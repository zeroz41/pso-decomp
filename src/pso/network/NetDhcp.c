/* The network stack's DHCP client (a C library, built with GC/1.2.5n): the lease timer, the DISCOVER/REQUEST/RELEASE
 * packets and steps, reply handling, the option table with its lease times, and the start/stop/query calls. */
#include "pso/network/NetworkRuntime.h"
#include "pso/network/UdpRuntime.h"
#include "pso/network/SocketEvents.h"
#include "pso/network/NetTcpState.h"
#include "pso/network/NetworkDispatch.h"
#include "pso/network/NetworkPacketPool.h"
#include "pso/network/NetDhcp.h"
#include "pso/network/NetworkTransport.h"
#include "pso/network/text_80421620.h"
#include "types.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
#include <stddef.h>
#include "pso/network/BufferRef.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

typedef struct Req_804250A8 {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Req_804250A8;

typedef struct P_8042315C { s32 type; s32 a; s32 b; s32 c; s32 pad10; s16 n; s16 m; s32 d; s32 pad1C; } P_8042315C;

s16 TLobby__sub_80422F70(s16 iface, void *hdr_src, s32 len, void *buf);
s16 if_config(s16 iface, void *req);
DhcpClientBuffers lbl_805C1E00;
extern u8 dhcp_domain_name[0x100]; /* defined at the end of the file */
extern u8 dhcp_hostname[0x2C]; /* defined at the end of the file */
volatile s32 dhcp_error;
s32 lbl_805D7B9C;
u32 lbl_805D7B98;
s32 lbl_805D7B94;
s32 lbl_805D7B90;
s32 lbl_805D7B8C;
s32 dhcp_retries_left;
s32 dhcp_send_time;
s32 lbl_805D7B80;
u32 dhcp_lease_expiry;
u32 dhcp_lease_start;
s32 dhcp_max_retries;
u32 dhcp_lease_elapsed;
u32 dhcp_rebinding_time;
u32 dhcp_renewal_time;
u32 dhcp_lease_time;
u32 dhcp_last_tick_ms;
u32 dhcp_elapsed_ms;
u32 dhcp_requested_lease;
s32 lbl_805D7B54;
u32 lbl_805D7B50;
u32 lbl_805D7B4C;
s32 *dhcp_broadcast_out;
s32 *dhcp_netmask_out;
s32 *dhcp_client_addr_out;
u32 dhcp_router;
u32 dhcp_dns2;
u32 dhcp_dns1;
s32 dhcp_broadcast;
s32 dhcp_netmask;
u32 dhcp_client_addr;
u8 dhcp_server_id[4];
u8 lbl_805D7B1C[6];
s16 dhcp_socket;
s32 lbl_805D7B14;
volatile s32 dhcp_reply_received;
volatile s32 dhcp_step;
s16 dhcp_iface;
volatile s32 dhcp_state = -2;

s32 dhcp_discover_step(void);
s32 dhcp_request_step(void);
s32 dhcp_release_step(void);
void TLobby__sub_80423298(void) {
    s32 now;
    s32 elapsed;
    u32 secs;
    dhcp_error = 0;
    if (dhcp_state == 1) {
        dhcp_discover_step();
        return;
    }
    if (dhcp_state == 2) {
        dhcp_request_step();
        return;
    }
    if (dhcp_state == 6) {
        dhcp_release_step();
        return;
    }
    if ((dhcp_state != 3 && dhcp_state != 4 && dhcp_state != 5) || dhcp_lease_time == 0xFFFFFFFF) {
        return;
    }
    get_time_ms(&now);
    elapsed = now - dhcp_last_tick_ms;
    dhcp_last_tick_ms = now;
    dhcp_elapsed_ms += elapsed;
    secs = dhcp_elapsed_ms / 1000;
    dhcp_lease_elapsed += secs;
    dhcp_elapsed_ms %= 1000;
    if (dhcp_lease_elapsed >= dhcp_lease_time) {
        if (dhcp_socket > -1) {
            udp_close(dhcp_socket);
            dhcp_socket = -1;
        }
        dhcp_state = -1;
        dhcp_error = 9;
        return;
    }
    if (dhcp_state != 5 && dhcp_lease_elapsed >= dhcp_rebinding_time) {
        dhcp_state = 5;
        dhcp_step = 0;
    }
    if (dhcp_state != 4 && dhcp_state != 5 && dhcp_lease_elapsed >= dhcp_renewal_time) {
        dhcp_state = 4;
        dhcp_step = 0;
    }
    if (dhcp_state == 4) {
        dhcp_request_step();
        return;
    }
    if (dhcp_state == 5) {
        dhcp_request_step();
    }
}

void parse_dhcp_lease_times(u8 *packet);

s32 TLobby__sub_80423440(BootpPacket *pkt) {
    u8 *opts = (u8 *)&pkt->cookie;
    u8 *p;
    s32 net;
    s32 w;
    u32 mask;
    u32 n;
    dhcp_set_option(0xF, 4, &pkt->yiaddr);
    lbl_805D7B80 = 0;
    if (find_dhcp_option(opts, 1, &p) == 4) {
        lbl_805D7B80++;
        dhcp_set_option(1, 4, p);
    } else {
        if (!(dhcp_client_addr & 0x80000000)) {
            mask = 0xFF000000;
        } else if ((dhcp_client_addr & 0xC0000000) == 0x80000000) {
            mask = 0xFFFF0000;
        } else if ((dhcp_client_addr & 0xE0000000) == 0xC0000000) {
            mask = 0xFFFFFF00;
        } else {
            mask = 0;
        }
        dhcp_set_option(1, 0, NULL);
        dhcp_netmask = mask;
    }
    if (find_dhcp_option(opts, 0x1C, &p) == 4) {
        lbl_805D7B80++;
        dhcp_set_option(2, 4, p);
    } else {
        dhcp_set_option(2, 0, NULL);
        net = dhcp_client_addr & dhcp_netmask;
        dhcp_broadcast = net | (dhcp_netmask ^ 0xFFFFFFFF);
    }
    if (dhcp_client_addr_out != NULL) {
        *dhcp_client_addr_out = dhcp_client_addr;
        dhcp_client_addr_out = NULL;
    }
    if (dhcp_netmask_out != NULL) {
        *dhcp_netmask_out = dhcp_netmask;
        dhcp_netmask_out = NULL;
    }
    if (dhcp_broadcast_out != NULL) {
        *dhcp_broadcast_out = dhcp_broadcast;
        dhcp_broadcast_out = NULL;
    }
    parse_dhcp_lease_times((u8 *)opts);
    n = find_dhcp_option(opts, 0xF, &p);
    if (n != 0) {
        dhcp_set_option(3, (s16)n, p);
    } else {
        dhcp_set_option(3, 1, NULL);
    }
    n = find_dhcp_option(opts, 6, &p);
    if (n >= 4 && (n & 3) == 0) {
        dhcp_set_option(4, 4, p);
        if (n > 4) {
            dhcp_set_option(5, 4, p + 4);
        } else {
            dhcp_set_option(5, 4, NULL);
        }
    } else {
        dhcp_set_option(4, 4, NULL);
        dhcp_set_option(5, 4, NULL);
    }
    n = find_dhcp_option(opts, 3, &p);
    if (n >= 4 && (n & 3) == 0) {
        dhcp_set_option(6, 4, p);
    } else {
        dhcp_set_option(6, 4, NULL);
    }
    return 0;
}

/* Builds a DHCP release packet into packet. */
s32 build_dhcp_release(DhcpMessage *packet) {
    s32 m;
    u8 *p;
    u16 len;
    NetMemset(packet, 0, sizeof(*packet));
    packet->hdr.op = 1;
    packet->hdr.htype = 1;
    packet->hdr.hlen = 6;
    packet->hdr.hops = 0;
    get_time_ms((s32 *)&dhcp_last_tick_ms);
    lbl_805D7B50 = dhcp_last_tick_ms;
    NetMemcpy(&packet->hdr.xid, &lbl_805D7B50, 4);
    packet->hdr.ciaddr = dhcp_client_addr;
    NetMemcpy(packet->hdr.chaddr, lbl_805D7B1C, 6);
    p = (u8 *)&packet->hdr.cookie;
    *(s32 *)p = lbl_805D7B4C;
    p += sizeof(packet->hdr.cookie);
    *p++ = 0x35;
    *p++ = 1;
    *p++ = 7;
    *p++ = 0x3D;
    *p++ = 7;
    *p++ = 1;
    NetMemcpy(p, lbl_805D7B1C, 6);
    p += 6;
    *p++ = 0x36;
    *p++ = 4;
    NetMemcpy(p, dhcp_server_id, 4);
    p += 4;
    len = NetStringLength((const char*)dhcp_hostname);
    if (len != 0) {
        *p++ = 0xC;
        m = len + 1;
        *p++ = m;
        NetMemcpy(p, dhcp_hostname, m);
        p += m;
    }
    *p++ = 0xFF;
    return p - ((u8 *)packet);
}

s32 dhcp_build_packet(DhcpMessage *packet) {
    s32 m;
    u8 *p;
    u16 len;
    u32 tmp;
    NetMemset(packet, 0, sizeof(*packet));
    packet->hdr.op = 1;
    packet->hdr.htype = 1;
    packet->hdr.hlen = 6;
    packet->hdr.hops = 0;
    NetMemcpy(&packet->hdr.xid, &lbl_805D7B50, 4);
    packet->hdr.flags = 0;
    if (dhcp_state == 4 || dhcp_state == 5) {
        packet->hdr.ciaddr = dhcp_client_addr;
    }
    NetMemcpy(packet->hdr.chaddr, lbl_805D7B1C, 6);
    p = (u8 *)&packet->hdr.cookie;
    *(s32 *)p = (s32)lbl_805D7B4C;
    p += sizeof(packet->hdr.cookie);
    *p++ = 0x35;
    *p++ = 1;
    *p++ = 3;
    *p++ = 0x3D;
    *p++ = 7;
    *p++ = 1;
    NetMemcpy(p, lbl_805D7B1C, 6);
    p += 6;
    *p++ = 0x37;
    *p++ = 5;
    *p++ = 1;
    *p++ = 3;
    *p++ = 6;
    *p++ = 0xF;
    *p++ = 0x1C;
    if (dhcp_state != 4 && dhcp_state != 5) {
        *p++ = 0x36;
        *p++ = 4;
        NetMemcpy(p, dhcp_server_id, 4);
        p += 4;
    }
    if (dhcp_requested_lease != 0) {
        *p++ = 0x33;
        *p++ = 4;
        tmp = dhcp_requested_lease;
        NetMemcpy(p, &tmp, 4);
        p += 4;
    }
    if (dhcp_state != 4 && dhcp_state != 5) {
        *p++ = 0x32;
        *p++ = 4;
        NetMemcpy(p, &dhcp_client_addr, 4);
        p += 4;
    }
    len = NetStringLength((const char*)&dhcp_hostname);
    if (len != 0) {
        *p++ = 0xC;
        m = len + 1;
        *p++ = m;
        NetMemcpy(p, ((char *)&dhcp_hostname), m);
        p += m;
    }
    *p++ = 0xFF;
    return p - ((u8 *)packet);
}

s32 build_dhcp_discover_packet(DhcpMessage *packet) {
    u32 source;
    u8 *p;
    u16 len;
    s32 n;
    NetMemset(packet, 0, sizeof(*packet));
    packet->hdr.op = 1;
    packet->hdr.htype = 1;
    packet->hdr.hlen = 6;
    packet->hdr.hops = 0;
    get_time_ms((s32 *)&dhcp_last_tick_ms);
    lbl_805D7B50 = dhcp_last_tick_ms;
    NetMemcpy(&packet->hdr.xid, &lbl_805D7B50, 4);
    packet->hdr.flags = 0;
    NetMemcpy(packet->hdr.chaddr, lbl_805D7B1C, 6);
    p = (u8 *)&packet->hdr.cookie;
    *(u32 *)p = lbl_805D7B4C;
    p += sizeof(packet->hdr.cookie);
    *p++ = 0x35;
    *p++ = 1;
    *p++ = 1;
    *p++ = 0x3D;
    *p++ = 7;
    *p++ = 1;
    NetMemcpy(p, lbl_805D7B1C, 6);
    p += 6;
    *p++ = 0x37;
    *p++ = 5;
    *p++ = 1;
    *p++ = 3;
    *p++ = 6;
    *p++ = 0xF;
    *p++ = 0x1C;
    if (dhcp_requested_lease != 0) {
        *p++ = 0x33;
        *p++ = 4;
        source = dhcp_requested_lease;
        NetMemcpy(p, &source, 4);
        p += 4;
    }
    len = NetStringLength((const char*)dhcp_hostname);
    if (len != 0) {
        *p++ = 0xC;
        n = len + 1;
        *p++ = n;
        NetMemcpy(p, dhcp_hostname, n);
        p += n;
    }
    *p++ = 0xFF;
    return p - ((u8 *)packet);
}

s32 dhcp_set_interface_mode(s32);
s32 ensure_dhcp_reply_socket(void);


s32 dhcp_release_step(void) {
    s32 now;
    P_8042315C opt;
    send_buffs buf;
    NetworkAddress dst;
    NetworkAddress src;
    s32 len;
    u32 pad[3];
    s16 sock;
    get_time_ms(&now);
    switch (dhcp_step) {
    case 0:
        udp_close(dhcp_socket);
        dhcp_socket = -1;
        if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
            lbl_805D7B14 = dhcp_set_interface_mode(0);
        }
        opt.type = 4;
        opt.a = 0;
        opt.b = -1;
        opt.c = -1;
        if (if_config(dhcp_iface, &opt) != 0) {
            dhcp_error = 3;
            dhcp_step = -1;
            dhcp_state = -2;
            break;
        }
        lbl_805D7B14 = 1;
        if (ensure_dhcp_reply_socket() != 0) {
            break;
        }
        lbl_805D7B9C = dhcp_max_retries;
    case 1:
        if (dhcp_step == 0) {
            dhcp_step = 1;
        } else if (now - lbl_805D7B98 < 300) {
            break;
        }
        len = build_dhcp_release(&lbl_805C1E00.outgoing);
        src.family = 4;
        dst.family = 4;
        src.ipv4 = 0;
        dst.ipv4 = 0xFFFFFFFF;
        sock = dhcp_socket;
        len = len > 300 ? len : 300;
        buf.len = len;
        buf.buff = (u8 *)&lbl_805C1E00.outgoing;
        if (udp_send(sock, &src, &dst, 0x43, NULL, 1, &buf) < 0) {
            udp_close(dhcp_socket);
            dhcp_socket = -1;
            if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                lbl_805D7B14 = dhcp_set_interface_mode(0);
            }
            dhcp_error = 5;
            dhcp_step = -1;
            dhcp_state = -2;
        } else {
            lbl_805D7B98 = now;
            lbl_805D7B9C--;
            if (lbl_805D7B9C <= 0) {
                udp_close(dhcp_socket);
                dhcp_socket = -1;
                if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                    lbl_805D7B14 = dhcp_set_interface_mode(0);
                }
                dhcp_state = 0;
                dhcp_step = 0;
                dhcp_set_option(0xF, 0, NULL);
                dhcp_set_option(0xE, 0, NULL);
            }
        }
        break;
    }
    return dhcp_state;
}

/* One step of the DHCP request state machine (dhcp_step). */
s32 dhcp_request_step(void) {
    s32 now;
    s32 x;
    send_buffs buf;
    NetworkAddress dst;
    NetworkAddress src;
    u32 pad[3];
    s32 len;
    s16 sock;
    u32 d;
    s32 id;
    u32 t;
    get_time_ms(&now);
    switch (dhcp_step) {
    case 0:
        lbl_805D7B50 = now;
        if (dhcp_state == 2) {
            lbl_805D7B90 = dhcp_max_retries;
        }
        if (ensure_dhcp_reply_socket() != 0) {
            break;
        }
        dhcp_step = 1;
    case 1:
        len = dhcp_build_packet(&lbl_805C1E00.outgoing);
        dhcp_reply_received = 0;
        if (dhcp_state == 4) {
            id = *(s32 *)dhcp_server_id;
        } else {
            id = -1;
        }
        sock = dhcp_socket;
        dst.family = 4;
        src.family = 4;
        src.ipv4 = 0;
        dst.ipv4 = id;
        len = len > 300 ? len : 300;
        buf.len = len;
        buf.buff = (u8 *)&lbl_805C1E00.outgoing;
        if (udp_send(sock, &src, &dst, 0x43, NULL, 1, &buf) < 0) {
            udp_close(dhcp_socket);
            dhcp_socket = -1;
            if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                lbl_805D7B14 = dhcp_set_interface_mode(0);
            }
            dhcp_error = 5;
            dhcp_step = -1;
            dhcp_state = -2;
            break;
        }
        lbl_805D7B8C = now;
        if (dhcp_state == 4) {
            d = dhcp_rebinding_time - dhcp_lease_elapsed;
            if (d >= 120) {
                lbl_805D7B94 = (d >> 1) * 1000;
            } else {
                lbl_805D7B94 = 0;
            }
        } else if (dhcp_state == 5) {
            d = dhcp_lease_time - dhcp_lease_elapsed;
            if (d >= 120) {
                lbl_805D7B94 = (d >> 1) * 1000;
            } else {
                lbl_805D7B94 = 0;
            }
        }
        dhcp_step = 2;
        break;
    case 2:
        if (dhcp_reply_received != 0) {
            if (dhcp_state == 4 || dhcp_state == 5) {
                parse_dhcp_lease_times((u8 *)&lbl_805C1E00.reply.hdr.cookie);
                dhcp_lease_elapsed = 0;
            }
            udp_close(dhcp_socket);
            dhcp_socket = -1;
            if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                lbl_805D7B14 = dhcp_set_interface_mode(0);
            }
            TLobby__sub_80423440(&lbl_805C1E00.reply.hdr);
            dhcp_step = 0;
            dhcp_state = 3;
        } else if (dhcp_state == 2) {
            if ((u32)(now - lbl_805D7B8C) >= 3000) {
                lbl_805D7B90--;
                if (lbl_805D7B90 <= 0) {
                    udp_close(dhcp_socket);
                    dhcp_socket = -1;
                    if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                        lbl_805D7B14 = dhcp_set_interface_mode(0);
                    }
                    dhcp_state = -1;
                    dhcp_step = -1;
                    dhcp_error = 7;
                } else {
                    dhcp_step = 1;
                }
            }
        } else if (dhcp_state == 4) {
            t = lbl_805D7B94;
            if (t != 0 && (u32)(now - lbl_805D7B8C) >= t) {
                dhcp_step = 1;
            } else {
                dhcp_error = 8;
            }
        } else if (dhcp_state == 5) {
            t = lbl_805D7B94;
            if (t != 0 && (u32)(now - lbl_805D7B8C) >= t) {
                dhcp_step = 1;
            } else {
                dhcp_error = 9;
            }
        }
        break;
    }
    return dhcp_state;
}
s16 dhcp_handle_reply(s16 arg0, NetworkReceivePrefix *arg1);
/* One step of the DHCP discover state machine (dhcp_step). */
s32 dhcp_discover_step(void) {
    s32 now;
    P_8042315C req;
    P_8042315C req2;
    u32 pad2[3];
    u32 buf[2];
    u32 pad1[1];
    send_buffs rd;
    NetworkAddress dst;
    NetworkAddress src;
    s32 len;
    s16 sock;
    u32 pad[4];
    get_time_ms(&now);
    switch (dhcp_step) {
    case 0:
        udp_close(dhcp_socket);
        dhcp_socket = -1;
        if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
            lbl_805D7B14 = dhcp_set_interface_mode(0);
        }
        req.type = 4;
        req.a = 0;
        req.b = -1;
        req.c = -1;
        if (if_config(dhcp_iface, &req) != 0) {
            if_down(dhcp_iface, 4);
            req2.type = 4;
            req2.a = 0;
            req2.b = -1;
            req2.c = -1;
            if (if_config(dhcp_iface, &req2) != 0) {
                dhcp_step = -1;
                dhcp_state = -2;
                dhcp_error = 3;
                break;
            }
        }
        lbl_805D7B14 = 1;
        buf[0] = 4;
        buf[1] = 0;
        sock = udp_open(NULL, 0x44, buf, 0x43, 0, dhcp_handle_reply);
        dhcp_socket = sock;
        if (sock < 0) {
            if_down(dhcp_iface, 4);
            lbl_805D7B14 = 0;
            dhcp_step = -1;
            dhcp_state = -2;
            dhcp_error = 4;
            break;
        }
        dhcp_retries_left = dhcp_max_retries;
        dhcp_step = 1;
    case 1:
        len = build_dhcp_discover_packet(&lbl_805C1E00.outgoing);
        dhcp_reply_received = 0;
        src.family = 4;
        dst.family = 4;
        src.ipv4 = 0;
        dst.ipv4 = 0xFFFFFFFF;
        sock = dhcp_socket;
        len = len > 300 ? len : 300;
        rd.len = len;
        rd.buff = (u8 *)&lbl_805C1E00.outgoing;
        if (udp_send(sock, &src, &dst, 0x43, NULL, 1, &rd) < 0) {
            udp_close(dhcp_socket);
            dhcp_socket = -1;
            if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                lbl_805D7B14 = dhcp_set_interface_mode(0);
            }
            dhcp_error = 5;
            dhcp_step = -1;
            dhcp_state = -2;
            break;
        }
        dhcp_send_time = now;
        dhcp_step = 2;
        break;
    case 2:
        if (dhcp_reply_received != 0) {
            dhcp_step = 0;
            dhcp_state = 2;
            break;
        }
        if ((u32)(now - dhcp_send_time) < 3000) {
            break;
        }
        dhcp_retries_left--;
        if (dhcp_retries_left <= 0) {
            udp_close(dhcp_socket);
            dhcp_socket = -1;
            if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                lbl_805D7B14 = dhcp_set_interface_mode(0);
            }
            dhcp_state = -1;
            dhcp_step = -1;
            dhcp_error = 6;
            break;
        }
        dhcp_step = 1;
        break;
    }
    return dhcp_state;
}

s16 DHCP_hostname(char *hostname) {
    u32 length;
    dhcp_error = 0;
    if (hostname == 0) {
        dhcp_error = 1;
        return -1;
    }
    length = NetStringLength((const char*)hostname);
    if ((u16)length < 0x20 && (u16)length != 0) {
        dhcp_set_option(0x10, (u16)length, hostname);
        return 0;
    }
    dhcp_error = 1;
    return -1;
}


void dhcp_stop(void);
s32 dhcp_get_option(s16, void *);

typedef struct DhcpOption_804FD948 {
    s16 id;
    s16 present;
    s16 kind;
    s16 size;
    void *data;
} DhcpOption_804FD948;
DhcpOption_804FD948 lbl_804FD948[12] = {
    { 0x1, 0, 1, 4, &dhcp_netmask },
    { 0x2, 0, 1, 4, &dhcp_broadcast },
    { 0x3, 0, 0, 0x100, dhcp_domain_name },
    { 0x4, 0, 1, 4, &dhcp_dns1 },
    { 0x5, 0, 1, 4, &dhcp_dns2 },
    { 0x6, 0, 1, 4, &dhcp_router },
    { 0x7, 0, 1, 4, &dhcp_lease_time },
    { 0x8, 0, 1, 4, &dhcp_renewal_time },
    { 0x9, 0, 1, 4, &dhcp_rebinding_time },
    { 0xE, 0, 1, 4, dhcp_server_id },
    { 0xF, 0, 1, 4, &dhcp_client_addr },
    { 0x10, 0, 0, 0x20, dhcp_hostname },
};
void net_sleep_ms(s32);

s32 get_task_count(void) {
    return dhcp_state;
}


void parse_dhcp_lease_times(u8 *packet) {
    u8 *arg0 = packet;
    u8 *p;
    s32 v;
    s32 w;

    if (find_dhcp_option(arg0, 0x33, &p) == 4) {
        NetMemcpy(&v, p, 4);
        w = v;
        dhcp_set_option(7, 4, &w);
        get_time_seconds((s32 *)&dhcp_lease_start);
        dhcp_lease_expiry = dhcp_lease_start + dhcp_lease_time;
        if (find_dhcp_option(arg0, 0x3A, &p) == 4) {
            NetMemcpy(&v, p, 4);
            w = v;
            dhcp_set_option(8, 4, &w);
        } else {
            dhcp_set_option(8, 0, NULL);
            dhcp_renewal_time = dhcp_lease_time >> 1;
        }
        if (find_dhcp_option(arg0, 0x3B, &p) == 4) {
            NetMemcpy(&v, p, 4);
            w = v;
            dhcp_set_option(9, 4, &w);
        } else {
            dhcp_set_option(9, 0, NULL);
            dhcp_rebinding_time = (dhcp_lease_time >> 1) + (dhcp_lease_time >> 2) + (dhcp_lease_time >> 3);
        }
    } else {
        dhcp_set_option(7, 0, NULL);
        dhcp_lease_time = -1;
    }
}

s16 TLobby__sub_8042474C(s32 *lease, s32 *renew, s32 *rebind) {
    dhcp_error = 0;
    if (dhcp_state == 3 || dhcp_state == 4 || dhcp_state == 5) {
        if (dhcp_get_option(7, lease) != 0) {
            dhcp_error = 0x11;
        }
        if (dhcp_get_option(8, renew) != 0 && dhcp_error == 0) {
            dhcp_error = 0x12;
        }
        if (dhcp_get_option(9, rebind) != 0 && dhcp_error == 0) {
            dhcp_error = 0x13;
        }
        return 0;
    }
    dhcp_error = 2;
    return -1;
}

s32 find_dhcp_option(u8 *p, u8 tag, u8 **out) {
    u8 *base = p;
    u8 t;
    u8 len;
    p += 4;
    while ((s32)((uaddr)base - (uaddr)p) < 0x4D4) {
        t = *p++;
        if (t == 0) {
            continue;
        }
        if (t == 0xFF) {
            return 0;
        }
        if (t == tag) {
            len = *p++;
            *out = p;
            return len;
        }
        len = *p++;
        p += len;
    }
    return 0;
}

s16 DHCP_get_gateway(void *arg0, s32 *router) {
    dhcp_error = 0;
    if (dhcp_state != 3 && dhcp_state != 4 && dhcp_state != 5) {
        dhcp_error = 2;
        return -1;
    }
    if (dhcp_get_option(6, router) != 0) {
        dhcp_error = 0x10;
    }
    return 0;
}

s16 DHCP_get_dns(void *arg0, char *domain, s32 *dns1, s32 *dns2) {
    dhcp_error = 0;
    if (dhcp_state != 3 && dhcp_state != 4 && dhcp_state != 5) {
        dhcp_error = 2;
        return -1;
    }
    if (dhcp_get_option(4, dns1) != 0) {
        dhcp_error = 0xE;
    }
    if (dhcp_get_option(5, dns2) != 0 && dhcp_error == 0) {
        dhcp_error = 0xF;
    }
    if (dhcp_get_option(3, domain) != 0 && dhcp_error == 0) {
        dhcp_error = 0xD;
    }
    return 0;
}

#pragma push
#pragma opt_propagation off
s16 dhcp_handle_reply(s16 arg0, NetworkReceivePrefix *arg1) {
    DhcpClientBuffers *g = &lbl_805C1E00;
    BootpPacket *pk;
    u8 *q;
    u8 *p;

    if (arg0 == 0) {
        arg1->buf = (u8 *)&g->received;
        return 0;
    }
    pk = &g->received.hdr;
    q = (u8 *)&pk->cookie;
    if (pk->op != 2 || pk->htype != 1 || pk->hlen != 6) {
        return 0;
    }
    if (NetMemcmp(&pk->xid, &lbl_805D7B50, 4) != 0) {
        return 0;
    }
    if (NetMemcmp(pk->chaddr, lbl_805D7B1C, 6) != 0) {
        return 0;
    }
    if (NetMemcmp(q, &lbl_805D7B4C, 4) != 0) {
        return 0;
    }
    if (dhcp_step != 2) {
        return 0;
    }
    switch (dhcp_state) {
    case 3:
        break;
    case 1:
        if (dhcp_reply_received == 0 && find_dhcp_option(q, 0x35, &p) == 1 && *p == 2 &&
            find_dhcp_option(q, 0x36, &p) == 4) {
            dhcp_set_option(0xE, 4, p);
            dhcp_client_addr = pk->yiaddr;
            dhcp_reply_received = 1;
        }
        break;
    case 2:
        if (dhcp_reply_received == 0 && find_dhcp_option(q, 0x35, &p) == 1 && *p == 5) {
            NetMemcpy(&g->reply, &g->received, arg1->len);
            dhcp_reply_received = 1;
        }
        break;
    case 4:
        if (dhcp_reply_received == 0 && find_dhcp_option(q, 0x35, &p) == 1 && *p == 5 &&
            dhcp_client_addr == pk->yiaddr) {
            NetMemcpy(&g->reply, &g->received, arg1->len);
            dhcp_reply_received = 1;
        }
        break;
    case 5:
        if (dhcp_reply_received == 0 && find_dhcp_option(q, 0x35, &p) == 1 && *p == 5 &&
            dhcp_client_addr == pk->yiaddr) {
            NetMemcpy(&g->reply, &g->received, arg1->len);
            dhcp_reply_received = 1;
        }
        break;
    }
    return 0;
}
#pragma pop

void dhcp_stop(void) {
    NetUnregisterTimer(TLobby__sub_80423298);
    if (dhcp_socket != -1) {
        udp_close(dhcp_socket);
        dhcp_socket = -1;
    }
    lbl_805D7B14 = dhcp_set_interface_mode(0);
}

s32 DHCP_release(s32 session, s32 ip, s32 retries) {
    s32 state;
    dhcp_state = 6;
    dhcp_step = 0;
    dhcp_max_retries = retries;
    dhcp_error = 0;
    do {
        state = dhcp_state;
        net_sleep_ms(0x10);
    } while (state == 6);
    if (state != 0) {
        return -1;
    }
    return 0;
}

s16 dhcp_discover_and_request(s16 iface, s32 arg1, s32 lease_time, void *arg3, s32 *address, s32 *netmask, s32 *broadcast, s32 retries) {
    s32 state;
    if (DHCP_request(iface, arg1, lease_time, arg3, address, netmask, broadcast, retries) != 0) {
        return -1;
    }
    do {
        state = dhcp_state;
        net_sleep_ms(0x10);
    } while (state == 1 || state == 2);
    if (state == -1) {
        return 1;
    }
    if (state == -2) {
        return -1;
    }
    return 0;
}

s32 DHCP_request(s16 iface, s32 arg1, s32 lease_time, void *arg3, s32 *address, s32 *netmask, s32 *broadcast, s32 retries) {
    dhcp_error = 0;
    if (dhcp_state != 0) {
        dhcp_error = 2;
        return -1;
    }
    if (address == NULL || netmask == NULL || broadcast == NULL) {
        dhcp_error = 1;
        return -1;
    }
    dhcp_client_addr_out = address;
    dhcp_netmask_out = netmask;
    dhcp_broadcast_out = broadcast;
    lbl_805D7B54 = arg1;
    dhcp_requested_lease = lease_time;
    dhcp_max_retries = retries;
    dhcp_state = 1;
    dhcp_step = 0;
    return 0;
}

/* Clears the DHCP client state (lease timers, option table, hostname) and records the interface. */
static inline void dhcp_reset_state(s16 iface) {
    u32 i;

    dhcp_state = 0;
    dhcp_step = 0;
    dhcp_reply_received = 0;
    lbl_805D7B14 = dhcp_set_interface_mode(0);
    dhcp_socket = -1;
    for (i = 0; i < 12; i++) {
        lbl_804FD948[i].present = 0;
        NetMemset(lbl_804FD948[i].data, 0, lbl_804FD948[i].size);
    }
    dhcp_client_addr_out = 0;
    dhcp_netmask_out = 0;
    dhcp_broadcast_out = 0;
    lbl_805D7B4C = 0x63825363;
    lbl_805D7B50 = 0;
    lbl_805D7B54 = 0;
    dhcp_requested_lease = 0;
    NetMemset(dhcp_hostname, 0, 0x20);
    dhcp_elapsed_ms = 0;
    dhcp_last_tick_ms = 0;
    dhcp_lease_time = 0;
    dhcp_renewal_time = 0;
    dhcp_rebinding_time = 0;
    dhcp_lease_elapsed = 0;
    dhcp_max_retries = 0;
    dhcp_lease_start = 0;
    dhcp_lease_expiry = 0;
    dhcp_error = 0;
    dhcp_iface = iface;
}

/* Brings the interface up (mode-4 request), then reads its 0x1C-byte info into lbl_805D7B1C. */
static inline s32 dhcp_open_interface(s16 iface) {
    s32 addr[7];
    addr[0] = 4;
    addr[1] = 0;
    addr[2] = 0;
    addr[3] = 0;
    if (if_config(iface, addr) < 0) {
        return -1;
    }
    if (TLobby__sub_80422F70(iface, addr, 0x1C, lbl_805D7B1C) < 0) {
        if_down(iface, 4);
        return -1;
    }
    if_down(iface, 4);
    return 0;
}

s16 DHCP_init(s16 iface) {
    dhcp_reset_state(iface);
    if (dhcp_open_interface(dhcp_iface) != 0) {
        dhcp_error = 3;
        return -1;
    }
    NetRegisterTimer(50, 0, TLobby__sub_80423298);
    return 0;
}

s32 ensure_dhcp_reply_socket(void) {
    s32 addr[7];
    u8 unused[4];
    if (dhcp_state == 4 || dhcp_state == 5 || dhcp_state == 6) {
        if (dhcp_socket > -1) {
            udp_close(dhcp_socket);
        }
        addr[0] = 4;
        addr[1] = 0;
        if ((dhcp_socket = udp_open(0, 0x44, addr, 0x43, 0, dhcp_handle_reply)) < 0) {
            if (dhcp_state == 6) {
                lbl_805D7B14 = dhcp_set_interface_mode(0);
            }
            dhcp_error = 4;
            dhcp_step = -1;
            dhcp_state = -2;
            return -1;
        }
    }
    return 0;
}

#pragma dont_inline on
#pragma use_lmw_stmw off
s32 dhcp_set_interface_mode(s32 mode) {
    u8 pad0[4];
    u8 buf[0x1c];
    s32 buf2[3];
    struct Req_804250A8 req;
    u8 pad[0x10];
    struct Req_804250A8 req2;
    s32 ret;
    s32 r;

    ret = (s16)TLobby__sub_80422F70(dhcp_iface, buf, 0x1c, (u8 *)buf2 + 0x28) < 0 ? 0 : 1;
    r = ret;
    if (ret != mode) {
        switch (mode) {
        case 1:
            req.a = 4;
            req.b = 0;
            req.c = -1;
            req.d = -1;
            if (if_config(dhcp_iface, &req) != 0) {
                if_down(dhcp_iface, 4);
                req2.a = 4;
                req2.b = 0;
                req2.c = -1;
                req2.d = -1;
                if (if_config(dhcp_iface, &req2) != 0) {
                    dhcp_error = 3;
                    r = 0;
                    dhcp_step = -1;
                    dhcp_state = -2;
                    return r;
                }
            }
            return 1;
        case 0:
            if_down(dhcp_iface, 4);
            return 0;
        }
    }
    return r;
}
#pragma use_lmw_stmw reset
#pragma dont_inline off

s32 dhcp_get_option(s16 id, void *out) {
    DhcpOption_804FD948 *tbl = lbl_804FD948;
    s32 result = -1;
    s32 i;
    for (i = 0; i < 12; i++) {
        if (id == tbl[i].id) {
            if (tbl[i].present != 0) {
                result = 0;
            }
            if (out != NULL) {
                switch (tbl[i].kind) {
                case 0:
                    NetCopyString((char*)out, (const char*)tbl[i].data);
                    break;
                case 1:
                    NetMemcpy(out, tbl[i].data, tbl[i].size);
                    break;
                }
            }
            break;
        }
    }
    return result;
}

s32 dhcp_set_option(s16 id, s16 len, void *value) {
    DhcpOption_804FD948 *tbl = lbl_804FD948;
    s32 result = -1;
    s32 i;
    for (i = 0; i < 12; i++) {
        if (id == tbl[i].id) {
            result = 0;
            switch (tbl[i].kind) {
            case 0:
            case 1:
                if (value != NULL) {
                    tbl[i].present = 1;
                    NetMemcpy(tbl[i].data, value, tbl[i].size);
                    if (tbl[i].kind == 0) {
                        u8 *end = (u8 *)tbl[i].data;
                        if (len < tbl[i].size) {
                            end += len;
                        } else {
                            end += tbl[i].size - 1;
                        }
                        *end = 0;
                    }
                } else {
                    tbl[i].present = 0;
                    if (len > 0) {
                        NetMemset(tbl[i].data, 0, tbl[i].size);
                    }
                }
                break;
            }
            break;
        }
    }
    return result;
}


u8 dhcp_hostname[0x2C];
u8 dhcp_domain_name[0x100];
