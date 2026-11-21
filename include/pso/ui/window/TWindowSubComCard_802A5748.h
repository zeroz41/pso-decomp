#ifndef PSO_UI_WINDOW_TWINDOWSUBCOMCARD_802A5748_H
#define PSO_UI_WINDOW_TWINDOWSUBCOMCARD_802A5748_H

#include "types.h"

class TChCrTagPlBack;
void initialize_option_dialog(void *arg0, s32 message, s32 position, f32 farg0);
extern "C" {
void open_yes_no_prompt(TChCrTagPlBack *arg0, u32 arg1, s32 text, s32 arg3, f32 width);
void open_yes_no_prompt_with_text(TChCrTagPlBack *window, s32 text, s32 pos, f32 width);
}

#endif
