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
    void reset_cursor();
    void set_cursor_index_1();
    void set_cursor_index_2();
    // Requests state value - 1 for run_task to switch to; 0 cancels the request.
    void request_state(s32 value);
    void set_index_and_close_status(s32 index);
    void set_status_value(s32 value);
    virtual void run_task();
    virtual void render();
    void update_chara_making();
    void draw_model_with_arg(NJS_OBJECT *model);
    // Draws a part model tinted with the appearance's colour at the given alpha.
    void draw_model_tinted(NJS_OBJECT *model, CharacterAppearanceFields *appearance, f32 alpha);
    void draw_model_tinted_opaque(NJS_OBJECT *model, CharacterAppearanceFields *appearance);
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
    CharacterAppearanceFields visual_record;  // copy_player_visual_record fills it
    CharacterPreview *preview_data;  // the character being shown, while it loads and after
};
extern TAdChrSelPlayerGC *multi_chr_select_player_slot_table[4];
extern TObjMotionAction chr_sel_player_actions[9];
LAYOUT_ASSERT(CharacterSelectPlayerAppearanceOffset, offsetof(TAdChrSelPlayerGC, visual_record) == 0x120);
LAYOUT_ASSERT(CharacterSelectPlayerPreviewOffset, offsetof(TAdChrSelPlayerGC, preview_data) == 0x170);
LAYOUT_ASSERT(CharacterSelectPlayerSpinOffset, offsetof(TAdChrSelPlayerGC, spin_model) == 0x11C);
LAYOUT_ASSERT(TAdChrSelPlayerGC_size, sizeof(TAdChrSelPlayerGC) == 0x174);
LAYOUT_ASSERT(TAdChrSelPlayerGC_pending_state_offset, offsetof(TAdChrSelPlayerGC, pending_state) == 0x100);
LAYOUT_ASSERT(TAdChrSelPlayerGC_layout_mode_offset, offsetof(TAdChrSelPlayerGC, layout_mode) == 0x104);
LAYOUT_ASSERT(TAdChrSelPlayerGC_status_index_offset, offsetof(TAdChrSelPlayerGC, status_index) == 0x110);

// Load and release hooks of the multi-player character select scene: the BML bundle the
// player previews take their motions from.
void load_multi_ply_chr_select_resources(void);
void free_multi_ply_chr_select_resources(void);
void reset_animation_ticks(TAdChrSelPlayerGC *player);
void enable_spin_model(TAdChrSelPlayerGC *player);
BOOL is_player_model_shown(TAdChrSelPlayerGC *player);
#endif
