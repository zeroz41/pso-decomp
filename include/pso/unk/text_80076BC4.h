#ifndef PSO_UNK_TEXT_80076BC4_H
#define PSO_UNK_TEXT_80076BC4_H

#include "types.h"

s32 chat_accept_submission(saddr submission);
void chat_dispatch_accepted_result(s32 *submission);
extern "C" {
void clear_chat_shortcut(s32 i);
char *fn_80076BC4(s32 *text);
saddr get_chat_shortcut(s32 index);
bool is_chat_shortcut_set(s32 index);
void send_chat_shortcut(void);
}
s32 store_chat_shortcut(s32 index, s32 src);
void submit_chat_text(u8 *lobby);

#endif
