#ifndef PSO_MISC_CAMERADISTANCEFADE_H
#define PSO_MISC_CAMERADISTANCEFADE_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/misc/MaterialColorFade.h"

// Fades an object out in split screen while the camera is farther than
// fade_distance from it (color.a runs from 0, opaque, down to -1, gone),
// and draws it with its own constant material colour. The laser fences and
// the containers keep one as a member.
class CameraDistanceFade : public MaterialColorFade {
public:
    CameraDistanceFade();
    virtual ~CameraDistanceFade();
    virtual void set_flags_and_apply_damage_color();
    virtual void clear_flag_and_notify();
    // Picks the fade direction from the camera distance; FALSE once the
    // object has faded out completely.
    s32 update_visibility(const Vec *pos);
    // TRUE while partly faded (split screen only).
    s32 is_translucent();
    s32 is_visible();
    void step_fade();
    void reset();

    s32 fade_out;  // 0 fades in, 1 fades out
    f32 fade_distance;
};

typedef char CameraDistanceFadeSize[sizeof(CameraDistanceFade) == 0x20 ? 1 : -1];

#endif
