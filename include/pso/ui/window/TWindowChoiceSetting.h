#ifndef PSO_UI_WINDOW_TWINDOWCHOICESETTING_H
#define PSO_UI_WINDOW_TWINDOWCHOICESETTING_H

#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowMenuInfomation.h"

struct TWindowChoiceSetting : public TWindowMenuInfomation {
    static const char *class_name;
    TWindowChoiceSetting(void *parent, s32 rows);
    virtual ~TWindowChoiceSetting();
    void update_scroll_tween();
    s16 get_field_74();
    void begin_scroll(f32 height);
    void sub_80249144();
    static TWindowChoiceSetting *create_choice_setting_window(
        const NJS_POINT2 *position, const NJS_POINT2 *extent, s32 rows);
    static void sub_80249220(const NJS_POINT2 *extent, s32 rows);
    virtual void render();
    u16 m_80;
    virtual void run_task();
    u8 unk_82[0x2];
};

LAYOUT_ASSERT(TWindowChoiceSetting_size, sizeof(TWindowChoiceSetting) == 0x84);
void set_choice_setting_popup_size(const NJS_POINT2 *extent, s32 rows);
extern "C" {
void TWindowMenuInfomation__ct(TWindowMenuInfomation *window, u32 rows);
}
TWindowMenuInfomation *create_information_counter_window(s32 rows);

#endif
