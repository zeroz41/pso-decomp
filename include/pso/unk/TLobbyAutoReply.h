#ifndef PSO_UNK_TLOBBYAUTOREPLY_H
#define PSO_UNK_TLOBBYAUTOREPLY_H

#include "types.h"

void sync_auto_reply_state();
saddr get_card_window_area();
void set_short_mail_text(char *text);
int get_flag_bit0();
s32 set_flag_bit0(s32 enabled);
s32 is_active();
void clear_auto_reply_flags(void *p);

void reset_auto_reply_flags(s32 _w0);
void TLobby__sub_8001DC04(void *p);

#endif
