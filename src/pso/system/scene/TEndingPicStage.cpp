#include "types.h"
#include "pso/system/scene/TEndingPicStage.h"
#include "pso/ui/frontend/TAdEndText.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjEndingPlayer.h"
#include "pso/item/TItemData.h"
#include "pso/system/scene/EndingSceneTables.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/ambient/TObjLight_SceneLights.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_CardSequence.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/TLevelSelect.h"

TObjEndingPlayer *ending_player;
s8 player_light_index;
player_class_type ending_player_class_type;

void TEndingPicStage::pose_player(player_class_type class_type, s8 picture) {
    switch (class_type) {
        case CLASS_TYPE_HUNTER: {
            ending_player->set_position_from(&ending_player_positions_hunter[picture]);
            ending_player->rotation.y = 182.04445f * (f32)ending_player_angles_hunter[picture].y;
            ending_player->set_animation_from_data(picture);
            break;
        }
        case CLASS_TYPE_RANGER: {
            ending_player->set_position_from(&ending_player_positions_ranger[picture]);
            ending_player->rotation.y = 182.04445f * (f32)ending_player_angles_ranger[picture].y;
            ending_player->set_animation_from_data(picture);
            break;
        }
        case CLASS_TYPE_FORCE: {
            ending_player->set_position_from(&ending_player_positions_force[picture]);
            ending_player->rotation.y = 182.04445f * (f32)ending_player_angles_force[picture].y;
            ending_player->set_animation_from_data(picture);
            break;
        }
    }
}


player_class_type TObjPlayer::get_class_type() {
    s32 flags = this->appearance.classFlags;
    player_class_type class_type = CLASS_TYPE_HUNTER;

    if (flags & CLASS_FLAG_HUNTER) {
        class_type = CLASS_TYPE_HUNTER;
    }
    if (flags & CLASS_FLAG_RANGER) {
        class_type = CLASS_TYPE_RANGER;
    }
    if (flags & CLASS_FLAG_FORCE) {
        return CLASS_TYPE_FORCE;
    }
    return class_type;
}

void TEndingPicStage::publish_light() {
    ColorF c;

    c.r = player_light_color_rgba_table[player_light_index].r / 255.0f;
    c.g = player_light_color_rgba_table[player_light_index].g / 255.0f;
    c.b = player_light_color_rgba_table[player_light_index].b / 255.0f;
    c.a = player_light_color_rgba_table[player_light_index].a / 255.0f;

    publish_light_direction_color(0, &player_light_direction_color_table[player_light_index], &c);
}

void TEndingPicStage::set_camera() {
    CameraParams camera;
    Vec position = ending_camera_position;
    Vec direction = ending_camera_direction;

    activate_camera_mode(9);
    VecCopy(&camera.position, &position);
    VecCopy(&camera.target, &direction);
    camera.fov = 0x1693;

    set_active_camera_pose_from_params(&camera);
}

void TEndingPicStage::set_picture(s32 picture) {
    if (game_difficulty_selection != 3 && get_ending_scene_active() == 0) {
        player_class_type class_type;

        player_light_index = (s8)picture;
        class_type = ending_player->get_class_type();
        ending_player_class_type = class_type;
        pose_player(class_type, (s8)picture);
    }
}

void TEndingPicStage::render() {}

void TEndingPicStage::run_task() {
    set_camera();
    publish_light();
}

TEndingPicStage::~TEndingPicStage() {}

TEndingPicStage::TEndingPicStage(TObject *parent) : TObject(parent) {
    TItemData item;

    player_light_index = 0;
    Vec position = ending_player_start_position;
    ending_player = TObjEndingPlayer::create((TPlyCharData *)TAdSinglePlyChrSelectGC::get_char_index(0xFFFF));
    ending_player->set_position_from(&position);
    item.init();
    item.data1.data_u8[0] = 2;
    item.data1.data_u8[1] = 0;
}
