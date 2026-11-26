#ifndef PSO_UNK_TEXT_803F4D84_H
#define PSO_UNK_TEXT_803F4D84_H

#include "types.h"

// Accessors for the current entry of the network settings (the fields of the browser's settings
// pages on the disc). Each copies one field to dst and returns 0, or a negative error.
// Common to every entry:
s32 get_network_config_login_user(char *dst, s32 len);
s32 get_network_config_login_password(char *dst, s32 len);
s32 get_network_config_dns_server1(void *dst);
s32 get_network_config_dns_server2(void *dst);
// Modem entries (dial type 0 tone, 1 pulse):
s32 get_network_config_dial_type(u8 *dst);
s32 get_network_config_outside_line_number(char *dst, s32 len);
s32 get_network_config_phone_number(s32 n, char *dst, s32 len);
s32 get_network_config_modem_command(char *dst, s32 len);
// Broadband entries (IP set type 0 DHCP, 1 PPPoE, otherwise a fixed address):
s32 get_network_config_ip_set_type(u8 *dst);
s32 get_network_config_ip_address(void *dst);
s32 get_network_config_subnet_mask(void *dst);
s32 get_network_config_default_gateway(void *dst);
s32 get_network_config_pc_name(char *buf, u32 n);
extern "C" {
s32 TLobby__sub_803F5B20(char *buf, s32 n);
s32 TLobby__sub_803F5C58(char *buf, s32 n);
s32 TLobby__sub_803F5D90(char *buf, s32 n);
s32 TLobby__sub_803F5EC8(char *buf, s32 n);
s32 TLobby__sub_803F6000(char *buf, s32 n);
s32 TLobby__sub_803F6138(char *buf, s32 n);
s32 TLobby__sub_803F6270(u16 *out);
}

typedef struct NetConfigSlot {
    s16 v;
    u8 pad[0x26];
} NetConfigSlot;

typedef struct NetConfigRecord {
    char login_user[0x80];
    char login_password[0x20];
    s32 dns_server1;
    s32 dns_server2;
    u8 padA8[0xEE - 0xA8];
    s16 device_type; /* 1 modem, 4 broadband */
    u8 dial_type; /* 0 tone, 1 pulse */
    u8 padF1[3];
    char outside_line_number[0x20];
    char phone_numbers[3][0x20];
    u8 pad174[4];
    char modem_command[0x20];
    u8 ip_set_type; /* 0 DHCP, 1 PPPoE, otherwise a fixed address */
    u8 pad199[3];
    s32 ip_address;
    u8 pad1A0[0x210 - 0x1A0];
} NetConfigRecord;

typedef struct NetConfigBuffer {
    s16 f0;
    s16 cur;
    u8 pad4[0x24];
    NetConfigSlot ent[6];
    NetConfigRecord rec[6];
} NetConfigBuffer;

struct NetConfigRecordData { u8 pad[0xEE]; s16 state; u8 pad2[0xB0]; u8 data[4]; u8 pad3[0x210 - 0x1A4]; };

struct NetConfigDataView { u8 pad0[2]; s16 cur; u8 pad4[0x24]; NetConfigSlot recs[6]; NetConfigRecordData ents[6]; };

struct NetConfigSlotWord { s16 v; s16 w; u8 pad[0x24]; };

struct NetConfigRecordNames {
    u8 pad0[0xEE];
    s16 state;
    u8 pad1[0xB0];
    u8 data0[4];
    u8 data1[4];
    char name[0x210 - 0x1A8];
};

struct NetConfigStringSet {
    char s0[0x40];
    char s1[0x40];
    char s2[0x40];
    char s3[0x20];
    char s4[0x20];
    char s5[0x24];
};

struct NetConfigRecordVersion { u8 pad[0xEC]; u16 v; s16 state; u8 pad2[0x210 - 0xF0]; };

struct NetConfigVersionView { u8 pad0[2]; s16 cur; u8 pad4[0x24]; NetConfigSlot recs[6]; NetConfigRecordVersion ents[6]; };

struct NetConfigBufferView {
    u8 pad0[2];
    s16 cur;
    u8 pad4[0x24];
    NetConfigSlotWord recs[6];
    union {
        NetConfigRecordNames ents[6];
        struct {
            u8 pad[0xD5C - 0x118];
            NetConfigStringSet ents2[6];
        } b;
    } u;
};

#endif
