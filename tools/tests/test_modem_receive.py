"""Exercise the modem's receive and control routines with a synthetic EXI device."""
from pathlib import Path
import re
import shutil
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]
FIXTURES = Path(__file__).resolve().parent / "fixtures"


def extract_block(source, pattern):
    """These top-level definitions close with a brace in column zero."""
    match = re.search(pattern, source, re.MULTILINE)
    if match is None:
        raise AssertionError(f"missing source block: {pattern}")
    end = source.index("\n}", match.end()) + 2
    return source[match.start():end]


@unittest.skipUnless(shutil.which("c++"), "host C++ compiler is unavailable")
class ModemReceiveTests(unittest.TestCase):
    def run_harness(self, fixture, records, functions, include_commands=False):
        source = (ROOT / "src/pso/network/ModemRuntime.cpp").read_text()
        definitions = [extract_block(source, rf"^struct {name} \{{") + ";" for name in records]
        if include_commands:
            table = extract_block(source, r"^static char modem_setup_commands\[\]\[12\] = \{")
            definitions.append(table + ";")
        bodies = [
            extract_block(source, rf"^[\w *]+\b{name}\([^;{{}}]*\)\s*\{{")
            for name in functions
        ]
        harness = (FIXTURES / fixture).read_text()
        harness = harness.replace("@@RECORDS@@", "\n".join(definitions))
        harness = harness.replace("@@FUNCTIONS@@", "\n".join(bodies))
        with tempfile.TemporaryDirectory() as temporary:
            cpp = Path(temporary) / "modem.cpp"
            executable = Path(temporary) / "modem"
            cpp.write_text(harness)
            compiled = subprocess.run(
                ["c++", "-std=c++17", "-O2", str(cpp), "-o", str(executable)],
                capture_output=True, text=True,
            )
            self.assertEqual(compiled.returncode, 0, compiled.stdout + compiled.stderr)
            result = subprocess.run([str(executable)], capture_output=True, text=True)
            self.assertEqual(result.returncode, 0, result.stdout + result.stderr)

    def test_receive_state_and_device_call_order(self):
        self.run_harness(
            "modem_receive_harness.cpp.in",
            ("ModemSendState", "ModemRecvState"),
            ("ModemMin", "TAdSinglePlyChrSelectGC__sub_8042BF6C",
             "TAdSinglePlyChrSelectGC__sub_8042C124", "TAdSinglePlyChrSelectGC__sub_8042D7E0"),
        )

    def test_dispatch_and_initialization_order(self):
        self.run_harness(
            "modem_control_harness.cpp.in",
            ("ModemSendState", "ModemRecvState", "ModemResponseState", "ModemConnectionInfo"),
            ("ModemMin", "ModemLeadingZeroCount", "TAdSinglePlyChrSelectGC__sub_8042C2E4",
             "ModemRunCommand", "ModemWriteCommand", "ModemBuildCountryCommand",
             "ModemSetupCommands", "modem_init"),
            include_commands=True,
        )


if __name__ == "__main__":
    unittest.main()
