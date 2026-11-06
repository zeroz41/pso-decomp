#ifndef PSO_PLAYER_TUNK_804F2A10_H
#define PSO_PLAYER_TUNK_804F2A10_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804F2A10 : public TObject {
public:
    virtual ~TUnk_804F2A10();
    void*init_vtable_804F2A10();
    virtual void render();
    virtual void run_task();
};
typedef char TUnk_804F2A10_size[sizeof(TUnk_804F2A10) == 0x1C ? 1 : -1];

#endif
