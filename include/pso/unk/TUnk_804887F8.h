#ifndef PSO_UNK_TUNK_804887F8_H
#define PSO_UNK_TUNK_804887F8_H
#include "types.h"
#include "pso/unk/TUnk_80488E00.h"

class TUnk_804887F8 : public TUnk_80488E00 {
public:
    virtual ~TUnk_804887F8();
    virtual void update_follow_flags();
    void*init();
    u8 unk_110[0x4];
    int m_114;
    u8 unk_118[0x18];
};
typedef char TUnk_804887F8_size[sizeof(TUnk_804887F8) == 0x130 ? 1 : -1];

#endif
