#ifndef PSO_UNK_TWINDOWLAYOUTNUMBER_H
#define PSO_UNK_TWINDOWLAYOUTNUMBER_H

#include "types.h"
#include "pso/unk/TWindowLayoutRect.h"
#include "pso/unk/WindowLayoutRecord.h"

// A window part that draws a number right-aligned (case 4 of init_window_layout_entries).
class TWindowLayoutNumber : public TWindowLayoutRect {
public:
    f32 depth;
    s32 color;  // ARGB the digits are drawn in (the record's colour word)
    s32 value;

    TWindowLayoutNumber(ValueLayoutRecord *rec, s32 client);
    virtual ~TWindowLayoutNumber();
    virtual void update();
    virtual void render(WindowDrawContext *context);
    // Sets width and height from the digits of value.
    void calc_size();
};

LAYOUT_ASSERT(TWindowLayoutNumber_size, sizeof(TWindowLayoutNumber) == 0x24);

// A number part that counts towards its target (case 5 of init_window_layout_entries).
class TWindowLayoutCountingNumber : public TWindowLayoutNumber {
public:
    f32 current;
    f32 target;
    f32 step;

    TWindowLayoutCountingNumber(ValueLayoutRecord *rec, s32 client);
    virtual ~TWindowLayoutCountingNumber();
    virtual void update();
    void set_all_values(s32 value);
    void set_animated_target(s32 value, f32 frames);
    void set_status_entry_target(s32 value);
};

LAYOUT_ASSERT(TWindowLayoutCountingNumber_size, sizeof(TWindowLayoutCountingNumber) == 0x30);

extern "C" {
// The constructors, called by init_window_layout_entries.
void *__ct__19TWindowLayoutNumberFP17ValueLayoutRecordl(void *p, ValueLayoutRecord *rec, s32 client);
void *__ct__27TWindowLayoutCountingNumberFP17ValueLayoutRecordl(void *p, ValueLayoutRecord *rec, s32 client);
}

#endif
