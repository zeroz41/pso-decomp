#include "types.h"
#include "pso/ui/frontend/TAdGameStartLineGC.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
const char *TAdGameStartLineGC__name = "TAdGameStartLineGC";

void *lbl_805D6C18;

#pragma push
#pragma fp_contract on
void TAdGameStartLineGC::draw_lines() {
    begin_screen_draw(1);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(lbl_805D6C18));
    set_draw_texture_and_color(0, m_color);
    for (u32 i = 0; i < 4; i++) {
        draw_textured_quad_at_depth(&m_quads[i].x0, 0.0001f * i + 0.795f);
    }
    TWindowSubStatusDisp::get_player();
}
#pragma pop

void TAdGameStartLineGC::render() { if (TMainTask::get_render_pass() != 1) { set_additive_blend(); draw_lines(); set_default_alpha_blend(); } }

#pragma push
#pragma fp_contract on
void TAdGameStartLineGC::run_task() {
    s32 i;
    m_frame++;
    if (m_frame < 10) {
        m_scale_x = 3.0f - 0.2f * (f32)m_frame;
        m_scale_y = 3.0f - 0.2f * (f32)m_frame;
    } else if (m_frame > 28) {
        m_left_x -= 64.0f;
        m_right_x += 64.0f;
        m_rest[0].x0 = m_left_x;
        m_rest[0].x1 = 384.0f + m_left_x;
        m_rest[1].x0 = 384.0f + m_left_x;
        m_rest[1].x1 = 640.0f + m_left_x;
        m_rest[2].x0 = m_right_x;
        m_rest[2].x1 = m_right_x - 384.0f;
        m_rest[3].x0 = m_right_x - 384.0f;
        m_rest[3].x1 = m_right_x - 640.0f;
        for (i = 0; i < 4; i++) {
            m_centers[i].x = 0.5f * (m_rest[i].x1 - m_rest[i].x0) + m_rest[i].x0;
        }
    }
    for (i = 0; i < 4; i++) {
        m_quads[i].x0 = m_scale_x * (m_rest[i].x0 - m_centers[i].x) + m_centers[i].x;
        m_quads[i].y0 = m_scale_y * (m_rest[i].y0 - m_centers[i].y) + m_centers[i].y;
        m_quads[i].x1 = m_scale_x * (m_rest[i].x1 - m_centers[i].x) + m_centers[i].x;
        m_quads[i].y1 = m_scale_y * (m_rest[i].y1 - m_centers[i].y) + m_centers[i].y;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
TAdGameStartLineGC::~TAdGameStartLineGC() {}
extern "C" {
void *__ct__7TObjectFP7TObject(void *, TObject *);
extern void *__vt__18TAdGameStartLineGC[];
TAdGameStartLineGC *__ct__18TAdGameStartLineGCFP7TObject(TAdGameStartLineGC *self, TObject *parent);
}

TAdGameStartLineGC *__ct__18TAdGameStartLineGCFP7TObject(TAdGameStartLineGC *self, TObject *parent) {
    s32 i;
    __ct__7TObjectFP7TObject(self, parent);
    *(void **)((u8 *)self + 0x18) = __vt__18TAdGameStartLineGC;
    self->m_name = TAdGameStartLineGC__name;
    self->m_left_x = 27.0f;
    self->m_left_y = 191.0f;
    self->m_right_x = 613.0f;
    self->m_right_y = 289.0f;
    self->m_color = -1;
    self->m_frame = -1;
    self->m_scale_x = 3.0f;
    self->m_scale_y = 3.0f;
    lbl_805D6C18 = (void *)TObjPlayer::get_instance();
    self->m_rest[0].x0 = self->m_left_x;
    self->m_rest[0].y0 = self->m_left_y;
    self->m_rest[0].x1 = 384.0f + self->m_left_x;
    self->m_rest[0].y1 = 128.0f + self->m_left_y;
    self->m_rest[1].x0 = 384.0f + self->m_left_x;
    self->m_rest[1].y0 = self->m_left_y;
    self->m_rest[1].x1 = 640.0f + self->m_left_x;
    self->m_rest[1].y1 = 128.0f + self->m_left_y;
    self->m_rest[2].x0 = self->m_right_x;
    self->m_rest[2].y0 = self->m_right_y;
    self->m_rest[2].x1 = self->m_right_x - 384.0f;
    self->m_rest[2].y1 = self->m_right_y - 128.0f;
    self->m_rest[3].x0 = self->m_right_x - 384.0f;
    self->m_rest[3].y0 = self->m_right_y;
    self->m_rest[3].x1 = self->m_right_x - 640.0f;
    self->m_rest[3].y1 = self->m_right_y - 128.0f;
    for (i = 0; i < 4; i++) {
        self->m_centers[i].x = 0.5f * (self->m_rest[i].x1 - self->m_rest[i].x0) + self->m_rest[i].x0;
        self->m_centers[i].y = 0.5f * (self->m_rest[i].y1 - self->m_rest[i].y0) + self->m_rest[i].y0;
    }
    for (i = 0; i < 2; i++) {
        self->m_quads[i * 2].u0 = 0.0f;
        self->m_quads[i * 2].v0 = 0.5f;
        self->m_quads[i * 2].u1 = 0.75f;
        self->m_quads[i * 2].v1 = 0.75f;
        self->m_quads[i * 2 + 1].u0 = 0.5f;
        self->m_quads[i * 2 + 1].v0 = 0.5f;
        self->m_quads[i * 2 + 1].u1 = 1.0f;
        self->m_quads[i * 2 + 1].v1 = 0.75f;
    }
    return self;
}
#pragma pop
