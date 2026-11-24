#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/ui/frontend/TAdSelectTxtSubGC.h"
#include "pso/ui/frontend/TAdSelectTxtGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/npc/TObjNpcHosa.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

const char *ad_select_txt_sub_gc_class_name = "TAdSelectTxtSubGC";
s32 status_disp_texture_handle;

void TAdSelectTxtSubGC::render_status() {
    begin_screen_draw(1);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(status_disp_texture_handle));
    set_draw_texture_and_color(m_texture, m_color);
    draw_textured_quad_at_depth(&m_quad.x0, 0.25f);
    TWindowSubStatusDisp::get_player();
}

void TAdSelectTxtSubGC::render() { if (TMainTask::get_render_pass() != 1) { set_color_blending_mode(0, 8); set_color_blending_mode(1, 10); render_status(); set_color_blending_mode(0, 8); set_color_blending_mode(1, 6); } }

#pragma push
#pragma fp_contract on
void TAdSelectTxtSubGC::run_task() {
    f32 center;
    s32 frame;
    frame = m_frame;
    if (frame < 5) {
        m_frame = frame + 1;
    }
    m_scale_x = 2.0f - 0.2f * (f32)m_frame;
    m_scale_y = 2.0f - 0.2f * (f32)m_frame;
    center = m_center_x;
    m_quad.x0 = (m_scale_x * (m_rest.x0 - center)) + center;
    center = m_center_y;
    m_quad.y0 = (m_scale_y * (m_rest.y0 - center)) + center;
    center = m_center_x;
    m_quad.x1 = (m_scale_x * (m_rest.x1 - center)) + center;
    center = m_center_y;
    m_quad.y1 = (m_scale_y * (m_rest.y1 - center)) + center;
}
#pragma pop

#pragma push
#pragma fp_contract on
TAdSelectTxtSubGC::~TAdSelectTxtSubGC() {}
extern "C" {
void *__ct__7TObjectFP7TObject(void *, TObject *);
extern void *__vt__17TAdSelectTxtSubGC[];
TAdSelectTxtSubGC *__ct__17TAdSelectTxtSubGCFP7TObjectP17TAdSelectTxtEntry(TAdSelectTxtSubGC *self, TObject *parent, TAdSelectTxtEntry *entry);
}

TAdSelectTxtSubGC *__ct__17TAdSelectTxtSubGCFP7TObjectP17TAdSelectTxtEntry(TAdSelectTxtSubGC *self, TObject *parent, TAdSelectTxtEntry *entry) {
    __ct__7TObjectFP7TObject(self, parent);
    *(void **)((u8 *)self + 0x18) = __vt__17TAdSelectTxtSubGC;
    self->m_name = ad_select_txt_sub_gc_class_name;
    self->m_row = entry->value;
    self->m_column = entry->index;
    copy_vec2(&self->m_origin, entry->position);
    self->m_color = entry->text_id;
    self->m_frame = -1;
    self->m_scale_x = 2.0f;
    self->m_scale_y = 2.0f;
    status_disp_texture_handle = TObjNpcHosa__sub_802A39B0();
    self->m_texture = self->m_row > 8;
    self->m_row -= (self->m_row > 8) ? 9 : 0;
    self->m_rest.x0 = 32.0f * (f32)self->m_column + self->m_origin.x;
    self->m_rest.y0 = self->m_origin.y;
    self->m_rest.x1 = 32.0f * (self->m_column + 1) + self->m_origin.x;
    self->m_rest.y1 = 27.0f + self->m_origin.y;
    self->m_center_x = 0.5f * (self->m_rest.x1 - self->m_rest.x0) + self->m_rest.x0;
    self->m_center_y = 0.5f * (self->m_rest.y1 - self->m_rest.y0) + self->m_rest.y0;
    self->m_quad.u0 = (32.0f * (f32)self->m_column) / 256.0f;
    self->m_quad.v0 = (28.0f * (f32)self->m_row) / 256.0f;
    self->m_quad.u1 = (32.0f * (self->m_column + 1) - 1.0f) / 256.0f;
    self->m_quad.v1 = (28.0f * (self->m_row + 1) - 1.0f) / 256.0f;
    return self;
}
#pragma pop

extern "C" {
int TObjNpcHosa__sub_802A39B0(void) {  return ad_select_text_texture_handle; }

}
