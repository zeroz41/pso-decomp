#include "types.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
f64 acos();

f32 TObjPlayer::get_scale_factor() {
    return (f32) acos();
}

}
