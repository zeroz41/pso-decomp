#include "pso/network/NetworkTransport.h"
#include "pso/network/NetPppoe.h"
#include "pso/network/ModemRuntime.h"
#include "pso/network/NetworkMessageTransport.h"
#include "pso/network/NetworkRuntime.h"
#include "types.h"
#include <stddef.h>
#include "pso/network/NetStackTypes.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct PppoeSlot {
    s16 state;
    u16 id;
    s16 reused;            /* the slot was taken over from a closed (state 6) session */
    s16 retries;           /* resends left before the current discovery step gives up */
    s32 timeout;
    s32 last;
    u8 local_mac[6];
    u8 broadcast_mac[6];   /* the PADI destination */
    u16 service_name_ok;   /* the offer carried the wanted Service-Name (or none was asked for) */
    u16 ac_name_ok;        /* the offer carried the wanted AC-Name (or none was asked for) */
    u8 *ac_mac;            /* the access concentrator's MAC, in the offer */
    u8 *ac_cookie;         /* AC-Cookie tag (0x104) to echo, in the offer */
    u16 ac_cookie_len;
    u8 pad2A[2];
    u8 *relay_session_id;  /* Relay-Session-Id tag (0x110) to echo */
    u16 relay_session_id_len;
    u8 host_uniq[8];       /* Host-Uniq tag (0x103): the slot address and the open time */
    PppoeNames names;
    u8 frame[0x5EA];
    u16 frame_len;
    u8 rx_frame[0x5EA];
    u16 rx_frame_len;
    u8 padE12[0xE14 - 0xE12];
};
LAYOUT_ASSERT(PppoeSlot_size, sizeof(PppoeSlot) == 0xE14);
LAYOUT_ASSERT(PppoeSlot_frame_offset, offsetof(PppoeSlot, frame) == 0x23A);
LAYOUT_ASSERT(PppoeSlot_frame_length_offset, offsetof(PppoeSlot, frame_len) == 0x824);
LAYOUT_ASSERT(PppoeSlot_rx_frame_offset, offsetof(PppoeSlot, rx_frame) == 0x826);
LAYOUT_ASSERT(PppoeSlot_rx_length_offset, offsetof(PppoeSlot, rx_frame_len) == 0xE10);

/* lobby_pppoe_slot_table: the client's one session and the address received frames must be sent to. */
typedef struct PppoeTable {
    PppoeSlot slots[1];
    u8 mac[6];                  /* 0xE14: no code in this build writes it */
    u8 padE1A[6];
} PppoeTable;
LAYOUT_ASSERT(PppoeTable_size_check, sizeof(PppoeTable) == 0xE20);

extern u8 lbl_805CF240[0xA0];
extern u8 pppoe_message_queue[0xA0];
extern u8 transport_message_queue[0x48];
PppoeTable lobby_pppoe_slot_table;
extern u8 transport_message_queue[];
extern u8 pppoe_message_queue[];

extern u8 lbl_805CF240[];

PppoeSlot *find_pppoe_slot_by_session_id(u8 *frame, u16 frame_len);
s16 pppoe_parse_pads_tags(PppoeSlot *e, u8 *p, u16 len);
s16 pppoe_send_discovery(PppoeSlot *e);
s32 detach_pppoe_protocols(s32);
s16 pppoe_build_padr_tags(PppoeSlot *e);
s16 pppoe_build_padi_tags(PppoeSlot *self);
PppoeSlot *pppoe_find_slot_by_host_uniq(u8 *p, u16 len);
void pppoe_process_slot(PppoeSlot *e);
s16 handle_pppoe_discovery_frame(u8 *frame, u16 frame_len);
s16 pppoe_parse_pado_tags(PppoeSlot *e, u8 *p, u16 len);



s16 build_ethernet_frame_header(void *frame, void *dst_mac, void *src_mac, u16 type, u8 code, u16 session, u16 len) {
  u8 *p;
  u8 c;
  u16 t;
  u16 x;
  u8 *eth;
  u16 l;
  s16 r;
  eth = ((u8 *)frame);
  NetMemcpy(eth, dst_mac, 6);
  NetMemcpy(eth + 6, src_mac, 6);
  t = type;
  NetMemcpy(((u8 *)frame) + 0xC, &t, 2);
  p = eth + 0xE;
  c = 0x11;
  NetMemcpy(p, &c, 1);
  NetMemcpy(p + 1, &code, 1);
  x = session;
  NetMemcpy(p + 2, &x, 2);
  l = len;
  NetMemcpy(p + 4, &l, 2);
  r = ((u32) len) + 0x14;
  if (r < 0x3C)
  {
    r = 0x3C;
  }
  return r;
}

inline s16 put_service_name(u8 **p, PppoeSlot *e) {
    u16 type;
    u16 len;
    s16 n;
    s16 ret;
    type = 0x101;
    NetMemcpy(*p, &type, 2);
    *p += 2;
    n = NetStringLength((char *)e->names.service);
    len = n;
    NetMemcpy(*p, &len, 2);
    *p += 2;
    NetMemcpy(*p, e->names.service, n);
    ret = n + 4;
    *p += n;
    return ret;
}

inline s16 put_host_uniq(u8 **p, PppoeSlot *e) {
    u16 type;
    u16 len;
    s16 ret;
    type = 0x103;
    NetMemcpy(*p, &type, 2);
    *p += 2;
    len = 8;
    NetMemcpy(*p, &len, 2);
    *p += 2;
    NetMemcpy(*p, e->host_uniq, 8);
    *p += 8;
    ret = 12;
    return ret;
}

inline s16 put_ac_cookie(u8 **p, PppoeSlot *e) {
    u16 type;
    u16 len;
    s16 n = 0;
    if (e->ac_cookie != NULL) {
        type = 0x104;
        NetMemcpy(*p, &type, 2);
        *p += 2;
        len = e->ac_cookie_len;
        NetMemcpy(*p, &len, 2);
        *p += 2;
        NetMemcpy(*p, e->ac_cookie, e->ac_cookie_len);
        n = e->ac_cookie_len + 4;
        *p += e->ac_cookie_len;
    }
    return n;
}

inline s16 put_relay_session_id(u8 **p, PppoeSlot *e) {
    u16 type;
    u16 len;
    s16 n = 0;
    if (e->relay_session_id != NULL) {
        type = 0x110;
        NetMemcpy(*p, &type, 2);
        *p += 2;
        len = e->relay_session_id_len;
        NetMemcpy(*p, &len, 2);
        *p += 2;
        NetMemcpy(*p, e->relay_session_id, e->relay_session_id_len);
        n = e->relay_session_id_len + 4;
        *p += e->relay_session_id_len;
    }
    return n;
}

inline s16 put_end_of_list(u8 **p) {
    u16 type;
    u16 len;
    s16 ret;
    type = 0;
    NetMemcpy(*p, &type, 2);
    *p += 2;
    len = 0;
    NetMemcpy(*p, &len, 2);
    *p += 2;
    ret = 4;
    return ret;
}

inline s16 put_end_of_list3(u8 **p) {
    s32 tag;
    u16 type;
    u16 len;
    s16 ret;
    tag = 0;
    type = 0;
    NetMemcpy(*p, &type, 2);
    len = 0;
    NetMemcpy(*p + 2, &len, 2);
    *p += 4;
    ret = 4;
    return ret;
}

#pragma push
#pragma opt_propagation off
s16 pppoe_send_discovery(PppoeSlot *e) {
    void *src;
    u8 *p;
    s16 n;
    u16 type;
    u8 flag;
    s32 padA;
    s32 padB;
    s32 padC;
    switch (e->state) {
    case 0:
    case 1:
        n = pppoe_build_padi_tags(e);
        if (n >= 0) {
            src = e->broadcast_mac;
            type = 0x8863;
            flag = 9;
            break;
        }
        goto out;
    case 2:
    case 3:
        n = pppoe_build_padr_tags(e);
        if (n >= 0) {
            src = e->ac_mac;
            type = 0x8863;
            flag = 0x19;
            break;
        }
        goto out;
    case 5:
        if (e->id == 0) {
            n = -1;
            goto out;
        }
        p = e->frame + 0x14;
        n = put_end_of_list3(&p);
        if (n >= 0) {
            src = e->ac_mac;
            type = 0x8863;
            n = 2 + 2;
            flag = 0xA7;
            break;
        }
        goto out;
    case 4:
    default:
        n = -1;
        goto out;
    }
    n = build_ethernet_frame_header((e->frame), src, e->local_mac, type, flag, e->id, n);
    e->frame_len = n;
out:
    return n;
}
#pragma pop
s16 pppoe_build_padr_tags(PppoeSlot *e) {
    u8 *p;
    s16 n;
    s16 total;
    p = e->frame + 0x14;
    n = put_service_name(&p, e);
    if (n < 0) {
        return -1;
    }
    total = n;
    total += put_host_uniq(&p, e);
    n = put_ac_cookie(&p, e);
    if (n < 0) {
        return -1;
    }
    total += n;
    n = put_relay_session_id(&p, e);
    if (n < 0) {
        return -1;
    }
    total += n;
    total += put_end_of_list(&p);
    return total;
}

#pragma push
#pragma opt_common_subs off
#pragma opt_lifetimes off
s16 pppoe_build_padi_tags(PppoeSlot *self) {
    u8 pad1[4];
    u8 *p;
    u16 w[8];
    u8 pad2[12];
    s16 len;
    s16 n;
    s16 r;

    p = self->frame + 0x14;
    w[6] = 0x101;
    NetMemcpy(p, &w[6], 2);
    p += 2;
    n = NetStringLength((const char *)(self->names.service));
    w[7] = n;
    NetMemcpy(p, &w[7], 2);
    p += 2;
    NetMemcpy(p, self->names.service, n);
    p += n;
    len = n + 4;
    if (len < 0) {
        return -1;
    }
    r = write_pppoe_ac_name_tag(&p, self);
    if (r < 0) {
        return -1;
    }
    r = len + r;
    w[3] = 0x103;
    NetMemcpy(p, &w[3], 2);
    p += 2;
    w[4] = 8;
    NetMemcpy(p, &w[4], 2);
    p += 2;
    NetMemcpy(p, self->host_uniq, 8);
    p += 8;
    w[0] = 0;
    NetMemcpy(p, &w[0], 2);
    p += 2;
    w[1] = 0;
    NetMemcpy(p, &w[1], 2);
    return r + 0x10;
}
#pragma pop

s16 write_empty_tlv_header(u8 **p, PppoeSlot *e) {
    u16 type;
    u16 len;
    s16 ret;
    type = 0;
    NetMemcpy(*p, &type, 2);
    *p += 2;
    len = 0;
    NetMemcpy(*p, &len, 2);
    *p += 2;
    ret = 4;
    return ret;
}

#pragma push
#pragma opt_common_subs off
s16 write_pppoe_ac_name_tag(u8 **cursor, PppoeSlot *slot) {
    s16 sp12;
    s16 sp10;
    s16 name_len;
    if (slot->names.name[0] == 0) {
        return 0;
    }
    sp12 = 0x102;
    NetMemcpy(*cursor, (&sp12), 2);
    *cursor += 2;
    name_len = NetStringLength((char *)slot->names.name);
    sp10 = name_len;
    NetMemcpy(*cursor, (&sp10), 2);
    *cursor += 2;
    NetMemcpy(*cursor, (char *)slot->names.name, (name_len));
    *cursor += name_len;
    return name_len + 4;
}
#pragma pop

inline s16 build_padt(PppoeSlot *e) {
    u8 *payload;
    u8 *p;
    s16 n;
    payload = e->frame + 0x14;
    p = payload;
    n = write_empty_tlv_header(&p, e);
    if (n < 0) {
        return -1;
    }
    return n;
}

inline void restart_timer(PppoeSlot *e, s16 retries, s32 timeout) {
    get_time_ms(&e->last);
    e->timeout = timeout;
    e->retries = retries;
}

void pppoe_process_slot(PppoeSlot *self) {
    u16 a;
    u16 q;
    u8 *w;
    u8 buf[8];
    u8 *p;
    s32 tm;
    s16 cnt;
    s16 r;

    switch (self->state) {
    case 0:
        if (self->retries > 0) {
            r = pppoe_terminate_hook();
            if (r >= 0) {
                u16 h;
                if (self->reused) {
                    p = self->frame + 0x14;
                    q = 0xC021;
                    NetMemcpy(p, &q, 2);
                    p[2] = 5;
                    p[3] = 1;
                    a = 4;
                    NetMemcpy(p + 4, &a, 2);
                    self->frame_len = build_ethernet_frame_header(self->frame, self->ac_mac, self->local_mac, 0x8864, 0, self->id, 6);
                    post_send_message(self->frame, self->frame_len);
                    w = p;
                    r = write_empty_tlv_header(&w, self);
                    if (r < 0) {
                        r = -1;
                    }
                    if (r >= 0) {
                        self->frame_len = build_ethernet_frame_header(self->frame, self->ac_mac, self->local_mac, 0x8863, 0xa7, self->id, r);
                        post_send_message(self->frame, self->frame_len);
                    }
                }
                self->id = 0;
                r = pppoe_send_discovery(self);
                if (r < 0) {
                    return;
                }
                h = self->frame_len;
                post_send_message(self->frame, h);
                self->state = 1;
                get_time_ms(&self->last);
                self->timeout = 0xbb8;
                self->retries = 2;
                return;
            }
            tm = self->timeout;
            cnt = self->retries - 1;
            get_time_ms(&self->last);
            self->timeout = tm;
            self->retries = cnt;
        } else {
            self->timeout = 0;
            self->state = -1;
        }
        break;
    case 1:
    case 3:
        if (self->retries > 0) {
            u16 h;
            r = pppoe_send_discovery(self);
            if (r >= 0) {
                h = self->frame_len;
                post_send_message(self->frame, h);
            }
            tm = self->timeout * 2;
            cnt = self->retries - 1;
            get_time_ms(&self->last);
            self->timeout = tm;
            self->retries = cnt;
        } else {
            self->timeout = 0;
            self->state = 5;
        }
        break;
    case 2:
    case 4:
    case 5:
        break;
    default:
        break;
    }
}

inline s16 send_frame(PppoeSlot *e, u16 len) {
    return post_send_message(e->frame, len);
}

// PPPoE discovery receive: PADO (7) / PADS (0x65) / PADT (0xA7) by the code byte of the header.
s16 handle_pppoe_discovery_frame(u8 *frame, u16 frame_len) {
    s16 ret = -1;
    u8 *base = frame + 0xe;
    u8 *sub = base + 6;
    s32 pad[2];
    u8 cmd;
    u16 id;
    u16 hdr;
    u8 spare[2];
    PppoeSlot *p;
    s16 t;

    NetMemcpy(&id, base + 4, 2);
    NetMemcpy(&cmd, base + 1, 1);
    switch (cmd) {
    case 0x7:
        p = pppoe_find_slot_by_host_uniq(sub, id);
        if (p == NULL) {
            ret = 0;
            break;
        }
        if (p->state != 1) {
            ret = -1;
            break;
        }
        p->timeout = 0;
        NetMemcpy(p->rx_frame, frame, frame_len);
        p->rx_frame_len = frame_len;
        ret = pppoe_parse_pado_tags(p, p->rx_frame + 0x14, id);
        if (ret <= 0) {
            break;
        }
        p->ac_mac = p->rx_frame + 6;
        p->state = 2;
        ret = pppoe_send_discovery(p);
        if (ret < 0) {
            break;
        }
        {
            u16 sz = p->frame_len;
            t = post_send_message(p->frame, sz);
        }
        ret = t;
        if (ret != 0) {
            break;
        }
        p->state = 3;
        get_time_ms((s32 *)&p->last);
        p->timeout = 3000;
        *(s16 *)((u8 *)p + 6) = 2;
        break;
    case 0x65:
        p = pppoe_find_slot_by_host_uniq(sub, id);
        if (p == NULL) {
            ret = 0;
            break;
        }
        if (p->state != 3) {
            ret = -1;
            break;
        }
        p->timeout = 0;
        ret = pppoe_parse_pads_tags(p, sub, id);
        if (ret <= 0) {
            break;
        }
        NetMemcpy(&hdr, base + 2, 2);
        p->id = hdr;
        p->state = 4;
        break;
    case 0xa7:
        p = find_pppoe_slot_by_session_id(frame, frame_len);
        if (p == NULL) {
            ret = 0;
            break;
        }
        p->timeout = 0;
        skip_pppoe_tags(p, sub, id);
        if (p->state == 4) {
            p->state = 5;
            ret = pppoe_send_discovery(p);
            if (ret >= 0) {
                u16 sz = p->frame_len;
                ret = post_send_message(p->frame, sz);
            }
            break;
        }
        if (p->state != -1) {
            detach_pppoe_protocols(0);
        }
        p->state = -1;
        ret = 0;
        break;
    }
    return ret;
}

s32 skip_pppoe_tags(PppoeSlot *slot, u8 *tags, u16 tags_len) {
    u8 *p = tags;
    u16 len = tags_len;
    u16 a;
    u16 b;
    u8 pad[4];
    s32 t;
    while (len != 0) {
        NetMemcpy(&a, p, 2);
        if (a == 0) {
            break;
        }
        NetMemcpy(&b, p + 2, 2);
        t = b + 4;
        p += t;
        len -= t;
    }
    return 0;
}

s16 pppoe_parse_pads_tags(PppoeSlot *e, u8 *p, u16 len) {
    s16 result = 1;
    u8 *cur = p;
    u16 type;
    u16 tag_len;
    u8 *data;
    while (len != 0) {
        NetMemcpy(&type, cur, 2);
        if (type == 0) {
            break;
        }
        NetMemcpy(&tag_len, cur + 2, 2);
        data = cur + 4;
        switch (type) {
        case 0x101:
        case 0x103:
            break;
        case 0x110:
            e->relay_session_id = data;
            e->relay_session_id_len = tag_len;
            break;
        case 0x201:
            result = -1;
            goto done;
        case 0x202:
            result = -1;
            goto done;
        case 0x203:
            result = -1;
            goto done;
        }
        cur += tag_len + 4;
        len -= tag_len + 4;
    }
done:
    return result;
}

s16 pppoe_parse_pado_tags(PppoeSlot *e, u8 *p, u16 len) {
    s16 result = 0;
    u8 *cur;
    u16 type;
    u16 tag_len;
    u8 *data;
    e->service_name_ok = 1;
    if (e->names.service[0] != 0) {
        e->service_name_ok = 0;
    }
    e->ac_name_ok = 1;
    if (e->names.name[0] != 0) {
        e->ac_name_ok = 0;
    }
    cur = p;
    while (len != 0) {
        NetMemcpy(&type, cur, 2);
        if (type == 0) {
            break;
        }
        NetMemcpy(&tag_len, cur + 2, 2);
        data = cur + 4;
        switch (type) {
        case 0x101:
            if (e->names.service[0] != 0 && NetMemcmp(e->names.service, data, tag_len) == 0) {
                e->service_name_ok = 1;
            }
            break;
        case 0x102:
            if (e->names.name[0] != 0 && NetMemcmp(e->names.name, data, tag_len) == 0) {
                e->ac_name_ok = 1;
            }
            break;
        case 0x103:
            break;
        case 0x104:
            e->ac_cookie = data;
            e->ac_cookie_len = tag_len;
            break;
        case 0x110:
            e->relay_session_id = data;
            e->relay_session_id_len = tag_len;
            break;
        case 0x201:
            result = -1;
            goto done;
        case 0x202:
            result = -1;
            goto done;
        case 0x203:
            result = -1;
            goto done;
        }
        cur += tag_len + 4;
        len -= tag_len + 4;
    }
done:
    if (result == 0 && e->service_name_ok != 0 && e->ac_name_ok != 0) {
        result = 1;
    }
    return result;
}

PppoeSlot *pppoe_find_slot_by_host_uniq(u8 *p, u16 len) {
    PppoeSlot *e;
    PppoeSlot *ret = NULL;
    u8 *cur = p;
    s16 i;
    u8 *data;
    u16 type;
    u16 tag_len;
    while (len != 0) {
        NetMemcpy(&type, cur, 2);
        if (type == 0) {
            break;
        }
        NetMemcpy(&tag_len, cur + 2, 2);
        switch (type) {
        case 0x103:
            if (tag_len != 8) {
                ret = NULL;
                goto done;
            }
            e = lobby_pppoe_slot_table.slots;
            data = cur + 4;
            i = 0;
            ret = NULL;
            for (; i < 1; e++, i++) {
                ret = e;
                if (NetMemcmp(data, ret->host_uniq, 8) == 0) {
                    break;
                }
            }
            if (i >= 1) {
                ret = NULL;
                goto done;
            }
            break;
        }
        cur += tag_len + 4;
        len -= tag_len + 4;
    }
done:
    return ret;
}

PppoeSlot *find_pppoe_slot_by_session_id(u8 *frame, u16 frame_len) {
    u16 id;
    PppoeSlot *ret;
    s16 i;
    if (frame_len < 0x14U) {
        return NULL;
    }
    NetMemcpy(&id, frame + 0x10, 2);
    if (id == 0) {
        return NULL;
    }
    i = 0;
    ret = NULL;
    while (i < 1) {
        ret = &lobby_pppoe_slot_table.slots[i];
        if (id == ret->id) {
            break;
        }
        i++;
    }
    if (i >= 1) {
        ret = NULL;
    }
    return ret;
}

s16 get_pppoe_session_id(s16 slot) {
    if ((slot < 0) || (slot >= 1)) {
        return -1;
    }
    return lobby_pppoe_slot_table.slots[slot].state;
}

#pragma push
#pragma inline_depth(4)
static inline void check_pppoe_timeouts(void) {
    s32 now;
    PppoeSlot *p;
    s16 i;
    get_time_ms(&now);
    for (p = lobby_pppoe_slot_table.slots, i = 0; i < 1; p++, i++) {
        if (p->state != -1 && p->timeout != 0 && now - p->last > p->timeout) {
            pppoe_process_slot(p);
        }
    }
}
s16 pppoe_recv_packet(void *buf, u16 bufLen, u16 *outLen) {
    u16 type;
    u8 *pkt;
    u16 id;
    s32 padA;
    u16 len;
    s32 padB;
    PppoeSlot *e;
    s16 ret;
    u8 *src;
    check_pppoe_timeouts();
    if (recv_pppoe_message(&pkt, &id) == 0) {
        if (outLen != NULL) {
            *outLen = 0;
        }
        return 0;
    }
    NetMemcpy(&type, pkt + 0xC, 2);
    if (type != 0x8863 && type != 0x8864) {
        ret = 0;
    } else if (NetMemcmp(pkt, lobby_pppoe_slot_table.mac, 6) != 0) {
        ret = 0;
    } else if (pkt[0xE] != 0x11) {
        ret = 0;
    } else if (type == 0x8863) {
        ret = handle_pppoe_discovery_frame(pkt, id);
    } else {
        ret = 0;
        NetMemcpy(&len, pkt + 0x12, 2);
        src = pkt + 0x14;
        if (buf != NULL && len <= bufLen) {
            e = find_pppoe_slot_by_session_id(pkt, id);
            if (e != NULL && e->state == 4) {
                ret = e - lobby_pppoe_slot_table.slots;
                NetMemcpy(buf, src, len);
                if (outLen != NULL) {
                    *outLen = len;
                }
                clear_message_entry_wrapper(pkt);
                return ret;
            }
        }
    }
    clear_message_entry_wrapper(pkt);
    if (outLen != NULL) {
        *outLen = 0;
    }
    return ret;
}
#pragma pop

s16 pppoe_send_session_frame(s16 slot, u8 *frame, u16 len) {
    PppoeSlot *e;
    u8 *hdr;
    u16 type;
    u8 version;
    u8 code;
    u16 session;
    u16 length;
    u8 *src;
    u8 *dst;
    u16 frame_len;
    if (slot < 0 || slot >= 1) {
        return -1;
    }
    e = &lobby_pppoe_slot_table.slots[slot];
    if (e->state != 4) {
        return -1;
    }
    hdr = frame + 0xE;
    version = 0x11;
    NetMemcpy(hdr, &version, 1);
    code = 0;
    NetMemcpy(hdr + 1, &code, 1);
    session = e->id;
    NetMemcpy(hdr + 2, &session, 2);
    length = len;
    NetMemcpy(hdr + 4, &length, 2);
    dst = e->ac_mac;
    type = 0x8864;
    src = e->local_mac;
    NetMemcpy(frame, dst, 6);
    NetMemcpy(frame + 6, src, 6);
    NetMemcpy(frame + 0xC, &type, 2);
    e->frame_len = len + 0x14;
    if (e->frame_len < 0x3C) {
        e->frame_len = 0x3C;
    }
    frame_len = e->frame_len;
    return post_send_message(frame, frame_len);
}

s32 pppoe_close(s16 slot) {
    PppoeSlot *e;
    if (slot < 0 || slot >= 1) {
        return -1;
    }
    e = &lobby_pppoe_slot_table.slots[slot];
    switch (e->state) {
    case 0:
        if (e->state != -1) {
            detach_pppoe_protocols(0);
        }
        e->state = -1;
        break;
    case 1:
        if (e->state != -1) {
            detach_pppoe_protocols(0);
        }
        e->state = -1;
        break;
    case 2:
        if (e->state != -1) {
            detach_pppoe_protocols(0);
        }
        e->state = -1;
        break;
    case 3:
        e->state = 5;
        break;
    case 4:
        e->state = 5;
        if (pppoe_send_discovery(e) >= 0) {
            u16 frame_len = e->frame_len;
            post_send_message((e->frame), frame_len);
        }
        break;
    case 5:
        if (e->state != -1) {
            detach_pppoe_protocols(0);
        }
        if (e->id != 0) {
            e->state = 6;
        } else {
            e->state = -1;
        }
        break;
    }
    return 0;
}

s16 pppoe_open(PppoeNames *names) {
    PppoeSlot *tbl;
    PppoeSlot *p;
    PppoeSlot *e;
    s32 now;
    saddr stamp;
    s16 i;
    s16 slot;
    s16 set;

    tbl = (0, (PppoeSlot *)&lobby_pppoe_slot_table);
    set = 0;
    for (p = &tbl[0], i = 0; i < 1; p++, (i++) & 0xFFFFFFFFFFFFFFFF) {
        if (p->state == 6) {
            p->state = -1;
            set = 1;
            break;
        }
    }
    for (p = &tbl[0], i = 0, e = NULL; i < 1; p++, i++) {
        e = p;
        if (e->state == -1) {
            slot = i;
            break;
        }
    }
    if (e == NULL) {
        return -1;
    }
    if (open_pppoe_adapter((u8 *)&tbl[1]) < 0) {
        return -1;
    }
    e->names = *names;
    e->reused = set;
    stamp = (saddr)e;
    get_time_ms(&now);
    NetMemcpy(e->host_uniq, &stamp, 4);
    NetMemcpy(e->host_uniq + 4, &now, 4);
    NetMemcpy(e->local_mac, (u8 *)&tbl[1], 6);
    NetMemcpy(e->broadcast_mac, (u8 *)&tbl[1] + 6, 6);
    e->ac_cookie = NULL;
    e->relay_session_id = NULL;
    e->retries = 0;
    e->timeout = 0;
    e->state = 0;
    get_time_ms(&e->last);
    e->timeout = 200;
    e->retries = 50;
    return slot;
}

s32 pppoe_term_rtos(void) {
    return 0;
}

s16 pppoe_init_rtos(s32 unused) {
    lobby_pppoe_slot_table.slots[0].state = -1;
    return 0;
}
