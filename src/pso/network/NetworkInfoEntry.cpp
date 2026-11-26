#include "types.h"
#include <string.h>
#include "pso/network/NetworkInfoLoader.h"
#include "pso/network/NetworkInfoEntry.h"
#include "pso/network/TLobby.h"









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




extern NetConfigBuffer *lobby_net_config_buffer;
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
    strncpy(dst, lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].name, len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].name)) {
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
    strncpy(dst, lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].name2, len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].name2)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_current_entry_dns1(void *dst) {
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
    memcpy(dst, &b->rec[i].f1B8, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_current_entry_dns2(void *dst) {
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
    memcpy(dst, &b->rec[i].f1BC, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_current_entry_dial_type(u8 *dst) {
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
    if (b->rec[i].kind != 1) {
        return -3;
    }
    *dst = b->rec[i].f208;
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
    i = lobby_net_config_buffer->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (lobby_net_config_buffer->rec[i].kind != 1) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].str20C, len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].str20C)) {
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
    if (lobby_net_config_buffer->rec[i].kind != 1) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].strs[0] + (n *= 0x20), len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].strs[0] + n)) {
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
    i = lobby_net_config_buffer->cur;
    if (i < 0 || i >= 6) {
        return -3;
    }
    i = lobby_net_config_buffer->ent[i].v;
    if (i < 0 || i >= 6) {
        return -3;
    }
    if (lobby_net_config_buffer->rec[i].kind != 1) {
        return -3;
    }
    if (len <= 0) {
        return -2;
    }
    memset(dst, 0, len);
    strncpy(dst, lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].str290, len - 1);
    if ((u32)len <= strlen(lobby_net_config_buffer->rec[lobby_net_config_buffer->ent[lobby_net_config_buffer->cur].v].str290)) {
        return -2;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_current_entry_connection_type(u8 *dst) {
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
    if (b->rec[i].kind != 4) {
        return -3;
    }
    *dst = b->rec[i].f2B0;
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
s32 get_current_entry_ip_addr(void *dst) {
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
    if (b->rec[i].kind != 4) {
        return -3;
    }
    memcpy(dst, &b->rec[i].f2B4, 4);
    return 0;
}
#pragma pop

#pragma push
#pragma peephole off
#pragma scheduling off
s32 get_current_entry_netmask(void *dst) {
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
s32 get_current_entry_gateway(void *dst) {
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
s32 copy_current_entry_dhcp_hostname(char *buf, u32 n) {
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
