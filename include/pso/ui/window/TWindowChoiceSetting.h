#ifndef PSO_UI_WINDOW_TWINDOWCHOICESETTING_H
#define PSO_UI_WINDOW_TWINDOWCHOICESETTING_H

#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowMenuInfomation.h"
#include "pso/unk/WindowLayoutRecord.h"

struct TWindowChoiceSetting : public TWindowMenuInfomation {
    static const char *class_name;
    TWindowChoiceSetting(void *parent, s32 rows);
    virtual ~TWindowChoiceSetting();
    void update_scroll_tween();
    s16 get_index();
    void begin_scroll(f32 height);
    void shrink_to_selected_entry();
    static TWindowChoiceSetting *create_choice_setting_window(
        const NJS_POINT2 *position, const NJS_POINT2 *extent, s32 rows);
    static void set_popup_size(const NJS_POINT2 *extent, s32 rows);
    virtual void render();
    u16 choice_flags; // bit 0: shrunk onto the selected entry
    virtual void run_task();
    u8 pad_82[0x2];
};

LAYOUT_ASSERT(TWindowChoiceSetting_size, sizeof(TWindowChoiceSetting) == 0x84);
void set_choice_setting_popup_size(const NJS_POINT2 *extent, s32 rows);
TWindowMenuInfomation *create_information_counter_window(s32 rows);

// choice_setting_popup_layout_entries, the layout table choice_setting_popup_window_descriptor
// points at (one type-9 record; set_choice_setting_popup_size fills in the row count).
struct ChoiceSettingPopupLayout {
    u32 cols;
    u32 rows;
    TypeLayoutRecord rec;
};


#endif
