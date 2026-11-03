#ifndef PSO_BOSS_TUNK_804E4B3C_H
#define PSO_BOSS_TUNK_804E4B3C_H
#include "types.h"
#include "pso/TObject.h"

class TUnk_804E4B3C : public TObject {
public:
    virtual ~TUnk_804E4B3C();
    virtual void run_task();
    void *destroy(s16);
    void update_phase_motion();
    void spawn(s32, s32);
    virtual void render();
    // run_task's phase handlers (indexed by unk_1C)
    void init_effect();
    void sub_802F2400();
    void sub_802F23FC();
    void sub_802F273C();
    void update_dust_spawn();
    void update_spawn_timer(s32 arg1, s32 arg2, s32 arg3);
    void double_scroll_speed();
    void advance_effect_timer();
    s32 unk_1C;
    u8 unk_20[0x34];
    f32 unk_54;
    f32 unk_58;
    f32 unk_5C; // scroll speed (update_spawn_timer adds it to unk_58, advance_effect_timer raises it)
    u8 unk_60[0x10];
    s32 unk_70;
    u8 unk_74[0xC];
    f32 unk_80;
    f32 m_84;
    TObject *unk_88;
    void * m_8c;
    u8 unk_90[0x4];
};
typedef char TUnk_804E4B3C_size[sizeof(TUnk_804E4B3C) == 0x94 ? 1 : -1];

#endif
