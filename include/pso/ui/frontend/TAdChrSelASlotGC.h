#ifndef PSO_UI_FRONTEND_TADCHRSELASLOTGC_H
#define PSO_UI_FRONTEND_TADCHRSELASLOTGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TAdSubPlyItemGC;

struct TAdChrSelASlotGC : public TObject {
    TAdChrSelASlotGC(TObject *arg1, void *arg2);
    virtual ~TAdChrSelASlotGC();
    virtual void render();
    virtual void run_task();
    u32 state_frames;
    u8 _pad20[0x4];
    u32 state;
    u32 prev_state;
    u8 _pad2C[0x4];
    u32 m_30;
    void check_room_seq_4(s32 arg1);
    void set_flag_40();
    static void render(void *self);
    s32 get_plate_value_for_slot(s32 k);
    s32 open_confirm_message(s32 arg1, s32 arg2);
    s32 create_message_window(s32 arg1, s32 arg2);
    static s32 create_format_message_window(s32 arg0, s32 arg1, s32 arg2);
    static s32 open_yes_no_window(s32 arg0, s32 arg1, s32 arg2);
    void sub_8030CBD0();
    void sub_8030CBD4();
    void update_load_state();
    void set_state();
    void check_load_state();
    void init_selection();
    void sub_8030CCE0();
    void sub_8030CCE4();
    void sub_8030CEEC();
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
    void sub_8030D5DC();
    void close_windows();
    void create_children(s32 arg1);
    void init(s32 arg1);
    s32 get_slot_index();
    void forward_slot_selection(void* a1, void* a2);
    u8 unk_34[0x4];
    s32 m_38;
    TAdSubPlyItemGC *player_items;
    s32 m_40;
    u8 unk_44[0x4];
    u32 m_48;
    u8 unk_4C[0x4];
    u32 m_50;
    u8 unk_54[0x4];
    u32 m_58;
    u8 unk_5C[0x4];
    u32 m_60;
    u8 unk_64[0x4];
    u32 m_68;
    u8 unk_6C[0x4];
    u32 m_70;
    u8 unk_74[0x4];
    u32 m_78;
    u8 unk_7C[0x4];
};

typedef char TAdChrSelASlotGC_size[sizeof(TAdChrSelASlotGC) == 0x80 ? 1 : -1];
#endif
