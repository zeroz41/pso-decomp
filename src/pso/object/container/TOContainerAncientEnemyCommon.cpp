#include "types.h"
#include "pso/object/container/TOContainerAncientEnemyCommon.h"

extern "C" {

void *TOContainerAncientEnemyCommon__ct(void *arg0);
void *__dt__29TOContainerAncientEnemyCommonFv(void *arg0, s16 arg1);
void TOContainerAncientEnemy__ct(void *);
void __dl__7TObjectFPv(void *);
void *__dt__23TOContainerAncientEnemyFv(void *arg0, s16 arg1);

extern s32 __vt__29TOContainerAncientEnemyCommon[];

void *__dt__29TOContainerAncientEnemyCommonFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__29TOContainerAncientEnemyCommon;
        __dt__23TOContainerAncientEnemyFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *lbl_805D2F0C;

void *TOContainerAncientEnemyCommon__ct(void *container_ancient_enemy_common) {
    TOContainerAncientEnemy__ct(container_ancient_enemy_common);
    *(s32 **)((s8 *)container_ancient_enemy_common + 0x18) = __vt__29TOContainerAncientEnemyCommon;
    *(void * *)&((TOContainerAncientEnemyCommon *)container_ancient_enemy_common)->m_name = lbl_805D2F0C;
    return container_ancient_enemy_common;
}

}
