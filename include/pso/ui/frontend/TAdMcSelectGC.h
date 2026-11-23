#ifndef PSO_UI_FRONTEND_TADMCSELECTGC_H
#define PSO_UI_FRONTEND_TADMCSELECTGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdMcSelectCursorGC;
class TAdChrSelSlotGC;

struct TAdMcSelectGC : public TObject {
    TAdMcSelectGC(TObject *parent);
    virtual ~TAdMcSelectGC();
    virtual void render();
    u32 m_1c;
    u8 _pad20[0x4];
    u32 m_24;
    uaddr m_28;
    uaddr m_2c;
    TAdChrSelSlotGC *slot_gc; // 0x30
    static void render(void *self);
    static void update_state();
    static s32 get_selected_slot_index();
    static void select_if_mc_present();
    virtual void run_task();
    static TAdMcSelectGC *create(TObject *parent);
    static void open();
    static void close();
    static TAdMcSelectCursorGC *get_mc_count();
};

LAYOUT_ASSERT(TAdMcSelectGC_size, sizeof(TAdMcSelectGC) == 0x34);

extern "C" {
void *__dt__13TAdMcSelectGCFv(void *arg0, s16 arg1);
}

#endif
