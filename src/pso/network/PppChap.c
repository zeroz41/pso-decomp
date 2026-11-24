#include "types.h"
#include "pso/network/PppApi.h"
#include "pso/network/PppChap.h"
#include "pso/network/Ppp.h"
#include "pso/network/NetStack.h"
/* This file's functions. */
void init_net_state_a(void);
s32 init_net_state_b(void);
#include "pso/network/NetworkRuntime.h"
#include "pso/network/PppVj.h"
#include "pso/network/NetworkTransport.h"



#include <stddef.h>
#include "pso/network/NetStackTypes.h"
#include "pso/network/PppBuffer.h"


void init_net_state_a(void) {
    term_ppp_auth_config(&chap_state);
}

s32 init_net_state_b(void) {
    init_net_buffer_table(&chap_state);
    return 0;
}

s16 PP_chap_monitor(PppFsm *c, s32 timeout) {
    PppChap *auth;
    PppProtoBlocks *blocks;
    NetThreadState *g;

    blocks = c->blocks;
    auth = (PppChap *)c->opts;
    if (lobby_session_flags & 2) {
        auth->active = 1;
        fsm_restart_timer(c);
        ppp_fsm_send_packet(c, 1, 0, build_avetcp_net_buffer(c));
    } else {
        auth->active = 0;
    }
    g = &net_thread_state;
    c->abort = 0;
    while (c->state != 5) {
        if (is_timed_out() != 0 || c->abort != 0 || blocks->phase == 4) {
            c->abort = 0;
            if (ppp_auth_failed != 0) {
                lobby_modem_error = 6;
            } else {
                lobby_modem_error = 5;
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
PppChapAuthenticationState ppp_chap_authentication_state;
PppAuthState chap_state;
/* The challenge length and the response reader's scratch byte, in reverse definition order. */
u16 chap_challenge_length;
u8 chap_read_byte_buffer;
void PP_chap_init(PppProtoBlocks *connection) {
    PppFsm *fsm = &connection->chap;
    PppFsmTimer *timer;

    if (fsm->opts == NULL) {
        timer = &fsm->timer;
        ppp_chap_authentication_state.proto.name = chap_protocol_name;
        ppp_chap_authentication_state.proto.proto = 0xC223;
        ppp_chap_authentication_state.proto.code_mask = 0x70;
        ppp_chap_authentication_state.proto.tx_counter_index = 3;
        ppp_chap_authentication_state.proto.max_terminate_attempts = 0;
        ppp_chap_authentication_state.proto.max_request_attempts = chap_state.max_request_attempts;
        ppp_chap_authentication_state.proto.max_peer_attempts = chap_state.max_peer_attempts;
        ppp_chap_authentication_state.proto.timeout = chap_state.timeout_secs * 1000;
        ppp_chap_authentication_state.proto.release_resources = fsm_noop_action;
        ppp_chap_authentication_state.proto.reset_options = fsm_noop_action;
        ppp_chap_authentication_state.proto.start_negotiation = fsm_noop_action;
        ppp_chap_authentication_state.proto.link_opened = fsm_noop_action;
        ppp_chap_authentication_state.proto.link_closed = fsm_noop_action;
        ppp_chap_authentication_state.proto.finish_termination = fsm_noop_action;
        ppp_chap_authentication_state.proto.build_config_request = build_avetcp_net_buffer;
        ppp_chap_authentication_state.proto.check_config_request = fsm_noop_check;
        ppp_chap_authentication_state.proto.check_config_ack = fsm_noop_check;
        ppp_chap_authentication_state.proto.check_config_nak = fsm_noop_check;
        ppp_chap_authentication_state.proto.check_config_reject = fsm_noop_check;
        fsm->blocks = connection;
        fsm->proto = &ppp_chap_authentication_state.proto;
        fsm->opts = &ppp_chap_authentication_state.options;
        fsm->max_request_attempts = fsm->proto->max_request_attempts;
        fsm->max_peer_attempts = fsm->proto->max_peer_attempts;
        fsm->max_terminate_attempts = fsm->proto->max_terminate_attempts;
        fsm->state = 0;
        fsm->retries = fsm->max_request_attempts;
        fsm->peer_attempts_left = fsm->max_peer_attempts;
        timer->callback = chap_request_timeout;
        timer->arg = fsm;
        lobby_timer_add(timer, fsm->proto->timeout);
    }
}

s32 PP_chap_remote(PppProtoBlocks *blocks) {
    blocks->chap.state = 2;
    blocks->chap.flags = (u8) (blocks->chap.flags | 0x20);
    blocks->auth_pending = (u8) (blocks->auth_pending | 0x20);
    return 0;
}

s32 PP_chap_local(PppProtoBlocks *blocks) {
    PppFsm *s = &blocks->chap;
    s->state = 1;
    s->flags |= 0x10;
    blocks->auth_pending |= 0x10;
    s->retries = s->max_request_attempts;
    return 0;
}


void chap_input(PppFsm *self, PppFrame *source) {
    PppHeader hdr;
    u8 flags;
    PppProtoBlocks *blocks;

    if (fsm_read_header(&hdr, &source) != -1) {
        hdr.len -= 4;
        ppp_buffer_truncate(&source, hdr.len);
        switch (hdr.code) {
        case 1:
            chap_recv_challenge(self, &hdr, source);
            return;
        case 2:
            if (chap_recv_response(self, &hdr, source) == 0) {
                if (lobby_session_flags & 2) {
                    blocks = self->blocks;
                    lobby_timer_stop(&self->timer);
                    flags = self->flags & 0xFFFFFFEF;
                    self->flags = flags;
                    if (!(flags & 0x10)) {
                        self->state = 5;
                    }
                    blocks->auth_pending = (u8) (blocks->auth_pending & 0xFFFFFFEF);
                    blocks->auth_pending = (u8) (blocks->auth_pending & 0xFFFFFFDF);
                    start_ipcp_after_auth(blocks);
                    return;
                }
                blocks = self->blocks;
                lobby_timer_stop(&self->timer);
                flags = self->flags & 0xFFFFFFDF;
                self->flags = flags;
                if (!(flags & 0x10)) {
                    self->state = 5;
                }
                blocks->auth_pending = (u8) (blocks->auth_pending & 0xFFFFFFDF);
                start_ipcp_after_auth(blocks);
                return;
            }
            break;
        case 3:
            lobby_timer_stop(&self->timer);
            blocks = self->blocks;
            lobby_timer_stop(&self->timer);
            flags = self->flags & 0xFFFFFFEF;
            self->flags = flags;
            if (!(flags & 0x10)) {
                self->state = 5;
            }
            blocks->auth_pending = (u8) (blocks->auth_pending & 0xFFFFFFEF);
            blocks->auth_pending = (u8) (blocks->auth_pending & 0xFFFFFFDF);
            start_ipcp_after_auth(blocks);
            return;
        case 4:
            lobby_timer_stop(&self->timer);
            blocks = self->blocks;
            update_connection_state(&blocks->chap);
            update_connection_state(&blocks->lcp);
            self->abort = 1;
            ppp_auth_failed = 1;
            break;
        }
    }
}

s32 chap_set_secret(u8 *source, u8 *chap_secret, PppFsm *fsm) {
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

void chap_request_timeout(PppFsm *c) {
    PppFrame *buf;
    PppChap *chap = (PppChap *)c->opts;
    PppProtoBlocks *sub;

    if (chap->active != 0) {
        if (c->retries != 0) {
            chap->msg = "Request timeout";
            fsm_send_config_request(c);
            return;
        }
        chap->msg = "Request retry exceeded";
        sub = c->blocks;
        update_connection_state(&sub->chap);
        update_connection_state(&sub->lcp);
        c->abort = 1;
        return;
    }
    if (c->retries != 0) {
        buf = ppp_buffer_from_bytes(chap_state.response, chap->len);
        ppp_fsm_send_packet(c, 2, chap->id, buf);
        lobby_timer_start(&c->timer);
        c->retries--;
        return;
    }
    sub = c->blocks;
    update_connection_state(&sub->chap);
    update_connection_state(&sub->lcp);
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
        p = value = chap_state.rx_value;
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
        q = name = chap_state.rx_name;
        for (j = 0; j < m; j++) {
            *q++ = chap_read_byte(&v);
        }
        *q = 0;
    }
    if (lobby_session_flags & 2) {
        secret = ppp_find_auth_secret((const char *)name);
        if (secret == NULL) {
            NetCopyString(chap_state.message, chap_failure_message);
            reply = ppp_buffer_from_bytes(chap_state.message, NetStringLength(chap_state.message));
            ppp_fsm_send_packet(c, 4, hdr->id, reply);
            return -1;
        }
    }
    *chap_state.hash_input = hdr->id;
    if (lobby_session_flags & 2) {
        NetCopyString((char *)chap_state.hash_input + 1, secret);
    } else {
        NetCopyString((char *)chap_state.hash_input + 1, chap->secret);
    }
    if (lobby_session_flags & 2) {
        len = NetStringLength(secret);
    } else {
        len = NetStringLength(chap->secret);
    }
    init_md5_state(&ctx);
    MD5Update(&ctx, chap_state.hash_input, len + 1);
    MD5Update(&ctx, chap_state.tx_challenge + 1, chap_challenge_length);
    MD5Final((u8 *)chap_state.message, &ctx);
    if (NetMemcmp(chap_state.message, value, 0x10) == 0) {
        NetCopyString(chap_state.message, "Wellcome!!");
        code = 3;
        ret = 0;
    } else if (lobby_session_flags & 2) {
        NetCopyString(chap_state.message, chap_failure_message);
        code = 4;
        ret = -1;
    } else {
        NetCopyString(chap_state.message, "Wellcome!!");
        code = 3;
        ret = 0;
    }
    reply = ppp_buffer_from_bytes(chap_state.message, NetStringLength(chap_state.message));
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
inline void chap_session_down(PppProtoBlocks *blocks) {
    update_connection_state(&blocks->chap);
    update_connection_state(&blocks->lcp);
}
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
        challenge_cursor = (challenge_slot.value = chap_state.rx_challenge);
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
        peer_name = chap_state.rx_challenge_name;
        for (peer_name_index = 0; peer_name_index < peer_name_length; peer_name_index++) {
            *peer_name++ = chap_read_byte(&source);
        }
        *peer_name = 0;
    }
    *chap_state.response_input = header->id;
    NetCopyString((char *)chap_state.response_input + 1, chap->secret);
    string_length = NetStringLength(chap->secret);
    raw_name_length = NetStringLength(chap->name);
    challenge_offset = string_length + 1;
    string_length = raw_name_length;
    NetMemcpy(chap_state.response_input + challenge_offset, challenge_slot.value, challenge_length);
    NetMemset(chap_state.response, 0, chap_state.response_size);
    *chap_state.response = 0x10;
    init_md5_state(&context);
    MD5Update(&context, chap_state.response_input, challenge_offset + challenge_length);
    MD5Final(chap_state.response + 1, &context);
    {
        u32 response_name_length = string_length;
        NetMemcpy(chap_state.response + 0x11, chap->name, response_name_length);
    }
    chap->id = header->id;
    chap->len = string_length + 0x11;
    reply = ppp_buffer_from_bytes(chap_state.response, chap->len);
    ppp_fsm_send_packet(connection, 2, chap->id, reply);
    lobby_timer_start(&connection->timer);
    connection->retries--;
    if (connection->peer_attempts_left != 0) {
        connection->peer_attempts_left--;
    } else {
        chap_session_down(connection->blocks);
    }
}
#pragma pop
