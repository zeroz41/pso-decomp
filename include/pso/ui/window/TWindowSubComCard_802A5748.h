#ifndef PSO_UI_WINDOW_TWINDOWSUBCOMCARD_802A5748_H
#define PSO_UI_WINDOW_TWINDOWSUBCOMCARD_802A5748_H

#include "types.h"

class TChCrTagPlBack;
void initialize_option_dialog(void *arg0, s32 message, s32 position, f32 farg0);
extern "C" {
void open_yes_no_prompt(TChCrTagPlBack *ch_cr_tag_pl_back, u32 title, s32 text, s32 arg3, f32 width);
}

#endif
