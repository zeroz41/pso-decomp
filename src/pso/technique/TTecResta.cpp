#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecResta.h"
#include "pso/technique/TTecRestaEff.h"
#include "pso/unk/TUnk_804CCA90.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecReverser.h"


#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecLuker.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/TargetCursorList.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on


const char *TTecResta::class_name = "TTecResta";


struct Row_8023967C { s32 delay; s32 duration; s32 entry; u32 flags; };




extern "C" {
Row_8023967C TTecResta__self_recovery_effect_table[3] = {
    {0x14, 1, 0x2C, 0},
    {0, 1, 0x2D, 1},
    {0x14, 1, 0x2E, 0},
};
}
void TTecReverser::vfunc_6(void *arg) {
    TObjPlayer *player = (TObjPlayer *)arg;
    DirectAttackPayload hit;
    hit.kind = 8;
    hit.power = power;
    player->receive_direct_attack((void *)source, hit, 0, -1, -1);
    new TUnk_804CCA90(&player->position, 0x2D, 0x4002AD13, tl_07);
}

TTecResta::TTecResta(void *owner, void *pos, s32 level) : TTecPlayerInfluence(owner, pos, level) {
    TObjCollidable *t;
    m_name = class_name;
    use_targets = 0;
    init_parameters();
    t = target;
    if (t != NULL) {
        t->bodies->radius = 5.0f + params.pad_08;
    }
    if (source != 0U) {
        sourceId = ((TObjBase *)(saddr)source)->get_entity_id();
    }
    if (show_effects != 0) {
        init_cast();
        play_launch_sound();
    }
}

#pragma push
#pragma opt_common_subs off
TTecResta::TTecResta(void *owner, void *pos, void *target_list, s32 level) : TTecPlayerInfluence(owner, pos, level) {
    TObjCollidable *t;
    m_name = class_name;
    use_targets = 1;
    copy_technique_target_list(&targets, (TargetCursorList *)target_list);
    init_parameters();
    t = target;
    if (t != NULL) {
        t->bodies->radius = 5.0f + params.pad_08;
    }
    if (source != 0U) {
        sourceId = ((TObjBase *)(saddr)source)->get_entity_id();
    }
    if (show_effects != 0) {
        init_cast();
        play_launch_sound();
    }
}
#pragma pop

TTecResta::~TTecResta() {

}

void TTecResta::run_task() {
    uaddr member;
    s32 i;
    source = (uaddr)find_entity_by_id(sourceId);
    if (TTecLuker::is_parents_unqueued(source) == 0) {
        queue_destruction();
        return;
    }
    if (use_targets != 0) {
        if (level <= 1) {
            apply_to_player((TObjPlayer *)source);
        } else {
            apply_to_player((TObjPlayer *)source);
            if (targets.count != 0) {
                for (i = 0; i < targets.count; i++) {
                    member = (uaddr)find_entity_by_id(targets.records[i].id);
                    if (TTecLuker::is_parents_unqueued(member) != 0) {
                        apply_to_player((TObjPlayer *)member);
                    }
                }
            }
        }
    } else if (level <= 1) {
        apply_to_player((TObjPlayer *)source);
    } else {
        deliver_technique_to_party_targets();
    }
    queue_destruction();
}

void TTecResta::render() {  }

#pragma push
#pragma opt_common_subs off
void TTecResta::apply_to_player(TObjPlayer *player) {
    DirectAttackPayload hit;
    if (player->is_script_controlled() != 0) {
        return;
    }
    hit.kind = 6;
    hit.power = params.pad_00;
    if (is_split_screen() == 0) {
        TWindowCtrl::show_party_effect(((TObjBase *)source)->get_entity_id(), player->get_entity_id(), 6);
    }
    player->receive_direct_attack((void *)source, hit, 0, 0xF, -1);
    if (((TObjBase *)source)->get_entity_id() == player->get_entity_id()) {
        if (show_effects != 0) {
            new TTecRestaEff(&player->body_center, source, tl_07);
        }
    } else if (show_effects != 0) {
        TParticleCtrl *e = spawn_particle_effect_with_flags(&player->body_center, 0x1F6, 0x10);
        if (e != NULL) {
            e->set_owner_id(player->get_entity_id());
        }
        e = spawn_particle_effect_with_flags(&player->body_center, 0x1F7, 0x10);
        if (e != NULL) {
            e->set_owner_id(player->get_entity_id());
        }
    }
    if (show_effects != 0) {
        new TUnk_804CCA90(&player->body_center, 0x14, 0x4002A80F, tl_07);
    }
}
#pragma pop

void TTecResta::create(void *owner, void *pos, s32 level) {
    new TTecResta(owner, pos, level);
}

void TTecResta::create(void *source, void *origin, void *targets, s32 level) {
    new TTecResta(source, origin, targets, level);
}

#pragma push
#pragma opt_common_subs off
TTecRestaEff::TTecRestaEff(Vec *pos, s32 owner, TObject *parent) : TObject(parent) {
    Vec v;
    s32 i;
    Row_8023967C *row;
    m_timer = 0;
    for (i = 0; i < 3; i++) {
        m_emitters[i] = 0;
    }
    m_owner = owner;
    for (i = 0; i < 3; i++) {
        VecCopy(&v, pos);
        row = &TTecResta__self_recovery_effect_table[i];
        if (row->flags & 1) {
            v.y -= 5.0f;
        }
        if (i == 2) {
            m_emitters[i] = create_timed_particle_emitter_with_flags(&v, row->entry, row->delay, row->duration, 0x30);
        } else {
            m_emitters[i] = create_timed_particle_emitter_with_flags(&v, row->entry, row->delay, row->duration, 0x10);
        }
        if (m_emitters[i] != 0) {
            m_emitters[i]->set_owner_id(((TObjBase *)(saddr)(m_owner))->get_entity_id());
        }
    }
}
#pragma pop

TTecRestaEff::~TTecRestaEff() {

}

void TTecRestaEff::run_task() {
    if (m_timer++ > 180) {
        queue_destruction();
    }
}

void TTecResta::init_parameters() {
    TechniqueParams *res;
    res = calc_technique_parameters(0xF, level, 0xFFFF);
    params.copy(res);
    params.pad_00 = params.pad_00 + (f32)(params.pad_24 * level);
    if (TTecCtrl::is_technique_ready() != 0) {
        params.pad_00 *= technique_scale_table[15].power;
    }
}

f32 TTecResta::calc_heal_amount(s32 level) {
    f32 amount;
    amount = calc_technique_parameters(0xF, level, 0xFFFF)->pad_00;
    amount = amount + (f32)(level * 5);
    if (TTecCtrl::is_technique_ready() != 0) {
        amount *= technique_scale_table[15].power;
    }
    return amount;
}

void TTecResta::init_cast() { spawn_support_tec_range_effect(); }
