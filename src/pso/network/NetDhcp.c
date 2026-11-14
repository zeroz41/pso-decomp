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

typedef struct Pkt_804249F0 {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 pad3;
    u8 f4[4];
    u8 pad8[0x10 - 0x8];
    u32 f10;
    u8 pad14[0x1C - 0x14];
    u8 f1C[6];
    u8 pad22[0xEC - 0x22];
    u8 opts[4];
} Pkt_804249F0;

typedef struct G_804249F0 {
    u8 pad0[0x5DC];
    u8 buf[0xBB8 - 0x5DC];
    Pkt_804249F0 pkt;
} G_804249F0;

typedef struct Arg_804249F0 {
    u8 pad0[2];
    s16 len;
    void *p;
} Arg_804249F0;

typedef struct Req_804250A8 {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
} Req_804250A8;

typedef struct P_8042315C { s32 type; s32 a; s32 b; s32 c; s32 pad10; s16 n; s16 m; s32 d; s32 pad1C; } P_8042315C;

s32 NetUnregisterTimer(void *);
s32 TLobby__sub_80425288(s16, s16, void *);
s16 TUdpSocket__sub_80421BAC(s32 h, u32 *src, u32 *dst, u16 port, u32 *opt, s8 n, send_buffs *bufs);
s16 TUdpSocket__sub_80421DEC(void *src, s32 sport, void *dst, s32 dport, s32 arg4, void *cb);
s16 TLobby__sub_80422F70(s16 iface, void *hdr_src, s32 len, void *buf);
s16 TLobby__sub_8042315C(s16 iface, void *req);
u8 lbl_805C1E00[0x1194];
extern u8 lbl_805C2F94[0x100]; /* defined at the end of the file */
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
u32 lbl_805D7B58;
s32 lbl_805D7B54;
u32 lbl_805D7B50;
u32 lbl_805D7B4C;
s32 *lbl_805D7B48;
s32 *lbl_805D7B44;
s32 *lbl_805D7B40;
u32 lbl_805D7B3C;
u32 lbl_805D7B38;
u32 lbl_805D7B34;
s32 lbl_805D7B30;
s32 lbl_805D7B2C;
u32 lbl_805D7B28;
u8 dhcp_server_id[4];
u8 lbl_805D7B1C[6];
s16 dhcp_socket;
s32 lbl_805D7B14;
s32 dhcp_reply_received;
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
            TLobby__sub_80421B3C(dhcp_socket);
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

s32 TLobby__sub_80423440(u8 *pkt) {
    s32 find_dhcp_option(u8 *p, u8 tag, u8 **out); /* declared s32 here; the definition returns u8 */
    u8 *opts = pkt + 0xEC;
    u8 *p;
    s32 net;
    s32 w;
    u32 mask;
    u32 n;
    TLobby__sub_80425288(0xF, 4, pkt + 0x10);
    lbl_805D7B80 = 0;
    if (find_dhcp_option(opts, 1, &p) == 4) {
        lbl_805D7B80++;
        TLobby__sub_80425288(1, 4, p);
    } else {
        if (!(lbl_805D7B28 & 0x80000000)) {
            mask = 0xFF000000;
        } else if ((lbl_805D7B28 & 0xC0000000) == 0x80000000) {
            mask = 0xFFFF0000;
        } else if ((lbl_805D7B28 & 0xE0000000) == 0xC0000000) {
            mask = 0xFFFFFF00;
        } else {
            mask = 0;
        }
        TLobby__sub_80425288(1, 0, NULL);
        lbl_805D7B2C = mask;
    }
    if (find_dhcp_option(opts, 0x1C, &p) == 4) {
        lbl_805D7B80++;
        TLobby__sub_80425288(2, 4, p);
    } else {
        TLobby__sub_80425288(2, 0, NULL);
        net = lbl_805D7B28 & lbl_805D7B2C;
        lbl_805D7B30 = net | (lbl_805D7B2C ^ 0xFFFFFFFF);
    }
    if (lbl_805D7B40 != NULL) {
        *lbl_805D7B40 = lbl_805D7B28;
        lbl_805D7B40 = NULL;
    }
    if (lbl_805D7B44 != NULL) {
        *lbl_805D7B44 = lbl_805D7B2C;
        lbl_805D7B44 = NULL;
    }
    if (lbl_805D7B48 != NULL) {
        *lbl_805D7B48 = lbl_805D7B30;
        lbl_805D7B48 = NULL;
    }
    parse_dhcp_lease_times((u8 *)opts);
    n = find_dhcp_option(opts, 0xF, &p);
    if (n != 0) {
        TLobby__sub_80425288(3, (s16)n, p);
    } else {
        TLobby__sub_80425288(3, 1, NULL);
    }
    n = find_dhcp_option(opts, 6, &p);
    if (n >= 4 && (n & 3) == 0) {
        TLobby__sub_80425288(4, 4, p);
        if (n > 4) {
            TLobby__sub_80425288(5, 4, p + 4);
        } else {
            TLobby__sub_80425288(5, 4, NULL);
        }
    } else {
        TLobby__sub_80425288(4, 4, NULL);
        TLobby__sub_80425288(5, 4, NULL);
    }
    n = find_dhcp_option(opts, 3, &p);
    if (n >= 4 && (n & 3) == 0) {
        TLobby__sub_80425288(6, 4, p);
    } else {
        TLobby__sub_80425288(6, 4, NULL);
    }
    return 0;
}

/* Builds a DHCP release packet into packet. */
s32 build_dhcp_release(u8 *packet) {
    s32 m;
    u8 *p;
    u16 len;
    NetMemset(packet, 0, 0x5DC);
    ((u8 *)packet)[0] = 1;
    ((u8 *)packet)[1] = 1;
    ((u8 *)packet)[2] = 6;
    ((u8 *)packet)[3] = 0;
    get_time_ms((s32 *)&dhcp_last_tick_ms);
    lbl_805D7B50 = dhcp_last_tick_ms;
    NetMemcpy(((u8 *)packet) + 4, &lbl_805D7B50, 4);
    *(s32 *)(((u8 *)packet) + 0xC) = lbl_805D7B28;
    NetMemcpy(((u8 *)packet) + 0x1C, lbl_805D7B1C, 6);
    p = ((u8 *)packet) + 0xEC;
    *(s32 *)p = lbl_805D7B4C;
    p += 4;
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

s32 dhcp_build_packet(u8 *packet) {
    s32 m;
    u8 *p;
    u16 len;
    u32 tmp;
    NetMemset(packet, 0, 0x5DC);
    ((u8 *)packet)[0] = 1;
    ((u8 *)packet)[1] = 1;
    ((u8 *)packet)[2] = 6;
    ((u8 *)packet)[3] = 0;
    NetMemcpy(((u8 *)packet) + 4, &lbl_805D7B50, 4);
    *(u16 *)(((u8 *)packet) + 0xA) = 0;
    if (dhcp_state == 4 || dhcp_state == 5) {
        *(s32 *)(((u8 *)packet) + 0xC) = lbl_805D7B28;
    }
    NetMemcpy(((u8 *)packet) + 0x1C, lbl_805D7B1C, 6);
    p = ((u8 *)packet) + 0xEC;
    *(s32 *)p = (*(s32 *)&lbl_805D7B4C);
    p += 4;
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
    if (lbl_805D7B58 != 0) {
        *p++ = 0x33;
        *p++ = 4;
        tmp = lbl_805D7B58;
        NetMemcpy(p, &tmp, 4);
        p += 4;
    }
    if (dhcp_state != 4 && dhcp_state != 5) {
        *p++ = 0x32;
        *p++ = 4;
        NetMemcpy(p, &lbl_805D7B28, 4);
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

s32 build_dhcp_discover_packet(u8 *packet) {
    u32 spC;
    u8 *p;
    u16 len;
    s32 n;
    NetMemset(packet, 0, 0x5DC);
    ((u8 *)packet)[0] = 1;
    ((u8 *)packet)[1] = 1;
    ((u8 *)packet)[2] = 6;
    ((u8 *)packet)[3] = 0;
    get_time_ms((s32 *)&dhcp_last_tick_ms);
    lbl_805D7B50 = dhcp_last_tick_ms;
    NetMemcpy(((u8 *)packet) + 4, &lbl_805D7B50, 4);
    *(s16 *)(((u8 *)packet) + 0xA) = 0;
    NetMemcpy(((u8 *)packet) + 0x1C, lbl_805D7B1C, 6);
    p = ((u8 *)packet) + 0xEC;
    *(u32 *)p = lbl_805D7B4C;
    p += 4;
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
    if (lbl_805D7B58 != 0) {
        *p++ = 0x33;
        *p++ = 4;
        spC = lbl_805D7B58;
        NetMemcpy(p, &spC, 4);
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

s32 TLobby__sub_804250A8(s32);
s32 TLobby__sub_80424FE0(void);


s32 dhcp_release_step(void) {
    s32 now;
    P_8042315C opt;
    send_buffs buf;
    u32 dst[5];
    u32 src[5];
    s32 len;
    u32 pad[3];
    s16 sock;
    get_time_ms(&now);
    switch (dhcp_step) {
    case 0:
        TLobby__sub_80421B3C(dhcp_socket);
        dhcp_socket = -1;
        if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
            lbl_805D7B14 = TLobby__sub_804250A8(0);
        }
        opt.type = 4;
        opt.a = 0;
        opt.b = -1;
        opt.c = -1;
        if (TLobby__sub_8042315C(dhcp_iface, &opt) != 0) {
            dhcp_error = 3;
            dhcp_step = -1;
            dhcp_state = -2;
            break;
        }
        lbl_805D7B14 = 1;
        if (TLobby__sub_80424FE0() != 0) {
            break;
        }
        lbl_805D7B9C = dhcp_max_retries;
    case 1:
        if (dhcp_step == 0) {
            dhcp_step = 1;
        } else if (now - lbl_805D7B98 < 300) {
            break;
        }
        len = build_dhcp_release((u8 *)lbl_805C1E00);
        src[0] = 4;
        dst[0] = 4;
        src[1] = 0;
        dst[1] = -1;
        sock = dhcp_socket;
        len = len > 300 ? len : 300;
        buf.len = len;
        buf.buff = lbl_805C1E00;
        if (TUdpSocket__sub_80421BAC(sock, src, dst, 0x43, NULL, 1, &buf) < 0) {
            TLobby__sub_80421B3C(dhcp_socket);
            dhcp_socket = -1;
            if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                lbl_805D7B14 = TLobby__sub_804250A8(0);
            }
            dhcp_error = 5;
            dhcp_step = -1;
            dhcp_state = -2;
        } else {
            lbl_805D7B98 = now;
            lbl_805D7B9C--;
            if (lbl_805D7B9C <= 0) {
                TLobby__sub_80421B3C(dhcp_socket);
                dhcp_socket = -1;
                if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                    lbl_805D7B14 = TLobby__sub_804250A8(0);
                }
                dhcp_state = 0;
                dhcp_step = 0;
                TLobby__sub_80425288(0xF, 0, NULL);
                TLobby__sub_80425288(0xE, 0, NULL);
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
    u32 dst[5];
    u32 src[5];
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
        if (TLobby__sub_80424FE0() != 0) {
            break;
        }
        dhcp_step = 1;
    case 1:
        len = dhcp_build_packet(lbl_805C1E00);
        *(volatile s32 *)&dhcp_reply_received = 0;
        if (dhcp_state == 4) {
            id = *(s32 *)dhcp_server_id;
        } else {
            id = -1;
        }
        sock = dhcp_socket;
        dst[0] = 4;
        src[0] = 4;
        src[1] = 0;
        dst[1] = id;
        len = len > 300 ? len : 300;
        buf.len = len;
        buf.buff = lbl_805C1E00;
        if (TUdpSocket__sub_80421BAC(sock, src, dst, 0x43, NULL, 1, &buf) < 0) {
            TLobby__sub_80421B3C(dhcp_socket);
            dhcp_socket = -1;
            if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                lbl_805D7B14 = TLobby__sub_804250A8(0);
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
                parse_dhcp_lease_times(lbl_805C1E00 + 0x6C8);
                dhcp_lease_elapsed = 0;
            }
            TLobby__sub_80421B3C(dhcp_socket);
            dhcp_socket = -1;
            if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                lbl_805D7B14 = TLobby__sub_804250A8(0);
            }
            TLobby__sub_80423440(lbl_805C1E00 + 0x5DC);
            dhcp_step = 0;
            dhcp_state = 3;
        } else if (dhcp_state == 2) {
            if ((u32)(now - lbl_805D7B8C) >= 3000) {
                lbl_805D7B90--;
                if (lbl_805D7B90 <= 0) {
                    TLobby__sub_80421B3C(dhcp_socket);
                    dhcp_socket = -1;
                    if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                        lbl_805D7B14 = TLobby__sub_804250A8(0);
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
s32 dhcp_handle_reply(s16 arg0, Arg_804249F0 *arg1);
/* One step of the DHCP discover state machine (dhcp_step). */
s32 dhcp_discover_step(void) {
    s32 now;
    P_8042315C req;
    P_8042315C req2;
    u32 pad2[3];
    u32 buf[2];
    u32 pad1[1];
    send_buffs rd;
    u32 dst[5];
    u32 src[5];
    s32 len;
    s16 sock;
    u32 pad[4];
    get_time_ms(&now);
    switch (dhcp_step) {
    case 0:
        TLobby__sub_80421B3C(dhcp_socket);
        dhcp_socket = -1;
        if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
            lbl_805D7B14 = TLobby__sub_804250A8(0);
        }
        req.type = 4;
        req.a = 0;
        req.b = -1;
        req.c = -1;
        if (TLobby__sub_8042315C(dhcp_iface, &req) != 0) {
            TLobby__sub_80423064(dhcp_iface, 4);
            req2.type = 4;
            req2.a = 0;
            req2.b = -1;
            req2.c = -1;
            if (TLobby__sub_8042315C(dhcp_iface, &req2) != 0) {
                dhcp_step = -1;
                dhcp_state = -2;
                dhcp_error = 3;
                break;
            }
        }
        lbl_805D7B14 = 1;
        buf[0] = 4;
        buf[1] = 0;
        sock = TUdpSocket__sub_80421DEC(NULL, 0x44, buf, 0x43, 0, dhcp_handle_reply);
        dhcp_socket = sock;
        if (sock < 0) {
            TLobby__sub_80423064(dhcp_iface, 4);
            lbl_805D7B14 = 0;
            dhcp_step = -1;
            dhcp_state = -2;
            dhcp_error = 4;
            break;
        }
        dhcp_retries_left = dhcp_max_retries;
        dhcp_step = 1;
    case 1:
        len = build_dhcp_discover_packet((u8 *)lbl_805C1E00);
        dhcp_reply_received = 0;
        src[0] = 4;
        dst[0] = 4;
        src[1] = 0;
        dst[1] = -1;
        sock = dhcp_socket;
        len = len > 300 ? len : 300;
        rd.len = len;
        rd.buff = lbl_805C1E00;
        if (TUdpSocket__sub_80421BAC(sock, src, dst, 0x43, NULL, 1, &rd) < 0) {
            TLobby__sub_80421B3C(dhcp_socket);
            dhcp_socket = -1;
            if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                lbl_805D7B14 = TLobby__sub_804250A8(0);
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
            TLobby__sub_80421B3C(dhcp_socket);
            dhcp_socket = -1;
            if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
                lbl_805D7B14 = TLobby__sub_804250A8(0);
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

s32 TLobby__sub_8042455C(void *a) {
    u32 length;
    dhcp_error = 0;
    if (a == 0) {
        dhcp_error = 1;
        return -1;
    }
    length = NetStringLength((const char*)a);
    if ((u16)length < 0x20 && (u16)length != 0) {
        TLobby__sub_80425288(0x10, (u16)length, a);
        return 0;
    }
    dhcp_error = 1;
    return -1;
}



s32 TLobby__sub_804250A8(s32);
void TLobby__sub_80424CA8(void);
s32 TLobby__sub_804251C0(s16, void *);

typedef struct DhcpOption_804FD948 {
    s16 id;
    s16 present;
    s16 kind;
    s16 size;
    void *data;
} DhcpOption_804FD948;
DhcpOption_804FD948 lbl_804FD948[12] = {
    { 0x1, 0, 1, 4, &lbl_805D7B2C },
    { 0x2, 0, 1, 4, &lbl_805D7B30 },
    { 0x3, 0, 0, 0x100, lbl_805C2F94 },
    { 0x4, 0, 1, 4, &lbl_805D7B34 },
    { 0x5, 0, 1, 4, &lbl_805D7B38 },
    { 0x6, 0, 1, 4, &lbl_805D7B3C },
    { 0x7, 0, 1, 4, &dhcp_lease_time },
    { 0x8, 0, 1, 4, &dhcp_renewal_time },
    { 0x9, 0, 1, 4, &dhcp_rebinding_time },
    { 0xE, 0, 1, 4, dhcp_server_id },
    { 0xF, 0, 1, 4, &lbl_805D7B28 },
    { 0x10, 0, 0, 0x20, dhcp_hostname },
};
void TLobby__sub_803F97E8(s32);
s32 TLobby__sub_80424DCC(s16, s32, s32, void *, void *, void *, void *, s32);

s32 get_task_count(void) {
    return dhcp_state;
}

s32 TLobby__sub_80425288(s16, s16, void *);

void parse_dhcp_lease_times(u8 *packet) {
    u8 *arg0 = packet;
    s32 find_dhcp_option(u8 *p, u8 tag, u8 **out);
    u8 *p;
    s32 v;
    s32 w;

    if (find_dhcp_option(arg0, 0x33, &p) == 4) {
        NetMemcpy(&v, p, 4);
        w = v;
        TLobby__sub_80425288(7, 4, &w);
        get_time_seconds((s32 *)&dhcp_lease_start);
        dhcp_lease_expiry = dhcp_lease_start + dhcp_lease_time;
        if (find_dhcp_option(arg0, 0x3A, &p) == 4) {
            NetMemcpy(&v, p, 4);
            w = v;
            TLobby__sub_80425288(8, 4, &w);
        } else {
            TLobby__sub_80425288(8, 0, NULL);
            dhcp_renewal_time = dhcp_lease_time >> 1;
        }
        if (find_dhcp_option(arg0, 0x3B, &p) == 4) {
            NetMemcpy(&v, p, 4);
            w = v;
            TLobby__sub_80425288(9, 4, &w);
        } else {
            TLobby__sub_80425288(9, 0, NULL);
            dhcp_rebinding_time = (dhcp_lease_time >> 1) + (dhcp_lease_time >> 2) + (dhcp_lease_time >> 3);
        }
    } else {
        TLobby__sub_80425288(7, 0, NULL);
        dhcp_lease_time = -1;
    }
}

s32 TLobby__sub_8042474C(void *lease, void *renew, void *rebind) {
    dhcp_error = 0;
    if ((*(volatile s32 *)&dhcp_state) == 3 || (*(volatile s32 *)&dhcp_state) == 4 || (*(volatile s32 *)&dhcp_state) == 5) {
        if (TLobby__sub_804251C0(7, lease) != 0) {
            dhcp_error = 0x11;
        }
        if (TLobby__sub_804251C0(8, renew) != 0 && dhcp_error == 0) {
            dhcp_error = 0x12;
        }
        if (TLobby__sub_804251C0(9, rebind) != 0 && dhcp_error == 0) {
            dhcp_error = 0x13;
        }
        return 0;
    }
    dhcp_error = 2;
    return -1;
}

u8 find_dhcp_option(u8 *p, u8 tag, u8 **out) {
    u8 *base = p;
    u8 t;
    u8 len;
    p += 4;
    while ((s32)((u32)base - (u32)p) < 0x4D4) {
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

s32 TLobby__sub_8042489C(void *, void *out) {
    dhcp_error = 0;
    if ((*(volatile s32 *)&dhcp_state) != 3 && (*(volatile s32 *)&dhcp_state) != 4 && (*(volatile s32 *)&dhcp_state) != 5) {
        dhcp_error = 2;
        return -1;
    }
    if (TLobby__sub_804251C0(6, out) != 0) {
        dhcp_error = 0x10;
    }
    return 0;
}

s16 validate_slot_buffers(s32 arg0, void *arg1, void *arg2, void *arg3) {
    dhcp_error = 0;
    if ((*(volatile s32 *)&dhcp_state) != 3 && (*(volatile s32 *)&dhcp_state) != 4 && (*(volatile s32 *)&dhcp_state) != 5) {
        dhcp_error = 2;
        return -1;
    }
    if (TLobby__sub_804251C0(4, arg2) != 0) {
        dhcp_error = 0xE;
    }
    if (TLobby__sub_804251C0(5, arg3) != 0 && dhcp_error == 0) {
        dhcp_error = 0xF;
    }
    if (TLobby__sub_804251C0(3, arg1) != 0 && dhcp_error == 0) {
        dhcp_error = 0xD;
    }
    return 0;
}

#pragma push
#pragma opt_propagation off
s32 dhcp_handle_reply(s16 arg0, Arg_804249F0 *arg1) {
    s32 find_dhcp_option(u8 *p, u8 tag, u8 **out); /* declared s32 here; the definition returns u8 */
    G_804249F0 *g = (G_804249F0 *)lbl_805C1E00;
    Pkt_804249F0 *pk;
    u8 *q;
    u8 *p;

    if (arg0 == 0) {
        arg1->p = &g->pkt;
        return 0;
    }
    pk = &g->pkt;
    q = pk->opts;
    if (pk->f0 != 2 || pk->f1 != 1 || pk->f2 != 6) {
        return 0;
    }
    if (NetMemcmp(pk->f4, &lbl_805D7B50, 4) != 0) {
        return 0;
    }
    if (NetMemcmp(pk->f1C, lbl_805D7B1C, 6) != 0) {
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
            TLobby__sub_80425288(0xE, 4, p);
            lbl_805D7B28 = pk->f10;
            dhcp_reply_received = 1;
        }
        break;
    case 2:
        if (dhcp_reply_received == 0 && find_dhcp_option(q, 0x35, &p) == 1 && *p == 5) {
            NetMemcpy(g->buf, pk, arg1->len);
            dhcp_reply_received = 1;
        }
        break;
    case 4:
        if (dhcp_reply_received == 0 && find_dhcp_option(q, 0x35, &p) == 1 && *p == 5 &&
            lbl_805D7B28 == pk->f10) {
            NetMemcpy(g->buf, pk, arg1->len);
            dhcp_reply_received = 1;
        }
        break;
    case 5:
        if (dhcp_reply_received == 0 && find_dhcp_option(q, 0x35, &p) == 1 && *p == 5 &&
            lbl_805D7B28 == pk->f10) {
            NetMemcpy(g->buf, pk, arg1->len);
            dhcp_reply_received = 1;
        }
        break;
    }
    return 0;
}
#pragma pop

void TLobby__sub_80424CA8(void) {
    NetUnregisterTimer(TLobby__sub_80423298);
    if (dhcp_socket != -1) {
        TLobby__sub_80421B3C(dhcp_socket);
        dhcp_socket = -1;
    }
    lbl_805D7B14 = TLobby__sub_804250A8(0);
}

s32 TLobby__sub_80424CF4(void *, void *, s32 timeout) {
    s32 state;
    *(volatile s32 *)&dhcp_state = 6;
    *(volatile s32 *)&dhcp_step = 0;
    dhcp_max_retries = timeout;
    dhcp_error = 0;
    do {
        state = *(volatile s32 *)&dhcp_state;
        TLobby__sub_803F97E8(0x10);
    } while (state == 6);
    if (state != 0) {
        return -1;
    }
    return 0;
}

s32 TLobby__sub_80424D58(s16 a0, s32 a1, s32 a2, void *a3, void *a4, void *a5, void *a6, s32 a7) {
    s32 state;
    if (TLobby__sub_80424DCC(a0, a1, a2, a3, a4, a5, a6, a7) != 0) {
        return -1;
    }
    do {
        state = dhcp_state;
        TLobby__sub_803F97E8(0x10);
    } while (state == 1 || state == 2);
    if (state == -1) {
        return 1;
    }
    if (state == -2) {
        return -1;
    }
    return 0;
}

s32 TLobby__sub_80424DCC(s16, s32 a1, s32 a2, void *, void *a4, void *a5, void *a6, s32 a7) {
    dhcp_error = 0;
    if (*(volatile s32 *)&dhcp_state != 0) {
        dhcp_error = 2;
        return -1;
    }
    if (a4 == NULL || a5 == NULL || a6 == NULL) {
        dhcp_error = 1;
        return -1;
    }
    lbl_805D7B40 = a4;
    lbl_805D7B44 = a5;
    lbl_805D7B48 = a6;
    lbl_805D7B54 = a1;
    lbl_805D7B58 = a2;
    dhcp_max_retries = a7;
    *(volatile s32 *)&dhcp_state = 1;
    *(volatile s32 *)&dhcp_step = 0;
    return 0;
}

/* Clears the DHCP client state (lease timers, option table, hostname) and records the interface. */
static inline void dhcp_reset_state(s16 iface) {
    u32 i;

    dhcp_state = 0;
    dhcp_step = 0;
    dhcp_reply_received = 0;
    lbl_805D7B14 = TLobby__sub_804250A8(0);
    dhcp_socket = -1;
    for (i = 0; i < 12; i++) {
        lbl_804FD948[i].present = 0;
        NetMemset(lbl_804FD948[i].data, 0, lbl_804FD948[i].size);
    }
    lbl_805D7B40 = 0;
    lbl_805D7B44 = 0;
    lbl_805D7B48 = 0;
    lbl_805D7B4C = 0x63825363;
    lbl_805D7B50 = 0;
    lbl_805D7B54 = 0;
    lbl_805D7B58 = 0;
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
    if (TLobby__sub_8042315C(iface, addr) < 0) {
        return -1;
    }
    if (TLobby__sub_80422F70(iface, addr, 0x1C, lbl_805D7B1C) < 0) {
        TLobby__sub_80423064(iface, 4);
        return -1;
    }
    TLobby__sub_80423064(iface, 4);
    return 0;
}

s32 TLobby__sub_80424E44(s16 iface) {
    dhcp_reset_state(iface);
    if (dhcp_open_interface(dhcp_iface) != 0) {
        dhcp_error = 3;
        return -1;
    }
    NetRegisterTimer(50, 0, TLobby__sub_80423298);
    return 0;
}

s32 TLobby__sub_80424FE0(void) {
    s32 addr[7];
    u8 unused[4];
    if ((*(volatile s32 *)&dhcp_state) == 4 || (*(volatile s32 *)&dhcp_state) == 5 || (*(volatile s32 *)&dhcp_state) == 6) {
        if (dhcp_socket > -1) {
            TLobby__sub_80421B3C(dhcp_socket);
        }
        addr[0] = 4;
        addr[1] = 0;
        if ((dhcp_socket = TUdpSocket__sub_80421DEC(0, 0x44, addr, 0x43, 0, dhcp_handle_reply)) < 0) {
            if (*(volatile s32 *)&dhcp_state == 6) {
                lbl_805D7B14 = TLobby__sub_804250A8(0);
            }
            dhcp_error = 4;
            *(volatile s32 *)&dhcp_step = -1;
            *(volatile s32 *)&dhcp_state = -2;
            return -1;
        }
    }
    return 0;
}

#pragma dont_inline on
#pragma use_lmw_stmw off
s32 TLobby__sub_804250A8(s32 mode) {
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
            if (TLobby__sub_8042315C(dhcp_iface, &req) != 0) {
                TLobby__sub_80423064(dhcp_iface, 4);
                req2.a = 4;
                req2.b = 0;
                req2.c = -1;
                req2.d = -1;
                if (TLobby__sub_8042315C(dhcp_iface, &req2) != 0) {
                    dhcp_error = 3;
                    r = 0;
                    *(volatile s32 *)&dhcp_step = -1;
                    dhcp_state = -2;
                    return r;
                }
            }
            return 1;
        case 0:
            TLobby__sub_80423064(dhcp_iface, 4);
            return 0;
        }
    }
    return r;
}
#pragma use_lmw_stmw reset
#pragma dont_inline off

s32 TLobby__sub_804251C0(s16 id, void *out) {
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

s32 TLobby__sub_80425288(s16 id, s16 len, void *value) {
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
u8 lbl_805C2F94[0x100];
