#ifndef PSO_UNK_TUNK_80488B68_H
#define PSO_UNK_TUNK_80488B68_H
#include "types.h"
#include "pso/unk/TUnk_80488A28.h"

class TUnk_80488B68 : public TUnk_80488A28 {
public:
    TUnk_80488B68();
    virtual ~TUnk_80488B68();
    virtual void post_update_view();
    virtual void run_task();
    u8 unk_6C[0x4];
    float m_70;
    u8 unk_74[0x4];
    float m_78;
    u8 unk_7C[0x4];
    float m_80;
    u8 unk_84[0x4];
    int m_88;
    u8 unk_8C[0x4];
    int m_90;
    u8 unk_94[0x4];
    unsigned char m_98;
    u8 unk_99[0x1];
    short m_9a;
    u8 unk_9C[0x4];
    float m_a0;
};
typedef char TUnk_80488B68_size[sizeof(TUnk_80488B68) == 0xA4 ? 1 : -1];

#endif
