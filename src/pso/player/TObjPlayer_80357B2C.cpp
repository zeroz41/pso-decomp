#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlAccessors.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/unk/TUnk_804CCB28.h"
#include "types.h"
#include <stdlib.h>
#include "pso/system/vector.h"
#include "pso/technique/TTecZonde.h"
#include "pso/technique/TTecZondeEff.h"
#include "pso/player/TObjPlayer.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TUnk_804F166C.h"
#include "pso/map/FloorArea.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/math/AngleLookup.h"

#include <stddef.h>
#include "pso/ui/hud/TNowLoading.h"
#include "pso/item/TItem.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/TObjBase.h"

struct InwardOrbitDir { s32 x, y, z; };

static const Vec lbl_804793D8 = {0.0f, -1.0f, 0.0f};
static const InwardOrbitDir lbl_804793E4 = {0, 0, 0x4000};


struct Strike_80357B2C {
    Vec pos;
    Vec dir;
    f32 len;
};


extern "C" {
void dispatch_weapon_special_effect(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase);
f32 vector_length(void *);

}
void spawn_scattered_lightning_strikes(u8 *arg0, s32 arg1);
#pragma push
#pragma fp_contract on
void spawn_scattered_lightning_strikes(u8 *arg0, s32 arg1) {
    Vec *p = (Vec *)arg0;
    Strike_80357B2C strikes[14];
    Strike_80357B2C *s;
    Vec *d;
    s32 i;
    f32 scale;
    s32 j;
    s32 k;
    s32 m;
    for (i = 0; i < 14; i++) {
        s = &strikes[i];
        s->pos.y = 100.0f + p->y;
        if (arg1 == 5 && i == 0) {
            s->pos.y = 500.0f + p->y;
        }
        s->pos.x = 13.0f * ((f32) i * (3.0517578e-05f * (f32) rand())) + p->x;
        s->pos.z = 13.0f * ((f32) i * (3.0517578e-05f * (f32) rand())) + p->z;
        d = &s->dir;
        s->dir.x = p->x - s->pos.x;
        s->dir.y = p->y - s->pos.y;
        s->dir.z = p->z - s->pos.z;
        s->len = vector_length(d);
        if (0.0f != s->len) {
            normalize_vector(d);
        }
    }
    scale = 0.5f;
    switch (arg1) {
    case 0:
        new TTecZondeEff((TObject *)tl_07, &strikes[0].pos, &strikes[0].dir, 0x14000000, 0x14, strikes[0].len, 0.5f);
        break;
    case 1:
        scale *= 1.2f;
        new TTecZondeEff((TObject *)tl_07, &strikes[0].pos, &strikes[0].dir, 0x14000000, 0x14, strikes[0].len, (f32)scale);
        break;
    case 2:
        scale *= 1.4f;
        new TTecZondeEff((TObject *)tl_07, &strikes[0].pos, &strikes[0].dir, 0x14000000, 0x14, strikes[0].len, (f32)scale);
        break;
    case 3:
        for (j = 0; j < 3; j++) {
            new TTecZondeEff((TObject *)tl_07, &strikes[j].pos, &strikes[j].dir, 0x14000000, 0x14, strikes[j].len, 0.5f);
        }
        break;
    case 4:
        scale *= 1.4f;
        for (k = 0; k < 3; k++) {
            new TTecZondeEff((TObject *)tl_07, &strikes[k].pos, &strikes[k].dir, 0x14000000, 0x14, strikes[k].len, (f32)scale);
        }
        break;
    case 5:
        for (m = 0; m < 14; m++) {
            if (m == 0) {
                new TTecZondeEff((TObject *)tl_07, &strikes[m].pos, &strikes[m].dir, 0x14000000, 0x14, strikes[m].len, 5.0f);
            } else {
                new TTecZondeEff((TObject *)tl_07, &strikes[m].pos, &strikes[m].dir, 0x14000000, 0x14, strikes[m].len, 0.5f);
            }
        }
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on

void TUnk_804F166C::update_inward_orbit_point() {
    point.x = radius * sin_table_lookup(angle) + center.x;
    point.y = center.y;
    point.z = radius * cos_table_lookup(angle) + center.z;
}
#pragma pop

void TUnk_804F166C::render() {  }

void TUnk_804F166C::run_task() {
    angle -= 0x1999;
    radius -= 4.0f;
    update_inward_orbit_point();
    if (particle != NULL) {
        particle->set_position(&point);
    }
    if (frames_left > 0) {
        frames_left--;
        return;
    }
    queue_destruction();
}

TUnk_804F166C::~TUnk_804F166C() {
    if (particle != NULL) {
        particle->queue_destruction();
    }
}

#pragma push
#pragma fp_contract on
TUnk_804F166C::TUnk_804F166C(TObject *parent, Vec *pos, s32 start_angle) : TObject(parent) {
    VecCopy(&origin, pos);
    center.x = 5.0f * sin_table_lookup(start_angle) + pos->x;
    center.y = pos->y;
    center.z = 5.0f * cos_table_lookup(start_angle) + pos->z;
    radius = 40.0f;
    angle = start_angle - 0x4000;
    frames_left = 10;
    update_inward_orbit_point();
    InwardOrbitDir dir = lbl_804793E4;
    particle = (TParticleCtrl *)spawn_continuous_particle_with_direction(&point, &dir, 10);
}
#pragma pop

void TObjPlayer::update_battle_control_on_unlock(void *player, void *target, void *pos, s32 phase) {
    if (phase == 0) {
        ((TObjPlayer *)player)->update_battle_control_if_unlocked();
    }
}

// The weapon special effects: dispatch_weapon_special_effect calls one with phase 0 on the
// attacker and phase 1 at the hit position (see weapon_special_effect_callbacks below).
typedef void (*WeaponSpecialEffect)(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase);

void handle_exp_steal_effect(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    if (phase == 0) {
        player->update_battle_control_if_unlocked();
    }
    if (phase == 1) {
        spawn_particle_effect(&player->body_center, 0xA8);
    }
}


void handle_action(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    if (phase == 0) {
        player->update_battle_control_if_unlocked();
    }
    if (phase == 1) {
        TParticleCtrl *particle = (TParticleCtrl *)spawn_particle_effect(&player->body_center, 0xA8);
        if (particle != NULL) {
            particle->set_scale(0.2f, 0.3f);
        }
    }
}

void dispatch_effect_by_type(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    if (phase == 0) {
        player->update_battle_control_if_unlocked();
    }
    if (phase == 1) {
        spawn_particle_effect(&player->body_center, 0x10A);
    }
}

void weapon_fractional_hp_effect(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    if (phase == 0) {
        player->update_battle_control_if_unlocked();
    }
    if (phase == 1) {
        spawn_particle_effect(pos, 0x1AC);
    }
}

void handle_symbol_chat_action(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    if (phase == 0) {
        player->update_battle_control_if_unlocked();
    }
    if (phase == 1) {
        TParticleCtrl *particle = (TParticleCtrl *)spawn_particle_effect(&player->body_center, 0x67);
        if (particle != NULL) {
            particle->set_scale(0.2f, 0.3f);
        }
    }
}

void handle_action_by_type(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    if (phase == 0) {
        player->update_battle_control_if_unlocked();
    }
    if (phase == 1) {
        spawn_particle_effect(&player->body_center, 0x67);
    }
}

void handle_stage_event(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    if (phase == 0) {
        player->update_battle_control_if_unlocked();
    }
    if (phase == 1) {
        spawn_particle_effect(&player->body_center, 0x66);
    }
}

void trigger_biter_effect(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    Vec node;

    if (phase == 0) {
        player->get_anim_node_position(0x30, &node);
        spawn_particle_effect(&node, 0x1AB);
    }
}

void prepare_shock_special_effect(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    Vec node;

    if (phase == 0) {
        player->get_anim_node_position(0x30, &node);
        spawn_particle_effect(&node, 0x1AA);
    }
}


void weapon_hell_effect(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    if (phase == 0) {
        spawn_particle_effect(&player->body_center, 0xC6);
        spawn_particle_effect(&player->body_center, 0xC9);
    }
    if (phase == 1) {
        {
            TParticleCtrl *particle = spawn_particle_effect(pos, 0x1C5);
            if (particle != NULL) {
                particle->set_scale(2.0f, 2.0f);
            }
        }
        {
            TParticleCtrl *particle = spawn_particle_effect(pos, 0x1C8);
            if (particle != NULL) {
                particle->set_scale(2.0f, 2.0f);
            }
        }
    }
}

void weapon_dark_effect(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    if (phase == 0) {
        spawn_particle_effect(&player->body_center, 0xC6);
        spawn_particle_effect(&player->body_center, 0xC9);
    }
    if (phase == 1) {
        spawn_particle_effect(pos, 0x1C5);
        spawn_particle_effect(pos, 0x1C8);
    }
}

void weapon_dim_shadow_effect(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    Vec node;

    if (phase == 0) {
        player->get_anim_node_position(0x30, &node);
        spawn_particle_effect(&node, 0x1A8);
        spawn_particle_effect(&node, 0x1A9);
    }
    if (phase == 1) {
        spawn_particle_effect_with_flags(pos, 0xC8, 0x40);
        create_timed_particle_emitter_with_flags(pos, 0x101, 0, 0x1E, 0x40);
    }
}

void dispatch_attack_event(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    if (phase == 0) {
        spawn_particle_effect(&player->body_center, 0xA0);
    }
    if (phase == 1) {
        spawn_scattered_lightning_strikes((u8 *)pos, 4);
    }
}

void dispatch_by_type(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    if (phase == 0) {
        spawn_particle_effect(&player->body_center, 0xA0);
    }
    if (phase == 1) {
        spawn_scattered_lightning_strikes((u8 *)pos, 4);
    }
}

void weapon_special_lightning_bolt_effect(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    Vec node;
    Vec v;
    if (phase == 0) {
        player->get_anim_node_position(0x30, &node);
        spawn_particle_effect(&node, 0xBE);
    }
    if (phase == 1) {
        VecCopy((Vec *)&v, pos);
        v.y += 100.0f;
        {
            Vec t = lbl_804793D8;
            new TTecZondeEff((TObject *)tl_07, &v, &t, 0x14000000, 0x14, 100.0f, 1.8f);
        }
    }
}

void spawn_effect_by_type(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    TParticleCtrl *temp_a;

    if (phase == 0) {
        spawn_particle_effect(&player->body_center, 0xBD);
    }
    if (phase == 1) {
        temp_a = create_timed_particle_emitter(pos, 0xBF, 0, 0xF);
        if (temp_a != 0) {
            attach_particle_model(temp_a, get_bml_model(technique_effect_bml, 0), technique_texture_list, get_bml_motion(technique_effect_bml, 0), 0, 1.0f);
        }
    }
}

void spawn_hit_effect(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    TParticleCtrl *timed_particle_emitter;

    if (phase == 0) {
        spawn_particle_effect(&player->body_center, 0xBD);
    }
    if (phase == 1) {
        timed_particle_emitter = create_timed_particle_emitter(pos, 0x9A, 0, 0xF);
        if (timed_particle_emitter != 0) {
            attach_particle_model(timed_particle_emitter, get_bml_model(technique_effect_bml, 0), technique_texture_list, get_bml_motion(technique_effect_bml, 0), 0, 1.0f);
        }
    }
}

void prepare_freeze_special_effect(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    Vec node;

    if (phase == 0) {
        player->get_anim_node_position(0x30, &node);
        spawn_particle_effect(&node, 0x6A);
    }
}

void weapon_fire_explosion_effect(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    TUnk_804CCB28 *obj;
    if (phase == 0) {
        spawn_particle_effect(&player->body_center, 0x69);
    }
    if (phase == 1) {
        obj = new TUnk_804CCB28(10.0f, pos, 0, tl_particle);
        if (obj != NULL) {
            obj->scale.x = 0.6f;
            obj->scale.y = 0.6f;
            obj->scale.z = 0.6f;
            obj->target_scale = 0.8f;
        }
    }
}

void spawn_mirror_pair(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    if (phase == 0) {
        spawn_particle_effect(&player->body_center, 0x69);
    }
    if (phase == 1) {
        new TUnk_804F166C(tl_05, pos, target->rotation_y);
        new TUnk_804F166C(tl_05, pos, target->rotation_y - 0x8000);
    }
}

void handle_hit_effect(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    Vec node;

    if (phase == 0) {
        player->get_anim_node_position(0x30, &node);
        spawn_particle_effect(&node, 0x68);
    }
    if (phase == 1) {
        create_timed_particle_emitter_with_flags(pos, 0x18, 0, 5, 0x40);
    }
}

// Indexed by TItemWeapon::get_special_selector(); slot 0 is a weapon without a special.
WeaponSpecialEffect weapon_special_effect_callbacks[41] = {
    NULL,
    dispatch_effect_by_type,
    dispatch_effect_by_type,
    dispatch_effect_by_type,
    dispatch_effect_by_type,
    handle_action,
    handle_action,
    handle_action,
    handle_action,
    handle_exp_steal_effect,
    handle_exp_steal_effect,
    handle_exp_steal_effect,
    handle_stage_event,
    handle_symbol_chat_action,
    handle_action_by_type,
    prepare_freeze_special_effect,
    prepare_freeze_special_effect,
    spawn_hit_effect,
    spawn_effect_by_type,
    prepare_shock_special_effect,
    prepare_shock_special_effect,
    prepare_shock_special_effect,
    prepare_shock_special_effect,
    handle_hit_effect,
    handle_hit_effect,
    spawn_mirror_pair,
    weapon_fire_explosion_effect,
    weapon_special_lightning_bolt_effect,
    weapon_special_lightning_bolt_effect,
    dispatch_by_type,
    dispatch_attack_event,
    weapon_dim_shadow_effect,
    weapon_dim_shadow_effect,
    weapon_dark_effect,
    weapon_hell_effect,
    trigger_biter_effect,
    trigger_biter_effect,
    trigger_biter_effect,
    trigger_biter_effect,
    weapon_fractional_hp_effect,
    weapon_fractional_hp_effect,
};

void dispatch_weapon_special_effect(TObjPlayer *player, TObjBase *target, Vec *pos, s32 phase) {
    TItemWeapon *weapon;
    u8 selector;
    if (player == NULL && target == NULL) {
        return;
    }
    if ((s32)player->get_entity_id() >= 0xC) {
        return;
    }
    if (is_current_area_item_enabled() == 0) {
        return;
    }
    weapon = (TItemWeapon *)TObjPlayer::get_equipped_weapon(player);
    if (weapon == NULL) {
        return;
    }
    if (((TItem *)weapon)->get_item_type() != 0) {
        return;
    }
    if (weapon->test_weapon_flags(0x400020) != 0U) {
        TObjPlayer::update_battle_control_on_unlock(player, target, pos, phase);
        return;
    }
    selector = weapon->get_special_selector();
    if (selector < 41) {
        WeaponSpecialEffect effect = weapon_special_effect_callbacks[selector];
        if (effect != NULL) {
            effect(player, target, pos, phase);
        }
    }
}
