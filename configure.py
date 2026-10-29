#!/usr/bin/env python3

###
# PSO Episode I & II Plus decompilation build configuration.
#
# Generates build.ninja, objdiff.json, and compile_commands.json
# using the standard dtk-template project generator (tools/project.py).
#
# Usage:
#   python3 configure.py                    # Generate build files
#   python3 configure.py --help             # Show all options
#
# After generating:
#   ninja                                   # Build & verify (default)
#   ninja all_source                        # Compile all source objects
#   ninja progress                          # Show progress after build
###

import argparse
import bisect
import re
import sys
from pathlib import Path
from typing import Any, Dict, List, Tuple
from tools.pso_assets import add_build_steps as add_data_build_steps

from tools.project import (
    Object,
    ProgressCategory,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

# ===================================================================
# Units
# ===================================================================
# A unit is LINKED into the DOL from its compiled object when every function
# and data section in it matches. linked_units.txt is the only authority for
# that; tools/link_units.py maintains it.
_LINKED_UNITS_FILE = Path(__file__).resolve().parent / "config" / "GPOE8P" / "psov3" / "linked_units.txt"
_LINKED_UNITS = set()
if _LINKED_UNITS_FILE.exists():
    for _line in _LINKED_UNITS_FILE.read_text().splitlines():
        _line = _line.split("#", 1)[0].strip()
        if _line:
            _LINKED_UNITS.add(_line)


def Unit(name: str, **kwargs: Any) -> Object:
    """A translation unit (name == its splits.txt unit == its source path)."""
    return Object(name in _LINKED_UNITS, name, **kwargs)


def _units_from_splits(prefix: str) -> List[Tuple[str, int]]:
    """(unit, link address) of every `prefix` unit in splits.txt, in link order.
    A unit without .text takes the address of the last .text before it."""
    path = Path(__file__).resolve().parent / "config" / "GPOE8P" / "psov3" / "splits.txt"
    out: List[Tuple[str, int]] = []
    unit, addr = None, 0
    for line in path.read_text().splitlines() if path.exists() else []:
        if line and not line[0].isspace() and line.rstrip().endswith(":"):
            unit = line.rstrip()[:-1]
            if unit.startswith(prefix):
                out.append((unit, addr))
        m = re.match(r"\s+\.text\s+start:0x([0-9A-Fa-f]+)", line)
        if m:
            addr = int(m.group(1), 16)
            if out and out[-1][0] == unit:
                out[-1] = (unit, addr)
    return out


def _switch(flags: List[str], *switches: str, drop: Tuple[str, ...] = ()) -> List[str]:
    """`flags` with each of `switches` replacing the switch of the same name
    in place (`-O4,p` replaces `-O4,s`, `-inline auto` replaces `-inline off`)
    or appended, and the switches named in `drop` removed."""
    def name(f: str) -> str:
        return "-O" if re.match(r"-O\d", f) else f.split(" ", 1)[0]
    new = {name(s): s for s in switches}
    out = [new.pop(name(f), f) for f in flags if name(f) not in drop]
    return out + list(new.values())


# ===================================================================
# Version Configuration
# ===================================================================
DEFAULT_VERSION = "GPOE8P"
VERSIONS = [
    "GPOE8P",  # USA v1.02
]

# ===================================================================
# Argument Parsing
# ===================================================================
parser = argparse.ArgumentParser(
    description="PSO Episode I & II Plus decompilation build configuration"
)
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    nargs="?",
    help="script mode (default: configure)",
)
parser.add_argument(
    "-v", "--version",
    choices=VERSIONS,
    type=str,
    default=DEFAULT_VERSION,
    help=f"game version (default: {DEFAULT_VERSION})",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--non-matching",
    dest="non_matching",
    action="store_true",
    help="build non-matching objects",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate linker map file(s)",
)
parser.add_argument(
    "--dtk",
    metavar="BINARY",
    type=Path,
    help="path to decomp-toolkit binary",
)
parser.add_argument(
    "--objdiff",
    metavar="BINARY",
    type=Path,
    help="path to objdiff-cli binary",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers directory",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils",
)
parser.add_argument(
    "--sjiswrap",
    metavar="EXE",
    type=Path,
    help="path to sjiswrap.exe",
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine",
    )
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)
parser.add_argument(
    "--no-progress",
    dest="progress",
    action="store_false",
    help="disable progress calculation",
)
parser.add_argument(
    "--target",
    choices=["psov3", "main"],
    default="psov3",
    help="DOL target to build (default: psov3 — the game binary)",
)
parser.add_argument("--data-replacements", type=Path, metavar="DIR",
                    help="verify exact runtime data replacements under DIR/files/")
args = parser.parse_args()

# ===================================================================
# Project Configuration
# ===================================================================
config = ProjectConfig()
config.version = str(args.version)
config.build_dir = args.build_dir
config.non_matching = args.non_matching
config.generate_map = args.map
config.dtk_path = args.dtk
config.objdiff_path = args.objdiff
config.compilers_path = args.compilers
config.binutils_path = args.binutils
config.sjiswrap_path = getattr(args, "sjiswrap", None)
config.progress = args.progress
if not is_windows():
    config.wrapper = getattr(args, "wrapper", None)

# Don't build asm overrides unless --non-matching
if not config.non_matching:
    config.asm_dir = None

# PSO uses `.rel` as a generic data-file extension. `movie.rel` is the only
# verified standard CodeWarrior REL module; it needs its own non-empty module
# config, symbols, splits, and source plan before enabling REL linking.
config.build_rels = False

# ---------------------------------------------------------------------------
# Tool versions (from dtk-template)
# ---------------------------------------------------------------------------
config.binutils_tag = "2.42-1"
config.compilers_tag = "20251118"
config.dtk_tag = "v1.8.4"
config.objdiff_tag = "v3.6.1"
config.sjiswrap_tag = "v1.2.2"
config.wibo_tag = "1.0.3"

# ---------------------------------------------------------------------------
# Paths — select DOL target
# ---------------------------------------------------------------------------
if args.target == "psov3":
    config.config_path = Path("config") / config.version / "psov3" / "config.yml"
    config.check_sha_path = Path("config") / config.version / "psov3" / "build.sha1"
else:
    config.config_path = Path("config") / config.version / "config.yml"
    config.check_sha_path = Path("config") / config.version / "build.sha1"
    # Separate output namespace (build/GPOE8P-main/) so switching targets
    # doesn't clobber the psov3 target's split/obj artifacts.
    config.version = f"{config.version}-main"

# ---------------------------------------------------------------------------
# Assembler flags
# ---------------------------------------------------------------------------
config.asflags = [
    "-mgekko",
    "--strip-local-absolute",
    "-I include",
    f"-I build/{config.version}/include",
]

# ---------------------------------------------------------------------------
# Linker flags
# ---------------------------------------------------------------------------
config.ldflags = [
    "-fp hardware",
    "-nodefaults",
]
if args.map:
    config.ldflags.append("-mapunused")

# Linker version
config.linker_version = "GC/2.6"

# Shift JIS: disabled by default, enable per-object if needed
config.shift_jis = False

# ===================================================================
# Compiler Flags
# ===================================================================

# Base flags: CodeWarrior for GameCube, matching the original build.
cflags_base = [
    "-nodefaults",
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-Cpp_exceptions off",
    "-RTTI off",
    "-O4,p",
    "-inline auto",
    "-str reuse",
    "-maxerrors 1",
    "-nosyspath",
    # Generated headers only — per-group include paths live in
    # cflags_pso / cflags_dolphin / cflags_runtime below so SDK code
    # never sees game headers and vice versa.
    f"-i build/{config.version}/include",
]

# PSO main game code flags. Do not pass the base speed/auto-inline flags and
# then override them later; some MWCC/wibo rebuild paths are fragile with
# duplicate optimization switches. SDK/runtime still use cflags_base unchanged.
cflags_pso_base = [
    f for f in cflags_base
    if f not in ("-O4,p", "-inline auto")
]

cflags_pso = [
    *cflags_pso_base,
    "-i include",
    "-i src",
    "-i libs/dolphin/include",
    "-i libs/dolphin/include/dolphin",  # for "types.h" includes inside SDK headers
    "-char signed",
    "-use_lmw_stmw on",
    # Sega's game code was built optimize-for-SIZE, not speed: the original
    # uses stmw/lmw register save-restore and un-scheduled prologues. -O4,s
    # reproduces that (verified via locate_func masked scan, 2026-06-12).
    # SDK/runtime keep their own optimization via cflags_dolphin/runtime.
    "-O4,s",
    # ...and with auto-inlining OFF. The original keeps operator new/delete,
    # accessors, etc. as real out-of-line calls. Switching -inline auto ->
    # off took locate_func FOUND counts from 6->83 (TProtocol), 2->16
    # (TMainTask), 5->13 (TObject) with zero regressions (2026-06-12).
    "-inline off",
    # Target game code loads f64 constant-pool literals (int->float magic
    # 0x4330000080000000 etc.) from .rodata via lis/@l, never @sda21 — the
    # target's lfd@sda21 sites are all SDK-side units. mwcc's default
    # -sdata2 8 parks compiler-generated doubles in .sdata2, which is the
    # documented "magic-const @sda21-vs-rodata" stuck cluster. 4 keeps f32
    # consts (lfs @sda21, everywhere in target game code) small-data while
    # pushing 8-byte pool literals to .rodata like the original.
    "-sdata2 4",
]

# Dolphin SDK library flags
cflags_dolphin = [
    *cflags_base,
    "-i libs/dolphin/include",
    "-i libs/dolphin/include/dolphin",  # for "types.h" includes inside SDK headers
    "-i libs/dolphin/include/libc",
    "-i libs/dolphin/src",
    "-char unsigned",
    "-fp_contract off",
    "-D__GEKKO__",  # donor SDK sources guard asm functions with this
]

# odemuexi2/DebuggerDriver.o was built with deferred inlining: functions are
# emitted in reverse definition order and its small EXI helpers inline away.
cflags_dolphin_deferred = [
    "-inline auto,deferred" if f == "-inline auto" else f for f in cflags_dolphin
]

# Recovered SDK owners omit unused inline-math constants from their pools.
cflags_dolphin_recovered = [
    f for f in cflags_dolphin if f != "-char unsigned"
] + ["-char signed", "-DPSO_SDK_COMPACT_MATH"]

# PowerPC EABI runtime flags
cflags_runtime = [
    *cflags_base,
    # ac-donor MSL_C/ + libc/ headers first (the MSL sources are ac's
    # no-threads build, which is what PSO's MSL actually is). Do NOT mix in
    # libs/dolphin/include/libc here — its stdio.h shares the same include
    # guard but lacks the FILE typedef.
    "-i libs/PowerPC_EABI_Support/include",
    "-i libs/PowerPC_EABI_Support/include/libc",
    "-i libs/dolphin/include/dolphin",
    "-i libs/PowerPC_EABI_Support/Runtime/Inc",
    "-i libs/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Include",
    "-i libs/PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Include",
    "-use_lmw_stmw on",
    "-str reuse,pool,readonly",
    "-common off",
    "-char signed",
    "-inline deferred,auto",
]

# MetroTRK debugger flags (mirrors ac-decomp's TRK_MINNOW_DOLPHIN lib)
cflags_trk = [
    *cflags_base,
    "-i libs",
    "-i libs/dolphin/include",
    "-i libs/dolphin/include/dolphin",
    "-i libs/dolphin/include/libc",
    "-i libs/PowerPC_EABI_Support/Runtime/Inc",
    "-i libs/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Include",
    "-i libs/PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Include",
    "-sdata 0",
    "-sdata2 0",
    "-inline auto,deferred",
    "-rostr",
    "-char signed",
    "-use_lmw_stmw on",
]

# Native donor profiles verified against complete owning translation units.
cflags_native_recovered = [
    '-nodefaults',
    '-proc gekko',
    '-align powerpc',
    '-enum int',
    '-fp hardware',
    '-Cpp_exceptions off',
    '-RTTI off',
    '-O4,p',
    '-str reuse,pool,readonly',
    '-maxerrors 1',
    '-nosyspath',
    '-fp_contract off',
    '-char signed',
    '-use_lmw_stmw on',
    '-common off',
    '-D__GEKKO__',
    '-DDEBUG=0',
    '-DNDEBUG',
    '-DVERSION=0',
    '-inline deferred,auto',
    '-i libs',
    '-i libs/PowerPC_EABI_Support/include',
    '-i libs/PowerPC_EABI_Support/include/libc',
    '-i libs/dolphin/include',
    '-i libs/dolphin/include/dolphin',
    f'-i build/{config.version}/include',
]
cflags_native_recovered_auto = [
    "-inline auto" if f == "-inline deferred,auto" else f
    for f in cflags_native_recovered
]

# ===================================================================
# Compilers
# ===================================================================
# Sega built the game code with CodeWarrior GC/2.6 (GC/2.5 and GC/2.7 give the
# same code here; GC/2.0 does not) and cflags_pso. Everything else in
# PsoV3.dol is libraries linked prebuilt, each built with its own compiler:
# the Dolphin SDK, runtime and MetroTRK (helpers below), MusyX and the
# middleware after it (MIDDLEWARE).
GAME_COMPILER = "GC/2.6"

# Game files whose objects came from another compiler (an incremental build
# keeps an object until its source changes) or with other switches. Every
# entry is here because a function or data section matches only this way.
GAME_EXCEPTIONS: Dict[str, Dict[str, Any]] = {
    "pso/enemy/TObjEneDelDepth.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # GC/2.0: compiler-expanded struct copies take 2.0's registers.
    "pso/boss/Boss5GryphonBehavior.cpp": {"mw_version": "GC/2.0"},
    "pso/enemy/TObjEneGyaranzo.cpp": {"mw_version": "GC/2.0"},
    "pso/misc/TOExplosiveMachine.cpp": {"mw_version": "GC/2.0"},
    "pso/enemy/TObjEneSlimeTailAttack.cpp": {"mw_version": "GC/2.0"},
    "pso/boss/TBoss8Dragon.cpp": {"mw_version": "GC/2.0"},
    # GC/1.3.2: the container files 0x8018807C-0x8018D900, the CRC-32 pair
    # (`xoris/xori 0xFFFF`; 2.x always emits `li -1; xor`), and five others.
    "pso/object/TObjComputer.cpp": {"mw_version": "GC/1.3.2"},
    "pso/item/TObjContainerJung.cpp": {"mw_version": "GC/1.3.2"},
    # The two below also schedule the by-value DirectAttackPayload read of
    # their receive_direct_attack overrides only the way 1.3.2 does.
    "pso/item/TObjContainerItem.cpp": {"mw_version": "GC/1.3.2"},
    "pso/misc/TContainerAncient01.cpp": {"mw_version": "GC/1.3.2"},
    "pso/ui/TAdSinglePlyChrSelectGC_801FBF54.cpp": {"mw_version": "GC/1.3.2"},
    "pso/misc/TQuestVmDownLoadServer.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-inline deferred")},
    "pso/misc/TCameraCtrl.cpp": {"mw_version": "GC/1.3.2"},
    "pso/player/TObjPlayer_80141D1C.cpp": {"mw_version": "GC/1.3.2"},
    "pso/misc/TKeyBoardControl_8025EC04.cpp": {"mw_version": "GC/1.3.2"},
    "pso/menu/TAdMultiOkGC.cpp": {"mw_version": "GC/1.3.2"},
    "pso/misc/TLobby_802A5120.cpp": {"mw_version": "GC/1.3.2"},
    "pso/unk/text_8032B318.cpp": {"mw_version": "GC/1.3.2"},
    # GC/1.3: the compiler-generated TMenuList<> copy constructor.
    "pso/misc/TRegister.cpp": {"mw_version": "GC/1.3"},
    "pso/misc/TPlyGuildCardTag_801E0284.cpp": {"mw_version": "GC/1.3"},
    "pso/misc/TPlyStartGame.cpp": {"mw_version": "GC/1.3"},
    "pso/misc/TWindowShortListCtrl_8026E7DC.cpp": {"mw_version": "GC/1.3"},
    # Deferred inlining: functions come out in reverse source order and the
    # vtables before the switch tables in .data.
    "pso/misc/TMedicalCenterSequence.cpp": {"cflags": _switch(cflags_pso, "-inline deferred")},
    "pso/boss/TBoss7LaserLight.cpp": {"cflags": _switch(cflags_pso, "-inline deferred")},
    "pso/enemy/TObjEnemyCustom.cpp": {"cflags": _switch(cflags_pso, "-inline deferred", "-pool off", "-str reuse,readonly")},
    "pso/boss/TBoss3VoloptCore.cpp": {"cflags": _switch(cflags_pso, "-inline deferred")},
    "pso/boss/TBoss3VoloptP01.cpp": {"cflags": _switch(cflags_pso, "-inline deferred")},
    # Delbiter uses deferred code generation: reverse source definitions put
    # native vtables before the switch tables and functions in address order.
    "pso/enemy/TObjEneDellBiter.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/enemy/TObjEneDellBiterEffects.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # The Vol Opt fade tasks: deferred like the units above, but nothing is
    # inlined (the inline TUnk_804999E8 destructor and TObject::queue_destruction
    # stay calls).
    "pso/boss/TUnk_804848A0.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # TItem.cpp is written from its last function back (deferred code
    # generation; the data keeps source order) and built with GC/2.0, like the
    # struct-copy units above.
    # The dragonfly base and its cave subclass: vtables come out subclass first.
    "pso/misc/TOBiwaMushi.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-fp_contract on", "-str reuse,readonly", "-sdata 4")},
    "pso/misc/TODragonflyCave01.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-fp_contract on", "-str reuse,readonly", "-sdata 4")},
    "pso/misc/TODragonflyMachine01.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on", "-str reuse,readonly", "-sdata 4")},
    "pso/item/TItem.cpp": {"mw_version": "GC/2.0", "cflags": _switch(cflags_pso, "-inline off,deferred")},
    # TItemProArmor.cpp, TItemProShield.cpp and TItemProUnit.cpp are written
    # from their last function back (deferred code generation, which also puts
    # each vtable before the switch tables).
    "pso/item/TItemProArmor.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # TODoorBase's vtable precedes its switch tables: deferred, written from
    # its last function back.
    "pso/misc/TODoorBase.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # TOBarrierEnergy01's vtable precedes its switch table too.
    "pso/misc/TOBarrierEnergy01.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TItemProArmorParticle.cpp is written from its last function back too:
    # its data (class names, particle table) keeps source order.
    "pso/item/TItemProArmorParticle.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # TObjTreeLobby.cpp is written from its last function back: the
    # quest-damage task it also defines has its vtable after the tree's.
    "pso/object/TObjTreeLobby.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # TItemMag's vtable precedes its switch tables: deferred, and written from
    # its last function back.
    "pso/item/TItemMag.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/item/TItemProUnit.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # TOKey's vtable precedes its switch tables: deferred, and written from
    # its last function back.
    "pso/misc/TOKey.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/item/TItemProShield.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # TItemEffNeedle.cpp too: its three vtables come out in the order only
    # deferred code generation gives (TItemEffNeedlePos keeps the implicit
    # destructor).
    "pso/item/TItemEffNeedle.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # TItemEquipBase.cpp keeps its class-name string in .rodata.
    "pso/item/TItemEquipBase.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TObjMotion.cpp keeps its class-name string in .rodata too.
    "pso/object/TObjMotion.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TItemMagSub.cpp (with TItemMagGrowEff) keeps its strings in .rodata, and
    # is written from its last function back: deferred code generation puts
    # the TItemMagGrowEff vtable first.
    "pso/item/TItemMagSub.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TItemObject's vtable precedes its switch table: deferred, and written
    # from its last function back.
    "pso/item/TItemObject.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # Two tool classes built the same way: the material's vtable precedes its
    # switch table, and TUnk_8049FED0's TU emits its helper task's vtable first.
    "pso/item/TUnk_8049FBC0.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/item/TUnk_8049FED0.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/item/TUnk_804F0D34.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # Vol Opt's second form also keeps eight-byte tables in .data, a six-byte
    # one in .bss and four-byte pointers in .sbss; its .rodata initializers run
    # from the last function back and its vtable precedes the switch tables.
    "pso/boss/TBoss3VoloptP02.cpp": {"cflags": _switch(cflags_pso, "-inline deferred", "-sdata 4")},
    # The character appearance tables keep eight-byte descriptors in .data
    # but four-byte pointer lists in .sdata.
    "pso/misc/CharacterAppearanceTables.cpp": {"cflags": _switch(cflags_pso, "-sdata 4")},
    # Vol Opt keeps its six-byte P01 order in .bss and its four-byte globals
    # in .sbss; its vtable precedes the switch tables in .data.
    "pso/boss/TBoss3Volopt.cpp": {"cflags": _switch(cflags_pso, "-inline deferred", "-sdata 4")},
    # Vol Opt's monitors keep their eight-byte texture lists in .data but the
    # four-byte class-name pointer in .sdata.
    "pso/boss/TBoss3VoloptMonitor.cpp": {"cflags": _switch(cflags_pso, "-inline deferred", "-sdata 4")},
    # The cave and machine map objects keep their eight-byte model-name lists
    # in .data but the four-byte motion-name list and class-name pointer in
    # .sdata.
    "pso/misc/TOAirconCave01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/misc/TOAirconCave02.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/misc/TOCapsuleMachine01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    # The character creation camera: deferred with nothing inlined, and its
    # multiply-adds contracted into fmadds.
    "pso/camera/CreationCamera.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-fp_contract on")},
    # The pad rumble and Ninja helper code contract multiply-adds into fmadds/fnmsubs.
    "pso/system/PadRumble.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on")},
    "pso/system/NinjaUtil.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on")},
    # Metrowerks' GCN_Mem_Alloc.c (runtime library code at -O4,p); belongs
    # in the runtime lib under its own name.
    "pso/unk/text_8039739C.cpp": {"cflags": _switch(cflags_pso, "-O4,p")},
    "pso/quest/QuestOpcodeHandlers.cpp": {"cflags": _switch(cflags_pso, "-inline on")},
    "pso/quest/TQuestThread.cpp": {"cflags": _switch(cflags_pso, "-inline on")},
}

# MusyX (Factor 5). Its objects carry extab/extabindex for every non-leaf
# function: C++ with exceptions on reproduces them and leaves .text alone.
cflags_musyx = _switch(cflags_pso, "-O4,p", "-sdata2 8", "-Cpp_exceptions on") + ["-lang=c++"]

# Prebuilt middleware after MusyX, in link order: (name, first .text address,
# compiler, flags, per-file exceptions). Each library runs to the next one's
# address; the version strings in their data name them.
cflags_middleware = _switch(cflags_pso, "-O4,p", drop=("-sdata2",))
MIDDLEWARE: List[Tuple[str, int, str, List[str], Dict[str, Dict[str, Any]]]] = [
    # MusyX's synthesizer core, then its service, hardware and effect files.
    ("musyx", 0x803A3858, "GC/1.2.5n", _switch(cflags_musyx, "-opt nocse"), {}),
    ("musyx_hw", 0x803BAC70, "GC/1.2.5n", _switch(cflags_musyx, "-inline auto"), {}),
    # CRI ADX, LSC, SJ, MFCI and GCRNA ("Build:Jun 13 2002").
    ("cri", 0x803BFE50, "GC/2.6", cflags_middleware, {}),
    # Sega's Ginja model library.
    ("ginja", 0x803D6538, "GC/2.6", _switch(cflags_middleware, "-O3,p", "-opt nopeephole"), {}),
    # mcFsGc ("Ver 1.10.00 Build:Sep 17 2002") with ACCESS's file transfer.
    ("mcfs", 0x803E5668, "GC/1.2.5", cflags_middleware, {
        # Epilogue order (mtlr before the restores) only 1.2.5n produces.
        "pso/misc/TKeyBoardControl_803F0C50.cpp": {"mw_version": "GC/1.2.5n"},
        "pso/unk/text_803F1804.cpp": {"mw_version": "GC/1.2.5n"},
    }),
    # ntInf ("Ver 1.17.00 Build:Jul 9 2002").
    ("ntinf", 0x803F3CF4, "GC/2.6", cflags_middleware, {
        "pso/unk/text_803F4D84.cpp": {"cflags": _switch(cflags_middleware, "-O2", "-use_lmw_stmw off")},
    }),
    # ACCESS AVE-TCP ("avetcp.a Ver.1.16.1 Oct 23 2002"); its PPP files were
    # built without common subexpression elimination.
    ("avetcp", 0x803F7678, "GC/1.2.5n", cflags_middleware, {
        "pso/protocol/NetworkRuntime.cpp": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/misc/TLobby_803FAEA0.cpp": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/misc/TLobby_803FC178.cpp": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/misc/TLobby_804048E8.cpp": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/misc/TLobby_804050DC.cpp": {"cflags": _switch(cflags_middleware, "-opt nocse")},
    }),
    # The modem driver (AT command strings).
    ("modem", 0x8042BF48, "GC/1.2.5", cflags_middleware, {}),
    # ntUtl ("Ver 1.16.00 Build:Jul 8 2002"); the SDK's EXI library follows.
    ("ntutl", 0x8042E8C4, "GC/2.6", cflags_middleware, {}),
]
MIDDLEWARE_END = 0x8042F13C


def _game_and_middleware_libs() -> List[Dict[str, Any]]:
    """The pso/ and musyx/ units of splits.txt, sorted into the game lib and
    the MIDDLEWARE libs by link address."""
    game: List[Object] = []
    libs = [{"lib": name, "mw_version": mw, "cflags": flags, "progress_category": "game",
             "src_dir": "src", "objects": []} for name, _, mw, flags, _ in MIDDLEWARE]
    starts = [start for _, start, _, _, _ in MIDDLEWARE]
    for unit, addr in _units_from_splits(""):
        if not unit.startswith(("pso/", "musyx/")):
            continue
        i = bisect.bisect_right(starts, addr) - 1
        if i < 0 or addr >= MIDDLEWARE_END:
            game.append(Unit(unit, **GAME_EXCEPTIONS.get(unit, {})))
        else:
            libs[i]["objects"].append(Unit(unit, **MIDDLEWARE[i][4].get(unit, {})))
    return [{"lib": "psov3_main", "mw_version": GAME_COMPILER, "cflags": cflags_pso,
             "progress_category": "game", "src_dir": "src", "objects": game}, *libs]


# ===================================================================
# Library Helpers
# ===================================================================

def DolphinLib(lib_name: str, objects: list) -> dict:
    """A Dolphin SDK library. Use when registering SDK source files.

    The SDK copy embedded in PsoV3.dol was prebuilt by Nintendo with an
    older compiler than the game code — GC/1.2.5n matches its prologue
    style (mflr/stw/stwu, 0x8 frames), same as tp's DolphinLib.
    """
    return {
        "lib": lib_name,
        "mw_version": "GC/1.2.5n",
        "cflags": cflags_dolphin,
        "progress_category": "sdk",
        "src_dir": "libs/dolphin/src",
        "objects": objects,
    }


_msl_math = {
    "mw_version": "GC/1.3",
    "cflags": [f for f in cflags_runtime if f != "-fp_contract off"] + ["-fp_contract on"],
}


def RuntimeLib(lib_name: str, objects: list) -> dict:
    """A PowerPC EABI runtime / MSL library.

    Unit names carry the full PowerPC_EABI_Support/... prefix (same as tp)
    so src_dir is libs/.
    """
    return {
        "lib": lib_name,
        "mw_version": "GC/2.6",
        "cflags": cflags_runtime,
        "progress_category": "runtime",
        "src_dir": "libs",
        "objects": objects,
    }


def TRKLib(lib_name: str, objects: list) -> dict:
    """MetroTRK debugger library. Prebuilt like the SDK; flags and compiler
    follow ac-decomp's TRK_MINNOW_DOLPHIN settings (GC/1.3)."""
    return {
        "lib": lib_name,
        "mw_version": "GC/1.3",
        "cflags": cflags_trk,
        "progress_category": "sdk",
        "src_dir": "libs",
        "objects": objects,
    }


# ===================================================================
# Library / Object Definitions
# ===================================================================
# PsoV3.dol's pso/ and musyx/ units are read from splits.txt: adding a unit
# there is all it takes. The SDK and runtime units are listed by hand so
# each one's compiler settings sit next to it.
# ===================================================================

if args.target == "psov3":
    config.reconfig_deps = [
        Path("config/GPOE8P/psov3/splits.txt"),
        _LINKED_UNITS_FILE.relative_to(Path(__file__).resolve().parent),
    ]
    config.libs = [
        *_game_and_middleware_libs(),
        DolphinLib(
            "recovered_sdk",
            [
                Unit('mtx/mtx.c', mw_version="GC/1.2.5"),
                Unit('mtx/mtxvec.c'),
                Unit('mtx/mtx44.c'),
                Unit('mtx/vec.c'),
                Unit('dvd/dvdlow.c'),
                Unit('dvd/dvdfs.c'),
                Unit('dvd/dvd.c'),
                Unit('vi/vi.c'),
                Unit('pad/Pad.c'),
                Unit('ai/ai.c'),
                Unit('ar/ar.c'),
                Unit('ar/arq.c'),
                Unit('dsp/dsp.c'),
                Unit('dsp/dsp_debug.c'),
                Unit('dsp/dsp_task.c'),
                Unit('card/CARDBios.c'),
                Unit('card/CARDUnlock.c'),
                Unit('card/CARDRdwr.c'),
                Unit('card/CARDBlock.c'),
                Unit('card/CARDDir.c'),
                Unit('card/CARDCheck.c'),
                Unit('card/CARDMount.c'),
                Unit('card/CARDFormat.c'),
                Unit('card/CARDOpen.c'),
                Unit('card/CARDCreate.c'),
                Unit('card/CARDRead.c'),
                Unit('card/CARDWrite.c'),
                Unit('card/CARDDelete.c'),
                Unit('card/CARDStat.c'),
                Unit('card/CARDRename.c'),
                Unit('card/CARDStatEx.c'),
                Unit('card/CARDNet.c'),
                Unit('gx/GXFifo.c'),
                Unit('gx/GXAttr.c'),
                Unit('gx/GXMisc.c'),
                Unit('gx/GXFrameBuf.c'),
                Unit('gx/GXLight.c'),
                Unit('gx/GXTexture.c'),
                Unit('gx/GXBump.c'),
                Unit('gx/GXPixel.c'),
                Unit("gx/GXStubs.c"),
                Unit('gx/GXDisplayList.c'),
                Unit('gx/GXTransform.c'),
                Unit('gx/GXPerf.c'),
            ],
        ) | {"cflags": cflags_dolphin_recovered},
        TRKLib(
            "recovered_trk",
            [
                Unit("TRK_MINNOW_DOLPHIN/support.c",
                            mw_version="GC/2.6", cflags=cflags_native_recovered),
                Unit("TRK_MINNOW_DOLPHIN/notify.c",
                            mw_version="GC/2.6", cflags=cflags_native_recovered),
                Unit("TRK_MINNOW_DOLPHIN/flush_cache.c",
                            mw_version="GC/2.6", cflags=cflags_native_recovered),
                Unit("TRK_MINNOW_DOLPHIN/mem_TRK.c",
                            mw_version="GC/1.3", cflags=cflags_native_recovered_auto),
                Unit("TRK_MINNOW_DOLPHIN/targimpl.c",
                            mw_version="GC/2.6", cflags=[*cflags_native_recovered, "-sdata 0", "-sdata2 0"]),
                Unit("TRK_MINNOW_DOLPHIN/targsupp.s", src_dir=f"build/{config.version}/orig_asm"),
                Unit("TRK_MINNOW_DOLPHIN/exception.s", src_dir=f"build/{config.version}/orig_asm"),
                Unit("TRK_MINNOW_DOLPHIN/dolphin_trk.c",
                            mw_version="GC/2.6", cflags=[*cflags_native_recovered, "-sdata 0", "-sdata2 0"]),
            ],
        ),
        RuntimeLib(
            "recovered_runtime",
            [
                Unit("PowerPC_EABI_Support/Runtime/Src/CPlusLibPPC.cp",
                            mw_version="GC/2.6", cflags=cflags_native_recovered),
                Unit("PowerPC_EABI_Support/Runtime/Src/NMWException.cp",
                            mw_version="GC/1.3", cflags=cflags_native_recovered_auto),
                Unit("PowerPC_EABI_Support/Runtime/Src/ptmf.c",
                            mw_version="GC/2.6", cflags=cflags_native_recovered),
                Unit("PowerPC_EABI_Support/Runtime/Src/runtime.c",
                            mw_version="GC/2.6", cflags=cflags_native_recovered),
                Unit("PowerPC_EABI_Support/Runtime/Src/__init_cpp_exceptions.cpp",
                            mw_version="GC/2.6", cflags=cflags_native_recovered),
                Unit("PowerPC_EABI_Support/Runtime/Src/__mem.c",
                            mw_version="GC/2.6", cflags=cflags_native_recovered),
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/ansi_fp.c",
                            mw_version="GC/1.3", cflags=cflags_native_recovered_auto),
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/printf.c",
                            mw_version="GC/1.3", cflags=cflags_native_recovered),
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/rand.c",
                            mw_version="GC/1.3", cflags=cflags_native_recovered),
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/scanf.c",
                            mw_version="GC/1.3", cflags=cflags_native_recovered),
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/string.c",
                            mw_version="GC/2.6", cflags=cflags_native_recovered),
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/strtoul.c",
                            mw_version="GC/1.3", cflags=cflags_native_recovered),
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/uart_console_io.c",
                            mw_version="GC/2.6", cflags=cflags_native_recovered),
            ],
        ),
        DolphinLib(
            "recovered_sdk_io",
            [
                Unit('exi/EXIBios.c', cflags=cflags_dolphin_recovered),
                Unit('exi/EXIUart.c', cflags=cflags_dolphin_recovered),
                Unit('si/SIBios.c', cflags=cflags_dolphin_recovered),
            ],
        ),
        # ------------------------------------------------------------------
        # PsoV3.dol — Embedded Dolphin SDK copy.
        # TU boundaries transferred from the tp and ac-decomp donors
        # (see WORKFLOW.md's SDK/runtime loop). Source lives in libs/dolphin/src.
        # ------------------------------------------------------------------
        DolphinLib(
            "base",
            [
                Unit("base/PPCArch.c"),
            ],
        ),
        DolphinLib(
            "db",
            [
                Unit("db/db.c"),
            ],
        ),
        DolphinLib(
            "os",
            [
                Unit("os/OS.c", cflags=cflags_dolphin_recovered),
                Unit("os/__start.c", cflags=cflags_dolphin_recovered),
                Unit("os/OSAlarm.c"),
                Unit("os/OSAlloc.c"),
                Unit("os/OSArena.c"),
                Unit("os/OSAudioSystem.c"),
                Unit("os/OSCache.c", cflags=cflags_dolphin_recovered),
                Unit("os/OSContext.c", cflags=cflags_dolphin_recovered),
                Unit("os/OSError.c", cflags=cflags_dolphin_recovered),
                Unit("os/OSFont.c"),
                Unit("os/OSInterrupt.c"),
                Unit("os/OSLink.c"),
                Unit("os/OSMessage.c"),
                Unit("os/OSMemory.c"),
                Unit("os/OSMutex.c"),
                Unit("os/OSReboot.c"),
                Unit("os/OSReset.c"),
                Unit("os/OSResetSW.c"),
                Unit("os/OSRtc.c"),
                Unit("os/OSSync.c"),
                Unit("os/OSThread.c"),
                Unit("os/OSTime.c"),
                Unit("os/__ppc_eabi_init.cpp"),
            ],
        ),
        DolphinLib(
            "dvd",
            [
                Unit("dvd/dvdqueue.c"),
                Unit("dvd/dvderror.c"),
                Unit("dvd/fstload.c", cflags=cflags_dolphin_recovered),
            ],
        ),
        DolphinLib(
            "gx",
            [
                Unit("gx/GXInit.c", cflags=cflags_dolphin_recovered),
                Unit("gx/GXGeometry.c"),
                Unit("gx/GXTev.c"),
            ],
        ),
        DolphinLib(
            "si",
            [
                Unit("si/SISamplingRate.c", cflags=cflags_dolphin_recovered),
            ],
        ),
        DolphinLib(
            "gba",
            [
                Unit("gba/GBA.c", cflags=cflags_dolphin_recovered),
                Unit("gba/GBAGetProcessStatus.c", cflags=cflags_dolphin_recovered),
                Unit("gba/GBAJoyBoot.c", cflags=cflags_dolphin_recovered),
                Unit("gba/GBARead.c", cflags=cflags_dolphin_recovered),
                Unit("gba/GBAWrite.c", cflags=cflags_dolphin_recovered),
                Unit("gba/GBAXfer.c", cflags=cflags_dolphin_recovered),
                Unit("gba/GBAKey.c", cflags=cflags_dolphin_recovered),
            ],
        ),
        DolphinLib(
            "amcstubs",
            [
                Unit("amcstubs/AmcExi2Stubs.c"),
            ],
        ),
        DolphinLib(
            "odenotstub",
            [
                Unit("odenotstub/odenotstub.c"),
            ],
        ),
        DolphinLib(
            "odemuexi2",
            [
                Unit("odemuexi2/DebuggerDriver.c", cflags=cflags_dolphin_deferred),
            ],
        ),
        TRKLib(
            "TRK_MINNOW_DOLPHIN",
            [
                Unit("TRK_MINNOW_DOLPHIN/mainloop.c"),
                Unit("TRK_MINNOW_DOLPHIN/nubevent.c"),
                Unit("TRK_MINNOW_DOLPHIN/nubinit.c"),
                Unit("TRK_MINNOW_DOLPHIN/msg.c"),
                Unit("TRK_MINNOW_DOLPHIN/msgbuf.c"),
                Unit("TRK_MINNOW_DOLPHIN/msghndlr.c"),
                Unit("TRK_MINNOW_DOLPHIN/serpoll.c"),
                Unit("TRK_MINNOW_DOLPHIN/usr_put.c"),
                Unit("TRK_MINNOW_DOLPHIN/dispatch.c"),
                Unit("TRK_MINNOW_DOLPHIN/mpc_7xx_603e.c"),
                Unit("TRK_MINNOW_DOLPHIN/main_TRK.c"),
                Unit("TRK_MINNOW_DOLPHIN/dolphin_trk_glue.c"),
                Unit("TRK_MINNOW_DOLPHIN/targcont.c"),
                Unit("TRK_MINNOW_DOLPHIN/target_options.c"),
                Unit("TRK_MINNOW_DOLPHIN/mutex_TRK.c"),
                Unit("TRK_MINNOW_DOLPHIN/mslsupp.c"),
            ],
        ),
        RuntimeLib(
            "Runtime.PPCEABI.H",
            [
                Unit("PowerPC_EABI_Support/Runtime/Src/__va_arg.c"),
                Unit("PowerPC_EABI_Support/Runtime/Src/global_destructor_chain.c"),
                Unit("PowerPC_EABI_Support/Runtime/Src/Gecko_ExceptionPPC.cp"),
            ],
        ),
        RuntimeLib(
            "MSL_C.PPCEABI.bare.H",
            [
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/abort_exit.c"),
                # alloc.c: only GC/1.3 emits `li -5; and` where 1.3.2+ use rlwinm
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/alloc.c",
                            mw_version="GC/1.3"),
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/ansi_files.c"),
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/buffer_io.c"),
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/direct_io.c"),
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/FILE_POS.c"),
                # file_io.c: PSO's fclose keeps a real `bl fflush`; -inline
                # deferred would fold fflush into fclose and reverse the
                # emission order, so this TU drops deferred. extra_cflags
                # can't cancel it (deferred is sticky), hence full override.
                Unit(
                    "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/file_io.c",
                    cflags=[
                        f if f != "-inline deferred,auto" else "-inline auto"
                        for f in cflags_runtime
                    ],
                ),
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/mbstring.c"),
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/mem.c"),
                # mem_funcs.c: PSO's copy of these MSL copy loops predates the
                # rest of the runtime — GC/2.6 emits clrlwi/pipelined loops
                # that can't match; GC/1.3 with plain -inline auto is exact.
                Unit(
                    "PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/mem_funcs.c",
                    mw_version="GC/1.3",
                    cflags=[
                        f if f != "-inline deferred,auto" else "-inline auto"
                        for f in cflags_runtime
                    ],
                ),
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/misc_io.c"),
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/wchar_io.c"),
            ],
        ),
        # fdlibm + math_ppc (0x8039F7FC-0x803A2DA0): built like ac's MSL math,
        # GC/1.3 with -fp_contract on (e_acos needs fmadd; s_atan only matches
        # under 1.3).
        RuntimeLib(
            "MSL_C.PPCEABI.bare.H.math",
            [
                *[Unit(f"PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Double_precision/{_n}.c", **_msl_math)
                  for _n in (
                      "e_acos", "e_asin", "e_atan2", "e_log", "e_pow", "e_rem_pio2", "k_cos",
                      "k_rem_pio2", "k_sin", "k_tan", "s_atan", "s_ceil", "s_copysign", "s_cos",
                      "s_floor", "s_frexp", "s_ldexp", "s_modf", "s_nextafter", "s_sin", "s_tan",
                      "w_acos", "w_asin", "w_atan2", "w_log", "w_pow",
                  )],
                Unit("PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Src/math_ppc.c", **_msl_math),
            ],
        ),
    ]
else:
    # main.dol has no recovered source; it is rebuilt from its original objects.
    config.libs = []

# ===================================================================
# Progress Categories
# ===================================================================
config.progress_categories = [
    ProgressCategory("game", "PSO Game Code"),
    ProgressCategory("sdk", "Dolphin SDK"),
    ProgressCategory("runtime", "Runtime"),
]

# Progress report arguments for objdiff-cli
config.progress_report_args = [
    "--config", "functionRelocDiffs=data_value",
]

# ===================================================================
# Functions written in assembly
# ===================================================================
# The SDK, runtime and MetroTRK functions that Nintendo and Metrowerks wrote in
# assembly are not in this repository. Their bodies are
#     #include "orig_asm/<unit>/<function>.inc"
# and tools/orig_asm.py writes those files from decomp-toolkit's disassembly of
# the original, before anything is compiled. Units that are assembly from start
# to finish are written whole.
_ORIG_ASM = re.compile(r'^#include "(orig_asm/[\w/]+\.inc)"$', re.M)
_ORIG_ASM_UNITS = ["TRK_MINNOW_DOLPHIN/targsupp.s", "TRK_MINNOW_DOLPHIN/exception.s"]


def add_orig_asm_steps(config: ProjectConfig) -> None:
    outputs: List[Path] = []
    for root in (Path("libs"), Path("src")):
        for path in sorted(root.rglob("*")):
            if path.suffix in (".c", ".cp", ".cpp") and path.is_file():
                text = path.read_text(encoding="utf-8", errors="replace")
                if "orig_asm/" in text:
                    outputs += [config.out_path() / "include" / inc for inc in _ORIG_ASM.findall(text)]
    outputs += [config.out_path() / "orig_asm" / unit for unit in _ORIG_ASM_UNITS]
    symbols = Path("config") / config.version / "psov3" / "symbols.txt"
    config.custom_build_rules = [*(config.custom_build_rules or []), {
        "name": "orig_asm",
        "command": "$python tools/orig_asm.py $asm_dir $symbols $out",
        "description": "ORIG_ASM $asm_dir",
    }]
    steps = config.custom_build_steps = dict(config.custom_build_steps or {})
    steps["pre-compile"] = [*steps.get("pre-compile", []), {
        "outputs": outputs,
        "rule": "orig_asm",
        "inputs": [config.out_path() / "config.json"],
        "implicit": [Path("tools/orig_asm.py"), symbols],
        "variables": {"asm_dir": str(config.out_path() / "asm"), "symbols": str(symbols)},
    }]
    config.reconfig_deps = [*(config.reconfig_deps or []), Path("tools/orig_asm.py")]


# ===================================================================
# Main Dispatch
# ===================================================================
if args.target == "psov3":
    add_orig_asm_steps(config)
    # A disc image in orig/GPOE8P/, or the disc extracted there by wit.
    _disc_root = Path("orig/GPOE8P/P-GPOE")
    if not _disc_root.is_dir():
        _disc_root = Path("orig/GPOE8P")
    add_data_build_steps(config, _disc_root, replacements=args.data_replacements)

if args.mode == "configure":
    generate_build(config)
elif args.mode == "progress":
    calculate_progress(config)
else:
    sys.exit(f"Unknown mode: {args.mode}")
