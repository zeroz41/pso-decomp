# Contributing

This is a matching decompilation: a function counts when its compiled code is byte-identical to the original,
lives in the unit that owns its address, is a real member of its class and is named on evidence. objdiff's report
(`build/GPOE8P/report.json`) is the only measure of progress. Use whatever tools you like; send a clean pull
request.

## Setup

Follow [Building](README.md#building) in the README. Never commit the original or anything extracted or built from
it: `orig/` and `build/` are ignored.

## What a change can do

- **Match functions.** C or C++ for functions that were not matched before, which objdiff reports as exact.
- **Define data.** A unit's tables, strings and other data objects in source, so its data sections match.
- **Link a unit.** Once every function and data section in a unit matches, `tools/link_units.py scan --write` adds
  it to `config/GPOE8P/psov3/linked_units.txt` so the build takes it from source.
- **Fold or split units.** Move functions and data into the unit that owns them, merging ranges that belong to one
  original object file or splitting ones that don't, and update `config/GPOE8P/psov3/splits.txt` to match.
- **Name things.** Real names for functions, classes, members and data, in the same change as the evidence for them.

[docs/architecture.md](docs/architecture.md) explains units, linking and the source layout.

## Recovering a function

1. Find the unit that owns its address in `config/GPOE8P/psov3/splits.txt`; its source file has the same path
   under `src/`.
2. Write the function as a member of its class, using the class's header in `include/` and the declarations of what
   it calls. If the class has no header yet, add one: fields, the virtual functions in slot order, the methods.
3. Open the repository in objdiff, select the unit and compare. objdiff rebuilds the unit when you save.
4. Keep the bodies in a unit in address order.

## Checking a change

Build the commit your change starts from and save its report:

    python configure.py
    ninja
    ninja baseline

Then make your change and run:

    python tools/check_pr.py

It must end in `PASS`. It runs these checks, which you can also run one at a time:

- `ninja` rebuilds `PsoV3.dol` and checks it against the original's SHA-1.
- `python tools/report_delta.py build/GPOE8P/baseline.json build/GPOE8P/report.json --check` compares the reports by
  original address, so renames and folds can't hide a loss: no exact function, linked unit or data range may go
  missing. Alignment padding that drops out of every unit when you split one off is shown but allowed, since its
  bytes are zero and nothing lives there. `ninja changes` lists the per-function differences.
- `python tools/link_units.py check` checks that every unit in `linked_units.txt` still links from source. objdiff
  can score a unit 100% while its object won't link. One example is a constant or string turned into a literal
  that `symbols.txt` still exports as a global.

When `link_units.py` reports a problem, run `python tools/link_units.py scan`. It writes every reason for each unit
to `config/GPOE8P/psov3/linked_units_blocked.json`:

- `missing <symbol>`: the original exports a symbol your source no longer defines. Run
  `python tools/localize_split_globals.py --write <unit>`, then rebuild. It marks the symbol `scope:local` in
  `symbols.txt` after checking that no other object refers to it. If something else does refer to it, define it
  in source under that name instead.
- `section <name>`: the compiled object has data the unit's split doesn't own yet. Claim that range in
  `splits.txt`.
- `size`, `alignment`, `order` or `data-layout`: the object's layout still differs from the original's.
- `data <section>:<percent>`: that section's data doesn't match yet.

`localize_split_globals.py` only marks symbols in units whose reasons are all `missing`, since any other reason
would keep the unit from linking anyway.

When your change makes a whole unit match, run `python tools/link_units.py scan --write` to link it, then
`python configure.py` and `ninja` again, and commit the updated `linked_units.txt` and `config.yml`.

## Source quality

A byte match proves the code compiles to the original. It says nothing about whether the source reads as the
program's own C++. `tools/source_quality.py` counts what is still decompiler output in `src/` and `include/` and
compares your change with the commit it branched from on `master`:

    python tools/source_quality.py                         # working tree against master
    python tools/source_quality.py --base master --head my-branch
    python tools/source_quality.py --tree                  # whole-tree counts and the worst files

CI runs the same script on every pull request and adds the result to the CI comment. It never fails a pull
request. Aim to remove more than you add and to add nothing on the lines you write. Every check is an exact
pattern or a class relation read from the declarations, so a finding is never a guess. Code that only moves
between files or functions counts as neither added nor removed.

**Debt**, the total:

| Check | Finds | Write instead |
|---|---|---|
| `extern_c` | `extern "C"` in a source file declaring what another file defines | include the owner's header |
| `mangled_member`, `mangled_free` | hand-mangled names in source: `update__6TEnemyFv(p)` | the member: `p->update()` |
| `flat_name` | members spelled as C names: `TEnemy__update(void *self)`, `TEnemy__instance` | a member or static member of the class |
| `raw_offset`, `punned_deref` | `(u8 *)p + 0x30`, `*(f32 *)(p + 0x18)`, `*(s32 *)&x` | a field of the right type |
| `offset_member` | fields named after their offset: `unk_30`, `m_30c`, `field_96` | a name from evidence, or `pad_<offset>` for bytes nothing uses |
| `fp_cast` | calls through function-pointer casts | a declared function or a typed pointer |
| `decomp_temp`, `stack_local`, `arg_name`, `ghidra_temp`, `ghidra_type`, `m2c_macro` | `temp_r3`, `sp1C`, `arg0`, `iVar1`, `undefined4`, `M2C_FIELD` | names for what they hold, real types |
| `data_label`, `function_placeholder`, `address_in_name`, `address_type` | names built from addresses: `lbl_8045A010`, `fn_80123456`, `TEnemy__sub_80123456`, `TUnk_804806E8` | a name from evidence; without evidence, keep the placeholder |
| `vtable_symbol`, `hand_vtable`, `filler_virtual`, `slot_name`, `local_virtual` | vtables written by hand, `vfunc_67`, virtual stand-in classes in a source file | virtual functions declared in the class's header |
| `retype_macro`, `inline_asm` | `#define` re-typings of globals, assembly in source | real declarations; see the assembly rule below |

**Members in the wrong class** are reported next to the total, not in it:

- `this_cast`: `this` cast to a declared class that is not its own class, a base or a derived class, such as
  `((TObjPlayer *)this)->init_position_vectors()` inside a `TObjNpcNFW00` member, or a stand-in such as
  `(Self_80238EC8 *)this`. Either the function belongs to that other class, or the cast hides a base or a field
  the class should declare.
- `subobject_call`: a function named for the calling class but called on part of it,
  `TEnemy__set_task((char *)this + 0x3C, task)`. It is a member of whatever object lives at that offset:
  declare the field with its class and call `tasks.set_task(task)`.

**Symbols.** Renamed or new names in `symbols.txt` are flagged when they are flat C names or still built from an
address. A member's symbol is its CodeWarrior name, `poll_default__9TLoadCtrlFv`, which the compiler
produces once the function is a real member. New or renamed symbols that leave a `force_active` entry in
`config.yml` naming nothing are listed too: rename both together.

## Rules

- Nothing that matches or links today may stop matching or linking: `tools/check_pr.py` must pass.
- One source file per unit, functions in address order, class declarations in `include/`.
- No assembly, anywhere. A function Nintendo or Metrowerks wrote in assembly keeps its C signature with the body
  `#include "orig_asm/<unit>/<function>.inc"`, and `tools/orig_asm.py` generates that body from the disc during the
  build. Never write assembly by hand; a function that can only be matched that way stays unmatched.
- No data copied out of the game: no byte dumps of textures, models, sounds or other assets.
- Write source, not decompiler output: use class members and real types instead of raw pointer offsets,
  `void *` parameters, hand-mangled names, decompiler helper macros or hand-written vtables.
  [Source quality](#source-quality) lists what counts and how to check a change.
- No commented-out code, address comments, or notes about how a match was found. Comment only what the code
  can't say itself.
- Names come from evidence in the executable: strings, class-name tables, vtables, call patterns. Keep the
  placeholder (`fn_<address>`) rather than guess.
- Code copied or adapted from another project keeps its notices. Add the project to `third_party/README.md`,
  with its license text under `third_party/LICENSES/` if its terms require a copy.

## Pull requests

- One coherent piece of work per pull request, such as one class or one unit.
- Title it with the result: `Match TObjEneDimedian`, `Link TLobby.cpp`, `Split TBoss8Dragon into its units`.
- Say what changed: matched functions and code and data bytes before and after (the first lines of
  `report_delta.py`), and the evidence for any unit boundary or name.
- Base it on the current `master` and run `tools/check_pr.py` again after rebasing.
- Commits are one short line in plain words, under your own name. Pull requests are squash-merged.
