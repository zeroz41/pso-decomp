#ifndef PSO_UNK_TUNK_804F01A8_H
#define PSO_UNK_TUNK_804F01A8_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TUnk_804F01A8 : public TObject {
public:
    virtual ~TUnk_804F01A8();
    void *ct();
    s32 get_field_24();
    void open_confirm_dialog(s32 arg1, s32 arg2);
    void set_option_and_confirm(s32 arg1, s32 arg2);
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x4];
    u32 m_20;
    u32 m_24;
    u32 m_28;
    u32 m_2c;
};
typedef char TUnk_804F01A8_size[sizeof(TUnk_804F01A8) == 0x30 ? 1 : -1];

#endif
