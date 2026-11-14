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
    # -str readonly: the string literals of these files sit in .rodata.
    "pso/unk/TLobby_80103F5C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/TDuelEffectCtrl.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/TDuelEffectNumber.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/TDuelEffectString.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-fp_contract on")},
    "pso/effect/TEffClitical.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/item/TItemEffArmor.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/derolle/TObjBoss2Tunnel_802F1A58.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/TLobby_803382E4.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/TObjControl.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/font/TFontSmallTask.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowSubStatusDisp_80338740.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowArea.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/city/TShopDeleteItemWindow.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/TLobby_80207DA8.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/item/TItemReverseTech.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/hud/TNowLoading.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/item/TItemLoad_80110010.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/player/TObjPlayer_801D84CC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -sdata 4: the 8-byte camera bank list 0x80488B98 sits in .data, not .sdata.
    "pso/camera/TCameraCtrl_8006C7C4.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    # run_task and get_target_position reach each .rodata object with its own lis/addi: -pool off.
    "pso/unk/TUnk_80488DA0.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/effect/item/TItemEffBringer.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/item/TItemEffCane.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/item/TItemEffEquip.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/item/TItemEffLandHit.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/item/TItemEffLavis.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/photon/TPhotonEstlla.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/photon/TPhotonFarlla.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # setup_photon_blast_camera reaches its four .rodata camera offsets with a lis/addi each: -pool off.
    "pso/effect/photon/PhotonBlastSummon.cpp": {"cflags": _switch(cflags_pso, "-pool off")},
    # render reaches each of its .rodata vectors and angles with its own lis/addi (no shared base): -pool off.
    "pso/effect/particle/ParticleBallistic.cpp": {"cflags": _switch(cflags_pso, "-pool off")},
    "pso/effect/photon/TPhotonConcentrate.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TPhotonMylla__ct reaches its packet template with its own lis/addi (no shared .rodata base): -pool off.
    "pso/effect/photon/TPhotonMylla.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/object/TObjLuker_801329B0.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/ending/TObjOnlineEnding_802E4B80.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdPlayerLoadGC.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/ui/TLogo.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # vtables come out TUnk_804E70A8 then TUnk_804E71A0: written last to first, deferred.
    "pso/player/TObjPlayer_80307618.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # vtables come out 0810, 0908, 0A00, 0AF8 then 0BF0: written last to first, deferred.
    "pso/effect/item/TItemEffPG.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # vtables come out TUnk_804A2548 then TUnk_804A2564: written last to first, deferred.
    "pso/player/TUnk_804A2548.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # vtables come out TUnk_804A5D10 then TUnk_804A5D28: written last to first, deferred.
    "pso/weapon/TUnk_804A5D28.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # vtables come out KeyQuick, Key, Normal then TUnk_804B2578: written last to first, deferred.
    "pso/object/cave/TOHangceilingCave01.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/ui/hud/TMainCursor.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # vtables come out StelthReal, then the dispatch_state jump table, then Stelth: written last to first, deferred.
    "pso/enemy/stelth/TObjEneMe3Stelth.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/enemy/bringer/TObjEneDf2Bringer.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/sorcerer/TObjEneRe4Sorcerer_800EDB98.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/gigue/TObjEneMe1GiGue.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly", "-fp_contract on")},
    "pso/enemy/canadin/TObjEneMe1Canadin.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/enemy/deldepth/TObjEneDelDepth.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/enemy/panarms/TObjEnePanarms_800DCEB8.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # -sdata 4: the four 8-byte tables 0x80495914-0x80495934 sit in .data, not .sdata.
    "pso/enemy/panarms/TObjEnePanarms.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-sdata 4")},
    "pso/enemy/moja/TObjEneMoja.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # -inline off,deferred: the constructor reaches __vt__16TObjEneRe2Flower through the .data anchor
    # (setup_data + 388) and the vtable sits before dispatch_action's jump table.
    "pso/enemy/flower/TObjEneRe2Flower.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # -inline off,deferred: .data is the attach-joint table, then __vt__10TObjPlayer, then the
    # jump tables; written last to first, deferred.
    "pso/player/TObjPlayer_801AF2F0.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # -sdata 4: the two 8-byte name tables 0x804809B0-0x804809C0 sit in .data, not .sdata.
    "pso/ui/frontend/TAdRicoRingCtrl.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly", "-sdata 4")},
    "pso/enemy/dd/TObjEneDD.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/enemy/dubchik/TObjEneDubchik.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/ui/city/TShopKeepItemWindow.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/npc/TNpcPlayer.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/ui/window/TWindowMainMenu_802AD538.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -fp_contract on: the lens flare render 0x800812D0 fuses its element placement into fmadds/fnmsubs;
    # the unit's other functions are the same either way.
    "pso/effect/TEF_LensFlare.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on")},
    # -fp_contract on: 0x80257024 fuses its depth math (0.299f * depth + parent depth) into fmadds; the
    # unit's other functions are the same either way (its twin draw_gauge in _8025737C needs it too).
    "pso/ui/window/TWindowSubStatusDisp_80256B94.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on")},
    # -fp_contract on: the scroll bar render 0x80340A78 fuses its cap and thumb math into fmadds/fnmsubs;
    # init, set_value_f32 and set_scale are the same either way.
    "pso/ui/window/TWindowDD_80340A78.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on")},
    # -fp_contract on: handle_scroll_input, get_cursor_pos and the strip draw 0x80341674 fuse into fmadds
    # (they were the unit's fp_contract pragma regions); the other functions are the same either way.
    # -fp_contract on: 0x803412A0 fuses its width math into fmadds (it was the unit's fp_contract pragma region);
    # the other ten functions of this file are the same either way.
    "pso/ui/window/TWindowDD_80341334.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on")},
    "pso/ui/window/TWindowDD_80341A08.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on")},
    # -str readonly: every string of these units is read-only data ("SELECT"/"NEXT" of the constructor in .rodata,
    # the Spanish "\xBF"/"\xA1" marks of 0x80345608 in .sdata2, each pooled once).
    "pso/ui/window/TWindowDD_803430BC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowDD_8034435C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # ws_data_load reaches each .rodata object with its own lis/addi (no shared base): -pool off.
    "pso/ui/window/TWindowDD_80346A84.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/ui/window/TWindowCtrlMain.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/ui/frontend/TAdSelectTxtSubGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdBackGC_8029A6EC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdMcSelectGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdMultiSaveGC.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # -sdata 4: the 8-byte model name table 0x80494A40 sits in .data, the 4-byte motion name table in .sdata.
    "pso/boss/volopt/TBoss3Volopt_800D8ACC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/ui/frontend/TAdMcSelectCursorGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdMcSelectMcGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdPlyPltAnimGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdChrSelASlotGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdChrSelBSlotGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -inline off,deferred: functions come out in reverse source order (the .rodata local initialisers 0x804661E4
    # precede the scale table and the conversion doubles). -str reuse,readonly: strings 0x80466190 sit in .rodata.
    # -sdata 4: the 8-byte texlists 0x804DCA78/98 sit in .data.
    "pso/ui/frontend/TAdTitleGC.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly", "-sdata 4")},
    "pso/ui/frontend/TAdMultiPlayerNoGC.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # -str reuse,readonly: the f256_selectgamen names 0x804662D8 and the class name sit in .rodata.
    # -sdata 4: the 8-byte texlists 0x804DCB98/B8 sit in .data.
    "pso/ui/frontend/TAdSelectTxtGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    # -inline off: the TPlyItem part sits in a defer_codegen region (written backwards),
    # the TItemList part after it is forward. readonly: the class-name strings are in .rodata.
    "pso/player/TPlyItem.cpp": {"cflags": _switch(cflags_pso, "-inline off", "-str reuse,readonly")},
    # -sdata 4: the 8-byte kind tables 0x80542FBC-0x80542FDC sit in .bss, not .sbss.
    "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.cpp": {"cflags": _switch(cflags_pso, "-inline on,deferred", "-str reuse,readonly", "-sdata 4")},
    "pso/enemy/gibon/TObjEneBm5GibonU.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/shinowa/TObjEneMe3Shinowa.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/derolle/TObjBoss2Tunnel.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-opt nopropagation", "-pool off", "-sdata 4")},
    # Its three vtables sit in .data as TUnk_80482D04, TUnk_80482EC0, TBoss2Mine: key-function text order, so deferred with the source written backwards.
    "pso/boss/derolle/TBoss2Mine.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/enemy/gigue/TObjEneMe1GiGue_802CDB1C.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/enemy/mericarol/TObjEneBm9Mericarol_Bomb.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/mericarol/TObjEneBm9Mericarol_EffCurse3.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/epsilon/TObjEneEpsilonGuard_8035DD68.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/epsilon/TObjEneEpsilonGuard_8035F5C8.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly", "-sdata 4")},
    # Functions in reverse source order (0x8008DC18-0x80090448 is written last-to-first) and the four 8-byte
    # .bss arrays 0x805007A8-0x805007C0 reached through one lis/addi pool base in the ctor, not r13.
    "pso/enemy/balclaw/TObjEneBalClawBody.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-sdata 4")},
    "pso/enemy/balclaw/TObjEneBalClawClaw.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/effect/particle/TPlyFollowParticleCtrl.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/player/TObjPlayer_8002E784.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/boss/darkfalz/TBoss4DarkFalz_8004C93C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/lappy/TObjEneLappy.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/wolf/TObjEneBm5Wolf.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/gee/TObjEneMe1Gee.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/gibbles/TObjEneGibbles.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/text_8019DBB4.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/door/TODoorLabo.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/ui/frontend/TAdEnterSerialAccessGC_8032AD30.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/photon/TPhotonGolla.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/photon/TPhotonPilla.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/fence/TObjLazerFenceNorm.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # -sdata 4: the four 8-byte model name tables 0x804E07A0/0x804E07D4/0x804E0800/0x804E082C sit in .data, not .sdata.
    "pso/object/lobby/LobbyPigeonPath.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/boss/olgaflow/TBoss6Tube.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/jungle/TOJungleDesign.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdSinglePlyChrSelectGC_80336054.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/TLobby_801461EC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # load_area_enemy_set/load_area_object_set reach each .rodata object with their own lis/addi: -pool off.
    "pso/unk/text_8020A2AC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/unk/TLobby_802268F4.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/TLobby_80228818.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/TLobby_800F8AA8.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowDD_8034AF68.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/text_80066F10.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/npc/TObjNpcNgcBase_80358AE8.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/object/fence/TOVS2Wall01.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/derolle/TObjBoss2CeilJunk_8003A81C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowDD_8034725C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/trap/TOMine.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/trap/TOMineIcon01.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/trap/TOMineIcon02.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/trap/TOMineIcon03.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/trap/TOMineIcon04.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/warp/TObjLaboMapWarp.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-inline off,deferred", "-pool off", "-sdata 4")},
    "pso/ui/hud/TRaderMapCore_801FB2B8.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/charcreate/TChCrEffTag.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdAgreementBaseGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdEnterPasswordGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdWarningBaseGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdEnterPPPPassGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/ending/TObjOnlineEndingHexLine.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/galgryphon/TBoss5GryphonShockWave.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/gyaranzo/TObjGyaranzoMissile.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowChoiceSetting.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/chat/TWindowSubSymbolChatPartsSet.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/chat/TWindowSubSymbolChat_80281814.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/derolle/TBoss2Tentacle.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/derolle/TObjBoss2Tunnel_8003B138.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/charcreate/TChCrEffWall.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/charcreate/TChCrTagOccHeader.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/charcreate/TChCrTagOccupation.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TLobby__sub_8034DAA0 addresses its four .rodata parameter records with a lis/addi each (no shared
    # .rodata base): built -pool off.
    "pso/npc/TNpcPlayer_8034DAA0.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly", "-pool off")},
    "pso/npc/TNpcPlayer_80190E64.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/panarms/TObjEnePanarmsAtkColli.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/seabed/TObjSeabedSuisoBrakable.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # The TLevelSelect ctor reaches each .rodata object with its own lis/addi (no shared base): -pool off.
    "pso/ui/TLevelSelect.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/ui/TLogo_8001C134.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TObjNewFloorWin_80073DC4.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # Its ctor reaches each .rodata object with its own lis/addi (no shared base): -pool off.
    "pso/ui/frontend/TAdMultiChgGameModeGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/ui/frontend/TAdMultiChgGameModeGC_8023EAC4.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdMultiSelGameModeGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdMultiChgGameModeGC_8036DE10.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -str reuse,readonly: the class name string 0x80477DA0 sits in .rodata.
    # -sdata 4: the 8-byte menu position 0x804EF8D8 sits in .data, the 4-byte menu width in .sbss.
    "pso/ui/frontend/TAdSinglePlyChrSelectGC_8033A8EC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/system/save/TCheckMemoryCard.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    # -str reuse,readonly: the class name string 0x80472920 sits in .rodata.
    # -sdata 4: the 8-byte window positions 0x804E3040-58 sit in .data, the 4-byte menu width in .sbss.
    # -fp_contract on: T_ATS_DrawCalendar::render uses fnmsubs and the static initialiser fmadds.
    # -inline off,deferred: __vt__18T_ATS_DrawCalendar (0x804E34FC) sits before __vt__12TAdTimeSetGC (0x804E3514)
    # although the functions and literals are in address order; the source is written last function first.
    "pso/ui/frontend/TAdTimeSetGC.cpp": {
        "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly", "-sdata 4", "-fp_contract on")
    },
    "pso/ui/frontend/TAdLoadQuestPrtTxtGC_8034A090.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdScrollWinGC.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/ui/window/TWindowSubComCard_8007341C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/unk/text_800FA464.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/item/shop/ShopToolStock.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/item/shop/ShopWeaponStock.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowSubStatusDisp_80228CC0.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowChallengeResult.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/text_8013F810.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/network/TProtocol_801DA240.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/olgaflow/TBoss6EmptyWarp_802B0E2C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/olgaflow/TBoss6PlotFalz_802B0228.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/effect/photon/TPhotonLeilla.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/photon/TPhotonLine.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/text_8028A820.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/trap/TOTrapSeabed01.cpp": {"cflags": _switch(cflags_pso, "-inline on,deferred", "-str reuse,readonly", "-sdata 4")},
    "pso/object/trap/TOTrapAncient02.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-fp_contract on", "-str reuse,readonly", "-sdata 4")},
    "pso/npc/TObjNpcMoja.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/npc/TObjNpcNFM01.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/npc/TObjNpcNFM00.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/system/movie/TMovie.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/unk/TUnk_8048E1A4.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/TUnk_804CC870.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowSubStatusDisp_80288030.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    # -inline off,deferred: .text runs Brakable05..TOWreckAncient but the strings, __name pointers and tables run the other way.
    # -str reuse,readonly: every string of the TU (file names, class names) is in .rodata in the DOL.
    "pso/object/wreck/TOWreckAncient.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # -inline off,deferred: .rodata runs F800, EF14, E88C (opposite to .text); GC/2.0: sub_8031F1A8 schedules only under 2.0.
    "pso/enemy/recon/TObjEneRecobox_8031F800.cpp": {"mw_version": "GC/2.0", "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # node-range statics, then the load slot count, then run_task's table: written last to first, deferred.
    "pso/ui/charcreate/TChCrLoadReq.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/enemy/beast/TObjEneBeast.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # load_texture_pvm_file reaches each .rodata object with its own lis/addi (no shared base): -pool off.
    "pso/unk/TLobby_801E43E4.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/unk/text_801A3014.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/TLobby_801A3C48.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/warp/TObjWarpBossMulti.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/chat/TWindowSubSymbolChatHelp.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/door/TODoorFourLightSpace.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/technique/TTecGiBarta.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/technique/TTecFoie_8022FC94.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -fp_contract on: TUnk_804CC800::run_task fuses its three orbit sums (radius * cos + centre) into
    # fmadds; the unit's other functions are the same either way.
    # TTecGiFoie.cpp keeps its class name string in .rodata (-str readonly) and reaches each .rodata
    # object with its own lis/addi: -pool off.
    "pso/technique/TTecGiFoie.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on", "-str reuse,readonly", "-pool off")},
    "pso/object/TObjSinBoard.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/ambient/TObjGrass.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/lobby/LobbyGoGoBall.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/door/TODoorJungleMain.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/door/TObjDoorJung.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/door/TObjDoorKey.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/TObjDoaEx01.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/door/TObjDoor_8018E358.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/warp/TObjMapWarpAncient.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # The warp debug printers reach each .rodata object with their own lis/addi (no shared base): -pool off.
    "pso/object/warp/TObjAreaWarpEndingJung.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    # TObjWarpJungMain.cpp reaches each .rodata object with its own lis/addi: -pool off.
    "pso/object/warp/TObjWarpJungMain.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/ui/window/TWindowComCard.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowSubComCard_80271E7C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowSubCustomEquip.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/city/THunterGuildSeqOnlineTask.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/city/THunterGuildSeqOnlineTask_802156A0.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TObjBgmColCtrl.cpp reaches each .rodata object with its own lis/addi: -pool off.
    "pso/object/collision/TObjBgmColCtrl.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/object/ambient/TButterfly.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/TObjTank.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/goldragon/TObjBoss8DemoRoom.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/npc/TObjNpcConnoisseur.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/npc/TObjNpcARW00.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/npc/TObjNpcFemaleBase.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/npc/TObjNpcFemaleChild.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/npc/TObjNpcFemaleDwarf.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/npc/TObjNpcFemaleFat.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/npc/TObjNpcFemaleMacho.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/npc/TObjNpcFemaleOld.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/npc/TObjNpcFemaleTall.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/dragon/TBoss1Dragon.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/technique/TTecBarta.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # consume_telepipe_arrival reaches each .rodata object with its own lis/addi (no shared base): -pool off.
    # -sdata 4: the 8-byte recovery_technique_charge_particle_ids 0x804CC988 sits in .data, not .sdata.
    "pso/technique/TTecLuker.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off", "-sdata 4")},
    # -str reuse,readonly: the class name 0x8044D8A4 sits in .rodata between the emitter bands and the offset vector.
    "pso/technique/TTecMegid.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/saver/SaverLifecycle.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/darkgunner/DarkGunner.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/darkgunner/TObjEneDarkGunCenter.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/illgill/TObjEneIllGill.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdChrMoveEffectGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/boss/derolle/TObjBoss2CeilJunk.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/ui/frontend/TAdChrSelPlyPlateGC.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/ui/frontend/TAdChrSelSlotGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/container/TObjContainerIdo_8018BEE4.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/player/TPlyPhotonChair.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/player/TPlayerBattleCtrl4P.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/fence/TLazerFenceSw.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TObjChip: render's colour template sits after draw_chips' in .rodata
    # while render comes first in .text, so the source runs backwards.
    "pso/object/TObjChip.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # Deferred: the vtables come out in reverse key-function order.
    "pso/technique/TTecAnti.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # -fp_contract on: calc_technique_parameters fuses tp_cost += level * (percent / 100.0f) into fmadds;
    # the unit's other functions compile the same either way. -inline on: its 17 per-level pad_12
    # updates read the global after the inner clamp only through the inlined lowered_pad_12 (auto
    # would also inline calc_technique_boost into it). deferred: the original .data holds
    # __vt__8TTecCtrl before the four switch jump tables (0x804CC5F4 < 0x804CC60C), which only
    # deferred code generation emits. -str reuse,readonly: its model/motion names, archive name and
    # class name sit in .rodata. -pool off: create_technique_charge_light loads each case's colour and
    # direction templates by their own lis/addi; pooled data would share one .rodata base instead.
    "pso/technique/TTecCtrl.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on", "-inline on,deferred", "-str reuse,readonly", "-pool off")},
    # -fp_contract on: the ctor fuses its scale and corner math into fmadds; the unit's other
    # functions have no float math. deferred: the original .data holds __vt__16TPlayerFootStamp
    # (0x804DE4F8) before the ctor's switch jump table (0x804DE510), which only deferred code
    # generation emits. readonly: the class name string sits in .rodata (0x804708E8).
    "pso/player/TPlayerFootStamp.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on", "-inline off,deferred", "-str reuse,readonly")},
    "pso/technique/TTecResta.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TTecReverser.cpp reaches each .rodata object with its own lis/addi: -pool off.
    "pso/technique/TTecReverser.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly", "-pool off")},
    "pso/object/ambient/TObjEnvSoundGlobal.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/TObjBigTuitate.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # GC/2.0: compiler-expanded struct copies take 2.0's registers.
    # -sdata 4: the 8-byte effect id pair lbl_80485B08 sits in .data, not .sdata.
    # -inline off,deferred: the ctor reaches the compiler-made vtable off the TU's pooled
    # .data base (addi r0,r28,1860), so the vtable existed before the functions were
    # compiled; with the source last-to-first every function lands at its address.
    # -fp_contract on: four functions need fused multiply-adds, none differ with it on.
    "pso/boss/darkfalz/TBoss4Type1.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-sdata 4", "-fp_contract on", "-str reuse,readonly")},
    # -sdata 4: the 8-byte name list lbl_80487858 sits in .data, not .sdata.
    "pso/boss/galgryphon/Boss5GryphonBehavior.cpp": {"mw_version": "GC/2.0", "cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/enemy/gyaranzo/TObjEneGyaranzo.cpp": {"mw_version": "GC/2.0", "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/trap/TOExplosiveMachine.cpp": {"mw_version": "GC/2.0"},
    # The debris-chip spawners below build const TObjChipParams aggregates whose position, model and
    # texture loads all come before the stores into the locals, which only 2.0 schedules that way
    # (as in TOExplosiveMachine::run_task). -pool off: each chip's initializer template is reached
    # with its own lis/addi, not off one shared base.
    "pso/unk/text_80049FD8.cpp": {"mw_version": "GC/2.0"},
    "pso/object/trap/TOTrapAncient01.cpp": {"mw_version": "GC/2.0", "cflags": _switch(cflags_pso, "-pool off", "-inline off,deferred", "-str reuse,readonly")},
    # TItemAttackCol's ctor builds a const StarLightParameters aggregate from the params; its star-colour loads
    # come before the stores into the local, the same 2.0 aggregate scheduling as the chip spawners above.
    "pso/weapon/TItemAttackCol.cpp": {"mw_version": "GC/2.0"},
    "pso/enemy/slime/TObjEneSlimeTailAttack.cpp": {"mw_version": "GC/2.0", "cflags": _switch(cflags_pso, "-inline on,deferred", "-fp_contract on", "-str reuse,readonly")},
    # -inline off,deferred: every jump table of the unit sits after the vtable, while the slot-87 handler
    # table (a function-local static) sits before the bezier tables: data in parse order, code deferred.
    "pso/boss/goldragon/TBoss8Dragon.cpp": {"mw_version": "GC/2.0", "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TBoss2DeRolLe__sub_8002FE60: its expanded instance-data struct copy hoists the next load above the
    # last store only under 2.0; every other function of the unit compiles the same.
    "pso/boss/derolle/TBoss2DeRolLe.cpp": {"mw_version": "GC/2.0", "cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/TEffIndirectCtrl.cpp": {"mw_version": "GC/2.0", "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/boss/darkfalz/TObjDFDemo1.cpp": {"cflags": _switch(cflags_pso, "-sdata 4")},
    "pso/boss/darkfalz/TObjDFDemo4.cpp": {"cflags": _switch(cflags_pso, "-inline deferred", "-sdata 4")},
    # -sdata 4: the 8-byte motion id table 0x804EF9D8 sits in .data, the 4-byte class name in .sdata.
    # deferred: the ctor addresses .data from one base with the vtable at +0x14, and the .sdata2
    # pool order only comes out with the functions emitted last to first. Inlining on: the ctor's
    # three .rodata tables are local statics of inline helpers, addressed by symbol, not pooled.
    "pso/boss/olgaflow/TBoss6Demo11_TYPE1_DEAD.cpp": {"cflags": _switch(cflags_pso, "-inline deferred", "-sdata 4")},
    # GC/1.3.2: the container files 0x8018807C-0x8018D900, the CRC-32 pair
    # (`xoris/xori 0xFFFF`; 2.x always emits `li -1; xor`), and five others.
    # TObjCamera: 1.3.2 copies CameraSoundEvent member by member unscheduled.
    "pso/camera/TObjCamera.cpp": {"mw_version": "GC/1.3.2"},
    "pso/object/TObjComputer.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/container/TObjContainerJung.cpp": {"mw_version": "GC/1.3.2"},
    # The two below also schedule the by-value DirectAttackPayload read of
    # their receive_direct_attack overrides only the way 1.3.2 does.
    "pso/object/container/TObjContainerItem.cpp": {"mw_version": "GC/1.3.2"},
    "pso/object/container/TContainerAncient01.cpp": {"mw_version": "GC/1.3.2"},
    "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.cpp": {"mw_version": "GC/1.3.2"},
    "pso/quest/TQuestVmDownLoadServer.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-inline deferred")},
    "pso/camera/TCameraCtrl.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/ui/window/TWindowKeyBoardHard.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdMultiOkGC.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TLobby_80228154: its sprite draw keeps the frame size and flag tests only under 1.3.2.
    "pso/unk/TLobby_80228154.cpp": {"mw_version": "GC/1.3.2"},
    # TBoss7Crawfish: one GC/1.3.2 TU (the five former parts compile identically under 1.3.2, not under 2.6);
    # its resource names are .rodata strings.
    "pso/boss/barbaray/TBoss7Crawfish.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/TLobby_802A5120.cpp": {"mw_version": "GC/1.3.2"},
    "pso/unk/text_8032B318.cpp": {"mw_version": "GC/1.3.2"},
    # GC/1.3: the compiler-generated TMenuList<> copy constructor.
    "pso/network/TRegister.cpp": {"mw_version": "GC/1.3"},
    "pso/player/TPlyGuildCardTag_801E0284.cpp": {"mw_version": "GC/1.3"},
    # fill_date_from_seconds stores the month between the days[m - 1] load and the subtraction only
    # under 1.3-2.0 (2.6 schedules the store after it).
    "pso/system/data/pso_date.cpp": {"mw_version": "GC/1.3"},
    "pso/network/TPlyStartGame.cpp": {"mw_version": "GC/1.3"},
    # TShopItemListWindow: handle_amount_confirm compiles identical only under 1.3-2.0 (2.5/2.6
    # schedule it differently); every other function of the unit compiles the same.
    "pso/ui/city/TShopItemListWindow.cpp": {"mw_version": "GC/1.3"},
    "pso/ui/window/TWindowShortListCtrl_8026E7DC.cpp": {"mw_version": "GC/1.3", "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # Deferred inlining: functions come out in reverse source order and the
    # vtables before the switch tables in .data.
    "pso/ui/city/TMedicalCenterSequence.cpp": {"cflags": _switch(cflags_pso, "-inline deferred")},
    "pso/boss/barbaray/TBoss7LaserLight.cpp": {"cflags": _switch(cflags_pso, "-inline deferred")},
    # Its two string literals, the class names, sit in the unit's .rodata after the level table.
    "pso/boss/barbaray/TBoss7PhotonBullet_802EF26C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/derolle/TBoss2PhotonBullet_80038DCC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/derolle/TBoss2Fin.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/derolle/TBoss2Joint.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/dragon/TObjBoss1Crater.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/dragon/ObjBoss1CommonResource.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/olgaflow/Boss6Type2Data.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/goldragon/TBoss8DragonEffTail.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/dragon/ObjBoss1CommonJResource.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/barbaray/TBoss7Joint.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/darkfalz/TBoss4Thanks.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/olgaflow/TBoss6Zanzo.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TBoss7TentacleNeedle's vtable precedes TBoss7Tentacle's although every Needle virtual comes
    # first in .text: deferred, written from the unit's last function back.
    "pso/boss/barbaray/TBoss7TentacleNeedle.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/enemy/TObjEnemyCustom.cpp": {"cflags": _switch(cflags_pso, "-inline deferred", "-pool off", "-str reuse,readonly")},
    "pso/boss/volopt/TBoss3VoloptCore.cpp": {"cflags": _switch(cflags_pso, "-inline deferred")},
    "pso/boss/volopt/TBoss3VoloptP01.cpp": {"cflags": _switch(cflags_pso, "-inline deferred")},
    # Delbiter uses deferred code generation: reverse source definitions put
    # native vtables before the switch tables and functions in address order.
    "pso/enemy/nanodrago/TObjEneNanoDrago.cpp": {"cflags": _switch(cflags_pso, "-inline deferred", "-str reuse,readonly")},
    "pso/enemy/dellbiter/TObjEneDellBiter.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/enemy/dellbiter/TObjEneDellBiterEffects.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # The Bringer twin: its four vtables come out in ascending key-function order.
    "pso/enemy/bringer/BringerEffects.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # The Vol Opt fade tasks: deferred like the units above, but nothing is
    # inlined (the inline TUnk_804999E8 destructor and TObject::queue_destruction
    # stay calls).
    "pso/boss/TUnk_804848A0.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TItem.cpp is written from its last function back (deferred code
    # generation; the data keeps source order) and built with GC/2.0, like the
    # struct-copy units above.
    # The dragonfly base and its cave subclass: vtables come out subclass first.
    "pso/object/ambient/TOBiwaMushi.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-fp_contract on", "-str reuse,readonly", "-sdata 4")},
    "pso/object/cave/TODragonflyCave01.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-fp_contract on", "-str reuse,readonly", "-sdata 4")},
    # The cave rocks: one file, written from its last function back.
    "pso/object/cave/TORockCave.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/mine/TODragonflyMachine01.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on", "-str reuse,readonly", "-sdata 4")},
    # GC/2.0: apply_use_effect only schedules its effect-table copy as the original with 2.0, like TItem.cpp.
    "pso/item/TUnk_804F112C.cpp": {"mw_version": "GC/2.0"},
    "pso/item/TItem.cpp": {"mw_version": "GC/2.0", "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TItemProArmor.cpp, TItemProShield.cpp and TItemProUnit.cpp are written
    # from their last function back (deferred code generation, which also puts
    # each vtable before the switch tables).
    "pso/item/armor/TItemProArmor.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TODoorBase's vtable precedes its switch tables: deferred, written from
    # its last function back.
    "pso/object/door/TODoorBase.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # vtable before run_task's jump table: written last to first, deferred. -str readonly: strings in
    # .rodata 0x80440940; -sdata 4: the 8-byte model-name table sits in .data.
    "pso/enemy/dubchik/TOCtrlDubchik_8015CA74.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-fp_contract on", "-str reuse,readonly", "-sdata 4")},
    # TOBarrierEnergy01's vtable precedes its switch table too.
    "pso/object/fence/TOBarrierEnergy01.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/door/TODoorAncient01.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/door/TODoorAncient03.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/door/TODoorAncient04.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TItemProArmorParticle.cpp is written from its last function back too:
    # its data (class names, particle table) keeps source order.
    "pso/item/armor/TItemProArmorParticle.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TObjTreeLobby.cpp is written from its last function back: the
    # quest-damage task it also defines has its vtable after the tree's.
    "pso/object/lobby/TObjTreeLobby.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TObjLobbyMain.cpp too: its vtable precedes its two switch tables.
    "pso/object/lobby/TObjLobbyMain.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TObjParticleLobby.cpp too: its vtable precedes setup_emitter's jump table.
    "pso/object/lobby/TObjParticleLobby.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TItemMag's vtable precedes its switch tables: deferred, and written from
    # its last function back.
    "pso/item/mag/TItemMag.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # The bridges' vtables come out in the reverse of their .text order:
    # deferred, written from the unit's last function back. -fp_contract on:
    # TObjHashiBase::update_object_view_visibility fuses its multiply-adds.
    # The seabed tanks' vtables come out in .text order: deferred, written
    # from the unit's last function back.
    "pso/object/seabed/TObjSuisoChip.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/TObjHashi.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly", "-fp_contract on")},
    "pso/item/armor/TItemProUnit.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TOKey's vtable precedes its switch tables: deferred, and written from
    # its last function back.
    "pso/object/key/TOKey.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/item/armor/TItemProShield.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TItemEffNeedle.cpp too: its three vtables come out in the order only
    # deferred code generation gives (TItemEffNeedlePos keeps the implicit
    # destructor).
    "pso/effect/item/TItemEffNeedle.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TItemEquipBase.cpp keeps its class-name string in .rodata.
    "pso/item/TItemEquipBase.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TObjMotion.cpp keeps its class-name string in .rodata too.
    "pso/object/base/TObjMotion.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # The ancient doors keep their class-name and file-name strings in .rodata
    # (07's 8-byte model/motion name lists stay in .data: -sdata 4).
    "pso/object/door/TODoorAncient05.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/door/TODoorAncient06.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/door/TODoorAncient07.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    # 08 and 09 are written from their last function back (each vtable
    # precedes its switch tables: deferred code generation).
    "pso/object/door/TODoorAncient08.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly", "-sdata 4")},
    "pso/object/door/TODoorAncient09.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly", "-sdata 4")},
    "pso/object/door/TODoorCave01.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/object/door/TODoorCave02.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/object/door/TODoorMachine01.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/object/door/TODoorMachine02.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/object/door/TODoorVoShip.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/object/door/TODoorVS2Door01.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/object/door/TODoorCave03.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    # TItemMagSub.cpp (with TItemMagGrowEff) keeps its strings in .rodata, and
    # is written from its last function back: deferred code generation puts
    # the TItemMagGrowEff vtable first.
    "pso/item/mag/TItemMagSub.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TItemObject's vtable precedes its switch table: deferred, and written
    # from its last function back.
    "pso/item/TItemObject.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # Two tool classes built the same way: the material's vtable precedes its
    # switch table, and TUnk_8049FED0's TU emits its helper task's vtable first.
    "pso/item/TUnk_8049FBC0.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/item/TUnk_8049FED0.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/item/TUnk_804F0D34.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # Its ctor's switch table follows the vtable in .data.
    "pso/weapon/TUnk_804A4948.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/effect/item/TItemWpnCardEffect.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # Vol Opt's second form also keeps eight-byte tables in .data, a six-byte
    # one in .bss and four-byte pointers in .sbss; its .rodata initializers run
    # from the last function back and its vtable precedes the switch tables.
    "pso/boss/volopt/TBoss3VoloptP02.cpp": {"cflags": _switch(cflags_pso, "-inline deferred", "-sdata 4")},
    # The character appearance tables keep eight-byte descriptors in .data
    # but four-byte pointer lists in .sdata.
    "pso/ui/charcreate/CharacterAppearanceTables.cpp": {"cflags": _switch(cflags_pso, "-sdata 4")},
    # Vol Opt keeps its six-byte P01 order in .bss and its four-byte globals
    # in .sbss; its vtable precedes the switch tables in .data.
    "pso/boss/volopt/TBoss3Volopt.cpp": {"cflags": _switch(cflags_pso, "-inline deferred", "-sdata 4")},
    # Vol Opt's monitors keep their eight-byte texture lists in .data but the
    # four-byte class-name pointer in .sdata.
    "pso/boss/volopt/TBoss3VoloptMonitor.cpp": {"cflags": _switch(cflags_pso, "-inline deferred", "-sdata 4")},
    # The cave and machine map objects keep their eight-byte model-name lists
    # in .data but the four-byte motion-name list and class-name pointer in
    # .sdata.
    "pso/object/cave/TOAirconCave01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/object/cave/TOAirconCave02.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/object/ruins/TOCapsuleAncient01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/object/fence/TOFenceAncient01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/object/fence/TOFenceAncient02.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/object/fence/TOFenceAncient03.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/object/fence/TOFenceAncient04.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/object/mine/TOCapsuleMachine01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/object/lab/TOCapsuleLabo.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/object/mine/TOComputerMachine01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    # load_container_fragment_textures reaches each .rodata object with its own lis/addi: -pool off.
    "pso/object/container/TOContainerAncientEnemy.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/object/ruins/TOMonumentAncient01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/boss/darkfalz/TOBoss4.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on", "-str reuse,readonly", "-sdata 4", "-inline deferred")},
    "pso/boss/olgaflow/TBoss6Rock.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on", "-str reuse,readonly", "-inline off,deferred", "-str reuse,readonly")},
    "pso/boss/olgaflow/TBoss6Type2_80336E6C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/olgaflow/TBoss6Type2.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on")},
    "pso/boss/olgaflow/TBoss6Type2_802BE588.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-inline off,deferred", "-str reuse,readonly")},
    "pso/boss/olgaflow/TBoss6CrushRock.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on", "-inline off,deferred", "-str reuse,readonly")},
    "pso/boss/olgaflow/TBoss6SwordShot.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on")},
    "pso/boss/olgaflow/TBoss6GravBall.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on")},
    # -inline deferred: the TU inlines its inline helpers one level deep (no auto-inlining) and emits its functions in
    # reverse source order; -fp_contract on: its float math fuses into fmadds/fnmsubs throughout.
    # sub_802B59CC and the other users reach each of TBoss6Type1's .rodata tables with their own lis/addi
    # (no shared .rodata base): -pool off.
    "pso/boss/olgaflow/TBoss6Type1.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on", "-inline deferred", "-pool off")},
    "pso/object/warp/TObjCityMainWarpChallenge.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/TObjTombstone.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-fp_contract on", "-str reuse,readonly")},
    "pso/object/cave/TOCakeshopCave01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/object/mine/TOHangerMachine01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/object/mine/TOMonitorMachine01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/object/cave/TORainbowCave01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly", "-fp_contract on")},
    "pso/object/cave/TORevlightCave01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/object/cave/TOSignCave01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/object/cave/TOSignCave02.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/object/cave/TOSignCave03.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/object/ruins/TOMonumentAncient02.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly", "-fp_contract on")},
    # Kurage addresses each debug label on its own (no shared .rodata base).
    "pso/object/ambient/TOKurage.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly", "-fp_contract on", "-pool off")},
    # The TBinModel ctor (0x8002058C) inlines its list helpers; "gvm" is in .sdata2 (readonly strings) and
    # every literal gets its own lis/addi (no pool base).
    "pso/unk/TLobby_8001EF5C.cpp": {"cflags": _switch(cflags_pso, "-inline on", "-str reuse,readonly", "-pool off")},
    "pso/object/TOHealGeneral.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    # The key subclasses address each of their texture names on its own
    # (no shared .rodata base): built -pool off.
    "pso/object/key/TOKeyAncient01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly", "-pool off")},
    "pso/object/key/TOKeyAncient02.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly", "-pool off")},
    "pso/object/key/TOKeyAncient03.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly", "-pool off")},
    "pso/object/key/TOKeyCave01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly", "-pool off")},
    "pso/object/key/TOKeyCol.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly", "-pool off")},
    "pso/object/key/TOKeyMachine01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly", "-pool off")},
    "pso/object/key/TOKeyJungleMain.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly", "-pool off")},
    # TObjFish::run_task reaches its .rodata frame tables, the int->float magic and 10430.38 with a lis/addi each
    # (no shared .rodata base): built -pool off.
    "pso/object/ambient/TObjFish.cpp": {"cflags": _switch(cflags_pso, "-pool off")},
    # The sensor base: its vtable comes before its jump tables.
    "pso/object/switch/TOSensor.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/switch/TOSwitchItem.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TOSwitchAttackSub.cpp keeps both class name strings in .rodata (-str readonly) and reaches its
    # .rodata tables with their own lis/addi: -pool off.
    # TObjRoomId.cpp keeps its class name and debug label strings in .rodata (-str readonly) and
    # reaches each .rodata object with its own lis/addi: -pool off.
    # TBoss6Thanks.cpp keeps its class name string in .rodata (-str readonly) and reaches each
    # .rodata object with its own lis/addi: -pool off.
    "pso/boss/olgaflow/TBoss6Thanks.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    # text_8034960C.cpp keeps TAdLoadQuestCellGC's name string in .rodata (-str readonly) and
    # reaches each .rodata table with its own lis/addi: -pool off.
    "pso/unk/text_8034960C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    # text_802FF760.cpp keeps TAdMultiConfirmGC's name string in .rodata (-str readonly) and
    # reaches each .rodata object with its own lis/addi: -pool off.
    "pso/unk/text_802FF760.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/object/TObjRoomId.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/object/switch/TOSwitchAttackSub.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/object/switch/TOSensorAncient01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly", "-pool off")},
    "pso/object/switch/TOSensorGeneral01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly", "-pool off")},
    # Unlike the other keys it addresses its descriptors off one .data base.
    "pso/object/key/TOKeyGenericSw.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    # The character creation camera: deferred with nothing inlined, and its
    # multiply-adds contracted into fmadds.
    "pso/camera/CreationCamera.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-fp_contract on")},
    # The pad rumble and Ninja helper code contract multiply-adds into fmadds/fnmsubs.
    "pso/system/PadRumble.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on")},
    "pso/render/NinjaUtil.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on")},
    "pso/render/TFogCtrl.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # The render helpers (0x801412D0-0x80142770): GC/1.3.2, one .sdata2 pool. Only
    # 1.3.2 keeps approach_vector_fixed_distance's early-out copy unscheduled.
    "pso/render/render_util.cpp": {"mw_version": "GC/1.3.2", "cflags": [*_switch(cflags_pso, "-fp_contract on"), "-DPSO_SDK_COMPACT_MATH"]},
    "pso/render/render_util_head.cpp": {"mw_version": "GC/1.3.2", "cflags": [*_switch(cflags_pso, "-fp_contract on"), "-DPSO_SDK_COMPACT_MATH"]},
    "pso/render/render_util_tail.cpp": {"mw_version": "GC/1.3.2", "cflags": [*_switch(cflags_pso, "-fp_contract on"), "-DPSO_SDK_COMPACT_MATH"]},
    # Metrowerks' GCN_Mem_Alloc.c (runtime library code at -O4,p); belongs
    # in the runtime lib under its own name.
    "pso/unk/text_8039739C.cpp": {"cflags": _switch(cflags_pso, "-O4,p")},
    "pso/quest/QuestOpcodeHandlers.cpp": {"cflags": _switch(cflags_pso, "-inline on", "-str reuse,readonly")},
    "pso/quest/TQuestThread.cpp": {"cflags": _switch(cflags_pso, "-inline on")},
    # The quest-list vtable precedes its switch table: deferred, written from
    # its last function back. Its titles and window sizes are addressed one
    # by one (no shared .rodata base), and its strings are read-only.
    "pso/quest/TQuestListVM.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-pool off", "-str reuse,readonly")},
    # load_battle_param_entry reaches each .rodata object with its own lis/addi: -pool off.
    "pso/unk/TLobby_8001D6A0.cpp": {"cflags": _switch(cflags_pso, "-pool off")},
    # TItemData.cpp reaches each .rodata object with its own lis/addi: -pool off.
    "pso/item/TItemData.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    # TObjNpcEnemy.cpp reaches each .rodata object with its own lis/addi: -pool off.
    "pso/npc/TObjNpcEnemy.cpp": {"cflags": _switch(cflags_pso, "-pool off")},
    "pso/object/collision/TObjFogCollisionPoison.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TLobby_801F3A24.cpp reaches each .rodata object with its own lis/addi: -pool off.
    "pso/unk/TLobby_801F3A24.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    # TWindowChatSymbol.cpp reaches each .rodata object with its own lis/addi: -pool off.
    "pso/ui/chat/TWindowChatSymbol.cpp": {"cflags": _switch(cflags_pso, "-pool off")},
    "pso/player/PhotonBlastResults.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -sdata 4: the 8-byte model name table sits in .data and the 8-byte 0x805007D4 in .bss, next to the 4-byte .sdata name pointer.
    "pso/enemy/berura/TObjEneRe7Berura.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/ui/keyboard/TKeyBoardControl.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/goldragon/TObjBoss8Piller.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/text_803626A8.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -sdata 4: the 8-byte name tables sit in .data while 4-byte objects sit in .sdata.
    "pso/unk/text_8035B750.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/object/ambient/TObjCGrass.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/object/TObjLiveMonitor.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # Each debug string is reached with its own lis/addi (no pooled base register).
    "pso/object/collision/TObjFogCollisionSwitch.cpp": {"cflags": _switch(cflags_pso, "-pool off")},
}

# MusyX (Factor 5). Its objects carry extab/extabindex for every non-leaf
# function: C++ with exceptions on reproduces them and leaves .text alone.
cflags_musyx = _switch(cflags_pso, "-O4,p", "-sdata2 8", "-Cpp_exceptions on") + ["-lang=c++"]

# Prebuilt middleware after MusyX, in link order: (name, first .text address,
# compiler, flags, per-file exceptions). Each library runs to the next one's
# address; the version strings in their data name them.
cflags_middleware = _switch(cflags_pso, "-O4,p", drop=("-sdata2",))
# CRI built its libraries with -inline auto (the RE4 decomp builds every CRI file with it).
cflags_cri = _switch(cflags_middleware, "-inline auto")
MIDDLEWARE: List[Tuple[str, int, str, List[str], Dict[str, Dict[str, Any]]]] = [
    # MusyX's synthesizer core, then its service, hardware and effect files.
    ("musyx", 0x803A3858, "GC/1.2.5n", _switch(cflags_musyx, "-opt nocse"), {}),
    ("musyx_hw", 0x803BAC70, "GC/1.2.5n", _switch(cflags_musyx, "-inline auto"), {}),
    # CRI ADX, LSC, SJ, MFCI and GCRNA ("Build:Jun 13 2002").
    ("cri", 0x803BFE50, "GC/2.6", cflags_cri, {
        # These files pool their string literals (-str reuse,readonly).
        "pso/unk/text_803CC294.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
        "pso/unk/text_803CE568.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
        "pso/unk/text_803CFEA0.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
        "pso/unk/text_803D31A4.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
        "pso/audio/LscInit.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
        # Their strings (chunk tags, error messages, the build string) are read-only data: .sdata2 and .rodata.
        "pso/audio/AdxAiff.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
        "pso/audio/AdxAu.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
        "pso/audio/AdxBsc.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
        "pso/audio/AdxSpsd.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
        "pso/audio/AdxtInit.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
        "pso/audio/AdxEncoder.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
        "pso/audio/AdxTalk.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
        "pso/audio/AdxtStart.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
        "pso/audio/AdxtServer.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
        "pso/audio/AdxManager.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
    }),
    # Sega's Ginja model library.
    ("ginja", 0x803D6538, "GC/2.6", _switch(cflags_middleware, "-O3,p", "-opt nopeephole"), {
        # Saves registers through _savegpr_N everywhere (no stmw in the unit).
        "pso/unk/text_803E2D70.cpp": {"cflags": _switch(cflags_middleware, "-O3,p", "-opt nopeephole", "-use_lmw_stmw off")},
        "pso/unk/text_803E2F28.cpp": {"cflags": _switch(cflags_middleware, "-O3,p", "-opt nopeephole", "-use_lmw_stmw off")},
    }),
    # mcFsGc ("Ver 1.10.00 Build:Sep 17 2002") with ACCESS's file transfer.
    ("mcfs", 0x803E5668, "GC/1.2.5", cflags_middleware, {
        # Epilogue order (mtlr before the restores) only 1.2.5n produces.
        "pso/ui/keyboard/TKeyBoardControl_803F0C50.cpp": {"mw_version": "GC/1.2.5n"},
        "pso/unk/text_803F1804.cpp": {"mw_version": "GC/1.2.5n"},
        # Its loops keep base + index offsets instead of walking pointers
        # (0x803F2F1C, 0x803F31D8); the rest of the file is the same either way.
        "pso/ui/frontend/TAdPlayerLoadGC_803F18B8.cpp": {"cflags": _switch(cflags_middleware, "-opt nostrength")},
    }),
    # ntInf ("Ver 1.17.00 Build:Jul 9 2002").
    ("ntinf", 0x803F3BF8, "GC/2.6", cflags_middleware, {
        "pso/unk/text_803F4D84.cpp": {"cflags": _switch(cflags_middleware, "-O2", "-use_lmw_stmw off")},
    }),
    # ACCESS AVE-TCP ("avetcp.a Ver.1.16.1 Oct 23 2002"); its PPP files were
    # built without common subexpression elimination.
    ("avetcp", 0x803F7678, "GC/1.2.5n", cflags_middleware, {
        "pso/network/TLobby_803F86BC.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetworkRuntime.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetworkThreadRuntime.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/TLobby_803FAEA0.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/TLobby_803FC178.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/TLobby_803FCF44.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetPppLink.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/PppFsm.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/PppIpcp.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/PppLcp.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/PppBuffer.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/PppMd5.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetByteOrder.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/PppPap.c": {"cflags": _switch(cflags_middleware, "-opt nocse", "-str reuse,readonly")},
        "pso/network/PppControl.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/PppVj.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/TLobby_804048E8.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/TLobby_804050DC.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetArp.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetEthernet.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetHandlerTable.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetDns.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetIcmp.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetIcmp6.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetAddrFamily.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetIpv4.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetIpv4Route.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetIpv6.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/TLobby_8041112C.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetLoopback.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetBufferPool.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetIPv6NeighborDiscovery.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetFragment.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetDispatcher.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetTcp.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
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
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/ctype.c",
                            mw_version="GC/1.3", cflags=cflags_native_recovered),
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/locale.c",
                            mw_version="GC/1.3", cflags=cflags_native_recovered),
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
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/float.c",
                            mw_version="GC/1.3", cflags=cflags_native_recovered),
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
