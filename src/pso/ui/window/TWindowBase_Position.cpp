#include "types.h"
#include "pso/ui/window/TWindowBase.h"

void TWindowBase::set_position(f32 *pos) {
    if ((this->target_position[0] != pos[0]) || (this->target_position[1] != pos[1])) {
        this->target_position[0] = pos[0];
        this->target_position[1] = pos[1];
        this->tween_ticks = 3;
    }
}
