#ifndef PSO_MISC_TUNK_804B27D8_H
#define PSO_MISC_TUNK_804B27D8_H
#include "types.h"
#include "pso/object/TObjMapObject.h"

class TUnk_804B27D8 : public TObjMapObject {
public:
    virtual ~TUnk_804B27D8();
    virtual s32 update_active_state();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_6(s16 *, s32);
    void *init();
    void *destroy_key_object(s16);
    virtual void render();
    virtual void run_task();
    u8 unk_C8[0x4];
    s32 m_cc;
    u8 unk_D0[0x4];
    s32 m_d4;
    u8 unk_D8[0x4];
    u32 m_dc;
    s32 m_e0;
};

#endif
