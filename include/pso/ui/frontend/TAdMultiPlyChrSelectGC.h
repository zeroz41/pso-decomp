#ifndef PSO_UI_FRONTEND_TADMULTIPLYCHRSELECTGC_H
#define PSO_UI_FRONTEND_TADMULTIPLYCHRSELECTGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdChrSelASlotGC;
class TAdGuideTxtGC;
struct TAdChrSelPlyPlateGC;

class TUnk_804E3008;

struct TAdMultiPlyChrSelectGC : public TObject {
    TAdMultiPlyChrSelectGC(TObject *, s32);
    virtual ~TAdMultiPlyChrSelectGC();
    static TUnk_804E3008 *get_or_create_player(TObject *parent, s32 mode, s32 index, s32 slot);
    void create_widgets();
    void sub_802DC118(s32);
    virtual void render();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    u8 unk_28[0x4];
    f32 m_2c;
    u8 unk_30[0x4];
    s32 m_34;
    u8 unk_38[0x4];
    u32 m_3c;
    u32 m_40;
    u8 _pad44[0x4];
    u32 m_48;
    u32 m_4c;
    u8 unk_50[0x4];
    s32 m_54;
    u8 unk_58[0x4];
    TAdChrSelPlyPlateGC *player_plate;
    u8 unk_60[0x4];
    TAdGuideTxtGC *guide;
    void set_index_and_close_status(s32 arg1);
    void set_status_value(s32 arg1);
    void handle_event(s32 arg1);
    void initialize_selection_state(s32 arg1);
    static int get_instance();
    static TAdChrSelPlyPlateGC *get_card_instance();
    static void set_select_mode(int a0, int a1);
    static void reset_slot_selection_table();
    static void split_slot_index(s32 arg0, s32 *arg1, s32 *arg2);
    static void init();
    static s32 get_status();
    static s32 is_selection_confirmed();
    static s32 count_ready();
    static void remove_selected_slot(s32 arg0);
    static void add_selected_slot();
    static s32 get_clamped_cursor();
    static void reset_slot_selections();
    s32 get_field_20();
    static TAdMultiPlyChrSelectGC *get_state();
    static TAdMultiPlyChrSelectGC *get_or_create(TObject *parent, s32 mode);
    static saddr get_selected_slot();
    static int get_global_6700();
    s32 get_player_index();
    void set_cursor_index(s32 v);
    void set_field_100(s32 v);
    static void render(void *self);
    static s32 create_confirm_window();
    s32 create_choice_menu();
    void collect_player_slots();
    s32 get_state_result();
    static u8 *format_player_number_text(s32 arg0, s32 arg1);
    void request_scene_change();
    void check_cancel_input();
    void handle_input();
    void update_input_state();
    void close_and_reset();
    void update_idle_timer();
    void update_confirm_start();
    void handle_cancel_state();
    void update_state_move();
    void handle_confirm_state();
    void update_state();
    void update_card_select_state();
    void update_state_wait_card();
    void update_select();
    void reset_to_select();
    void update_button_input();
    virtual void run_task();
    void set_field_1c(s32 v);
    s32 get_mode();
    s32 is_state_closing();
    static saddr get_global_state();
    static int get_select_flag();
    static int get_chr_select_state();
    s32 get_ready_state();
    static u32 get_move_effect(saddr arg0);
    static TAdChrSelASlotGC *get_or_create_slot_window(TObject *parent, s32 mode);
    u8 unk_68[0x4];
    saddr m_6c;
    u8 unk_70[0x4];
    u32 m_74;
    u8 unk_78[0x4];
    s32 m_7c;
    u8 unk_80[0x4];
    u32 m_84;
    u8 unk_88[0x4];
    saddr m_8c;
    u8 unk_90[0x4];
    uaddr m_94;
    u8 unk_98[0x4];
    s32 m_9c;
    static s32 dispatch_draw_command(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
    void open_windows();
    void init_windows();
    void open_char_select();
    void close_windows();
    void update_card_select();
    void update_state_option();
    void update_card_confirm();
};

extern "C" TAdMultiPlyChrSelectGC *TAdMultiPlyChrSelectGC__instance;

LAYOUT_ASSERT(TAdMultiPlyChrSelectGC_size, sizeof(TAdMultiPlyChrSelectGC) == 0xA0);

// TAdMultiPlyChrSelectGC__character_slot_positions: layout known from its uses only.
struct TAdMultiPlyChrSelectGCCharacterSlotPositions { s32 value; u8 remaining[0x1C]; };
extern TAdMultiPlyChrSelectGCCharacterSlotPositions TAdMultiPlyChrSelectGC__character_slot_positions;

#endif
