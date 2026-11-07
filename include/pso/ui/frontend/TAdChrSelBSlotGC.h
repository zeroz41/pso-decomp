#ifndef PSO_UI_FRONTEND_TADCHRSELBSLOTGC_H
#define PSO_UI_FRONTEND_TADCHRSELBSLOTGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TAdSubPlyItemGC;

struct TAdChrSelBSlotGC : public TObject {
    TAdChrSelBSlotGC(TObject *parent);
    virtual ~TAdChrSelBSlotGC();
    void sub_8030FE04();
    virtual void render();
    virtual void run_task();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    void create_children();
    static void render(void *self);
    static bool is_slot_state_one(s32 arg0, u32 arg1);
    void set_load_state();
    void init();
    void reset_load_state();
    void reset_slot_state();
    void update_load_state();
    void set_state_confirm();
    void enter_state17();
    void reset_plate_positions();
    void check_cancel_and_close();
    static void *create(void *arg0);
    static int get_global_state();
    static int get_global_slot_data();
    u8 unk_28[0x4];
    s32 m_2c;
    TAdSubPlyItemGC *player_items;
    void * m_34;
    u8 unk_38[0x4];
    s32 m_3c;
    u8 unk_40[0x4];
    s32 m_44;
    u8 unk_48[0x4];
    s32 m_4c;
    u8 unk_50[0x4];
    s32 m_54;
    u8 unk_58[0x4];
    s32 m_5c;
    u8 unk_60[0x4];
    s32 m_64;
    u8 unk_68[0x4];
    s32 m_6c;
    u8 unk_70[0x4];
    s32 m_74;
    u8 unk_78[0x4];
    s32 m_7c;
};

typedef char TAdChrSelBSlotGC_size[sizeof(TAdChrSelBSlotGC) == 0x80 ? 1 : -1];
#endif
