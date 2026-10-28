#ifndef PSO_ITEM_TUNK_8049F038_H
#define PSO_ITEM_TUNK_8049F038_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TUnk_8049F038 : public TUnk_804AF8A0 {
public:
    TUnk_8049F038(TObject *parent, s16 a, s32 b);
    virtual ~TUnk_8049F038();
    void *destroy(s16);
    virtual void *get_center();
    virtual void run_task();
    u8 unk_AC[0x4];
    s32 m_b0;
    u8 unk_B4[0x2C];
};
typedef char TUnk_8049F038_size[sizeof(TUnk_8049F038) == 0xE0 ? 1 : -1];

#endif
