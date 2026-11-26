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
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"

const f32 heading_title_offset[2] = { 0.0f, -13.0f };

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

void WindowHeading::render(WindowDrawContext *context) { draw(context); }

void WindowHeading::update() { advance_reveal(); }

WindowHeading::~WindowHeading() {}

WindowHeading::WindowHeading(saddr title, s32 client_id)
    : HeadingEntry((f32 *)heading_title_offset, title, 1, client_id) {}

#pragma push
#pragma scheduling off
void TWindowSubStatusDisp::fill_card_text_entries(GuildCardRecord *record) {
    saddr *items;
    saddr entry_1;
    saddr entry_3;
    saddr entry_5;
    saddr entry_7;
    saddr entry_6;
    saddr entry_8;
    items = (saddr *)(*(u8 * *)&this->m_flags);
    entry_1 = items[1];
    entry_3 = items[3];
    entry_5 = items[5];
    entry_7 = items[7];
    entry_6 = items[6];
    entry_8 = items[8];
    text_builder_reset();
    text_builder_append((u8 *)":");
    text_builder_append((u8 *)(record->get_sub_disp_ptr()));
    set_text_entry_string((WindowTextEntry *)entry_1, (uaddr)(get_shared_text_buffer()), 0x60);
    text_builder_reset();
    text_builder_append((u8 *)":");
    text_builder_append((u8 *)(record->get_name()));
    set_text_entry_string((WindowTextEntry *)entry_3, (uaddr)(get_shared_text_buffer()), 0x60);
    text_builder_reset();
    text_builder_append((u8 *)":");
    text_builder_append((u8 *)(TWindowSubComCard__sub_8027523C(record)));
    set_text_entry_string((WindowTextEntry *)entry_5, (uaddr)(get_shared_text_buffer()), 0x60);
    if ((s8) *(u8 *)record->get_card_data_ptr() != 0) {
        text_builder_reset();
        text_builder_append((u8 *)":");
        text_builder_append(((u8 *)record->get_card_data_ptr()));
        set_text_entry_string((WindowTextEntry *)entry_7, (uaddr)(get_shared_text_buffer()), 0x60);
        ((TWindowLayoutEntry *)entry_6)->show();
        ((TWindowLayoutEntry *)entry_7)->show();
    } else {
        ((TWindowLayoutEntry *)entry_6)->hide();
        ((TWindowLayoutEntry *)entry_7)->hide();
    }
    if (strcmp((const char *)(record->get_sub_obj()), (const char *)(record->get_sub_disp_ptr())) != 0) {
        text_builder_reset();
        text_builder_append((u8 *)(record->get_sub_obj()));
        text_builder_append((u8 *)(TWindowSubStatusDisp::get_message_10(0x45)));
        set_text_entry_string((WindowTextEntry *)entry_8, (uaddr)(get_shared_text_buffer()), 0x60);
        ((TWindowLayoutEntry *)entry_8)->show();
        return;
    }
    ((TWindowLayoutEntry *)entry_8)->hide();
}
#pragma pop
