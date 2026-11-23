#!/usr/bin/env python3
"""Source quality: how much of the matching source still reads as decompiler output.

A byte match proves the code compiles to the original; it says nothing about whether
the source reads as the program's own C/C++. This counts what is left to clean in
src/ and include/ (placeholder names, hand-mangled and flat C spellings of members, raw
offsets, casts, decompiler temporaries, units and classes not in their real home, members
written in the wrong class) and compares two revisions, so a change is measured on the
tree instead of described.

Check your change before opening a pull request (working tree against where it
branched from master):
    python tools/source_quality.py
Other revisions, or the whole tree:
    python tools/source_quality.py --base master --head my-branch
    python tools/source_quality.py --tree [REV]
CI runs the same script from master on every pull request and posts the result in the
CI comment. It never fails a pull request; it shows what the change adds and removes.

Every check is a rule: a pattern on the text, a file name, or a relation read from the
declarations across files or from config/ (symbols.txt and splits.txt). What each one means and
how to fix it is in CONTRIBUTING.md, "Source quality". Standard library only.
"""
from __future__ import annotations

import argparse
import ast
import bisect
import collections
import dataclasses
import itertools
import json
import operator
import re
import subprocess
import sys
import threading
import warnings
from dataclasses import dataclass
from pathlib import Path
from typing import Container, Iterable, Iterator

ROOT = Path(__file__).resolve().parent.parent
SOURCE_ROOTS = ("src", "include")
SOURCE_SUFFIXES = {".c", ".cc", ".cp", ".cpp", ".cxx", ".h", ".hh", ".hpp", ".hxx", ".inc", ".inl"}
HEADER_SUFFIXES = {".h", ".hh", ".hpp", ".hxx", ".inc", ".inl"}
CPP_SUFFIXES = {".cc", ".cp", ".cpp", ".cxx"}           # C++ source files
CXX_FILES = CPP_SUFFIXES | {".hh", ".hpp", ".hxx"}      # C++ files: sources and C++-only headers (.h is either)
MAX_FILE = 4 << 20   # larger files are skipped (no source file comes near this)
WORKTREE = "working tree"


# --- the debt catalog ---------------------------------------------------------------------------------------------

@dataclass(frozen=True)
class Pattern:
    key: str
    name: str                    # short name (the CI comment's table)
    example: str                 # what it looks like in source
    regex: re.Pattern
    group: str
    sources_only: bool = False   # counted in .c/.cpp files only
    needle: re.Pattern | None = None   # text every match contains: files without it are skipped (speed only)


def _p(key: str, name: str, example: str, regex: str, group: str, flags: int = 0,
       sources_only: bool = False, needle: str | None = None) -> Pattern:
    return Pattern(key, name, example, re.compile(regex, flags), group, sources_only,
                   re.compile(needle) if needle else None)


GROUPS = {"linkage": "Linkage", "layout": "Layout", "types": "Types", "decompiler": "Decompiler output",
          "names": "Names", "vtables": "Vtables", "placement": "Units and classes", "asm": "Assembly"}

_EXTERN_PATTERN = r'\bextern\s+"C"'
_NEVER = r"(?!)"   # judged by a parser or over the whole tree, not by a pattern (see PARSED and TREE_CHECKS)
# Placeholder offsets in names; real words spelled in hex digits are names, not offsets.
_HEX_OFFSET = (r"(?:0x)?(?!(?i:add|bad|bed|cab|dab|dad|ebb|fab|fad|fed|fee|ace|bee|cafe|face|fade|dead|deaf|beef|"
               r"babe|bead|cede|dace|abbe)\b)[0-9A-Fa-f]{1,4}\b")
_BYTE_TYPE = r"(?:u8|s8|char|unsigned\s+char|signed\s+char|uint8_t|int8_t|byte|undefined1?)"
_BYTE_CAST = r"\(\s*(?:const\s+)?" + _BYTE_TYPE + r"\s*\*\s*\)\s*(?:\(\s*[\w.\->]+\s*\)|[\w.\->]+)\s*"
_PLUS_OFFSET = r"\+\s*(?:0x[0-9A-Fa-f]+|\d+)\b(?!\s*[\[(])"
_THIS_INIT = (r"(?:\(\s*(?:const\s+)?(?:(?:struct|class)\s+)?[A-Za-z_][\w:]*\s*\*\s*\)"
              r"|(?:reinterpret|static)_cast\s*<[^>]*\*\s*>\s*)\(?\s*this\b")   # (T *)this, static_cast<T *>(this)
_SELF_THIS = r"self\s*=\s*this\s*;"   # self = this; (any other name set to a bare this is often a cursor)
# The integer types a pointer is cast to and back from.
_INT_TYPE = r"(?:[su]addr|u32|s32|u?intptr_t|int|long|unsigned(?:\s+(?:int|long))?)"

# The same catalog and totals as zkit's `quality`.
CATALOG: tuple[Pattern, ...] = (
    # linkage
    _p("extern_c", 'extern "C" declarations', 'extern "C" void TEnemy__update(void *);',
       _EXTERN_PATTERN, "linkage", sources_only=True),
    _p("header_extern_c", 'extern "C" on C++ functions in headers', 'extern "C" void widget_update(TWidget *);',
       _NEVER, "linkage"),
    _p("local_decl", "Prototypes and externs in source files", "void heap_free(void *);",
       _NEVER, "linkage", sources_only=True),
    _p("self_param", "self receivers in C++", "void widget_draw(TWidget *self)", _NEVER, "linkage"),
    _p("mangled_member", "Hand-mangled member names", "update__6TEnemyFv",
       r"\b[A-Za-z_]\w*?__\d+[A-Za-z_]\w*?F\w*\b", "linkage"),
    _p("mangled_free", "Hand-mangled free functions", "helper__Fv", r"\b[A-Za-z_]\w*?__F[A-Za-z]\w*\b", "linkage"),
    _p("mangled_itanium", "Itanium-mangled names", "_ZN6TEnemy6updateEv",
       r"\b_Z(?:N|L|T[VIS])?\d*[A-Za-z_]\w*\b", "linkage"),
    # Class__method: a member spelled as a C function, so its symbol is a flat C name instead of the
    # mangled method__<len>ClassF... and its receiver is a void * instead of `this`.
    _p("flat_name", "Members spelled as C names", "TEnemy__update",
       r"\b(?![A-Za-z0-9_]*__(?:\d|F[A-Za-z]|(?:sub|data)_[0-9A-Fa-f]{6}|vt\d))"
       r"(?=[A-Z](?:[A-Z0-9]|_(?!_))*(?:[a-z]|\d__))[A-Z][A-Za-z0-9]*(?:_[A-Za-z0-9]+)*__[a-z_][A-Za-z0-9_]*\b", "linkage"),
    # layout
    _p("raw_offset", "Byte-pointer offsets", "(u8 *)p + 0x30",
       r"\(\s*" + _BYTE_CAST + r"\)\s*" + _PLUS_OFFSET + "|" + _BYTE_CAST + _PLUS_OFFSET, "layout"),
    _p("offset_cast", "Casts of pointer plus offset", "(Vec *)(p + 0x178)",
       r"(?<!\*)(?<!\*\s)\(\s*(?:const\s+)?[A-Za-z_]\w*\s*\*+\s*\)\s*\(\s*[\w.\->]+\s*\+\s*0x[0-9A-Fa-f]+\s*\)",
       "layout"),
    _p("punned_deref", "Type-punned dereferences", "*(f32 *)&x, *(s32 *)(p + 0x18)",
       r"\*\s*\(\s*(?:(?:const|volatile)\s+)*[A-Za-z_][\w:]*(?:\s+[A-Za-z_]\w*)*\s*\*+\s*(?:const\s*)?\)\s*"
       r"(?:&|\(\s*[^()]*?\+\s*(?:0x[0-9A-Fa-f]+|\d+)\s*\))", "layout"),
    _p("offset_member", "Offset-named fields", "unk_30, m_c, field_96, set_field_378, ->x7A",
       r"\b(?:m_|unk_?|unknown_?|field_?|mbr_)" + _HEX_OFFSET +
       r"|\b[A-Za-z]\w*?_(?:field|unk|unknown)_?" + _HEX_OFFSET +
       r"|(?:->|\.)\s*f(?=[0-9A-Fa-f]*\d)[0-9A-Fa-f]{2,4}\b|\b[a-z]\w*Field_?(?=[0-9A-Fa-f]*\d)[0-9A-Fa-f]{1,4}\b"
       r"|(?:->|\.)\s*(?!f[0-9A-Fa-f]{2,4}\b)(?![usf](?:8|16|32|64)\b)(?!m[0-3][0-3]\b)(?!ip\d+\b)(?!sp[0-9A-F])"
       r"[a-z]{1,2}(?=[0-9A-F])(?=[0-9A-Fa-f]*\d)[0-9A-Fa-f]{2,4}\b", "layout"),
    _p("pad_access", "Padding fields read or written", "p->pad_3E = 0", _NEVER, "layout"),
    _p("size_assert", "Hand-written size asserts", "typedef char check[sizeof(T) == 8 ? 1 : -1];", _NEVER,
       "layout"),
    _p("blob_type", "Size-named blob types", "ByteBlock_28", r"\bByteBlock_?(?:0x)?[0-9A-Fa-f]{1,4}\b", "layout",
       needle=r"ByteBlock"),
    # types
    _p("fp_cast", "Function-pointer casts", "((void (*)(T *))p)(x)",
       r"\(\s*[A-Za-z_][\w:\s\*&<>,]*\(\s*\*+\s*\)\s*\([^()]*\)\s*\)\s*[\w(*&]", "types"),
    _p("string_cast", "Strings cast to integers", '(saddr)"file.gvm"', r"\(\s*" + _INT_TYPE + r"\s*\)\s*\"", "types"),
    _p("ghidra_type", "Ghidra types", "undefined4", r"\bundefined[1248]?\b", "types"),
    _p("address_type", "Address-named types", "TUnk_804806E8",
       r"\b(?:struct|class|union)\s+[A-Za-z]\w*?_[0-9A-Fa-f]{8}\w*"
       r"|\b(?!(?:lbl|fn|FUN|func|sub|DAT|PTR|dat|jumptable|switch)_)[A-Za-z]\w*?_[0-9A-Fa-f]{8}\w*(?=\s*(?:[*&]|::|<))",
       "types"),
    _p("retype_macro", "Re-typing macros", "#define g (*(T *)&g)",
       r"#\s*define\s+(\w+)\s+\(\s*\*\s*\([^)]*\*\s*\)\s*&\s*\1\s*\)"
       r"|#\s*define\s+(\w+)\s+\(\s*\([^)]*\(\s*\*\s*\)\s*\([^)]*\)\s*\)\s*\2\s*\)", "types"),
    # a lower-case object-like macro standing in for an expression (re-typing macros are counted above)
    _p("alias_macro", "Lower-case object macros", "#define obj ((T *)this)",
       r"(?m)^[ \t]*#[ \t]*define[ \t]+(?!_|nullptr\b)([a-z]\w*)[ \t]+"
       r"(?!\(\s*\*\s*\([^)]*\*\s*\)\s*&\s*\1\s*\)|\(\s*\([^)]*\(\s*\*\s*\)\s*\([^)]*\)\s*\)\s*\1\s*\))\S[^\n]*",
       "types", needle=r"define[ \t]+[a-z]"),
    _p("this_alias", "Aliases of this", "TWidget *self = (TWidget *)this;",
       r"\b[A-Za-z_][\w:]*\s*\*\s*(?:const\s+)?(?:\w+\s*=\s*" + _THIS_INIT + r"\s*\)?\s*;|" + _SELF_THIS + ")",
       "types", needle=r"this"),
    # an integer cast to a pointer (a round trip when the integer was a pointer), and a pointer cast to an integer
    _p("ptr_int_roundtrip", "Casts between pointers and integers", "(T *)(u32)p, (u32)(T *)p",
       r"\(\s*(?:const\s+)?[A-Za-z_]\w*\s*\*+\s*\)\s*\(\s*" + _INT_TYPE + r"\s*\)"
       r"|\(\s*" + _INT_TYPE + r"\s*\)\s*\(\s*(?:const\s+)?[A-Za-z_]\w*\s*\*+\s*\)", "types"),
    # decompiler output
    _p("decomp_temp", "m2c temporaries", "temp_r3, var_f31", r"\b(?:temp|var)_[rfa]\d+(?:_\d+)?\b", "decompiler"),
    _p("stack_local", "Stack-slot locals", "sp1C", r"\bsp[0-9A-F]{1,3}\b", "decompiler"),
    _p("arg_name", "Numbered parameters", "arg0, farg1", r"\bf?arg\d+\b", "decompiler"),
    _p("ghidra_temp", "Ghidra temporaries", "iVar1, param_1",
       r"\b(?:[a-z]{1,3}Var\d+|param_\d+|local_[0-9a-fA-F]+|unaff_\w+|extraout_\w+|auStack_\w+|"
       r"in_(?:[a-z]{1,4}\d+|lr|ctr|xer|fpscr|fpcr|sp|pc|nzcv|tpidr\w*|stack_[0-9a-fA-F]+|[A-Z]\w*))\b",
       "decompiler"),
    _p("m2c_macro", "m2c macros", "M2C_FIELD", r"\bM2C_\w+", "decompiler"),
    _p("address_comment", "Address comments", "// moved from 0x8043E828, // was fn_80123456", _NEVER,
       "decompiler"),
    _p("register_name", "Register-style names", "f32 f31; void f(s32 r3)", _NEVER, "decompiler"),
    _p("decomp_label", "Decompiler labels", "goto block_12;",
       r"(?m)\bgoto\s+(?:block|loop|label|lbl|L|bb|jump|case|lab)_?[0-9A-Fa-f]+\b"
       r"|^\s*(?:block|loop|label|lbl|bb|lab)_?[0-9A-Fa-f]+\s*:(?!:)", "decompiler",
       needle=r"goto|(?:block|loop|label|lbl|bb|lab)_?[0-9A-Fa-f]+\s*:"),
    _p("permuter_var", "Permuter variables", "new_var2, phi_r3", r"\bnew_var\d*\b|\bsaved_reg_\w+|\bphi_[rf]\d+\b",
       "decompiler", needle=r"new_var|saved_reg_|phi_"),
    _p("no_op", "No-op statements", "x = x; if (1)", _NEVER, "decompiler"),
    # names
    _p("data_label", "Address-named data", "lbl_8045A010",
       r"\b(?:lbl|DAT|PTR|dat)_[0-9A-Fa-f]{6,16}\b|\b\w+__data_[0-9A-Fa-f]{6,16}\b", "names"),
    _p("function_placeholder", "Address-named functions", "fn_80123456, TEnemy__sub_80123456",
       r"\b(?:fn|FUN|func|sub)_[0-9A-Fa-f]{6,16}\b|\b\w+__sub_[0-9A-Fa-f]{6,16}\b", "names"),
    _p("address_in_name", "Names built on an address", "call_36A90_with_1",
       r"\b(?!(?:lbl|fn|sub|func|dat|ptr|jumptable|switch|temp|var|arg|sp|text|data|bss|rodata)_[0-9A-F])"
       r"[a-z][a-z0-9]*(?:_[a-z][a-z0-9]*)*_(?=[0-9A-F]*\d)[0-9A-F]{5,8}_[A-Za-z0-9]\w*\b", "names"),
    _p("address_ident", "Other address-named identifiers", "Thing_80123456", _NEVER, "names"),
    _p("param_name_split", "Placeholder parameters named on the other side",
       "f(int arg0); / f(int count) {", _NEVER, "names"),
    # vtables
    _p("vtable_symbol", "Vtable symbols in source", "__vt__6TEnemy", r"\b__vt__\d+\w+|\b_ZTV\w+|\b\w+__vtable\b",
       "vtables"),
    _p("hand_vtable", "Hand-written vtables", "void *TEnemy_vtable[] = {",
       r"\bvoid\s*\*\s*(?:const\s+)?\w*(?:vt|vtable|vtbl)\w*\s*\[\s*\d*\s*\]\s*=", "vtables", flags=re.I),
    _p("filler_virtual", "Filler virtuals", "virtual void reserved_3();",
       r"CAT\s*\(\s*\w+\s*,\s*__LINE__\s*\)|\bvirtual\s+\w[\w\s\*&]*\b(?:reserved|virtual|slot|dummy|pad)_?\d+\s*\(",
       "vtables"),
    _p("slot_name", "Slot-numbered names", "vfunc_67, TEnemy__vt82",
       r"\bvfunc_?\d+(?!\d)|\bvf\d+\b|\b[A-Za-z_]\w*?__vt\d+(?!\d)", "vtables"),
    _p("local_virtual", "Virtuals in source files", "virtual void draw();",
       r"(?m)^\s*virtual\b[^;{]*[;{]", "vtables", sources_only=True),
    # where units and classes live
    _p("address_unit", "Units named after an address", "TEnemy_80123456.cpp", _NEVER, "placement"),
    _p("local_class", "Classes declared in source files", "struct EnemyView : TObject {", _NEVER, "placement",
       sources_only=True),
    _p("duplicate_class", "Classes declared in more than one file", "class TEnemy {", _NEVER,
       "placement"),
    _p("misowned_member", "Members that belong to another class", "TWidget::set_sound_volume(int)", _NEVER,
       "placement"),
    # assembly
    _p("inline_asm", "Inline assembly", "asm { ... }",
       r"\basm\s*\{|\b__asm__\b|\basm\s+[\w\s\*&:~<>,]+?\w+\s*\([^;]*\)\s*\{", "asm"),
)
BY_KEY = {p.key: p for p in CATALOG}

# Members written in the wrong class, read from the class declarations (not counted in the debt total).
OWNERSHIP = {   # key -> (name, example)
    "this_cast": ("Casts of this to an unrelated class", "((TObjPlayer *)this)->f()"),
    "subobject_call": ("Own member called on a sub-object", "TEnemy__f((char *)this + 0x3C)"),
}
STALE_FORCE_ACTIVE = "force_active entries the change left naming no symbol in symbols.txt"
# Addresses in comments count when they fall in the executable's image (PsoV3.dol: its first section to the
# end of .bss); other 0x8xxxxxxx values (masks, OS globals, heap addresses) are not code or data addresses.
IMAGE = (0x8000C000, 0x805E1224)


# --- C/C++ text helpers -----------------------------------------------------------------------------------------

_BLANK = re.compile(r'R"(?P<d>[^ ()\\\t\r\n]{0,16})\(.*?\)(?P=d)"|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'|'
                    r'//[^\n]*|/\*.*?\*/|^[ \t]*#(?:[^\n]*\\\n)*[^\n]*', re.S | re.M)
_COMMENT_OR_STRING = re.compile(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\\n])*"', re.S)


def blank(text: str) -> str:
    """text with comments, literals and preprocessor lines replaced by spaces; offsets and newlines kept."""
    return _BLANK.sub(lambda m: re.sub(r"[^\n]", " ", m[0]), text)


def blank_comments(text: str) -> str:
    """Comments dropped and string literals emptied, so documentation of a pattern is not the pattern; every
    line kept in place (for line numbers)."""
    return _COMMENT_OR_STRING.sub(lambda m: "\n" * m[0].count("\n") if m[0][0] == "/" else '""', text)


def _line_index(code: str):
    starts = [0, *itertools.accumulate(len(line) + 1 for line in code.split("\n"))]
    return lambda offset: bisect.bisect_right(starts, offset)   # 1-based line of an offset


_BRACE = re.compile(r"[{}]")


def _matching(code: str, at: int) -> int:
    """Offset of the brace closing the one at `at` (or the end of the text)."""
    depth = 0
    for match in _BRACE.finditer(code, at):
        depth += 1 if match[0] == "{" else -1
        if depth == 0:
            return match.start()
    return len(code)


_ACCESS = re.compile(r"^\s*(?:(?:public|private|protected)\s*:(?!:)\s*)+")
_TEMPLATE = re.compile(r"\btemplate\s*<")
_OPERATOR = re.compile(r"\boperator\s*(?:\(\s*\)|\[\s*\]|[^\s(]+)")
_NOT_A_NAME = {"decltype", "noexcept", "__attribute__", "alignas", "__declspec", "throw", "requires", "sizeof",
               "if", "for", "while", "switch", "return", "catch", "void", "int", "char", "bool", "float", "double",
               "auto", "const", "unsigned", "signed", "long", "short"}
_CLASS_HEAD = re.compile(r"\b(?:class|struct|union)\b(?:\s+(?:\[\[[^\]]*\]\]\s*|alignas\s*\([^)]*\)\s*)*"
                         r"(?P<name>[A-Za-z_][\w:]*))?\s*(?:final\s*)?(?::(?!:)[^{;]*)?$")
_NAME_BEFORE = re.compile(r"((?:[A-Za-z_]\w*\s*(?:<[^<>(){};]*>)?\s*::\s*)*~?[A-Za-z_]\w*)\s*$")


@dataclass(frozen=True)
class Definition:
    name: str     # as spelled in the declarator: helper, Class::method
    scope: str    # enclosing namespaces and classes joined by ::
    in_class: bool
    open: int     # offset of the body's opening brace (a prototype's `;`)
    end: int      # offset of its closing brace (a prototype's `;`)
    params: tuple[int, int] = (0, 0)   # offsets of the parameter list's parentheses

    @property
    def owner(self) -> str | None:
        """The class a member belongs to (None for a free function)."""
        qualified = f"{self.scope}::{self.name}" if self.scope else self.name
        parts = [re.sub(r"<.*", "", p) for p in qualified.split("::")]
        return parts[-2] if len(parts) > 1 else None


def _strip_angles(text: str, at: int) -> int:
    depth = 0
    for index in range(at, len(text)):
        if text[index] == "<":
            depth += 1
        elif text[index] == ">":
            depth -= 1
            if depth == 0:
                return index + 1
        elif text[index] in "{};":
            break
    return at + 1


def _clean_head(head: str) -> str:
    out = head
    for match in _TEMPLATE.finditer(head):
        stop = _strip_angles(head, match.end() - 1)
        out = out[:match.start()] + " " * (stop - match.start()) + out[stop:]
    return _OPERATOR.sub(lambda m: "operator" + "_" * (len(m[0]) - 8), out)


def _groups(head: str) -> list[tuple[int, int]]:
    out, depth, start = [], 0, 0
    for index, char in enumerate(head):
        if char == "(":
            if depth == 0:
                start = index
            depth += 1
        elif char == ")" and depth:
            depth -= 1
            if depth == 0:
                out.append((start, index))
    return out


def _declarator(head: str) -> tuple[int, int, int] | None:
    """(name start, params open, params close) when head declares a function, else None."""
    clean = _clean_head(head)
    groups = _groups(clean)
    if not groups:
        return None
    colon = next((m.start() for m in re.finditer(r"(?<!:):(?!:)", clean) if m.start() > groups[0][1]), None)
    candidates = []
    for open_, close in groups:
        if colon is not None and open_ > colon:
            break
        found = _NAME_BEFORE.search(clean[:open_])
        if found and found[1].split("::")[-1].strip().lstrip("~") not in _NOT_A_NAME:
            candidates.append((found.start(1), open_, close))
    if not candidates:
        return None
    name, open_, close = candidates[-1]
    depth = 0
    for char in clean[:name]:
        depth += char == "<"
        depth -= char == ">" and depth > 0
        if char == "=" and depth == 0:
            return None
    after, depth = clean[close + 1:], 0
    for index, char in enumerate(after):
        depth += char == "("
        depth -= char == ")" and depth > 0
        if char == "=" and depth == 0 and after[index - 1:index] not in ("=", "<", ">", "!") \
                and after[index + 1:index + 2] != "=":
            return None
    return name, open_, close


def definitions(code: str, prototypes: list[Definition] | None = None) -> list[Definition]:
    """Every function definition in blanked C/C++ source, in file order (bodies are not entered). Function
    declarations ending in `;` are added to `prototypes` when it is given."""
    out: list[Definition] = []
    scopes: list[tuple[str, str]] = []
    head_start = position = 0
    structure = re.compile(r"[{};]")
    while True:
        match = structure.search(code, position)
        if match is None:
            break
        at, char = match.start(), match[0]
        if char == "}" or (char == ";" and (prototypes is None or "(" not in code[head_start:at])):
            if char == "}" and scopes:
                scopes.pop()
            head_start = position = at + 1
            continue
        raw = code[head_start:at]
        access = _ACCESS.match(raw)
        offset = head_start + (access.end() if access else 0)
        head = code[offset:at]
        if char == ";":
            found = _declarator(head)
            if found:
                prototypes.append(Definition(re.sub(r"\s+", "", head[found[0]:found[1]]),
                                             "::".join(n for _, n in scopes if n),
                                             bool(scopes) and scopes[-1][0] == "class", at, at,
                                             (offset + found[1], offset + found[2])))
            head_start = position = at + 1
            continue
        clean = _clean_head(head)
        if re.search(r"\benum\b", clean):
            position = head_start = _matching(code, at) + 1
            continue
        klass = _CLASS_HEAD.search(clean)
        if klass and "=" not in clean[:klass.start()]:
            scopes.append(("class", (klass["name"] or "").rsplit("::", 1)[-1]))
            head_start = position = at + 1
            continue
        found = _declarator(head) if "(" in head else None
        if found and re.search(r"(?<!:):(?!:)", clean[found[2]:]) and re.search(r"[\w>]\s*$", head):
            position = _matching(code, at) + 1   # `member{value}` inside a constructor's initializer list
            continue
        if found:
            name_at, open_, close = found
            end = _matching(code, at)
            out.append(Definition(re.sub(r"\s+", "", head[name_at:open_]), "::".join(n for _, n in scopes if n),
                                  bool(scopes) and scopes[-1][0] == "class", at, end,
                                  (offset + open_, offset + close)))
            head_start = position = end + 1
            continue
        if "(" not in clean and re.search(r"\bnamespace\b", clean):
            name = re.search(r"\bnamespace\s+([\w:]*)", clean)
            scopes.append(("namespace", name[1] if name else ""))
        elif re.fullmatch(r"\s*extern\s*", clean):   # extern "C" { (the string is blanked)
            scopes.append(("extern", ""))
        else:
            position = head_start = _matching(code, at) + 1
            continue
        head_start = position = at + 1
    return out


# --- extern "C" debt (as zkit's quality judges it) --------------------------------------------------------------

_EXTERN_C = re.compile(_EXTERN_PATTERN + r"\s*")
_ATTRIBUTE = re.compile(r"\b(?:__declspec|__attribute__|alignas)\s*\(")
_NOT_DECLARED = re.compile(r"\s*(?:typedef|using|template|static_assert|namespace|extern\s*$)\b|"
                           r"\s*(?:struct|class|union|enum)\s+\w+\s*$")
_IDENTIFIER = re.compile(r"[A-Za-z_]\w*")
_C_KEYWORDS = {"const", "volatile", "static", "extern", "inline", "unsigned", "signed", "struct", "class", "union",
               "enum", "register", "restrict", "__restrict"}


def _top_level(text: str, char: str) -> list[int]:
    out, depth = [], 0
    for index, c in enumerate(text):
        if c in "([{":
            depth += 1
        elif c in ")]}":
            depth -= depth > 0
        elif c == char and depth == 0 and not (char == "=" and (text[index + 1:index + 2] == "="
                                                                or text[index - 1:index] in ("=", "!", "<", ">"))):
            out.append(index)
    return out


def _declared(declarator: str) -> tuple[str, bool] | None:
    pointer = re.match(r"[^(]*\(\s*[*&]+\s*(?:const\s+)?([A-Za-z_]\w*)\s*\)", declarator)
    if pointer:
        return pointer[1], False
    opens = [i for i in range(len(declarator)) if declarator[i] == "(" and not _top_level(declarator[:i], "(")]
    if opens:
        name = re.search(r"([A-Za-z_]\w*)\s*$", declarator[:opens[0]])
        return (name[1], True) if name and name[1] not in _C_KEYWORDS else None
    names = [n for n in _IDENTIFIER.findall(re.sub(r"\[[^\]]*\]", " ", declarator)) if n not in _C_KEYWORDS]
    return (names[-1], False) if len(names) > 1 else None


def _drop_attributes(head: str) -> str:
    for attribute in list(_ATTRIBUTE.finditer(head)):
        depth, index = 0, attribute.end() - 1
        while index < len(head):
            depth += head[index] == "("
            depth -= head[index] == ")"
            if depth == 0:
                break
            index += 1
        head = head[:attribute.start()] + " " * (index + 1 - attribute.start()) + head[index + 1:]
    return head


_PUNCTUATION = re.compile(r"[()\[\]{;]")


def _items(code: str, start: int, stop: int, single: bool) -> list[tuple[int, int, bool]]:
    out, begin, index, depth = [], start, start, 0
    while index < stop:
        found = _PUNCTUATION.search(code, index, stop)
        if found is None:
            break
        index, c = found.start(), found[0]
        if c in "([":
            depth += 1
        elif c in ")]":
            depth -= depth > 0
        elif c == "{" and depth == 0:
            close = _matching(code, index)
            head = code[begin:index]
            if _top_level(head, "=") or "(" not in head:
                index = close + 1
                continue
            out.append((begin, close + 1, True))
            begin = index = close + 1
            if single:
                break
            continue
        elif c == ";" and depth == 0:
            out.append((begin, index, False))
            begin = index + 1
            if single:
                break
        index += 1
    return out


def _extern_c_heads(text: str, code: str) -> Iterator[tuple[int, str, bool, bool]]:
    """(offset, head, has a body, in an `extern "C" {` block) of each declaration under `extern "C"`."""
    for match in _EXTERN_C.finditer(text):
        if code[match.start():match.start() + 6] != "extern":   # in a comment or a string
            continue
        at = match.end()
        block = code[at:at + 1] == "{"
        stop = _matching(code, at) if block else len(code)
        for begin, end, body in _items(code, at + 1 if block else at, stop, single=not block):
            head = _drop_attributes(code[begin:end].split("{", 1)[0] if body else code[begin:end])
            if head.strip() and not _NOT_DECLARED.match(head):
                yield begin + len(head) - len(head.lstrip()), head, body, block


def _declarators(head: str) -> list[str]:
    """The pieces of a declaration between its top-level commas."""
    commas = _top_level(head, ",")
    return [head[a:b] for a, b in zip([0, *(i + 1 for i in commas)], [*commas, len(head)])]


def extern_c_debt(text: str, code: str, defs: list[Definition] | None = None) -> list[tuple[int, str]]:
    """(1-based line, name) of each `extern "C"` that is linkage debt in a source file: a declaration of a name
    the file does not define (a call-site prototype that belongs in the owner's header), or a C name given to a
    hand-mangled C++ spelling. A definition under `extern "C"` gives what the file owns its C name and is fine."""
    line = _line_index(code)
    mangled = [p.regex for p in CATALOG if p.key.startswith("mangled_")]
    defined, declared, debt = set(), [], []
    for lead, head, body, block in _extern_c_heads(text, code):
        initialized = bool(_top_level(head, "="))
        extern = bool(re.match(r"\s*extern\b", head))
        for piece in (head.split("=", 1)[0],) if initialized else _declarators(head):
            found = _declared(piece)
            if found is None:
                continue
            name, function = found
            if any(r.fullmatch(name) for r in mangled):
                debt.append((line(lead), name))
            elif body or initialized or (block and not extern and not function):
                defined.add(name)
            else:
                declared.append((line(lead), name))
    if declared:
        inside = []
        for definition in definitions(code) if defs is None else defs:
            defined.add(definition.name.split("::")[-1])
            inside.append((definition.open, definition.end))
        for found in re.finditer(r"\b([A-Za-z_]\w*)\s*(?:\[[^\]\n]*\]\s*)*=(?!=)", code):
            if not any(a < found.start() < b for a, b in inside):
                defined.add(found[1])
        debt += [(where, name) for where, name in declared if name not in defined]
    return sorted(debt)


def extern_c_functions(text: str, code: str) -> list[tuple[int, str]]:
    """(1-based line, name) of each function a header declares under `extern "C"` (header_extern_c judges them
    against the unit that defines each: C linkage is right for a C unit's functions, not a C++ unit's)."""
    line, out = None, []
    for lead, head, body, _ in _extern_c_heads(text, code):
        if body or _top_level(head, "="):
            continue
        for piece in _declarators(head):
            found = _declared(piece)
            if found and found[1]:
                line = line or _line_index(code)
                out.append((line(lead), found[0]))
    return out


# --- declarations, comments and literals ---------------------------------------------------------------------------

_MACRO_NAME = re.compile(r"[A-Z][A-Z0-9_]*")   # MACRO(...) at file scope is an invocation, not a prototype


def _file_scope(text: str, code: str, start: int, stop: int, under_c: bool,
                out: list[tuple[int, int, bool, bool]]) -> None:
    """(begin, end, has a body, under extern "C") of each declaration and definition at file scope, inside
    namespaces and extern "C" blocks too. A class body or an initializer stays part of its declaration."""
    begin = index = start
    depth = 0
    while index < stop:
        found = _PUNCTUATION.search(code, index, stop)
        if found is None:
            break
        at, c = found.start(), found[0]
        index = at + 1
        if c in "([":
            depth += 1
        elif c in ")]":
            depth -= depth > 0
        elif depth:
            continue
        elif c == ";":
            out.append((begin, at, False, under_c))
            begin = index
        else:
            close = _matching(code, at)
            head = code[begin:at]
            lead = begin + len(head) - len(head.lstrip())
            if re.fullmatch(r"\s*extern\s*", head):   # extern "C" { (its string blanked)
                _file_scope(text, code, at + 1, close, under_c or bool(_EXTERN_C.match(text, lead)), out)
                begin = index = close + 1
            elif re.fullmatch(r"\s*(?:inline\s+)?namespace\b[\w\s:]*", head):
                _file_scope(text, code, at + 1, close, under_c, out)
                begin = index = close + 1
            elif _top_level(head, "=") or "(" not in head:
                index = close + 1
            else:
                out.append((begin, close + 1, True, under_c))
                begin = index = close + 1


def _unbraced(head: str) -> str:
    """head with every {...} (a class body, an initializer) replaced by spaces."""
    out, depth = [], 0
    for c in head:
        depth += c == "{"
        out.append(" " if depth else c)
        depth -= c == "}" and depth > 0
    return "".join(out)


def local_decl_debt(text: str, code: str, defs: list[Definition]) -> tuple[list[tuple[int, str]], set[str]]:
    """(1-based line, declaration) of each prototype or `extern` at file scope of a source file, outside
    `extern "C"` (extern_c judges those), that names nothing the file defines: it belongs in the header of the
    file that defines it, which this file should include. Also the names the file defines (its functions and its
    data at file scope)."""
    items: list[tuple[int, int, bool, bool]] = []
    _file_scope(text, code, 0, len(code), False, items)
    defined = {d.name.split("::")[-1] for d in defs}
    declared = []
    for begin, end, body, under_c in items:
        if body:
            continue
        head = _unbraced(_drop_attributes(code[begin:end]))
        lead = begin + len(head) - len(head.lstrip())
        if not head.strip() or _NOT_DECLARED.match(head):
            continue
        single_c = bool(_EXTERN_C.match(text, lead))
        extern = bool(re.match(r"\s*extern\b", head))
        internal = bool(re.match(r"\s*(?:static|inline)\b", head))
        commas = _top_level(head, ",")
        for a, b in zip([0, *(i + 1 for i in commas)], [*commas, len(head)]):
            piece = head[a:b]
            initialized = _top_level(piece, "=")
            found = _declared(piece[:initialized[0]] if initialized else piece)
            if found is None or found[0] in _NOT_A_NAME or _MACRO_NAME.fullmatch(found[0]):
                continue
            name, function = found
            if initialized or not (function or extern):
                defined.add(name)
            elif not (under_c or single_c or (function and internal)):
                declared.append((lead, name, " ".join(head.split())[:80]))
    if not declared:
        return [], defined
    line = _line_index(code)
    return [(line(lead), found) for lead, name, found in declared if name not in defined], defined


_LITERAL_OR_COMMENT = re.compile(r'R"(?P<d>[^ ()\\\t\r\n]{0,16})\(.*?\)(?P=d)"|"(?:\\.|[^"\\\n])*"|'
                                 r"'(?:\\.|[^'\\\n])*'|//[^\n]*|/\*.*?\*/", re.S)
_ADDRESS = re.compile(r"\b(?:0[xX])?(8[0-5][0-9A-Fa-f]{6})\b")
_COMMENT_PLACEHOLDER = re.compile(r"\b(?:fn|lbl|sub|FUN|DAT|func|loc)_[0-9A-Fa-f]{6,8}\b|\w__sub_[0-9A-Fa-f]{6,8}\b")


def address_comments(text: str) -> list[tuple[int, str]]:
    """(1-based line, comment) of each comment that names an address in the executable's image or a placeholder
    name (fn_80123456): where code came from belongs in history, what it is belongs in its name."""
    out, line = [], None
    for match in _LITERAL_OR_COMMENT.finditer(text):
        if match[0][0] != "/":
            continue
        address = next((a for a in _ADDRESS.finditer(match[0]) if IMAGE[0] <= int(a[1], 16) < IMAGE[1]), None)
        placeholder = _COMMENT_PLACEHOLDER.search(match[0])
        if address or placeholder:
            line = line or _line_index(text)
            at = min(m.start() for m in (address, placeholder) if m)
            out.append((line(match.start() + at), " ".join(match[0].split())[:80]))
    return out


def string_casts(text: str) -> list[tuple[int, str]]:
    """(1-based line, cast with its literal) of each string literal cast to an integer type. Read on the text with
    comments and the insides of literals blanked (offsets kept), so `"(u32)"` inside a string is no cast."""
    if '"' not in text:
        return []
    kept = _LITERAL_OR_COMMENT.sub(lambda m: re.sub(r"[^\n]", " ", m[0]) if m[0][0] == "/" else
                                   m[0][0] + re.sub(r"[^\n]", " ", m[0][1:-1]) + m[0][-1], text)
    found = list(BY_KEY["string_cast"].regex.finditer(kept))
    if not found:
        return []
    line = _line_index(kept)
    return [(line(m.start()), " ".join((_STRING_CAST.match(text, m.start()) or m)[0].split())[:80]) for m in found]


_STRING_CAST = re.compile(BY_KEY["string_cast"].regex.pattern + r'(?:\\.|[^"\\\n])*"')   # with the literal
_UNIT_ADDRESS = re.compile(r"_(8[0-5][0-9A-Fa-f]{6})")


def address_unit(rel: str) -> list[tuple[int, str]]:
    """A source file named after an address in the image: a fragment that is not in its real unit yet."""
    path = Path(rel)
    if any(IMAGE[0] <= int(m[1], 16) < IMAGE[1] for m in _UNIT_ADDRESS.finditer(path.stem)):
        return [(1, path.name)]
    return []


_CLASS_BODY = re.compile(r"\b(typedef\s+)?(class|struct|union)\b\s*(?:([A-Za-z_]\w*)\s*)?(?:final\s*)?"
                         r"(?::(?!:)\s*[^{};]*)?\{")


def class_bodies(code: str) -> list[tuple[int, str, str]]:
    """(offset, keyword, name) of each class body not nested in another one, named by its tag or, for an
    anonymous one, by its typedef. Anonymous bodies without a typedef (the type of one variable) are skipped."""
    out, outer_end = [], -1
    for match in _CLASS_BODY.finditer(code):
        brace = match.end() - 1
        if brace < outer_end or code[max(0, match.start() - 12):match.start()].rstrip().endswith("enum"):
            continue
        outer_end = _matching(code, brace)
        name = match[3]
        if not name and match[1]:
            typedef = re.match(r"\s*([A-Za-z_]\w*)\s*[;,\[]", code[outer_end + 1:outer_end + 200])
            name = typedef and typedef[1]
        if name:
            out.append((match.start(), match[2], name))
    return out


def local_classes(rel: str, blanked: "_Blanked") -> list[tuple[int, str]]:
    """(line, class) of each class a C++ source file declares instead of a header. C files are left out: C code
    keeps a struct only one file uses in that file."""
    if Path(rel).suffix.lower() not in CPP_SUFFIXES:
        return []
    return [(blanked.line(offset), f"{keyword} {name}") for offset, keyword, name in blanked.bodies()]


# --- slipped decompiler shapes -------------------------------------------------------------------------------

def _normal(found: str) -> str:
    return " ".join(found.split())[:80]


def _inside(spans: list[tuple[int, int]]):
    """offset -> whether it falls strictly inside one of the (sorted, disjoint) spans."""
    opens = [a for a, _ in spans]

    def test(offset: int) -> bool:
        index = bisect.bisect_left(opens, offset) - 1
        return index >= 0 and offset < spans[index][1]
    return test


def _outermost(spans: Iterable[tuple[int, int]]) -> list[tuple[int, int]]:
    """The spans not inside another, sorted."""
    out: list[tuple[int, int]] = []
    for a, b in sorted(spans):
        if not out or a >= out[-1][1]:
            out.append((a, b))
    return out


def _in_bodies(blanked: "_Blanked"):
    return _inside(_outermost((d.open, d.end) for d in blanked.defs()))


_ADDRESS_IDENT = re.compile(r"\b[A-Za-z_]\w*?_(8[0-5][0-9A-Fa-f]{6})(?![0-9A-Fa-f])\w*\b")
_ADDRESS_NAMED = ("data_label", "function_placeholder", "address_type", "address_in_name")


def address_idents(blanked: "_Blanked") -> list[tuple[int, str]]:
    """(line, identifier) of each identifier holding an address of the image that the address-named checks above
    (data, functions, types, names built on an address) do not count. Include guards (`..._H`) are skipped: they
    follow the header's name, which address_unit counts."""
    kept = blanked.kept()
    found = [m for m in _ADDRESS_IDENT.finditer(kept)
             if IMAGE[0] <= int(m[1], 16) < IMAGE[1] and not m[0].endswith(("_H", "_H_"))]
    if not found:
        return []
    spans = sorted(m.span() for key in _ADDRESS_NAMED for m in blanked.matches(BY_KEY[key]))
    ends = list(itertools.accumulate((b for _, b in spans), max))
    starts = [a for a, _ in spans]
    line = _line_index(kept)
    out = []
    for m in found:
        index = bisect.bisect_left(starts, m.end()) - 1   # spans starting before the match ends
        if index >= 0 and ends[index] > m.start():
            continue
        out.append((line(m.start()), m[0][:80]))
    return out


_PAD_ACCESS = re.compile(r"(?:->|\.)\s*(?:m_)?pad_?(?=[0-9A-Fa-f]*\d)[0-9A-Fa-f]{1,4}\b"
                         r"|(?<![\w.>])(?:m_)?pad_?(?=[0-9A-Fa-f]*\d)[0-9A-Fa-f]{1,4}\s*(?:\[[^\]]*\]\s*)*"
                         r"(?:[-+*/|&^]?=(?!=)|\+\+|--)")


def pad_accesses(blanked: "_Blanked") -> list[tuple[int, str]]:
    """(line, access) of each padding field a function body reads or writes: the field has a meaning."""
    code = blanked()
    found = list(_PAD_ACCESS.finditer(code)) if "pad" in code else []
    if not found:
        return []
    inside = _in_bodies(blanked)
    return [(blanked.line(m.start()), _normal(m[0])) for m in found if inside(m.start())]


_SELF_PARAM = re.compile(r"[(,]\s*(?:const\s+)?[A-Za-z_][\w:]*\s*\*\s*(?:const\s+)?self\s*[,)]"
                         r"|\b[A-Za-z_][\w:]*\s*\*\s*(?!" + _SELF_THIS + r")self\s*=(?!\s*" + _THIS_INIT + r")")


def self_params(rel: str, blanked: "_Blanked") -> list[tuple[int, str]]:
    """(line, declaration) of each `self` receiver in a C++ file: a member written as a C function."""
    if Path(rel).suffix.lower() not in CXX_FILES or "self" not in blanked.text:
        return []
    kept = blanked.kept()
    found = list(_SELF_PARAM.finditer(kept))
    if not found:
        return []
    line = _line_index(kept)
    return [(line(m.start()), _normal(m[0])) for m in found]


_SCALAR = (r"(?:(?:unsigned|signed)\s+)?(?:u8|s8|u16|s16|u32|s32|u64|s64|f32|f64|uaddr|saddr|int|char|short|long|"
           r"float|double|bool|BOOL|uintptr_t|intptr_t|size_t|unsigned|signed|void|vu8|vu16|vu32|vs32)")
# no r0-r2: under the PowerPC EABI r0 is scratch, r1 the stack pointer and r2 the SDA2 base, never a named local
_REGISTER = re.compile(r"\b(?:f(?:[0-9]|[12][0-9]|3[01])|r(?:[3-9]|[12][0-9]|3[01]))\b")
_TYPE_BEFORE = re.compile(r"\b(?:" + _SCALAR + r"|const|struct|class|[A-Z]\w*|[a-z]\w*_t)\s*[\*&]*\s*$")
_COMMA_BEFORE = re.compile(r",\s*[\*&]*\s*$")
_NOT_DECLARATOR = re.compile(r"\b(?:return|case|goto)\s*$")
_DECLARATION = re.compile(r"\s*(?:(?:static|const|register|volatile)\s+)*(?:" + _SCALAR + r"|[A-Z]\w*)\b[^();]*$")
_ASM_LINE = re.compile(r"^\s*(?!" + _SCALAR + r"\s)[a-z_][a-z0-9_]*\.?\s+[rf]\d+\s*,")   # fmr f30, f31
_ASM_BLOCK = re.compile(r"\basm\b[^;{]*\{")


def register_names(text: str, blanked: "_Blanked") -> list[tuple[int, str]]:
    """(line, declaration) of each local or parameter declared with a register's name (r3, f31) outside assembly:
    where m2c saw the value live, not what it is. Fields are left out (u16 f4; often names its offset)."""
    code = blanked()
    found = list(_REGISTER.finditer(code))
    if not found:
        return []
    defs = blanked.defs()
    in_scope = _inside(_outermost([(d.open, d.end) for d in defs]
                                  + [d.params for d in defs + blanked.prototypes()]))
    asm = []
    for match in _ASM_BLOCK.finditer(code):
        if not asm or match.start() >= asm[-1][1]:
            asm.append((match.start(), _matching(code, match.end() - 1)))
    in_asm = _inside(asm)
    lines = text.split("\n")
    out = []
    for m in found:
        before = code[max(0, m.start() - 60):m.start()]
        if not in_scope(m.start()) or in_asm(m.start()) or _NOT_DECLARATOR.search(before):
            continue
        if not _TYPE_BEFORE.search(before):
            # `f32 f30, f31;`: a comma counts only in a declaration statement
            start = max(code.rfind(c, 0, m.start()) for c in ";{}") + 1
            if not (_COMMA_BEFORE.search(before) and _DECLARATION.match(code, start, m.start())
                    and _DECLARATION.match(code[start:m.start()])):
                continue
        number = blanked.line(m.start())
        if _ASM_LINE.search(lines[number - 1]):
            continue
        out.append((number, _normal(lines[number - 1])))
    return out


_SIZE_ASSERT = re.compile(r"\btypedef\s+(?:char|int|u8|s8)\s+\w+\s*\[\s*\(?\s*[^;\]]*?\?\s*1\s*:\s*-\s*1\s*\)?\s*\]")
_SELF_ASSIGNED = re.compile(r"=\s*([A-Za-z_]\w*(?:\s*(?:->|\.)\s*[A-Za-z_]\w*|\[\s*\w+\s*\])*)\s*;")
_CONSTANT_TEST = re.compile(r"if\s*\(\s*(?:0|1|true|false|TRUE|FALSE)\s*\)|while\s*\(\s*(?:0|false|FALSE)\s*\)")


def _word(c: str) -> bool:
    return c.isalnum() or c == "_"


def no_ops(blanked: "_Blanked") -> list[tuple[int, str]]:
    """(line, statement) of each no-op: `x = x;`, `if (1)`, `while (0)` (a decompiler's or permuter's shape)."""
    code = blanked()
    out = []
    for m in _SELF_ASSIGNED.finditer(code):
        end = m.start()
        while end and code[end - 1].isspace():
            end -= 1
        start = end - len(m[1])
        if start >= 0 and code[start:end] == m[1] and \
                not (start and (_word(code[start - 1]) or code[start - 1] in ".>*")):
            out.append((start, _normal(code[start:m.end()])))
    for m in _CONSTANT_TEST.finditer(code):
        if not (m.start() and _word(code[m.start() - 1])):
            out.append((m.start(), _normal(m[0])))
    return [(blanked.line(at), found) for at, found in sorted(out)]


_BLOCK_EXTERN = re.compile(r"(?m)^[ \t]+extern[ \t]+[^;{}]*;")
_BLOCK_PROTOTYPE = re.compile(
    r"(?m)^[ \t]+(?:static[ \t]+)?(?:const[ \t]+)?(?:" + _SCALAR +
    r"|[A-Z]\w*)(?:[ \t]*\*+[ \t]*|[ \t]+)[A-Za-z_]\w*[ \t]*\([ \t]*(?:void|(?:const[ \t]+)?"
    r"(?:struct[ \t]+)?(?:" + _SCALAR + r"|[A-Z]\w*)[ \t]*[\*&]*(?:[ \t]*\w+)?(?:[ \t]*,[ \t]*(?:const[ \t]+)?"
    r"(?:struct[ \t]+)?(?:" + _SCALAR + r"|[A-Z]\w*)[ \t]*[\*&]*(?:[ \t]*\w+)?)*)?[ \t]*\)[ \t]*;")


_MACRO_CALL = re.compile(r"\(\s*[A-Z_][A-Z0-9_]*\s*\)\s*;")   # f(MACRO); is a call, not a prototype


def block_decls(text: str, blanked: "_Blanked", defined: Container[str]) -> list[tuple[int, str]]:
    """(line, declaration) of each prototype or `extern` declared inside a function body, of a name the file does
    not define (`defined`): it belongs in the header of the file that defines it."""
    code = blanked()
    found = list(_BLOCK_EXTERN.finditer(code)) if "extern" in text else []
    for open_, end in _outermost((d.open, d.end) for d in blanked.defs()):
        found += [m for m in _BLOCK_PROTOTYPE.finditer(code, open_, end) if not _MACRO_CALL.search(m[0])]
    if not found:
        return []
    inside = _in_bodies(blanked)
    out = []
    for m in found:
        lead = m.start() + len(m[0]) - len(m[0].lstrip())
        if not inside(lead) or _EXTERN_C.match(text, lead):
            continue
        names = [_declared(piece[:equals[0]] if equals else piece)
                 for piece in _declarators(m[0].strip().rstrip(";")) for equals in [_top_level(piece, "=")]]
        if not all(name and name[0] in defined for name in names):
            out.append((blanked.line(lead), _normal(m[0])))
    return sorted(out)


def local_decls(text: str, blanked: "_Blanked") -> list[tuple[int, str]]:
    """local_decl: prototypes and externs at file scope and in function bodies of names the file does not define."""
    found, defined = local_decl_debt(text, blanked(), blanked.defs())
    return sorted(found + block_decls(text, blanked, defined))


# --- parameter names, compared across files ----------------------------------------------------------------------
# A prototype pairs with the one definition of the same qualified name and parameter count. A parameter named by a
# placeholder on one side and a real name on the other is debt (param_name_split).

LIBRARY_ROOTS = ("libs",)   # read to pair a prototype with its definition, never counted
_PARAM_PLACEHOLDER = re.compile(
    r"^_*(?:[a-z]?arg_?\d+|a\d+|param_?\d+|p\d+|var_?[rf]?\d+\w*|temp_\w+|tmp_?\d*|sp[0-9A-Fa-f]+"
    r"|pad_?\w*|unk\w*|lbl_\w*|field_?[0-9A-Fa-f]+\w*|m_[0-9A-Fa-f]+|local_(?:res)?[0-9A-Fa-f]+|r\d+|f\d+|v\d+"
    r"|ptr_?\d*|unused\w*|\w*_[0-9A-Fa-f]{6,8}|[A-Za-z]|saved_r\d+|in_r\d+|in_f\d+)$")


def _placeholder(name: str, other: str) -> bool:
    """A decompiler-style parameter name (arg0, param_1, unk_4, a lone letter). A letter that starts the other
    side's real name abbreviates it (x / xPos) and is a name."""
    name, other = name.rstrip("_"), other.rstrip("_")
    return bool(_PARAM_PLACEHOLDER.match(name)) and (len(name) > 1 or not other.lower().startswith(name.lower())
                                                     or bool(_PARAM_PLACEHOLDER.match(other)))


def _param_names(code: str, span: tuple[int, int], line) -> tuple[tuple[str, int], ...]:
    """(name or "", line) of each parameter in the list whose parentheses are at span."""
    inner = code[span[0] + 1:span[1]]
    if inner.strip() in ("", "void"):
        return ()
    out, commas = [], _top_level(inner, ",")
    for a, b in zip([0, *(i + 1 for i in commas)], [*commas, len(inner)]):
        piece = inner[a:b]
        equals = _top_level(piece, "=")
        found = _declared(piece[:equals[0]] if equals else piece)
        name = found[0] if found and not found[1] and found[0] not in _NOT_A_NAME else ""
        out.append((name, line(span[0] + 1 + a + len(piece) - len(piece.lstrip()))))
    return tuple(out)


def signatures(blanked: "_Blanked") -> list[tuple[bool, str, tuple[tuple[str, int], ...]]]:
    """(is a definition, qualified name, parameters) of each function prototype and definition in a file."""
    code = blanked()
    return [(definition, f"{d.scope}::{d.name}" if d.scope else d.name, _param_names(code, d.params, blanked.line))
            for definition, found in ((True, blanked.defs()), (False, blanked.prototypes())) for d in found]


def param_names(files: Iterable[tuple[str, list]], counted: Container[str]) -> dict[str, list[Finding]]:
    """param_name_split by the file holding the line to fix (the placeholder's), for files in `counted`."""
    defined, declared = collections.defaultdict(list), collections.defaultdict(list)
    for rel, sigs in files:
        for definition, name, params in sigs:
            (defined if definition else declared)[(name, len(params))].append((rel, params))
    out: dict[str, list[Finding]] = collections.defaultdict(list)
    seen = set()
    for key, prototypes in declared.items():
        if len(defined.get(key, ())) != 1:
            continue
        def_rel, def_params = defined[key][0]
        for rel, params in prototypes:
            for (dn, dl), (fn, fl) in zip(params, def_params):
                if not dn or not fn or dn == fn:
                    continue
                weak = [n for n, o in ((dn, fn), (fn, dn)) if _placeholder(n, o)]
                if len(weak) != 1:
                    continue
                site, line, good, other, other_line = (rel, dl, fn, def_rel, fl) if weak[0] == dn else \
                    (def_rel, fl, dn, rel, dl)
                if site not in counted or (site, line, weak[0], good) in seen:
                    continue
                seen.add((site, line, weak[0], good))
                where = f"{other.rsplit('/', 1)[-1]}:{other_line}"
                out[site].append(Finding("param_name_split", f"{weak[0]} ({good} at {where})", line))
    return dict(out)


_PARTNER_LINE = re.compile(r":\d+\)$")


def identity(f: Finding) -> tuple[str, str]:
    """What a finding is matched by between revisions: (key, text), less a partner's line (other edits move it)."""
    return (f.key, _PARTNER_LINE.sub(")", f.text)) if f.key == "param_name_split" else (f.key, f.text)


# Checks a parser judges in one file: key -> (path, text, blanked: _Blanked) -> [(line, finding text)].
PARSED = {
    "extern_c": lambda rel, text, blanked: [] if "extern" not in text else
    [(where, f'extern "C" {name}') for where, name in extern_c_debt(text, blanked(), blanked.defs())],
    "local_decl": lambda rel, text, blanked: local_decls(text, blanked),
    "self_param": lambda rel, text, blanked: self_params(rel, blanked),
    "pad_access": lambda rel, text, blanked: pad_accesses(blanked),
    "size_assert": lambda rel, text, blanked: [] if "typedef" not in text else
    [(blanked.line(m.start()), _normal(m[0])) for m in _SIZE_ASSERT.finditer(blanked())],
    "string_cast": lambda rel, text, blanked: string_casts(text),
    "address_comment": lambda rel, text, blanked: address_comments(text),
    "register_name": lambda rel, text, blanked: register_names(text, blanked),
    "no_op": lambda rel, text, blanked: no_ops(blanked),
    "address_ident": lambda rel, text, blanked: address_idents(blanked),
    "address_unit": lambda rel, text, blanked: [] if Path(rel).suffix.lower() in HEADER_SUFFIXES else
    address_unit(rel),
    "local_class": lambda rel, text, blanked: local_classes(rel, blanked),
}
# Checks judged over the whole tree (see relations()): they depend on more than one file, or on the config. A
# header named after an address (address_unit) counts only when no unit has its name, since one rename fixes both.
TREE_CHECKS = {"duplicate_class", "header_extern_c", "param_name_split", "address_unit", "misowned_member"}


# --- per-file scan ----------------------------------------------------------------------------------------------

Hunk = tuple[range, range]   # a diff hunk: the lines base removed, the lines head added


@dataclass
class Finding:
    key: str
    text: str
    line: int


_CAST_TYPE = r"\(\s*(?:const\s+)?([A-Za-z_]\w*)\s*\*\s*\)\s*"
_THIS_CAST = re.compile(_CAST_TYPE + r"(?:\(\s*this\s*\)|this\b(?!\s*(?:->|\.|\[)))"
                        r"|\b(?:static|reinterpret)_cast\s*<\s*(?:const\s+)?([A-Za-z_]\w*)\s*\*\s*>\s*\(\s*this\s*\)")
_BYTE_THIS = (r"\(\s*\(?\s*(?:const\s+)?(?:u8|s8|char|unsigned\s+char|signed\s+char)\s*\*\s*\)\s*\(?\s*this\s*\)?"
              r"\s*\+\s*(0x[0-9A-Fa-f]+|\d+)\s*\)?")
_SUB_CALLS = (
    ("flat", re.compile(r"\b([A-Z][A-Za-z0-9]*[a-z0-9])__[a-z_]\w*\s*\(\s*" + _BYTE_THIS)),
    ("mangled", re.compile(r"\b[A-Za-z_~]\w*?__(\d+)([A-Za-z_]\w*?)F\w*\s*\(\s*" + _BYTE_THIS)),
    ("cast", re.compile(r"\(\s*\(\s*([A-Za-z_]\w*)\s*\*\s*\)\s*" + _BYTE_THIS + r"\s*\)\s*->\s*~?\w+\s*\(")),
)
_CLASS_DECL = re.compile(r"\b(?:class|struct|union)\s+([A-Za-z_]\w*)\s*(?:final\s*)?(?::(?!:)\s*([^{;]*))?\{")
_TYPEDEF = re.compile(r"\btypedef\s+(?:(?:struct|class|union)\s+)?([A-Za-z_]\w*)\s+([A-Za-z_]\w*)\s*;")
_TYPEDEF_BODY = re.compile(r"\btypedef\s+(?:struct|class|union)\s*\w*\s*\{")
_USING = re.compile(r"\busing\s+([A-Za-z_]\w*)\s*=\s*(?:(?:struct|class|union)\s+)?([A-Za-z_]\w*)\s*;")


@dataclass
class FileScan:
    counts: collections.Counter                 # catalog key -> count (zkit's method)
    texts: collections.Counter                  # (key, matched text) -> count
    this_casts: list[tuple[str, str, int]]      # (owner class, cast type, line)
    subobject_calls: list[tuple[str, int]]      # (call text, line)
    classes: dict[str, set[str]]                # class declared here -> its direct bases
    aliases: dict[str, str]                     # typedef / using name -> the type it names
    bodies: dict[str, int]                      # class with a body here, not nested in another -> its line
    found: list[Finding] | None = None          # every catalog finding with its line, kept for changed files only
    c_functions: list[tuple[int, str]] = dataclasses.field(default_factory=list)   # header: (line, extern "C" fn)
    signatures: list = dataclasses.field(default_factory=list)   # see signatures()


class _Blanked:
    """blank(text), its function definitions and class bodies, each computed once and only when a check needs it."""

    def __init__(self, text: str):
        self.text, self.code, self._defs, self._bodies, self._line = text, None, None, None, None
        self._prototypes: list[Definition] = []
        self._kept, self._matches = None, None

    def __call__(self) -> str:
        if self.code is None:
            self.code = blank(self.text)
        return self.code

    def kept(self) -> str:
        """blank_comments(text): code and preprocessor lines kept, comments and literals blanked."""
        if self._kept is None:
            self._kept = blank_comments(self.text)
        return self._kept

    def matches(self, pattern: Pattern) -> list[re.Match]:
        """A catalog pattern's matches on kept(), found once (address_ident reads the address-named checks')."""
        if self._matches is None:
            self._matches = {}
        if pattern.key not in self._matches:
            kept = self.kept()
            self._matches[pattern.key] = [] if pattern.needle and not pattern.needle.search(kept) else \
                list(pattern.regex.finditer(kept))
        return self._matches[pattern.key]

    def defs(self) -> list[Definition]:
        if self._defs is None:
            self._defs = definitions(self(), self._prototypes)
        return self._defs

    def prototypes(self) -> list[Definition]:
        self.defs()
        return self._prototypes

    def bodies(self) -> list[tuple[int, str, str]]:
        if self._bodies is None:
            self._bodies = class_bodies(self()) if _HAS_CLASS.search(self.text) else []
        return self._bodies

    def line(self, offset: int) -> int:
        if self._line is None:
            self._line = _line_index(self())
        return self._line(offset)


_HAS_CLASS = re.compile(r"\b(?:class|struct|union)\b")


def catalog_findings(rel: str, text: str, blanked: _Blanked | None = None) -> list[Finding]:
    """Every catalog finding of a file, with its 1-based line."""
    header = Path(rel).suffix.lower() in HEADER_SUFFIXES
    blanked = blanked or _Blanked(text)
    kept = blanked.kept()
    line = None
    out = []
    for pattern in CATALOG:
        if header and pattern.sources_only:
            continue
        if pattern.key in PARSED:
            out += [Finding(pattern.key, found, where) for where, found in PARSED[pattern.key](rel, text, blanked)]
            continue
        if pattern.key in TREE_CHECKS:
            continue
        for match in blanked.matches(pattern):
            line = line or _line_index(kept)
            out.append(Finding(pattern.key, match[0][:80], line(match.start())))
    return out


def scan_file(rel: str, text: str, keep: bool = False) -> FileScan:
    header = Path(rel).suffix.lower() in HEADER_SUFFIXES
    blanked = _Blanked(text)
    found = catalog_findings(rel, text, blanked)
    counts = collections.Counter(f.key for f in found)
    texts = collections.Counter((f.key, f.text) for f in found)
    code = blanked.code

    this_casts, subobject_calls = [], []
    classes: dict[str, set[str]] = collections.defaultdict(set)
    aliases: dict[str, str] = {}
    if any(word in text for word in ("class", "struct", "union", "typedef", "using")):
        code = blanked()
        for match in _CLASS_DECL.finditer(code):
            bases = classes[match[1]]
            for base in (match[2] or "").split(","):
                base = re.sub(r"<.*", "", re.sub(r"\b(?:public|private|protected|virtual)\b", "", base))
                base = base.split("::")[-1].strip()
                if base:
                    bases.add(base)
        for match in _TYPEDEF.finditer(code):
            aliases[match[2]] = match[1]
        for match in _USING.finditer(code):
            aliases[match[1]] = match[2]
        for match in _TYPEDEF_BODY.finditer(code):
            close = _matching(code, match.end() - 1)
            name = re.match(r"\s*([A-Za-z_]\w*)\s*;", code[close + 1:close + 200])
            if name:
                classes.setdefault(name[1], set())
    if "this" in text and (not header or "{" in text):
        code = blanked()
        if _THIS_CAST.search(code) or re.search(_BYTE_THIS, code):
            line = _line_index(code)
            for definition in blanked.defs():
                owner = definition.owner
                if owner is None:
                    continue
                body = code[definition.open:definition.end]
                for match in _THIS_CAST.finditer(body):
                    this_casts.append((owner, match[1] or match[2], line(definition.open + match.start())))
                for kind, regex in _SUB_CALLS:
                    for match in regex.finditer(body):
                        target = match[2][:int(match[1])] if kind == "mangled" else match[1]
                        offset = int(match[3] if kind == "mangled" else match[2], 0)
                        if target == owner and offset:
                            call = " ".join(match[0].split())
                            subobject_calls.append((f"{owner}: {call}", line(definition.open + match.start())))
    bodies = {}
    for offset, _, name in blanked.bodies():
        bodies.setdefault(name, blanked.line(offset))
    c_functions = extern_c_functions(text, blanked()) if header and "extern" in text else []
    return FileScan(counts, texts, this_casts, subobject_calls, dict(classes), aliases, bodies,
                    found if keep else None, c_functions, signatures(blanked))


class ClassMap:
    """Declared classes and their bases, merged over every file (a class declared twice keeps every base)."""

    def __init__(self, scans: Iterable[FileScan]):
        self.bases: dict[str, set[str]] = collections.defaultdict(set)
        self.aliases: dict[str, str] = {}
        for scan in scans:
            for name, bases in scan.classes.items():
                self.bases[name].update(bases)
            self.aliases.update(scan.aliases)
        self._ancestors: dict[str, set[str]] = {}

    def resolve(self, name: str) -> str:
        seen = set()
        while name in self.aliases and name not in seen:
            seen.add(name)
            name = self.aliases[name]
        return name

    def ancestors(self, name: str) -> set[str]:
        if name not in self._ancestors:
            out, todo = set(), [name]
            while todo:
                for base in self.bases.get(todo.pop(), ()):
                    base = self.resolve(base)
                    if base not in out:
                        out.add(base)
                        todo.append(base)
            self._ancestors[name] = out
        return self._ancestors[name]

    def unrelated(self, owner: str, target: str) -> bool:
        """True only when both are declared classes and neither derives from the other."""
        owner, target = self.resolve(owner), self.resolve(target)
        if owner not in self.bases or target not in self.bases or owner == target:
            return False
        return target not in self.ancestors(owner) and owner not in self.ancestors(target)


def ownership(scan: FileScan, classes: ClassMap) -> list[Finding]:
    out = [Finding("this_cast", f"{owner}: ({target} *)this", line)
           for owner, target, line in scan.this_casts if classes.unrelated(owner, target)]
    out += [Finding("subobject_call", text[:120], line) for text, line in scan.subobject_calls]
    return out


def duplicates(scans: dict[str, FileScan]) -> dict[str, list[Finding]]:
    """Classes with a body in more than one file: every copy after the first, a header's copy coming first.
    A name declared only in .c files is left out, since separate C files may each keep their own struct."""
    homes = collections.defaultdict(list)
    for rel, scan in scans.items():
        for name, line in scan.bodies.items():
            homes[name].append((rel, line))
    out = collections.defaultdict(list)
    for name, places in homes.items():
        if len(places) < 2 or all(Path(rel).suffix.lower() == ".c" for rel, _ in places):
            continue
        places.sort(key=lambda place: (Path(place[0]).suffix.lower() not in HEADER_SUFFIXES, place[0]))
        for rel, line in places[1:]:
            out[rel].append(Finding("duplicate_class", name, line))
    return out


def relations(scans: dict[str, FileScan], config: "Config | None" = None,
              library: dict[str, list] | None = None,
              members: dict[str, list[Finding]] | None = None) -> dict[str, list[Finding]]:
    """Findings that depend on more than one file, by the file they are in: classes declared twice,
    extern "C" in headers on functions a C++ unit defines, parameters named differently in a prototype and its
    definition (library: signatures() of files read only to pair them), headers named after an address that no unit
    shares a name with, members in the wrong class, and members that belong to another class (members:
    misowned_members())."""
    classes = ClassMap(scans.values())
    out = duplicates(scans)
    for rel, found in (members or {}).items():
        out[rel] += found
    for rel, found in param_names([*sorted((rel, s.signatures) for rel, s in scans.items()),
                                   *sorted((library or {}).items())], scans).items():
        out[rel] += found
    units = {Path(rel).stem for rel in scans if Path(rel).suffix.lower() not in HEADER_SUFFIXES}
    for rel, scan in scans.items():
        found = ownership(scan, classes)
        if config is not None:
            found += [Finding("header_extern_c", f'extern "C" {name}', line)
                      for line, name in scan.c_functions if config.cxx_linkage(name)]
        if Path(rel).suffix.lower() in HEADER_SUFFIXES and Path(rel).stem not in units:
            found += [Finding("address_unit", name, line) for line, name in address_unit(rel)]
        if found:
            out[rel] += found
    return dict(out)


# --- misowned_member: a C/C++ fact scanner ---------------------------------------------------------------------------
#
# Per function definition: its class, static/virtual, the fields it touches (by declaring class), the globals it
# uses, the functions it calls (constructors included), and how it uses this. A heuristic front end with no compiler:
# one pass of macro expansion and #if evaluation, a declaration walker for classes, typedefs, globals and functions,
# and a body walker that types each receiver backwards (a->b.c[i]->d, casts, calls).

TOK = re.compile(r"[A-Za-z_]\w*|0[xX][0-9A-Fa-f]+\w*|\d[\w.]*|\.\.\.|->|::|\+\+|--|<<=?|>>=?|[<>=!]=|&&|\|\||"
                 r"[-+*/%&|^]=|##|\S")
_STRIP = re.compile(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'', re.S)
_DIR = re.compile(r'^[ \t]*#[ \t]*(\w*)(.*)$', re.S)
BR = {'(': ')', '[': ']', '{': '}'}
CLOSE = {')', ']', '}'}
SRC_EXT = ('.c', '.cpp', '.cp', '.cc')
HDR_EXT = ('.h', '.hpp', '.inc', '.hh')
# libclang's shim neutralises these (cw_shim.h + remapped types.h)
FORCED = {'LAYOUT_ASSERT': (['name', 'cond'], []), 'AT_ADDRESS': (['addr'], []), 'asm': (None, ['__asm_kw']),
          '__option': (['x'], ['0']), '_var_arg_typeof': (['t'], ['0']), 'ATTRIBUTE_ALIGN': (['num'], []),
          'ATTRIBUTE_ALIGN_PARAM': (['num'], [])}
BUILTIN = {'void', 'char', 'short', 'int', 'long', 'float', 'double', 'bool', 'signed', 'unsigned', 'wchar_t',
           '__int64'}
SPEC = {'static', 'extern', 'inline', '__inline', '__inline__', 'virtual', 'const', 'volatile', 'mutable',
        'register', 'explicit', 'friend', 'typename', 'auto', '__asm_kw', 'struct', 'class', 'union', 'enum',
        '__declspec', '__attribute__', 'restrict', '__restrict', 'override'}
KW = BUILTIN | SPEC | {'return', 'if', 'else', 'while', 'for', 'do', 'switch', 'case', 'default', 'break',
                       'continue', 'goto', 'sizeof', 'new', 'delete', 'this', 'operator', 'typedef', 'template',
                       'namespace', 'using', 'public', 'private', 'protected', 'static_cast',
                       'reinterpret_cast', 'const_cast', 'dynamic_cast', 'true', 'false', 'try', 'catch', 'throw',
                       '__STR__', 'NULL', 'nullptr'}
CASTKW = {'static_cast', 'reinterpret_cast', 'const_cast', 'dynamic_cast'}
ACCESS = {'public', 'private', 'protected'}
ASSIGN = {'=', '+=', '-=', '*=', '/=', '%=', '&=', '|=', '^=', '<<=', '>>='}


def isid(t):
    return bool(t) and (t[0].isalpha() or t[0] == '_')


class Type:
    __slots__ = ('base', 'depth', 'spell', 'fn')

    def __init__(self, base, depth=0, spell='', fn=False):
        self.base, self.depth, self.spell, self.fn = base, depth, spell, fn

    def deref(self, n=1):
        return Type(self.base, max(self.depth - n, 0), self.spell, self.fn)

    def __repr__(self):
        return f'{self.base}{"*" * self.depth}'


class Cls:
    __slots__ = ('name', 'bases', 'fields', 'methods', 'file', 'kind', 'nested', 'has_ctor')

    def __init__(self, name, file, kind):
        self.name, self.file, self.kind = name, file, kind
        self.bases = []
        self.fields = {}        # name -> (declaring class, Type, static)
        self.methods = {}       # name -> [Meth]
        self.nested = {}        # short name -> qualified
        self.has_ctor = False


class Meth:
    __slots__ = ('cls', 'name', 'static', 'virtual', 'ret', 'params', 'file')

    def __init__(self, cls, name, static, virtual, ret, params, file):
        self.cls, self.name, self.static, self.virtual = cls, name, static, virtual
        self.ret, self.params, self.file = ret, params, file


class Func:
    __slots__ = ('q', 'name', 'cls', 'file', 'hdr', 'static', 'virtual', 'params', 'lo', 'hi', 'asm')

    def __init__(self, **kw):
        for k in self.__slots__:
            setattr(self, k, kw.get(k))


# ------------------------------------------------------------------ preprocessing
def _strip(text):
    def rep(m):
        s = m[0]
        if s[0] == '/':
            return '\n' * s.count('\n') if s[1] == '*' else ''
        return ' __STR__ ' if s[0] == '"' else ' 0 '
    return _STRIP.sub(rep, text)


def parse_define(rest):
    m = re.match(r'(\w+)(\([^)]*\))?(.*)$', rest.strip(), re.S)
    if not m:
        return None, None
    name = m[1]
    params = None
    if m[2] is not None:
        params = [p.strip() for p in m[2][1:-1].split(',') if p.strip()]
        params = ['__VA_ARGS__' if p == '...' else p for p in params]
    return name, (params, TOK.findall(m[3]))


def collect_macros(files):
    """Header macros visible everywhere (not include guards, not #undef'd in their own header)."""
    g = {}
    for path, text in files.items():
        if not path.endswith(HDR_EXT):
            continue
        last_ifndef = None
        local = {}
        for ln in re.findall(r'^[ \t]*#[ \t]*(?:define|undef|ifndef)\b(?:[^\n]*\\\n)*[^\n]*', _strip(text), re.M):
            ln = ln.replace('\\\n', ' ')
            m = _DIR.match(ln)
            d, rest = m[1], m[2]
            if d == 'ifndef':
                last_ifndef = rest.strip()
                continue
            if d == 'undef':
                local.pop(rest.strip(), None)
                continue
            name, mac = parse_define(rest)
            if name is None:
                continue
            if name == last_ifndef and not mac[1]:
                last_ifndef = None
                continue
            last_ifndef = None
            local[name] = mac
        g.update(local)
    g.update(FORCED)
    return g


def _args(toks, i):
    """toks[i] == '(' : returns (list of arg token lists, index after ')')."""
    depth, args, cur = 0, [], []
    n = len(toks)
    j = i
    while j < n:
        t = toks[j]
        if t in ('(', '[', '{'):
            depth += 1
            if depth > 1:
                cur.append(t)
        elif t in (')', ']', '}'):
            depth -= 1
            if depth == 0:
                args.append(cur)
                return args, j + 1
            cur.append(t)
        elif t == ',' and depth == 1:
            args.append(cur)
            cur = []
        else:
            cur.append(t)
        j += 1
    return None, i + 1


def expand(toks, macros, hide=frozenset(), depth=0):
    if depth > 8:
        return toks
    hits = [i for i, t in enumerate(toks) if t in macros and t not in hide]
    if not hits:
        return toks
    out = []
    pos = 0
    for i in hits:
        if i < pos:
            continue
        name = toks[i]
        params, body = macros[name]
        if params is None:
            out.extend(toks[pos:i])
            out.extend(expand(body, macros, hide | {name}, depth + 1))
            pos = i + 1
            continue
        if i + 1 >= len(toks) or toks[i + 1] != '(':
            continue
        args, end = _args(toks, i + 1)
        if args is None:
            continue
        if args == [[]] and not params:
            args = []
        amap = {}
        for k, p in enumerate(params):
            if p == '__VA_ARGS__':
                rest = []
                for a in args[k:]:
                    if rest:
                        rest.append(',')
                    rest.extend(a)
                amap[p] = rest
            else:
                amap[p] = args[k] if k < len(args) else []
        res = []
        b = body
        k = 0
        while k < len(b):
            t = b[k]
            if t == '#' and k + 1 < len(b) and b[k + 1] in amap:
                res.append('__STR__')
                k += 2
                continue
            if t == '##' and res and k + 1 < len(b):
                nt = b[k + 1]
                nx = amap[nt] if nt in amap else [nt]
                if nx:
                    res[-1] = res[-1] + nx[0]
                    res.extend(nx[1:])
                k += 2
                continue
            if t in amap:
                if k + 1 < len(b) and b[k + 1] == '##':
                    res.extend(amap[t])
                else:
                    res.extend(expand(amap[t], macros, hide, depth + 1))
            else:
                res.append(t)
            k += 1
        out.extend(toks[pos:i])
        out.extend(expand(res, macros, hide | {name}, depth + 1))
        pos = end
    out.extend(toks[pos:])
    return out


def _eval_if(expr, macros, defined):
    e = re.sub(r'defined\s*\(\s*(\w+)\s*\)|defined\s+(\w+)',
               lambda m: '1' if (m[1] or m[2]) in defined or (m[1] or m[2]) in macros else '0', expr)
    toks = expand(TOK.findall(e), {k: v for k, v in macros.items() if v[0] is None})
    py = []
    for t in toks:
        if t == '&&':
            py.append(' and ')
        elif t == '||':
            py.append(' or ')
        elif t == '!':
            py.append(' not ')
        elif isid(t):
            py.append('1' if t in defined else '0')
        else:
            py.append(re.sub(r'(?<=\d)[uUlL]+$', '', t))
    try:
        with warnings.catch_warnings():
            warnings.simplefilter("ignore")
            return bool(_pp_value(ast.parse("".join(py).strip(" \t"), mode="eval").body))
    except Exception:
        return True


_PP_UNARY = {ast.USub: operator.neg, ast.UAdd: operator.pos, ast.Invert: operator.invert, ast.Not: operator.not_}
_PP_BINARY = {ast.Add: operator.add, ast.Sub: operator.sub, ast.Mult: operator.mul, ast.Div: operator.truediv,
              ast.Mod: operator.mod, ast.LShift: operator.lshift, ast.RShift: operator.rshift,
              ast.BitAnd: operator.and_, ast.BitOr: operator.or_, ast.BitXor: operator.xor}
_PP_COMPARE = {ast.Eq: operator.eq, ast.NotEq: operator.ne, ast.Lt: operator.lt, ast.LtE: operator.le,
               ast.Gt: operator.gt, ast.GtE: operator.ge}


def _pp_value(node):
    """What eval() gives for a condition rewritten as Python, for numbers and operators only: the text comes from
    the change under review, so it is never evaluated as code. Anything else (and a shift past 64 bits) raises."""
    if isinstance(node, ast.Constant) and type(node.value) in (int, float):
        return node.value
    if isinstance(node, ast.UnaryOp) and type(node.op) in _PP_UNARY:
        return _PP_UNARY[type(node.op)](_pp_value(node.operand))
    if isinstance(node, ast.BinOp) and type(node.op) in _PP_BINARY:
        left, right = _pp_value(node.left), _pp_value(node.right)
        if isinstance(node.op, ast.LShift) and right > 64:
            raise ValueError("shift too large")
        return _PP_BINARY[type(node.op)](left, right)
    if isinstance(node, ast.BoolOp):
        for item in node.values:
            value = _pp_value(item)
            if bool(value) is isinstance(node.op, ast.Or):
                break
        return value
    if isinstance(node, ast.Compare) and all(type(op) in _PP_COMPARE for op in node.ops):
        left = _pp_value(node.left)
        for op, item in zip(node.ops, node.comparators):
            right = _pp_value(item)
            if not _PP_COMPARE[type(op)](left, right):
                return False
            left = right
        return True
    raise ValueError("not a constant expression")


def preprocess(path, text, gmacros):
    """-> token list of the file (directives applied, macros expanded)."""
    cpp = not path.endswith('.c')
    defined = {'__cplusplus'} if cpp else set()
    if path.startswith('libs/'):
        defined.add('__GEKKO__')
    macros = dict(gmacros)
    out = []
    buf = []
    stack = []
    active = True
    lines = _strip(text).split('\n')
    n = len(lines)
    i = 0

    def flush():
        if buf:
            out.extend(expand(TOK.findall('\n'.join(buf)), macros))
            buf.clear()

    while i < n:
        ln = lines[i]
        if ln.lstrip().startswith('#'):
            while ln.endswith('\\') and i + 1 < n:
                i += 1
                ln = ln[:-1] + ' ' + lines[i]
            m = _DIR.match(ln)
            d, rest = (m[1], m[2].strip()) if m else ('', '')
            if d in ('if', 'ifdef', 'ifndef'):
                if active:
                    if d == 'if':
                        v = _eval_if(rest, macros, defined)
                    else:
                        nm = rest.split()[0] if rest.split() else ''
                        v = (nm in defined or nm in macros) == (d == 'ifdef')
                    stack.append([True, v])
                    active = v
                else:
                    stack.append([False, True])
            elif d == 'elif':
                if stack:
                    par, taken = stack[-1]
                    if par and not taken:
                        v = _eval_if(rest, macros, defined)
                        stack[-1][1] = v
                        active = v
                    else:
                        active = False
            elif d == 'else':
                if stack:
                    par, taken = stack[-1]
                    active = par and not taken
                    stack[-1][1] = True
            elif d == 'endif':
                if stack:
                    active = stack.pop()[0]
            elif active and d == 'define':
                name, mac = parse_define(rest)
                if name and name not in FORCED:
                    flush()
                    macros[name] = mac
            elif active and d == 'undef':
                flush()
                macros.pop(rest.strip(), None)
        elif active:
            buf.append(ln)
        i += 1
    flush()
    return out


def match_table(toks):
    m = {}
    st = []
    for i, t in enumerate(toks):
        if t in BR:
            st.append(i)
        elif t in CLOSE:
            if st:
                j = st.pop()
                m[j] = i
                m[i] = j
    return m


# ------------------------------------------------------------------ declarations
class Tree:
    def __init__(self, files):
        """files: {tree-relative path: text} for src/, include/, libs/ (headers and units)."""
        self.classes = {}           # qualified name -> Cls  (first non-forward definition, headers first)
        self.local_classes = collections.defaultdict(dict)   # file -> {name: Cls} (classes defined in units)
        self.typedefs = {}          # name -> Type
        self.globals = {}           # qualified name -> Type
        self.file_globals = collections.defaultdict(dict)    # unit file -> name -> Type (its own declarations)
        self.funcs_decl = collections.defaultdict(list)   # free function name -> [Meth]
        self.defs = []              # Func
        self.toks = {}
        self.match = {}
        gm = collect_macros(files)
        order = sorted(files, key=lambda p: (not p.endswith(HDR_EXT), p))
        for p in order:
            t = preprocess(p, files[p], gm)
            self.toks[p] = t
            self.match[p] = match_table(t)
        for p in order:
            self._block(p, 0, len(self.toks[p]), None, '')

    # --- class lookup
    def cls(self, name, file=None, ctx=None):
        if name is None:
            return None
        if ctx is not None:
            c = self.classes.get(ctx)
            while c is not None:
                q = c.nested.get(name)
                if q:
                    return self.classes.get(q)
                c = self.classes.get(c.name.rsplit('::', 1)[0]) if '::' in c.name else None
        if file is not None:
            c = self.local_classes.get(file, {}).get(name)
            if c is not None:
                return c
        c = self.classes.get(name)
        if c is not None:
            return c
        td = self.typedefs.get(name)
        if td is not None and td.depth == 0 and td.base != name:
            return self.classes.get(td.base)
        return None

    def resolve(self, t, file=None, ctx=None, seen=0):
        """Type with typedefs unwound and base mapped to a class name when it names one."""
        if t is None or t.base is None:
            return t
        b = t.base
        if ctx is not None or file is not None:
            c = self.cls(b, file, ctx)
            if c is not None:
                return Type(c.name, t.depth, t.spell, t.fn)
        if b in self.classes:
            return t
        td = self.typedefs.get(b)
        if td is not None and seen < 8 and td.base != b:
            r = self.resolve(td, file, None, seen + 1)
            return Type(r.base, r.depth + t.depth, t.spell or td.spell, r.fn or t.fn)
        return t

    def _block(self, f, lo, hi, cls, ns):
        toks, mt = self.toks[f], self.match[f]
        i = lo
        s = lo
        pre = []      # tokens of the current statement that replace a consumed class/enum body
        while i < hi:
            t = toks[i]
            if t == ';':
                st = pre + toks[s:i]
                if st:
                    self._decl(f, st, cls, ns)
                pre = []
                i += 1
                s = i
                continue
            if t == '(' or t == '[':
                i = mt.get(i, i) + 1
                continue
            if t == ':' and cls is not None and i == s + 1 and toks[s] in ACCESS and not pre:
                i += 1
                s = i
                continue
            if t == '}':      # stray
                i += 1
                s = i
                pre = []
                continue
            if t == '{':
                j = mt.get(i, hi - 1)
                head = pre + toks[s:i]
                k = self._classify(head)
                if k == 'ns':
                    nm = head[1] if len(head) > 1 and isid(head[1]) else ''
                    self._block(f, i + 1, j, cls, ns + (nm + '::' if nm else ''))
                    i = j + 1
                    s = i
                    pre = []
                    continue
                if k == 'extern':
                    self._block(f, i + 1, j, cls, ns)
                    i = j + 1
                    s = i
                    pre = []
                    continue
                if k[0] == 'class':
                    ci = k[1]
                    name = self._class(f, head, ci, i, j, cls, ns)
                    pre = head[:ci] + ['\x00' + name]
                    i = j + 1
                    s = i
                    continue
                if k == 'enum':
                    ei = head.index('enum')
                    nm = [x for x in head[ei + 1:] if isid(x) and x != 'class']
                    if nm:
                        self.typedefs.setdefault(nm[0], Type('int', 0, nm[0]))
                    pre = head[:ei] + ['int']
                    i = j + 1
                    s = i
                    continue
                if k == 'init':
                    i = j + 1
                    continue
                if k == 'func':
                    self._funcdef(f, head, i, j, cls, ns)
                    i = j + 1
                    s = i
                    pre = []
                    continue
                i = j + 1
                s = i
                pre = []
                continue
            i += 1

    def _classify(self, head):
        if not head:
            return 'other'
        if head[0] == 'namespace':
            return 'ns'
        if head[0] == 'extern' and len(head) == 2 and head[1] == '__STR__':
            return 'extern'
        d = 0
        for k, t in enumerate(head):
            if t == '(':
                d += 1
            elif t == ')':
                d -= 1
            elif d == 0 and t == '=' and (k == 0 or head[k - 1] != 'operator'):
                return 'init'
        # class head: [template <..>] [typedef] (class|struct|union) [name] [: bases]
        for k, t in enumerate(head):
            if t in ('class', 'struct', 'union') and '(' not in head[:k]:
                # `struct X *f(...) {` is a function returning a pointer
                rest = head[k + 1:]
                if '(' in rest and ')' == head[-1] or (rest and rest[-1] == 'const' and ')' in rest):
                    break
                return ('class', k)
            if t == 'enum' and '(' not in head:
                return 'enum'
        if ')' in head or 'operator' in head:
            return 'func'
        return 'other'

    def _class(self, f, head, ci, lo, hi, outer, ns):
        kind = head[ci]
        rest = head[ci + 1:]
        # skip attributes
        while rest and rest[0] in ('__declspec', '__attribute__') and len(rest) > 1:
            rest = rest[1:]
            if rest and rest[0] == '(':
                d = 0
                for k, t in enumerate(rest):
                    d += t == '('
                    d -= t == ')'
                    if d == 0:
                        rest = rest[k + 1:]
                        break
        name = None
        if rest and isid(rest[0]) and rest[0] not in ('final',):
            name = rest[0]
            rest = rest[1:]
            while len(rest) >= 2 and rest[0] == '::' and isid(rest[1]):
                name = name + '::' + rest[1]
                rest = rest[2:]
            if rest and rest[0] == '<':
                d = 0
                for k, t in enumerate(rest):
                    d += t == '<'
                    d -= t == '>'
                    if d == 0:
                        rest = rest[k + 1:]
                        break
        anon = name is None
        if anon:
            base = outer if outer else '(unnamed)'
            name = f'{base}::(anonymous {kind} at {f}:{lo})' if outer else f'(unnamed {kind} at {f}:{lo})'
            q = name
        else:
            q = (outer + '::' + name) if outer else ns + name
        c = Cls(q, f, kind)
        bases = []
        if rest and rest[0] == ':':
            cur = []
            for t in rest[1:] + [',']:
                if t == ',':
                    ids = [x for x in cur if isid(x) and x not in ('public', 'private', 'protected', 'virtual')]
                    if ids:
                        bases.append('::'.join(ids) if '::' in cur else ids[-1] if '<' not in cur else ids[0])
                    cur = []
                elif t in ('<', '>'):
                    cur.append(t)
                else:
                    cur.append(t)
        c.bases = bases
        prev = self.classes.get(q)
        islocal = f.endswith(SRC_EXT)
        if islocal and prev is not None and prev.file != f:
            self.local_classes[f][q] = c
        elif prev is None or not prev.fields and not prev.methods:
            self.classes[q] = c
        else:
            self.local_classes[f][q] = c
        if outer and not anon:
            oc = self.classes.get(outer) or self.local_classes[f].get(outer)
            if oc is not None:
                oc.nested[name] = q
        self._block(f, lo + 1, hi, q, ns)
        # resolve base names now that the class exists
        c.bases = [self._qual_class(b, f, outer) for b in bases]
        return q

    def _qual_class(self, b, f, ctx):
        c = self.cls(b, f, ctx)
        return c.name if c else b

    def _owner(self, cls, f):
        if cls is None:
            return None
        return self.local_classes.get(f, {}).get(cls) or self.classes.get(cls)

    # --- declarations
    def parse_type(self, st, k=0):
        """-> (Type, index after the type specifiers, flags set)."""
        flags = set()
        base = None
        n = len(st)
        bt = []
        while k < n:
            t = st[k]
            if t in ('__declspec', '__attribute__') and k + 1 < n and st[k + 1] == '(':
                d = 0
                while k < n:
                    d += st[k] == '('
                    d -= st[k] == ')'
                    k += 1
                    if d == 0:
                        break
                continue
            if t == '__STR__' and k > 0 and st[k - 1] == 'extern':
                k += 1
                continue
            if t in SPEC:
                if t in ('struct', 'class', 'union', 'enum'):
                    k += 1
                    continue
                flags.add(t)
                k += 1
                continue
            if t in BUILTIN:
                bt.append(t)
                k += 1
                continue
            if t[0] == '\x00':
                base = t[1:]
                k += 1
                break
            if bt:
                break
            if isid(t) and t not in KW:
                base = t
                k += 1
                while k + 1 < n and st[k] == '::' and isid(st[k + 1]):
                    if st[k + 1] == base.rsplit('::', 1)[-1] or st[k + 1].startswith('~'):
                        break
                    if k + 2 < n and st[k + 2] == '(' and st[k + 1] not in self.classes and \
                            base + '::' + st[k + 1] not in self.classes:
                        break
                    base = base + '::' + st[k + 1]
                    k += 2
                if k < n and st[k] == '<':
                    d = 0
                    while k < n:
                        d += st[k] == '<'
                        d -= st[k] == '>'
                        k += 1
                        if d == 0:
                            break
                break
            break
        while k < n and st[k] in ('const', 'volatile'):
            k += 1
        if base is None and bt:
            if 'float' in bt:
                base = 'float'
            elif 'double' in bt:
                base = 'double'
            elif 'void' in bt:
                base = 'void'
            elif 'bool' in bt:
                base = 'bool'
            elif 'char' in bt:
                base = 'char'
            else:
                base = 'int'
        return Type(base, 0, ' '.join(bt) or (base or '')), k, flags

    def declarators(self, st, k):
        """Split st[k:] on top-level commas -> list of (name, ptr, fn-params or None, is_fnptr, arrays, rest)."""
        out = []
        n = len(st)
        while k < n:
            ptr = 0
            while k < n and st[k] in ('*', '&', 'const', 'volatile', '__restrict', 'restrict'):
                ptr += st[k] in ('*', '&')
                k += 1
            name = None
            fnptr = False
            params = None
            arrays = 0
            qual = []
            if k < n and st[k] == '(' and k + 1 < n and st[k + 1] in ('*', '&') or \
                    (k < n and st[k] == '(' and k + 2 < n and isid(st[k + 1]) and st[k + 2] == '::'):
                # (*name)(...) function pointer / (Cls::*pm)
                d = 0
                j = k
                while j < n:
                    d += st[j] == '('
                    d -= st[j] == ')'
                    if isid(st[j]) and st[j] not in KW and name is None and st[j - 1] in ('*', '&', '('):
                        name = st[j]
                    j += 1
                    if d == 0:
                        break
                fnptr = True
                ptr += 1
                k = j
            else:
                # possibly qualified name, operator, destructor
                while k < n:
                    t = st[k]
                    if t == '~' and k + 1 < n:
                        name = '~' + st[k + 1]
                        k += 2
                    elif t == 'operator':
                        j = k + 1
                        if j < n and st[j] in ('(', '['):
                            j += 2
                        else:
                            while j < n and st[j] != '(':
                                j += 1
                        name = 'operator' + ''.join(st[k + 1:j])
                        k = j
                    elif isid(t) and t not in KW:
                        name = t
                        k += 1
                        if k < n and st[k] == '<':
                            d = 0
                            j = k
                            while j < n:
                                d += st[j] == '<'
                                d -= st[j] == '>'
                                j += 1
                                if d == 0:
                                    break
                            if j < n and st[j] == '::':
                                k = j
                    else:
                        break
                    if k + 1 < n and st[k] == '::':
                        qual.append(name)
                        name = None
                        k += 1
                        continue
                    break
            # suffixes
            rest_start = k
            while k < n and st[k] != ',':
                t = st[k]
                if t == '(':
                    d = 0
                    j = k
                    while j < n:
                        d += st[j] == '('
                        d -= st[j] == ')'
                        j += 1
                        if d == 0:
                            break
                    if params is None and not (fnptr and params is None and False):
                        params = st[k + 1:j - 1]
                    k = j
                    continue
                if t == '[':
                    arrays += 1
                    d = 0
                    while k < n:
                        d += st[k] == '['
                        d -= st[k] == ']'
                        k += 1
                        if d == 0:
                            break
                    continue
                if t == '=' or t == ':':
                    # initializer / bitfield: skip to top-level comma
                    d = 0
                    while k < n:
                        x = st[k]
                        if x in ('(', '[', '{', '<') and x != '<':
                            d += 1
                        elif x in (')', ']', '}'):
                            d -= 1
                        elif x == ',' and d == 0:
                            break
                        k += 1
                    break
                k += 1
            out.append((qual, name, ptr, None if fnptr else params, fnptr, arrays, st[rest_start:k]))
            k += 1
        return out

    def param_list(self, pt, f, ctx):
        """param tokens -> [(name, Type)]"""
        if not pt or pt == ['void']:
            return []
        res = []
        cur = []
        d = 0
        for t in pt + [',']:
            if t in ('(', '[', '<'):
                d += 1
            elif t in (')', ']', '>'):
                d -= 1
            if t == ',' and d == 0:
                if cur and cur != ['...']:
                    ty, k, _ = self.parse_type(cur)
                    ds = self.declarators(cur, k)
                    nm, ptr, arr = None, 0, 0
                    if ds:
                        _, nm, ptr, _, fp, arr, _ = ds[0]
                    t2 = Type(ty.base, ptr + arr, ' '.join(cur), bool(ds and ds[0][4]))
                    res.append((nm, self.resolve(t2, f, ctx)))
                cur = []
            else:
                cur.append(t)
        return res

    def _decl(self, f, st, cls, ns):
        if not st:
            return
        if st[0] == 'template':
            return
        if st[0] == 'using':
            if len(st) >= 4 and st[2] == '=':
                ty, k, _ = self.parse_type(st, 3)
                ds = self.declarators(st, k)
                self.typedefs[st[1]] = Type(ty.base, ds[0][2] if ds else 0, ty.spell)
            return
        if st[0] == 'friend' or st[0] == 'static_assert':
            return
        if st[0] == 'typedef':
            ty, k, _ = self.parse_type(st, 1)
            for qual, name, ptr, params, fnptr, arrays, _ in self.declarators(st, k):
                if name and name != ty.base:
                    self.typedefs[name] = Type(ty.base, ptr + arrays, ty.spell, fnptr or params is not None)
                elif name and name == ty.base and ty.base not in self.classes:
                    pass
            return
        if st[0] in ('class', 'struct', 'union') and (len(st) == 1 or (isid(st[1]) and (len(st) == 2 or st[2] == ';'))):
            return          # forward declaration
        ty, k, flags = self.parse_type(st)
        own = self._owner(cls, f)
        # constructor / destructor / conversion operator declarations inside a class
        if own is not None and (k < len(st) and st[k] == '(' and ty.base == cls.rsplit('::', 1)[-1]):
            own.has_ctor = True
            return
        if own is not None and ty.base is None and st and st[k:k + 1] == ['~']:
            return
        if own is not None and (st[k - 1:k] == [cls.rsplit('::', 1)[-1]] and k < len(st) and st[k] == '('):
            own.has_ctor = True
            return
        for qual, name, ptr, params, fnptr, arrays, rest in self.declarators(st, k):
            if not name:
                continue
            if ty.base and ty.base[0] == '(' or ty.base and '(anonymous' in ty.base or \
                    ty.base and '(unnamed' in ty.base:
                pass
            if params is not None and not fnptr:
                rt = self.resolve(Type(ty.base, ptr, ty.spell + ' *' * ptr), f, cls)
                pl = self.param_list(params, f, cls)
                if own is not None and not qual:
                    m = Meth(cls, name, 'static' in flags, 'virtual' in flags or 'override' in rest, rt, pl, f)
                    own.methods.setdefault(name, []).append(m)
                elif qual:
                    oc = self.cls('::'.join(qual), f, cls)
                    if oc is not None:
                        pass      # out-of-line redeclaration
                else:
                    self.funcs_decl[ns + name].append(Meth(None, ns + name, 'static' in flags, False, rt, pl, f))
                continue
            t2 = self.resolve(Type(ty.base, ptr + arrays, ty.spell, fnptr), f, cls)
            if own is not None and not qual:
                if 'static' in flags:
                    own.fields[name] = (cls, t2, True)
                    self.globals[cls + '::' + name] = t2
                else:
                    own.fields[name] = (cls, t2, False)
            elif qual:
                self.globals['::'.join(qual) + '::' + name] = t2
            else:
                self.globals.setdefault(ns + name, t2)
                if not f.endswith(HDR_EXT) and cls is None:
                    self.file_globals[f][ns + name] = t2
        # anonymous struct/union member: merge its fields (declaring class stays the anonymous record)
        if own is not None and ty.base and ty.base.startswith(cls + '::(anonymous') and \
                not [d for d in self.declarators(st, k) if d[1]]:
            ac = self.classes.get(ty.base) or self.local_classes[f].get(ty.base)
            if ac is not None:
                for fn_, v in ac.fields.items():
                    own.fields.setdefault(fn_, v)
                for mn, v in ac.methods.items():
                    own.methods.setdefault(mn, v)

    def _funcdef(self, f, head, lo, hi, cls, ns):
        # strip a ctor init list: ':' at paren depth 0 after the parameter list
        d = 0
        cut = None
        seen_paren = False
        for k, t in enumerate(head):
            if t == '(':
                d += 1
                seen_paren = True
            elif t == ')':
                d -= 1
            elif t == ':' and d == 0 and seen_paren:
                cut = k
                break
        hd = head[:cut] if cut is not None else head
        if hd and hd[0] == 'template':
            return
        ty, k, flags = self.parse_type(hd)
        is_asm = '__asm_kw' in flags or '__asm_kw' in hd
        ds = self._ctor_head(hd) or self.declarators(hd, k)
        if ds and ds[0][1] and (ds[0][1] == (ds[0][0][-1] if ds[0][0] else '') or ds[0][1].startswith('~')):
            ty = Type('void', 0, '')
        own_cls = cls
        if ds and ds[0][1] is None and ty.base and k < len(hd) and hd[k] == '(':
            # constructor/destructor in class, or free function without return type: name parsed as type
            ds = [([], ty.base, 0, None, False, 0, [])]
            j = k
            dd = 0
            while j < len(hd):
                dd += hd[j] == '('
                dd -= hd[j] == ')'
                j += 1
                if dd == 0:
                    break
            ds = [([], ty.base, 0, hd[k + 1:j - 1], False, 0, hd[j:])]
            qb = ty.base.rsplit('::', 1)
            if len(qb) == 2:
                ds = [([qb[0]], qb[1], 0, hd[k + 1:j - 1], False, 0, hd[j:])]
            ty = Type('void', 0, '')
        if not ds:
            return
        qual, name, ptr, params, fnptr, arrays, rest = ds[0]
        if name is None or params is None:
            return
        if qual:
            qn = '::'.join(qual)
            oc = self.cls(qn, f, cls)
            own_cls = oc.name if oc is not None else (ns + qn if not cls else qn)
            if oc is None:
                own_cls = qn
        kind = 'FUNC'
        short = own_cls.rsplit('::', 1)[-1] if own_cls else None
        if own_cls and name == short:
            kind = 'CONSTRUCTOR'
        elif own_cls and name.startswith('~'):
            kind = 'DESTRUCTOR'
        q = (own_cls + '::' + name) if own_cls else ns + name
        static = 'static' in flags
        virtual = 'virtual' in flags
        ret = self.resolve(Type(ty.base, ptr, ty.spell), f, own_cls)
        oc = self._owner(own_cls, f) if own_cls else None
        if oc is not None:
            ms = oc.methods.get(name)
            if ms:
                if cls is None:      # out-of-line: flags from the in-class declaration
                    static = any(m.static for m in ms)
                    virtual = any(m.virtual for m in ms)
            elif cls is not None and kind == 'FUNC':
                m = Meth(own_cls, name, static, virtual or 'override' in rest, ret, [], f)
                oc.methods.setdefault(name, []).append(m)
            if kind == 'CONSTRUCTOR':
                oc.has_ctor = True
        if oc is not None and not virtual and kind == 'FUNC':
            virtual = self.overrides(oc, name)
        pl = self.param_list(params, f, own_cls)
        if oc is not None and cls is not None and kind == 'FUNC':
            for m in oc.methods.get(name, []):
                if not m.params:
                    m.params = pl
        elif cls is None and own_cls is None:
            self.funcs_decl.setdefault(q, [])
            if not self.funcs_decl[q]:
                self.funcs_decl[q].append(Meth(None, q, static, False, ret, pl, f))
        self.defs.append(Func(q=q, name=name, cls=own_cls, file=f, hdr=f.endswith(HDR_EXT), static=static,
                              virtual=virtual, params=pl, lo=lo + 1, hi=hi, asm=is_asm))

    def _ctor_head(self, hd):
        """`[inline] A::B(...)` / `A::~A(...)` (out of line) -> declarators-style tuple list, else None."""
        j = 0
        while j < len(hd) and hd[j] in ('inline', '__inline', 'explicit'):
            j += 1
        if j >= len(hd) or not isid(hd[j]):
            return None
        names = [hd[j]]
        k = j + 1
        while k + 1 < len(hd) and hd[k] == '::':
            if hd[k + 1] == '~' and k + 2 < len(hd) and isid(hd[k + 2]):
                names.append('~' + hd[k + 2])
                k += 3
            elif isid(hd[k + 1]):
                names.append(hd[k + 1])
                k += 2
            else:
                break
        if len(names) < 2 or k >= len(hd) or hd[k] != '(':
            return None
        if names[-1] != names[-2] and names[-1] != '~' + names[-2]:
            return None
        e = k
        d = 0
        while e < len(hd):
            d += hd[e] == '('
            d -= hd[e] == ')'
            e += 1
            if d == 0:
                break
        return [(names[:-1], names[-1], 0, hd[k + 1:e - 1], False, 0, hd[e:])]

    def overrides(self, c, name, seen=None):
        """virtual when a base declares the method virtual."""
        seen = seen or set()
        for b in c.bases:
            if b in seen:
                continue
            seen.add(b)
            bc = self.classes.get(b)
            if bc is None:
                continue
            if any(m.virtual for m in bc.methods.get(name, ())):
                return True
            if self.overrides(bc, name, seen):
                return True
        return False

    # --- member lookup
    def field(self, cname, name, file=None):
        """-> (declaring class, Type, static) of a data member, searching bases breadth first."""
        seen = set()
        todo = [cname]
        while todo:
            c0 = todo.pop(0)
            if c0 in seen:
                continue
            seen.add(c0)
            c = self.local_classes.get(file, {}).get(c0) if file else None
            c = c or self.classes.get(c0)
            if c is None:
                continue
            v = c.fields.get(name)
            if v is not None:
                return v
            todo.extend(c.bases)
        return None

    def method(self, cname, name, file=None):
        seen = set()
        todo = [cname]
        while todo:
            c0 = todo.pop(0)
            if c0 in seen:
                continue
            seen.add(c0)
            c = self.local_classes.get(file, {}).get(c0) if file else None
            c = c or self.classes.get(c0)
            if c is None:
                continue
            v = c.methods.get(name)
            if v:
                return v
            todo.extend(c.bases)
        return None

# ------------------------------------------------------------------ bodies

    def method_index(self):
        if getattr(self, '_midx', None) is None:
            idx = collections.defaultdict(set)
            for c in self.classes.values():
                for m in c.methods:
                    idx[m].add(c.name)
            self._midx = idx
        return self._midx


    def field_index(self):
        if getattr(self, '_fidx', None) is None:
            idx = collections.defaultdict(set)
            for c in self.classes.values():
                for f, v in c.fields.items():
                    if v[0] == c.name or '(anonymous' in v[0]:
                        idx[f].add(v)
            self._fidx = idx
        return self._fidx


STMT_END = {';', '{', '}'}
NOT_DECL_START = {'return', 'goto', 'case', 'delete', 'throw', 'else', 'do', 'break', 'continue', 'default',
                  'sizeof', 'new', 'this', 'if', 'while', 'for', 'switch'}


class Body:
    """Facts of one function body (libclang facts subset)."""

    def __init__(self, tree, fd):
        self.T = tree
        self.fd = fd
        self.toks = tree.toks[fd.file]
        self.mt = tree.match[fd.file]
        self.file = fd.file
        oc = tree._owner(fd.cls, fd.file) if fd.cls else None
        self.cls = oc.name if oc is not None else None
        self.cpp = not fd.file.endswith('.c')
        self.locals = {nm: ty for nm, ty in fd.params if nm}
        self.fields, self.globals, self.callees = set(), set(), set()   # fields as Declaring::name
        self.call_at = {}           # index of '(' -> Meth or None
        self.this_cast = False      # `this` cast or used in arithmetic
        self.this_args = []         # parameter type spelling ('' unknown) of each call argument that is `this`
        self.skip = set()
        if not fd.asm:
            # the libclang facts walk the body only (no ctor init list)
            self.walk(fd.lo, fd.hi)

    # --- helpers
    def add_callee(self, q):
        self.callees.add(q)

    def is_type_name(self, t):
        if t in BUILTIN:
            return True
        if t in self.locals or not isid(t) or t in KW:
            return False
        return t in self.T.typedefs or self.T.cls(t, self.file, self.cls) is not None

    def type_group(self, a, b):
        """toks[a] == '(' and toks[b] == ')': the group is a type (a cast) -> Type, else None."""
        ts = self.toks[a + 1:b]
        if not ts:
            return None
        k = 0
        while k < len(ts) and ts[k] in ('const', 'volatile', 'struct', 'class', 'union', 'enum', 'unsigned',
                                        'signed'):
            k += 1
        if k >= len(ts):
            return Type('int') if ts[-1] in ('unsigned', 'signed') else None
        if not self.is_type_name(ts[k]):
            return None
        for x in ts[k + 1:]:
            if not (x in ('*', '&', 'const', 'volatile', '::', '<', '>', ',') or isid(x) or x in BUILTIN or
                    x[0].isdigit() or x in ('(', ')', '[', ']')):
                return None
        ty, kk, _ = self.T.parse_type(ts)
        ptr = sum(1 for x in ts[kk:] if x in ('*', '&'))
        return self.T.resolve(Type(ty.base, ptr, ' '.join(ts)), self.file, self.cls)

    def field_of(self, cname, name):
        if cname is None:
            return None
        return self.T.field(cname, name, self.file)

    def method_of(self, cname, name):
        if cname is None:
            return None
        return self.T.method(cname, name, self.file)

    def type_end(self, e, lo, depth=0):
        """Type of the expression whose last token is toks[e]."""
        if e < lo or depth > 12:
            return None
        toks = self.toks
        t = toks[e]
        if t == ')':
            o = self.mt.get(e)
            if o is None or o < lo:
                return None
            p = toks[o - 1] if o - 1 >= lo else ''
            if p == '>':
                # cast<T>(x)
                d = 0
                k = o - 1
                while k >= lo:
                    d += toks[k] == '>'
                    d -= toks[k] == '<'
                    if d == 0:
                        break
                    k -= 1
                if k - 1 >= lo and toks[k - 1] in CASTKW:
                    ts = toks[k + 1:o - 1]
                    ty, kk, _ = self.T.parse_type(ts)
                    ptr = sum(1 for x in ts[kk:] if x in ('*', '&'))
                    return self.T.resolve(Type(ty.base, ptr), self.file, self.cls)
                return None
            if (isid(p) and p not in KW) or p in (')', ']'):
                m = self.call_at.get(o)
                if m is not None:
                    return m.ret if isinstance(m, Meth) else m
                return None
            if o + 1 < e and toks[o + 1] == '(':
                g = self.mt.get(o + 1)
                if g is not None and g < e:
                    ct = self.type_group(o + 1, g)
                    if ct is not None:
                        return ct
            if o + 1 < e and toks[o + 1] == '*':
                r = self.type_end(e - 1, o + 1, depth + 1)
                return r.deref() if r is not None else None
            if o + 1 < e and toks[o + 1] == '&':
                r = self.type_end(e - 1, o + 1, depth + 1)
                return Type(r.base, r.depth + 1) if r is not None else None
            return self.type_end(e - 1, o + 1, depth + 1)
        if t == ']':
            o = self.mt.get(e)
            if o is None:
                return None
            r = self.type_end(o - 1, lo, depth + 1)
            return r.deref() if r is not None else None
        if not isid(t):
            return None
        if t == 'this':
            return Type(self.cls, 1) if self.cls else None
        p = toks[e - 1] if e - 1 >= lo else ''
        if p in ('.', '->'):
            r = self.type_end(e - 2, lo, depth + 1)
            if r is None:
                return None
            fl = self.field_of(r.base, t)
            return fl[1] if fl else None
        if p == '::' and e - 2 >= lo and isid(toks[e - 2]):
            qn = toks[e - 2]
            c = self.T.cls(qn, self.file, self.cls)
            if c is not None:
                fl = self.field_of(c.name, t)
                return fl[1] if fl else None
            return self.T.globals.get(qn + '::' + t)
        if t in self.locals:
            return self.locals[t]
        if self.cls:
            fl = self.field_of(self.cls, t)
            if fl:
                return fl[1]
        return self.T.file_globals[self.file].get(t) or self.T.globals.get(t)

    def enclosing_call(self, j, lo):
        """For toks[j] that is a whole call argument: (index of the call's '(', arg index) or None."""
        toks = self.toks
        if toks[j + 1] not in (',', ')'):
            return None
        k = j - 1
        idx = 0
        while k >= lo:
            t = toks[k]
            if t in (')', ']', '}'):
                k = self.mt.get(k, k) - 1
                continue
            if t == ',':
                idx += 1
            elif t == '(':
                return k, idx
            elif t in ('[', '{', ';', '=') or t in ASSIGN:
                return None
            elif idx == 0 and k == j - 1:
                return None
            k -= 1
        return None

    def walk(self, lo, hi):
        toks = self.toks
        T = self.T
        stmt = True
        j = lo
        cls = self.cls
        while j < hi:
            t = toks[j]
            if j in self.skip:
                j += 1
                stmt = False
                continue
            if t in STMT_END:
                stmt = True
                j += 1
                continue
            if t == '(' and j > lo and toks[j - 1] == 'for':
                stmt = True
                j += 1
                continue
            if not isid(t):
                if t == '=' and self.cpp and j > lo:
                    self.class_assign(j, lo)
                stmt = False
                j += 1
                continue
            if stmt and t not in NOT_DECL_START:
                k = self.local_decl(j, hi)
                stmt = False
                if k is not None:
                    j = k
                    continue
            stmt = False
            if t == 'this':
                self.this_at(j, lo, hi)
                j += 1
                continue
            if t == 'operator' and j + 2 < hi and toks[j + 1] in ('new', 'delete') and toks[j + 2] == '(':
                j += 2          # ::operator delete(p)
                continue
            if t == 'new':
                self.new_at(j, hi)
                j += 1
                continue
            if t in KW:
                j += 1
                continue
            p = toks[j - 1] if j > lo else ''
            nx = toks[j + 1] if j + 1 < hi else ''
            if p in ('.', '->'):
                recv = self.type_end(j - 2, lo)
                if nx == '(':
                    ms = self.method_of(recv.base, t) if recv is not None else None
                    if ms:
                        m = ms[0]
                        self.add_callee(m.cls + '::' + t)
                        self.call_at[j + 1] = m
                    else:
                        fl = self.field_of(recv.base, t) if recv is not None else None
                        if fl:       # call through a function-pointer member
                            self.touch_field(fl, t)
                            self.call_at[j + 1] = None
                        else:
                            self.fallback_call(t, j)
                else:
                    fl = self.field_of(recv.base, t) if recv is not None else None
                    if fl:
                        self.touch_field(fl, t)
                    else:
                        self.fallback_field(t)
                j += 1
                continue
            if p == '::' and j - 2 >= lo and isid(toks[j - 2]):
                j += 1
                continue          # handled at the head of the qualified name
            if nx == '::' and j + 2 < hi and isid(toks[j + 2]):
                k = j
                parts = [t]
                while k + 2 < hi and toks[k + 1] == '::' and isid(toks[k + 2]):
                    k += 2
                    parts.append(toks[k])
                self.qualified(parts, k, lo, hi)
                j = k + 1
                continue
            gscope = p == '::'          # ::name -> global scope only
            if t in self.locals and not gscope:
                if nx == '(':
                    self.call_at[j + 1] = None
                j += 1
                continue
            if cls is not None and not gscope:
                fl = self.field_of(cls, t)
                if fl:
                    self.touch_field(fl, t)
                    j += 1
                    continue
                if nx == '(':
                    ms = self.method_of(cls, t)
                    if ms:
                        m = ms[0]
                        self.add_callee(m.cls + '::' + t)
                        self.call_at[j + 1] = m
                        j += 1
                        continue
            if t in T.globals and nx != '(':
                self.globals.add(t)
                j += 1
                continue
            if nx == '(':
                if t in BUILTIN:
                    j += 1
                    continue
                c = T.cls(t, self.file, cls)
                if c is not None:
                    if self.cpp:
                        self.add_callee(c.name + '::' + c.name.rsplit('::', 1)[-1])
                    self.call_at[j + 1] = Type(c.name, 0)
                    j += 1
                    continue
                if t in T.typedefs:
                    self.call_at[j + 1] = T.resolve(Type(t, 0), self.file, cls)
                    j += 1
                    continue
                if t in T.globals:
                    self.globals.add(t)
                    self.call_at[j + 1] = None
                    j += 1
                    continue
                ds = T.funcs_decl.get(t)
                self.add_callee(t)
                self.call_at[j + 1] = ds[0] if ds else None
                j += 1
                continue
            j += 1

    def chain_start(self, e, lo):
        toks, mt = self.toks, self.mt
        k = e
        while k >= lo:
            t = toks[k]
            if t in (')', ']'):
                o = mt.get(k)
                if o is None or o < lo:
                    return k
                pv = toks[o - 1] if o - 1 >= lo else ''
                if t == ']' or (isid(pv) and pv not in KW) or pv in (')', ']'):
                    k = o - 1
                    continue
                return o
            if isid(t):
                if k - 1 >= lo and toks[k - 1] in ('.', '->', '::'):
                    k -= 2
                    continue
                return k
            return k + 1
        return lo

    def class_assign(self, j, lo):
        """`lhs = rhs` with a class-typed lhs: the (implicit) copy assignment operator is a callee."""
        c = self.class_asg_at(j, lo)
        if c is not None:
            self.add_callee(c.name + '::operator=')

    def class_asg_at(self, j, lo):
        """toks[j] == '=' assigns a class-typed lhs -> the class, else None."""
        if j - 1 in self.skip:          # declarator: initialisation, not assignment
            return None
        ty = self.type_end(j - 1, lo)
        if ty is None:
            return None
        st = self.chain_start(j - 1, lo)
        k = st - 1
        while k >= lo:
            if self.toks[k] == '*':
                ty = ty.deref() if ty.depth else None
                if ty is None:
                    return None
                k -= 1
                continue
            if self.toks[k] == ')':                 # *(T *)p = x
                o = self.mt.get(k)
                ct = self.type_group(o, k) if o is not None and o >= lo else None
                if ct is not None and k - 1 >= lo and o - 1 >= lo and self.toks[o - 1] == '*':
                    ty = ct
                    k = o - 1
                    continue
            break
        if ty.depth or ty.fn:
            return None
        r = self.T.resolve(ty, self.file, self.cls)
        if r is None or r.depth or r.fn:
            return None
        return self.T.cls(r.base, self.file, self.cls)

    def local_decl(self, j, hi):
        """At a statement start: a local declaration? record it and return the index after the type."""
        toks = self.toks
        k = j
        while k < hi and toks[k] in ('const', 'static', 'register', 'volatile', 'struct', 'class', 'union',
                                     'enum', 'unsigned', 'signed', 'typename'):
            k += 1
        if k >= hi:
            return None
        t = toks[k]
        if t not in BUILTIN and (not self.is_type_name(t) or t in self.locals):
            if not (k > j and isid(t) and t not in KW and k + 1 < hi and (isid(toks[k + 1]) or toks[k + 1] == '*')):
                return None
        e = k
        # type tokens
        if t in BUILTIN:
            while e < hi and toks[e] in BUILTIN | {'const', 'volatile'}:
                e += 1
        else:
            e = k + 1
            while e + 1 < hi and toks[e] == '::' and isid(toks[e + 1]):
                e += 2
            if e < hi and toks[e] == '<':
                d = 0
                while e < hi:
                    d += toks[e] == '<'
                    d -= toks[e] == '>'
                    e += 1
                    if d == 0:
                        break
            while e < hi and toks[e] in ('const', 'volatile'):
                e += 1
        # first declarator must be [*&const]* ident followed by = ; , [ ( or a (*fp) group
        q = e
        while q < hi and toks[q] in ('*', '&', 'const', 'volatile'):
            q += 1
        if q >= hi:
            return None
        if toks[q] == '(' and q + 2 < hi and toks[q + 1] == '*':
            pass
        elif not (isid(toks[q]) and toks[q] not in KW and q + 1 < hi and toks[q + 1] in ('=', ';', ',', '[', '(', ':')):
            return None
        ty, _, _ = self.T.parse_type(toks[j:e])
        base = self.T.resolve(Type(ty.base, 0, ' '.join(toks[j:e])), self.file, self.cls)
        # walk declarators
        x = e
        expect = True
        ptr = 0
        while x < hi:
            tt = toks[x]
            if tt in ('(', '[', '{'):
                if expect and tt == '(' and x + 1 < hi and toks[x + 1] == '*':
                    # function pointer local
                    g = self.mt.get(x, x)
                    nm = [toks[y] for y in range(x, g) if isid(toks[y])]
                    if nm:
                        self.declare(nm[-1], Type(base.base, ptr + 1, base.spell, True), x)
                    expect = False
                    x = self.mt.get(x, x) + 1
                    continue
                if tt == '[' and not expect:
                    self._arr_last()
                g = self.mt.get(x)
                if g is None:
                    break
                x = g + 1 if tt != '(' or expect else x + 1
                if tt == '(' and not expect:
                    return self._decl_rest(e, x, hi)      # ctor-style init: let the walk see the args
                continue
            if tt == ';':
                break
            if tt == ',':
                expect = True
                ptr = 0
                x += 1
                continue
            if tt == '=':
                # initializer: walk continues from e; stop declarator collection at the next top-level , or ;
                return self._decl_rest(e, x, hi)
            if expect:
                if tt in ('*', '&'):
                    ptr += 1
                elif isid(tt) and tt not in KW and tt not in ('const', 'volatile'):
                    self.declare(tt, Type(base.base, base.depth + ptr, base.spell, base.fn), x)
                    expect = False
            x += 1
        return x

    _last = None

    def _arr_last(self):
        if self._last is not None:
            nm, ty = self._last
            ty2 = Type(ty.base, ty.depth + 1, ty.spell, ty.fn)
            self.locals[nm] = ty2
            self._last = (nm, ty2)

    def _decl_rest(self, e, x, hi):
        """Declarators after the first initializer: the remaining names get declared as the walk passes."""
        # find the declarator names after top-level commas up to the statement end
        toks = self.toks
        k = x
        while k < hi and toks[k] != ';':
            if toks[k] in ('(', '[', '{'):
                k = self.mt.get(k, k) + 1
                continue
            if toks[k] == ',':
                q = k + 1
                ptr = 0
                while q < hi and toks[q] in ('*', '&', 'const'):
                    ptr += toks[q] != 'const'
                    q += 1
                if q < hi and isid(toks[q]) and toks[q] not in KW and q + 1 < hi and \
                        toks[q + 1] in ('=', ';', ',', '['):
                    last = self._last
                    bt = last[1] if last else Type(None)
                    self.declare(toks[q], Type(bt.base, ptr, bt.spell), q)
            k += 1
        return x

    def declare(self, nm, ty, idx):
        self.locals[nm] = ty
        self.skip.add(idx)
        self._last = (nm, ty)
        if self.cpp and ty.depth == 0 and ty.base and not ty.fn and not (
                idx + 2 < len(self.toks) and self.toks[idx + 1] == '=' and self.toks[idx + 2] == '{'):
            c = self.T.cls(ty.base, self.file, self.cls)
            if c is not None and c.kind != 'union' or (c is not None and c.has_ctor):
                self.add_callee(c.name + '::' + c.name.rsplit('::', 1)[-1])

    def qualified(self, parts, k, lo, hi):
        """A::B::c at toks[k] == c."""
        T = self.T
        toks = self.toks
        last = parts[-1]
        qn = '::'.join(parts[:-1])
        nx = toks[k + 1] if k + 1 < hi else ''
        c = T.cls(qn, self.file, self.cls)
        if nx == '(':
            if c is not None:
                if last == c.name.rsplit('::', 1)[-1]:
                    self.add_callee(c.name + '::' + last)
                    self.call_at[k + 1] = Type(c.name, 0)
                    return
                ms = self.method_of(c.name, last)
                if ms:
                    m = ms[0]
                    self.add_callee(m.cls + '::' + last)
                    self.call_at[k + 1] = m
                    return
                self.add_callee(c.name + '::' + last)
                self.call_at[k + 1] = None
                return
            q = qn + '::' + last
            ds = T.funcs_decl.get(q)
            self.add_callee(q)
            self.call_at[k + 1] = ds[0] if ds else None
            return
        if c is not None:
            fl = self.field_of(c.name, last)
            if fl:
                self.touch_field(fl, last)
            return        # else an enumerator / nested type
        g = qn + '::' + last
        if g in T.globals:
            self.globals.add(g)

    def touch_field(self, fl, name):
        dc, _, static = fl
        (self.globals if static else self.fields).add(dc + '::' + name)

    def fallback_call(self, t, j):
        idx = self.T.method_index()
        cs = idx.get(t)
        if cs and len(cs) == 1:
            c = next(iter(cs))
            m = self.T.classes[c].methods[t][0]
            self.add_callee(c + '::' + t)
            self.call_at[j + 1] = m
        else:
            self.call_at[j + 1] = None

    def fallback_field(self, t):
        cs = self.T.field_index().get(t)
        if cs and len(cs) == 1:
            self.touch_field(next(iter(cs)), t)

    def this_at(self, j, lo, hi):
        toks = self.toks
        p = toks[j - 1] if j > lo else ''
        nx = toks[j + 1] if j + 1 < hi else ''
        path = False
        if p == ')' and nx not in ('->', '.'):     # `(T)this->x` casts the member, not `this`
            o = self.mt.get(j - 1)
            if o is not None and self.type_group(o, j - 1) is not None:
                path = True
        if p == '(' and j - 2 >= lo and toks[j - 2] == '>':
            # xxx_cast<T>(this)
            k = j - 2
            d = 0
            while k >= lo:
                d += toks[k] == '>'
                d -= toks[k] == '<'
                if d == 0:
                    break
                k -= 1
            if k - 1 >= lo and toks[k - 1] in CASTKW:
                path = True
        if nx in ('+', '-') or p in ('+', '?'):
            path = True
        if path:
            self.this_cast = True
            return
        ec = self.enclosing_call(j, lo)
        if ec is not None:
            o, idx = ec
            m = self.call_at.get(o)
            self.this_args.append(m.params[idx][1].spell or '' if isinstance(m, Meth) and idx < len(m.params) else '')

    def new_at(self, j, hi):
        toks = self.toks
        k = j + 1
        if k < hi and toks[k] == '(':
            k = self.mt.get(k, k) + 1          # placement new
        while k < hi and toks[k] in ('struct', 'class', 'const'):
            k += 1
        if k >= hi or not isid(toks[k]):
            return
        c = self.T.cls(toks[k], self.file, self.cls)
        if c is not None and self.cpp:
            e = k + 1
            has_args = e < hi and toks[e] == '('
            self.add_callee(c.name + '::' + c.name.rsplit('::', 1)[-1])
            if has_args:
                self.call_at[e] = Type(c.name, 0)
                self.skip.add(k)

    def row(self):
        fd = self.fd
        return {'q': fd.q, 'name': fd.name, 'cls': fd.cls, 'file': fd.file, 'hdr': fd.hdr, 'static': fd.static,
                'virtual': fd.virtual, 'fields': self.fields, 'globals': self.globals, 'callees': self.callees,
                'this_cast': self.this_cast, 'this_args': self.this_args}


# --- misowned_member: the rule over the scanner's facts -------------------------------------------------------------
#
# A config function named Cls::f (CodeWarrior-mangled f__<n>ClsF...) is in the wrong class when its body (outside
# headers, not virtual) touches no field of Cls's hierarchy, under a quarter of its callers belong to that hierarchy,
# its unit is not named after Cls, and nothing else explains the placement: the unit holds Cls's name or vtable
# (HOME_UNIT), it constructs a Cls (SELF_FACTORY), it is a small function placed after its only callers
# (INLINE_PLACEMENT, INLINE_TAIL), it passes or calls through this (THIS_USED), or the globals it uses are Cls's own
# (OWN_GLOBAL). A cast of this keeps it debt; so does a function at the edge of its unit next to the class's home
# unit (UNIT_BOUNDARY).

_OWNER_SYMBOL = re.compile(r"^(\S+) = (\S+):0x([0-9A-Fa-f]+);(?: // (.*))?$")
_SPLIT_UNIT = re.compile(r"^(\S.*):\s*$")
_SPLIT_RANGE = re.compile(r"^\s+(\S+)\s+start:0x([0-9A-Fa-f]+)\s+end:0x([0-9A-Fa-f]+)")
_DATA_MEMBER = re.compile(r"^(\w+?)__(\d+)(\w+)$")
_OWNER_DEBT = ("OWNER_DEBT", "UNIT_BOUNDARY")


def _member_of(name: str) -> tuple[str | None, str | None]:
    """(class, base name) of a mangled single-level member function, else (None, None)."""
    m = _MEMBER.search(name)
    if not m or len(m[2]) <= int(m[1]) or not m[2][int(m[1]):].startswith(("F", "CF")):
        return None, None
    return m[2][:int(m[1])], name[:m.start()]


def _closure(start: str, graph) -> set[str]:
    seen, todo = set(), [start]
    while todo:
        for y in graph.get(todo.pop(), ()):
            if y not in seen:
                seen.add(y)
                todo.append(y)
    return seen


def _named_after(cls: str, unit: str | None) -> bool:
    name = (unit or "").rsplit("/", 1)[-1]
    return name.startswith(cls + "_") or name == cls + ".cpp"


def _misowned(rows: list[dict], bases: dict[str, set[str]], symbols_text: str,
              splits_text: str) -> list[tuple[dict, str, int]]:
    """(body row, category, nth body of its name in its file) of each member judged in the wrong class, in
    symbols.txt order."""
    units, ranges, unit = [], collections.defaultdict(list), None   # .text units by address; every unit's ranges
    for line in splits_text.split("\n"):
        m = _SPLIT_UNIT.match(line)
        if m and not line.startswith("Sections"):
            unit = m[1]
            continue
        m = _SPLIT_RANGE.match(line)
        if m and unit:
            ranges[unit].append((m[1], int(m[2], 16), int(m[3], 16)))
            if m[1] == ".text":
                units.append((int(m[2], 16), int(m[3], 16), unit))
    units.sort()
    starts = [u[0] for u in units]

    def unit_of(a: int) -> str | None:
        i = bisect.bisect_right(starts, a) - 1
        return units[i][2] if i >= 0 and a < units[i][1] else None

    funcs, data = [], []
    for line in symbols_text.split("\n"):
        m = _OWNER_SYMBOL.match(line.strip())
        if not m:
            continue
        a, rest = int(m[3], 16), m[4] or ""
        if m[2] == ".text" and "type:function" in rest:
            size = re.search(r"size:0x([0-9A-Fa-f]+)", rest)
            funcs.append((m[1], a, int(size[1], 16) if size else 0, *_member_of(m[1]), unit_of(a)))
        else:
            data.append((m[1], m[2], a))
    by_unit, by_cls, by_key = (collections.defaultdict(list) for _ in range(3))
    for f in funcs:
        by_unit[f[5]].append(f)
        if f[3]:
            by_cls[f[3]].append(f)
        by_key[(f[3], f[4] if f[3] else f[0])].append(f)
    for fs in by_unit.values():
        fs.sort(key=lambda f: f[1])
    index = {u[2]: i for i, u in enumerate(units)}
    spans = sorted((lo, hi, sec, u) for u, rs in ranges.items() for sec, lo, hi in rs if sec != ".text")
    span_starts = [s[0] for s in spans]
    unit_data = collections.defaultdict(set)   # unit -> the data symbols in its sections
    for name, sec, a in data:
        i = bisect.bisect_right(span_starts, a) - 1
        if i >= 0 and a < spans[i][1] and spans[i][2] == sec:
            unit_data[spans[i][3]].add(name)
    data_unit = {}   # data symbol (and Cls::name for a mangled static member) -> its unit
    for u, names in unit_data.items():
        for n in names:
            data_unit[n] = u
            m = _DATA_MEMBER.match(n)
            if m and len(m[3]) == int(m[2]):
                data_unit[f"{m[3]}::{m[1]}"] = u

    derived = collections.defaultdict(set)
    for c, bs in bases.items():
        for b in bs:
            derived[b].add(c)
    body, every, callers = {}, collections.defaultdict(list), collections.defaultdict(set)
    for r in rows:
        body[r["q"]] = r   # the last body of a name, unless its own unit's is picked below
        every[r["q"]].append(r)
        for c in r["callees"]:
            callers[c].add((r["q"], r["cls"]))

    def caller_addresses(q: str) -> list[int]:
        return [f[1] for cq, ccls in callers.get(q, ()) for f in
                by_key.get((ccls, cq.rsplit("::", 1)[-1]) if ccls else (None, cq), ())]

    def category(cls: str, base: str, a: int, size: int, unit: str, home: str, r: dict) -> str:
        own_data = (f"{cls}__name", f"__vt__{len(cls)}{cls}")
        if any(n in unit_data.get(unit, ()) for n in own_data):
            return "HOME_UNIT"
        if any("::" in c and c.rsplit("::", 1)[0] == cls and c.rsplit("::", 1)[1] == cls.rsplit("::", 1)[-1]
               for c in r["callees"]):
            return "SELF_FACTORY"
        calls = caller_addresses(f"{cls}::{base}")
        if calls and size <= 0x60 and all(unit_of(x) == unit for x in calls) and min(calls) < a:
            return "INLINE_PLACEMENT"
        fs, i = by_unit.get(unit, []), index.get(unit)
        if fs and i is not None and (fs[0][1] == a and i > 0 and units[i - 1][2] == home or
                                     fs[-1][1] == a and i + 1 < len(units) and units[i + 1][2] == home):
            return "UNIT_BOUNDARY"
        if r["this_cast"]:
            return "OWNER_DEBT"
        if not r["static"]:
            narrow, up = {cls} | _closure(cls, derived), {cls} | _closure(cls, bases)
            if any(re.search(rf"\b{re.escape(c)}\b", pt) for pt in r["this_args"] for c in narrow) or \
                    any("::" in c and c.rsplit("::", 1)[0] in up and not (body.get(c) or {}).get("static", False)
                        for c in r["callees"]):
                return "THIS_USED"
        if r["globals"]:
            homes = {home} | {u for u in ranges if _named_after(cls, u)} | \
                {u for u, names in unit_data.items() if any(n in names for n in own_data)}
            if all(g.startswith((cls + "::", cls + "__")) or data_unit.get(g) in homes for g in r["globals"]):
                return "OWN_GLOBAL"
        if calls and size <= 0x40 and min(calls) < a and unit_of(min(calls)) == unit:
            return "INLINE_TAIL"
        return "OWNER_DEBT"

    homes = {c: collections.Counter(f[5] for f in fs).most_common(1)[0][0] for c, fs in by_cls.items()}
    out = []
    for _, a, size, cls, base, unit in funcs:
        if not cls or not unit or base.startswith("__"):
            continue
        q = f"{cls}::{base}"
        if len(every.get(q, ())) > 1:   # overloads: judge the body in the function's own unit (kept for later lookups)
            own = [r for r in every[q] if r["file"] == "src/" + unit]
            if own:
                body[q] = own[-1]
        r = body.get(q)
        if r is None or r["virtual"] or _named_after(cls, unit):
            continue
        hierarchy = {cls} | _closure(cls, bases) | _closure(cls, derived)
        if {f.rsplit("::", 1)[0] for f in r["fields"]} & hierarchy:
            continue
        cs = callers.get(q, set())
        if cs and sum(c[1] in hierarchy for c in cs) / len(cs) >= 0.25:
            continue
        cat = category(cls, base, a, size, unit, homes[cls], r)
        if cat in _OWNER_DEBT:
            same = [x for x in every[q] if x["file"] == r["file"]]
            out.append((r, cat, next(i for i, x in enumerate(same) if x is r)))
    return out


def _definition_line(stripped: str, r: dict, nth: int) -> int:
    """1-based line of the nth definition of r's function in the file (comments and strings stripped)."""
    name = re.escape(r["name"])
    if r["name"].startswith("operator"):
        name = r"operator\s*" + re.escape(r["name"][8:].strip())
    cls = r["cls"].rsplit("::", 1)[-1] if r["cls"] else None
    lo, patterns = 0, []
    if cls:
        patterns.append((rf"\b{re.escape(cls)}\s*::\s*{name}\s*\(", 0))
        m = re.search(rf"\b(?:class|struct|union)\s+{re.escape(cls)}\b[^;{{}}]*\{{", stripped)
        if m:
            lo = m.end()
    patterns.append((rf"(?<![\w:.>~]){name}\s*\(", lo))
    for pattern, start in patterns:
        hits = []
        for m in re.finditer(pattern, stripped[start:]):
            k, depth = start + m.end(), 1
            while k < len(stripped) and depth:
                depth += {"(": 1, ")": -1}.get(stripped[k], 0)
                k += 1
            if re.match(r"\s*(?:(?:const|volatile|override|noexcept|throw\s*\(\s*\))\s*)*(?::[^;{}]*)?\{",
                        stripped[k:k + 400]):
                hits.append(stripped.count("\n", 0, start + m.start()) + 1)
        if hits:
            return hits[min(nth, len(hits) - 1)]
    return 1


def misowned_members(texts: dict[str, str], pairs: Iterable[tuple[str, str]],
                     counted: Container[str]) -> dict[str, list[Finding]]:
    """misowned_member findings by file, for the files in `counted`: texts are every C/C++ file of the revision
    (src/, include/ and libs/), pairs its (symbols.txt, splits.txt) texts."""
    tree = Tree({rel: text for rel, text in texts.items() if rel.endswith(SRC_EXT + HDR_EXT)})
    rows = [Body(tree, d).row() for d in tree.defs if not d.hdr]
    bases = {c.name: set(c.bases) for c in tree.classes.values()}
    found, stripped = set(), {}
    for symbols_text, splits_text in pairs:
        for r, cat, nth in _misowned(rows, bases, symbols_text, splits_text):
            rel, cls = r["file"], r["q"].rsplit("::", 1)[0]
            if rel not in counted:
                continue
            if rel not in stripped:
                stripped[rel] = _strip(texts[rel])
            found.add((rel, _definition_line(stripped[rel], r, nth),
                       f"{r['q']} touches nothing of {cls}'s hierarchy and few callers belong to it: "
                       f"likely the wrong owner class ({cat})"))
    out = collections.defaultdict(list)
    for rel, line, text in sorted(found):
        out[rel].append(Finding("misowned_member", text, line))
    return dict(out)


# --- reading revisions -------------------------------------------------------------------------------------------

class Repo:
    def __init__(self, git_dir: str | None):
        self.prefix = ["git", "-c", "core.quotePath=false", *(["--git-dir", git_dir] if git_dir else ["-C", str(ROOT)])]
        self.bare = bool(git_dir)

    def git(self, *args: str, check: bool = True) -> bytes:
        result = subprocess.run([*self.prefix, *args], capture_output=True)
        if check and result.returncode:
            raise SystemExit(f"git {' '.join(args)}: {result.stderr.decode(errors='replace').strip()}")
        return result.stdout

    def exists(self, rev: str) -> bool:
        return subprocess.run([*self.prefix, "rev-parse", "--verify", "--quiet", rev + "^{commit}"],
                              capture_output=True).returncode == 0

    def commit(self, rev: str) -> str | None:
        if rev == WORKTREE:
            return None
        return self.git("rev-parse", "--verify", rev + "^{commit}").decode().strip()

    def files(self, rev: str, roots: Iterable[str], keep=lambda rel: True,
              limit: int | None = MAX_FILE) -> Iterator[tuple[str, str]]:
        """(path, text) of every file under roots at a revision, or in the working tree (files over limit skipped)."""
        limit = limit or float("inf")
        if rev == WORKTREE:
            listing = self.git("ls-files", "-z", "-c", "-o", "--exclude-standard", "--", *roots)
            for rel in sorted(set(listing.decode("utf-8", "surrogateescape").split("\0")) - {""}):
                path = ROOT / rel
                if keep(rel) and path.is_file() and path.stat().st_size <= limit:
                    yield rel, path.read_text(encoding="utf-8", errors="replace")
            return
        blobs = []
        for entry in self.git("ls-tree", "-r", "-z", "-l", rev, "--", *roots).split(b"\0"):
            meta, _, name = entry.partition(b"\t")
            parts = meta.split()
            rel = name.decode("utf-8", "surrogateescape")
            if len(parts) == 4 and parts[1] == b"blob" and keep(rel) and parts[3].isdigit() \
                    and int(parts[3]) <= limit:
                blobs.append((rel, parts[2]))
        yield from self.blobs(blobs)

    def blobs(self, blobs: list[tuple[str, bytes]]) -> Iterator[tuple[str, str]]:
        if not blobs:
            return
        process = subprocess.Popen([*self.prefix, "cat-file", "--batch"], stdin=subprocess.PIPE,
                                   stdout=subprocess.PIPE)
        assert process.stdin and process.stdout
        feeder = threading.Thread(target=lambda: (process.stdin.write(b"".join(o + b"\n" for _, o in blobs)),
                                                  process.stdin.close()), daemon=True)
        feeder.start()
        for rel, _ in blobs:
            header = process.stdout.readline().split()
            if len(header) < 3:
                continue
            data = process.stdout.read(int(header[2]))
            process.stdout.read(1)
            yield rel, data.decode("utf-8", errors="replace")
        feeder.join()
        process.stdout.close()
        process.wait()

    def paths(self, rev: str, roots: Iterable[str]) -> list[str]:
        """Every file path under roots at a revision, or in the working tree."""
        if rev == WORKTREE:
            out = self.git("ls-files", "-z", "-c", "-o", "--exclude-standard", "--", *roots)
        else:
            out = self.git("ls-tree", "-r", "-z", "--name-only", rev, "--", *roots)
        return sorted(set(out.decode("utf-8", "surrogateescape").split("\0")) - {""})

    def read(self, rev: str, paths: list[str], limit: int | None = MAX_FILE) -> dict[str, str]:
        """{path: text} of the given paths at a revision (missing paths left out)."""
        wanted = set(paths)
        roots = sorted(wanted) if len(wanted) <= 500 else sorted({p.split("/", 1)[0] for p in wanted})
        return dict(self.files(rev, roots, keep=lambda rel: rel in wanted, limit=limit)) if wanted else {}

    def diff(self, base: str, head: str, roots: Iterable[str]) -> tuple[list[str], dict[str, list[Hunk]]]:
        """Paths changed between base and head, and the hunks of each: (lines base removed, lines head added)."""
        args = ["diff", "-U0", "--text", "--no-renames", "--no-color", "--no-ext-diff", base]
        if head != WORKTREE:
            args.append(head)
        out = self.git(*args, "--", *roots).decode("utf-8", "surrogateescape")
        hunks: dict[str, list[Hunk]] = {}
        changed, current, header, old = [], None, False, None
        for line in out.splitlines():
            if line.startswith("diff --git "):
                current, header, old = None, True, None
            elif header and line.startswith("--- "):   # ---/+++ are headers only before the first @@
                old = _diff_path(line[4:])
            elif header and line.startswith("+++ "):
                current = _diff_path(line[4:]) or old
                changed.append(current)
                hunks.setdefault(current, [])
            elif line.startswith("@@") and current is not None:
                header = False
                hunk = re.match(r"@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@", line)
                if hunk:
                    old_at, old_n, new_at, new_n = (int(n) if n is not None else 1 for n in hunk.groups())
                    hunks[current].append((range(old_at, old_at + old_n), range(new_at, new_at + new_n)))
        if head == WORKTREE:
            untracked = self.git("ls-files", "-z", "-o", "--exclude-standard", "--", *roots)
            for rel in untracked.decode("utf-8", "surrogateescape").split("\0"):
                if rel and (ROOT / rel).is_file():
                    changed.append(rel)
                    lines = len((ROOT / rel).read_text(errors="replace").splitlines())
                    hunks[rel] = [(range(0), range(1, lines + 2))]
        return sorted(set(changed)), hunks


def _diff_path(field: str) -> str | None:
    """The path of a diff's ---/+++ line less its a/ or b/ (None for /dev/null). Git quotes a path holding special
    characters and ends one holding a space with a tab."""
    field = field.rstrip("\t")
    if field == "/dev/null":
        return None
    if len(field) > 1 and field[0] == field[-1] == '"':
        field = field[1:-1]
    return field[2:]


def source_file(rel: str) -> bool:
    return Path(rel).suffix.lower() in SOURCE_SUFFIXES


# --- symbols.txt and config.yml -------------------------------------------------------------------------------

_SYMBOL = re.compile(r"^(\S+)\s*=\s*([.\w]+):(0x[0-9A-Fa-f]+);\s*//(.*)$")
_PLACEHOLDER = re.compile(r"(?:^|_)(?:fn|func|sub|lbl|FUN|DAT|PTR|dat)_[0-9A-Fa-f]{6,16}|_[0-9A-Fa-f]{8}(?:_|$)|"
                          r"__(?:sub|data)_[0-9A-Fa-f]{6,16}")
_SLOT = re.compile(r"\bvfunc_?\d+(?!\d)|^vf\d+$|__vt\d+(?!\d)")
_FLAT = BY_KEY["flat_name"].regex
_MEMBER = re.compile(r"__(\d+)([A-Za-z_]\w*)")   # CodeWarrior's member mangling: name__<length><class>...


def symbols(text: str) -> dict[tuple[str, int], tuple[str, str]]:
    out = {}
    for line in text.splitlines():
        match = _SYMBOL.match(line.strip())
        if match:
            kind = re.search(r"\btype:(\w+)", match[4])
            out[(match[2], int(match[3], 16))] = (match[1], kind[1] if kind else "")
    return out


def name_flags(name: str, kind: str) -> list[str]:
    flags = []
    if _FLAT.fullmatch(name):
        prefix, method = name.split("__", 1)
        flags.append(f"flat C name (as a member of {prefix}: {method}__{len(prefix)}{prefix}"
                     f"{'F...' if kind == 'function' else ''})")
    owner, member = None, _MEMBER.search(name)
    if member and int(member[1]) <= len(member[2]):
        owner = member[2][:int(member[1])]
        if not any(IMAGE[0] <= int(m[1], 16) < IMAGE[1] for m in _UNIT_ADDRESS.finditer(owner)):
            owner = None
    if _PLACEHOLDER.search(name.replace(owner, "", 1) if owner else name):
        flags.append("named after its address")
    if _SLOT.search(name):
        flags.append("named after a vtable slot")
    if owner:
        flags.append(f"member of {owner}, a class named after an address")
    return flags


def force_active(text: str) -> list[str]:
    block = re.search(r"^force_active:\n((?:[ \t]*(?:-.*)?\n|[ \t]*#.*\n)*)", text, re.M)
    return [] if not block else [x.strip().strip("\"'") for x in re.findall(r"^\s*-\s*(.+?)\s*$", block[1], re.M)]


_CONFIG_PATHS = re.compile(r"^(symbols|splits):\s*(\S+)", re.M)
_SPLIT_TEXT = re.compile(r"^\s+\.text\s+start:(0x[0-9A-Fa-f]+)\s+end:(0x[0-9A-Fa-f]+)")


def split_units(text: str) -> list[tuple[int, int, str]]:
    """(start, end, unit) of every unit's .text in a splits.txt, sorted."""
    out, unit = [], None
    for line in text.splitlines():
        if line and not line[0].isspace() and line.endswith(":"):
            unit = line[:-1]
        elif unit:
            found = _SPLIT_TEXT.match(line)
            if found:
                out.append((int(found[1], 16), int(found[2], 16), unit))
    return sorted(out)


def _unit_at(units: list[tuple[int, int, str]], starts: list[int], address: int) -> str | None:
    index = bisect.bisect_right(starts, address) - 1
    return units[index][2] if index >= 0 and units[index][0] <= address < units[index][1] else None


_MIDDLEWARE = re.compile(r"^MIDDLEWARE\b[^=\n]*=\s*\[.*?(0x[0-9A-Fa-f]+)", re.M | re.S)
_MIDDLEWARE_END = re.compile(r"^MIDDLEWARE_END\s*=\s*(0x[0-9A-Fa-f]+)", re.M)


def middleware(configure: str) -> tuple[int, int] | None:
    """Where configure.py links its prebuilt C libraries: from the first start in its MIDDLEWARE list to
    MIDDLEWARE_END (None when it does not say)."""
    start, end = _MIDDLEWARE.search(configure), _MIDDLEWARE_END.search(configure)
    return (int(start[1], 16), int(end[1], 16)) if start and end else None


@dataclass
class Config:
    linkage: dict[str, set[str]]   # function name -> the units defining it
    middleware: set[str] = dataclasses.field(default_factory=set)   # units of the prebuilt C libraries
    pairs: list[tuple[str, str]] = dataclasses.field(default_factory=list)   # (symbols.txt, splits.txt) texts

    def cxx_linkage(self, name: str) -> bool:
        """True when a C++ unit, and no C unit, defines the function. A middleware unit is never C++: the
        libraries are C, whatever the unit's file is called."""
        units = self.linkage.get(name, ())
        return any(Path(u).suffix.lower() in CPP_SUFFIXES and u not in self.middleware for u in units) and \
            not any(Path(u).suffix.lower() == ".c" for u in units)


def read_config(repo: "Repo", rev: str) -> Config:
    """Every config.yml's symbols.txt and splits.txt at a revision: which unit defines each function, and which
    units start in configure.py's middleware range."""
    configs = [p for p in repo.paths(rev, ["config"]) if p.endswith("config.yml")]
    pairs = []
    for text in repo.read(rev, configs, None).values():
        paths = dict(_CONFIG_PATHS.findall(text))
        if "symbols" in paths:
            pairs.append((paths["symbols"], paths.get("splits")))
    texts = repo.read(rev, sorted({p for pair in pairs for p in pair if p}), None)
    config = Config(collections.defaultdict(set))
    libraries = middleware(repo.read(rev, ["configure.py"], None).get("configure.py", ""))
    for symbols_path, splits_path in sorted(set(pairs)):
        config.pairs.append((texts.get(symbols_path, ""), texts.get(splits_path, "") if splits_path else ""))
        units = split_units(texts.get(splits_path, "")) if splits_path else []
        starts = [u[0] for u in units]
        if libraries:
            config.middleware.update(unit for start, _, unit in units if libraries[0] <= start < libraries[1])
        for line in texts.get(symbols_path, "").splitlines():
            match = _SYMBOL.match(line.strip())
            if not match or match[2] != ".text" or not re.search(r"\btype:function\b", match[4]):
                continue
            unit = _unit_at(units, starts, int(match[3], 16))
            if unit:
                config.linkage[match[1]].add(unit)
    return config


def config_review(repo: Repo, base: str, head: str, changed: list[str] | None = None) -> dict:
    """Symbols the change renamed or added (flagged when the name is flat or still a placeholder), and
    force_active entries the change left naming no symbol (added, or stale after a rename)."""
    if changed is None:
        changed, _ = repo.diff(base, head, ["config"])
    renames, added, stale = [], [], []
    cache: dict[tuple[str, str], str] = {}

    def text(rev: str, path: str) -> str:
        if (rev, path) not in cache:
            cache[(rev, path)] = repo.read(rev, [path], None).get(path, "")
        return cache[(rev, path)]

    for path in changed:
        if not path.endswith("symbols.txt"):
            continue
        before, after = symbols(text(base, path)), symbols(text(head, path))
        for key, (name, kind) in sorted(after.items(), key=lambda item: item[0][1]):
            old = before.get(key)
            where = {"file": path, "section": key[0], "address": f"0x{key[1]:08X}", "type": kind}
            flags = name_flags(name, kind)
            if old and old[0] != name:
                renames.append({**where, "old": old[0], "new": name, "flags": flags})
            elif not old and flags:
                added.append({**where, "name": name, "flags": flags})

    configs = {p for p in changed if p.endswith("config.yml")}
    if any(p.endswith("symbols.txt") for p in changed):
        configs.update(p for p in repo.paths(head, ["config"]) if p.endswith("config.yml"))
    for path in sorted(configs):
        def unresolved(rev: str) -> set[str]:
            config = text(rev, path)
            symbols_path = re.search(r"^symbols:\s*(\S+)", config, re.M)
            if not symbols_path:
                return set()
            names = {n for n, _ in symbols(text(rev, symbols_path[1])).values()}
            return {n for n in force_active(config) if n not in names}
        stale += [{"file": path, "name": n} for n in sorted(unresolved(head) - unresolved(base))]
    return {"renames": renames, "added_symbols": added, "stale_force_active": stale}


# --- comparing two revisions --------------------------------------------------------------------------------------

OWNERSHIP_TITLE = "Members in the wrong class (not in the total)"


def _row(key: str) -> dict:
    if key in OWNERSHIP:
        return {"key": key, "name": OWNERSHIP[key][0], "example": OWNERSHIP[key][1], "group": "ownership",
                "category": OWNERSHIP_TITLE}
    p = BY_KEY[key]
    return {"key": key, "name": p.name, "example": p.example, "group": p.group, "category": GROUPS[p.group]}


def library(texts: Iterable[tuple[str, str]]) -> dict[str, list]:
    """signatures() of library files (LIBRARY_ROOTS)."""
    return {rel: signatures(_Blanked(text)) for rel, text in texts if source_file(rel)}


def counted(rel: str) -> bool:
    """True for files under SOURCE_ROOTS (the ones counted), False for library files."""
    return rel.split("/", 1)[0] in SOURCE_ROOTS


def tree_report(repo: Repo, rev: str, top: int) -> dict:
    texts = dict(repo.files(rev, (*SOURCE_ROOTS, *LIBRARY_ROOTS), keep=source_file))
    scans = {rel: scan_file(rel, text) for rel, text in texts.items() if counted(rel)}
    config = read_config(repo, rev)
    related = relations(scans, config, library((rel, t) for rel, t in texts.items() if not counted(rel)),
                        misowned_members(texts, config.pairs, scans))
    totals, per_file = collections.Counter(), {}
    for rel, scan in scans.items():
        found = related.get(rel, [])
        totals.update(scan.counts)
        totals.update(f.key for f in found)
        per_file[rel] = sum(scan.counts.values()) + sum(f.key not in OWNERSHIP for f in found)   # debt only
    return {"revision": rev, "files": len(scans), "total": sum(totals[p.key] for p in CATALOG),
            "categories": [{**_row(p.key), "count": totals[p.key]} for p in CATALOG],
            "ownership": [{**_row(k), "count": totals[k]} for k in OWNERSHIP],
            "worst_files": [{"path": rel, "count": n} for rel, n in
                            sorted(per_file.items(), key=lambda item: -item[1])[:top] if n]}


def _multiset(scans: Iterable[FileScan]) -> collections.Counter:
    out = collections.Counter()
    for scan in scans:
        out.update(scan.texts)
    return out


def _placed(counts: collections.Counter, found: list[tuple[str, Finding]]) -> list[tuple[str, Finding]]:
    """The findings in `found` (taken in path and line order) that account for `counts`, a multiset of identities."""
    left, out = collections.Counter(counts), []
    for rel, f in sorted(found, key=lambda item: (item[0], item[1].line)):
        if left[identity(f)] > 0:
            left[identity(f)] -= 1
            out.append((rel, f))
    return out


def _hunk(hunks: dict[str, list[Hunk]], rel: str, line: int, side: int) -> int | None:
    """The hunk of rel holding line among the lines base removed (side 0) or head added (side 1)."""
    found = hunks.get(rel, ())
    index = bisect.bisect_right(found, line, key=lambda hunk: hunk[side].start) - 1   # sorted, disjoint per side
    return index if index >= 0 and line in found[index][side] else None


def compare(repo: Repo, base: str, head: str) -> dict:
    changed, hunks = repo.diff(base, head, SOURCE_ROOTS)
    config_changed, _ = repo.diff(base, head, ["config"])
    head_config = read_config(repo, head)
    changed = {p for p in changed if source_file(p)}
    base_text = repo.read(base, sorted(changed))
    head_files = dict(repo.files(head, (*SOURCE_ROOTS, *LIBRARY_ROOTS), keep=source_file))
    head_text, head_scans = {}, {}   # the whole head tree, for totals and the class map
    for rel, text in head_files.items():
        if not counted(rel):
            continue
        head_scans[rel] = scan_file(rel, text, keep=rel in changed)
        if rel in changed:
            head_text[rel] = text
    base_changed = {rel: scan_file(rel, text, keep=True) for rel, text in base_text.items()}
    base_scans = {rel: s for rel, s in head_scans.items() if rel not in head_text}
    base_scans.update(base_changed)
    library_changed = set(repo.diff(base, head, LIBRARY_ROOTS)[0])
    library_text = {rel: t for rel, t in repo.read(base, sorted(library_changed)).items() if source_file(rel)}
    head_library = library((rel, t) for rel, t in head_files.items() if not counted(rel))
    base_library = {rel: s for rel, s in head_library.items() if rel not in library_changed}
    base_library.update(library(library_text.items()))
    base_files = {rel: t for rel, t in head_files.items() if rel not in changed and rel not in library_changed}
    base_files.update(base_text)
    base_files.update(library_text)
    base_config = read_config(repo, base) if config_changed else head_config

    # Whole-tree totals: head counted directly, base = head with the changed files swapped back.
    head_totals, base_totals = collections.Counter(), collections.Counter()
    for scan in head_scans.values():
        head_totals.update(scan.counts)
    for scan in base_scans.values():
        base_totals.update(scan.counts)
    # extern "C" in headers is judged against the head's config on both sides, so only header edits move it. A
    # member's class is judged against each side's own config, since a rename changes symbols.txt and source together.
    head_own = relations(head_scans, head_config, head_library,
                         misowned_members(head_files, head_config.pairs, head_scans))
    base_own = relations(base_scans, head_config, base_library,
                         misowned_members(base_files, base_config.pairs, base_scans))
    for found in head_own.values():
        head_totals.update(f.key for f in found)
    for found in base_own.values():
        base_totals.update(f.key for f in found)

    # Added and removed: the change's findings as a multiset of (category, text), so code that only moves
    # (between functions or files) cancels out. Findings across files can change in files the change did not
    # touch (a class gained or lost a base, a class's other copy went away), so they are compared over the whole
    # tree.
    after = _multiset(head_scans[rel] for rel in head_text)
    before = _multiset(base_changed.values())
    for rel, found in head_own.items():
        after.update(map(identity, found))
    for rel, found in base_own.items():
        before.update(map(identity, found))
    rise = after - before
    fall = before - after
    added, removed = collections.Counter(), collections.Counter()
    for (key, _), n in rise.items():
        added[key] += n
    for (key, _), n in fall.items():
        removed[key] += n

    # Where they are: the rise on lines head added (and in files a cross-file finding moved in), the fall on lines
    # base removed. A hunk that replaces lines nets each check within it, so rewriting a debt line (renaming a
    # variable on it) is neither added nor removed debt.
    risen, fallen = [], []
    for rel in head_text:
        lines = {n for _, add in hunks.get(rel, ()) for n in add}
        risen += [(rel, f) for f in head_scans[rel].found + head_own.get(rel, []) if f.line in lines]
    for rel, found in head_own.items():
        if rel not in head_text:
            risen += [(rel, f) for f in found]
    for rel, scan in base_changed.items():
        lines = {n for gone, _ in hunks.get(rel, ()) for n in gone}
        fallen += [(rel, f) for f in scan.found + base_own.get(rel, []) if f.line in lines]
    replaced = collections.Counter((rel, _hunk(hunks, rel, f.line, 0), f.key) for rel, f in _placed(fall, fallen))
    placed = _placed(rise, risen)
    # A cross-file finding can appear on a line the change kept (its partner changed): list it there.
    rest = rise - collections.Counter(identity(f) for _, f in placed)
    listed = {id(f) for _, f in placed}
    kept = [(rel, f) for rel in head_text for f in head_own.get(rel, []) if id(f) not in listed]
    new = []
    for rel, f in placed + _placed(rest, kept):
        at = (rel, _hunk(hunks, rel, f.line, 1), f.key)
        if at[1] is not None and replaced[at] > 0:
            replaced[at] -= 1
            added[f.key] -= 1
            removed[f.key] -= 1
        else:
            new.append({"key": f.key, "path": rel, "line": f.line, "text": f.text})

    rows = [{**_row(key), "base": base_totals[key], "head": head_totals[key], "added": added[key],
             "removed": removed[key]} for key in [*BY_KEY, *OWNERSHIP]]
    debt = [r for r in rows if r["group"] != "ownership"]
    return {
        "version": 2, "base": base, "head": head, "base_commit": repo.commit(base), "head_commit": repo.commit(head),
        "files_changed": len(head_text.keys() | base_text.keys()),
        "categories": rows,
        "total": {k: sum(r[k] for r in debt) for k in ("base", "head", "added", "removed")},
        "ownership_total": {k: sum(r[k] for r in rows if r["group"] == "ownership")
                            for k in ("base", "head", "added", "removed")},
        "new": new, **config_review(repo, base, head, config_changed),
    }


# --- output ---------------------------------------------------------------------------------------------------------

def _grouped(rows: list[dict]) -> list[tuple[str, list[dict]]]:
    """Rows under their category, in catalog order (ownership last)."""
    titles = list(dict.fromkeys(r["category"] for r in rows))
    return [(title, [r for r in rows if r["category"] == title]) for title in titles]


def print_compare(result: dict, limit: int) -> None:
    total = result["total"]
    print(f"Source quality: {result['base']} -> {result['head']} ({result['files_changed']} source files changed)")
    print(f"Debt {total['head'] - total['base']:+,}: removed {total['removed']:,}, added {total['added']:,}; "
          f"tree {total['base']:,} -> {total['head']:,}")
    width = max(len(r["name"]) for r in result["categories"])
    print(f"\n  {'check':<{width}}  {'removed':>8} {'added':>7} {'net':>7} {'total':>8}")
    groups = _grouped(result["categories"])
    last = [title for title, rows in groups if rows[0]["group"] != "ownership"][-1]   # the total follows the debt
    for title, rows in groups:
        print(f"{title}")
        for r in rows:
            print(f"  {r['name']:<{width}}  {r['removed']:>8,} {r['added']:>7,} {r['head'] - r['base']:>+7,} "
                  f"{r['head']:>8,}")
        if title == last:
            print(f"  {'Total debt':<{width}}  {total['removed']:>8,} {total['added']:>7,} "
                  f"{total['head'] - total['base']:>+7,} {total['head']:>8,}")
    if result["new"]:
        print(f"\nNew debt on added lines ({len(result['new'])}):")
        for f in result["new"][:limit]:
            print(f"  {f['path']}:{f['line']}  [{f['key']}]  {f['text']}")
        if len(result["new"]) > limit:
            print(f"  ... {len(result['new']) - limit} more (--limit)")
    flagged = [r for r in result["renames"] if r["flags"]]
    if result["renames"]:
        print(f"\nRenamed symbols ({len(result['renames'])}, {len(flagged)} flagged):")
        for r in result["renames"][:limit]:
            print(f"  {r['address']}  {r['old']} -> {r['new']}")
            for flag in r["flags"]:
                print(f"      ! {flag}")
    if result["added_symbols"]:
        print(f"\nNew symbols with placeholder or flat names ({len(result['added_symbols'])}):")
        for r in result["added_symbols"][:limit]:
            print(f"  {r['address']}  {r['name']}: {'; '.join(r['flags'])}")
    if result["stale_force_active"]:
        print(f"\n{STALE_FORCE_ACTIVE} ({len(result['stale_force_active'])}):")
        for r in result["stale_force_active"][:limit]:
            print(f"  {r['file']}: {r['name']}")


def print_tree(result: dict) -> None:
    print(f"Source quality at {result['revision']}: {result['files']} files, debt {result['total']:,}")
    for title, rows in _grouped(result["categories"] + result["ownership"]):
        print(title)
        for r in rows:
            print(f"  {r['count']:>8,}  {r['name']} ({r['example']})")
    if result["worst_files"]:
        print("Most debt:")
        for f in result["worst_files"]:
            print(f"  {f['count']:>8,}  {f['path']}")


def default_base(repo: Repo) -> str:
    for ref in ("upstream/master", "origin/master", "master"):
        if repo.exists(ref):
            return repo.git("merge-base", "HEAD", ref).decode().strip() or ref
    raise SystemExit("no master branch found: pass --base REV")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--base", help="revision to compare against (default: where HEAD branched from master)")
    parser.add_argument("--head", default=WORKTREE, help="revision to measure (default: the working tree)")
    parser.add_argument("--tree", nargs="?", const=WORKTREE, metavar="REV",
                        help="whole-tree counts at REV (default: the working tree) instead of a comparison")
    parser.add_argument("--git-dir", help="read revisions from this git directory (CI); needs --base and --head")
    parser.add_argument("--json", type=Path, metavar="PATH", help="also write the result to PATH as JSON")
    parser.add_argument("--limit", type=int, default=200, help="most findings to list per section")
    parser.add_argument("--top", type=int, default=15, help="worst files to list with --tree")
    args = parser.parse_args()
    repo = Repo(args.git_dir)
    if args.git_dir and (args.tree == WORKTREE if args.tree else args.head == WORKTREE or not args.base):
        parser.error("--git-dir reads revisions only: pass --base and --head, or --tree REV")

    if args.tree:
        result = tree_report(repo, args.tree, args.top)
        print_tree(result)
    else:
        base = args.base or default_base(repo)
        for rev in (base, args.head):
            if rev != WORKTREE and not repo.exists(rev):
                parser.error(f"unknown revision {rev}")
        result = compare(repo, base, args.head)
        print_compare(result, args.limit)
    if args.json:
        args.json.parent.mkdir(parents=True, exist_ok=True)
        args.json.write_text(json.dumps(result, indent=1) + "\n")
    return 0


if __name__ == "__main__":
    sys.exit(main())
