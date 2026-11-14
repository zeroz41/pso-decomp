#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/dragon/TBoss1DragonEffBullet.h"
#include "pso/system/vector.h"
#include "pso/boss/dragon/TBoss1Dragon.h"

#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/task/TObject.h"

struct RecoveredGlobal_8002BCE0_lbl_80435410 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8002BCE0_lbl_8043541C {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8002BC30___vt__21TBoss1DragonEffBullet {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredFields_8002B9D0_arg0 {
    u8 unknown_0[0x1C];
    f32 field_1C;
    f32 field_20;
    f32 field_24;
    f32 field_28;
    f32 field_2C;
    f32 field_30;
    s32 field_34;
    s32 field_38;
    f32 field_3C;
    f32 field_40;
    u8 * field_44;
    u8 * field_48;
};

extern "C" {
s32 isV2Mode__12TBoss1DragonFv(void);
extern RecoveredGlobal_8002BCE0_lbl_80435410 lbl_80435410;
extern RecoveredGlobal_8002BCE0_lbl_8043541C lbl_8043541C;
s32 *dragon_fireball_particle_ids;
s32 __ct__7TObjectFP7TObject(void *, void *);
f32 subtract_vector(void *, void *);
extern s32 __vt__21TBoss1DragonEffBullet[];
extern s32 TBoss1DragonEffBullet__name;

void TBoss1DragonEffBullet::render() {  }

#pragma push
#pragma fp_contract on
void TBoss1DragonEffBullet::run_task() {
    struct RecoveredFields_8002B9D0_arg0 *arg0 = (struct RecoveredFields_8002B9D0_arg0 *)this;
    f32 temp_f0;
    f32 temp_f1;
    f32 var_f2;
    u8 *temp_r3;
    u8 *temp_r3_2;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    switch (arg0->field_38) {
    case 0:
        var_f2 = 25.0f;
        arg0->field_3C += var_f2;
        temp_f0 = arg0->field_3C;
        temp_f1 = arg0->field_40;
        if (temp_f0 > temp_f1) {
            arg0->field_34 = 0;
            var_f2 = temp_f1 - (temp_f0 - var_f2);
            arg0->field_38 = 1;
        }
        arg0->field_1C += arg0->field_28 * var_f2;
        arg0->field_20 += arg0->field_2C * var_f2;
        arg0->field_24 += arg0->field_30 * var_f2;
        if ((u8 *) arg0->field_44 == NULL) {
            arg0->field_44 = (u8 *)spawn_continuous_particle_effect_with_flags(&arg0->field_1C, *(s32 *)((s8 *)(*(u8 * *)&dragon_fireball_particle_ids) + 0), 0x40);
        }
        temp_r3 = arg0->field_44;
        if (temp_r3 != NULL) {
            ((TParticleCtrl *)temp_r3)->set_position(&arg0->field_1C);
        }
        temp_r3_2 = arg0->field_48;
        if (temp_r3_2 != NULL) {
            ((TParticleCtrl *)temp_r3_2)->set_position(&arg0->field_1C);
        }
        return;
    case 1:
        arg0->field_34 += 1;
        if ((s32) arg0->field_34 == 1) {
            spawn_particle_effect_with_flags(&arg0->field_1C, *(s32 *)((s8 *)(*(u8 * *)&dragon_fireball_particle_ids) + 4), 0x40);
            temp_r3_3 = arg0->field_48;
            if (temp_r3_3 != NULL) {
                ((TObject *)temp_r3_3)->queue_destruction();
                arg0->field_48 = NULL;
            }
            temp_r3_4 = arg0->field_44;
            if (temp_r3_4 != NULL) {
                ((TObject *)temp_r3_4)->queue_destruction();
                arg0->field_44 = NULL;
            }
            play_sound_effect(0x4003AD0C, &arg0->field_1C, 0, 0);
            ((TBoss1Dragon *)(TBoss1Dragon::get_instance()))->apply_fireball_impact_damage((s32)&arg0->field_1C);
        }
        if ((s32) arg0->field_34 <= 2) {
            spawn_particle_effect_with_flags(&arg0->field_1C, *(s32 *)((s8 *)(*(u8 * *)&dragon_fireball_particle_ids) + 8), 0x40);
            return;
        }
        arg0->field_38 = 2;
        return;
    case 2:
        arg0->field_34 += 1;
        if ((s32) arg0->field_34 > 0x64) {
            ((TObject *)arg0)->queue_destruction();
        }
        break;
    }
}
#pragma pop

}
TBoss1DragonEffBullet::~TBoss1DragonEffBullet() {
    if (*(void **)((s8 *)this + 0x48) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x48)))->queue_destruction(); this->m_48 = 0; }
    if (*(void **)((s8 *)this + 0x44) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x44)))->queue_destruction(); this->m_44 = 0; }
}

typedef char RecoveredGlobal_8002BCE0_lbl_80435410_size[sizeof(RecoveredGlobal_8002BCE0_lbl_80435410) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8002BCE0_lbl_8043541C_size[sizeof(RecoveredGlobal_8002BCE0_lbl_8043541C) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_8002BC30___vt__21TBoss1DragonEffBullet_size[sizeof(RecoveredGlobal_8002BC30___vt__21TBoss1DragonEffBullet) == 0x18 ? 1 : -1];
u8 *TBoss1DragonEffBullet__ct(u8 *boss1_dragon_eff_bullet, s32 arg1, s32 arg2, s32 arg3) {
    __ct__7TObjectFP7TObject((void *)boss1_dragon_eff_bullet, (void *)arg1);
    *(s32 **)((s8 *)boss1_dragon_eff_bullet + 0x18) = &(*(RecoveredGlobal_8002BC30___vt__21TBoss1DragonEffBullet *)&__vt__21TBoss1DragonEffBullet).value;
    *(s32 *)((s8 *)boss1_dragon_eff_bullet + 0) = (s32) TBoss1DragonEffBullet__name;
    VecCopy((Vec *)(boss1_dragon_eff_bullet + 0x1C), (const Vec *)(arg2));
    VecCopy((Vec *)(boss1_dragon_eff_bullet + 0x28), (const Vec *)(arg3));
    subtract_vector(boss1_dragon_eff_bullet + 0x28, boss1_dragon_eff_bullet + 0x1C);
    ((TBoss1DragonEffBullet *)boss1_dragon_eff_bullet)->m_40 = ((TObjBoss2Tunnel *)(boss1_dragon_eff_bullet + 0x28))->update_scale();
    *(f32 *)((s8 *)boss1_dragon_eff_bullet + 0x3C) = 0.0f;
    ((TBoss1DragonEffBullet *)boss1_dragon_eff_bullet)->m_34 = 0;
    ((TBoss1DragonEffBullet *)boss1_dragon_eff_bullet)->m_38 = 0;
    ((TBoss1DragonEffBullet *)boss1_dragon_eff_bullet)->m_44 = 0;
    ((TBoss1DragonEffBullet *)boss1_dragon_eff_bullet)->m_48 = 0;
    play_sound_effect(0x4003B20B, boss1_dragon_eff_bullet + 0x1C, 0, 0);
    return boss1_dragon_eff_bullet;
}

void TBoss1Dragon::select_fireball_particle_table() {
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        dragon_fireball_particle_ids = &lbl_80435410.value;
        return;
    case 1:
        dragon_fireball_particle_ids = &lbl_8043541C.value;
        return;
    }
}

