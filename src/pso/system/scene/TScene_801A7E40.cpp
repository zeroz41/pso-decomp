#include "types.h"
#include "pso/system/scene/TScene.h"

    extern unsigned char TScene__floor_scene_ready_flag;
void TScene::set_ready() { TScene__floor_scene_ready_flag = 1; }

void TScene::reset_counter() { TScene__floor_scene_ready_flag = 0; }
