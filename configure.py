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
    "-i include/clib",  # the C library's headers, as the game's code sees them
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
    # The ending credits keep their 8-byte texture list in .data.
    "pso/ui/frontend/TAdEndText.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    # pack_movie_frame keeps every named local in one register, recomputes its pad and
    # stride shifts and leaves invariant hoisting to the backend. The frame-buffer
    # functions after it (flush_cache..flush_framebuffer, same TU) match under these too.
    "pso/system/movie/MovieFramePack.cpp": {"cflags": _switch(cflags_pso, "-opt nolifetimes,nocse,noprop,noloop")},
    # TObjChara's vtable sits ahead of the jump tables and its methods run in reverse
    # slot order: deferred generation of the last-to-first source. The EXP/TP/HP labels
    # are 4-byte string literals in .sdata2.
    "pso/object/base/TObjChara.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/ui/frontend/DrawLine.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-fp_contract on")},
    # .rodata holds assign_photon_blast_palette_slot's id table ahead of the earlier
    # assign_default_photon_blast_palette_slots's: deferred generation of the last-to-first source.
    "pso/system/data/pso_const_ids4.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # .rodata holds render's scale vector ahead of the int-to-float constant the earlier
    # TTecReverser::sub_8022BE64 uses: deferred generation of the last-to-first source.
    "pso/technique/TTecCircle.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/effect/TDuelEffectCtrl.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/TDuelEffectNumber.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/TDuelEffectString.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-fp_contract on")},
    # -sdata 4: the 8-byte texture lists (clitical_texture_list, technique_ringwave_texture_list) are outside small data.
    "pso/effect/TEffClitical.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/effect/item/TItemEffArmor.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/barbaray/TObjBoss7Tunnel.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/TLobby_803382E4.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/TObjControl.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -sdata 4: its 8-byte leader selection 0x805011D8 sits in .bss, not .sbss.
    "pso/ui/font/TFontSmallTask.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/ui/window/TWindowSubStatusDisp_80338740.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # its class-name string sits in .rodata ahead of the list size pair: readonly strings.
    "pso/ui/window/TWindowSubShortCutList.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # its class name ("TChCrCharSelect", 0x80464E60) opens its .rodata ahead of its tables: readonly strings.
    "pso/ui/charcreate/TChCrCharSelect.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # its class name ("TBoss5GryphonTornado", 0x804792E4) follows the particle id table in .rodata: readonly strings.
    "pso/boss/galgryphon/TBoss5GryphonTornado.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # its class name sits in .rodata and the "" its name fallback points at opens its .sdata2: readonly strings.
    # .data holds the vtable ahead of run_task's jump table: deferred generation of the last-to-first source.
    "pso/ui/window/TWindowMakeTeam.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # .data holds the vtable (0x804CF038) ahead of create's jump table: deferred generation of the last-to-first source.
    "pso/ui/window/TWindowEffectParty.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # -inline off,deferred: .data is the layout tables, the vtable, then the jump tables.
    "pso/ui/window/TWindowFukidasi.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # .data holds the vtable (0x804D16C0) ahead of run_task's jump table: deferred generation of the last-to-first source.
    "pso/ui/window/TWindowSubMag.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # .data holds the vtable (0x804DE8C8) ahead of run_task's jump table: deferred generation of the last-to-first source.
    "pso/ui/window/TWindowSubTrade.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # .data holds the vtable (0x804D1568) ahead of the switch table: deferred generation of the last-to-first source.
    "pso/ui/window/TWindowSubEquip_80277DF8.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # both class names (TODummyKeyCave01, TODummyKeyCave01Sound) sit in .rodata: readonly strings. .data holds
    # TODummyKeyCave01Sound's vtable, then sub_80165940's jump table, then TODummyKeyCave01's vtable: only
    # deferred code generation of the last-to-first source emits them in that order.
    "pso/object/key/TODummyKeyCave01.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # its class name sits in .rodata and the layout table's pooled ":" opens its .sdata2: readonly strings.
    "pso/ui/window/TWindowShortCut.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # its class name "TBreakUpMdl" sits in .rodata between the default parameter row and colour: readonly strings.
    "pso/effect/TBreakUpMdl.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # the four effect class names sit in .rodata, pointed to by .sdata 0x805D29B8..C4: readonly strings.
    # -inline off,deferred: the four vtables follow the text in forward order (EffLight first), so the
    # source runs from the last function back; -fp_contract on: EffLight::render and
    # EffDischarge::run_task use fmadds.
    "pso/enemy/canadin/CanadinEffects.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly", "-fp_contract on")},
    "pso/ui/window/TWindowArea.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # its only string (the empty entry text) sits in .sdata2, as in its sibling parts _80336054/_8033A8EC.
    # .data holds the vtable ahead of run_task's jump table: deferred generation of the last-to-first source.
    "pso/ui/frontend/TAdEnterSerialAccessGC.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/ui/frontend/TAdSinglePlyChrSelectGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/city/TShopDeleteItemWindow.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/TLobby_80207DA8.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/item/TItemReverseTech.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/hud/TNowLoading.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TItemLoad.cpp's six vtables (0x8049F3F4..0x8049F448) follow its text in
    # forward order: deferred code generation, written from its last function back.
    "pso/item/TItemLoad.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # -str reuse,readonly: "PlyEndingMotionData.rel" 0x80447190 (801D84CC) and "PlyLevelTbl.cpt" 0x804492E8
    # (801D8ADC) sit in .rodata.
    "pso/player/TObjPlayer_801D84CC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/player/TObjPlayer_801D8ADC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # vtables come out TCameraConversation, TCameraPan then TCameraFixed (the text order of their
    # dtors): written last to first, deferred.
    "pso/camera/TCameraConversation.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # -sdata 4: its last .bss object (0x8050BEB8) is 8 bytes.
    "pso/network/TPlyJoinLobbyEntry.cpp": {"cflags": _switch(cflags_pso, "-sdata 4")},
    # -sdata 4: the 8-byte load/release callback tables of BOSS01 (0x804A7358), BOSS02 (0x804A7360)
    # and BOSS05 (0x804A7368) sit in .data, not .sdata.
    "pso/map/area/AreaBoss01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4")},
    "pso/map/area/AreaBoss02.cpp": {"cflags": _switch(cflags_pso, "-sdata 4")},
    "pso/map/area/AreaBoss05.cpp": {"cflags": _switch(cflags_pso, "-sdata 4")},
    # -sdata 4: the 8-byte camera bank list 0x80488B98 sits in .data, not .sdata.
    "pso/camera/TCameraWatchPlayer.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    # -sdata 4: the 8-byte creation_sprite_table and ccconsole_pvm_file_name_table sit in .data while
    # the 4-byte ui_sprite_scale is in .sdata; the texture and pvm names sit in .rodata: readonly strings.
    "pso/ui/UISprite.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    # -sdata 4: its 8-byte task list sits in .bss, not .sbss.
    "pso/technique/TTecZondeEff.cpp": {"cflags": _switch(cflags_pso, "-sdata 4")},
    # The TBoss8DragonEffBullet constructor reaches each of its three .rodata particle tables with its own lis/addi: -pool off.
    "pso/boss/goldragon/TBoss8DragonEffBullet.cpp": {"cflags": _switch(cflags_pso, "-pool off")},
    # run_task and get_target_position reach each .rodata object with its own lis/addi: -pool off.
    "pso/camera/TCameraDebugView.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/effect/item/TItemEffBringer.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/item/TItemEffCane.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/item/TItemEffEquip.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/item/TItemEffLavis.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/photon/TPhotonEstlla.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/photon/TPhotonFarlla.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # setup_photon_blast_camera reaches its four .rodata camera offsets with a lis/addi each: -pool off.
    "pso/effect/photon/PhotonBlastSummon.cpp": {"cflags": _switch(cflags_pso, "-pool off")},
    # render reaches each of its .rodata vectors and angles with its own lis/addi (no shared base): -pool off.
    "pso/effect/particle/ParticleBallistic.cpp": {"cflags": _switch(cflags_pso, "-pool off")},
    # .rodata holds generate_child_default's zero vector and the generator names ahead of
    # apply_particle_model_fade_color's conversion constant, while .sdata2 follows text order:
    # deferred generation of a TU written last to first (0x80085EE4-0x80086884).
    "pso/effect/particle/TParticle.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/effect/photon/TPhotonConcentrate.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TPhotonMylla__ct reaches its packet template with its own lis/addi (no shared .rodata base): -pool off.
    "pso/effect/photon/TPhotonMylla.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    # the TAdStorySelectGC ctor reaches each of its .rodata initialisers with its own lis/addi (no shared base): -pool off.
    "pso/ui/frontend/TAdStorySelectGC_802C3284.cpp": {"cflags": _switch(cflags_pso, "-pool off")},
    "pso/object/TObjLuker_801329B0.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -inline off,deferred: the ctor reaches __vt__16TObjOnlineEnding through the unit's .data
    # anchor, so the vtable is pooled before the functions; the source runs from the last function back.
    "pso/object/ending/TObjOnlineEndingMain.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # -inline off,deferred: the ctor reaches __vt__21TObjHMS_EZRope_Player through the unit's .data
    # anchor and the HMS vtable precedes the base's, so the source runs from the last function back.
    "pso/object/TObjHMS_EZRope_Player.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/ui/frontend/TAdPlayerLoadGC.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/ui/frontend/TAdDialingMessageWindow.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/ui/frontend/TAdSubPlyItemGC_802D6BEC.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/ui/TLogo.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # vtables come out 1BB0, 1CA8, the create_object_by_type jump table, then
    # 1E08..23F0 (text order of their dtors): written last to first, deferred.
    "pso/player/TObjPlayer_802D5174.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # vtables come out TUnk_804E70A8 then TUnk_804E71A0: written last to first, deferred.
    # -sdata 4: the 8-byte shared_capture_texture_list is addressed outside small data.
    "pso/player/TObjPlayer_80307618.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly", "-sdata 4")},
    # vtables come out TUnk_804A0568..0688 (text order of their vfunc_6) then
    # TItemTimerEvent: written last to first, deferred.
    "pso/item/TItemTimerEvent.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # vtables come out 0810, 0908, 0A00, 0AF8 then 0BF0: written last to first, deferred.
    # The TUnk_804F0908 (Rappy's Fan) and TUnk_804F0AF8 (with the Gi-Gue bazooka) units end at
    # .sdata2 pads (0x805DFDFC, 0x805DFE04) before TItemEffPG; all three keep deferred backwards source.
    "pso/weapon/TUnk_804F0908.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/weapon/TUnk_804F0AF8.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/effect/item/TItemEffPG.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # vtables come out TUnk_804A2548 then TUnk_804A2564: written last to first, deferred.
    "pso/player/TUnk_804A2548.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # vtables come out TUnk_804A5D10 then TUnk_804A5D28: written last to first, deferred.
    "pso/weapon/TUnk_804A5D28.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # __vt__18TWindowSubShortCut (804D19D8) comes out before the run_task jump
    # table (804D19F0): written last to first, deferred.
    "pso/ui/window/TWindowSubShortCut.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # vtables come out KeyQuick, Key, Normal then TUnk_804B2578: written last to first, deferred.
    "pso/object/cave/TOHangceilingCave01.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # vtables come out TUnk_804A6F78, F90, FA8 then FC0 (text order of their key functions): written last to
    # first, deferred.
    "pso/object/ambient/TObjLight_80133568.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/object/TDeadSpot.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/ui/hud/TMainCursor.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # vtables come out StelthReal, then the dispatch_state jump table, then Stelth: written last to first, deferred.
    "pso/enemy/stelth/TObjEneMe3Stelth.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/enemy/bringer/TObjEneDf2Bringer.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/sorcerer/TObjEneRe4Sorcerer_800EDB98.cpp": {"cflags": _switch(cflags_pso, "-inline on,deferred", "-str reuse,readonly")},
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
    "pso/ui/city/TShopGetItemWindow.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/item/shop/TShopGenerator.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/npc/TNpcPlayer.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # Inline the generated row-position assignment to preserve its two word-pair copies.
    "pso/ui/window/TWindowMainMenu_802AD538.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-inline noauto,level=1")},
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
    "pso/ui/window/TWindowDD_80341A08.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-fp_contract on")},
    # -str readonly: every string of these units is read-only data ("SELECT"/"NEXT" of the constructor in .rodata,
    # the Spanish "\xBF"/"\xA1" marks of 0x80345608 in .sdata2, each pooled once).
    "pso/ui/window/TWindowDD_803430BC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-inline off,deferred")},
    "pso/ui/window/TWindowDD_8034435C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # ws_data_load reaches each .rodata object with its own lis/addi (no shared base): -pool off.
    "pso/ui/window/TWindowDD_80346A84.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/ui/window/TWindowCtrlMain.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # get_viewport_offset reaches each of its three .rodata viewport tables with its own lis/addi
    # (no shared .rodata base, though the tables precede the unit's pooled double): -pool off.
    "pso/ui/window/WindowDrawContext.cpp": {"cflags": _switch(cflags_pso, "-pool off")},
    # its language letters ("J".."S") and "W:"/" D:" sit in .sdata2 as 4-byte-or-less readonly strings.
    "pso/ui/window/TWindowCtrlMain_800FC91C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdSelectTxtSubGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdBackGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
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
    # TAdMultiPlyChrSelectGC (0x802DBCC4-0x802E0064): deferred, written last to first, since the
    # functions' slot descriptors 0x80472848-0x804728A8 run in the reverse of their functions' order.
    # -str reuse,readonly: the class name 0x80472810 sits in .rodata and "" in .sdata2 (0x805DE898).
    "pso/ui/frontend/TAdMultiPlyChrSelectGC.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
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
    # The resource file names and the class name of TObjEneBm9Mericarol sit in .rodata: readonly strings.
    "pso/enemy/mericarol/TObjEneBm9Mericarol.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # The resource file names and the class name of TObjEneMorfos sit in .rodata: readonly strings.
    "pso/enemy/morfos/TObjEneMorfos.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/mericarol/TObjEneBm9Mericarol_Bomb.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/mericarol/TObjEneBm9Mericarol_EffCurse3.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/epsilon/TObjEneEpsilonGuard_8035DD68.cpp": {"mw_version": "GC/2.0", "cflags": _switch(cflags_pso, "-str reuse,readonly")},
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
    # .data holds the vtable ahead of sub_802D9110's jump table: deferred generation of the last-to-first source.
    "pso/enemy/gibbles/TObjEneGibbles.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/door/TODoorLabo.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/effect/photon/TPhotonGolla.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/photon/TPhotonPilla.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/fence/TObjLazerFenceNorm.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # -sdata 4: the four 8-byte model name tables 0x804E07A0/0x804E07D4/0x804E0800/0x804E082C sit in .data, not .sdata.
    # vtables come out TUnk_804E0898, 08D4, 0910, 094C, 0988 then TObjPathObj: written last to first, deferred.
    "pso/object/lobby/LobbyPigeonPath.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-sdata 4", "-str reuse,readonly")},
    "pso/boss/olgaflow/TBoss6Tube.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/jungle/TOJungleDesign.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TTitleScene.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/TLobby_801461EC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # load_area_enemy_set/load_area_object_set reach each .rodata object with their own lis/addi: -pool off.
    "pso/unk/TLobby_80209524.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/unk/TLobby_80226C3C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/TLobby_80228818.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/TLobby_800F8AA8.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/text_80066F10.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/npc/TObjNpcNgcBase.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/object/fence/TOVS2Wall01.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/derolle/TObjBoss2CeilJunk_8003A81C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowDD_8034725C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/trap/TOMine.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/trap/TOMineIcon01.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/trap/TOMineIcon02.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/trap/TOMineIcon03.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/trap/TOMineIcon04.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/warp/TObjLaboMapWarp.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-inline off,deferred", "-pool off", "-sdata 4")},
    # -str reuse,readonly: the model/archive names 0x80444280-0x80444720 sit in .rodata.
    # -sdata 4: the 8-byte name lists 0x804B5E8C/0x804B5EC0 sit in .data, the 4-byte {NULL} lists in .sdata.
    "pso/unk/text_80184C2C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    # The .rodata initialisers (0x8044A698-0x8044A7A0) all precede the code literals and the vtables come out
    # TRaderMapCore then TUnk_804C88A8: written last to first, deferred.
    "pso/ui/hud/TRaderMapCore.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/ui/charcreate/TChCrEffTag.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdAgreementBaseGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdEnterPasswordGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdWarningBaseGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdEnterPPPPassGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -inline off,deferred: __vt__23TObjOnlineEndingHexLine precedes the HexMove vtable although
    # HexLine's key function comes first, so the source runs from the last function back.
    "pso/object/ending/TObjOnlineEndingHexLine.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/boss/galgryphon/TBoss5GryphonShockWave.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/gyaranzo/TObjGyaranzoMissile.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowChoiceSetting.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/chat/TWindowSubSymbolChatPartsSet.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # .data holds lbl_804D2B48 and the vtable ahead of run_task's jump table: deferred generation of the last-to-first source.
    "pso/ui/chat/TWindowSubSymbolChat.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # .data holds only the vtable; text runs create_status_category_menu..ctor: deferred generation of ctor-first source.
    "pso/unk/TUnk_804D1AD0.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # its class-name string sits in .rodata ahead of the list/window size pairs: readonly strings.
    "pso/ui/chat/TWindowSubShortMail.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # its class-name string sits in .rodata and its short layout strings ("Lv", ":", "pt") in .sdata2: readonly strings.
    # .data ends rank table then vtable after the page-table statics, .sdata2 runs the layout strings, rank strings, 7.5f, 1.0f:
    # deferred generation of the ctor-first source (the page dispatchers were the deferred pair).
    "pso/ui/window/TWindowSubStatusDisp_8027FD88.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/boss/derolle/TBoss2Tentacle.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/derolle/TObjBoss2Tunnel_8003B138.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/charcreate/TChCrEffWall.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/charcreate/TChCrTagOccHeader.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/charcreate/TChCrTagOccupation.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TLobby__sub_8034DAA0 addresses its four .rodata parameter records with a lis/addi each (no shared
    # .rodata base): built -pool off.
    "pso/npc/NpcPartnerControl.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly", "-pool off")},
    "pso/npc/TNpcTalkTrigger.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/panarms/TObjEnePanarmsAtkColli.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/seabed/TObjSeabedSuisoBrakable.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # The TLevelSelect ctor reaches each .rodata object with its own lis/addi (no shared base): -pool off.
    "pso/ui/TLevelSelect.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    # -sdata 4: the 8-byte texture_logo_e_descriptor is addressed outside small data.
    "pso/ui/TLogo_8001C134.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/ui/window/TObjNewFloorWin.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # Its ctor reaches each .rodata object with its own lis/addi (no shared base): -pool off.
    "pso/ui/frontend/TAdMultiChgGameModeGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    # -str reuse,readonly: create_mode_scene's "advr.adx" sits in the unit's .rodata.
    "pso/ui/frontend/TAdMultiChgGameModeGC_8023E7A8.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdMultiSelGameModeGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdMultiChgGameModeGC_8036DE10.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -str reuse,readonly: the class name string 0x80477DA0 sits in .rodata.
    # -sdata 4: the 8-byte menu position 0x804EF8D8 sits in .data, the 4-byte menu width in .sbss.
    "pso/ui/TCharSaveSequence.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/system/save/TCheckMemoryCard.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    # -str reuse,readonly: the class name string 0x80472920 sits in .rodata.
    # -sdata 4: the 8-byte window positions 0x804E3040-58 sit in .data, the 4-byte menu width in .sbss.
    # -fp_contract on: T_ATS_DrawCalendar::render uses fnmsubs and the static initialiser fmadds.
    # -inline off,deferred: __vt__18T_ATS_DrawCalendar (0x804E34FC) sits before __vt__12TAdTimeSetGC (0x804E3514)
    # although the functions and literals are in address order; the source is written last function first.
    "pso/ui/frontend/TAdTimeSetGC.cpp": {
        "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly", "-sdata 4", "-fp_contract on")
    },
    "pso/ui/frontend/TAdLoadQuestPrtTxtGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdScrollWinGC.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/ui/window/TWindowSubComCard_8007341C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/unk/text_800FA464.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/item/shop/ShopToolStock.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/item/shop/ShopWeaponStock.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowSubStatusDisp_80228CC0.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # its class-name string sits in .rodata ahead of the decimal place table: readonly strings.
    "pso/ui/window/TWindowInputNumber.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -str reuse,readonly: every string of the TU sits in .rodata: the class name 0x8044F520 and
    # "LEVEL " 0x8044F534, "HP +" 0x8044F53C, "TP +" 0x8044F544. update_stat_messages reaches those
    # three strings with a lis/addi each (no shared .rodata base): -pool off.
    # .data holds the vtable ahead of update_stat_messages's jump table: deferred generation of the last-to-first source.
    "pso/ui/window/TWindowSetLevelUp.cpp": {"cflags": _switch(cflags_pso, "-inline on,deferred", "-str reuse,readonly", "-pool off")},
    "pso/ui/window/TWindowChallengeResult.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/text_8013F810.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/network/TProtocol_801DA240.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/network/TProtocol.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/olgaflow/TBoss6EmptyWarp_802B0E2C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/olgaflow/TBoss6PlotFalz_802B0228.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/effect/photon/TPhotonLeilla.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/photon/TPhotonLine.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/text_8028A820.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/trap/TOTrapSeabed01.cpp": {"cflags": _switch(cflags_pso, "-inline on,deferred", "-str reuse,readonly", "-sdata 4")},
    "pso/object/trap/TOTrapAncient02.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-fp_contract on", "-str reuse,readonly", "-sdata 4")},
    "pso/npc/TObjNpcMoja.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # Deferred files: the constructor reads the vtable from the pooled .data base.
    "pso/npc/TObjNpcLappy.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/npc/TObjNpcBringer.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/npc/TObjNpcNFM01.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/npc/TObjNpcNFM00.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/system/movie/TMovie.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/unk/TUnk_8048E1A4.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -sdata 4: the 8-byte texture lists (lbl_804CC868, technique_ringwave_texture_list) are outside small data.
    "pso/unk/TUnk_804CC870.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/ui/window/TWindowSubStatusDisp_80288030.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    # -inline off,deferred: the named float constants 0x805DE9C8-0x805DEA04 sit in .sdata2, are loaded
    # by address (not folded), and precede the TU's own literal pool (76.0/-75.0): written last to first.
    "pso/player/TObjPlayer_802E6CA8.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # -sdata 4: the 8-byte technique_ringwave_texture_list sits in .data, not .sdata.
    "pso/technique/TechniqueRingwaveList.cpp": {"cflags": _switch(cflags_pso, "-sdata 4")},
    # -sdata 4: the 8-byte NJS_TEXLISTs sit in .data, not .sdata.
    "pso/player/TObjPlayer_80083594.cpp": {"cflags": _switch(cflags_pso, "-sdata 4")},
    # -str reuse,readonly: the five string literals sit in .rodata; -sdata 4: the 8-byte
    # motion name list sits in .data, the 4-byte name pointer in .sdata.
    "pso/object/lobby/TObjButterflyLobby_80350958.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    # -str reuse,readonly: the three string literals sit in .rodata; -sdata 4: the
    # 8-byte texture lists sit in .data, the 4-byte pointers in .sdata/.sbss.
    "pso/ui/frontend/TAdSelectCurGC_802AED98.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    # .sdata2 starts with the {44, 46} template of sub_800D6D64 (near the end of .text), then the floats in
    # forward .text order; .rodata has the two templates in reverse .text order: -inline off,deferred.
    "pso/enemy/merilllia/TObjEneMerillLia.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # the class name sits in .rodata 0x804349C0; run_task reaches now_loading_pos and both Vec templates with a lis/addi each: -str reuse,readonly, -pool off.
    # The 1-byte chr_select_state at 0x805D4A78 is followed by 7 pad bytes, so 0x805D4A80 starts a new TU: 0x8001C5F8 cuts the unit.
    "pso/system/TLoadCtrl.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/unk/TLobby_80299C4C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/TLobby_80299B90.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # the scene music names and the retry class name sit in .rodata 0x804651A0-0x804651F8: -str reuse,readonly.
    # Each zero word before an 8-aligned string restart (0x804651B0, 0x804651C0) ends one TU string pool.
    "pso/unk/TLobby_80299A60.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # "TChallenge4P" and "Area00" sit in .rodata 0x80464E48-0x80464E60: -str reuse,readonly.
    "pso/unk/TLobby_80291D94.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # the class name and ":%04d:%02d'" sit in .rodata, ":%s" in .sdata2: -str reuse,readonly.
    "pso/ui/frontend/TAdPlyStatusGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # the five model, archive and class-name strings 0x80465938-0x804659A0 sit in .rodata: -str reuse,readonly.
    "pso/object/jungle/TOGrassJungle.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # draw_char_info_sprites reaches each .rodata position template with its own lis/addi: -pool off.
    "pso/ui/charcreate/TChCrTagInformation.cpp": {"cflags": _switch(cflags_pso, "-pool off")},
    # "TObjEneBm3Fly" sits in .rodata at 0x8043B0EC
    "pso/enemy/fly/TObjEneBm3Fly.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # "TAdPlyChrSelPlateGC" sits in .rodata at 0x80471A60
    "pso/ui/frontend/TAdPlyChrSelPlateGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # class-name string in .rodata; the ctor loads each .rodata table with its own lis/addi
    "pso/ui/frontend/TAdSelectGameModeGC_802C4748.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    # "TObjDFDemo0" sits in .rodata at 0x804372B0
    "pso/boss/darkfalz/TObjDFDemo0.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # "TEneParticleCtrl" sits in .rodata at 0x80477BE8
    "pso/effect/enemy/TEneParticleCtrl.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # "TWindowMenuTeamStatus" sits in .rodata at 0x80477C00
    "pso/unk/TLobby_80338E9C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # class-name strings sit in .rodata before the double literals (0x80443B68)
    "pso/object/city/CityTraffic.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # .data holds the ten season-object vtables in the ascending text order of their key
    # functions (dtors 0x801833C8..0x80184AD0); CW writes vtables in reverse key-function
    # order, so the functions were generated deferred from a last-to-first source.
    # -pool off: vfunc_13 reaches each of its debug strings by symbol (lis/addi per string).
    # -str readonly: those strings sit in .rodata between the int-to-float double and the
    # later double literal.
    # vtables come out Lobby, Med, Warp, Guild, Shop, then their base: written last to first, deferred.
    "pso/object/city/CityDoors.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/object/city/CitySeason.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-pool off", "-str reuse,readonly")},
    # TShopJudgmentItemWindow: its class name and four string literals sit in .rodata.
    "pso/ui/city/TShopJudgmentItemWindow.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TObjDFJisin: the Jisin, Horming and Yutai class-name strings sit in .rodata.
    # vtables come out TObjDFTenchuFuru then TObjDFUsoTower (text order of their dtors): written last to first, deferred.
    "pso/boss/darkfalz/TObjDFJisin.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TWindowSubTradeMain_80330A84 (+_80332148): "TWindowSubTradeMain" sits in .rodata;
    # .data holds the vtable (0x804EDF90) ahead of run_task's jump tables: deferred generation of the last-to-first source.
    "pso/ui/window/TWindowSubTradeMain_80330A84.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TCharaMaking (+TCharaMaking_8028E3F4): its motion names and file names sit in .rodata.
    "pso/ui/charcreate/TCharaMaking.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TWindowSubStatusDisp_802671F0 (+3 folded parts): "TWindowMenuIconLine" sits in .rodata and "/" in .sdata2.
    "pso/ui/window/TWindowSubStatusDisp_802671F0.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TWindowSubSymbolChat_80076F88 (+TWindowChat_800774C0): its only string "symbolchat.dat" sits in .rodata.
    "pso/ui/chat/TWindowSubSymbolChat_80076F88.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TQuestListOnline: vtable before vfunc_11's switch table and .sdata2 literals in .text order need deferred with the
    # source in reverse .text order (as its neighbour TQuestListVM); "" and the class name are read-only literals.
    "pso/quest/TQuestListOnline.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TEnding_8008C5C0: "ending.adx" sits in .rodata; start_ending_scene reaches each .rodata object with its own lis/addi.
    "pso/system/scene/TEnding_8008C5C0.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    # text_802A1020: the file-name strings its two .data tables point at sit in .rodata.
    "pso/unk/text_802A1020.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TAdEnterBaseGC (+5 folded parts): the source is written last function first (validate_input's templates precede
    # draw_masked's double in .rodata); "%08X" sits in .rodata; the 8-byte status-line position sits in .data;
    # draw_masked_password_field reaches each .rodata object with its own lis/addi.
    "pso/ui/frontend/TAdEnterBaseGC.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly", "-sdata 4", "-pool off")},
    # The class name, the QUEST/RICO label names and debug_draw_label's formats sit in .rodata (readonly strings);
    # debug_draw_label reaches each of them with its own lis/addi (no shared base): -pool off.
    "pso/object/TObjMesBase.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    # The model/bml file names and the class name sit in .rodata, where only readonly strings go.
    "pso/object/TMotorcycle.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # The six debug-hook names (csnVector() ...) sit in .rodata, where only readonly strings go.
    "pso/map/CsnQuery.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # The quest collision family (TObjQuestColBase..TObjQuestCol2, TQuestColCtrl): its class names run
    # ColBase..Col2 in .rodata/.sdata while its text and vtables run Col2..ColBase, so the source is written
    # ColBase first and built deferred; the names sit in .rodata, where only readonly strings go.
    "pso/object/quest/TObjQuestCol.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TAdTitleTexGC (+ former TLobby_802A5120): GC/1.3.2 for TLobby__sub_802A5154; its array templates precede
    # update_title_tex_positions' pooled double although that code comes first (written last to first,
    # deferred); strings in .rodata; the 8-byte texlists in .data.
    "pso/ui/frontend/TAdTitleTexGC.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly", "-sdata 4")},
    # TItemDrop: its strings sit in .rodata and .sdata2 (-str reuse,readonly), and TItemDrop::load_drop_tables
    # loads each string with its own lis/addi (-pool off).
    "pso/item/drop/TItemDrop_80105D0C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
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
    "pso/system/scene/OfflineGameScene.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/unk/TLobby_801A3C48.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # run_task reaches each of its four .rodata initialiser templates with its own lis/addi: -pool off.
    "pso/unk/TUnk_804C2298.cpp": {"cflags": _switch(cflags_pso, "-pool off")},
    # prepare_offline_quest_filenames reaches each language suffix string with its own lis/addi: -pool off.
    "pso/unk/text_801F3774.cpp": {"cflags": _switch(cflags_pso, "-pool off")},
    "pso/object/warp/TObjWarpBossMulti.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/chat/TWindowSubSymbolChatHelp.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/door/TODoorFourLightSpace.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/technique/TTecGiBarta.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/technique/TTecFoie.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # Its class-name strings "TTecSlicer"/"TSlicerHistory" sit in .rodata (8044DC68), not .data.
    "pso/technique/TTecSlicer.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -fp_contract on: TUnk_804CC800::run_task fuses its three orbit sums (radius * cos + centre) into
    # fmadds; the unit's other functions are the same either way.
    # TTecGiFoie.cpp keeps its class name string in .rodata (-str readonly) and reaches each .rodata
    # object with its own lis/addi: -pool off.
    "pso/technique/TTecGiFoie.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on", "-str reuse,readonly", "-pool off")},
    # -sdata 4: the 8-byte gogo_ball_team_scores this unit owns for LobbyGoGoBall sits in
    # .bss, not .sbss; its own 4-byte small data is unaffected.
    "pso/object/TObjSinBoard.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/object/ambient/TObjGrass.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/lobby/LobbyGoGoBall.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # -inline off,deferred: .rodata is in reverse .text order: run_task's (0x8029B640) Vec templates 0x804653E8/0x804653F4,
    # then render's (0x8029B428) id template 0x80465400, then load_resources' (0x8029B3C8) gvm string 0x80465418.
    # -sdata 4: the 8-byte bm_o_jungle_doormain_motion_names 0x804DBFFC sits in .data, not .sdata.
    "pso/object/door/TODoorJungleMain.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-sdata 4", "-str reuse,readonly")},
    "pso/object/door/TObjDoorJung.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/door/TObjDoorKey.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/TObjDoaEx01.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -sdata 4: the 8-byte TObjDoor__motion_table 0x8050DC78 sits in .bss, not .sbss, while the
    # unit's 4-byte objects stay in .sdata/.sbss.
    "pso/object/door/TObjDoor_8018E358.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-sdata 4", "-str reuse,readonly")},
    # TObjGoalWarpAncient's methods lead .text but its vtable follows TObjMapWarpAncient's in .data and the
    # literals run in .text order: deferred codegen of a last-to-first source, as TObjLaboMapWarp.
    "pso/object/warp/TObjMapWarpAncient.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-inline off,deferred")},
    # The warp debug printers reach each .rodata object with their own lis/addi (no shared base): -pool off.
    "pso/object/warp/TObjAreaWarpEndingJung.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    # TObjWarpJungMain.cpp reaches each .rodata object with its own lis/addi: -pool off.
    "pso/object/warp/TObjWarpJungMain.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/ui/window/TWindowComCard.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowComCardFollower.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # .data holds the vtable (0x804D0FF0) ahead of run_task's jump table: deferred generation of the last-to-first source.
    "pso/ui/window/TWindowSubComCard.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
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
    # -inline auto,deferred: .data holds the TBoss1Dragon vtable ahead of the jump tables and the
    # TUnk_80481B34 vtable after them, so the source runs last function to first.
    "pso/boss/dragon/TBoss1Dragon.cpp": {"cflags": _switch(cflags_pso, "-inline auto,deferred", "-str reuse,readonly")},
    "pso/technique/TTecBarta.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # consume_telepipe_arrival reaches each .rodata object with its own lis/addi (no shared base): -pool off.
    # -inline off,deferred: .data holds the TUnk_804CC9D4, TUnk_804CCA0C and TTecLuker vtables in the
    # order of their key functions in .text, the order deferred generation of the last-to-first source gives.
    "pso/technique/TTecLuker.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off", "-inline off,deferred")},
    # -sdata 4: the 8-byte recovery_technique_charge_particle_ids 0x804CC988 sits in .data, not .sdata.
    "pso/unk/TUnk_804CC990.cpp": {"cflags": _switch(cflags_pso, "-sdata 4")},
    # -str reuse,readonly: the class name 0x8044D8A4 sits in .rodata between the emitter bands and the offset vector.
    "pso/technique/TTecMegid.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -sdata 4: the 8-byte fake_tec_texlist is addressed with lis/addi, not r13.
    "pso/enemy/saver/SaverLifecycle.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/enemy/darkgunner/DarkGunner.cpp": {"cflags": _switch(cflags_pso, "-inline on,deferred", "-str reuse,readonly")},
    "pso/enemy/darkgunner/TObjEneDarkGunCenter.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/enemy/illgill/TObjEneIllGill.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdChrMoveEffectGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/boss/derolle/TObjBoss2CeilJunk.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/ui/frontend/TAdChrSelPlyPlateGC.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/ui/frontend/TAdChrSelSlotGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/container/TObjContainerIdo_8018BEE4.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/player/TPlyPhotonChair.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/player/TPlayerBattleCtrl4P.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # .data opens with the rank table, then TUnk_804C3E88's vtable ahead of handle_6x7D_set_battle_mode_data's jump
    # table: deferred generation of the last-to-first source; .rodata then runs local initialisers backwards and the code
    # strings and int-to-float constant in .text order. Each string is reached by its own lis/addi: -pool off.
    # -sdata 4: the 8-byte battle_mode_data_table sits in .bss, not .sbss.
    "pso/unk/TLobby_801C25B4.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-pool off", "-sdata 4", "-str reuse,readonly")},
    "pso/object/fence/TLazerFenceSw.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # Their class names ("TObjLight" 0x80445D38, "TMapCsnCtrl" 0x80445D68, "TObjMapCsn" 0x8043F268) open
    # their .rodata: readonly strings.
    "pso/object/ambient/TObjLight.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/map/TObjMapCsn.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/map/TMapCsnCtrl.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TObjChip: render's colour template sits after draw_chips' in .rodata
    # while render comes first in .text, so the source runs backwards.
    "pso/object/TObjChip.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # Deferred: the vtables come out in reverse key-function order.
    "pso/technique/TTecAnti.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TTecPlayerInfluence.cpp is written from its last function back: its .rodata has the class name, render's
    # {50, 50, 50} template, then the range-effect tables of the lower-addressed functions, then the codegen
    # literal (only deferred code generation orders parse-time objects ahead of the earlier functions' code).
    "pso/technique/TTecPlayerInfluence.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # -fp_contract on: calc_technique_parameters fuses tp_cost += level * (percent / 100.0f) into fmadds;
    # the unit's other functions compile the same either way. -inline on: its 17 per-level pad_12
    # updates read the global after the inner clamp only through the inlined lowered_pad_12 (auto
    # would also inline calc_technique_boost into it). deferred: the original .data holds
    # __vt__8TTecCtrl before the four switch jump tables (0x804CC5F4 < 0x804CC60C), which only
    # deferred code generation emits. -str reuse,readonly: its model/motion names, archive name and
    # class name sit in .rodata. -pool off: create_technique_charge_light loads each case's colour and
    # direction templates by their own lis/addi; pooled data would share one .rodata base instead.
    # -sdata 4: the 8-byte technique_ringwave_texture_list is addressed with lis/addi, not r13.
    "pso/technique/TTecCtrl.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on", "-inline on,deferred", "-str reuse,readonly", "-pool off", "-sdata 4")},
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
    # with its own lis/addi, not off one shared base. TObjVoloptPillar::sub_80049FD8 is one such
    # spawner, and the rest of the pillar's TU builds identically with 2.0. -pool off: run_task reaches
    # the TU's own .rodata (the attack and push templates, the two doubles) each with its own lis/addi.
    "pso/boss/volopt/TObjVoloptPillar.cpp": {"mw_version": "GC/2.0", "cflags": _switch(cflags_pso, "-pool off")},
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
    # -inline off,deferred: the Vec initialiser objects 0x804359C0..E4 lie in reverse order of their
    # functions while the codegen literals after them lie in forward order: data in parse order, code deferred.
    "pso/boss/derolle/TBoss2DeRolLe.cpp": {"mw_version": "GC/2.0", "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/effect/TEffIndirectCtrl.cpp": {"mw_version": "GC/2.0", "cflags": [*_switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly"), "-DPSO_SDK_COMPACT_MATH"]},
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
    # TAdDialingGC (0x80328210-0x80328F7C, one TU split in three): the quad drawer 0x80328B24 takes
    # `const f32 *` (its callers pass .rodata arrays); 2.x CSEs every const read across the polygon
    # stores, 1.3.2 hoists only the first point's loads and reloads the rest, as the original does.
    # Every other function of the three units compiles the same under both.
    # Deferred, written last to first: the .rodata runs class name (0x80476798), the quad tables
    # (0x804767A8-C0) then the status format (0x804767C8), the reverse of their functions' order,
    # and __vt__12TAdDialingGC (0x804ED5C8) sits ahead of update_state_display's jump table.
    "pso/ui/frontend/TAdDialingGC.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/ui/frontend/TAdDialingGC_80328E50.cpp": {"mw_version": "GC/1.3.2"},
    "pso/ui/frontend/TAdDialingGC_80328E90.cpp": {"mw_version": "GC/1.3.2"},
    # TDLGraph (0x8007ECF0-0x8007F85C): the progress bar 0x8007F27C reads its `const NJS_POINT2 &`
    # arguments after the prologue's register saves and between the colour stores, as 1.3.2 schedules
    # them; 2.x hoists those loads above the saves. Every other function compiles the same under both.
    # Deferred: the bar's vertex-list template sits in .rodata ahead of the pooled doubles and strings,
    # which only the last-to-first emission order gives. Readonly: its format strings are in .rodata.
    "pso/render/TDLGraph.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/object/TObjComputer.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # The next two container units (and TOContainerAncientEnemy) emit their
    # functions and vtables last-to-first: -inline off,deferred, with the
    # source written in reverse; it puts all 16 container vtables in place.
    "pso/object/container/TObjContainerJung.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-inline off,deferred")},
    # The two below also schedule the by-value DirectAttackPayload read of
    # their receive_direct_attack overrides only the way 1.3.2 does.
    "pso/object/container/TObjContainerItem.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # -str readonly: every string of the unit (archive file names, class names) sits in .rodata.
    # -sdata 4: its 8-byte effect tables sit in .bss and its small data is all 4-byte words.
    # One deferred file for both container classes: the R vtable comes first and both constructors
    # read their vtables from the pooled .data base.
    "pso/object/container/TContainerAncient01.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly", "-sdata 4")},
    # -sdata 4: its 8-byte objects (chr_select_serial_seeds, lbl_80513918, the save message text position) sit in
    # .bss/.data, not .sbss/.sdata, and its small data is all 4-byte words or smaller.
    "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-sdata 4")},
    "pso/quest/TQuestVmDownLoadServer.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-inline deferred")},
    "pso/camera/TCameraCtrl.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/ui/window/TWindowKeyBoardHard.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdMultiOkGC.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # TLobby_80228154: its sprite draw keeps the frame size and flag tests only under 1.3.2.
    # -str reuse,readonly: the area names of area_initializer_dispatch_table sit in .rodata right after the
    # unit's double (0x8044C9F0), in table order.
    "pso/unk/TLobby_80228154.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TBoss7DeRolLeC: deferred codegen (its vtable sits before the jump tables in .data).
    "pso/boss/barbaray/TBoss7DeRolLeC.cpp": {"cflags": _switch(cflags_pso, "-inline on,deferred")},
    # TBoss7Crawfish: one GC/1.3.2 TU (the five former parts compile identically under 1.3.2, not under 2.6);
    # its resource names are .rodata strings.
    "pso/boss/barbaray/TBoss7Crawfish.cpp": {"mw_version": "GC/1.3.2", "cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # GC/1.3: the compiler-generated TMenuList<> copy constructor.
    "pso/network/TRegister.cpp": {"mw_version": "GC/1.3"},
    "pso/player/TPlyGuildCardTag_801E0284.cpp": {"mw_version": "GC/1.3"},
    # fill_date_from_seconds stores the month between the days[m - 1] load and the subtraction only
    # under 1.3-2.0 (2.6 schedules the store after it).
    "pso/system/data/pso_date.cpp": {"mw_version": "GC/1.3"},
    "pso/network/TPlyStartGame.cpp": {"mw_version": "GC/1.3"},
    # TShopItemListWindow: handle_amount_confirm compiles identical only under 1.3-2.0 (2.5/2.6
    # schedule it differently); every other function of the unit compiles the same.
    # Deferred inlining: __vt__19TShopItemListWindow sits before vfunc_11's switch table in .data
    # although the dtor (its only early user) follows vfunc_11, so the source runs backwards.
    "pso/ui/city/TShopItemListWindow.cpp": {"mw_version": "GC/1.3", "cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/ui/window/TWindowShortListCtrl_8026E7DC.cpp": {"mw_version": "GC/1.3", "cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # Deferred inlining: functions come out in reverse source order and the
    # vtables before the switch tables in .data.
    "pso/ui/city/TMedicalCenterSequence.cpp": {"cflags": _switch(cflags_pso, "-inline deferred", "-str reuse,readonly")},
    # .data holds the vtable (0x804CA138) ahead of vfunc_11's switch table although the dtor
    # follows vfunc_11: deferred generation of the last-to-first source.
    "pso/ui/city/TShopItemTecSequence.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # .data holds the vtable (0x804C9E38) ahead of vfunc_11's switch table although the dtor
    # follows vfunc_11: deferred generation of the last-to-first source.
    "pso/ui/city/TShopEquipmentGearSequence.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # .data holds the vtable (0x804C9F48) ahead of vfunc_11's switch table: deferred
    # generation of the last-to-first source, as for the gear shop.
    "pso/ui/city/TShopEquipmentSequence.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # .data holds the vtable (0x804C9DD8) ahead of vfunc_11's switch table although the dtor
    # follows vfunc_11: deferred generation of the last-to-first source.
    "pso/ui/city/TShopArmorListWindow.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # .data holds the vtable (0x804C96D8) ahead of vfunc_11's switch table although the dtor
    # follows vfunc_11: deferred generation of the last-to-first source.
    "pso/ui/city/THunterGuildSeqOffline.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # .data holds the client vtable (0x804C9740) ahead of both vfunc_11 switch tables although the
    # client dtor follows its vfunc_11: deferred generation of the last-to-first source.
    "pso/ui/city/THunterGuildSeqOffline_80213788.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/boss/barbaray/TBoss7LaserLight.cpp": {"cflags": _switch(cflags_pso, "-inline deferred")},
    # Its two string literals, the class names, sit in the unit's .rodata after the level table.
    "pso/boss/barbaray/TBoss7PhotonBullet_802EF26C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/derolle/TBoss2PhotonBullet_80038DCC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/derolle/TBoss2Fin.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/derolle/TBoss2Joint.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/dragon/TObjBoss1Crater.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/dragon/ObjBoss1CommonResource.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/olgaflow/Boss6Type2Data.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # Boss7TentacleData.cpp keeps its two class-name strings in .rodata after the angle tables.
    "pso/boss/barbaray/Boss7TentacleData.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TObjBoss7Dust.cpp holds TObjBoss7Dust and TObjBoss7DustCtrl: Dust's code comes first in .text,
    # yet DustCtrl's class name precedes Dust's in .sdata/.rodata and Dust's vtable precedes
    # DustCtrl's: deferred, written from the unit's last function back.
    "pso/boss/barbaray/TObjBoss7Dust.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/boss/goldragon/TBoss8DragonEffTail.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/dragon/ObjBoss1CommonJResource.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/barbaray/TBoss7Joint.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TBoss4Thanks.cpp holds the class's door tests and any_player_has_listed_item: the table that
    # function reads (boss4_thanks_listed_item_table) sits in this TU's .rodata ahead of the emitter table.
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
    # The jungle rocks: vtables come out L01, M01 then S01 (code order): written last to first, deferred.
    "pso/object/jungle/TORockJungleL01.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
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
    # TItemShoot.cpp's five vtables come out RotZ, Gun, Particle, Model, Shoot
    # (their .text order) and its class-name strings sit in .rodata: deferred,
    # written from its last function back.
    "pso/weapon/shoot/TItemShoot.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
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
    # TItemEffShield.cpp is written from its last function back: its three vtables (TUnk_8049F130,
    # TUnk_8049F148, TItemEffShield) come out in .text order, the class name heads its .rodata.
    "pso/effect/item/TItemEffShield.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
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
    # GC/1.3: the const vfunc_79 overrides load through const this in source
    # order; 1.3.2 and 2.x hoist those loads above the stores (whole unit exact on 1.3).
    "pso/object/container/TOContainerAncientEnemy.cpp": {"mw_version": "GC/1.3", "cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off", "-inline off,deferred")},
    "pso/object/ruins/TOMonumentAncient01.cpp": {"cflags": _switch(cflags_pso, "-sdata 4", "-str reuse,readonly")},
    "pso/boss/darkfalz/TOBoss4.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on", "-str reuse,readonly", "-sdata 4", "-inline deferred")},
    "pso/boss/olgaflow/TBoss6Rock.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on", "-str reuse,readonly", "-inline off,deferred", "-str reuse,readonly")},
    "pso/boss/olgaflow/TBoss6Type2_80336E6C.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # .data holds the vtable (0x804DFADC) ahead of the switch table of sub_802BBC74: deferred generation of the
    # last-to-first source. Inlining stays on: copy_block's struct assignment and the two motion-track constant
    # references are inlined, and the constants come out at their first user inside the literal pool.
    "pso/boss/olgaflow/TBoss6Type2.cpp": {"cflags": _switch(cflags_pso, "-inline deferred", "-fp_contract on")},
    # send_subordinate_actions loads its two flag bytes from .sdata2 ahead of its float literals: constant references
    # inlined at the use (the TBoss6Type2.cpp form), so this unit is built with inlining on.
    "pso/boss/olgaflow/TBoss6Type2_80356E50.cpp": {"cflags": _switch(cflags_pso, "-inline on")},
    "pso/boss/olgaflow/TBoss6Type2_802BE588.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-inline off,deferred", "-str reuse,readonly")},
    "pso/boss/olgaflow/TBoss6CrushRock.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on", "-inline off,deferred", "-str reuse,readonly")},
    # break_rocks_in_wave loads the bitmap length from .sdata2 ahead of run_task's float literals: a constant reference
    # inlined at the use (the TBoss6Type2.cpp form), so this unit is built with inlining on.
    "pso/boss/olgaflow/TBoss6SwordShot.cpp": {"cflags": _switch(cflags_pso, "-fp_contract on", "-inline on")},
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
    # .rodata object with its own lis/addi: -pool off. It also holds any_player_has_listed_equipment:
    # the table it reads (listed_equipment_table) sits in this TU's .rodata.
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
    # Its vtable sits after TFogCtrl_EOR's: deferred generation of the last-to-first source. Inlining stays
    # on so copy_fog_entry's block copies fold in instead of becoming out-of-line ByteBlock assignments.
    "pso/render/TFogCtrl.cpp": {"cflags": _switch(cflags_pso, "-inline on,deferred", "-str reuse,readonly")},
    # The render helpers (0x801412D0-0x80142770): GC/1.3.2, one .sdata2 pool. Only
    # 1.3.2 keeps approach_vector_fixed_distance's early-out copy unscheduled.
    "pso/render/render_util.cpp": {"mw_version": "GC/1.3.2", "cflags": [*_switch(cflags_pso, "-fp_contract on"), "-DPSO_SDK_COMPACT_MATH"]},
    "pso/render/render_util_head.cpp": {"mw_version": "GC/1.3.2", "cflags": [*_switch(cflags_pso, "-fp_contract on"), "-DPSO_SDK_COMPACT_MATH"]},
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
    # TObjFogCollision.cpp: create/ct/dtor of each class come last in .text and the vtables run in reverse key-function
    # order (deferred); every string is in .rodata; draw_volume reaches each colour template with its own lis/addi.
    "pso/object/collision/TObjFogCollision.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly", "-pool off")},
    # TLobby_801F3A24.cpp reaches each .rodata object with its own lis/addi: -pool off.
    "pso/unk/TLobby_801F3A24.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    # TWindowChatSymbol.cpp reaches each .rodata object with its own lis/addi: -pool off.
    "pso/ui/chat/TWindowChatSymbol.cpp": {"cflags": _switch(cflags_pso, "-pool off")},
    # TUnk_804CE7D0.cpp's ctor reaches each .rodata point with its own lis/addi: -pool off.
    "pso/ui/chat/TUnk_804CE7D0.cpp": {"cflags": _switch(cflags_pso, "-pool off")},
    "pso/player/PhotonBlastResults.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -sdata 4: the 8-byte model name table sits in .data and the 8-byte 0x805007D4 in .bss, next to the 4-byte .sdata name pointer.
    "pso/enemy/berura/TObjEneRe7Berura.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/ui/window/TWindowKeyBoardSoft.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/goldragon/TObjBoss8Piller.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # vtables come out TBoss5GryphonColli then TBoss5GryphonColli_C (text order of their dtors): written last to first, deferred.
    "pso/boss/galgryphon/TBoss5GryphonColli.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    # .data holds __vt__19TObjBoss8PillerCtrl ahead of run_task's jump table: deferred generation of the last-to-first source.
    "pso/boss/goldragon/TObjBoss8PillerCtrl.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/enemy/epsilon/TObjEneEpsilon.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -sdata 4: the 8-byte name tables sit in .data while 4-byte objects sit in .sdata.
    "pso/unk/text_8035B750.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    # -fp_contract on: fn_80293D84 fuses each hexagon vertex's scale and offset into fmadds; no other
    # function of the unit has an unfused multiply-add. Readonly strings: its class name
    # ("TChCrEffFade", 0x80464EC8) opens its .rodata ahead of its tables, as in TChCrCharSelect.
    "pso/ui/charcreate/TChCrEffFade.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-fp_contract on")},
    # Same as its nights sibling: the chao file names sit in .rodata (0x80479808) and the 8-byte
    # model-name table in .data (0x804F1D00) while the 4-byte resource handle sits in .sbss.
    "pso/unk/text_8035B6B0.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    # Readonly strings: the class name ("TAdPlyPltAnimCtrlGC", 0x804792C4) sits in .rodata after
    # its threshold table while the unit's .data holds only run_task's switch jump table.
    "pso/ui/frontend/TAdPlyPltAnimCtrlGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/ambient/TObjCGrass.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-sdata 4")},
    "pso/object/TObjLiveMonitor.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -str readonly: the class-name string their .sdata name pointer targets sits in .rodata
    "pso/boss/olgaflow/TBoss6EffHyoui.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/keyboard/KeyboardControlTask.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/keyboard/KeyboardKeyState.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/trap/TOTrap.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/wreck/TOWreckAncient02.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/sprite/TQuadSpriteNormal.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/sprite/TQuadSpriteScl.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/sprite/TQuadSpriteSclCol.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/sprite/TQuadSpriteSclColRot.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowGetComCard.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowMainMenu1P.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # its class name ("TWindowOptionCtrl", 0x8044F478) and its strings sit in .rodata: readonly strings.
    "pso/ui/window/TWindowOptionCtrl.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # One TU 0x8034CC00-0x8034D3D0 written last to first, deferred: its .rodata runs the class name, then
    # open_card_info_window's, show_card_a7's and set_message_index's tables (reverse text order), and .data
    # holds the vtable ahead of run_task's jump table.
    "pso/ui/window/TWindowSubInformationBoard.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # -str readonly: "TWindowBase" (TWindowBase__name, tmp buffer key) sits in .rodata (0x8044E658).
    "pso/ui/window/TWindowBase.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowSubTechnique.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # TWindowCtrl: its pointer-to-member constants sit in .data in reverse .text order of their users, so the
    # source is written last to first under deferred codegen; the class name "TWindowCtrl" sits in .rodata.
    "pso/ui/window/TWindowCtrl.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # -str readonly: the class name "TWindowStatus" of TWindowStatus__name sits in .rodata (0x8044F640).
    "pso/ui/window/TWindowStatus.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowTradeRequest_802E0170.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/network/TGameProtocol.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdMcCheckGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/effect/TEF_PvrWave.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/darkfalz/TObjDFDemoF.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/dragon/TObjBoss1Floor.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/object/TObjParticle.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # .data holds the vtable ahead of vfunc_11's jump table and .rodata init_quest_list_window's window size
    # ahead of update_list_navigation's: deferred generation of the last-to-first source.
    "pso/quest/TQuestListOffline.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    "pso/ui/window/TWindowMessage.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowRoom.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdGameStartShadowGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/galgryphon/TBoss5GryphonLightning.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # The TAdSnAkPassConfirmGC constructor reaches each of its three .rodata window rects with its own lis/addi: -pool off.
    "pso/ui/frontend/TAdSnAkPassConfirmGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-pool off")},
    "pso/ui/frontend/TAdGameStartLineGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdChrSelMovePlateGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/frontend/TAdFloorLoadCamGC.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/boss/galgryphon/TBoss5GryphonLightningEff.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    # -inline off,deferred: __vt__12T_OWEHMS_Exp precedes __vt__24TObjWaitEntryHairMoveSim, which
    # only fits key functions defined in reverse, so the source runs from the last function back.
    "pso/object/TObjWaitEntryHairMoveSim.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred", "-str reuse,readonly")},
    # -inline off,deferred: __vt__8TEndingC precedes run_task's jump table, so the source runs
    # from the last function back.
    "pso/system/scene/TEndingCWall.cpp": {"cflags": _switch(cflags_pso, "-inline off,deferred")},
    "pso/object/collision/TOSymbolchatColli.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/charcreate/TChCrTagInformationStr.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/quest/challenge/TChallenge4PItemSelect.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly")},
    "pso/ui/window/TWindowMainMenu.cpp": {"cflags": _switch(cflags_pso, "-str reuse,readonly", "-inline off,deferred")},
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
        "pso/system/movie/Gcci.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
        "pso/audio/CriSvm.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
        # -str reuse,readonly: its chunk tags "fmt ", "data", "RIFF", "WAVE" sit in .sdata2 0x805E0CA0-0x805E0CC0.
        "pso/unk/TLobby_803BFE50.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
        # -str reuse,readonly: the TU's 17 string literals sit in .rodata 0x8047DF90-0x8047E220.
        "pso/system/movie/Mfci.cpp": {"cflags": _switch(cflags_cri, "-str reuse,readonly")},
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
        # -inline off,deferred: its named .sdata2 constants (0x805E0E18-0x805E0E3C), defined after the one function,
        # sit before the function's int->double conversion constants (0x805E0E40); only deferred compilation emits that order.
        "pso/render/GinjaPerspective.cpp": {"cflags": _switch(cflags_middleware, "-O3,p", "-opt nopeephole", "-inline off,deferred")},
        # -sdata 4: its last .bss object (0x8058D520) is 8 bytes.
        "pso/unk/text_803DCDFC.cpp": {"cflags": _switch(cflags_middleware, "-O3,p", "-opt nopeephole", "-sdata 4")},
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
        # -str reuse,readonly: the version banner and sprintf format strings sit in .rodata.
        "pso/system/save/McFsGc.cpp": {"cflags": _switch(cflags_middleware, "-opt nostrength", "-str reuse,readonly")},
        # -pool off: find_longest_match_entry (0x803E9DE0) and sub_803E9A74 load the string, entry and index
        # tables of the TU's own .rodata each with its own lis/addi.
        "pso/quest/TQuestVmDownLoadServer_803E9A24.cpp": {"cflags": _switch(cflags_middleware, "-pool off")},
        # -str reuse,readonly: its string literal " " sits in .sdata2 0x805E10D0 (padded to the next TU at 0x805E10D8).
        "pso/quest/TQuestVmDownLoadServer_803EB0D8.cpp": {"cflags": _switch(cflags_middleware, "-str reuse,readonly")},
        # -str reuse,readonly: its literals "Dummy" and "" sit in .sdata2 0x805E10D8 (sub_803F09A4).
        "pso/quest/QuestDownloadAramFile.cpp": {"cflags": _switch(cflags_middleware, "-str reuse,readonly")},
    }),
    # ntInf ("Ver 1.17.00 Build:Jul 9 2002"). GC/1.3: its buffer pointers sit on 32-byte boundaries
    # (.sbss 0x805D79C0, 0x805D79E0) and the two entry points taking the caller's buffer 32-align their
    # frames; 1.3 honours aligned(32) on pointers, 1.3.2-2.7 drop it, and the rest of the code is the same.
    ("ntinf", 0x803F3BF8, "GC/1.3", cflags_middleware, {
        "pso/unk/text_803F4D84.cpp": {"cflags": _switch(cflags_middleware, "-O2", "-use_lmw_stmw off")},
    }),
    # ACCESS AVE-TCP ("avetcp.a Ver.1.16.1 Oct 23 2002"); its PPP files were
    # built without common subexpression elimination.
    ("avetcp", 0x803F7678, "GC/1.2.5n", cflags_middleware, {
        # -str reuse,readonly: the test account's literals sit in .sdata2 ("test", 805E1100) and .rodata ("hogehoge", 8047FD28).
        "pso/network/NetAuthSecrets.c": {"cflags": _switch(cflags_middleware, "-str reuse,readonly")},
        "pso/network/TLobby_803F86BC.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetworkRuntime.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        # -str reuse,readonly: its one string literal, the IPv6CP protocol name "IPv6cp", sits in .sdata2 (805E1150).
        "pso/network/NetworkThreadRuntime.c": {"cflags": _switch(cflags_middleware, "-opt nocse", "-str reuse,readonly")},
        "pso/network/TLobby_803FAEA0.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        # -str reuse,readonly: CHAP's messages "Request timeout", "Request retry exceeded" and "Wellcome!!" sit in .rodata (8047FDE0).
        "pso/network/TLobby_803FC178.c": {"cflags": _switch(cflags_middleware, "-opt nocse", "-str reuse,readonly")},
        "pso/network/TLobby_803FCF44.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetPppLink.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/PppFsm.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/PppIpcp.c": {"cflags": _switch(cflags_middleware, "-opt nocse", "-str reuse,readonly")},
        "pso/network/PppLcp.c": {"cflags": _switch(cflags_middleware, "-opt nocse", "-str reuse,readonly")},
        "pso/network/PppBuffer.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        # PppMd5.c was built with CSE: MD5Transform matches only with it and MD5Update as RFC 1321 writes it.
        "pso/network/NetByteOrder.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/PppPap.c": {"cflags": _switch(cflags_middleware, "-opt nocse", "-str reuse,readonly")},
        "pso/network/PppControl.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/PppVj.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        # TLobby_804048E8.c was built with CSE: its VJ compressor matches only with it, init_net_list as BSD writes it.
        "pso/network/TLobby_804050DC.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        # NetArp.c was built with CSE: every function matches with it, arp_handle_packet only with it.
        "pso/network/NetEthernet.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetHandlerTable.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetDns.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetIcmp.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetIcmp6.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetAddrFamily.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetIpv4.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetIpv4Route.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetIpv6.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        # TLobby_8041112C.c was built with CSE: every function matches with it, NetIPv6GetAddressScopeClass only in
        # its inline-helper form, and seven functions needed opt_common_subs pragma scopes under -opt nocse.
        # NetLoopback.c was built with CSE: every function matches with it, send_loopback_frame only with it.
        # NetBufferPool.c was built with CSE: its free (0x8041579C) and alloc (0x80415954) only match with it.
        "pso/network/NetIPv6NeighborDiscovery.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        "pso/network/NetFragment.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
        # NetDispatcher.c was built with CSE: three functions match only with it, the protocol loop as typed C.
        "pso/network/NetTcp.c": {"cflags": _switch(cflags_middleware, "-opt nocse")},
    }),
    # The modem driver (AT command strings).
    ("modem", 0x8042BF48, "GC/1.2.5", cflags_middleware, {}),
    # ntUtl ("Ver 1.16.00 Build:Jul 8 2002"); the SDK's EXI library follows.
    # -str reuse,readonly: its version and message strings sit in .rodata 0x80480240-0x804805C8.
    ("ntutl", 0x8042E8C4, "GC/2.6", _switch(cflags_middleware, "-str reuse,readonly"), {}),
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
                # errno.c: data-only (user decision): only errno, .sbss 0x805D7330.
                Unit("PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Src/errno.c"),
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
