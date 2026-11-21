#ifndef PSO_UNK_TUNK_804C2298_H
#define PSO_UNK_TUNK_804C2298_H
#include "types.h"
#include "pso/system/task/TObject.h"

struct TCheckMemoryCard;
struct TWindowMessage;

// The scene TAdMultiChgGameModeGC creates for game mode 3: a short list (TWindowOptionCtrl) whose
// choice picks the dial image, then the system file check and load (reading inferred).
class TUnk_804C2298 : public TObject {
public:
    TUnk_804C2298();
    void sub_801A4CA4();
    // render is the first virtual declared: the vtable comes out with it, ahead of run_task's
    // jump table.
    virtual void render();
    virtual void run_task();
    virtual ~TUnk_804C2298();
    s8 state;
    u8 pad_1d;
    s16 timer;
    // The short list choice; 4 until one is made (name inferred).
    s32 selection;
    TObject *list;
    TWindowMessage *window;
    TCheckMemoryCard *card;
};
LAYOUT_ASSERT(TUnk_804C2298_size, sizeof(TUnk_804C2298) == 0x30);

#endif
