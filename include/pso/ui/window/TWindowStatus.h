#ifndef PSO_UI_WINDOW_TWINDOWSTATUS_H
#define PSO_UI_WINDOW_TWINDOWSTATUS_H

#include "types.h"
#include "pso/ui/window/TWindowSimpleStatus.h"
#include "pso/unk/WindowLayoutRecord.h"

struct TWindowStatus : public TWindowSimpleStatus {
    TWindowStatus(void *position, s32 client, u8 *descriptor);
    virtual ~TWindowStatus();
    static const char *class_name;
    virtual void render();
    virtual void run_task();
    void draw_background(WindowDrawContext *context);
    void update_hp_tp_values();
};

LAYOUT_ASSERT(TWindowStatus_size, sizeof(TWindowStatus) == 0x78);

TWindowSimpleStatus *create_status_window(saddr client);

struct StatusWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    ValueLayoutRecord rec_2;
    LayoutEntryCopyRecord rec_3;
    LayoutEntryCopyRecord rec_4;
    TextLayoutRecord rec_5;
    TextLayoutRecord rec_6;
    ValueLayoutRecord rec_7;
    TextLayoutRecord rec_8;
    ValueLayoutRecord rec_9;
    TextLayoutRecord rec_10;
    ValueLayoutRecord rec_11;
    TextLayoutRecord rec_12;
    ValueLayoutRecord rec_13;
    ValueLayoutRecord rec_14;
};

#endif
