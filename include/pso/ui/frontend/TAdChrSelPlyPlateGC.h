#ifndef PSO_UI_FRONTEND_TADCHRSELPLYPLATEGC_H
#define PSO_UI_FRONTEND_TADCHRSELPLYPLATEGC_H

#include "types.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/math/TMath.h"

// A selection cell or cursor quad carries screen bounds and texture coordinates.
struct CharacterSelectionQuad {
    f32 x, y, z, w;
    f32 u0, v0, u1, v1;
};

// Multiplayer character-select player plates. The class name is the string its constructor
// stores in m_name; the vtable it installs (0x804E0B10) holds the dtor, run_task (0x802C6AC8)
// and render (0x802C54C4).
struct TAdChrSelPlyPlateGC : public TObject {
    TAdChrSelPlyPlateGC(TObject *parent, vec2f *pos);
    virtual ~TAdChrSelPlyPlateGC();
    virtual void run_task();
    virtual void render();
    void draw_selection_cursors();
    void move_cursor(s32 x_, s32 y_, s32 dx, s32 dy, s32 depth);
    void update_option_cursor();
    void handle_dpad_input();
    s32 find_active_slot();
    void find_first_open_cell(u32 *cell);
    void reset_cursor_state();
    s32 get_selection();
    s32 get_card_index(s32);
    void set_selection(s32 selection);
    s32 get_cursor();
    void set_state_ready();
    void set_cursor_column(s32 column);
    void restore_selection();
    void capture_card_index();
    s32 get_field_0x530();
    s32 get_active_card_slot();
    void set_active_card_slot(s32 slot);
    void set_cursor_fields(s32 field_4f4, s32 field_4f0);
    void init_slot_position(s32 position, s32 row, s32 column);
    void clear_slot_entries(s32 column);

    s32 unk_1c;
    s32 unk_20;
    CharacterSelectionQuad quad[8][3]; // Four selection rows, then four confirmation rows.
    f32 cursor[3][8];
    vec2f home[4][3];
    u8 pad_3e4[0x444 - 0x3e4];
    s32 cursor_alpha[4][3];
    s32 cursor_color[4][3];
    vec2f pos;
    s32 sel[4][3];
    s32 unk_4dc[3];
    s32 unk_4e8;
    s32 cursor_col;
    s32 unk_4f0;
    s32 unk_4f4;
    s32 unk_4f8;
    s32 unk_4fc;
    s32 unk_500[4][3];
    s32 unk_530;
    s32 unk_534;
};

typedef char CharacterSelectionQuadSize[sizeof(CharacterSelectionQuad) == 0x20 ? 1 : -1];
typedef char CharacterSelectionQuadsOffset[offsetof(TAdChrSelPlyPlateGC, quad) == 0x24 ? 1 : -1];
typedef char CharacterSelectionCursorOffset[offsetof(TAdChrSelPlyPlateGC, cursor) == 0x324 ? 1 : -1];
typedef char CharacterSelectionHomeOffset[offsetof(TAdChrSelPlyPlateGC, home) == 0x384 ? 1 : -1];
typedef char CharacterSelectionAlphaOffset[offsetof(TAdChrSelPlyPlateGC, cursor_alpha) == 0x444 ? 1 : -1];
typedef char TAdChrSelPlyPlateGC_size[sizeof(TAdChrSelPlyPlateGC) == 0x538 ? 1 : -1];

extern TAdChrSelPlyPlateGC *ad_chr_sel_ply_plate_instance;

extern "C" {
TAdChrSelPlyPlateGC *fn_802C6F20(TObject *parent, vec2f *pos);
void TAdMultiPlyChrSelectGC__sub_802C50EC(TAdChrSelPlyPlateGC *plate);
void TAdMultiPlyChrSelectGC__sub_802C522C(TAdChrSelPlyPlateGC *plate);
s32 TAdMultiPlyChrSelectGC__sub_802C6558(void);
s32 TAdMultiPlyChrSelectGC__sub_802C658C(s32 arg0);
void TAdMultiPlyChrSelectGC__sub_802C65C0(s32 arg0);
s32 TAdMultiPlyChrSelectGC__sub_802C6848(s32 arg0);
int TAdMultiPlyChrSelectGC__sub_802C6920(void);
u32 get_multiplayer_controller_active_index(int param_1);
}
s32 is_multiplayer_character_slot_selected(s32 arg0);

#endif
