#ifndef PSO_UI_WINDOW_TWINDOWCHOICESETTING_H
#define PSO_UI_WINDOW_TWINDOWCHOICESETTING_H

#include "types.h"
#include "pso/ui/window/TUnk_804D0658.h"

struct TWindowChoiceSetting : public TUnk_804D0658 {
    TWindowChoiceSetting(void *parent, s32 rows);
    virtual ~TWindowChoiceSetting();
    void sub_80249078();
    s16 get_field_74();
    virtual void render();
    u16 m_80;
    virtual void run_task();
    u8 unk_82[0x2];
};

LAYOUT_ASSERT(TWindowChoiceSetting_size, sizeof(TWindowChoiceSetting) == 0x84);
extern "C" {
void TWindowMenuInfomation__ct(u8 *lobby, u32 rows);
}
s32 create_information_counter_window(s32 rows);
extern "C" {
void create_sub_window__20TWindowChoiceSettingFPvi(void *arg0, s32 title);
}

#endif
