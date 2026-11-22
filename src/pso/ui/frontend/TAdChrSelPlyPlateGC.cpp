#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/unk/text_80299420.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdPlyPltAnimCtrlGC.h"
#include "pso/ui/frontend/TAdChrSelPlyPlateGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802C6F88.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/system/vector.h"

typedef struct G_802C6A10 { s32 value; u8 remaining[0xC]; } G_802C6A10;

typedef struct Jump_802C5C84 {
    s32 v[4];
} Jump_802C5C84;

struct Pad_802C6AC8 { u8 pad[0x20]; u8 ctl[0x30]; };

extern s32 multi_ply_chr_select_slot_table[][5];
extern "C" {
s32 get_field_20__22TAdMultiPlyChrSelectGCFv();
s32 lbl_805D67D0;
s32 lbl_805D67D4;
s32 play_sound_effect(int, void *, int, int);
void TAdChrSelPlyPlateGC__update_cell_uvs(TAdChrSelPlyPlateGC *);
extern u8 controller_physical_port_bank[];
}

s32 multi_ply_chr_select_player_slot[4] = {
    0, 0, 0, 0,
};
s32 TAdMultiPlyChrSelectGC__selected_slot_order[4] = {
    0, 0, 0, 0,
};
s32 multi_ply_chr_select_slot_table[6][5] = {
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
};
s32 multi_ply_chr_select_tag_shown[4] = {
    0, 0, 0, 0,
};
f32 multi_ply_chr_select_tag_alpha[4] = {
    0, 0, 0, 0,
};
s32 multiplayer_controller_device_codes[4] = {
    0, 6, 12, 18,
};

const s32 multi_ply_chr_select_default_slot_table[6][5] = {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 1, 1, 0, 0 },
    { 0, 1, -1, 0, 0 },
    { 0, 0, 0, 0, 0 },
};
const Jump_802C5C84 multi_chr_select_cursor_jump_table[6][5] = {
    { { 0, 0, 0, 0 }, { 4, 0, 0, 0 }, { 3, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
    { { 0, 0, 2, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, -2 }, { 0, 0, 0, 0 } },
    { { 0, 0, 2, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, -2 }, { 0, 0, 0, 0 } },
    { { 0, 0, 2, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, -2 }, { 0, 0, 0, 0 } },
    { { 0, 0, 2, 0 }, { 0, 0, 0, 0 }, { 0, -3, 0, -1 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
    { { 0, 0, 0, 0 }, { 0, -4, 0, 0 }, { 0, -4, 0, 0 }, { 0, 0, 0, 0 }, { 0, 0, 0, 0 } },
};
const f32 multi_ply_chr_select_tag_size[2] = { 180.0f, 38.0f };

const char *TAdChrSelPlyPlateGC__name = "TAdChrSelPlyPlateGC";

#define WIN_802C6008 ((void *)(controller_physical_port_bank + TAdMultiPlyChrSelectGC__selected_slot * 0x50 + 0x20))
#define WIN_802C61E4 ((void *)(controller_physical_port_bank + multi_ply_chr_select_active_player * 0x50 + 0x20))

int multi_ply_chr_select_active_player;
s32 TAdMultiPlyChrSelectGC__select_mode;
s32 TAdMultiPlyChrSelectGC__selected_slot;
TAdChrSelPlyPlateGC *ad_chr_sel_ply_plate_instance;
TAdChrSelPlyPlateGC *TAdChrSelPlyPlateGC__create_singleton(TObject *parent, vec2f *pos) {
    if (ad_chr_sel_ply_plate_instance != NULL) {
        return NULL;
    }
    ad_chr_sel_ply_plate_instance = new TAdChrSelPlyPlateGC(parent, pos);
    return ad_chr_sel_ply_plate_instance;
}

TAdChrSelPlyPlateGC::TAdChrSelPlyPlateGC(TObject *parent, vec2f *pos) : TObject(parent) {
    u32 i;
    u32 j;
    m_name = TAdChrSelPlyPlateGC__name;
    lbl_805D67D0 = TAdMultiPlyChrSelectGC__sub_802C6FA8();
    lbl_805D67D4 = TAdMultiPlyChrSelectGC::get_global_6700();
    TAdMultiPlyChrSelectGC__select_mode = 0;
    copy_vec2(&this->pos, pos);
    unk_1c = -1;
    unk_4e8 = 0;
    TAdMultiPlyChrSelectGC__selected_slot = 0;
    multi_ply_chr_select_active_player = 0;
    cursor_col = 0;
    unk_4f0 = 0;
    unk_4f4 = 0;
    unk_4f8 = 0;
    unk_4fc = 0;
    unk_20 = multi_ply_chr_select_active_player;
    unk_534 = 1;
    TAdChrSelPlyPlateGC__update_cell_uvs(this);
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            cursor_color[i][j] = 0;
            cursor_alpha[i][j] = 0;
            unk_500[i][j] = 0;
            sel[i][j] = 0;
            unk_4dc[j] = 0;
        }
        multi_ply_chr_select_tag_shown[i] = 0;
        multi_ply_chr_select_tag_alpha[i] = 0.0f;
    }
    TAdMultiPlyChrSelectGC::reset_slot_selection_table();
    TAdPlyPltAnimCtrlGC::get_instance((saddr)tl_clipout);
}

TAdChrSelPlyPlateGC::~TAdChrSelPlyPlateGC() {
    if (ad_chr_sel_ply_plate_instance != NULL) {
        ad_chr_sel_ply_plate_instance = NULL;
    }
}

void TAdChrSelPlyPlateGC::run_task() {
    u32 i;
    u32 j;
    u32 k;
    if (TAdMultiPlyChrSelectGC__is_controller_connected(TAdMultiPlyChrSelectGC::get_clamped_cursor()) == 0 && unk_20 < TAdMultiPlyChrSelectGC::count_ready()) {
        multi_ply_chr_select_active_player = find_active_slot();
        switch (TAdMultiPlyChrSelectGC__select_mode) {
        case 1:
            break;
        case 0: {
            u32 buf[2];
            find_first_open_cell(buf);
            cursor_col = buf[1] - 1;
            sel[multi_ply_chr_select_active_player][cursor_col] = buf[0] - 1;
            break;
        }
        }
    }
    if (TAdMultiPlyChrSelectGC__is_controller_connected(0) == 0 || TAdMultiPlyChrSelectGC::count_ready() < 2) {
        unk_534 = 0;
    } else {
        unk_534 = 1;
    }
    if (unk_534 != 0) {
        switch (TAdMultiPlyChrSelectGC__select_mode) {
        case 0:
            handle_dpad_input();
            if (TAdMultiPlyChrSelectGC::get_clamped_cursor() == 3 && is_multiplayer_character_slot_selected(3) != 0) {
                s32 n = TAdMultiPlyChrSelectGC::count_ready();
                if (TAdMultiPlyChrSelectGC__count_selected_slots() < n) {
                    multi_ply_chr_select_active_player = find_active_slot();
                }
            }
            break;
        case 1:
            update_option_cursor();
            break;
        }
    }
    unk_530 = 0;
    if (unk_534 != 0) {
        for (i = 0; i < 4; i++) {
            if (TWindowShortListCtrl__check_controller_button(((Pad_802C6AC8 *)controller_physical_port_bank)[i].ctl, 8) != 0 && TAdMultiPlyChrSelectGC__count_selected_slots() > 0) {
                unk_530 = 1;
            }
        }
    }
    for (k = 0; k < 4; k++) {
        for (j = 0; j < 3; j++) {
            cursor_alpha[k][j] -= 0x16;
            if (cursor_alpha[k][j] < 0) {
                cursor_alpha[k][j] = 0;
            }
        }
    }
    cursor_alpha[sel[multi_ply_chr_select_active_player][cursor_col]][cursor_col] = 0xFF;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            cursor_color[i][j] = (cursor_alpha[i][j] << 24) | 0xFFFFFF;
        }
    }
    if (unk_4fc != 0) {
        unk_4f8 = 0;
        unk_4fc = 0;
    }
    unk_20 = TAdMultiPlyChrSelectGC::count_ready();
}

s32 TAdChrSelPlyPlateGC::find_active_slot() {
    s32 var_r31;
    var_r31 = 0;
loop_1:
    if ((TAdMultiPlyChrSelectGC__is_controller_connected(var_r31) != 0) && (is_multiplayer_character_slot_selected(var_r31) == 0)) {
        return var_r31;
    }
    var_r31 += 1;
    if (var_r31 >= 4) {
        return 3;
    }
    goto loop_1;
}

void TAdMultiPlyChrSelectGC::reset_slot_selections() {
    s32 i;
    for (i = 0; i < 4; i++) {
        multi_ply_chr_select_player_slot[i] = -1;
        TAdMultiPlyChrSelectGC__selected_slot_order[i] = -1;
    }
    TAdMultiPlyChrSelectGC::reset_slot_selection_table();
    multi_ply_chr_select_active_player = 0;
}

s32 TAdMultiPlyChrSelectGC::get_clamped_cursor() {
    if (((s32) multi_ply_chr_select_active_player < 0) || ((s32) multi_ply_chr_select_active_player > 3)) {
        multi_ply_chr_select_active_player = 0;
    }
    return multi_ply_chr_select_active_player;
}

void TAdMultiPlyChrSelectGC::add_selected_slot() {
    s32 i;
    if (multi_ply_chr_select_active_player < 0 || (u32)multi_ply_chr_select_active_player >= 4) {
        multi_ply_chr_select_active_player = 0;
    }
    for (i = 0; i < 4; i++) {
        if (TAdMultiPlyChrSelectGC__selected_slot_order[i] == -1) {
            TAdMultiPlyChrSelectGC__selected_slot_order[i] = multi_ply_chr_select_active_player;
            return;
        }
    }
    TAdMultiPlyChrSelectGC__selected_slot_order[3] = multi_ply_chr_select_active_player;
}

saddr TAdMultiPlyChrSelectGC__get_last_selected_player(void) {
    s32 i;
    s32 slot;
    if (multi_ply_chr_select_active_player < 0 || (u32)multi_ply_chr_select_active_player >= 4) {
        multi_ply_chr_select_active_player = 0;
    }
    for (i = 3; i >= 0; i--) {
        slot = TAdMultiPlyChrSelectGC__selected_slot_order[i];
        if (slot != -1) {
            s32 result = slot;
            if (result < 0 || (u32)result > 4) {
                result = 0;
            }
            return result;
        }
    }
    return 0;
}

void TAdMultiPlyChrSelectGC::remove_selected_slot(s32 arg0) {
    u32 i;
    u32 j;
    for (i = 0; i < 4; i++) {
        if (arg0 == TAdMultiPlyChrSelectGC__selected_slot_order[i]) {
            for (j = i; j < 4; j++) {
                if (j < 3) {
                    TAdMultiPlyChrSelectGC__selected_slot_order[j] = TAdMultiPlyChrSelectGC__selected_slot_order[j + 1];
                }
            }
            TAdMultiPlyChrSelectGC__selected_slot_order[3] = -1;
            return;
        }
    }
}

s32 TAdMultiPlyChrSelectGC__is_controller_connected(s32 arg0) {
    if ((arg0 < 0) || (arg0 > 3)) {
        return 0;
    }
    return *(s32 *)((s8 *)(*(s32 **)((s8 *)(TKeyBoardControl__sub_803DEB74(multiplayer_controller_device_codes[arg0])) + 0x30)) + 0) & 1;
}

#pragma push
#pragma fp_contract on
void TAdChrSelPlyPlateGC__show_selected_slot_tags(TAdChrSelPlyPlateGC *self) {
    s32 i;
    s32 c;
    s32 r;
    u32 cell[2];
    f32 top;
    f32 bottom;
    for (i = 0; i < sizeof(multi_ply_chr_select_tag_shown) / sizeof(multi_ply_chr_select_tag_shown[0]); i++) {
        if (is_multiplayer_character_slot_selected(i)) {
            multi_ply_chr_select_tag_shown[i] = 1;
            TAdMultiPlyChrSelectGC::split_slot_index(i, &c, &r);
            self->quad[i + 4][0].x = self->quad[r][c].x;
            self->quad[i + 4][0].z = self->quad[r][c].z;
            self->quad[i + 4][0].y = self->quad[r][c].y;
            self->quad[i + 4][0].w = self->quad[r][c].w;
            self->quad[i + 4][0].u0 = 0.0f;
            top = i * multi_ply_chr_select_tag_size[1];
            self->quad[i + 4][0].v0 = top / 256.0f;
            self->quad[i + 4][0].u1 = multi_ply_chr_select_tag_size[0] / 256.0f;
            bottom = i * multi_ply_chr_select_tag_size[1] + multi_ply_chr_select_tag_size[1];
            self->quad[i + 4][0].v1 = bottom / 256.0f;
            s32 row = r + 1;
            s32 col = c + 1;
            multi_ply_chr_select_slot_table[row][col] = -1;
        }
    }
    multi_ply_chr_select_active_player = ((TAdChrSelPlyPlateGC *)self)->find_active_slot();
    self->find_first_open_cell(cell);
    self->cursor_col = cell[1] - 1;
    self->sel[multi_ply_chr_select_active_player][self->cursor_col] = cell[0] - 1;
}
#pragma pop

void TAdMultiPlyChrSelectGC__deselect_slot(s32 arg0) {
    s32 c;
    s32 r;
    multi_ply_chr_select_tag_shown[arg0] = 0;
    multi_ply_chr_select_tag_alpha[arg0] = 0.0f;
    TAdMultiPlyChrSelectGC::split_slot_index(arg0, &c, &r);
    s32 ri = r + 1;
    s32 ci = c + 1;
    multi_ply_chr_select_slot_table[ri][ci] = multi_ply_chr_select_default_slot_table[ri][ci];
    multi_ply_chr_select_player_slot[arg0] = -1;
    TAdMultiPlyChrSelectGC::remove_selected_slot(arg0);
}

s32 TAdMultiPlyChrSelectGC__get_multiplayer_character_slot(s32 arg0) {
    s32 temp_r3;
    s32 var_r3;
    var_r3 = arg0;
    if ((var_r3 > 3) || (var_r3 < 0)) {
        var_r3 = 3;
    }
    temp_r3 = multi_ply_chr_select_player_slot[var_r3];
    if (temp_r3 == -1) {
        return 0;
    }
    return temp_r3;
}

s32 TAdMultiPlyChrSelectGC__count_selected_slots(void) {
    s32 n = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (multi_ply_chr_select_player_slot[i] != -1) n++;
    }
    return n;
}

s32 TAdMultiPlyChrSelectGC::count_ready() {
    s32 var_r31;
    s32 var_r30;
    var_r31 = 0;
    var_r30 = 0;
    do {
        if (TAdMultiPlyChrSelectGC__is_controller_connected(var_r30) != 0) {
            var_r31 += 1;
        }
        var_r30 += 1;
    } while (var_r30 < 4);
    return var_r31;
}

s32 is_multiplayer_character_slot_selected(s32 arg0) {
    if ((arg0 < 0) || ((u32) arg0 > 3U)) {
        return 0;
    }
    if (multi_ply_chr_select_player_slot[arg0] == -1) {
        return 0;
    }
    return 1;
}

s32 TAdMultiPlyChrSelectGC::is_selection_confirmed() {
    if (TAdMultiPlyChrSelectGC__sub_80299454() != 0) {
        if (TAdMultiPlyChrSelectGC__count_selected_slots() > 0) {
            return ((s32)TAdMultiPlyChrSelectGC__get_last_selected_player());
        }
        return 0;
    }
    return 0;
}

s32 TAdMultiPlyChrSelectGC::get_status() {
    s32 var_r3 = (s32) multi_ply_chr_select_active_player;
    if (var_r3 == 0) {
        return 0;
    }
    switch ((s32) TAdMultiPlyChrSelectGC__select_mode) {
    case 0:
        return var_r3;
    case 1:
        return (s32) TAdMultiPlyChrSelectGC__selected_slot;
    default:
        return 0;
    }
}

void TAdMultiPlyChrSelectGC::init() { multi_ply_chr_select_active_player = TAdMultiPlyChrSelectGC__get_last_selected_player(); TAdMultiPlyChrSelectGC__get_last_selected_player(); ((int (*)(void))TAdMultiPlyChrSelectGC__deselect_slot)(); }

void TAdChrSelPlyPlateGC::handle_dpad_input() {
    s32 n;
    s32 m;
    unk_1c++;
    TAdChrSelPlyPlateGC__update_cell_uvs(this);
    n = TAdMultiPlyChrSelectGC::count_ready();
    m = TAdMultiPlyChrSelectGC__count_selected_slots();
    if (m != n && unk_4dc[cursor_col] != 0 && unk_4f8 == 0) {
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)WIN_802C61E4, 0x10, 6, 1) != 0) {
            move_cursor(cursor_col, sel[multi_ply_chr_select_active_player][cursor_col], 0, -1, unk_4dc[cursor_col]);
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)WIN_802C61E4, 0x20, 6, 1) != 0) {
            move_cursor(cursor_col, sel[multi_ply_chr_select_active_player][cursor_col], 0, 1, unk_4dc[cursor_col]);
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)WIN_802C61E4, 0x80, 6, 1) != 0) {
            move_cursor(cursor_col, sel[multi_ply_chr_select_active_player][cursor_col], 1, 0, 2);
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)WIN_802C61E4, 0x40, 6, 1) != 0) {
            move_cursor(cursor_col, sel[multi_ply_chr_select_active_player][cursor_col], -1, 0, 2);
        }
    }
    if (TWindowShortListCtrl__check_controller_button(WIN_802C61E4, 4) != 0 && unk_4f8 == 0) {
        unk_4f8 = 1;
    }
}

void TAdChrSelPlyPlateGC::update_option_cursor() {
    unk_1c++;
    TAdChrSelPlyPlateGC__update_cell_uvs(this);
    if (unk_4dc[cursor_col] != 0 && unk_4f8 == 0) {
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)WIN_802C6008, 0x10, 6, 1) != 0) {
            play_sound_effect(0x54100, 0, 0, 0);
            sel[multi_ply_chr_select_active_player][cursor_col]--;
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)WIN_802C6008, 0x20, 6, 1) != 0) {
            play_sound_effect(0x54100, 0, 0, 0);
            sel[multi_ply_chr_select_active_player][cursor_col]++;
        }
        if (sel[multi_ply_chr_select_active_player][cursor_col] > unk_4dc[cursor_col] - 1) {
            sel[multi_ply_chr_select_active_player][cursor_col] = 0;
        }
        if (sel[multi_ply_chr_select_active_player][cursor_col] < 0) {
            sel[multi_ply_chr_select_active_player][cursor_col] = unk_4dc[cursor_col] - 1;
        }
    }
    if (TWindowShortListCtrl__check_controller_button(WIN_802C6008, 4) != 0 && unk_4f8 == 0) {
        unk_4f8 = 1;
    }
}
extern "C" {

void TAdChrSelPlyPlateGC__update_cell_uvs(TAdChrSelPlyPlateGC *self) {
    u32 i;
    u32 j;
    s32 cnt;
    s32 idx;
    f32 uu;
    f32 a;
    f32 b;

    /* Per-player 4x3 grid of selection quads: cell texture coords scale the shared
       (u,v) page, with the active-slot column clamped to 3. */
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            cnt = multi_ply_chr_select_active_player;
            uu = 0.0f;
            idx = 3;
            if (cnt < 4) {
                idx = cnt;
            }
            /* The identity
               i++/i-- pair between the v0 and u1 stores is load-bearing: it
               re-ties the allocator onto orig's row-pointer/clamp numbering. */
            self->quad[i][j].u0 = uu;
            a = 38.0f * (f32)idx;
            b = 38.0f + a;
            self->quad[i][j].v0 = a / 256.0f;
            i++;
            i--;
            self->quad[i][j].u1 = 0.703125f;
            self->quad[i][j].v1 = b / 256.0f;
        }
    }

    /* Fixed home slots for the trailing (unpaired) columns. */
    self->cursor[0][4] = 0.0625f;
    self->cursor[0][5] = 0.875f;
    self->cursor[0][6] = 0.125f;
    self->cursor[0][7] = 0.9453125f;
    self->cursor[1][4] = 0.0f;
    self->cursor[1][5] = 0.875f;
    self->cursor[1][6] = 0.0625f;
    self->cursor[1][7] = 0.9453125f;
    self->cursor[2][4] = 0.125f;
    self->cursor[2][5] = 0.875f;
    self->cursor[2][6] = 0.1875f;
    self->cursor[2][7] = 0.9453125f;
}

void TAdChrSelPlyPlateGC::move_cursor(s32 x_, s32 y_, s32 dx, s32 dy, s32 depth) {
    s32 x = x_;
    s32 y = y_;
    s32 dir;
    s32 nx;
    s32 ny;
    s32 cnt;
    s32 k;
    x++;
    y++;
    if (dy == -1) dir = 0;
    if (dy == 1) dir = 1;
    if (dx == -1) dir = 2;
    if (dx == 1) dir = 3;
    ny = y + dy;
    nx = x + dx;
    if (multi_ply_chr_select_slot_table[ny][nx] == 1) {
        x += dx;
        y += dy;
        play_sound_effect(0x54100, NULL, 0, 0);
        cursor_col = x - 1;
        sel[multi_ply_chr_select_active_player][cursor_col] = y - 1;
        return;
    }
    if (multi_ply_chr_select_slot_table[ny][nx] == 0) {
        Jump_802C5C84 j = multi_chr_select_cursor_jump_table[ny][nx];
        switch (dir) {
        case 0:
        case 1:
            ny += j.v[dir];
            break;
        case 2:
        case 3:
            nx += j.v[dir];
            break;
        }
        ny -= dy;
        nx -= dx;
        move_cursor(nx - 1, ny - 1, dx, dy, depth - 1);
        return;
    }
    if (multi_ply_chr_select_slot_table[ny][nx] == -1) {
        if (dy != 0) {
            cnt = 0;
            for (k = 0; k < 4; k++) {
                if (multi_ply_chr_select_slot_table[k + 1][cursor_col + 1] == -1) {
                    cnt++;
                }
            }
            if (cnt == 4) {
                nx = 3 - x;
                move_cursor(nx - 1, y - 1, dx, dy, 4);
            } else {
                move_cursor(nx - 1, ny - 1, dx, dy, 4);
            }
            return;
        }
        cnt = 0;
        for (k = 0; k < 4; k++) {
            if (multi_ply_chr_select_slot_table[k + 1][nx] == -1) {
                cnt++;
            }
        }
        if (cnt == 4) {
            return;
        }
        switch (x) {
        case 0:
            nx = 1;
            break;
        case 3:
            nx = 2;
            break;
        default:
            nx = 3 - x;
            break;
        }
        if (y < 3) {
            ny = 0;
            dx = 0;
            dy = 1;
        } else {
            ny = 5;
            dx = 0;
            dy = -1;
        }
        move_cursor(nx - 1, ny - 1, dx, dy, 4);
    }
}

void TAdChrSelPlyPlateGC::find_first_open_cell(u32 *cell) {
    u32 p;
    s32 q;
    for (p = 1; p < 3; p++) {
        for (q = 1; q < 5; q++) {
            if (multi_ply_chr_select_slot_table[q][p] == 1) {
                cell[0] = q;
                cell[1] = p;
                return;
            }
        }
    }
}

void TAdMultiPlyChrSelectGC::split_slot_index(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 var_r3;
    var_r3 = TAdMultiPlyChrSelectGC__get_multiplayer_character_slot(arg0);
    *arg1 = var_r3 > 3;
    if (var_r3 > 3) {
        var_r3 -= 4;
    }
    *arg2 = var_r3;
}

void TAdMultiPlyChrSelectGC::reset_slot_selection_table() {
    u32 i;
    s32 j;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 5; j++) {
            multi_ply_chr_select_slot_table[i][j] = multi_ply_chr_select_default_slot_table[i][j];
        }
    }
}

void TAdChrSelPlyPlateGC__add_slot_position(TAdChrSelPlyPlateGC *self, const void *src, s32 col) {
    if ((u32)self->unk_4dc[col] < 4) {
        copy_vec2(&self->home[self->unk_4dc[col]][col], (void *)src);
        self->quad[self->unk_4dc[col]][col].x = self->home[self->unk_4dc[col]][col].x;
        self->quad[self->unk_4dc[col]][col].y = self->home[self->unk_4dc[col]][col].y;
        self->quad[self->unk_4dc[col]][col].z = self->home[self->unk_4dc[col]][col].x + self->pos.x;
        self->quad[self->unk_4dc[col]][col].w = self->home[self->unk_4dc[col]][col].y + self->pos.y;
        self->cursor_alpha[self->unk_4dc[col]][col] = 0;
        self->unk_500[self->unk_4dc[col]][col] = 1;
        self->unk_4dc[col]++;
    }
}

void TAdChrSelPlyPlateGC::clear_slot_entries(s32 arg1) {
    s32 i;
    for (i = 0; i < 4; i++) {
        cursor_alpha[i][arg1] = 0;
        multi_ply_chr_select_tag_alpha[i] = 0.0f;
        unk_500[i][arg1] = 0;
    }
    unk_4dc[arg1] = 0;
}

void TAdChrSelPlyPlateGC::init_slot_position(saddr position, s32 arg2, s32 arg3) {
    copy_vec2(&home[arg2][arg3], (void *)position);
    quad[arg2][arg3].x = home[arg2][arg3].x;
    quad[arg2][arg3].y = home[arg2][arg3].y;
    quad[arg2][arg3].x = home[arg2][arg3].x + pos.x;
    quad[arg2][arg3].y = home[arg2][arg3].y + pos.y;
    cursor_alpha[arg2][arg3] = 0;
}

#pragma push
#pragma fp_contract on
void TAdChrSelPlyPlateGC__select_slot_at_cursor(TAdChrSelPlyPlateGC *self) {
    u32 cell[2];
    f32 top;
    f32 bottom;
    s32 row = self->sel[multi_ply_chr_select_active_player][self->cursor_col] + 1;
    s32 col = self->cursor_col + 1;
    if (multi_ply_chr_select_slot_table[row][col] == -1) {
        play_sound_effect(0x53F06, 0, 0, 0);
        return;
    }
    multi_ply_chr_select_tag_shown[multi_ply_chr_select_active_player] = 1;
    multi_ply_chr_select_slot_table[row][col] = -1;
    multi_ply_chr_select_player_slot[multi_ply_chr_select_active_player] =
        self->sel[multi_ply_chr_select_active_player][self->cursor_col] + self->cursor_col * 4;
    self->quad[multi_ply_chr_select_active_player + 4][0].x = self->quad[self->sel[multi_ply_chr_select_active_player][self->cursor_col]][self->cursor_col].x;
    self->quad[multi_ply_chr_select_active_player + 4][0].z = self->quad[self->sel[multi_ply_chr_select_active_player][self->cursor_col]][self->cursor_col].z;
    self->quad[multi_ply_chr_select_active_player + 4][0].y = self->quad[self->sel[multi_ply_chr_select_active_player][self->cursor_col]][self->cursor_col].y;
    self->quad[multi_ply_chr_select_active_player + 4][0].w = self->quad[self->sel[multi_ply_chr_select_active_player][self->cursor_col]][self->cursor_col].w;
    self->quad[multi_ply_chr_select_active_player + 4][0].u0 = 0.0f;
    top = multi_ply_chr_select_active_player * multi_ply_chr_select_tag_size[1];
    self->quad[multi_ply_chr_select_active_player + 4][0].v0 = top / 256.0f;
    self->quad[multi_ply_chr_select_active_player + 4][0].u1 = multi_ply_chr_select_tag_size[0] / 256.0f;
    bottom = multi_ply_chr_select_active_player * multi_ply_chr_select_tag_size[1] + multi_ply_chr_select_tag_size[1];
    self->quad[multi_ply_chr_select_active_player + 4][0].v1 = bottom / 256.0f;
    self->cursor_alpha[self->sel[multi_ply_chr_select_active_player][self->cursor_col]][self->cursor_col] = 0;
    TAdMultiPlyChrSelectGC::add_selected_slot();
    multi_ply_chr_select_active_player = ((TAdChrSelPlyPlateGC *)self)->find_active_slot();
    self->find_first_open_cell(cell);
    self->cursor_col = cell[1] - 1;
    self->sel[multi_ply_chr_select_active_player][self->cursor_col] = cell[0] - 1;
}
#pragma pop

void TAdChrSelPlyPlateGC__start_selected_slot_anim(TAdChrSelPlyPlateGC *self) {
    NJS_POINT2 pos;
    TAdPlyPltAnimCtrlGC *anim;
    pos.x = self->quad[self->sel[multi_ply_chr_select_active_player][self->cursor_col]][self->cursor_col].x;
    pos.y = self->quad[self->sel[multi_ply_chr_select_active_player][self->cursor_col]][self->cursor_col].y;
    anim = (TAdPlyPltAnimCtrlGC *)TAdMultiPlyChrSelectGC::get_selected_slot();
    if (anim != NULL) {
        anim->init(&pos);
    }
}

void TAdChrSelPlyPlateGC::reset_cursor_state() {
    u32 i;
    s32 j;
    for (i = 0; i < 4; i++) {
        multi_ply_chr_select_tag_shown[i] = 0;
        multi_ply_chr_select_tag_alpha[i] = 0.0f;
        for (j = 0; j < 3; j++) {
            unk_500[i][j] = 0;
            unk_4dc[j] = 0;
        }
    }
    multi_ply_chr_select_active_player = 0;
    unk_530 = 0;
}

u32 get_multiplayer_controller_active_index(int param_1) {
  int iVar3;
  int iVar2;
  int iVar1;
  iVar3 = 0;
  for (iVar2 = 0; iVar2 < param_1 + 1; iVar2 = iVar2 + 1) {
    iVar1 = TAdMultiPlyChrSelectGC__is_controller_connected(iVar2);
    if (iVar1 == 0) {
      iVar3 = iVar3 + 1;
    }
  }
  return param_1 - iVar3 & ~(param_1 - iVar3 >> 0x1f);
}

void TAdChrSelPlyPlateGC::render() {
    if (TMainTask::get_render_pass() != 1) {
        draw_selection_cursors();
        switch ((s32) TAdMultiPlyChrSelectGC__select_mode) {
        case 0:
            TAdChrSelPlyPlateGC__draw_slot_tags(this);
            return;
        case 1:
            TAdChrSelPlyPlateGC__draw_slot_tags_shifted(this);
            break;
        }
    }
}

void TAdChrSelPlyPlateGC::draw_selection_cursors() {
    u32 i;
    u32 j;
    s32 n;
    s32 m;
    if (TAdMultiPlyChrSelectGC__select_mode == 0) {
        n = TAdMultiPlyChrSelectGC::count_ready();
        m = TAdMultiPlyChrSelectGC__count_selected_slots();
        if (m == n) {
            return;
        }
    }
    if (TAdMultiPlyChrSelectGC__select_mode == 1) {
        TAdMultiPlyChrSelectGC::get_state();
        if (TAdMultiPlyChrSelectGC::get_state()->get_field_20() < 0xD) {
            return;
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            if (unk_500[i][j] != 0) {
                cursor[0][0] = 16.0f + quad[i][j].x;
                cursor[0][2] = quad[i][j].z - 16.0f;
                cursor[0][1] = quad[i][j].y;
                cursor[0][3] = quad[i][j].w;
                cursor[1][0] = quad[i][j].x;
                cursor[1][2] = 16.0f + cursor[1][0];
                cursor[1][1] = quad[i][j].y;
                cursor[1][3] = quad[i][j].w;
                cursor[2][0] = quad[i][j].z - 16.0f;
                cursor[2][2] = 16.0f + cursor[2][0];
                cursor[2][1] = quad[i][j].y;
                cursor[2][3] = quad[i][j].w;
                set_color_blending_mode(0, 8);
                set_color_blending_mode(1, 0xA);
                begin_screen_draw(1);
                TObjFish::set_global_param((s32)lbl_805D67D4);
                set_draw_texture_and_color(0, cursor_color[i][j]);
                draw_textured_quad_at_depth(cursor[0], 0.53f);
                draw_textured_quad_at_depth(cursor[1], 0.53f);
                draw_textured_quad_at_depth(cursor[2], 0.53f);
                TWindowSubStatusDisp::get_player();
                set_color_blending_mode(0, 8);
                set_color_blending_mode(1, 6);
            }
        }
    }
}

#pragma push
#pragma fp_contract on
void TAdChrSelPlyPlateGC__draw_slot_tags(TAdChrSelPlyPlateGC *self) {
    u32 i;
    for (i = 0; i < 4; i++) {
        if (multi_ply_chr_select_tag_shown[i] == 1) {
            s32 alpha = (s32)(255.0f * multi_ply_chr_select_tag_alpha[i] + 0.5f);
            begin_screen_draw(1);
            TObjFish::set_global_param(lbl_805D67D0);
            set_draw_texture_and_color(0, (alpha << 24) | 0xFFFFFF);
            draw_textured_quad_at_depth(&self->quad[i + 4][0].x, 0.54f);
            TWindowSubStatusDisp::get_player();
            multi_ply_chr_select_tag_alpha[i] += 0.16666667f;
            multi_ply_chr_select_tag_alpha[i] = multi_ply_chr_select_tag_alpha[i] >= 1.0f ? 1.0f : multi_ply_chr_select_tag_alpha[i];
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TAdChrSelPlyPlateGC__draw_slot_tags_shifted(TAdChrSelPlyPlateGC *self) {
    u32 i;
    CharacterSelectionQuad q;
    for (i = 0; i < 4; i++) {
        if (multi_ply_chr_select_tag_shown[i] == 1) {
            begin_screen_draw(1);
            TObjFish::set_global_param(lbl_805D67D0);
            set_draw_texture_and_color(0, ((s32)(255.0f * multi_ply_chr_select_tag_alpha[i] + 0.5f) << 24) | 0xFFFFFF);
            q.u0 = self->quad[i + 4][0].u0;
            q.u1 = self->quad[i + 4][0].u1;
            q.v0 = self->quad[i + 4][0].v0;
            q.v1 = self->quad[i + 4][0].v1;
            q.x = (-206.0f) + self->quad[i + 4][0].x;
            q.z = (-206.0f) + self->quad[i + 4][0].z;
            q.y = self->quad[i + 4][0].y;
            q.w = self->quad[i + 4][0].w;
            if (q.x > 0.0f) {
                draw_textured_quad_at_depth(&q.x, 0.54f);
            }
            multi_ply_chr_select_tag_alpha[i] += 0.16666667f;
            multi_ply_chr_select_tag_alpha[i] = multi_ply_chr_select_tag_alpha[i] >= 1.0f ? 1.0f : multi_ply_chr_select_tag_alpha[i];
            TWindowSubStatusDisp::get_player();
        }
    }
}
}
#pragma pop
