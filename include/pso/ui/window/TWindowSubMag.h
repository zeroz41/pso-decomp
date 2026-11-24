#ifndef PSO_UI_WINDOW_TWINDOWSUBMAG_H
#define PSO_UI_WINDOW_TWINDOWSUBMAG_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
struct TWindowLoadItemTexture;
struct TWindowHelpItem;
struct TWindowSubMagPhoton;
struct TItemData;

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
    TItemData *mag;
    TWindowMainMenu *parent;
    void *list;
    void *list2;
    void *card;
    TWindowHelpItem *help;
    TWindowLoadItemTexture *slotwin;
    TWindowSubMagPhoton *photon;
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
    static void feed_mag(void* p, void* a1, void* a2);
};

LAYOUT_ASSERT(TWindowSubMag_size, sizeof(TWindowSubMag) == 0x50);
#endif
