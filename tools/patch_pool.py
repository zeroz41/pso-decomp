#!/usr/bin/env python3
"""Make the game's CodeWarrior builds: GC/<v>np = GC/<v> without .rodata pooling.

Every stock mwcceppc (GC/1.0 to 3.0a5.2) puts a TU's own .rodata objects (const
tables, readonly strings, float templates) into the TU's literal pool and
addresses them as pool+offset. PsoV3's game code never does that: each such
object keeps its own symbol and relocation. The np builds reproduce it.

The patch routes the compiler's four calls of its pool-base lookup through a
stub that answers "not poolable" when the object's pool section is .rodata
(name "...rodata..."); every other object falls through to the original lookup.
The stub sits in the zero padding at the end of .text, so the file keeps its size.

usage: patch_pool.py <stock dir> <np dir> <version>
Copies the stock compiler directory and patches mwcceppc.exe in the copy. Both
the stock input and the patched output are checked against known SHA-1s.
"""
import hashlib
import shutil
import struct
import sys
from pathlib import Path

# version: (stock sha1, np sha1, pool-base lookup VA, call sites of it)
BUILDS = {
    "GC/2.6": ("1110a7a9924a09a608967efdf79ecf09900344e7",
               "0ef567680232d6455923dec246f409d38649109b",
               0x4D1140, (0x4DD9D7, 0x4DDAE9, 0x4E089F, 0x4E091E)),
    "GC/2.0": ("ef148743ee72be15f64926ac18c3aadc9cca2b47",
               "89a83889349866ac53214ac44cb4ade048883957",
               0x4D12B0, (0x4DDB47, 0x4DDC59, 0x4E0A0F, 0x4E0A8E)),
    "GC/1.3.2": ("d8f9c36d62f66c2a044d5a20a132b79eeb2f36e5",
                 "fd9884f95472b5fa79af927b7e5a56a667805321",
                 0x4D0440, (0x4DCC17, 0x4DCD29, 0x4DFA4F, 0x4DFACE)),
}

# mov eax,[esp+4]; mov eax,[eax+1Eh]   ; the object's pool section
# test eax,eax; jz lookup
# mov eax,[eax+0Ah]; cmp dword [eax+0Dh],'roda'; jnz lookup
# xor eax,eax; ret                      ; .rodata: not poolable
# lookup: jmp <pool-base lookup>
STUB = bytes.fromhex("8b442404" "8b401e" "85c0" "740f" "8b400a" "81780d726f6461" "7503" "31c0c3")


def sha1(data: bytes) -> str:
    return hashlib.sha1(data).hexdigest()


def patch(exe: bytearray, lookup: int, calls) -> None:
    pe = struct.unpack_from("<I", exe, 0x3C)[0]
    opt_size = struct.unpack_from("<H", exe, pe + 20)[0]
    image_base = struct.unpack_from("<I", exe, pe + 24 + 28)[0]
    sec = pe + 24 + opt_size
    name, vsize, va, raw_size, raw_ptr = struct.unpack_from("<8sIIII", exe, sec)
    assert name.startswith(b".text"), name
    cave = (vsize + 15) & ~15
    cave_va = image_base + va + cave
    code = bytearray(STUB)
    code += b"\xe9" + struct.pack("<i", lookup - (cave_va + len(code) + 5))
    assert cave + len(code) <= raw_size and not any(exe[raw_ptr + cave:raw_ptr + cave + len(code)])
    exe[raw_ptr + cave:raw_ptr + cave + len(code)] = code
    struct.pack_into("<I", exe, sec + 8, cave + len(code))  # VirtualSize covers the stub
    for at in calls:
        p = at - image_base - va + raw_ptr
        assert exe[p] == 0xE8 and struct.unpack_from("<i", exe, p + 1)[0] == lookup - (at + 5), hex(at)
        struct.pack_into("<i", exe, p + 1, cave_va - (at + 5))


def main() -> None:
    if len(sys.argv) != 4 or sys.argv[3] not in BUILDS:
        sys.exit(f"usage: patch_pool.py <stock dir> <np dir> <{'|'.join(BUILDS)}>")
    src, dst, version = Path(sys.argv[1]), Path(sys.argv[2]), sys.argv[3]
    stock_sha, np_sha, lookup, calls = BUILDS[version]
    exe = bytearray((src / "mwcceppc.exe").read_bytes())
    if sha1(exe) != stock_sha:
        sys.exit(f"{src}/mwcceppc.exe is not the stock {version} compiler (sha1 {sha1(exe)})")
    patch(exe, lookup, calls)
    if sha1(exe) != np_sha:
        sys.exit(f"patched {version} compiler has sha1 {sha1(exe)}, expected {np_sha}")
    dst.mkdir(parents=True, exist_ok=True)
    for f in src.iterdir():
        if f.is_file() and f.name != "mwcceppc.exe":
            shutil.copy2(f, dst / f.name)
    tmp = dst / "mwcceppc.exe.tmp"
    tmp.write_bytes(exe)
    tmp.chmod(0o755)
    tmp.replace(dst / "mwcceppc.exe")


if __name__ == "__main__":
    main()
