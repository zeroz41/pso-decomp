#ifndef PSO_UI_CHAT_CHATSHORTCUTS_H
#define PSO_UI_CHAT_CHATSHORTCUTS_H

#include "types.h"

struct ChatShortcut;

s32 chat_accept_submission(ChatShortcut *submission);
void chat_dispatch_accepted_result(ChatShortcut *submission);
void clear_chat_shortcut(s32 i);
char *get_chat_shortcut_text(s32 *text);
ChatShortcut *get_chat_shortcut(s32 index);
s32 is_chat_shortcut_set(s32 index);
void send_chat_shortcut(s32 index);
ChatShortcut *store_chat_shortcut(s32 index, const ChatShortcut *src);
void submit_chat_text(char *text);

struct SubmitChatTextTag { u32 a; u32 b; };

#endif
