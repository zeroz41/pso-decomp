#include "pso/network/NetworkRuntime.h"
#include "pso/network/UdpRuntime.h"
#include "pso/network/SocketEvents.h"
#include "types.h"
#include "pso/unk/TLobby.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct RecoveredGlobal_804217E4_lbl_805C1C50 {
    s32 value;
    u8 remaining[0xF4];
};

struct RecoveredGlobal_80421814_lbl_805C1C50 {
    s32 value;
    u8 remaining[0xF4];
};

struct RecoveredGlobal_80421844_lbl_805C1C50 {
    s32 value;
    u8 remaining[0xF4];
};

#include <stddef.h>
#include "pso/network/TUdpSocket.h"
struct Stack_80421AD8 {
    s16 sp1C;
    s16 sp1E;
    s32 sp20;
    s32 sp24;
    s32 sp28;
};

struct RecoveredGlobal_804218AC_lbl_805C1C50 {
    s32 value;
    u8 remaining[0xF4];
};

struct RecoveredGlobal_804219D0_lbl_805C1C50 {
    s32 value;
    u8 remaining[0xF4];
};

struct RecoveredGlobal_80421A50_lbl_805C1C50 {
    s32 value;
    u8 remaining[0xF4];
};

struct RecoveredGlobal_80422DE4_lbl_805C1C50 {
    s32 value;
    u8 remaining[0xF4];
};

struct G_80421B3C { s32 f0; };

struct G_8042298C { s32 f0; };

struct G_804228E8 { s32 f0; };

struct G_804229F8 { s32 f0; };

struct O_80421938 { u8 pad0[8]; s32 f8; s16 fC; };

struct Stack_80421938 { s16 flags; s16 len; s32 zero; u8 src[0x10]; u8 dst[0x10]; };

struct O_80421F10 { u8 pad0[8]; s32 f8; s16 fC; };

struct Stack_80421F10 { s16 flags; s16 len; s32 zero; u8 src[0x14]; u8 dst[0x14]; s16 port; };

struct S_804220A0 {
    u8 pad0[0x1FC]; s32 f1FC; u8 pad200[0xAC]; u8 flags; u8 count; s16 f2AE; u8 pad2B0[4]; u8 flags2; u8 pad2B5[0x544 - 0x2B5];
};

struct T_8042213C {
    u8 pad0[0xB]; u8 fB; u8 padC[0x2A4 - 0xC]; u8 f2A4; u8 pad2A5; s16 f2A6; u8 f2A8[0x544 - 0x2A8];
};

struct G_8042213C { s32 f0; };

struct IpAddr_80422B8C { u32 family; u8 a[0xC]; };

struct G_80422B8C { s32 f0; };

struct G_80422CFC { s32 f0; };

struct T_80422E30 {
    u8 pad0[0x2A4]; u8 fl1; u8 p1; s16 st1; s32 th1; u8 pad2AC[8]; u8 fl2; u8 p2; s16 st2; s32 th2; u8 pad2BC[0x544 - 0x2BC];
};

struct P_8042315C { s32 type; s32 a; s32 b; s32 c; s32 pad10; s16 n; s16 m; s32 d; s32 pad1C; };

struct T_80422368
{
  u8 pad0[0x200];
  s32 z;
  u8 padA[0x2A4 - 0x204];
  u8 fl;
  u8 pad1;
  s16 st;
  s32 th;
  u8 padE[0x544 - 0x2AC];
};

struct T_8042276C
{
  u8 pad0[0x1FC];
  s32 z;
  u8 padA[0x2B4 - 0x200];
  u8 fl;
  u8 pad1;
  s16 st;
  s32 th;
  u8 padE[0x544 - 0x2BC];
};

extern "C" {
s32 TLobby__sub_80409AA8(void);
s32 TLobby__sub_8040DD68(void);
s32 TLobby__sub_8040ED28(void);
s32 NetIPv6Shutdown(void);
s32 TLobby__sub_8041112C(void);
void NetIPv6ShutdownNeighborDiscovery(void);
s32 TLobby__sub_80418A7C(void);
void TLobby__sub_80419A00(void);
s32 TLobby__sub_80419A7C(void);
s32 TLobby__sub_8041A1D8(void);
extern RecoveredGlobal_804217E4_lbl_805C1C50 network_dispatch_state;
s32 TLobby__sub_804217E4(void);
s32 TLobby__sub_80421814(void);
s32 NetUnregisterTimer(void *);
s32 TLobby__sub_80421844(s32 arg0);
void TLobby__sub_80421FB8(void *, void *, void *);
s32 TLobby__sub_80421AD8(u8 *arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4);
s32 NetRegisterTimer(void *, int, void *);
s32 TLobby__sub_804218AC(s32 arg0, s32 arg1);
s32 TLobby__sub_8040F9CC(void *, void *, void *, int);
s32 TLobby__sub_804219D0(s32 arg0, s32 arg1, s32 arg2);
s32 TRKValidMemory32(void *, void *, void *, int, int, int);
s32 TLobby__sub_80421A50(s32 arg0, s32 arg1, s32 arg2);
s32 TLobby__sub_8041E780();
s32 tcp_create__Fv(void);
s32 TLobby__sub_80421B3C(s32 a);
s32 mark_connection_closed__6TLobbyFs(s32);
s32 tcp_delete__Fs(s32 a);
void TLobby__sub_80425288(s32, s32, void *);
extern volatile s32 dhcp_error;
s32 TLobby__sub_8042455C(void *a);
s16 TLobby__sub_8041DE1C(s16, s16, u32 *);
void TLobby__sub_8041E590(s16);
s32 get_tcp_stat__6TLobbyFsPsPsPlPl(int, void *, void *, void *, void *);
s16 validate_tcp_handle__6TLobbyFs(int);
s32 tcp_stat__FsPsPsPUlPUl(s32 a, s16 *b, s16 *c, u32 *d, u32 *e);
s16 tcp_get_socket_handle__6TLobbyFs(int);
s32 abort_tcp_connection__6TLobbyFs(int);
s32 tcp_abort__Fs(s32 a);
void NetMemcpy(void *_w0, void *_w1, int _w2);
s32 TLobby__sub_80421938(O_80421938 *o, void *src, void *dst, void *cb, s32 flags);
s32 TLobby__sub_80421F10(O_80421F10 *o, void *src, void *dst, s16 port, void *cb, s32 flags);
extern S_804220A0 *tcp_protocol_state[];
s32 complete_request_callback__6TLobbyFv(s32 idx_, void (*cb)(s16, s16, s32), s16 arg2, s32 *arg3);
void OSReport(const char *, ...);
s16 reset_socket_table__6TLobbyFv();
s16 TLobby__sub_80409AD8();
s16 init_ipv4_interfaces__6TLobbyFv();
s16 TLobby__sub_8040ED70();
s16 NetIPv6Init();
s16 TUdpSocket__sub_8041118C();
s16 TLobby__sub_80415690();
s16 NetIPv6InitNeighborDiscovery();
s16 init_packet_fragment_pools__6TLobbyFv();
s16 TLobby__sub_80419A34(int);
s16 NetInitializeDispatcher();
s16 NetTCPInit();
s16 init_ucb_entries__6TLobbyFv();
extern char lbl_804800F0[];
extern u32 TLobby__network_stack_init_count;
extern u8 *lbl_805E1188;
void NetStoreCurrentThread(s32 *arg0);
void NetSuspendCurrentThread(void);
void NetMemset(void *_w0, int _w1, int _w2);
s16 TLobby__sub_8041DBD4(int, void *, s16, void *);
s16 tcp_receive__FsPFss_vsPUc(s32 a, void *cb, s32 len, void *buf);
s32 TLobby__sub_8041E2EC(int, void *, void *);
s32 tcp_connect_start__6TLobbyFsls(int, void *, u16);
s32 tcp_connect__FsP10at_ip_addrUsP12at_ip_option(s32 a, IpAddr_80422B8C *addr, u16 port, IpAddr_80422B8C *opt);
s32 TLobby__sub_8041E5E4(int, void *, u16);
s32 tcp_bind__FsP10at_ip_addrUs(s32 a, void *addr, u16 port);
s16 TLobby__sub_8040F00C(s16, void *, int, void *);
s16 TLobby__sub_80412058(s16, void *, int, void *);
s16 TLobby__sub_80422F70(s16 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 OSDisableInterrupts();
s32 OSRestoreInterrupts(int);
s16 TLobby__sub_8040F1A0(s16);
s16 TLobby__sub_80412210(s16);
s16 TLobby__sub_80423064(s16 arg0, s32 arg1);
s16 TLobby__sub_8040F454(s32, s32, s32, s16);
s16 TLobby__sub_80412CA4(void *, s16, s16, s16, s32);
s16 TLobby__sub_8042315C(s16 arg0, P_8042315C *p);
u8 lbl_805C1E00[0x1194];
u8 lbl_805C2F94[0x100];
u8 dhcp_hostname[0x2C];
extern u8 lbl_805D7B1C[6];
extern u32 lbl_805D7B4C;
extern u32 lbl_805D7B50;
extern u32 lbl_805D7B58;
extern u32 dhcp_last_tick_ms;
extern volatile s32 dhcp_state;
extern u8 dhcp_server_id[4];
extern s32 lbl_805D7B28;
s32 set_slot_state_and_resume__6TLobbyFv(s32 idx, void (*cb)(s16, s16), s16 arg2);
s32 set_thread_state_and_resume__6TLobbyFv(s32 idx, void (*cb)(s16, s16), s16 arg2);
s32 TLobby::cleanup_subsystems() {
    TLobby__sub_80419A7C();
    TLobby__sub_80409AA8();
    NetIPv6ShutdownNeighborDiscovery();
    TLobby__sub_8041112C();
    TLobby__sub_8040ED28();
    NetIPv6Shutdown();
    TLobby__sub_8040DD68();
    TLobby__sub_80418A7C();
    TLobby::reset_stack_module();
    TLobby__sub_8041A1D8();
    TLobby::shutdown_network_handle();
    TLobby::reset_net_value();
    TLobby__sub_80419A00();
    return 0;
}
typedef char RecoveredGlobal_804217E4_lbl_805C1C50_size[sizeof(RecoveredGlobal_804217E4_lbl_805C1C50) == 0xF8 ? 1 : -1];

s16 TLobby::init_network_stack() {
    s16 var_r31;
    u32 temp_r3;
    if ((s32) *lbl_805E1188 != 0xA) {
        return -1;
    }
    if ((u32) TLobby__network_stack_init_count == 0U) {
        OSReport(lbl_804800F0);
    }
    temp_r3 = TLobby__network_stack_init_count;
    TLobby__network_stack_init_count = temp_r3 + 1;
    var_r31 = TLobby__sub_80419A34(temp_r3);
    if (var_r31 >= 0) {
        var_r31 = TLobby__sub_80415690();
        if (var_r31 >= 0) {
            var_r31 = reset_socket_table__6TLobbyFv();
            if (var_r31 >= 0) {
                var_r31 = NetTCPInit();
                if (var_r31 >= 0) {
                    var_r31 = init_ucb_entries__6TLobbyFv();
                    if (var_r31 >= 0) {
                        var_r31 = init_packet_fragment_pools__6TLobbyFv();
                        if (var_r31 >= 0) {
                            var_r31 = init_ipv4_interfaces__6TLobbyFv();
                            if (var_r31 >= 0) {
                                var_r31 = NetIPv6Init();
                                if (var_r31 >= 0) {
                                    var_r31 = TLobby__sub_8040ED70();
                                    if (var_r31 >= 0) {
                                        var_r31 = TUdpSocket__sub_8041118C();
                                        if (var_r31 >= 0) {
                                            var_r31 = NetIPv6InitNeighborDiscovery();
                                            if (var_r31 >= 0) {
                                                var_r31 = TLobby__sub_80409AD8();
                                                if (var_r31 >= 0) {
                                                    var_r31 = NetInitializeDispatcher();
                                                    if (var_r31 >= 0) {
                                                        return 0;
                                                    }
                                                    TLobby__sub_80409AA8();
                                                    goto block_19;
                                                }
block_19:
                                                NetIPv6ShutdownNeighborDiscovery();
                                                goto block_20;
                                            }
block_20:
                                            TLobby__sub_8041112C();
                                            goto block_21;
                                        }
block_21:
                                        TLobby__sub_8040ED28();
                                        goto block_22;
                                    }
block_22:
                                    NetIPv6Shutdown();
                                    goto block_23;
                                }
block_23:
                                TLobby__sub_8040DD68();
                                goto block_24;
                            }
block_24:
                            TLobby__sub_80418A7C();
                            goto block_25;
                        }
block_25:
                        TLobby::reset_stack_module();
                        goto block_26;
                    }
block_26:
                    TLobby__sub_8041A1D8();
                    goto block_27;
                }
block_27:
                TLobby::shutdown_network_handle();
                goto block_28;
            }
block_28:
            TLobby::reset_net_value();
            goto block_29;
        }
block_29:
        TLobby__sub_80419A00();
        goto block_30;
    }
block_30:
    return var_r31;
}

s32 TLobby__sub_804217E4(void) {
    TUdpSocket::unlock_mutex(network_dispatch_state.value);
    return 0;
}
typedef char RecoveredGlobal_80421814_lbl_805C1C50_size[sizeof(RecoveredGlobal_80421814_lbl_805C1C50) == 0xF8 ? 1 : -1];
s32 TLobby__sub_80421814(void) {
    TLobby::lock_mutex((int)((void *) ((*(RecoveredGlobal_80421814_lbl_805C1C50 *)&network_dispatch_state).value)));
    return 0;
}
typedef char RecoveredGlobal_80421844_lbl_805C1C50_size[sizeof(RecoveredGlobal_80421844_lbl_805C1C50) == 0xF8 ? 1 : -1];
s32 TLobby__sub_80421844(s32 arg0) {
    s32 temp_r31;
    if (arg0 == 0) {
        return -2;
    }
    TLobby::lock_mutex((int)((void *) ((*(RecoveredGlobal_80421844_lbl_805C1C50 *)&network_dispatch_state).value)));
    temp_r31 = NetUnregisterTimer((void *)arg0);
    TUdpSocket::unlock_mutex((int)((void *) ((*(RecoveredGlobal_80421844_lbl_805C1C50 *)&network_dispatch_state).value)));
    return temp_r31;
}

typedef char RecoveredGlobal_804218AC_lbl_805C1C50_size[sizeof(RecoveredGlobal_804218AC_lbl_805C1C50) == 0xF8 ? 1 : -1];
s32 TLobby__sub_804218AC(s32 arg0, s32 arg1) {
    s32 temp_r31;
    if (arg0 == 0) {
        return -2;
    }
    if (arg1 <= 0) {
        return -2;
    }
    TLobby::lock_mutex((int)((void *) ((*(RecoveredGlobal_804218AC_lbl_805C1C50 *)&network_dispatch_state).value)));
    temp_r31 = NetRegisterTimer((void *)arg1, 0, (void *)arg0);
    TUdpSocket::unlock_mutex((int)((void *) ((*(RecoveredGlobal_804218AC_lbl_805C1C50 *)&network_dispatch_state).value)));
    return temp_r31;
}

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_804219D0_lbl_805C1C50_size[sizeof(RecoveredGlobal_804219D0_lbl_805C1C50) == 0xF8 ? 1 : -1];

s32 TLobby__sub_80421938(O_80421938 *o, void *src, void *dst, void *cb, s32 flags) {
    Stack_80421938 s;
    s.flags = flags | 0xC00;
    s.len = o->f8 - o->fC;
    s.zero = 0;
    NetMemcpy(s.src, src, 0x10);
    NetMemcpy(s.dst, dst, 0x10);
    if (cb != NULL) {
        TLobby__sub_80421FB8(cb, &s, o);
    }
    return 0;
}

s32 TLobby__sub_804219D0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;
    TLobby::lock_mutex((int)((void *) ((*(RecoveredGlobal_804219D0_lbl_805C1C50 *)&network_dispatch_state).value)));
    temp_r31 = TLobby__sub_8040F9CC((void *)arg0, (void *)arg1, (void *)arg2, 0);
    TUdpSocket::unlock_mutex((int)((void *) ((*(RecoveredGlobal_804219D0_lbl_805C1C50 *)&network_dispatch_state).value)));
    return temp_r31;
}
#pragma pop

typedef char RecoveredGlobal_80421A50_lbl_805C1C50_size[sizeof(RecoveredGlobal_80421A50_lbl_805C1C50) == 0xF8 ? 1 : -1];
s32 TLobby__sub_80421A50(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_r31;
    TLobby::lock_mutex((int)((void *) ((*(RecoveredGlobal_80421A50_lbl_805C1C50 *)&network_dispatch_state).value)));
    temp_r31 = TRKValidMemory32((void *)arg0, (void *)arg1, (void *)arg2, 1, (int) (0U), (int) (0U));
    TUdpSocket::unlock_mutex((int)((void *) ((*(RecoveredGlobal_80421A50_lbl_805C1C50 *)&network_dispatch_state).value)));
    return temp_r31;
}

s32 TLobby__sub_80421AD8(u8 *arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4) {
    struct Fields_arg0 { u8 pad_0[8]; s32 field_8; s16 field_C; };
    typedef char sp1C_offset[(offsetof(Stack_80421AD8, sp1C) == 0x0) ? 1 : -1];
    typedef char sp1E_offset[(offsetof(Stack_80421AD8, sp1E) == 0x2) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_80421AD8, sp20) == 0x4) ? 1 : -1];
    typedef char sp24_offset[(offsetof(Stack_80421AD8, sp24) == 0x8) ? 1 : -1];
    typedef char sp28_offset[(offsetof(Stack_80421AD8, sp28) == 0xC) ? 1 : -1];
    Stack_80421AD8 stack;
    stack.sp1C = arg4 | 0x800;
    stack.sp1E = ((Fields_arg0*)arg0)->field_8 - ((Fields_arg0*)arg0)->field_C;
    stack.sp20 = 0;
    stack.sp24 = arg1;
    stack.sp28 = arg2;
    if (arg3 != 0U) {
        TLobby__sub_80421FB8((void *)arg3, &stack.sp1C, (void *)arg0);
    }
    return 0;
}
typedef char RecoveredGlobal_80422DE4_lbl_805C1C50_size[sizeof(RecoveredGlobal_80422DE4_lbl_805C1C50) == 0xF8 ? 1 : -1];

s32 TLobby__sub_80421B3C(s32 a) {
    s32 r;
    G_80421B3C *g;
    s16 m;
    if ((a & 0xC00) != 0x400) { return -4; }
    g = ((G_80421B3C *)&network_dispatch_state);
    m = a & 0xFFFFF3FF;
    TLobby::lock_mutex((int)((void *)g->f0));
    r = NetUdpClose(m);
    TUdpSocket::unlock_mutex((int)((void *)g->f0));
    return r;
}

struct UdpItem_80421BAC { s16 len; u8 pad2[2]; u8 data[8]; };
struct UdpPkt_80421BAC { u8 pad0[4]; s32 count; u32 len; UdpItem_80421BAC items[4]; };
struct UdpBuf_80421BAC { s16 len; u8 pad2[2]; s32 data; };
s16 udp_sendto__6TLobbyFsPvPvPvUsi(s32 id, void *pkt, void *src, void *dst, u16 port, s32 opt);

s16 TUdpSocket__sub_80421BAC(s32 h, u32 *src, u32 *dst, u16 port, u32 *opt, s8 n, UdpBuf_80421BAC *bufs) {
    u32 any_addr[5];
    u32 any_opt[4];
    u16 i;
    UdpPkt_80421BAC *pkt;
    s16 r;
    if ((h & 0xC00) != 0x400) {
        return -4;
    }
    h = h & 0xFFFFF3FF;
    NetMemset(any_addr, 0, 0x14);
    if (dst != NULL) {
        if (*dst == 0) {
            return -2;
        }
    } else {
        dst = any_addr;
    }
    if (src == NULL) {
        src = any_addr;
    }
    if (opt != NULL && *opt != 0) {
        if (*opt != *dst) {
            return -2;
        }
    } else {
        NetMemset(any_opt, 0, 0x10);
        opt = any_opt;
    }
    TLobby::lock_mutex(network_dispatch_state.value);
    if (n > 3) {
        TUdpSocket::unlock_mutex(network_dispatch_state.value);
        return -2;
    }
    pkt = (UdpPkt_80421BAC *)TLobby::alloc_free_entry();
    if (pkt == NULL) {
        TUdpSocket::unlock_mutex(network_dispatch_state.value);
        return -0x101;
    }
    pkt->count = 0;
    pkt->len = 0;
    for (i = n; i != 0; i--) {
        if (bufs[i - 1].len < 0) {
            ((TUdpSocket *)pkt)->release_entry();
            TUdpSocket::unlock_mutex(network_dispatch_state.value);
            return -2;
        }
        pkt->len += bufs[i - 1].len;
        pkt->items[pkt->count].len = bufs[i - 1].len;
        ((TLobby *)pkt->items[pkt->count].data)->init_packet_header(bufs[i - 1].data);
        pkt->count++;
    }
    if (pkt->len > 0x7FE3) {
        ((TUdpSocket *)pkt)->release_entry();
        TUdpSocket::unlock_mutex(network_dispatch_state.value);
        return -2;
    }
    if (pkt->len == 0) {
        ((TUdpSocket *)pkt)->release_entry();
        TUdpSocket::unlock_mutex(network_dispatch_state.value);
        return 0;
    }
    r = udp_sendto__6TLobbyFsPvPvPvUsi(h, pkt, src, dst, port, (s32)opt);
    ((TUdpSocket *)pkt)->release_entry();
    TUdpSocket::unlock_mutex(network_dispatch_state.value);
    return r;
}

s16 TUdpSocket__sub_80421DEC(void *src, s32 sport, void *dst, s32 dport, s32 arg4, s32 (*cb)(s16, void *)) {
    u8 any[0x14];
    s16 h;
    s16 r;
    NetMemset(any, 0, 0x14);
    if (cb == NULL) {
        return -2;
    }
    if (src == NULL) {
        src = any;
    }
    if (dst == NULL) {
        dst = any;
    }
    TLobby::lock_mutex(network_dispatch_state.value);
    h = NetUdpCreate();
    if (h < 0) {
        TUdpSocket::unlock_mutex(network_dispatch_state.value);
        return h;
    }
    r = NetUdpBind(h, (NetworkAddress*)src, sport);
    if (r < 0) {
        NetUdpClose(h);
        TUdpSocket::unlock_mutex(network_dispatch_state.value);
        return r;
    }
    r = NetUdpConnect(h, (NetworkAddress*)dst, dport, arg4, (u32)cb);
    if (r < 0) {
        NetUdpClose(h);
        TUdpSocket::unlock_mutex(network_dispatch_state.value);
        return r;
    }
    h |= 0x400;
    TUdpSocket::unlock_mutex(network_dispatch_state.value);
    return h;
}

s32 TLobby__sub_80421F10(O_80421F10 *o, void *src, void *dst, s16 port, void *cb, s32 flags) {
    Stack_80421F10 s;
    s.flags = flags | 0x400;
    s.len = o->f8 - o->fC;
    s.zero = 0;
    NetMemcpy(s.src, src, 0x14);
    NetMemcpy(s.dst, dst, 0x14);
    s.port = port;
    if (cb != NULL) {
        TLobby__sub_80421FB8(cb, &s, o);
    }
    return 0;
}

struct PktSeg_80421FB8 { s16 len; u8 pad2[2]; u8 data[8]; };
struct PktHdr_80421FB8 { s16 flags; s16 len; u8 *buf; };
struct PktBuf_80421FB8 { u8 pad0[0xC]; PktSeg_80421FB8 seg[8]; };
typedef s16 (*PktCb_80421FB8)(s32, PktHdr_80421FB8 *);
void TLobby__sub_80406FD8(void *, void *, s32);
void TLobby__sub_80406EB8(void *, u32);

void TLobby__sub_80421FB8(void *cb, void *hdr_, void *o_) {
    s32 i;
    u8 *buf;
    s16 len;
    s32 pkt[2];
    s16 chunk;
    PktHdr_80421FB8 *hdr;
    PktBuf_80421FB8 *o;
    hdr = (PktHdr_80421FB8 *)hdr_;
    o = (PktBuf_80421FB8 *)o_;
    len = hdr->len;
    if (((PktCb_80421FB8)cb)(0, hdr) == 0) {
        if (hdr->len >= len) {
            hdr->len = len;
        }
        len = hdr->len;
        if (len == 0 || hdr->buf == NULL) {
            return;
        }
        buf = hdr->buf;
        ((TLobby *)pkt)->init_packet_header((s32)buf);
        for (i = 1; len > 0; i++) {
            if (len > o->seg[i].len) {
                chunk = o->seg[i].len;
            } else {
                chunk = len;
            }
            TLobby__sub_80406FD8(pkt, o->seg[i].data, chunk);
            TLobby__sub_80406EB8(pkt, chunk);
            len -= chunk;
        }
        ((PktCb_80421FB8)cb)(1, hdr);
    }
}

s32 complete_request_callback__6TLobbyFv(s32 idx_, void (*cb)(s16, s16, s32), s16 arg2, s32 *arg3) {
    s16 idx = idx_;
    S_804220A0 *s = tcp_protocol_state[0];
    s += idx;
    if (cb != NULL && !(s->flags & 8)) {
        cb(arg2, idx, *arg3);
    } else if (!(s->flags2 & 4)) {
        s->f2AE = arg2;
        s->flags2 |= 4;
        s->f1FC = 0;
    }
    s->count--;
    return 0;
}

s16 tcp_receive__FsPFss_vsPUc(s32 a, void *cb, s32 len, void *buf) {
    u8 hdr[8];
    s16 r;
    G_8042213C *g;
    T_8042213C *s;
    if (a & 0xC00) {
        return -4;
    }
    g = (G_8042213C *)&network_dispatch_state;
    a = a & 0xFFFFF3FF;
    TLobby::lock_mutex((int)((void *)g->f0));
    if (validate_tcp_handle__6TLobbyFs(a) < 0) {
        TUdpSocket::unlock_mutex((int)((void *)g->f0));
        return -4;
    }
    if (tcp_get_socket_handle__6TLobbyFs(a) == 1) {
        TUdpSocket::unlock_mutex((int)((void *)g->f0));
        return -9;
    }
    s = (T_8042213C *)tcp_protocol_state[0];
    s += (s16)a;
    if (s->f2A4 & 3) {
        TUdpSocket::unlock_mutex((int)((void *)g->f0));
        return -9;
    }
    ((TLobby *)hdr)->init_packet_header((s32)buf);
    NetMemset(&s->f2A4, 0, 8);
    s->f2A4 |= 1;
    if (s->fB & 0x40) {
        s->f2A4 |= 8;
        r = TLobby__sub_8041DBD4(a, hdr, len, cb);
        s->f2A4 &= ~8;
    } else {
        r = TLobby__sub_8041DBD4(a, hdr, len, cb);
    }
    if (r < 0) {
        s->f2A4 &= ~1;
        TUdpSocket::unlock_mutex((int)((void *)network_dispatch_state.value));
        return r;
    }
    if (cb != NULL && (!(s->fB & 0x40) || !(s->f2A4 & 4))) {
        TUdpSocket::unlock_mutex((int)((void *)network_dispatch_state.value));
        return -1;
    }
    if (s->f2A4 & 4) {
        r = s->f2A6;
        TUdpSocket::unlock_mutex((int)((void *)network_dispatch_state.value));
        return r;
    }
    NetStoreCurrentThread((s32 *)s->f2A8);
    s->f2A4 |= 2;
    TUdpSocket::unlock_mutex((int)((void *)network_dispatch_state.value));
    NetSuspendCurrentThread();
    TLobby::lock_mutex((int)((void *)network_dispatch_state.value));
    s->f2A4 &= ~2;
    r = s->f2A6;
    s->f2A4 &= ~1;
    TUdpSocket::unlock_mutex((int)((void *)network_dispatch_state.value));
    return r;
}

typedef struct S_804220A0 S_804220A0;
typedef struct T_80422368 T_80422368;
s32 set_slot_state_and_resume__6TLobbyFv(s32 idx, void (*cb)(s16, s16), s16 arg2) {
  T_80422368 *s = (T_80422368 *) tcp_protocol_state[0];
  s16 new_var;
  s += (s16) idx;
  if ((cb != 0) && (!(s->fl & 8)))
  {
    new_var = (s16) idx;
    cb(arg2, new_var);
    s->st = arg2;
    s->fl &= ~1;
    s->fl |= 4;
    s->z = 0;
  }
  else
    if ((s->fl & 1) && (!(s->fl & 4)))
  {
    if (s->fl & 2)
    {
      TLobby::resume_thread(s->th);
    }
    s->st = arg2;
    s->fl &= ~1;
    s->fl |= 4;
    s->z = 0;
  }
  return 0;
}

typedef struct T_8042276C T_8042276C;
s32 set_thread_state_and_resume__6TLobbyFv(s32 idx, void (*cb)(s16, s16), s16 arg2) {
  T_8042276C *s = (T_8042276C *) tcp_protocol_state[0];
  s16 new_var;
  s += (s16) idx;
  if ((cb != 0) && (!(s->fl & 8)))
  {
    new_var = (s16) idx;
    cb(arg2, new_var);
    s->st = arg2;
    s->fl &= ~1;
    s->fl |= 4;
    s->z = 0;
  }
  else
    if ((s->fl & 1) && (!(s->fl & 4)))
  {
    if (s->fl & 2)
    {
      TLobby::resume_thread(s->th);
    }
    s->st = arg2;
    s->fl &= ~1;
    s->fl |= 4;
    s->z = 0;
  }
  return 0;
}

}

struct send_buffs {
    s16 len;
    u8 *buff;
};

struct TcpSendItem_80422448 { s16 len; u8 pad2[2]; u8 data[8]; };
struct TcpSendPkt_80422448 { u8 pad0[4]; s32 count; u32 len; TcpSendItem_80422448 items[4]; };

struct T_80422448 {
    u8 pad0[0xB]; u8 fB; u8 padC[0x2AD - 0xC]; u8 f2AD; u8 pad2AE[0x2B4 - 0x2AE];
    u8 f2B4; u8 pad2B5; s16 f2B6; s32 f2B8[(0x544 - 0x2B8) / 4];
};

extern "C" s16 tcp_start_send(s32 nh, TcpSendPkt_80422448 *pkt, void (*notify)(s16, s16), s32 arg3);

extern "C" s16 tcp_send__FsPFss_vcP10send_buffs(s32 nh, void (*notify)(s16, s16), char bufnum, send_buffs *sb);
s16 tcp_send__FsPFss_vcP10send_buffs(s32 nh, void (*notify)(s16, s16), char bufnum, send_buffs *sb) {
    u16 i;
    T_80422448 *s;
    TcpSendPkt_80422448 *pkt;
    s32 j;
    G_8042213C *g;
    s16 r;

    i = bufnum;
    if (bufnum > 3) {
        return -2;
    }
    if (nh & 0xC00) {
        return -4;
    }
    g = (G_8042213C *)&network_dispatch_state;
    nh = nh & 0xFFFFF3FF;
    TLobby::lock_mutex(g->f0);
    if (validate_tcp_handle__6TLobbyFs(nh) < 0) {
        TUdpSocket::unlock_mutex(g->f0);
        return -4;
    }
    r = tcp_get_socket_handle__6TLobbyFs(nh);
    if (r == -1 || r == 1) {
        TUdpSocket::unlock_mutex(network_dispatch_state.value);
        return -9;
    }
    s = (T_80422448 *)tcp_protocol_state[0];
    s += (s16)nh;
    if ((s->f2B4 & 3) || s->f2AD != 0) {
        TUdpSocket::unlock_mutex(network_dispatch_state.value);
        return -9;
    }
    pkt = (TcpSendPkt_80422448 *)TLobby::alloc_free_entry();
    if (pkt == NULL) {
        TUdpSocket::unlock_mutex(g->f0);
        return -0x101;
    }
    pkt->count = i;
    pkt->len = j = 0;
    for (; i != 0; j++) {
        i--;
        if (sb[i].len < 0) {
            ((TUdpSocket *)pkt)->release_entry();
            TUdpSocket::unlock_mutex(network_dispatch_state.value);
            return -2;
        }
        ((TLobby *)pkt->items[j].data)->init_packet_header((s32)sb[i].buff);
        pkt->items[j].len = sb[i].len;
        pkt->len += pkt->items[j].len;
    }
    if (pkt->len == 0) {
        ((TUdpSocket *)pkt)->release_entry();
        TUdpSocket::unlock_mutex(network_dispatch_state.value);
        return -2;
    }
    NetMemset(&s->f2B4, 0, 8);
    s->f2B4 |= 1;
    if (s->fB & 0x40) {
        s->f2B4 |= 8;
        r = tcp_start_send(nh, pkt, notify, 0);
        s->f2B4 &= ~8;
    } else {
        r = tcp_start_send(nh, pkt, notify, 0);
    }
    ((TUdpSocket *)pkt)->release_entry();
    if (r < 0) {
        s->f2B4 &= ~1;
        TUdpSocket::unlock_mutex(network_dispatch_state.value);
        return r;
    }
    if (notify != NULL && (!(s->fB & 0x40) || !(s->f2B4 & 4))) {
        TUdpSocket::unlock_mutex(network_dispatch_state.value);
        return -1;
    }
    if (s->f2B4 & 4) {
        r = s->f2B6;
        TUdpSocket::unlock_mutex(network_dispatch_state.value);
        return r;
    }
    NetStoreCurrentThread(s->f2B8);
    s->f2B4 |= 2;
    TUdpSocket::unlock_mutex(network_dispatch_state.value);
    NetSuspendCurrentThread();
    TLobby::lock_mutex(network_dispatch_state.value);
    s->f2B4 &= ~2;
    r = s->f2B6;
    s->f2B4 &= ~1;
    TUdpSocket::unlock_mutex(network_dispatch_state.value);
    return r;
}

s16 tcp_get_opt(s16 nh, s16 type, u32 *opt) {
    s16 r;
    if (nh & 0xC00) {
        return -2;
    }
    nh &= 0xFFFFF3FF;
    if (opt == NULL) {
        return -2;
    }
    TLobby::lock_mutex(network_dispatch_state.value);
    r = TLobby__sub_8041DE1C(nh, type, opt);
    TUdpSocket::unlock_mutex(network_dispatch_state.value);
    return r;
}

extern "C" {
s32 tcp_stat__FsPsPsPUlPUl(s32 a, s16 *b, s16 *c, u32 *d, u32 *e) {
    s32 r;
    G_804228E8 *g;
    if (a & 0xC00) { return -4; }
    g = ((G_804228E8 *)&network_dispatch_state);
    a = a & 0xFFFFF3FF;
    TLobby::lock_mutex((int)((void *)g->f0));
    if (validate_tcp_handle__6TLobbyFs(a) < 0) {
        TUdpSocket::unlock_mutex((int)((void *)g->f0));
        return -4;
    }
    r = get_tcp_stat__6TLobbyFsPsPsPlPl(a, b, c, d, e);
    TUdpSocket::unlock_mutex((int)((void *)g->f0));
    return r;
}

s32 tcp_delete__Fs(s32 a) {
    s32 r;
    G_8042298C *g;
    s32 m;
    if (a & 0xC00) { return -4; }
    g = ((G_8042298C *)&network_dispatch_state);
    m = a & 0xFFFFF3FF;
    TLobby::lock_mutex((int)((void *)g->f0));
    r = mark_connection_closed__6TLobbyFs(m);
    TUdpSocket::unlock_mutex((int)((void *)g->f0));
    return r;
}

s32 tcp_abort__Fs(s32 a) {
    s32 r;
    G_804229F8 *g;
    s32 m;
    s16 st;
    if (a & 0xC00) { return -4; }
    g = ((G_804229F8 *)&network_dispatch_state);
    m = a & 0xFFFFF3FF;
    TLobby::lock_mutex((int)((void *)g->f0));
    if (validate_tcp_handle__6TLobbyFs(m) < 0) {
        TUdpSocket::unlock_mutex((int)((void *)g->f0));
        return -4;
    }
    st = tcp_get_socket_handle__6TLobbyFs(m);
    if (st == -1 || st == 1) {
        TUdpSocket::unlock_mutex((int)((void *)network_dispatch_state.value));
        return -9;
    }
    r = abort_tcp_connection__6TLobbyFs(m);
    TUdpSocket::unlock_mutex((int)((void *)g->f0));
    return r;
}

struct T_80422AB8 {
    u8 pad0[0x2BC]; u8 fl; u8 pad2BD; s16 st; s32 th; u8 pad2C4[4]; s32 z; u8 pad2CC[0x544 - 0x2CC];
};

s32 TLobby__sub_80422AB8(s32 idx, void (*cb)(s16, s16, s32, s32), s16 code, s32 arg3, s32 arg4, s32 arg5) {
    T_80422AB8 *s = (T_80422AB8 *)tcp_protocol_state[0];
    s16 i2;
    s16 v;
    s += (s16)idx;
    if (cb != NULL && !(s->fl & 8)) {
        i2 = (s16)idx;
        if (code >= 0) {
            v = (s32)code;
            TLobby__sub_8041E590(code);
        } else {
            v = code;
        }
        cb(v, i2, arg3, arg5);
        s->z = 0;
    } else {
        s->st = code;
        if (s->fl & 2) {
            TLobby::resume_thread(s->th);
        }
    }
    s->fl &= ~1;
    s->fl |= 4;
    return 0;
}

s32 tcp_connect__FsP10at_ip_addrUsP12at_ip_option(s32 a, IpAddr_80422B8C *addr, u16 port, IpAddr_80422B8C *opt) {
    IpAddr_80422B8C tmp;
    s32 r;
    G_80422B8C *g;
    void *p;
    if (a & 0xC00) {
        return -4;
    }
    a = a & 0xFFFFF3FF;
    if (addr != NULL) {
        if (addr->family == 0) {
            return -2;
        }
    } else {
        return -2;
    }
    NetMemset(&tmp, 0, 0x10);
    if (opt != NULL && opt->family != 0) {
        if (opt->family != addr->family) {
            return -2;
        }
    } else {
        opt = &tmp;
    }
    switch (addr->family) {
    case 4:
        p = opt->a;
        opt = (IpAddr_80422B8C *)tmp.a;
        break;
    case 6:
        p = tmp.a;
        opt = (IpAddr_80422B8C *)opt->a;
        break;
    case 5:
    default:
        return -2;
    }
    g = (G_80422B8C *)&network_dispatch_state;
    TLobby::lock_mutex((int)((void *)g->f0));
    if (validate_tcp_handle__6TLobbyFs(a) < 0) {
        TUdpSocket::unlock_mutex((int)((void *)g->f0));
        return -4;
    }
    if (tcp_get_socket_handle__6TLobbyFs(a) != 0) {
        TUdpSocket::unlock_mutex((int)((void *)g->f0));
        return -9;
    }
    TLobby__sub_8041E2EC(a, p, opt);
    r = tcp_connect_start__6TLobbyFsls(a, addr, port);
    TUdpSocket::unlock_mutex((int)((void *)g->f0));
    return r;
}

s32 tcp_bind__FsP10at_ip_addrUs(s32 a, void *addr, u16 port) {
    u8 tmp[0x14];
    s32 r;
    G_80422CFC *g;
    if (a & 0xC00) { return -4; }
    a = a & 0xFFFFF3FF;
    if (addr == NULL) {
        NetMemset(tmp, 0, 0x14);
        addr = tmp;
    }
    g = ((G_80422CFC *)&network_dispatch_state);
    TLobby::lock_mutex((int)((void *)g->f0));
    if (validate_tcp_handle__6TLobbyFs(a) < 0) {
        TUdpSocket::unlock_mutex((int)((void *)g->f0));
        return -4;
    }
    if (tcp_get_socket_handle__6TLobbyFs(a) != 0) {
        TUdpSocket::unlock_mutex((int)((void *)g->f0));
        return -9;
    }
    r = TLobby__sub_8041E5E4(a, addr, port);
    TUdpSocket::unlock_mutex((int)((void *)g->f0));
    return r;
}

s32 tcp_create__Fv(void) {
    s32 temp_r31;
    TLobby::lock_mutex((int)((void *) ((*(RecoveredGlobal_80422DE4_lbl_805C1C50 *)&network_dispatch_state).value)));
    temp_r31 = TLobby__sub_8041E780();
    TUdpSocket::unlock_mutex((int)((void *) ((*(RecoveredGlobal_80422DE4_lbl_805C1C50 *)&network_dispatch_state).value)));
    return temp_r31;
}

void NetDispatchSocketEvent(s16 v, s32 cb_, s32 type, s16 code) {
    T_80422E30 *s;
    switch ((s16)type) {
    case 1:
        v |= 0x800;
        break;
    case 6:
        v |= 0xC00;
        break;
    case 2:
        v |= 0x400;
        break;
    case 3:
        if (TLobby::validate_tcp_handle(v) < 0) {
            return;
        }
        s = (T_80422E30 *)tcp_protocol_state[0];
        s += (s16)v;
        if ((u16)(code - 10) <= 1 || code == 4) {
            if (s->fl2 & 2) {
                s->st2 = -5;
                s->fl2 &= ~1;
                TLobby::resume_thread(s->th2);
            }
            if (s->fl1 & 2) {
                s->st1 = -5;
                s->fl1 &= ~1;
                TLobby::resume_thread(s->th1);
            }
        }
        break;
    default:
        return;
    }
    if ((void *)cb_ != NULL) {
        ((void (*)(s16, s16))cb_)(v, code);
    }
}

s16 TLobby__sub_80422F70(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 sp18;
    s16 temp_r3_2;
    s16 temp_r3;
    s16 var_r29;
    if (arg0 < 0) {
        return -2;
    }
    var_r29 = 0;
    TLobby::lock_mutex(network_dispatch_state.value);
    ((TLobby *)(&sp18))->init_packet_header(arg1);
    temp_r3_2 = TLobby__sub_8040F00C(arg0, &sp18, (int)arg2, (void *)arg3);
    if (temp_r3_2 > 0) {
        var_r29 = temp_r3_2;
        arg2 -= temp_r3_2 * 0x1C;
    }
    temp_r3 = TLobby__sub_80412058(arg0, &sp18, (int)arg2, (void *)arg3);
    if (temp_r3 > 0) {
        var_r29 += temp_r3;
    }
    TUdpSocket::unlock_mutex(network_dispatch_state.value);
    if (var_r29 == 0) {
        if (temp_r3_2 < temp_r3) {
            return temp_r3_2;
        }
        return temp_r3;
    }
    return var_r29;
}

s16 TLobby__sub_80423064(s16 idx, s32 arg1) {
    s16 temp_r3;
    s16 temp_r3_2;
    s16 var_r31;
    s32 level;
    if (idx < 0) {
        return -2;
    }
    TLobby::lock_mutex(network_dispatch_state.value);
    level = OSDisableInterrupts();
    switch (arg1) {
    case 0:
        var_r31 = 0;
        temp_r3 = TLobby__sub_8040F1A0(idx);
        if (temp_r3 < 0) {
            var_r31 = temp_r3;
        }
        temp_r3_2 = TLobby__sub_80412210(idx);
        if (temp_r3_2 < 0) {
            var_r31 = temp_r3_2;
        }
        break;
    case 4:
        var_r31 = TLobby__sub_8040F1A0(idx);
        break;
    case 6:
        var_r31 = TLobby__sub_80412210(idx);
        break;
    default:
        var_r31 = -2;
        break;
    }
    OSRestoreInterrupts(level);
    TUdpSocket::unlock_mutex(network_dispatch_state.value);
    return var_r31;
}

s16 TLobby__sub_8042315C(s16 arg0, P_8042315C *p) {
    s16 r;
    s32 intr;
    if (arg0 < 0) {
        return -2;
    }
    TLobby::lock_mutex(network_dispatch_state.value);
    intr = OSDisableInterrupts();
    switch (p->type) {
    case 4:
        r = TLobby__sub_8040F454(p->a, p->b, p->c, arg0);
        break;
    case 6:
        if (p->n < 0 || p->n > 0x80) {
            r = -2;
        } else {
            r = TLobby__sub_80412CA4(&p->a, p->n, p->m, arg0, p->d);
        }
        break;
    case 5:
    default:
        r = -2;
        break;
    }
    OSRestoreInterrupts(intr);
    TUdpSocket::unlock_mutex(network_dispatch_state.value);
    return r;
}

s32 TLobby__sub_8042325C(s32 a, s32 b, s32 c, s32 (*fn)(s32, s32, s32)) {
    s32 r = 0;
    if (fn != NULL) {
        r = fn(a, b, c);
    }
    return r;
}

// DHCP client state (names inferred): dhcp_state 1/2/6 dispatch to the discover/request/reboot steps, 3/4/5 =
// bound/renewing/rebinding; dhcp_socket is the UDP 68->67 socket; dhcp_elapsed_ms/dhcp_lease_elapsed count the
// lease clock against dhcp_lease_time/dhcp_renewal_time/dhcp_rebinding_time.
extern volatile s32 dhcp_step;
extern s16 dhcp_socket;
extern u32 dhcp_elapsed_ms;
extern u32 dhcp_lease_time;
extern u32 dhcp_renewal_time;
extern u32 dhcp_rebinding_time;
extern u32 dhcp_lease_elapsed;
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
    TLobby::get_time_ms(&now);
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

extern s32 lbl_805D7B2C;
extern s32 lbl_805D7B30;
extern s32 *lbl_805D7B40;
extern s32 *lbl_805D7B44;
extern s32 *lbl_805D7B48;
extern s32 lbl_805D7B80;
s32 find_dhcp_option__6TLobbyFPvUcPv(u8 *p, u8 tag, u8 **out);

s32 TLobby__sub_80423440(u8 *pkt) {
    u8 *opts = pkt + 0xEC;
    u8 *p;
    s32 net;
    s32 w;
    u32 mask;
    u32 n;
    TLobby__sub_80425288(0xF, 4, pkt + 0x10);
    lbl_805D7B80 = 0;
    if (find_dhcp_option__6TLobbyFPvUcPv(opts, 1, &p) == 4) {
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
    if (find_dhcp_option__6TLobbyFPvUcPv(opts, 0x1C, &p) == 4) {
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
    ((TLobby *)opts)->parse_dhcp_lease_times();
    n = find_dhcp_option__6TLobbyFPvUcPv(opts, 0xF, &p);
    if (n != 0) {
        TLobby__sub_80425288(3, (s16)n, p);
    } else {
        TLobby__sub_80425288(3, 1, NULL);
    }
    n = find_dhcp_option__6TLobbyFPvUcPv(opts, 6, &p);
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
    n = find_dhcp_option__6TLobbyFPvUcPv(opts, 3, &p);
    if (n >= 4 && (n & 3) == 0) {
        TLobby__sub_80425288(6, 4, p);
    } else {
        TLobby__sub_80425288(6, 4, NULL);
    }
    return 0;
}

s32 TLobby::build_dhcp_release() {
    s32 m;
    u8 *p;
    u16 len;
    NetMemset(this, 0, 0x5DC);
    ((u8 *)this)[0] = 1;
    ((u8 *)this)[1] = 1;
    ((u8 *)this)[2] = 6;
    ((u8 *)this)[3] = 0;
    TLobby::get_time_ms((s32 *)&dhcp_last_tick_ms);
    lbl_805D7B50 = dhcp_last_tick_ms;
    NetMemcpy(((u8 *)this) + 4, &lbl_805D7B50, 4);
    *(s32 *)(((u8 *)this) + 0xC) = lbl_805D7B28;
    NetMemcpy(((u8 *)this) + 0x1C, lbl_805D7B1C, 6);
    p = ((u8 *)this) + 0xEC;
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
    return p - ((u8 *)this);
}

s32 TLobby::dhcp_build_packet() {
    s32 m;
    u8 *p;
    u16 len;
    u32 tmp;
    NetMemset(this, 0, 0x5DC);
    ((u8 *)this)[0] = 1;
    ((u8 *)this)[1] = 1;
    ((u8 *)this)[2] = 6;
    ((u8 *)this)[3] = 0;
    NetMemcpy(((u8 *)this) + 4, &lbl_805D7B50, 4);
    *(u16 *)(((u8 *)this) + 0xA) = 0;
    if (dhcp_state == 4 || dhcp_state == 5) {
        *(s32 *)(((u8 *)this) + 0xC) = lbl_805D7B28;
    }
    NetMemcpy(((u8 *)this) + 0x1C, lbl_805D7B1C, 6);
    p = ((u8 *)this) + 0xEC;
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
    return p - ((u8 *)this);
}

s32 TLobby::build_dhcp_discover_packet() {
    u32 spC;
    u8 *p;
    u16 len;
    s32 n;
    NetMemset(this, 0, 0x5DC);
    ((u8 *)this)[0] = 1;
    ((u8 *)this)[1] = 1;
    ((u8 *)this)[2] = 6;
    ((u8 *)this)[3] = 0;
    TLobby::get_time_ms((s32 *)&dhcp_last_tick_ms);
    lbl_805D7B50 = dhcp_last_tick_ms;
    NetMemcpy(((u8 *)this) + 4, &lbl_805D7B50, 4);
    *(s16 *)(((u8 *)this) + 0xA) = 0;
    NetMemcpy(((u8 *)this) + 0x1C, lbl_805D7B1C, 6);
    p = ((u8 *)this) + 0xEC;
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
    return p - ((u8 *)this);
}

extern s16 dhcp_iface;
extern s32 lbl_805D7B14;
extern s32 dhcp_max_retries;
extern u32 lbl_805D7B98;
extern s32 lbl_805D7B9C;
extern s32 dhcp_reply_received;
extern u32 dhcp_send_time;
extern s32 dhcp_retries_left;
extern u8 lbl_805C1E00[];
s32 TLobby__sub_804250A8(s32);
s32 TLobby__sub_80424FE0(void);

// Closes the DHCP UDP socket (names inferred); returns the close result.
static inline s32 dhcp_close_socket() {
    s32 r = TLobby__sub_80421B3C(dhcp_socket);
    dhcp_socket = -1;
    if (dhcp_state == 1 || dhcp_state == 2 || dhcp_state == 6) {
        lbl_805D7B14 = TLobby__sub_804250A8(0);
    }
    return r;
}

// Opens the DHCP client UDP socket (port 68 to server port 67; names inferred); returns the handle or an error.
static inline s16 dhcp_open_socket(u32 *addr) {
    s16 r;
    addr[0] = 4;
    addr[1] = 0;
    r = TUdpSocket__sub_80421DEC(0, 0x44, addr, 0x43, 0, TLobby::dhcp_handle_reply);
    dhcp_socket = r;
    return r;
}

s32 dhcp_release_step(void) {
    s32 now;
    P_8042315C opt;
    UdpBuf_80421BAC buf;
    u32 dst[5];
    u32 src[5];
    s32 len;
    s16 sock;
    TLobby::get_time_ms(&now);
    switch (dhcp_step) {
    case 0:
        dhcp_close_socket();
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
        len = ((TLobby *)lbl_805C1E00)->build_dhcp_release();
        src[0] = 4;
        dst[0] = 4;
        src[1] = 0;
        dst[1] = -1;
        sock = dhcp_socket;
        buf.len = len > 300 ? len : 300;
        buf.data = (s32)lbl_805C1E00;
        if (TUdpSocket__sub_80421BAC(sock, src, dst, 0x43, NULL, 1, &buf) < 0) {
            dhcp_close_socket();
            dhcp_error = 5;
            dhcp_step = -1;
            dhcp_state = -2;
        } else {
            lbl_805D7B98 = now;
            lbl_805D7B9C--;
            if (lbl_805D7B9C <= 0) {
                dhcp_close_socket();
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

s32 dhcp_discover_step(void) {
    s32 now;
    P_8042315C opt;
    P_8042315C opt2;
    u32 addr[5];
    u32 server = 0xFFFFFFFF; // discover is always broadcast
    s32 len;
    UdpBuf_80421BAC buf;
    u32 dst[5];
    u32 src[5];
    s16 sock;
    TLobby::get_time_ms(&now);
    switch (dhcp_step) {
    case 0:
        dhcp_close_socket();
        opt.type = 4;
        opt.a = 0;
        opt.b = -1;
        opt.c = -1;
        if (TLobby__sub_8042315C(dhcp_iface, &opt) != 0) {
            TLobby__sub_80423064(dhcp_iface, 4);
            opt2.type = 4;
            opt2.a = 0;
            opt2.b = -1;
            opt2.c = -1;
            if (TLobby__sub_8042315C(dhcp_iface, &opt2) != 0) {
                dhcp_step = -1;
                dhcp_state = -2;
                dhcp_error = 3;
                break;
            }
        }
        lbl_805D7B14 = 1;
        if (dhcp_open_socket(addr) < 0) {
            TLobby__sub_80423064(dhcp_iface, 4);
            lbl_805D7B14 = 0;
            dhcp_step = -1;
            dhcp_state = -2;
            dhcp_error = 4;
            break;
        }
        dhcp_step = 1;
        dhcp_retries_left = dhcp_max_retries;
    case 1:
        len = ((TLobby *)lbl_805C1E00)->build_dhcp_discover_packet();
        src[0] = 4;
        dst[0] = 4;
        dhcp_reply_received = 0;
        src[1] = 0;
        dst[1] = server;
        sock = dhcp_socket;
        buf.len = len > 300 ? len : 300;
        buf.data = (s32)lbl_805C1E00;
        if (TUdpSocket__sub_80421BAC(sock, src, dst, 0x43, NULL, 1, &buf) < 0) {
            dhcp_close_socket();
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
        } else if (now - dhcp_send_time >= 3000) {
            dhcp_retries_left--;
            if (dhcp_retries_left <= 0) {
                dhcp_close_socket();
                dhcp_state = -1;
                dhcp_step = -1;
                dhcp_error = 6;
            } else {
                dhcp_step = 1;
            }
        }
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
    // Preserve the original 16-bit hostname-length checks.
    if ((u16)length < 0x20 && (u16)length != 0) {
        TLobby__sub_80425288(0x10, (u16)length, a);
        return 0;
    }
    dhcp_error = 1;
    return -1;
}

}
