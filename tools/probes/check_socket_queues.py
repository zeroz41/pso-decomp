#!/usr/bin/env python3
"""Compare normal TCP send, receive and reassembly operations in two GPOE8P DOLs. Requires Unicorn 2.1.4."""
import argparse
import hashlib
import random
from pathlib import Path
import struct
import subprocess

from unicorn import (
    Uc, UC_ARCH_PPC, UC_MODE_PPC32, UC_MODE_BIG_ENDIAN,
    UC_HOOK_CODE,
)
from unicorn import ppc_const as ppc

ORIGINAL_SHA1 = "0d85744b51d7379efb025a943d0cd5aaae2191a3"

TCB = 0x81100000
PACKET = TCB + 0x1000
DATA = TCB + 0x20000
QUEUE = TCB + 0x30000
RETAIL_SYMBOLS = {
    "TLobby__sub_8041F66C": 0x8041F66C,
    "TLobby__sub_8041F914": 0x8041F914,
    "TLobby__sub_8041FFF8": 0x8041FFF8,
    "tcp_gather_send_data": 0x80420410,
    "complete_request_callback": 0x804220A0,
    "set_thread_state_and_resume": 0x8042276C,
    "tcp_protocol_state": 0x805C1D48,
}
RETURN = 0x80001000
STATE_SIZE = 0x544
MASK = 0xFFFFFFFF


def linked_symbols(elf):
    nm = Path(__file__).resolve().parents[2] / "build/binutils/powerpc-eabi-nm"
    symbols = {}
    for line in subprocess.check_output([nm, "-n", elf], text=True).splitlines():
        columns = line.split()
        if len(columns) == 3 and columns[2] in RETAIL_SYMBOLS:
            symbols[columns[2]] = int(columns[0], 16)
    missing = RETAIL_SYMBOLS.keys() - symbols.keys()
    if missing:
        raise ValueError(f"Missing socket symbols in {elf}: {', '.join(sorted(missing))}")
    return symbols


class Game:
    def __init__(self, path, expected_sha1=None, symbols=None):
        self.symbols = RETAIL_SYMBOLS if symbols is None else symbols
        data = path.read_bytes()
        if expected_sha1 and hashlib.sha1(data).hexdigest() != expected_sha1:
            raise ValueError(f"Unexpected input revision at {path}")
        self.cpu = Uc(UC_ARCH_PPC, UC_MODE_PPC32 | UC_MODE_BIG_ENDIAN)
        self.cpu.mem_map(0x80000000, 0x700000)
        self.cpu.mem_map(TCB, 0x40000)
        self.cpu.reg_write(ppc.UC_PPC_REG_2, 0x805DFD00)
        self.cpu.reg_write(ppc.UC_PPC_REG_13, 0x805DA600)
        offsets = struct.unpack_from(">18I", data, 0)
        addresses = struct.unpack_from(">18I", data, 0x48)
        sizes = struct.unpack_from(">18I", data, 0x90)
        for offset, address, size in zip(offsets, addresses, sizes):
            if size:
                if offset + size > len(data):
                    raise ValueError(f"Truncated DOL section at {offset:#x}")
                self.cpu.mem_write(address, data[offset:offset + size])

    def call(self, entry, *args):
        cpu = self.cpu
        cpu.reg_write(ppc.UC_PPC_REG_1, TCB + 0x8000)
        registers = (ppc.UC_PPC_REG_3, ppc.UC_PPC_REG_4, ppc.UC_PPC_REG_5, ppc.UC_PPC_REG_6)
        for reg, value in zip(registers, args):
            cpu.reg_write(reg, value)
        cpu.reg_write(ppc.UC_PPC_REG_LR, RETURN)
        cpu.emu_start(self.symbols[entry], RETURN, count=20_000)
        if cpu.reg_read(ppc.UC_PPC_REG_PC) != RETURN:
            raise AssertionError(f"Routine {entry} failed to return")
        return cpu.reg_read(ppc.UC_PPC_REG_3)

    def run(self, entry, state):
        self.cpu.mem_write(TCB, bytes(state))
        self.call(entry, TCB)
        return self.cpu.mem_read(TCB, STATE_SIZE)


def check_reassembly(original, candidate):
    cases = 0
    for origin in (0x100000, 0x7FFFFFF0, 0xFFFFFFF0):
        for count in (0, 1, 2, 3, 12, 32):
            starts = [origin + 32 * index for index in range(count)]
            positions = [start + offset for start in starts for offset in (0, 2, 23, 24, 27)]
            for position in [origin - 1, *positions, origin + 32 * count]:
                state = bytearray(STATE_SIZE)
                struct.pack_into(">Ihh", state, 0xF4, 24 * count, count - 1, 0 if count else -1)
                for index, start in enumerate(starts):
                    struct.pack_into(">II", state, 0xFC + 8 * index, start & MASK, (start + 24) & MASK)
                struct.pack_into(">I", state, 0x228, position & MASK)
                struct.pack_into(">I", state, 0x534, 4096)
                actual = candidate.run("TLobby__sub_8041F66C", state)
                # Compare sequence positions before truncation for an independent wraparound oracle.
                remaining = sum(start > position for start in starts)
                if actual != original.run("TLobby__sub_8041F66C", state) or (
                    struct.unpack_from(">Ih", actual, 0xF4) != (remaining * 24, remaining - 1)
                ):
                    raise AssertionError(f"Reassembly differs for {count} ranges at {position:#x}")
                cases += 1
    return cases


def check_wrapped_receive(candidate):
    cpu = candidate.cpu
    header = PACKET + 0x100
    source = DATA + 0x1000
    capacity = 256
    segments = (
        # Offset, length, and expected merged interval relative to the receive head.
        (8, 16, 8, 24),
        (20, 16, 8, 36),
        (4, 12, 4, 36),
        (12, 4, 4, 36),
    )
    cases = 0
    for origin in (0x100000, 0x7FFFFFF0, 0xFFFFFFF0):
        state = bytearray(STATE_SIZE)
        struct.pack_into(">IB", state, 0xC8, DATA, 1)
        struct.pack_into(">hh", state, 0xF8, -1, -1)
        struct.pack_into(">I", state, 0x228, origin)
        struct.pack_into(">I", state, 0x534, capacity)
        cpu.mem_write(TCB, bytes(state))
        cpu.mem_write(DATA, bytes(capacity))
        expected_payload = bytearray(capacity)
        for case, (offset, length, start, end) in enumerate(segments, 1):
            packet = bytearray(0x9C)
            struct.pack_into(">II", packet, 4, 1, length)
            struct.pack_into(">h2xIB", packet, 12, length, source, 1)
            tcp_header = bytearray(20)
            struct.pack_into(">I", tcp_header, 4, (origin + offset) & MASK)
            payload = bytes([case]) * length
            cpu.mem_write(PACKET, bytes(packet))
            cpu.mem_write(header, bytes(tcp_header))
            cpu.mem_write(source, payload)
            status = candidate.call("TLobby__sub_8041F914", PACKET, 0, TCB, header)
            expected_payload[offset:offset + length] = payload
            queue = cpu.mem_read(TCB + 0xF4, 16)
            expected = (end - start, 0, 0, (origin + start) & MASK, (origin + end) & MASK)
            if (
                status != 0
                or struct.unpack(">IhhII", queue) != expected
                or cpu.mem_read(DATA, capacity) != expected_payload
            ):
                raise AssertionError(f"Receive range or payload mismatch at {origin:#x}, segment {case}")
            cases += 1
    return cases


def send_fixture(rng, queue_mode, lengths, capacity, ring_head=None):
    state = bytearray(STATE_SIZE)
    ring = bytearray(65 * 16)
    struct.pack_into(">IB", state, 0x10, QUEUE if queue_mode else DATA, 1)
    struct.pack_into(">I", state, 0x34, sum(lengths))
    if queue_mode:
        head = rng.randrange(65) if ring_head is None else ring_head
        state[0x204] = 0x80
        struct.pack_into(">II", state, 0x20, len(lengths), head)
        for index, length in enumerate(lengths):
            slot = (head + index) % 65
            struct.pack_into(">IB3xhhI", ring, slot * 16, DATA + 512 * index, 1,
                             length, rng.randrange(8), index + 1)
        return state, ring, 0
    head = rng.randrange(capacity)
    used = rng.randrange(capacity + 1)
    struct.pack_into(">III", state, 0x20, used, head, (head + used) % capacity)
    struct.pack_into(">I", state, 0x530, capacity)
    struct.pack_into(">I", state, 0x30, len(lengths))
    struct.pack_into(">I", state, 0x1FC, 1)
    for index, length in enumerate(lengths):
        struct.pack_into(">h2xIB", state, 0x38 + index * 12, length, DATA + 4096 + 512 * index, 1)
    return state, ring, used


def gather(game, state, ring, offset, length):
    cpu = game.cpu
    cpu.mem_write(TCB, bytes(state))
    cpu.mem_write(QUEUE, bytes(ring))
    cpu.mem_write(PACKET, bytes(0x9C))
    status = game.call("tcp_gather_send_data", offset, length, PACKET, TCB)
    packet = cpu.mem_read(PACKET, 0x9C)
    count, total = struct.unpack_from(">II", packet, 4)
    if status != 0 or not 0 < count <= 12 or total != length:
        raise AssertionError(f"Unexpected gather result {status}, {count}, {total} for {length} bytes")
    return packet, cpu.mem_read(TCB, len(state)), cpu.mem_read(QUEUE, len(ring))


def acknowledge(game, state, ring, data, amount, reenter):
    cpu = game.cpu
    events = []

    def completion(cpu, address, size, symbol):
        args = tuple(cpu.reg_read(reg) for reg in (ppc.UC_PPC_REG_3, ppc.UC_PPC_REG_4, ppc.UC_PPC_REG_5))
        request = bytes(cpu.mem_read(cpu.reg_read(ppc.UC_PPC_REG_6), 16)) if symbol == "complete_request_callback" else b""
        events.append((symbol, args, request))
        if reenter and symbol == "complete_request_callback" and len(events) == 1:
            remaining, head = struct.unpack(">II", cpu.mem_read(TCB + 0x20, 8))
            if remaining:
                next_head = (head + 17) % 65
                cpu.mem_write(QUEUE + next_head * 16, bytes(cpu.mem_read(QUEUE + head * 16, 16)))
                cpu.mem_write(TCB + 0x24, struct.pack(">I", next_head))
        cpu.reg_write(ppc.UC_PPC_REG_3, 0)
        cpu.reg_write(ppc.UC_PPC_REG_PC, cpu.reg_read(ppc.UC_PPC_REG_LR))

    cpu.mem_write(TCB, bytes(state))
    cpu.mem_write(game.symbols["tcp_protocol_state"], struct.pack(">I", TCB))
    cpu.mem_write(QUEUE, bytes(ring))
    cpu.mem_write(DATA, data)
    hooks = []
    for name in ("complete_request_callback", "set_thread_state_and_resume"):
        address = game.symbols[name]
        hooks.append(cpu.hook_add(UC_HOOK_CODE, completion, name, begin=address, end=address))
    try:
        status = game.call("TLobby__sub_8041FFF8", amount, TCB)
    finally:
        for hook in hooks:
            cpu.hook_del(hook)
    if status != 0:
        raise AssertionError(f"ACK failed for {amount} bytes")
    return cpu.mem_read(TCB, len(state)), cpu.mem_read(QUEUE, len(ring)), cpu.mem_read(DATA, len(data)), events


def check_send(original, candidate):
    rng = random.Random(457)
    for queue_mode in (True, False):
        for case in range(1200):
            lengths = [rng.randrange(1, 48) for _ in range(rng.randrange(1, 9))]
            state, ring, used = send_fixture(rng, queue_mode, lengths, 128)
            total = used + sum(lengths)
            offset = rng.randrange(total)
            args = state, ring, offset, rng.randrange(1, total - offset + 1)
            if gather(original, *args) != gather(candidate, *args):
                raise AssertionError(f"Gather mismatch, queue mode {queue_mode}, case {case}")
    boundary_cases = 0
    for queue_mode in (True, False):
        for lengths in ([1], [32767], [1] * 12, [32767] * 12, [50, 32767, 2, 7, 32765], [16384] * 6):
            for head in (0, 63, 64) if queue_mode else (0,):
                state, ring, _ = send_fixture(rng, queue_mode, lengths, 96, ring_head=head)
                if not queue_mode:
                    struct.pack_into(">III", state, 0x20, 0, 0, 0)
                total = sum(lengths)
                for offset in sorted({0, total - 1, total // 2}):
                    for size in sorted({1, total - offset, min(32767, total - offset)}):
                        args = state, ring, offset, size
                        if gather(original, *args) != gather(candidate, *args):
                            raise AssertionError(f"Gather boundary mismatch for {lengths}, {offset}, {size}")
                        boundary_cases += 1
    rng = random.Random(1457)
    callbacks = 0
    for queue_mode in (True, False):
        for case in range(800):
            data = rng.randbytes(0x2000)
            lengths = [rng.randrange(1, 28) for _ in range(rng.randrange(1, 8))]
            state, ring, used = send_fixture(rng, queue_mode, lengths, 96)
            reenter = queue_mode and case % 4 == 0 and len(lengths) > 1
            amount = lengths[0] + rng.randrange(lengths[1]) if reenter else rng.randrange(used + sum(lengths) + 1)
            args = state, ring, data, amount, reenter
            actual = acknowledge(candidate, *args)
            if actual != acknowledge(original, *args):
                raise AssertionError(f"ACK mismatch, queue mode {queue_mode}, case {case}")
            callbacks += len(actual[-1])
    print(f"{2400 + boundary_cases:,} gathers and 1,600 ACKs passed, including {callbacks} completion events.")


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("original", type=Path, help="original GPOE8P PsoV3.dol")
    parser.add_argument("candidate", type=Path, help="GPOE8P DOL linked with the recovered socket runtime")
    parser.add_argument("--candidate-elf", type=Path, help="matching ELF when the candidate's symbol addresses moved")
    args = parser.parse_args()
    original = Game(args.original, ORIGINAL_SHA1)
    candidate = Game(args.candidate, symbols=linked_symbols(args.candidate_elf) if args.candidate_elf else None)
    reassembly_cases = check_reassembly(original, candidate)
    receive_cases = check_wrapped_receive(candidate)
    print(f"{reassembly_cases} reassembly comparisons and {receive_cases} out-of-order receive cases passed.")
    check_send(original, candidate)


if __name__ == "__main__":
    main()
