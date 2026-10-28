#include "pso/object/TObjWarnChime.h"
#include "pso/item/TItemProShield.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
void play_sound_effect(s32, s32, s32, s32);
s16 get_actor_hp(u8 *p);
void* get_player_by_client_id(s32);
extern const char TObjWarnChime_class_name[] = "TObjWarnChime";
const char* TObjWarnChime_name = TObjWarnChime_class_name;
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
        cur = get_actor_hp((u8 *)p);
        max = ((TItemProShield *)p)->get_field_2b8();
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
    if (TCameraCtrl::should_update() == 0) {
        m_state = 0;
        return;
    }
    update_player_hp_ratios();
    update_chime_countdown();
}
void TObjWarnChime::reset_state() {
    m_countdown = -1;
    m_chime_interval = 0;
    if (TCameraCtrl::should_update() != 0) {
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
