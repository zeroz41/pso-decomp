#include "types.h"
#include "pso/misc/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/misc/TWindowSubStatusDisp_80287570.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowMeseta.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowSubStatusDisp.h"

#pragma readonly_strings on

extern "C" {
const char *TWindowMeseta__class_name = "TWindowMeseta";
}


struct Sub_80269244 { u8 pad0[8]; f32 x8; };

struct Meseta_80269244 {
    s32 name;
    u8 pad4[0x18 - 0x4];
    s32 *vt;
    u8 pad1c[0x38 - 0x1C];
    f32 x38;
    u8 pad3c[0x48 - 0x3C];
    f32 x48;
    u8 pad4c[0x60 - 0x4C];
    f32 x60;
    s32 x64;
    s32 meseta;
    f32 x6c;
    f32 x70;
};

extern "C" {
s32 get_meseta_value__13TWindowMesetaFv();
extern s32 TWindowMeseta__window_descriptor[];
extern s32 __vt__13TWindowMeseta[];
extern const char *TWindowMeseta__class_name;
void *TWindowMeseta__ct(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void *__dt__13TWindowMesetaFv(void *arg0, s16 arg1);
void __dl__7TObjectFPv(void *);


void TWindowMeseta::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;

    temp_r3 = get_meseta_value__13TWindowMesetaFv();
    if (temp_r3 != (s32) this->m_68) {
        this->m_68 = temp_r3;
        ((TWindowSubStatusDisp *)(((TWindowBase *)arg0)->get_array_entry(1)))->set_animated_target(this->m_68, 9.0f);
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_window_entry_list((u8 *)&this->m_24);
}

void *__dt__13TWindowMesetaFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TWindowMeseta;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#define self ((Meseta_80269244 *)arg0)
void *TWindowMeseta__ct(void *arg0, s32 arg1, s32 arg2, s32 str) {
    Sub_80269244 *a;
    Sub_80269244 *b;
    ((TWindowDD *)arg0)->construct_base((u8 *)TWindowMeseta__window_descriptor, (s16)arg2, (u8 *)arg1);
    self->vt = __vt__13TWindowMeseta;
    self->name = ((s32)TWindowMeseta__class_name);
    self->x64 = arg2;
    self->meseta = ((s32 (*)(void *))get_meseta_value__13TWindowMesetaFv)(arg0);
    a = (Sub_80269244 *)((TWindowBase *)arg0)->get_array_entry(0);
    b = (Sub_80269244 *)((TWindowBase *)arg0)->get_array_entry(1);
    set_text_entry_string((u8 *)a, str, 0);
    ((TWindowSubStatusDisp *)b)->set_all_values(self->meseta);
    self->x38 = 10.0f + b->x8;
    ((TWindowBase *)arg0)->save_position();
    self->x60 = TWindowSubStatusDisp__sub_802877A4(self->x48 - 16.0f);
    if (TCameraCtrl::get_camera_id() > 2) {
        self->x6c = 0.75f;
        self->x70 = 0.75f;
    } else {
        self->x6c = 1.0f;
        self->x70 = 1.0f;
    }
    return arg0;
}
#undef self

}
