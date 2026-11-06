#ifndef PSO_UI_FRONTEND_TADYESNOBASEGC_H
#define PSO_UI_FRONTEND_TADYESNOBASEGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdYesNoBaseGC : public TObject {
    virtual ~TAdYesNoBaseGC();
    virtual void vfunc_6() = 0;
    virtual void vfunc_7() = 0;
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10() = 0;
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13() = 0;
    s32 sub_8032C0B4();
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    u32 m_28;
    u32 m_2c;
    u8 unk_30[0x4];
    f32 m_34;
    u8 unk_38[0x4];
    f32 m_3c;
    u32 m_40;
    u32 m_44;
    s32 create_menu_window();
    void init_parts(void *arg1, void *arg2);
};

typedef char TAdYesNoBaseGC_size[sizeof(TAdYesNoBaseGC) == 0x48 ? 1 : -1];
#endif
