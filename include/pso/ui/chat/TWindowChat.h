#ifndef PSO_UI_CHAT_TWINDOWCHAT_H
#define PSO_UI_CHAT_TWINDOWCHAT_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TWindowChat : public TObject {
public:
    virtual void render();
    TWindowChat(TObject *arg1, void *arg2);
    virtual ~TWindowChat();
    s32 sub_80247EC0();
    s32 sub_80247128();
    s32 sub_80247080();
    virtual void run_task();

    s32 submit_keyboard_input();
    void open_input();
    void handle_dpad_shortcuts();
    void close_all_children();
    void open_next_input_window();

    u8 inputMode;
    u8 unknown_1D;
    u16 flags;
    void* composer;
    void* softKeyboard;
    void* hardKeyboard;
    void* auxiliaryWindow;
    void* symbolChatWindow;
    void* wordSelectWindow;
    void* result;
public:
    void reset_input();
    void update();
    void handle_input();
    void handle_chat_input();
    u8 get_input_mode();
    int get_flag();
    int forward_card_at_1c();
    int get_subcard_field1c();
    void set_active_flag();
    void set_input_active();
    int is_mode_bit6();
    int is_visible();
    int is_mode_bit4();
    int is_open();
    static void open_symbol_chat(s32 *arg0);
    void flush_if_flagged();
};
#include <stddef.h>
typedef char ChatBaseSize[(sizeof(TObject)==0x1C)?1:-1];
typedef char ChatSize[(sizeof(TWindowChat)==0x3C)?1:-1];
#define CHAT_OFFSET(field, offset) typedef char ChatOffset_##field[(offsetof(TWindowChat,field)==offset)?1:-1]
CHAT_OFFSET(inputMode,0x1C); CHAT_OFFSET(flags,0x1E);
CHAT_OFFSET(composer,0x20); CHAT_OFFSET(softKeyboard,0x24);
CHAT_OFFSET(hardKeyboard,0x28); CHAT_OFFSET(auxiliaryWindow,0x2C);
CHAT_OFFSET(symbolChatWindow,0x30); CHAT_OFFSET(wordSelectWindow,0x34);
CHAT_OFFSET(result,0x38);
#undef CHAT_OFFSET
#endif
