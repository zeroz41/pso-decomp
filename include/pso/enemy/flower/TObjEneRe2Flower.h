#ifndef PSO_ENEMY_FLOWER_TOBJENERE2FLOWER_H
#define PSO_ENEMY_FLOWER_TOBJENERE2FLOWER_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"

struct TObjEneRe2Flower : public TObjEneDD_ST {
    TObjEneRe2Flower(TObject *parent, void *setData);
    virtual ~TObjEneRe2Flower();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_28();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void vfunc_88();
    virtual void vfunc_105();
    virtual void vfunc_106();
    void sub_800C3DC4();
    s32 sub_800C3B8C();
    void sub_800C3BA8();
    void dispatch_action(s32);
    void handle_event(s32 arg1);
    void begin_state_242();
    s32 check_hit_flag();
    void clear_child_flags();
    void set_child_flags();
    u8 *find_target_in_range();
    static void destroy_instance();
    static void *create(void *arg0);
    int get_flag_11();

    u8 pad_374[0x8];
    f32 m_37c;
    u8 pad_380[0x40];
    s32 m_3c0;
    u32 m_3c4;
    f32 m_3c8;
    s32 m_3cc;
    s32 m_3d0;
    s32 m_3d4;
    s32 m_3d8;
    Vec m_3dc[2];
    TUnk_80494938 m_3f4;
    s32 m_410;
    s32 m_414;
    s32 m_418;
    s32 m_41c;
    s32 m_420;
    f32 m_424;
    TObject *m_428;
};

// The archive loader the enemy factory table pairs with destroy_instance.
extern "C" void TObjPlayer__sub_800C44C4(void);

typedef char TObjEneRe2Flower_size[sizeof(TObjEneRe2Flower) == 0x42C ? 1 : -1];
#endif
