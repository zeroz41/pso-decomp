#ifndef PSO_OBJECT_WARP_TOBJWARPJUNG_H
#define PSO_OBJECT_WARP_TOBJWARPJUNG_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct TObjWarpJung : public TObjAreaWarp {
    virtual ~TObjWarpJung();
    virtual void confirm_area_transfer(s32);
    void render();
    void run_task();
    static f32 get_static_field4_as_float();
    static void set_global_render_param();
    static void render_warp_effect(s32 arg0, s32 arg1);
    static void render_warp(s32 model_index);
    static s32 update_warp_display();
    u8 unk_AC[0x18];
    f32 beam_frame; /* beam motion frame: += 4.0 per tick, wraps past frameCount - 1 (name inferred) */
};

typedef char TObjWarpJung_size[sizeof(TObjWarpJung) == 0xC8 ? 1 : -1];

// Sets the texture of the six beam models: 0 red (ts064_beam_aka), 1 blue (ts064_beam_ao).
extern "C" s32 TObjWarpJung__sub_801A0404(s32 arg0);

// The floor resource hooks of the jungle warp beam (FloorLifecycleTables).
void free_warp_jung_beam_resources(void);
void load_warp_beam_resources(void);

#endif
