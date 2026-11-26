#ifndef PSO_UI_WINDOW_WORDSELECTMESSAGE_H
#define PSO_UI_WINDOW_WORDSELECTMESSAGE_H

#include "types.h"

// A word-select message as it is sent (the 6x74 payload): the chosen word ids, what they are about, and a
// number some words carry (levels, amounts). The chat packet carries all 0x1C bytes.
struct WordSelectMessage {
    s16 count;
    s16 type;
    s16 ids[8];
    s32 numeric_parameter;
    s32 unknown_a4;

    void init();
    void reset_numeric_parameter();
    void set_numeric_parameter(s32 value);
    s32 get_numeric_parameter();
    void set_last_token(s32 id);
    void pop_token();
    void push_token(s32 id);
    void bswap();
    void remember_selected_id();
    void format_type6_message(saddr buffer, void *pos);
};

LAYOUT_ASSERT(WordSelectMessage_size, sizeof(WordSelectMessage) == 0x1C);

// The 6x74 subcommand a word-select message travels in (name from newserv).
struct G_WordSelect_6x74 {
    u8 subcommand;
    u8 size;
    u16 client_id;
    WordSelectMessage message;

    void init_header();
    void bswap_message();
    void send();
    static void send_message(WordSelectMessage *message);
};

LAYOUT_ASSERT(G_WordSelect_6x74_size, sizeof(G_WordSelect_6x74) == 0x20);

#endif
