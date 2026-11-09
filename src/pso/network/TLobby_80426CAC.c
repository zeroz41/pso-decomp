#include "pso/network/NetworkTransport.h"
#include "pso/network/TLobby_80426CAC.h"
#include "pso/network/ModemRuntime.h"
#include "pso/network/NetworkMessageTransport.h"
#include "pso/network/NetworkRuntime.h"
#include "types.h"
#include "pso/network/NetStackTypes.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

typedef struct PppoeNames {
    u8 name[0x100];
    u8 service[0x100];
} PppoeNames;

typedef struct PppoeSlot {
    s16 state;
    u16 id;
    s16 m_4;
    s16 m_6;
    s32 timeout;
    s32 last;
    u8 m_10[6];
    u8 m_16[6];
    u16 m_1C;
    u16 m_1E;
    u8 *m_20;
    u8 *m_24;
    u16 m_28;
    u8 pad2A[2];
    u8 *m_2C;
    u16 m_30;
    u8 m_32[8];
    PppoeNames names;
    u8 frame[0x5EA];
    u16 frame_len;
    u8 rx_frame[0x5EA];
    u16 rx_frame_len;
    u8 padE12[0xE14 - 0xE12];
} PppoeSlot;

/* lobby_pppoe_slot_table: the client's one session and the address received frames must be sent to. */
typedef struct PppoeTable {
    PppoeSlot slots[1];
    u8 mac[6];                  /* 0xE14: no code in this build writes it */
    u8 padE1A[6];
} PppoeTable;
typedef char PppoeTable_size_check[sizeof(PppoeTable) == 0xE20 ? 1 : -1];

extern u8 lbl_805CF240[0xA0];
extern u8 pppoe_message_queue[0xA0];
extern u8 lbl_805CF380[0x48];
PppoeTable lobby_pppoe_slot_table;
extern u8 lbl_805CF380[];
extern u8 pppoe_message_queue[];

extern u8 lbl_805CF240[];

PppoeSlot *find_pppoe_slot_by_session_id(s32 arg0, u16 arg1);
s16 TLobby__sub_8042787C(PppoeSlot *e, u8 *p, u16 len);
s16 TLobby__sub_80426D80(PppoeSlot *e);
s32 TLobby__sub_80426574(s32);
s16 TLobby__sub_80426EB8(PppoeSlot *e);
s16 TLobby__sub_804270C0(u8 *self);
PppoeSlot *TLobby__sub_80427B6C(u8 *p, u16 len);
void TLobby__sub_80427378(PppoeSlot *e);
s16 handle_pppoe_discovery_frame(s32, u16);
s16 TLobby__sub_80427988(PppoeSlot *e, u8 *p, u16 len);

#define arg0 ((s32)argp)
#undef arg0

s16 build_ethernet_frame_header(void *frame, void *src, void *mac, u16 type, u8 flag, u16 a, u16 len);
s32 write_pppoe_ac_name_tag(s32 *arg0, u8 *arg1);
s32 skip_pppoe_tags(s32 arg0, u8 *arg1, u16 arg2);
s16 get_pppoe_session_id(s16 arg0);
s16 pppoe_recv_packet(void *buf, u16 bufLen, u16 *outLen);

typedef struct Unk804271E8Blk {
    u32 w[0x80];
} Unk804271E8Blk;

s16 build_ethernet_frame_header(void *frame, void *src, void *mac, u16 type, u8 flag, u16 a, u16 len) {
  u8 *p;
  u8 c;
  u16 t;
  u16 x;
  u8 *new_var;
  u16 l;
  s16 r;
  new_var = ((u8 *)frame);
  NetMemcpy(new_var, src, 6);
  NetMemcpy(new_var + 6, mac, 6);
  t = type;
  NetMemcpy(((u8 *)frame) + 0xC, &t, 2);
  p = new_var + 0xE;
  c = 0x11;
  NetMemcpy(p, &c, 1);
  NetMemcpy(p + 1, &flag, 1);
  x = a;
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
    NetMemcpy(*p, e->m_32, 8);
    *p += 8;
    ret = 12;
    return ret;
}

inline s16 put_ac_cookie(u8 **p, PppoeSlot *e) {
    u16 type;
    u16 len;
    s16 n = 0;
    if (e->m_24 != NULL) {
        type = 0x104;
        NetMemcpy(*p, &type, 2);
        *p += 2;
        len = e->m_28;
        NetMemcpy(*p, &len, 2);
        *p += 2;
        NetMemcpy(*p, e->m_24, e->m_28);
        n = e->m_28 + 4;
        *p += e->m_28;
    }
    return n;
}

inline s16 put_relay_session_id(u8 **p, PppoeSlot *e) {
    u16 type;
    u16 len;
    s16 n = 0;
    if (e->m_2C != NULL) {
        type = 0x110;
        NetMemcpy(*p, &type, 2);
        *p += 2;
        len = e->m_30;
        NetMemcpy(*p, &len, 2);
        *p += 2;
        NetMemcpy(*p, e->m_2C, e->m_30);
        n = e->m_30 + 4;
        *p += e->m_30;
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
s16 TLobby__sub_80426D80(PppoeSlot *e) {
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
        n = TLobby__sub_804270C0((u8 *)(e));
        if (n >= 0) {
            src = e->m_16;
            type = 0x8863;
            flag = 9;
            break;
        }
        goto out;
    case 2:
    case 3:
        n = TLobby__sub_80426EB8(e);
        if (n >= 0) {
            src = e->m_20;
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
            src = e->m_20;
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
    n = build_ethernet_frame_header((e->frame), src, e->m_10, type, flag, e->id, n);
    e->frame_len = n;
out:
    return n;
}
#pragma pop
s16 TLobby__sub_80426EB8(PppoeSlot *e) {
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
s16 TLobby__sub_804270C0(u8 *self) {
    s16 NetStringLength(const char *);
    s16 write_pppoe_ac_name_tag(s32 *, u8 *);
    u8 pad1[4];
    u8 *p;
    u16 w[8];
    u8 pad2[12];
    s16 len;
    s32 n;
    s16 r;

    p = self + 0x24e;
    w[6] = 0x101;
    NetMemcpy(p, &w[6], 2);
    p += 2;
    n = NetStringLength((const char *)(self + 0x13a));
    w[7] = (u16)n;
    NetMemcpy(p, &w[7], 2);
    p += 2;
    NetMemcpy(p, self + 0x13a, n);
    p += n;
    len = n + 4;
    if (len < 0) {
        return -1;
    }
    r = write_pppoe_ac_name_tag((s32 *)&p, self);
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
    NetMemcpy(p, self + 0x32, 8);
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
s32 write_pppoe_ac_name_tag(s32 *arg0, u8 *arg1) {
typedef struct Fields_arg1 { u8 pad_0[58]; char name[1]; } Fields_arg1;
    s16 sp12;
    s16 sp10;
    s16 temp_r3;
    if ((u8) ((Fields_arg1*)arg1)->name[0] == 0) {
        return 0;
    }
    sp12 = 0x102;
    NetMemcpy((void *)(*arg0), (&sp12), 2);
    *arg0 += 2;
    temp_r3 = NetStringLength(((Fields_arg1*)arg1)->name);
    sp10 = temp_r3;
    NetMemcpy((void *)(*arg0), (&sp10), 2);
    *arg0 += 2;
    NetMemcpy((void *)(*arg0), ((Fields_arg1*)arg1)->name, (temp_r3));
    *arg0 += temp_r3;
    return temp_r3 + 4;
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
    e->m_6 = retries;
}

void TLobby__sub_80427378(PppoeSlot *self) {
    s16 write_empty_tlv_header(); /* declared without a parameter list; the definition is s16 (u8 **, PppoeSlot *) */
    s16 TLobby__sub_80426440(); /* declared s16 here; the definition returns s32 */
    void *v = self;
    u16 a;
    u16 q;
    u8 *w;
    u8 buf[8];
    u8 *s = v;
    u8 *p;
    s32 tm;
    s16 cnt;
    s16 r;

    switch (*(s16 *)s) {
    case 0:
        if (*(s16 *)(s + 6) > 0) {
            r = TLobby__sub_80426440();
            if (r >= 0) {
                u16 h;
                if (*(s16 *)(s + 4)) {
                    p = s + 0x24e;
                    q = 0xC021;
                    NetMemcpy(p, &q, 2);
                    p[2] = 5;
                    p[3] = 1;
                    a = 4;
                    NetMemcpy(p + 4, &a, 2);
                    *(s16 *)(s + 0x824) = build_ethernet_frame_header(s + 0x23a, *(void **)(s + 0x20), s + 0x10, 0x8864, 0, *(u16 *)(s + 2), 6);
                    post_send_message(s + 0x23a, *(u16 *)(s + 0x824));
                    w = p;
                    r = write_empty_tlv_header(&w, s);
                    if (r < 0) {
                        r = -1;
                    }
                    if (r >= 0) {
                        *(s16 *)(s + 0x824) = build_ethernet_frame_header(s + 0x23a, *(void **)(s + 0x20), s + 0x10, 0x8863, 0xa7, *(u16 *)(s + 2), r);
                        post_send_message(s + 0x23a, *(u16 *)(s + 0x824));
                    }
                }
                *(u16 *)(s + 2) = 0;
                r = TLobby__sub_80426D80((void *)(s));
                if (r < 0) {
                    return;
                }
                h = *(u16 *)(s + 0x824);
                post_send_message(s + 0x23a, h);
                *(s16 *)s = 1;
                get_time_ms((s32 *)(s + 0xc));
                *(s32 *)(s + 8) = 0xbb8;
                *(s16 *)(s + 6) = 2;
                return;
            }
            tm = *(s32 *)(s + 8);
            cnt = *(s16 *)(s + 6) - 1;
            get_time_ms((s32 *)(s + 0xc));
            *(s32 *)(s + 8) = tm;
            *(s16 *)(s + 6) = cnt;
        } else {
            *(s32 *)(s + 8) = 0;
            *(s16 *)s = -1;
        }
        break;
    case 1:
    case 3:
        if (*(s16 *)(s + 6) > 0) {
            u16 h;
            r = TLobby__sub_80426D80((void *)(s));
            if (r >= 0) {
                h = *(u16 *)(s + 0x824);
                post_send_message(s + 0x23a, h);
            }
            tm = *(s32 *)(s + 8) * 2;
            cnt = *(s16 *)(s + 6) - 1;
            get_time_ms((s32 *)(s + 0xc));
            *(s32 *)(s + 8) = tm;
            *(s16 *)(s + 6) = cnt;
        } else {
            *(s32 *)(s + 8) = 0;
            *(s16 *)s = 5;
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
s16 handle_pppoe_discovery_frame(s32 frame, u16 frame_len) {
    s16 ret = -1;
    u8 *base = (u8 *)frame + 0xe;
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
        p = TLobby__sub_80427B6C(sub, id);
        if (p == NULL) {
            ret = 0;
            break;
        }
        if (p->state != 1) {
            ret = -1;
            break;
        }
        p->timeout = 0;
        NetMemcpy((u8 *)p + 0x826, (void *)frame, frame_len);
        *(u16 *)((u8 *)p + 0xe10) = frame_len;
        ret = TLobby__sub_80427988(p, (u8 *)p + 0x83a, id);
        if (ret <= 0) {
            break;
        }
        *(u8 **)((u8 *)p + 0x20) = (u8 *)p + 0x82c;
        p->state = 2;
        ret = TLobby__sub_80426D80(p);
        if (ret < 0) {
            break;
        }
        {
            u16 sz = *(u16 *)((u8 *)p + 0x824);
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
        p = TLobby__sub_80427B6C(sub, id);
        if (p == NULL) {
            ret = 0;
            break;
        }
        if (p->state != 3) {
            ret = -1;
            break;
        }
        p->timeout = 0;
        ret = TLobby__sub_8042787C(p, sub, id);
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
        skip_pppoe_tags((s32)p, sub, id);
        if (p->state == 4) {
            p->state = 5;
            ret = TLobby__sub_80426D80(p);
            if (ret >= 0) {
                u16 sz = *(u16 *)((u8 *)p + 0x824);
                ret = post_send_message(p->frame, sz);
            }
            break;
        }
        if (p->state != -1) {
            TLobby__sub_80426574(0);
        }
        p->state = -1;
        ret = 0;
        break;
    }
    return ret;
}

s32 skip_pppoe_tags(s32 arg0, u8 *arg1, u16 arg2) {
    u8 *p = arg1;
    u16 len = arg2;
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

s16 TLobby__sub_8042787C(PppoeSlot *e, u8 *p, u16 len) {
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
            e->m_2C = data;
            e->m_30 = tag_len;
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

s16 TLobby__sub_80427988(PppoeSlot *e, u8 *p, u16 len) {
    s16 result = 0;
    u8 *cur;
    u16 type;
    u16 tag_len;
    u8 *data;
    e->m_1C = 1;
    if (e->names.service[0] != 0) {
        e->m_1C = 0;
    }
    e->m_1E = 1;
    if (e->names.name[0] != 0) {
        e->m_1E = 0;
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
                e->m_1C = 1;
            }
            break;
        case 0x102:
            if (e->names.name[0] != 0 && NetMemcmp(e->names.name, data, tag_len) == 0) {
                e->m_1E = 1;
            }
            break;
        case 0x103:
            break;
        case 0x104:
            e->m_24 = data;
            e->m_28 = tag_len;
            break;
        case 0x110:
            e->m_2C = data;
            e->m_30 = tag_len;
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
    if (result == 0 && e->m_1C != 0 && e->m_1E != 0) {
        result = 1;
    }
    return result;
}

PppoeSlot *TLobby__sub_80427B6C(u8 *p, u16 len) {
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
                if (NetMemcmp(data, ret->m_32, 8) == 0) {
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

PppoeSlot *find_pppoe_slot_by_session_id(s32 arg0, u16 arg1) {
    u16 id;
    PppoeSlot *ret;
    s16 i;
    if (arg1 < 0x14U) {
        return NULL;
    }
    NetMemcpy(&id, (void *)(arg0 + 0x10), 2);
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

s16 get_pppoe_session_id(s16 arg0) {
    if ((arg0 < 0) || (arg0 >= 1)) {
        return -1;
    }
    return lobby_pppoe_slot_table.slots[arg0].state;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline void check_80427D40(void) {
    s32 now;
    PppoeSlot *p;
    s16 i;
    get_time_ms(&now);
    for (p = lobby_pppoe_slot_table.slots, i = 0; i < 1; p++, i++) {
        if (p->state != -1 && p->timeout != 0 && now - p->last > p->timeout) {
            TLobby__sub_80427378(p);
        }
    }
}
s16 pppoe_recv_packet(void *buf, u16 bufLen, u16 *outLen) {
    u16 type;
    s32 pkt;
    u16 id;
    s32 padA;
    u16 len;
    s32 padB;
    PppoeSlot *e;
    s16 ret;
    u8 *src;
    check_80427D40();
    if (recv_pppoe_message(&pkt, &id) == 0) {
        if (outLen != NULL) {
            *outLen = 0;
        }
        return 0;
    }
    NetMemcpy(&type, (u8 *)pkt + 0xC, 2);
    if (type != 0x8863 && type != 0x8864) {
        ret = 0;
    } else if (NetMemcmp((void *)pkt, lobby_pppoe_slot_table.mac, 6) != 0) {
        ret = 0;
    } else if (((u8 *)pkt)[0xE] != 0x11) {
        ret = 0;
    } else if (type == 0x8863) {
        ret = handle_pppoe_discovery_frame(pkt, id);
    } else {
        ret = 0;
        NetMemcpy(&len, (u8 *)pkt + 0x12, 2);
        src = (u8 *)pkt + 0x14;
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

s16 TLobby__sub_80427F48(s16 slot, u8 *frame, u16 len) {
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
    dst = e->m_20;
    type = 0x8864;
    src = e->m_10;
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

s32 TLobby__sub_80428094(s16 slot) {
    PppoeSlot *e;
    if (slot < 0 || slot >= 1) {
        return -1;
    }
    e = &lobby_pppoe_slot_table.slots[slot];
    switch (e->state) {
    case 0:
        if (e->state != -1) {
            TLobby__sub_80426574(0);
        }
        e->state = -1;
        break;
    case 1:
        if (e->state != -1) {
            TLobby__sub_80426574(0);
        }
        e->state = -1;
        break;
    case 2:
        if (e->state != -1) {
            TLobby__sub_80426574(0);
        }
        e->state = -1;
        break;
    case 3:
        e->state = 5;
        break;
    case 4:
        e->state = 5;
        if (TLobby__sub_80426D80(e) >= 0) {
            u16 frame_len = e->frame_len;
            post_send_message((e->frame), frame_len);
        }
        break;
    case 5:
        if (e->state != -1) {
            TLobby__sub_80426574(0);
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

s16 TLobby__sub_804281DC(void *self) {
    PppoeSlot *tbl;
    PppoeSlot *p;
    PppoeSlot *e;
    s32 now;
    s32 stamp;
    s16 i;
    s16 slot;
    s16 set;
    s16 TLobby__sub_80426660(u8 *); /* declared s16 here; the definition returns s32 */

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
    if (TLobby__sub_80426660((u8 *)&tbl[1]) < 0) {
        return -1;
    }
    *(Unk804271E8Blk *)((u8 *)e + 0x3A) = *(Unk804271E8Blk *)self;
    e->m_4 = set;
    stamp = (s32)e;
    get_time_ms(&now);
    NetMemcpy((u8 *)e + 0x32, &stamp, 4);
    NetMemcpy((u8 *)e + 0x36, &now, 4);
    NetMemcpy((u8 *)e + 0x10, (u8 *)&tbl[1], 6);
    NetMemcpy((u8 *)e + 0x16, (u8 *)&tbl[1] + 6, 6);
    *(u32 *)((u8 *)e + 0x24) = 0;
    *(u32 *)((u8 *)e + 0x2C) = 0;
    e->m_6 = 0;
    e->timeout = 0;
    e->state = 0;
    get_time_ms(&e->last);
    e->timeout = 200;
    e->m_6 = 50;
    return slot;
}

s32 TLobby__sub_80428358(void) {
    return 0;
}

s32 TLobby__sub_80428360(void) {
    lobby_pppoe_slot_table.slots[0].state = -1;
    return 0;
}

