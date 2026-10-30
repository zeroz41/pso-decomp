#ifndef PSO_ENEMY_TOBJENERE2FLOWER_H
#define PSO_ENEMY_TOBJENERE2FLOWER_H

#include "types.h"
#include "pso/misc/MaterialOpacityFade.h"
#include "pso/enemy/TObjEneDD_ST.h"

struct TObjEneRe2Flower : public TObjEneDD_ST {
    virtual ~TObjEneRe2Flower();
    virtual void run_task();
    virtual void vfunc_88();
    virtual void vfunc_105();
    virtual void vfunc_106();
    void sub_800C3DC4();
    bool sub_800C3B8C();
    void dispatch_action(s32);
    void vfunc_63();
    void vfunc_62();
    void vfunc_61();
    void vfunc_28();
    u8 unk_374[0x30];
    u32 m_3c0;
    u32 m_3c4;
    u8 _pad3C8[0x4];
    u32 m_3cc;
    u32 m_3d0;
    u32 m_3d4;
    u32 m_3d8;
    u8 _pad3DC[0x18];
    void* m_3f4;
    u8 _pad3F8[0x10];
    u32 m_408;
    u8 _pad40C[0x4];

    MaterialOpacityFade fade;

    void handle_event(s32 arg1);
    void begin_state_242();
    s32 check_hit_flag();
    void clear_child_flags();
    void set_child_flags();
    u8 *find_target_in_range();
    static void destroy_instance();
    static void *create(void *arg0);
    int get_flag_11();
    u8 unk_410[0x1C];
};

typedef char TObjEneRe2FlowerFadeOffset[offsetof(TObjEneRe2Flower, fade) == 0x3F4 ? 1 : -1];

typedef char TObjEneRe2Flower_size[sizeof(TObjEneRe2Flower) == 0x42C ? 1 : -1];
#endif
