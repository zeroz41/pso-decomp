#ifndef PSO_UI_FRONTEND_TADPLYPLTANIMGC_H
#define PSO_UI_FRONTEND_TADPLYPLTANIMGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdPlyPltAnimGC : public TObject {
    virtual ~TAdPlyPltAnimGC();
    virtual void run_task();
    virtual void render();
    u8 unk_1C[0x34];
    u8 m_6c;
    u8 _pad6D[0x3];
    u32 m_70;
    u32 m_74;
    u32 m_78;
    u8 unk_60[0x1C];
};

typedef char TAdPlyPltAnimGC_size[sizeof(TAdPlyPltAnimGC) == 0x7C ? 1 : -1];

struct TAdPlyPltAnimCtrlGC;
extern "C" {
void TAdPlyPltAnimCtrlGC__sub_80355D38(TAdPlyPltAnimCtrlGC *arg0);
s32 TAdPlyPltAnimGC__ct(int arg0, void *arg1, void *arg2);
void TAdPlyPltAnimGC__sub_8035615C(void);
void *__dt__15TAdPlyPltAnimGCFv(void *arg0, s16 arg1);
s32 get_or_create__15TAdPlyPltAnimGCFii(s32 arg0, s32 arg1);
}

#endif
