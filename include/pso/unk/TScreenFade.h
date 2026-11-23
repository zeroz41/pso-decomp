#ifndef PSO_UNK_TSCREENFADE_H
#define PSO_UNK_TSCREENFADE_H
#include "types.h"
#include "pso/system/task/TObject.h"

// Base of the screen fade tasks: alpha moves towards its end value and the
// fade fills the screen with color.
class TScreenFade : public TObject {
public:
    TScreenFade(TObject *parent);
    // render comes first: it is the key function, so the vtable is emitted
    // with it while the destructor is defined with the Vol Opt fades.
    virtual void render();
    virtual ~TScreenFade();
    f32 alpha;
    union {
        s32 packed_color; // color[] as one word
        u8 color[4];
    };
};

#endif
