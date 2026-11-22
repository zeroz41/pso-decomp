#ifndef PSO_UNK_TUNK_804887F8_H
#define PSO_UNK_TUNK_804887F8_H
#include "types.h"
#include "pso/camera/TCameraFollow.h"

class TUnk_804887F8 : public TCameraFollow {
public:
    TUnk_804887F8();
    virtual ~TUnk_804887F8();
    virtual void run_task();
    virtual void update_follow_flags();
    void update_target_follow();
    s32 m_110;
    int m_114;
    u8 unk_118[0x18];
};
LAYOUT_ASSERT(TUnk_804887F8_size, sizeof(TUnk_804887F8) == 0x130);

#endif
