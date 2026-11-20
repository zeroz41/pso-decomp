#ifndef PSO_OBJECT_CONTAINER_TOBJCONTAINERJUNGENEMY_H
#define PSO_OBJECT_CONTAINER_TOBJCONTAINERJUNGENEMY_H

#include "types.h"
#include "pso/player/TUnk_804B6C24.h"

struct TObjContainerJungEnemy : public TUnk_804B6C24 {
    TObjContainerJungEnemy(TObject *parent, void *set_data);
    virtual ~TObjContainerJungEnemy();
    virtual void vfunc_79() const;
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

LAYOUT_ASSERT(TObjContainerJungEnemy_size, sizeof(TObjContainerJungEnemy) == 0x378);

#endif
