#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/task/TObject.h"
#include "pso/effect/item/TItemEffEquip_801088D0.h"

void retire_equipment_effect(TObject* effect) {
    if (effect != 0) {
        effect->queue_destruction();
    }
}
