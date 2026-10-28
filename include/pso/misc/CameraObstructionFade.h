#ifndef PSO_MISC_CAMERAOBSTRUCTIONFADE_H
#define PSO_MISC_CAMERAOBSTRUCTIONFADE_H

#include "pso/player/TUnk_80494AE0.h"

class CameraObstructionFade : public TUnk_80494AE0 {
public:
    s32 restoring;
};
typedef char CameraObstructionFade_size[sizeof(CameraObstructionFade) == 0x1C ? 1 : -1];

#endif
