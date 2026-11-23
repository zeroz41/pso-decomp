#ifndef PSO_UI_WINDOW_TWINDOWSETLEVELUP_H
#define PSO_UI_WINDOW_TWINDOWSETLEVELUP_H

#include "pso/system/task/TObject.h"
#include "types.h"

// Prints a player's level-up messages one per 0x16 ticks: the new level, then each gain
// ("HP +n", "TP +n", "<stat> +n") that is above zero.
class TWindowSetLevelUp : public TObject {
public:
    TWindowSetLevelUp(TObject *parent, saddr stats, s32 client);
    virtual ~TWindowSetLevelUp();
    void update_stat_messages();
    virtual void run_task();
    virtual void render();
public:
    void copy_stat_block(saddr stats);

    static const char *class_name;

    s8 state;
    u8 pad_1d;
    s16 timer;
    s32 client;
    s16 stat_gains[5];
    u8 pad_2e[0xC];
    s16 hp_gain;
    s16 tp_gain;
    u8 pad_3e[0x2];
};

LAYOUT_ASSERT(TWindowSetLevelUp_size, sizeof(TWindowSetLevelUp) == 0x40);

#endif
