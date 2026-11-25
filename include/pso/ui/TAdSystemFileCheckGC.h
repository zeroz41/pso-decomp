#ifndef PSO_UI_TADSYSTEMFILECHECKGC_H
#define PSO_UI_TADSYSTEMFILECHECKGC_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TAdSystemFileCheckGC : public TObject {
public:
    TAdSystemFileCheckGC(TObject *object);
    virtual ~TAdSystemFileCheckGC();
    virtual void run_task();
    u8 unk_1C[0x4];
    s32 m_20;
    u8 unk_24[0x4];
    s32 m_28;
    u8 unk_2C[0x4];
    s32 m_30;
    u8 unk_34[0x4];
};
LAYOUT_ASSERT(TAdSystemFileCheckGC_size, sizeof(TAdSystemFileCheckGC) == 0x38);

#endif
