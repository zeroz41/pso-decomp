#ifndef PSO_UI_TUNK_804E0B28_H
#define PSO_UI_TUNK_804E0B28_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804E0B28 : public TObject {
public:
    TUnk_804E0B28(TObject*parent, s32 client);
    virtual ~TUnk_804E0B28();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x2C];
    u32 m_48;
    u8 unk_4C[0x4];
};
typedef char TUnk_804E0B28_size[sizeof(TUnk_804E0B28) == 0x50 ? 1 : -1];

#endif
