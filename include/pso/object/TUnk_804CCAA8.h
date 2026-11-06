#ifndef PSO_OBJECT_TUNK_804CCAA8_H
#define PSO_OBJECT_TUNK_804CCAA8_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804CCAA8 : public TObject {
public:
    virtual ~TUnk_804CCAA8();
    virtual void run_task();
    u8 unk_1C[0x4];
    s32 m_20;
    u8 unk_24[0x28];
    s32 m_4c;
    u8 unk_50[0x4];
    u8 * m_54;
    u8 unk_58[0x4];
    f32 m_5c;
    u8 unk_60[0x4];
};
typedef char TUnk_804CCAA8_size[sizeof(TUnk_804CCAA8) == 0x64 ? 1 : -1];

#endif
