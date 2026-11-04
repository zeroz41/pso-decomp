#ifndef PSO_UI_TADCHRSELPLYPLATEGC_H
#define PSO_UI_TADCHRSELPLYPLATEGC_H

#include "types.h"
#include "pso/TObject.h"
#include "pso/TMath.h"

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

    s32 unk_1c;
    s32 unk_20;
    u8 pad_24[0x444 - 0x24];
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

typedef char TAdChrSelPlyPlateGC_size[sizeof(TAdChrSelPlyPlateGC) == 0x538 ? 1 : -1];

extern TAdChrSelPlyPlateGC *ad_chr_sel_ply_plate_instance;

extern "C" {
TAdChrSelPlyPlateGC *fn_802C6F20(TObject *parent, vec2f *pos);
void TAdMultiPlyChrSelectGC__sub_802C50EC(s32 arg0);
void TAdMultiPlyChrSelectGC__sub_802C522C(s32 arg0);
s32 TAdMultiPlyChrSelectGC__sub_802C6558(void);
s32 TAdMultiPlyChrSelectGC__sub_802C658C(s32 arg0);
void TAdMultiPlyChrSelectGC__sub_802C65C0(s32 arg0);
s32 TAdMultiPlyChrSelectGC__sub_802C6848(s32 arg0);
int TAdMultiPlyChrSelectGC__sub_802C6920(void);
u32 get_multiplayer_controller_active_index(int param_1);
s32 is_multiplayer_character_slot_selected(s32 arg0);
}

#endif
