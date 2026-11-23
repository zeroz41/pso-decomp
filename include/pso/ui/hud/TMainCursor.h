#ifndef PSO_UI_HUD_TMAINCURSOR_H
#define PSO_UI_HUD_TMAINCURSOR_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/data/FlagWord.h"
#include "pso/ui/window/ActionPaletteTag.h"
#include "pso/unk/TUnk_804A7254.h"

// TMainCursor +0x24.
class TUnk_8013E800 {
public:
    u16 unk_0;

    TUnk_8013E800();
    ~TUnk_8013E800();
};

// TMainCursor +0x60; TUnk_8013EF6C holds two.
class TUnk_8013E780 {
public:
    ActionPaletteTag unk_0;
    s16 unk_4;
    s16 unk_6;

    TUnk_8013E780();
    ~TUnk_8013E780();
    void reset_target();
};

struct TMainCursor : public TObject {
    TMainCursor(TObject *parent, saddr target_index, s32 target_id, s32 action_palette, s32 active, u16 offset_y, f32 size);
    virtual ~TMainCursor();
    void bind_action_channels();
    void sub_8013E724(f32);
    u32 m_1c;
    FlagWord unk_20;
    TUnk_8013E800 unk_24;
    u8 pad_26[0x2];
    u8 unk_28[0x4];
    f32 m_2c;
    u8 unk_30[0x4];
    s32 m_34;
    u8 unk_38[0x4];
    f32 m_3c;
    void* m_40;
    u8 _pad44[0x8];
    TUnk_804A7254 unk_4c;
    TUnk_8013E780 unk_60;
    void update_position();
    s32 sort_actions_by_priority();
    void reset_state();
    void update_photon_chair();
    virtual void render();
    virtual void run_task();
    void reset_cursor_parts();
    static void quick_sort(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    void reset_slots();
    void init_slots();
    void set_cursor_pos(u16 arg1, s32 arg2);
    static s32 get_action_cursor_priority(void *arg0, saddr player, s32 index);
    static void set_cursor_color(s32 arg0, saddr player, saddr main_cursor);
    static void set_display_flags(s32 arg0, saddr player, saddr main_cursor);
    static void setup_flags(s32 arg0, s32 player, saddr main_cursor);
    static void sort_list(s32 arg0, s32 arg1);
    s32 is_channel_active();
    int check_visible();
    saddr get_state();
    void set_target_index(s16 v);
    void update_cursor_pos();
    void*copy_from(void* a1);
    saddr get_index();
    void reset_slot();
    void set_type(s32 v);
    static int get_cursor_state();
    saddr check_field_24();
    u16 get_id();
    void*get_list();
    void update_target_sub();
    u16 get_render_flag();
    int test_flag_2_at_20();
    int init_render_flags();
    int update();
    int check_flag_1();
    u8 is_position_moved();
    void check_flag_4();
    u8 forward_13E338_at_60();
    u8 update_sub_60();
    void set_offset_y(s16 offset_y);
    void init_field_60(u8 v);
    int get_selected_entry();
    u8 get_active();
    int is_cursor_clear();
    void set_color_mode(s32 v);
    void set_color(s32 v);
    void set_field_0c(s32 v);
    void set_flags(s32 v);
    void set_cursor_id(s16 v);
    void set_field2(s16 v);
    void set_size(f32 v);
    f32 get_pos();
    int get_rader_map();
    static void find_action_slot_for_target(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    void refresh_target_marker();
    void update_chair();
    void validate_target();
    int is_same_target(void *b);
    void set_target_id_at_60(u8 target_id);
    void set_target_id(s16 v);
    int set_target_index_at_60(void* target_index);
    s32 get_body_exclude_mask();
    s32 get_body_include_mask();
    s32 get_actor_exclude_mask();
    s32 get_actor_include_mask();
    static void store_sorted_record(void* p, void* a1, void* a2);
    void init_slot(s32 i);
    void update_pair();
    void update_cursor_pair();
    s32 test_button(s32 arg1, u16 arg2);
    void set_flag_bit(s32 arg1, u16 arg2);
    static s32 find_action_slot(s32 arg0, void *arg1, s16 type, s32 enabled, s32 arg4);
    s32 check_can_pickup();
    void setup_action_channel(u8 *player, s32 slot, s32 kind, s32 id);
    static s32 try_add_target_candidate(void *, void *, void *, void *);
    static void *get_record_at(void *self, int i);
};

LAYOUT_ASSERT(TMainCursor_size, sizeof(TMainCursor) == 0x68);
#endif
