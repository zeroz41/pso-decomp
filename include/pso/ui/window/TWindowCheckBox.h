#ifndef PSO_UI_WINDOW_TWINDOWCHECKBOX_H
#define PSO_UI_WINDOW_TWINDOWCHECKBOX_H
#include "types.h"
#include "pso/ui/window/TWindowMenuIconLine.h"

struct NJS_POINT2;

class TWindowCheckBox : public TWindowMenuIconLine {
public:
    TWindowCheckBox(u8 *parent, s32 client);
    virtual ~TWindowCheckBox();
    virtual void run_task();
    virtual void render();
    static TWindowCheckBox *create(const NJS_POINT2 *position, saddr size, s32 client);
    // The item of the entry at selected_index.
    s32 update_selected_item();
    void set_selected_index(s16 selected_index);
    void sub_80248994(u32 color, s32 item);
    void advance_matching_entries(s32 arg1, s32 arg2);
    void add_menu_item(s32 text, s32 item);
    void draw_status(s32 text, s32 item);
    void dispatch_without_flags(s32 text, s32 item);
    void sub_80248B7C(s32);
    void sync_level_field();
    s16 selected_index;
    u8 pad_8A[0x2];
};

TWindowCheckBox *create_check_box_window_for_local_client(const NJS_POINT2 *layout_position, const void *position);
TWindowCheckBox *create_check_box_window_on_layer(const NJS_POINT2 *position, s32 size, s32 client);

LAYOUT_ASSERT(TWindowCheckBox_size, sizeof(TWindowCheckBox) == 0x8C);

#endif
