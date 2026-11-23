#include "pso/ui/frontend/TAdGameStartShadowGC.h"

#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"

const char *TAdGameStartShadowGC__name = "TAdGameStartShadowGC";
saddr TAdGameStartShadowGC__texture_list;

void TAdGameStartShadowGC::draw_band() {
    u32 i;
    begin_screen_draw(1);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>((void *)TAdGameStartShadowGC__texture_list));
    set_draw_texture_and_color(0, m_color);
    for (i = 0; i < 5; i++) {
        draw_textured_quad_at_depth(&m_quads[i].x0, 0.74f);
    }
    TWindowSubStatusDisp::get_player();
}

void TAdGameStartShadowGC::render() { if (TMainTask::get_render_pass() != 1) { draw_band(); } }

void TAdGameStartShadowGC::run_task() {
    s32 frame;
    s32 alpha;
    s32 faded;

    m_frame = (s32) (m_frame + 1);
    frame = m_frame;
    if (frame < 0xA) {
        m_alpha = (s32) (m_alpha + 0x19);
        alpha = m_alpha;
        if (alpha > 0xFF) {
            alpha = 0xFF;
        }
        m_alpha = alpha;
    } else if (frame > 0x1C) {
        m_alpha = (s32) (m_alpha - 0x19);
        faded = m_alpha;
        if (faded < 0) {
            faded = 0;
        }
        m_alpha = faded;
    }
    m_color = (s32) ((m_alpha << 0x18) | 0xFF0000 | 0xFFFF);
}
TAdGameStartShadowGC::~TAdGameStartShadowGC() {}
extern "C" {
void *__ct__7TObjectFP7TObject(void *, TObject *);
extern void *__vt__20TAdGameStartShadowGC[];
TAdGameStartShadowGC *__ct__20TAdGameStartShadowGCFP7TObject(TAdGameStartShadowGC *self, TObject *parent);
}

TAdGameStartShadowGC *__ct__20TAdGameStartShadowGCFP7TObject(TAdGameStartShadowGC *self, TObject *parent) {
    u32 i;
    __ct__7TObjectFP7TObject(self, parent);
    *(void **)((u8 *)self + 0x18) = __vt__20TAdGameStartShadowGC;
    self->m_name = TAdGameStartShadowGC__name;
    self->m_color = -1;
    self->m_alpha = 0;
    self->m_frame = -1;
    TAdGameStartShadowGC__texture_list = TObjPlayer::get_instance();
    for (i = 0; i < 5; i++) {
        self->m_quads[i].x0 = 128.0f * (f32)i;
        self->m_quads[i].x1 = 128.0f + self->m_quads[i].x0;
        self->m_quads[i].y0 = 190.0f;
        self->m_quads[i].y1 = 128.0f + self->m_quads[i].y0;
    }
    self->m_quads[0].u0 = 0.0f;
    self->m_quads[0].v0 = 0.75f;
    self->m_quads[0].u1 = 0.25f;
    self->m_quads[0].v1 = 1.0f;
    for (i = 1; i < 4; i++) {
        self->m_quads[i].u0 = 0.25f;
        self->m_quads[i].v0 = 0.75f;
        self->m_quads[i].u1 = 0.5f;
        self->m_quads[i].v1 = 1.0f;
    }
    self->m_quads[4].u0 = 0.5f;
    self->m_quads[4].v0 = 0.75f;
    self->m_quads[4].u1 = 0.75f;
    self->m_quads[4].v1 = 1.0f;
    return self;
}
