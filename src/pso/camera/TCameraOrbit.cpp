// The player 0 orbit camera (mode 7), and TCameraController::set_target_pos.
#include "types.h"
#include "pso/camera/TCameraOrbit.h"
#include "pso/math/AngleLookup.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"

TCameraController *TCameraOrbit::create() {
    return new TCameraOrbit();
}

#pragma push
#pragma fp_contract on
void TCameraOrbit::update_orbit_camera() {
    f32 new_distance = distance;
    u32 buttons = pad->buttons;
    s16 stick_x = pad->stick_x;
    s16 stick_y = pad->stick_y;
    f32 radius;
    if (buttons & 0x400) {
        if (buttons & 0x20000) {
            new_distance += 2.0f;
            if (new_distance > 1000.0f) {
                new_distance = 1000.0f;
            }
            distance = new_distance;
        } else if (buttons & 0x10000) {
            new_distance = new_distance - 2.0f;
            if (new_distance < 15.0f) {
                new_distance = 15.0f;
            }
            distance = new_distance;
        }
        yaw += stick_x * 3;
        pitch += stick_y * 3;
    }
    radius = distance * cos_table_lookup(pitch);
    position.x = radius * sin_table_lookup(yaw) + target.x;
    position.y = target.y - distance * sin_table_lookup(pitch);
    position.z = radius * cos_table_lookup(yaw) + target.z;
}
#pragma pop

void TCameraOrbit::reset_behind_player() {
    Vec offset;
    TObjPlayer *player;
    player = get_player_by_client_id(0);
    if (player != NULL) {
        yaw = player->rotation_y;
        offset.x = 0.0f;
        offset.y = 0.0f;
        offset.z = distance;
        push_matrix_from(&identity_matrix);
        rotate_matrix_y(0, yaw);
        matrix_mult_vec(0, &offset, &offset);
        pop_matrix();
        position.x = target.x + offset.x;
        position.y = target.y + offset.y;
        position.z = target.z + offset.z;
    }
}

void TCameraOrbit::follow_player0() {
    Vec focus;
    TObjPlayer *player;
    player = get_player_by_client_id(0);
    if (player != NULL) {
        focus.x = player->position.x;
        focus.y = 10.0f + player->position.y;
        focus.z = player->position.z;
        set_target_pos(&focus);
    }
}

void TCameraOrbit::reset_state() {
    distance = 25.0f;
    pitch = 0;
    roll = 0;
    follow_player0();
    reset_behind_player();
}

void TCameraOrbit::run_task() {
    follow_player0();
    update_orbit_camera();
}

TCameraOrbit::~TCameraOrbit() {}

TCameraOrbit::TCameraOrbit() {
    flags = 0;
    pad = &controller_input_state.controllers[0];
    reset_state();
}

void TCameraController::set_target_pos(Vec *pos) {
    target.x = pos->x;
    target.y = pos->y;
    target.z = pos->z;
}
