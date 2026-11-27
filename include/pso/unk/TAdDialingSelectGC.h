#ifndef PSO_UNK_TADDIALINGSELECTGC_H
#define PSO_UNK_TADDIALINGSELECTGC_H
#include "types.h"
#include "pso/system/task/TObject.h"

struct TCheckMemoryCard;
struct TWindowMessage;
struct TWindowOptionCtrl;

// The scene TAdMultiChgGameModeGC creates for game mode 3: a short list (TWindowOptionCtrl) whose
// choice picks the dial image, then the system file check and load (reading inferred).
class TAdDialingSelectGC : public TObject {
public:
    TAdDialingSelectGC();
    void update_dial_image();
    // render is the first virtual declared: the vtable comes out with it, ahead of run_task's
    // jump table.
    virtual void render();
    virtual void run_task();
    virtual ~TAdDialingSelectGC();
    s8 state;
    u8 pad_1d;
    s16 timer;
    // The short list choice; 4 until one is made (name inferred).
    s32 selection;
    TWindowOptionCtrl *option_window;
    TWindowMessage *window;
    TCheckMemoryCard *card;
};
LAYOUT_ASSERT(TAdDialingSelectGC_size, sizeof(TAdDialingSelectGC) == 0x30);

typedef struct DialingWindowPos {
    f32 a, b;
} DialingWindowPos;

// The idle timeout setting of the client's character save record.
s32 get_idle_timeout_setting(u32 client);

#endif
