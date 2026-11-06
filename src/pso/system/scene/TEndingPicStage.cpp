#include "types.h"
#include "pso/system/scene/TEndingPicStage.h"
#include "pso/ui/frontend/TAdEndText.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804C4540.h"
#include "pso/item/TItemData.h"
#include "pso/system/scene/EndingSceneTables.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"

extern "C" {
void init__9TItemDataFv(TItemData *item);
extern s32 game_difficulty_selection;
}

TUnk_804C4540 *ending_player;
s8 player_light_index;
player_class_type ending_player_class_type;

void TEndingPicStage::pose_player(player_class_type class_type, s8 picture) {
    switch (class_type) {
        case CLASS_TYPE_HUNTER: {
            ending_player->set_position_from((void *)&ending_player_positions_hunter[picture]);
            ending_player->rotation_y = 182.04445f * (f32)ending_player_angles_hunter[picture].y;
            TObjPlayer::set_animation_from_data((s32)ending_player, picture);
            break;
        }
        case CLASS_TYPE_RANGER: {
            ending_player->set_position_from((void *)&ending_player_positions_ranger[picture]);
            ending_player->rotation_y = 182.04445f * (f32)ending_player_angles_ranger[picture].y;
            TObjPlayer::set_animation_from_data((s32)ending_player, picture);
            break;
        }
        case CLASS_TYPE_FORCE: {
            ending_player->set_position_from((void *)&ending_player_positions_force[picture]);
            ending_player->rotation_y = 182.04445f * (f32)ending_player_angles_force[picture].y;
            TObjPlayer::set_animation_from_data((s32)ending_player, picture);
            break;
        }
    }
}

struct EndingCamera { u8 pad0[0x14]; s32 f14; s32 f18; Vec v1c; Vec v28; s32 tail[4]; };

struct ColorF { f32 r, g, b, a; };

player_class_type TObjPlayer::get_class_type() {
    s32 flags = this->class_flags;
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

    publish_light_direction_color(0, (void *)&player_light_direction_color_table[player_light_index], &c);
}

void TEndingPicStage::set_camera() {
    EndingCamera camera;
    Vec position = ending_camera_position;
    Vec direction = ending_camera_direction;

    activate_camera_mode(9);
    VecCopy(&camera.v1c, &position);
    VecCopy(&camera.v28, &direction);
    camera.f14 = 0x1693;

    set_active_camera_pose_from_params((u8 *)&camera);
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
    ending_player = TUnk_804C4540::create(get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF));
    ending_player->set_position_from(&position);
    init__9TItemDataFv(&item);
    item.data1.data_u8[0] = 2;
    item.data1.data_u8[1] = 0;
}
