#ifndef PSO_WEAPON_TITEMATTACKCOL_H
#define PSO_WEAPON_TITEMATTACKCOL_H

#include "types.h"
#include "pso/item/TUnk_804E355C.h"

struct TItemAttackCol : public TUnk_804E355C {
    virtual ~TItemAttackCol();
    virtual void vfunc_7();
    void check_object_hits();
    virtual void vfunc_6(s32 *);
    void* m_c4;
    u8 _padC8[0x8];
    void* m_d0;
    u8 unk_D4[0x8];
    f32 m_dc;
    void* m_e0;
    u32 m_e4;
    u32 m_e8;
    u32 m_ec;
    u32 m_f0;
    u32 m_f4;
    u32 m_f8;
    void* m_fc;
    u32 m_100;
    u8 _pad104[0x4];
    void* m_108;
    u8 _pad10C[0x8];
    u32 m_114;
    u32 m_118;
    u32 m_11c;
    u8 _pad120[0xC];
    u32 m_12c;
    u32 m_130;
    u32 m_134;
    u32 m_138;
    u32 m_13c;
    u32 m_140;
    static void add_to_active_list(void* a0);
    void shift_collision_bounds();
    void move_with_collision(void *arg1);
    virtual void render();
    virtual void run_task();
    static void create(void *arg0, void *arg1);
    void copy_pos(void* q);
};

typedef char TItemAttackCol_size[sizeof(TItemAttackCol) == 0x144 ? 1 : -1];
#endif
