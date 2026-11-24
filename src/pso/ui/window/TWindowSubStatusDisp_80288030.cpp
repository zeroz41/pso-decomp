#include "types.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/unk/GuildCardRecord.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include <string.h>
#include "pso/unk/TLobby_8001D6A0.h"
#include "pso/ui/window/TWindowSubStatusDisp_80228F5C.h"

extern "C" {
u8 *init_heading_entry__20TWindowSubStatusDispFPvPvici(u8 *arg0, u8 *arg1, saddr arg2, s8 arg3, s32 arg4);
extern const f32 lbl_8044FCF0[2] = { 0.0f, -13.0f };
}
void text_builder_reset(void);
void set_text_entry_string(u8 *arg0, uaddr str, s32 arg2);
// The HUD palette texture names; load_hud_palette_textures loads the archive into this list.
NJS_TEXNAME f256_hyouji_texname[13] = { // the texture names of f256_hyouji_texlist
    { "f256_hyouji_a", 0, 0 },
    { "f256_hyouji_b", 0, 0 },
    { "f256_hyouji_c", 0, 0 },
    { "f256_actionpallet_a", 0, 0 },
    { "f256_actionpallet_b", 0, 0 },
    { "f256_actionpallet_c", 0, 0 },
    { "f256_duelcount", 0, 0 },
    { "r256_symobj01", 0, 0 },
    { "r256_symobj02", 0, 0 },
    { "r256_symobj03", 0, 0 },
    { "r256_symparts", 0, 0 },
    { "b256_mainmenu", 0, 0 },
    { "f256_carsol", 0, 0 },
};

NJS_TEXLIST f256_hyouji_texlist = { f256_hyouji_texname, 13 };

extern "C" {
int TWindowSubStatusDisp__sub_802879B0(void*);

void TWindowSubStatusDisp::forward_render(void *level) { this->update(level); }
int TWindowSubStatusDisp::update_subwindow() { return TWindowSubStatusDisp__sub_802879B0(this); }
s32 TWindowSubStatusDisp::destroy_status_display(saddr arg0, s16 arg1) {
    if (arg0 != 0) {
        TWindowSubStatusDisp::deleting_destructor(arg0, 0);
        if (arg1 > 0) {
            ::operator delete((void *)arg0);
        }
    }
    return arg0;
}

u8 *TWindowSubStatusDisp::construct_type1_heading(s32 title, s32 client_index) {
    init_heading_entry__20TWindowSubStatusDispFPvPvici(((u8 *)this), (u8 *)lbl_8044FCF0, title, 1, client_index);
    return ((u8 *)this);
}

#pragma push
#pragma scheduling off
void TWindowSubStatusDisp::fill_card_text_entries(GuildCardRecord *record) {
    u8 *temp_r3;
    saddr temp_r31;
    saddr temp_r30;
    saddr temp_r29;
    saddr temp_r28;
    saddr temp_r27;
    saddr temp_r26;
    temp_r3 = (u8 *)(*(u8 * *)&this->m_flags);
    temp_r31 = *(s32 *)((s8 *)temp_r3 + 4);
    temp_r30 = *(s32 *)((s8 *)temp_r3 + 0xC);
    temp_r29 = *(s32 *)((s8 *)temp_r3 + 0x14);
    temp_r28 = *(s32 *)((s8 *)temp_r3 + 0x1C);
    temp_r27 = *(s32 *)((s8 *)temp_r3 + 0x18);
    temp_r26 = *(s32 *)((s8 *)temp_r3 + 0x20);
    text_builder_reset();
    text_builder_append((u8 *)":");
    text_builder_append((u8 *)(record->get_sub_disp_ptr()));
    set_text_entry_string((u8 *)temp_r31, (uaddr)(get_shared_text_buffer()), 0x60);
    text_builder_reset();
    text_builder_append((u8 *)":");
    text_builder_append((u8 *)(record->get_name()));
    set_text_entry_string((u8 *)temp_r30, (uaddr)(get_shared_text_buffer()), 0x60);
    text_builder_reset();
    text_builder_append((u8 *)":");
    text_builder_append((u8 *)(TWindowSubComCard__sub_8027523C(record)));
    set_text_entry_string((u8 *)temp_r29, (uaddr)(get_shared_text_buffer()), 0x60);
    if ((s8) *(u8 *)record->get_card_data_ptr() != 0) {
        text_builder_reset();
        text_builder_append((u8 *)":");
        text_builder_append(((u8 *)record->get_card_data_ptr()));
        set_text_entry_string((u8 *)temp_r28, (uaddr)(get_shared_text_buffer()), 0x60);
        ((TWindowSubStatusDisp *)temp_r27)->clear_visible_flag();
        ((TWindowSubStatusDisp *)temp_r28)->clear_visible_flag();
    } else {
        ((TWindowHelpItem *)temp_r27)->set_flag0_bit2();
        ((TWindowHelpItem *)temp_r28)->set_flag0_bit2();
    }
    if (strcmp((const char *)(record->get_sub_obj()), (const char *)(record->get_sub_disp_ptr())) != 0) {
        text_builder_reset();
        text_builder_append((u8 *)(record->get_sub_obj()));
        text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x45)));
        set_text_entry_string((u8 *)temp_r26, (uaddr)(get_shared_text_buffer()), 0x60);
        ((TWindowSubStatusDisp *)temp_r26)->clear_visible_flag();
        return;
    }
    ((TWindowHelpItem *)temp_r26)->set_flag0_bit2();
}
}
#pragma pop
