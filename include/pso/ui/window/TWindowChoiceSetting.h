#ifndef PSO_UI_WINDOW_TWINDOWCHOICESETTING_H
#define PSO_UI_WINDOW_TWINDOWCHOICESETTING_H

#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowMenuInfomation.h"

struct TWindowChoiceSetting : public TWindowMenuInfomation {
    TWindowChoiceSetting(void *parent, s32 rows);
    virtual ~TWindowChoiceSetting();
    void sub_80249078();
    s16 get_field_74();
    void begin_scroll(f32 height);
    virtual void render();
    u16 m_80;
    virtual void run_task();
    u8 unk_82[0x2];
};

LAYOUT_ASSERT(TWindowChoiceSetting_size, sizeof(TWindowChoiceSetting) == 0x84);
extern "C" {
void TWindowMenuInfomation__ct(TWindowMenuInfomation *window, u32 rows);
void fn_80268C5C(const NJS_POINT2 *extent, s32 rows);
TWindowChoiceSetting *create_choice_setting_window__17TWindowSubComCardFiii(
    const NJS_POINT2 *position, const NJS_POINT2 *extent, s32 rows);
void render__21TWindowMenuInfomationFv(u8 *arg0);
}
TWindowMenuInfomation *create_information_counter_window(s32 rows);

#endif
