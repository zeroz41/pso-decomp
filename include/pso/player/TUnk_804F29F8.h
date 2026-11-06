#ifndef PSO_PLAYER_TUNK_804F29F8_H
#define PSO_PLAYER_TUNK_804F29F8_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804F29F8 : public TObject {
public:
    virtual ~TUnk_804F29F8();
    virtual void render();
    virtual void run_task();
};
typedef char TUnk_804F29F8_size[sizeof(TUnk_804F29F8) == 0x1C ? 1 : -1];

#endif
