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

CI runs the same script on every pull request and adds the result to the CI comment: a table of the checks the
change moved, with what it removed and added, and every check by category in a collapsed table under it. It never
fails a pull request. Aim to remove more than you add and to add
nothing on the lines you write. Every check is a rule: a pattern on the text, a file name, or a relation read from
the declarations, `symbols.txt` and `splits.txt`, so a finding is never a guess. A finding is matched with the line
it is on: a line that only moves between files or functions, or a rename within the lines a hunk rewrites, counts
as neither added nor removed, while a finding on a new line is added even when its text matches debt removed
elsewhere.

**Debt**, the total:

| Check | Finds | Write instead |
|---|---|---|
| `extern_c`, `local_decl` | `extern "C"` declarations, prototypes and `extern` data written in a source file (also inside a function body), of what another file defines | include the owner's header |
| `header_extern_c` | `extern "C"` in a header on a function a C++ unit defines, read from `symbols.txt` and `splits.txt`: `extern "C" void widget_update(TWidget *);`. The middleware in `configure.py` is exempt: those libraries are C | declare it with C++ linkage, as a member where it is one |
| `self_param` | `self` receivers in C++ files (`.cpp`, `.cc`, `.cp`, `.cxx`, `.hpp`, `.hh`, `.hxx`; a `.h` may be C): `void widget_update(TWidget *self)` | a member function using `this` |
| `mangled_member`, `mangled_free`, `mangled_itanium` | hand-mangled names in source: `update__6TEnemyFv(p)` | the member: `p->update()` |
| `flat_name` | members spelled as C names: `TEnemy__update(void *self)`, `TEnemy__instance` | a member or static member of the class |
| `raw_offset`, `offset_cast`, `punned_deref` | `(u8 *)p + 0x30`, `(Vec *)(p + 0x178)`, `*(f32 *)(p + 0x18)`, `*(s32 *)&x` | a field of the right type |
| `offset_member` | fields named after their offset: `unk_30`, `m_30c`, `field_96`, `set_field_378`, `p->x7A`, `s.f3A`, `p->b9` | a name from evidence, or `pad_<offset>` for bytes nothing uses |
| `pad_access` | `pad_<offset>` fields the code reads or writes: `p->pad_3E = 0` | a named field: bytes the code uses are not padding |
| `offsetof_access`, `scalar_view` | `offsetof` used as an address, `p + offsetof(TWidget, pos)`, `bytes[offsetof(TWidget, pos)]`, and an object read as an array of scalars, `((s16 *)this)[9]`, `((u32 *)widget)[i]` where `widget` points to a class or struct | the field: `p->pos` |
| `size_assert`, `blob_type` | hand-written `typedef char check[sizeof(T) == 8 ? 1 : -1];`, size-named copy types `struct ByteBlock_28 { u8 b[0x28]; };`, and a struct of bytes of the same size that a change adds in place of one it removes (the blob renamed) | `LAYOUT_ASSERT` from `types.h`; the real type being copied |
| `overlay_type` | structs no file uses as a type, only casts pointers to, that start with padding or are one array: `struct PhaseView { u8 pad[0x28]; s32 phase; };` read as `((PhaseView *)p)->phase` | the fields in the class or data they overlay |
| `fp_cast`, `string_cast` | calls through function-pointer casts, string literals cast to integers or `void *`: `(saddr)"file.gvm"`, `(void *)"file.gvm"` | a declared function or a typed pointer; a `const char *` parameter |
| `this_alias`, `alias_macro`, `cast_macro`, `ptr_int_roundtrip` | `TWidget *self = (TWidget *)this;` and `TWidget *self = this;`, object macros for values `#define obj ((T *)this)`, `#define SELF ((T *)this)`, function macros that cast an argument to a pointer type other than `void *` or a byte pointer `#define HP(p) (((TObjChara *)(p))->hp)`, casts between pointers and integers `(T *)(u32)p`, `(u32)(T *)p`, `(T *)((u32)p + 0x10)` | `this` and the class's fields; real declarations and members; the pointer's real type |
| `repeat_cast` | one name or member chain cast to the same pointer type more than once in a function: `((PppFsm *)self)->abort(); ((PppFsm *)self)->state = 0;`. Casts of `this` and to byte or `void` pointers are left out | a parameter, local or field declared with that type |
| `redundant_cast`, `void_value`, `cross_cast`, `pointer_as_int` | casts judged by the declared type of the local, parameter or file-scope variable they cast: to the type it already has, `TWidget w; f((TWidget *)&w);`; a `void *` parameter or local cast back to a type other than a byte pointer, `void *w; ((TWidget *)w)->x` (`const void *` buffers, and functions the file passes as callbacks, are left out); a class pointer cast to a class it is not related to, `TPlayer *p; ((TWidget *)p)->f()`; a pointer, array, `this` or address cast to an integer outside arithmetic, `f((saddr)&pos)`, `(u32)widget` | declare it with its type: the field, base or member it is; `uaddr` only where the integer is an address, as in `(uaddr)p & 31` |
| `void_arg`, `void_table`, `byte_new`, `static_this` | `void *` casts on arguments, `f((void *)widget)` (a pointer converts by itself; anything else was not a pointer); tables of `void *`, `void *handlers[] = {`; allocations by byte count, `operator new(0x1C)`; members called as statics with `this`, `TWidget::update(this, dt)` | typed parameters; a typed table or struct; `new TWidget`; `update(dt)` |
| `decomp_temp`, `stack_local`, `arg_name`, `ghidra_temp`, `ghidra_type`, `m2c_macro` | `temp_r3`, `sp1C`, `arg0`, `arg2_`, `param1`, `iVar1`, `undefined4`, `M2C_FIELD` | names for what they hold, real types |
| `register_name`, `decomp_label`, `permuter_var`, `no_op` | locals and parameters with register names, `f32 f31;`, `void f(s32 r3)`, `goto block_12;`, `new_var2`, `phi_r3`, `x = x;`, `if (0)`, `if (1)`, `while (0)`, an empty `extern "C" {}` | names for what they hold, structured control flow, nothing |
| `address_comment` | comments naming an address in the executable or a placeholder: `// moved from 0x8043E828`, `// was fn_80123456` | nothing; see the comment rule below |
| `data_label`, `function_placeholder`, `address_in_name`, `address_type`, `address_ident`, `hash_type`, `hex_name` | names built from addresses: `lbl_8045A010`, `fn_80123456`, `TEnemy__sub_80123456`, `TUnk_804806E8`, and any other identifier holding one, `Thing_80123456`; types named after a hash, `VObj_18_4a35f9`; names holding a hex number, `set_mode_0x15`, `has_flag_0x800` | a name from evidence; without evidence, keep the placeholder |
| `param_name_split` | a parameter with a placeholder name on one side and a real name on the other, in a prototype and its definition: `void f(int arg0);` with `void f(int count) {` | the real name on both sides; if that name is `self`, don't copy it (`self_param` flags it): make the function a member of that class instead |
| `vtable_symbol`, `hand_vtable`, `filler_virtual`, `slot_name`, `local_virtual` | vtables written by hand, `vfunc_67`, `p->m4()`, virtual functions declared in a source file | virtual functions declared in the class's header |
| `address_unit` | units and headers named after an address: `TEnemy_80123456.cpp`, `TEnemy_80123456.h` (a header only when no unit has its name), a piece of code not yet in the unit that owns it | fold it into its unit, or name the unit from evidence |
| `local_class`, `duplicate_class` | classes declared in a C++ source file, and classes declared in more than one file: stand-in views such as `struct EnemyView { u8 pad_0[0x30]; f32 speed; };` | one declaration per class, in its header; a view's fields belong in the class it views |
| `misowned_member` | member functions that belong to another class, read from the bodies, `symbols.txt` and `splits.txt`: the body touches no field of its class or of the classes it derives from or that derive from it, and few of its callers are in that hierarchy, such as `TWidget::set_sound_volume(int)` writing only the sound driver's data. Not flagged: units named after the class or holding its name or vtable, small functions placed after their only callers, and bodies that pass `this` on or call the class's members | move the function to the class whose data it uses; make it static, or a free function, when it uses no `this` |
| `retype_macro`, `inline_asm` | `#define` re-typings of globals, assembly in source | real declarations; see the assembly rule below |

C files may keep a struct that only that file uses, so `local_class` counts C++ source files, and a name declared
only in C files is not a duplicate.

**Members in the wrong class** are reported next to the total, not in it:

- `this_cast`: `this` cast to a declared class that is not its own class, a base or a derived class, such as
  `((TObjPlayer *)this)->init_position_vectors()` inside a `TObjNpcNFW00` member, or a stand-in such as
  `(Self_80238EC8 *)this`. Either the function belongs to that other class, or the cast hides a base or a field
  the class should declare.
- `subobject_call`: a function named for the calling class but called on part of it,
  `TEnemy__set_task((char *)this + 0x3C, task)`. It is a member of whatever object lives at that offset:
  declare the field with its class and call `tasks.set_task(task)`.

**Symbols.** Renamed or new names in `symbols.txt` are flagged when they are flat C names, still built from an
address, or members of a class still named after one. A member's symbol is its CodeWarrior name,
`poll_default__9TLoadCtrlFv`, which the compiler produces once the function is a real member. New or renamed
symbols that leave a `force_active` entry in `config.yml` naming nothing are listed too: rename both together.

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
