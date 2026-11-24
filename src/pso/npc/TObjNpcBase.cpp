#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma readonly_strings on
#include "pso/enemy/EnemyMovement.h"
#include "pso/unk/TUnk_804C8678.h"
#include "pso/unk/text_803D96A8.h"
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/player/TPlyDispData.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraConversation.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/quest/TQuestThread.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/base/TObjChara.h"
#include "pso/map/FloorArea.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/npc/TObjNpcBringer.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/system/SoundEffect.h"
#include "pso/camera/TCameraFollow.h"
#include "pso/network/client_id.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/base/TObjBase.h"
#include "pso/player/PlayerSlots.h"
#include "pso/render/render_util.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/TLobby_800F8AA8.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/object/CursorAction.h"

const char *TObjNpcBase::class_name = "TObjNpcBase";

#pragma pool_data off
void TObjNpcBase::vfunc_92() {  }
void TObjNpcBase::vfunc_91() {  }
void TObjNpcBase::draw_debug_info() {
    home_rotation_y = rotation_y;
    uses_area_flags = 0;
    if (1000.0f <= parameters[1]) {
        uses_area_flags = 1;
        disp_on_flag = parameters[1] - 1000.0f;
    } else {
        disp_on_flag = parameters[1];
    }
    if (1000.0f <= parameters[2]) {
        uses_area_flags = 1;
        disp_off_flag = parameters[2] - 1000.0f;
    } else {
        disp_off_flag = parameters[2];
    }
    message_label = parameters[4];
    object_number = parameters[3];
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x1A001D, "<- DISP ON FLAG NO : %4.0f", parameters[1]);
    debug_printf_at(0x1A001E, "<- DISP OFF FLAG NO: %4.0f", parameters[2]);
    debug_printf_at(0x1A001F, "<- OBJECT NUMBER : %4d", object_number);
    debug_printf_at(0x1A0020, "<- MESSAGE LABEL : %4d", message_label);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}
#pragma pool_data reset

player_stats npc_default_battle_stats = { {0}, 0, 20.0f, 0.0f, 0, 0, 0 };
NpcMovementParameters npc_movement_parameters = { 100.0f, 0.5f, 0x400 };
CollisionBody npc_base_collision_body_desc = { {0.0f, 10.0f, 0.0f}, 5.0f, 0.0f, 0, 0x30203 };

void TObjNpcBase::setup_common() {
    set_motion_params(&npc_default_battle_stats);
    movementParameters = &npc_movement_parameters;
    init_collision_body_parts(this, &npc_base_collision_body_desc, 1);
    register_object_by_id();
    update_prev_position();
    copy_position();
    apply_set_params(0, 1);
}

void TObjNpcBase::interact(u16 client) {
    TObjPlayer *player;

    if (message_label > 0) {
        if (client == local_client_id) {
            player = get_player_by_client_id(client);
            if ((player != NULL) && (mode != 3)) {
                mode = 3;
                phase = 0;
                interactor = client;
                targetId = client;
                target = player;
                if ((s32) targetId == local_client_id) {
                    send_impose_hold(player, -1);
                }
                request_action(1);
                m_2ac = 0;
            }
        } else {
            interactor = 0xFFFFU;
            targetId = 0xFFFFU;
        }
    }
}

void TObjNpcBase::debug_draw_talk() {
    if ((has_interactor() != 0) && (get_player_by_client_id(interactor) != NULL)) {
        debug_printf_at(0x1A0020, "TALK");
    }
}

void TObjNpcBase::apply_set_params(s32 min_variant, s32 max_variant) {
    s32 current = variant;
    if (current <= min_variant) {
        variant = min_variant;
    } else if (max_variant <= current) {
        variant = max_variant;
    }
    if (1000.0f <= parameters[1]) {
        uses_area_flags = 1;
        disp_on_flag = (s32) (parameters[1] - 1000.0f);
    } else {
        disp_on_flag = (s32) parameters[1];
    }
    if (1000.0f <= parameters[2]) {
        uses_area_flags = 1;
        disp_off_flag = (s32) (parameters[2] - 1000.0f);
    } else {
        disp_off_flag = (s32) parameters[2];
    }
    set_message_label((s32) parameters[4]);
    set_object_number((s32) parameters[3]);
    home_rotation_y = rotation_y;
    if (object_number > 0) {
        view_distance = 400.0f;
        return;
    }
    view_distance = 250.0f;
}

void TObjNpcBase::update_conversation() {
    G_StopAtPosition_6x3E pkt1;
    G_StopAtPosition_6x3E pkt2;
    Vec d;
    s32 ang;
    TObjPlayer *player;
    if (interactor != local_client_id || target == 0 || message_label <= 0) {
        phase = 3;
    }
    switch (phase) {
    case 0:
        VecCopy(&d, &((TObjBase *)target)->position);
        subtract_vector(&d, &position);
        ang = 10430.38043493439 * atan2_float(d.x, d.z);
        switch (object_number) {
        case 0x3E9:
        case 0x3EA:
        case 0x3EB:
        case 0x41A:
        case 0x41B:
        case 0x41F:
            phase = 1;
            request_action(0);
            pkt1.init();
            pkt1.header.client_id = ((TObjBase *)(target))->get_entity_id();
            VecCopy((Vec *)&pkt1.pos, &((TObjBase *)target)->position);
            pkt1.angle = ang + 0x8000;
            pkt1.send();
            break;
        default:
            if (angle_difference_abs(rotation_y, ang) < ((NpcMovementParameters *)movementParameters)->turn_speed) {
                phase = 1;
                rotation_y = ang;
                request_action(0);
                pkt2.init();
                pkt2.header.client_id = ((TObjBase *)(target))->get_entity_id();
                VecCopy((Vec *)&pkt2.pos, &((TObjBase *)target)->position);
                pkt2.angle = rotation_y + 0x8000;
                pkt2.send();
            } else {
                rotation_y = approach_angle_limited(rotation_y, ang, ((NpcMovementParameters *)movementParameters)->turn_speed);
            }
            break;
        }
        break;
    case 1:
        phase = 2;
        if (TRaderMapCore::is_not_split_screen() == 0) {
            switch (object_number) {
            case 0x3E9:
                conversation_camera = create_conversation_camera(7);
                deactivate_local_player_collision();
                break;
            case 0x3EA:
                conversation_camera = create_conversation_camera(9);
                deactivate_local_player_collision();
                break;
            case 0x3EB:
                conversation_camera = create_conversation_camera(8);
                deactivate_local_player_collision();
                break;
            case 0x41A:
                conversation_camera = create_conversation_camera(0x11);
                deactivate_local_player_collision();
                break;
            case 0x41B:
                conversation_camera = create_conversation_camera(0x12);
                deactivate_local_player_collision();
                break;
            case 0x41F:
                conversation_camera = create_conversation_camera(0x13);
                deactivate_local_player_collision();
                break;
            default:
                begin_conversation_camera();
                break;
            }
        }
        if (object_number >= 100 && object_number < 1000 && quest_mission_manager != 0 && (quest_mission_manager)->all_parents_unqueued_for_destruction() != 0) {
            quest_thread = new TQuestThread(quest_mission_manager, message_label);
        } else if (object_number >= 1000 && quest_area_manager != 0 && (quest_area_manager)->all_parents_unqueued_for_destruction() != 0) {
            quest_thread = new TQuestThread(quest_area_manager, message_label);
        }
        break;
    case 2:
        if ((quest_thread != 0 && quest_thread->all_parents_unqueued_for_destruction() == 0) || quest_thread == 0) {
            phase = 3;
            m_2ac = 0;
            switch (object_number) {
            case 0x3E9:
            case 0x3EA:
            case 0x3EB:
            case 0x41A:
            case 0x41B:
            case 0x41F:
                activate_local_player_collision();
                if (conversation_camera != 0) {
                    conversation_camera->queue_destruction();
                    conversation_camera = 0;
                }
                break;
            default:
                end_conversation_camera();
                break;
            }
            if (target != 0 && local_client_id == ((TObjBase *)(target))->get_entity_id()) {
                player = get_player_by_client_id(local_client_id);
                if (player != NULL && player->check_player_flag1() != 0) {
                    send_release_hold(player);
                }
            }
        }
        break;
    case 3:
        mode = 0;
        phase = 0;
        targetId = 0xFFFF;
        interactor = 0xFFFF;
        target = 0;
        quest_thread = 0;
        break;
    }
    update_collisions();
}

void TObjNpcBase::update_wandering() {
    switch (phase) {
    case 0: {
        Vec v;
        s32 angle;
        f32 s;
        v.y = 0.0f;
        v.x = 0.0f;
        v.z = 1.0f;
        angle = (s32)(182.04445f * (360.0f * this->random_ratio()));
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, angle);
        rotate_vector_by_matrix(0, &v, &v);
        pop_matrix();
        v.x = v.x * parameters[0];
        v.z = v.z * parameters[0];
        vec3_add_to(&v, &home_position);
        if (100.0f < horizontal_distance_squared(&v, &position)) {
            select_enemy_destination(this, v, 0);
            velocity.x = velocity.z = 0.0f;
            phase = 1;
            request_action(1);
        }
        break;
    }
    case 1: {
        f32 r;
        enemy_turn_toward_dest(((NpcMovementParameters *)movementParameters)->turn_speed);
        enemy_set_heading_velocity(((NpcMovementParameters *)movementParameters)->speed, this, rotation_y);
        move_with_wall_slide(this);
        if (is_passing_frame(1.0f) != 0 || is_passing_frame(15.0f) != 0) {
            play_voice();
        }
        {
            f32 dist = horizontal_distance_squared(&move_destination, &body_center);
            r = ((NpcMovementParameters *)movementParameters)->speed + bodies->radius;
            if (dist < r * r || (bodies->flags & 0x380000)) {
                phase = 3;
                request_action(0);
            }
        }
        break;
    }
    case 2:
        break;
    case 3:
        m_2ac++;
        if (120.0f < (f32)(s32)m_2ac) {
            phase = 0;
            m_2ac = 0;
        }
        break;
    }
    update_collisions();
}

void TObjNpcBase::update_standing() {
    switch (phase) {
    case 0:
        if (rotation_y != home_rotation_y) {
            phase = 2;
            request_action(1);
        } else {
            phase = 1;
            request_action(0);
        }
        break;
    case 1:
        break;
    case 2:
        if (rotation_y != home_rotation_y) {
            rotation_y = approach_angle_limited(rotation_y, home_rotation_y, ((NpcMovementParameters *)movementParameters)->turn_speed);
        } else {
            phase = 1;
            request_action(0);
        }
        break;
    }
}

void TObjNpcBase::run_move_action() {
    s16 current = mode;
    if ((current >= 4) || (current < 1)) {
        if (variant != 1) {
            mode = 1;
            phase = 0;
            request_action(0);
            return;
        }
        mode = 2;
        phase = 0;
        request_action(0);
    }
}

void TObjNpcBase::update_idle() {  }

void TObjNpcBase::run_idle_action() {
    if (mode != 0) {
        mode = 0;
        phase = 0;
        request_action(0);
    }
}

void TObjNpcBase::refresh_target() {
    if (mode != 3) {
        if (is_actor_cadence_frame(30) != 0) {
            targetId = find_nearest_visible_player(this, NULL, ((NpcMovementParameters *)movementParameters)->search_range);
            {
                u32 id = targetId;
                if (id != 0xFFFF) {
                    target = get_player_by_client_id(id);
                } else {
                    target = 0;
                }
            }
        }
    }
}

void TObjNpcBase::render() {
    if ((update_object_view_visibility(view_distance, view_radius) != 0) && (visible == 1)) {
        select_actor_lighting(this);
        model_render_flags |= 1;
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix_from(0);
        translate_matrix_vec3(0, (u8 *) &position);
        rotate_matrix_y(0, rotation_y);
        set_motion_packed_rotation();
        if (draws_chunk_model != 0) {
            draw_chunk_object(model);
        } else {
            draw();
        }
        clear_motion_packed_rotation();
        pop_matrix();
        model_render_flags &= ~1;
        restore_scene_lighting();
        draw_ground_shadow(0, 0);
    }
}

void TObjNpcBase::run_task() {
    s32 on_flag;
    s32 off_flag;
    TUnk_804C8678 *root;
    if (disp_on_flag <= 0 && disp_off_flag <= 0) {
        visible = 1;
        set_indexed_flags(0, 1);
    } else {
        if (uses_area_flags == 0) {
            root = quest_mission_manager;
        } else {
            root = quest_area_manager;
        }
        on_flag = disp_on_flag;
        if (on_flag > 0) {
            if (TQuestThread::get_register(root, on_flag) != 0) {
                visible = 1;
                set_indexed_flags(0, 1);
            } else {
                visible = 0;
                clear_player_status_flag(0, 1U);
            }
        }
        off_flag = disp_off_flag;
        if ((off_flag > 0) && (TQuestThread::get_register(root, off_flag) != 0)) {
            visible = 0;
            clear_player_status_flag(0, 1U);
        }
    }
    switch (mode) {
    case 0:
        update_idle();
        break;
    case 1:
        update_standing();
        break;
    case 2:
        update_wandering();
        break;
    case 3:
        update_conversation();
        break;
    }
    advance_animation();
    update_prev_position();
    copy_position();
    if (message_label > 0 && TRaderMapCore::is_not_split_screen() == 0) {
        submit_cursor_candidate(this, -1);
    }
    clear_actor_flags(0x1B3FU);
}

uaddr npc_town_motion_data;

void TObjNpcBase::free_static() {
    if (npc_town_motion_data != 0U) {
        TLobby::free_nodes_with_id(npc_town_motion_data);
        npc_town_motion_data = 0U;
    }
}

void TObjNpcBase::load_resources() {
    npc_town_motion_data = (uaddr)load_encrypted_archive_data("PlyMotionNpcTown.cpt");
}

TObjNpcBase::~TObjNpcBase() {
    free_collision_body_parts(this);
}

TObjNpcBase::TObjNpcBase(TObject *parent) : TObjEnemy(parent) {
    m_name = class_name;
    m_388 = 0;
    visible = 1;
    switch (get_current_floor_area()) {
    case AREA_LOBBY:
        draws_chunk_model = 1;
        break;
    default:
        draws_chunk_model = 0;
        break;
    }
    mode = 0;
    actorFlags = 0x44000000;
    uses_area_flags = 0;
    if (1000.0f <= parameters[1]) {
        uses_area_flags = 1;
        disp_on_flag = parameters[1] - 1000.0f;
    } else {
        disp_on_flag = parameters[1];
    }
    if (1000.0f <= parameters[2]) {
        uses_area_flags = 1;
        disp_off_flag = parameters[2] - 1000.0f;
    } else {
        disp_off_flag = parameters[2];
    }
    message_label = parameters[4];
    object_number = parameters[3];
    view_distance = 400.0f;
    view_radius = 20.0f;
    cursor_action.set_npc_talk();
    quest_thread = 0;
    conversation_camera = 0;
}

void TObjNpcBase::request_action(s32) {  }
void TObjNpcBase::play_voice() {
    play_sound_effect(0x40003804, &position, 0, 0);
}
void TObjNpcBase::set_object_number(s32 number) { object_number = number; }
void TObjNpcBase::set_message_label(s32 label) { message_label = label; }
void CursorAction::set_npc_talk() { kind = CURSOR_ACTION_NPC_TALK; }

void G_StopAtPosition_6x3E::send() {
    bswap();
    send_subcommand(this);
}
void G_StopAtPosition_6x3E::bswap() {
    header.bswap();
    bswap_16(&is_near_enemy);
    bswap_16(&angle);
    bswap_16((u16 *)&floor);
    bswap_16((u16 *)&room);
    bswap_32((u32 *)&pos.x);
    bswap_32((u32 *)&pos.y);
    bswap_32((u32 *)&pos.z);
}
void G_StopAtPosition_6x3E::init() {
    is_near_enemy = 0;
    angle = 0;
    floor = -1;
    room = -1;
    pos.z = 0.0f;
    pos.y = 0.0f;
    pos.x = 0.0f;
    header.subcommand = 0x3E;
    header.size = sizeof(G_StopAtPosition_6x3E) / 4;
}
void TObjNpcBringer::request_action(s32) {
    if ((s16) this->mode != 2) {
        this->requested_action = 0;
        return;
    }
    this->requested_action = 1;
}

