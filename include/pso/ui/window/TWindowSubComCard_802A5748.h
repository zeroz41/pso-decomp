#ifndef PSO_UI_WINDOW_TWINDOWSUBCOMCARD_802A5748_H
#define PSO_UI_WINDOW_TWINDOWSUBCOMCARD_802A5748_H

#include "types.h"

struct NJS_POINT2;
struct TWindowMessageYesNo;
void initialize_option_dialog(void *dialog, s32 message, const NJS_POINT2 *position, f32 width);
void open_yes_no_prompt(TWindowMessageYesNo *dialog, u32 title, s32 text, const NJS_POINT2 *position, f32 width);

#endif
