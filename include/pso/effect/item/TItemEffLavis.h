#ifndef PSO_EFFECT_ITEM_TITEMEFFLAVIS_H
#define PSO_EFFECT_ITEM_TITEMEFFLAVIS_H
#include "pso/weapon/shoot/TItemShootModel.h"
#include <stddef.h>

class TItemEffLavis : public TItemShootModel {
public:
    TItemEffLavis(void* owner, const Vec* start, const Vec* endpoint, f32 life);
    virtual ~TItemEffLavis();
    virtual void hook();

    static const char *class_name;
};

LAYOUT_ASSERT(LavisEffectSize, sizeof(TItemEffLavis) == 0x6C);
struct TItemWeapon;
TItemShoot *create_lavis_shot(TItemWeapon *owner, const Vec *start, const Vec *endpoint, f32 life);
#endif
