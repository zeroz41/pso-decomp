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

struct Quantity_8026D000 {
    s32 f0;
    u8 pad4[0x18 - 4];
    void **vt;
    u8 pad1C[0x38 - 0x1C];
    f32 f38;
    u8 pad3C[0x60 - 0x3C];
    f32 f60;
    f32 f64;
    f32 f68;
};

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
saddr get_window_layout_position(s32);
const char *TWindowQuantity__name = "TWindowQuantity";
s32 draw_window_tab(s32, s32, s32, f32);

void TWindowQuantity::set_position(s32 arg1) {
    draw_window_tab(arg1, arg1 + 0x10, 3, this->m_60);
}

void render__15TWindowQuantityFv(saddr arg0) {
    saddr ctx;
    ctx = reinterpret_cast<saddr>(((TWindowBase *)arg0)->setup_window_draw_context((f32 *)(arg0 + 0x64)));
    ((TWindowQuantity *)arg0)->set_position(ctx);
    draw_visible_window_entries(
        reinterpret_cast<const void *>(arg0),
        reinterpret_cast<const WindowLayoutEntries *>((void *)(arg0 + 0x24)),
        reinterpret_cast<WindowDrawContext *>(ctx));
}

void TWindowQuantity::run_task() { ((TWindowDD *)this)->initialize_subwindow(); update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((char*)this + 0x24)); }

TWindowQuantity::~TWindowQuantity() {}

TWindowQuantity::TWindowQuantity(s32 arg1) : TWindowBase((u8 *)&quantity_window_layout, (s16)arg1, (u8 *)(get_window_layout_position(0x2A))) {
#define self ((Quantity_8026D000 *)this)
    u8 *e1;
    u8 *e0;
    s32 id;
    f32 n;
    self->f0 = (saddr)TWindowQuantity__name;
    id = get_message_text(1);
    n = (f32)calc_text_width();
    self->f60 = TWindowSubStatusDisp__sub_802877A4(24.0f + (12.0f + n));
    e0 = (u8 *)this->get_array_entry(0);
    e1 = (u8 *)this->get_array_entry(1);
    set_text_entry_string(e0, id, 0);
    *(f32 *)(e1 + 8) = 24.0f + (12.0f + (8.0f + n));
    self->f38 = TWindowSubStatusDisp::get_base_y(self->f60);
    this->save_position();
    if (TCameraCtrl::get_camera_id() > 2) {
        self->f64 = 0.75f;
        self->f68 = 0.75f;
    } else {
        self->f64 = 1.0f;
        self->f68 = 1.0f;
    }
#undef self
}

void *create_window_quantity(void *client) {
    return new TWindowQuantity((saddr)client);
}

}
