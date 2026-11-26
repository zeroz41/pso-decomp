#ifndef PSO_UI_CHAT_TWINDOWCHAT_H
#define PSO_UI_CHAT_TWINDOWCHAT_H
#include "pso/system/task/TObject.h"
#include "types.h"

struct ChatShortcut;
struct TWindowKeyBoardBase;
struct TWindowKeyBoardHard;
struct TWindowKeyBoardSoft;

class TWindowChat : public TObject {
public:
    virtual void render();
    TWindowChat(TObject *object, void *result);
    virtual ~TWindowChat();
    // Flags 0x40 or 0x200: the chat closes once a message is sent.
    s32 closes_after_send();
    // Text is being typed, the chat is open, or the keyboard shows its status text.
    s32 is_busy();
    s32 update_word_select_window();
    s32 update_symbol_chat_window();
    virtual void run_task();

    s32 submit_keyboard_input();
    void open_input();
    void handle_dpad_shortcuts();
    void close_all_children();
    void close_and_clear_flag();
    void set_keyboard_flag62_bit4();
    void set_flag1e_bit80();
    void set_flag1e_bit40();
    void set_flag1e_bit8();
    void clear_flag1e_bit8();
    void set_flag1e_bit200();
    void open_next_input_window();

    u8 inputMode;
    u8 pad_1D;
    u16 flags;
    TWindowKeyBoardBase *composer;
    TWindowKeyBoardSoft *softKeyboard;
    TWindowKeyBoardHard *hardKeyboard;
    class TWindowBase *auxiliaryWindow;
    class TSymbolChatMenu *symbolChatWindow;
    class TWindowDD *wordSelectWindow;
    ChatShortcut *result;  // what the player chose: kind 1 text, 2 word select, 3 symbol chat, then its body
public:
    void update();
    void handle_input();
    void handle_chat_input();
    void set_active_flag();
    void set_input_active();
    int is_mode_bit6();
    int is_visible();
    int is_mode_bit4();
    int is_open();
    static struct SymbolChatPreset *open_symbol_chat(s32 *index);
};
void consume_input_active_flag(TWindowChat *chat);
void consume_active_flag(TWindowChat *chat);

#include <stddef.h>
LAYOUT_ASSERT(ChatBaseSize, sizeof(TObject)==0x1C);
LAYOUT_ASSERT(ChatSize, sizeof(TWindowChat)==0x3C);
#define CHAT_OFFSET(field, offset) LAYOUT_ASSERT(ChatOffset_##field, offsetof(TWindowChat,field)==offset)
CHAT_OFFSET(inputMode,0x1C); CHAT_OFFSET(flags,0x1E);
CHAT_OFFSET(composer,0x20); CHAT_OFFSET(softKeyboard,0x24);
CHAT_OFFSET(hardKeyboard,0x28); CHAT_OFFSET(auxiliaryWindow,0x2C);
CHAT_OFFSET(symbolChatWindow,0x30); CHAT_OFFSET(wordSelectWindow,0x34);
CHAT_OFFSET(result,0x38);
#undef CHAT_OFFSET
#endif
