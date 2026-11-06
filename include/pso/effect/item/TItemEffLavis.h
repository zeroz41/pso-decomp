#ifndef PSO_EFFECT_ITEM_TITEMEFFLAVIS_H
#define PSO_EFFECT_ITEM_TITEMEFFLAVIS_H
#include "pso/weapon/shoot/TItemShootModel.h"
#include <stddef.h>

class TItemEffLavis : public TItemShootModel {
public:
    TItemEffLavis(void* owner, const Vec* start, const Vec* endpoint, f32 life);
    virtual ~TItemEffLavis();
    virtual void hook();
};

typedef char LavisEffectSize[(sizeof(TItemEffLavis) == 0x6C) ? 1 : -1];
extern "C" TItemEffLavis* create_lavis_shot(void* owner, const Vec* start,
                                          const Vec* endpoint, f32 life);
#endif
