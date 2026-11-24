#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/camera/CameraHelpers.h"
#include "pso/system/vector.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz_8004C93C.h"
#include "pso/boss/darkfalz/TBoss4Fade.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "types.h"
#include "pso/boss/darkfalz/TBoss4Type1.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/darkfalz/TObjDFDemo0.h"
#include "pso/boss/darkfalz/TObjDFDemo1.h"
#include "pso/boss/darkfalz/TObjDFDemo2.h"

#include <stddef.h>
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TObjDFHorming.h"
#include "pso/boss/darkfalz/TBoss4Thanks.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/unk/TLobby.h"
#include "pso/boss/darkfalz/TObjDFDemo3.h"
#include "pso/boss/darkfalz/TObjDFDemo4.h"
#include "pso/boss/darkfalz/TObjDFDemo5.h"
#include "pso/boss/darkfalz/TObjDFDemoF.h"
#include "pso/object/ending/TObjOnlineEnding.h"
#include "pso/boss/darkfalz/TObjDFUsoTower.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TObject.h"

#include "pso/player/TObjPlayer.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/system/byteswap.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/render/render_util.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/unk/text_8036A3CC.h"

extern const char dark_falz_state_name_editor[] = "EDITOR";
extern const char dark_falz_state_name_wait_casket[] = "WAIT_CASKET";
extern const char dark_falz_state_name_demo_warp0[] = "DEMO_WARP0";
extern const char dark_falz_state_name_demo_warp1[] = "DEMO_WARP1";
extern const char dark_falz_state_name_zako[] = "ZAKO";
extern const char dark_falz_state_name_app_type1[] = "APP TYPE1";
extern const char dark_falz_state_name_type1[] = "TYPE1";
extern const char dark_falz_state_name_app_type2[] = "APP TYPE2";
extern const char dark_falz_state_name_type2[] = "TYPE2";
extern const char dark_falz_state_name_die_type2[] = "DIE TYPE2";
extern const char dark_falz_state_name_get_ring[] = "GET RING";
extern const char dark_falz_state_name_demo_warp2[] = "DEMO_WARP2";
extern const char dark_falz_state_name_demo_warp3[] = "DEMO_WARP3";
extern const char dark_falz_state_name_type3[] = "TYPE3";
extern const char dark_falz_state_name_die_type3[] = "DIE TYPE3";
extern const char dark_falz_state_name_ol_ending[] = "OL ENDING";
extern "C" {
extern Vec dark_falz_demo5_position;
    extern int dark_falz_form_index;

TBoss4Type3 *TBoss4DarkFalz::get_type3_instance() { return TBoss4DarkFalz__type3_instance; }

TBoss4Type2 *TBoss4DarkFalz::get_type2_instance() {
    return TBoss4DarkFalz__type2_instance;
}


TBoss4Type1 *TBoss4DarkFalz::get_instance() {
    return TBoss4DarkFalz__type1_instance;
}

int TBoss4DarkFalz::is_floor_leader() { return this->not_floor_leader == 0; }
s32 TBoss4Type3::get_action_state() { return state; }
s32 TBoss4Type2::get_phase() { return action; }
s32 TBoss4Type1::get_state() { return state; }
CameraAngles *TObjBase::get_rotation() { return reinterpret_cast<CameraAngles *>(&rotation_x); }
void TObjBase::save_previous_position() {
    VecCopy(&prev_position, &position);
}

int TObjBase::set_position_from(void *pos) {
    return reinterpret_cast<saddr>(VecCopy(&position, static_cast<const Vec *>(pos)));
}

void G_DarkFalzActions_6x19::send() { bswap(); send_subcommand(this); }
void G_DarkFalzActions_6x19::bswap() { header.bswap(); bswap_16((u16 *)&state); bswap_16(&unknown_a3); bswap_32((u32 *)&form_action); bswap_32(&unused); }
void G_DarkFalzActions_6x19::init() { header.subcommand = 0x19; header.size = 4; }

void TBoss4DarkFalz::update_ol_ending() {
    f32 v;
    s32 t;
    t = state_timer;
    if (t > 0x1BC) {
        v = (t - 0x1BC) / 6.0f;
        if (v > 1.0f) {
            v = 1.0f;
        }
        set_fade(0xFFFFFF, v);
    }
    t = state_timer - 1;
    state_timer = t;
    if (t < 0) {
        refresh_player_equipment();
        handle_defeat();
    }
}

void TBoss4DarkFalz::set_state() { freeze_all_players(); TObjOnlineEnding::create(this); state_timer = 454; }

void TBoss4DarkFalz::update_fade_countdown() {
    f32 v;
    s32 t;
    if (TBoss4DarkFalz::is_ending_or_split_screen() != 0) {
        t = state_timer;
        if (t < 0xA) {
            v = (f32)(0xA - t) / 6.0f;
            if (v > 1.0f) {
                v = 1.0f;
            }
            set_fade(0xFFFFFF, v);
        }
    }
    t = state_timer - 1;
    state_timer = t;
    if (t < 0) {
        if (TBoss4DarkFalz::is_ending_or_split_screen() != 0) {
            change_state(0xF);
            return;
        }
        handle_defeat();
    }
}

void TBoss4DarkFalz::begin_defeat_sequence() {
    u16 sp8[4];
    s32 i;
    freeze_all_players();
    TLobby::stop_audio_streams();
    set_story_flag_or_send_quest_flag(0x37);
    TBoss4Thanks::check_ready();
    if (TBoss4DarkFalz__type3_instance != NULL) {
        TObjChara *form = TBoss4DarkFalz__type3_instance;
        TObjDFDemo5::create(this, &form->position, form->rotation_y);
    } else {
        TObjDFDemo5::create(this, &dark_falz_demo5_position, 0);
    }
    if (TBoss4DarkFalz__type3_instance != NULL) {
        TBoss4DarkFalz__type3_instance->get_defeat_params(&local_attacker_id, &attacker_id, sp8);
        TBoss4DarkFalz__type3_instance->queue_destruction();
        TBoss4DarkFalz__type3_instance = NULL;
        i = 0;
        do {
            obj_setArrS16_FC(this, i, sp8[i]);
            i += 1;
        } while (i < 4);
    }
    state_timer = 0x12E;
}
void TBoss4DarkFalz::update_type3() {  }
void TBoss4DarkFalz::request_action_e() {
    if ((TBoss4DarkFalz__type3_instance == NULL) || (TBoss4DarkFalz__type3_instance->get_action_state() == 3) || (TBoss4DarkFalz__type3_instance->get_action_state() == 2) || (sub_8004B07C() != 0)) {
        send_action_packet(0xE);
    }
}
void TBoss4DarkFalz::start_phase() { end_player_camera_pans(); refresh_player_equipment(); }

#pragma push
#pragma fp_contract on
void TBoss4DarkFalz::update_demo_warp3() {
    TBoss4FormSetData set_data;
    f32 ratio;
    s32 timer;
    ratio = (f32) state_timer / 126.0f;
    set_fade(0xFFFFFF, ratio * (ratio * (ratio * ratio)));
    timer = state_timer - 1;
    state_timer = timer;
    if (timer <= 0) {
        set_story_flag_or_send_quest_flag(0x36);
        set_data.owner = this;
        copy_set_entry(&set_data.entry, &dark_falz_set_entry);
        set_data.entry.room = 2;
        set_data.entry.set_index = set_index + 0x1FE;
        set_data.entry.entity_id = entity_id + 0x1FE;
        TBoss4DarkFalz__type3_instance = TBoss4Type3::create(&set_data);
        change_state(0xD);
    }
}
#pragma pop

void TBoss4DarkFalz::enter_state_126() { state_timer = 126; dark_falz_form_index = 2; place_players_on_ring(); push_players_out_of_zone(2); }

void TBoss4DarkFalz::update_countdown_shrink() {
    f32 ratio;
    s32 timer;
    ratio = 1.0f - ((f32) state_timer / 114.0f);
    set_fade(0xFFFFFF, ratio * (ratio * (ratio * ratio)));
    timer = state_timer - 1;
    state_timer = timer;
    if (timer <= 0) {
        this->change_state(0xC);
    }
}

void TBoss4DarkFalz::init_state() {
    freeze_all_players();
    TObjDFDemo4::create(this, &cinematic_position, cinematic_angle);
    play_area_music("dark2.adx");
    state_timer = 114;
}

void TBoss4DarkFalz::update_get_ring() {
    f32 v;
    s32 t;
    if (TBoss4DarkFalz::is_ending_or_split_screen() != 0) {
        t = state_timer;
        if (t < 0xA) {
            v = (f32)(0xA - t) / 6.0f;
            if (v > 1.0f) {
                v = 1.0f;
            }
            set_fade(0xFFFFFF, v);
        }
    }
    t = state_timer - 1;
    state_timer = t;
    if (t < 0) {
        if (TBoss4DarkFalz::is_ending_or_split_screen() != 0) {
            change_state(0xF);
            return;
        }
        handle_defeat();
    }
}

void TBoss4DarkFalz::update_leader_get_ring() {  }
void TBoss4DarkFalz::enter_state_142() {
    freeze_all_players();
    TObjDFDemo3::create(this, &cinematic_position, cinematic_angle);
    state_timer = 142;
}
void TBoss4DarkFalz::update_timer() {
    s32 timer;
    timer = state_timer - 1;
    state_timer = timer;
    if (timer < 0) {
        if (game_difficulty_selection == 0) {
            change_state(0xA);
            return;
        }
        change_state(0xB);
    }
}

}

extern "C" {
extern Vec dark_falz_demo1_position;

void TBoss4DarkFalz::update_leader_die_type2() {  }

#pragma fp_contract on
void TBoss4DarkFalz::enter_demo2_phase() {
    u16 arr[4];
    Vec v;
    saddr flag;
    s32 i;
    freeze_all_players();
    TLobby::stop_audio_streams();
    if (TBoss4DarkFalz__type2_instance != NULL) {
        VecCopy(&v, VecCopy(&cinematic_position, &TBoss4DarkFalz__type2_instance->position));
        v.y = 0.0f;
        normalize_vector(&v);
        cinematic_position.x -= 75.0f * v.x;
        cinematic_position.z -= 75.0f * v.z;
        cinematic_position.y = 0.0f;
        cinematic_angle = TBoss4DarkFalz__type2_instance->rotation_y;
    } else {
        cinematic_position.x = cinematic_position.y = cinematic_position.z = 0.0f;
        cinematic_angle = 0;
    }
    flag = 0;
    if (game_difficulty_selection != 0) {
        flag = 1;
    }
    TObjDFDemo2::create(this, &cinematic_position, cinematic_angle, flag);
    set_story_flag_or_send_quest_flag(0x35);
    if (TBoss4DarkFalz__type2_instance != NULL) {
        TBoss4DarkFalz__type2_instance->get_demo2_params(&local_attacker_id, &attacker_id, arr);
        TBoss4DarkFalz__type2_instance->queue_destruction();
        TBoss4DarkFalz__type2_instance = NULL;
        for (i = 0; i < 4; i++) {
            obj_setArrS16_FC(this, i, arr[i]);
        }
    }
    state_timer = 0x118;
}

void TBoss4DarkFalz::update_type2() {  }

void TBoss4DarkFalz::request_action_9() {
    if ((TBoss4DarkFalz__type2_instance == NULL) || (TBoss4DarkFalz__type2_instance->get_phase() == 3) || (TBoss4DarkFalz__type2_instance->get_phase() == 2) || (sub_8004B07C() != 0)) {
        send_action_packet(9);
    }
}

void TBoss4DarkFalz::update_parts() { end_player_camera_pans(); refresh_player_equipment(); }

void TBoss4DarkFalz::update_spawn_type2_countdown() {
    TBoss4FormSetData set_data;
    state_timer = state_timer - 1;
    if (state_timer < 0) {
        set_data.owner = this;
        copy_set_entry(&set_data.entry, &dark_falz_set_entry);
        set_data.entry.room = 1;
        set_data.entry.set_index = set_index + 0x1FF;
        set_data.entry.entity_id = entity_id + 0x1FF;
        TBoss4DarkFalz__type2_instance = TBoss4Type2::create(&set_data);
        set_story_flag_or_send_quest_flag(0x34);
        change_state(8);
    }
}

void TBoss4DarkFalz::update_leader_app_type2() {  }

void TBoss4DarkFalz::start_demo1() {
    freeze_all_players();
    if (TBoss4DarkFalz__type1_instance != NULL) {
        TObjChara *form = TBoss4DarkFalz__type1_instance;
        TObjDFDemo1::create(this, &form->position, form->rotation_y);
    } else {
        TObjDFDemo1::create(this, &dark_falz_demo1_position, 0);
    }
    set_story_flag_or_send_quest_flag(0x33U);
    if (TBoss4DarkFalz__type1_instance != NULL) {
        TBoss4DarkFalz__type1_instance->queue_destruction();
        TBoss4DarkFalz__type1_instance = NULL;
    }
    state_timer = 0x12C;
}

void TBoss4DarkFalz::spawn_ancient_trap() {
    if (get_live_minion_count() > 0) {
        play_persistent_sound(0x4003A30A, this, NULL, -0x20, 2);
    }
}

void TBoss4DarkFalz::request_action_7() {
    if ((TBoss4DarkFalz__type1_instance == NULL) || (TBoss4DarkFalz__type1_instance->get_state() == 3) || (TBoss4DarkFalz__type1_instance->get_state() == 4) || (sub_8004B07C() != 0)) {
        send_action_packet(7);
    }
}

void TBoss4DarkFalz::spawn_type1() {
    TBoss4FormSetData set_data;
    set_data.owner = this;
    copy_set_entry(&set_data.entry, &dark_falz_set_entry);
    set_data.entry.room = 1;
    set_data.entry.set_index = set_index + 0x200;
    set_data.entry.entity_id = entity_id + 0x200;
    TBoss4DarkFalz__type1_instance = TBoss4Type1::create(&set_data);
    state_timer = 0;
    end_player_camera_pans();
    refresh_player_equipment();
}


void TBoss4DarkFalz::update_intro_demo() {
    s32 timer;
    s32 next;

    timer = state_timer;
    if (timer < 4) {
        set_fade(0xFFFFFF, (f32) (4 - timer) / 4.0f);
    }
    if (state_timer == 0x2D) {
        if (intro_tower != NULL) {
            intro_tower->set_fade_state(1);
        }
        TObjDFDemo0::create(this);
    }
    if (state_timer == 0xB9) {
        if (intro_tower != NULL) {
            intro_tower->set_fade_state(2);
        }
        play_area_music("dark1.adx");
    }
    next = state_timer;
    if (next > 0x145) {
        if (intro_tower != NULL) {
            intro_tower->queue_destruction();
            intro_tower = NULL;
        }
        set_story_flag_or_send_quest_flag(0x32);
        change_state(6);
        return;
    }
    state_timer = next + 1;
}

void TBoss4DarkFalz::update_leader_app_type1() {  }
void TBoss4DarkFalz::start_effect() {
    freeze_all_players();
    TLobby::stop_audio_streams();
    play_sound_effect(0x4003A80B, 0, 0, 0);
    state_timer = 0;
}
void TBoss4DarkFalz::spawn_trap() {
    play_persistent_sound(0x4003A30A, this, NULL, -0x18, 2);
}
void TBoss4DarkFalz::check_timeout() {
    if ((is_timer_expired() != 0) || (sub_8004B07C() != 0)) {
        send_action_packet(5);
    }
}
void TBoss4DarkFalz::enter_zako() {
    play_sound_effect(0x4003AD0C, 0, 0, 0);
    end_player_camera_pans();
    refresh_player_equipment();
    spawn_zako_rings();
}


void TBoss4DarkFalz::update_demo_warp1() {
    f32 ratio;
    s32 timer;

    ratio = (f32) state_timer / 30.0f;
    set_fade(0xFFFFFF, ratio * (ratio * (ratio * ratio)));
    timer = state_timer - 1;
    state_timer = timer;
    if (timer <= 0) {
        change_state(4);
    }
}

}

void TBoss4DarkFalz::init_timer() {
    state_timer = 30;
    dark_falz_form_index = 1;
    intro_tower = TObjDFUsoTower::create(this);
    refresh_player_equipment();
}

void TBoss4DarkFalz::update_demo_warp0() {
    f32 t;
    s32 timer;

    timer = state_timer;
    if (timer > 0x71) {
        t = (timer - 0x71) / 7.0f;
        t *= t;
        set_fade(0xFFFFFF, t);
    } else if (timer < 0x20) {
        t = 1.0f - ((timer - 2) / 30.0f);
        if (t > 1.0f) {
            t = 1.0f;
        }
        t *= t;
        set_fade(0xFFFFFF, t);
    }
    if (--state_timer < 0) {
        change_state(3);
    }
}

void TBoss4DarkFalz::start_demo() { place_players_for_demo(); push_players_out_of_zone(1); freeze_all_players(); TObjDFDemoF::create(this); set_dark_falz_music_request(1); unlock_music_flag(23); state_timer = 120; }

void TBoss4DarkFalz::check_players_near_center() {
    Vec v;
    TObjPlayer *p;
    s32 i;
    f32 lim;
    v.x = -9860.0f;
    v.z = -240.0f;
    lim = 900.0f;
    for (i = 0; i < registered_player_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != NULL && horizontal_distance_squared(&v, &p->body_center) <= lim) {
            send_action_packet(2);
            return;
        }
    }
    if (sub_8004B07C() != 0) {
        send_action_packet(2);
    }
}

void TBoss4DarkFalz::update_leader_editor() { if (TObjPlayer::check_demo_mode() == 0) { change_state(1); } }


TBoss4DarkFalzState dark_falz_state_table[16] = {
    { dark_falz_state_name_editor, 0, 0, &TBoss4DarkFalz::update_leader_editor, 0 },
    { dark_falz_state_name_wait_casket, 0, 0, &TBoss4DarkFalz::check_players_near_center, 0 },
    { dark_falz_state_name_demo_warp0, &TBoss4DarkFalz::start_demo, 0, 0, &TBoss4DarkFalz::update_demo_warp0 },
    { dark_falz_state_name_demo_warp1, &TBoss4DarkFalz::init_timer, 0, 0, &TBoss4DarkFalz::update_demo_warp1 },
    { dark_falz_state_name_zako, &TBoss4DarkFalz::enter_zako, 0, &TBoss4DarkFalz::check_timeout, &TBoss4DarkFalz::spawn_trap },
    { dark_falz_state_name_app_type1, &TBoss4DarkFalz::start_effect, 0, &TBoss4DarkFalz::update_leader_app_type1, &TBoss4DarkFalz::update_intro_demo },
    { dark_falz_state_name_type1, &TBoss4DarkFalz::spawn_type1, 0, &TBoss4DarkFalz::request_action_7, &TBoss4DarkFalz::spawn_ancient_trap },
    { dark_falz_state_name_app_type2, &TBoss4DarkFalz::start_demo1, 0, &TBoss4DarkFalz::update_leader_app_type2, &TBoss4DarkFalz::update_spawn_type2_countdown },
    { dark_falz_state_name_type2, &TBoss4DarkFalz::update_parts, 0, &TBoss4DarkFalz::request_action_9, &TBoss4DarkFalz::update_type2 },
    { dark_falz_state_name_die_type2, &TBoss4DarkFalz::enter_demo2_phase, 0, &TBoss4DarkFalz::update_leader_die_type2, &TBoss4DarkFalz::update_timer },
    { dark_falz_state_name_get_ring, &TBoss4DarkFalz::enter_state_142, 0, &TBoss4DarkFalz::update_leader_get_ring, &TBoss4DarkFalz::update_get_ring },
    { dark_falz_state_name_demo_warp2, &TBoss4DarkFalz::init_state, 0, 0, &TBoss4DarkFalz::update_countdown_shrink },
    { dark_falz_state_name_demo_warp3, &TBoss4DarkFalz::enter_state_126, 0, 0, &TBoss4DarkFalz::update_demo_warp3 },
    { dark_falz_state_name_type3, &TBoss4DarkFalz::start_phase, 0, &TBoss4DarkFalz::request_action_e, &TBoss4DarkFalz::update_type3 },
    { dark_falz_state_name_die_type3, &TBoss4DarkFalz::begin_defeat_sequence, 0, 0, &TBoss4DarkFalz::update_fade_countdown },
    { dark_falz_state_name_ol_ending, &TBoss4DarkFalz::set_state, 0, 0, &TBoss4DarkFalz::update_ol_ending },
};

// Zero positions passed to create_demo1 (start_demo1) and TObjDFDemo5::create (begin_defeat_sequence);
// they follow the state table in .data.
extern "C" {
Vec dark_falz_demo1_position = {0.0f, 0.0f, 0.0f};
Vec dark_falz_demo5_position = {0.0f, 0.0f, 0.0f};
}


