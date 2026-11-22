#ifndef PSO_UI_FRONTEND_TADCHRSELBSLOTGC_H
#define PSO_UI_FRONTEND_TADCHRSELBSLOTGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

class TAdSubPlyItemGC;
class TAdChrSelMovePlateGC;
class TAdPlyChrSelPlateGC;
class TAdChrSelSlotGC;
class TAdChrSelASlotGC;
class TAdDrawLineCtrl;
class TWindowBase;
struct TWindowMessageYesNo;
struct G_8030E3BC;

struct TAdChrSelBSlotGC : public TObject {
    TAdChrSelBSlotGC(TObject *parent);
    virtual ~TAdChrSelBSlotGC();
    void sub_8030FE04();
    virtual void render();
    virtual void run_task();
    // state, prev_state, state_frames: names inferred from run_task (same layout as TAdChrSelASlotGC)
    s32 state;        // 0x1C
    s32 prev_state;   // 0x20
    s32 state_frames; // 0x24
    void create_children();
    static void render(void *self);
    s32 is_slot_state_one(u32 i);
    G_8030E3BC *sub_8030E3BC(s32 index, s32 slot, void *pos);
    void sub_8030E458();
    void set_load_state();
    void init();
    void reset_load_state();
    void reset_slot_state();
    void sub_8030E550();
    void update_load_state();
    void set_state_confirm();
    void set_state(s32 value);
    s32 get_state();
    s32 is_state_closing();
    void enter_state17();
    void sub_8030E620();
    void sub_8030E624();
    void reset_plate_positions();
    void sub_8030E768();
    void sub_8030E824();
    void sub_8030E8E0();
    void sub_8030E99C();
    void sub_8030EA58();
    void sub_8030EB14();
    void sub_8030EBD0();
    void check_cancel_and_close();
    void update_slot_state();
    void update_card_select();
    void sub_8030EF74();
    void update_card_confirm();
    void sub_8030F13C();
    void sub_8030F228();
    void sub_8030F2E4();
    void sub_8030F3A0();
    void close_windows();
    void reset_windows();
    static void *create(void *arg0);
    int get_global_state();
    static TAdChrSelASlotGC *get_global_slot_data();
    TAdChrSelSlotGC *slot_gc; // 0x28
    TAdPlyChrSelPlateGC *m_2c;
    TAdSubPlyItemGC *player_items;
    TAdChrSelMovePlateGC *m_34;
    TAdDrawLineCtrl *m_38;
    TAdDrawLineCtrl *m_3c;
    TWindowBase *m_40;
    TWindowBase *m_44;
    TWindowBase *m_48;
    TWindowBase *m_4c;
    TWindowBase *m_50;
    TWindowBase *m_54;
    TWindowBase *m_58;
    TWindowBase *m_5c;
    TWindowBase *m_60;
    TWindowBase *m_64;
    TWindowBase *m_68;
    TWindowMessageYesNo *m_6c;
    TWindowMessageYesNo *m_70;
    TWindowBase *m_74;
    TWindowBase *m_78;
    TWindowBase *m_7c;
};

LAYOUT_ASSERT(TAdChrSelBSlotGC_size, sizeof(TAdChrSelBSlotGC) == 0x80);
#endif
