#ifndef PSO_UI_FRONTEND_TADPLYPLTANIMCTRLGC_H
#define PSO_UI_FRONTEND_TADPLYPLTANIMCTRLGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

// Screen position of the player plates
struct PlyPltAnimVec2 {
    f32 x, y;
};

class TAdPlyPltAnimGC;

struct TAdPlyPltAnimCtrlGC : public TObject {
    virtual ~TAdPlyPltAnimCtrlGC();
    virtual void render();
    u32 m_1c;
    u32 m_20;
    PlyPltAnimVec2 m_24;
    static void render(void *self);
    void init(void* a1);
    virtual void run_task();
    static u32 get_instance(s32 arg0);
    static TAdPlyPltAnimGC *get_table_value(int a0);
};

typedef char TAdPlyPltAnimCtrlGC_size[sizeof(TAdPlyPltAnimCtrlGC) == 0x2C ? 1 : -1];

extern "C" {
u8 *TAdPlyPltAnimCtrlGC__ct(TAdPlyPltAnimCtrlGC *arg0, s32 arg1);
void TAdPlyPltAnimCtrlGC__sub_80355168(u8 *arg0);
void *__dt__19TAdPlyPltAnimCtrlGCFv(void *arg0, s16 arg1);
u8 fn_8035510C(s32 *arg0, s32 arg1);
}

#endif
