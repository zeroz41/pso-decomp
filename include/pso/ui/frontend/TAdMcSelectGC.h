#ifndef PSO_UI_FRONTEND_TADMCSELECTGC_H
#define PSO_UI_FRONTEND_TADMCSELECTGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdMcSelectGC : public TObject {
    virtual ~TAdMcSelectGC();
    virtual void render();
    u32 m_1c;
    u8 _pad20[0x4];
    u32 m_24;
    u32 m_28;
    u32 m_2c;
    u32 m_30;
    void init_slot(s32 arg1, void *arg2);
    static void render(void *self);
    static void update_state();
    static s32 get_selected_slot_index();
    static void select_if_mc_present();
    virtual void run_task();
    static void *create(void *arg0);
    static void open();
    static void close();
    static int get_mc_count();
    s32 get_slot_index();
    void set_field_13c(s32 v);
    void set_field_0x1c(s32 v);
    void set_select_index(s32 v);
    void set_field_134(s32 arg1);
    void set_field_24(s32 v);
    void set_field20(f32 v);
    void set_field_20(s32 v);
    void set_float_1c(f32 v);
};

typedef char TAdMcSelectGC_size[sizeof(TAdMcSelectGC) == 0x34 ? 1 : -1];

extern "C" {
void *__dt__13TAdMcSelectGCFv(void *arg0, s16 arg1);
}

#endif
