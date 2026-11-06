#ifndef PSO_PLAYER_TUNK_8048E5F4_H
#define PSO_PLAYER_TUNK_8048E5F4_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_8048E5F4 : public TObject {
public:
    virtual ~TUnk_8048E5F4();
    void *init_subobject(void *, void *);
    virtual void render_shadows();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x4];
};
typedef char TUnk_8048E5F4_size[sizeof(TUnk_8048E5F4) == 0x20 ? 1 : -1];

#endif
