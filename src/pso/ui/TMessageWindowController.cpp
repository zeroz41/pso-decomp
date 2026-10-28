#include "pso/ui/TMessageWindowController.h"
#include "pso/misc/TQuestListChallenge.h"
#include "pso/misc/TUnk_804CDFE8.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/misc/TWindowMessagePage.h"
#include "pso/quest/TQuestThread.h"
#pragma readonly_strings on
extern "C" {
void *memset(void *, int, unsigned long);
int sprintf(char *, const char *, ...);
unsigned long strlen(const char *);
char *strcpy(char *, const char *);
int strcmp(const char *, const char *);
const char *get_status_window__20TWindowSubStatusDispFi(u16);
extern s32 local_client_id;
const char *get_selected_entry__16TQuestListOnlineFv();
s32 get_game_play_mode();
s32 get_shop_text(s32 arg0);
TWindowMessagePage *create__18TWindowMessagePageFllll(s32, s32, s32, s32);
TWindowMessagePage *set_text__18TWindowMessagePageFlll(s32, s32, s32);
void TWindow__close(u8 *arg0);
__declspec(section ".rodata") extern const char message_tag_error[];
}
s32 get_guild_text(s32 arg0);
s32 get_appraisal_text(s32 arg0);
struct MessageTagCommand {
    const char *name;
    void (TMessageWindowController::*callback)();
};

void TMessageWindowController::append_file_number() {
    char buf[0x20];
    memset(buf, 0, 0x20);
    sprintf(buf, "%d", 2);
    append_text(buf);
}
void TMessageWindowController::append_title_string() {
    const char *text = get_status_window__20TWindowSubStatusDispFi((u16)local_client_id);
    if (text != NULL) {
        append_text(text);
        return;
    }
    append_text(message_tag_error);
}
void TMessageWindowController::append_block_space() {
    char buf[0x20];
    s32 value = TQuestVmDownLoadServer::get_field230();
    memset(buf, 0, 0x20);
    sprintf(buf, "%d", value);
    append_text(buf);
}
void TMessageWindowController::append_quest_title() {
    const char *text = NULL;
    s32 mode;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        mode = get_game_play_mode();
        switch (mode) {
        case 1:
        case 2:
            text = (const char *)get_selected_quest_text__19TQuestListChallengeFv();
            break;
        }
    } else {
        text = get_selected_entry__16TQuestListOnlineFv();
    }
    if (text != NULL) {
        append_text(text);
        return;
    }
    append_text(message_tag_error);
}
void TMessageWindowController::append_quest_name() {
    const char *text = TQuestThread::get_quest_name();
    if (strcmp(text, message_tag_error) == 0) {
        append_text(text);
        return;
    }
    append_text(text);
}
void TMessageWindowController::parse_tag_command() {
    MessageTagCommand commands[5] = {
        { "quest name", &TMessageWindowController::append_quest_name },
        { "block space", &TMessageWindowController::append_block_space },
        { "quest title", &TMessageWindowController::append_quest_title },
        { "title string", &TMessageWindowController::append_title_string },
        { "file num", &TMessageWindowController::append_file_number },
    };
    char buf[0x40];
    u32 n = 0;
    while (n < 0x40 && at_end() == 0) {
        u8 ch = read_byte();
        switch ((s8)ch) {
        case '>': {
            u32 i;
            buf[n] = 0;
            for (i = 0; i < 5; i++) {
                if (strcmp(commands[i].name, buf) == 0) {
                    (this->*commands[i].callback)();
                }
            }
            return;
        }
        }
        buf[n] = ch;
        n++;
    }
}
__declspec(section ".rodata") const char message_tag_error[] = "ERROR";
s32 TMessageWindowController::at_end() { return (u8)((s8)*input == 0); }
u8 TMessageWindowController::read_byte() {
    const char *old = input;
    input = old + 1;
    return *old;
}
void TMessageWindowController::append_text(const char *text) {
    s32 length = strlen(text);
    strcpy(output, text);
    output += length;
}
void TMessageWindowController::append_byte(u8 byte) {
    char *old = output;
    output = old + 1;
    *old = byte;
}
void TMessageWindowController::begin_parse(const char *source, char *destination) {
    input = source;
    output = destination;
}
char *TMessageWindowController::parse_message_text(const char *source, char *destination) {
    u8 byte;
    begin_parse(source, destination);
    while (at_end() == 0) {
        byte = read_byte();
        switch ((s8)byte) {
        case '<':
            parse_tag_command();
            break;
        case '>':
            for (;;) {}
        case '=':
        default:
            append_byte(byte);
            break;
        }
    }
    append_byte(0);
    return destination;
}
s32 TMessageWindowController::is_ready() {
    TWindowMessagePage *current = window;
    if (current != NULL) return ((TWindowMessagePage *)current)->is_ready();
    return 1;
}
void TMessageWindowController::send_message(s32 index, s32 flags) {
    if (window != NULL) {
        ((TWindowMessagePage *)window)->set_message((void *)(get_appraisal_text(index)), (s32)(flags | 0x80));
    }
}
void TMessageWindowController::format_guild_message(s32 index, s32 flags) {
    const char *text;
    if (window != NULL) {
        text = (const char *)get_guild_text(index);
        memset(buffer, 0, 0x200);
        parse_message_text(text, buffer);
        ((TWindowMessagePage *)window)->set_message((void *)buffer, (s32)(flags | 0x80));
    }
}
void TMessageWindowController::display_message(const char *text, s32 flags) {
    if (window != NULL) {
        memset(buffer, 0, 0x200);
        parse_message_text(text, buffer);
        ((TWindowMessagePage *)window)->set_message((void *)buffer, (s32)(flags | 0x80));
    }
}
void TMessageWindowController::format_shop_message(s32 index, s32 flags) {
    const char *text;
    if (window != NULL) {
        text = (const char *)get_shop_text(index);
        memset(buffer, 0, 0x200);
        parse_message_text(text, buffer);
        ((TWindowMessagePage *)window)->set_message((void *)buffer, (s32)(flags | 0x80));
    }
}
void TMessageWindowController::close() {
    if (window != NULL) {
        TWindow__close((u8 *)window);
        window = NULL;
    }
}
TWindowMessagePage *TMessageWindowController::create_message_window(s32 x, s32 y, s32 flags) {
    f32 scale;
    if (TLobby::is_camera_ctrl_active() > 2) scale = 0.75f;
    else scale = 1.0f;
    if (window == NULL) {
        window = create__18TWindowMessagePageFllll(x, y, 1, flags);
        ((TUnk_804CDFE8 *)window)->set_position_xy(scale, scale);
        return window;
    }
    return NULL;
}
TWindowMessagePage *TMessageWindowController::create_window(s32 x, s32 y) {
    f32 scale;
    if (TLobby::is_camera_ctrl_active() > 2) scale = 0.75f;
    else scale = 1.0f;
    if (window == NULL) {
        window = set_text__18TWindowMessagePageFlll(x, y, 1);
        ((TUnk_804CDFE8 *)window)->set_position_xy(scale, scale);
        return window;
    }
    return NULL;
}
TMessageWindowController::~TMessageWindowController() {
    if (window != NULL) {
        TWindow__close((u8 *)window);
        window = NULL;
    }
}
TMessageWindowController::TMessageWindowController() {
    window = NULL;
    memset(buffer, 0, 0x200);
    input = NULL;
    output = NULL;
}
