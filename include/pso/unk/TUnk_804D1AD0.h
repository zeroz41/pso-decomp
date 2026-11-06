#ifndef PSO_UNK_TUNK_804D1AD0_H
#define PSO_UNK_TUNK_804D1AD0_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804D1AD0 : public TObject {
public:
    virtual ~TUnk_804D1AD0();
    void *destroy(s16);
    s32 create_status_category_menu();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x4];
    void * m_20;
    u8 unk_24[0x4];
    s32 m_28;
};
typedef char TUnk_804D1AD0_size[sizeof(TUnk_804D1AD0) == 0x2C ? 1 : -1];

#endif
