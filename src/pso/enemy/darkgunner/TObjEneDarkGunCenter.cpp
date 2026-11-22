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
#include "pso/enemy/darkgunner/DarkGunner.h"
#include "pso/enemy/darkgunner/TObjEneDarkGunner.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/task/TObject.h"

const char *TObjEneDarkGunCenter__name = "TObjEneDarkGunCenter";

extern s32 lbl_805D5870;
extern void *tl_04;

void TObjEneDarkGunCenter::sub_800A0654() {
    s32 i;
    for (i = 0; i < gunner_count; i++) {
        TObjEneDarkGunner *gunner = (TObjEneDarkGunner *)get_enemy_entity(gunner_ids[i]);
        if (gunner != NULL) {
            ((TObjEneDarkGunner *)gunner)->apply_fall_damage_flag();
        }
    }
}

s32 TObjEneDarkGunCenter::sub_800A06B4() {
    s32 i;
    for (i = 0; i < gunner_count; i++) {
        TObjEneDarkGunner *gunner = (TObjEneDarkGunner *)get_enemy_entity(gunner_ids[i]);
        if (gunner != NULL) {
            if (gunner->sub_800A1808() == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void TObjEneDarkGunCenter::trigger_targets_action() {
    s32 i;
    state_timer = 0x78;
    state = 6;
    for (i = 0; i < gunner_count; i++) {
        TObjEneDarkGunner *gunner = (TObjEneDarkGunner *)get_enemy_entity(gunner_ids[i]);
        if (gunner != NULL) {
            ((TObjEneDarkGunner *)gunner)->trigger_action_if_not_flagged();
        }
    }
}

void TObjEneDarkGunCenter::sub_800A0798() {
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

void TObjEneDarkGunCenter::hide_linked_enemies() {
    s32 i;
    for (i = 0; i < gunner_count; i++) {
        TObjEneDarkGunner *gunner = (TObjEneDarkGunner *)get_enemy_entity(gunner_ids[i]);
        if (gunner != NULL) {
            ((TObjEneDarkGunner *)gunner)->set_hidden_flag();
        }
    }
    state_timer = 0x78;
    state = 4;
}

s32 TObjEneDarkGunCenter::sub_800A0884() {
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
                fn_800A0FDC(gunners[j]);
            } else {
                clear_lappy_flag_set_param(gunners[j]);
            }
        }
    }
    return 1;
}

void TObjEneDarkGunCenter::sub_800A0994() {
    s32 k;
    TObjEneDarkGunner *a;
    TObjEneDarkGunner *gunner;
    s32 m;
    TObjEneDarkGunner *b;
    s32 i;
    s32 j;
    gunner_count = 0;
    for (k = registered_player_count; k < registered_player_count + lbl_805D5870; k++) {
        gunner = (TObjEneDarkGunner *)TObjPlayer::get_player_data(k);
        if (gunner != NULL && ((TUnk_804B6C24 *)gunner)->check_value_equals((saddr)TObjEneDarkGunner__class_name) != 0 &&
            parameters[0] == gunner->parameters[0] && room == gunner->room) {
            gunner->center_id = entity_id;
            gunner_ids[gunner_count++] = get_entity_id(gunner);
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

void TObjEneDarkGunCenter::sub_800A0B18() {  }
void TObjEneDarkGunCenter::render() {  }

#pragma defer_codegen on

TObjEneDarkGunCenter::TObjEneDarkGunCenter(TObject *parent, void *set_data) : TObjEnemy(parent) {
    s32 i;
    m_name = TObjEneDarkGunCenter__name;
    apply_set_data(set_data);
    ((TBoss3Volopt *)this)->reset_photon_effect();
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

void TObjEneDarkGunCenter::sub_800A0E80() {  }

void TObjEneDarkGunCenter::sub_800A0E7C() {  }

void *TObjEneDarkGunCenter::create(void *set_data) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjEneDarkGunCenter(control, set_data);
}

void TObjEneDarkGunCenter::run_task() {
    s32 ang;
    s32 i;
    s32 t;
    s32 id;
    TObjEneDarkGunner *gunner;
    if (TObjPlayer::check_demo_mode() == 1) {
        sub_800A0B18();
        return;
    }
    sub_800A0994();
    switch (state) {
    case 0:
        if (is_actor_cadence_frame(0x1e) != 0) {
            id = find_nearest_visible_player(this, NULL, 1000.0f);
            if (id != 0xFFFF) {
                target = (u8 *)get_player_by_client_id(id);
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
                sub_800A0654();
            }
        }
        break;
    case 1:
        state_timer--;
        if (state_timer <= 0) {
            hide_linked_enemies();
            state_timer = 0xd2;
            state = 2;
        }
        break;
    case 2:
        state_timer--;
        if (sub_800A06B4() != 0 || state_timer <= 0) {
            state = 3;
        }
        break;
    case 3:
        if (find_nearest_visible_player(this, NULL, 1000.0f) != 0xFFFF) {
            hide_linked_enemies();
            sub_800A0884();
        } else {
            state = 0;
        }
        break;
    case 4:
        state_timer--;
        if (state_timer <= 0) {
            sub_800A0798();
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
