#include "types.h"
#include "pso/system/scene/TScene.h"

void TScene::set_ready() { floor_scene_ready_flag = 1; }

void TScene::reset_counter() { floor_scene_ready_flag = 0; }
