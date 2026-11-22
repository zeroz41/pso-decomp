#!/usr/bin/env python3
"""Source quality: how much of the matching source still reads as decompiler output.

A byte match proves the code compiles to the original; it says nothing about whether
the source reads as the program's own C/C++. This counts what is left to clean in
src/ and include/ (placeholder names, hand-mangled and flat C spellings of members, raw
offsets, casts, decompiler temporaries, members written in the wrong class) and
compares two revisions, so a change is measured on the tree instead of described.

Check your change before opening a pull request (working tree against where it
branched from master):
    python tools/source_quality.py
Other revisions, or the whole tree:
    python tools/source_quality.py --base master --head my-branch
    python tools/source_quality.py --tree [REV]
CI runs the same script from master on every pull request and posts the result in the
CI comment. It never fails a pull request; it shows what the change adds and removes.

Every check is exact: a pattern on the text, or a class relation read from the class
declarations. What each one means and how to fix it is in CONTRIBUTING.md, "Source
quality". Standard library only.
"""
from __future__ import annotations

import argparse
import bisect
import collections
import dataclasses
import json
import re
import subprocess
import sys
import threading
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable, Iterator

ROOT = Path(__file__).resolve().parent.parent
SOURCE_ROOTS = ("src", "include")
SOURCE_SUFFIXES = {".c", ".cc", ".cp", ".cpp", ".cxx", ".h", ".hh", ".hpp", ".hxx", ".inc", ".inl"}
HEADER_SUFFIXES = {".h", ".hh", ".hpp", ".hxx", ".inc", ".inl"}
MAX_FILE = 4 << 20   # larger files are skipped (no source file comes near this)
WORKTREE = "working tree"


# --- the debt catalog ---------------------------------------------------------------------------------------------

@dataclass(frozen=True)
class Pattern:
    key: str
    label: str
    regex: re.Pattern
    group: str
    sources_only: bool = False   # counted in .c/.cpp files only


def _p(key: str, label: str, regex: str, group: str, flags: int = 0, sources_only: bool = False) -> Pattern:
    return Pattern(key, label, re.compile(regex, flags), group, sources_only)


_EXTERN_PATTERN = r'\bextern\s+"C"'

# The same catalog as zkit's `quality` (whose totals these match exactly), plus flat_name.
CATALOG: tuple[Pattern, ...] = (
    _p("extern_c", 'extern "C" declarations of what another file defines', _EXTERN_PATTERN, "linkage",
       sources_only=True),
    _p("mangled_member", "hand-mangled member names (name__9TClassFv)",
       r"\b[A-Za-z_]\w*?__\d+[A-Za-z_]\w*?F\w*\b", "linkage"),
    _p("mangled_free", "hand-mangled free functions (name__Fv)", r"\b[A-Za-z_]\w*?__F[A-Za-z]\w*\b", "linkage"),
    _p("mangled_itanium", "hand-mangled names (Itanium _Z...)", r"\b_Z(?:N|L|T[VIS])?\d*[A-Za-z_]\w*\b", "linkage"),
    # Class__method: a member spelled as a C function, so its symbol is a flat C name instead of the
    # mangled method__<len>ClassF... and its receiver is a void * instead of `this`.
    _p("flat_name", "flat C spellings of members (TClass__method)",
       r"\b(?![A-Za-z0-9_]*__(?:\d|F[A-Za-z]|(?:sub|data)_[0-9A-Fa-f]{6}|vt\d))"
       r"[A-Z][A-Za-z0-9]*[a-z0-9]__[a-z_][A-Za-z0-9_]*\b", "linkage"),
    _p("raw_offset", "raw pointer + offset accesses ((u8 *)p + 0x30)",
       r"\(\s*\(?\s*(?:const\s+)?(?:u8|s8|char|unsigned\s+char|signed\s+char|uint8_t|int8_t|byte|undefined1?)"
       r"\s*\*\s*\)\s*\(?\s*[\w.\->]+\s*\)?\s*\+\s*(?:0x[0-9A-Fa-f]+|\d+)\s*\)", "layout"),
    _p("offset_member", "offset-named members (m_30c, unk_308, field_96, ->f30)",
       r"\b(?:m_|unk_?|field_?)(?:0x)?(?=[0-9A-Fa-f]*\d)[0-9A-Fa-f]{2,4}\b|(?:->|\.)\s*f(?=[0-9A-Fa-f]*\d)[0-9A-Fa-f]{2,4}\b"
       r"|\b[a-z]\w*Field_?(?=[0-9A-Fa-f]*\d)[0-9A-Fa-f]{1,4}\b", "layout"),
    _p("punned_deref", "type-punned or cast-pointer derefs (*(f32 *)&x, *(s32 *)(p + 0x18))",
       r"\*\s*\(\s*(?:(?:const|volatile)\s+)*[A-Za-z_][\w:]*(?:\s+[A-Za-z_]\w*)*\s*\*+\s*(?:const\s*)?\)\s*"
       r"(?:&|\(\s*[^()]*?\+\s*(?:0x[0-9A-Fa-f]+|\d+)\s*\))", "layout"),
    _p("fp_cast", "calls through function-pointer casts ((void (*)(T *))p)",
       r"\(\s*[A-Za-z_][\w:\s\*&<>,]*\(\s*\*+\s*\)\s*\([^()]*\)\s*\)\s*[\w(*&]", "types"),
    _p("decomp_temp", "m2c temporaries (temp_r3, var_f31)", r"\b(?:temp|var)_[rfa]\d+(?:_\d+)?\b", "decompiler"),
    _p("stack_local", "stack-slot locals (sp8, sp1C)", r"\bsp[0-9A-F]{1,3}\b", "decompiler"),
    _p("arg_name", "argN parameters (arg0, farg1)", r"\bf?arg\d+\b", "decompiler"),
    _p("ghidra_temp", "Ghidra temporaries (iVar1, param_1, local_10)",
       r"\b(?:[a-z]{1,3}Var\d+|param_\d+|local_[0-9a-fA-F]+|unaff_\w+|extraout_\w+|auStack_\w+|"
       r"in_(?:[a-z]{1,4}\d+|lr|ctr|xer|fpscr|fpcr|sp|pc|nzcv|tpidr\w*|stack_[0-9a-fA-F]+|[A-Z]\w*))\b",
       "decompiler"),
    _p("ghidra_type", "Ghidra placeholder types (undefined4)", r"\bundefined[1248]?\b", "types"),
    _p("m2c_macro", "m2c helper macros (M2C_FIELD, M2C_ERROR)", r"\bM2C_\w+", "decompiler"),
    _p("data_label", "address-named data (lbl_8045A010, Class__data_8045A010)",
       r"\b(?:lbl|DAT|PTR|dat)_[0-9A-Fa-f]{6,16}\b|\b\w+__data_[0-9A-Fa-f]{6,16}\b", "names"),
    _p("function_placeholder", "address-named functions (fn_, sub_, Class__sub_8013E17C)",
       r"\b(?:fn|FUN|func|sub)_[0-9A-Fa-f]{6,16}\b|\b\w+__sub_[0-9A-Fa-f]{6,16}\b", "names"),
    _p("address_in_name", "names built around an address (call_36A90_with_1)",
       r"\b(?!(?:lbl|fn|sub|func|dat|ptr|jumptable|switch|temp|var|arg|sp|text|data|bss|rodata)_[0-9A-F])"
       r"[a-z][a-z0-9]*(?:_[a-z][a-z0-9]*)*_(?=[0-9A-F]*\d)[0-9A-F]{5,8}_[A-Za-z0-9]\w*\b", "names"),
    _p("address_type", "address-named types (TUnk_804806E8, Obj_800EB910 *)",
       r"\b(?:struct|class|union)\s+[A-Za-z]\w*?_[0-9A-Fa-f]{8}\w*"
       r"|\b(?!(?:lbl|fn|FUN|func|sub|DAT|PTR|dat|jumptable|switch)_)[A-Za-z]\w*?_[0-9A-Fa-f]{8}\w*(?=\s*(?:[*&]|::|<))",
       "types"),
    _p("vtable_symbol", "vtable symbols spelled in source (__vt__)", r"\b__vt__\d+\w+|\b_ZTV\w+|\b\w+__vtable\b",
       "vtables"),
    _p("hand_vtable", "hand-written function tables standing in for vtables",
       r"\bvoid\s*\*\s*(?:const\s+)?\w*(?:vt|vtable|vtbl)\w*\s*\[\s*\d*\s*\]\s*=", "vtables", flags=re.I),
    _p("filler_virtual", "filler virtuals (reserved_N, slotNN)",
       r"CAT\s*\(\s*\w+\s*,\s*__LINE__\s*\)|\bvirtual\s+\w[\w\s\*&]*\b(?:reserved|virtual|slot|dummy|pad)_?\d+\s*\(",
       "vtables"),
    _p("slot_name", "vtable-slot names (vfunc_67, Class__vt82)",
       r"\bvfunc_?\d+(?!\d)|\bvf\d+\b|\b[A-Za-z_]\w*?__vt\d+(?!\d)", "vtables"),
    _p("local_virtual", "virtual declarations in source files (TU-local stand-in classes)",
       r"(?m)^\s*virtual\b[^;{]*[;{]", "vtables", sources_only=True),
    _p("retype_macro", "#define re-typings of globals or functions",
       r"#\s*define\s+(\w+)\s+\(\s*\*\s*\([^)]*\*\s*\)\s*&\s*\1\s*\)"
       r"|#\s*define\s+(\w+)\s+\(\s*\([^)]*\(\s*\*\s*\)\s*\([^)]*\)\s*\)\s*\2\s*\)", "types"),
    _p("inline_asm", "assembly in source (asm blocks)",
       r"\basm\s*\{|\b__asm__\b|\basm\s+[\w\s\*&:~<>,]+?\w+\s*\([^;]*\)\s*\{", "asm"),
)
BY_KEY = {p.key: p for p in CATALOG}

# Members written in the wrong class, read from the class declarations (not counted in the debt total).
OWNERSHIP = {
    "this_cast": "`this` cast to a class outside its own hierarchy",
    "subobject_call": "member named for its own class but called on a sub-object (this + N)",
}
STALE_FORCE_ACTIVE = "force_active entries the change left naming no symbol in symbols.txt"


# --- C/C++ text helpers -----------------------------------------------------------------------------------------

_BLANK = re.compile(r'R"(?P<d>[^ ()\\\t\r\n]{0,16})\(.*?\)(?P=d)"|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'|'
                    r'//[^\n]*|/\*.*?\*/|^[ \t]*#(?:[^\n]*\\\n)*[^\n]*', re.S | re.M)
_COMMENT_OR_STRING = re.compile(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\\n])*"', re.S)


def blank(text: str) -> str:
    """text with comments, literals and preprocessor lines replaced by spaces; offsets and newlines kept."""
    return _BLANK.sub(lambda m: re.sub(r"[^\n]", " ", m[0]), text)


def strip_comments(text: str) -> str:
    """Comments dropped and string literals emptied, so documentation of a pattern is not the pattern."""
    return _COMMENT_OR_STRING.sub(lambda m: "" if m[0][0] == "/" else '""', text)


def blank_comments(text: str) -> str:
    """As strip_comments, but every line kept in place (for line numbers)."""
    return _COMMENT_OR_STRING.sub(lambda m: "\n" * m[0].count("\n") if m[0][0] == "/" else '""', text)


def _line_index(code: str):
    starts = [0] + [m.end() for m in re.finditer(r"\n", code)]
    return lambda offset: bisect.bisect_right(starts, offset)   # 1-based line of an offset


def _matching(code: str, at: int) -> int:
    """Offset of the brace closing the one at `at` (or the end of the text)."""
    depth = 0
    for match in re.finditer(r"[{}]", code[at:]):
        depth += 1 if match[0] == "{" else -1
        if depth == 0:
            return at + match.start()
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
    open: int     # offset of the body's opening brace
    end: int      # offset of its closing brace

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


def definitions(code: str) -> list[Definition]:
    """Every function definition in blanked C/C++ source, in file order (bodies are not entered)."""
    out: list[Definition] = []
    scopes: list[tuple[str, str]] = []
    head_start = position = 0
    structure = re.compile(r"[{};]")
    while True:
        match = structure.search(code, position)
        if match is None:
            break
        at, char = match.start(), match[0]
        if char in ";}":
            if char == "}" and scopes:
                scopes.pop()
            head_start = position = at + 1
            continue
        raw = code[head_start:at]
        access = _ACCESS.match(raw)
        offset = head_start + (access.end() if access else 0)
        head = code[offset:at]
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
            name_at, open_, _ = found
            end = _matching(code, at)
            out.append(Definition(re.sub(r"\s+", "", head[name_at:open_]), "::".join(n for _, n in scopes if n),
                                  bool(scopes) and scopes[-1][0] == "class", at, end))
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


def _items(code: str, start: int, stop: int, single: bool) -> list[tuple[int, int, bool]]:
    out, begin, index, depth = [], start, start, 0
    while index < stop:
        c = code[index]
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


def extern_c_debt(text: str, code: str) -> list[tuple[int, str]]:
    """(1-based line, name) of each `extern "C"` that is linkage debt in a source file: a declaration of a name
    the file does not define (a call-site prototype that belongs in the owner's header), or a C name given to a
    hand-mangled C++ spelling. A definition under `extern "C"` gives what the file owns its C name and is fine."""
    line = _line_index(code)
    mangled = [p.regex for p in CATALOG if p.key.startswith("mangled_")]
    defined, declared, debt = set(), [], []
    for match in _EXTERN_C.finditer(text):
        if code[match.start():match.start() + 6] != "extern":   # in a comment or a string
            continue
        at = match.end()
        block = code[at:at + 1] == "{"
        stop = _matching(code, at) if block else len(code)
        for begin, end, body in _items(code, at + 1 if block else at, stop, single=not block):
            head = _drop_attributes(code[begin:end].split("{", 1)[0] if body else code[begin:end])
            if not head.strip() or _NOT_DECLARED.match(head):
                continue
            initialized = bool(_top_level(head, "="))
            extern = bool(re.match(r"\s*extern\b", head))
            for piece in (head.split("=", 1)[0],) if initialized else \
                    [head[a:b] for a, b in zip([0, *(i + 1 for i in _top_level(head, ","))],
                                               [*_top_level(head, ","), len(head)])]:
                found = _declared(piece)
                if found is None:
                    continue
                name, function = found
                where = line(begin + len(head) - len(head.lstrip()))
                if any(r.fullmatch(name) for r in mangled):
                    debt.append((where, name))
                elif body or initialized or (block and not extern and not function):
                    defined.add(name)
                else:
                    declared.append((where, name))
    if declared:
        inside = []
        for definition in definitions(code):
            defined.add(definition.name.split("::")[-1])
            inside.append((definition.open, definition.end))
        for found in re.finditer(r"\b([A-Za-z_]\w*)\s*(?:\[[^\]\n]*\]\s*)*=(?!=)", code):
            if not any(a < found.start() < b for a, b in inside):
                defined.add(found[1])
        debt += [(where, name) for where, name in declared if name not in defined]
    return sorted(debt)


# --- per-file scan ----------------------------------------------------------------------------------------------

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
    code: str | None = None                     # comment-blanked text, kept for changed files only


def scan_file(rel: str, text: str, keep: bool = False) -> FileScan:
    header = Path(rel).suffix.lower() in HEADER_SUFFIXES
    stripped = strip_comments(text)
    counts, texts = collections.Counter(), collections.Counter()
    code = None
    for pattern in CATALOG:
        if header and pattern.sources_only:
            continue
        if pattern.key == "extern_c":
            if "extern" not in text:
                continue
            code = code or blank(text)
            for _, name in extern_c_debt(text, code):
                counts["extern_c"] += 1
                texts[("extern_c", f'extern "C" {name}')] += 1
            continue
        for match in pattern.regex.finditer(stripped):
            counts[pattern.key] += 1
            texts[(pattern.key, match[0][:80])] += 1

    this_casts, subobject_calls = [], []
    classes: dict[str, set[str]] = collections.defaultdict(set)
    aliases: dict[str, str] = {}
    if any(word in text for word in ("class", "struct", "union", "typedef", "using")):
        code = code or blank(text)
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
        code = code or blank(text)
        if _THIS_CAST.search(code) or re.search(_BYTE_THIS, code):
            line = _line_index(code)
            for definition in definitions(code):
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
    return FileScan(counts, texts, this_casts, subobject_calls, dict(classes), aliases,
                    blank_comments(text) if keep else None)


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


def locate(scan: FileScan, rel: str, text: str) -> list[Finding]:
    """Every catalog finding of a file with its line (only for files the change touches)."""
    code = scan.code if scan.code is not None else blank_comments(text)
    line = _line_index(code)
    header = Path(rel).suffix.lower() in HEADER_SUFFIXES
    out = []
    for pattern in CATALOG:
        if header and pattern.sources_only:
            continue
        if pattern.key == "extern_c":
            if "extern" in text:
                out += [Finding("extern_c", f'extern "C" {name}', where) for where, name in extern_c_debt(text, blank(text))]
            continue
        out += [Finding(pattern.key, m[0][:80], line(m.start())) for m in pattern.regex.finditer(code)]
    return out


# --- reading revisions -------------------------------------------------------------------------------------------

class Repo:
    def __init__(self, git_dir: str | None):
        self.prefix = ["git", "--git-dir", git_dir] if git_dir else ["git", "-C", str(ROOT)]
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

    def diff(self, base: str, head: str, roots: Iterable[str]) -> tuple[list[str], dict[str, set[int]]]:
        """Paths changed between base and head, and the lines head added to each."""
        args = ["diff", "-U0", "--no-renames", "--no-color", "--no-ext-diff", base]
        if head != WORKTREE:
            args.append(head)
        out = self.git(*args, "--", *roots).decode("utf-8", "surrogateescape")
        added: dict[str, set[int]] = {}
        changed, current = [], None
        for line in out.splitlines():
            if line.startswith("diff --git "):
                current = None
            elif line.startswith("--- "):
                old = line[4:]
            elif line.startswith("+++ "):
                path = line[4:]
                current = (path[2:] if path != "/dev/null" else old[2:]).strip('"')
                changed.append(current)
                added.setdefault(current, set())
            elif line.startswith("@@") and current is not None:
                hunk = re.match(r"@@ -\d+(?:,\d+)? \+(\d+)(?:,(\d+))? @@", line)
                if hunk:
                    start, count = int(hunk[1]), int(hunk[2] if hunk[2] is not None else 1)
                    added[current].update(range(start, start + count))
            elif line.startswith("Binary files") and current is None:
                pass
        if head == WORKTREE:
            untracked = self.git("ls-files", "-z", "-o", "--exclude-standard", "--", *roots)
            for rel in untracked.decode("utf-8", "surrogateescape").split("\0"):
                if rel and (ROOT / rel).is_file():
                    changed.append(rel)
                    added[rel] = set(range(1, len((ROOT / rel).read_text(errors="replace").splitlines()) + 2))
        return sorted(set(changed)), added


def source_file(rel: str) -> bool:
    return Path(rel).suffix.lower() in SOURCE_SUFFIXES


# --- symbols.txt and config.yml -------------------------------------------------------------------------------

_SYMBOL = re.compile(r"^(\S+)\s*=\s*([.\w]+):(0x[0-9A-Fa-f]+);\s*//(.*)$")
_PLACEHOLDER = re.compile(r"(?:^|_)(?:fn|func|sub|lbl|FUN|DAT|PTR|dat)_[0-9A-Fa-f]{6,16}|_[0-9A-Fa-f]{8}(?:_|$)|"
                          r"__(?:sub|data)_[0-9A-Fa-f]{6,16}")
_SLOT = re.compile(r"\bvfunc_?\d+(?!\d)|^vf\d+$|__vt\d+(?!\d)")
_FLAT = BY_KEY["flat_name"].regex


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
        flags.append(f"flat C name: as a real member of its class it is mangled ({method}__{len(prefix)}{prefix}"
                     f"{'F...' if kind == 'function' else ''}, for a member of {prefix})")
    if _PLACEHOLDER.search(name):
        flags.append("still named after its address")
    if _SLOT.search(name):
        flags.append("named after a vtable slot")
    return flags


def force_active(text: str) -> list[str]:
    block = re.search(r"^force_active:\n((?:[ \t]*(?:-.*)?\n|[ \t]*#.*\n)*)", text, re.M)
    return [] if not block else [x.strip().strip("\"'") for x in re.findall(r"^\s*-\s*(.+?)\s*$", block[1], re.M)]


def config_review(repo: Repo, base: str, head: str) -> dict:
    """Symbols the change renamed or added (flagged when the name is flat or still a placeholder), and
    force_active entries the change left naming no symbol (added, or stale after a rename)."""
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
            if old and old[0] != name:
                renames.append({**where, "old": old[0], "new": name, "flags": name_flags(name, kind)})
            elif not old and name_flags(name, kind):
                added.append({**where, "name": name, "flags": name_flags(name, kind)})

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

def scan_tree(repo: Repo, rev: str) -> dict[str, FileScan]:
    return {rel: scan_file(rel, text) for rel, text in repo.files(rev, SOURCE_ROOTS, keep=source_file)}


def tree_report(repo: Repo, rev: str, top: int) -> dict:
    scans = scan_tree(repo, rev)
    classes = ClassMap(scans.values())
    totals, owned, per_file = collections.Counter(), collections.Counter(), {}
    for rel, scan in scans.items():
        found = ownership(scan, classes)
        owned.update(f.key for f in found)
        totals.update(scan.counts)
        per_file[rel] = sum(scan.counts.values()) + len(found)
    return {"revision": rev, "files": len(scans), "total": sum(totals.values()),
            "categories": [{"key": p.key, "label": p.label, "group": p.group, "count": totals[p.key]} for p in CATALOG],
            "ownership": [{"key": k, "label": label, "count": owned[k]} for k, label in OWNERSHIP.items()],
            "worst_files": [{"path": rel, "count": n} for rel, n in
                            sorted(per_file.items(), key=lambda item: -item[1])[:top] if n]}


def _multiset(scans: Iterable[FileScan]) -> collections.Counter:
    out = collections.Counter()
    for scan in scans:
        out.update(scan.texts)
    return out


def compare(repo: Repo, base: str, head: str) -> dict:
    changed, added_lines = repo.diff(base, head, SOURCE_ROOTS)
    changed = {p for p in changed if source_file(p)}
    base_text = repo.read(base, sorted(changed))
    head_text, head_scans = {}, {}   # the whole head tree, for totals and the class map
    for rel, text in repo.files(head, SOURCE_ROOTS, keep=source_file):
        head_scans[rel] = scan_file(rel, text, keep=rel in changed)
        if rel in changed:
            head_text[rel] = text
    base_changed = {rel: scan_file(rel, text) for rel, text in base_text.items()}
    base_scans = {rel: s for rel, s in head_scans.items() if rel not in head_text}
    base_scans.update(base_changed)

    head_classes, base_classes = ClassMap(head_scans.values()), ClassMap(base_scans.values())

    # Whole-tree totals: head counted directly, base = head with the changed files swapped back.
    head_totals, base_totals = collections.Counter(), collections.Counter()
    for scan in head_scans.values():
        head_totals.update(scan.counts)
    for scan in base_scans.values():
        base_totals.update(scan.counts)
    head_own = {rel: ownership(scan, head_classes) for rel, scan in head_scans.items()}
    base_own = {rel: ownership(scan, base_classes) for rel, scan in base_scans.items()}
    for found in head_own.values():
        head_totals.update(f.key for f in found)
    for found in base_own.values():
        base_totals.update(f.key for f in found)

    # Added and removed: the change's findings as a multiset of (category, text), so code that only moves
    # (between functions or files) cancels out. Ownership findings can change in files the change did not
    # touch (a class gained or lost a base), so they are compared over the whole tree.
    after = _multiset(head_scans[rel] for rel in head_text)
    before = _multiset(base_changed.values())
    for rel, found in head_own.items():
        after.update((f.key, f.text) for f in found)
    for rel, found in base_own.items():
        before.update((f.key, f.text) for f in found)
    rise = after - before
    fall = before - after
    added, removed = collections.Counter(), collections.Counter()
    for (key, _), n in rise.items():
        added[key] += n
    for (key, _), n in fall.items():
        removed[key] += n

    # Where the new findings are: on lines the change added, as many of each (category, text) as it rose by.
    new = []
    left = collections.Counter(rise)
    candidates = []
    for rel, text in head_text.items():
        lines = added_lines.get(rel, set())
        candidates += [(rel, f) for f in locate(head_scans[rel], rel, text) + head_own.get(rel, []) if f.line in lines]
    for rel, found in head_own.items():
        if rel not in head_text:
            candidates += [(rel, f) for f in found]
    for rel, f in sorted(candidates, key=lambda item: (item[0], item[1].line)):
        if left[(f.key, f.text)] > 0:
            left[(f.key, f.text)] -= 1
            new.append({"key": f.key, "path": rel, "line": f.line, "text": f.text})

    rows = []
    for p in CATALOG:
        rows.append({"key": p.key, "label": p.label, "group": p.group, "base": base_totals[p.key],
                     "head": head_totals[p.key], "added": added[p.key], "removed": removed[p.key]})
    for key, label in OWNERSHIP.items():
        rows.append({"key": key, "label": label, "group": "ownership", "base": base_totals[key],
                     "head": head_totals[key], "added": added[key], "removed": removed[key]})
    debt = [r for r in rows if r["group"] != "ownership"]
    return {
        "version": 1, "base": base, "head": head, "base_commit": repo.commit(base), "head_commit": repo.commit(head),
        "files_changed": len(head_text.keys() | base_text.keys()),
        "categories": rows,
        "total": {k: sum(r[k] for r in debt) for k in ("base", "head", "added", "removed")},
        "ownership_total": {k: sum(r[k] for r in rows if r["group"] == "ownership")
                            for k in ("base", "head", "added", "removed")},
        "new": new, **config_review(repo, base, head),
    }


# --- output ---------------------------------------------------------------------------------------------------------

LABELS = {**{p.key: p.label for p in CATALOG}, **OWNERSHIP}


def print_compare(result: dict, limit: int) -> None:
    total, own = result["total"], result["ownership_total"]
    net = total["head"] - total["base"]
    print(f"Source quality: {result['base']} -> {result['head']} ({result['files_changed']} source files changed)")
    print(f"  debt {net:+,} (removed {total['removed']:,}, added {total['added']:,}); "
          f"tree {total['base']:,} -> {total['head']:,}")
    print(f"  ownership {own['head'] - own['base']:+,} (removed {own['removed']:,}, added {own['added']:,}); "
          f"tree {own['base']:,} -> {own['head']:,}")
    rows = [r for r in result["categories"] if r["added"] or r["removed"] or r["head"] != r["base"]]
    if rows:
        print(f"\n  {'removed':>8} {'added':>7} {'net':>7}  category")
        for r in rows:
            print(f"  {r['removed']:>8,} {r['added']:>7,} {r['head'] - r['base']:>+7,}  {r['label']}")
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
    for r in result["categories"]:
        if r["count"]:
            print(f"  {r['count']:>8,}  {r['label']}")
    print("Ownership (not in the debt total):")
    for r in result["ownership"]:
        print(f"  {r['count']:>8,}  {r['label']}")
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
    if args.git_dir and (args.head == WORKTREE or not (args.base or args.tree)):
        parser.error("--git-dir reads revisions only: pass --base and --head")

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
