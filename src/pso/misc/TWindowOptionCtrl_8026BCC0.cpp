#include "types.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TWindowBase.h"
#include "pso/boss/TObjBoss2Tunnel_8007C5C0.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLoadCtrl_80227390.h"
#include "pso/misc/TWindowOptionCtrl_8026C5D8.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TWindowSoundBalance.h"
#include "pso/misc/TWindowMessageYesNo.h"
#include "pso/misc/TWindowOptionCtrl.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubComCard.h"

struct Opt_8026BCC0 {
    u8 pad0[0x1C];
    s8 state;
    u8 f1D;
    u8 pad1E[2];
    s16 f20;
    u8 pad22[2];
    s32 f24;
    void *f28;
    void *f2C;
    void *f30;
    void *f34;
    void *f38;
    void *f3C;
    void *f40;
    void *f44;
    void *f48;
};

extern "C" {
void *create_menu__17TWindowOptionCtrlFv(void *);
void *create_select_menu_window__17TWindowOptionCtrlFv(void *);
s32 update_selected_item__17TWindowOptionCtrlFv(void *);
void *create_list_window__17TWindowOptionCtrlFv(void *);
extern u8 lbl_8044F4B4[];
void *create_sound_mode_menu__17TWindowOptionCtrlFv(void *);
void *create_sound_balance_window__17TWindowOptionCtrlFv(void *);
s32 get_field_64__17TWindowOptionCtrlFv(void *p);
void set_params__17TWindowOptionCtrlFPvsSc(void *arg0, s16 arg1, s8 arg2);
void *create_snap_shot_window__17TWindowOptionCtrlFv(void *);
void *__nw__7TObjectFUl(u32);
void *ct__13TUnk_804F01A8Fv(void *arg0);
void *create_sub_menu_window__17TWindowOptionCtrlFv(void *);
void *create_option_menu__17TWindowOptionCtrlFv(void *);
void set_field_value__17TWindowOptionCtrlFls(s32 arg0, s16 arg1);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
void play_sound_effect(int, int, int, int);
extern u8 controller_input_state[];
void TWindowOptionCtrl::run_task() {
    Opt_8026BCC0 *self = (Opt_8026BCC0 *)this;
    switch (self->state) {
    case 0:
    case 1:
        if (self->f44 != NULL) {
            ((TWindowBase *)self->f44)->close();
            self->f44 = NULL;
        }
        if (self->f40 != NULL) {
            ((TWindowSubComCard *)(self->f40))->close();
            self->f40 = NULL;
        }
        if (self->f3C != NULL) {
            ((TWindowBase *)self->f3C)->close();
            self->f3C = NULL;
        }
        if (self->f38 != NULL) {
            ((TWindowBase *)self->f38)->close();
            self->f38 = NULL;
        }
        if (self->f34 != NULL) {
            ((TWindowBase *)self->f34)->close();
            self->f34 = NULL;
        }
        if (self->f2C != NULL) {
            ((TWindowBase *)self->f2C)->close();
            self->f2C = NULL;
        }
        if (self->f28 == NULL) {
            self->f28 = create_menu__17TWindowOptionCtrlFv(self);
        }
        ((TWindowSubComCard *)(self->f28))->clear_transition_flag();
        ((TWindowSubComCard *)(self->f28))->clear_flag_and_release();
        self->state = 2;
    case 2:
        if (((TWindowMenu *)(self->f28))->is_cancelled() != 0) {
            self->state = 0x1B;
        } else if (((TWindowMenu *)(self->f28))->is_decided() != 0) {
            self->state = ((TWindowMenu *)self->f28)->get_selected_value();
        }
        break;
    case 3:
        ((TWindowOptionCtrl *)(self->f28))->open();
        if (self->f34 == NULL) {
            self->f34 = create_select_menu_window__17TWindowOptionCtrlFv(self);
        }
        self->state = 4;
    case 4:
        if (((TWindowMenuIconLine *)(self->f34))->is_cancelled() != 0) {
            self->state = 1;
        }
        if (((TWindowOptionCtrl *)self)->handle_input(update_selected_item__17TWindowOptionCtrlFv(self->f34)) != 0) {
            self->state = 1;
        }
        break;
    case 5:
        TWindowOptionCtrl__sub_802273B4(0x1E);
        ((TWindowOptionCtrl *)(self->f28))->open();
        if (self->f2C == NULL) {
            self->f2C = create_list_window__17TWindowOptionCtrlFv(self);
        }
        self->state = 6;
    case 6:
        if (((TWindowMenu *)(self->f2C))->is_cancelled() != 0) {
            if (self->f1D & 2) {
                TWindowOptionCtrl__sub_802273B4(0x1E);
                self->f1D &= ~2;
                ((TWindowOptionCtrl *)(self->f2C))->clear_flag70_bit4();
            } else {
                TLobby::stop_audio_streams();
                TLobby::close_option_window();
                play_area_music((char *)lbl_8044F4B4);
                self->state = 1;
                break;
            }
        }
        if (((TWindowMenu *)(self->f2C))->is_decided() != 0) {
            ((TWindowOptionCtrl *)self)->apply_and_close(((TWindowMenu *)self->f2C)->get_selected_value());
            ((TWindowSubComCard *)(self->f2C))->clear_flag_and_release();
        }
        break;
    case 7:
        ((TWindowOptionCtrl *)(self->f28))->open();
        if (self->f34 == NULL) {
            self->f34 = create_sound_mode_menu__17TWindowOptionCtrlFv(self);
        }
        self->state = 8;
    case 8:
        self->f20 = update_selected_item__17TWindowOptionCtrlFv(self->f34);
        if (((TWindowMenuIconLine *)(self->f34))->is_cancelled() != 0) {
            self->state = 1;
        }
        break;
    case 9:
        ((TWindowOptionCtrl *)(self->f28))->open();
        if (self->f38 == NULL) {
            self->f38 = create_sound_balance_window__17TWindowOptionCtrlFv(self);
        }
        self->state = 0xA;
    case 10:
        if (TWindowOptionCtrl__sub_8026C658(self->f38) != 0) {
            s16 b = get_field_64__17TWindowOptionCtrlFv(self->f38);
            ((void (*)(void *, s16, s16)) set_params__17TWindowOptionCtrlFPvsSc)(self, (s16)((TWindowOptionCtrl *)(self->f38))->get_field_62(), b);
            self->state = 1;
        } else if (((TWindowSoundBalance *)(self->f38))->is_active() != 0) {
            s16 b = get_field_64__17TWindowOptionCtrlFv(self->f38);
            ((void (*)(void *, s16, s16)) set_params__17TWindowOptionCtrlFPvsSc)(self, (s16)((TWindowOptionCtrl *)(self->f38))->get_field_62(), b);
            self->state = 1;
        }
        break;
    case 11:
        if (TObjBoss2Tunnel::save_snapshot() != 1) {
            self->state = 0xE;
        } else {
            save_screen_snapshot();
            self->state = 0xC;
        }
        break;
    case 12:
        if (TObjBoss2Tunnel::load_snapshot() != 0) {
            ((TWindowOptionCtrl *)(self->f28))->open();
            if (self->f3C == NULL) {
                self->f3C = create_snap_shot_window__17TWindowOptionCtrlFv(self);
            }
            self->state = 0xD;
        }
        break;
    case 13:
        if (TWindowOptionCtrl__sub_8026C630(self->f3C) != 0) {
            self->state = 1;
        }
        break;
    case 14:
        if (self->f48 == NULL) {
            void *p = __nw__7TObjectFUl(0x30);
            if (p != NULL) {
                p = ((void *(*)(void *, void *)) ct__13TUnk_804F01A8Fv)(p, self);
            }
            self->f48 = p;
        }
        ((TWindowOptionCtrl *)(self->f28))->open();
        self->state = 0xF;
    case 15: {
        s32 r = ((TWindowOptionCtrl *)(self->f48))->get_field_24();
        if (r == 1 || r == 2) {
            queue_destruction__7TObjectFv(self->f48);
            self->f48 = NULL;
            if (r == 1) {
                self->state = 0xB;
            } else {
                self->state = 1;
            }
        } else if (r == 3) {
            TKeyBoardControl__sub_8000F9CC(0);
        }
        break;
    }
    case 16:
        if (self->f40 != NULL) {
            ((TWindowSubComCard *)(self->f40))->close();
            self->f40 = NULL;
        }
        if (self->f34 != NULL) {
            ((TWindowBase *)self->f34)->close();
            self->f34 = NULL;
        }
        if (self->f30 != NULL) {
            ((TWindowBase *)self->f30)->close();
            self->f30 = NULL;
        }
        if (self->f2C == NULL) {
            self->f2C = create_sub_menu_window__17TWindowOptionCtrlFv(self);
        }
        ((TWindowOptionCtrl *)(self->f28))->open();
        ((TWindowSubComCard *)(self->f2C))->clear_transition_flag();
        ((TWindowSubComCard *)(self->f2C))->clear_flag_and_release();
        self->state = 0x11;
    case 17:
        if (((TWindowMenu *)(self->f2C))->is_cancelled() != 0) {
            self->state = 1;
        } else if (((TWindowMenu *)(self->f2C))->is_decided() != 0) {
            self->state = ((TWindowMenu *)self->f2C)->get_selected_value();
        }
        break;
    case 18:
        ((TWindowOptionCtrl *)(self->f2C))->open();
        if (self->f34 == NULL) {
            self->f34 = create_option_menu__17TWindowOptionCtrlFv(self);
        }
        self->state = 0x13;
    case 19:
        ((void (*)(void *, s32)) set_field_value__17TWindowOptionCtrlFls)(self, update_selected_item__17TWindowOptionCtrlFv(self->f34));
        if (((TWindowMenuIconLine *)(self->f34))->is_cancelled() != 0) {
            self->state = 0x10;
        }
        break;
    case 20:
    case 21:
        self->state = 0x17;
        break;
    case 22:
        if (((TWindowMenu *)(self->f30))->is_cancelled() != 0) {
            self->state = 0x10;
        }
        if (((TWindowMenu *)(self->f30))->is_decided() != 0) {
            self->state = 0x17;
        }
        break;
    case 23:
        if (self->f40 == NULL) {
            switch (((TWindowMenu *)self->f2C)->get_selected_value()) {
            case 0x14:
                self->f40 = (void *)TWindowOptionCtrl::open_yes_no_window((s32)self, 0x22, 0xD0);
                break;
            case 0x15:
                self->f40 = (void *)TWindowOptionCtrl::open_yes_no_window((s32)self, 0x24, 0xD0);
                break;
            }
        }
        ((TWindowOptionCtrl *)(self->f2C))->open();
        self->state = 0x18;
    case 24:
        if (((TWindowSubComCard *)(self->f40))->get_card_data() != 0) {
            self->state = 0x10;
        } else if (((TWindowMessageYesNo *)(self->f40))->is_child_visible() != 0) {
            if (((TWindowSubComCard *)(self->f40))->get_slot_or_neg1() == 0) {
                if (((TWindowMenu *)self->f2C)->get_selected_value() == 0x14) {
                    self->f24 = 1;
                } else {
                    self->f24 = 3;
                }
                self->state = 0x1B;
            } else {
                self->state = 0x10;
            }
        }
        break;
    case 25:
        if (self->f44 == NULL) {
            self->f44 = (void *)((TWindowOptionCtrl *)((void *)TWindowOptionCtrl::get_option_entry(0xCF)))->create_serial_info_window(1);
        }
        ((TWindowOptionCtrl *)(self->f28))->open();
        self->state = 0x1A;
    case 26:
        if (TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 6) != 0 ||
            test_flag_4c__23TAdSinglePlyChrSelectGCFv(controller_input_state + 0x160, 6) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            self->state = 1;
        }
        break;
    case 27:
        self->f1D |= 1;
        break;
    }
}

}
