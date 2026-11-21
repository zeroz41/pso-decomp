#ifndef PSO_BOSS_TUNK_80484870_H
#define PSO_BOSS_TUNK_80484870_H

#include "types.h"
#include "pso/boss/TUnk_80484840.h"

// A line Vol Opt draws between two points.
class TUnk_80484870 : public TObject {
public:
    void *from;
    void *to;
    u8 pad_24[0x4];

    TUnk_80484870(void *from, void *to);
    virtual ~TUnk_80484870();
    virtual void run_task();
    virtual void render();
};

LAYOUT_ASSERT(TUnk_80484870_size, sizeof(TUnk_80484870) == 0x28);

#endif
