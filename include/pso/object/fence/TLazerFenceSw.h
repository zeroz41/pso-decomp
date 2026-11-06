#ifndef PSO_OBJECT_FENCE_TLAZERFENCESW_H
#define PSO_OBJECT_FENCE_TLAZERFENCESW_H

#include "types.h"
#include "pso/object/key/TOKey.h"

struct TLazerFenceSw : public TOKey {
    TLazerFenceSw(TObject *arg1, void *arg2);
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
    void *create();
    static void load_resources();
    u8 unk_FC[0x1C];
};

typedef char TLazerFenceSw_size[sizeof(TLazerFenceSw) == 0x118 ? 1 : -1];

extern "C" {
void TLazerFenceSw__sub_8018A554(void *p, f32 v);
}

#endif
