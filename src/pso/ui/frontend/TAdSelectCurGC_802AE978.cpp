#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/vector.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
void TAdSelectCurGC::draw_quads() {
    u32 i;
    for (i = 0; i < entry_count; i++) {
        begin_screen_draw(1);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(menu_selection_cursor_texture_list));
        set_draw_texture_and_color(0, (static_cast<u32>(entry_alpha[i]) << 24) | 0xFFFFFF);
        draw_textured_quad_at_depth(&quads[i].x0, draw_depth);
        draw_textured_quad_at_depth(&quads[i + 16].x0, draw_depth);
        draw_textured_quad_at_depth(&quads[i + 32].x0, draw_depth);
        end_screen_draw();
    }
}

void TAdSelectCurGC::render() { if (TMainTask::get_render_pass() != 1) { set_color_blending_mode(0, 8); set_color_blending_mode(1, 10); draw_quads(); set_color_blending_mode(0, 8); set_color_blending_mode(1, 6); } }

void TAdSelectCurGC::update_texture_rectangles(s32 frame) {
    s32 i;
    for (i = 0; i < static_cast<s32>(entry_count); i++) {
        switch (confirmation_result()) {
        case 0:
            quads[i].u0 = 0.0625f;
            quads[i].v0 = 0.875f;
            quads[i].u1 = 0.125f;
            quads[i].v1 = 0.9453125f;
            (quads + 16)[i].u0 = 0.0f;
            (quads + 16)[i].v0 = 0.875f;
            (quads + 16)[i].u1 = 0.0625f;
            (quads + 16)[i].v1 = 0.9453125f;
            (quads + 32)[i].u0 = 0.125f;
            (quads + 32)[i].v0 = 0.875f;
            (quads + 32)[i].u1 = 0.1875f;
            (quads + 32)[i].v1 = 0.9453125f;
            break;
        case 1:
            quads[i].u0 = 0.25390625f;
            quads[i].v0 = 0.875f;
            quads[i].u1 = 0.31640625f;
            quads[i].v1 = 0.9453125f;
            (quads + 16)[i].u0 = 0.19140625f;
            (quads + 16)[i].v0 = 0.875f;
            (quads + 16)[i].u1 = 0.25390625f;
            (quads + 16)[i].v1 = 0.9453125f;
            (quads + 32)[i].u0 = 0.31640625f;
            (quads + 32)[i].v0 = 0.875f;
            (quads + 32)[i].u1 = 0.37890625f;
            (quads + 32)[i].v1 = 0.9453125f;
            break;
        }
    }
}

void TAdSelectCurGC::reset_entries() {
    s32 i;
    selected_index = 0;
    entry_count = 0;
    confirmation = 0;
    frame = -1;
    pending_command = 0;
    for (i = 0; i < 16; i++) {
        entry_alpha[i] = 0;
    }
}

static const f32 cursor_end_cap_width = 16.0f;
static const f32 cursor_end_caps_width = 32.0f;

void TAdSelectCurGC::append_entry(const void *position) {
    if (entry_count < 16) {
        copy_vec2(&entry_positions[entry_count], const_cast<void *>(position));
        quads[entry_count].x0 = cursor_end_cap_width + entry_positions[entry_count].x;
        quads[entry_count].y0 = entry_positions[entry_count].y;
        quads[entry_count].x1 = quads[entry_count].x0 + (cursor_size.x - cursor_end_caps_width);
        quads[entry_count].y1 = quads[entry_count].y0 + cursor_size.y;
        (quads + 16)[entry_count].x0 = entry_positions[entry_count].x;
        (quads + 16)[entry_count].y0 = entry_positions[entry_count].y;
        (quads + 16)[entry_count].x1 = cursor_end_cap_width + (quads + 16)[entry_count].x0;
        (quads + 16)[entry_count].y1 = (quads + 16)[entry_count].y0 + cursor_size.y;
        (quads + 32)[entry_count].x0 = entry_positions[entry_count].x + (cursor_size.x - cursor_end_cap_width);
        (quads + 32)[entry_count].y0 = entry_positions[entry_count].y;
        (quads + 32)[entry_count].x1 = cursor_end_cap_width + (quads + 32)[entry_count].x0;
        (quads + 32)[entry_count].y1 = (quads + 32)[entry_count].y0 + cursor_size.y;
        entry_count++;
    }
}
