#ifndef PSO_MISC_TUNK_804B7C1C_H
#define PSO_MISC_TUNK_804B7C1C_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TUnk_804B7C1C : public TObjCollidable {
public:
    virtual ~TUnk_804B7C1C();
    virtual void render();
    virtual void run_task();
    u8 unk_AC[0x4];
    s32 m_b0;
    u8 unk_B4[0x4];
};
typedef char TUnk_804B7C1C_size[sizeof(TUnk_804B7C1C) == 0xB8 ? 1 : -1];

#endif
