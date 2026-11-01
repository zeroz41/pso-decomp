#include "types.h"
#include "pso/misc/TWindowCtrlMain_8024674C.h"
#include "pso/misc/TWindowSubShortMail_80246CB8.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowCtrlMain.h"
#include "pso/misc/TWindowFukidasi.h"
#include "pso/misc/TLanguage.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TWindowSubShortMail.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"

struct Obj_80246948 { u8 pad[0x2c]; u32 f2c; };

extern s32 lbl_8044E658[];
extern s32 lbl_8044E688[];
extern s32 hud_palette_texture_filename[];
extern s32 lbl_8044E6B0[];
extern s32 lbl_8044E6C4[];
extern s32 lbl_8044E6D8[];
extern s32 lbl_8044E6F0[];
extern s32 lbl_8044E708[];
extern s32 lbl_8044E720[];
extern s32 lbl_8044E734[];
extern s32 lbl_8044E748[];
extern s32 lbl_8044E758[];
extern s32 f256_hyouji_texlist[];
extern u32 lbl_805D63F0;
extern s16 window_ui_theme_index;
extern "C" {
void release_texture_list(void*);

void TWindowCtrlMain::free_window() {
    if ((u32) lbl_805D63F0 != 0U) {
        release_texture_list((void*)lbl_805D63F0);
        lbl_805D63F0 = 0U;
    }
}
}

void load_hud_palette_textures(void) {
    s32 sp8[3];
    sp8[0] = TLobby::tmp_buf_use_req((const char *)lbl_8044E658);
    TLanguage::draw_string((void *)lbl_8044E688, (void *)sp8, 0x40);
    TLanguage::draw_string((void *)hud_palette_texture_filename, (void *)sp8, 0x41);
    TLanguage::draw_string((void *)lbl_8044E6B0, (void *)sp8, 0x42);
    TLanguage::draw_string((void *)lbl_8044E6C4, (void *)sp8, 0x44);
    TLanguage::draw_string((void *)lbl_8044E6D8, (void *)sp8, 0x45);
    TLanguage::draw_string((void *)lbl_8044E6F0, (void *)sp8, 0x46);
    TLanguage::draw_string((void *)lbl_8044E708, (void *)sp8, 0x47);
    TLanguage::draw_string((void *)lbl_8044E720, (void *)sp8, 1);
    TLanguage::draw_string((void *)lbl_8044E734, (void *)sp8, 0x4A);
    TLanguage::draw_string((void *)lbl_8044E748, (void *)sp8, 0x43);
    ((TLobby *)lbl_8044E658)->tmp_buf_release();
    TLobby__sub_8023E554((s32)lbl_8044E758, (s32)f256_hyouji_texlist);
    lbl_805D63F0 = (u32)f256_hyouji_texlist;
    TObjFish::set_global_param((s32)((void *)f256_hyouji_texlist));
    TLanguage::set_entry_index(0, 0x40);
    TLanguage::set_entry_index(1, 0x41);
    TLanguage::set_entry_index(2, 0x42);
    TLanguage::set_entry_index(3, 0x45);
    TLanguage::set_entry_index(4, 0x46);
    TLanguage::set_entry_index(5, 0x47);
    TLanguage::set_entry_index(0xB, 0x44);
    TLanguage::set_entry_index(0xC, 0x43);
    TLanguage::set_entry_index(6, 0x4A);
    TLanguage::set_entry_index(7, 1);
    TLanguage::set_entry_index(8, 1);
    TLanguage::set_entry_index(9, 1);
    TLanguage::set_entry_index(0xA, 1);
    window_ui_theme_index = 0;
}

u8 TWindowBase::sub_80246948() {
    Obj_80246948 *self = (Obj_80246948 *)this;
    return !(self->f2c & 1);
}

int TWindowFukidasi__sub_8024695C(void* p) { return (*(u32*)((char*)p + 0x2c) >> 8) & 0x1; }

int TWindowFukidasi::get_visible_flag() { return (*(u32*)((char*)this + 0x2c) >> 9) & 0x1; }

int TWindowFukidasi::is_bit10_set() { return (*(u32*)((char*)this + 0x2c) >> 10) & 0x1; }
void TWindowSubStatusDisp::update_entry_visibility() {
    u32 temp_r31;
    u32 temp_r30;
    u32 temp_r29;
    u32 temp_r28;
    u32 temp_r27;
    u32 temp_r26;
    u32 temp_r25;
    u32 temp_r24;
    s32 arg0 = (s32)this;
    temp_r31 = ((TWindowBase *)arg0)->get_array_entry(7);
    temp_r30 = ((TWindowBase *)arg0)->get_array_entry(6);
    temp_r29 = ((TWindowBase *)arg0)->get_array_entry(5);
    temp_r28 = ((TWindowBase *)arg0)->get_array_entry(4);
    temp_r27 = ((TWindowBase *)arg0)->get_array_entry(3);
    temp_r26 = ((TWindowBase *)arg0)->get_array_entry(2);
    temp_r25 = ((TWindowBase *)arg0)->get_array_entry(1);
    temp_r24 = ((TWindowBase *)arg0)->get_array_entry(0);
    if (is_guild_card_receive_active() != 0) {
        if (temp_r31 != 0U) {
            ((TWindowSubStatusDisp *)temp_r31)->clear_visible_flag();
        }
        if (temp_r30 != 0U) {
            ((TWindowSubStatusDisp *)temp_r30)->clear_visible_flag();
        }
    } else {
        if (temp_r31 != 0U) {
            ((TWindowHelpItem *)temp_r31)->set_flag0_bit2();
        }
        if (temp_r30 != 0U) {
            ((TWindowHelpItem *)temp_r30)->set_flag0_bit2();
        }
    }
    if (is_com_card_active() != 0) {
        if (temp_r29 != 0U) {
            ((TWindowSubStatusDisp *)temp_r29)->clear_visible_flag();
        }
        if (temp_r28 != 0U) {
            ((TWindowSubStatusDisp *)temp_r28)->clear_visible_flag();
        }
    } else {
        if (temp_r29 != 0U) {
            ((TWindowHelpItem *)temp_r29)->set_flag0_bit2();
        }
        if (temp_r28 != 0U) {
            ((TWindowHelpItem *)temp_r28)->set_flag0_bit2();
        }
    }
    if (TWindowSubShortMail::is_active() != 0) {
        if (temp_r27 != 0U) {
            ((TWindowSubStatusDisp *)temp_r27)->clear_visible_flag();
        }
        if (temp_r26 != 0U) {
            ((TWindowSubStatusDisp *)temp_r26)->clear_visible_flag();
        }
    } else {
        if (temp_r27 != 0U) {
            ((TWindowHelpItem *)temp_r27)->set_flag0_bit2();
        }
        if (temp_r26 != 0U) {
            ((TWindowHelpItem *)temp_r26)->set_flag0_bit2();
        }
    }
    if (is_trade_active() != 0) {
        if (temp_r25 != 0U) {
            ((TWindowSubStatusDisp *)temp_r25)->clear_visible_flag();
        }
        if (temp_r24 != 0U) {
            ((TWindowSubStatusDisp *)temp_r24)->clear_visible_flag();
        }
    } else {
        if (temp_r25 != 0U) {
            ((TWindowHelpItem *)temp_r25)->set_flag0_bit2();
        }
        if (temp_r24 != 0U) {
            ((TWindowHelpItem *)temp_r24)->set_flag0_bit2();
        }
    }
}
