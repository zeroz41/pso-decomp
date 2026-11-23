#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecDeband.h"
#include "pso/technique/TTecLuker.h"
#include "pso/system/task/TObject_80019A50.h"

#include "pso/technique/TTecAnti.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"

#include "pso/system/task/TObject.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/TargetCursorList.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on


const char *TTecDeband::class_name = "TTecDeband";






void TTecDeband::init_params() { spawn_support_tec_range_effect(); }

void TTecDeband::update_effect_params() {
    TechniqueParams *res;
    res = calc_technique_parameters(0xA, this->level, 0xFFFF);
    params.copy(res);
    this->params.pad_00 = (f32) (this->params.pad_24 * this->level);
}

void TTecDeband::apply_to_player(TObjPlayer *player) {
    DirectAttackPayload hit;
    hit.kind = 0xA;
    hit.power = params.pad_00;
    if (player->is_script_controlled() == 0) {
        player->receive_direct_attack((void *)source, hit, 0, 0xA, -1);
        if (is_split_screen() == 0) {
            TWindowCtrl::show_party_effect(((TObjBase *)source)->get_entity_id(), player->get_entity_id(), 0xA);
        }
    }
}

void TTecDeband::create(saddr owner, saddr pos, saddr targets, s32 level) {
    new TTecDeband((void *)owner, (void *)pos, (void *)targets, level);
}
void TTecDeband::create(void *owner, void *pos, s32 level) {
    new TTecDeband(owner, pos, level);
}
void TTecDeband::render() {  }

TTecDeband::~TTecDeband() {

}

void TTecDeband::run_task() {
    uaddr member;
    s32 i;
    if (target == 0) {
        queue_destruction();
        return;
    }
    source = (uaddr)find_entity_by_id(sourceId);
    if (source == 0) {
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
                    if ((TTecLuker::is_parents_unqueued(member) != 0) && (TObjPlayer::is_valid_and_active(member) != 0)) {
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

#pragma opt_common_subs off
TTecDeband::TTecDeband(void *owner, void *pos, void *target_list, s32 level) : TTecPlayerInfluence(owner, pos, level) {
    TObjCollidable *t;
    m_name = class_name;
    use_targets = 1;
    copy_technique_target_list(&targets, (TargetCursorList *)target_list);
    update_effect_params();
    t = target;
    if (t != NULL) {
        t->bodies->radius = 5.0f + params.pad_08;
    }
    if (source != 0U) {
        sourceId = ((TObjBase *)(saddr)source)->get_entity_id();
    }
    if (show_effects != 0) {
        init_params();
        play_state_sound();
    }
}
#pragma opt_common_subs reset

TTecDeband::TTecDeband(void *owner, void *pos, s32 level) : TTecPlayerInfluence(owner, pos, level) {
    TObjCollidable *t;
    m_name = class_name;
    use_targets = 0;
    update_effect_params();
    t = target;
    if (t != NULL) {
        t->bodies->radius = 5.0f + params.pad_08;
    }
    if (source != 0U) {
        sourceId = ((TObjBase *)(saddr)source)->get_entity_id();
    }
    init_params();
    play_state_sound();
}

