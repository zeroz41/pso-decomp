#ifndef PSO_UI_WINDOW_TWINDOWSUBMAGPHOTON_H
#define PSO_UI_WINDOW_TWINDOWSUBMAGPHOTON_H

#include "types.h"
#include "pso/ui/window/TWindowBase.h"

struct TItemData;
struct NJS_POINT2;

struct TWindowSubMagPhoton : public TWindowBase {
    TWindowSubMagPhoton(const NJS_POINT2 *position, TItemData *mag_state, s32 client);
    virtual ~TWindowSubMagPhoton();
    static const char *class_name;
    void init_photon_blast_entries();
    int get_active_flag();
    int is_cancelled();
    s32 get_selected_blast();
    virtual void render();
    u8 m_60;
    u8 selected_blast_index;
    s16 cursor_frame;
    s32 photon_blasts[3];
    TItemData *mag_item;
    void handle_cancel();
    void play_open_sound();
    void update_selection_input();
    void draw_cursor(WindowDrawContext *context);
    virtual void run_task();
    void get_cursor_origin(NJS_POINT2 *position);
};

LAYOUT_ASSERT(TWindowSubMagPhoton_blasts_offset, offsetof(TWindowSubMagPhoton, photon_blasts) == 0x64);
LAYOUT_ASSERT(TWindowSubMagPhoton_item_offset, offsetof(TWindowSubMagPhoton, mag_item) == 0x70);
LAYOUT_ASSERT(TWindowSubMagPhoton_size, sizeof(TWindowSubMagPhoton) == 0x74);
#endif
