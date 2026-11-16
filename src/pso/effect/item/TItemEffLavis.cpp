#include "pso/effect/item/TItemEffLavis.h"

const char *TItemEffLavis__class_name = "TItemEffLavis";

void TItemEffLavis::hook() {}
TItemEffLavis::~TItemEffLavis() {}

TItemEffLavis::TItemEffLavis(void* owner, const Vec* start,
                           const Vec* endpoint, f32 life)
    : TItemShootModel(owner, start, endpoint, life) {
    m_name = TItemEffLavis__class_name;
}

TItemEffLavis* create_lavis_shot(void* owner, const Vec* start,
                              const Vec* endpoint, f32 life) {
    TItemEffLavis* result = 0;
    if (0.0f != life && owner != 0) {
        result = new TItemEffLavis(owner, start, endpoint, life);
    }
    return result;
}
