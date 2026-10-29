#ifndef PSO_MISC_TLAZERFENCESW_H
#define PSO_MISC_TLAZERFENCESW_H

#include "types.h"
#include "pso/misc/TOKey.h"

struct TLazerFenceSw : public TOKey {
    virtual ~TLazerFenceSw();
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
