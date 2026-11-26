#ifndef PSO_UI_WINDOW_TWINDOWEFFECTPARTY_H
#define PSO_UI_WINDOW_TWINDOWEFFECTPARTY_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

class TParticleCtrl;

struct TWindowEffectParty : public TObject {
    static const char *class_name;
    TWindowEffectParty(TObject *object, s8 source, s8 target, void *effect_id);
    virtual ~TWindowEffectParty();
    s8 state;
    s8 source_slot;
    s8 target_slot;
    u8 _pad1F[0x1];
    f32 pos_x;
    f32 pos_y;
    f32 target_x;
    f32 target_y;
    TParticleCtrl *m_particle; // inferred name: the continuous effect spawned by the ctor, released by the dtor
    virtual void render();
    virtual void run_task();
    s32 step_toward_target(f32 to_x, f32 to_y);
    void calc_effect_position(Vec *out);
    void set_slot_position(s32 slot, f32 *position);
    static void *create(void *owner, u16 from, u16 to, u32 kind);
};

LAYOUT_ASSERT(TWindowEffectParty_size, sizeof(TWindowEffectParty) == 0x34);

void *get_simple_status_window(s8 i);


#endif
