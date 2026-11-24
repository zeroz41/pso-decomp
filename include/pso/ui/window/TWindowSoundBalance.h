#ifndef PSO_UI_WINDOW_TWINDOWSOUNDBALANCE_H
#define PSO_UI_WINDOW_TWINDOWSOUNDBALANCE_H

#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowBase.h"

struct SoundBalanceSettings {
    u8 unknown_00[4];
    s16 music_gain;
    s8 sound_effect_gain;
};

struct TWindowSoundBalance : public TWindowBase {
    TWindowSoundBalance(const NJS_POINT2 *position);
    virtual ~TWindowSoundBalance();
    int is_active();
    virtual void render();
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
    void apply_balance(WindowDrawContext *context);
    void handle_cancel();
    u8 unk_66[0x2];
};

LAYOUT_ASSERT(TWindowSoundBalance_size, sizeof(TWindowSoundBalance) == 0x68);

extern "C" {
}

// --- C functions defined in TWindowSoundBalance.cpp ---
extern "C" {
}
// --- end of C functions

#endif
