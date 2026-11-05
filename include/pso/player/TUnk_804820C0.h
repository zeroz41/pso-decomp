#ifndef PSO_PLAYER_TUNK_804820C0_H
#define PSO_PLAYER_TUNK_804820C0_H
#include "types.h"
#include "pso/TObject.h"

class TUnk_804820C0 : public TObject {
public:
    virtual ~TUnk_804820C0();
    void *init_base();
    s32 m_1c;  // TUnk_80482090::run_task counts frames in it up to 0xA0
};

#endif
