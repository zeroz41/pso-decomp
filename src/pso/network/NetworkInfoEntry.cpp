#include "types.h"
#include <string.h>
#include "pso/network/NetworkInfoLoader.h"
#include "pso/network/NetworkInfoCodec.h"
#include "pso/network/NetworkInfoEntry.h"
#include "pso/network/TLobby.h"







#pragma push
#pragma scheduling off
#pragma peephole off
s32 copy_current_entry_name(char *dst, s32 len) {
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
    strncpy(dst, lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].li, len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].li)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 copy_current_entry_password(char *dst, s32 len) {
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
    strncpy(dst, lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].lp, len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].lp)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_current_entry_dns1(void *dst) {
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
    memcpy(dst, &cfg->b[i].d1, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_current_entry_dns2(void *dst) {
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
    memcpy(dst, &cfg->b[i].d2, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_current_entry_dial_type(u8 *dst) {
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
    if (cfg->b[i].at != 1) {
        return -3;
    }
    *dst = cfg->b[i].dt;
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 copy_current_entry_dial_prefix(char *dst, s32 len) {
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
    if (lobby_net_config_buffer->b[i].at != 1) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].ol, len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].ol)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma optimize_for_size off
#pragma peephole off
s32 copy_current_entry_phone_number(s32 n, char *dst, s32 len) {
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
    if (lobby_net_config_buffer->b[i].at != 1) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].t1 + (n *= 0x20), len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].t1 + n)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 copy_current_entry_modem_init(char *dst, s32 len) {
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
    if (lobby_net_config_buffer->b[i].at != 1) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].mi, len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].mi)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_current_entry_connection_type(u8 *dst) {
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
    if (cfg->b[i].at != 4) {
        return -3;
    }
    *dst = cfg->b[i].dy;
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_current_entry_ip_addr(void *dst) {
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
    if (cfg->b[i].at != 4) {
        return -3;
    }
    memcpy(dst, &cfg->b[i].ip, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 get_current_entry_netmask(void *dst) {
    if (get_network_config_mode() == 0) return -1;
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) return -5;
    NetworkInfoConfig *s = lobby_net_config_buffer; s16 i;
    i = s->cnum;
    if (i < 0 || i >= 6) return -3;
    i = s->a[i].pan;
    if (i < 0 || i >= 6) return -3;
    if (s->b[i].at != 4) return -3;
    memcpy(dst, &s->b[i].snm, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 get_current_entry_gateway(void *dst) {
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
    if (s->b[i].at != 4) {
        return -3;
    }
    memcpy(dst, &s->b[i].g1, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 copy_current_entry_dhcp_hostname(char *buf, u32 n) {
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
    if (s->b[i].at != 4) {
        return -3;
    }
    memset(buf, 0, n);
    strncpy(buf, lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].hn, n - 1);
    if (n <= strlen(lobby_net_config_buffer->b[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].pan].hn)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 copy_current_entry_mail_name(char *buf, s32 n) {
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
    strncpy(buf, lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].mn, n - 1);
    if ((u32)n <= strlen(lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].mn)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 copy_current_entry_mail_address(char *buf, s32 n) {
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
    strncpy(buf, lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].ma, n - 1);
    if ((u32)n <= strlen(lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].ma)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 copy_current_entry_mail_server(char *buf, s32 n) {
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
    strncpy(buf, lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].ms, n - 1);
    if ((u32)n <= strlen(lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].ms)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 copy_current_entry_pop_server(char *buf, s32 n) {
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
    strncpy(buf, lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].ps, n - 1);
    if ((u32)n <= strlen(lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].ps)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 copy_current_entry_pop_user(char *buf, s32 n) {
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
    strncpy(buf, lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].pi, n - 1);
    if ((u32)n <= strlen(lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].pi)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 copy_current_entry_pop_password(char *buf, s32 n) {
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
    strncpy(buf, lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].pp, n - 1);
    if ((u32)n <= strlen(lobby_net_config_buffer->c[lobby_net_config_buffer->a[lobby_net_config_buffer->cnum].man].pp)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_current_entry_proxy_port(u16 *out) {
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
    *out = s->b[i].pxp;
    return 0;
}
#pragma pop
