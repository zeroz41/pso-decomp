#include "pso/camera/CreationCamera.h"
#include "pso/camera/CameraViewParams.h"
#include "pso/math/AngleLookup.h"
#include "pso/menu/CreationInput.h"
#include "pso/misc/CharacterAppearance.h"
#include "pso/misc/CharacterCreationModels.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjCMMainMenu.h"
#include "pso/object/TObjCMProportion.h"
#include "pso/render/render_util.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801FBF54.h"

// Per class, the range (in tens of units) the review camera's look-at height
// is picked from by the character's height setting.
struct CreationHeightBounds {
    f32 minimum;
    f32 maximum;
};

static char split_screen_character_name[12];

char *get_split_screen_character_name() {
    s32 record = get_character_save_record(0xFFFF);
    ((TLobby *)split_screen_character_name)->decode_obfuscated_string((void *)(record + 0x229C), 12);
    return split_screen_character_name;
}

u32 get_character_creation_selected_entry_id() {
    return creation_menu_selected_entry;
}

CreationCamera::CreationCamera() {
    m_38 = 0;
    target.x = 0.0f;
    target.y = 10.5f;
    target.z = 0.0f;
    distance = 30.0f;
    yaw = 0;
    pitch = 0;
    shot = 2;
    shot_timer = 0;
    distance_speed = 0.0f;
    height_speed = 0.0f;
    creation_camera_mode = CREATION_CAMERA_AUTO;
    projection_angle = 17294;
}

CreationCamera::~CreationCamera() {
}

s32 creation_camera_mode;

void CreationCamera::run_task() {
    static void (CreationCamera::*modes[5])() = {
        &CreationCamera::update_auto, &CreationCamera::begin_review,
        &CreationCamera::advance_review, &CreationCamera::update_idle,
        &CreationCamera::advance_manual,
    };
    (this->*modes[creation_camera_mode])();
    calc_spherical_camera_position();
}

static CreationHeightBounds creation_camera_height_bounds_table[12] = {
    {1.05f, 1.58f},
    {1.18f, 1.53f},
    {1.5f, 1.88f},
    {1.23f, 1.63f},
    {1.3f, 1.65f},
    {1.13f, 1.58f},
    {1.08f, 1.38f},
    {1.28f, 1.68f},
    {1.08f, 1.48f},
    {1.08f, 1.5f},
    {1.2f, 1.7f},
    {1.13f, 1.5f},
};

// The view with the character centred, and the one shifted right for a
// panel open on the left.
static CameraViewParams creation_view_parameters[2] = {
    {{1.0f, 1.0f}, 320.0f, 240.0f, {1.0f, 1.0f, 500.0f, 1.0f, 1.0f, 1.0f}, 640.0f, 480.0f, {0.0f, 0.0f, 20.0f, 15.0f, 1.0f, 1.0f}},
    {{1.0f, 1.0f}, 640.0f * 0.72f, 240.0f, {1.0f, 1.0f, 500.0f, 1.0f, 1.0f, 1.0f}, 640.0f, 480.0f, {0.0f, 0.0f, 20.0f, 15.0f, 1.0f, 1.0f}},
};

CreationCamera *CreationCamera::create() {
    return new CreationCamera;
}

void CreationCamera::advance_manual() {
    s32 stick_angle;
    f32 stick;
    f32 still;
    s32 min_pitch;

    if (creation_buttons_held(0x10)) {
        if ((target.y += 0.6333333f) > 20.0f) {
            target.y = 20.0f;
        }
    } else if (creation_buttons_held(0x20)) {
        if ((target.y -= 0.6333333f) < 1.0f) {
            target.y = 1.0f;
        }
    }

    get_creation_pad_stick(&stick_angle, &stick);
    if (0.0f != stick) {
        yaw = 1092.0f * stick * sin_table_lookup(stick_angle) + yaw;
        pitch = 1092.0f * stick * cos_table_lookup(stick_angle) + pitch;
        // Classes that cannot be looked at from below.
        min_pitch = -0x2BBC;
        if (creation_player_character != NULL &&
            (creation_player_character->classId == 10 || (creation_player_character->classFlags & 2))) {
            min_pitch = 0;
        }
        if (pitch > 0x2BBC) {
            pitch = 0x2BBC;
        } else if (pitch < min_pitch) {
            pitch = min_pitch;
        }
    } else if (creation_buttons_held(0x80)) {
        yaw += 0x444;
    } else if (creation_buttons_held(0x40)) {
        yaw -= 0x444;
    }

    distance += TObjCMProportion::get_right_trigger_ratio();
    distance -= TObjCMProportion::get_ratio();
    if (distance > 80.0f) {
        distance = 80.0f;
    } else if (distance < 20.0f) {
        distance = 20.0f;
    }

    get_creation_pad_stick(NULL, &still);
    if (still > 0.0f || creation_buttons_held(0x300F0)) {
        timer = 0;
        return;
    }
    if (++timer > 150) {
        creation_camera_mode = CREATION_CAMERA_IDLE;
    }
}

void CreationCamera::update_auto() {
    frame_menu_selection();
}

void CreationCamera::frame_menu_selection() {
    s32 wanted;
    switch (get_character_creation_selected_entry_id()) {
    case 0:
    case 1:
    case 2:
    case 4:
        wanted = 0;
        break;
    case 6:
    case 8:
        wanted = 1;
        break;
    default:
        wanted = 2;
        break;
    }
    if (shot == wanted) {
        shot_timer = 0;
    } else if (++shot_timer > 30) {
        shot = wanted;
        shot_timer = 0;
    }

    if (creation_player_character != NULL) {
        f32 height = calc_character_height(creation_player_character);
        switch (shot) {
        case 0:
            approach_target(0, 0, 0.5f * height, 0.91f * height);
            break;
        case 1:
            approach_target(0, 0, 25.0f, 11.0f);
            break;
        case 2:
            approach_target(0, 0, 1.25f * height, 0.55f * height);
            break;
        }
    }
}

void CreationCamera::begin_review() {
    if (creation_player_character != NULL) {
        distance = 0.375f * calc_character_height(creation_player_character);
        review_start_distance = distance;
        f32 minimum = creation_camera_height_bounds_table[creation_player_character->classId].minimum;
        target.y = 10.0f * ((1.0f - creation_player_character->height) * (creation_camera_height_bounds_table[creation_player_character->classId].maximum - minimum) + minimum);
        yaw = 0;
        pitch = 0;
        creation_camera_mode = CREATION_CAMERA_REVIEW;
        timer = 120;
    }
}

void CreationCamera::advance_review() {
    if (--timer <= 0) {
        timer = 0;
        creation_camera_mode = CREATION_CAMERA_IDLE;
        return;
    }
    f32 weight = 0.5f * (1.0f + cos_table_lookup((timer << 15) / 120));
    f32 start = review_start_distance;
    distance = weight * (25.0f - start) + start;
}

void CreationCamera::update_idle() {
    if (creation_buttons_pressed(0x6F0)) {
        timer = 0;
        creation_camera_mode = CREATION_CAMERA_MANUAL;
        return;
    }
    timer++;
    if (timer & 0x100) {
        // Level the camera out.
        if (pitch > -109 && pitch < 109) {
            pitch = 0;
        } else {
            s32 tilt = pitch;
            if (tilt < 0) {
                pitch = tilt + 109;
            } else {
                pitch = tilt - 109;
            }
        }
        switch ((timer >> 9) & 3) {
        case 0:
            yaw += 218;
            break;
        case 1:
            distance += -1.0f / 30.0f;
            break;
        case 2:
            yaw -= 218;
            break;
        case 3:
            distance += 1.0f / 30.0f;
            break;
        }
    }
}

void CreationCamera::calc_spherical_camera_position() {
    position.y = distance * sin_table_lookup(pitch) + target.y;
    f32 ground = distance * cos_table_lookup(pitch);
    position.x = ground * sin_table_lookup(yaw);
    position.z = ground * cos_table_lookup(yaw);
}

// Moves the distance and height toward the wanted ones with a speed that
// grows while far off (up to 0.1 a frame) and stops inside a 1/150 band.
void CreationCamera::approach_target(s32 wanted_pitch, s32 wanted_yaw, f32 wanted_distance, f32 wanted_height) {
    f32 gap = wanted_distance - distance;
    if (gap > 0.1f) {
        if ((distance_speed += 0.003f) > 0.1f) {
            distance_speed = 0.1f;
        }
    } else if (gap > 1.0f / 150.0f) {
        if ((distance_speed -= 0.003f) < 1.0f / 150.0f) {
            distance_speed = 1.0f / 150.0f;
        }
    } else if (gap < -0.1f) {
        if ((distance_speed -= 0.003f) < -0.1f) {
            distance_speed = -0.1f;
        }
    } else if (gap < -1.0f / 150.0f) {
        if ((distance_speed += 0.003f) > -1.0f / 150.0f) {
            distance_speed = -1.0f / 150.0f;
        }
    } else {
        distance_speed = 0.0f;
    }
    distance += distance_speed;

    gap = wanted_height - target.y;
    if (gap > 0.1f) {
        if ((height_speed += 0.003f) > 0.1f) {
            height_speed = 0.1f;
        }
    } else if (gap > 1.0f / 150.0f) {
        if ((height_speed -= 0.003f) < 1.0f / 150.0f) {
            height_speed = 1.0f / 150.0f;
        }
    } else if (gap < -0.1f) {
        if ((height_speed -= 0.003f) < -0.1f) {
            height_speed = -0.1f;
        }
    } else if (gap < -1.0f / 150.0f) {
        if ((height_speed += 0.003f) > -1.0f / 150.0f) {
            height_speed = -1.0f / 150.0f;
        }
    } else {
        height_speed = 0.0f;
    }
    target.y += height_speed;

    yaw = approach_angle_limited(yaw, wanted_yaw, 0xC0);
    pitch = approach_angle_limited(pitch, wanted_pitch, 0xC0);
}

// The creation screens' own projection: the shifted parameters while a
// panel is open, the defaults again when they close.
void begin_creation_view() {
    creation_view_parameters[1].begin_override();
    set_creation_projection_center(1.0f);
}

void end_creation_view() {
    end_view_override();
    creation_view_shift = 0.0f;
}

f32 creation_view_shift = 1.0f;

// Slides the projection centre from the middle of the screen (shift 0) to
// 72% across (shift 1), keeping the character beside an open panel.
void set_creation_projection_center(f32 shift) {
    CameraViewParams params = creation_view_parameters[0];
    params.center_x = 640.0f * (0.5f + (0.72f - 0.5f) * shift);
    params.apply_if_overridden();
    creation_view_shift = shift;
}
