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
import bisect
import collections
import dataclasses
import itertools
import json
import math
import re
import subprocess
import sys
import threading
from dataclasses import dataclass
from pathlib import Path
from typing import Container, Iterable, Iterator

import misowned   # tools/misowned.py, next to this file

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
_OPERAND = r"&?\s*[\w.\->]+(?:\s*\[[^\[\]\n]*\])?"   # p, &p->x, &table[i]
_BYTE_CAST = r"\(\s*(?:const\s+)?" + _BYTE_TYPE + r"\s*\*\s*\)\s*(?:\(\s*" + _OPERAND + r"\s*\)|" + _OPERAND + r")\s*"
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
       r"(?<!\*)(?<!\*\s)(?<!\*\()(?<!\*\s\()(?<!\*\(\s)"
       r"\(\s*(?:const\s+)?[A-Za-z_]\w*\s*\*+\s*\)\s*\(\s*[\w.\->]+\s*\+\s*0x[0-9A-Fa-f]+\s*\)",
       "layout"),
    _p("punned_deref", "Type-punned dereferences", "*(f32 *)&x, *(s32 *)(p + 0x18)",
       r"\*\s*(?:\(\s*)?\(\s*(?:(?:const|volatile)\s+)*[A-Za-z_][\w:]*(?:\s+[A-Za-z_]\w*)*\s*\*+\s*(?:const\s*)?\)\s*"
       r"(?:\(\s*)?(?:&|\(\s*[^()]*?\+\s*(?:0x[0-9A-Fa-f]+|\d+)\s*\))", "layout"),
    _p("offset_member", "Offset-named fields", "unk_30, m_c, field_96, set_field_378, ->x7A, ->b9",
       r"\b(?:m_|unk_?|unknown_?|field_?|mbr_)" + _HEX_OFFSET +
       r"|\b[A-Za-z]\w*?_(?:field|unk|unknown)_?" + _HEX_OFFSET +
       r"|(?:->|\.)\s*f(?=[0-9A-Fa-f]*\d)[0-9A-Fa-f]{2,4}\b|\b[a-z]\w*Field_?(?=[0-9A-Fa-f]*\d)[0-9A-Fa-f]{1,4}\b"
       r"|(?:->|\.)\s*(?!f[0-9A-Fa-f]{2,4}\b)(?![usf](?:8|16|32|64)\b)(?!m[0-3][0-3]\b)(?!ip\d+\b)(?!sp[0-9A-F])"
       r"[a-z]{1,2}(?=[0-9A-F])(?=[0-9A-Fa-f]*\d)[0-9A-Fa-f]{2,4}\b"
       r"|(?:->|\.)\s*[bfhw][0-9A-F]\b", "layout"),   # one hex digit: byte, field, half or word at 0-F
    _p("pad_access", "Padding fields read or written", "p->pad_3E = 0", _NEVER, "layout"),
    _p("offsetof_access", "offsetof as an address", "bytes[offsetof(TWidget, pos)], p + offsetof(TWidget, pos)",
       r"(?:[\w)\]]\s*\+\s*\(?\s*|\[\s*)offsetof\s*\([^()\n]*\)", "layout", needle=r"offsetof"),
    _p("scalar_view", "Objects indexed as scalars", "((s16 *)this)[9], ((u32 *)widget)[i]", _NEVER, "layout"),
    _p("size_assert", "Hand-written size asserts", "typedef char check[sizeof(T) == 8 ? 1 : -1];", _NEVER,
       "layout"),
    _p("blob_type", "Size-named blob types", "ByteBlock_28", r"\bByteBlock_?(?:0x)?[0-9A-Fa-f]{1,4}\b", "layout",
       needle=r"ByteBlock"),
    _p("overlay_type", "Structs only reached by casts", "struct PhaseView { u8 pad[0x28]; s32 phase; };", _NEVER,
       "layout"),
    # types
    _p("fp_cast", "Function-pointer casts", "((void (*)(T *))p)(x)",
       r"\(\s*[A-Za-z_][\w:\s\*&<>,]*\(\s*\*+\s*\)\s*\([^()]*\)\s*\)\s*[\w(*&]", "types"),
    _p("string_cast", "Strings cast to integers or void *", '(saddr)"file.gvm"',
       r"\(\s*(?:" + _INT_TYPE + r"|(?:const\s+)?void\s*\*)\s*\)\s*\"", "types"),
    _p("ghidra_type", "Ghidra types", "undefined4", r"\bundefined[1248]?\b", "types"),
    _p("address_type", "Address-named types", "TUnk_804806E8",
       r"\b(?:struct|class|union)\s+[A-Za-z]\w*?_[0-9A-Fa-f]{8}\w*"
       r"|\b(?!(?:lbl|fn|FUN|func|sub|DAT|PTR|dat|jumptable|switch)_)[A-Za-z]\w*?_[0-9A-Fa-f]{8}\w*(?=\s*(?:[*&]|::|<))",
       "types"),
    _p("hash_type", "Hash-named types", "VObj_18_4a35f9", r"\b[A-Z][A-Za-z]*_(?:[0-9A-Fa-f]{1,3}_)?(?=[0-9a-f]*\d)[0-9a-f]{6}\b",
       "types"),
    _p("retype_macro", "Re-typing macros", "#define g (*(T *)&g)",
       r"#\s*define\s+(\w+)\s+\(\s*\*\s*\([^)]*\*\s*\)\s*&\s*\1\s*\)"
       r"|#\s*define\s+(\w+)\s+\(\s*\([^)]*\(\s*\*\s*\)\s*\([^)]*\)\s*\)\s*\2\s*\)", "types"),
    # a lower-case object-like macro standing in for an expression (re-typing macros are counted above)
    _p("alias_macro", "Object macros for values", "#define obj ((T *)this), #define SELF ((T *)this)",
       r"(?m)^[ \t]*#[ \t]*define[ \t]+(?!_|nullptr\b)([a-z]\w*)[ \t]+"
       r"(?!\(\s*\*\s*\([^)]*\*\s*\)\s*&\s*\1\s*\)|\(\s*\([^)]*\(\s*\*\s*\)\s*\([^)]*\)\s*\)\s*\1\s*\))\S[^\n]*"
       r"|^[ \t]*#[ \t]*define[ \t]+(?!NULL\b)[A-Z_][A-Z0-9_]*[ \t]+\(?\s*\(\s*(?:const\s+)?(?:(?:struct|class)\s+)?"
       r"[A-Za-z_]\w*\s*\*+\s*\)\s*\(?\s*[A-Za-z_&][^\n]*",
       "types", needle=r"define[ \t]+\w"),
    _p("this_alias", "Aliases of this", "TWidget *self = (TWidget *)this;",
       r"\b[A-Za-z_][\w:]*\s*\*\s*(?:const\s+)?(?:\w+\s*=\s*" + _THIS_INIT + r"\s*\)?\s*;|" + _SELF_THIS + ")",
       "types", needle=r"this"),
    # an integer cast to a pointer (a round trip when the integer was a pointer), and a pointer cast to an integer
    _p("ptr_int_roundtrip", "Casts between pointers and integers", "(T *)(u32)p, (u32)(T *)p",
       r"\(\s*(?:const\s+)?[A-Za-z_]\w*\s*\*+\s*\)\s*\(\s*" + _INT_TYPE + r"\s*\)"
       r"|\(\s*" + _INT_TYPE + r"\s*\)\s*\(\s*(?:const\s+)?[A-Za-z_]\w*\s*\*+\s*\)"
       # pointer arithmetic done on an integer: (T *)((u32)p + 0x10)
       r"|\(\s*(?:const\s+)?[A-Za-z_]\w*\s*\*+\s*\)\s*\(\s*(?:\(\s*)?\(\s*" + _INT_TYPE
       + r"\s*\)\s*[\w.\->]+(?:\s*\([^()]*\))?\s*\)?\s*[-+]", "types"),
    _p("repeat_cast", "Values cast to one type again and again", "((TWidget *)p)->x = ((TWidget *)p)->y;", _NEVER,
       "types"),
    # casts judged by the declared type of what they cast (typed_casts()): a local, parameter or file-scope variable
    _p("redundant_cast", "Casts to the type a value already has", "TWidget w; f((TWidget *)&w);", _NEVER, "types"),
    _p("void_value", "void * values cast back to a type", "void *w = ...; ((TWidget *)w)->x", _NEVER, "types"),
    _p("pointer_as_int", "Pointers and addresses cast to integers", "f((saddr)&pos), (u32)widget", _NEVER,
       "types"),
    _p("cross_cast", "Pointers cast to an unrelated class", "TPlayer *p; ((TWidget *)p)->f()", _NEVER, "types"),
    _p("void_arg", "void * casts on arguments", "f((void *)widget)", _NEVER, "types", needle=r"void"),
    _p("void_table", "Tables of void pointers", "void *handlers[] = {",
       r"\bvoid\s*\*\s*(?:const\s+)?(?!(?i:\w*(?:vt|vtable|vtbl)))\w+\s*\[[^\]\n]*\]\s*(?:\[[^\]\n]*\]\s*)*=\s*\{",
       "types", needle=r"void"),
    _p("byte_new", "Allocations by byte count", "operator new(0x1C)",
       r"\boperator\s+new\s*\(\s*(?:0x[0-9A-Fa-f]+|\d+)[uUlL]*\s*\)", "types", needle=r"operator"),
    _p("cast_macro", "Function macros that cast their arguments", "#define HP(p) (((TObjChara *)(p))->hp)", _NEVER,
       "types", needle=r"define"),
    _p("static_this", "Own members called with this", "TWidget::update(this, dt)", _NEVER, "types",
       needle=r"this"),
    # decompiler output
    _p("decomp_temp", "m2c temporaries", "temp_r3, var_f31", r"\b(?:temp|var)_[rfa]\d+(?:_\d+)?\b", "decompiler"),
    _p("stack_local", "Stack-slot locals", "sp1C", r"\bsp[0-9A-F]{1,3}\b", "decompiler"),
    _p("arg_name", "Numbered parameters", "arg0, farg1, arg2_, param1",
       r"\bf?arg_?\d+(?:_\w*)?\b|\bparam\d+\b", "decompiler"),
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
    _p("no_op", "No-op statements", "x = x; if (1), extern \"C\" {}", _NEVER, "decompiler"),
    # names
    _p("data_label", "Address-named data", "lbl_8045A010",
       r"\b(?:lbl|DAT|PTR|dat)_[0-9A-Fa-f]{6,16}\b|\b\w+__data_[0-9A-Fa-f]{6,16}\b", "names"),
    _p("function_placeholder", "Address-named functions", "fn_80123456, TEnemy__sub_80123456",
       r"\b(?:fn|FUN|func|sub)_[0-9A-Fa-f]{6,16}\b|\b\w+__sub_[0-9A-Fa-f]{6,16}\b", "names"),
    _p("address_in_name", "Names built on an address", "call_36A90_with_1",
       r"\b(?!(?:lbl|fn|sub|func|dat|ptr|jumptable|switch|temp|var|arg|sp|text|data|bss|rodata)_[0-9A-F])"
       r"[a-z][a-z0-9]*(?:_[a-z][a-z0-9]*)*_(?=[0-9A-F]*\d)[0-9A-F]{5,8}_[A-Za-z0-9]\w*\b", "names"),
    _p("hex_name", "Names holding hex numbers", "set_mode_0x15", r"\b[A-Za-z_]\w*?0x[0-9A-Fa-f]+\w*", "names",
       needle=r"0x"),
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
    _p("slot_name", "Slot-numbered names", "vfunc_67, TEnemy__vt82, ->m4()",
       r"\bvfunc_?\d+(?!\d)|\bvf\d+\b|\b[A-Za-z_]\w*?__vt\d+(?!\d)"
       r"|(?:->|\.)\s*(?:(?![bfhw]\d\b)[a-z]{1,2}\d|m[0-3][0-3])\s*\(", "vtables"),
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
    """text with comments, literals and preprocessor lines replaced by spaces, and C++ casts spelled as C casts
    (c_casts); length and newlines kept."""
    return c_casts(_BLANK.sub(lambda m: re.sub(r"[^\n]", " ", m[0]), text), pad=True)


def blank_comments(text: str) -> str:
    """Comments dropped, string literals emptied and C++ casts spelled as C casts (c_casts), so documentation of
    a pattern is not the pattern and a cast is one shape; every line kept in place (for line numbers)."""
    return c_casts(_COMMENT_OR_STRING.sub(lambda m: "\n" * m[0].count("\n") if m[0][0] == "/" else '""', text))


_CXX_CAST = re.compile(r"\b(?:reinterpret|static|const|dynamic)_cast\s*<")
_POSTFIX_NEXT = re.compile(r"\s*(?:->|\.(?!\.)|\[|\(|\+\+|--)")


def c_casts(code: str, pad: bool = False) -> str:
    """Each `reinterpret_cast<T>(e)` (and static_, const_, dynamic_) spelled as the C cast `(T)e` would be written:
    the operand in parentheses only when it has an operator, the whole in parentheses only when a postfix operator
    follows. A respelled cast then reads, and is reported, the same as the C cast. Newlines are kept (after the
    cast); with pad, spaces after it keep the length too. Innermost first: the rightmost cast has no cast inside
    it, and a rewrite keeps every offset before it."""
    if "_cast" not in code:
        return code
    for match in reversed(list(_CXX_CAST.finditer(code))):
        depth, at = 1, match.end()
        while at < len(code) and depth:
            c = code[at]
            depth += c == "<"
            depth -= c == ">" and code[at - 1] != "-"
            if c in ";{}":
                break
            at += 1
        if depth:
            continue
        kind = code[match.end():at - 1]
        while at < len(code) and code[at] in " \t\n":
            at += 1
        if at >= len(code) or code[at] != "(":
            continue
        end = _parenthesis(code, at)
        if end is None:
            continue
        operand = code[at + 1:end]
        spelled = "(" + " ".join(kind.split()) + ")" + (operand if _bare_operand(operand) else "(" + operand + ")")
        if _POSTFIX_NEXT.match(code, end + 1) or code[:match.start()].rstrip().endswith("sizeof"):
            spelled = "(" + spelled + ")"
        span = code[match.start():end + 1]
        lines = span.count("\n") - operand.count("\n")   # newlines outside the operand
        spaces = len(span) - len(spelled) - lines if pad else 0
        if spaces < 0:
            continue
        code = code[:match.start()] + spelled + "\n" * lines + " " * spaces + code[end + 1:]
    return code


def _bare_operand(operand: str) -> bool:
    """Whether a cast operand needs no parentheses: unary prefixes, then a name, number or parenthesised group with
    only member access, calls and indexing after it (no binary operator at the top level)."""
    code = operand.strip().lstrip("&*!~- \t\n")
    at = 0
    if not code:
        return False
    while at < len(code):
        c = code[at]
        if c in "([":
            close = _closing(code, at)
            if close is None:
                return False
            at = close + 1
        elif c.isalnum() or c in "_. \t\n\"":
            at += 1
        elif code.startswith("->", at) or code.startswith("::", at):
            at += 2
        else:
            return False
    return True


def _closing(code: str, at: int) -> int | None:
    """The offset of the bracket closing the `(` or `[` at `at`, or None."""
    depth = 0
    for index in range(at, len(code)):
        c = code[index]
        depth += c in "(["
        depth -= c in ")]"
        if not depth:
            return index
    return None


def _parenthesis(code: str, at: int) -> int | None:
    """The offset of the `)` matching the `(` at `at`, or None (unbalanced before a `;`, `{` or `}`)."""
    depth = 0
    for index in range(at, len(code)):
        c = code[index]
        if c == "(":
            depth += 1
        elif c == ")":
            depth -= 1
            if not depth:
                return index
        elif c in ";{}":
            return None
    return None


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


# (T *)value: a name or a member chain, bare or in parentheses, that is the whole operand (not called, indexed,
# followed by -> or ., or by pointer arithmetic)
_CAST_OF = re.compile(r"\(\s*(?:const\s+)?((?:(?:struct|class|union)\s+)?[A-Za-z_][\w:]*)\s*(\*+)\s*(?:const\s*)?\)\s*"
                      r"(\(\s*)?(?<![\w.>])((?>[A-Za-z_]\w*(?:\s*(?:->|\.)\s*[A-Za-z_]\w*)*))(?(3)\s*\))"
                      r"(?!\s*(?:[\w(\[.:]|->|[-+](?![-+=>])))")
_BYTE_POINTEE = {"void", "u8", "s8", "char", "uint8_t", "int8_t", "byte"}


def repeat_casts(blanked: "_Blanked") -> list[tuple[int, str]]:
    """(line, cast) of each cast of one name or member chain to one pointer type that a function body makes more
    than once: the value is declared as one type and used as another. Casts of this (this_cast), to byte and void
    pointers (raw_offset and offset_cast count their arithmetic) and of call results are left out."""
    code = blanked()
    out = []
    for start, stop in _outermost((d.open, d.end) for d in blanked.defs() if d.end > d.open):
        seen = collections.defaultdict(list)
        for match in _CAST_OF.finditer(code, start, stop):
            pointee = re.sub(r"\b(?:struct|class|union)\s+", "", match[1])
            value = re.sub(r"\s+", "", match[4])
            if pointee not in _BYTE_POINTEE and not re.match(r"(?:this|NULL|nullptr)\b", value):
                seen[f"({pointee} {match[2]}){value}"].append(match.start())
        out += [(blanked.line(at), cast) for cast, offsets in seen.items() if len(offsets) > 1 for at in offsets]
    return sorted(out)


_TYPE_WORDS = r"(?:(?:unsigned|signed|long|short)\s+)*[A-Za-z_][\w:]*"
# a declaration of one variable: [qualifiers] type [*...] name, then = ; , ) or [
_VAR_DECL = re.compile(r"(?:(?<=[;{}(,])|^)\s*(?:(?:const|volatile|static|register|struct|class|union)\s+)*"
                       r"(" + _TYPE_WORDS + r")(\s+|\s*(?:\*\s*(?:const\b\s*)?)+)([A-Za-z_]\w*)\s*(?=[=;,)\[])", re.M)
_NOT_TYPE = {"return", "goto", "delete", "case", "else", "new", "throw", "typedef", "using", "namespace", "sizeof",
             "do", "if", "while", "for", "switch", "operator", "public", "private", "protected", "virtual", "inline",
             "friend", "template", "typename", "explicit", "default", "extern", "enum", "const", "volatile"}
# (T *)x, (T *)&x, (T)(x), (T *)&a->b.c: a cast whose whole operand is a name, its address, or a member's address
_VAR_CAST = re.compile(r"(?<![\w)\]])\(\s*(?:(?:const|volatile)\s+)*(?:(?:struct|class|union)\s+)?(" + _TYPE_WORDS
                       + r")\s*((?:\*\s*(?:const\b\s*)?)*)\)\s*(\()?\s*(&\s*)?(this|[A-Za-z_]\w*)"
                       r"((?:\s*(?:->|\.)\s*[A-Za-z_]\w*|\s*\[[^\[\]]*\])*)\s*(?(3)\))"
                       r"(?!\s*(?:\(|\[|->|\.(?!\.)|::|\+\+|--))")
# a binary + - * / % & | ^ << >> next to an operand (not -> -- ++ && || or a unary & * after an operator)
_ARITH_AFTER = re.compile(r"\s*(?:[+*/%^]|-(?![->])|&(?!&)|\|(?!\|)|<<|>>)(?!=)")
_ARITH_BEFORE = re.compile(r"(?:[\w)\]]\s*(?:[+*/%^]|-|&|\|)|<<|>>)\s*\(?\s*$")
_INDEXED = re.compile(r"\s*\)\s*\[")
_SCALAR_NAME = None   # set below from _SCALAR
_INT_NAMES = {"saddr", "uaddr", "u32", "s32", "uintptr_t", "intptr_t", "int", "long", "unsigned", "unsigned int",
              "unsigned long", "signed int", "signed long"}
_BYTE_TYPES = {"void", "u8", "s8", "char", "unsigned char", "signed char", "uint8_t", "int8_t", "byte"}


@dataclass(frozen=True)
class TypedCast:
    offset: int        # of the cast in blank(text)
    cast: str          # the type cast to, less qualifiers and its pointers: TWidget
    depth: int         # its pointer depth
    address: bool      # the operand is &name...
    name: str          # the operand's variable (this for this)
    member: bool       # the operand goes on to a member or element (&a->b)
    declared: str      # the variable's declared type ("" when unknown)
    declared_depth: int
    declared_at: int   # offset of the variable's declaration (-1 when unknown)
    text: str
    array: bool = False   # the variable is an array of declared_depth pointers
    arithmetic: bool = False   # the cast is an operand of + - * / % & | ^ << >>
    indexed: bool = False      # ((T *)x)[i]


_FOR_OPEN = re.compile(r"\bfor\s*\($")


def _declarations(code: str, start: int, end: int, lists: tuple = ()) -> dict[str, tuple[str, int, int, bool]]:
    """name -> (type, pointer depth, offset, array) of the variables declared between start and end: statements, and
    after a ( or , only in a parameter list (lists: their parenthesis offsets) or a for. A name declared as two types
    is dropped."""
    out: dict[str, tuple[str, int, int, bool] | None] = {}
    chunk = code[start:end]
    for match in _VAR_DECL.finditer(chunk):
        kind = " ".join(match[1].split())
        if kind in _NOT_TYPE or kind.split()[0] in _NOT_TYPE or match[3] in _NOT_TYPE:
            continue
        at = start + match.start()
        lead = code[at - 1] if at else ";"
        if lead in "(," and not any(a < at <= b for a, b in lists) \
                and not _FOR_OPEN.search(code, max(0, at - 8), at):
            continue
        array = chunk[match.end():match.end() + 1] == "["
        found = (kind, match[2].count("*"), start + match.start(3), array)
        if match[3] in out and (out[match[3]] is None or out[match[3]][:2] != found[:2]
                                or out[match[3]][3] != array):
            out[match[3]] = None
        elif match[3] not in out:
            out[match[3]] = found
    return {name: found for name, found in out.items() if found}


def _global_decls(code: str) -> dict[str, tuple[str, int, int, bool]]:
    """Variables declared at file scope (outside every body and brace), as _declarations()."""
    depth, outside, at = 0, [], 0
    for index, c in enumerate(code):
        if c == "{":
            if depth == 0:
                outside.append((at, index))
            depth += 1
        elif c == "}":
            depth = max(depth - 1, 0)
            if depth == 0:
                at = index + 1
    outside.append((at, len(code)))
    out: dict[str, tuple[str, int, int, bool] | None] = {}
    for start, end in outside:
        for name, found in _declarations(code, start, end).items():
            if name in out and (out[name] is None or out[name][:2] != found[:2] or out[name][3] != found[3]):
                out[name] = None
            elif name not in out:
                out[name] = found
    return {name: found for name, found in out.items() if found}


def typed_casts(blanked: "_Blanked") -> list[TypedCast]:
    """Each cast in a function body whose operand is a variable (or its address, or a member's address), with the
    variable's declared type: its parameter or local declaration, else the file's. Found once per file."""
    if blanked._typed is not None:
        return blanked._typed
    code, out = blanked(), []
    defs = [d for d in blanked.defs() if d.end > d.open]
    if defs and "(" in code:
        globals_ = _global_decls(code)
        lists = tuple(d.params for d in defs if d.params[1] > d.params[0])
        for start, stop in _outermost((d.params[0], d.end) for d in defs if d.params[1] > d.params[0]):
            local = _declarations(code, start, stop, lists)
            for match in _VAR_CAST.finditer(code, start, stop):
                before = code[max(start, match.start() - 8):match.start()]
                if re.search(r"\b(?:if|while|for|switch|return|sizeof)\s*$", before):
                    continue
                cast = re.sub(r"^(?:struct|class|union)\s+", "", " ".join(match[1].split()))
                if cast in _NOT_TYPE:
                    continue
                name = match[5]
                kind, depth, at, array = local.get(name) or globals_.get(name) or ("", 0, -1, False)
                arithmetic = bool(_ARITH_AFTER.match(code, match.end()) or _ARITH_BEFORE.search(code, start, match.start()))
                indexed = bool(_INDEXED.match(code, match.end())) and code[:match.start()].rstrip().endswith("(")
                out.append(TypedCast(match.start(), cast, match[2].count("*"), bool(match[4]), name,
                                     bool(match[6].strip()), kind, depth, at, _normal(match[0]), array, arithmetic,
                                     indexed))
    blanked._typed = out
    return out


def redundant_casts(blanked: "_Blanked") -> list[tuple[int, str]]:
    """(line, cast) of each cast of a variable, or of its address, to the type it already has: `(T *)&t` for `T t`,
    `(T)t` for `T t`. A cast that changes nothing is left from a decompiler or from a retyping."""
    return [(blanked.line(c.offset), c.text) for c in typed_casts(blanked)
            if c.declared and not c.member and c.name != "this" and c.cast == c.declared
            and (c.depth == c.declared_depth + c.address or (c.array and c.depth == c.declared_depth + 1))]


_CONST_VOID = re.compile(r"\bconst\s+void\s*\*\s*(?:const\s+)?$")   # a read-only buffer of any type


def void_values(blanked: "_Blanked") -> list[tuple[int, str]]:
    """(line, declaration) of each `void *` parameter or local, once, that its function casts to a pointer to some
    other type (not a byte or void pointer): the variable has that type. `const void *` stays, a read-only buffer of
    any type."""
    seen, code, callbacks = {}, blanked(), None
    for c in typed_casts(blanked):
        if c.declared == "void" and c.declared_depth == 1 and not c.address and not c.member and c.depth \
                and c.cast not in _BYTE_TYPES and c.declared_at >= 0 and c.declared_at not in seen \
                and not _CONST_VOID.search(code, max(0, c.declared_at - 40), c.declared_at):
            if callbacks is None:
                values = _values(code)
                callbacks = [d.params for d in blanked.defs() if d.end > d.open and _passed_as_value(d.name, values)]
            if not any(start < c.declared_at < stop for start, stop in callbacks):
                seen[c.declared_at] = f"void *{c.name}"
    return [(blanked.line(at), text) for at, text in sorted(seen.items())]


_VALUE_NAME = re.compile(r"(?<![\w.>~])(?:\w+::)*([A-Za-z_]\w*)\b(?!\s*[(*&\w])")


def _values(code: str) -> set[str]:
    """Names used as values in code, other than right after a cast: `qsort(.., compare)`, `= handler;`. A
    function so used is a callback, whose signature its caller fixes; `(void *)f` in a table fixes nothing."""
    out = set()
    for match in _VALUE_NAME.finditer(code):
        at = match.start() - 1
        while at >= 0 and code[at] in " \t\n":
            at -= 1
        if at < 0 or code[at] != ")":
            out.add(match[1])
    return out


def _passed_as_value(name: str, values: set[str]) -> bool:
    """Whether the function `name` (not a constructor, destructor or operator) is used as a value (_values)."""
    parts = name.split("::")
    bare = parts[-1]
    return not (bare.startswith(("~", "operator")) or len(parts) > 1 and parts[-2] == bare) and bare in values


def pointers_as_int(blanked: "_Blanked") -> list[tuple[int, str]]:
    """(line, cast) of each address, pointer variable or this cast to an integer: `(saddr)&pos`, `(u32)widget`."""
    return [(blanked.line(c.offset), c.text) for c in typed_casts(blanked)
            if not c.depth and c.cast in _INT_NAMES and not c.arithmetic
            and (c.address or ((c.name == "this" or c.declared_depth or c.array) and not c.member))]


def scalar_views(blanked: "_Blanked") -> list[tuple[int, str]]:
    """(line, cast) of each object read as an array of scalars: `((s16 *)this)[9]`, `((u32 *)widget)[i]` for a
    pointer to a class or struct."""
    return [(blanked.line(c.offset), c.text) for c in typed_casts(blanked)
            if c.indexed and c.depth == 1 and _SCALAR_NAME.match(c.cast) and not c.member and not c.address
            and (c.name == "this" or (c.declared_depth == 1 and not c.array and c.declared
                                      and not _SCALAR_NAME.match(c.declared)))]


_VOID_CAST = re.compile(r"\(\s*(?:const\s+)?void\s*\*\s*\)\s*(?!\s|0\b|NULL\b|\)|,)")
_NOT_CALL = {"if", "while", "switch", "return", "sizeof", "for", "do", "else", "case"}


def void_args(blanked: "_Blanked") -> list[tuple[int, str]]:
    """(line, argument) of each `(void *)` cast on a call's argument, other than of 0 or NULL: a pointer converts to
    void * by itself, so the cast either does nothing or turns an integer into a pointer."""
    code, out = blanked(), []
    for match in _VOID_CAST.finditer(code):
        depth, at = 0, match.start() - 1
        while at >= 0:
            c = code[at]
            if c in ")]}":
                depth += 1
            elif c in "([{":
                if depth == 0:
                    break
                depth -= 1
            elif c == ";" and depth == 0:
                at = -1
                break
            at -= 1
        if at < 0 or code[at] != "(":
            continue
        callee = re.search(r"([A-Za-z_]\w*)\s*$", code[max(0, at - 80):at])
        if not callee or callee[1] in _NOT_CALL:
            continue
        end, depth = match.end(), 0
        while end < len(code):
            c = code[end]
            if c in "([{":
                depth += 1
            elif c in ")]}":
                if depth == 0:
                    break
                depth -= 1
            elif c == "," and depth == 0 or c == ";":
                break
            end += 1
        out.append((blanked.line(match.start()), _normal(code[match.start():end])))
    return out


_MACRO = re.compile(r"(?m)^[ \t]*#[ \t]*define[ \t]+(\w+)\(([^)\n]*)\)((?:[^\n]*\\\n)*[^\n]*)")


def cast_macros(blanked: "_Blanked") -> list[tuple[int, str]]:
    """(line, `#define NAME`) of each function-like macro whose body casts one of its parameters to a pointer to some
    type other than void or a byte: each use re-types an argument out of sight."""
    kept, out = blanked.kept(), []
    if "define" not in kept:
        return out
    line = _line_index(kept)
    for match in _MACRO.finditer(kept):
        for param in (p.strip() for p in match[2].split(",")):
            if param and param != "..." and re.search(
                    r"\(\s*(?:const\s+)?(?:(?:struct|class|union)\s+)?(?!(?:void|" + _BYTE_TYPE + r")\s*\*)[A-Za-z_][\w:]*\s*\*+\s*(?:const\s*)?\)"
                    r"\s*\(?\s*" + re.escape(param) + r"\b", match[3]):
                out.append((line(match.start()), f"#define {match[1]}"))
                break
    return out


def static_this_calls(blanked: "_Blanked") -> list[tuple[int, str]]:
    """(line, call) of each `C::f(this, ...)` in a member of C: a member written as a static that takes its object."""
    code, out = blanked(), []
    for d in blanked.defs():
        owner = d.owner
        if not owner or d.end <= d.open:
            continue
        for match in re.finditer(r"(?<![\w:])" + re.escape(owner) + r"::(~?\w+)\s*\(\s*(?:\(\s*[\w:]+\s*\*\s*\)\s*)?"
                                 r"this\s*[,)]", code[d.open:d.end]):
            if match[1] not in (owner, "~" + owner):
                out.append((blanked.line(d.open + match.start()), _normal(match[0])))
    return out


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
_SCALAR_NAME = re.compile(_SCALAR + r"$")
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
    found = [(blanked.line(at), text) for at, text in sorted(out)]
    if "extern" in code:
        kept = blanked.kept()
        line = _line_index(kept)
        found += [(line(m.start()), 'extern "C" {}') for m in _EMPTY_EXTERN.finditer(kept)]
    return found


_EMPTY_EXTERN = re.compile(r'\bextern\s+"[^"\n]*"\s*\{\s*\}')


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


def identity(f: Finding) -> tuple[str, str, str]:
    """What a finding is matched by between revisions: (key, text, the line it is on), less a partner's line (other
    edits move it). The line makes a moved finding cancel and a new one count: `(saddr)this` reads the same on every
    line that has it."""
    text = _PARTNER_LINE.sub(")", f.text) if f.key == "param_name_split" else f.text
    return f.key, text, f.context


def _in_context(found: Iterable[Finding], text: str) -> list[Finding]:
    """found, each with the source line it is on, whitespace collapsed."""
    lines = text.split("\n")
    return [dataclasses.replace(f, context=" ".join(lines[f.line - 1].split()) if 0 < f.line <= len(lines) else "")
            for f in found]


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
    "repeat_cast": lambda rel, text, blanked: repeat_casts(blanked) if "*)" in text or "_cast" in text else [],
    "redundant_cast": lambda rel, text, blanked: redundant_casts(blanked),
    "void_value": lambda rel, text, blanked: void_values(blanked) if "void" in text else [],
    "pointer_as_int": lambda rel, text, blanked: pointers_as_int(blanked),
    "scalar_view": lambda rel, text, blanked: scalar_views(blanked) if "*)" in text or "_cast" in text else [],
    "void_arg": lambda rel, text, blanked: void_args(blanked) if "void" in text else [],
    "cast_macro": lambda rel, text, blanked: cast_macros(blanked) if "define" in text else [],
    "static_this": lambda rel, text, blanked: static_this_calls(blanked) if "this" in text and "::" in text else [],
}
# Checks judged over the whole tree (see relations()): they depend on more than one file, or on the config. A
# header named after an address (address_unit) counts only when no unit has its name, since one rename fixes both.
TREE_CHECKS = {"duplicate_class", "header_extern_c", "param_name_split", "address_unit", "misowned_member",
               "overlay_type", "cross_cast"}


# --- per-file scan ----------------------------------------------------------------------------------------------

Hunk = tuple[range, range]   # a diff hunk: the lines base removed, the lines head added


@dataclass
class Finding:
    key: str
    text: str
    line: int
    context: str = ""   # the source line, set when two revisions are compared (identity())


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
    this_casts: list[tuple[str, str, int]]      # (owner class, cast type, line)
    subobject_calls: list[tuple[str, int]]      # (call text, line)
    classes: dict[str, set[str]]                # class declared here -> its direct bases
    aliases: dict[str, str]                     # typedef / using name -> the type it names
    bodies: dict[str, int]                      # class with a body here, not nested in another -> its line
    found: list[Finding] | None = None          # every catalog finding with its line, kept for changed files only
    c_functions: list[tuple[int, str]] = dataclasses.field(default_factory=list)   # header: (line, extern "C" fn)
    signatures: list = dataclasses.field(default_factory=list)   # see signatures()
    overlays: list = dataclasses.field(default_factory=list)     # see plain_structs()
    blobs: dict = dataclasses.field(default_factory=dict)        # struct of byte arrays declared here -> its size
    var_casts: list = dataclasses.field(default_factory=list)    # (declared class, cast class, cast text, line)


class _Blanked:
    """blank(text), its function definitions and class bodies, each computed once and only when a check needs it."""

    def __init__(self, text: str):
        self.text, self.code, self._defs, self._bodies, self._line = text, None, None, None, None
        self._prototypes: list[Definition] = []
        self._kept, self._matches = None, None
        self._typed: list | None = None

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
    var_casts = [(c.declared, c.cast, c.text, blanked.line(c.offset)) for c in typed_casts(blanked)
                 if c.depth == 1 and c.declared_depth == 1 and not c.address and not c.member and c.name != "this"
                 and c.declared and c.declared != c.cast] if "*)" in text or "_cast" in text else []
    return FileScan(counts, this_casts, subobject_calls, dict(classes), aliases, bodies,
                    found if keep else None, c_functions, signatures(blanked), *plain_structs(blanked),
                    var_casts=var_casts)


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


_PAD_FIRST = re.compile(r"\s*(?:(?:unsigned|signed|const|volatile)\s+)*[A-Za-z_]\w*\s+"
                        r"(?:pad|unk|padding|gap|reserved|_)\w*\s*\[")
_BYTE_ARRAY = re.compile(r"\s*(?:const\s+)?(?:u8|s8|char|(?:un)?signed\s+char|u?int8_t)\s+\w+\s*((?:\[[^\]]+\]\s*)+)$")


def plain_structs(blanked: _Blanked) -> tuple[list[tuple[str, int, str]], dict[str, int]]:
    """Class bodies of plain fields (no member functions or nested bodies). Overlays: (name, line, `struct Name`) of
    those that start with padding or are a single array, the shapes of a view over part of something else and of a
    blob for copying bytes. Blobs: name -> size of those made only of byte arrays with literal sizes."""
    out, blobs = [], {}
    code = blanked()
    for offset, keyword, name in blanked.bodies():
        brace = code.index("{", offset)
        inner = re.sub(r"\b(?:public|private|protected)\s*:(?!:)", "", code[brace + 1:_matching(code, brace)])
        if re.search(r"[(){]", inner):
            continue
        fields = [field for field in inner.split(";") if field.strip()]
        if len(fields) == 1 and fields[0].rstrip().endswith("]") or len(fields) > 1 and _PAD_FIRST.match(fields[0]):
            out.append((name, blanked.line(offset), f"{keyword} {name}"))
        arrays = [_BYTE_ARRAY.match(field) for field in fields]
        if fields and all(arrays):
            try:
                blobs[name] = sum(math.prod(int(n, 0) for n in re.findall(r"\[\s*(\w+)\s*\]", a[1])) for a in arrays)
            except ValueError:
                pass
    return out, blobs


_BLOB_SIZE = re.compile(r"ByteBlock_?(?:0x)?([0-9A-Fa-f]{1,4})")


def renamed_blobs(before: Iterable[FileScan], after: dict[str, FileScan],
                  texts: dict[str, str]) -> dict[str, list[Finding]]:
    """blob_type findings at each mention of a struct of byte arrays a change added in place of a size-named blob it
    removed: `struct ByteBlock_78 { u8 bytes[0x78]; };` renamed `struct BodyCopy { u8 data[0x78]; };` is still a
    blob. Only a change shows the rename, so these count in comparisons only."""
    sizes = lambda scans: {int(size[1], 16) for scan in scans for f in scan.found
                           if f.key == "blob_type" and (size := _BLOB_SIZE.search(f.text))}
    gone = sizes(before) - sizes(after[rel] for rel in texts)
    old = {name for scan in before for name in scan.bodies}
    names = {name for rel in texts for name, size in after[rel].blobs.items() if size in gone and name not in old}
    if not names:
        return {}
    mention = re.compile(r"\b(?:" + "|".join(map(re.escape, sorted(names))) + r")\b")
    out = {}
    for rel, text in texts.items():
        if mention.search(text):
            code = blank(text)
            line = _line_index(code)
            out[rel] = [Finding("blob_type", m[0], line(m.start())) for m in mention.finditer(code)]
    return out


_TAG = r"(?:(?:const|volatile|struct|class|union)\s+)*"


def _type_use(code: str, start: int, end: int, name: str) -> str:
    """How one mention of a class name uses it: "declaration" (its body, a forward declaration, a typedef), "size",
    "cast" (a pointer cast to it, or a local holding one), or "typed" (anything else: a variable, member, parameter
    or return type, a base, a scope)."""
    before, after = code[max(0, start - 80):start], code[end:end + 160]
    if (re.search(r"\b(?:class|struct|union)\s*$", before) and re.match(r"\s*(?:final\s*)?[:{;]", after)
            or re.search(r"}\s*$", before) and re.match(r"\s*[;,]", after)
            or re.search(r"\btypedef\s+(?:struct|class|union)\s+(?:\w+\s*)?$", before) and re.match(r"\s*\w*\s*;", after)):
        return "declaration"
    if re.search(r"\b(?:sizeof|alignof)\s*\(\s*" + _TAG + "$", before):
        return "size"
    if (re.search(r"\(\s*" + _TAG + "$", before) and re.match(r"\s*\*+\s*(?:const\s*)?\)", after)
            or re.search(r"\b(?:static|reinterpret|const)_cast\s*<\s*" + _TAG + "$", before)):
        return "cast"
    if re.match(r"\s*\*\s*(?:const\s+)?\w+\s*=\s*(?:\(\s*" + _TAG + re.escape(name) + r"\s*\*|"
                r"(?:static|reinterpret)_cast\s*<\s*" + _TAG + re.escape(name) + r"\b)", after):
        return "cast"
    return "typed"


_CAST_TO = re.compile(r"(?:\(|_cast\s*<)\s*" + _TAG + r"([A-Za-z_]\w*)\s*\*")
_IDENT = re.compile(r"[A-Za-z_]\w*")


def overlay_types(texts: dict[str, str], scans: dict[str, FileScan]) -> dict[str, list[Finding]]:
    """overlay_type findings by file: the overlays (plain_structs()) of the files in scans that no file of the
    revision (texts) uses as a type, only casts other pointers to."""
    names = {name for scan in scans.values() for name, _, _ in scan.overlays}
    if names:   # only a name some text casts to can be an overlay
        names &= {match[1] for text in texts.values() if "*" in text for match in _CAST_TO.finditer(text)}
    cast, typed = set(), set()
    for text in texts.values():
        found = set(_IDENT.findall(text)) & names if names else None
        if not found:
            continue
        code = blank(text)
        for match in re.finditer(r"\b(?:" + "|".join(map(re.escape, sorted(found))) + r")\b", code):
            if match[0] not in typed:
                use = _type_use(code, match.start(), match.end(), match[0])
                (cast if use == "cast" else typed if use == "typed" else set()).add(match[0])
    out = collections.defaultdict(list)
    for rel, scan in scans.items():
        out[rel] += [Finding("overlay_type", text, line) for name, line, text in scan.overlays
                     if name in cast and name not in typed]
    return {rel: found for rel, found in out.items() if found}


def relations(scans: dict[str, FileScan], config: "Config | None" = None,
              library: dict[str, list] | None = None,
              members: dict[str, list[Finding]] | None = None) -> dict[str, list[Finding]]:
    """Findings that depend on more than one file, by the file they are in: classes declared twice,
    extern "C" in headers on functions a C++ unit defines, parameters named differently in a prototype and its
    definition (library: signatures() of files read only to pair them), headers named after an address that no unit
    shares a name with, members in the wrong class, and the findings read again from the revision's texts
    (members: text_relations())."""
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
        found += [Finding("cross_cast", text, line) for declared, cast, text, line in scan.var_casts
                  if classes.unrelated(declared, cast)]
        if config is not None:
            found += [Finding("header_extern_c", f'extern "C" {name}', line)
                      for line, name in scan.c_functions if config.cxx_linkage(name)]
        if Path(rel).suffix.lower() in HEADER_SUFFIXES and Path(rel).stem not in units:
            found += [Finding("address_unit", name, line) for line, name in address_unit(rel)]
        if found:
            out[rel] += found
    return dict(out)


def text_relations(texts: dict[str, str], pairs: Iterable[tuple[str, str]],
                   scans: dict[str, FileScan]) -> dict[str, list[Finding]]:
    """Cross-file findings read again from the revision's texts, for the files in scans: misowned_members() and
    overlay_types()."""
    out = collections.defaultdict(list)
    for found in (misowned_members(texts, pairs, scans), overlay_types(texts, scans)):
        for rel, items in found.items():
            out[rel] += items
    return dict(out)


def misowned_members(texts: dict[str, str], pairs: Iterable[tuple[str, str]],
                     counted: Container[str]) -> dict[str, list[Finding]]:
    """misowned_member findings by file (tools/misowned.py), for the files in `counted`: texts are every C/C++ file
    of the revision (src/, include/ and libs/), pairs its (symbols.txt, splits.txt) texts."""
    return {rel: [Finding(key, text, line) for line, key, text in found]
            for rel, found in misowned.misowned_members(texts, pairs, counted).items()}


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
                        text_relations(texts, config.pairs, scans))
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
                         text_relations(head_files, head_config.pairs, head_scans))
    for rel, found in renamed_blobs(base_changed.values(), head_scans, head_text).items():
        head_own[rel] = head_own.get(rel, []) + found
    base_own = relations(base_scans, head_config, base_library,
                         text_relations(base_files, base_config.pairs, base_scans))
    for found in head_own.values():
        head_totals.update(f.key for f in found)
    for found in base_own.values():
        base_totals.update(f.key for f in found)

    # Added and removed: the change's findings as a multiset of (category, text, line), so code that only moves
    # (between functions or files) cancels out, and debt that reads the same as debt the change removed elsewhere
    # does not. Findings across files can change in files the change did not
    # touch (a class gained or lost a base, a class's other copy went away), so they are compared over the whole
    # tree.
    head_found = {rel: _in_context(head_scans[rel].found, head_text[rel]) for rel in head_text}
    base_found = {rel: _in_context(scan.found, base_text[rel]) for rel, scan in base_changed.items()}
    head_own = {rel: _in_context(found, head_files.get(rel, "")) for rel, found in head_own.items()}
    base_own = {rel: _in_context(found, base_files.get(rel, "")) for rel, found in base_own.items()}
    after = collections.Counter(identity(f) for side in (head_found, head_own) for found in side.values() for f in found)
    before = collections.Counter(identity(f) for side in (base_found, base_own) for found in side.values()
                                 for f in found)
    rise = after - before
    fall = before - after
    added, removed = collections.Counter(), collections.Counter()
    for (key, *_), n in rise.items():
        added[key] += n
    for (key, *_), n in fall.items():
        removed[key] += n

    # Where they are: the rise on lines head added (and in files a cross-file finding moved in), the fall on lines
    # base removed. A hunk that replaces lines nets each check within it, so rewriting a debt line (renaming a
    # variable on it) is neither added nor removed debt.
    risen, fallen = [], []
    for rel in head_text:
        lines = {n for _, add in hunks.get(rel, ()) for n in add}
        risen += [(rel, f) for f in head_found[rel] + head_own.get(rel, []) if f.line in lines]
    for rel, found in head_own.items():
        if rel not in head_text:
            risen += [(rel, f) for f in found]
    for rel, scan in base_changed.items():
        lines = {n for gone, _ in hunks.get(rel, ()) for n in gone}
        fallen += [(rel, f) for f in base_found[rel] + base_own.get(rel, []) if f.line in lines]
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
