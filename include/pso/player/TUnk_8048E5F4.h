#ifndef PSO_PLAYER_TUNK_8048E5F4_H
#define PSO_PLAYER_TUNK_8048E5F4_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_8048E5F4 : public TObject {
public:
    TUnk_8048E5F4(TObject *parent, s32 flags);
    virtual ~TUnk_8048E5F4();
    virtual void render_shadows();
    virtual void render();
    virtual void run_task();
    s32 flags;
};
LAYOUT_ASSERT(TUnk_8048E5F4_size, sizeof(TUnk_8048E5F4) == 0x20);

#endif
