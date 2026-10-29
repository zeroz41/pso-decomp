#include "types.h"
#include "pso/unk/text_8014B8A4.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8014B8A4_lbl_8043FB50 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_8014B8A4_lbl_804A9F50 {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * TObjNpcBase__ct(void *);
}
extern RecoveredGlobal_8014B8A4_lbl_8043FB50 male_npc_idle_animation_parameters;
extern RecoveredGlobal_8014B8A4_lbl_804A9F50 lbl_804A9F50;
extern s32 *npc_town_motion_data;
typedef char RecoveredGlobal_8014B8A4_lbl_8043FB50_size[sizeof(RecoveredGlobal_8014B8A4_lbl_8043FB50) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_8014B8A4_lbl_804A9F50_size[sizeof(RecoveredGlobal_8014B8A4_lbl_804A9F50) == 0x178 ? 1 : -1];
u8 *construct_male_npc_base(u8 *player) {
    TObjNpcBase__ct(player);
    *(s32 **)((s8 *)player + 0x18) = &lbl_804A9F50.value;
    ((TObjMotion *)player)->init_motion((TObjMotionAction *)&male_npc_idle_animation_parameters.value, (BmlMotionEntry *)*npc_town_motion_data, 0);
    ((TObjMotion *)player)->set_motion_interpolation_flag();
    return player;
}
