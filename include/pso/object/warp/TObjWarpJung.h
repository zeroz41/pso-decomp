#ifndef PSO_OBJECT_WARP_TOBJWARPJUNG_H
#define PSO_OBJECT_WARP_TOBJWARPJUNG_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjWarpJung : public TObjAreaWarp {
    TObjWarpJung(TObject *parent, void *set_data);
    virtual ~TObjWarpJung();
    virtual void confirm_area_transfer(TObjPlayer *player);
    void render();
    void run_task();
    static f32 get_static_field4_as_float();
    static void set_global_render_param();
    static void render_warp_effect(s32 model_index, s32 frame);
    static void render_warp(s32 model_index);
    static s32 update_warp_display();
    // Sets the texture of the six beam models: 0 red (ts064_beam_aka), 1 blue (ts064_beam_ao).
    static s32 set_beam_texture(s32 color);
    f32 beam_frame; /* beam motion frame: += 4.0 per tick, wraps past nbFrame - 1 (name inferred) */
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjWarpJung_size, sizeof(TObjWarpJung) == 0xC8);

// The floor resource hooks of the jungle warp beam (FloorLifecycleTables).
void free_warp_jung_beam_resources(void);
void load_warp_beam_resources(void);

#endif
