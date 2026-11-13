#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/enemy/gee/TObjEneMe1Gee_NEEDLE.h"
#include "pso/enemy/gee/TObjEneMe1Gee.h"
#include "pso/enemy/TNeedleShoot.h"
#include "pso/enemy/TNeedleShoot_802A4668.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/BmlResource.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/map/FloorArea.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/enemy/gigue/TObjEneMe1GiGueMissile.h"

extern "C" {
s32 TObjPlayer__sub_802A445C(void *, s32);
u8 *TNeedleShoot__ct(void *, s32, void *, void *);
}

void *TNeedleShoot::get_shoot_data() { return unk_28; }

int TObjEneMe1Gee_NEEDLE::queue_destruction() {
    s32 remaining;
    remaining = m_c0 - 1;
    m_c0 = remaining;
    if (remaining <= 0) {
        queue_destruction__7TObjectFv(this);
    }
}

int TObjEneMe1Gee_NEEDLE::vfunc_6() {
    if (get_current_floor_area() == AREA_SEASIDE_NIGHT) {
        play_sound_effect(0x4003B20E, &m_6c, 0, 0);
    } else {
        play_sound_effect(0x3A847, &m_6c, 0, 0);
    }
    m_b8 = 0;
}

void TObjEneMe1Gee_NEEDLE::vfunc_9(void *arg) {
    TObjChara *target = (TObjChara *)arg;
    DirectAttackPayload attack;
    attack.kind = 0;
    attack.power = m_bc;
    DirectAttackPayload payload = attack;
    target->receive_direct_attack((void *)m_1c, payload, m_38, -1, -1);
    queue_destruction__7TObjectFv(this);
}

TObjEneMe1Gee_NEEDLE::~TObjEneMe1Gee_NEEDLE() {
}

#pragma readonly_strings on

extern "C" {
const char *TObjEneMe1Gee_NEEDLE__name = "TObjEneMe1Gee_NEEDLE";
BmlResource *me1gee_cached_model_handle;
}

struct RecoveredGlobal_802A4CC4_lbl_804DCFF8 {
    s32 value;
    u8 remaining[0x24];
};

extern "C" RecoveredGlobal_802A4CC4_lbl_804DCFF8 __vt__20TObjEneMe1Gee_NEEDLE;

void TObjEneMe1Gee_NEEDLE::render() {
    if (me1gee_cached_model_handle == NULL) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    push_matrix();
    TParticleCtrl::begin_effect_render();
    post_translate_matrix((const f32 *)&m_6c);
    rotate_matrix_y(NULL, m_a4);
    rotate_matrix_x(NULL, m_a0);
    TObjFish::set_global_param(TObjFish__sub_8001EDB0(me1gee_cached_model_handle, 1));
    draw_ginja_object((void *)get_bml_model(me1gee_cached_model_handle, 1));
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TObjEneMe1Gee_NEEDLE::run_task() {
    m_1c = (u32)find_entity_by_id(m_34);
    if (m_1c == 0) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    if ((s32)m_b8 == 1) {
        update_position();
        ((TObjEneMe1GiGueMissile *)this)->update_lifetime();
        TObjPlayer__sub_802A445C(this, 1);
        return;
    }
    TNeedleShoot__sub_802A4668(this);
}

extern "C" {
TObjEneMe1Gee_NEEDLE *TObjEneMe1Gee_NEEDLE__ct(TObjEneMe1Gee_NEEDLE *self, TObject *owner, Vec *from, Vec *to, f32 farg0,
                                               f32 power) {
    TNeedleShoot__ct(self, (s32)owner, from, to);
    *(s32 **)((u8 *)self + 0x18) = &__vt__20TObjEneMe1Gee_NEEDLE.value;
    self->m_name = TObjEneMe1Gee_NEEDLE__name;
    self->m_bc = power;
    *(f32 *)((u8 *)self + 0xAC) = farg0;
    self->m_c0 = 150;
    self->m_b0 = 1;
    if ((void *)self->m_1c != NULL) {
        self->m_34 = get_entity_id((TObjBase *)self->m_1c);
    }
    return self;
}

void TObjEneMe1Gee__sub_802A4D4C(void) {
}

}

void TObjEneMe1Gee::cache_result_805D6660() {
    me1gee_cached_model_handle = TObjEneMe1Gee::sub_800CC2BC();
}
