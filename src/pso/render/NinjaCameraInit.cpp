#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/render/GinjaView.h"

#pragma push
#pragma scheduling off
void init_ninja_camera(NJS_CAMERA *camera) {
    camera->px = 0.0f;
    camera->py = 0.0f;
    camera->pz = 0.0f;
    camera->vx = 0.0f;
    camera->vy = 0.0f;
    camera->vz = -1.0f;
    camera->roll = 0;
    camera->ang = 0x2aaa;
    camera->n_clip = -1.0f;
    camera->f_clip = -60000.0f;
}
#pragma pop
