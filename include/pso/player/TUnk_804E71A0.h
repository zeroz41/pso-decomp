#ifndef PSO_PLAYER_TUNK_804E71A0_H
#define PSO_PLAYER_TUNK_804E71A0_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804E71A0 : public TObject {
public:
    TUnk_804E71A0();
    virtual ~TUnk_804E71A0();
    virtual void render();
    virtual void run_task();
};
typedef char TUnk_804E71A0_size[sizeof(TUnk_804E71A0) == 0x1C ? 1 : -1];

#endif
