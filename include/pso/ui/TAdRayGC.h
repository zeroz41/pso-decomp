#ifndef PSO_UI_TADRAYGC_H
#define PSO_UI_TADRAYGC_H

#include "pso/TObject.h"
#include "types.h"

class TAdRayGC : public TObject {
public:
    virtual ~TAdRayGC();
    virtual void run_task();
    virtual void render();
public:
    static void draw_ray_quads(s32 arg0, u8 *arg1, void *arg2, s32 arg3);
    static void destroy_instance();
};

extern "C" {
void *__ct__8TAdRayGCFv(void *arg0);
}

void register_texture_f128_ray(void);

#endif
