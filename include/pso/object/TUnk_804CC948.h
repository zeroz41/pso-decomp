#ifndef PSO_OBJECT_TUNK_804CC948_H
#define PSO_OBJECT_TUNK_804CC948_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804CC948 : public TObject {
public:
    TUnk_804CC948(s32 arg1, s32 arg2);
    virtual ~TUnk_804CC948();
    u8 unk_1C[0x10];
    s32 m_2c;
    u8 unk_30[0x4];
};
typedef char TUnk_804CC948_size[sizeof(TUnk_804CC948) == 0x34 ? 1 : -1];

#endif
