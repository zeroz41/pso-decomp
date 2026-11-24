"""misowned_member: member functions that belong to another class.

A fact scanner for C/C++ with no compiler, then a rule over its facts and the config's symbols.txt and splits.txt.
Standard library only. This file is both the decomp's tools/misowned.py (run by tools/source_quality.py, also in CI)
and zkit's zkit/misowned.py (run by `zkit quality`); keep the two copies identical.
"""

from __future__ import annotations

import ast
import bisect
import collections
import operator
import re
import warnings
from typing import Container, Iterable

_MEMBER = re.compile(r"__(\d+)([A-Za-z_]\w*)")   # CodeWarrior's member mangling: name__<length><class>...

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
        free = re.match(r"(\w+?)__F", f[0]) if not f[3] else None
        if free:   # a C++ free function: its callers name it unmangled
            by_key[(None, free[1])].append(f)
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
                     counted: Container[str]) -> dict[str, list[tuple[int, str, str]]]:
    """misowned_member findings (line, key, text) by file, for the files in `counted`: texts are every C/C++ file of
    the revision (the counted roots and the library roots), pairs its (symbols.txt, splits.txt) texts."""
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
        out[rel].append((line, "misowned_member", text))
    return dict(out)
