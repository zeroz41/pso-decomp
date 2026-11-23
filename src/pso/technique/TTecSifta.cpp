#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecSifta.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/technique/TTecShot.h"

#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecLuker.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"

#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/TargetCursorList.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on


const char *TTecSifta::class_name = "TTecSifta";







void TTecSifta::spawn_sifta_range_effect() { spawn_support_tec_range_effect(); }

void TTecSifta::play_sifta_cast_sound() {
    s32 r;
    switch (band) {
    case 0:
    case 1:
        r = play_sound_effect(0x4002AD14, &position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002AD14, &position, 0, 0);
        break;
    case 4:
    case 5:
        r = play_sound_effect(0x4002AD14, &position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, -0x100, 0);
        }
        break;
    }
}

void TTecSifta::update_effect_params() {
    TechniqueParams *res;
    res = calc_technique_parameters(0xD, this->level, 0xFFFF);
    params.copy(res);
    this->params.pad_00 = (f32) (this->params.pad_24 * this->level);
}

void TTecSifta::create_instance(void *source, void *origin, void *targets, s32 level) {
    new TTecSifta(source, origin, targets, level);
}

void TTecSifta::create(void *owner, void *pos, s32 level) {
    new TTecSifta(owner, pos, level);
}

void TTecSifta::apply_to_player(TObjPlayer *player) {
    DirectAttackPayload hit;
    if (player->is_script_controlled() == 0) {
        hit.kind = 9;
        hit.power = params.pad_00;
        if (is_split_screen() == 0) {
            TWindowCtrl::show_party_effect(((TObjBase *)source)->get_entity_id(), player->get_entity_id(), 9);
        }
        player->receive_direct_attack((void *)source, hit, 0, 0xD, -1);
    }
}

TTecSifta::~TTecSifta() {

}


void TTecSifta::run_task() {
    uaddr member;
    s32 i;
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

#pragma push
#pragma opt_common_subs off
TTecSifta::TTecSifta(void *owner, void *pos, void *target_list, s32 level) : TTecPlayerInfluence(owner, pos, level) {
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
        spawn_sifta_range_effect();
        play_sifta_cast_sound();
    }
}
#pragma pop

TTecSifta::TTecSifta(void *owner, void *pos, s32 level) : TTecPlayerInfluence(owner, pos, level) {
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
    spawn_sifta_range_effect();
    play_sifta_cast_sound();
}

void TTecSifta::render() {  }

