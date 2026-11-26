#ifndef PSO_UI_WINDOW_MESSAGE_WINDOW_SETTINGS_ABI_H
#define PSO_UI_WINDOW_MESSAGE_WINDOW_SETTINGS_ABI_H

#include "types.h"

// Stores the two-float extent and row count for the next message window.
void set_message_window_size(const void *extent, u32 rows);

#endif
