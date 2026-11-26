#include "types.h"
#include <string.h>
#include "pso/network/NetworkInfoLoader.h"
#include "pso/unk/text_803F4D84.h"
#include "pso/network/TLobby.h"













extern NetConfigBuffer *lobby_net_config_buffer;
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
    i = lobby_net_config_buffer->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].login_user, len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].login_user)) {
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
    i = lobby_net_config_buffer->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].login_password, len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].login_password)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_network_config_dns_server1(void *dst) {
    NetConfigBuffer *b;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    b = lobby_net_config_buffer;
    i = b->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = b->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    memcpy(dst, &b->rec[i].dns_server1, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_network_config_dns_server2(void *dst) {
    NetConfigBuffer *b;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    b = lobby_net_config_buffer;
    i = b->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = b->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    memcpy(dst, &b->rec[i].dns_server2, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_network_config_dial_type(u8 *dst) {
    NetConfigBuffer *b;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    b = lobby_net_config_buffer;
    i = b->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = b->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (b->rec[i].device_type != 1) {
        return -3;
    }
    *dst = b->rec[i].dial_type;
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
    i = lobby_net_config_buffer->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (lobby_net_config_buffer->rec[i].device_type != 1) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].outside_line_number, len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].outside_line_number)) {
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
    i = lobby_net_config_buffer->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n < 0 || n >= 3) {
        return -2;
    }
    if (lobby_net_config_buffer->rec[i].device_type != 1) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].phone_numbers[0] + (n *= 0x20), len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].phone_numbers[0] + n)) {
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
    i = lobby_net_config_buffer->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (lobby_net_config_buffer->rec[i].device_type != 1) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].modem_command, len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].modem_command)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_network_config_ip_set_type(u8 *dst) {
    NetConfigBuffer *b;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    b = lobby_net_config_buffer;
    i = b->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = b->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (b->rec[i].device_type != 4) {
        return -3;
    }
    *dst = b->rec[i].ip_set_type;
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_network_config_ip_address(void *dst) {
    NetConfigBuffer *b;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    b = lobby_net_config_buffer;
    i = b->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = b->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (b->rec[i].device_type != 4) {
        return -3;
    }
    memcpy(dst, &b->rec[i].ip_address, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 get_network_config_subnet_mask(void *dst) {
    if (get_network_config_mode() == 0) return -1;
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) return -5;
    NetConfigDataView *s = (*(NetConfigDataView * *)&lobby_net_config_buffer); s16 i;
    i = s->cur;
    if (i < 0 || i >= 6) return -3;
    i = s->recs[i].v;
    if (i < 0 || i >= 6) return -3;
    if (s->ents[i].state != 4) return -3;
    memcpy(dst, s->ents[i].data, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 get_network_config_default_gateway(void *dst) {
    NetConfigBufferView *s;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    s = (*(NetConfigBufferView * *)&lobby_net_config_buffer);
    i = s->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = s->recs[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (s->u.ents[i].state != 4) {
        return -3;
    }
    memcpy(dst, s->u.ents[i].data1, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 get_network_config_pc_name(char *buf, u32 n) {
    NetConfigBufferView *s;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    s = (*(NetConfigBufferView * *)&lobby_net_config_buffer);
    i = s->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = s->recs[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (s->u.ents[i].state != 4) {
        return -3;
    }
    memset(buf, 0, n);
    strncpy(buf, (*(NetConfigBufferView * *)&lobby_net_config_buffer)->u.ents[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur].v].name, n - 1);
    if (n <= strlen((*(NetConfigBufferView * *)&lobby_net_config_buffer)->u.ents[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur].v].name)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 TLobby__sub_803F5B20(char *buf, s32 n) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = (*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = (*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[i].w;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n <= 0) {
        return -2;
    }
    memset(buf, 0, n);
    strncpy(buf, (*(NetConfigBufferView * *)&lobby_net_config_buffer)->u.b.ents2[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur].w].s5, n - 1);
    if ((u32)n <= strlen((*(NetConfigBufferView * *)&lobby_net_config_buffer)->u.b.ents2[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur].w].s5)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 TLobby__sub_803F5C58(char *buf, s32 n) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = (*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = (*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[i].w;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n <= 0) {
        return -2;
    }
    memset(buf, 0, n);
    strncpy(buf, (*(NetConfigBufferView * *)&lobby_net_config_buffer)->u.b.ents2[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur].w].s0, n - 1);
    if ((u32)n <= strlen((*(NetConfigBufferView * *)&lobby_net_config_buffer)->u.b.ents2[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur].w].s0)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 TLobby__sub_803F5D90(char *buf, s32 n) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = (*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = (*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[i].w;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n <= 0) {
        return -2;
    }
    memset(buf, 0, n);
    strncpy(buf, (*(NetConfigBufferView * *)&lobby_net_config_buffer)->u.b.ents2[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur].w].s1, n - 1);
    if ((u32)n <= strlen((*(NetConfigBufferView * *)&lobby_net_config_buffer)->u.b.ents2[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur].w].s1)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 TLobby__sub_803F5EC8(char *buf, s32 n) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = (*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = (*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[i].w;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n <= 0) {
        return -2;
    }
    memset(buf, 0, n);
    strncpy(buf, (*(NetConfigBufferView * *)&lobby_net_config_buffer)->u.b.ents2[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur].w].s2, n - 1);
    if ((u32)n <= strlen((*(NetConfigBufferView * *)&lobby_net_config_buffer)->u.b.ents2[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur].w].s2)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 TLobby__sub_803F6000(char *buf, s32 n) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = (*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = (*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[i].w;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n <= 0) {
        return -2;
    }
    memset(buf, 0, n);
    strncpy(buf, (*(NetConfigBufferView * *)&lobby_net_config_buffer)->u.b.ents2[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur].w].s3, n - 1);
    if ((u32)n <= strlen((*(NetConfigBufferView * *)&lobby_net_config_buffer)->u.b.ents2[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur].w].s3)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 TLobby__sub_803F6138(char *buf, s32 n) {
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    i = (*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = (*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[i].w;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (n <= 0) {
        return -2;
    }
    memset(buf, 0, n);
    strncpy(buf, (*(NetConfigBufferView * *)&lobby_net_config_buffer)->u.b.ents2[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur].w].s4, n - 1);
    if ((u32)n <= strlen((*(NetConfigBufferView * *)&lobby_net_config_buffer)->u.b.ents2[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->recs[(*(NetConfigBufferView * *)&lobby_net_config_buffer)->cur].w].s4)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 TLobby__sub_803F6270(u16 *out) {
    NetConfigVersionView *s;
    s16 i;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (get_network_config_backup_mode() == 0 && get_network_config_mode() == 1) {
        return -5;
    }
    s = (*(NetConfigVersionView * *)&lobby_net_config_buffer);
    i = s->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = s->recs[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    *out = s->ents[i].v;
    return 0;
}
#pragma pop
