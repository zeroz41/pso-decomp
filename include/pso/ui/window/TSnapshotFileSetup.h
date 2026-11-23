#ifndef PSO_UI_WINDOW_TSNAPSHOTFILESETUP_H
#define PSO_UI_WINDOW_TSNAPSHOTFILESETUP_H
#include "types.h"
#include "pso/system/task/TObject.h"

// The option menu's Snapshot file check: asks to create the file on the Memory Card in Slot B and walks
// through the card errors (text group 0x24).
class TSnapshotFileSetup : public TObject {
public:
    TSnapshotFileSetup(TObject *parent);
    virtual ~TSnapshotFileSetup();
    s32 get_result();
    void open_confirm_dialog(s32 arg1, s32 arg2);
    void set_option_and_confirm(s32 arg1, s32 arg2);
    virtual void render();
    virtual void run_task();
    s32 state;
    s32 flags;
    s32 result;            // 1 file ready, 2 cancelled, 3 manage the Memory Card
    u32 shown_message;     // the text group 0x24 entry on screen
    uaddr message_window;  // TWindowMessageYesNo
};
LAYOUT_ASSERT(TSnapshotFileSetup_size, sizeof(TSnapshotFileSetup) == 0x30);

#endif
