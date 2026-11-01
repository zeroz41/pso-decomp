#!/usr/bin/env python3
"""Browse standard objdiff reports offline, without inferring original source layout.

Usage: python tools/progress_map.py build/<version>/report.json [...] -o build/progress [--badges DIR]

Writes index.html (the table by unit and function) and treemap.html (one tile per
function or data section, sized by bytes, grouped by the unit's current folder).

The report's matched/complete counters remain authoritative. Complete means
source selected by the build configuration; it does not prove a final hash.
Data includes every section counted by the report, including BSS when present.
"""

import argparse
import json
import math
from pathlib import Path
from typing import Dict

COUNTERS = (
    "total_code", "matched_code", "complete_code", "total_data", "matched_data",
    "complete_data", "total_functions", "matched_functions", "total_units", "complete_units",
)
CODE_SECTIONS = {".text", ".init", ".fini"}
BSS_SECTIONS = {".bss", ".sbss", ".sbss2", ".common"}


def number(value, default=0):
    """Protobuf JSON encodes uint64 as strings and omits zero-valued fields."""
    if value is None:
        return default
    result = float(value)
    if not math.isfinite(result) or result < 0:
        raise ValueError(f"Invalid nonnegative report number: {value!r}")
    return result


def measures(raw):
    return {key: int(number(raw.get(key))) for key in COUNTERS}


def add_measures(target, source):
    for key in COUNTERS:
        target[key] += source[key]


def section_kind(name):
    if name in CODE_SECTIONS:
        return "code"
    if name in BSS_SECTIONS:
        return "bss"
    return "initialized_data"


def normalize_report(report: Dict, version: str) -> Dict:
    """Use real modules, current objects and original function addresses."""
    root = {"id": "root", "name": version, "kind": "directory", "children": [], "measures": measures({})}
    modules = {}
    function_ids = set()
    for index, unit in enumerate(report.get("units", [])):
        metadata = unit.get("metadata") or {}
        unit_name = str(unit.get("name", f"unit-{index}"))
        module = str(metadata.get("module_name") or unit_name.split("/")[0] or "main")
        source = metadata.get("source_path")
        path = str(source or unit_name).replace("\\", "/").strip("/")
        selected = metadata.get("complete") is True
        leaf = {
            "id": f"unit-{index}", "name": path.rsplit("/", 1)[-1], "kind": "unit", "unit_name": unit_name,
            "path": str(source or unit_name), "module": module, "source_path": source,
            "source_selected": selected, "measures": measures(unit.get("measures") or {}),
            "similarity": number((unit.get("measures") or {}).get("fuzzy_match_percent")),
            "sections": [], "functions": [],
        }
        for section_index, section in enumerate(unit.get("sections", [])):
            name = str(section.get("name", "(unnamed)"))
            size = int(number(section.get("size")))
            similarity = number(section.get("fuzzy_match_percent"))
            entry = {"name": name, "size": size, "kind": section_kind(name), "similarity": similarity,
                     "exact": similarity == 100, "source_selected": selected,
                     "address": (section.get("metadata") or {}).get("virtual_address"),
                     "id": f"section-{index}-{section_index}"}
            leaf["sections"].append(entry)
        for function in unit.get("functions", []):
            function_name = str(function.get("name", "(unnamed)"))
            function_metadata = function.get("metadata") or {}
            similarity = number(function.get("fuzzy_match_percent"))
            address = function_metadata.get("virtual_address")
            if address is None:
                raise ValueError(f"No original address for {unit_name}:{function_name}")
            module_key = metadata.get("module_id", module)
            identity = f"function:{module_key}:{int(number(address))}"
            if identity in function_ids:
                raise ValueError(f"Duplicate original function address: {identity}")
            function_ids.add(identity)
            leaf["functions"].append({
                "id": identity, "name": function_name,
                "display_name": str(function_metadata.get("demangled_name") or function_name),
                "size": int(number(function.get("size"))), "similarity": similarity,
                "exact": similarity == 100, "source_selected": selected,
                "address": function_metadata.get("virtual_address"),
            })
        addresses = [int(f["address"]) for f in leaf["functions"]]
        if not addresses:
            addresses = [int(s["address"]) for s in leaf["sections"] if s["address"] is not None]
        leaf["address"] = min(addresses) if addresses else None
        add_measures(root["measures"], leaf["measures"])
        if module not in modules:
            modules[module] = {"id": "module:" + module, "name": module, "kind": "module",
                               "children": [], "measures": measures({})}
            root["children"].append(modules[module])
        add_measures(modules[module]["measures"], leaf["measures"])
        modules[module]["children"].append(leaf)
    reported = measures(report.get("measures") or {})
    differences = {key: {"report": reported[key], "unit_sum": root["measures"][key]}
                   for key in COUNTERS if reported[key] != root["measures"][key]}
    return {
        "schema_version": 2, "version": version, "objdiff_report_version": report.get("version"),
        "objdiff_measures": report.get("measures") or {}, "measures": reported,
        "similarity": number((report.get("measures") or {}).get("fuzzy_match_percent")),
        "unit_sum_differences": differences, "tree": root,
    }


PAGE = r'''<!doctype html>
<html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<title>PSO objdiff report</title>
<style>
:root{color-scheme:dark}*{box-sizing:border-box}body{margin:0;background:#181b20;color:#eceff2;font:14px/1.5 system-ui,sans-serif}main{max-width:1440px;margin:auto;padding:24px}h1{font-size:24px;margin:0}p{margin:10px 0}.muted,small{color:#adb6c1}a{color:#9ec9f5}button,select,input{font:inherit;color:inherit;background:#242930;border:1px solid #454d58;border-radius:3px;padding:6px 9px}button{cursor:pointer}button:hover{background:#38414c}button:focus-visible,input:focus-visible,select:focus-visible{outline:2px solid #91c4fb;outline-offset:2px}.controls{display:flex;gap:12px;align-items:end;flex-wrap:wrap;margin:18px 0}label{display:grid;gap:3px;color:#adb6c1;font-size:12px}#search{min-width:240px}#scope-note{border-left:3px solid #789abc;padding-left:10px}.numbers{display:flex;gap:28px;flex-wrap:wrap;margin:18px 0}.numbers strong{font-size:20px;margin-right:8px}#breadcrumbs{display:flex;gap:8px;align-items:center;flex-wrap:wrap}#breadcrumbs button{padding:3px 8px}#detail{min-height:46px;overflow-wrap:anywhere;color:#adb6c1}.tablewrap{overflow:auto;border:1px solid #454d58}table{border-collapse:collapse;width:100%;font-size:13px;text-align:right}th,td{padding:8px 11px;border-bottom:1px solid #343b44;white-space:nowrap}th{background:#242930}th button{padding:0;background:none;border:0}th:first-child,td:first-child{text-align:left}td:first-child{max-width:580px;white-space:normal;overflow-wrap:anywhere}td button{color:#b8d8f9;padding:0;background:none;border:0;text-align:left}td small{display:block}.meter{display:block;height:4px;background:#414750;margin:4px 0}.meter span{display:block;height:100%;background:#468bd2}.linked span{background:#3b984c}tbody tr:hover{background:#252d37}#pager{display:flex;gap:12px;align-items:center;margin:15px 0}#warning{color:#eab968}details{margin-top:18px}footer{margin-top:20px;color:#adb6c1;font-size:12px}@media(max-width:700px){main{padding:12px}h1{font-size:21px}.numbers{gap:12px}.numbers strong{font-size:17px}#search{min-width:180px}}
</style></head><body><main>
<h1>PSO objdiff report</h1>
<p class="muted">Episode I &amp; II Plus · USA v1.02 · <a href="treemap.html">Treemap</a></p>
<p id="scope-note"></p>
<div class="controls">
<label>Executable / module<select id="scope"></select></label>
<label>Measure<select id="metric"><option value="code">Code</option><option value="data">Data + BSS</option></select></label>
<label>View<select id="view"><option value="objects">Current objects</option><option value="entries">Functions</option></select></label>
<label>Show<select id="filter"><option value="all">Everything</option><option value="unmatched">Needs matching</option><option value="unlinked">Not fully linked</option><option value="matched-unlinked">Exact, not linked</option></select></label>
<label>Search<input id="search" type="search" placeholder="Symbol, source file, 0x800…"></label><button id="reset">Reset</button>
</div>
<nav id="breadcrumbs" aria-label="Current object"></nav>
<div id="numbers" class="numbers" aria-live="polite"></div>
<p>Objects below are the current build splits. Source paths and object counts do not establish original TU boundaries or recovered game modules.</p>
<div id="detail"></div>
<p id="shown" class="muted"></p>
<div class="tablewrap"><table><thead><tr>
<th><button data-sort="name">Object / function</button></th><th><button data-sort="address">Original address</button></th>
<th><button data-sort="total">Bytes</button></th><th><button data-sort="matched">Matched</button></th><th><button data-sort="complete">Linked</button></th><th><button data-sort="remaining">Unmatched bytes ↓</button></th><th>Exact functions</th>
</tr></thead><tbody id="rows"></tbody></table></div>
<div id="pager"><button id="previous">Previous</button><span id="page"></span><button id="next">Next</button></div>
<p id="empty" hidden>No entries in this view.</p><p id="warning"></p>
<details><summary>Report definitions and folding</summary>
<p>Matched bytes are objdiff's exact-match counters. Linked bytes are selected from compiled source by the build; Ninja checks the output hash. A partly matched object retains its actual matched byte count.</p>
<p>A fold can combine several current objects. Rebuild the report to see the new ownership. Functions retain their original module/address identity when renamed or moved. Compare saved reports with <code>tools/report_delta.py BEFORE AFTER --check</code> to check exact functions and original data intervals, including linked coverage.</p>
<p>Inside an object, code rows are functions and data rows are sections. Their summed sizes can differ from the object counters because of padding. BSS describes zero-initialized storage. Function and object counts are not measures of recovered original TU boundaries.</p>
<p>Search and filters affect the table; the totals above it describe the selected module or object. Runtime asset verification is separate from these code/data counters.</p>
</details><footer id="exports"></footer>
</main><script id="reports" type="application/json">__REPORT_DATA__</script><script>
'use strict';
const reports=JSON.parse(document.getElementById('reports').textContent),$=id=>document.getElementById(id);
const fmt=n=>Number(n||0).toLocaleString('en-US'),percent=(n,d)=>d?(100*n/d).toFixed(2)+'%':'—';
const address=n=>n===null||n===undefined?'—':'0x'+Number(n).toString(16).toUpperCase().padStart(8,'0');
function el(tag,text,attrs={}){const n=document.createElement(tag);if(text!==undefined)n.textContent=text;for(const[k,v]of Object.entries(attrs))n.setAttribute(k,v);return n;}
let current,base,selected=null,metric='code',query='',filter='all',view='objects',sort='remaining',descending=true,page=0;
const scopes=[],pageSize=100;
function amount(n,kind='total'){return n.measures[kind+'_'+metric]||0;}
function entries(unit){return (metric==='code'?unit.functions:unit.sections.filter(s=>s.kind!=='code')).map(f=>({...f,kind:metric==='code'?'function':'section',owner:unit,path:unit.path,source_path:unit.source_path,measures:{['total_'+metric]:f.size,['matched_'+metric]:f.exact?f.size:0,['complete_'+metric]:unit.source_selected?f.size:0,total_functions:metric==='code'?1:0,matched_functions:metric==='code'&&f.exact?1:0}}));}
function permitted(n){const t=amount(n);return t>0&&(filter==='all'||filter==='unmatched'&&amount(n,'matched')<t||filter==='unlinked'&&amount(n,'complete')<t||filter==='matched-unlinked'&&amount(n,'matched')===t&&amount(n,'complete')<t);}
function matches(n){return !query||[n.name,n.display_name,n.path,n.unit_name,address(n.address)].join(' ').toLowerCase().includes(query);}
function results(){
 const units=selected?[selected]:base.children,out=[];
 for(const u of units){if(selected||view==='entries'){out.push(...entries(u).filter(n=>permitted(n)&&matches(n)));continue;}
  if(permitted(u)&&matches(u)){out.push(u);continue;}
  if(query)out.push(...entries(u).filter(n=>permitted(n)&&matches(n)));
 }return out;
}
function inspect(n){$('detail').replaceChildren(el('strong',n.display_name||n.unit_name||n.name),el('div',address(n.address)+' · '+fmt(amount(n))+' bytes · '+(n.owner?'Current object: '+n.owner.unit_name:n.path)),el('div','Matched: '+fmt(amount(n,'matched'))+' · Linked: '+fmt(amount(n,'complete'))));}
function visit(n){if(n.kind==='unit'){selected=n;query='';$('search').value='';page=0;render();}else inspect(n);}
function render(){
 const node=selected||base,nodes=results();
 $('breadcrumbs').replaceChildren();const back=el('button',base.name);back.onclick=()=>{selected=null;page=0;render();};$('breadcrumbs').append(back);if(selected)$('breadcrumbs').append(el('span','/'),el('span',selected.unit_name));
 $('numbers').replaceChildren();for(const[label,n,d]of[['Matched '+metric,amount(node,'matched'),amount(node)],['Linked '+metric,amount(node,'complete'),amount(node)],['Exact functions',node.measures.matched_functions,node.measures.total_functions]]){const box=el('div');box.append(el('strong',percent(n,d)),el('span',label),el('div',fmt(n)+' / '+fmt(d)+(label==='Exact functions'?'':' bytes'),{class:'muted'}));$('numbers').append(box);}
 const value=n=>sort==='address'?(n.address??Number.MAX_SAFE_INTEGER):sort==='remaining'?amount(n)-amount(n,'matched'):sort==='total'?amount(n):amount(n,sort)/amount(n);
 nodes.sort((a,b)=>((sort==='name'?(a.display_name||a.name).localeCompare(b.display_name||b.name):value(a)-value(b))*(descending?-1:1))||((a.address??0)-(b.address??0))||a.id.localeCompare(b.id));
 const pages=Math.max(1,Math.ceil(nodes.length/pageSize));page=Math.min(page,pages-1);$('page').textContent=(page+1)+' / '+pages;$('previous').disabled=page===0;$('next').disabled=page+1===pages;
 $('shown').textContent=fmt(nodes.length)+' entries · '+fmt(nodes.reduce((s,n)=>s+amount(n),0))+' bytes in table'+(query||filter!=='all'?' (filtered)':'');$('empty').hidden=nodes.length>0;$('rows').replaceChildren();
 for(const n of nodes.slice(page*pageSize,(page+1)*pageSize)){const tr=el('tr'),name=el('td'),b=el('button',n.display_name||n.name);b.onclick=()=>visit(n);name.append(b);if(n.path)name.append(el('small',n.path));tr.append(name,el('td',address(n.address)),el('td',fmt(amount(n))));for(const kind of ['matched','complete']){const td=el('td',percent(amount(n,kind),amount(n))),meter=el('span',undefined,{class:'meter'+(kind==='complete'?' linked':'')}),fill=el('span');fill.style.width=100*amount(n,kind)/amount(n)+'%';meter.append(fill);td.append(meter,el('small',fmt(amount(n,kind))+' bytes'));tr.append(td);}tr.append(el('td',fmt(amount(n)-amount(n,'matched'))),el('td',n.measures.total_functions?fmt(n.measures.matched_functions)+' / '+fmt(n.measures.total_functions):'—'));$('rows').append(tr);}
 $('warning').textContent=Object.keys(current.unit_sum_differences).length?'Report totals differ from unit sums. Module/object views use the current units; the downloaded report retains its original aggregates.':'';
 $('view').disabled=!!selected;$('view').options[1].textContent=metric==='code'?'Functions':'Data sections';if(selected)inspect(selected);else $('detail').textContent='Select an object to inspect its functions or data sections. Search also finds symbols inside objects.';
}
function selectScope(index){const s=scopes[index];current=s.report;base=s.node;selected=null;query='';page=0;$('search').value='';$('scope-note').textContent=s.aux?'Outside project scope: auxiliary executable retained for disc reconstruction.':base.name==='movie'?'movie.rel · Main-game code module, separate from PsoV3.':'PsoV3.dol · Main game; auxiliary DOLs are outside project scope.';$('exports').replaceChildren(el('span','Source: '+current.version+'/report.json · '),el('a','Download original objdiff report',{href:current.file_stem+'.json',download:''}));render();}
const main=el('optgroup',undefined,{label:'Main game'}),aux=el('optgroup',undefined,{label:'Outside project scope'});
for(const report of reports)for(const node of report.tree.children){const outside=/_(BOOT|SWITCHERD?|IWANAGAD?)$/.test(report.version)||report.version==='GPOE8P-main'||node.name==='boot';const i=scopes.length;scopes.push({report,node,aux:outside});(outside?aux:main).append(el('option',node.name+' · '+report.version,{value:i}));}
if(main.children.length)$('scope').append(main);if(aux.children.length)$('scope').append(aux);
$('scope').onchange=()=>selectScope(Number($('scope').value));for(const id of ['metric','view','filter'])$(id).onchange=()=>{metric=$('metric').value;view=$('view').value;filter=$('filter').value;page=0;render();};$('search').oninput=()=>{query=$('search').value.trim().toLowerCase();page=0;render();};$('reset').onclick=()=>{filter='all';view='objects';$('filter').value=filter;$('view').value=view;selectScope(Number($('scope').value));};$('previous').onclick=()=>{page--;render();};$('next').onclick=()=>{page++;render();};
document.querySelectorAll('[data-sort]').forEach(b=>b.onclick=()=>{const key=b.dataset.sort;descending=sort===key?!descending:!['name','address'].includes(key);sort=key;page=0;document.querySelectorAll('[data-sort]').forEach(x=>x.textContent=x.textContent.replace(/ [↑↓]$/,''));b.textContent+=' '+(descending?'↓':'↑');render();});
const first=scopes.findIndex(s=>s.node.name.toLowerCase()==='psov3');if(scopes.length){$('scope').value=String(first>=0?first:0);selectScope(Number($('scope').value));}else{$('empty').hidden=false;$('empty').textContent='No report units.';}
</script></body></html>
'''


TREEMAP_WIDTH, TREEMAP_HEIGHT = 1600, 1000
TREEMAP_HEADER = 15


def treemap_area(unit_name):
    """The folder a unit sits in, at most two levels below its module, read from its current path."""
    parts = str(unit_name).replace("\\", "/").split("/")
    folders = parts[1:-1][:2]
    if folders:
        return "/".join(folders)
    return "unclaimed data" if parts[-1].startswith("auto_") else parts[0]


def treemap_state(similarity, linked):
    """0 linked, 1 matched, 2 near (>= 90%), 3 partial (>= 50%), 4 started, 5 not started."""
    if similarity >= 100:
        return 0 if linked else 1
    return 2 if similarity >= 90 else 3 if similarity >= 50 else 4 if similarity > 0 else 5


def naming_tier(name):
    """0 named, 1 class-attributed placeholder (Class::sub_...), 2 placeholder (fn_, lbl_, @)."""
    if name.startswith(("fn_", "lbl_", "@")):
        return 2
    return 1 if "__sub_" in name else 0


def squarify(items, x, y, w, h):
    """Lay items (dicts with "size", largest first) out in the rectangle; sets item["rect"]."""
    total = sum(item["size"] for item in items)
    if total <= 0 or w <= 0 or h <= 0:
        for item in items:
            item["rect"] = (x, y, 0, 0)
        return
    scale = w * h / total
    rest = list(items)
    while rest:
        side = min(w, h)
        row, row_area, worst = [], 0.0, math.inf
        while rest:
            area = rest[0]["size"] * scale
            areas = [item["size"] * scale for item in row] + [area]
            total_area = row_area + area
            ratio = max(max(side * side * a / (total_area * total_area), total_area * total_area / (side * side * a))
                        for a in areas)
            if row and ratio > worst:
                break
            row.append(rest.pop(0))
            row_area, worst = total_area, ratio
        thickness = row_area / side
        offset = 0.0
        for item in row:
            length = item["size"] * scale / thickness
            item["rect"] = (x, y + offset, thickness, length) if w >= h else (x + offset, y, length, thickness)
            offset += length
        if w >= h:
            x, w = x + thickness, w - thickness
        else:
            y, h = y + thickness, h - thickness


def treemap_layout(units) -> Dict:
    """Nest tiles in their unit and area.

    Every tile is [x, y, w, h, state, tier, bytes, address, unit, name, linked, similarity].
    """
    areas = {}
    for unit in units:
        if unit["tiles"]:
            area = areas.setdefault(treemap_area(unit["name"]), [])
            area.append({**unit, "size": sum(t["size"] for t in unit["tiles"])})
    groups = sorted(({"name": name, "units": members, "size": sum(u["size"] for u in members)}
                     for name, members in areas.items()), key=lambda g: (-g["size"], g["name"]))
    squarify(groups, 0, 0, TREEMAP_WIDTH, TREEMAP_HEIGHT)
    names, unit_rects, tiles, area_rows = [], [], [], []
    for group in groups:
        x, y, w, h = group["rect"]
        header = TREEMAP_HEADER if w > 60 and h > 3 * TREEMAP_HEADER else 0
        group["units"].sort(key=lambda u: (-u["size"], u["name"]))
        squarify(group["units"], x + 1, y + header, w - 2, h - header - 1)
        counts = {"bytes": 0, "matched": 0, "linked": 0, "items": 0, "exact": 0, "placeholders": 0}
        for unit in group["units"]:
            unit_rects.append([round(v, 2) for v in unit["rect"]])
            names.append(unit["name"].split("/", 1)[-1])
            unit["tiles"].sort(key=lambda t: (-t["size"], t["address"]))
            squarify(unit["tiles"], *unit["rect"])
            for t in unit["tiles"]:
                tiles.append([*(round(v, 2) for v in t["rect"]), t["state"], t["tier"], t["size"], t["address"],
                              len(names) - 1, t["name"], int(t["linked"]), round(t["similarity"], 2)])
                counts["bytes"] += t["size"]
                counts["items"] += 1
                counts["matched"] += t["size"] if t["state"] < 2 else 0
                counts["linked"] += t["size"] if t["linked"] else 0
                counts["exact"] += t["state"] < 2
                counts["placeholders"] += t["tier"] == 2
        area_rows.append([group["name"], *(round(v, 2) for v in group["rect"]), counts])
    return {"areas": area_rows, "units": names, "unit_rects": unit_rects, "tiles": tiles}


def treemap_data(report: Dict) -> Dict:
    """Code (one tile per function) and data (one tile per data section) treemaps of a report."""
    code, data = [], []
    for unit in report.get("units", []):
        metadata = unit.get("metadata") or {}
        name, linked = str(unit.get("name", "?")), metadata.get("complete") is True
        functions, sections = [], []
        for function in unit.get("functions") or []:
            function_metadata = function.get("metadata") or {}
            functions.append({
                "size": int(number(function.get("size"))),
                "name": str(function_metadata.get("demangled_name") or function.get("name", "?")),
                "address": int(number(function_metadata.get("virtual_address"))),
                "similarity": number(function.get("fuzzy_match_percent")), "linked": linked,
                "state": treemap_state(number(function.get("fuzzy_match_percent")), linked),
                "tier": naming_tier(str(function.get("name", ""))),
            })
        for section in unit.get("sections") or []:
            if section_kind(str(section.get("name"))) == "code":
                continue
            sections.append({
                "size": int(number(section.get("size"))), "name": str(section.get("name", "?")),
                "address": int(number((section.get("metadata") or {}).get("virtual_address"))),
                "similarity": number(section.get("fuzzy_match_percent")), "linked": linked,
                "state": treemap_state(number(section.get("fuzzy_match_percent")), linked), "tier": 0,
            })
        code.append({"name": name, "tiles": [f for f in functions if f["size"] > 0]})
        data.append({"name": name, "tiles": [s for s in sections if s["size"] > 0]})
    m = measures(report.get("measures") or {})
    functions = [t for unit in code for t in unit["tiles"]]
    layouts = {"code": treemap_layout(code), "data": treemap_layout(data)}
    # The tiles must account for every counted byte; say so on the page if they ever do not.
    sums = {
        "total_code": "code", "matched_code": "code", "complete_code": "code",
        "total_data": "data", "matched_data": "data", "complete_data": "data",
    }
    warnings = []
    for key, mode in sums.items():
        tiles = layouts[mode]["tiles"]
        value = sum(t[6] for t in tiles if key.startswith("total") or
                    (t[10] if key.startswith("complete") else t[4] < 2))
        if value != m[key]:
            warnings.append(f"{key}: report {m[key]:,}, tiles {value:,}")
    if len(functions) != m["total_functions"] or sum(f["state"] < 2 for f in functions) != m["matched_functions"]:
        warnings.append(f"functions: report {m['matched_functions']:,} of {m['total_functions']:,}, tiles "
                        f"{sum(f['state'] < 2 for f in functions):,} of {len(functions):,}")
    return {
        "width": TREEMAP_WIDTH, "height": TREEMAP_HEIGHT, "measures": m, "layouts": layouts, "warnings": warnings,
        "named": sum(f["tier"] == 0 for f in functions),
    }


TREEMAP_PAGE = r"""<!doctype html>
<html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<title>PSO progress treemap</title>
<style>
:root{color-scheme:dark}*{box-sizing:border-box}body{margin:0;background:#181b20;color:#eceff2;font:14px/1.5 system-ui,sans-serif}main{max-width:1640px;margin:auto;padding:24px}h1{font-size:24px;margin:0}p{margin:10px 0}.muted{color:#adb6c1}a{color:#9ec9f5}select,input{font:inherit;color:inherit;background:#242930;border:1px solid #454d58;border-radius:3px;padding:6px 9px}input:focus-visible,select:focus-visible{outline:2px solid #91c4fb;outline-offset:2px}.bars{display:grid;grid-template-columns:repeat(auto-fill,minmax(260px,1fr));gap:14px 28px;margin:18px 0}.bar div{display:flex;justify-content:space-between;gap:8px;font-size:12px;color:#adb6c1;margin-bottom:3px}.bar b{color:#eceff2}.track{display:block;height:8px;background:#343b44;border-radius:4px;overflow:hidden}.track span{display:block;height:100%;border-radius:4px}.controls{display:flex;gap:12px;align-items:end;flex-wrap:wrap;margin:14px 0}label{display:grid;gap:3px;color:#adb6c1;font-size:12px}#search{min-width:260px}.legend{display:flex;gap:6px 16px;flex-wrap:wrap;font-size:12px;color:#adb6c1;margin:8px 0 12px}.legend i{display:inline-block;width:11px;height:11px;border-radius:2px;margin-right:5px;vertical-align:-1px}canvas{display:block;width:100%;height:auto;border:1px solid #454d58;background:#0f1114}#warning{color:#eab968}#tip{position:fixed;pointer-events:none;background:#242930;border:1px solid #454d58;border-radius:4px;padding:7px 9px;font-size:12px;max-width:440px;overflow-wrap:anywhere;display:none;z-index:2}#tip b{display:block;color:#eceff2}#tip span{display:block;color:#adb6c1;font-family:ui-monospace,monospace}@media(max-width:700px){main{padding:12px 16px}h1{font-size:21px}#search{min-width:0;width:100%}}
</style></head><body><main>
<h1>PSO progress treemap</h1>
<p class="muted">Episode I &amp; II Plus · USA v1.02 · <a href="index.html">Table by unit and function</a></p>
<div id="bars" class="bars"></div>
<p id="warning"></p>
<p class="muted" id="about"></p>
<div class="controls">
<label>Measure<select id="mode"><option value="code">Code</option><option value="data">Data</option></select></label>
<label>Colour<select id="colour"><option value="state">Progress</option><option value="names">Progress and names</option></select></label>
<label>Search<input id="search" type="search" placeholder="Function, section, unit or 0x800…"></label>
<span id="found" class="muted"></span>
</div>
<div id="legend" class="legend"></div>
<canvas id="canvas"></canvas>
<div id="tip"></div>
</main>
<script type="application/json" id="data">__TREEMAP_DATA__</script>
<script>
'use strict';
const D=JSON.parse(document.getElementById('data').textContent),M=D.measures,$=id=>document.getElementById(id);
const fmt=n=>Number(n).toLocaleString('en-US'),pct=(n,d)=>d?(100*n/d).toFixed(2)+'%':'—';
const STATES=[['#3b984c','Linked'],['#8bc34a','Matched, not linked'],['#d2a922','90% or more'],['#9a6f12','50% to 90%'],['#5c4310','Started'],['#2c3139','Not started']];
const NAMED=[['#3b984c','Matched, named'],['#a3b52b','Matched, Class::sub_ name'],['#468bd2','Matched, placeholder name']];
const canvas=$('canvas'),ctx=canvas.getContext('2d'),tip=$('tip');
let mode=location.hash==='#data'?'data':'code',colour='state',hits=null,scale=1,L=D.layouts[mode];
for(const[label,part,whole,count,c]of[['Code matched',M.matched_code,M.total_code,0,'#3b984c'],['Code linked',M.complete_code,M.total_code,0,'#2f7d3e'],
  ['Functions matched',M.matched_functions,M.total_functions,1,'#3b984c'],['Data matched',M.matched_data,M.total_data,0,'#d2a922'],
  ['Data linked',M.complete_data,M.total_data,0,'#9a7a1a'],['Units linked',M.complete_units,M.total_units,1,'#2f7d3e'],
  ['Functions named',D.named,M.total_functions,1,'#468bd2']]){
  const bar=document.createElement('div'),top=document.createElement('div'),name=document.createElement('span'),value=document.createElement('b'),track=document.createElement('span'),fill=document.createElement('span');
  bar.className='bar';track.className='track';name.textContent=label+(count?' ('+fmt(part)+' of '+fmt(whole)+')':'');value.textContent=pct(part,whole);
  fill.style.width=(whole?100*part/whole:0)+'%';fill.style.background=c;track.append(fill);top.append(name,value);bar.append(top,track);$('bars').append(bar);}
$('warning').textContent=D.warnings.length?'The tiles do not add up to the report: '+D.warnings.join('; '):'';
function palette(){return mode==='code'&&colour==='names'?[...NAMED,...STATES.slice(2)]:STATES;}
function fill(t){if(t[4]<2&&mode==='code'&&colour==='names')return NAMED[t[5]][0];return STATES[t[4]][0];}
function describe(t){return (t[4]<2?'matched':t[11].toFixed(2)+'% match')+(t[10]?', linked':', not linked');}
function legend(){const l=$('legend');l.textContent='';for(const[c,n]of palette()){const s=document.createElement('span'),i=document.createElement('i');i.style.background=c;s.append(i,n);l.append(s);}
  $('about').textContent=mode==='code'?'One tile per function, sized by its bytes, inside its current unit and that unit\'s folder.':'One tile per data section (.data, .rodata, .bss, …), sized by its bytes, inside its current unit and that unit\'s folder.';}
function header(a){const c=a[5],kind=mode==='code'?' fns':' sections';
  return a[0]+' — '+pct(c.matched,c.bytes)+' matched · '+pct(c.linked,c.bytes)+' linked · '+fmt(c.exact)+'/'+fmt(c.items)+kind+(mode==='code'&&c.placeholders?' · '+fmt(c.placeholders)+' unnamed':'');}
function draw(){
  const ratio=window.devicePixelRatio||1,width=canvas.clientWidth;scale=width/D.width;
  canvas.width=Math.round(width*ratio);canvas.height=Math.round(D.height*scale*ratio);canvas.style.height=(D.height*scale)+'px';
  ctx.setTransform(ratio*scale,0,0,ratio*scale,0,0);ctx.fillStyle='#0f1114';ctx.fillRect(0,0,D.width,D.height);
  for(const t of L.tiles){ctx.globalAlpha=hits&&!hits.has(t)?0.12:1;ctx.fillStyle=fill(t);ctx.fillRect(t[0],t[1],t[2],t[3]);}
  ctx.globalAlpha=1;ctx.strokeStyle='rgba(15,17,20,.6)';ctx.lineWidth=0.6/scale;
  for(const r of L.unit_rects)if(r[2]*scale>4&&r[3]*scale>4)ctx.strokeRect(r[0],r[1],r[2],r[3]);
  const text=Math.min(10.5,12*scale);ctx.strokeStyle='#0f1114';ctx.lineWidth=2/scale;ctx.font=(text/scale)+'px system-ui,sans-serif';ctx.textBaseline='top';
  for(const a of L.areas){const[,x,y,w,h]=a;ctx.strokeRect(x,y,w,h);if(text>=7&&w*scale>60&&h>45){ctx.fillStyle='#0f1114';ctx.fillRect(x,y,w,15);ctx.fillStyle='#d5dae0';ctx.save();ctx.beginPath();ctx.rect(x,y,w,15);ctx.clip();ctx.fillText(header(a),x+3,y+2);ctx.restore();}}
}
function at(e){const r=canvas.getBoundingClientRect(),x=(e.clientX-r.left)/scale,y=(e.clientY-r.top)/scale;
  for(const t of L.tiles)if(x>=t[0]&&x<t[0]+t[2]&&y>=t[1]&&y<t[1]+t[3])return['tile',t];
  for(const a of L.areas)if(x>=a[1]&&x<a[1]+a[3]&&y>=a[2]&&y<a[2]+a[4])return['area',a];return null;}
canvas.addEventListener('mousemove',e=>{const hit=at(e);if(!hit){tip.style.display='none';return;}
  tip.textContent='';const b=document.createElement('b'),a=document.createElement('span'),u=document.createElement('span');
  if(hit[0]==='tile'){const t=hit[1];b.textContent=t[9];a.textContent='0x'+t[7].toString(16).toUpperCase().padStart(8,'0')+' · '+fmt(t[6])+' bytes · '+describe(t);u.textContent=L.units[t[8]];}
  else{b.textContent=hit[1][0];a.textContent=header(hit[1]).slice(hit[1][0].length+3);}
  tip.append(b,a,u);tip.style.display='block';const w=tip.offsetWidth,h=tip.offsetHeight;
  tip.style.left=Math.max(8,Math.min(e.clientX+14,innerWidth-w-8))+'px';tip.style.top=(e.clientY+h+22>innerHeight?e.clientY-h-10:e.clientY+14)+'px';});
canvas.addEventListener('mouseleave',()=>tip.style.display='none');
function search(){const q=$('search').value.trim().toLowerCase();
  if(!q){hits=null;$('found').textContent='';return;}const address=/^0x[0-9a-f]+$/.test(q)?parseInt(q,16):null;
  hits=new Set(L.tiles.filter(t=>address!==null?address>=t[7]&&address<t[7]+t[6]:t[9].toLowerCase().includes(q)||L.units[t[8]].toLowerCase().includes(q)));
  $('found').textContent=fmt(hits.size)+(mode==='code'?' functions':' sections');}
function setMode(m){mode=m;L=D.layouts[mode];$('mode').value=mode;$('colour').disabled=mode!=='code';search();legend();draw();}
$('mode').addEventListener('change',e=>{history.replaceState(null,'',e.target.value==='data'?'#data':location.pathname);setMode(e.target.value);});
$('colour').addEventListener('change',e=>{colour=e.target.value;legend();draw();});
$('search').addEventListener('input',()=>{search();draw();});
addEventListener('resize',draw);setMode(mode);
</script></body></html>
"""


def render_treemap(report: Dict) -> str:
    data = json.dumps(treemap_data(report), ensure_ascii=True, separators=(",", ":")).replace("<", "\\u003c")
    return TREEMAP_PAGE.replace("__TREEMAP_DATA__", data)


def render_page(reports):
    # A script element is raw text even for application/json; escape '<' to keep
    # report symbol names from closing it. DOM rendering uses textContent.
    data = json.dumps(reports, ensure_ascii=True, separators=(",", ":")).replace("<", "\\u003c")
    return PAGE.replace("__REPORT_DATA__", data)


def generate(report_paths, output, width=1280, height=720) -> Path:
    """Write offline artifacts and return their index; never invokes a build."""
    paths = [Path(path) for path in report_paths]
    output = Path(output)
    if not paths:
        raise ValueError("at least one report is required")
    if width <= 0 or height <= 0:
        raise ValueError("width and height must be positive")
    versions = [path.parent.name for path in paths]
    if len(versions) != len(set(versions)):
        raise ValueError("report parent-directory names must be unique")
    reports = []
    output.mkdir(parents=True, exist_ok=True)
    for path, version in zip(paths, versions):
        report = json.loads(path.read_text(encoding="utf-8"))
        normalized = normalize_report(report, version)
        normalized["file_stem"] = version
        for name in (f"{version}.svg", f"{version}-data.svg"):
            (output / name).unlink(missing_ok=True)
        (output / f"{version}.json").write_text(json.dumps(report, indent=2) + "\n", encoding="utf-8")
        reports.append(normalized)
    index = output / "index.html"
    index.write_text(render_page(reports), encoding="utf-8")
    first = json.loads(paths[0].read_text(encoding="utf-8"))
    (output / "treemap.html").write_text(render_treemap(first), encoding="utf-8")
    return index


def badge_color(percent):
    for floor, color in ((100, "brightgreen"), (90, "green"), (75, "yellowgreen"), (50, "yellow"), (25, "orange")):
        if percent >= floor:
            return color
    return "red"


def badges(report: Dict) -> Dict[str, Dict]:
    """shields.io endpoint badges for the README, from a report's top-level counters."""
    m = measures(report.get("measures", {}))

    def pct(part, whole):
        return 100 * part / whole if whole else 0.0

    def badge(label, percent, count=None):
        message = f"{percent:.2f}%"
        if count:
            message += f" ({count[0]:,} of {count[1]:,})"
        return {"schemaVersion": 1, "label": label, "message": message, "color": badge_color(percent)}

    return {
        "code": badge("code matched", pct(m["matched_code"], m["total_code"])),
        "code-linked": badge("code linked", pct(m["complete_code"], m["total_code"])),
        "data": badge("data matched", pct(m["matched_data"], m["total_data"])),
        "data-linked": badge("data linked", pct(m["complete_data"], m["total_data"])),
        "functions": badge("functions matched", pct(m["matched_functions"], m["total_functions"]),
                           (m["matched_functions"], m["total_functions"])),
        "units-linked": badge("units linked", pct(m["complete_units"], m["total_units"]),
                              (m["complete_units"], m["total_units"])),
    }


def write_badges(directory: Path, report_path: Path) -> None:
    directory.mkdir(parents=True, exist_ok=True)
    for name, badge in badges(json.loads(Path(report_path).read_text(encoding="utf-8"))).items():
        (directory / f"{name}.json").write_text(json.dumps(badge) + "\n", encoding="utf-8")


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("reports", nargs="+", type=Path, help="build/<version>/report.json files")
    parser.add_argument("-o", "--output", type=Path, default=Path("build/progress"))
    parser.add_argument("--width", type=int, default=1280, help=argparse.SUPPRESS)
    parser.add_argument("--height", type=int, default=720, help=argparse.SUPPRESS)
    parser.add_argument("--badges", type=Path, help="also write the README's badge data from the first report here")
    args = parser.parse_args()
    try:
        index = generate(args.reports, args.output, args.width, args.height)
        print(f"wrote {index}")
        if args.badges:
            write_badges(args.badges, args.reports[0])
            print(f"wrote badges to {args.badges}")
    except ValueError as error:
        parser.error(str(error))


if __name__ == "__main__":
    main()
