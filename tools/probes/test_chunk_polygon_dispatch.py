"""Exercise valid polygon command lists using the recovered dispatcher body.

Rendering calls are recorded, not emulated. Native instructions, relocations
and the 32-bit storage layout are validated separately by the matching build.
"""
from pathlib import Path
import os
import shutil
import subprocess
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[2]
SOURCE = ROOT / "src/pso/unk/text_803E2F28.cpp"

PRELUDE = r'''
#include <stdint.h>
#define TYPES_H
typedef int16_t s16;
typedef uint16_t u16;
typedef int32_t s32;
typedef uint32_t u32;
typedef uint8_t u8;
typedef float f32;

#include "pso/render/ChunkPolygonList.h"
#include <cassert>
#include <cstring>
#include <vector>
struct Vtx_803E36C4 {};
struct TObjPlayer { static void setup_tev_passclr(); };
struct Event { const char *name; s32 a, b, c; const void *data; };
static std::vector<Event> events;
static void record(const char *name, s32 a=0, s32 b=0, s32 c=0, const void *p=0) {
    events.push_back({name, a, b, c, p});
}
s32 model_render_flags, chunk_previous_strip_flags, chunk_polygon_cache_pending;
u32 chunk_polygon_flags_and_mask = ~u32(0), chunk_polygon_flags_or_mask;
u32 chunk_strip_dirty_flags, chunk_has_vertex_colors;
s16 *chunk_polygon_list_cache[126];
void set_chunk_blend(u32 header) { record("blend", (s32)header); }
void apply_chunk_texture_command(s32 header, s32 texture) { record("texture", header, texture); }
void submit_chunk_material_color(s32 header, s16 *p) { record("material", header, 0, 0, p); }
void set_strip_lighting_chan_ctrl(u32 flags) { record("lighting", (s32)flags); }
void set_chunk_blend_depth_mode(s32 flags, s32 textured) { record("depth", flags, textured); }
void setup_chunk_tev_stages() { record("tev"); }
void TObjPlayer::setup_tev_passclr() { record("passclr"); }
void GXSetTexCoordGen2(s32 dst, u32 func, u32 src, s32 matrix, s32 normalize, s32 post) {
    assert(dst == 0 && normalize == 0 && post == 0x7D);
    record("texgen", func, src, matrix);
}
extern "C" {
void draw_strip_pos_normal__10TObjPlayerFPvPvUi(s16 *p, Vtx_803E36C4 *v, u32 info) {
    assert(reinterpret_cast<uintptr_t>(v) == 0x1234); record("normal", (s32)info, 0, 0, p);
}
void draw_strip_list_pos_nrm__10TObjPlayerFPvPvUi(s16 *p, Vtx_803E36C4 *v, u32 info) {
    assert(reinterpret_cast<uintptr_t>(v) == 0x1234); record("untextured", (s32)info, 0, 0, p);
}
void draw_triangle_strips__10TObjPlayerFPvPvUi(s16 *p, Vtx_803E36C4 *v, u32 info) {
    assert(reinterpret_cast<uintptr_t>(v) == 0x1234); record("triangle", (s32)info, 0, 0, p);
}
void draw_chunk_color_tex_strips(s16 *p, ChunkColorVertex *v, u32 info, s32 large) {
    assert(reinterpret_cast<uintptr_t>(v) == 0x1234); record("color", (s32)info, large, 0, p);
}
void draw_chunk_textured_strips(s16 *p, Vtx_803E36C4 *v, u32 info, s32 large) {
    assert(reinterpret_cast<uintptr_t>(v) == 0x1234); record("textured", (s32)info, large, 0, p);
}
}
'''

CASES = r'''
static void expect(unsigned i, const char *name, s32 a=0, s32 b=0, s32 c=0) {
    assert(i < events.size());
    const Event &e = events[i];
    assert(std::strcmp(e.name, name) == 0 && e.a == a && e.b == b && e.c == c);
}
int main(int argc, char **argv) {
    assert(argc == 2);
    if (std::strcmp(argv[1], "state") == 0) {
        s16 list[] = {0x1201, 2, (s16)0x8008, (s16)0x8765, 0x3F11, 2,
                      (s16)0xABCD, (s16)0xEF01, 0x501, 0xFF};
        dispatch_chunk_polygon_list(list, 0x1234);
        assert(events.size() == 5);
        expect(0, "blend", 0x1201);
        expect(1, "texture", (s16)0x8008, (s16)0x8765);
        expect(2, "blend", 0x3F11);
        expect(3, "material", 0x3F11);
        assert(events[3].data == list + 6);
        expect(4, "blend", 0x501);
    } else if (std::strcmp(argv[1], "cache") == 0) {
        s16 definition[] = {0x204, 0xA01, 0xFF};
        dispatch_chunk_polygon_list(definition, 0x1234);
        assert(events.empty() && chunk_polygon_cache_pending == 1);
        assert(chunk_polygon_list_cache[2] == definition + 1);
        s16 nested[] = {0x205, 0xFF};
        chunk_polygon_list_cache[3] = nested;
        chunk_polygon_cache_pending = 2;
        s16 call[] = {0x305, 0xFF};
        dispatch_chunk_polygon_list(call, 0x1234);
        assert(events.size() == 1 && chunk_polygon_cache_pending == 0);
        expect(0, "blend", 0xA01);
    } else if (std::strcmp(argv[1], "mask-boundaries") == 0) {
        // Derive expected flags from unsigned wire bits, independently of the
        // dispatcher's signed narrowing and shift operations.
        const u32 masks[] = {0, 0xFF, 0xFFFF, 0x7FFF, 0x8000, 0xFF00,
                             0xFFFF0000, 0xFFFFFFFF, 0xA5A55A5A};
        model_render_flags = 0x800;
        for (u32 high = 0; high < 256; ++high) {
          for (u32 tag = 0x40; tag <= 0x42; ++tag) {
            for (u32 and_mask : masks) {
                for (u32 or_mask : masks) {
                    events.clear();
                    chunk_previous_strip_flags = 0;
                    chunk_strip_dirty_flags = 1;
                    chunk_polygon_flags_and_mask = and_mask;
                    chunk_polygon_flags_or_mask = or_mask;
                    u32 bits = (high << 8) | tag;
                    u32 masked = ((bits & and_mask) | or_mask) & 0xFFFF;
                    s32 expected = masked >> 8;
                    if (expected & 0x80) expected -= 256;
                    s16 info = (high & 1) ? -32768 : 32767;
                    s16 list[] = {(s16)bits, 3, info, 0x1111, 0x2222, 0xFF};
                    dispatch_chunk_polygon_list(list, 0x1234);
                    bool projected = (expected & 0x40) != 0;
                    expect(0, "lighting", expected);
                    expect(1, "depth", expected, tag != 0x40 || projected);
                    expect(events.size() - 1,
                           tag == 0x40 ? (projected ? "normal" : "untextured") :
                           projected ? "triangle" : "textured",
                           info, tag == 0x42 && !projected);
                    assert(chunk_previous_strip_flags == expected);
                    assert(chunk_strip_dirty_flags == 0);
                    assert(events.back().data == list + 3);
                }
            }
          }
        }
    } else {
        bool normal = std::strcmp(argv[1], "normal") == 0;
        bool plain = std::strcmp(argv[1], "plain") == 0;
        bool triangle = std::strcmp(argv[1], "triangle") == 0;
        bool color = std::strcmp(argv[1], "color") == 0;
        bool wide = std::strcmp(argv[1], "wide") == 0;
        bool masked = std::strcmp(argv[1], "masked") == 0;
        s16 header = normal ? 0x4040 : plain ? 0x40 : triangle ? 0x4041 : wide ? 0x42 : 0x41;
        chunk_has_vertex_colors = color;
        if (masked) {
            model_render_flags = 0x800;
            chunk_polygon_flags_and_mask = 0xFF;
            chunk_polygon_flags_or_mask = 0x4000;
        }
        chunk_strip_dirty_flags = 1;
        s16 list[] = {header, 3, (s16)0xC123, 0x1111, 0x2222, 0xFF};
        dispatch_chunk_polygon_list(list, 0x1234);
        s32 flags = (normal || triangle || masked) ? 0x40 : 0;
        expect(0, "lighting", flags);
        expect(1, "depth", flags, !plain);
        expect(2, plain ? "passclr" : "tev");
        unsigned draw = plain ? 3 : 4;
        if (!plain) expect(3, "texgen", flags ? 0 : 1, flags ? 1 : 4, flags ? 0x2A : 0x3C);
        expect(draw, normal ? "normal" : plain ? "untextured" : (triangle || masked) ? "triangle" :
                     color ? "color" : "textured", (s16)0xC123, wide);
        assert(events[draw].data == list + 3 && events.size() == draw + 1);
        assert(chunk_previous_strip_flags == flags && chunk_strip_dirty_flags == 0);
    }
}
'''


class ChunkPolygonDispatchTests(unittest.TestCase):
    def test_valid_commands_and_strip_formats(self):
        compiler = shutil.which("g++")
        if compiler is None:
            self.skipTest("g++ is required")
        source = SOURCE.read_text()
        start = source.rindex("\nvoid dispatch_chunk_polygon_list(s16 *list, s32 vertex_buffer) {") + 1
        end = start + source[start:].index("{") + 1
        depth = 1
        while depth:
            depth += (source[end] == "{") - (source[end] == "}")
            end += 1
        with tempfile.TemporaryDirectory() as tmp:
            path = Path(tmp)
            fixture, binary = path / "dispatch.cpp", path / "dispatch"
            # The Ninja header also declares GameCube pointer layouts. Use its wire
            # constants with the host layout used by this fixture.
            ninja_header = ROOT / "include/pso/system/NinjaTypes.h"
            wire_constants = "\n".join(line for line in ninja_header.read_text().splitlines()
                                       if line.startswith("#define NJD_"))
            fixture.write_text(PRELUDE + wire_constants + "\n" + source[start:end] + CASES)
            flags = ["-std=c++17", "-O2", "-Wall", "-Wextra", "-Werror", "-Wno-int-to-pointer-cast"]
            if os.environ.get("PSO_TEST_SANITIZERS") == "1":
                flags += ["-fsanitize=address,undefined", "-fno-sanitize-recover=all", "-fno-pie", "-no-pie"]
            result = subprocess.run([compiler, *flags, "-iquote", str(ROOT / "include"),
                                     str(fixture), "-o", str(binary)], capture_output=True, text=True, timeout=30)
            self.assertEqual(result.returncode, 0, result.stdout + result.stderr)
            for case in ("state", "cache", "normal", "plain", "triangle", "color", "wide", "masked",
                         "mask-boundaries"):
                with self.subTest(case=case):
                    result = subprocess.run([str(binary), case], capture_output=True, text=True, timeout=5)
                    self.assertEqual(result.returncode, 0, result.stdout + result.stderr)


if __name__ == "__main__":
    unittest.main()
