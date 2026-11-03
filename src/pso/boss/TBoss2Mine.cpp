#include "types.h"
#include "pso/boss/TBoss2Mine.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/boss/TBoss2Mine_800375C0.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/boss/TBoss2Mine.h"

extern "C" {

void TBoss2Mine__sub_80038D84(void);
int TBoss2Mine__sub_80038D88(void* p);
s32 __ct__9TObjEneDDFP7TObject(void *, s32);
int TObjPlayer__sub_800F0928(void*);

extern void *__vt__10TBoss2Mine[];
extern s32 TBoss2Mine__name;

}
TBoss2Mine::TBoss2Mine(s32 ene_dd, s16 arg2, s16 arg3, s32 arg4) : TObjEneDD((TObject *)ene_dd) {
    s32 temp_r3;
    *(s32 *)((s8 *)this + 0) = (s32) TBoss2Mine__name;
    temp_r3 = get_instance__13TBoss2DeRolLeFv();
    if (temp_r3 != 0) {
        ((TObjEneDD *)this)->init_common_from((u8 *)temp_r3);
    }
    this->entity_id = arg2;
    *(s16 *)((s8 *)this + 0x2C) = arg3;
    init__10TBoss2MineFPvi((u8 *)this, arg4);
}
extern "C" {

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
