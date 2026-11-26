#ifndef PSO_NETWORK_NETWORKINFOENTRY_H
#define PSO_NETWORK_NETWORKINFOENTRY_H

#include "types.h"

// Copies the name of the current network configuration entry into dst (len bytes, zero filled).
s32 copy_current_entry_name(char *dst, s32 len);
s32 copy_current_entry_password(char *dst, s32 len);
s32 get_current_entry_dns1(void *dst);
s32 get_current_entry_dns2(void *dst);
s32 get_current_entry_dial_type(u8 *dst);
s32 copy_current_entry_dial_prefix(char *dst, s32 len);
s32 copy_current_entry_phone_number(s32 n, char *dst, s32 len);
s32 copy_current_entry_modem_init(char *dst, s32 len);
s32 get_current_entry_connection_type(u8 *dst);
s32 get_current_entry_ip_addr(void *dst);
s32 get_current_entry_netmask(void *dst);
s32 get_current_entry_gateway(void *dst);
s32 copy_current_entry_dhcp_hostname(char *buf, u32 n);
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
    char name[0x80];
    char name2[0x20];
    s32 f1B8;
    s32 f1BC;
    u8 padA8[0xEE - 0xA8];
    s16 kind;
    u8 f208;
    u8 padF1[3];
    char str20C[0x20];
    char strs[3][0x20];
    u8 pad174[4];
    char str290[0x20];
    u8 f2B0;
    u8 pad199[3];
    s32 f2B4;
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

#endif
