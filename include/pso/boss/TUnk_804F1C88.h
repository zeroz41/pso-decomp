#ifndef PSO_BOSS_TUNK_804F1C88_H
#define PSO_BOSS_TUNK_804F1C88_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804F1C88 : public TObject {
public:
    virtual ~TUnk_804F1C88();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x44];
};
typedef char TUnk_804F1C88_size[sizeof(TUnk_804F1C88) == 0x60 ? 1 : -1];

#endif
