#!/usr/bin/env python3
"""Compare the compiled scalar vertex transforms with the original instructions.

Requires a native build's generated disassembly and a host C++ compiler. Neither
original instructions nor game data are stored in this probe.
"""
import ctypes as C
import json
import pathlib
import random
import re
import struct
import subprocess
import tempfile

root = pathlib.Path(__file__).resolve().parents[2]
scratch = tempfile.TemporaryDirectory(prefix='pso-weighted-transform-')
tmp = pathlib.Path(scratch.name)
text = (root / 'src/pso/unk/text_803E2F28.cpp').read_text()
layout = text[text.index('struct ReorderedMatrix_803E3390'):text.index('// This chunk command')]
start = text.index('static void transform_chunk_vertex(')
weighted = text[start:text.index('#endif', start)]
start = text.index('\nvoid transform_chunk_vertices_pos_normal(')
ordinary = text[start:text.index('#endif', start)]
pre = r'''
#include <stdint.h>
#include <math.h>
#define TYPES_H
typedef uint8_t u8;
typedef int16_t s16;
typedef uint16_t u16;
typedef int32_t s32;
typedef uint32_t u32;
typedef float f32;
#include "pso/render/ChunkVertexJob.h"
extern "C" {
'''
(tmp / 'weighted-host.cpp').write_text(pre + layout + weighted + ordinary + '\n}\n')
subprocess.run([
    'c++', '-std=c++11', '-O2', '-ffp-contract=off', '-shared', '-fPIC', '-iquote', str(root / 'include'),
    str(tmp / 'weighted-host.cpp'), '-o', str(tmp / 'weighted.so'),
], check=True)
lib = C.CDLL(str(tmp / 'weighted.so'))
libm = C.CDLL('libm.so.6')
libm.fmaf.argtypes = [C.c_float] * 3
libm.fmaf.restype = C.c_float

def fma(a, b, c):
    return float(libm.fmaf(a, b, c))


def rnd32(x):
    return struct.unpack('>f', struct.pack('>f', x))[0]


class Job(C.Structure):
    _fields_ = [('dst', C.c_void_p), ('src', C.c_void_p), ('count', C.c_int32)]


lib.GXSetVtxAttrFmtv.argtypes = [C.POINTER(Job), C.c_void_p, C.c_uint32]
asm = (root / 'build/GPOE8P/asm/pso/unk/text_803E2F28.s').read_text()
def instructions(symbol):
    body = asm[asm.index(f'.fn {symbol},'):asm.index(f'.endfn {symbol}')]
    ins = []
    labels = {}
    for line in body.splitlines():
        if line.startswith('.L_'):
            labels[line[:-1]] = len(ins)
        if line.startswith('/*'):
            ins.append(line.split('*/')[1].strip())
    return ins, labels


weighted_instructions = instructions('GXSetVtxAttrFmtv')
ordinary_instructions = instructions('transform_chunk_vertices_pos_normal')
lib.transform_chunk_vertices_pos_normal.argtypes = [C.POINTER(Job), C.c_void_p]


def emulate(records, matrix, old, mode):
    ins, labels = ordinary_instructions if mode is None else weighted_instructions
    mem = bytearray(65536)
    job, src, dst, mat = (256, 4096, 12288, 32768)
    mem[job:job + 12] = struct.pack('>III', dst, src, len(records))
    mem[mat:mat + 48] = struct.pack('>12f', *matrix)
    for i, r in enumerate(records):
        fmt = '>6f' if mode is None else '>6fhH'
        struct.pack_into(fmt, mem, src + i * struct.calcsize(fmt), *r)
    for i, r in enumerate(old):
        mem[dst + i * 32:dst + (i + 1) * 32] = struct.pack('>8f', *r)
    regs = [0] * 32
    regs[1] = 61440
    regs[3] = job
    regs[4] = mat
    regs[5] = mode or 0
    fp = [[0.0, 0.0] for _ in range(32)]
    pc = 0
    ctr = 0
    cmp = 0
    gqr = {0: 0}
    steps = 0

    def r(v):
        return regs[int(v[1:])]

    def setr(v, x):
        regs[int(v[1:])] = x & 0xFFFFFFFF

    def addr(v):
        m = re.fullmatch('(-?(?:0x[0-9a-f]+|[0-9]+))\\((r\\d+)\\)', v)
        return ((r(m[2]) + int(m[1], 0)) & 0xFFFFFFFF, m[2])
    while pc < len(ins):
        steps += 1
        assert steps < 10000
        line = ins[pc]
        pc += 1
        op, args = line.split(None, 1) if ' ' in line or '\t' in line else (line, '')
        a = [x.strip() for x in args.split(',')]
        if op == 'blr':
            break
        if op in ('stfd', 'lfd'):
            continue
        if op == 'lwz':
            ad, _ = addr(a[1])
            setr(a[0], int.from_bytes(mem[ad:ad + 4], 'big'))
        elif op == 'lhzu':
            ad, base = addr(a[1])
            setr(a[0], int.from_bytes(mem[ad:ad + 2], 'big'))
            setr(base, ad)
        elif op == 'li':
            setr(a[0], int(a[1], 0))
        elif op == 'oris':
            setr(a[0], r(a[1]) | int(a[2], 0) << 16)
        elif op == 'mtspr':
            gqr[1] = r(a[1])
        elif op == 'stwu':
            ad, base = addr(a[1])
            mem[ad:ad + 4] = r(a[0]).to_bytes(4, 'big')
            setr(base, ad)
        elif op in ('addi', 'subi'):
            setr(a[0], r(a[1]) + (1 if op == 'addi' else -1) * int(a[2], 0))
        elif op == 'add':
            setr(a[0], r(a[1]) + r(a[2]))
        elif op == 'mr':
            setr(a[0], r(a[1]))
        elif op == 'slwi':
            setr(a[0], r(a[1]) << int(a[2], 0))
        elif op == 'mtctr':
            ctr = r(a[0])
        elif op == 'cmpwi':
            cmp = (r(a[0]) ^ 0x80000000) - 0x80000000 - int(a[1], 0)
        elif op in ('beq', 'bne', 'b'):
            if op == 'b' or (op == 'beq' and cmp == 0) or (op == 'bne' and cmp != 0):
                pc = labels[a[0]]
        elif op == 'bdnz':
            ctr = (ctr - 1) & 0xFFFFFFFF
            if ctr:
                pc = labels[a[0]]
        elif op in ('psq_l', 'psq_lu'):
            ad, base = addr(a[1])
            w = int(a[2])
            q = int(a[3].replace('qr', ''))
            n = 1 if w else 2
            if q == 0:
                vals = list(struct.unpack('>' + str(n) + 'f', mem[ad:ad + 4 * n]))
            else:
                assert gqr[q] == 0x08070807
                vals = [x / 256 for x in struct.unpack('>' + str(n) + 'h', mem[ad:ad + 2 * n])]
            if w:
                vals.append(1.0)
            fp[int(a[0][1:])] = vals
            if op.endswith('lu'):
                setr(base, ad)
        elif op in ('psq_st', 'psq_stu'):
            ad, base = addr(a[1])
            n = 1 if int(a[2]) else 2
            mem[ad:ad + 4 * n] = struct.pack('>' + str(n) + 'f', *fp[int(a[0][1:])][:n])
            if op == 'psq_stu':
                setr(base, ad)
        elif op.startswith('ps_madds'):
            d, x, y, z = [int(v[1:]) for v in a]
            lane = int(op[-1])
            fp[d] = [fma(fp[x][i], fp[y][lane], fp[z][i]) for i in range(2)]
        elif op.startswith('ps_muls'):
            d, x, y = [int(v[1:]) for v in a]
            lane = int(op[-1])
            fp[d] = [rnd32(fp[x][i] * fp[y][lane]) for i in range(2)]
        else:
            raise AssertionError(line)
    return bytes(mem[dst:dst + len(old) * 32])


rng = random.Random(0x803E3110)
cases = 0
for mode in [0, 1, 7, 0xFFFFFFFF, None]:
    for n in [1, 2, 3, 8]:
        for trial in range(40):
            matrix = [rnd32(rng.uniform(-10, 10)) for _ in range(12)]
            records = []
            for _ in range(n):
                components = [rnd32(rng.uniform(-20, 20)) for _ in range(6)]
                weight = rng.choice([-32768, -256, 0, 1, 255, 256, 257, 32767])
                records.append(components if mode is None else components + [weight, rng.randrange(8)])
            old = [[rnd32(rng.uniform(-100, 100)) for _ in range(8)] for _ in range(8)]
            expected = emulate(records, matrix, old, mode)
            fmt = '=6f' if mode is None else '=6fhH'
            src = C.create_string_buffer(b''.join(struct.pack(fmt, *r) for r in records))
            dst = C.create_string_buffer(b''.join((struct.pack('=8f', *r) for r in old)))
            mtx = (C.c_float * 12)(*matrix)
            job = Job(C.addressof(dst), C.addressof(src), n)
            if mode is None:
                lib.transform_chunk_vertices_pos_normal(C.byref(job), mtx)
            else:
                lib.GXSetVtxAttrFmtv(C.byref(job), mtx, mode)
            result = b''.join((struct.pack('>8f', *struct.unpack('=8f', dst.raw[i * 32:(i + 1) * 32])) for i in range(8)))
            assert result == expected, (mode, n, trial, result.hex(), expected.hex())
            cases += 1
print(json.dumps(dict(
    result='PASS',
    native_instruction_reference_cases=cases,
    includes='negative/zero/max weights, overwrite/accumulate, repeated destination '
             'indices, untouched padding, counts 1/2/3/8',
)))
