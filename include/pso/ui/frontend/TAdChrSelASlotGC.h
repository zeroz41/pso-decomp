#ifndef PSO_UI_FRONTEND_TADCHRSELASLOTGC_H
#define PSO_UI_FRONTEND_TADCHRSELASLOTGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TAdSubPlyItemGC;
class TAdChrSelMovePlateGC;
class TAdPlyChrSelPlateGC;

struct TAdChrSelASlotGC : public TObject {
    TAdChrSelASlotGC(TObject *parent, s32 mode);
    virtual ~TAdChrSelASlotGC();
    virtual void render();
    virtual void run_task();
    u32 state_frames;
    s32 mode;
    u32 state;
    u32 prev_state;
    u8 _pad2C[0x4];
    uaddr m_30;
    void set_flag_40();
    static void render(void *self);
    s32 get_plate_value_for_slot(s32 k);
    s32 open_confirm_message(s32 arg1, s32 arg2);
    s32 create_message_window(s32 arg1, s32 arg2);
    static s32 create_format_message_window(saddr arg0, s32 arg1, s32 arg2);
    static s32 open_yes_no_window(saddr arg0, s32 arg1, s32 arg2);
    void sub_8030CBD0();
    void sub_8030CBD4();
    void update_load_state();
    void set_state();
    void check_load_state();
    void init_selection();
    void sub_8030CCE0();
    void populate_slot_entries();
    void push_plate_positions();
    void update_window_78();
    void update_window_7c();
    void update_window_74();
    void update_window_70();
    void update_window_6c();
    void update_slot5();
    void update_slot4();
    void update_slot3();
    void update_slot2();
    void update_slot1();
    void reset_windows();
    void close_windows();
    void create_children(s32 arg1);
    void init(s32 arg1);
    s32 get_slot_index();
    void forward_slot_selection(void* a1, void* a2);
    TAdPlyChrSelPlateGC *m_34;
    TAdPlyChrSelPlateGC *m_38;
    TAdSubPlyItemGC *player_items;
    saddr m_40;
    TAdChrSelMovePlateGC *m_44;
    u32 m_48;
    u8 unk_4C[0x4];
    u32 m_50;
    u8 unk_54[0x4];
    uaddr m_58;
    u8 unk_5C[0x4];
    uaddr m_60;
    u8 unk_64[0x4];
    uaddr m_68;
    u8 unk_6C[0x4];
    uaddr m_70;
    u8 unk_74[0x4];
    uaddr m_78;
    u8 unk_7C[0x4];
};

LAYOUT_ASSERT(TAdChrSelASlotGC_size, sizeof(TAdChrSelASlotGC) == 0x80);
#endif
