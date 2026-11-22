#ifndef PSO_UI_FRONTEND_TADRAYGC_H
#define PSO_UI_FRONTEND_TADRAYGC_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TAdRayGC : public TObject {
public:
    TAdRayGC(TObject *parent);
    virtual ~TAdRayGC();
    virtual void run_task();
    virtual void render();
public:
    void draw_ray_quads(s32 frame, s32 color, s32 side);
    static void destroy_instance();
    s32 state;   // 0x1C: 0 left ray, 1 both, 2 right ray; run_task advances it by frames
    s32 frames;  // 0x20: frames since the ray started; picks the ray texture
};

LAYOUT_ASSERT(TAdRayGC_size, sizeof(TAdRayGC) == 0x24);

void register_texture_f128_ray(void);

#endif
