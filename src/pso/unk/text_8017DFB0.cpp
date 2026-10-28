#include "types.h"
#include "pso/misc/TOWreckAncient02.h"
#include "pso/unk/text_8017DFB0.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8017DFB0_lbl_804B5418 {
    s32 value;
    u8 remaining[0x130];
};

struct RecoveredGlobal_8017DFB0___vt__16TOWreckAncient02 {
    s32 value;
    u8 remaining[0x34];
};

extern "C" {
u32 init_collision_body_parts(void *, s32, s32);
u8 *TOWreckAncient__ct(u8 *arg0, s32 arg1);
extern RecoveredGlobal_8017DFB0_lbl_804B5418 TOWreckAncient__collision_body_templates;
extern RecoveredGlobal_8017DFB0___vt__16TOWreckAncient02 __vt__16TOWreckAncient02;
extern s32 TOWreckAncient02__name;
typedef char RecoveredGlobal_8017DFB0_lbl_804B5418_size[sizeof(RecoveredGlobal_8017DFB0_lbl_804B5418) == 0x134 ? 1 : -1];
typedef char RecoveredGlobal_8017DFB0___vt__16TOWreckAncient02_size[sizeof(RecoveredGlobal_8017DFB0___vt__16TOWreckAncient02) == 0x38 ? 1 : -1];
u8 *TOWreckAncient02__ct(u8 *wreck_ancient, s32 arg1) {
    TOWreckAncient__ct(wreck_ancient, 0);
    *(s32 **)((s8 *)wreck_ancient + 0x18) = &__vt__16TOWreckAncient02.value;
    *(s32 *)((s8 *)wreck_ancient + 0) = (s32) TOWreckAncient02__name;
    ((TOWreckAncient02 *)(wreck_ancient))->apply_object_set_data((void *)arg1);
    init_collision_body_parts(wreck_ancient, (s32) &TOWreckAncient__collision_body_templates.value, 1);
    ((TObjPlayer *)wreck_ancient)->register_object_by_id();
    return wreck_ancient;
}

}
