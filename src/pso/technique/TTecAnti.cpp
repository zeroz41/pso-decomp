#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/technique/TTecAnti.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecLuker.h"
#include "pso/technique/TTecAntiEff.h"
#include "pso/unk/TUnk_804CCA90.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"


#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/TargetCursorList.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on


const char *TTecAnti::class_name = "TTecAnti";



#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct AntiRow_8022AE10 { s32 a; s32 b; s32 c; s32 flags; };



extern "C" {
AntiRow_8022AE10 TTecAnti__self_effect_rows[4] = {
    {0xF, 1, 0x30, 0},
    {0xF, 1, 0x32, 0},
    {0, 0xF, 0x31, 1},
    {0xA, 1, 0x1EC, 1},
};
}
void TTecAnti::render() {  }

TargetCursorList *copy_technique_target_list(TargetCursorList *d, TargetCursorList *s) {
    *d = *s;
    return d;
}

void TechniqueParams::copy(TechniqueParams *src) {
    pad_00 = src->pad_00;
    pad_04 = src->pad_04;
    pad_08 = src->pad_08;
    pad_0C = src->pad_0C;
    tp_cost = src->tp_cost;
    pad_12 = src->pad_12;
    pad_14 = src->pad_14;
    pad_16 = src->pad_16;
    pad_18 = src->pad_18;
    pad_1C = src->pad_1C;
    pad_20 = src->pad_20;
    pad_22 = src->pad_22;
    tp_cost_percent = src->tp_cost_percent;
    pad_24 = src->pad_24;
    pad_26 = src->pad_26;
    pad_28 = src->pad_28;
    pad_2A = src->pad_2A;
}

TTecAnti::TTecAnti(void *owner, void *pos, void *target_list, s32 level) : TTecPlayerInfluence(owner, pos, level) {
    TObjCollidable *t;
    m_name = class_name;
    use_targets = 1;
    copy_technique_target_list(&targets, (TargetCursorList *)target_list);
    params.copy(&technique_param_table[16]);
    setup_params();
    t = target;
    if (t != NULL) {
        t->bodies->radius = 5.0f + params.pad_08;
    }
    if (source != 0U) {
        sourceId = ((TObjBase *)(saddr)source)->get_entity_id();
    }
    if (show_effects != 0) {
        play_anti_cast_sound();
        spawn_anti_range_effect();
    }
}

void TTecAnti::run_task() {
    uaddr member;
    s32 i;
    source = (uaddr)find_entity_by_id(sourceId);
    if (source == 0) {
        queue_destruction();
        return;
    }
    if (use_targets != 0) {
        if (level == 0) {
            apply_to_player((TObjPlayer *)source);
        } else {
            apply_to_player((TObjPlayer *)source);
            if (targets.count != 0) {
                for (i = 0; i < targets.count; i++) {
                    member = (uaddr)find_entity_by_id(targets.records[i].id);
                    if ((TTecLuker::is_parents_unqueued(member) != 0) && (TObjPlayer::is_valid_and_active(member) != 0)) {
                        apply_to_player((TObjPlayer *)member);
                    }
                }
            }
        }
    } else if (level == 0) {
        apply_to_player((TObjPlayer *)source);
    } else {
        deliver_technique_to_party_targets();
    }
    queue_destruction();
}

TTecAnti::~TTecAnti() {

}

void TTecAnti::create(void *source, void *origin, void *targets, s32 level) {
    new TTecAnti(source, origin, targets, level);
}

void TTecAnti::apply_to_player(TObjPlayer *player) {
    DirectAttackPayload hit;
    TParticleCtrl *o;
    hit.kind = 7;
    hit.power = params.pad_00;
    if (player->is_script_controlled() != 0) {
        return;
    }
    player->receive_direct_attack((void *)source, hit, 0, 0x10, level);
    if (is_split_screen() == 0) {
        TWindowCtrl::show_party_effect(((TObjBase *)source)->get_entity_id(), player->get_entity_id(), 7);
    }
    if (((TObjBase *)source)->get_entity_id() == player->get_entity_id()) {
        if (show_effects != 0) {
            new TTecAntiEff(&player->body_center, &player->position, player->get_entity_id(), tl_07);
        }
    } else if (show_effects != 0) {
        o = spawn_particle_effect_with_flags(&player->body_center, 0x1F8, 0x10);
        if (o != NULL) {
            o->set_owner_id(player->get_entity_id());
        }
        o = spawn_particle_effect_with_flags(&player->body_center, 0x1FF, 0x10);
        if (o != NULL) {
            o->set_owner_id(player->get_entity_id());
        }
    }
    if (show_effects != 0) {
        new TUnk_804CCA90(&player->body_center, 0xF, 0x4002AD11, tl_07);
    }
}

TTecAntiEff::TTecAntiEff(Vec *body_pos, Vec *ground_pos, u16 owner_id, TObject *parent) : TObject(parent) {
    s32 i;
    VecCopy(&m_body_pos, body_pos);
    VecCopy(&m_ground_pos, ground_pos);
    for (i = 0; i < 4; i++) {
        AntiRow_8022AE10 *row = &TTecAnti__self_effect_rows[i];
        TParticleCtrl *p;
        if (row->flags & 1) {
            p = create_timed_particle_emitter_with_flags(&m_ground_pos, row->c, row->a, row->b, 0x10);
            if (p != NULL) {
                p->set_owner_id(owner_id);
            }
        } else {
            p = create_timed_particle_emitter_with_flags(&m_body_pos, row->c, row->a, row->b, 0x10);
            if (p != NULL) {
                p->set_owner_id(owner_id);
            }
        }
    }
}

TTecAntiEff::~TTecAntiEff() {

}

void TTecAntiEff::run_task() { queue_destruction(); }

void TTecAnti::setup_params() {  }

void TTecAnti::spawn_anti_range_effect() { spawn_support_tec_range_effect(); }

void TTecAnti::play_anti_cast_sound() {
    s32 r;
    switch (band) {
    case 0:
    case 1:
        r = play_sound_effect(0x4002AB10, &position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002AB10, &position, 0, 0);
        break;
    case 4:
    case 5:
        r = play_sound_effect(0x4002AB10, &position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, -0x100, 0);
        }
        break;
    }
}
