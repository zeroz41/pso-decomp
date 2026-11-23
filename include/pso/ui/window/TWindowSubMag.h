#ifndef PSO_UI_WINDOW_TWINDOWSUBMAG_H
#define PSO_UI_WINDOW_TWINDOWSUBMAG_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowSubMag : public TObject {
    virtual ~TWindowSubMag();
    virtual void run_task();
    virtual void render();
    u8 state;
    u8 m_1d;
    u8 slots;
    u8 _pad1F[0x1];
    s16 timer;
    u8 _pad22[0x2];
    u32 displayed_item;
    u32 client_id;
    uaddr mag;
    u32 parent;
    uaddr list;
    uaddr list2;
    uaddr card;
    uaddr help;
    uaddr slotwin;
    uaddr photon;
    uaddr message;
    void update_mag_help();
    void update_displayed_item();
    s32 count_slots();
    void set_mag_mode(s32 arg1);
    void *create_learned_blast_toast();
    void *create();
    void *create_action_menu(s32 id);
    saddr create_list();
    s32 setup_list();
    s32 get_selected_blast();
    void set_flag60_bit8();
    void clear_flag60_bit8();
    s32 get_mag_state();
    void init_and_setup(void* a1);
    void start_scroll(f32 farg0);
    static void feed_mag(void* p, void* a1, void* a2);
};

LAYOUT_ASSERT(TWindowSubMag_size, sizeof(TWindowSubMag) == 0x50);
#endif
