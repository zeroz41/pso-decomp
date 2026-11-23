#include "pso/ui/window/WindowDrawContext.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowMainMenu.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDeposit.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

#include "pso/unk/WindowLayoutRecord.h"
#include "pso/unk/TUnk_804CF998.h"
#include "pso/ui/window/WindowLayout.h"

// inferred: window_deposit_layout_entries, the layout table window_deposit_layout points at.
struct DepositWindowLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
    ValueLayoutRecord rec_1;
};

DepositWindowLayout window_deposit_layout_entries = {
    2, 1,
    {3, {8.0f, 4.0f}, 0.7f, 0xFFFFFFFF, 0x40, NULL},
    {4, {8.0f, 4.0f}, 0.7f, 0xFFFFFFFF, 0, 0},
};

WindowDescriptor window_deposit_layout = {
    {160.0f, 27.0f}, 50100.0f, &window_deposit_layout_entries, 0x82B,
};

#pragma push
#pragma readonly_strings on
const char *TWindowDeposit::class_name = "TWindowDeposit";
#pragma pop

extern "C" {

void TWindowDeposit::render_status(WindowDrawContext *context) {
    draw_window_tab(context, &context->inner_x, 3, this->width);
}

void TWindowDeposit::render() {
    WindowDrawContext *context = setup_window_draw_context(scale);
    render_status(context);
    draw_visible_window_entries(this, &entry_list, context);
}

void TWindowDeposit::run_task() { ((TWindowDD *)this)->initialize_subwindow(); update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((char*)this + 0x24)); }

TWindowDeposit::~TWindowDeposit() {}
TWindowDeposit::TWindowDeposit(s16 client)
    : TWindowBase((u8 *)&window_deposit_layout, client, (u8 *)get_window_layout_position(0x29)) {
    u8 *label;
    TUnk_804CF998 *amount;
    f32 text_width;
    saddr text;

    m_name = class_name;
    text = get_message_text(2);
    text_width = (f32)calc_text_width((char *)text);
    width = TWindowSubStatusDisp__sub_802877A4(96.0f + (12.0f + text_width));
    label = (u8 *)get_array_entry(0);
    amount = (TUnk_804CF998 *)get_array_entry(1);
    set_text_entry_string(label, text, 0);
    amount->x = 96.0f + (12.0f + (8.0f + text_width));
    target_size[0] = TWindowSubStatusDisp::get_base_y(width);
    save_position();
    if (TCameraCtrl::get_camera_id() > 2) {
        scale[0] = 0.75f;
        scale[1] = 0.75f;
    } else {
        scale[0] = 1.0f;
        scale[1] = 1.0f;
    }
}

}
