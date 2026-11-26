#ifndef PSO_UI_WINDOW_TWINDOWPARTYSTATUS_H
#define PSO_UI_WINDOW_TWINDOWPARTYSTATUS_H

#include "types.h"
#include "pso/ui/window/TWindowSimpleStatus.h"
#include "pso/unk/WindowLayoutRecord.h"

struct TWindowPartyStatus : public TWindowSimpleStatus {
    TWindowPartyStatus(s32 slot, u8 *descriptor);
    virtual ~TWindowPartyStatus();
    static const char *class_name;
    virtual void render();
    void draw();
    void draw_background(WindowDrawContext *context);
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowPartyStatus_size, sizeof(TWindowPartyStatus) == 0x78);

void *create_party_status_window(s32 slot_offset);

struct PartyStatusWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    ValueLayoutRecord rec_2;
    LayoutEntryCopyRecord rec_3;
    TextLayoutRecord rec_4;
};

#endif
