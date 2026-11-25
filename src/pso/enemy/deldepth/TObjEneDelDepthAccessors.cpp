#include "pso/enemy/deldepth/TObjEneDelDepth.h"
#include "pso/enemy/deldepth/DelDepthData.h"

BmlResource *TObjEneDelDepth::get_data() {
    return del_depth_shared_resource;
}

f32 TObjEneDelDepth::get_bomb_speed() {
    return bombSpeed;
}
