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
// The current entry's mail account (its MAN index into the MA/MS/PS/PI/PP/MN settings).
s32 copy_current_entry_mail_name(char *buf, s32 n);
s32 copy_current_entry_mail_address(char *buf, s32 n);
s32 copy_current_entry_mail_server(char *buf, s32 n);
s32 copy_current_entry_pop_server(char *buf, s32 n);
s32 copy_current_entry_pop_user(char *buf, s32 n);
s32 copy_current_entry_pop_password(char *buf, s32 n);
// The PXP setting of the current entry's connection.
s32 get_current_entry_proxy_port(u16 *out);

#endif
