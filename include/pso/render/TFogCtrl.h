#ifndef PSO_RENDER_TFOGCTRL_H
#define PSO_RENDER_TFOGCTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TFogCtrl : public TObject {
    TFogCtrl(TObject *parent, s32 index);
    virtual ~TFogCtrl();
    virtual void run_task();
    u32 m_1c;
    u32 m_20;
    u8 _pad24[0x15C];
    u32 m_180;
    u32 m_184;
    u8 _pad188[0x14];
    u32 m_19c;
    u32 m_1a0;
    u32 m_1a4;
    u32 m_1a8;
    u32 m_1ac;
    u32 m_1b0;
    u32 m_1b4;
    u8 _pad1B8[0x8];
    u32 m_1c0;
    u32 m_1c4;
    static s32 select_fog_for_viewport(s32 arg0, s32 arg1, s32 arg2);
    static s32 restore_fog_for_player(s32 arg1, s32 arg0);
    static void*get_entry(int a0);
    static void clear_split_screen_fog();
    static void update_all();
    void clear_active_flag();
    s32 restore_fog(s32 arg1);
    void request_transition(s32 arg1, s32 arg2);
    s32 get_param();
    void apply_slot_params(s32 idx);
    static s32 is_controller_animated(s32 arg0, s32 arg1);
    void load_entry_into_slot(s32 i, s32 entry);
    virtual void render();
    static void update_fog_entries();
    static void reset();
    static void create_instance();
    static s32 update_all(s32 arg0, s32 arg1);
    static s32 apply_all(s32 arg0, s32 arg1);
    static s32 update_first_active_fog();
    static s32 update_all(s32 arg0);
    s32 select_fog(s32 arg1, s32 arg2);
};

typedef char TFogCtrl_size[sizeof(TFogCtrl) == 0x1C8 ? 1 : -1];
#endif
