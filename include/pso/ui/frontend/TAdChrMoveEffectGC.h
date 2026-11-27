#ifndef PSO_UI_FRONTEND_TADCHRMOVEEFFECTGC_H
#define PSO_UI_FRONTEND_TADCHRMOVEEFFECTGC_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"

// What setup_move_effect_params hands to every entry: where it starts and ends, its colour at
// each end (RGBA) and its size.
struct ChrMoveEffectParams {
    NJS_POINT2 start;
    NJS_POINT2 end;
    u8 start_color[4];
    u8 end_color[4];
    NJS_POINT2 size;
};

struct ChrMoveEffectEntry : public ChrMoveEffectParams {
    NJS_POINT2 current;
    u8 current_color[4];
    u8 alpha;
    u8 pad_2D[3];
    u32 flags;          // bit 0: moving
    s32 frame;
};

LAYOUT_ASSERT(ChrMoveEffectEntry_size, sizeof(ChrMoveEffectEntry) == 0x38);

struct TAdChrMoveEffectGC : public TObject {
    static const char *class_name;
    TAdChrMoveEffectGC(TObject *parent);
    virtual ~TAdChrMoveEffectGC();
    void draw_entries();
    s32 step;
    s32 active;
    virtual void render();
    void reset_effect_entries();
    void clear_entries();
    void setup_move_effect_params(s32 from_index, s32 to_index);
    void start_move_effect(ChrMoveEffectParams *params);
    static void copy_effect_data(void *dest, void *source);
    virtual void run_task();
    ChrMoveEffectEntry entries[16];
};

LAYOUT_ASSERT(TAdChrMoveEffectGC_size, sizeof(TAdChrMoveEffectGC) == 0x3A4);

extern TAdChrMoveEffectGC *chr_move_effect_instance;

// A view that starts at the slot offset i * 0x38 of the object: the entry begins 0x24 into it.
struct ChrMoveEffectSlot {
    u8 pad_0[0x24];
    ChrMoveEffectEntry entry;
};

#endif
