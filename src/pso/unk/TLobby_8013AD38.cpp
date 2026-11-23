#include "types.h"
#include "pso/unk/TLobby_8013AD38.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/city/TCheckRoomSequence.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"

extern "C" {
extern u8 *text_language_group_table;

int TWindowMenuIconLine::is_decided() { return (this->state_flags >> 1) & 0x1; }
int TWindowMenuIconLine::is_cancelled() { return (this->state_flags >> 2) & 0x1; }
int TWindowMakeTeam::test_flag_1d_bit1() { return (m_1d >> 1) & 1; }
s32 TWindowMakeTeam::get_field_20() { return m_20; }
u8 TWindowMakeTeam::get_mode() { return m_1e; }
u8 TWindowMakeTeam::read_mode() { return m_1e; }
int TWindowMakeTeam::test_flag_1d_bit0() { return m_1d & 1; }

s32 *get_access_key_input_buffer(void) {
    return (s32 *)TAdEnterSerialAccessGC::access_key_input_buffer;
}

char *TLobby::init_serial_access() { return TAdEnterSerialAccessGC::hex_to_decimal_string((const char *)get_raw_serial_input_buffer()); }

s32 *get_raw_serial_input_buffer(void) {
    return (s32 *)TAdEnterSerialAccessGC::raw_serial_buffer;
}

saddr get_connection_message_text(s32 arg0) {
    return *(s32 *)((s8 *)(*(saddr *)((s8 *)text_language_group_table + 0x30)) + (arg0 * 4));
}

}
