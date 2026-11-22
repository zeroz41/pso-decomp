#include "types.h"
#include "pso/camera/TCameraScripted.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/TCameraCtrl_803D6538.h"
#include "pso/item/drop/TItemDrop_800F93F0.h"
#include "pso/map/FloorArea.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer_800666B0.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/ResourceFile.h"
#include "pso/system/memory.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"

s32 saved_projection_angle;
s32 scripted_camera_projection_angle;

TCameraController *TCameraScripted::create() {
    return new TCameraScripted();
}

#pragma push
#pragma fp_contract on
void TCameraScripted::run_task() {
    CameraMotionSample sample;
    Vec forward;
    Vec offset;
    Vec direction;
    sample.channels[0] = &sample.position;
    sample.channels[1] = &sample.direction;
    sample.channels[2] = &sample.roll;
    sample.channels[3] = &sample.channel_3;
    sample_camera_motion(sample.defaults, (saddr)motion, (u8 *)sample.channels, playback.frame);
    projection_angle = scripted_camera_projection_angle;
    set_camera_capture_overlay_alpha(0x8F);
    if (bank_file->flags & 4) {
        if (bank_file->flags & 0x80) {
            projection_angle = 0x36C1;
            forward.x = sample.direction.x;
            forward.y = 0.0f;
            forward.z = sample.direction.z;
            f32 length = vec_squared_length(&forward);
            if (length) {
                normalize_vector(&forward);
            }
            position.x = -(4e+01f * forward.x - sample.position.x);
            position.y = sample.position.y;
            position.z = -(4e+01f * forward.z - sample.position.z);
            target.x = sample.direction.x + sample.position.x;
            target.y = sample.direction.y + sample.position.y;
            target.z = sample.direction.z + sample.position.z;
        } else {
            position.x = sample.position.x;
            position.y = sample.position.y;
            position.z = sample.position.z;
            target.x = sample.direction.x + position.x;
            target.y = sample.direction.y + position.y;
            target.z = sample.direction.z + position.z;
        }
    } else {
        offset.x = sample.position.x;
        offset.y = sample.position.y;
        offset.z = sample.position.z;
        direction.x = sample.direction.x;
        direction.y = sample.direction.y;
        direction.z = sample.direction.z;
        if (vec_squared_length(&direction) != 0.0f) {
            normalize_vector(&direction);
        }
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, angles.yaw);
        matrix_mult_vec(0, &offset, &offset);
        matrix_mult_vec(0, &direction, &direction);
        pop_matrices(1);
        position.x = offset.x + position_origin.x;
        position.y = offset.y + position_origin.y;
        position.z = offset.z + position_origin.z;
        target.x = direction.x + position.x;
        target.y = direction.y + position.y;
        target.z = direction.z + position.z;
    }
    playback.frame += playback.frame_step;
    if (playback.frame > (motion->frame_count - 1) || playback.frame >= 5e+03f) {
        if (bank_file->flags & 0x20) {
            playback.frame = 0.0f;
            return;
        }
        playback.frame = (motion->frame_count - 1);
        playback.flags |= 1;
    }
}
#pragma pop

TCameraScripted::~TCameraScripted() {}

TCameraScripted::TCameraScripted() {
    flags = 0;
    scripted_camera_projection_angle = 0;
    saved_projection_angle = 0;
    playback.index = 0;
    playback.bank = 0;
    playback.flags = 0;
    playback.frame = 0.0f;
    playback.frame_step = 0.0f;
    position_origin.x = 0.0f;
    position_origin.y = 0.0f;
    position_origin.z = 0.0f;
    target_origin.x = 0.0f;
    target_origin.y = 0.0f;
    target_origin.z = 0.0f;
    angles.pitch = 0;
    angles.yaw = 0;
    angles.roll = 0;
    motion = NULL;
    bank_file = NULL;
}

void TCameraCtrl::free_entries() {
    s32 i;
    for (i = 0; i < 8; i++) {
        if (camera_banks[i].buffer != NULL) {
            xfree(camera_banks[i].buffer);
            camera_banks[i].buffer = NULL;
        }
    }
}

void TCameraCtrl::load_camera_banks() {
    u32 j;
    CameraBankList *list;
    u32 count;
    u32 k;
    s32 i;
    s32 size;
    for (i = 0; i < 8; i++) {
        camera_banks[i].buffer = NULL;
    }
    list = &camera_path_bank_table[get_current_floor_area()];
    if (list->files == NULL) {
        return;
    }
    count = list->count;
    if (count >= 8) {
        return;
    }
    for (j = 0; j < count; j++) {
        size = get_resource_file_size(list->files[j].filename);
        if (size <= -1) {
            return;
        }
        camera_banks[j].buffer = xmalloc(size);
    }
    for (k = 0; k < count; k++) {
        camera_banks[k].directory = (CameraMotionDirectory *)load_relocatable_file((saddr)list->files[k].filename, (saddr)camera_banks[k].buffer);
    }
}

CameraBank camera_banks[8];
