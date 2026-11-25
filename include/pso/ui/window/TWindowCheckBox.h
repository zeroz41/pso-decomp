#ifndef PSO_UI_WINDOW_TWINDOWCHECKBOX_H
#define PSO_UI_WINDOW_TWINDOWCHECKBOX_H
#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

class TWindowCheckBox : public TWindowMenuIconLine {
public:
    TWindowCheckBox(u8 *parent, s32 client);
    virtual ~TWindowCheckBox();
    virtual void run_task();
    virtual void render();
    void advance_all_entries(s32);
    void sub_80248B7C(s32);
    void sync_level_field();
    u8 unk_88[0x4];
};
LAYOUT_ASSERT(TWindowCheckBox_size, sizeof(TWindowCheckBox) == 0x8C);

#endif
