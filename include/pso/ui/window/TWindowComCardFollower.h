#ifndef PSO_UI_WINDOW_TWINDOW_COM_CARD_FOLLOWER_H
#define PSO_UI_WINDOW_TWINDOW_COM_CARD_FOLLOWER_H
#include "types.h"
#include "pso/ui/window/TWindowBase.h"

#include "pso/system/NinjaTypes.h"

class TWindowComCardFollower : public TWindowBase {
public:
    TWindowComCardFollower(TWindowBase *parent, NJS_POINT2 *offset, s32 column, s32 mode, s32 client);
    virtual ~TWindowComCardFollower();
    void set_selected_index(s32 mode);
    void set_column(s32 column);
    virtual void render();
    virtual void run_task();
    TWindowBase *parent_window;
    NJS_POINT2 offset;
    s32 card_column;
    s32 help_mode;
};
LAYOUT_ASSERT(ComCardFollowerParentOffset, offsetof(TWindowComCardFollower, parent_window) == 0x60);
LAYOUT_ASSERT(ComCardFollowerPositionOffset, offsetof(TWindowComCardFollower, offset) == 0x64);
LAYOUT_ASSERT(ComCardFollowerModeOffset, offsetof(TWindowComCardFollower, help_mode) == 0x70);
LAYOUT_ASSERT(TWindowComCardFollower_size, sizeof(TWindowComCardFollower) == 0x74);

#endif
