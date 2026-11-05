#ifndef PSO_UI_TADDIALINGGC_H
#define PSO_UI_TADDIALINGGC_H

#include "types.h"
#include "pso/TObject.h"

struct TAdDialingGC : public TObject {
    virtual ~TAdDialingGC();
    void spawn_title_screen(s32);
    u32 m_1c;
    u32 m_20;
    u32 m_24;
    u32 m_28;
    u8 _pad2C[0x4];
    u16 m_30;
    u8 _pad32[0x36];
    u16 m_68;
    u8 unk_6A[0x32];
    s32 m_9c;
    u32 m_a0;
    u32 m_a4;
    static void select_dial_image(void *self, s32 x);
    virtual void render();
    virtual void run_task();
    void update_dial_state();
    void update_state();
    void update_dial_state(s32 arg1);
    void update_selection();
    void update_state_display();
    void show_guide_button();
    void update();
    static void update_dialing_display(int _w0);
    void update_status_message();
    void handle_state();
    void update_status_display();
    static int refresh_display();
    static void init_dialog();
    static void draw_dialing_status();
    void draw_if_flag_set();
    void render_if_flag_set();
    static void create();
    static void close();
    static void open();
};

typedef char TAdDialingGC_size[sizeof(TAdDialingGC) == 0xA8 ? 1 : -1];
extern "C" {
void *TAdDialingGC__ct(TAdDialingGC *ad_dialing_gc, TObject *parent);
}

#endif
