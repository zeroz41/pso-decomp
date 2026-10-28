#ifndef PSO_ENEMY_TUNK_804E14E8_H
#define PSO_ENEMY_TUNK_804E14E8_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TUnk_804E14E8 : public TObjCollidable {
public:
    virtual ~TUnk_804E14E8();
    u8 unk_AC[0x3C];
    f32 m_e8;
    u8 unk_EC[0x4];
    void * m_f0;
    u8 unk_F4[0x4];
    s32 m_f8;
    u8 unk_FC[0x4];
    s32 m_100;
    u8 unk_104[0x4];
    s16 m_108;
    u8 unk_10A[0x2];
};
typedef char TUnk_804E14E8_size[sizeof(TUnk_804E14E8) == 0x10C ? 1 : -1];

#endif
