#include "types.h"
#include "pso/network/TLobby_803FAEA0.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
/* This file's functions. */
void init_net_state_a(void);
s32 init_net_state_b(void);
s32 mark_sub_ready(void *obj);
s32 set_active_flag(void *self);
void update_connection_state(void *arg0);
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/NetworkTransport.h"

struct Self_803FD74C;

struct Self_803FD85C;

#include <stddef.h>
#include "pso/network/NetStackTypes.h"

void TLobby__sub_803F76F0(void *); /* declared with 1 parameter; the definition is void (void) */
void net_sleep_ms(int);
s16 ppp_buffer_read(void *self, void *dst, u16 n);

void init_net_state_a(void) {
    TLobby__sub_803F76F0((void *)&lbl_805C02D0);
}

s32 init_net_state_b(void) {
    init_net_buffer_table(&lbl_805C02D0);
    return 0;
}

s16 PP_chap_monitor(PppFsm *c, s32 timeout) {
    PppChap *auth;
    u8 *sub;
    NetThreadState *g;

    sub = c->sub;
    auth = (PppChap *)c->opts;
    if (lbl_805D7A90 & 2) {
        auth->active = 1;
        TLobby__sub_803FE820((saddr)c);
        ppp_fsm_send_packet(c, 1, 0, build_avetcp_net_buffer(c));
    } else {
        auth->active = 0;
    }
    g = &lbl_805C18A0;
    c->abort = 0;
    while (c->state != 5) {
        if (is_timed_out() != 0 || c->abort != 0 || *sub == 4) {
            c->abort = 0;
            if (ppp_auth_failed != 0) {
                lbl_805D7A82 = 6;
            } else {
                lbl_805D7A82 = 5;
            }
            lobby_modem_connect_state = 8;
            return -1;
        }
        if (get_remaining(timeout) != 0) {
            return -0x12;
        }
        unlock_mutex(g->mutex);
        net_sleep_ms(100);
        process_expired_timers();
        lock_mutex(g->mutex);
    }
    c->abort = 0;
    return 0;
}

struct PppChapAuthenticationState;
struct N_80405298;
PppChapAuthenticationState ppp_chap_authentication_state;
PppAuthState lbl_805C02D0;
/* The challenge length and the response reader's scratch byte (.sbss 805D7A98), in reverse definition order. */
u16 lbl_805D7A9A;
u8 chap_read_byte_buffer;
void TLobby__sub_803FC318(PppProtoBlocks *connection) {
    PppFsm *fsm = &connection->chap;
    PppFsmTimer *timer;

    if (fsm->opts == NULL) {
        timer = &fsm->timer;
        ppp_chap_authentication_state.proto.name = chap_protocol_name;
        ppp_chap_authentication_state.proto.proto = 0xC223;
        ppp_chap_authentication_state.proto.h6 = 0x70;
        ppp_chap_authentication_state.proto.tx_counter_index = 3;
        ppp_chap_authentication_state.proto.max_terminate_attempts = 0;
        ppp_chap_authentication_state.proto.max_request_attempts = lbl_805C02D0.f36;
        ppp_chap_authentication_state.proto.max_peer_attempts = lbl_805C02D0.f37;
        ppp_chap_authentication_state.proto.timeout = lbl_805C02D0.f38 * 1000;
        ppp_chap_authentication_state.proto.release_resources = TLobby__sub_803FE84C;
        ppp_chap_authentication_state.proto.reset_options = TLobby__sub_803FE84C;
        ppp_chap_authentication_state.proto.start_negotiation = TLobby__sub_803FE84C;
        ppp_chap_authentication_state.proto.link_opened = TLobby__sub_803FE84C;
        ppp_chap_authentication_state.proto.link_closed = TLobby__sub_803FE84C;
        ppp_chap_authentication_state.proto.finish_termination = TLobby__sub_803FE84C;
        ppp_chap_authentication_state.proto.build_config_request = build_avetcp_net_buffer;
        ppp_chap_authentication_state.proto.check_config_request = TLobby__sub_803FE844;
        ppp_chap_authentication_state.proto.check_config_ack = TLobby__sub_803FE844;
        ppp_chap_authentication_state.proto.check_config_nak = TLobby__sub_803FE844;
        ppp_chap_authentication_state.proto.check_config_reject = TLobby__sub_803FE844;
        fsm->sub = (u8 *)connection;
        fsm->proto = &ppp_chap_authentication_state.proto;
        fsm->opts = &ppp_chap_authentication_state.options;
        fsm->f4 = fsm->proto->max_request_attempts;
        fsm->f7 = fsm->proto->max_peer_attempts;
        fsm->f5 = fsm->proto->max_terminate_attempts;
        fsm->state = 0;
        fsm->retries = fsm->f4;
        fsm->f6 = fsm->f7;
        timer->callback = TLobby__sub_803FC728;
        timer->arg = fsm;
        lobby_timer_add((N_80405298 *)timer, fsm->proto->timeout);
    }
}

s32 set_active_flag(void *self) {
    u8 *arg0 = (u8 *)self;
    *(s8 *)((s8 *)arg0 + 0xA0) = 2;
    *(u8 *)((s8 *)arg0 + 0xA2) = (u8) (*(u8 *)((s8 *)arg0 + 0xA2) | 0x20);
    *(u8 *)((s8 *)arg0 + 2) = (u8) (*(u8 *)((s8 *)arg0 + 2) | 0x20);
    return 0;
}

s32 mark_sub_ready(void *obj) {
    Obj_803FC480 *self = (Obj_803FC480 *)obj;
    Sub_803FC480 *s = &self->sub;
    s->f0 = 1;
    s->f2 |= 0x10;
    self->f2 |= 0x10;
    s->f3 = s->f4;
    return 0;
}

struct O_80400ACC;

void chap_input(PppFsm *self, PppFrame *source) {
    u8 *arg0 = (u8 *)self;
    PppHeader hdr;
    u8 temp_r0;
    u8 temp_r0_2;
    u8 temp_r0_3;
    u8 *temp_r30;
    u8 *temp_r30_2;
    u8 *temp_r30_3;
    u8 *temp_r30_4;

    if (TLobby__sub_803FE8BC(&hdr, &source) != -1) {
        hdr.len -= 4;
        TLobby__sub_80401CAC(&source, hdr.len);
        switch (hdr.code) {
        case 1:
            chap_recv_challenge(self, &hdr, source);
            return;
        case 2:
            if (chap_recv_response(self, &hdr, source) == 0) {
                if (lbl_805D7A90 & 2) {
                    temp_r30 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xC));
                    lobby_timer_stop((void *) (arg0 + 0x10));
                    temp_r0 = *(u8 *)((s8 *)arg0 + 2) & 0xFFFFFFEF;
                    *(u8 *)((s8 *)arg0 + 2) = temp_r0;
                    if (!(temp_r0 & 0x10)) {
                        *(s8 *)((s8 *)arg0 + 0) = 5;
                    }
                    *(u8 *)((s8 *)temp_r30 + 2) = (u8) (*(u8 *)((s8 *)temp_r30 + 2) & 0xFFFFFFEF);
                    *(u8 *)((s8 *)temp_r30 + 2) = (u8) (*(u8 *)((s8 *)temp_r30 + 2) & 0xFFFFFFDF);
                    start_ipcp_after_auth((O_80400ACC *) (temp_r30));
                    return;
                }
                temp_r30_2 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xC));
                lobby_timer_stop((void *) (arg0 + 0x10));
                temp_r0_2 = *(u8 *)((s8 *)arg0 + 2) & 0xFFFFFFDF;
                *(u8 *)((s8 *)arg0 + 2) = temp_r0_2;
                if (!(temp_r0_2 & 0x10)) {
                    *(s8 *)((s8 *)arg0 + 0) = 5;
                }
                *(u8 *)((s8 *)temp_r30_2 + 2) = (u8) (*(u8 *)((s8 *)temp_r30_2 + 2) & 0xFFFFFFDF);
                start_ipcp_after_auth((O_80400ACC *) (temp_r30_2));
                return;
            }
            break;
        case 3:
            lobby_timer_stop((void *) (arg0 + 0x10));
            temp_r30_3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xC));
            lobby_timer_stop((void *) (arg0 + 0x10));
            temp_r0_3 = *(u8 *)((s8 *)arg0 + 2) & 0xFFFFFFEF;
            *(u8 *)((s8 *)arg0 + 2) = temp_r0_3;
            if (!(temp_r0_3 & 0x10)) {
                *(s8 *)((s8 *)arg0 + 0) = 5;
            }
            *(u8 *)((s8 *)temp_r30_3 + 2) = (u8) (*(u8 *)((s8 *)temp_r30_3 + 2) & 0xFFFFFFEF);
            *(u8 *)((s8 *)temp_r30_3 + 2) = (u8) (*(u8 *)((s8 *)temp_r30_3 + 2) & 0xFFFFFFDF);
            start_ipcp_after_auth((O_80400ACC *) (temp_r30_3));
            return;
        case 4:
            lobby_timer_stop((void *) (arg0 + 0x10));
            temp_r30_4 = (u8 *)(*(u8 **)((s8 *)arg0 + 0xC));
            update_connection_state(temp_r30_4 + 0xA0);
            update_connection_state(temp_r30_4 + 4);
            *(s16 *)((s8 *)arg0 + 8) = 1;
            ppp_auth_failed = 1;
            break;
        }
    }
}

s32 TLobby__sub_803FC684(u8 *source, u8 *chap_secret, PppFsm *fsm) {
    PppChap *options = fsm->opts;

    if (NetStringLength((const char *)((void *)source)) >= 0x80) {
        source[0x7F] = 0;
    }
    if (NetStringLength((const char *)((void *)chap_secret)) >= 0x80) {
        chap_secret[0x7F] = 0;
    }
    NetCopyString(ppp_chap_authentication_state.peer_id, (const char *)source);
    NetCopyString(ppp_chap_authentication_state.secret, (const char *)chap_secret);
    options->name = ppp_chap_authentication_state.peer_id;
    options->secret = ppp_chap_authentication_state.secret;
    return 0;
}

void TLobby__sub_803FC728(PppFsm *c) {
    PppFrame *buf;
    PppChap *chap = (PppChap *)c->opts;
    u8 *sub;

    if (chap->active != 0) {
        if (c->retries != 0) {
            chap->msg = "Request timeout";
            TLobby__sub_803FE658(c);
            return;
        }
        chap->msg = "Request retry exceeded";
        sub = c->sub;
        update_connection_state(sub + 0xA0);
        update_connection_state(sub + 4);
        c->abort = 1;
        return;
    }
    if (c->retries != 0) {
        buf = TLobby__sub_80401B20(lbl_805C02D0.p1C, chap->len);
        ppp_fsm_send_packet(c, 2, chap->id, buf);
        lobby_timer_start((u8 *)&c->timer);
        c->retries--;
        return;
    }
    sub = c->sub;
    update_connection_state(sub + 0xA0);
    update_connection_state(sub + 4);
    c->abort = 1;
}

#pragma push
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 chap_read_byte_slow(PppFrame **src) {
    if (ppp_buffer_read(src, &chap_read_byte_buffer, 1) != 1) {
        return -1;
    }
    return (s16)chap_read_byte_buffer;
}
inline s32 chap_read_byte(PppFrame **src) {
    s32 fast = 0;
    s32 valid = 0;
    if (src != NULL && *src != NULL) {
        valid = 1;
    }
    if (valid && (*src)->len > 1) {
        fast = 1;
    }
    if (fast) {
        (*src)->len--;
        return *(*src)->data++;
    }
    return chap_read_byte_slow(src);
}
s16 chap_recv_response(PppFsm *c, PppHeader *hdr, PppFrame *v) {
    s16 total;
    PppChap *chap;
    u8 *name;
    u8 *value;
    s16 n;
    const char *secret;
    s32 i;
    u8 *p;
    s16 m;
    s32 j;
    u8 *q;
    s16 len;
    s32 code;
    s16 ret;
    PppFrame *reply;
    MD5Context ctx;

    name = NULL;
    value = NULL;
    secret = NULL;
    chap = c->opts;

    if (hdr->id != c->id) {
        return -1;
    }
    total = hdr->len;
    n = chap_read_byte_slow(&v);
    if (n != -1) {
        p = value = lbl_805C02D0.p10;
        for (i = 0; i < n; i++) {
            *p++ = chap_read_byte(&v);
        }
    }
    m = total - n - 1;
    if (m < 0) {
        m = 0;
    }
    if (m >= 0x80) {
        m = 0x7F;
    }
    if (m != 0) {
        q = name = lbl_805C02D0.p4;
        for (j = 0; j < m; j++) {
            *q++ = chap_read_byte(&v);
        }
        *q = 0;
    }
    if (lbl_805D7A90 & 2) {
        secret = TLobby__sub_803F7684((const char *)name);
        if (secret == NULL) {
            NetCopyString(lbl_805C02D0.p20, chap_failure_message);
            reply = TLobby__sub_80401B20(lbl_805C02D0.p20, NetStringLength(lbl_805C02D0.p20));
            ppp_fsm_send_packet(c, 4, hdr->id, reply);
            return -1;
        }
    }
    *lbl_805C02D0.p18 = hdr->id;
    if (lbl_805D7A90 & 2) {
        NetCopyString((char *)lbl_805C02D0.p18 + 1, secret);
    } else {
        NetCopyString((char *)lbl_805C02D0.p18 + 1, chap->secret);
    }
    if (lbl_805D7A90 & 2) {
        len = NetStringLength(secret);
    } else {
        len = NetStringLength(chap->secret);
    }
    init_md5_state(&ctx);
    MD5Update(&ctx, lbl_805C02D0.p18, len + 1);
    MD5Update(&ctx, lbl_805C02D0.p8 + 1, lbl_805D7A9A);
    MD5Final((u8 *)lbl_805C02D0.p20, &ctx);
    if (NetMemcmp(lbl_805C02D0.p20, value, 0x10) == 0) {
        NetCopyString(lbl_805C02D0.p20, "Wellcome!!");
        code = 3;
        ret = 0;
    } else if (lbl_805D7A90 & 2) {
        NetCopyString(lbl_805C02D0.p20, chap_failure_message);
        code = 4;
        ret = -1;
    } else {
        NetCopyString(lbl_805C02D0.p20, "Wellcome!!");
        code = 3;
        ret = 0;
    }
    reply = TLobby__sub_80401B20(lbl_805C02D0.p20, NetStringLength(lbl_805C02D0.p20));
    ppp_fsm_send_packet(c, code, hdr->id, reply);
    return ret;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs on
#pragma opt_propagation off
#pragma opt_lifetimes off
inline PppChap *chap_options(PppFsm *connection) {
    return (PppChap *)connection->opts;
}

void chap_recv_challenge(PppFsm *connection, PppHeader *header, PppFrame *source) {
    struct {
        u8 *value;
    } challenge_slot;
    int raw_peer_length;
    s16 total;
    u32 challenge_offset;
    PppChap *chap;
    u8 *peer_name;
    s32 challenge_index;
    u16 string_length;
    u16 peer_name_length;
    s32 peer_name_index;
    u8 *challenge_cursor;
    PppFrame *reply;
    s16 challenge_length;
    u32 raw_name_length;
    MD5Context context;

    challenge_slot.value = 0;
    total = header->len;
    chap = chap_options(connection);
    challenge_length = chap_read_byte_slow(&source);
    if (challenge_length != -1) {
        challenge_cursor = (challenge_slot.value = lbl_805C02D0.pC);
        for (challenge_index = 0; challenge_index < challenge_length; challenge_index++) {
            *challenge_cursor++ = chap_read_byte(&source);
        }
    }
    raw_peer_length = (total - challenge_length) - 1;
    peer_name_length = raw_peer_length;
    if (peer_name_length >= 0x80) {
        peer_name_length = 0x7f;
    }
    if (peer_name_length != 0) {
        peer_name = lbl_805C02D0.p0;
        for (peer_name_index = 0; peer_name_index < peer_name_length; peer_name_index++) {
            *peer_name++ = chap_read_byte(&source);
        }
        *peer_name = 0;
    }
    *lbl_805C02D0.p14 = header->id;
    NetCopyString((char *)lbl_805C02D0.p14 + 1, chap->secret);
    string_length = NetStringLength(chap->secret);
    raw_name_length = NetStringLength(chap->name);
    challenge_offset = string_length + 1;
    string_length = raw_name_length;
    NetMemcpy(lbl_805C02D0.p14 + challenge_offset, challenge_slot.value, challenge_length);
    NetMemset(lbl_805C02D0.p1C, 0, lbl_805C02D0.size1C);
    *lbl_805C02D0.p1C = 0x10;
    init_md5_state(&context);
    MD5Update(&context, lbl_805C02D0.p14, challenge_offset + challenge_length);
    MD5Final(lbl_805C02D0.p1C + 1, &context);
    {
        u32 response_name_length = string_length;
        NetMemcpy(lbl_805C02D0.p1C + 0x11, (void *)chap->name, response_name_length);
    }
    chap->id = header->id;
    chap->len = string_length + 0x11;
    reply = TLobby__sub_80401B20(lbl_805C02D0.p1C, chap->len);
    ppp_fsm_send_packet(connection, 2, chap->id, reply);
    lobby_timer_start((u8 *)&connection->timer);
    connection->retries--;
    if (connection->f6 != 0) {
        connection->f6--;
    } else {
        header = (PppHeader *)connection->sub;
        update_connection_state((u8 *)header + 0xA0);
        update_connection_state((u8 *)header + 4);
    }
}
#pragma pop
