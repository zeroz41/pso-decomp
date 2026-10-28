#include "types.h"
#include "pso/misc/TLobby_8030A6A8.h"
#include "pso/misc/TOContainerAncientEnemyRare.h"
#include "pso/misc/TUnk_804B27D8.h"

struct RecoveredGlobal_8015B76C___vt__27TOContainerAncientEnemyRare {
    s32 value;
    u8 remaining[0x148];
};

extern "C" {
int is_quest_active(void);
s32 TOContainerAncientEnemyCommon__ct(int, void *);
s32 __nw__7TObjectFUl(int);
extern s32 enable_v2_features;
u8 *TOContainerAncientEnemy__ct(u8 *arg0, s32 arg1);
extern s32 __vt__27TOContainerAncientEnemyRare[];
extern s32 lbl_805D2F10;
extern s32 *ancient_container_fragment_texture_lists;
void __dl__7TObjectFPv(void *);
void *__dt__23TOContainerAncientEnemyFv(void *arg0, s16 arg1);

void TUnk_804B27D8::vfunc_15() {  }

void *__dt__27TOContainerAncientEnemyRareFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__27TOContainerAncientEnemyRare;
        __dt__23TOContainerAncientEnemyFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_8015B76C___vt__27TOContainerAncientEnemyRare_size[sizeof(RecoveredGlobal_8015B76C___vt__27TOContainerAncientEnemyRare) == 0x14C ? 1 : -1];
u8 *TOContainerAncientEnemyRare__ct(u8 *container_ancient_enemy_rare, s32 arg1) {
    TOContainerAncientEnemy__ct(container_ancient_enemy_rare, arg1);
    *(s32 **)((s8 *)container_ancient_enemy_rare + 0x18) = &(*(RecoveredGlobal_8015B76C___vt__27TOContainerAncientEnemyRare *)&__vt__27TOContainerAncientEnemyRare).value;
    *(s32 *)((s8 *)container_ancient_enemy_rare + 0) = (s32) lbl_805D2F10;
    ((TOContainerAncientEnemyRare *)container_ancient_enemy_rare)->texlist = (s32) *ancient_container_fragment_texture_lists;
    return container_ancient_enemy_rare;
}

s32 TOContainerAncientEnemyCommon__create(s32 container_ancient_enemy_common) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r0;
    s32 var_r0_2;
    if (((s32) enable_v2_features == 1) && (get_game_play_mode() == 1) && (is_quest_active() == 1)) {
        temp_r3 = __nw__7TObjectFUl(0x368);
        var_r0_2 = temp_r3;
        if (var_r0_2 != 0) {
            var_r0_2 = TOContainerAncientEnemyCommon__ct((int)temp_r3, (void *)container_ancient_enemy_common);
        }
        return var_r0_2;
    }
    temp_r3_2 = __nw__7TObjectFUl(0x368);
    var_r0 = temp_r3_2;
    if (var_r0 != 0) {
        var_r0 = TOContainerAncientEnemyCommon__ct((int)temp_r3_2, (void *)container_ancient_enemy_common);
    }
    return var_r0;
}

}
