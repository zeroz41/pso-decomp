#!/usr/bin/env python3
"""Compile the current geometry unit under stock MWCC profiles, without editing it.

Run configure.py and ninja first. Objects and complete objdiff output are written
only to --output-dir. This compares emitted code/data, not compiler provenance or
the compiler-specific .comment records. The source's native assembly guards remain
active; this is not a test of their scalar alternatives.
"""

import argparse
import hashlib
import json
from pathlib import Path
import shlex
import subprocess


ROOT = Path(__file__).resolve().parents[2]
UNIT = 'pso/unk/text_803E2F28'
TARGET = f'build/GPOE8P/src/{UNIT}.o'
ORIGINAL = f'build/GPOE8P/obj/{UNIT}.o'


def run(command):
    subprocess.run(command, cwd=ROOT, check=True)


def summarize(report):
    left = report['left']
    functions = [symbol for symbol in left['symbols'] if 'instructions' in symbol]
    return {
        'functions_total': len(functions),
        'functions_exact': sum(symbol.get('match_percent') == 100 for symbol in functions),
        'nonexact_functions': [
            {'name': symbol['name'], 'match_percent': symbol.get('match_percent')}
            for symbol in functions if symbol.get('match_percent') != 100
        ],
        'sections': [
            {'name': section['name'], 'match_percent': section.get('match_percent')}
            for section in left['sections']
            if section.get('kind') in ('SECTION_CODE', 'SECTION_DATA', 'SECTION_BSS')
        ],
    }


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--objdiff', required=True, type=Path)
    parser.add_argument('--output-dir', required=True, type=Path)
    parser.add_argument('--versions', nargs='+', default=[
        'GC/1.3', 'GC/1.3.2', 'GC/1.3.2r', 'GC/2.0', 'GC/2.0p1', 'GC/2.6',
    ])
    args = parser.parse_args()
    args.output_dir = args.output_dir.resolve()
    args.objdiff = args.objdiff.resolve()
    args.output_dir.mkdir(parents=True, exist_ok=True)

    recipes = subprocess.check_output(
        ['ninja', '-t', 'commands', TARGET], cwd=ROOT, text=True,
    ).splitlines()
    recipe = next(line for line in reversed(recipes) if 'mwcceppc.exe' in line)
    command = shlex.split(recipe.split(' && ')[0])
    compiler_index = next(i for i, arg in enumerate(command) if arg.endswith('mwcceppc.exe'))
    compiler_root = Path(command[compiler_index]).parents[2]
    if '-MMD' in command:
        command.remove('-MMD')
    outputs = {}
    results = {}
    invocations = {}
    for version in args.versions:
        profile = Path(version)
        if profile.is_absolute() or len(profile.parts) != 2 or '..' in profile.parts:
            parser.error(f'invalid compiler profile: {version}')
        output = args.output_dir / (version.replace('/', '-') + '.o')
        current = command.copy()
        current[compiler_index] = str(compiler_root / profile / 'mwcceppc.exe')
        current[current.index('-o') + 1] = str(output)
        invocations[version] = {
            'argv': current,
            'compiler_sha256': hashlib.sha256(Path(current[compiler_index]).read_bytes()).hexdigest(),
        }
        run(current)
        report_path = output.with_suffix('.json')
        run([str(args.objdiff), 'diff', '-1', ORIGINAL, '-2', str(output), '-o', str(report_path)])
        results[version] = summarize(json.loads(report_path.read_text()))
        outputs[version] = output
        print(json.dumps({'compiler': version, **results[version]}), flush=True)

    if 'GC/2.0' in outputs and 'GC/2.6' in outputs:
        cross_path = args.output_dir / 'GC-2.0-vs-2.6.json'
        run([str(args.objdiff), 'diff', '-1', str(outputs['GC/2.0']),
             '-2', str(outputs['GC/2.6']), '-o', str(cross_path)])
        results['GC/2.0 vs GC/2.6'] = summarize(json.loads(cross_path.read_text()))
    summary = {
        'source_sha256': hashlib.sha256((ROOT / f'src/{UNIT}.cpp').read_bytes()).hexdigest(),
        'invocations': invocations,
        'profiles': results,
    }
    (args.output_dir / 'summary.json').write_text(json.dumps(summary, indent=2) + '\n')


if __name__ == '__main__':
    main()
