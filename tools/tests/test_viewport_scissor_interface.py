"""Characterize the actual scissor provider and its shared caller interface.

No original game input or graphics device is used. The mode-2 cases are finite,
keep oy nonnegative, and keep every float-to-u32 input representable. Negative or
NaN oy uses the provider's existing uninitialized adj path and is deliberately
not claimed as defined portable behavior. This is not native-codegen/GPU proof.
"""
from pathlib import Path
import os
import re
import shutil
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT / "src/pso/unk/TLobby_801E2F94.cpp"
HEADER = ROOT / "include/pso/camera/TCameraCtrl.h"

PRELUDE = r"""
#include <cassert>
#include <cstdint>
#include <cstring>
using f32 = float;
using u32 = std::uint32_t;
struct TCameraCtrl { DECLARATION };
f32 viewport_scissor_origin_x, camera_viewport_center_y;
static u32 received[4];
static unsigned calls;
void GXSetScissor(u32 x, u32 y, u32 w, u32 h) {
    received[0] = x; received[1] = y; received[2] = w; received[3] = h;
    ++calls;
}
"""

CASES = r"""
void expect(u32 x, u32 y, u32 w, u32 h) {
    assert(calls == 1);
    assert(received[0] == x && received[1] == y);
    assert(received[2] == w && received[3] == h);
    calls = 0;
}
int main(int argc, char **argv) {
    assert(argc == 2);
    viewport_scissor_origin_x = 320.0f;
    camera_viewport_center_y = 240.0f;
    if (std::strcmp(argv[1], "other_modes") == 0) {
        for (int mode : {-1, 0, 1, 3}) {
            TCameraCtrl::set_viewport_scissor(mode, nullptr);
            expect(0, 0, 640, 480);
        }
    } else if (std::strcmp(argv[1], "basic") == 0) {
        Rect_801E317C rect = {1, 2, 4, 5};
        TCameraCtrl::set_viewport_scissor(2, &rect);
        expect(32, 64, 96, 128);
        assert(rect.x0 == 1 && rect.y0 == 2 && rect.x1 == 4 && rect.y1 == 5);
    } else if (std::strcmp(argv[1], "clamp") == 0) {
        Rect_801E317C rect = {0, 0, 30, 20};
        TCameraCtrl::set_viewport_scissor(2, &rect);
        expect(0, 0, 640, 480);
    } else if (std::strcmp(argv[1], "offset") == 0) {
        Rect_801E317C rect = {1, 2, 4, 5};
        viewport_scissor_origin_x = 336.0f;
        camera_viewport_center_y = 256.0f;
        TCameraCtrl::set_viewport_scissor(2, &rect);
        expect(16, 48, 96, 128);
    } else if (std::strcmp(argv[1], "fractional") == 0) {
        Rect_801E317C rect = {0.1f, 0.2f, 1.1f, 2.2f};
        TCameraCtrl::set_viewport_scissor(2, &rect);
        expect(3, 6, 32, 96);
    } else if (std::strcmp(argv[1], "bounded_states") == 0) {
        u32 rng = 0x6c214f8du;
        for (int i = 0; i < 10000; ++i) {
            rng ^= rng << 13; rng ^= rng >> 17; rng ^= rng << 5;
            u32 x = 32 + (rng & 127), y = 64 + ((rng >> 7) & 127);
            u32 w = 1 + ((rng >> 14) & 1023), h = 32 + ((rng >> 24) & 255);
            Rect_801E317C rect = {x / 32.0f, y / 32.0f,
                                  (x + w) / 32.0f, (y + h - 32) / 32.0f};
            // All values are exactly representable multiples of 1/32. Positive
            // oy initializes adj; x/y stay nonnegative after the offsets.
            viewport_scissor_origin_x = 336.0f;
            camera_viewport_center_y = 256.0f;
            TCameraCtrl::set_viewport_scissor(2, &rect);
            expect(x - 16, y - 16, w > 640 ? 640 : w, h);
        }
    } else {
        assert(false);
    }
}
"""


class ViewportScissorInterface(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        compiler = shutil.which("g++")
        if compiler is None:
            raise unittest.SkipTest("g++ is required for source characterization")
        source = SOURCE.read_text()
        declaration = re.search(
            r"static void set_viewport_scissor\(int mode, void \*rect\);",
            HEADER.read_text(),
        )
        rectangle = re.search(r"^struct Rect_801E317C \{.*?\};", source, re.M)
        function = re.search(
            r"(?ms)^void TCameraCtrl::set_viewport_scissor\(int mode, void \*rect\) \{.*?^\}",
            source,
        )
        if not all((declaration, rectangle, function)):
            raise AssertionError("Cannot extract the actual shared interface/provider")
        temp = tempfile.TemporaryDirectory()
        cls.addClassCleanup(temp.cleanup)
        path = Path(temp.name)
        cpp = path / "scissor.cpp"
        cpp.write_text(
            "#include <initializer_list>\n"
            + PRELUDE.replace("DECLARATION", declaration.group(0))
            + rectangle.group(0) + "\n" + function.group(0) + CASES
        )
        cls.binary = path / "scissor"
        flags = ["-std=c++17", "-O2"]
        if os.environ.get("PSO_TEST_SANITIZERS") == "1":
            flags += ["-fsanitize=address,undefined", "-fno-sanitize-recover=undefined",
                      "-fno-omit-frame-pointer"]
        result = subprocess.run(
            [compiler, *flags, str(cpp), "-o", str(cls.binary)],
            capture_output=True, text=True, timeout=30,
        )
        if result.returncode:
            raise AssertionError(result.stdout + result.stderr)

    def run_case(self, name):
        result = subprocess.run([str(self.binary), name], capture_output=True,
                                text=True, timeout=10)
        self.assertEqual(result.returncode, 0, result.stdout + result.stderr)

    def test_other_modes_do_not_read_rectangle(self):
        self.run_case("other_modes")

    def test_mode_two_rectangle_and_input_preservation(self):
        self.run_case("basic")

    def test_width_height_clamps(self):
        self.run_case("clamp")

    def test_defined_positive_offset_path(self):
        self.run_case("offset")

    def test_representable_fractional_conversions(self):
        self.run_case("fractional")

    def test_ten_thousand_bounded_states(self):
        self.run_case("bounded_states")

    def test_all_three_call_sites_use_shared_contract(self):
        calls = {
            "src/pso/camera/TCameraCtrl.cpp":
                "TCameraCtrl::set_viewport_scissor(0, rect);",
            "src/pso/camera/TCameraCtrl_80067FC0.cpp":
                "TCameraCtrl::set_viewport_scissor(2, TCameraCtrl__data_804FF634.f30);",
            "src/pso/boss/darkfalz/TBoss4ZakoDraw.cpp":
                "TCameraCtrl::set_viewport_scissor(2, var_r4);",
        }
        for path, call in calls.items():
            source = (ROOT / path).read_text()
            self.assertEqual(source.count(call), 1, path)
            self.assertNotIn("set_viewport_scissor__11TCameraCtrlFiPv", source, path)



if __name__ == "__main__":
    unittest.main()
