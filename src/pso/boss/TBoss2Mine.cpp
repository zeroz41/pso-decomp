#include "types.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/boss/TBoss2Mine_800375C0.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/boss/TBoss2Mine.h"

extern "C" {

void *TBoss2Mine__ct(void *arg0, s32 arg1, s16 arg2, s16 arg3, s32 arg4);
void TBoss2Mine__sub_80038D84(void);
int TBoss2Mine__sub_80038D88(void* p);
s32 TObjEneDD__ct(void *, s32);
int TObjPlayer__sub_800F0928(void*);

extern void *__vt__10TBoss2Mine[];
extern s32 TBoss2Mine__name;

void *TBoss2Mine__ct(void *boss2_mine, s32 ene_dd, s16 arg2, s16 arg3, s32 arg4) {
    s32 temp_r3;

    TObjEneDD__ct(boss2_mine, ene_dd);
    *(void **)((s8 *)boss2_mine + 0x18) = (void *) __vt__10TBoss2Mine;
    *(s32 *)((s8 *)boss2_mine + 0) = (s32) TBoss2Mine__name;
    temp_r3 = get_instance__13TBoss2DeRolLeFv();
    if (temp_r3 != 0) {
        ((TObjEneDD *)boss2_mine)->init_common_from((u8 *)temp_r3);
    }
    ((TBoss2Mine *)boss2_mine)->entity_id = arg2;
    *(s16 *)((s8 *)boss2_mine + 0x2C) = arg3;
    init__10TBoss2MineFPvi((u8 *)boss2_mine, arg4);
    return boss2_mine;
}

void TBoss2Mine__sub_80038D84(void) {  }
int TBoss2Mine__sub_80038D88(void* p) { return TObjPlayer__sub_800F0928(p); }
void TBoss2Mine::apply_poison_status() {  }
void TBoss2Mine::apply_paralysis() {  }
void TBoss2Mine::apply_slow_status() {  }
void TBoss2Mine::apply_confusion_status() {  }
void TBoss2Mine::apply_movement_ailment(s32) {  }
void TBoss2Mine::apply_shock_status() {  }
void TBoss2Mine::clear_harmful_statuses() {  }
void TBoss2Mine::apply_attack_stat_status(void *) {  }
void TBoss2Mine::apply_defense_stat_status(void *) {  }

}
