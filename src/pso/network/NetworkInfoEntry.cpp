#include "types.h"
#include <string.h>
#include "pso/network/NetworkInfoLoader.h"
#include "pso/network/NetworkInfoCodec.h"
#include "pso/network/NetworkInfoEntry.h"
#include "pso/network/TLobby.h"







#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_network_config_login_user(char *dst, s32 len) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = lobby_net_config_buffer->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->a[i].pan;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].login_user, len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].login_user)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_network_config_login_password(char *dst, s32 len) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = lobby_net_config_buffer->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->a[i].pan;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].login_password, len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].login_password)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_network_config_dns_server1(void *dst) {
    NetworkInfoConfig *cfg;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    cfg = lobby_net_config_buffer;
    i = cfg->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = cfg->a[i].pan;
    if (i < 0 || i >= 6) {
        return -3;
    }
    memcpy(dst, &cfg->b[i].dns_server1, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_network_config_dns_server2(void *dst) {
    NetworkInfoConfig *cfg;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    cfg = lobby_net_config_buffer;
    i = cfg->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = cfg->a[i].pan;
    if (i < 0 || i >= 6) {
        return -3;
    }
    memcpy(dst, &cfg->b[i].dns_server2, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_network_config_dial_type(u8 *dst) {
    NetworkInfoConfig *cfg;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    cfg = lobby_net_config_buffer;
    i = cfg->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = cfg->a[i].pan;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (cfg->b[i].device_type != 1) {
        return -3;
    }
    *dst = cfg->b[i].dial_type;
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_network_config_outside_line_number(char *dst, s32 len) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = lobby_net_config_buffer->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->a[i].pan;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (lobby_net_config_buffer->b[i].device_type != 1) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].outside_line_number, len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].outside_line_number)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma optimize_for_size off
#pragma peephole off
s32 get_network_config_phone_number(s32 n, char *dst, s32 len) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = lobby_net_config_buffer->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->a[i].pan;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n < 0 || n >= 3) {
        return -2;
    }
    if (lobby_net_config_buffer->b[i].device_type != 1) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].phone_numbers[0] + (n *= 0x20), len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].phone_numbers[0] + n)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_network_config_modem_command(char *dst, s32 len) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = lobby_net_config_buffer->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->a[i].pan;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (lobby_net_config_buffer->b[i].device_type != 1) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].modem_command, len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].modem_command)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_network_config_ip_set_type(u8 *dst) {
    NetworkInfoConfig *cfg;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    cfg = lobby_net_config_buffer;
    i = cfg->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = cfg->a[i].pan;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (cfg->b[i].device_type != 4) {
        return -3;
    }
    *dst = cfg->b[i].ip_set_type;
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_network_config_ip_address(void *dst) {
    NetworkInfoConfig *cfg;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    cfg = lobby_net_config_buffer;
    i = cfg->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = cfg->a[i].pan;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (cfg->b[i].device_type != 4) {
        return -3;
    }
    memcpy(dst, &cfg->b[i].ip_address, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 get_network_config_subnet_mask(void *dst) {
    if (get_network_config_mode() == 0) return -1;
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) return -5;
    NetworkInfoConfig *s = lobby_net_config_buffer; s16 i;
    i = s->cnum;
    if (i < 0 || i >= 6) return -3;
    i = s->a[i].pan;
    if (i < 0 || i >= 6) return -3;
    if (s->b[i].device_type != 4) return -3;
    memcpy(dst, &s->b[i].subnet_mask, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 get_network_config_default_gateway(void *dst) {
    NetworkInfoConfig *s;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    s = lobby_net_config_buffer;
    i = s->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = s->a[i].pan;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (s->b[i].device_type != 4) {
        return -3;
    }
    memcpy(dst, &s->b[i].default_gateway, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 get_network_config_pc_name(char *buf, u32 n) {
    NetworkInfoConfig *s;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    s = lobby_net_config_buffer;
    i = s->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = s->a[i].pan;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (s->b[i].device_type != 4) {
        return -3;
    }
    memset(buf, 0, n);
    strncpy(buf, lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].pc_name, n - 1);
    if (n <= strlen(lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].pc_name)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 get_network_config_mail_name(char *buf, s32 n) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = lobby_net_config_buffer->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->a[i].man;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n <= 0) {
        return -2;
    }
    memset(buf, 0, n);
    strncpy(buf, lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].mail_name, n - 1);
    if ((u32)n <= strlen(lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].mail_name)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 get_network_config_mail_address(char *buf, s32 n) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = lobby_net_config_buffer->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->a[i].man;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n <= 0) {
        return -2;
    }
    memset(buf, 0, n);
    strncpy(buf, lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].mail_address, n - 1);
    if ((u32)n <= strlen(lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].mail_address)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 get_network_config_mail_server(char *buf, s32 n) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = lobby_net_config_buffer->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->a[i].man;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n <= 0) {
        return -2;
    }
    memset(buf, 0, n);
    strncpy(buf, lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].mail_server, n - 1);
    if ((u32)n <= strlen(lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].mail_server)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 get_network_config_pop_server(char *buf, s32 n) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = lobby_net_config_buffer->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->a[i].man;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n <= 0) {
        return -2;
    }
    memset(buf, 0, n);
    strncpy(buf, lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].pop_server, n - 1);
    if ((u32)n <= strlen(lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].pop_server)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 get_network_config_pop_id(char *buf, s32 n) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = lobby_net_config_buffer->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->a[i].man;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n <= 0) {
        return -2;
    }
    memset(buf, 0, n);
    strncpy(buf, lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].pop_id, n - 1);
    if ((u32)n <= strlen(lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].pop_id)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 get_network_config_pop_password(char *buf, s32 n) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = lobby_net_config_buffer->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->a[i].man;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n <= 0) {
        return -2;
    }
    memset(buf, 0, n);
    strncpy(buf, lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].pop_password, n - 1);
    if ((u32)n <= strlen(lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].pop_password)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_network_config_proxy_port(u16 *out) {
    NetworkInfoConfig *s;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    s = lobby_net_config_buffer;
    i = s->cnum;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = s->a[i].pan;
    if (i < 0 || i >= 6) {
        return -3;
    }
    *out = s->b[i].proxy_port;
    return 0;
}
#pragma pop
