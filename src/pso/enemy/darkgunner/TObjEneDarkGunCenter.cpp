#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/EnemyTargeting.h"
#include "types.h"
#include "pso/enemy/darkgunner/TObjEneDarkGunCenter.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/object/TObjControl.h"
#include "pso/enemy/darkgunner/TObjEneDarkGunner.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjBase.h"

const char *TObjEneDarkGunCenter__name = "TObjEneDarkGunCenter";

void TObjEneDarkGunCenter::send_gunners_home() {
    s32 i;
    for (i = 0; i < gunner_count; i++) {
        TObjEneDarkGunner *gunner = (TObjEneDarkGunner *)get_enemy_entity(gunner_ids[i]);
        if (gunner != NULL) {
            gunner->return_home_or_wait();
        }
    }
}

s32 TObjEneDarkGunCenter::all_gunners_landed() {
    s32 i;
    for (i = 0; i < gunner_count; i++) {
        TObjEneDarkGunner *gunner = (TObjEneDarkGunner *)get_enemy_entity(gunner_ids[i]);
        if (gunner != NULL) {
            if (gunner->is_on_ground() == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void TObjEneDarkGunCenter::hide_gunners() {
    s32 i;
    state_timer = 0x78;
    state = 6;
    for (i = 0; i < gunner_count; i++) {
        TObjEneDarkGunner *gunner = (TObjEneDarkGunner *)get_enemy_entity(gunner_ids[i]);
        if (gunner != NULL) {
            gunner->start_hide();
        }
    }
}

void TObjEneDarkGunCenter::start_gunners_attack() {
    s32 i;
    state_timer = 0x1a4;
    state = 5;
    for (i = 0; i < gunner_count; i++) {
        TObjEneDarkGunner *gunner = (TObjEneDarkGunner *)get_enemy_entity(gunner_ids[i]);
        if (gunner != NULL) {
            gunner->run_attack_action();
        }
    }
}

void TObjEneDarkGunCenter::move_gunners() {
    s32 i;
    for (i = 0; i < gunner_count; i++) {
        TObjEneDarkGunner *gunner = (TObjEneDarkGunner *)get_enemy_entity(gunner_ids[i]);
        if (gunner != NULL) {
            gunner->start_move();
        }
    }
    state_timer = 0x78;
    state = 4;
}

s32 TObjEneDarkGunCenter::select_death_gunner() {
    TObjEneDarkGunner *gunners[16];
    s32 n;
    s32 i;
    s32 j;
    n = 0;
    for (i = 0; i < gunner_count; i++) {
        gunners[i] = (TObjEneDarkGunner *)get_enemy_entity(gunner_ids[i]);
        if (gunners[i] != NULL) {
            n++;
        }
    }
    if (n == 0) {
        return 0;
    }
    do {
        selected_gunner++;
        if (selected_gunner >= gunner_count) {
            selected_gunner = 0;
        }
    } while (gunners[selected_gunner] == NULL);
    for (j = 0; j < gunner_count; j++) {
        if (gunners[j] != NULL) {
            if (j == selected_gunner) {
                gunners[j]->become_death_gunner();
            } else {
                gunners[j]->become_dark_gunner();
            }
        }
    }
    return 1;
}

void TObjEneDarkGunCenter::gather_gunners() {
    s32 k;
    TObjEneDarkGunner *a;
    TObjEneDarkGunner *gunner;
    s32 m;
    TObjEneDarkGunner *b;
    s32 i;
    s32 j;
    gunner_count = 0;
    for (k = registered_player_count; k < registered_player_count + registered_enemy_count; k++) {
        gunner = (TObjEneDarkGunner *)TObjPlayer::get_player_data(k);
        if (gunner != NULL && gunner->check_value_equals(TObjEneDarkGunner__class_name) != 0 &&
            parameters[0] == gunner->parameters[0] && room == gunner->room) {
            gunner->center_id = entity_id;
            gunner_ids[gunner_count++] = gunner->get_entity_id();
            if (gunner_count >= 16) {
                break;
            }
        }
    }
    for (m = gunner_count; m < 16; m++) {
        gunner_ids[m] = 0xFFFF;
    }
    for (i = 0; i < gunner_count - 1; i++) {
        for (j = i + 1; j < gunner_count; j++) {
            a = (TObjEneDarkGunner *)get_enemy_entity(gunner_ids[i]);
            b = (TObjEneDarkGunner *)get_enemy_entity(gunner_ids[j]);
            if (a != NULL && b != NULL && a->parameters[1] > b->parameters[1]) {
                u16 t = gunner_ids[i];
                gunner_ids[i] = gunner_ids[j];
                gunner_ids[j] = t;
            }
        }
    }
}

void TObjEneDarkGunCenter::run_demo_task() {  }
void TObjEneDarkGunCenter::render() {  }

#pragma defer_codegen on

TObjEneDarkGunCenter::TObjEneDarkGunCenter(TObject *parent, void *set_data) : TObjEnemy(parent) {
    s32 i;
    m_name = TObjEneDarkGunCenter__name;
    apply_set_data(set_data);
    register_by_id();
    VecCopy(&body_center, &position);
    actorFlags = actorFlags | 0x06000000 | 0x800;
    state = 0;
    set_param(0x22);
    selected_gunner = -1;
    gunner_count = 0;
    for (i = 0; i < 16; i++) {
        gunner_ids[i] = 0xFFFF;
    }
    despawn_timer = -1;
}

TObjEneDarkGunCenter::~TObjEneDarkGunCenter() {}

void TObjEneDarkGunCenter::load_resources() {  }

void TObjEneDarkGunCenter::free_resources() {  }

void *TObjEneDarkGunCenter::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjEneDarkGunCenter(control, set_data);
}

void TObjEneDarkGunCenter::run_task() {
    s32 ang;
    s32 i;
    s32 t;
    s32 id;
    TObjEneDarkGunner *gunner;
    if (TObjPlayer::check_demo_mode() == 1) {
        run_demo_task();
        return;
    }
    gather_gunners();
    switch (state) {
    case 0:
        if (is_actor_cadence_frame(0x1e) != 0) {
            id = find_nearest_visible_player(this, NULL, 1000.0f);
            if (id != 0xFFFF) {
                target = get_player_by_client_id(id);
                ang = (s32)(10430.38043493439 * atan2_float(((TObjBase *)target)->position.z - position.z,
                                                            ((TObjBase *)target)->position.x - position.x)) + 0x4000;
                for (i = 0; i < gunner_count; i++) {
                    gunner = (TObjEneDarkGunner *)get_enemy_entity(gunner_ids[i]);
                    if (gunner != NULL) {
                        gunner->rotation_y = ang;
                    }
                    ang += 0x1555;
                }
                state_timer = 0x5a;
                state = 1;
            } else {
                send_gunners_home();
            }
        }
        break;
    case 1:
        state_timer--;
        if (state_timer <= 0) {
            move_gunners();
            state_timer = 0xd2;
            state = 2;
        }
        break;
    case 2:
        state_timer--;
        if (all_gunners_landed() != 0 || state_timer <= 0) {
            state = 3;
        }
        break;
    case 3:
        if (find_nearest_visible_player(this, NULL, 1000.0f) != 0xFFFF) {
            move_gunners();
            select_death_gunner();
        } else {
            state = 0;
        }
        break;
    case 4:
        state_timer--;
        if (state_timer <= 0) {
            start_gunners_attack();
        }
        break;
    case 5:
        state_timer--;
        if (state_timer <= 0) {
            state = 3;
        }
        break;
    case 6:
        state_timer--;
        if (state_timer <= 0) {
            state = 3;
        }
        break;
    }
    t = despawn_timer;
    if (t < 0) {
        if (gunner_count > 0) {
            despawn_timer = 0x5a;
        } else {
            despawn_timer = t - 1;
            if ((f32)(t - 1) <= -30.0f) {
                despawn_timer = 0x5a;
            }
        }
    } else {
        if (gunner_count > 0) {
            despawn_timer = 0x5a;
        } else if ((despawn_timer = t - 1) <= 0) {
            send_entity_set_flags();
            queue_destruction();
        }
    }
}
