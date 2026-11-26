#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/technique/TTecReverser.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecReverserEff.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecCircle.h"
#include "pso/technique/TTecShot.h"

#include "pso/enemy/gibon/TObjEneBm5GibonU.h"

#include "pso/technique/TTecAnti.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TechniqueContact.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/render/DebugFont.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/TargetCursorList.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on

// A particle emitter of the revival effect: it starts after `delay` frames, `count` times.
struct RevivalEmitter { s32 delay; s32 count; s32 id; s32 pad; };

const char *lbl_805D3818 = "TTecReverser";
RevivalEmitter revival_particle_table[3] = {
    {0, 0x1E, 0x35, 0},
    {0x23, 1, 0x36, 0},
    {0x2D, 1, 0x37, 0},
};

void TTecShot::debug_print_tech_params() {
    debug_printf_at(0x1E0014, "POWER  : %f", params.power);
    debug_printf_at(0x1E0015, "USE_TP : %d", params.tp_cost);
    debug_printf_at(0x1E0016, "CH_SPD : %d", params.charge_speed);
    debug_printf_at(0x1E0017, "SPEED  : %f", params.speed);
    debug_printf_at(0x1E0018, "SCOPE  : %f", params.range);
    debug_printf_at(0x1E0019, "MENTAL  : %f", params.mental);
}

void TTecShot::dispatch_all_technique_contacts() {
    TechniqueContactList *list;
    s32 i;
    if (collidable == NULL) {
        queue_destruction();
        return;
    }
    if ((u16) source->get_entity_id() < 4U) {
        if (((TObjPlayer *)source)->pk_state.is_enabled() != 0) {
            list = query_technique_player_contacts(source);
        } else {
            list = query_technique_enemy_contacts(source);
        }
    } else {
        list = query_technique_player_contacts(source);
    }
    if (list == NULL) {
        this->vfunc_6();
        queue_destruction();
        return;
    }
    for (i = 0; i < list->count; i++) {
        if (TObjPlayer::is_valid_and_active(list->actors[i]) != 0) {
            TObjChara *p = (TObjChara *) list->actors[i];
            if (p != NULL) {
                contact = list->bodies[i];
                this->apply_to_target(p);
            }
        }
    }
}

void TTecShot::dispatch_technique_contact(s32) {
    TechniqueContactList *list;
    if (collidable == NULL) {
        queue_destruction();
        return;
    }
    if ((u16) source->get_entity_id() < 4U) {
        if (((TObjPlayer *)source)->pk_state.is_enabled() != 0) {
            list = query_technique_player_contacts(source);
        } else {
            list = query_technique_enemy_contacts(source);
        }
    } else {
        list = query_technique_player_contacts(source);
    }
    if (list == NULL) {
        this->vfunc_6();
        queue_destruction();
        return;
    }
    if (TObjPlayer::is_valid_and_active(list->actors[0]) != 0) {
        TObjChara *p = (TObjChara *) list->actors[0];
        if (p != NULL) {
            contact = list->bodies[0];
            this->apply_to_target(p);
        }
    }
}

TTecReverser::TTecReverser(TObjBase *owner, Vec *origin, TargetCursorList *targets, s32 level) : TTecCircle(owner, origin, level) {
    this->m_name = lbl_805D3818;
    this->params.copy(&technique_param_table[17]);
    this->apply_params(&this->params, level);
    copy_technique_target_list(&this->targets, targets);
    play_sound_effect(0x4002A812, &position, 0, 0);
    if (this->source != NULL) {
        this->sourceId = this->source->get_entity_id();
    }
}

TTecReverser::~TTecReverser() {

}

void TTecReverser::create(TObjBase *source, Vec *origin, TargetCursorList *targets, s32 level) {
    new TTecReverser(source, origin, targets, level);
}

void TTecReverser::run_task() {
    TObjCollidable *entity;
    source = find_entity_by_id(sourceId);
    if (source == NULL) {
        queue_destruction();
        return;
    }
    if (targets.count == 0) {
        queue_destruction();
        return;
    }
    entity = find_entity_by_id(targets.records[0].id);
    if ((entity->is_active() == 0) && (TObjPlayer::is_valid_and_active(entity) != 0)) {
        apply_to_target((TObjChara *)entity);
    }
    queue_destruction();
}

void TTecReverser::render() {  }

TTecReverserEff::TTecReverserEff(TObjChara *chara, TObject *parent) : TObject(parent) {
    s32 i;
    m_timer = 0;
    VecCopy(&m_pos, &chara->body_center);
    for (i = 0; i < 3; i++) {
        if (i == 0) {
            Vec v;
            VecCopy(&v, &m_pos);
            v.y += 20.0f;
            m_emitters[i] = create_timed_particle_emitter(&v, revival_particle_table[i].id, revival_particle_table[i].delay, revival_particle_table[i].count);
        } else {
            m_emitters[i] = create_timed_particle_emitter(&m_pos, revival_particle_table[i].id, revival_particle_table[i].delay, revival_particle_table[i].count);
        }
    }
}

void TTecReverserEff::run_task() {
    m_timer = m_timer + 1;
    if (m_timer == 10) {
        spawn_particle_effect(&m_pos, 0x38);
    }
    if (m_timer > 200) {
        queue_destruction();
    }
}

TTecReverserEff::~TTecReverserEff() {

}
