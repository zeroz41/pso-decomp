#include "types.h"
#include "pso/npc/TObjNpcFemaleBase_80149C7C.h"
#include "pso/object/TObjMotion.h"
#include "pso/npc/TUnk_804A8640.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80149CE0_lbl_8043F810 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_80149CE0_lbl_804A8640 {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * TObjNpcBase__ct(void *);
extern RecoveredGlobal_80149CE0_lbl_8043F810 npc_female_base_action_table;
extern s32 lbl_804A8640[];
extern s32 *npc_town_motion_data;
void __dl__7TObjectFPv(void *);
void *__dt__11TObjNpcBaseFv(void *arg0, s16 arg1);

    extern int lbl_805D5758;
    extern int lbl_805D5D78;
void TObjNpcFemaleBase__sub_80149C7C(void) { lbl_805D5758 = lbl_805D5D78; }

void *TUnk_804A8640::destroy_npc_female_base(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804A8640;
        __dt__11TObjNpcBaseFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}
typedef char RecoveredGlobal_80149CE0_lbl_8043F810_size[sizeof(RecoveredGlobal_80149CE0_lbl_8043F810) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_80149CE0_lbl_804A8640_size[sizeof(RecoveredGlobal_80149CE0_lbl_804A8640) == 0x178 ? 1 : -1];
u8 *TUnk_804A8640::construct_female_base() {
    u8 *arg0 = (u8 *)this;
    TObjNpcBase__ct(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80149CE0_lbl_804A8640 *)&lbl_804A8640).value;
    ((TObjMotion *)arg0)->init_motion((TObjMotionAction *)&npc_female_base_action_table.value, (BmlMotionEntry *)*npc_town_motion_data, 0);
    ((TObjMotion *)arg0)->set_motion_interpolation_flag();
    return arg0;
}

}
