#include "pso/enemy/deldepth/TObjEneDelDepth.h"
#include "pso/enemy/deldepth/DelDepthData.h"

BmlResource *TObjEneDelDepth::get_data() {
    return TObjEneDelDepth__shared_resource;
}

f32 TObjEneDelDepth::get_bomb_speed() {
    return bombSpeed;
}
