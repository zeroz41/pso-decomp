#include "types.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/boss/TBoss6GravBall_80323134.h"
#include "pso/system/vector.h"
#include "pso/boss/TBoss6GravBall.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/misc/TNowLoading.h"
#include "pso/ui/TAdLdQuestPrtGC.h"
#include "pso/TParticleCtrl.h"

struct RecoveredGlobal_80323214_lbl_80476658 {
    s32 value;
    u8 remaining[0x20];
};

struct RecoveredGlobal_80323278_lbl_80476658 {
    s32 value;
    u8 remaining[0x20];
};

struct Vec_80323134 { f32 x, y, z; };
struct Ctl_80323134 { u8 pad[0x38]; Vec_80323134 pos; };
struct Obj_80323134 { u8 pad[0xC8]; Vec_80323134 pos; void *items[9]; };
struct T_80323320 { u8 pad[0xD4]; s32 arr[9]; };

extern "C" {
extern RecoveredGlobal_80323214_lbl_80476658 TBoss6GravBall__emitter_id_table;
void TBoss6GravBall__sub_80323320(T_80323320 *self);
void *get_player_by_client_id(s32 i);
void fn_80323134(Obj_80323134 *arg0);

void fn_80323134(Obj_80323134 *arg0) {
    s32 i;
    Vec_80323134 v;
    Ctl_80323134 *c;
    for (i = 0; i < 9; i++) {
        if (arg0->items[i] != 0) {
            switch (i) {
            case 5: case 6: case 7: case 8:
                c = (Ctl_80323134 *)get_player_by_client_id((u16)(i - 5));
                if (c != 0) {
                    VecCopy((Vec *)&v, (const Vec *)&c->pos);
                    ((TParticleCtrl *)arg0->items[i])->set_position(&v);
                }
                break;
            default:
                ((TParticleCtrl *)arg0->items[i])->set_position(&arg0->pos);
                break;
            }
        }
    }
}

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_80323214_lbl_80476658_size[sizeof(RecoveredGlobal_80323214_lbl_80476658) == 0x24 ? 1 : -1];

#pragma push
#pragma opt_common_subs off
void TBoss6GravBall::destroy_part(s32 arg1) {
    s32 arg0 = (s32)this;
    u32 temp_r3;
    u8 *temp_r31;
    temp_r31 = (u8 *)(arg0 + (arg1 * 4));
    temp_r3 = *(u32 *)((s8 *)temp_r31 + 0xD4);
    if (temp_r3 != 0U) {
        TParticleCtrl::release((void *)temp_r3);
        *(u32 *)((s8 *)temp_r31 + 0xD4) = 0U;
    }
}
#pragma pop

void TBoss6GravBall__sub_80323214(s32 arg0, s32 arg1) {
    s32 temp_r5;
    u8 *temp_r31;
    u8 *boss4_type2;
    temp_r5 = arg1 * 4;
    temp_r31 = (u8 *)(arg0 + temp_r5);
    if ((void *) *(u8 **)((s8 *)temp_r31 + 0xD4) == NULL) {
        *(u8 **)((s8 *)temp_r31 + 0xD4) = (unsigned char *) (create_particle_emitter((void *)(arg0 + 0xC8), *(s32 *)((s8 *)&TBoss6GravBall__emitter_id_table.value + temp_r5)));
        boss4_type2 = (u8 *)(*(u8 **)((s8 *)temp_r31 + 0xD4));
        if (boss4_type2 != NULL) {
            ((TParticleCtrl *)boss4_type2)->set_flags(0x2040);
        }
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_80323278_lbl_80476658_size[sizeof(RecoveredGlobal_80323278_lbl_80476658) == 0x24 ? 1 : -1];
void TBoss6GravBall::create_emitter(s32 arg1) {
    s32 arg0 = (s32)this;
    s32 temp_r5;
    u8 *temp_r31;
    u8 *boss4_type2;
    temp_r5 = arg1 * 4;
    temp_r31 = (u8 *)(arg0 + temp_r5);
    if ((void *) *(u8 **)((s8 *)temp_r31 + 0xD4) == NULL) {
        *(u8 **)((s8 *)temp_r31 + 0xD4) = (unsigned char *) (create_particle_emitter((void *)(arg0 + 0xC8), *(s32 *)((s8 *)(&(*(RecoveredGlobal_80323278_lbl_80476658 *)&TBoss6GravBall__emitter_id_table).value) + temp_r5)));
        boss4_type2 = (u8 *)(*(u8 **)((s8 *)temp_r31 + 0xD4));
        if (boss4_type2 != NULL) {
            ((TParticleCtrl *)boss4_type2)->set_flags(0x40);
        }
    }
}
#pragma pop

void TBoss6GravBall::init_parts() {
    s32 arg0 = (s32)this;
    s32 var_r31;
    var_r31 = 0;
    do {
        destroy_part(var_r31);
        var_r31 += 1;
    } while (var_r31 < 9);
}

void TBoss6GravBall__sub_80323320(T_80323320 *self) {
    s32 i;
    for (i = 0; i < 9; i++) {
        self->arr[i] = 0;
    }
}

void TBoss6GravBall::render() {  }

}
