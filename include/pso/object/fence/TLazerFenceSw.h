#ifndef PSO_OBJECT_FENCE_TLAZERFENCESW_H
#define PSO_OBJECT_FENCE_TLAZERFENCESW_H

#include "types.h"
#include "pso/object/key/TOKey.h"
#include "pso/camera/CameraDistanceFade.h"

struct TLazerFenceSw : public TOKey {
    TLazerFenceSw(TObject *parent, void *set_entry);
    virtual ~TLazerFenceSw();
    virtual void trigger_deactivate_sound();
    virtual void trigger_activate_sound();
    virtual void debug_draw_key_id();
    virtual void update_switch_off();
    virtual void update_switch_on();
    u16 color_slot;             // which beam colour (set_params[2] % 4)
    u16 pad_EA;
    f32 switch_frame;           // motion frame of the switch's own model
    CameraDistanceFade distance_fade;  // fades the fence out in split screen
    f32 uv_scroll;              // beam texture scroll, 0.2 a frame
    u32 last_scroll_tick;       // actor_frame_tick of the last scroll
    void draw_laser_beam();
    void render();
    void run_task();
    static void *create(void *set_data);
    static void load_resources();
};

LAYOUT_ASSERT(TLazerFenceSw_size, sizeof(TLazerFenceSw) == 0x118);

// The texture lists TLazerFenceSw::load_resources picks from. The unit defines
// them after that function, which reaches each with its own lis/addi while it
// reaches the .data it uses from one pooled base.
extern const char fe_obj_switch_laz_j_gvm[];
extern const char fe_obj_switch_laz_a_gvm[];
extern const char fe_obj_switch_laz_gvm[];

extern "C" {
void TLazerFenceSw__sub_8018A554(void *p, f32 v);
}

#endif
