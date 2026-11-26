#ifndef PSO_UI_FRONTEND_TADYESNOBASEGC_H
#define PSO_UI_FRONTEND_TADYESNOBASEGC_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"

struct TAdYesNoBaseGC : public TObject {
    TAdYesNoBaseGC(TObject *parent);
    virtual ~TAdYesNoBaseGC();
    virtual void vfunc_6() = 0;
    virtual void vfunc_7() = 0;
    virtual void vfunc_8() {}
    virtual void vfunc_9() {}
    virtual saddr vfunc_10() = 0;  // the prompt text: get_localized_text_entry
    virtual void vfunc_11();
    virtual void vfunc_12();
    s32 sub_8032C0B4();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    u32 m_28;
    u32 m_2c;
    NJS_POINT2 message_position;
    NJS_POINT2 message_size;
    uaddr m_40;
    uaddr m_44;
    s32 create_menu_window();
    void init_parts(void *position, void *size);
};

LAYOUT_ASSERT(TAdYesNoBaseGC_size, sizeof(TAdYesNoBaseGC) == 0x48);
#endif
