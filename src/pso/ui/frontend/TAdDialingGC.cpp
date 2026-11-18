#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/network/TLobby_803FAEA0.h"
#include "pso/ui/frontend/TAdDialingGC_80328210.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdDialingGC.h"
#include "pso/unk/TLobby_8013AD38.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdDialingGC_80328B20.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_8014618C.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"

struct Stack_803286AC {
    s32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    u8 pad_1C[0xC];
    s32 sp28;
};

struct Obj_803285C0 { u8 pad[0x20]; s32 mode; u8 pad2[0xC]; s16 state; };

TAdDialingGC *TAdDialingGC__instance;
extern "C" {
s32 create_guide_button(void *, void *, f32);
s32 init_guide_button_params(void *);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
extern TAdDialingGC *TAdDialingGC__instance;
void init_dialog__12TAdDialingGCFv(void *);
void draw_dialing_status__12TAdDialingGCFv(void *);
s32 update_status_message__12TAdDialingGCFv();
s32 __ct__10TAdTitleGCFP7TObjectl(u32, void *, s32);
u32 __nw__7TObjectFUl(s32);
s8 func_801A5E54__Fv();
s32 handle_state__12TAdDialingGCFv();
extern s32 TLobby__net_session_mode;
}

struct Obj_80328874 { u8 pad[0x9C]; s32 state; };

extern "C" {
void refresh_display__12TAdDialingGCFv(void *);
s32 render_status_disp__23TAdSinglePlyChrSelectGCFff(f32, f32);
}

struct Obj_80328990 { u8 pad[0x9C]; u32 state; };

extern "C" {
int update_dialing_display__12TAdDialingGCFi(void*);
BOOL fn_80145A44(char *dst);
s32 call_146CA0_with_5708__6TLobbyFv();
int sprintf(char *, const char *, ...);
}

extern "C" {
s32 update_dial_state__12TAdDialingGCFv();
s32 update_state__12TAdDialingGCFv();
s32 update_dial_state__12TAdDialingGCFl();
#pragma readonly_strings on
const char *TAdDialingGC__name = "TAdDialingGC";
extern const char *TAdDialingGC__name;
}

TAdDialingGC::TAdDialingGC(TObject *parent) : TObject(parent) {
    *(s32 *)((s8 *)this + 0) = (s32) ((s32)TAdDialingGC__name);
    TAdDialingGC__instance = this;
    if (TLobby::is_state_active() != 0) {
        this->m_1c = 1;
    } else if (TLobby__sub_8014618C() == 1) {
        this->m_1c = 2;
    } else {
        this->m_1c = 0;
    }
    this->m_20 = 0;
    this->m_24 = 0;
    this->m_28 = 0;
    this->m_30 = 0;
    this->m_68 = 0;
    this->m_a0 = 0;
    this->m_a4 = 0;
}

extern "C" {
TAdDialingGC::~TAdDialingGC() {
    TAdDialingGC__instance = 0;
}

void TAdDialingGC::run_task() {

    switch (this->m_1c) {
    case 0:
        update_dial_state__12TAdDialingGCFl();
        break;
    case 1:
        update_state__12TAdDialingGCFv();
        break;
    case 2:
        update_dial_state__12TAdDialingGCFv();
        break;
    }
    update_selection();
    this->m_24 = (this->m_24 + 1);
}

void TAdDialingGC::render() { TAdDialingGC__sub_80328B20(); render_if_flag_set(); draw_if_flag_set(); update(); }

}

__declspec(section ".rodata") extern const NJS_POINT2 lbl_804767A8[] = { 0, 28.0f };
__declspec(section ".rodata") extern const NJS_POINT2 lbl_804767B0[] = { 640.0f, 84.0f };
__declspec(section ".rodata") extern const NJS_POINT2 lbl_804767B8[] = { 0, 310.0f };
__declspec(section ".rodata") extern const NJS_POINT2 lbl_804767C0[] = { 640.0f, 136.0f };
extern const char lbl_804767C8[5] = "%s%s";
void TAdDialingGC::render_if_flag_set() {
    if ((this->m_a4 & 1) && ((s32) this->m_1c == 0)) {
        TAdDialingGC__sub_80328B24(lbl_804767A8, lbl_804767B0);
    }
}

void TAdDialingGC::draw_if_flag_set() {
    TAdDialingGC *self = this;
    if (self->m_a4 & 1) {
        TAdDialingGC__sub_80328B24(lbl_804767B8, lbl_804767C0);
    }
}

// Draws a flat dark-blue quad of `size` (w, h) at `origin` (x, y) (one 2D polygon, four points).
void TAdDialingGC__sub_80328B24(const NJS_POINT2 *origin, const NJS_POINT2 *size) {
    NJS_POINT2 pos[4];
    NJS_POINT2COL poly;
    NJS_COLOR col[4];
    poly.p = pos;
    poly.col = col;
    poly.tex = NULL;
    poly.num = 4;
    poly.p[0].x = origin->x;
    poly.p[0].y = origin->y;
    poly.col[0].color = 0x8F;
    poly.p[1].x = origin->x;
    poly.p[1].y = origin->y + size->y;
    poly.col[1].color = 0x8F;
    poly.p[2].x = origin->x + size->x;
    poly.p[2].y = origin->y + size->y;
    poly.col[2].color = 0x8F;
    poly.p[3].x = origin->x + size->x;
    poly.p[3].y = origin->y;
    poly.col[3].color = 0x8F;
    ((TObjCMHairMenu *)&poly)->draw_tri_fan_2d(4, 7, -120.0f);
}

void TAdDialingGC__sub_80328B20(void) {  }

extern "C" {
void TAdDialingGC::draw_dialing_status() {
    char a[0x20];
    char c[0x100];
    char b[0x100];
    if (fn_80145A44(a) == 0) {
        a[0] = 0;
    }
    sprintf(b, lbl_804767C8, a, call_146CA0_with_5708__6TLobbyFv());
    sprintf(c, (char *)get_connection_message_text(1), b);
    ((TAdSinglePlyChrSelectGC *)c)->render_status_disp(23.0f, 351.0f);
}

void TAdDialingGC::init_dialog() {
    get_connection_message_text(0);
    render_status_disp__23TAdSinglePlyChrSelectGCFff(23.0f, 331.0f);
}

int TAdDialingGC::refresh_display() { return update_dialing_display__12TAdDialingGCFi((void*)(8)); }

void TAdDialingGC::update_status_display() {
    Obj_80328990 *arg0 = (Obj_80328990 *)this;
    switch (this->m_9c) {
    case 1:
        refresh_display__12TAdDialingGCFv(arg0);
        return;
    case 2:
        TAdDialingGC::update_dialing_display(9);
        return;
    case 3:
        TAdDialingGC::update_dialing_display(0xA);
        return;
    case 4:
        TAdDialingGC::update_dialing_display(0xC);
        return;
    case 5:
        TAdDialingGC::update_dialing_display(0xB);
        return;
    case 6:
        TAdDialingGC::update_dialing_display(0xD);
        return;
    case 7:
        TAdDialingGC::update_dialing_display(6);
        return;
    case 16:
        TAdDialingGC::update_dialing_display(5);
        return;
    case 8:
        TAdDialingGC::update_dialing_display(0xF);
        return;
    case 9:
        TAdDialingGC::update_dialing_display(0x10);
        return;
    case 10:
        TAdDialingGC::update_dialing_display(0x10);
        return;
    case 0:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 17:
        return;
    }
}

void TAdDialingGC::handle_state() {

    switch (this->m_9c) {
    case 11:
        TAdDialingGC::update_dialing_display(0x11);
        return;
    case 12:
        TAdDialingGC::update_dialing_display(0x12);
        return;
    case 13:
        TAdDialingGC::update_dialing_display(0x13);
        return;
    case 14:
        refresh_display__12TAdDialingGCFv(this);
        return;
    case 15:
        TAdDialingGC::update_dialing_display(0x16);
        return;
    default:
        TAdDialingGC::update_dialing_display(0x10);
        return;
    }
}

void TAdDialingGC::update_status_message() {
    Obj_80328874 *arg0 = (Obj_80328874 *)this;
    switch (this->m_9c) {
    case 11:
        TAdDialingGC::update_dialing_display(0x11);
        return;
    case 12:
        TAdDialingGC::update_dialing_display(0x12);
        return;
    case 13:
        TAdDialingGC::update_dialing_display(0x13);
        return;
    case 14:
        refresh_display__12TAdDialingGCFv(arg0);
        return;
    case 8:
        TAdDialingGC::update_dialing_display(0xF);
        return;
    case 15:
        TAdDialingGC::update_dialing_display(0x16);
        return;
    default:
        TAdDialingGC::update_dialing_display(0x10);
        return;
    }
}

void TAdDialingGC::update_dialing_display(int _w0) {
    get_connection_message_text(_w0);
    render_status_disp__23TAdSinglePlyChrSelectGCFff(23.0f, 331.0f);
}

void TAdDialingGC::update() {

    switch (this->m_1c) {
    case 0:
        if ((s32) this->m_20 != 0) {
            update_state_display();
        }
        break;
    case 1:
        if ((s32) this->m_20 == 2) {
            update_status_message__12TAdDialingGCFv();
            return;
        }
        break;
    case 2:
        if ((s32) this->m_20 == 2) {
            handle_state__12TAdDialingGCFv();
        }
        break;
    }
}

void TAdDialingGC__sub_80328730(s32 arg0) {
    if (TAdDialingGC__instance != 0) {
        TAdDialingGC__instance->m_9c = arg0;
        TAdDialingGC__instance->m_20 = 2;
        switch (TAdDialingGC__instance->m_1c) {
        case 0:
            TAdDialingGC__instance->spawn_title_screen();
            TAdDialingGC__instance->show_guide_button();
            break;
        case 1:
        case 2:
            switch (arg0) {
            case 0:
            case 16:
            case 17:
                return;
            }
            TAdDialingGC__instance->spawn_title_screen();
            TAdDialingGC__instance->show_guide_button();
            break;
        }
    }
}

void TAdDialingGC::show_guide_button() {
    u8 *arg0 = (u8 *)this;
    Stack_803286AC stack;
    if (!(this->m_a4 & 2)) {
        init_guide_button_params(&stack.sp8);
        stack.sp8 = 1;
        stack.sp28 = get_localized_text_entry(0xF, 0x13);
        stack.spC = 485.0f;
        stack.sp14 = 485.0f;
        stack.sp10 = 421.0f;
        stack.sp18 = 421.0f;
        create_guide_button(arg0, &stack.sp8, 485.0f);
        this->m_a4 = (s32) (this->m_a4 | 2);
    }
}

void TAdDialingGC::update_state_display() {
    Obj_803285C0 *arg0 = (Obj_803285C0 *)this;
    if (*(s32 *)&this->m_20 == 2) {
        switch (*(s16 *)&this->m_30) {
        case 0:
            ((TAdDialingGC *)arg0)->update_status_display();
            break;
        case 4:
            TAdDialingGC::update_dialing_display(0x14);
            break;
        case 6:
            TAdDialingGC::update_dialing_display(3);
            break;
        case 8:
            ((TAdDialingGC *)arg0)->update_status_display();
            break;
        case 1: case 2: case 3: case 5: case 7:
            break;
        }
    }
    if (*(s32 *)&this->m_20 == 1) {
        switch (*(s16 *)&this->m_30) {
        case 0:
            TAdDialingGC::update_dialing_display(0x17);
            break;
        case 2:
            init_dialog__12TAdDialingGCFv(arg0);
            draw_dialing_status__12TAdDialingGCFv(arg0);
            break;
        case 3:
            TAdDialingGC::update_dialing_display(2);
            break;
        case 4:
            TAdDialingGC::update_dialing_display(0x14);
            break;
        case 6:
        case 8:
            TAdDialingGC::update_dialing_display(0x17);
            break;
        case 1: case 5: case 7:
            break;
        }
    }
}

void TAdDialingGC::update_selection() {
    *(s16 *)&this->m_68 = (s16) *(s16 *)&this->m_30;
    if ((s32) TLobby__net_session_mode != 0) {
        *(s16 *)&this->m_30 = 0;
        return;
    }
    NetGetLinkStatus((NetLinkStatus *)&this->_pad2C);
    if ((s16) *(s16 *)&this->m_68 != (s16) *(s16 *)&this->m_30) {
        *(s32 *)&this->m_24 = 0;
    }
}

s32 TAdDialingGC__sub_803284F8(s32 _w0) {
    if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)&controller_input_state + 0x20), 0x706) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state + 0x160), 0x606) != 0)) {
        return 1;
    }
    return 0;
}

void TAdDialingGC::spawn_title_screen() {
    if (!(this->m_a4 & 1)) {
        u32 temp_nw;
        if (((s32) this->m_1c == 0) && ((temp_nw = __nw__7TObjectFUl(0x138)) != 0U)) {
            __ct__10TAdTitleGCFP7TObjectl(temp_nw, this, 5);
        }
        create_draw_line_ctrl((TObject *)this, 0x11, 0.0f);
        this->m_a4 = (s32) (this->m_a4 | 1);
    }
}

void TAdDialingGC::update_dial_state(s32 arg1) {
    switch (this->m_20) {
    case 0:
        this->m_a0++;
        if ((s32) this->m_a0 > 0x5A) {
            spawn_title_screen();
            show_guide_button();
            this->m_a0 = 0;
            this->m_20 = 1;
        }
        return;
    case 2:
        if (func_801A5E54__Fv() != 0) {
            this->m_20 = 3;
            return;
        }
        this->m_a0 = (this->m_a0 + 1);
        switch (this->m_9c) {
        case 16:
        case 0:
            if ((s32) this->m_a0 > 0x5A) {
                this->m_20 = 3;
                return;
            }
            break;
        case 17:
            this->m_20 = 3;
            return;
        default:
            show_guide_button();
            if (TAdDialingGC__sub_803284F8((s32)this) != 0) {
                this->m_20 = 3;
                return;
            }
            break;
        }
        break;
    case 3:
        queue_destruction();
        break;
    }
}

void TAdDialingGC::update_state() {
    s32 temp_r0_2;

    switch (this->m_20) {
    case 0:
        this->m_20 = 1;
        return;
    case 2:
        temp_r0_2 = this->m_9c;
        if (temp_r0_2 < 0x10) {
            if (temp_r0_2 == 0) {
                goto block_11;
            }
            goto block_12;
        }
        if (temp_r0_2 < 0x12) {
block_11:
            this->m_20 = 3;
            return;
        }
block_12:
        if (TAdDialingGC__sub_803284F8((s32)this) != 0) {
            this->m_20 = 3;
        }
        break;
    case 3:
        queue_destruction();
        break;
    }
}

void TAdDialingGC::update_dial_state() {
    s32 temp_r0_2;

    switch (this->m_20) {
    case 0:
        this->m_20 = 1;
        return;
    case 2:
        temp_r0_2 = this->m_9c;
        if (temp_r0_2 < 0x10) {
            if (temp_r0_2 == 0) {
                goto block_11;
            }
            goto block_12;
        }
        if (temp_r0_2 < 0x12) {
block_11:
            this->m_20 = 3;
            return;
        }
block_12:
        if (TAdDialingGC__sub_803284F8((s32)this) != 0) {
            this->m_20 = 3;
        }
        break;
    case 3:
        queue_destruction();
        break;
    }
}

}
