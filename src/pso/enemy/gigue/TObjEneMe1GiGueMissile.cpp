#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/enemy/gigue/TObjEneMe1GiGueMissile.h"
#include "pso/enemy/gigue/TObjEneMe1GiGue.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/TNeedleShoot.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/render/render_util.h"
#include "pso/object/base/TObjChara.h"

extern "C" {
BmlResource *lbl_805D6858;
u16 get_entity_id(void *);
void *TNeedleShoot__ct(void *, s32, Vec *, Vec *);
extern void *__vt__22TObjEneMe1GiGueMissile[];
extern const char *lbl_805D3F20;
TObjEneMe1GiGueMissile *TObjEneMe1GiGueMissile__ct(TObjEneMe1GiGueMissile *self, s32 owner, Vec *from, Vec *to, f32 speed, f32 power);
s32 TObjPlayer__sub_802A445C(void *, int);
void TObjEneMe1GiGue__sub_802CE4E8(void);
void TObjEneMe1GiGue__sub_802CE4EC(void);
void obj_setFlags30(void *, int);
void create_fire_explosion_effect(void *, f32, void *, int, void *);
extern void *tl_07;

void TObjEneMe1GiGueMissile::explode(void *pos) {
    void *fx;
    TObjPlayer *p;
    s32 i;
    fx = TObject::operator new(0x64);
    if (fx != NULL) {
        create_fire_explosion_effect(fx, 40.0f, pos, 0, tl_07);
    }
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p != NULL && horizontal_distance_squared(&p->position, (Vec *)pos) <= 1600.0f) {
            DirectAttackPayload hit;
            hit.kind = 0;
            hit.power = m_c0;
            if (p->receive_direct_attack((void *)m_1c, hit, NULL, -1, -1) > 0.0f) {
                obj_setFlags30(p, 0x600);
            }
            if (get_current_floor_area() == AREA_TOWER) {
                play_sound_effect(0x4003A312, &p->position, 0, 0);
            } else {
                play_sound_effect(0x3A81F, &p->position, 0, 0);
            }
        }
    }
}

int TObjEneMe1GiGueMissile::vfunc_6() { explode(&pos); TObject::queue_destruction(); }

void TObjEneMe1GiGueMissile::vfunc_9(void *a1) { explode(&((TObjBase *)a1)->position); TObject::queue_destruction(); }

void TObjEneMe1GiGueMissile::create(s32 owner, s32 from, s32 to, f32 speed, f32 power) {
    void *o = TObject::operator new(0xC4);
    if (o != NULL) {
        TObjEneMe1GiGueMissile__ct((TObjEneMe1GiGueMissile *)o, owner, (Vec *)from, (Vec *)to, speed, power);
    }
}

}
TObjEneMe1GiGueMissile::~TObjEneMe1GiGueMissile() {

}

void TObjEneMe1GiGueMissile::render() {
    if (lbl_805D6858 == NULL) {
        TObject::queue_destruction();
        return;
    }
    push_matrix();
    TParticleCtrl::begin_effect_render();
    post_translate_matrix(&pos.x);
    rotate_matrix_y(NULL, m_a4);
    rotate_matrix_x(NULL, m_a0);
    TObjFish::set_global_param(lbl_805D6858->models[1].m_c);
    set_motion_packed_rotation();
    draw_model_motion((void *)get_bml_model(lbl_805D6858, 1), get_bml_motion(lbl_805D6858, 5), m_bc);
    clear_motion_packed_rotation();
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

#pragma push
#pragma opt_common_subs off
void TObjEneMe1GiGueMissile::run_task() {
    f32 frame;
    m_1c = (u32)find_entity_by_id(m_34);
    if (m_1c == 0) {
        TObject::queue_destruction();
        return;
    }
    m_bc += 1.0f;
    frame = m_bc;
    if (frame >= 20.0f) {
        m_bc = frame - 20.0f;
    }
    update_position();
    update_lifetime();
    TObjPlayer__sub_802A445C(this, 1);
}
#pragma pop

TObjEneMe1GiGueMissile *TObjEneMe1GiGueMissile__ct(TObjEneMe1GiGueMissile *self, s32 owner, Vec *from, Vec *to, f32 speed, f32 power) {
    TObjCollidable *target;
    TNeedleShoot__ct(self, owner, from, to);
    *(void ***)((s8 *)self + 0x18) = __vt__22TObjEneMe1GiGueMissile;
    self->m_name = lbl_805D3F20;
    self->m_c0 = power;
    *(f32 *)self->_padAC = speed;
    play_sound_effect(0x4002A600, &self->pos, 0, 0);
    if ((void *)self->m_1c != NULL) {
        self->m_34 = get_entity_id((void *)self->m_1c);
    }
    target = (TObjCollidable *)self->m_68;
    if (target != NULL) {
        target->bodies->radius = 1.0f;
    }
    self->m_b0 = 1;
    return self;
}

void TObjEneMe1GiGue__sub_802CE4E8(void) {  }

void TObjEneMe1GiGue__sub_802CE4EC(void) { lbl_805D6858 = TObjEneMe1GiGue::sub_802CAC80(); }
