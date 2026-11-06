#ifndef PSO_UI_WINDOW_TWINDOWEFFECTPARTY_H
#define PSO_UI_WINDOW_TWINDOWEFFECTPARTY_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowEffectParty : public TObject {
    TWindowEffectParty(TObject *arg1, s8 arg2, s8 arg3, void *arg4);
    virtual ~TWindowEffectParty();
    u8 m_1c;
    u8 m_1d;
    u8 m_1e;
    u8 _pad1F[0x1];
    void* m_20;
    u8 _pad24[0x4];
    void* m_28;
    u8 _pad2C[0x4];
    u32 m_30;
    virtual void render();
    virtual void run_task();
    s32 step_toward_target(f32 farg0, f32 farg1);
    void calc_effect_position(void *arg1);
    static void set_slot_position(s32 arg0, s32 arg1, void *arg2);
    static void *create(void *owner, s32 from, s32 to, u32 kind);
};

typedef char TWindowEffectParty_size[sizeof(TWindowEffectParty) == 0x34 ? 1 : -1];

extern "C" {
void *TWindowCtrl__sub_8024FB80(s8 i);
void *__dt__18TWindowEffectPartyFv(void *arg0, s16 arg1);
}

// --- C functions defined in TWindowEffectParty.cpp ---
extern "C" {
void *TWindowCtrl__sub_8024FB80(s8 i);
void *__dt__18TWindowEffectPartyFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
