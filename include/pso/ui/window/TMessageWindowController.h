#ifndef PSO_UI_WINDOW_TMESSAGEWINDOWCONTROLLER_H
#define PSO_UI_WINDOW_TMESSAGEWINDOWCONTROLLER_H
#include "types.h"

struct NJS_POINT2;
class TWindowMessagePage;
class TMessageWindowController {
public:
    TMessageWindowController();
    virtual ~TMessageWindowController();
    char buffer[0x200];
    const char *input;
    char *output;
    TWindowMessagePage *window;
    void append_file_number();
    void append_title_string();
    void append_block_space();
    void append_quest_title();
    void append_quest_name();
    void parse_tag_command();
    s32 at_end();
    u8 read_byte();
    void append_text(const char *text);
    void append_byte(u8 byte);
    void begin_parse(const char *source, char *destination);
    char *parse_message_text(const char *source, char *destination);
    s32 is_ready();
    void send_message(s32 index, s32 flags);
    void format_guild_message(s32 index, s32 flags);
    void display_message(const char *text, s32 flags);
    void format_shop_message(s32 index, s32 flags);
    void close();
    TWindowMessagePage *create_message_window(const NJS_POINT2 *position, s32 extent, s32 flags);
    TWindowMessagePage *create_window(const NJS_POINT2 *position, s32 extent);
};
LAYOUT_ASSERT(TMessageWindowController_size_check, sizeof(TMessageWindowController)==0x210);

struct MessageTagCommand {
    const char *name;
    void (TMessageWindowController::*callback)();
};

#endif
