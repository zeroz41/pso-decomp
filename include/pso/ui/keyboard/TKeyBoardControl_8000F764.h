#ifndef PSO_UI_KEYBOARD_TKEYBOARDCONTROL_8000F764_H
#define PSO_UI_KEYBOARD_TKEYBOARDCONTROL_8000F764_H

#include "types.h"

extern "C" {
// Calls TFogCtrl::clear_split_screen_fog().
void forward_clear_split_screen_fog(void);
void poll_input_devices_frame(void);
void run_end_of_render_tasks(void);
}

#endif
