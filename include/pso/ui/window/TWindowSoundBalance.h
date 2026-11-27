#ifndef PSO_UI_WINDOW_TWINDOWSOUNDBALANCE_H
#define PSO_UI_WINDOW_TWINDOWSOUNDBALANCE_H

#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/unk/WindowLayoutRecord.h"

struct TWindowSoundBalance : public TWindowBase {
    TWindowSoundBalance(const NJS_POINT2 *position);
    virtual ~TWindowSoundBalance();
    static const char *class_name;
    // Bit 0 of result_flags: the balance was confirmed.
    int is_active();
    // Bit 1 of result_flags: the window was left with the cancel button.
    int is_cancelled();
    s32 get_music_gain();
    s32 get_sound_effect_gain();
    virtual void render();
    u8 result_flags;  // 0x1 done, 0x2 cancelled (TWindowOptionCtrl polls them)
    s8 selection;
    s16 music_gain;
    s16 sound_effect_gain;
    void set_sound_effect_gain(s16 gain);
    void set_music_gain(s16 gain);
    void play_open_sound();
    void handle_lr_input();
    void handle_gain_input();
    virtual void run_task();
    void apply_balance(WindowDrawContext *context);
    void handle_cancel();
    u8 pad_66[0x2];
};

LAYOUT_ASSERT(TWindowSoundBalance_size, sizeof(TWindowSoundBalance) == 0x68);


// GaugeLayoutRecord, the type 1 record (0x24 bytes) behind entries 2 and 3, which
// set_music_gain (entry 2) and set_sound_effect_gain (entry 3) drive as gauges (TWindowStatusGauge::target).
struct GaugeLayoutRecord {
    s32 type;
    f32 pos[2];
    f32 pad_0C;
    u32 pad_10;
    s32 pad_14;
    f32 pad_18;
    f32 pad_1C;
    f32 pad_20;
};

// window_sound_balance_layout_entries, the layout table window_sound_balance_settings
// points at (the "BGM" and "SE" labels and their two gauges).
struct SoundBalanceWindowLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    GaugeLayoutRecord rec_2;
    GaugeLayoutRecord rec_3;
};


#endif
