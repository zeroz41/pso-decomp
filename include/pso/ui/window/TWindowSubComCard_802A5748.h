#ifndef PSO_UI_WINDOW_TWINDOWSUBCOMCARD_802A5748_H
#define PSO_UI_WINDOW_TWINDOWSUBCOMCARD_802A5748_H

#include "types.h"

struct TWindowMessageYesNo;
void initialize_option_dialog(void *dialog, s32 message, s32 position, f32 width);
extern "C" {
void open_yes_no_prompt(TWindowMessageYesNo *dialog, u32 title, s32 text, s32 position, f32 width);
}

#endif
