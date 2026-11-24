#include "pso/ui/window/WindowDrawContext.h"
#pragma readonly_strings on
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowQuantity.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/WindowLayout.h"

// inferred: quantity_window_layout_entries, the layout table quantity_window_layout points at.
struct QuantityWindowLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
    ValueLayoutRecord rec_1;
};

QuantityWindowLayout quantity_window_layout_entries = {
    2, 1,
    {3, {8.0f, 4.0f}, 0.7f, 0xFFFFFFFF, 0x40, NULL},
    {4, {8.0f, 4.0f}, 0.7f, 0xFFFFFFFF, 0, 0},
};

WindowDescriptor quantity_window_layout = {
    {160.0f, 27.0f}, 50100.0f, &quantity_window_layout_entries, 0x82B,
};

extern "C" {
u32 calc_text_width(void);
const char *TWindowQuantity__name = "TWindowQuantity";
void TWindowQuantity::set_position(WindowDrawContext *context) {
    draw_window_tab(context, &context->inner_x, 3, width);
}

void TWindowQuantity::render() {
    WindowDrawContext *context = setup_window_draw_context(scale);
    set_position(context);
    draw_visible_window_entries(this, &entry_list, context);
}

void TWindowQuantity::run_task() {
    ((TWindowDD *)this)->initialize_subwindow();
    update_window_entry_list(&entry_list);
}

TWindowQuantity::~TWindowQuantity() {}

TWindowQuantity::TWindowQuantity(s32 arg1) : TWindowBase((u8 *)&quantity_window_layout, (s16)arg1, (u8 *)(get_window_layout_position(0x2A))) {
    u8 *e1;
    u8 *e0;
    s32 id;
    f32 n;
    m_name = TWindowQuantity__name;
    id = get_message_text(1);
    n = (f32)calc_text_width();
    width = TWindowSubStatusDisp__sub_802877A4(24.0f + (12.0f + n));
    e0 = (u8 *)this->get_array_entry(0);
    e1 = (u8 *)this->get_array_entry(1);
    set_text_entry_string(e0, id, 0);
    ((f32 *)e1)[2] = 24.0f + (12.0f + (8.0f + n));
    target_size[0] = TWindowSubStatusDisp::get_base_y(width);
    this->save_position();
    if (TCameraCtrl::get_camera_id() > 2) {
        scale[0] = 0.75f;
        scale[1] = 0.75f;
    } else {
        scale[0] = 1.0f;
        scale[1] = 1.0f;
    }
}

TWindowQuantity *create_window_quantity(s32 client) {
    return new TWindowQuantity((saddr)client);
}

}
