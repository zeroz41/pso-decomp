#ifndef PSO_UI_WINDOW_TWINDOWSUBMAG_H
#define PSO_UI_WINDOW_TWINDOWSUBMAG_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowSubMag : public TObject {
    virtual ~TWindowSubMag();
    virtual void render();
    u8 m_1c;
    u8 m_1d;
    u8 m_1e;
    u8 _pad1F[0x1];
    s16 m_20;
    u8 _pad22[0x2];
    u32 m_24;
    u32 m_28;
    u32 m_2c;
    u32 m_30;
    u32 m_34;
    u32 m_38;
    u32 m_3c;
    u32 m_40;
    u32 m_44;
    u32 m_48;
    u32 m_4c;
    void update_mag_help();
    void update_displayed_item();
    s32 count_slots();
    void set_mag_mode(s32 arg1);
    void *create_learned_blast_toast();
    void *create();
    void *create_action_menu(s32 id);
    s32 create_list();
    s32 setup_list();
    static void run_task(void *arg0);
    s32 get_selected_blast();
    void set_flag60_bit8();
    void clear_flag60_bit8();
    s32 get_mag_state();
    void update_help_item();
    void set_mag_slot_state(s32 arg1);
    void init_and_setup(void* a1);
    void start_scroll(f32 farg0);
    static void feed_mag(void* p, void* a1, void* a2);
};

typedef char TWindowSubMag_size[sizeof(TWindowSubMag) == 0x50 ? 1 : -1];
#endif
