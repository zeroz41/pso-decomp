#include "types.h"
#include "pso/unk/text_8014AAC4.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8014AAC4_lbl_804A92A8 {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * TObjNpcBase__ct(void *);
extern const TObjMotionAction town_npc_animation_init_data[];
const TObjMotionAction town_npc_animation_init_data[2] = {
    {MOTION_MODE_LOOP, -1, 0, 0.9f, 1},
    {MOTION_MODE_LOOP, -1, 3, 1.4f, ACTION_INTERPOLATE | 2},
};
extern RecoveredGlobal_8014AAC4_lbl_804A92A8 npc_female_tall_dispatch_table;
extern s32 *npc_town_motion_data;
typedef char RecoveredGlobal_8014AAC4_lbl_804A92A8_size[sizeof(RecoveredGlobal_8014AAC4_lbl_804A92A8) == 0x178 ? 1 : -1];
u8 *fn_8014AAC4(u8 *player) {
    TObjNpcBase__ct(player);
    *(s32 **)((s8 *)player + 0x18) = &npc_female_tall_dispatch_table.value;
    ((TObjMotion *)player)->init_motion((TObjMotionAction *)town_npc_animation_init_data, (BmlMotionEntry *)*npc_town_motion_data, 0);
    ((TObjMotion *)player)->set_motion_interpolation_flag();
    return player;
}

}
