#include "types.h"
#include "pso/unk/text_8014AAC4.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_8014AAC4_lbl_8043F9C8 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_8014AAC4_lbl_804A92A8 {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
u8 * TObjNpcBase__ct(void *);
extern RecoveredGlobal_8014AAC4_lbl_8043F9C8 town_npc_animation_init_data;
extern RecoveredGlobal_8014AAC4_lbl_804A92A8 npc_female_tall_dispatch_table;
extern s32 *npc_town_motion_data;
typedef char RecoveredGlobal_8014AAC4_lbl_8043F9C8_size[sizeof(RecoveredGlobal_8014AAC4_lbl_8043F9C8) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_8014AAC4_lbl_804A92A8_size[sizeof(RecoveredGlobal_8014AAC4_lbl_804A92A8) == 0x178 ? 1 : -1];
u8 *fn_8014AAC4(u8 *player) {
    TObjNpcBase__ct(player);
    *(s32 **)((s8 *)player + 0x18) = &npc_female_tall_dispatch_table.value;
    ((TObjMotion *)player)->init_motion((TObjMotionAction *)&town_npc_animation_init_data.value, (BmlMotionEntry *)*npc_town_motion_data, 0);
    ((TObjMotion *)player)->set_motion_interpolation_flag();
    return player;
}

}
