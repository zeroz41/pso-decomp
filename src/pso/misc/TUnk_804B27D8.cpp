#include "types.h"
#include "pso/misc/TUnk_804B27D8.h"
#include "pso/TMainTask.h"
#include "pso/TObject.h"
#include "pso/misc/TCameraCtrl_8006CC30.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TSwitch.h"
#include "pso/misc/TUnk_804C8678.h"
#include "pso/network/client_id.h"
#include "pso/object/CursorAction.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/NinjaTypes.h"
#include "pso/quest/TQuestThread.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803E2D70.h"

// Defined in TQuestThread.cpp. TQuestThread.h cannot declare them yet: 16
// files still redeclare them with their own types.
extern TUnk_804C8678 *quest_mission_manager;
extern TUnk_804C8678 *quest_area_manager;

void TUnk_804B27D8::vfunc_16() {}

void TUnk_804B27D8::vfunc_6(s16 *state, s32) {
    m_ac = *state;
}

void TUnk_804B27D8::interact(s32 client) {
    TObjPlayer *player;
    if (quest_label > 0) {
        if ((u16)client == local_client_id) {
            player = get_player_by_client_id((u16)client);
            if (player == NULL || (s32)m_ac != 1) {
                return;
            }
            m_ac = 2;
            interactor = client;
            TObjPlayer::play_effect_default((s32)player, -1);
        } else {
            interactor = 0xFFFF;
        }
    }
}

s32 TUnk_804B27D8::update_active_state() {
    switch (activation) {
    case 1:
        if (is_any_player_within_radius_xz(4900.0f) != 0) {
            active = 1;
        } else {
            active = 0;
        }
        break;
    case 2:
        if (is_current_floor_switch_set((u16)switch_id) == 1) {
            active = 1;
        } else {
            active = 0;
        }
        break;
    }
    return active;
}

void TUnk_804B27D8::set_quest_label(s32 label) {
    if (label < 0) {
        label = 0;
    }
    quest_label = label;
}

void TUnk_804B27D8::set_script_id(s32 id) {
    if (id < 0) {
        id = 0;
    }
    script_id = id;
}

// Set entry params: 4 the switch (-1 a nearby player, above 0xFF never), 5 the
// script id, 6 the quest label.
s32 TUnk_804B27D8::read_set_params() {
    switch_id = set_params[0];
    if (switch_id > 0xFF) {
        activation = 0;
    } else if (switch_id < 0) {
        activation = 1;
    } else {
        activation = 2;
    }
    set_script_id(set_params[1]);
    set_quest_label(set_params[2]);
    return switch_id;
}

void TUnk_804B27D8::run_task() {
    TObjPlayer *player;
    f32 frame;
    f32 end;
    if (TObjPlayer::check_demo_mode() == 1) {
        vfunc_16();
        return;
    }
    switch (m_ac) {
    case 0:
        if (update_active_state() != 0 && is_any_player_within_radius_xz(4900.0f) != 0 && quest_label > 0) {
            m_ac = 1;
        }
        break;
    case 1:
        submit_cursor_candidate(this, -1);
        break;
    case 2:
        if (interactor == local_client_id) {
            m_ac = 3;
            begin_conversation_camera();
            if (script_id >= 100 && script_id < 1000 && quest_mission_manager != NULL &&
                ((TObject *)quest_mission_manager)->all_parents_unqueued_for_destruction() != 0) {
                quest_thread = new TQuestThread((TObject *)quest_mission_manager, quest_label);
                if (quest_thread != NULL) {
                    quest_thread->set_parent(tl_00);
                }
            } else if (quest_area_manager != NULL &&
                       ((TObject *)quest_area_manager)->all_parents_unqueued_for_destruction() != 0) {
                quest_thread = new TQuestThread((TObject *)quest_area_manager, quest_label);
                if (quest_thread != NULL) {
                    quest_thread->set_parent(tl_00);
                }
            }
        } else {
            m_ac = 1;
            interactor = 0xFFFF;
        }
        break;
    case 3:
        if ((quest_thread != NULL && quest_thread->all_parents_unqueued_for_destruction() == 0) || quest_thread == NULL) {
            m_ac = 0;
            quest_thread = NULL;
            end_conversation_camera();
            if (interactor == local_client_id) {
                player = get_player_by_client_id(local_client_id);
                if (player != NULL && ((TLobby *)player)->check_player_flag1() != 0) {
                    TObjPlayer::send_code_45_1((s32)player);
                }
            }
        }
        break;
    }
    m_b0 += 1.0f;
    end = animation_end_frame;
    frame = m_b0;
    if (end < frame) {
        m_b0 = frame - end;
    }
    vfunc_15();
}

#pragma push
#pragma fp_contract on
void TUnk_804B27D8::render() {
    visible = update_object_view_visibility(m_c0, model_radius);
    if (visible == 1) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(texlist);
        if (active == 1) {
            if (motion != NULL) {
                draw_model_motion(model, motion, m_b0);
            } else {
                draw_chunk_object(model);
            }
        } else {
            draw_chunk_model(((NJS_OBJECT *)model)->model);
        }
        pop_matrix();
    }
}
#pragma pop

TUnk_804B27D8::~TUnk_804B27D8() {}

TUnk_804B27D8::TUnk_804B27D8(TObject *parent) : TObjMapObject(parent) {
    switch_id = -1;
    activation = 0;
    m_ac = 0;
    active = 0;
    script_id = 0;
    quest_label = 0;
    cursor_action.set_talk();
    quest_thread = NULL;
    visible = 1;
}

void CursorAction::set_talk() { kind = CURSOR_ACTION_TALK; }
