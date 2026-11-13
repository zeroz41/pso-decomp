#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/render/NinjaUtil.h"
#include "pso/enemy/TUnk_804E14E8.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/gigue/TObjEneMe1GiGue.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/enemy/gyaranzo/TObjGyaranzoMissile.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_80086B64.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D853C.h"
#include "pso/math/AngleUnits.h"

extern "C" {
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e);
extern f32 lbl_805D6844;
extern f32 lbl_805D6848;
TObjChara *find_active_entity_by_id(u16);
extern s32 local_client_id;
extern const f32 lbl_805D684C;
extern s32 lbl_805D6854;
}

TUnk_804E14E8::TUnk_804E14E8(Vec *start, u16 target_id, GiGueShotAngles *angles, s32 delay, s32 double_hit, u16 src_id)
    : TObjCollidable(tl_04) {
    Vec *target;
    this->target_id = target_id;
    this->src_id = src_id;
    this->double_hit = double_hit;
    this->start = start;
    m_e8 = 0.0f;
    push_matrix_from(identity_matrix);
    {
        Vec v = {0.0f, 0.0f, lbl_805D6844};
        rotate_matrix_y(NULL, angles->y);
        rotate_matrix_x(NULL, angles->x);
        matrix_mult_vec(NULL, &v, &vel);
    }
    pop_matrix();
    timer = delay;
    target = (Vec *)&((TObjChara *)find_entity_by_id(target_id))->m_2fc;
    {
    ParticleAngles ang;
    ang.x = 0;
    ang.y = (s32)(RADIANS_TO_ANGLE * atan2_float(target->x - start->x, target->z - start->z)) + 0x4000;
    ang.z = 0x4000 - (s32)(RADIANS_TO_ANGLE * atan2_float(target->y - start->y, vec_xz_distance(target, start)));
    ptcl0 = (TParticleCtrl *)spawn_particle_effect_with_rotation(start, &ang, 0x201, 2);
    ptcl1 = (TParticleCtrl *)spawn_particle_effect_with_rotation(start, &ang, 0x202, 2);
    }
    speed = lbl_805D6848;
    if (xz_distance_squared(target, start) < 22500.0f) {
        speed *= 2.0f;
    }
    state = 0;
}

TUnk_804E14E8::~TUnk_804E14E8() {
    if (ptcl0 != NULL) {
        ptcl0->queue_destruction();
        ptcl0 = NULL;
    }
    if (ptcl1 != NULL) {
        ptcl1->queue_destruction();
        ptcl1 = NULL;
    }
}

void TUnk_804E14E8::run_task() {
    TObjEneMe1GiGue *src;
    TObjChara *tgt;
    Vec v;
    src = (TObjEneMe1GiGue *)find_entity_by_id(src_id);
    if (src == NULL) {
        queue_destruction();
        return;
    }
    tgt = find_active_entity_by_id(target_id);
    switch (state) {
    case 0:
        timer--;
        if (timer <= 0) {
            timer = 0;
            VecCopy(&pos, start);
            state = 1;
            if (get_current_floor_area() == AREA_TOWER) {
                play_sound_effect(0x4003A313, &pos, 0, 0);
                return;
            }
            play_sound_effect(0x3A820, &pos, 0, 0);
            return;
        }
        if (ptcl0 != NULL) {
            ptcl0->enable();
        }
        if (ptcl1 != NULL) {
            ptcl1->enable();
        }
        return;
    case 1:
        timer++;
        if (timer >= 0x5A) {
            queue_destruction();
            return;
        }
        if (tgt != NULL) {
            VecCopy(&v, (Vec *)&tgt->m_2fc);
            subtract_vector(&v, &pos);
            vec_set_length(&v, speed);
            speed += lbl_805D684C;
            vec3_add_to(&vel, &v);
            vec_set_length(&vel, lbl_805D6844);
        }
        VecCopy(&prev, &pos);
        vec3_add_to(&pos, &vel);
        if (ptcl0 != NULL) {
            ptcl0->set_position(&pos);
        }
        if (ptcl1 != NULL) {
            ptcl1->set_position(&pos);
        }
        if (csnVector(&prev, &pos, -1) != 0) {
            queue_destruction();
            return;
        }
        if (tgt != NULL && !(tgt->actorFlags & 0x04000A00) &&
            xyz_distance_squared(&pos, (Vec *)&tgt->m_2fc) <= lbl_805D6844 * lbl_805D6844) {
            DirectAttackPayload hit = {1, (f32)lbl_805D6854};
            tgt->receive_direct_attack(src, hit, 0, -1, -1);
            if (double_hit == 1) {
                hit.kind = 0x12;
                tgt->receive_direct_attack(src, hit, 0, -1, -1);
            }
            spawn_particle_effect(&tgt->m_2fc, 0x8E);
            if (local_client_id == target_id) {
                src->apply_hit_shake(tgt);
            }
            queue_destruction();
        }
        break;
    }
}

