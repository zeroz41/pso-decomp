#ifndef PSO_UI_FRONTEND_TADCHRSELPLYPLATEGC_H
#define PSO_UI_FRONTEND_TADCHRSELPLYPLATEGC_H

#include "types.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/math/TMath.h"
#include "pso/system/NinjaTypes.h"

// A selection cell or cursor quad carries screen bounds and texture coordinates.
struct CharacterSelectionQuad {
    f32 x, y, z, w;
    f32 u0, v0, u1, v1;
};

// Multiplayer character-select player plates. The class name is the string its constructor
// stores in m_name; the vtable it installs (0x804E0B10) holds the dtor, run_task (0x802C6AC8)
// and render (0x802C54C4).
struct TAdChrSelPlyPlateGC : public TObject {
    static const char *name;
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
    void set_selection(s32 value);
    s32 get_cursor();
    void set_state_ready();
    void set_cursor_column(s32 column);
    void restore_selection();
    void capture_card_index();
    s32 is_confirm_pressed();
    s32 get_active_card_slot();
    void set_active_card_slot(s32 slot);
    void set_cursor_fields(s32 field_4f4, s32 field_4f0);
    void init_slot_position(const NJS_POINT2 *position, s32 row, s32 column);
    void clear_slot_entries(s32 column);
    int get_instance();
    void set_select_mode(int mode);
    static TAdChrSelPlyPlateGC *create_singleton(TObject *parent, vec2f *pos);
    void draw_slot_tags_shifted();
    void draw_slot_tags();
    void show_selected_slot_tags();
    void add_slot_position(const NJS_POINT2 *src, s32 col);
    void select_slot_at_cursor();
    void start_selected_slot_anim();
    void update_cell_uvs();

    s32 input_frames;
    s32 prev_ready_count;
    CharacterSelectionQuad quad[8][3]; // Four selection rows, then four confirmation rows.
    f32 cursor[3][8];
    vec2f home[4][3];
    u8 pad_3e4[0x444 - 0x3e4];
    s32 cursor_alpha[4][3];
    s32 cursor_color[4][3];
    vec2f pos;
    s32 sel[4][3];
    s32 slot_count[3];
    s32 captured_card_index;
    s32 cursor_col;
    s32 unk_4f0;
    s32 unk_4f4;
    s32 selection;
    s32 ready;
    s32 slot_active[4][3];
    s32 start_requested;
    s32 input_enabled;
};

LAYOUT_ASSERT(CharacterSelectionQuadSize, sizeof(CharacterSelectionQuad) == 0x20);
LAYOUT_ASSERT(CharacterSelectionQuadsOffset, offsetof(TAdChrSelPlyPlateGC, quad) == 0x24);
LAYOUT_ASSERT(CharacterSelectionCursorOffset, offsetof(TAdChrSelPlyPlateGC, cursor) == 0x324);
LAYOUT_ASSERT(CharacterSelectionHomeOffset, offsetof(TAdChrSelPlyPlateGC, home) == 0x384);
LAYOUT_ASSERT(CharacterSelectionAlphaOffset, offsetof(TAdChrSelPlyPlateGC, cursor_alpha) == 0x444);
LAYOUT_ASSERT(CharacterSelectionPositionOffset, offsetof(TAdChrSelPlyPlateGC, pos) == 0x4A4);
LAYOUT_ASSERT(CharacterSelectionPositionSize, sizeof(vec2f) == 8);
LAYOUT_ASSERT(TAdChrSelPlyPlateGC_size, sizeof(TAdChrSelPlyPlateGC) == 0x538);

extern TAdChrSelPlyPlateGC *ad_chr_sel_ply_plate_instance;

extern "C" {
u32 get_multiplayer_controller_active_index(int index);
}
s32 is_multiplayer_character_slot_selected(s32 slot);

#endif
