#ifndef PSO_UI_WINDOW_TEXTBUILDER_H
#define PSO_UI_WINDOW_TEXTBUILDER_H

#include "types.h"

// Shared text builder: appends into text_builder_buffer at text_builder_write_cursor.
void append_padded_number(s32 v, u8 n);
void append_text_space(void);

char *format_int_decimal(s32 v, char *out);

void text_builder_append_int(s32 value);
void text_builder_append(const char *str);
void text_builder_reset(void);

void append_comma();

s8 *copy_message_page_text(const s8 *text);

#endif
