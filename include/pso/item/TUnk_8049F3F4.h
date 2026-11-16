#ifndef PSO_ITEM_TUNK_8049F3F4_H
#define PSO_ITEM_TUNK_8049F3F4_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_8049F3F4 : public TObject {
public:
    virtual ~TUnk_8049F3F4();
    void *init(void *, void *, void *, void *);
    virtual void run_task();
    u8 unk_1C[0x4];
    s32 m_20;
    u8 unk_24[0x4];
    s32 m_28;
    u8 unk_2C[0x10];
    u32 m_3c;
    u8 unk_40[0x4];
};
typedef char TUnk_8049F3F4_size[sizeof(TUnk_8049F3F4) == 0x44 ? 1 : -1];

// --- C functions defined in TUnk_8049F3F4.cpp ---
extern "C" {
void *__dt__13TUnk_8049F3F4Fv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
