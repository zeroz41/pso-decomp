#ifndef PSO_ITEM_TUNK_804C4498_H
#define PSO_ITEM_TUNK_804C4498_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804C4498 : public TObject {
public:
    virtual ~TUnk_804C4498();
    void sub_801D5884(u8);
    s32 reset_placement_search_ring();
    s32 step_placement_search();
    u8 unk_1C[0x1];
    u8 m_1d;
    u8 unk_1E[0x2];
    u16 m_20;
    u8 unk_22[0x2];
    s32 m_24;
    u8 unk_28[0x1C];
    f32 m_44;
    u8 unk_48[0x4];
    f32 m_4c;
    u8 unk_50[0x4];
};

#endif
