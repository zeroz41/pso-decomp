#ifndef PSO_NETWORK_NETWORKSETTINGS_H
#define PSO_NETWORK_NETWORKSETTINGS_H

#include "types.h"

// The account settings init_work reads from the network configuration.
struct AccountConfigRecord {
    s32 f0;
    char host[0x80];
    char user[0x20];
    char phone[3][0x40];
    u32 dns1;
    u32 dns2;
    char mail_address[0x20];
    char mail_server[0x40];
    char pop_server[0x40];
    char pop_user[0x20];
    char pop_password[0x20];
    u8 pad[0x274 - 0x24C];
};

// The broadband adapter settings init_struct reads from the network configuration.
struct LanConfigRecord {
    s32 f0;
    s32 connection_type; /* 0 DHCP, 1 PPPoE, otherwise a fixed address */
    char ppp_user[0x80];
    char ppp_password[0x20];
    s32 ip_addr;
    s32 netmask;
    s32 fB0;
    s32 dns1;
    s32 dns2;
    s32 gateway;
    s32 fC0;
    char dhcp_hostname[0x40];
    char domain[0x40];
    char mail_name[0x20];
    char mail_address[0x40];
    char pop_server[0x40];
    char pop_user[0x20];
    char pop_password[0x20];
    u8 pad_224[0x20];
    u16 proxy_port;
    u8 pad[0x26C - 0x246];
};

s32 load_network_info(void);
s32 init_struct(LanConfigRecord *info);
s32 init_work(s32 unused, AccountConfigRecord *info);

extern void *network_info_work;
extern u16 network_config_open;
extern int network_lease_time; /* the DHCP lease time NetworkConnect keeps */
BOOL read_dial_prefix(char *dst);
s32 adapter_supports_connection(s32 mode);
int is_network_info_loaded(void);

// 1 when the broadband configuration's connection type is 1 (PPPoE).
s32 is_state_active();
s32 is_dhcp_connection(void);

s32 is_confirmed();
s32 has_broadband_adapter(void);

struct LoadNetworkInfoIds { s32 v[2]; };

struct LoadNetworkInfoBuf { s32 hdr; char name[0xA0]; s8 x[0x270 - 0xA4]; };

#endif
