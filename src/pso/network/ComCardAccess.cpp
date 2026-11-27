// Com-card record accessors and the com-card break-in flag (short_mail_flags bit 2).
#include "types.h"
#include "pso/unk/GuildCardRecord.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowCtrl.h"

s32 GuildCardRecord::get_serial() const { return serial; }

int get_com_card_data() { return com_card_entry_count; }

char *GuildCardRecord::get_sub_disp_ptr() { return ext.player_name; }

s32 GuildCardRecord::get_id() { return id; }

void set_short_mail_flag_bit2(void) {
    short_mail_flags |= 4;
}

void TLobby::clear_flag_bit2() {
    short_mail_flags &= 0xFFFFFFFB;
}
