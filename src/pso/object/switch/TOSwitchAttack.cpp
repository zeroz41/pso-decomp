#include "pso/effect/particle/ParticleFactory.h"
#include "pso/network/protocol/protocol_types.h"
#include "types.h"
#include "pso/object/switch/TOSwitchAttack.h"

#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/network/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/switch/TSwitch.h"


void TOSwitchAttack::render() {  }


#pragma push
#pragma opt_lifetimes off
void TOSwitchAttack::run_task() {
    u8 busy;
    s32 ok;
    u8 r;
    TObjCollidable *q;
    s32 n;
    s32 i;
    TObjChara *p;
    s32 end;
    CollisionBody *rec;
    if (effect_timer > 0) {
        effect_timer--;
    }
    busy = 0;
    if (repeatable == 0 && fired == 1) {
        busy = 1;
    }
    if (busy) {
        return;
    }
    ok = 1;
    if (stop_switch <= 0x100 && is_current_floor_switch_set(stop_switch) == 1) {
        ok = 0;
        trigger_state = 0;
    }
    if (ok != 1) {
        return;
    }
    if (trigger_switch > 0x100) {
        return;
    }
    r = is_current_floor_switch_set(trigger_switch);
    if (r == 1 && trigger_state == 0) {
        n = TLobby::get_game_mode();
        for (i = 0; i != n; i++) {
            p = resolve_hittable_target(i, 0);
            if (p != NULL) {
                if (((TObjPlayer *)p)->get_floor() == get_current_floor() &&
                    horizontal_distance_squared(&p->position, &position) < range_sq) {
                    DirectAttackPayload b;
                    b.kind = 0;
                    b.power = damage;
                    p->receive_direct_attack(this, b, NULL, -1, -1);
                }
            }
        }
        end = n + TObjEneDD::get_enemy_count();
        for (i = n; i != end; i++) {
            q = find_entity_by_id(i);
            if (q != NULL) {
                s32 k;
                rec = q->bodies;
                for (k = 0; k != q->body_count; k++, rec++) {
                    if (horizontal_distance_squared(&rec->center, &position) < range_sq) {
                        TObjChara *p2 = resolve_hittable_target(i, k);
                        if (p2 != NULL) {
                            DirectAttackPayload b;
                            b.kind = 0;
                            b.power = damage;
                            p2->receive_direct_attack(this, b, NULL, -1, -1);
                        }
                    }
                }
            }
        }
        switch (effect_type) {
        case 0:
            spawn_particle_effect_with_flags(&position, 0x45, 0x40);
            spawn_particle_effect_with_flags(&position, 0x189, 0x40);
            TCameraCtrl::set_shake_preset(2);
            play_sound_effect(0x4001C112, &position, 0, 0);
            break;
        case 1:
            TCameraCtrl::set_shake_preset(2);
            break;
        case 2:
            if (effect_timer == 0) {
                Vec v = position;
                v.y += 10.0f;
                spawn_particle_effect_with_flags(&v, 0x1A6, 0x40);
                spawn_particle_effect_with_flags(&v, 0x1A7, 0x40);
                effect_timer = 0x3C;
            }
            break;
        case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        case 11: case 12: case 13: case 14: case 15: case 16: case 17:
        case 18: case 19: case 20:
            if (m_down == 0) {
                create_sub(stop_switch, trigger_switch, effect_type - 3, size);
            }
            break;
        }
        fired = 1;
    }
    trigger_state = r;
}
#pragma pop

void *TOSwitchAttack::create(void *set_data) {
    return new TOSwitchAttack(tl_05, set_data);
}

void TOSwitchAttack::free_resources() {  }
void TOSwitchAttack::load_resources() {  }

TOSwitchAttack::~TOSwitchAttack() {

}

TOSwitchAttack::TOSwitchAttack(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = switch_attack_name;
    apply_object_set_data(set_data);
    init_params();
    trigger_state = 0;
    effect_timer = 0;
}
