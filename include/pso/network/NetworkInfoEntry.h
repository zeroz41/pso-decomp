#ifndef PSO_NETWORK_NETWORKINFOENTRY_H
#define PSO_NETWORK_NETWORKINFOENTRY_H

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
// The current entry's mail account (its MAN index into the MA/MS/PS/PI/PP/MN settings).
s32 get_network_config_mail_name(char *buf, s32 n);
s32 get_network_config_mail_address(char *buf, s32 n);
s32 get_network_config_mail_server(char *buf, s32 n);
s32 get_network_config_pop_server(char *buf, s32 n);
s32 get_network_config_pop_id(char *buf, s32 n);
s32 get_network_config_pop_password(char *buf, s32 n);
// The PXP setting of the current entry's connection.
s32 get_network_config_proxy_port(u16 *out);

#endif
