#include "types.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowMessageLog.h"
extern char *chat_log_lines[];

void TWindowMessageLog::load_chat_history() {
    s32 i;
    for (i = 0; i < 30; i++) {
        if (chat_log_lines[i] != 0) {
            append_line((s32)chat_log_lines[i]);
        }
    }
    complete_reveal();
    this->clamp_scroll_offset();
}
