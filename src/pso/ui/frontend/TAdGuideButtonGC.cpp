#include "pso/ui/frontend/TAdGuideButtonGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802C6F88.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/object/ambient/TObjFish.h"
extern "C" {
s32 render_status_disp__23TAdSinglePlyChrSelectGCFff(const char *, f32, f32, f32);
extern const GuideButtonPoint guide_button_atlas_origins[4] = {
    {212.0f,78.0f},{190.0f,78.0f},{234.0f,78.0f},{190.0f,100.0f},
};
#pragma push
#pragma readonly_strings on
const char *guide_button_type_name = "TAdGuideButtonGC";
#pragma pop
u32 guide_button_texture_handle;
TAdGuideButtonGC *guide_button_instance;
}
#pragma push
#pragma fp_contract on
void TAdGuideButtonGC::draw_label(int style, const char *text) {
    render_status_disp__23TAdSinglePlyChrSelectGCFff(text, 22.0f + quads[0].x0, 1.0f + quads[0].y0, 22.0f);
}
#pragma pop
void TAdGuideButtonGC::draw_quad(int style) {
    if (guide_button_texture_handle != 0) {
        TObjFish::set_global_param(guide_button_texture_handle);
        begin_screen_draw(1);
        set_draw_texture_and_color(0,-1);
        draw_textured_quad_at_depth((f32 *)quads, 0.5f);
        TWindowSubStatusDisp::get_player();
    }
}
void TAdGuideButtonGC::render() {
    if (TMainTask::get_render_pass() != 1) {
        draw_quad(0);
        draw_label(0,label);
    }
}
void TAdGuideButtonGC::setup_button(GuideButtonSpec *spec) {
    s32 i;
    this->kind = spec->kind;
    ((TWindowSubSymbolChatPartsSet *)(&this->from))->copy_vec2(&spec->from);
    ((TWindowSubSymbolChatPartsSet *)(&this->to))->copy_vec2(&spec->to);
    this->alpha_step = spec->alpha_step;
    this->duration = spec->duration;
    this->label = spec->label;
    this->active = 1;
    for (i = 0; i < 8; i++) {
        this->quads[i].u0 = guide_button_atlas_origins[this->kind].x / 256.0f;
        this->quads[i].v0 = guide_button_atlas_origins[this->kind].y / 256.0f;
        this->quads[i].u1 = (20.0f + guide_button_atlas_origins[this->kind].x) / 256.0f;
        this->quads[i].v1 = (20.0f + guide_button_atlas_origins[this->kind].y) / 256.0f;
        this->alpha[i] = spec->alpha;
    }
}

void TAdGuideButtonGC::update_trail_quads() {
    GuideButtonPoint d[8];
    u32 i;
    if (this->duration == this->frame) {
        if (this->settled_frames < 8) {
            this->settled_frames++;
        }
    }
    for (i = 0; i < 8; i++) {
        s32 cur = this->duration;
        s32 off = 0;
        s32 base = this->frame;
        if (cur != base) {
            if (base < i) {
                off = i;
            }
        } else if (this->settled_frames < i) {
            off = 8 - i;
        }
        d[i].x = ((this->to.x - this->from.x) * (f32)((cur - (base - off)) * (cur - (base - off)))) / 400.0f;
        d[i].y = ((this->to.y - this->from.y) * (f32)((this->duration - (this->frame - off)) * (this->duration - (this->frame - off)))) / 400.0f;
        this->quads[i].x0 = this->from.x + d[i].x;
        this->quads[i].y0 = this->from.y + d[i].y;
        this->quads[i].x1 = 20.0f + this->quads[i].x0;
        this->quads[i].y1 = 20.0f + this->quads[i].y0;
    }
}

void TAdGuideButtonGC::run_task() {
    s32 i;
    if (this->active != 0) {
        if (this->frame < this->duration) {
            this->frame++;
        }
        for (i = 0; i < 8; i++) {
            if (this->alpha[i] < 0xFF) {
                this->alpha[i] += this->alpha_step;
            }
            this->alpha[i] = this->alpha[i] > 0xFF ? 0xFF : this->alpha[i];
        }
        update_trail_quads();
    }
}

TAdGuideButtonGC::~TAdGuideButtonGC() {
    if (guide_button_instance != NULL) guide_button_instance = NULL;
}
TAdGuideButtonGC::TAdGuideButtonGC(TObject *parent) : TObject(parent) {
    m_name = guide_button_type_name;
    frame = -1;
    settled_frames = 0;
    guide_button_texture_handle = TAdMultiPlyChrSelectGC__sub_802C6FA8();
    active = 0;
}
void create_guide_button(TObject *parent, GuideButtonSpec *spec) {
    if (guide_button_instance == NULL) {
        guide_button_instance = new TAdGuideButtonGC(parent);
        if (guide_button_instance != NULL) guide_button_instance->setup_button(spec);
    }
}
#pragma push
#pragma readonly_strings on
void init_guide_button_params(GuideButtonSpec *spec) {
    spec->kind = 0;
    spec->from.x = 0.0f;
    spec->from.y = 0.0f;
    spec->to.x = 0.0f;
    spec->to.y = 0.0f;
    spec->alpha = 0xFF;
    spec->alpha_step = 0xFF;
    spec->duration = 0;
    spec->label = "";
}

#pragma pop
