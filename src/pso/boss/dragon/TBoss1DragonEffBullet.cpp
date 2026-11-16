#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "libs/dolphin/include/dolphin/mtx/GeoTypes.h"
#include "pso/boss/dragon/TBoss1DragonEffBullet.h"
#include "pso/system/vector.h"
#include "pso/boss/dragon/TBoss1Dragon.h"

#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

struct RecoveredFields_8002B9D0_arg0 {
    u8 unknown_0[0x1C];
    Vec position;
    Vec field_28;
    s32 field_34;
    s32 field_38;
    f32 field_3C;
    f32 field_40;
    TParticleCtrl* particle;
    TParticleCtrl* particle_2;
};

extern "C" {
s32 isV2Mode__12TBoss1DragonFv(void);
// Fireball particle ids (flight, impact, burst): the normal dragon's and the v2 one's.
extern const s32 lbl_80435410[3] = {548, 550, 553};
extern const s32 lbl_8043541C[3] = {522, 520, 201};
const s32 *dragon_fireball_particle_ids;
s32 __ct__7TObjectFP7TObject(void *, void *);
f32 subtract_vector(void *, void *);
extern s32 __vt__21TBoss1DragonEffBullet[];
const char *TBoss1DragonEffBullet__name = "TBoss1DragonEffBullet";

void TBoss1DragonEffBullet::render() {  }

#pragma push
#pragma fp_contract on
void TBoss1DragonEffBullet::run_task() {
    struct RecoveredFields_8002B9D0_arg0 *self = (struct RecoveredFields_8002B9D0_arg0 *)this;
    f32 temp_f0;
    f32 temp_f1;
    f32 speed;
    TParticleCtrl *particle;
    TParticleCtrl *particle_2;
    TParticleCtrl *temp_r3_3;
    TParticleCtrl *temp_r3_4;
    switch (self->field_38) {
    case 0:
        speed = 25.0f;
        self->field_3C += speed;
        temp_f0 = self->field_3C;
        temp_f1 = self->field_40;
        if (temp_f0 > temp_f1) {
            self->field_34 = 0;
            speed = temp_f1 - (temp_f0 - speed);
            self->field_38 = 1;
        }
        self->position.x += self->field_28.x * speed;
        self->position.y += self->field_28.y * speed;
        self->position.z += self->field_28.z * speed;
        if (self->particle == NULL) {
            self->particle = spawn_continuous_particle_effect_with_flags(&self->position, dragon_fireball_particle_ids[0], 0x40);
        }
        particle = self->particle;
        if (particle != NULL) {
            particle->set_position(&self->position);
        }
        particle_2 = self->particle_2;
        if (particle_2 != NULL) {
            particle_2->set_position(&self->position);
        }
        return;
    case 1:
        self->field_34 += 1;
        if (self->field_34 == 1) {
            spawn_particle_effect_with_flags(&self->position, dragon_fireball_particle_ids[1], 0x40);
            temp_r3_3 = self->particle_2;
            if (temp_r3_3 != NULL) {
                temp_r3_3->queue_destruction();
                self->particle_2 = NULL;
            }
            temp_r3_4 = self->particle;
            if (temp_r3_4 != NULL) {
                temp_r3_4->queue_destruction();
                self->particle = NULL;
            }
            play_sound_effect(0x4003AD0C, (Vec *)(&self->position), 0, 0);
            ((TBoss1Dragon *)(TBoss1Dragon::get_instance()))->apply_fireball_impact_damage(&self->position);
        }
        if ((s32) self->field_34 <= 2) {
            spawn_particle_effect_with_flags(&self->position, *(s32 *)((s8 *)(*(u8 * *)&dragon_fireball_particle_ids) + 8), 0x40);
            return;
        }
        self->field_38 = 2;
        return;
    case 2:
        self->field_34 += 1;
        if ((s32) self->field_34 > 0x64) {
            ((TObject *)self)->queue_destruction();
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

u8 *TBoss1DragonEffBullet__ct(u8 *boss1_dragon_eff_bullet, s32 arg1, s32 arg2, s32 arg3) {
    __ct__7TObjectFP7TObject((void *)boss1_dragon_eff_bullet, (void *)arg1);
    *(s32 **)((s8 *)boss1_dragon_eff_bullet + 0x18) = __vt__21TBoss1DragonEffBullet;
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
    play_sound_effect(0x4003B20B, (Vec *)(boss1_dragon_eff_bullet + 0x1C), 0, 0);
    return boss1_dragon_eff_bullet;
}

void TBoss1Dragon::select_fireball_particle_table() {
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        dragon_fireball_particle_ids = lbl_80435410;
        return;
    case 1:
        dragon_fireball_particle_ids = lbl_8043541C;
        return;
    }
}
