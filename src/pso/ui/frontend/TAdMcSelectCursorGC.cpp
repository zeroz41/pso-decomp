#include "types.h"
#include "pso/ui/frontend/TAdMcSelectCursorGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/frontend/TAdMcSelectCursorGC_8032A610.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"

extern "C" {
GinjaTextureEntry lbl_804ED990 = { "f256_memorycard_select", 0, NULL };
__declspec(section ".data") GinjaTextureList mc_select_cursor_texture_list = { &lbl_804ED990, 1 };
}

struct Ent_8032A574 { f32 a, b, c, d; u8 pad[0x10]; };

struct Obj_8032A574 {
    const char *f0; u8 pad[0x14]; void *vt; s32 f1C; s32 f20; s32 f24; u8 pad2[0x38 - 0x28];
    Ent_8032A574 ents[8];
};

struct Alt_8032A574 { u8 pad[0x128]; s32 f128, f12C, f130, f134, f138, f13C; };

struct Rect_8032A2A4 { f32 x0, y0, x1, y1; u8 pad[0x10]; };

struct Self_8032A2A4 {
    u8 pad0[0x1c];
    s32 f1C;
    s32 f20;
    s32 f24;
    Rect_8032A2A4 rects[8];
    u32 f128;
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, s32);
const char *TAdMcSelectCursorGC__class_name = "TAdMcSelectCursorGC";
void play_sound_effect(s32, s32, s32, s32);
extern u8 controller_input_state[];
extern u8 controller_physical_port_bank[];
void restore_saved_depth_alpha_state(void);

s32 TAdMcSelectCursorGC__texture_entry;

void TAdMcSelectCursorGC::render_cursor() {
    u8 *arg0 = (u8 *)this;
    begin_screen_draw(1);
    TObjFish::set_global_param(TAdMcSelectCursorGC__texture_entry);
    set_draw_texture_and_color(0, ((this->m_128 << 0x18) | 0xFF0000 | 0xFFFF));
    draw_textured_quad_at_depth((f32 *)(arg0 + 0x28), 0.9f);
    TWindowSubStatusDisp::get_player();
}

void TAdMcSelectCursorGC::render() {
    if ((s32) this->m_13c == 1) {
        if (TMainTask::get_render_pass() == 1) {
            return;
        }
        goto block_5;
    }
    if ((s32)this->defer_render() == 0) {
        set_depth_buffer_settings_2();
block_5:
        set_additive_blend();
        render_cursor();
        set_default_alpha_blend();
        if ((s32) this->m_13c == 0) {
            restore_saved_depth_alpha_state();
        }
    }
}

u32 TAdMcSelectCursorGC__instance;

#pragma fp_contract on
void TAdMcSelectCursorGC::run_task() {
    Self_8032A2A4 *self = (Self_8032A2A4 *)this;
    uaddr t2;
    uaddr t;
    uaddr t1;
    s32 i;
    if (self->f1C == 0) {
        t = TAdMcSelectCursorGC::get_cursor_type(1 - self->f20);
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)(controller_physical_port_bank + 0x20), 0x80, 6, 1) != 0 ||
            test_buttons_press_or_repeat((saddr)(controller_input_state + 0x160), 0x80, 6, 1) != 0) {
            if (TAdMcSelectCursorGC__sub_8032A6D8((void *)t) >= 4) {
                self->f20++;
                if (self->f20 > 1) {
                    self->f20 = 1;
                }
            }
        } else if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)(controller_physical_port_bank + 0x20), 0x40, 6, 1) != 0 ||
                    test_buttons_press_or_repeat((saddr)(controller_input_state + 0x160), 0x40, 6, 1) != 0) &&
                   TAdMcSelectCursorGC__sub_8032A6D8((void *)t) >= 4) {
            self->f20--;
            if (self->f20 < 0) {
                self->f20 = 0;
            }
        }
    }
    t1 = TAdMcSelectCursorGC::get_cursor_type(self->f20);
    t2 = TAdMcSelectCursorGC::get_cursor_type(1 - self->f20);
    if (t1 != 0 && TAdMcSelectCursorGC__sub_8032A6D8((void *)t1) == 0) {
        if (t2 != 0 && TAdMcSelectCursorGC__sub_8032A6D8((void *)t2) == 0) {
            self->f128 = 0;
        } else {
            self->f20 = 1 - self->f20;
        }
    } else {
        self->f128 += 0x19;
        self->f128 = self->f128 > 0xFF ? 0xFF : self->f128;
    }
    for (i = 0; i < 8; i++) {
        self->rects[i].x0 = 286.0f * self->f20 + 51.0f;
        self->rects[i].y0 = 116.0f;
        self->rects[i].x1 = 256.0f + self->rects[i].x0;
        self->rects[i].y1 = 372.0f;
    }
    if (self->f20 != self->f24) {
        play_sound_effect(0x54100, 0, 0, 0);
        self->f128 = 0;
    }
    self->f24 = self->f20;
}

}
TAdMcSelectCursorGC::~TAdMcSelectCursorGC() {
    if ((u32) TAdMcSelectCursorGC__instance != 0U) {
        TAdMcSelectCursorGC__instance = 0U;
    }
}
#define arg0 ((Obj_8032A574 *)this)
TAdMcSelectCursorGC::TAdMcSelectCursorGC(TObject *parent) : TObject(parent) {
    s32 i;
    arg0->f0 = TAdMcSelectCursorGC__class_name;
    ((Alt_8032A574 *)arg0)->f138 = 0;
    ((Alt_8032A574 *)arg0)->f12C = 0;
    ((Alt_8032A574 *)arg0)->f134 = 0;
    ((Alt_8032A574 *)arg0)->f128 = 0;
    ((Alt_8032A574 *)arg0)->f13C = 1;
    arg0->f1C = 0;
    arg0->f20 = 0;
    arg0->f24 = arg0->f20;
    for (i = 0; i < 8; i++) {
        arg0->ents[i].a = 0.0f;
        arg0->ents[i].b = 0.0f;
        arg0->ents[i].c = 1.0f;
        arg0->ents[i].d = 1.0f;
    }
}
#undef arg0
extern "C" {

s32 release_texture_list(void *, s32);


uaddr TAdMcSelectCursorGC::get_instance(saddr arg0) {
    uaddr ad_mc_select_cursor_gc;

    if ((u32) TAdMcSelectCursorGC__instance == 0U) {
        ad_mc_select_cursor_gc = (uaddr)new TAdMcSelectCursorGC((TObject *)arg0);
        TAdMcSelectCursorGC__instance = ad_mc_select_cursor_gc;
    }
    return TAdMcSelectCursorGC__instance;
}


void TAdMcSelectCursorGC::release_cursor_entry() {
    u8 *value;
    if ((void **) (*(void ** *)&TAdMcSelectCursorGC__texture_entry) != NULL) {
        value = (u8 *)(*(*(void ** *)&TAdMcSelectCursorGC__texture_entry));
        if ((u32) *(u32 *)((s8 *)value + 8) != 0U) {
            release_texture_list((*(void ** *)&TAdMcSelectCursorGC__texture_entry), (saddr) value);
        }
    }
}

void TAdMcSelectCursorGC::init_resource() { TAdMcSelectCursorGC__texture_entry = (saddr)&mc_select_cursor_texture_list; load_streamed_prs_texture((saddr)"f256_memorycard_select", (saddr)&mc_select_cursor_texture_list); }

s32 TAdMcSelectCursorGC__sub_8032A6D8(void* p) { return *(s32*)((char*)p + 0x1c); }

    extern int memcard_cursor_instance_table[];
saddr TAdMcSelectCursorGC::get_cursor_type(int a0) {  return memcard_cursor_instance_table[a0]; }

}
