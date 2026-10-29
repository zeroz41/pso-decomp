#include "pso/protocol/protocol_types.h"
#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "pso/misc/TOChatSensor_8015B214.h"
#include "pso/system/byteswap.h"
#include "pso/misc/TOChatSensor.h"

extern "C" {

int load_encrypted_archive_data(void*);
}

    extern unsigned char lbl_804404B0[];
    extern int chat_sensor_table;
void load_chat_sensor(void) { chat_sensor_table = load_encrypted_archive_data(lbl_804404B0); }

void TOChatSensor::send_state() { swap_state_endian(); send_subcommand((u8 *)this); }

void TOChatSensor::swap_state_endian() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); }

void TOChatSensor::init_packet_type() { *(u8 *)&this->m_name = 147; *(u8*)((char*)this + 0x1) = 3; }
