#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERJUNGENEMY_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERJUNGENEMY_H

#include "types.h"
#include "pso/player/TUnk_804B6C24.h"

struct TObjContainerJungEnemy : public TUnk_804B6C24 {
    virtual ~TObjContainerJungEnemy();
    virtual void vfunc_81();
    virtual void debug_print_item_box_info();
    virtual void vfunc_6(s16 *, s32);
    virtual void vfunc_80();
    virtual f32 receive_physical_attack(void *, f32);
    u32 m_368;
    u32 m_36c;
    u32 m_370;
    u32 m_374;
    void load_models();
    static void *create(void *arg0);
};

typedef char TObjContainerJungEnemy_size[sizeof(TObjContainerJungEnemy) == 0x378 ? 1 : -1];

extern "C" {
u8 *TObjContainerJungEnemy__ct(u8 *arg0, s32 arg1, s32 _w2);
void *__dt__22TObjContainerJungEnemyFv(void *arg0, s16 arg1);
}

#endif
