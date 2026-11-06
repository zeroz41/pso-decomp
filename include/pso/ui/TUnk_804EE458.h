#ifndef PSO_UI_TUNK_804EE458_H
#define PSO_UI_TUNK_804EE458_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804EE458 : public TObject {
public:
    TUnk_804EE458(int a1);
    virtual ~TUnk_804EE458();
    s32 sub_8033596C();
    u8 unk_1C[0x4];
    int m_20;
    u8 unk_24[0x4];
    float m_28;
    u8 unk_2C[0x4];
    float m_30;
    u8 unk_34[0x4];
    int m_38;
};
typedef char TUnk_804EE458_size[sizeof(TUnk_804EE458) == 0x3C ? 1 : -1];

#endif
