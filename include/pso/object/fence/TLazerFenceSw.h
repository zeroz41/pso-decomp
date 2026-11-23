#ifndef PSO_OBJECT_FENCE_TLAZERFENCESW_H
#define PSO_OBJECT_FENCE_TLAZERFENCESW_H

#include "types.h"
#include "pso/object/key/TOKey.h"

struct TLazerFenceSw : public TOKey {
    TLazerFenceSw(TObject *parent, void *set_entry);
    virtual ~TLazerFenceSw();
    virtual void trigger_deactivate_sound();
    virtual void trigger_activate_sound();
    virtual void debug_draw_key_id();
    virtual void update_switch_off();
    virtual void update_switch_on();
    u32 m_104;
    u8 _pad108[0xC];
    u32 m_f8;
    void draw_laser_beam();
    void render();
    void run_task();
    static void *create(void *set_data);
    static void load_resources();
    u8 unk_FC[0x1C];
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
