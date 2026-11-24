#ifndef PSO_UNK_TUNK_804A7008_H
#define PSO_UNK_TUNK_804A7008_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804A7008 : public TObject {
public:
    virtual ~TUnk_804A7008();
    int now;   // DateToSeconds of the current date, every frame
    s32 start; // the time of the last key or pad input
    u32 limit; // the idle time allowed
    u8 state;  // 1 once the warning window is shown
    u8 pad_29[0x3];
};
LAYOUT_ASSERT(TUnk_804A7008_size, sizeof(TUnk_804A7008) == 0x2C);

#endif
