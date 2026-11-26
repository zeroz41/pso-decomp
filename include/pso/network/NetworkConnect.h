#ifndef PSO_NETWORK_NETWORKCONNECT_H
#define PSO_NETWORK_NETWORKCONNECT_H

#include "types.h"

// --- C functions defined in NetworkConnect.cpp ---
extern "C" {
s32 apply_static_network_config(s32 *arg0);
s32 apply_dhcp_network_config(s32 *netmask);
s32 should_try_next_phone_number(u32 arg0);
int get_phone_number_count(void);
void get_local_ip_address(s32 *arg0);
int TLobby__sub_8014677C(void);
s32 init_network_and_connect(void);
void TLobby__sub_801469B8(void);
char *get_ppp_password(void);
char *TLobby__sub_80146D44(void);
char *get_account_user_name(s32 idx);
void copy_ip_address(void *p, void *q);
s32 disconnect_network(void);
s32 connect_with_any_phone_number(s32 id);
void TLobby__sub_80147978(void);
}
// What follows the online character save: 0 asks the server for the time, 1 and 2
// close the lobby with state 0x13 or 0x14. Always 0 in this build.
int get_post_save_lobby_action();
s32 connect_modem(s32 idx, s16 id);
s32 connect_pppoe(s32 *out_value);
extern "C" {
void set_keyboard_buffer_cursor(int a0);
void reset_keyboard_buffer_cursor(void);
void *get_account_entry(int idx);
}
void get_link_state(s16 *state, s16 *reason);
int get_link_status();
char *get_modem_phone_number(s32 idx);
void init_keyboard_buffer();
s32 poll_connect();
void remove_default_route();
void set_default_gateway(s32 gateway);
s32 query_task_active();
int get_link_status_value();
void cleanup();
void flush_pending_flags();
s32 run_connect_sequence();
char *get_dialing_phone_number();
void set_ppp_password(const char *src);
void load_network_configs();
void teardown_boss2();
s32 set_dns_servers();
void init_account_entries();
// --- end of C functions

extern s32 net_session_mode;

#endif
