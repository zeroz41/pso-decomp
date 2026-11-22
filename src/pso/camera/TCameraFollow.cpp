#include "types.h"
#include "pso/camera/TCameraController.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/camera/TCameraFollow.h"
#include "pso/system/vector.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/dragon/TBoss1Dragon.h"
#include "pso/boss/galgryphon/Boss5GryphonBehavior.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/GinjaView.h"
#include "pso/map/FloorArea.h"
#include "pso/map/CsnQuery.h"
#include "pso/math/MatrixVector.h"
#include "pso/network/client_id.h"
#include "pso/render/render_util.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixStack.h"

// Eye offsets behind the actor that init_pose and reset_to_actor turn by its facing.
__declspec(section ".rodata") Vec follow_camera_init_eye_offset = { 0.0f, 0.0f, 45.42f };
__declspec(section ".rodata") Vec follow_camera_reset_eye_offset = { 0.0f, 0.0f, 45.42f };


#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#include <stddef.h>
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803D853C.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/keyboard/TKeyBoardControl_803DE9C4.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/render/Draw2D.h"
#include "pso/ui/hud/TLockOnCursor.h"

u8 camera_override_flags;


// select_follow_camera_offsets's eye offset behind the actor outside the boss arenas (the
// first row; the second is never read).
Vec follow_camera_default_eye_offsets[2] = {
    { 0.0f, 25.43f, 45.42f },
    { 0.0f, 0.0f, 0.0f },
};

void reset_camera_to_local_player() {
    camera_override_flags = 0;
    camera_override_client_id = 0xFFFF;
    reset_cameras_to_actor(get_player_by_client_id(local_client_id), 0);
}

void set_locked_camera_override(const Vec *position, u16 client_id) {
    camera_override_flags |= 2;
    VecCopy(&camera_override_position, position);
    camera_override_client_id = client_id;
}

void set_fixed_camera_override(const Vec *position, const Vec *target) {
    camera_override_flags |= 1;
    VecCopy(&camera_override_position, position);
    VecCopy(&camera_fixed_target_position, target);
}

s32 TCameraFollow::apply_override_pose() {
    TObjPlayer *player;
    if (camera_override_flags != 0) {
        this->flags = 0;
        VecCopy(&this->position, &camera_override_position);
        if (camera_override_flags & 2) {
            player = get_player_by_client_id(camera_override_client_id);
            if (player != NULL) {
                this->target.x = player->position.x;
                this->target.y = 19.8f + player->position.y;
                this->target.z = player->position.z;
            }
        } else {
            VecCopy(&this->target, &camera_fixed_target_position);
        }
        return 1;
    }
    return 0;
}

void TCameraFollow::set_pos_target(Vec *target_offset, Vec *eye_offset, s32 yaw) {
    follow_flags |= 8;
    set_target_yaw(yaw);
    this->target_offset.x = target_offset->x;
    this->target_offset.y = target_offset->y;
    this->target_offset.z = target_offset->z;
    this->eye_offset.x = eye_offset->x;
    this->eye_offset.y = eye_offset->y;
    this->eye_offset.z = eye_offset->z;
}

s32 TCameraFollow::is_manual_camera_held() {
    if (is_split_screen() != 0) {
        return 0;
    }
    return ((u32)get_pad_slot(0x12)->held >> 17) & 1;
}

#pragma push
#pragma fp_contract on
// The free camera of the keyboard pad: the stick turns and raises the eye, R pulls it in,
// the 0x10/0x20 buttons zoom.
void TCameraFollow::update_manual_camera() {
    PadSlot *pad;
    f32 fx;
    f32 fy;
    f32 len;
    s32 r;
    s16 x;
    s16 y;
    s16 t;

    if (is_split_screen() != 0) {
        return;
    }
    pad = get_pad_slot(0x12);
    fx = pad->stickX;
    fy = pad->stickY;
    if (-31.0f < fx && fx <= 31.0f) {
        fx = 0.0f;
    }
    if (-31.0f < fy && fy <= 31.0f) {
        fy = 0.0f;
    }
    len = newton_sqrtf(fx * fx + fy * fy);
    if (0.0f != len) {
        len *= 0.0078125f;
    }
    if (len > 1.0f) {
        len = 1.0f;
    }
    r = (s16)pad->trigR;
    x = (s16)pad->stickX;
    y = (s16)pad->stickY;
    if (len > 0.2f) {
        t = 2.5f * len;
        if (x > 0) {
            this->yaw += (s32)(182.04445f * t);
        } else {
            this->yaw -= (s32)(182.04445f * t);
        }
        this->yaw = (u16)this->yaw;
    }
    this->eye_offset.y -= 0.1f * y;
    this->eye_offset.z -= 0.1f * r;
    if (pad->held & 0x10) {
        this->fov += 0xB6;
    } else if (pad->held & 0x20) {
        this->fov -= 0xB6;
    }
    if (this->fov >= 0x71C7) {
        this->fov = 0x71C7;
    }
    if (this->fov <= 0xE38) {
        this->fov = 0xE38;
    }
}

#pragma pop

void TCameraFollow::rotate_heading_by_stick() {
    ControllerInputContext *pad;
    f32 mag;
    s16 sx;
    s16 amt;
    if (is_split_screen() != 0) {
        return;
    }
    pad = &controller_input_state.controllers[0];
    if (pad == 0) {
        return;
    }
    mag = pad->stick_magnitude;
    sx = pad->stick_x;
    if (mag > 0.2f) {
        amt = (s16)(2.5f * mag);
        if (sx > 0) {
            yaw += (s32)(182.04445f * (f32)amt);
        } else {
            yaw -= (s32)(182.04445f * (f32)amt);
        }
        yaw = (u16)yaw;
    }
}

void request_follow_camera_offsets(Vec *target_offset, Vec *eye_offset, u16 client_id) {
    TObjPlayer *player;
    s32 angle;
    angle = 0x8000;
    player = NULL;
    if (is_split_screen() != 0) {
        if (client_id != 0xFFFF) {
            player = get_player_by_client_id(client_id);
        }
    } else {
        player = get_player_by_client_id(local_client_id);
    }
    if (player != NULL) {
        angle = player->rotation_y + 0x8000;
    }
    apply_follow_camera_offsets(target_offset, eye_offset, angle, client_id);
}

void apply_follow_camera_offsets(Vec *target_offset, Vec *eye_offset, s32 angle, u16 client_id) {
    TCameraFollow *camera;
    TObjPlayer *player;
    s32 i;
    s32 yaw;
    if (TCameraCtrl::view_state.controller <= 2 || TCameraCtrl::view_state.controller == 3) {
        if (is_split_screen() != 0) {
            if (client_id == 0xFFFF) {
                for (i = 0; i < 4; i++) {
                    camera = (TCameraFollow *)camera_controller_registry[TCameraCtrl::view_state.controller + i];
                    player = get_player_by_client_id(TCameraCtrl::get_nth_view_player_id(i));
                    yaw = angle;
                    if (player != 0) {
                        yaw = player->rotation_y + angle;
                    }
                    camera->set_pos_target(target_offset, eye_offset, yaw);
                }
                return;
            }
            camera = (TCameraFollow *)camera_controller_registry[TCameraCtrl::view_state.controller + client_id];
        } else {
            camera = (TCameraFollow *)camera_controller_registry[TCameraCtrl::view_state.controller];
        }
        if (camera != 0) {
            camera->set_pos_target(target_offset, eye_offset, angle);
        }
    }
}

void request_follow_camera_recenter() {
    TCameraFollow *camera;
    if (TCameraCtrl::view_state.controller == 0) {
        camera = (TCameraFollow *)camera_controller_registry[TCameraCtrl::view_state.controller];
        if (camera != NULL) {
            camera->recenter_requested = 1;
        }
    }
}

void end_conversation_camera() {
    TCameraFollow *camera;
    if (TCameraCtrl::view_state.controller == 0) {
        camera = (TCameraFollow *)camera_controller_registry[TCameraCtrl::view_state.controller];
        if (camera != NULL) {
            camera->set_close_up(0);
        }
    }
}

#pragma push
#pragma opt_common_subs off
s32 TCameraFollow::is_side_obstructed(s32 heading) {
    Vec eye;
    Vec candidate;
    Vec offset;
    const Vec *source;
    if (is_split_screen())
        source = &camera_ctrl_instance->split_pos[TCameraCtrl::get_camera_mode()];
    else
        source = &camera_ctrl_instance->pos;
    VecCopy(&eye, source);
    VecCopy(&offset, &eye_offset);
    offset.z += 7.0f;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, heading);
    matrix_mult_vec(0, &offset, &offset);
    pop_matrices(1);
    VecCopy(&candidate, &actor->position);
    candidate.x += offset.x;
    candidate.y += 12.0f + offset.y;
    candidate.z += offset.z;
    if (csnVector(&eye, &candidate, 0x100))
        return 1;
    return csnVector(&candidate, &camera_ctrl_instance->tgt, 0x100) ? 1 : 0;
}

#pragma pop

// Turns the follow camera to whichever side of the actor (facing +-0x6000) is nearer
// and not blocked.
void begin_conversation_camera() {
    s32 facing;
    s32 diff;
    s32 far_heading;
    s32 near_heading;
    TCameraFollow *camera;
    TObjPlayer *actor;
    if (TCameraCtrl::view_state.controller == 0) {
        camera = (TCameraFollow *)camera_controller_registry[TCameraCtrl::view_state.controller];
        camera->set_close_up(1);
        actor = camera->actor;
        if (actor != NULL) {
            facing = actor->rotation_y;
            diff = angle_difference_abs(camera->yaw, facing + 0x6000);
            if (diff > angle_difference_abs(camera->yaw, facing - 0x6000)) {
                near_heading = facing - 0x6000;
                far_heading = facing + 0x6000;
            } else {
                near_heading = facing + 0x6000;
                far_heading = facing - 0x6000;
            }
            if (camera->is_side_obstructed(near_heading) != 0) {
                if (camera->is_side_obstructed(far_heading) == 0) {
                    camera->yaw = far_heading;
                }
            } else {
                camera->yaw = near_heading;
            }
        }
    }
}

void TCameraFollow::update_follow_motion_state() {
    Vec d;
    s32 rate;
    u32 actor_flags;
    s32 follow;
    s32 moving;
    s32 locked_on;
    Vec *prev;
    Vec *pos;
    TLockOnCursor *cursor;
    TObjPlayer *player;
    prev = this->actor->get_prev_position_ptr();
    pos = this->actor->get_position_ptr();
    if (prev == NULL || pos == NULL) {
        return;
    }
    {
        d.x = pos->x - prev->x;
        d.y = pos->y - prev->y;
        d.z = pos->z - prev->z;
        if (vec_squared_length(&d) < 0.25f) {
            moving = 0;
        } else {
            moving = 1;
        }
        switch (motion_state) {
        case 0:
            if (moving != 0) {
                motion_state = 1;
            }
            player = this->actor;
            actor_flags = player->actorFlags;
            if ((actor_flags & 0x100000) || (actor_flags & 0x20) || (player->mode == 8)) {
                idle_frames = 0;
            }
            if (idle_frames > 0xFA) {
                motion_state = 2;
                return;
            }
            break;
        case 1:
            idle_frames = 0;
            follow = follow_flags;
            if (follow & 1) {
                if (follow & 0x10) {
                    eye_rate = 0.05f;
                    yaw = approach_camera_angle(yaw, get_target_yaw(), 0x16C);
                } else {
                    eye_rate = 0.67f;
                    set_target_yaw(this->actor->rotation_y + 0x8000);
                    yaw = this->actor->rotation_y + 0x8000;
                }
            } else {
                rate = (follow & 4) ? 2 : 5;
                locked_on = 0;
                cursor = this->actor->lock_on_cursor;
                if ((cursor != NULL) && (cursor->nearest_target.published_target_id != 0xFFFF) && (cursor->nearest_target.published_target_dist <= 4900.0f)) {
                    locked_on = 1;
                }
                if (locked_on == 0) {
                    yaw = approach_camera_angle(yaw, get_target_yaw(), rate);
                }
            }
            if (moving == 0) {
                motion_state = 0;
                return;
            }
            break;
        case 2:
            set_target_yaw(this->actor->rotation_y + 0x8000);
            yaw = approach_camera_angle(yaw, get_target_yaw(), 3);
            if (moving != 0) {
                motion_state = 1;
                idle_frames = 0;
            }
            break;
        }
    }
}

void TCameraFollow::calc_follow_position() {
    Vec v;
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, this->yaw);
    matrix_mult_vec(0, &this->eye_offset, &v);
    pop_matrices(1);
    this->position.x = this->actor->position.x + v.x;
    this->position.y = this->actor->position.y + v.y;
    this->position.z = this->actor->position.z + v.z;
}

void TCameraFollow::select_follow_camera_offsets() {
    s32 area = get_current_floor_area();
    if (area == AREA_DRAGON) {
        {
            Vec eye_offset;
            Vec target_offset;
            get_dragon_follow_camera_offsets(&target_offset, &eye_offset);
            request_follow_camera_offsets(&target_offset, &eye_offset, 0xFFFF);
        }
        {
            Vec eye_offset;
            Vec target_offset;
            get_dragon_follow_camera_offsets(&target_offset, &eye_offset);
            request_follow_camera_offsets(&target_offset, &eye_offset, 0xFFFF);
        }
    } else if (area == AREA_GAL_GRYPHON) {
        Vec eye_offset;
        Vec target_offset;
        get_gryphon_follow_camera_offsets(&target_offset, &eye_offset);
        request_follow_camera_offsets(&target_offset, &eye_offset, 0xFFFF);
    } else if (area == AREA_GOL_DRAGON) {
        Vec eye_offset;
        Vec target_offset;
        TBoss8Dragon::get_camera_offsets(&target_offset, &eye_offset);
        request_follow_camera_offsets(&target_offset, &eye_offset, 0xFFFF);
    } else {
        if (!(this->follow_flags & 8)) {
            this->set_target_yaw(this->actor->rotation_y + 0x8000);
            this->target_offset.x = 0.0f;
            this->target_offset.y = 19.8f;
            this->target_offset.z = -5.0f;
            this->eye_offset.x = follow_camera_default_eye_offsets[0].x;
            this->eye_offset.y = follow_camera_default_eye_offsets[0].y;
            this->eye_offset.z = follow_camera_default_eye_offsets[0].z;
            if (is_split_screen() != 0 && TCameraCtrl::get_camera_id() == 2) {
                this->eye_offset.z *= 1.4f;
                this->eye_offset.y *= 0.9f;
            }
        }
        this->follow_flags &= ~8;
    }
}

void TCameraFollow::update_follow_settings() {
    Vec *src;
    this->flags = FLAG_CHECK_OBSTRUCTION | FLAG_SMOOTH_POSE;
    if (TCameraCtrl::get_camera_id() == 2) {
        this->eye_rate = 0.56f;
    } else {
        this->eye_rate = 0.67f;
    }
    if (is_split_screen() != 0) {
        src = &camera_ctrl_instance->split_pos[TCameraCtrl::get_camera_mode()];
    } else {
        src = &camera_ctrl_instance->pos;
    }
    if (horizontal_distance_squared(&camera_ctrl_instance->tgt, src) >= 529.0f) {
        this->follow_flags |= 4;
    } else {
        this->follow_flags &= ~4;
    }
    if (this->predict_obstruction() != 0) {
        if (is_split_screen() != 0) {
            src = &camera_ctrl_instance->split_pos[TCameraCtrl::get_camera_mode()];
        } else {
            src = &camera_ctrl_instance->pos;
        }
        if (horizontal_distance_squared(src, &this->actor->position) > 400.0f) {
            this->follow_flags |= 1;
        } else {
            this->follow_flags |= 1;
            this->follow_flags |= 0x10;
        }
    } else {
        this->follow_flags &= ~1;
        this->follow_flags &= ~0x10;
    }
    this->select_follow_camera_offsets();
}

void TCameraFollow::clear_follow_flags() { this->follow_flags = 0; }

void TCameraFollow::reset_to_actor_offset(TObjPlayer *actor, Vec *offset) {
    CsnHit *hit;
    if (actor != NULL) {
        this->target.x = actor->position.x;
        this->target.y = 19.8f + actor->position.y;
        this->target.z = actor->position.z;
        this->position.x = this->target.x + offset->x;
        this->position.y = this->target.y + offset->y;
        this->position.z = this->target.z + offset->z;
        hit = csnVector(&this->target, &this->position, 0x100);
        if (hit != NULL) {
            VecCopy(&this->position, &hit->contact->point);
        }
    }
}

void TCameraFollow::reset_to_actor(TObjPlayer *actor) {
    Vec v = follow_camera_reset_eye_offset;
    Vec d;
    CsnHit *hit;
    if (actor != NULL) {
        this->yaw = actor->rotation_y + 0x8000;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, this->yaw);
        matrix_mult_vec(0, &v, &v);
        pop_matrices(1);
        this->target.x = actor->position.x;
        this->target.y = 19.8f + actor->position.y;
        this->target.z = actor->position.z;
        this->position.x = this->target.x + v.x;
        this->position.y = this->target.y + v.y;
        this->position.z = this->target.z + v.z;
        hit = csnVector(&this->target, &this->position, 0x100);
        if (hit != NULL) {
            d.x = this->position.x - this->target.x;
            d.y = this->position.y - this->target.y;
            d.z = this->position.z - this->target.z;
            if (0.0f != vec_squared_length(&d)) {
                normalize_vector(&d);
            }
            this->position.x = hit->contact->point.x - d.x;
            this->position.y = hit->contact->point.y - d.y;
            this->position.z = hit->contact->point.z - d.z;
        }
    }
}

void TCameraFollow::apply_camera_params(s32) {  }

void TCameraFollow::init_pose() {
    Vec v = follow_camera_init_eye_offset;
    TObjPlayer *player;
    s32 area;
    player = get_player_by_client_id(local_client_id);
    area = get_current_floor_area();
    if (player != NULL) {
        this->yaw = player->rotation_y + 0x8000;
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, this->yaw);
        matrix_mult_vec(0, &v, &v);
        pop_matrices(1);
        this->target.x = player->position.x;
        this->target.y = 25.43f + (19.8f + player->position.y);
        this->target.z = player->position.z;
        this->position.x = this->target.x + v.x;
        this->position.y = this->target.y + v.y;
        this->position.z = this->target.z + v.z;
    } else {
        switch (area) {
        case AREA_PIONEER2_EP1:
            VecCopy(&this->position, &follow_camera_init_pose_table[0][0].pos);
            VecCopy(&this->target, &follow_camera_init_pose_table[0][0].target);
            this->fov = follow_camera_init_pose_table[0][0].fov;
            set_clip_planes(follow_camera_init_pose_table[0][0].near_clip, follow_camera_init_pose_table[0][0].far_clip);
            break;
        case AREA_LOBBY:
            VecCopy(&this->position, &follow_camera_init_pose_table[0][1].pos);
            VecCopy(&this->target, &follow_camera_init_pose_table[0][1].target);
            this->fov = follow_camera_init_pose_table[0][1].fov;
            set_clip_planes(follow_camera_init_pose_table[0][1].near_clip, follow_camera_init_pose_table[0][1].far_clip);
            break;
        case AREA_PIONEER2_EP2:
            VecCopy(&this->position, &follow_camera_init_pose_table[0][2].pos);
            VecCopy(&this->target, &follow_camera_init_pose_table[0][2].target);
            this->fov = follow_camera_init_pose_table[0][2].fov;
            set_clip_planes(follow_camera_init_pose_table[0][2].near_clip, follow_camera_init_pose_table[0][2].far_clip);
            break;
        }
    }
    camera_renderer_setup_nop(&ninja_camera, this->fov);
    update_camera_state(this->position.x, this->position.y, this->position.z);
}

TCameraController *TCameraFollow::create() {
    return new TCameraFollow();
}

#pragma push
#pragma fp_contract on
void TCameraFollow::compute_follow_target() {
    Vec o;
    Vec d;
    f32 k;
    Vec *prev;
    Vec *pos;
    f32 x;
    f32 y;
    f32 z;
    prev = this->actor->get_prev_position_ptr();
    pos = this->actor->get_position_ptr();
    d.x = pos->x - prev->x;
    d.y = pos->y - prev->y;
    d.z = pos->z - prev->z;
    vec_squared_length(&d);
    push_matrix_from(identity_matrix);
    rotate_matrix_y(0, this->actor->rotation_y + 0x8000);
    matrix_mult_vec(0, &this->target_offset, &o);
    pop_matrices(1);
    x = o.x + this->actor->position.x + 18.0f * d.x;
    y = o.y + this->actor->position.y;
    z = o.z + this->actor->position.z + 18.0f * d.z;
    if (is_split_screen() != 0) {
        TCameraCtrl::get_camera_mode();
    }
    this->target.x = x;
    this->target.y = y;
    this->target.z = z;
    if (get_current_floor_area() == AREA_PIONEER2_EP1 || get_current_floor_area() == AREA_PIONEER2_EP2) {
        if (this->close_up != 0) {
            k = -3.0f;
            approach_camera_scalar(&this->target_y_offset, &k, 1.4f);
        } else {
            k = 0.0f;
            approach_camera_scalar(&this->target_y_offset, &k, 1.4f);
        }
    }
    this->target.y += this->target_y_offset;
}
#pragma pop

void TCameraFollow::run_task() {
    s32 i;
    TObjPlayer *player;
    u32 actor_flags;
    this->actor = get_player_by_client_id(actor_id);
    if (this->actor == NULL) {
        set_target(get_player_by_client_id(local_client_id));
        flags = 0;
        return;
    }
    if (is_split_screen() == 0) {
        TObjPlayer *local;
        local = get_player_by_client_id(local_client_id);
        if (local != NULL) {
            if (this->actor->get_floor() != local->get_floor()) {
                reset_cameras_to_actor(get_player_by_client_id(local_client_id), 0);
                for (i = 0; i < 4; i++) {
                    local = get_player_by_client_id(i);
                    if (local != NULL) {
                        local->refresh_equipment_slot();
                    }
                }
                return;
            }
            if (actor_id != local_client_id && this->actor != NULL && this->actor->is_flag_4000_set() != 0) {
                reset_cameras_to_actor(get_player_by_client_id(local_client_id), 0);
                for (i = 0; i < 4; i++) {
                    local = get_player_by_client_id(i);
                    if (local != NULL) {
                        local->refresh_equipment_slot();
                    }
                }
            }
        }
    }
    if (close_up != 0) {
        idle_frames = 0;
        fov = approach_angle_limited(fov, 0x22D8, 0xB6);
    } else if (get_current_floor_area() == AREA_PIONEER2_EP1 || get_current_floor_area() == AREA_PIONEER2_EP2) {
        if (is_split_screen() == 0 && test_previous_buttons_packed(&controller_input_state.controllers[3], 0x20000) == 0) {
            fov = approach_angle_limited(fov, 0x36C1, 0xB6);
        }
    } else {
        fov = approach_angle_limited(fov, 0x36C1, 0xB6);
    }
    if (get_current_floor_area() == AREA_PIONEER2_EP1 || get_current_floor_area() == AREA_PIONEER2_EP2) {
        eye_offset.y = 20.43f;
    }
    update_follow_settings();
    if (apply_override_pose() != 0) {
        end_conversation_camera();
        clear_follow_flags();
        return;
    }
    switch (state) {
    case 0:
        target.x = this->actor->position.x;
        target.y = 19.8f + this->actor->position.y;
        target.z = this->actor->position.z;
        yaw = this->actor->rotation_y + 0x8000;
        state = 1;
        break;
    case 1:
        i = TCameraCtrl::get_nth_view_player_id(TCameraCtrl::get_camera_no());
        player = get_player_by_client_id(i);
        if ((player != NULL && player->is_controls_locked() == 0) || TWindowCtrl::get_flag_bit3() == 1) {
            i = get_camera_reset_button(i);
            if ((test_pressed_buttons_packed(&controller_input_state.controllers[player->get_controller_port()], i) != 0 && close_up == 0) || recenter_requested != 0) {
                recenter_requested = 0;
                yaw = this->actor->rotation_y + 0x8000;
            }
        }
        if (is_manual_camera_held() != 0) {
            idle_frames = 0;
            update_manual_camera();
        } else {
            actor_flags = this->actor->actorFlags;
            if ((actor_flags & 0x100000) || (actor_flags & 0x20)) {
                idle_frames = 0;
            } else if (actor_flags & 0x800) {
                idle_frames = 0;
                rotate_heading_by_stick();
            } else {
                update_follow_motion_state();
            }
        }
        calc_follow_position();
        compute_follow_target();
        break;
    }
    clear_follow_flags();
}

TCameraFollow::~TCameraFollow() {
    actor = 0;
    close_up = 0;
}

TCameraFollow::TCameraFollow() {
    s32 i;
    camera_override_flags = 0;
    camera_override_client_id = 0xFFFF;
    follow_flags = 0;
    idle_frames = 0;
    motion_state = 0;
    eye_offset.x = 0.0f;
    eye_offset.y = 0.0f;
    eye_offset.z = 0.0f;
    target_offset.x = 0.0f;
    target_offset.y = 0.0f;
    target_offset.z = 0.0f;
    flags = FLAG_CHECK_OBSTRUCTION | FLAG_SMOOTH_POSE;
    set_target(get_player_by_client_id(local_client_id));
    init_pose();
    close_up = 0;
    recenter_requested = 0;
    target_yaw = 0;
    target_y_offset = 0.0f;
    for (i = 0; i < 4; i++) {
        slots[i].clear();
    }
}

void TCameraFollow::set_close_up(s32 on) { this->close_up = on; }
s32 TCameraFollow::get_target_yaw() { return this->target_yaw; }

void FollowCameraSlot::clear() {
    pad_18 = 0;
    pad_0[0] = 0.0f;
    pad_0[1] = 0.0f;
    pad_0[2] = 0.0f;
    pad_0[3] = 0.0f;
    pad_0[4] = 0.0f;
    pad_0[5] = 0.0f;
}

s32 get_camera_reset_button(s32 client_id) {
    return TWindowKeyBoardHard::test_card_flag_2(client_id) ? 0x10000 : 0x20000;
}

s32 TWindowCtrl::get_flag_bit3() {
    if (instance == NULL) {
        return 0;
    }
    return ((u16)instance->flags >> 3U) & 1;
}

s32 TObjPlayer::is_flag_4000_set() { return check_flag(16384); }

Vec camera_override_position = { 0.0f, 0.0f, 0.0f };
Vec camera_fixed_target_position = { 0.0f, 0.0f, 0.0f };


u16 camera_override_client_id = 0xFFFF;
