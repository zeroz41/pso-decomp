#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma readonly_strings on
#include "pso/unk/TUnk_804C8678.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/npc/TObjNpcBase_80149128.h"
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcFemaleBase.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/quest/TQuestThread.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
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
#include "pso/camera/TCameraCtrl_8006CC30.h"
#include "pso/network/client_id.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/math/MatrixTransforms.h"

extern "C" {
const char *TObjNpcBase__name = "TObjNpcBase";
s32 debug_printf_at(s32, const char *, ...);
}

#pragma pool_data off
void TObjNpcBase::vfunc_92() {  }
void TObjNpcBase::vfunc_91() {  }
void TObjNpcBase::draw_debug_info() {
    m_384 = rotation_y;
    m_38c = 0;
    if (1000.0f <= parameters[1]) {
        m_38c = 1;
        m_3a0 = parameters[1] - 1000.0f;
    } else {
        m_3a0 = parameters[1];
    }
    if (1000.0f <= parameters[2]) {
        m_38c = 1;
        m_3a4 = parameters[2] - 1000.0f;
    } else {
        m_3a4 = parameters[2];
    }
    m_3a8 = parameters[4];
    m_3ac = parameters[3];
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x1A001D, "<- DISP ON FLAG NO : %4.0f", parameters[1]);
    debug_printf_at(0x1A001E, "<- DISP OFF FLAG NO: %4.0f", parameters[2]);
    debug_printf_at(0x1A001F, "<- OBJECT NUMBER : %4d", m_3ac);
    debug_printf_at(0x1A0020, "<- MESSAGE LABEL : %4d", m_3a8);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}
#pragma pool_data reset

NpcBattleStats npc_default_battle_stats = { {0}, 20.0f };
NpcMovementParameters npc_movement_parameters = { 100.0f, 0.5f, 0x400 };
CollisionBody npc_base_collision_body_desc = { {0.0f, 10.0f, 0.0f}, 5.0f, 0.0f, 0, 0x30203 };

void TObjNpcBase::setup_common() {
    set_motion_params(&npc_default_battle_stats);
    movementParameters = &npc_movement_parameters;
    init_collision_body_parts(this, &npc_base_collision_body_desc, 1);
    register_object_by_id();
    update_prev_position();
    ((TBoss3VoloptHiraisin *)this)->copy_position();
    apply_set_params(0, 1);
}

// ---- src/pso/unk/text_801482F8.cpp

extern "C" {
s32 approach_angle_limited(s32, s32, s32);
void select_enemy_destination(TObjEnemy *, Vec *, s32);
f32 horizontal_distance_squared(Vec *, Vec *);
void vec3_add_to(Vec *, Vec *);
void rotate_vector_by_matrix(int, Vec *, Vec *);
void rotate_matrix_y(int, int);
extern u8 identity_matrix[];
u16 get_entity_id(void *);
f32 atan2_float(f32 y, f32 x);
}
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
void move_with_wall_slide(u8 *arg0);
u8 *create_conversation_camera(s32 arg0);
extern "C" {
s32 angle_difference_abs(s32, s32);

void TObjNpcBase::interact(s32 client) {
    TObjPlayer *player;

    if (m_3a8 > 0) {
        if ((u16) client == local_client_id) {
            player = get_player_by_client_id((u16) client);
            if ((player != NULL) && (mode != 3)) {
                mode = 3;
                phase = 0;
                interactor = client;
                targetId = client;
                target = (u8 *) player;
                if ((s32) targetId == local_client_id) {
                    TObjPlayer::play_effect_default((saddr) player, -1);
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

void TObjNpcBase::apply_set_params(s32 arg1, s32 arg2) {
    s32 temp_r0;
    temp_r0 = variant;
    if (temp_r0 <= arg1) {
        variant = arg1;
    } else if (arg2 <= temp_r0) {
        variant = arg2;
    }
    if (1000.0f <= parameters[1]) {
        m_38c = 1;
        m_3a0 = (s32) (parameters[1] - 1000.0f);
    } else {
        m_3a0 = (s32) parameters[1];
    }
    if (1000.0f <= parameters[2]) {
        m_38c = 1;
        m_3a4 = (s32) (parameters[2] - 1000.0f);
    } else {
        m_3a4 = (s32) parameters[2];
    }
    sub_80149360((s32) parameters[4]);
    sub_80149358((s32) parameters[3]);
    m_384 = rotation_y;
    if (m_3ac > 0) {
        m_398 = 400.0f;
        return;
    }
    m_398 = 250.0f;
}

void TObjNpcBase::update_conversation() {
    G_StopAtPosition_6x3E pkt1;
    G_StopAtPosition_6x3E pkt2;
    Vec d;
    s32 ang;
    void *m;
    uaddr p;
    if (interactor != local_client_id || target == 0 || m_3a8 <= 0) {
        phase = 3;
    }
    switch (phase) {
    case 0:
        VecCopy(&d, &((TObjBase *)target)->position);
        subtract_vector(&d, &position);
        ang = 10430.38043493439 * atan2_float(d.x, d.z);
        switch (m_3ac) {
        case 0x3E9:
        case 0x3EA:
        case 0x3EB:
        case 0x41A:
        case 0x41B:
        case 0x41F:
            phase = 1;
            request_action(0);
            ((TNpcPlayer *)(&pkt1))->init_6x3E_packet();
            pkt1.header.client_id = get_entity_id(target);
            VecCopy((Vec *)&pkt1.pos, &((TObjBase *)target)->position);
            pkt1.angle = ang + 0x8000;
            ((TNpcPlayer *)(&pkt1))->send_6x3E();
            break;
        default:
            if (angle_difference_abs(rotation_y, ang) < ((NpcMovementParameters *)movementParameters)->turn_speed) {
                phase = 1;
                rotation_y = ang;
                request_action(0);
                ((TNpcPlayer *)(&pkt2))->init_6x3E_packet();
                pkt2.header.client_id = get_entity_id(target);
                VecCopy((Vec *)&pkt2.pos, &((TObjBase *)target)->position);
                pkt2.angle = rotation_y + 0x8000;
                ((TNpcPlayer *)(&pkt2))->send_6x3E();
            } else {
                rotation_y = approach_angle_limited(rotation_y, ang, ((NpcMovementParameters *)movementParameters)->turn_speed);
            }
            break;
        }
        break;
    case 1:
        phase = 2;
        if (TRaderMapCore::is_not_split_screen() == 0) {
            switch (m_3ac) {
            case 0x3E9:
                m_3b4 = (TObject *)create_conversation_camera(7);
                TCameraCtrl::update_battle_camera();
                break;
            case 0x3EA:
                m_3b4 = (TObject *)create_conversation_camera(9);
                TCameraCtrl::update_battle_camera();
                break;
            case 0x3EB:
                m_3b4 = (TObject *)create_conversation_camera(8);
                TCameraCtrl::update_battle_camera();
                break;
            case 0x41A:
                m_3b4 = (TObject *)create_conversation_camera(0x11);
                TCameraCtrl::update_battle_camera();
                break;
            case 0x41B:
                m_3b4 = (TObject *)create_conversation_camera(0x12);
                TCameraCtrl::update_battle_camera();
                break;
            case 0x41F:
                m_3b4 = (TObject *)create_conversation_camera(0x13);
                TCameraCtrl::update_battle_camera();
                break;
            default:
                begin_conversation_camera();
                break;
            }
        }
        if (m_3ac >= 100 && m_3ac < 1000 && quest_mission_manager != 0 && (quest_mission_manager)->all_parents_unqueued_for_destruction() != 0) {
            m = new TQuestThread(quest_mission_manager, m_3a8);
            m_3b0 = (TQuestThread *)m;
        } else if (m_3ac >= 1000 && quest_area_manager != 0 && (quest_area_manager)->all_parents_unqueued_for_destruction() != 0) {
            m = new TQuestThread(quest_area_manager, m_3a8);
            m_3b0 = (TQuestThread *)m;
        }
        break;
    case 2:
        if ((m_3b0 != 0 && m_3b0->all_parents_unqueued_for_destruction() == 0) || m_3b0 == 0) {
            phase = 3;
            m_2ac = 0;
            switch (m_3ac) {
            case 0x3E9:
            case 0x3EA:
            case 0x3EB:
            case 0x41A:
            case 0x41B:
            case 0x41F:
                TCameraCtrl::update_active_player();
                if (m_3b4 != 0) {
                    m_3b4->queue_destruction();
                    m_3b4 = 0;
                }
                break;
            default:
                end_conversation_camera();
                break;
            }
            if (target != 0 && local_client_id == get_entity_id(target)) {
                p = (uaddr)get_player_by_client_id(local_client_id);
                if (p != 0 && ((TObjPlayer *)p)->check_player_flag1() != 0) {
                    TObjPlayer::send_code_45_1((saddr)p);
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
        m_3b0 = 0;
        break;
    }
    ((TObjPlayer *)this)->update_collisions();
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
            Vec d = v;
            select_enemy_destination(this, &d, 0);
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
        move_with_wall_slide((u8 *)this);
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
    ((TObjPlayer *)this)->update_collisions();
}

void TObjNpcBase::update_standing() {
    switch (phase) {
    case 0:
        if (rotation_y != m_384) {
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
        if (rotation_y != m_384) {
            rotation_y = approach_angle_limited(rotation_y, m_384, ((NpcMovementParameters *)movementParameters)->turn_speed);
        } else {
            phase = 1;
            request_action(0);
        }
        break;
    }
}

void TObjNpcBase::run_move_action() {
    s16 temp_r0;
    temp_r0 = mode;
    if ((temp_r0 >= 4) || (temp_r0 < 1)) {
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

void TObjNpcBase::vfunc_83() {  }
}

void TObjNpcBase::run_idle_action() {
    if (mode != 0) {
        mode = 0;
        phase = 0;
        request_action(0);
    }
}

extern "C" {
u16 find_nearest_visible_player(void *, s32, f32 *, f32);
void translate_matrix_vec3(u8 *arg0, u8 *arg1);

void TObjNpcBase::refresh_target() {
    f32 *temp_r5;

    if (mode != 3) {
        if (is_actor_cadence_frame(30) != 0) {
            temp_r5 = (f32 *)movementParameters;
            targetId = find_nearest_visible_player(this, 0, temp_r5, *temp_r5);
            {
                u32 id = targetId;
                if (id != 0xFFFF) {
                    target = (u8 *)get_player_by_client_id(id);
                } else {
                    target = 0;
                }
            }
        }
    }
}

extern s32 model_render_flags;

void TObjNpcBase::render() {
    if ((update_object_view_visibility(m_398, m_39c) != 0) && (m_390 == 1)) {
        select_actor_lighting(this);
        model_render_flags |= 1;
        TObjFish::set_global_param(texlist);
        push_matrix_from(0);
        translate_matrix_vec3(0, (u8 *) &position);
        rotate_matrix_y(0, rotation_y);
        set_motion_packed_rotation();
        if (m_394 != 0) {
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
    s32 index;
    s32 temp_r4_2;
    TUnk_804C8678 *root;
    if (m_3a0 <= 0 && m_3a4 <= 0) {
        m_390 = 1;
        set_indexed_flags(0, 1);
    } else {
        if (m_38c == 0) {
            root = quest_mission_manager;
        } else {
            root = quest_area_manager;
        }
        index = m_3a0;
        if (index > 0) {
            if (TQuestThread::get_register(root, index) != 0) {
                m_390 = 1;
                set_indexed_flags(0, 1);
            } else {
                m_390 = 0;
                clear_player_status_flag(0, 1U);
            }
        }
        temp_r4_2 = m_3a4;
        if ((temp_r4_2 > 0) && (TQuestThread::get_register(root, temp_r4_2) != 0)) {
            m_390 = 0;
            clear_player_status_flag(0, 1U);
        }
    }
    switch (mode) {
    case 0:
        vfunc_83();
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
    ((TBoss3VoloptHiraisin *)this)->copy_position();
    if (m_3a8 > 0 && TRaderMapCore::is_not_split_screen() == 0) {
        submit_cursor_candidate((void *) this, -1);
    }
    obj_clearFlags30(0x1B3FU);
}

}

// ---- src/pso/npc/TObjNpcBase_801490F4.cpp

uaddr npc_town_motion_data;

void TObjNpcBase::free_static() {
    if (npc_town_motion_data != 0U) {
        TLobby::free_nodes_with_id(npc_town_motion_data);
        npc_town_motion_data = 0U;
    }
}

extern "C" {
int load_encrypted_archive_data(const char *);
void load_ply_motion_npc_town(void) { npc_town_motion_data = load_encrypted_archive_data("PlyMotionNpcTown.cpt"); }
void TObjNpcBase__sub_80149368(CursorAction *action);

}

TObjNpcBase::~TObjNpcBase() {
    free_collision_body_parts(this);
}

TObjNpcBase::TObjNpcBase(TObject *parent) : TObjEnemy(parent) {
    m_name = TObjNpcBase__name;
    m_388 = 0;
    m_390 = 1;
    switch (get_current_floor_area()) {
    case AREA_LOBBY:
        m_394 = 1;
        break;
    default:
        m_394 = 0;
        break;
    }
    mode = 0;
    actorFlags = 0x44000000;
    m_38c = 0;
    if (1000.0f <= parameters[1]) {
        m_38c = 1;
        m_3a0 = parameters[1] - 1000.0f;
    } else {
        m_3a0 = parameters[1];
    }
    if (1000.0f <= parameters[2]) {
        m_38c = 1;
        m_3a4 = parameters[2] - 1000.0f;
    } else {
        m_3a4 = parameters[2];
    }
    m_3a8 = parameters[4];
    m_3ac = parameters[3];
    m_398 = 400.0f;
    m_39c = 20.0f;
    TObjNpcBase__sub_80149368(&cursor_action);
    m_3b0 = 0;
    m_3b4 = 0;
}

void TObjNpcBase::request_action(s32) {  }
void TObjNpcBase::play_voice() {
    play_sound_effect(0x40003804, &position, 0, 0);
}
void TObjNpcBase::sub_80149358(s32 v) { m_3ac = v; }
void TObjNpcBase::sub_80149360(s32 v) { m_3a8 = v; }
void TObjNpcBase__sub_80149368(CursorAction *action) { action->kind = 2; }

// ---- src/pso/misc/TNpcPlayer_80149374.cpp
void TNpcPlayer::send_6x3E() {
    bswap_6x3E();
    send_subcommand(this);
}
void TNpcPlayer::bswap_6x3E() {
    G_StopAtPosition_6x3E *cmd = (G_StopAtPosition_6x3E *)this;
    cmd->header.bswap();
    bswap_16(&cmd->is_near_enemy);
    bswap_16(&cmd->angle);
    bswap_16((u16 *)&cmd->floor);
    bswap_16((u16 *)&cmd->room);
    bswap_32((u32 *)&cmd->pos.x);
    bswap_32((u32 *)&cmd->pos.y);
    bswap_32((u32 *)&cmd->pos.z);
}
void TNpcPlayer::init_6x3E_packet() {
    G_StopAtPosition_6x3E *cmd = (G_StopAtPosition_6x3E *)this;
    cmd->is_near_enemy = 0;
    cmd->angle = 0;
    cmd->floor = -1;
    cmd->room = -1;
    cmd->pos.z = 0.0f;
    cmd->pos.y = 0.0f;
    cmd->pos.x = 0.0f;
    cmd->header.subcommand = 0x3E;
    cmd->header.size = sizeof(G_StopAtPosition_6x3E) / 4;
}
void TObjNpcBringer::request_action(s32) {
    if ((s16) this->mode != 2) {
        this->requested_action = 0;
        return;
    }
    this->requested_action = 1;
}

