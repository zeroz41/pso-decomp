#ifndef PSO_UI_FRONTEND_TADDIALINGGC_H
#define PSO_UI_FRONTEND_TADDIALINGGC_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"

struct TAdDialingGC : public TObject {
    static void set_dial_result(s32 status);
    static TAdDialingGC *get_instance();
    static const char *name;
    static TAdDialingGC * instance;
    TAdDialingGC(TObject *parent);
    virtual ~TAdDialingGC();
    void spawn_title_screen();
    s32 is_dial_cancel_pressed();
    u32 dial_mode;
    s32 dial_step;
    s32 frame;
    u32 m_28;
    u8 _pad2C[0x4];
    s16 selection;
    u8 _pad32[0x36];
    s16 prev_selection;
    u8 unk_6A[0x32];
    s32 status_code;
    u32 wait_frames;
    u32 dial_flags;
    static void select_dial_image(void *self, s32 x);
    virtual void render();
    virtual void run_task();
    void update_dial_state();
    void update_state();
    void update_idle_dial_state();
    void update_selection();
    void update_state_display();
    void show_guide_button();
    void update();
    static void update_dialing_display(int _w0);
    void update_status_message();
    void handle_state();
    void update_status_display();
    void refresh_display();
    void init_dialog();
    void draw_dialing_status();
    void draw_if_flag_set();
    void render_if_flag_set();
    void create();
    static void close();
    static void open();
};

LAYOUT_ASSERT(TAdDialingGC_size, sizeof(TAdDialingGC) == 0xA8);



void draw_dialing_rectangle(const NJS_POINT2 *origin, const NJS_POINT2 *size);
void dialing_render_stub(TAdDialingGC *screen);
#endif
