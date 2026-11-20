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
    u32 mag;
    u32 parent;
    u32 list;
    u32 list2;
    u32 card;
    u32 help;
    u32 slotwin;
    u32 photon;
    u32 message;
    void update_mag_help();
    void update_displayed_item();
    s32 count_slots();
    void set_mag_mode(s32 arg1);
    void *create_learned_blast_toast();
    void *create();
    void *create_action_menu(s32 id);
    s32 create_list();
    s32 setup_list();
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

LAYOUT_ASSERT(TWindowSubMag_size, sizeof(TWindowSubMag) == 0x50);
#endif
