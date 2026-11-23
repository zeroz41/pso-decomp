#ifndef PSO_UI_WINDOW_TWINDOWSUBMAG_H
#define PSO_UI_WINDOW_TWINDOWSUBMAG_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TWindowLoadItemTexture;

struct TWindowSubMag : public TObject {
    TWindowSubMag(TWindowMainMenu *parent, s32 client);
    virtual ~TWindowSubMag();
    virtual void run_task();
    virtual void render();
    u8 state;
    s8 m_1d;
    s8 slots;
    u8 pad_1f[0x1];
    s16 timer;
    u8 pad_22[0x2];
    u32 displayed_item;
    s32 client_id;
    uaddr mag;
    TWindowMainMenu *parent;
    void *list;
    void *list2;
    void *card;
    void *help;
    TWindowLoadItemTexture *slotwin;
    void *photon;
    void *message;

    static const char *class_name;
    void update_mag_help();
    void update_displayed_item();
    s32 count_slots();
    void set_mag_mode(s32 mag_mode);
    void *create_learned_blast_toast();
    void *create();
    void *create_action_menu(s32 id);
    saddr create_list();
    saddr setup_list();
    s32 get_selected_blast();
    void set_flag60_bit8();
    void clear_flag60_bit8();
    s32 get_mag_state();
    void start_scroll(f32 farg0);
    static void feed_mag(void* p, void* a1, void* a2);
};

LAYOUT_ASSERT(TWindowSubMag_size, sizeof(TWindowSubMag) == 0x50);
#endif
