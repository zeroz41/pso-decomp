#ifndef PSO_MISC_TUNK_804CC9D4_H
#define PSO_MISC_TUNK_804CC9D4_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TUnk_804CC9D4 : public TUnk_804AF8A0 {
public:
    virtual ~TUnk_804CC9D4();
    virtual void interact(s32 client);
    u8 unk_AC[0x4];
    s32 m_b0;
};
typedef char TUnk_804CC9D4_size[sizeof(TUnk_804CC9D4) == 0xB4 ? 1 : -1];

#endif
