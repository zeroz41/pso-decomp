#ifndef PSO_UNK_TUNK_804B0BB8_H
#define PSO_UNK_TUNK_804B0BB8_H
#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

// The base of the switch-driven doors (TODoorAncient*, TODoorCave*,
// TODoorMachine*, TODoorFourLight*, TObjDoorJung, TOBarrierEnergy01).
class TUnk_804B0BB8 : public TUnk_804AFBF8 {
public:
    TUnk_804B0BB8(TObject *parent);
    virtual ~TUnk_804B0BB8();
    virtual void run_task();
    virtual void update_door_switch_state();
    virtual void play_proximity_sound();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual s32 init_door_switch_binding();
    virtual void vfunc_20();
    void play_door_sound();
    s32 m_c8;
    s32 m_cc;
    s32 m_d0;
};

typedef char TUnk_804B0BB8Size[sizeof(TUnk_804B0BB8) == 0xD4 ? 1 : -1];

// The derived constructors and destructors still written out by hand call
// these by their symbols.
extern "C" void *__dt__13TUnk_804B0BB8Fv(void *self, s16 del);

extern "C" void *__vt__13TUnk_804B0BB8[];

#endif
