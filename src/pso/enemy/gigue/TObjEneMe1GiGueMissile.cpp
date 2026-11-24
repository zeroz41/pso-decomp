#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/unk/TUnk_804CCB28.h"
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
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"

#pragma readonly_strings on

BmlResource *gigue_missile_resource;
const char *TObjEneMe1GiGueMissile__name = "TObjEneMe1GiGueMissile";

void TObjEneMe1GiGueMissile::explode(void *pos) {
    TObjPlayer *p;
    s32 i;
    new TUnk_804CCB28(40.0f, (const Vec *)pos, 0, tl_07);
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p != NULL && horizontal_distance_squared(&p->position, (Vec *)pos) <= 1600.0f) {
            DirectAttackPayload hit;
            hit.kind = 0;
            hit.power = power;
            if (p->receive_direct_attack(owner, hit, NULL, -1, -1) > 0.0f) {
                p->set_actor_flags(0x600);
            }
            if (get_current_floor_area() == AREA_TOWER) {
                play_sound_effect(0x4003A312, &p->position, 0, 0);
            } else {
                play_sound_effect(0x3A81F, &p->position, 0, 0);
            }
        }
    }
}

void TObjEneMe1GiGueMissile::on_wall_hit() { explode(&pos); TObject::queue_destruction(); }

void TObjEneMe1GiGueMissile::on_target_hit(TObjCollidable *target) { explode(&target->position); TObject::queue_destruction(); }

void TObjEneMe1GiGueMissile::create(TObjBase *owner, Vec *from, Vec *to, f32 speed, f32 power) {
    new TObjEneMe1GiGueMissile(owner, from, to, speed, power);
}

TObjEneMe1GiGueMissile::~TObjEneMe1GiGueMissile() {

}

void TObjEneMe1GiGueMissile::render() {
    if (gigue_missile_resource == NULL) {
        TObject::queue_destruction();
        return;
    }
    push_matrix();
    TParticleCtrl::begin_effect_render();
    post_translate_matrix(&pos.x);
    rotate_matrix_y(NULL, rotation_y);
    rotate_matrix_x(NULL, rotation_x);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(gigue_missile_resource->models[1].texlist));
    set_motion_packed_rotation();
    draw_model_motion((void *)get_bml_model(gigue_missile_resource, 1), get_bml_motion(gigue_missile_resource, 5), motion_frame);
    clear_motion_packed_rotation();
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

#pragma push
#pragma opt_common_subs off
void TObjEneMe1GiGueMissile::run_task() {
    f32 frame;
    owner = find_entity_by_id(owner_id);
    if (owner == 0) {
        TObject::queue_destruction();
        return;
    }
    motion_frame += 1.0f;
    frame = motion_frame;
    if (frame >= 20.0f) {
        motion_frame = frame - 20.0f;
    }
    update_position();
    update_lifetime();
    check_target_hit(1);
}
#pragma pop

TObjEneMe1GiGueMissile::TObjEneMe1GiGueMissile(TObjBase *owner, Vec *from, Vec *to, f32 speed, f32 power)
    : TNeedleShoot(owner, from, to) {
    m_name = TObjEneMe1GiGueMissile__name;
    this->power = power;
    this->speed = speed;
    play_sound_effect(0x4002A600, &pos, 0, 0);
    if (this->owner != NULL) {
        owner_id = this->owner->get_entity_id();
    }
    if (collider != NULL) {
        collider->bodies->radius = 1.0f;
    }
    contact_mode = 1;
}

void TObjEneMe1GiGueMissile::free_global() {}

void TObjEneMe1GiGueMissile::init_global() { gigue_missile_resource = TObjEneMe1GiGue::get_resource(); }
