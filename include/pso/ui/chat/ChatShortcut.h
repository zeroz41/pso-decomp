#ifndef PSO_UI_CHAT_CHAT_SHORTCUT_H
#define PSO_UI_CHAT_CHAT_SHORTCUT_H

#include "types.h"
#include "pso/ui/window/WordSelectMessage.h"

// What a chat shortcut sends: 0 none, 1 chat text, 2 word select message, 3 symbol chat.
struct ChatShortcutKind {
    u32 value;

    ChatShortcutKind &operator=(const ChatShortcutKind &src);
};

// What a chat shortcut sends, by its kind.
union ChatShortcutBody {
    char text[0x50];            // 1: chat text
    WordSelectMessage message;  // 2: word select message
    s32 symbol_chat_preset;     // 3: index of the symbol chat preset
};

// One chat shortcut of the character's save record: the kind and the text, message or symbol chat it sends.
struct ChatShortcut {
    ChatShortcutKind kind;
    ChatShortcutBody body;

    ChatShortcut &operator=(const ChatShortcut &src);
};

LAYOUT_ASSERT(ChatShortcut_size, sizeof(ChatShortcut) == 0x54);

#endif
