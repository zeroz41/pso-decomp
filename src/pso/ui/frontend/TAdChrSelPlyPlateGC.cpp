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

typedef struct S_802C59EC {
    u8 pad0[0x444];
    s32 a[4][3];
    u8 pad474[0x4DC - 0x474];
    s32 f4DC[3];
    u8 pad4E8[0x500 - 0x4E8];
    s32 b[4][3];
} S_802C59EC;

typedef struct G_802C6A10 { s32 value; u8 remaining[0xC]; } G_802C6A10;

struct S_802C5594 {
    u8 pad0[0x4DC];
    s32 x[3];
    u8 pad4E8[0x500 - 0x4E8];
    s32 y[4][3];
    s32 f530;
};

struct E_802C5944 { f32 x; f32 y; u8 pad[0x18]; };

struct V_802C5944 { f32 x; f32 y; };

struct S_802C5944 {
    u8 pad0[0x24];
    E_802C5944 e[4][3];
    u8 pad1a4[0x384 - 0x1A4];
    V_802C5944 v[4][3];
    u8 pad3e4[0x444 - 0x3E4];
    s32 a[4][3];
    u8 pad474[0x4A4 - 0x474];
    f32 ox;
    f32 oy;
};

struct E_802C5314 { f32 x; f32 y; f32 z; f32 w; u8 pad[0x10]; };

struct S_802C5314 {
    u8 pad0[0x24];
    E_802C5314 e[4][3];
    u8 pad1a4[0x324 - 0x1A4];
    f32 r324[8];
    f32 r344[8];
    f32 r364[8];
    u8 pad384[0x474 - 0x384];
    s32 sel[4][3];
    u8 pad4a4[0x500 - 0x4A4];
    s32 y[4][3];
};

typedef struct Jump_802C5C84 {
    s32 v[4];
} Jump_802C5C84;

struct Pad_802C6AC8 { u8 pad[0x20]; u8 ctl[0x30]; };

/* Selection-screen view: per player row/column quads (x0,y0,x1,y1,u0,v0,u1,v1), the three
   cursor quads, home positions, and per-player column state. */
struct Quad_802C50EC { f32 x, y, z, w, u0, v0, u1, v1; };
struct V2_802C50EC { f32 x, y; };
struct S_802C50EC {
    u8 pad0[0x24];
    Quad_802C50EC quad[8][3];
    f32 cursor[3][8];
    V2_802C50EC home[4][3];
    u8 pad3e4[0x444 - 0x3E4];
    s32 a[4][3];
    u8 pad474[0x4A4 - 0x474];
    f32 ox;
    f32 oy;
    s32 sel[4][3];
    s32 f4DC[4];
    s32 cursor_col;
    u8 pad4f0[0x500 - 0x4F0];
    s32 b[4][3];
};

extern "C" {
    extern int multi_ply_chr_select_active_player;
extern s32 TAdMultiPlyChrSelectGC__select_mode;
extern s32 TAdMultiPlyChrSelectGC__selected_slot;
extern s32 multi_ply_chr_select_slot_table[][5];
void copy_vec2__28TWindowSubSymbolChatPartsSetFPv(void *);
s32 get_field_20__22TAdMultiPlyChrSelectGCFv();
extern s32 lbl_805D67D4;
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 play_sound_effect(int, void *, int, int);
s32 TAdMultiPlyChrSelectGC__sub_802C5F1C(void *);
extern u8 controller_physical_port_bank[];
extern s32 lbl_805D67D0;

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

TAdChrSelPlyPlateGC *fn_802C6F20(TObject *parent, vec2f *pos) {
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
    ((TWindowSubSymbolChatPartsSet *)&this->pos)->copy_vec2(pos);
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
    TAdMultiPlyChrSelectGC__sub_802C5F1C(this);
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
    TAdPlyPltAnimCtrlGC::get_instance((s32)tl_clipout);
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
    if (TAdMultiPlyChrSelectGC__sub_802C6848(TAdMultiPlyChrSelectGC::get_clamped_cursor()) == 0 && unk_20 < TAdMultiPlyChrSelectGC::count_ready()) {
        multi_ply_chr_select_active_player = find_active_slot();
        switch (TAdMultiPlyChrSelectGC__select_mode) {
        case 1:
            break;
        case 0: {
            u32 buf[2];
            TAdMultiPlyChrSelectGC::find_first_open_cell((s32)this, buf);
            cursor_col = buf[1] - 1;
            sel[multi_ply_chr_select_active_player][cursor_col] = buf[0] - 1;
            break;
        }
        }
    }
    if (TAdMultiPlyChrSelectGC__sub_802C6848(0) == 0 || TAdMultiPlyChrSelectGC::count_ready() < 2) {
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
                if (TAdMultiPlyChrSelectGC__sub_802C6558() < n) {
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
            if (TWindowShortListCtrl__check_controller_button(((Pad_802C6AC8 *)controller_physical_port_bank)[i].ctl, 8) != 0 && TAdMultiPlyChrSelectGC__sub_802C6558() > 0) {
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
    if ((TAdMultiPlyChrSelectGC__sub_802C6848(var_r31) != 0) && (is_multiplayer_character_slot_selected(var_r31) == 0)) {
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

int TAdMultiPlyChrSelectGC__sub_802C6920(void) {
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

s32 TAdMultiPlyChrSelectGC__sub_802C6848(s32 arg0) {
    if ((arg0 < 0) || (arg0 > 3)) {
        return 0;
    }
    return *(s32 *)((s8 *)(*(s32 **)((s8 *)(TKeyBoardControl__sub_803DEB74(multiplayer_controller_device_codes[arg0])) + 0x30)) + 0) & 1;
}

#pragma push
#pragma fp_contract on
void TAdMultiPlyChrSelectGC__sub_802C6660(S_802C50EC *self) {
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
    TAdMultiPlyChrSelectGC::find_first_open_cell((s32)self, cell);
    self->cursor_col = cell[1] - 1;
    self->sel[multi_ply_chr_select_active_player][self->cursor_col] = cell[0] - 1;
}
#pragma pop

void TAdMultiPlyChrSelectGC__sub_802C65C0(s32 arg0) {
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

s32 TAdMultiPlyChrSelectGC__sub_802C658C(s32 arg0) {
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

s32 TAdMultiPlyChrSelectGC__sub_802C6558(void) {
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
        if (TAdMultiPlyChrSelectGC__sub_802C6848(var_r30) != 0) {
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
        if (TAdMultiPlyChrSelectGC__sub_802C6558() > 0) {
            return ((s32)TAdMultiPlyChrSelectGC__sub_802C6920());
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

void TAdMultiPlyChrSelectGC::init() { multi_ply_chr_select_active_player = TAdMultiPlyChrSelectGC__sub_802C6920(); TAdMultiPlyChrSelectGC__sub_802C6920(); ((int (*)(void))TAdMultiPlyChrSelectGC__sub_802C65C0)(); }

void TAdChrSelPlyPlateGC::handle_dpad_input() {
    s32 n;
    s32 m;
    unk_1c++;
    TAdMultiPlyChrSelectGC__sub_802C5F1C(this);
    n = TAdMultiPlyChrSelectGC::count_ready();
    m = TAdMultiPlyChrSelectGC__sub_802C6558();
    if (m != n && unk_4dc[cursor_col] != 0 && unk_4f8 == 0) {
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((s32)WIN_802C61E4, 0x10, 6, 1) != 0) {
            move_cursor(cursor_col, sel[multi_ply_chr_select_active_player][cursor_col], 0, -1, unk_4dc[cursor_col]);
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((s32)WIN_802C61E4, 0x20, 6, 1) != 0) {
            move_cursor(cursor_col, sel[multi_ply_chr_select_active_player][cursor_col], 0, 1, unk_4dc[cursor_col]);
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((s32)WIN_802C61E4, 0x80, 6, 1) != 0) {
            move_cursor(cursor_col, sel[multi_ply_chr_select_active_player][cursor_col], 1, 0, 2);
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((s32)WIN_802C61E4, 0x40, 6, 1) != 0) {
            move_cursor(cursor_col, sel[multi_ply_chr_select_active_player][cursor_col], -1, 0, 2);
        }
    }
    if (TWindowShortListCtrl__check_controller_button(WIN_802C61E4, 4) != 0 && unk_4f8 == 0) {
        unk_4f8 = 1;
    }
}

void TAdChrSelPlyPlateGC::update_option_cursor() {
    unk_1c++;
    TAdMultiPlyChrSelectGC__sub_802C5F1C(this);
    if (unk_4dc[cursor_col] != 0 && unk_4f8 == 0) {
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((s32)WIN_802C6008, 0x10, 6, 1) != 0) {
            play_sound_effect(0x54100, 0, 0, 0);
            sel[multi_ply_chr_select_active_player][cursor_col]--;
        }
        if (TAdMultiPlyChrSelectGC::dispatch_draw_command((s32)WIN_802C6008, 0x20, 6, 1) != 0) {
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

s32 TAdMultiPlyChrSelectGC__sub_802C5F1C(void *arg0) {
    S_802C50EC *self = (S_802C50EC *)arg0;
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
            /* All quad stores route through the re-cast arg0, and the identity
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

void TAdMultiPlyChrSelectGC::find_first_open_cell(s32 arg0, u32 *arg1) {
    u32 p;
    s32 q;
    for (p = 1; p < 3; p++) {
        for (q = 1; q < 5; q++) {
            if (multi_ply_chr_select_slot_table[q][p] == 1) {
                arg1[0] = q;
                arg1[1] = p;
                return;
            }
        }
    }
}

void TAdMultiPlyChrSelectGC::split_slot_index(s32 arg0, s32 *arg1, s32 *arg2) {
    s32 var_r3;
    var_r3 = TAdMultiPlyChrSelectGC__sub_802C658C(arg0);
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

/* src is passed through untouched to copy_vec2 as its second argument. */
void TAdMultiPlyChrSelectGC__sub_802C5A44(S_802C50EC *self, const void *src, s32 col) {
    if ((u32)self->f4DC[col] < 4) {
        copy_vec2__28TWindowSubSymbolChatPartsSetFPv(&self->home[self->f4DC[col]][col]);
        self->quad[self->f4DC[col]][col].x = self->home[self->f4DC[col]][col].x;
        self->quad[self->f4DC[col]][col].y = self->home[self->f4DC[col]][col].y;
        self->quad[self->f4DC[col]][col].z = self->home[self->f4DC[col]][col].x + self->ox;
        self->quad[self->f4DC[col]][col].w = self->home[self->f4DC[col]][col].y + self->oy;
        self->a[self->f4DC[col]][col] = 0;
        self->b[self->f4DC[col]][col] = 1;
        self->f4DC[col]++;
    }
}

void TAdMultiPlyChrSelectGC::clear_slot_entries(s32 arg1) {
    S_802C59EC *arg0 = (S_802C59EC *)this;
    s32 i;
    for (i = 0; i < 4; i++) {
        arg0->a[i][arg1] = 0;
        multi_ply_chr_select_tag_alpha[i] = 0.0f;
        arg0->b[i][arg1] = 0;
    }
    arg0->f4DC[arg1] = 0;
}

void TAdMultiPlyChrSelectGC::init_slot_position(s32 arg1, s32 arg2, s32 arg3) {
    S_802C5944 *arg0 = (S_802C5944 *)this;
    copy_vec2__28TWindowSubSymbolChatPartsSetFPv(&arg0->v[arg2][arg3]);
    arg0->e[arg2][arg3].x = arg0->v[arg2][arg3].x;
    arg0->e[arg2][arg3].y = arg0->v[arg2][arg3].y;
    arg0->e[arg2][arg3].x = arg0->v[arg2][arg3].x + arg0->ox;
    arg0->e[arg2][arg3].y = arg0->v[arg2][arg3].y + arg0->oy;
    arg0->a[arg2][arg3] = 0;
}

#pragma push
#pragma fp_contract on
void TAdMultiPlyChrSelectGC__sub_802C5688(S_802C50EC *self) {
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
    self->a[self->sel[multi_ply_chr_select_active_player][self->cursor_col]][self->cursor_col] = 0;
    TAdMultiPlyChrSelectGC::add_selected_slot();
    multi_ply_chr_select_active_player = ((TAdChrSelPlyPlateGC *)self)->find_active_slot();
    TAdMultiPlyChrSelectGC::find_first_open_cell((s32)self, cell);
    self->cursor_col = cell[1] - 1;
    self->sel[multi_ply_chr_select_active_player][self->cursor_col] = cell[0] - 1;
}
#pragma pop

void TAdMultiPlyChrSelectGC__sub_802C561C(S_802C50EC *self) {
    V2_802C50EC pos;
    TAdPlyPltAnimCtrlGC *anim;
    pos.x = self->quad[self->sel[multi_ply_chr_select_active_player][self->cursor_col]][self->cursor_col].x;
    pos.y = self->quad[self->sel[multi_ply_chr_select_active_player][self->cursor_col]][self->cursor_col].y;
    anim = (TAdPlyPltAnimCtrlGC *)TAdMultiPlyChrSelectGC::get_selected_slot();
    if (anim != NULL) {
        anim->init(&pos);
    }
}

void TAdMultiPlyChrSelectGC::reset_cursor_state() {
    S_802C5594 *arg0 = (S_802C5594 *)this;
    u32 i;
    s32 j;
    for (i = 0; i < 4; i++) {
        multi_ply_chr_select_tag_shown[i] = 0;
        multi_ply_chr_select_tag_alpha[i] = 0.0f;
        for (j = 0; j < 3; j++) {
            arg0->y[i][j] = 0;
            arg0->x[j] = 0;
        }
    }
    multi_ply_chr_select_active_player = 0;
    arg0->f530 = 0;
}

u32 get_multiplayer_controller_active_index(int param_1) {
  int iVar3;
  int iVar2;
  int iVar1;
  iVar3 = 0;
  for (iVar2 = 0; iVar2 < param_1 + 1; iVar2 = iVar2 + 1) {
    iVar1 = TAdMultiPlyChrSelectGC__sub_802C6848(iVar2);
    if (iVar1 == 0) {
      iVar3 = iVar3 + 1;
    }
  }
  return param_1 - iVar3 & ~(param_1 - iVar3 >> 0x1f);
}

void TAdChrSelPlyPlateGC::render() {
    s32 arg0 = (s32)this;
    if (TMainTask::get_render_pass() != 1) {
        draw_selection_cursors();
        switch ((s32) TAdMultiPlyChrSelectGC__select_mode) {
        case 0:
            TAdMultiPlyChrSelectGC__sub_802C522C(arg0);
            return;
        case 1:
            TAdMultiPlyChrSelectGC__sub_802C50EC(arg0);
            break;
        }
    }
}

void TAdChrSelPlyPlateGC::draw_selection_cursors() {
    S_802C5314 *self = (S_802C5314 *)this;
    u32 i;
    u32 j;
    s32 n;
    s32 m;
    if (TAdMultiPlyChrSelectGC__select_mode == 0) {
        n = TAdMultiPlyChrSelectGC::count_ready();
        m = TAdMultiPlyChrSelectGC__sub_802C6558();
        if (m == n) {
            return;
        }
    }
    if (TAdMultiPlyChrSelectGC__select_mode == 1) {
        TAdMultiPlyChrSelectGC::get_state();
        TAdMultiPlyChrSelectGC::get_state();
        if (get_field_20__22TAdMultiPlyChrSelectGCFv() < 0xD) {
            return;
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            if (self->y[i][j] != 0) {
                self->r324[0] = 16.0f + self->e[i][j].x;
                self->r324[2] = self->e[i][j].z - 16.0f;
                self->r324[1] = self->e[i][j].y;
                self->r324[3] = self->e[i][j].w;
                self->r344[0] = self->e[i][j].x;
                self->r344[2] = 16.0f + self->r344[0];
                self->r344[1] = self->e[i][j].y;
                self->r344[3] = self->e[i][j].w;
                self->r364[0] = self->e[i][j].z - 16.0f;
                self->r364[2] = 16.0f + self->r364[0];
                self->r364[1] = self->e[i][j].y;
                self->r364[3] = self->e[i][j].w;
                set_color_blending_mode(0, 8);
                set_color_blending_mode(1, 0xA);
                begin_screen_draw(1);
                TObjFish::set_global_param(lbl_805D67D4);
                set_draw_texture_and_color(0, self->sel[i][j]);
                draw_textured_quad_at_depth(self->r324, 0.53f);
                draw_textured_quad_at_depth(self->r344, 0.53f);
                draw_textured_quad_at_depth(self->r364, 0.53f);
                TWindowSubStatusDisp::get_player();
                set_color_blending_mode(0, 8);
                set_color_blending_mode(1, 6);
            }
        }
    }
}

#pragma push
#pragma fp_contract on
void TAdMultiPlyChrSelectGC__sub_802C522C(s32 arg0) {
    S_802C50EC *self = (S_802C50EC *)arg0;
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
void TAdMultiPlyChrSelectGC__sub_802C50EC(s32 arg0) {
    S_802C50EC *self = (S_802C50EC *)arg0;
    u32 i;
    Quad_802C50EC q;
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
#pragma pop

}
