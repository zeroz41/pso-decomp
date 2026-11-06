#include "pso/network/NetworkTransport.h"
#include "pso/unk/TLobby_80426CAC.h"
#include "pso/network/ModemRuntime.h"
#include "pso/network/NetworkMessageTransport.h"
#include "pso/network/NetworkRuntime.h"

#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TUdpSocket.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80428374_lbl_805D0A40 {
    s32 value;
    u8 remaining[0x5C];
};

struct RecoveredGlobal_8042839C_lbl_805D0A40 {
    s32 value;
    u8 remaining[0x5C];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct RecoveredGlobal_8042E768_lbl_805D1D20 {
    s32 value;
    u8 remaining[0x18];
};

struct RecoveredGlobal_80427D0C_lbl_805CFC20 {
    s32 value;
    u8 remaining[0xE1C];
};

struct RecoveredGlobal_80428360_lbl_805CFC20 {
    s16 value;
    u8 remaining[0xE1E];
};

struct RecoveredGlobal_8042DD70_lbl_805D1D20 {
    s32 value;
    u8 remaining[0x18];
};

typedef struct Names_8042E57C {
    char *name[6];
} Names_8042E57C;

typedef struct Names_8042E628 {
    char *name[4];
} Names_8042E628;

typedef struct Names_8042E6C4 {
    char *name[5];
} Names_8042E6C4;

typedef struct Names_8042E7B8 {
    char *name[3];
} Names_8042E7B8;

typedef struct Ent_80426894 {
    s16 count;
    u8 id[6];
} Ent_80426894;

typedef struct Tbl_80426894 {
    u8 pad[6];
    Ent_80426894 ent[6];
} Tbl_80426894;

typedef struct Ent_80425870 {
    s32 used;
    u32 f4;
    u32 base;
} Ent_80425870;

typedef struct Ent_80427C6C {
    u16 pad0;
    u16 id;
    u8 rest[0xE10];
} Ent_80427C6C;

typedef struct PppoeNames {
    u8 name[0x100];
    u8 service[0x100];
} PppoeNames;

typedef struct Ent_80427D40 {
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
    u8 rest[0xE14 - 0x826];
} Ent_80427D40;

extern "C" {
extern u8 lbl_805CF240[0xA0];
extern u8 TLobby__pppoe_message_queue[0xA0];
extern u8 lbl_805CF380[0x48];
RecoveredGlobal_80427D0C_lbl_805CFC20 lobby_pppoe_slot_table;
extern u8 lbl_805CF380[];
extern u8 TLobby__pppoe_message_queue[];
typedef struct Ent_804267F0 {
    s16 count;
    u8 id[6];
} Ent_804267F0;

typedef struct Tbl_804267F0 {
    u8 pad[6];
    Ent_804267F0 ent[6];
} Tbl_804267F0;

extern u8 lbl_805CF240[];

Ent_80427C6C *TLobby__sub_80427C6C(s32 arg0, u16 arg1);
s32 TLobby__sub_8042787C(Ent_80427D40 *e, u8 *p, u16 len);
s32 TLobby__sub_80427F48(s16 slot, u8 *frame, u16 len);
s16 TLobby__sub_80426D80(Ent_80427D40 *e);
s32 TLobby__sub_80426574(s32);
s16 TLobby__sub_80426EB8(Ent_80427D40 *e);
s16 TLobby__sub_804270C0(Ent_80427D40 *e);
s16 TLobby__sub_80426660(u8 *arg0);
Ent_80427D40 *TLobby__sub_80427B6C(u8 *p, u16 len);
void TLobby__sub_80427378(Ent_80427D40 *e);
s16 TLobby__sub_804275B0(s32, u16);

#pragma push
#pragma opt_propagation off
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma pop

#define arg0 ((s32)argp)
#undef arg0

#pragma push
#pragma dont_inline on
#pragma pop

s16 TLobby::build_ethernet_frame_header(void *src, void *mac, u16 type, u8 flag, u16 a, u16 len) {
  u8 *p;
  u8 c;
  u16 t;
  u16 x;
  u8 *new_var;
  u16 l;
  s16 r;
  new_var = ((u8 *)this);
  NetMemcpy(new_var, src, 6);
  NetMemcpy(new_var + 6, mac, 6);
  t = type;
  NetMemcpy(((u8 *)this) + 0xC, &t, 2);
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

inline s16 put_service_name(u8 **p, Ent_80427D40 *e) {
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

inline s16 put_host_uniq(u8 **p, Ent_80427D40 *e) {
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

inline s16 put_ac_cookie(u8 **p, Ent_80427D40 *e) {
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

inline s16 put_relay_session_id(u8 **p, Ent_80427D40 *e) {
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
s16 TLobby__sub_80426D80(Ent_80427D40 *e) {
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
        n = TLobby__sub_804270C0(e);
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
    n = ((TLobby *)e->frame)->build_ethernet_frame_header(src, e->m_10, type, flag, e->id, n);
    e->frame_len = n;
out:
    return n;
}
#pragma pop
s16 TLobby__sub_80426EB8(Ent_80427D40 *e) {
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

s16 TLobby__sub_804270C0(Ent_80427D40 *e) {
    u8 *p;
    s16 n;
    s16 total;
    p = e->frame + 0x14;
    n = put_service_name(&p, e);
    if (n < 0) {
        return -1;
    }
    total = n;
    n = TLobby::write_name_field((s32 *)&p, (u8 *)e);
    if (n < 0) {
        return -1;
    }
    total += n;
    total += put_host_uniq(&p, e);
    total += put_end_of_list(&p);
    return total;
}

s16 TLobby__sub_80427240(u8 **p, Ent_80427D40 *e) {
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
s16 TLobby::write_name_field(s32 *arg0, u8 *arg1) {
    struct Fields_arg1 { u8 pad_0[58]; char name[1]; };
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

inline s16 build_padt(Ent_80427D40 *e) {
    u8 *payload;
    u8 *p;
    s16 n;
    payload = e->frame + 0x14;
    p = payload;
    n = TLobby__sub_80427240(&p, e);
    if (n < 0) {
        return -1;
    }
    return n;
}

inline void restart_timer(Ent_80427D40 *e, s16 retries, s32 timeout) {
    TLobby::get_time_ms(&e->last);
    e->timeout = timeout;
    e->m_6 = retries;
}

void TLobby__sub_80427378(Ent_80427D40 *e) {
    u16 len;
    u16 proto;
    u8 *p;
    s16 n;
    switch (e->state) {
    case 0:
        if (e->m_6 > 0) {
            if (TLobby__sub_80426440() >= 0) {
                if (e->m_4 != 0) {
                    p = e->frame + 0x14;
                    proto = 0xC021;
                    NetMemcpy(p, &proto, 2);
                    p[2] = 5;
                    p[3] = 1;
                    len = 4;
                    NetMemcpy(p + 4, &len, 2);
                    e->frame_len = ((TLobby *)e->frame)->build_ethernet_frame_header(e->m_20, e->m_10, 0x8864, 0, e->id, 6);
                    ((TLobby *)e->frame)->post_send_message(e->frame_len);
                    n = build_padt(e);
                    if (n >= 0) {
                        e->frame_len = ((TLobby *)e->frame)->build_ethernet_frame_header(e->m_20, e->m_10, 0x8863, 0xA7, e->id, n);
                        ((TLobby *)e->frame)->post_send_message(e->frame_len);
                    }
                }
                e->id = 0;
                if (TLobby__sub_80426D80(e) >= 0) {
                    u16 frame_len = e->frame_len;
                    ((TLobby *)e->frame)->post_send_message(frame_len);
                    e->state = 1;
                    restart_timer(e, 2, 3000);
                }
            } else {
                restart_timer(e, e->m_6 - 1, e->timeout);
            }
        } else {
            e->timeout = 0;
            e->state = -1;
        }
        break;
    case 1:
    case 3:
        if (e->m_6 > 0) {
            if (TLobby__sub_80426D80(e) >= 0) {
                u16 frame_len = e->frame_len;
                ((TLobby *)e->frame)->post_send_message(frame_len);
            }
            restart_timer(e, e->m_6 - 1, e->timeout * 2);
        } else {
            e->timeout = 0;
            e->state = 5;
        }
        break;
    case 2:
    case 4:
    case 5:
        break;
    }
}


typedef char RecoveredGlobal_80427D0C_lbl_805CFC20_size[sizeof(RecoveredGlobal_80427D0C_lbl_805CFC20) == 0xE20 ? 1 : -1];

s32 TLobby__sub_8042787C(Ent_80427D40 *e, u8 *p, u16 len) {
    s32 result = 1;
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

s32 TLobby::parse_tlv_records(s32 arg0, u8 *arg1, u16 arg2) {
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

s16 TLobby__sub_80427988(Ent_80427D40 *e, u8 *p, u16 len) {
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

Ent_80427C6C *TLobby__sub_80427C6C(s32 arg0, u16 arg1) {
    u16 id;
    Ent_80427C6C *ret;
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
        ret = &((Ent_80427C6C *)&lobby_pppoe_slot_table)[i];
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

Ent_80427D40 *TLobby__sub_80427B6C(u8 *p, u16 len) {
    Ent_80427D40 *e;
    Ent_80427D40 *ret = NULL;
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
            e = (Ent_80427D40 *)&lobby_pppoe_slot_table;
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

s16 TLobby::get_slot_id(s16 arg0) {
    if ((arg0 < 0) || (arg0 >= 1)) {
        return -1;
    }
    return *(s16 *)((s8 *)((u8 *)&lobby_pppoe_slot_table.value + (arg0 * 0xE14)) + 0);
}

#define TBL_80427D40 ((Ent_80427D40 *)&lobby_pppoe_slot_table)
#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline void check_80427D40(void) {
    s32 now;
    Ent_80427D40 *p;
    s16 i;
    TLobby::get_time_ms(&now);
    for (p = TBL_80427D40, i = 0; i < 1; p++, i++) {
        if (p->state != -1 && p->timeout != 0 && now - p->last > p->timeout) {
            TLobby__sub_80427378(p);
        }
    }
}
s16 TLobby::pppoe_recv_packet(u16 bufLen, u16 *outLen) {
    u16 type;
    s32 pkt;
    u16 id;
    s32 padA;
    u16 len;
    s32 padB;
    Ent_80427D40 *e;
    s16 ret;
    u8 *src;
    check_80427D40();
    if (TLobby::recv_pppoe_message(&pkt, &id) == 0) {
        if (outLen != NULL) {
            *outLen = 0;
        }
        return 0;
    }
    NetMemcpy(&type, (u8 *)pkt + 0xC, 2);
    if (type != 0x8863 && type != 0x8864) {
        ret = 0;
    } else if (NetMemcmp((void *)pkt, &TBL_80427D40[1], 6) != 0) {
        ret = 0;
    } else if (((u8 *)pkt)[0xE] != 0x11) {
        ret = 0;
    } else if (type == 0x8863) {
        ret = TLobby__sub_804275B0(pkt, id);
    } else {
        ret = 0;
        NetMemcpy(&len, (u8 *)pkt + 0x12, 2);
        src = (u8 *)pkt + 0x14;
        if (this != NULL && len <= bufLen) {
            e = ((Ent_80427D40 *)TLobby__sub_80427C6C(pkt, id));
            if (e != NULL && e->state == 4) {
                ret = e - TBL_80427D40;
                NetMemcpy(this, src, len);
                if (outLen != NULL) {
                    *outLen = len;
                }
                TLobby::clear_message_entry_wrapper(pkt);
                return ret;
            }
        }
    }
    TLobby::clear_message_entry_wrapper(pkt);
    if (outLen != NULL) {
        *outLen = 0;
    }
    return ret;
}
#pragma pop

s32 TLobby__sub_80427F48(s16 slot, u8 *frame, u16 len) {
    Ent_80427D40 *e;
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
    e = &TBL_80427D40[slot];
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
    return ((TLobby *)frame)->post_send_message(frame_len);
}

s32 TLobby__sub_80428094(s16 slot) {
    Ent_80427D40 *e;
    if (slot < 0 || slot >= 1) {
        return -1;
    }
    e = &TBL_80427D40[slot];
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
            ((TLobby *)e->frame)->post_send_message(frame_len);
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

s16 TLobby__sub_804281DC(u8 *arg0) {
    Ent_80427D40 *tbl;
    Ent_80427D40 *p;
    Ent_80427D40 *e;
    s32 now;
    s32 stamp;
    s16 i;
    s16 slot;
    s16 set;
    tbl = (0, (Ent_80427D40 *)&lobby_pppoe_slot_table);
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
    e->names = *(PppoeNames *)arg0;
    e->m_4 = set;
    stamp = (s32)e;
    TLobby::get_time_ms(&now);
    NetMemcpy(e->m_32, &stamp, 4);
    NetMemcpy(e->m_32 + 4, &now, 4);
    NetMemcpy(e->m_10, (u8 *)&tbl[1], 6);
    NetMemcpy(e->m_16, (u8 *)&tbl[1] + 6, 6);
    e->m_24 = NULL;
    e->m_2C = NULL;
    e->m_6 = 0;
    e->timeout = 0;
    e->state = 0;
    TLobby::get_time_ms(&e->last);
    e->timeout = 200;
    e->m_6 = 50;
    return slot;
}

s32 TLobby__sub_80428358(void) {
    return 0;
}

typedef char RecoveredGlobal_80428374_lbl_805D0A40_size[sizeof(RecoveredGlobal_80428374_lbl_805D0A40) == 0x60 ? 1 : -1];

typedef char RecoveredGlobal_80428360_lbl_805CFC20_size[sizeof(RecoveredGlobal_80428360_lbl_805CFC20) == 0xE20 ? 1 : -1];
s32 TLobby__sub_80428360(void) {
    (*(RecoveredGlobal_80428360_lbl_805CFC20 *)&lobby_pppoe_slot_table).value = -1;
    return 0;
}

typedef char RecoveredGlobal_8042839C_lbl_805D0A40_size[sizeof(RecoveredGlobal_8042839C_lbl_805D0A40) == 0x60 ? 1 : -1];

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_8042DD70_lbl_805D1D20_size[sizeof(RecoveredGlobal_8042DD70_lbl_805D1D20) == 0x1C ? 1 : -1];
#pragma pop

typedef char RecoveredGlobal_8042E768_lbl_805D1D20_size[sizeof(RecoveredGlobal_8042E768_lbl_805D1D20) == 0x1C ? 1 : -1];

}
