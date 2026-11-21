#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/system/task/TObject_80019A50.h"
#include "types.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/unk/text_801095EC.h"
#include "pso/system/vector.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"

const char *TItemEffLandHit__class_name = "TItemEffLandHit";

void TItemEffLandHit::run_task() {
    if (this->m_38) {
        queue_destruction();
    }
}

TItemEffLandHit::~TItemEffLandHit() {}

#define item_eff_land_hit ((u8 *)this)
TItemEffLandHit::TItemEffLandHit(TObject *parent, TItem *item, Vec *arg3, Vec *arg4) : TObject(parent) {
    *(s32 *)((s8 *)item_eff_land_hit + 0) = (s32) TItemEffLandHit__class_name;
    VecCopy((Vec *)(item_eff_land_hit + 0x28), (const Vec *)arg4);
    VecCopy((Vec *)(item_eff_land_hit + 0x1C), (const Vec *)arg3);
    *(s32 *)((s8 *)item_eff_land_hit + 0x34) = ((TItem *)item)->get_item_id();
    ((TItemEffLandHit *)item_eff_land_hit)->m_38 = 0;
    ((TObject *)item_eff_land_hit)->disallow_rendering();
}
#undef item_eff_land_hit
