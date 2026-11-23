#ifndef PSO_UNK_TUNK_804F01A8_H
#define PSO_UNK_TUNK_804F01A8_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804F01A8 : public TObject {
public:
    TUnk_804F01A8(TObject *parent);
    virtual ~TUnk_804F01A8();
    s32 get_field_24();
    void open_confirm_dialog(s32 arg1, s32 arg2);
    void set_option_and_confirm(s32 arg1, s32 arg2);
    virtual void render();
    virtual void run_task();
    s32 state;
    s32 flags;
    s32 result;
    u32 m_28;
    uaddr m_2c;
};
LAYOUT_ASSERT(TUnk_804F01A8_size, sizeof(TUnk_804F01A8) == 0x30);

#endif
