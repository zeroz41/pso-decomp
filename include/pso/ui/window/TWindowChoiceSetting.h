#ifndef PSO_UI_WINDOW_TWINDOWCHOICESETTING_H
#define PSO_UI_WINDOW_TWINDOWCHOICESETTING_H

#include "types.h"
#include "pso/ui/window/TUnk_804D0658.h"

struct TWindowChoiceSetting : public TUnk_804D0658 {
    virtual ~TWindowChoiceSetting();
    void sub_80249078();
    s16 get_field_74();
    virtual void render();
    u16 m_80;
    virtual void run_task();
    u8 unk_82[0x2];
    static s32 apply_choice(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
};

typedef char TWindowChoiceSetting_size[sizeof(TWindowChoiceSetting) == 0x84 ? 1 : -1];
extern "C" {
void TWindowMenuInfomation__ct(u8 *arg0, u32 arg1);
void TWindowSubStatusDisp__sub_80268C80(u8 *arg0);
}
s32 create_information_counter_window(s32 arg0);
extern "C" {
void create_sub_window__20TWindowChoiceSettingFPvi(void *arg0, s32 arg1);
}

#endif
