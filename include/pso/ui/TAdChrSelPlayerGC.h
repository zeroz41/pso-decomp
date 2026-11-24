#ifndef PSO_UI_TAD_CHR_SEL_PLAYER_GC_H
#define PSO_UI_TAD_CHR_SEL_PLAYER_GC_H
#include <stddef.h>
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/ui/charcreate/CharacterAppearance.h"

class CharacterPreview;

// One player model of the multi-player character select; get_or_create_player
// keeps them in multi_chr_select_player_slot_table.
class TAdChrSelPlayerGC : public TObjMotion {
public:
    TAdChrSelPlayerGC(TObject *parent, s32, s32, s32 slot);
    virtual ~TAdChrSelPlayerGC();
    void place_model_for_mode(s32 index);
    void init_model_animation();
    void set_cursor_index(s32);
    void set_field_100(s32 value);
    void set_index_and_close_status(s32 index);
    void set_status_value(s32 value);
    virtual void run_task();
    virtual void render();
    void update_chara_making();
    void draw_model_with_arg(void *model);
    void init_selection_model(s32);
    s32 state;  // run_task switches on it; render draws in state 3
    s32 pending_state;  // zero for no request, otherwise the state plus one
    s32 layout_mode;
    s32 formation_index;
    s32 slot;  // its index in multi_chr_select_player_slot_table
    s32 status_index;
    u8 pad_114[0x4];
    s32 animation_ticks;
    s32 spin_model;
    CharacterAppearanceFields visual_record;
    CharacterPreview *preview_data;
};
extern TAdChrSelPlayerGC *multi_chr_select_player_slot_table[4];
LAYOUT_ASSERT(CharacterSelectPlayerAppearanceOffset, offsetof(TAdChrSelPlayerGC, visual_record) == 0x120);
LAYOUT_ASSERT(CharacterSelectPlayerPreviewOffset, offsetof(TAdChrSelPlayerGC, preview_data) == 0x170);
LAYOUT_ASSERT(CharacterSelectPlayerSpinOffset, offsetof(TAdChrSelPlayerGC, spin_model) == 0x11C);
LAYOUT_ASSERT(TAdChrSelPlayerGC_size, sizeof(TAdChrSelPlayerGC) == 0x174);
LAYOUT_ASSERT(TAdChrSelPlayerGC_pending_state_offset, offsetof(TAdChrSelPlayerGC, pending_state) == 0x100);
LAYOUT_ASSERT(TAdChrSelPlayerGC_layout_mode_offset, offsetof(TAdChrSelPlayerGC, layout_mode) == 0x104);
LAYOUT_ASSERT(TAdChrSelPlayerGC_status_index_offset, offsetof(TAdChrSelPlayerGC, status_index) == 0x110);

#endif
