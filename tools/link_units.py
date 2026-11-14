#!/usr/bin/env python3
"""link_units.py — keep the list of units linked from compiled source.

The build links a unit's *compiled* object into the DOL only when its Object
is marked completed (``Matching``). Every other unit is compiled for objdiff
alone and the original split object is linked in its place.

``config/GPOE8P/psov3/linked_units.txt`` lists the units whose compiled object
is linked; ``configure.py`` reads it. Membership is earned from
``build/GPOE8P/report.json``: every function and every section of the unit
must be 100% (a code-only unit whose .ctors/.rodata differ stays out), and
its compiled object must pass the link checks below.

Usage:
  link_units.py check           # exit 1 if any listed unit is no longer linkable
  link_units.py scan            # report candidates / regressions (no write)
  link_units.py scan --write    # add candidates, drop regressions, write list
  link_units.py bisect          # after a build.sha1 failure: find the culprit
  link_units.py force-active --write   # list unreferenced symbols of linked units in config.yml

``scan`` also writes ``linked_units_blocked.json`` next to the list: units
whose functions all match but whose object fails a link check, with every
reason, including data that does not match yet.

Linking a compiled object exposes four things objdiff never checks, and the
scan refuses a unit on any of them: extra allocated sections (a vtable in
.data the split does not own), extra defined globals (a body duplicated into a
second unit), split globals the compiled object lacks, and a section-size
mismatch. A fifth is fixed rather than refused: mwld dead-strips unreferenced
functions, so those symbols go into config.yml's `force_active:` list and dtk
puts them in the linker script's FORCEACTIVE block. Shared named global objects
must also keep their original section and offset: equal unrelocated pointer
words can otherwise hide a swapped declaration order.

``bisect`` rebuilds the link step with halves of the newly added set until the
DOL hash passes, records offenders in ``linked_units_skip.txt`` and rewrites
the list. It only relinks (objects are already compiled) so each probe is fast.
"""
from __future__ import annotations

import argparse
import functools
import hashlib
import json
import subprocess
import sys
from pathlib import Path

try:
    from .mwcc_parts import mwcat_discarded_text_bytes
except ImportError:  # direct tools/link_units.py invocation
    from mwcc_parts import mwcat_discarded_text_bytes

ROOT = Path(__file__).resolve().parent.parent
REPORT = ROOT / "build" / "GPOE8P" / "report.json"
CFG_DIR = ROOT / "config" / "GPOE8P" / "psov3"
LINKED = CFG_DIR / "linked_units.txt"
SKIP = CFG_DIR / "linked_units_skip.txt"
SHA_FILE = CFG_DIR / "build.sha1"
DOL = ROOT / "build" / "GPOE8P" / "psov3.dol"
PY = ROOT / ".venv" / "bin" / "python"
if not PY.exists():
    PY = Path(sys.executable)

UNIT_PREFIX = "psov3/"


def _read_list(path: Path) -> list[str]:
    if not path.exists():
        return []
    out = []
    for line in path.read_text().splitlines():
        line = line.split("#", 1)[0].strip()
        if line:
            out.append(line)
    return out


def _write_list(path: Path, names: list[str], header: str) -> None:
    body = "\n".join(sorted(set(names)))
    path.write_text(f"# {header}\n{body}\n" if body else f"# {header}\n")


def unit_name(report_unit: dict) -> str:
    """report.json unit name -> configure.py Object name (``pso/x/Y.cpp``)."""
    name = report_unit["name"]
    if name.startswith(UNIT_PREFIX):
        name = name[len(UNIT_PREFIX):]
    meta = report_unit.get("metadata") or {}
    src = meta.get("source_path")
    for prefix in ("libs/dolphin/src/", "libs/", "src/", "build/GPOE8P/orig_asm/"):
        if src and src.startswith(prefix):
            return src[len(prefix):]
    return name


OBJ_DIR = ROOT / "build" / "GPOE8P" / "src"
SHF_ALLOC = 0x2


def elf_alloc_section_layout(path: Path) -> dict[str, tuple[int, int]]:
    """{section name: (size, alignment)} for each allocated section of a
    big-endian ELF32 object (mwcc .o). Pure-python: no objdump needed."""
    b = path.read_bytes()
    if b[:4] != b"\x7fELF":
        return {}
    be = lambda o, n=4: int.from_bytes(b[o:o + n], "big")
    shoff, shentsize, shnum, shstrndx = be(0x20), be(0x2E, 2), be(0x30, 2), be(0x32, 2)
    hdrs = []
    for i in range(shnum):
        o = shoff + i * shentsize
        hdrs.append((be(o), be(o + 4), be(o + 8), be(o + 16), be(o + 20), be(o + 32)))
    _, _, _, stroff, strsize, _ = hdrs[shstrndx]
    strtab = b[stroff:stroff + strsize]
    out = {}
    for name_off, typ, flags, off, size, alignment in hdrs:
        if not (flags & SHF_ALLOC) or size == 0 or typ == 0:
            continue
        end = strtab.index(b"\0", name_off)
        out[strtab[name_off:end].decode()] = (size, alignment)
    return out


def elf_alloc_sections(path: Path) -> dict[str, int]:
    """{section name: size} for each allocated, non-empty section."""
    return {name: size for name, (size, _) in elf_alloc_section_layout(path).items()}


def elf_symbol_bindings(path: Path) -> dict[str, tuple[int, int]]:
    """{name: (binding, type)} of defined GLOBAL/WEAK symbols in a BE ELF32 .o."""
    b = path.read_bytes()
    if b[:4] != b"\x7fELF":
        return {}
    be = lambda o, n=4: int.from_bytes(b[o:o + n], "big")
    shoff, shentsize, shnum = be(0x20), be(0x2E, 2), be(0x30, 2)
    hdrs = []
    for i in range(shnum):
        o = shoff + i * shentsize
        hdrs.append((be(o + 4), be(o + 16), be(o + 20), be(o + 24)))  # type, off, size, link
    out = {}
    for typ, off, size, link in hdrs:
        if typ != 2:  # SHT_SYMTAB
            continue
        _, stroff, strsize, _ = hdrs[link]
        strtab = b[stroff:stroff + strsize]
        for o in range(off, off + size, 16):
            name_off, info, shndx = be(o), b[o + 12], be(o + 14, 2)
            bind, styp = info >> 4, info & 0xF
            if bind not in (1, 2) or shndx == 0 or 0xFF00 <= shndx < 0xFFF2:
                continue
            end = strtab.index(b"\0", name_off)
            out[strtab[name_off:end].decode()] = (bind, styp)
    return out


def elf_defined_globals(path: Path) -> dict[str, int]:
    """{name: st_type} of every defined GLOBAL/WEAK symbol in a BE ELF32 .o."""
    return {name: typ for name, (_, typ) in elf_symbol_bindings(path).items()}


def _obj_path(u: dict) -> Path:
    n = unit_name(u)
    return OBJ_DIR / (n[:-len(Path(n).suffix)] + ".o")


@functools.lru_cache(maxsize=1)
def _canonical_function_owners(report: Path, mtime_ns: int, size: int) -> dict:
    """Unique original owners, refreshed when a build replaces the report."""
    owners = {}
    for unit in json.loads(report.read_text()).get("units", []):
        if (unit.get("metadata") or {}).get("module_name") not in (None, "psov3"):
            continue
        for function in unit.get("functions") or []:
            name = function["name"]
            owners[name] = None if name in owners else unit
    return owners


def discarded_weak_functions(u: dict) -> set[str]:
    """Extra inline copies that mwld resolves to a canonical strong function.

    Require a unique report owner and a GLOBAL function in its original object.
    Its compiled object must also provide it strongly unless that owner is
    unlinked and has non-exact report scores, preventing promotion in this scan.
    Thus selection changes cannot replace our strong provider with a weak copy.
    Weak data, strong duplicates, and ambiguous/missing providers remain errors.
    This does not waive any function, section, order or final DOL-hash check.
    """
    obj = _obj_path(u)
    if not obj.exists():
        return set()
    own = {f["name"] for f in u.get("functions") or []}
    weak = {name for name, binding in elf_symbol_bindings(obj).items()
            if binding == (2, 2) and name not in own and name in _dol_symbol_names()}
    if not weak or not REPORT.exists():
        return set()
    stat = REPORT.stat()
    owners = _canonical_function_owners(REPORT, stat.st_mtime_ns, stat.st_size)
    linked = set(_read_list(LINKED))
    discarded = set()
    for name in weak:
        owner = owners.get(name)
        if not owner or unit_name(owner) == unit_name(u):
            continue
        compiled = _obj_path(owner)
        split = SPLIT_OBJ_DIR / compiled.relative_to(OBJ_DIR)
        if not split.exists() or elf_symbol_bindings(split).get(name) != (1, 2):
            continue
        if compiled.exists() and elf_symbol_bindings(compiled).get(name) != (1, 2):
            # The owner's own copy is weak as well (an in-class inline whose
            # vtable both TUs emit): mwld keeps the first weak definition, so
            # a linked owner earlier in the link order still provides it.
            if not (elf_symbol_bindings(compiled).get(name) == (2, 2)
                    and unit_name(owner) in linked
                    and _links_before(split, SPLIT_OBJ_DIR / obj.relative_to(OBJ_DIR))):
                if (unit_name(owner) in linked or (owner.get("metadata") or {}).get("complete")
                        or report_scores_exact(owner)):
                    continue
        discarded.add(name)
    return discarded


def extra_compiled_symbols(u: dict) -> list[str]:
    """Global symbols the compiled .o DEFINES that are not functions of this
    unit's split. objdiff ignores them, the linker does not: a body duplicated
    into a second unit or a name shared by two functions collides with the
    real definition at link time."""
    obj = _obj_path(u)
    if not obj.exists():
        return ["<no compiled object>"]
    own = {f["name"] for f in (u.get("functions") or [])}
    has_data = any(s["name"] != ".text" and int(s.get("size", 0) or 0)
                   for s in (u.get("sections") or []))
    n = unit_name(u)
    split = SPLIT_OBJ_DIR / (n[:-len(Path(n).suffix)] + ".o")
    # A global the unit's own split object defines too (an asm `entry` label
    # such as OS.c's __DBVECTOR) is the same symbol, not a duplicate.
    split_globals = elf_defined_globals(split) if split.exists() else {}
    discarded = discarded_weak_functions(u)
    extra = []
    for name, styp in elf_defined_globals(obj).items():
        if name in own or name in split_globals or name in discarded:
            continue
        if styp == 1 and has_data:  # STT_OBJECT in a unit that owns data: unverifiable here
            continue
        if styp == 2 and name not in _dol_symbol_names():
            # A library function the original link dead-stripped (DVDPause in
            # dvd.c): nothing in the DOL can reference it, so mwld strips it
            # from the compiled object too. Only a name the DOL defines
            # elsewhere is a real duplicate.
            continue
        extra.append(name)
    return sorted(extra)


_DOL_NAMES: set[str] | None = None


def _dol_symbol_names() -> set[str]:
    global _DOL_NAMES
    if _DOL_NAMES is None:
        _read_symbol_inventory()
    return _DOL_NAMES


SPLIT_OBJ_DIR = ROOT / "build" / "GPOE8P" / "obj"
SPLIT_CONFIG = ROOT / "build" / "GPOE8P" / "config.json"


def _links_before(a: Path, b: Path) -> bool:
    """Whether split object `a` comes before `b` in dtk's link order."""
    order = {o: i for i, o in enumerate(_split_objects())}
    return a in order and b in order and order[a] < order[b]


def _split_objects() -> list[Path]:
    """The split objects of the current split, as dtk lists them in
    build/GPOE8P/config.json. SPLIT_OBJ_DIR also keeps the objects of retired
    splits, and their references would make the result depend on the history
    of the build directory instead of on the checked-in configuration."""
    if not SPLIT_CONFIG.exists():
        sys.exit(f"missing {SPLIT_CONFIG.relative_to(ROOT)} — run ninja first")
    return [ROOT / u["object"] for u in json.loads(SPLIT_CONFIG.read_text())["units"]]


def missing_compiled_symbols(u: dict) -> list[str]:
    """Global symbols the ORIGINAL split object defines that the compiled .o
    does not (e.g. a .rodata double the split owns but the source keeps
    local/anonymous). Other units may reference them, so the link needs them.
    When nothing else does, localize_split_globals.py marks them local."""
    n = unit_name(u)
    split = SPLIT_OBJ_DIR / (n[:-len(Path(n).suffix)] + ".o")
    obj = _obj_path(u)
    if not split.exists() or not obj.exists():
        return []
    have = elf_defined_globals(obj)
    # dtk names uncovered bytes inside a split `gap_<sec>_<ADDR>_<kind>`;
    # nothing can reference those names, so the compiled object need not.
    return sorted(s for s in elf_defined_globals(split)
                  if s not in have and not _DTK_GAP_RE.match(s))


_DTK_GAP_RE = __import__("re").compile(r"gap_\d\d_[0-9A-F]{8}_\w+$")


def elf_global_object_layout(path: Path) -> dict[str, tuple[str, int]]:
    """Section name and offset of externally visible allocated object symbols.

    Local literals and non-object aliases are intentionally outside this check.
    Shared global/weak object aliases still retain their original addresses.
    """
    b = path.read_bytes()
    if b[:4] != b"\x7fELF":
        return {}
    be = lambda o, n=4: int.from_bytes(b[o:o + n], "big")
    shoff, shentsize, shnum, shstrndx = be(0x20), be(0x2E, 2), be(0x30, 2), be(0x32, 2)
    hdrs = [tuple(be(shoff + i * shentsize + k) for k in (0, 4, 8, 16, 20, 24))
            for i in range(shnum)]
    shstr = b[hdrs[shstrndx][3]:hdrs[shstrndx][3] + hdrs[shstrndx][4]]
    objects = {}
    for _, typ, _, off, size, link in hdrs:
        if typ != 2:
            continue
        stroff, strsize = hdrs[link][3:5]
        strtab = b[stroff:stroff + strsize]
        for o in range(off, off + size, 16):
            name_off, value, info, other, shndx = be(o), be(o + 4), b[o + 12], b[o + 13], be(o + 14, 2)
            if ((info >> 4) not in (1, 2) or (info & 0xF) != 1 or (other & 3) in (1, 2)
                    or not (0 < shndx < min(shnum, 0xFF00))):
                continue
            section_name, _, flags, _, _, _ = hdrs[shndx]
            if not flags & SHF_ALLOC:
                continue
            section = shstr[section_name:shstr.index(b"\0", section_name)].decode()
            name = strtab[name_off:strtab.index(b"\0", name_off)].decode()
            objects[name] = (section, value)
    return objects


def global_data_layout_mismatch(u: dict) -> list[str]:
    """Reject moved named globals even when their unrelocated bytes are equal."""
    n = unit_name(u)
    split = SPLIT_OBJ_DIR / (n[:-len(Path(n).suffix)] + ".o")
    obj = _obj_path(u)
    if not split.exists() or not obj.exists():
        return []
    original, compiled = elf_global_object_layout(split), elf_global_object_layout(obj)
    return [f"{name}: {original[name][0]}+0x{original[name][1]:X} != "
            f"{compiled[name][0]}+0x{compiled[name][1]:X}"
            for name in sorted(original.keys() & compiled.keys())
            if original[name] != compiled[name]]


def stripped_functions(u: dict, split: Path, obj: Path) -> dict[str, int]:
    """Compiled functions the original split lacks and mwld dead-strips
    (unreferenced, not a DOL symbol, or a discarded weak copy): name -> size."""
    in_split = set(elf_function_sizes(split, local=True))
    discarded = discarded_weak_functions(u)
    return {name: size for name, size in elf_function_sizes(obj, local=True).items()
            if name not in in_split and (name not in _dol_symbol_names() or name in discarded)}


def section_size_mismatch(u: dict) -> list[str]:
    """Allocated sections whose byte size differs between the original split
    object and the compiled object. objdiff scores functions, not trailing
    padding: a unit can be 100% on every function yet be 4-16 bytes short,
    which shifts every later address and breaks the DOL hash."""
    n = unit_name(u)
    split = SPLIT_OBJ_DIR / (n[:-len(Path(n).suffix)] + ".o")
    obj = _obj_path(u)
    if not split.exists() or not obj.exists():
        return []
    a, b = elf_alloc_sections(split), elf_alloc_sections(obj)
    if ".text" in b:  # functions mwld will dead-strip (see extra_compiled_symbols)
        stripped = stripped_functions(u, split, obj)
        b[".text"] -= sum(stripped.values())
        # mwld drops a stripped function's exception-table entries with it
        for section, size in stripped_exception_bytes(obj, set(stripped)).items():
            if section in b:
                b[section] -= size
        # MWCC can emit an implicit member and then a strong body with the
        # same name. Only the latter retains an ELF symbol; .mwcats still
        # records both parts, and MWLD drops the superseded one. Never
        # discount arbitrary uncovered bytes.
        b[".text"] -= mwcat_discarded_text_bytes(obj)
    for section, size in unreferenced_weak_object_bytes(obj).items():
        if section in b:
            b[section] -= size
            if not b[section]:
                del b[section]
    starts ={x["name"]: int((x.get("metadata") or {}).get("virtual_address") or -1)
              for x in u.get("sections") or []}
    return sorted(f"{s}:{a.get(s, 0)}!={b.get(s, 0)}" for s in set(a) | set(b)
                  if a.get(s, 0) != b.get(s, 0)
                  and not _is_alignment_pad(split, s, starts.get(s, -1), a.get(s, 0), b.get(s, 0)))


@functools.lru_cache(maxsize=1)
def _section_owners(report: Path, mtime_ns: int, size: int) -> dict:
    """Index original section starts; duplicate owners remain ambiguous."""
    owners = {}
    for unit in json.loads(report.read_text()).get("units", []):
        if (unit.get("metadata") or {}).get("module_name") not in (None, "psov3"):
            continue
        for section in unit.get("sections") or []:
            start = (section.get("metadata") or {}).get("virtual_address")
            if start is not None and int(section.get("size", 0) or 0):
                owners.setdefault((section["name"], int(start)), []).append(unit_name(unit))
    return owners


def _following_section_alignment(section: str, start: int) -> int | None:
    """Require alignment from the original and any compiled following owner."""
    if not REPORT.exists():
        return None
    stat = REPORT.stat()
    owners = _section_owners(REPORT, stat.st_mtime_ns, stat.st_size).get((section, start), [])
    if len(owners) != 1:
        return None
    split = SPLIT_OBJ_DIR / Path(owners[0]).with_suffix(".o")
    if not split.exists():
        return None
    alignment = elf_alloc_section_layout(split).get(section, (0, 0))[1]
    if alignment <= 0 or alignment & (alignment - 1):
        return None
    # A scan can promote the next unit at the same time. Its compiled object
    # must recreate the tail too, even if the report still marks it unlinked.
    compiled = OBJ_DIR / Path(owners[0]).with_suffix(".o")
    if compiled.exists():
        actual = elf_alloc_section_layout(compiled).get(section, (0, 0))[1]
        if actual <= 0 or actual & (actual - 1):
            return None
        alignment = min(alignment, actual)
    return alignment


def _tail_has_named_symbols(path: Path, section: str, start: int, end: int) -> bool:
    """Padding cannot contain an original object, function, or public label."""
    b = path.read_bytes()
    if b[:4] != b"\x7fELF":
        return True
    be = lambda o, n=4: int.from_bytes(b[o:o + n], "big")
    shoff, shentsize, shnum, shstrndx = be(0x20), be(0x2E, 2), be(0x30, 2), be(0x32, 2)
    headers = [(be(shoff + i * shentsize), be(shoff + i * shentsize + 4),
                be(shoff + i * shentsize + 16), be(shoff + i * shentsize + 20),
                be(shoff + i * shentsize + 24)) for i in range(shnum)]
    _, _, stroff, strsize, _ = headers[shstrndx]
    strings = b[stroff:stroff + strsize]
    section_index = next((i for i, (name, *_rest) in enumerate(headers)
                          if strings[name:strings.index(b"\0", name)].decode() == section), None)
    if section_index is None:
        return True
    for _, typ, off, size, link in headers:
        if typ != 2:
            continue
        _, _, stroff, strsize, _ = headers[link]
        strings = b[stroff:stroff + strsize]
        for pos in range(off, off + size, 16):
            info = b[pos + 12]
            if be(pos + 14, 2) != section_index or info & 0xF in (3, 4):
                continue
            if info >> 4 not in (1, 2) and info & 0xF not in (1, 2):
                continue
            name_off = be(pos)
            name = strings[name_off:strings.index(b"\0", name_off)].decode()
            if not name or _DTK_GAP_RE.match(name):
                continue
            value, extent = be(pos + 4), max(1, be(pos + 8))
            if value < end and value + extent > start:
                return True
    return False


def _is_alignment_pad(split: Path, section: str, start: int, split_size: int, size: int) -> bool:
    """Accept only original zero tails that the linker recreates by alignment.

    Retain the established sub-eight-byte tail rule. A larger tail requires
    the immediately following original object's explicit ELF alignment; an
    aligned end address alone does not prove padding.
    """
    if not (0 < size < split_size and start >= 0):
        return False
    end = start + split_size
    tail = elf_section_bytes(split, section)
    if _tail_has_named_symbols(split, section, size, split_size):
        return False
    if split_size - size < 8 and end % 8 == 0:
        return tail is None or not any(tail[size:])
    alignment = _following_section_alignment(section, end)
    if split_size - size < 8:
        # A partial claim can end inside a TU's pool, before a 4-aligned object.
        return (alignment is not None and alignment >= 4 and (tail is None or not any(tail[size:]))
                and ((start + size + alignment - 1) & -alignment) == end)
    if alignment is None or alignment <= 8 or tail is None or any(tail[size:]):
        return False
    return ((start + size + alignment - 1) & -alignment) == end


def elf_section_bytes(path: Path, section: str) -> bytes | None:
    """Contents of `section` in a BE ELF32 .o, or None for NOBITS (.bss)."""
    b = path.read_bytes()
    be = lambda o, n=4: int.from_bytes(b[o:o + n], "big")
    shoff, shentsize, shnum, shstrndx = be(0x20), be(0x2E, 2), be(0x30, 2), be(0x32, 2)
    strbase = be(shoff + shstrndx * shentsize + 16)
    for i in range(shnum):
        o = shoff + i * shentsize
        name = b[strbase + be(o):b.index(b"\0", strbase + be(o))].decode()
        if name == section:
            return None if be(o + 4) == 8 else b[be(o + 16):be(o + 16) + be(o + 20)]
    return None


def elf_function_sizes(path: Path, local: bool = False) -> dict[str, int]:
    """{name: st_size} of every defined GLOBAL/WEAK (and with `local`, LOCAL)
    function in a BE ELF32 .o."""
    b = path.read_bytes()
    if b[:4] != b"\x7fELF":
        return {}
    be = lambda o, n=4: int.from_bytes(b[o:o + n], "big")
    shoff, shentsize, shnum = be(0x20), be(0x2E, 2), be(0x30, 2)
    hdrs = [(be(shoff + i * shentsize + 4), be(shoff + i * shentsize + 16),
             be(shoff + i * shentsize + 20), be(shoff + i * shentsize + 24)) for i in range(shnum)]
    out = {}
    for typ, off, size, link in hdrs:
        if typ != 2:
            continue
        _, stroff, strsize, _ = hdrs[link]
        strtab = b[stroff:stroff + strsize]
        for o in range(off, off + size, 16):
            name_off, st_size, info, shndx = be(o), be(o + 8), b[o + 12], be(o + 14, 2)
            if (info >> 4 in (1, 2) or local) and info & 0xF == 2 and 0 < shndx < 0xFF00:
                out[strtab[name_off:strtab.index(b"\0", name_off)].decode()] = st_size
    return out


def unreferenced_weak_object_bytes(path: Path) -> dict[str, int]:
    """{section: bytes} of WEAK data objects that no relocation in the object
    references and the DOL does not name: the local statics of an SDK inline
    the unit never calls (math.h sqrtf's _half/_three). mwld dead-strips them."""
    b = path.read_bytes()
    if b[:4] != b"\x7fELF":
        return {}
    be = lambda o, n=4: int.from_bytes(b[o:o + n], "big")
    shoff, shentsize, shnum, shstrndx = be(0x20), be(0x2E, 2), be(0x30, 2), be(0x32, 2)
    hdrs = [(be(shoff + i * shentsize), be(shoff + i * shentsize + 4),
             be(shoff + i * shentsize + 16), be(shoff + i * shentsize + 20),
             be(shoff + i * shentsize + 24)) for i in range(shnum)]  # name, type, off, size, link
    shstr = b[hdrs[shstrndx][2]:hdrs[shstrndx][2] + hdrs[shstrndx][3]]
    referenced = {be(o + 4) >> 8 for _, typ, off, size, _ in hdrs if typ == 4  # SHT_RELA
                  for o in range(off, off + size, 12)}
    dol = _dol_symbol_names()
    out: dict[str, int] = {}
    for _, typ, off, size, link in hdrs:
        if typ != 2:
            continue
        strtab = b[hdrs[link][2]:hdrs[link][2] + hdrs[link][3]]
        for i, o in enumerate(range(off, off + size, 16)):
            name_off, st_size, info, shndx = be(o), be(o + 8), b[o + 12], be(o + 14, 2)
            if info >> 4 != 2 or info & 0xF != 1 or not 0 < shndx < 0xFF00 or i in referenced:
                continue
            if strtab[name_off:strtab.index(b"\0", name_off)].decode() in dol:
                continue
            sec_name = shstr[hdrs[shndx][0]:shstr.index(b"\0", hdrs[shndx][0])].decode()
            out[sec_name] = out.get(sec_name, 0) + st_size
    return out


def stripped_exception_bytes(path: Path, names: set[str]) -> dict[str, int]:
    """Bytes of `extabindex` (one 12-byte entry each) and of the `extab` entries
    they point at that belong to the functions in `names`, in a BE ELF32 .o."""
    if not names:
        return {}
    b = path.read_bytes()
    be = lambda o, n=4: int.from_bytes(b[o:o + n], "big")
    shoff, shentsize, shnum, shstrndx = be(0x20), be(0x2E, 2), be(0x30, 2), be(0x32, 2)
    hdrs = [tuple(be(shoff + i * shentsize + k) for k in (0, 4, 16, 20, 24, 28)) for i in range(shnum)]
    shstr = hdrs[shstrndx][2]
    sec_name = lambda i: b[shstr + hdrs[i][0]:b.index(b"\0", shstr + hdrs[i][0])].decode()
    index = next((i for i in range(shnum) if sec_name(i) == "extabindex"), None)
    extab = next((i for i in range(shnum) if sec_name(i) == "extab"), None)
    rela = next((i for i in range(shnum) if hdrs[i][1] == 4 and hdrs[i][5] == index), None)
    if index is None or extab is None or rela is None:
        return {}
    symtab = hdrs[hdrs[rela][4]]
    strtab = hdrs[symtab[4]][2]

    def symbol(n):
        o = symtab[2] + n * 16
        name = b[strtab + be(o):b.index(b"\0", strtab + be(o))].decode()
        return name, be(o + 4)
    func, entry = {}, {}
    for o in range(hdrs[rela][2], hdrs[rela][2] + hdrs[rela][3], 12):
        off, info, addend = be(o), be(o + 4), int.from_bytes(b[o + 8:o + 12], "big", signed=True)
        name, value = symbol(info >> 8)
        if off % 12 == 0:
            func[off // 12] = name
        elif off % 12 == 8:
            entry[off // 12] = value + addend
    starts = sorted(set(entry.values())) + [hdrs[extab][3]]
    out = {"extab": 0, "extabindex": 0}
    for k, name in func.items():
        if name in names:
            out["extabindex"] += 12
            if k in entry:
                start = entry[k]
                out["extab"] += next(x for x in starts if x > start) - start
    return out


def section_alignment_mismatch(u: dict) -> list[str]:
    """Reject padding the compiler's section alignment would add at link time.

    A recovered switch can have exact instructions, table bytes and section
    size while MWCC aligns its data to eight bytes at an original address
    divisible only by four. objdiff cannot detect that linker insertion.
    """
    obj = _obj_path(u)
    if not obj.exists():
        return []
    compiled = elf_alloc_section_layout(obj)
    bad = []
    for section in u.get("sections") or []:
        address = (section.get("metadata") or {}).get("virtual_address")
        size, alignment = compiled.get(section["name"], (0, 0))
        if address is not None and size and alignment and int(address) % alignment:
            bad.append(f'{section["name"]}:0x{int(address):08X} needs {alignment}-byte alignment')
    return sorted(bad)


def elf_function_order_by_section(path: Path) -> dict[str, list[str]]:
    """Defined functions in address order within each allocated ELF section.

    ELF section indices are object-local: .init can precede .text in a split
    object and follow it in the compiler's object without changing link order.
    """
    b = path.read_bytes()
    if b[:4] != b"\x7fELF":
        return {}
    be = lambda o, n=4: int.from_bytes(b[o:o + n], "big")
    shoff, shentsize, shnum, shstrndx = be(0x20), be(0x2E, 2), be(0x30, 2), be(0x32, 2)
    hdrs = [tuple(be(shoff + i * shentsize + k) for k in (0, 4, 8, 16, 20, 24))
            for i in range(shnum)]
    shstr = b[hdrs[shstrndx][3]:hdrs[shstrndx][3] + hdrs[shstrndx][4]]
    rows = []
    for _, typ, _, off, size, link in hdrs:
        if typ != 2:
            continue
        stroff, strsize = hdrs[link][3:5]
        strtab = b[stroff:stroff + strsize]
        for o in range(off, off + size, 16):
            name_off, val, info, shndx = be(o), be(o + 4), b[o + 12], be(o + 14, 2)
            if info & 0xF != 2 or not (0 < shndx < min(shnum, 0xFF00)):
                continue
            section_name, _, flags, _, _, _ = hdrs[shndx]
            if not flags & SHF_ALLOC:
                continue
            section = shstr[section_name:shstr.index(b"\0", section_name)].decode()
            name = strtab[name_off:strtab.index(b"\0", name_off)].decode()
            rows.append((section, val, name))
    order: dict[str, list[str]] = {}
    for section, _, name in sorted(rows):
        order.setdefault(section, []).append(name)
    return order


def elf_function_order(path: Path) -> list[str]:
    """Functions ordered by section name, then address within that section."""
    return [name for names in elf_function_order_by_section(path).values() for name in names]


def function_order_mismatch(u: dict) -> list[str]:
    n = unit_name(u)
    split = SPLIT_OBJ_DIR / (n[:-len(Path(n).suffix)] + ".o")
    obj = _obj_path(u)
    if not split.exists() or not obj.exists():
        return []
    a, b = elf_function_order_by_section(split), elf_function_order_by_section(obj)
    common = {name for names in a.values() for name in names} & {
        name for names in b.values() for name in names}
    a = {section: kept for section, names in a.items()
         if (kept := [name for name in names if name in common])}
    b = {section: kept for section, names in b.items()
         if (kept := [name for name in names if name in common])}
    return [] if a == b else ["function order differs from the split object"]


def extra_compiled_sections(u: dict) -> list[str]:
    """Allocated sections the compiled .o emits that the unit's split does not
    own (e.g. a class vtable in .data still living in the auto data unit).
    Linking such an object injects bytes / duplicate symbols, so it is not
    linkable until the split claims that data range."""
    obj = OBJ_DIR / (unit_name(u)[:-len(Path(unit_name(u)).suffix)] + ".o")
    if not obj.exists():
        return ["<no compiled object>"]
    have = {s["name"] for s in (u.get("sections") or []) if int(s.get("size", 0) or 0)}
    return sorted(n for n in elf_alloc_sections(obj) if n not in have)


def report_scores_exact(u: dict) -> bool:
    fns = u.get("functions") or []
    sections = [s for s in u.get("sections") or []
                if int(s.get("size", 0) or 0)]
    if not fns:
        # Original table-only objects have no functions to recover. Require
        # actual, completely matched data; an empty report or unclassified
        # executable bytes must never earn promotion this way. The ordinary
        # object, symbol, layout and alignment guards still apply below.
        data_sections = {".data", ".rodata", ".sdata", ".sdata2", ".bss",
                         ".sbss", ".ctors", ".dtors"}
        if not sections or any(s.get("name") not in data_sections for s in sections):
            return False
    if any(f.get("fuzzy_match_percent", 0) != 100 for f in fns):
        return False
    for s in sections:
        if s.get("fuzzy_match_percent", 0) != 100 and not _stripped_exception_entries(u, s.get("name")):
            return False
    return True


def _stripped_exception_entries(u: dict, section: str) -> bool:
    """True when `section` (extab/extabindex) holds entries of functions mwld
    dead-strips: objdiff scores them as extra bytes, the linker drops them.
    section_size_mismatch then requires the rest to have the original size."""
    if section not in ("extab", "extabindex"):
        return False
    n = unit_name(u)
    split = SPLIT_OBJ_DIR / (n[:-len(Path(n).suffix)] + ".o")
    obj = _obj_path(u)
    if not split.exists() or not obj.exists():
        return False
    stripped = stripped_functions(u, split, obj)
    return stripped_exception_bytes(obj, set(stripped)).get(section, 0) > 0


def unit_is_exact(u: dict) -> bool:
    return (report_scores_exact(u)
            and not extra_compiled_sections(u) and not extra_compiled_symbols(u)
            and not missing_compiled_symbols(u) and not global_data_layout_mismatch(u)
            and not section_size_mismatch(u)
            and not section_alignment_mismatch(u)
            and not function_order_mismatch(u))


def load_report() -> list[dict]:
    if not REPORT.exists():
        sys.exit(f"missing {REPORT} — run ninja first")
    return json.load(open(REPORT))["units"]


def scan(write: bool) -> int:
    symbol_snapshot, symbols = _read_symbol_inventory()
    units = load_report()
    linked = set(_read_list(LINKED))
    skip = set(_read_list(SKIP))
    exact = {}
    for u in units:
        meta = u.get("metadata") or {}
        if meta.get("module_name") not in (None, "psov3"):
            continue
        source = meta.get("source_path") or ""
        if not source.startswith(("src/pso/", "src/musyx/", "libs/", "build/GPOE8P/orig_asm/")):
            continue
        n = unit_name(u)
        exact[n] = unit_is_exact(u) or (n in linked and _proven_by_dol(u))
    add = sorted(n for n, ok in exact.items() if ok and n not in linked and n not in skip)
    blocked = {}
    for u in units:
        n = unit_name(u)
        if n in exact and not exact[n]:
            fns = u.get("functions") or []
            if fns and all(f.get("fuzzy_match_percent", 0) == 100 for f in fns):
                # Every reason, not only the first: localize_split_globals.py
                # plans only units whose sole reasons are `missing`, and a unit
                # that is also blocked otherwise would not link after it.
                reasons = []
                for kind, check in (("section", extra_compiled_sections),
                                    ("symbol", extra_compiled_symbols),
                                    ("missing", missing_compiled_symbols),
                                    ("data-layout", global_data_layout_mismatch),
                                    ("size", section_size_mismatch),
                                    ("order", function_order_mismatch),
                                    ("alignment", section_alignment_mismatch)):
                    reasons += [f"{kind} {x}" for x in check(u)]
                if reasons:
                    # Data that does not match yet blocks the unit as well.
                    reasons += [f"data {s['name']}:{s.get('fuzzy_match_percent', 0)}%"
                                for s in u.get("sections") or []
                                if int(s.get("size", 0) or 0) and s.get("fuzzy_match_percent", 0) != 100]
                    blocked[n] = reasons
    regress = sorted(n for n in linked if not exact.get(n, False))
    keep = sorted(n for n in linked if exact.get(n, False))
    want_active = _force_active_names(set(keep + add), symbols) if write else []
    # Finish all input-dependent work before touching even the blocked report.
    _check_symbol_inventory(symbol_snapshot)
    if blocked:
        from collections import Counter
        c = Counter(v[0].split(" ")[0] + (":" + v[0].split(" ")[1] if v[0].startswith("section") else "")
                    for v in blocked.values())
        print(f"exact-by-objdiff but NOT linkable ({len(blocked)}): compiled object emits "
              f"sections/symbols the split does not own -> " + ", ".join(f"{k}:{v}" for k, v in c.most_common(6)))
        (CFG_DIR / "linked_units_blocked.json").write_text(json.dumps(blocked, indent=1, sort_keys=True))
        print("  details: config/GPOE8P/psov3/linked_units_blocked.json "
              "(section: claim the data range into the unit's split; "
              "missing: tools/localize_split_globals.py)")
    code = sum(1 for _ in add)
    print(f"linked now: {len(linked)}   exact candidates to add: {code}   "
          f"regressed (drop): {len(regress)}   skipped (known link-breakers): {len(skip)}")
    for n in regress[:20]:
        print(f"  regress  {n}")
    if write:
        _write_list(LINKED, keep + add,
                    "Units linked into the DOL from compiled source")
        print(f"wrote {LINKED.relative_to(ROOT)}: {len(keep) + len(add)} units")
        if add:
            (CFG_DIR / "linked_units_pending.txt").write_text("\n".join(add) + "\n")
            print("  newly added set recorded in linked_units_pending.txt (for bisect)")
        _update_force_active(want_active, write=True)
    return 0


SYMBOLS = CFG_DIR / "symbols.txt"
SPLITS = CFG_DIR / "splits.txt"
_SYM_RE = __import__("re").compile(r"^(\S+) = (\.\w+):0x([0-9A-Fa-f]+); // (.*)$")


def _read_symbol_inventory() -> tuple[bytes, list[tuple[str, int, str]]]:
    """Read one nonempty inventory; never trust names cached by an earlier scan."""
    global _DOL_NAMES
    try:
        snapshot = SYMBOLS.read_bytes()
        lines = snapshot.decode("utf-8").splitlines()
    except (OSError, UnicodeError) as exc:
        sys.exit(f"cannot read symbol inventory {SYMBOLS}: {exc}; no outputs written")
    symbols = [(m.group(1), int(m.group(3), 16), m.group(4))
               for line in lines if (m := _SYM_RE.match(line))]
    if not symbols:
        sys.exit(f"symbol inventory {SYMBOLS} contains no symbols; no outputs written")
    _DOL_NAMES = {name for name, _, _ in symbols}
    return snapshot, symbols


def _check_symbol_inventory(snapshot: bytes) -> None:
    """Refuse a stale plan if symbols.txt changed while the scan ran."""
    try:
        current = SYMBOLS.read_bytes()
    except OSError as exc:
        sys.exit(f"cannot recheck symbol inventory {SYMBOLS}: {exc}; no outputs written")
    if current != snapshot:
        sys.exit(f"symbol inventory {SYMBOLS} changed during scan; no outputs written")


def elf_undefined_symbols(path: Path) -> set[str]:
    """Names of UNDEFINED symbols in a BE ELF32 .o = what it references elsewhere."""
    b = path.read_bytes()
    if b[:4] != b"\x7fELF":
        return set()
    be = lambda o, n=4: int.from_bytes(b[o:o + n], "big")
    shoff, shentsize, shnum = be(0x20), be(0x2E, 2), be(0x30, 2)
    hdrs = [(be(shoff + i * shentsize + 4), be(shoff + i * shentsize + 16),
             be(shoff + i * shentsize + 20), be(shoff + i * shentsize + 24)) for i in range(shnum)]
    out = set()
    for typ, off, size, link in hdrs:
        if typ != 2:
            continue
        _, stroff, strsize, _ = hdrs[link]
        strtab = b[stroff:stroff + strsize]
        for o in range(off, off + size, 16):
            if be(o + 14, 2) == 0 and be(o):
                name_off = be(o)
                out.add(strtab[name_off:strtab.index(b"\0", name_off)].decode())
    return out


def _unit_ranges(names: set[str]) -> list[tuple[int, int, str]]:
    """[(start, end, unit)] for every section range of the given units."""
    import re
    out, cur = [], None
    for line in SPLITS.read_text().splitlines():
        m = re.match(r"^(\S+):\s*$", line)
        if m:
            cur = m.group(1)
            continue
        m = re.match(r"^\s+(\.\w+)\s+start:0x([0-9A-Fa-f]+)\s+end:0x([0-9A-Fa-f]+)", line)
        if m and cur in names:
            out.append((int(m.group(2), 16), int(m.group(3), 16), cur))
    out.sort()
    return out


CONFIG_YML = CFG_DIR / "config.yml"
_FA_BEGIN = "# --- force_active (BEGIN) ---"
_FA_END = "# --- force_active (END) ---"


def _read_force_active() -> list[str]:
    txt = CONFIG_YML.read_text()
    if _FA_BEGIN not in txt:
        return []
    block = txt.split(_FA_BEGIN, 1)[1].split(_FA_END, 1)[0]
    return [l.strip()[2:].strip().strip('"') for l in block.splitlines() if l.strip().startswith("- ")]


def _yaml_scalar(name: str) -> str:
    """Quote names YAML cannot read bare (MWCC thunks begin with `@`)."""
    return f'"{name}"' if not (name[:1].isalpha() or name[:1] == "_") else name


def _write_force_active(names: list[str]) -> None:
    txt = CONFIG_YML.read_text()
    body = "\n".join(f"  - {_yaml_scalar(n)}" for n in sorted(set(names)))
    block = f"{_FA_BEGIN}\nforce_active:\n{body}\n{_FA_END}\n"
    if _FA_BEGIN in txt:
        head = txt.split(_FA_BEGIN, 1)[0]
        tail = txt.split(_FA_END, 1)[1].lstrip("\n")
        txt = head + block + tail
    else:
        txt = txt.rstrip("\n") + "\n" + block
    CONFIG_YML.write_text(txt)


def _force_active_names(linked: set[str], symbols: list[tuple[str, int, str]]) -> list[str]:
    """mwld dead-strips any function/object that nothing references, and a
    compiled object cannot carry the "keep" bit dtk stamps on split objects.
    dtk emits every name in config.yml's `force_active:` list into the linker
    script's FORCEACTIVE block, so every global symbol inside a LINKED unit
    that no other object references goes there — otherwise the linked DOL
    silently loses bytes and the hash fails. (symbols.txt `force_active`
    attributes are NOT durable: dtk rewrites symbols.txt without them.)"""
    import bisect
    ranges = _unit_ranges(linked)
    starts = [r[0] for r in ranges]
    referenced: set[str] = set()
    for obj in _split_objects():
        referenced |= elf_undefined_symbols(obj)
    want = []
    for name, addr, attrs in symbols:
        k = bisect.bisect_right(starts, addr) - 1
        if k < 0 or not (ranges[k][0] <= addr < ranges[k][1]):
            continue
        if "type:function" not in attrs and "type:object" not in attrs:
            continue
        if "scope:local" in attrs or "stripped" in attrs or "noexport" in attrs:
            continue
        if name not in referenced:
            want.append(name)
    return want


def _update_force_active(want: list[str], write: bool) -> None:
    have = _read_force_active()
    add = sorted(set(want) - set(have))
    drop = sorted(set(have) - set(want))
    print(f"force_active: {len(have)} listed, +{len(add)} unreferenced symbol(s) in linked units, -{len(drop)} stale")
    if write and (add or drop):
        _write_force_active(want)
        print(f"  wrote {CONFIG_YML.relative_to(ROOT)} force_active block ({len(want)} names); "
              "dtk re-splits + regenerates ldscript FORCEACTIVE on the next ninja")


def force_active(write: bool) -> int:
    snapshot, symbols = _read_symbol_inventory()
    want = _force_active_names(set(_read_list(LINKED)), symbols)
    _check_symbol_inventory(snapshot)
    _update_force_active(want, write)
    return 0


def _proven_by_dol(u: dict) -> bool:
    """A linked SDK/runtime unit (libs/) whose object the checks above reject
    only for what mwld resolves at link time: the SDK headers' inline-math
    local statics, statics the compiler renames, literals it pools apart.
    The DOL hash, which every build checks, is the proof for these."""
    source = (u.get("metadata") or {}).get("source_path") or ""
    return source.startswith("libs/") and report_scores_exact(u)


def check() -> int:
    units = load_report()
    linked = set(_read_list(LINKED))
    exact = {unit_name(u): unit_is_exact(u) or (unit_name(u) in linked and _proven_by_dol(u))
             for u in units}
    bad = [n for n in _read_list(LINKED) if not exact.get(n, False)]
    if bad:
        print(f"link_units check: {len(bad)} linked unit(s) no longer exact:")
        for n in bad[:40]:
            print("  " + n)
        return 1
    print(f"link_units check: OK ({len(_read_list(LINKED))} linked units all exact)")
    return 0


def _dol_ok() -> bool:
    if not DOL.exists():
        return False
    want = SHA_FILE.read_text().split()[0]
    return hashlib.sha1(DOL.read_bytes()).hexdigest() == want


def _relink(names: list[str]) -> bool:
    _write_list(LINKED, names, "bisect probe — will be rewritten")
    subprocess.run([str(PY), "configure.py", "--target", "psov3"], cwd=ROOT,
                   check=True, stdout=subprocess.DEVNULL)
    r = subprocess.run(["ninja", str(DOL.relative_to(ROOT))], cwd=ROOT,
                       stdout=subprocess.DEVNULL, stderr=subprocess.PIPE, text=True)
    if r.returncode != 0:
        tail = r.stderr.strip().splitlines()[-3:]
        print("    link failed: " + " | ".join(tail))
        return False
    return _dol_ok()


def bisect() -> int:
    pending_path = CFG_DIR / "linked_units_pending.txt"
    pending = _read_list(pending_path)
    if not pending:
        sys.exit("nothing pending — run `scan --write` first")
    linked = _read_list(LINKED)
    base = [n for n in linked if n not in set(pending)]
    print(f"bisect: base {len(base)} known-good, probing {len(pending)} new units")
    if not _relink(base):
        sys.exit("base set already fails the DOL hash — fix that first")
    good: list[str] = []
    bad: list[str] = []
    work = [pending]
    while work:
        grp = work.pop()
        if _relink(base + good + grp):
            good += grp
            print(f"  ok   +{len(grp)}  (linked {len(base) + len(good)})")
            continue
        if len(grp) == 1:
            bad += grp
            print(f"  BAD  {grp[0]}")
            continue
        mid = len(grp) // 2
        work.append(grp[mid:])
        work.append(grp[:mid])
    _write_list(LINKED, base + good,
                "Units linked into the DOL from compiled source")
    if bad:
        _write_list(SKIP, _read_list(SKIP) + bad,
                    "exact-by-objdiff units that break the DOL hash when linked "
                    "(investigate: section order/alignment/local symbols)")
    pending_path.unlink(missing_ok=True)
    print(f"bisect done: linked {len(base) + len(good)}, skipped {len(bad)}")
    return 0 if _relink(base + good) else 1


def main() -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    sub = ap.add_subparsers(dest="cmd", required=True)
    s = sub.add_parser("scan")
    s.add_argument("--write", action="store_true")
    sub.add_parser("check")
    sub.add_parser("bisect")
    f = sub.add_parser("force-active", help="tag unreferenced symbols of linked units in symbols.txt")
    f.add_argument("--write", action="store_true")
    a = ap.parse_args()
    if a.cmd == "scan":
        return scan(a.write)
    if a.cmd == "check":
        return check()
    if a.cmd == "force-active":
        return force_active(a.write)
    return bisect()


if __name__ == "__main__":
    sys.exit(main())
