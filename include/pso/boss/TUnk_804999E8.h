#ifndef PSO_BOSS_TUNK_804999E8_H
#define PSO_BOSS_TUNK_804999E8_H
#include "types.h"
#include "pso/system/task/TObject.h"

// Base of the screen fade tasks: alpha moves towards its end value and the
// fade fills the screen with color.
class TUnk_804999E8 : public TObject {
public:
    TUnk_804999E8(TObject *parent);
    // render comes first: it is the key function, so the vtable is emitted
    // with it while the destructor is defined with the Vol Opt fades.
    virtual void render();
    virtual ~TUnk_804999E8();
    f32 alpha;
    union {
        s32 m_20;
        u8 color[3];
    };
};

#endif
