#ifndef PSO_UI_WINDOW_PROGRESS_MESSAGE_WINDOW_H
#define PSO_UI_WINDOW_PROGRESS_MESSAGE_WINDOW_H

#include "types.h"

struct TWindowMessage;

// The extent address is passed as a target word by the original progress-window entry point.
extern "C" TWindowMessage *update_window_mode_from_progress__6TLobbyFPv(const void *position, s32 extent_address);

#endif
