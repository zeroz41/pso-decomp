#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_8025A9B4_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_8025A9B4_H

#include "types.h"

class WindowTextEntry;
struct TextLayoutRecord;

void set_text_entry_string(WindowTextEntry *entry, const char *str, s32 flags);
extern "C" void measure_message_text_width(WindowTextEntry *entry, f32 max_width);

#endif
