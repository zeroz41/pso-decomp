#include "types.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/unk/text_801095EC.h"
#include "pso/TItemEffLandHit.h"
#include "pso/system/vector.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_801095EC___vt__15TItemEffLandHit {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_801095EC___vt__15TItemEffLandHit __vt__15TItemEffLandHit;
extern s32 TItemEffLandHit__class_name;
typedef char RecoveredGlobal_801095EC___vt__15TItemEffLandHit_size[sizeof(RecoveredGlobal_801095EC___vt__15TItemEffLandHit) == 0x18 ? 1 : -1];
u8 *TItemEffLandHit__ct(u8 *item_eff_land_hit, u8 *arg1, u8 *item, u8 *arg3, u8 *arg4) {
    __ct__7TObjectFP7TObject(item_eff_land_hit, arg1);
    *(s32 **)((s8 *)item_eff_land_hit + 0x18) = &__vt__15TItemEffLandHit.value;
    *(s32 *)((s8 *)item_eff_land_hit + 0) = (s32) TItemEffLandHit__class_name;
    VecCopy((Vec *)(item_eff_land_hit + 0x28), (const Vec *)arg4);
    VecCopy((Vec *)(item_eff_land_hit + 0x1C), (const Vec *)arg3);
    *(s32 *)((s8 *)item_eff_land_hit + 0x34) = ((TItem *)item)->get_item_id();
    ((TItemEffLandHit *)item_eff_land_hit)->m_38 = 0;
    disallow_rendering__7TObjectFv((TObject *)item_eff_land_hit);
    return item_eff_land_hit;
}

}
