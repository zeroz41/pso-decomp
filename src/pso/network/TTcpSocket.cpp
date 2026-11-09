#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804050DC.h"
#pragma readonly_strings on
#include "types.h"
#include "pso/system/byteswap.h"
#include "pso/system/main_loop.h"
#include "pso/network/TProtocol.h"
#include <stdio.h>
#include <string.h>
#include "pso/macros.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/network/TSocket.h"
#include "pso/network/TTcpSocket.h"
#include "pso/network/TUdpSocket.h"
#include "pso/unk/TLobby.h"

struct RecoveredGlobal_80078378_lbl_8048D3B8 {
    s32 value;
    u8 remaining[0x3C];
};

struct Sock_80078110 { char pad[0x1c]; s32 f1c; u16 port; u8 pad22[2]; s32 addr; s16 fd; };

struct Q_80078110 { s32 len; s32 v; u8 pad[0xc]; };

struct R_80078110 { s16 a; s32 b; };

struct C_80078110 { s32 len; s8 a; s8 b; s8 c; u8 pad[8]; };

struct Sock_800781B8 { char pad[0x1c]; s32 f1c; u16 port; u8 pad22[2]; s32 addr; s16 fd; };

struct Q_800781B8 { s32 len; s32 v; u8 pad[0xc]; };

struct R_800781B8 { s16 a; s32 b; };

struct C_800781B8 { s32 len; s8 a; s8 b; s8 c; u8 pad[8]; };

struct Sock_800782B8 { char pad[0x1c]; s32 f1c; u16 port_a; u16 port_b; u8 pad24[4]; s16 fd; };

struct Q_800782B8 { s32 len; s32 v; u8 pad[0xc]; };

struct Q2_800782B8 { s32 len; s32 v; u8 pad[0xc]; };

struct Sock_80078264 { u8 pad[0x28]; s16 x28; };

extern "C" {
struct Rec_8007841C *copy_udp_socket_event_record(struct Rec_8007841C *dst, struct Rec_8007841C *src);
extern RecoveredGlobal_80078378_lbl_8048D3B8 udp_socket_slots;
void TLobby__sub_8014672C(s32 *arg0);
void TUdpSocket__sub_80421BAC(int, void *, void *, int, void *, int, void *);
void TUdpSocket__sub_80078110(Sock_80078110 *arg0, s32 arg1, s16 arg2);
void TUdpSocket__sub_800781B8(Sock_800781B8 *arg0, s32 arg1);
s16 TUdpSocket__sub_80421DEC(void *, int, void *, int, int, s32 (*)(s16, u8 *));
s16 open_socket__10TUdpSocketFPv(Sock_800782B8 *arg0);
s32 TLobby__sub_80421B3C(s32 a);
void free_socket_slot__10TUdpSocketFPv(Sock_80078264 *arg0);
struct Base_80078064 { char pad[0x18]; };
struct VObj_80078064 : Base_80078064 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5();
};

void *__dt__10TUdpSocketFv(void *arg0, s16 arg1);
s32 __dl__7TObjectFPv(void *);
s32 __dt__7TSocketFv(void *, s32);

void run_task__7TObjectFv();
void render__7TObjectFv();
void render_shadows__7TObjectFv();
}
void reset_buffer(u8 *arg0);
TTcpSocket *tcp_socket_table[16] = {0};
extern "C" {
RecoveredGlobal_80078378_lbl_8048D3B8 udp_socket_slots = {0};
}
const char *sock_status_names[17] = {
    "SUCCESS", "API_PENDING", "API_PORTFULL", "API_DUPSOCK", "API_INVALIDHANDLE",
    "API_SENDPENDING", "API_CONNRESET", "API_UNREACHABLE", "API_RECVFIN",
    "API_RECVPENDING", "API_PORTCLOSED", "API_TIMEOUT", "API_NOBUF", "API_BADOPT",
    "API_dummy1", "API_dummy2", "API_GENERAL",
};
void *__vt__10TUdpSocket[11] = {
    0, 0, (void *)__dt__10TUdpSocketFv, (void *)run_task__7TObjectFv,
    (void *)render__7TObjectFv, (void *)render_shadows__7TObjectFv,
    (void *)open_socket__10TUdpSocketFPv, (void *)free_socket_slot__10TUdpSocketFPv,
    (void *)reset_buffer, (void *)TUdpSocket__sub_800781B8, (void *)TUdpSocket__sub_80078110,
};
extern "C" {

void *__dt__10TUdpSocketFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        struct VObj_80078064 *o = (struct VObj_80078064 *)arg0;
        *(s32 **)((s8 *)arg0 + 0x18) = (s32 *)__vt__10TUdpSocket;
        o->m5();
        __dt__7TSocketFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
}

void reset_buffer(u8 *arg0) {
    memset(arg0 + 0x74, 0, 0x800);
    *(s8 *)((s8 *)arg0 + 0x2B) = 1;
}
typedef char RecoveredGlobal_80078378_lbl_8048D3B8_size[sizeof(RecoveredGlobal_80078378_lbl_8048D3B8) == 0x40 ? 1 : -1];
extern "C" {

void TUdpSocket__sub_80078110(Sock_80078110 *arg0, s32 arg1, s16 arg2) {
    Q_80078110 q2;
    Q_80078110 q1;
    C_80078110 c;
    R_80078110 r;
    u16 port;
    q1.len = 4;
    q1.v = arg0->f1c;
    TLobby__sub_8014672C(&arg0->addr);
    q2.len = 4;
    q2.v = arg0->addr;
    c.len = 4;
    c.a = 0x78;
    c.b = 0;
    c.c = 0;
    r.b = arg1;
    r.a = arg2;
    port = arg0->port;
    bswap_16(&port);
    TUdpSocket__sub_80421BAC(arg0->fd, &q2, &q1, port, &c, 1, &r);
}

void TUdpSocket__sub_800781B8(Sock_800781B8 *arg0, s32 arg1) {
    Q_800781B8 q2;
    Q_800781B8 q1;
    C_800781B8 c;
    R_800781B8 r;
    u16 port;
    q1.len = 4;
    q1.v = arg0->f1c;
    TLobby__sub_8014672C(&arg0->addr);
    q2.len = 4;
    q2.v = arg0->addr;
    c.len = 4;
    c.a = 0x78;
    c.b = 0;
    c.c = 0;
    r.b = arg1;
    r.a = strlen((const char *)arg1);
    port = arg0->port;
    bswap_16(&port);
    TUdpSocket__sub_80421BAC(arg0->fd, &q2, &q1, port, &c, 1, &r);
}

void free_socket_slot__10TUdpSocketFPv(Sock_80078264 *arg0) {
    if (arg0->x28 >= 0x400) {
        TLobby__sub_80421B3C(arg0->x28);
        (&udp_socket_slots.value)[arg0->x28 - 0x400] = 0;
    }
}

s16 open_socket__10TUdpSocketFPv(Sock_800782B8 *arg0) {
    Q_800782B8 q1;
    Q2_800782B8 q2;
    u16 pb;
    u16 pa;
    s32 i;
    q1.len = 4;
    q1.v = 0;
    q2.len = 4;
    q2.v = arg0->f1c;
    for (i = 0; i < 30001; i++) {
    }
    pa = arg0->port_b;
    pb = arg0->port_a;
    bswap_16(&pa);
    bswap_16(&pb);
    arg0->fd = TUdpSocket__sub_80421DEC(&q1, pa, &q2, pb, 0, TUdpSocket::handle_socket_event);
    if (arg0->fd < 0) {
        return -1;
    }
    (&udp_socket_slots.value)[arg0->fd - 0x400] = (s32)arg0;
    return arg0->fd;
}

s32 TUdpSocket::handle_socket_event(s16 arg0, u8 *arg1) {
    s32 (*temp_r12)(void *);
    u8 *temp_r5;
    temp_r5 = (u8 *)(*(s32 *)((s8 *)&udp_socket_slots.value + ((*(s16 *)((s8 *)arg1 + 0) - 0x400) * 4)));
    if (temp_r5 == NULL) {
        return 1;
    }
    if (arg0 == 0) {
        *(s32 *)((s8 *)arg1 + 4) = (s32)(temp_r5 + 0x74);
        ((void (*)(void *, void *))copy_udp_socket_event_record)(temp_r5 + 0x884, arg1);
        *(s16 *)((s8 *)arg1 + 2) = 0x800;
    } else {
        *(s8 *)((s8 *)temp_r5 + 0x2B) = 0;
        *(s16 *)((s8 *)temp_r5 + 0x2E) = 0;
        *(s16 *)((s8 *)temp_r5 + 0x2C) = (s16) *(s16 *)((s8 *)arg1 + 2);
        temp_r12 = *(s32 (**)(void *))((s8 *)temp_r5 + 0x880);
        if (temp_r12 != NULL) {
            temp_r12(temp_r5);
        }
    }
    return 0;
}
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Sub_8007841C { s32 w[5]; };

struct Pair_8007841C { s32 w[2]; };

struct Rec_8007841C { Pair_8007841C ab; Sub_8007841C c; Sub_8007841C d; u16 e; };

extern "C" {

Rec_8007841C *copy_udp_socket_event_record(Rec_8007841C *dst, Rec_8007841C *src) {
    dst->ab = src->ab;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    return dst;
}

}
#pragma pop

// Game code; structure adapted from pso-gc-reference, verified against PsoV3.dol.

struct at_ip4_opt {
	u8 ttl;
	u8 svctype;
	u8 df_flag;
};

struct at_ip6_opt {
	u8 traffic_class;
	u32 flow_label;
	u8 hop_limit;
};

struct at_ip_option {
	u32 type;
	union {
		struct at_ip6_opt ip6;
		struct at_ip4_opt ip4;
	} ip46;
};

struct at_ip_addr {
	u32 type;
	union {
		u8 ip6[16];
		u32 ip4;
	} ip46;
};

void func_80019A68();
void controller_stuff();
char func_801A5E54();
void render_tick();
void func_803DCDFC();
extern "C" {
short tcp_abort(short nh);
short tcp_bind(short nh, struct at_ip_addr *addr, u16 port);
short tcp_connect(short nh, struct at_ip_addr *addr, u16 port, struct at_ip_option *option);
short tcp_create();
short tcp_delete(short nh);
short tcp_get_opt(short nh, short type, u32 *opt);
short tcp_send(short nh, void (*notify)(short size, short sock_fd), char bufnum, struct send_buffs *sb);
int tcp_stat(short nh, short *stat, short *backlog, u32 *sendwin, u32 *recvwin);
short tcp_receive(short nh, void (*notify)(short size, short sock_fd), short len, u8 *buf);
}
int get_link_status();
char *get_sock_status_name(short code);

TTcpSocket::~TTcpSocket() {
	close();
}

void TTcpSocket::recv() {
	if (m_sock_fd != -1) {
		memset(m_packet_buffer, 0, sizeof(m_packet_buffer));
		m_buffer_cleared = true;
		(int)tcp_receive(m_sock_fd, notify, sizeof(m_packet_buffer), m_packet_buffer);
	}
}

void TTcpSocket::notify(short size, short sock_fd) {
	char tmp_str[64];
	TTcpSocket *socket = tcp_socket_table[sock_fd];

	if (socket != nullptr) {
		if (size > 0) {
			socket->m_buffer_cleared = false;
			socket->m_size = size;
			socket->m_buffer_offset = 0;
			sprintf(tmp_str, "Rcv:%d byte", size);
			socket->log(tmp_str);
			if (socket->m_callback != nullptr) {
				socket->m_callback(socket);
			}
		} else {
			socket->m_is_invalid_packet |= 1;
		}
	}
}

short TTcpSocket::send(u8 *data, size_t size) {
	if (m_sock_fd != -1) {
		if (m_is_encrypted) {
			m_send_crypt.encrypt(data, size);
		}

		if (m_is_invalid_packet || !get_link_status()) {
			return -1;
		} else {
			if (int status = stat()) {
				log(get_sock_status_name(status));
				m_is_invalid_packet |= 1;
				return 1;
			} else {
				if (m_send_window <= size) {
					m_is_invalid_packet |= 1;
					return 1;
				} else {
					if (m_stat_val < 0) {
						m_is_invalid_packet |= 1;
						return 1;
					} else {
						struct send_buffs sb;
						sb.buff = data;
						sb.len = size;
						m_unused = 0;
						int ret = tcp_send(m_sock_fd, nullptr, 1, &sb);
						if (ret >= 1 || ret < -1) {
							m_is_invalid_packet |= 1;
							log(get_sock_status_name(ret));
							close();
						}
						return ret;
					}
				}
			}
		}
	}
	return -1;
}

short TTcpSocket::send(u8 *data) {
	if (m_sock_fd != -1) {
		if (m_is_invalid_packet || !get_link_status()) {
			return -1;
		} else {
			if (short status = stat()) {
				log(get_sock_status_name(status));
				m_is_invalid_packet |= 1;
				return 1;
			} else {
				if (m_stat_val < 0) {
					m_is_invalid_packet |= 1;
					return 1;
				} else {
					s8 len = strlen(reinterpret_cast<const char *>(data));
					struct send_buffs sb;
					sb.buff = data;
					sb.len = len;
					if (m_send_window <= len) {
						m_is_invalid_packet |= 1;
						return 1;
					} else {
						short ret = tcp_send(m_sock_fd, nullptr, 1, &sb);
						if (ret) {
							close();
						}
						return ret;
					}
				}
			}
		}
	} else {
		return -1;
	}
}

int TTcpSocket::test_connection() {
	for (int i = 0; i < 1800; ++i) {
		if (int status = stat()) {
			log(get_sock_status_name(status));
			m_is_invalid_packet |= 1;
			return 1;
		} else if (m_send_window <= 128) {
			m_is_invalid_packet |= 1;
			return 1;
		} else if (m_stat_val < 0) {
			m_is_invalid_packet |= 1;
			return 1;
		} else if (!get_link_status()) {
			m_is_invalid_packet |= 1;
			return 1;
		} else if (m_send_window > 4095) {
			return 0;
		} else {
			main_task.begin_frame();
			main_task.run_tl_camera_tasks();
			main_task.render();
			main_task.render_screen_overlay();
			func_80019A68();
			render_tick();
		}
	}

	m_is_invalid_packet |= 1;
	return 1;
}

void TTcpSocket::some_stub() {}

short TTcpSocket::stat() {
	if (m_sock_fd != -1) {
		return tcp_stat(m_sock_fd, &m_stat_val, nullptr, &m_send_window, &m_recv_window);
	} else {
		return 0;
	}
}

short TTcpSocket::close() {
	short result = m_sock_fd;
	if (result != -1) {
		(short)tcp_abort(m_sock_fd);
		(short)tcp_delete(m_sock_fd);
		tcp_socket_table[m_sock_fd] = nullptr;
		m_sock_fd = result = -1;
		m_is_encrypted = 0;
		m_size = 0;
		m_buffer_offset = 0;
		m_buffer_cleared = true;
	}
	return result;
}

int TTcpSocket::open() {
	m_sock_fd = -1;
	m_is_encrypted = 0;
	m_size = 0;
	m_buffer_offset = 0;
	m_buffer_cleared = true;
	m_unused = 0;
	m_sock_fd = tcp_create();

	if (m_sock_fd < 0) {
		log(get_sock_status_name(m_sock_fd));
		return -1;
	} else {
		struct at_ip_option connect_option;
		struct at_ip_addr connect_addr;
		struct at_ip_addr bind_addr;

		u32 opt = 1;

		tcp_get_opt(m_sock_fd, 0x2001, &opt);

		bind_addr.type = 4;
		bind_addr.ip46.ip4 = 0;

		tcp_bind(m_sock_fd, &bind_addr, m_src_port);

		connect_addr.type = 4;
		connect_addr.ip46.ip4 = m_dst_addr.addr;

		connect_option.type = 4;
		connect_option.ip46.ip4.ttl = 120;
		connect_option.ip46.ip4.svctype = 0;
		connect_option.ip46.ip4.df_flag = 0;

		if (tcp_connect(m_sock_fd, &connect_addr, m_dst_port, &connect_option)) {
			log(get_sock_status_name(m_sock_fd));
			return -1;
		} else {
			for (;;) {
				func_803DCDFC();
				controller_stuff();
				if (short status = stat()) {
					log(get_sock_status_name(status));
					return -2;
				} else if (m_stat_val < 0) {
					return -2;
				} else {
					some_stub();
					if (m_stat_val < 4) {
						if (!get_link_status()) {
							return -3;
						} else if (func_801A5E54()) {
							return -2;
						} else {
							main_task.begin_frame();
							main_task.run_tl_camera_tasks();
							main_task.render();
							main_task.render_screen_overlay();
							func_80019A68();
							render_tick();
						}
					} else {
						tcp_socket_table[m_sock_fd] = this;
						return m_sock_fd;
					}
				}
			}
		}
	}
}

// Adapted from pso-gc-reference (mrb0nk500) for GPOE8P (MWCC 2.6)

extern "C" {
void func_80019A68__Fv();
s32 get_csn_group_flags(s32);
s8 func_801A5E54__Fv();
int atoi(const char *);
void func_803DCDFC__Fv();
s16 TLobby__sub_8040A698(s16, void *, void *, int, void *, int);
s16 TLobby__sub_8040A8B0(char *, s32, int);
}

int TSocket::is_empty() {
    if (all_parents_unqueued_for_destruction()) {
        return !m_size;
    } else {
        return true;
    }
}

const u8 TProtocol::next() {
    const u8 val = m_packet_buffer[m_buffer_offset++];
    if (m_buffer_offset >= m_size) {
        m_buffer_offset = 0;
        m_size = 0;
    }
    return val;
}

void TSocket::set_port(u32 port) {
    m_dst_port = to_le_uint16_t(port);
}

void TSocket::set_ip_address(u32 addr) {
    u8 *ptr = reinterpret_cast<u8 *>(&addr);
    m_dst_addr.addr_bytes[3] = ptr[0];
    m_dst_addr.addr_bytes[2] = ptr[1];
    m_dst_addr.addr_bytes[1] = ptr[2];
    m_dst_addr.addr_bytes[0] = ptr[3];
}

int TSocket::resolve_domain(char *domain) {
    s32 ret;
    s16 result;
    s32 i;
    s32 n;
    char *start;
    s16 count;
    s16 handle;
    char buf[0x20];
    u32 sp10[4];
    s32 spC;
    s16 spA;
    s16 sp8;

    start = buf;
    memset(start, 0, 0x20);
    strncpy(start, domain, 0x1F);
    if (get_csn_group_flags(buf[0]) != 0) {
        handle = TLobby__sub_8040A8B0(start, (s8)NetStringLength(start), 4);
        if (handle >= 0) {
            spC = 4;
            count = 0;
            spA = 1;
            sp8 = 0;
            do {
                result = TLobby__sub_8040A698(handle, &spC, &spA, 0, &sp8, -1);
                count++;
                if (count > 0x1518) {
                    break;
                }
                func_803DCDFC__Fv();
                controller_stuff();
                if (func_801A5E54__Fv() != 0) {
                    break;
                }
                main_task.begin_frame();
                ((TMainTask *)(&main_task))->run_tl_camera_tasks();
                main_task.render();
                main_task.render_screen_overlay();
                func_80019A68__Fv();
                render_tick();
            } while (result == -1);
            switch (result) {
            case 0:
                bswap_32(sp10);
                set_ip_address(sp10[0]);
                ret = 0;
                break;
            case -66:
            case -68:
            case -70:
            case -2:
                set_ip_address(0);
                ret = 3;
                break;
            case -71:
                set_ip_address(0);
                ret = 5;
                break;
            case -1:
            case -69:
                set_ip_address(0);
                ret = 2;
                break;
            default:
                set_ip_address(0);
                ret = 6;
                break;
            }
            close_connection_by_index(handle);
        } else {
            set_ip_address(0);
            ret = 4;
        }
        return ret;
    }
    i = 0;
    n = 0;
    while (n < 4) {
        if (buf[i] == '.' || buf[i] == 0) {
            buf[i] = 0;
            m_dst_addr.addr_bytes[n] = atoi(start);
            start = &buf[i + 1];
            n++;
        }
        i++;
    }
    return 0;
}

TSocket::TSocket(TObject *parent) : TObject(parent) {
    m_dst_addr.addr_bytes[0] = 0;
    m_dst_addr.addr_bytes[1] = 0;
    m_dst_addr.addr_bytes[2] = 0;
    m_dst_addr.addr_bytes[3] = 0;
    m_dst_port = 0;
    m_src_port = 0;
    m_sock_fd = -1;
    m_is_invalid_packet = false;
    m_size = 0;
    m_buffer_offset = 0;
    m_buffer_cleared = true;
    m_callback = nullptr;
}

char *get_sock_status_name(s16 status) {
    return (char *)sock_status_names[(u8)-status & 0xF];
}

u16 to_be_uint16_t(u16 val) {
    u8 *ptr = reinterpret_cast<u8 *>(&val);
    return ptr[0] + (ptr[1] << 8);
}

u16 to_le_uint16_t(u16 val) {
    u8 *ptr = reinterpret_cast<u8 *>(&val);
    return ptr[1] + (ptr[0] << 8);
}

TSocket::~TSocket() {

}
