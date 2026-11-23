#include "types.h"
#include "pso/camera/TCameraDebugOrbit.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/ControllerInputState.h"

TCameraController *TCameraDebugOrbit::create() {
    return new TCameraDebugOrbit();
}

#pragma push
#pragma fp_contract on
void TCameraDebugOrbit::run_task() {
    ControllerInputContext *pad = &controller_input_state.controllers[1];
    u32 buttons = pad->buttons;
    s16 stick_x = pad->stick_x;
    s16 stick_y = pad->stick_y;
    f32 radius;
    if (buttons & 0x20000) {
        distance += 2.2f;
    } else if (buttons & 0x10000) {
        distance -= 2.2f;
    }
    if (distance < 10.0f) {
        distance = 10.0f;
    }
    if (distance > 300.0f) {
        distance = 300.0f;
    }
    yaw += stick_x * 3;
    pitch += stick_y * 3;
    radius = distance * cos_table_lookup(pitch);
    position.x = radius * sin_table_lookup(yaw) + target.x;
    position.y = target.y - distance * sin_table_lookup(pitch);
    position.z = radius * cos_table_lookup(yaw) + target.z;
}
#pragma pop

TCameraDebugOrbit::~TCameraDebugOrbit() {}

TCameraDebugOrbit::TCameraDebugOrbit() {
    distance = 10.0f;
    flags = 0;
}
