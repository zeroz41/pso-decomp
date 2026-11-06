#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/enemy/TUnk_804E14E8.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjGyaranzoMissile.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/map/FloorArea.h"
#include "pso/TMainTask.h"
#include "pso/unk/text_80086B64.h"

struct Vec_802CDEB4 { f32 x, y, z; };

struct Vec_802CDB1C { f32 x, y, z; };

extern "C" {
f32 atan2_float(f32 y, f32 x);
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e);
s32 matrix_mult_vec(void *, Vec_802CDEB4 *, void *);
s32 rotate_matrix_y(void *, s32);
s32 rotate_matrix_x(void *, s32);
s32 push_matrix_from(void *);
s32 pop_matrix();
extern u8 identity_matrix[];
extern f32 lbl_805D6844;
extern f32 lbl_805D6848;
u32 csnVector(void *, void *, s32);
void *spawn_particle_effect(void *pos, s32 id);
TObjChara *find_active_entity_by_id(u16);
s32 play_sound_effect(s32, void *, s32, s32);
s32 vec3_add_to(void *, void *);
s32 subtract_vector(void *, void *);
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
        Vec_802CDEB4 v = {0.0f, 0.0f, lbl_805D6844};
        rotate_matrix_y(0, angles->y);
        rotate_matrix_x(0, angles->x);
        matrix_mult_vec(0, &v, &vel);
    }
    pop_matrix();
    timer = delay;
    target = (Vec *)((u8 *)find_entity_by_id(target_id) + 0x2FC);
    {
    ParticleAngles ang;
    ang.x = 0;
    ang.y = (s32)(10430.38043493439 * atan2_float(target->x - start->x, target->z - start->z)) + 0x4000;
    ang.z = 0x4000 - (s32)(10430.38043493439 * atan2_float(target->y - start->y, vec_xz_distance(target, start)));
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

extern "C" {
#pragma push
#pragma opt_common_subs off
void TUnk_804E14E8::run_task() {
    u8 *src;
    TObjChara *tgt;
    Vec_802CDB1C v;
    src = (u8 *)find_entity_by_id(src_id);
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
            VecCopy((Vec *)&pos, start);
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
            VecCopy((Vec *)&v, (const Vec *)((u8 *)tgt + 0x2FC));
            subtract_vector(&v, &pos);
            vec_set_length((Vec *)&v, speed);
            speed += lbl_805D684C;
            vec3_add_to(&vel, &v);
            vec_set_length((Vec *)&vel, lbl_805D6844);
        }
        VecCopy((Vec *)&prev, (const Vec *)&pos);
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
            xyz_distance_squared((Vec *)&pos, (Vec *)((u8 *)tgt + 0x2FC)) <= lbl_805D6844 * lbl_805D6844) {
            DirectAttackPayload hit = {1, (f32)lbl_805D6854};
            tgt->receive_direct_attack(src, hit, 0, -1, -1);
            if (double_hit == 1) {
                hit.kind = 0x12;
                tgt->receive_direct_attack(src, hit, 0, -1, -1);
            }
            spawn_particle_effect((u8 *)tgt + 0x2FC, 0x8E);
            if (local_client_id == target_id) {
                ((TObjEneMe1GiGue *)src)->apply_hit_shake((u32)tgt);
            }
            queue_destruction();
        }
        break;
    }
}
#pragma pop


}
