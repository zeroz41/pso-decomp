#ifndef PSO_UNK_TUNK_804B7C04_H
#define PSO_UNK_TUNK_804B7C04_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804B7C04 : public TObject {
public:
    TUnk_804B7C04(f32 *position, s32 heading, s32 slot, s32 record, s32 mode, TObject *parent);
    virtual ~TUnk_804B7C04();
    virtual void run_task();
    f32 position[3];
    s32 heading;
    int m_2c;
    u16 slot;
    s32 unk_34;
    s32 unk_38;
};
LAYOUT_ASSERT(TUnk_804B7C04_size, sizeof(TUnk_804B7C04) == 0x3C);

#endif
