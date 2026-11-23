#include "pso/network/NetworkTimer.h"
#include "dolphin/os/OSMessage.h"
#include <stddef.h>
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


s32 init_bba_exi_adapter(void *);
/* The message queues (OSMessageQueue + messages) and, below, the channel table: only this file uses them. */
typedef struct TransportMessageQueue32 {
    OSMessageQueue queue;
    OSMessage messages[32];
} TransportMessageQueue32;

typedef struct TransportMessageQueue10 {
    OSMessageQueue queue;
    OSMessage messages[10];
} TransportMessageQueue10;

LAYOUT_ASSERT(TransportMessageQueue32Size, sizeof(TransportMessageQueue32) == 0xA0);
LAYOUT_ASSERT(TransportMessageQueue10Size, sizeof(TransportMessageQueue10) == 0x48);
LAYOUT_ASSERT(TransportMessageQueue32Messages, offsetof(TransportMessageQueue32, messages) == 0x20);
LAYOUT_ASSERT(TransportMessageQueue10Messages, offsetof(TransportMessageQueue10, messages) == 0x20);

static TransportMessageQueue32 lbl_805CF240;
static TransportMessageQueue32 pppoe_message_queue;
static TransportMessageQueue10 lbl_805CF380;
/* The thread, link-status and Ethernet negotiation-mode state. */
s32 network_message_pending_count;
saddr ether_nego_mode;
uaddr lbl_805D7BC4;
u32 lobby_exi_stable_target;
u32 lobby_exi_stable_count;
s32 lobby_exi_prev_status;
NetThreadHandle lobby_message_thread_handle;
s32 lbl_805D7BB0;
s16 network_link_status_cache = -1;
void TLobby__sub_80426190(EthernetReceiveFilter *);
s16 TLobby__sub_80426110(EthernetReceiveFilter *o, u16 kind, u16 ether_type);
extern const u8 lbl_805E1190[8] = { 255, 255, 255, 255, 255, 255, 0, 0 };
saddr TLobby__sub_804089A8(s16, s16, void *, void *); /* declared here with other parameter types; the definition is s32 (s16, s16, s16, void *) */
saddr TLobby__sub_80426AAC(u16 key, saddr len);

static struct {
    EthernetReceiveFilter filter;
    u8 unknown_56[0x802];
} lobby_net_channel_table;

void reset_message_thread(void) {
    if ((u32)lobby_message_thread_handle != 0) {
        cancel_thread_if_running((void *)lobby_message_thread_handle);
        deactivate_entry_by_key((uaddr)((void *)lobby_message_thread_handle));
        lobby_message_thread_handle = 0;
    }
    NetUnregisterTimer(update_exi_status);
    network_link_status_cache = -1;
    lobby_exi_prev_status = 0;
    lobby_exi_stable_count = 0;
    lbl_805D7BB0 = 0;
}

void update_exi_status(void) {
    s32 status;
    if (poll_exi_status(&status) == 1) {
        if (status != (s32) lobby_exi_prev_status) {
            lobby_exi_prev_status = status;
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

/* Looks up packet's pool entry and posts it on queue with its length; returns 0 on success, -1 otherwise. */
s32 post_message(OSMessageQueue *queue, u8 *packet, s32 length, s32 by_address) {
    s32 sent;
    NetworkPacketBufferDescriptor *p;
    if (by_address != 0) {
        p = find_entry_by_address(packet);
    } else {
        p = TLobby__sub_804256B8(packet);
    }
    if (p != NULL) {
        p->queued_length = length;
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
    NetworkPacketBufferDescriptor *msg;
    OSMessage sp8;
    u8 *packet;
    s32 n;
    for (;;) {
        OSReceiveMessage(&lbl_805CF240.queue, (OSMessage *)&msg, OS_MESSAGE_BLOCK);
        n = msg->queued_length;
        packet = msg->data;
        if (n > 0) {
            start_exi_send(packet, n, TLobby__sub_80425D88);
            OSReceiveMessage(&lbl_805CF380.queue, &sp8, OS_MESSAGE_BLOCK);
            network_message_pending_count -= 1;
        }
        clear_message_entry(packet);
    }
}

void TLobby__sub_80425D88(u8 v) {
    network_message_pending_count++;
    OSSendMessage(&lbl_805CF380.queue, (OSMessage)v, OS_MESSAGE_NOBLOCK);
}

#define pkt ((EthernetFrameHeader *)a)
void dispatch_received_ethernet_frame(EthernetReceiveFilter *filter, void *a, void *b) {
    s32 i;
    EthernetMulticastEntry *e;
    u8 *mq = (u8 *)&lbl_805CF240;
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
            release_entry_by_id(a);
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
                post_message((OSMessageQueue *)(mq + sizeof(TransportMessageQueue32)), a, (saddr)((u8 *)b - 4), 1);
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
                    post_message((OSMessageQueue *)(mq + sizeof(TransportMessageQueue32)), a, (saddr)((u8 *)b - 4), 1);
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
            release_entry_by_id(a);
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
            release_entry_by_id(a);
            break;
        }
        return;
    }
    switch (type) {
    case 1:
        TLobby__sub_804089A8(0, 1, (u8 *)b - 4, a);
        break;
    case 2:
        post_message((OSMessageQueue *)(mq + sizeof(TransportMessageQueue32)), a, (saddr)((u8 *)b - 4), 1);
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
        TLobby__sub_8042B58C((uaddr)TLobby__sub_80426AAC, (saddr)forward_to_channel);
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
    if (init_bba_exi_adapter((void *)ether_nego_mode) != 1) {
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
    OSInitMessageQueue(&lbl_805CF240.queue, lbl_805CF240.messages, 32);
    OSInitMessageQueue(&pppoe_message_queue.queue, pppoe_message_queue.messages, 32);
    OSInitMessageQueue(&lbl_805CF380.queue, lbl_805CF380.messages, 10);
    if (TLobby__sub_803F9B94(message_thread_loop, &lobby_message_thread_handle) < 0) {
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

s16 TLobby__sub_80426440(void) {
    return 0;
}

s16 post_send_message(void *data, u16 len) {
    u8 *buf;
    NetworkPacketBufferDescriptor *msg;
    u8 pad[8];
    saddr src = (saddr)data;
    buf = TLobby__sub_8042558C(len);
    if (buf == NULL) {
        return -1;
    }
    NetMemcpy((void *)buf, (void *)src, (saddr) (void *)len);
    msg = TLobby__sub_804256B8(buf);
    if (msg != NULL) {
        msg->queued_length = (s32)len;
        OSSendMessage(&lbl_805CF240.queue, msg, OS_MESSAGE_NOBLOCK);
    }
    return 0;
}

void clear_message_entry_wrapper(u8 *packet) {
    clear_message_entry(packet);
}

u16 recv_pppoe_message(u8 **out_data, u16 *out_len) {
    NetworkPacketBufferDescriptor *msg;
    if (OSReceiveMessage(&pppoe_message_queue.queue, (OSMessage *)&msg, OS_MESSAGE_NOBLOCK) == 1) {
        *out_data = msg->data;
        *out_len = msg->queued_length;
        return msg->queued_length;
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
    NetworkPacketBufferDescriptor *msg;

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
        if (OSReceiveMessage(&pppoe_message_queue.queue, (OSMessage *)&msg, OS_MESSAGE_NOBLOCK) == 0) {
            break;
        }
        clear_message_entry(msg->data);
    }
    return 0;
}

s16 TLobby__sub_80426660(u8 *out) {
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

s32 queue_timeout_message(s16 dev, u8 *packet, s16 timeout) {
    s32 clamped;
    NetworkPacketBufferDescriptor *msg;
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
    msg = TLobby__sub_804256B8(packet);
    if (msg != NULL) {
        msg->queued_length = clamped;
        OSSendMessage(&lbl_805CF240.queue, msg, OS_MESSAGE_NOBLOCK);
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

saddr TLobby__sub_80426AAC(u16 key, saddr len) {
    EthernetReceiveFilter *o = &lobby_net_channel_table.filter;
    s32 i;
    saddr ret = 0;
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
                ret = (saddr)TLobby__sub_80425640(len);
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
    s32 status;
    if ((s16) network_link_status_cache != -1) {
        return network_link_status_cache;
    }
    if (poll_exi_status(&status) == 1) {
        if (status == 1) {
            return 1;
        }
        return 0;
    }
    return -1;
}

s32 AT_SetEtherNegoMode(s32 mode) {
    switch (mode) {
    case 1:
        ether_nego_mode = 1;
        break;
    case 2:
        ether_nego_mode = 2;
        break;
    case 3:
        ether_nego_mode = 3;
        break;
    case 4:
        ether_nego_mode = 4;
        break;
    case 0:
        ether_nego_mode = 0;
        break;
    default:
        return -1;
    }
    return 0;
}
