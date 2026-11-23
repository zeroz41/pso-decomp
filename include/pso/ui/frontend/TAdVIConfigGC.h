#ifndef PSO_UI_FRONTEND_TADVICONFIGGC_H
#define PSO_UI_FRONTEND_TADVICONFIGGC_H

#include "types.h"
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdYesNoBaseGC.h"

struct TAdVIConfigGC : public TAdYesNoBaseGC {
    TAdVIConfigGC(TObject *parent);
    virtual ~TAdVIConfigGC();
    u32 m_48;
    u8 *init(const Vec *position, f32 radius);
    virtual void render();
    void set_field48_clear_global();
    static void enable_progressive_mode(void * _w0);
    static int disable_progressive_mode(void* _w0);
    virtual void run_task();
    static s32 draw_with_layer(s32 arg0, s32 size, s32 client);
    void set_field_2c(s32 v);
    static void apply_config_if_valid(s32 arg0, s32 arg1);
    void open_player_names_window();
    s32 get_field_14();
    void update_visibility();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual saddr vfunc_10();
    static void *destroy(void *, s16);
};

LAYOUT_ASSERT(TAdVIConfigGC_size, sizeof(TAdVIConfigGC) == 0x4C);

extern s32 logo_clear_flag;

#endif
