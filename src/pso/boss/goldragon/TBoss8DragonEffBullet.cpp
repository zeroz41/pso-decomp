#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/goldragon/TBoss8DragonEffBullet.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/math/MatrixTransforms.h"

#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/task/TObject.h"

#pragma readonly_strings on

extern "C" {
// Three id tables; the constructor stores the one m_44 (1-3) selects at +0x54.
static const s32 lbl_80474B68[3] = {548, 550, 553};
static const s32 lbl_80474B74[3] = {538, 536, 553};
static const s32 lbl_80474B80[3] = {522, 518, 521};
const char *TBoss8DragonEffBullet__name = "TBoss8DragonEffBullet";
u8 *get_enemy_entity(u16 arg0);
void TBoss8Dragon__sub_802FB220(void *o, saddr x, u32 a);

void TBoss8DragonEffBullet::render() {  }

#pragma push
#pragma fp_contract on
void TBoss8DragonEffBullet::run_task() {
    f32 temp_f0;
    f32 temp_f1;
    f32 var_f2;
    TParticleCtrl *temp_r3;
    TParticleCtrl *temp_r3_2;
    TParticleCtrl *temp_r3_3;
    TParticleCtrl *temp_r3_4;
    switch (m_38) {
    case 0:
        var_f2 = 25.0f;
        m_3c += var_f2;
        temp_f0 = m_3c;
        temp_f1 = m_40;
        if (temp_f0 > temp_f1) {
            m_34 = 0;
            var_f2 = temp_f1 - (temp_f0 - var_f2);
            m_38 = 1;
        }
        m_1c.x += m_28.x * var_f2;
        m_1c.y += m_28.y * var_f2;
        m_1c.z += m_28.z * var_f2;
        if (m_4c == NULL) {
            m_4c = spawn_continuous_particle_effect_with_flags(&m_1c, m_54[0], 0x40);
        }
        if ((m_44 == 3) && (m_50 == NULL)) {
            m_50 = spawn_continuous_particle_effect_with_flags(&m_1c, 0x204, 0x40);
        }
        temp_r3 = m_4c;
        if (temp_r3 != NULL) {
            temp_r3->set_position(&m_1c);
        }
        temp_r3_2 = m_50;
        if (temp_r3_2 != NULL) {
            temp_r3_2->set_position(&m_1c);
        }
        return;
    case 1:
        m_34 += 1;
        if (m_34 == 1) {
            spawn_particle_effect_with_flags(&m_1c, m_54[1], 0x40);
            temp_r3_3 = m_50;
            if (temp_r3_3 != NULL) {
                temp_r3_3->queue_destruction();
                m_50 = NULL;
            }
            temp_r3_4 = m_4c;
            if (temp_r3_4 != NULL) {
                temp_r3_4->queue_destruction();
                m_4c = NULL;
            }
            play_sound_effect(0x4003AD0C, &m_1c, 0, 0);
            TBoss8Dragon__sub_802FB220(get_enemy_entity(m_48), (saddr)&m_1c, m_44);
        }
        if (m_34 <= 2) {
            spawn_particle_effect_with_flags(&m_1c, m_54[2], 0x40);
            return;
        }
        m_38 = 2;
        return;
    case 2:
        m_34 += 1;
        if (m_34 > 0x64) {
            queue_destruction();
        }
        break;
    }
}
#pragma pop

}
TBoss8DragonEffBullet::~TBoss8DragonEffBullet() {
    if (m_50 != NULL) { m_50->queue_destruction(); m_50 = 0; }
    if (m_4c != NULL) { m_4c->queue_destruction(); m_4c = 0; }
}

TBoss8DragonEffBullet::TBoss8DragonEffBullet(TObject *parent, Vec *from, Vec *to, saddr kind, u16 owner) : TObject(parent) {
    m_name = TBoss8DragonEffBullet__name;
    VecCopy(&m_1c, from);
    VecCopy(&m_28, to);
    subtract_vector(&m_28, &m_1c);
    m_40 = normalize_vector_safe(&m_28);
    m_3c = 0.0f;
    m_34 = 0;
    m_38 = 0;
    m_44 = kind;
    m_48 = owner;
    m_4c = 0;
    m_50 = 0;
    play_sound_effect(0x4003B20B, &m_1c, 0, 0);
    switch (m_44) {
    case 1:
        m_54 = lbl_80474B68;
        break;
    case 2:
        m_54 = lbl_80474B74;
        break;
    case 3:
        m_54 = lbl_80474B80;
        break;
    }
}
