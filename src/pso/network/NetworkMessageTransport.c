/* The network stack's message transport (a C library, built with GC/1.2.5n): the message thread and its queues
 * between the Ethernet/PPPoE receive path and the stack, the receive filter (local address, multicast addresses,
 * protocol registrations) and the EXI link status. */
#include "pso/network/NetworkRuntime.h"
#include "pso/network/NetworkTransport.h"
#include "pso/network/NetworkMessageTransport.h"
#include "pso/network/NetworkPacketPool.h"

#include "types.h"
#include "pso/network/EthernetReceiveFilter.h"
#include "pso/network/TLobby_80429598.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

typedef struct Msg_804264F4 { u32 f0; u32 f4; s32 f8; } Msg_804264F4;

s32 OSInitMessageQueue(void *, void *, int);
s16 TLobby__sub_803F9B94(void *, void *);
void NetRegisterTimer(int, int, void (*)(void));
s32 init_bba_exi_adapter(void *);
/* The message queues (OSMessageQueue + messages) and, below, the channel table: only this file uses them. */
static u8 lbl_805CF240[0xA0];
static u8 pppoe_message_queue[0xA0];
static u8 lbl_805CF380[0x48];
extern s32 lobby_message_thread_handle;
extern u32 lbl_805D7BC4;
extern s16 network_link_status_cache;
extern s32 lobby_exi_prev_status;
extern u32 lobby_exi_stable_count;
extern u32 lobby_exi_stable_target;
void TAdSinglePlyChrSelectGC__sub_8042DDE4(int, int);
s32 OSSendMessage(void *mq, void *msg, s32 flags);
extern s32 network_message_pending_count;
void TLobby__sub_80426190(EthernetReceiveFilter *);
s16 TLobby__sub_80426110(EthernetReceiveFilter *o, u16 arg1, u16 arg2);
s32 OSReceiveMessage(void *, void *, int);
extern s32 lbl_805D7BB0;
extern s32 lobby_connect_mode;
s32 NetUnregisterTimer(void *fn);
u8 *TLobby__sub_804256B8(s32);
s32 TLobby__sub_8042558C(void *);
extern u8 lbl_805E1190[6];
s32 TLobby__sub_804089A8(s16, s16, void *, void *); /* declared here with other parameter types; the definition is s32 (s16, s16, s16, void *) */
s32 TLobby__sub_80425640(s32 len);
s32 TLobby__sub_80426AAC(u16 key, s32 len);

static struct {
    EthernetReceiveFilter filter;
    u8 unknown_56[0x802];
} lobby_net_channel_table;

void reset_message_thread(void) {
    if ((u32)lobby_message_thread_handle != 0) {
        cancel_thread_if_running((void *)lobby_message_thread_handle);
        deactivate_entry_by_key((u32)((void *)lobby_message_thread_handle));
        lobby_message_thread_handle = 0;
    }
    NetUnregisterTimer((void *)update_exi_status);
    network_link_status_cache = -1;
    lobby_exi_prev_status = 0;
    lobby_exi_stable_count = 0;
    lbl_805D7BB0 = 0;
}

void update_exi_status(void) {
    s32 sp8;
    if (poll_exi_status(&sp8) == 1) {
        if (sp8 != (s32) lobby_exi_prev_status) {
            lobby_exi_prev_status = sp8;
            lobby_exi_stable_count = 1U;
        } else if ((u32) lobby_exi_stable_count != 0U) {
            lobby_exi_stable_count += 1;
        }
        if ((u32) lobby_exi_stable_count >= (u32) lobby_exi_stable_target) {
            if ((s32) lobby_exi_prev_status == 1) {
                network_link_status_cache = 1;
            } else {
                network_link_status_cache = 0;
            }
            lobby_exi_stable_count = 0U;
            lobby_exi_stable_target = 0xAU;
        }
    }
}

/* Looks up a message entry and posts it on queue with value stored at +4; returns 0 on success, -1 otherwise. */
s32 post_message(void *queue, s32 address, s32 value, s32 by_address) {
    s32 sent;
    u8 *p;
    if (by_address != 0) {
        p = find_entry_by_address(address);
    } else {
        p = TLobby__sub_804256B8(address);
    }
    if (p != NULL) {
        *(s32 *)(p + 4) = value;
        sent = OSSendMessage(queue, p, 0);
    } else {
        sent = 0;
    }
    if (sent == 1) {
        return 0;
    }
    return -1;
}

void message_thread_loop(void) {
    u8 *spC;
    u8 *sp8;
    s32 id;
    s32 n;
    for (;;) {
        OSReceiveMessage(lbl_805CF240, &spC, 1);
        n = *(s32 *)(spC + 4);
        id = *(s32 *)(spC + 8);
        if (n > 0) {
            start_exi_send(id, n, TLobby__sub_80425D88);
            OSReceiveMessage(lbl_805CF380, &sp8, 1);
            network_message_pending_count -= 1;
        }
        clear_message_entry(id);
    }
}

void TLobby__sub_80425D88(u8 v) {
    network_message_pending_count++;
    OSSendMessage(lbl_805CF380, (void *)v, 0);
}

#define pkt ((EthernetFrameHeader *)a)
void dispatch_received_ethernet_frame(EthernetReceiveFilter *filter, void *a, void *b) {
    s32 i;
    EthernetMulticastEntry *e;
    u8 *mq = lbl_805CF240;
    EthernetProtocolRegistration *r = filter->protocols;
    u16 *key = &pkt->ether_type;
    u8 *src = pkt->source;
    u16 type = 0;
    i = 0;
    while (i < 5) {
        if (r->delivery_mode != 0 && r->ether_type == *key) {
            type = r->delivery_mode;
            break;
        }
        i++;
        r++;
    }
    if (i == 5) {
        return;
    }
    if (NetMemcmp(src, filter->local_address, 6) == 0) {
        switch (type) {
        case 1:
            TLobby__sub_804089A8(0, 1, 0, a);
            break;
        case 2:
            release_entry_by_id((u32)a);
            break;
        }
        return;
    }
    if (pkt->destination[0] & 1) {
        if (NetMemcmp(a, lbl_805E1190, 6) == 0) {
            switch (type) {
            case 1:
                TLobby__sub_804089A8(0, 1, (u8 *)b - 4, a);
                break;
            case 2:
                post_message(mq + 0xA0, (s32)a, (s32)((u8 *)b - 4), 1);
                break;
            }
            return;
        }
        i = 0;
        e = filter->multicast;
        for (; i < 6; i++, e++) {
            if (e->references > 0 && NetMemcmp(a, e->address, 6) == 0) {
                switch (type) {
                case 1:
                    TLobby__sub_804089A8(0, 1, (u8 *)b - 4, a);
                    break;
                case 2:
                    post_message(mq + 0xA0, (s32)a, (s32)((u8 *)b - 4), 1);
                    break;
                }
                return;
            }
        }
        switch (type) {
        case 1:
            TLobby__sub_804089A8(0, 1, 0, a);
            break;
        case 2:
            release_entry_by_id((u32)a);
            break;
        }
        return;
    }
    if (NetMemcmp(a, filter->local_address, 6) != 0) {
        switch (type) {
        case 1:
            TLobby__sub_804089A8(0, 1, 0, a);
            break;
        case 2:
            release_entry_by_id((u32)a);
            break;
        }
        return;
    }
    switch (type) {
    case 1:
        TLobby__sub_804089A8(0, 1, (u8 *)b - 4, a);
        break;
    case 2:
        post_message(mq + 0xA0, (s32)a, (s32)((u8 *)b - 4), 1);
        break;
    }
}

#undef pkt

s16 TLobby__sub_80426110(EthernetReceiveFilter *o, u16 kind, u16 ether_type) {
    s32 i;
    EthernetProtocolRegistration *p = o->protocols;
    for (i = 5; i != 0; i--, p++) {
        if (p->delivery_mode != 0) {
            if (p->ether_type != ether_type) {
                continue;
            }
            break;
        } else {
            p->delivery_mode = kind;
            p->ether_type = ether_type;
            o->protocol_count++;
            if (o->protocol_count > 0) {
                TLobby__sub_80426190(o);
            }
            return 0;
        }
    }
    return -1;
}

void TLobby__sub_80426190(EthernetReceiveFilter *o) {
    s32 i;
    s32 n = 0;
    for (i = 0; i < 5; i++) {
        if (o->protocols[i].delivery_mode != 0) {
            o->filter_types[n] = o->protocols[i].ether_type;
            n++;
        }
    }
    for (i = n; i < 5; i++) {
        o->filter_types[n] = 0;
    }
    if (n > 0) {
        TLobby__sub_8042BA48(o->filter_types, n);
        TLobby__sub_8042B58C((u32)TLobby__sub_80426AAC, (s32)forward_to_channel);
    }
}

/* Resets the 0x56-byte network config block (MAC + 6 multicast slots) and starts the message thread. */
s16 TLobby__sub_804262CC(EthernetReceiveFilter *config) {
    EthernetMulticastEntry *entry;
    s16 status;
    s32 i;

    if ((s32) lbl_805D7BB0 == 1) {
        return 0;
    }
    NetMemset(config, 0, sizeof(EthernetReceiveFilter));
    if (init_bba_exi_adapter((void *)lobby_connect_mode) != 1) {
        status = -1;
    } else {
        if ((u32) lbl_805D7BC4 != 0U) {
            copy_mac_address((void *)lbl_805D7BC4);
        }
        copy_6_byte_config(config->local_address);
        i = 0;
        entry = config->multicast;
        do {
            if (entry->references > 0) {
                enable_network_multicast_address(entry->address);
            }
            i += 1;
            entry++;
        } while (i < 6);
        TLobby__sub_80426190(config);
        status = 0;
    }
    if (status < 0) {
        return -1;
    }
    OSInitMessageQueue(lbl_805CF240, lbl_805CF240 + 0x20, 0x20);
    OSInitMessageQueue(pppoe_message_queue, pppoe_message_queue + 0x20, 0x20);
    OSInitMessageQueue(lbl_805CF380, lbl_805CF380 + 0x20, 0xA);
    if (TLobby__sub_803F9B94((void *) message_thread_loop, &lobby_message_thread_handle) < 0) {
        return -1;
    }
    NetResumeThread((u32)lobby_message_thread_handle);
    lbl_805D7BB0 = 1;
    network_link_status_cache = -1;
    lobby_exi_prev_status = 0;
    lobby_exi_stable_count = 1;
    lobby_exi_stable_target = 1;
    NetRegisterTimer(0x64, 0, update_exi_status);
    return 0;
}

s32 TLobby__sub_80426440(void) {
    return 0;
}

s16 post_send_message(void *data, u16 len) {
    s32 buf;
    u8 *msg;
    u8 pad[8];
    s32 src = (s32)data;
    buf = TLobby__sub_8042558C((void *)len);
    if (buf == 0) {
        return -1;
    }
    NetMemcpy((void *)buf, (void *)src, (int) (void *)len);
    msg = (u8 *)(TLobby__sub_804256B8(buf));
    if (msg != NULL) {
        *(s32 *)((s8 *)msg + 4) = (s32) len;
        OSSendMessage((void *) (((s32 *)&lbl_805CF240)), msg, 0);
    }
    return 0;
}

void clear_message_entry_wrapper(s32 entry) {
    clear_message_entry(entry);
}

u16 recv_pppoe_message(s32 *out_data, u16 *out_len) {
    Msg_804264F4 *msg;
    if (OSReceiveMessage(pppoe_message_queue, &msg, 0) == 1) {
        *out_data = msg->f8;
        *out_len = msg->f4;
        return msg->f4;
    }
    return 0;
}

static inline s16 remove_rec_80426998(u16 key) {
    s32 i;
    EthernetReceiveFilter *o = &lobby_net_channel_table.filter;
    EthernetProtocolRegistration *p = o->protocols;
    for (i = 5; i != 0; i--, p++) {
        if (p->delivery_mode != 0 && p->ether_type == key) {
            p->delivery_mode = 0;
            p->ether_type = 0;
            o->protocol_count--;
            return 0;
        }
    }
    return -1;
}

s32 TLobby__sub_80426574(void) {
    EthernetReceiveFilter *o = &lobby_net_channel_table.filter;
    EthernetProtocolRegistration *p;
    s32 i;
    Msg_804264F4 *msg;

    remove_rec_80426998(0x8864);
    p = o->protocols;
    for (i = 5; i != 0; i--, p++) {
        if (p->delivery_mode != 0 && p->ether_type == 0x8863) {
            p->delivery_mode = 0;
            p->ether_type = 0;
            o->protocol_count--;
            break;
        }
    }
    for (;;) {
        if (OSReceiveMessage(pppoe_message_queue, &msg, 0) == 0) {
            break;
        }
        clear_message_entry(msg->f8);
    }
    return 0;
}

s32 TLobby__sub_80426660(u8 *out) {
    EthernetReceiveFilter *chan = &lobby_net_channel_table.filter;
    if (TLobby__sub_804262CC(chan) < 0) {
        return -1;
    }
    TLobby__sub_80426110(chan, 2, 0x8863);
    TLobby__sub_80426110(chan, 2, 0x8864);
    NetMemcpy(out, chan->local_address, 6);
    NetMemcpy(out + 6, lbl_805E1190, 6);
    return 0;
}

s32 queue_timeout_message(s16 dev, s32 address, s16 timeout) {
    s32 clamped;
    u8 *msg;
    u8 pad[8];
    if ((timeout <= 0) || (timeout > 0x5EA)) {
        return -0x113;
    }
    if (timeout < 0x3C) {
        clamped = 0x3C;
    } else {
        clamped = timeout;
    }
    if (dev != 0) {
        return -0x113;
    }
    msg = TLobby__sub_804256B8(address);
    if (msg != NULL) {
        *(s32 *)(msg + 4) = clamped;
        OSSendMessage(lbl_805CF240, msg, 0);
    }
    return 0;
}

/* Copies the 6-byte local address; the device argument must be 0 (else -0x113). */
s32 get_local_address(s16 dev, void *out) {
    u8 *src;
    if (dev != 0) {
        return -0x113;
    }
    src = lobby_net_channel_table.filter.local_address;
    if (lbl_805D7BB0 == 0) {
        return -0x113;
    }
    NetMemcpy(out, src, 6);
    return 6;
}

#pragma push
#pragma dont_inline on
s32 consume_item_count_by_id(s16 dev, void *id) {
    s32 i;
    EthernetMulticastEntry *e;

    if (dev != 0) {
        return -0x113;
    }
    e = lobby_net_channel_table.filter.multicast;
    for (i = 0; i < 6; i++, e++) {
        if (e->references > 0 && NetMemcmp(e->address, id, 6) == 0) {
            e->references--;
            return 0;
        }
    }
    return -0x113;
}
#pragma pop

/* Adds (or refcounts) a 6-byte multicast address in the 6-entry table and enables it. */
s32 add_multicast_address(s16 dev, void *addr) {
    s32 i;
    EthernetMulticastEntry *found;
    EthernetMulticastEntry *e;
    u8 pad[4];
    if (dev != 0) {
        return -0x113;
    }
    e = lobby_net_channel_table.filter.multicast;
    i = 0;
    found = NULL;
    for (; i < 6; i++, e++) {
        if (e->references < 0) {
            return -0x113;
        }
        if (e->references == 0) {
            if (found == NULL) {
                found = e;
            }
        } else if (NetMemcmp(e->address, addr, 6) == 0) {
            e->references++;
            return 0;
        }
    }
    if (found == NULL) {
        return -0x113;
    }
    found->references++;
    NetMemcpy(found->address, addr, 6);
    enable_network_multicast_address(addr);
    return 0;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
s32 remove_rec_by_handle(s16 dev, u16 handle) {
    if (dev != 0) {
        return -0x113;
    }
    if (remove_rec_80426998(handle) < 0) {
        return -0x113;
    }
    return 0;
}
#pragma pop

s32 open_channel_checked(s16 dev, u16 ether_type) {
    EthernetReceiveFilter *g;
    if (dev != 0) {
        return -0x113;
    }
    g = &lobby_net_channel_table.filter;
    if (TLobby__sub_80426110(g, 1, ether_type) < 0) {
        return -0x113;
    }
    return 0;
}

void forward_to_channel(void *frame, void *b) {
    if (frame != NULL) {
        EthernetReceiveFilter *q = &lobby_net_channel_table.filter;
        dispatch_received_ethernet_frame(q, frame, b);
    }
}

s32 TLobby__sub_80426AAC(u16 key, s32 len) {
    EthernetReceiveFilter *o = &lobby_net_channel_table.filter;
    s32 i;
    s32 ret = 0;
    EthernetFrameHeader hdr;
    u8 pad[4];

    if (len <= 0 || len > 0x5EE) {
        return 0;
    }
    for (i = 0; i < o->protocol_count; i++) {
        if (o->protocols[i].delivery_mode != 0 && o->protocols[i].ether_type == key) {
            switch (o->protocols[i].delivery_mode) {
            case 1:
                hdr.ether_type = key;
                ret = TLobby__sub_804089A8(0, 0, (void *)(len - 4), &hdr);
                break;
            case 2:
                ret = TLobby__sub_80425640(len);
                break;
            }
            break;
        }
    }
    return ret;
}

s32 TLobby__sub_80426B88(s16 dev) {
    EthernetReceiveFilter *g;
    if (dev != 0) {
        return -0x113;
    }
    g = &lobby_net_channel_table.filter;
    if (TLobby__sub_804262CC(g) < 0) {
        return -0x113;
    }
    return 0;
}

/* Cached link status: 1 up, 0 down, -1 unknown. */
s16 query_link_status(void) {
    s32 sp8;
    if ((s16) network_link_status_cache != -1) {
        return network_link_status_cache;
    }
    if (poll_exi_status(&sp8) == 1) {
        if (sp8 == 1) {
            return 1;
        }
        return 0;
    }
    return -1;
}

s32 set_connect_mode(s32 mode) {
    switch (mode) {
    case 1:
        lobby_connect_mode = 1;
        break;
    case 2:
        lobby_connect_mode = 2;
        break;
    case 3:
        lobby_connect_mode = 3;
        break;
    case 4:
        lobby_connect_mode = 4;
        break;
    case 0:
        lobby_connect_mode = 0;
        break;
    default:
        return -1;
    }
    return 0;
}
