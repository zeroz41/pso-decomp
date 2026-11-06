#include "types.h"
#include "pso/system/scene/TScene.h"

    extern int scene_resource_index;
int TScene::get_status() {  return scene_resource_index; }
