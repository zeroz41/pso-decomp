#ifndef PSO_UI_FRONTEND_TADSCROLLWINGC_8026A5F8_H
#define PSO_UI_FRONTEND_TADSCROLLWINGC_8026A5F8_H

#include "types.h"

void cache_last_chat_line(const char *text);
void chat_log_add_line(const char *text);
void chat_log_remove_line(saddr index);
s32 chat_text_lacks_language_tag(const char *text);

#endif
