#!/usr/bin/env python3
"""Exercise the linked GPOE8P resource readers using Unicorn 2.1.4 and synthetic disc sectors."""
import argparse
import hashlib
from pathlib import Path
import re
import struct

from unicorn import Uc, UC_ARCH_PPC, UC_HOOK_CODE, UC_MODE_BIG_ENDIAN, UC_MODE_PPC32
from unicorn import ppc_const as ppc

ROOT = Path(__file__).resolve().parents[2]
SYMBOLS = ROOT / "config/GPOE8P/psov3/symbols.txt"
RETAIL_SHA1 = "0d85744b51d7379efb025a943d0cd5aaae2191a3"
RETURN = 0x80001000
STACK = 0x81108000
FILENAME = 0x81111000
DESTINATION = 0x81112020
ALLOCATION = 0x81120000
DISC = 0x81130000
ARCHIVE = 0x81130200
SECTOR = 2048
CONTENTS = bytes(i % 251 for i in range(6 * SECTOR))
GUARD = b"\xAA" * (len(CONTENTS) + 32)
FAILED = 0xFFFFFFFF

OPEN = "adxf_open__6TLobbyFUii"
CLOSE = "close_adxf_handle__6TLobbyFv"
SEEK = "adxf_seek__6TLobbyFPvii"
READ = "read_checked_align__6TLobbyFlll"
ALLOC = "alloc__22TQuestVmDownLoadServerFUl"
FREE = "safe_free__23TAdSinglePlyChrSelectGCFUl"
DECODE = "prs_decompress_buffer"


class ResourceReads:
    def __init__(self, dol):
        if hashlib.sha1(dol).hexdigest() != RETAIL_SHA1:
            raise ValueError("Expected the matching GPOE8P DOL")
        self.symbols = {
            name: int(address, 16) for name, address in
            re.findall(r"^(\S+) = \.\w+:0x([\da-fA-F]+);", SYMBOLS.read_text(), re.MULTILINE)
        }
        self.cpu = Uc(UC_ARCH_PPC, UC_MODE_PPC32 | UC_MODE_BIG_ENDIAN)
        self.cpu.mem_map(0x80000000, 0x700000)
        self.cpu.mem_map(0x81100000, 0x40000)
        for offset, address, size in zip(*(struct.unpack_from(">18I", dol, start)
                                           for start in (0, 0x48, 0x90))):
            if size:
                self.cpu.mem_write(address, dol[offset:offset + size])
        self.cpu.reg_write(ppc.UC_PPC_REG_2, 0x805DFD00)
        self.cpu.reg_write(ppc.UC_PPC_REG_13, 0x805DA600)
        self.cpu.mem_write(FILENAME, b"fixture.bin\0")
        self.fail_allocation = False
        self.calls = {}
        self.hook(OPEN, self.open_file)
        self.hook(CLOSE, lambda *_: 0)
        self.hook(SEEK, lambda *_: 0)
        self.hook(READ, self.read_sectors)
        self.hook("adxf_get_stat", lambda *_: 3)
        self.hook("adxf_get_fsize_byte__6TLobbyFv", self.disc_size)
        self.hook(ALLOC, lambda *_: 0 if self.fail_allocation else ALLOCATION)
        self.hook(FREE, lambda *_: None)
        self.hook(DECODE, lambda source, target, unused: self.cpu.mem_write(target, b"decoded"))

    def hook(self, symbol, operation):
        def intercept(cpu, address, instruction_size, user_data):
            args = tuple(cpu.reg_read(reg) for reg in
                         (ppc.UC_PPC_REG_3, ppc.UC_PPC_REG_4, ppc.UC_PPC_REG_5))
            self.calls.setdefault(symbol, []).append(args)
            result = operation(*args)
            if result is not None:
                cpu.reg_write(ppc.UC_PPC_REG_3, result & FAILED)
            cpu.reg_write(ppc.UC_PPC_REG_PC, cpu.reg_read(ppc.UC_PPC_REG_LR))

        address = self.symbols[symbol]
        self.cpu.hook_add(UC_HOOK_CODE, intercept, begin=address, end=address)

    def open_file(self, name, partition, unused):
        assert (name, partition) == (FILENAME, 0)
        return DISC if self.size >= 0 else 0

    def disc_size(self, handle, unused4, unused5):
        assert handle == DISC
        return self.size

    def read_sectors(self, handle, count, destination):
        assert handle == (ARCHIVE if self.in_archive else DISC)
        end = self.offset + count * SECTOR
        assert end <= len(CONTENTS)
        self.cpu.mem_write(destination, CONTENTS[self.offset:end])
        self.offset = end
        return 0

    def set_word(self, name, value):
        self.cpu.mem_write(self.symbols[name], struct.pack(">I", value))

    def set_file(self, in_archive, size, decoded_size=0):
        self.size = size
        self.in_archive = in_archive
        self.set_word("TItemDrop__gsl_adxf_handle", ARCHIVE)
        self.set_word("TItemDrop__gsl_entry_count", 1)
        name = b"fixture.bin" if in_archive else b"other.bin"
        self.cpu.mem_write(self.symbols["gsl_archive_entries"],
                           name.ljust(32, b"\0") + struct.pack(">iii", 5, size, decoded_size))

    def call(self, name):
        self.calls.clear()
        self.offset = 0
        self.cpu.reg_write(ppc.UC_PPC_REG_1, STACK)
        self.cpu.reg_write(ppc.UC_PPC_REG_3, FILENAME)
        self.cpu.reg_write(ppc.UC_PPC_REG_4, DESTINATION)
        self.cpu.reg_write(ppc.UC_PPC_REG_LR, RETURN)
        self.cpu.emu_start(self.symbols[name], RETURN, count=20_000)
        assert self.cpu.reg_read(ppc.UC_PPC_REG_PC) == RETURN, name
        return self.cpu.reg_read(ppc.UC_PPC_REG_3)

    def check_size(self):
        assert self.call("get_resource_file_size") == (self.size & FAILED)
        assert len(self.calls.get(OPEN, [])) == int(not self.in_archive)
        assert len(self.calls.get(CLOSE, [])) == int(not self.in_archive and self.size >= 0)

    def check_read(self, name):
        for target in (ALLOCATION, DESTINATION):
            self.cpu.mem_write(target - 16, GUARD)
        self.set_word("disc_read_filename", 0)
        result = self.call(name)
        allocates = name == "load_disc_file"
        if allocates:
            assert result == (ALLOCATION if self.size > 0 else 0)
        else:
            assert result == (self.size if self.size > 0 else FAILED)
        assert self.cpu.mem_read(self.symbols["disc_read_filename"], 4) == struct.pack(">I", FILENAME)
        expected_bytes = max(self.size, 0)
        transfer = ((expected_bytes + SECTOR - 1) // SECTOR) * SECTOR
        assert self.offset == transfer
        assert [args[0] for args in self.calls.get(ALLOC, [])] == ([transfer] if allocates and transfer else [])
        if self.in_archive:
            assert OPEN not in self.calls and CLOSE not in self.calls
            assert self.calls[SEEK][0] == (ARCHIVE, 5, 0)
        else:
            assert SEEK not in self.calls
            assert len(self.calls[OPEN]) == 1 + int(self.size > 0)
        written = expected_bytes if name == "read_disc_file" else transfer
        target = ALLOCATION if allocates else DESTINATION
        expected = GUARD[:16] + CONTENTS[:written] + GUARD[16 + written:]
        assert self.cpu.mem_read(target - 16, len(GUARD)) == expected

    def check_compressed_and_failed_allocation(self):
        self.set_file(True, 2049, 9011)
        assert self.call("read_disc_file_sectors") == 9011
        assert self.offset == 4096 and self.calls[ALLOC][0][0] == 10240
        assert [args[:2] for args in self.calls[DECODE]] == [(ALLOCATION, DESTINATION)]
        assert self.calls[FREE][0][0] == ALLOCATION
        assert self.cpu.mem_read(DESTINATION, 7) == b"decoded"

        self.fail_allocation = True
        assert self.call("load_disc_file") == 0
        assert self.offset == 0 and FREE not in self.calls


def check(path):
    reader = ResourceReads(path.read_bytes())
    cases = 0
    for in_archive in (False, True):
        for size in (-1, 0, 1, 2047, 2048, 2049, 4095, 4096, 4097):
            if in_archive and size < 0:
                continue
            reader.set_file(in_archive, size)
            reader.check_size()
            for name in ("read_disc_file", "read_disc_file_sectors", "load_disc_file"):
                reader.check_read(name)
            cases += 4
    reader.check_compressed_and_failed_allocation()
    print(f"{path}: {cases + 2} resource loading cases passed")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("dol", nargs="+", type=Path)
    if not __debug__:
        parser.error("run with assertions enabled")
    for path in parser.parse_args().dol:
        check(path)
