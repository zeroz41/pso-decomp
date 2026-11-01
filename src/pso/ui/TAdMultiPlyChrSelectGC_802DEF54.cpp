#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802D50A0.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802E0FC8.h"
#include "pso/unk/text_802C6DD4.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802C50EC.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802DBCC4.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802DC3D4.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802DC760.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802DCD14.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802DD8E0.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802DE094.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802DEC44.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802DEF54.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/misc/TWindowSubComCard.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct V2_802DF9B4 { f32 x, y; };

struct I2_802DF9B4 { s32 a, b; };

struct Blk_802DF9B4 { V2_802DF9B4 a, b, c; };

extern "C" {
u32 __nw__7TObjectFUl(int);
s32 __ct__9TAdBackGCFv(void *, void *);
s32 __ct__12TAdBackTxtGCFv(void *, void *);
s32 __ct__10TAdTitleGCFP7TObjectl(void *, void *, int);
u32 __ct__13TAdTitleTexGCFv(void *, void *);
u32 __ct__14TAdSelectCurGCFv(void *, void *, void *, void *);
s32 set_entry_value__22TAdMultiPlyChrSelectGCFlUl(u32, int, void *);
u32 __ct__13TAdGuideTxtGCFv(void *, void *);
u32 __ct__14TAdGameStartGCFv(void *, s32);
u8 *get_or_create_slot_window__22TAdMultiPlyChrSelectGCFii(s32 arg0, s32 arg1);
s32 create__16TAdChrSelBSlotGCFPv(void *);
extern V2_802DF9B4 multi_chr_select_widget_layout[];
extern u8 lbl_80472808[];
extern I2_802DF9B4 lbl_80472828[];
extern Blk_802DF9B4 multi_chr_select_layout_table[];
extern V2_802DF9B4 lbl_80472848[];
extern s32 tl_02;
extern s32 tl_clipout;
extern s32 TAdMultiPlyChrSelectGC__data_805DE898;
s32 TWindowShortListCtrl__check_controller_button(void *, s32, s32);
s32 play_sound_effect(s32, s32, s32, s32);

extern s8 controller_physical_port_bank[];
extern u32 multi_chr_select_serial_access_state;

void update_state_serial__22TAdMultiPlyChrSelectGCFPv(void *arg0) {
    s32 temp_r5;

    if ((u32) *(u32 *)((s8 *)arg0 + 0x90) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x90)))->close();
        *(u32 *)((s8 *)arg0 + 0x90) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x80) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x80)))->close();
        *(u32 *)((s8 *)arg0 + 0x80) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x8C) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x8C)))->close();
        *(u32 *)((s8 *)arg0 + 0x8C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x98) != 0U) {
        ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x98)))->close();
        *(u32 *)((s8 *)arg0 + 0x98) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x7C) != 0U) {
        ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x7C)))->close();
        *(u32 *)((s8 *)arg0 + 0x7C) = 0U;
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x74) != 0U) {
        queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x74));
        *(u32 *)((s8 *)arg0 + 0x74) = 0U;
    }
    ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->set_state_ready();
    ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x5C)))->reset_cursor_state();
    ((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x60)))->set_field_100(1);
    *(s32 *)((s8 *)arg0 + 0x30) = -1;
    temp_r5 = *(s32 *)((s8 *)arg0 + 0x1C);
    *(s32 *)((s8 *)arg0 + 0x1C) = (temp_r5 + 1);
    if ((TWindowShortListCtrl__check_controller_button(controller_physical_port_bank + 0x20, 2, temp_r5) != 0) && (TAdMultiPlyChrSelectGC::get_chr_select_state() == 0)) {
        if ((((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x68)))->get_player_index() != 0xE) && ((s32) *(s32 *)((s8 *)arg0 + 0x1C) > 0xA)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            *(s32 *)((s8 *)arg0 + 0x20) = 0x1B;
            return;
        }
        if (TAdMultiPlyChrSelectGC__sub_802C6558() < 1) {
            play_sound_effect(0x52F16, 0, 0, 0);
            *(s32 *)((s8 *)arg0 + 0x20) = 0x1B;
            return;
        }
        goto block_19;
    }
block_19:
    if (((TAdMultiPlyChrSelectGC *)(*(s32 *)((s8 *)arg0 + 0x68)))->get_player_index() == 0xE) {
        *(s32 *)((s8 *)arg0 + 0x20) = 1;
        if ((s32) *(s32 *)((s8 *)arg0 + 0x9C) != 0) {
            *(s32 *)((s8 *)arg0 + 0x9C) = 0;
            if ((u32) multi_chr_select_serial_access_state != get_field_118__22TAdEnterSerialAccessGCFv()) {
                TAdMultiPlyChrSelectGC::reset_slot_selections();
            }
        }
    }
}

struct C_802DF114 {
    u8 pad0[0x1C];
    s32 f1C;
    s32 f20;
    s32 f24;
    u8 pad28[0x14];
    s32 f3C;
    s32 f40;
    u8 pad44[4];
    s32 f48;
    s32 f4C;
    u8 pad50[0x14];
    u32 f64;
};
typedef void (C_802DF114::*Pmf_802DF114)();
void set_default_camera__21TAdMultiChgGameModeGCFv(void *);
int TAdMultiPlyChrSelectGC__sub_802C6920(void);
extern "C" void TAdMultiPlyChrSelectGC__sub_802DCCA4();
extern "C" void update_idle_timer__22TAdMultiPlyChrSelectGCFv();
extern "C" void reset_to_select__22TAdMultiPlyChrSelectGCFv();
extern "C" void check_cancel_input__22TAdMultiPlyChrSelectGCFv();
extern "C" void close_and_reset__22TAdMultiPlyChrSelectGCFv();
extern "C" void close_windows__22TAdMultiPlyChrSelectGCFv();
extern "C" void handle_cancel_state__22TAdMultiPlyChrSelectGCFv();
extern "C" void handle_confirm_state__22TAdMultiPlyChrSelectGCFv();
extern "C" void handle_input__22TAdMultiPlyChrSelectGCFv();
extern "C" void init_windows__22TAdMultiPlyChrSelectGCFv();
extern "C" void open_char_select__22TAdMultiPlyChrSelectGCFv();
extern "C" void request_scene_change__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_button_input__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_card_confirm__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_card_select__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_card_select_state__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_confirm_start__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_input_state__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_select__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_state__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_state_move__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_state_option__22TAdMultiPlyChrSelectGCFv();
extern "C" void update_state_wait_card__22TAdMultiPlyChrSelectGCFv();
void *lbl_804E2B90[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_state_serial__22TAdMultiPlyChrSelectGCFPv,
};
void *lbl_804E2B9C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DEDA8,
};
void *lbl_804E2BA8[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_button_input__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2BB4[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DE7D0,
};
void *lbl_804E2BC0[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_card_confirm__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2BCC[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_state_option__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2BD8[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_card_select__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2BE4[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update__22TAdMultiPlyChrSelectGCFPv,
};
void *lbl_804E2BF0[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&close_windows__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2BFC[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&open_char_select__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2C08[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&init_windows__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2C14[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&reset_to_select__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2C20[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DDD08,
};
void *lbl_804E2C2C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DDBA8,
};
void *lbl_804E2C38[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_select__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2C44[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_state_wait_card__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2C50[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_card_select_state__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2C5C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_state__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2C68[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DD400,
};
void *lbl_804E2C74[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&handle_confirm_state__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2C80[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DD2B0,
};
void *lbl_804E2C8C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_state_move__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2C98[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DD010,
};
void *lbl_804E2CA4[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DCF68,
};
void *lbl_804E2CB0[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&handle_cancel_state__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2CBC[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_confirm_start__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2CC8[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_idle_timer__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2CD4[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DCD14,
};
void *lbl_804E2CE0[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DCCA4,
};
void *lbl_804E2CEC[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&close_and_reset__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2CF8[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DCA20,
};
void *lbl_804E2D04[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DC8A0,
};
void *lbl_804E2D10[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&update_input_state__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2D1C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DC5CC,
};
void *lbl_804E2D28[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&handle_input__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2D34[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DC440,
};
void *lbl_804E2D40[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&check_cancel_input__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2D4C[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&TAdMultiPlyChrSelectGC__sub_802DC310,
};
void *lbl_804E2D58[3] = {
    (void *)0x0, (void *)0xffffffff, (void *)&request_scene_change__22TAdMultiPlyChrSelectGCFv,
};
void *lbl_804E2D64[117] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
u8 *TAdMultiPlyChrSelectGC__instance;

void TAdMultiPlyChrSelectGC::run_task() {
    C_802DF114 *self = (C_802DF114 *)this;
    static s8 init;
    set_default_camera__21TAdMultiChgGameModeGCFv(self);
    self->f3C = 1;
    if (self->f48 != 1 && TAdMultiPlyChrSelectGC__sub_802C6848(0) == 0) {
        self->f3C = 0;
        set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 0, (void *)get_localized_text_entry(0x1F, 0xB));
        set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 1, &TAdMultiPlyChrSelectGC__data_805DE898);
    } else if (self->f48 != 1 && TAdMultiPlyChrSelectGC::count_ready() < 2) {
        self->f3C = 0;
        set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 0, (void *)get_localized_text_entry(0x1F, 0xC));
        set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 1, &TAdMultiPlyChrSelectGC__data_805DE898);
    } else {
        switch (self->f48) {
        case 0:
        case 2:
            if (self->f20 >= 0xC && self->f20 < 0x19) {
                if (TAdMultiPlyChrSelectGC__sub_802C6558() > 0) {
                    if (self->f40 == 0) {
                        if (TAdMultiPlyChrSelectGC__sub_802C6848(TAdMultiPlyChrSelectGC__sub_802C6920()) != 0) {
                            set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 0, TAdMultiPlyChrSelectGC::format_player_number_text((s32)self, (s32)(TAdMultiPlyChrSelectGC__sub_802C6920())));
                            set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 1, &TAdMultiPlyChrSelectGC__data_805DE898);
                        } else {
                            set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 0, &TAdMultiPlyChrSelectGC__data_805DE898);
                            set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 1, &TAdMultiPlyChrSelectGC__data_805DE898);
                        }
                    } else {
                        set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 0, (void *)get_localized_text_entry(0x1F, 0xD));
                        set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 1, (void *)get_localized_text_entry(0x1F, 0xE));
                    }
                } else if (self->f40 == 0) {
                    set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 0, &TAdMultiPlyChrSelectGC__data_805DE898);
                    set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 1, &TAdMultiPlyChrSelectGC__data_805DE898);
                } else {
                    set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 0, (void *)get_localized_text_entry(0x1F, 0xD));
                    set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 1, (void *)get_localized_text_entry(0x1F, 0xE));
                }
            } else if (self->f20 >= 3 && TAdMultiPlyChrSelectGC__sub_802C6848(TAdMultiPlyChrSelectGC::get_clamped_cursor()) != 0) {
                if (self->f40 == 0) {
                    ((TAdMultiPlyChrSelectGC *)self)->sub_802DC118(TAdMultiPlyChrSelectGC::get_clamped_cursor());
                } else {
                    set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 0, (void *)get_localized_text_entry(0x1F, 0xD));
                    set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 1, (void *)get_localized_text_entry(0x1F, 0xE));
                }
            } else if (self->f40 == 0) {
                set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 0, &TAdMultiPlyChrSelectGC__data_805DE898);
                set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 1, &TAdMultiPlyChrSelectGC__data_805DE898);
            } else {
                set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 0, (void *)get_localized_text_entry(0x1F, 0xD));
                set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 1, (void *)get_localized_text_entry(0x1F, 0xE));
            }
            break;
        case 1:
            set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 0, (void *)get_localized_text_entry(0x1F, 1));
            set_entry_value__22TAdMultiPlyChrSelectGCFlUl(self->f64, 1, &TAdMultiPlyChrSelectGC__data_805DE898);
            break;
        }
    }
    if (!init) {
        ((Pmf_802DF114 *)lbl_804E2D64)[0] = *(Pmf_802DF114 *)lbl_804E2B90;
        ((Pmf_802DF114 *)lbl_804E2D64)[1] = *(Pmf_802DF114 *)lbl_804E2B9C;
        ((Pmf_802DF114 *)lbl_804E2D64)[2] = *(Pmf_802DF114 *)lbl_804E2BA8;
        ((Pmf_802DF114 *)lbl_804E2D64)[3] = *(Pmf_802DF114 *)lbl_804E2BB4;
        ((Pmf_802DF114 *)lbl_804E2D64)[4] = *(Pmf_802DF114 *)lbl_804E2BC0;
        ((Pmf_802DF114 *)lbl_804E2D64)[5] = *(Pmf_802DF114 *)lbl_804E2BCC;
        ((Pmf_802DF114 *)lbl_804E2D64)[6] = *(Pmf_802DF114 *)lbl_804E2BD8;
        ((Pmf_802DF114 *)lbl_804E2D64)[7] = *(Pmf_802DF114 *)lbl_804E2BE4;
        ((Pmf_802DF114 *)lbl_804E2D64)[8] = *(Pmf_802DF114 *)lbl_804E2BF0;
        ((Pmf_802DF114 *)lbl_804E2D64)[9] = *(Pmf_802DF114 *)lbl_804E2BFC;
        ((Pmf_802DF114 *)lbl_804E2D64)[10] = *(Pmf_802DF114 *)lbl_804E2C08;
        ((Pmf_802DF114 *)lbl_804E2D64)[11] = *(Pmf_802DF114 *)lbl_804E2C14;
        ((Pmf_802DF114 *)lbl_804E2D64)[12] = *(Pmf_802DF114 *)lbl_804E2C20;
        ((Pmf_802DF114 *)lbl_804E2D64)[13] = *(Pmf_802DF114 *)lbl_804E2C2C;
        ((Pmf_802DF114 *)lbl_804E2D64)[14] = *(Pmf_802DF114 *)lbl_804E2C38;
        ((Pmf_802DF114 *)lbl_804E2D64)[15] = *(Pmf_802DF114 *)lbl_804E2C44;
        ((Pmf_802DF114 *)lbl_804E2D64)[16] = *(Pmf_802DF114 *)lbl_804E2C50;
        ((Pmf_802DF114 *)lbl_804E2D64)[17] = *(Pmf_802DF114 *)lbl_804E2C5C;
        ((Pmf_802DF114 *)lbl_804E2D64)[18] = *(Pmf_802DF114 *)lbl_804E2C68;
        ((Pmf_802DF114 *)lbl_804E2D64)[19] = *(Pmf_802DF114 *)lbl_804E2C74;
        ((Pmf_802DF114 *)lbl_804E2D64)[20] = *(Pmf_802DF114 *)lbl_804E2C80;
        ((Pmf_802DF114 *)lbl_804E2D64)[21] = *(Pmf_802DF114 *)lbl_804E2C8C;
        ((Pmf_802DF114 *)lbl_804E2D64)[22] = *(Pmf_802DF114 *)lbl_804E2C98;
        ((Pmf_802DF114 *)lbl_804E2D64)[23] = *(Pmf_802DF114 *)lbl_804E2CA4;
        ((Pmf_802DF114 *)lbl_804E2D64)[24] = *(Pmf_802DF114 *)lbl_804E2CB0;
        ((Pmf_802DF114 *)lbl_804E2D64)[25] = *(Pmf_802DF114 *)lbl_804E2CBC;
        ((Pmf_802DF114 *)lbl_804E2D64)[26] = *(Pmf_802DF114 *)lbl_804E2CC8;
        ((Pmf_802DF114 *)lbl_804E2D64)[27] = *(Pmf_802DF114 *)lbl_804E2CD4;
        ((Pmf_802DF114 *)lbl_804E2D64)[28] = *(Pmf_802DF114 *)lbl_804E2CE0;
        ((Pmf_802DF114 *)lbl_804E2D64)[29] = *(Pmf_802DF114 *)lbl_804E2CEC;
        ((Pmf_802DF114 *)lbl_804E2D64)[30] = *(Pmf_802DF114 *)lbl_804E2CF8;
        ((Pmf_802DF114 *)lbl_804E2D64)[31] = *(Pmf_802DF114 *)lbl_804E2D04;
        ((Pmf_802DF114 *)lbl_804E2D64)[32] = *(Pmf_802DF114 *)lbl_804E2D10;
        ((Pmf_802DF114 *)lbl_804E2D64)[33] = *(Pmf_802DF114 *)lbl_804E2D1C;
        ((Pmf_802DF114 *)lbl_804E2D64)[34] = *(Pmf_802DF114 *)lbl_804E2D28;
        ((Pmf_802DF114 *)lbl_804E2D64)[35] = *(Pmf_802DF114 *)lbl_804E2D34;
        ((Pmf_802DF114 *)lbl_804E2D64)[36] = *(Pmf_802DF114 *)lbl_804E2D40;
        ((Pmf_802DF114 *)lbl_804E2D64)[37] = *(Pmf_802DF114 *)lbl_804E2D4C;
        ((Pmf_802DF114 *)lbl_804E2D64)[38] = *(Pmf_802DF114 *)lbl_804E2D58;
        init = 1;
    }
    self->f24 = self->f20;
    self->f4C = TAdMultiPlyChrSelectGC::get_clamped_cursor();
    (self->*((Pmf_802DF114 *)lbl_804E2D64)[self->f20])();
    if (self->f24 != self->f20) {
        self->f1C = 0;
    }
}
void TAdMultiPlyChrSelectGC::create_widgets() {
    u32 p;
    p = __nw__7TObjectFUl(0x24);
    if (p != 0) {
        __ct__9TAdBackGCFv((void *) p, this);
    }
    p = __nw__7TObjectFUl(0x28);
    if (p != 0) {
        __ct__12TAdBackTxtGCFv((void *) p, this);
    }
    switch (this->m_48) {
    case 0:
    case 2:
        p = __nw__7TObjectFUl(0x138);
        if (p != 0) {
            __ct__10TAdTitleGCFP7TObjectl((void *) p, this, 0);
        }
        *(s32 *)&this->unk_68 = (s32)get_or_create_slot_window__22TAdMultiPlyChrSelectGCFii((s32)this, 1);
        *(s32 *)&this->unk_60 = get_or_create_player__22TAdMultiPlyChrSelectGCFiiii((s32)this, 1, -1, 0);
        break;
    case 1: {
        p = __nw__7TObjectFUl(0x138);
        if (p != 0) {
            __ct__10TAdTitleGCFP7TObjectl((void *) p, this, 8);
        }
        *(s32 *)&this->unk_68 = (s32)get_or_create_slot_window__22TAdMultiPlyChrSelectGCFii((s32)this, 2);
        this->m_6c = create__16TAdChrSelBSlotGCFPv(this);
        I2_802DF9B4 pos = lbl_80472828[0];
        p = __nw__7TObjectFUl(0x708);
        if (p != 0) {
            p = __ct__14TAdSelectCurGCFv((void *) p, this, &pos, lbl_80472808);
        }
        *(u32 *)&this->unk_70 = p;
        *(s32 *)&this->unk_60 = get_or_create_player__22TAdMultiPlyChrSelectGCFiiii((s32)this, 2, -1, 0);
        break;
    }
    }
    p = __nw__7TObjectFUl(0x44);
    if (p != 0) {
        p = __ct__13TAdGuideTxtGCFv((void *) p, this);
    }
    this->m_64 = p;
    set_entry_value__22TAdMultiPlyChrSelectGCFlUl(this->m_64, 0, &TAdMultiPlyChrSelectGC__data_805DE898);
    set_entry_value__22TAdMultiPlyChrSelectGCFlUl(this->m_64, 1, &TAdMultiPlyChrSelectGC__data_805DE898);
    p = __nw__7TObjectFUl(0x9C);
    if (p != 0) {
        p = __ct__13TAdTitleTexGCFv((void *) p, this);
    }
    Blk_802DF9B4 blk = multi_chr_select_layout_table[0];
    fn_802D50B8((void *)p, (void *)&blk.a, (void *)&blk.b, (void *)&blk.c);
    p = __nw__7TObjectFUl(0xD4);
    if (p != 0) {
        p = __ct__14TAdGameStartGCFv((void *) p, tl_clipout);
    }
    *(u32 *)&this->unk_78 = p;
    V2_802DF9B4 v = lbl_80472848[0];
    v.x = multi_chr_select_widget_layout[0].x;
    v.y = multi_chr_select_widget_layout[0].y;
    this->m_5c = (s32)fn_802C6F20(tl_02, (s32)&v);
    TAdMultiPlyChrSelectGC::get_move_effect(tl_clipout);
}

}
