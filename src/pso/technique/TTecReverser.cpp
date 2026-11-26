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
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/TargetCursorList.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on

struct Entry_80239E44 { s32 a; s32 b; s32 c; s32 pad; };


struct List_8023A244 { uaddr objs[16]; s32 vals[16]; s32 count; };

extern "C" {
const char *lbl_805D3818 = "TTecReverser";
Entry_80239E44 revival_particle_table[3] = {
    {0, 0x1E, 0x35, 0},
    {0x23, 1, 0x36, 0},
    {0x2D, 1, 0x37, 0},
};

}

void TTecShot::debug_print_tech_params() {
    debug_printf_at(0x1E0014, "POWER  : %f", params.power);
    debug_printf_at(0x1E0015, "USE_TP : %d", params.tp_cost);
    debug_printf_at(0x1E0016, "CH_SPD : %d", params.charge_speed);
    debug_printf_at(0x1E0017, "SPEED  : %f", params.speed);
    debug_printf_at(0x1E0018, "SCOPE  : %f", params.range);
    debug_printf_at(0x1E0019, "MENTAL  : %f", params.mental);
}

void TTecShot::dispatch_all_technique_contacts() {
    List_8023A244 *list;
    s32 i;
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x128) == 0U) {
        queue_destruction();
        return;
    }
    if ((u16) ((TObjBase *)((saddr)(*(s32 *)((s8 *)((u8 *)this) + 0x1C))))->get_entity_id() < 4U) {
        if (((TObjPlayer *)*(saddr *)((s8 *)((u8 *)this) + 0x1C))->pk_state.is_enabled() != 0) {
            list = (List_8023A244 *) query_technique_player_contacts(*(s32 *)((s8 *)((u8 *)this) + 0x1C));
        } else {
            list = (List_8023A244 *) query_technique_enemy_contacts(*(s32 *)((s8 *)((u8 *)this) + 0x1C));
        }
    } else {
        list = (List_8023A244 *) query_technique_player_contacts(*(s32 *)((s8 *)((u8 *)this) + 0x1C));
    }
    if (list == NULL) {
        this->vfunc_6();
        queue_destruction();
        return;
    }
    for (i = 0; i < list->count; i++) {
        if (TObjPlayer::is_valid_and_active((int) list->objs[i]) != 0) {
            TObjChara *p = (TObjChara *) list->objs[i];
            if (p != NULL) {
                *(s32 *)((s8 *)((u8 *)this) + 0xF8) = list->vals[i];
                this->apply_to_target(p);
            }
        }
    }
}

void TTecShot::dispatch_technique_contact(s32) {
    u8 *var_r31;
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x128) == 0U) {
        queue_destruction();
        return;
    }
    if ((u16) ((TObjBase *)((saddr)(*(s32 *)((s8 *)((u8 *)this) + 0x1C))))->get_entity_id() < 4U) {
        if (((TObjPlayer *)*(saddr *)((s8 *)((u8 *)this) + 0x1C))->pk_state.is_enabled() != 0) {
            var_r31 = query_technique_player_contacts(*(s32 *)((s8 *)((u8 *)this) + 0x1C));
        } else {
            var_r31 = query_technique_enemy_contacts(*(s32 *)((s8 *)((u8 *)this) + 0x1C));
        }
    } else {
        var_r31 = query_technique_player_contacts(*(s32 *)((s8 *)((u8 *)this) + 0x1C));
    }
    if (var_r31 == NULL) {
        this->vfunc_6();
        queue_destruction();
        return;
    }
    if (TObjPlayer::is_valid_and_active((int) (*(u32 *)((s8 *)var_r31 + 0))) != 0) {
        TObjChara *p = *(TObjChara **)((s8 *)var_r31 + 0);
        if (p != NULL) {
            *(s32 *)((s8 *)((u8 *)this) + 0xF8) = (s32) *(s32 *)((s8 *)var_r31 + 0x40);
            this->apply_to_target(p);
        }
    }
}

#define tec_reverser ((u8 *)this)
TTecReverser::TTecReverser(saddr arg1, saddr origin, saddr targets, saddr level) : TTecCircle(arg1, origin, level) {
    ((TTecReverser *)tec_reverser)->m_name = lbl_805D3818;
    ((TechniqueParams *)(tec_reverser + 0x88))->copy(&technique_param_table[17]);
    ((TTecReverser *)tec_reverser)->apply_params((TechniqueParams *)(tec_reverser + 0x88), level);
    copy_technique_target_list(&((TTecReverser *)tec_reverser)->targets, (TargetCursorList *)targets);
    play_sound_effect(0x4002A812, &position, 0, 0);
    if (((TTecReverser *)tec_reverser)->source != 0U) {
        ((TTecReverser *)tec_reverser)->sourceId = ((TObjBase *)(saddr)((TTecReverser *)tec_reverser)->source)->get_entity_id();
    }
}
#undef tec_reverser

TTecReverser::~TTecReverser() {

}

void TTecReverser::create(void *source, void *origin, void *targets, s32 level) {
    new TTecReverser((saddr)source, (saddr)origin, (saddr)targets, level);
}

void TTecReverser::run_task() {
    uaddr entity;
    source = (uaddr)find_entity_by_id(sourceId);
    if (source == 0) {
        queue_destruction();
        return;
    }
    if (targets.count == 0) {
        queue_destruction();
        return;
    }
    entity = (uaddr)find_entity_by_id(targets.records[0].id);
    if ((((TObjBase *)entity)->is_active() == 0) && (TObjPlayer::is_valid_and_active(entity) != 0)) {
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
            m_emitters[i] = create_timed_particle_emitter(&v, revival_particle_table[i].c, revival_particle_table[i].a, revival_particle_table[i].b);
        } else {
            m_emitters[i] = create_timed_particle_emitter(&m_pos, revival_particle_table[i].c, revival_particle_table[i].a, revival_particle_table[i].b);
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
