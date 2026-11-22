#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/camera/TCameraConversation.h"
#include "pso/camera/TCameraFixed.h"
#include "pso/camera/TCameraPan.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/TCameraFollow.h"
#include "pso/math/MatrixVector.h"
#include "pso/network/client_id.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D96A8.h"

extern TCameraCtrl *camera_ctrl_instance;

const NpcCameraDestination fixed_npc_camera_destination_table[20] = {
    {-158.0f, 15.0f, 269.0f, -165.0f, 19.0f, 287.0f},
    {-206.0f, 15.0f, 262.0f, -210.0f, 18.0f, 290.0f},
    {-226.0f, 13.0f, 231.0f, -240.0f, 19.0f, 244.0f},
    {-127.0f, 12.0f, 240.0f, -114.0f, 24.0f, 276.0f},
    {-256.0f, 12.0f, -32.0f, -271.0f, 15.0f, -19.0f},
    {184.4f, 11.8f, 330.8f, 174.0f, 17.5f, 353.1f},
    {208.6f, 15.1f, -281.4f, 219.4f, 23.0f, -308.2f},
    {-4.8f, 11.7f, -2015.1f, 0.4f, 20.0f, -2032.5f},
    {-34.7f, 14.5f, -1994.0f, -58.0f, 18.8f, -2004.0f},
    {33.9f, 12.7f, -1996.6f, 71.4f, 22.4f, -2006.6f},
    {-158.8f, 13.5f, -125.4f, -189.3f, 19.8f, -150.5f},
    {-144.6f, 13.0f, -187.0f, -170.4f, 19.9f, -214.1f},
    {-93.0f, 14.6f, -197.7f, -99.8f, 20.0f, -236.8f},
    {-91.5f, 13.1f, -110.0f, -62.0f, 20.0f, -110.0f},
    {-122.0f, 12.7f, -73.8f, -164.3f, 21.9f, -26.6f},
    {-1.0f, 13.0f, 209.9f, -56.0f, 20.0f, 202.8f},
    {-0.58f, 12.0f, -210.3f, -32.26f, 16.64f, -221.77f},
    {-10000.0f, 48.0f, -198.4f, -10000.0f, 46.5f, -236.3f},
    {-10039.4f, 43.3f, -176.9f, -10063.5f, 53.8f, -212.1f},
    {-9953.2f, 42.4f, -168.1f, -9924.0f, 50.0f, -183.9f},
};

struct O_8006BAC8 { u8 pad[0xd4]; Vec arr[1]; };

struct O_8006BAB4 { u8 pad[0x104]; Vec arr[1]; };

s32 fixed_npc_camera_active;

extern "C" {
Vec *TCameraCtrl__sub_8006BAB4(O_8006BAB4 *self, s32 i);
Vec *TCameraCtrl__sub_8006BAC8(O_8006BAC8 *self, s32 i);
}

s32 get_camera_override_flags() { return camera_override_flags; }

extern "C" {
Vec *TCameraCtrl__sub_8006BAC8(O_8006BAC8 *self, s32 i) {
    return &self->arr[i];
}

Vec *TCameraCtrl__sub_8006BAB4(O_8006BAB4 *self, s32 i) {
    return &self->arr[i];
}
}

TCameraFixed::TCameraFixed() : TCameraController() {
    flags = 4;
    fixed_npc_camera_active = 0;
}

TCameraFixed::~TCameraFixed() {
    fixed_npc_camera_active = 0;
}

void TCameraFixed::run_task() {}

void TCameraFixed::apply_camera_params(s32) {
    void *params;

    if (camera_ctrl_instance != NULL) {
        params = camera_ctrl_instance->get_params();
        target.x = *(f32 *)((s8 *)params + 0x28);
        target.y = *(f32 *)((s8 *)params + 0x2C);
        target.z = *(f32 *)((s8 *)params + 0x30);
        position.x = *(f32 *)((s8 *)params + 0x1C);
        position.y = *(f32 *)((s8 *)params + 0x20);
        position.z = *(f32 *)((s8 *)params + 0x24);
        projection_angle = (s32)(182.04445f * (f32) * (s32 *)((s8 *)params + 0x14));
        eye_rate = *(f32 *)((s8 *)params + 0x10);
    }
}

TCameraController *TCameraFixed::create() {
    return new TCameraFixed();
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
TCameraPan::TCameraPan(Vec *goal, s32 frames, s32 hold, TObject *parent) : TObject(parent) {
    Vec d;
    f32 dist;
    dist = xyz_distance(&camera_ctrl_instance->pos, &camera_ctrl_instance->tgt);
    VecCopy(&look_goal, goal);
    VecCopy(&look_at, &camera_ctrl_instance->tgt);
    if (frames == 0) {
        pan_frames = 1;
    } else {
        pan_frames = frames;
    }
    hold_frames = hold;
    d.x = look_goal.x - camera_ctrl_instance->pos.x;
    d.y = look_goal.y - camera_ctrl_instance->pos.y;
    d.z = look_goal.z - camera_ctrl_instance->pos.z;
    if (0.0f != vector_length(&d)) {
        normalize_vector(&d);
    }
    look_goal.x = d.x * dist + camera_ctrl_instance->pos.x;
    look_goal.y = d.y * dist + camera_ctrl_instance->pos.y;
    look_goal.z = d.z * dist + camera_ctrl_instance->pos.z;
    step = xyz_distance(&look_goal, &camera_ctrl_instance->tgt) / (f32)pan_frames;
    frame = 0;
    TCameraCtrl::set_fixed_position_and_target((u8 *)&camera_ctrl_instance->pos.x, (u8 *)&camera_ctrl_instance->tgt.x);
}
#pragma pop

TCameraPan::~TCameraPan() {
    TCameraCtrl::reset_to_local_player();
}

void TCameraPan::run_task() {
    approach_vector_fixed_distance(&look_at, &look_goal, &look_at, step);
    if (get_camera_override_flags() == 1) {
        TCameraCtrl::set_fixed_position_and_target((u8 *)&camera_ctrl_instance->pos.x, (u8 *)&look_at);
    }
    frame++;
    if (frame == pan_frames + hold_frames || get_camera_override_flags() == 0) {
        queue_destruction();
    }
}

void TCameraCtrl::create(saddr goal, s32 frames, s32 hold_frames) {
    new TCameraPan((Vec *)goal, frames, hold_frames, tl_07);
}

TCameraConversation::TCameraConversation(s32 view, s32 destination, TObject *parent) : TObject(parent) {
    this->destination = destination;
    activate_camera_mode(9);
    if (is_split_screen() != 0) {
        Vec *split_position = TCameraCtrl__sub_8006BAC8((O_8006BAC8 *)camera_ctrl_instance, view);
        VecCopy(&position, split_position);
        VecCopy(&target, TCameraCtrl__sub_8006BAB4((O_8006BAB4 *)camera_ctrl_instance, view));
    } else {
        VecCopy(&position, &camera_ctrl_instance->pos);
        VecCopy(&target, &camera_ctrl_instance->tgt);
    }
    set_active_camera_pose(&position, &target);
    fixed_npc_camera_active = 0;
}

TCameraConversation::~TCameraConversation() {
    restore_player_cameras();
    fixed_npc_camera_active = 0;
}

void TCameraConversation::run_task() {
    approach_camera_vector(&position, (Vec *)&fixed_npc_camera_destination_table[destination].position, 0.725f);
    approach_camera_vector(&target, (Vec *)&fixed_npc_camera_destination_table[destination].target, 0.725f);
    fixed_npc_camera_active = 1;
    set_active_camera_pose(&position, &target);
}

TCameraConversation *create_conversation_camera(s32 destination) {
    if (is_split_screen() != 0) {
        return NULL;
    }
    s32 view = local_client_id;
    return new TCameraConversation(view, destination, tl_07);
}

void TCameraCtrl::update_battle_camera() {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        player->deactivate_body_collision();
    }
}

void TCameraCtrl::update_active_player() {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player != NULL) {
        player->activate_body_collision();
    }
}
