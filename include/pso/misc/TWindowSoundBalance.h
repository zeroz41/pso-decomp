#ifndef PSO_MISC_TWINDOWSOUNDBALANCE_H
#define PSO_MISC_TWINDOWSOUNDBALANCE_H

#include "types.h"
#include "pso/misc/TWindowBase.h"

struct SoundBalanceSettings {
    u8 unknown_00[4];
    s16 music_gain;
    s8 sound_effect_gain;
};

struct TWindowSoundBalance : public TWindowBase {
    virtual ~TWindowSoundBalance();
    int is_active();
    virtual void render();
    u8 _pad1C[0x8];
    void* m_24;
    u8 _pad28[0x38];
    u8 m_60;
    s8 selection;
    s16 music_gain;
    s16 sound_effect_gain;
    void set_sound_effect_gain(s16 gain);
    void set_music_gain(s16 gain);
    void play_open_sound();
    void handle_lr_input();
    void sub_8027095C();
    virtual void run_task();
    void apply_balance(void *arg1);
    void handle_cancel();
    u8 unk_66[0x2];
};

typedef char TWindowSoundBalance_size[sizeof(TWindowSoundBalance) == 0x68 ? 1 : -1];

extern "C" {
u8 *TWindowSoundBalance__ct(u8 *arg0, s32 arg1);
void *__dt__19TWindowSoundBalanceFv(void *arg0, s16 arg1);
void render__19TWindowSoundBalanceFv(s32 arg0);
}

// --- C functions defined in TWindowSoundBalance.cpp ---
extern "C" {
u8 *TWindowSoundBalance__ct(u8 *arg0, s32 arg1);
void *__dt__19TWindowSoundBalanceFv(void *arg0, s16 arg1);
void render__19TWindowSoundBalanceFv(s32 arg0);
}
// --- end of C functions

#endif
