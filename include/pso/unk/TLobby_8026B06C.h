#ifndef PSO_UNK_TLOBBY_8026B06C_H
#define PSO_UNK_TLOBBY_8026B06C_H

#include "types.h"

struct NJS_POINT2;
struct TWindowMessageQuest;
struct TWindowMessageScroll;

extern "C" {
TWindowMessageQuest *create_quest_message_window_at(const NJS_POINT2 *position, const NJS_POINT2 *extent);
int dispatch_message_window_text(TWindowMessageQuest *window, s32 text, s32 flags);
TWindowMessageScroll *open_message_scroll_window(const NJS_POINT2 *position, const NJS_POINT2 *extent, s32 *completion);
}

#endif
