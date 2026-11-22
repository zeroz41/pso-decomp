#include "pso/object/TObjWarnChime.h"
#include "pso/object/base/TObjChara.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/PlayerSlots.h"
#include "pso/unk/TLobby.h"
#include "pso/map/FloorArea.h"
#include "pso/network/client_id.h"


extern const char TObjWarnChime_class_name[] = "TObjWarnChime";
const char* TObjWarnChime_name = TObjWarnChime_class_name;

s32 TObjWarnChime::should_update() {
    TObjPlayer *player;

    if (!is_split_screen()) {
        player = get_player_by_client_id(local_client_id);
        if (player == NULL || ((TLobby *)player)->check_player_state_flag_2() != 0) {
            return 0;
        }
        if (!is_quest_active()) {
            return 0;
        }
    }
    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1:
    case AREA_LOBBY:
    case AREA_BATTLE1:
    case AREA_BATTLE2:
    case AREA_PIONEER2_EP2:
        return 0;
    }
    return 1;
}
void TObjWarnChime::update_chime_countdown() {
    if (m_countdown < 0 || m_chime_interval <= 0) {
        return;
    }
    if (m_countdown % m_chime_interval == 0) {
        play_sound_effect(0x23230, 0, 0, 0);
    }
    m_countdown--;
}
void TObjWarnChime::update_player_hp_ratios() {
    s32 changed;
    s32 i;
    void* p;
    f32 min;
    f32 max;
    f32 cur;
    min = 1.0f;
    changed = 0;
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p == NULL || ((TObjPlayer *)p)->find_revival_item() != 0) {
            m_player_hp_ratios[i] = 1.0f;
            continue;
        }
        cur = ((TObjChara *)p)->get_actor_hp();
        max = ((TObjChara *)p)->get_hpmax();
        if (0.0f == cur) {
            m_player_hp_ratios[i] = 1.0f;
            continue;
        }
        if (max <= 0.0f) {
            m_player_hp_ratios[i] = 1.0f;
            continue;
        }
        max = cur / max;
        if (m_player_hp_ratios[i] > max) {
            changed = 1;
            if (min > max) {
                min = max;
            }
        }
        m_player_hp_ratios[i] = max;
    }
    if (changed == 0 || min >= 1.0f) {
        return;
    }
    m_countdown = 0x5A;
    m_chime_interval = (s32)(12.0f * min) + 3;
}
void TObjWarnChime::update_when_camera_active() {
    if (should_update() == 0) {
        m_state = 0;
        return;
    }
    update_player_hp_ratios();
    update_chime_countdown();
}
void TObjWarnChime::reset_state() {
    m_countdown = -1;
    m_chime_interval = 0;
    if (should_update() != 0) {
        m_state = 1;
    }
}
void TObjWarnChime::run_task() {
    switch (m_state) {
    case 0: reset_state(); return;
    case 1: update_when_camera_active(); return;
    }
}
TObjWarnChime::~TObjWarnChime() {}
TObjWarnChime::TObjWarnChime(TObject* parent) : TObject(parent) {
    s32 i;
    m_name = TObjWarnChime_name;
    m_countdown = -1;
    m_chime_interval = 0;
    for (i = 0; i < 4; i++) {
        m_player_hp_ratios[i] = 1.0f;
    }
    m_state = 0;
}
TObjWarnChime* TObjWarnChime::create(TObject* parent) {
    return new TObjWarnChime(parent);
}

s16 TObjChara::get_hpmax() { return hpmax; }
