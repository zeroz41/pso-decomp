# Architecture

## The disc

The USA v1.02 disc (`GPOE8P`) carries several executables. This project decompiles `files/PsoV3.dol`, the game
itself.

| File | Contents |
|---|---|
| `files/PsoV3.dol` | the game: Sega's code, the Dolphin SDK, MSL and the PowerPC runtime, MetroTRK, MusyX |
| `files/movie.rel` | a code module the game loads at run time, not decompiled yet |
| `sys/main.dol` | the boot loader that starts `PsoV3.dol`, not decompiled; `python configure.py --target main` rebuilds it from [`config/GPOE8P/config.yml`](../config/GPOE8P/config.yml), [`splits.txt`](../config/GPOE8P/splits.txt) and [`symbols.txt`](../config/GPOE8P/symbols.txt) |
| switcher and network browser `.dol`s | programs that start the network setup and switch between executables, not decompiled |

The rest of `files/` is data, including 648 relocatable data containers (`.rel` files holding item, shop, map,
motion, quest and text tables) and five pairs of language files. The build checks each of them against its
pinned hash in `config/GPOE8P/data.json`.

`PsoV3.dol`'s entry point is `0x8000C040`. Its sections:

| Section | Range |
|---|---|
| `.init` | `0x8000C000`–`0x8000E520` |
| `extab` | `0x8000E520`–`0x8000EC60` |
| `extabindex` | `0x8000EC60`–`0x8000F740` |
| `.text` | `0x8000F740`–`0x80433F20` |
| `.ctors` | `0x80433F20`–`0x80434020` |
| `.dtors` | `0x80434020`–`0x80434040` |
| `.rodata` | `0x80434040`–`0x804805E0` |
| `.data` | `0x804805E0`–`0x804FE020` |
| `.bss` | `0x804FE020`–`0x805D2600` |
| `.sdata` | `0x805D2600`–`0x805D49A0` |
| `.sbss` | `0x805D49A0`–`0x805D7D00` |
| `.sdata2` | `0x805D7D00`–`0x805E1200` |
| `.sbss2` | `0x805E1200`–`0x805E1224` |

The executable ships without symbols. The names in
[`config/GPOE8P/psov3/symbols.txt`](../config/GPOE8P/psov3/symbols.txt) were recovered from strings, class-name
tables and vtables, from other builds of the SDK and runtime, or from what the code does. Functions without that
evidence keep a placeholder such as `fn_8001A2B4`.

## Units

The game was linked from object files, and each one is a unit here: a contiguous range of `.text` together with
the data it owns, defined in [`config/GPOE8P/psov3/splits.txt`](../config/GPOE8P/psov3/splits.txt) and compiled
from one source file of the same name. Functions inside a unit stay in address order, because the linker keeps
the order of the object file.

A unit is linked when every function and data section in it matches; the build then takes its bytes from the
compiled object instead of the original. [`linked_units.txt`](../config/GPOE8P/psov3/linked_units.txt) lists
those units. [`configure.py`](../configure.py) declares the compilers: the game code is built with one
(`GAME_COMPILER`, CodeWarrior GC/2.6), each prebuilt library with its own (the SDK, runtime, MetroTRK, MusyX and the
middleware in `MIDDLEWARE`), and the few files built differently are listed with their evidence (`GAME_EXCEPTIONS`).

Unit boundaries come from evidence in the executable: compiler and flag changes, literal pools, static initializers,
alignment. Many are still provisional and move as units are folded together or split apart.

## Source layout

- `src/pso/<category>/` holds the game's units, sorted by the class that owns their code. The original directory
  structure is unknown; this is the project's own organization:

  | Folder | Contents |
  |---|---|
  | `player/`, `npc/` | the player character and its data; town and quest NPCs |
  | `enemy/<monster>/` | one folder per monster family; `enemy/` itself holds the shared enemy code and factories |
  | `boss/<boss>/` | one folder per boss fight (`dragon`, `derolle`, `volopt`, `darkfalz`, `barbaray`, `goldragon`, `galgryphon`, `olgaflow`) |
  | `weapon/`, `weapon/shoot/` | weapons, and the ranged weapons with their projectiles |
  | `item/` | items and their tables; `mag/`, `armor/`, `drop/`, `shop/` |
  | `technique/` | techniques |
  | `object/` | map objects: `base/` (the object hierarchy), function families (`door/`, `key/`, `switch/`, `trap/`, `container/`, `warp/`, `fence/`, `wreck/`, `collision/`, `quest/`, `lobby/`, `city/`), area decor (`cave/`, `mine/`, `ruins/`, `jungle/`, `seabed/`, `lab/`), `ambient/` and `ending/` |
  | `effect/` | visual effects; `photon/`, `particle/`, `item/`, `enemy/`, `sprite/` |
  | `camera/`, `map/`, `render/`, `audio/`, `math/` | cameras, map and set data, rendering helpers, sound, math |
  | `quest/`, `quest/challenge/` | the quest script engine and quest lists; challenge mode |
  | `network/`, `network/protocol/` | sockets, encryption and sessions; packet layouts and validation |
  | `ui/` | `window/` (in-game windows), `chat/`, `hud/`, `frontend/` (title and adventure screens), `charcreate/`, `city/` (shops and counters), `keyboard/`, `font/` |
  | `system/` | `task/` (the task tree), `scene/`, `save/`, `movie/`, `data/` |
  | `unk/` | ranges whose owner is not known yet |

- `include/pso/<category>/<Class>.h` declares a class: its fields, its virtual functions in slot order and its
  methods. A class's header sits in the same folder as its units.
- A unit is named after the class whose code it holds. `<Class>.cpp` is a class whose code forms one range;
  `<Class>_<address>.cpp` is one range of a class spread across several units; `unk/text_<address>.cpp` is a
  range whose owner is not known yet. A weak inline copy of a base class's method lives in the unit of the class
  that first calls it, so a unit can hold some code of another class.
- `src/musyx/` is the MusyX sound library, one unit per original source file.
- `libs/` holds the Dolphin SDK, MSL and the PowerPC runtime, and MetroTRK, adapted from other GameCube
  decompilations to the versions this game links. [third_party/](../third_party/) lists their origins.

## Build

[`configure.py`](../configure.py) generates the Ninja build with [`tools/project.py`](../tools/project.py), from
[dtk-template](https://github.com/encounter/dtk-template). decomp-toolkit splits the original executable into
per-unit objects using `config/GPOE8P/psov3/config.yml`, the units are compiled, and the linker rebuilds
`PsoV3.dol` from compiled objects for linked units and original objects for the rest. objdiff compares every unit
with its original object and writes `build/GPOE8P/report.json`.

About a hundred SDK, runtime, MetroTRK and MusyX functions were written in assembly by Nintendo and Metrowerks. The
source keeps their signatures; before compiling, [`tools/orig_asm.py`](../tools/orig_asm.py) writes each body from
decomp-toolkit's disassembly of your disc into `build/GPOE8P/include/orig_asm/`, so the repository holds none of it.
