#ifndef PSO_UI_FRONTEND_TADVICONFIGGC_H
#define PSO_UI_FRONTEND_TADVICONFIGGC_H

#include "types.h"

struct NJS_POINT2;
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdYesNoBaseGC.h"

struct TAdVIConfigGC : public TAdYesNoBaseGC {
    static const char *class_name;
    TAdVIConfigGC(TObject *parent);
    virtual ~TAdVIConfigGC();
    u32 m_48;
    u8 *init(const Vec *position, f32 radius);
    virtual void render();
    void set_field48_clear_global();
    void enable_progressive_mode();
    static void disable_progressive_mode();
    virtual void run_task();
    void set_default_choice(s32 v);
    void open_player_names_window();
    s32 get_field_14();
    void update_visibility();
    virtual void on_accept();
    virtual void on_cancel();
    virtual const char *get_message_text();
    static void *destroy(void *, s16);
};

LAYOUT_ASSERT(TAdVIConfigGC_size, sizeof(TAdVIConfigGC) == 0x4C);

extern s32 logo_clear_flag;

#endif
