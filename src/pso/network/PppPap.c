/* PPP PAP, the protocol that names itself "Pap", and its state objects (a C library, built with GC/1.2.5n). */
#include "types.h"
#include "pso/network/PppApi.h"
#include "pso/network/PppChap.h"
#include "pso/network/Ppp.h"
#include "pso/network/NetStack.h"
#include "pso/network/NetIpv6Route.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/PppVj.h"
#include "pso/network/NetworkTransport.h"

#include "pso/network/NetStackTypes.h"

#include "pso/network/PppBuffer.h"
#include "pso/network/PppFsm.h"


void init_net_block_620(void) {
    term_pap_config(&pap_state);
}

s32 init_net_block_620_secondary(void) {
    init_net_block_620_params(&pap_state);
    return 0;
}

s16 PP_pap_monitor(PppFsm *fsm, u32 timeout) {
    PppFsm *c = fsm;
    NetThreadState *g;
    PppProtoBlocks *blocks;

    blocks = c->blocks;
    g = &net_thread_state;
    c->abort = 0;
    while (c->state != 5) {
        if (is_timed_out() != 0 || c->abort != 0 || blocks->phase == 4) {
            update_connection_state(c);
            update_connection_state(&c->blocks->lcp);
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
            update_connection_state(c);
            update_connection_state(&c->blocks->lcp);
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

PppFrame *pap_build_auth_request(PppFsm *fsm);
void PP_pap_init(PppProtoBlocks *blocks) {
    PppPapAuthenticationState *g;
    PppFsmProtocol *p;
    PppFsm *fsm;
    PppFsmTimer *timer;

    g = &ppp_pap_authentication_state;
    p = &g->proto;
    fsm = &blocks->pap;
    if (fsm->opts == NULL) {
        timer = &fsm->timer;
        p->name = "Pap";
        p->proto = 0xC023;
        p->code_mask = 0xE;
        p->tx_counter_index = 1;
        p->max_terminate_attempts = 0;
        /* The settings follow the options and name buffers in BSS. */
        p->max_request_attempts = *(u8 *)((uaddr)g + (sizeof(*g) + offsetof(PppPapState, max_request_attempts)));
        p->max_peer_attempts = *(u8 *)((uaddr)g + (sizeof(*g) + offsetof(PppPapState, max_peer_attempts)));
        p->timeout = *(u16 *)((uaddr)g + (sizeof(*g) + offsetof(PppPapState, timeout_secs))) * 1000;
        p->release_resources = fsm_noop_action;
        p->reset_options = fsm_noop_action;
        p->start_negotiation = fsm_noop_action;
        p->link_opened = fsm_noop_action;
        p->link_closed = fsm_noop_action;
        p->finish_termination = fsm_noop_action;
        p->build_config_request = pap_build_auth_request;
        p->check_config_request = fsm_noop_check;
        p->check_config_ack = fsm_noop_check;
        p->check_config_nak = fsm_noop_check;
        p->check_config_reject = fsm_noop_check;
        fsm->blocks = blocks;
        fsm->proto = p;
        fsm->opts = &g->options;
        fsm->max_request_attempts = fsm->proto->max_request_attempts;
        fsm->max_peer_attempts = fsm->proto->max_peer_attempts;
        fsm->max_terminate_attempts = fsm->proto->max_terminate_attempts;
        fsm->state = 0;
        fsm->retries = fsm->max_request_attempts;
        fsm->peer_attempts_left = fsm->max_peer_attempts;
        timer->callback = handle_request_timeout;
        timer->arg = fsm;
        lobby_timer_add(timer, fsm->proto->timeout);
    }
}

s32 PP_pap_remote(PppProtoBlocks *blocks) {
    PppFsm *fsm = &blocks->pap;
    fsm->state = 2;
    fsm->flags |= 0x20;
    blocks->auth_pending |= 0x20;
    return 0;
}

void PP_pap_local(PppProtoBlocks *blocks) {
    PppFsm *fsm = &blocks->pap;
    fsm->state = 1;
    fsm->flags |= 0x10;
    blocks->auth_pending |= 0x10;
    fsm->retries = fsm->max_request_attempts;
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_lifetimes off
#pragma dont_inline off
#pragma inline_depth(4)
u8 pap_read_byte_buffer[8];
static inline PapOptions *pap_options(PppFsm *connection) {
    return (PapOptions *)connection->opts;
}

static inline u8 **pap_message_buffer(void) {
    u8 **value = (u8 **)&pap_state.message;
    return value;
}
static inline s16 pap_read_reply_message(PapOptions *options, u8 actual_id, u8 expected_id, PppFrame *source) {
    s32 result;
    u8 **destination;
    s32 copied;
    u32 available;
    s16 requested;
    if (actual_id != expected_id) {
        return -1;
    }
    requested = ppp_buffer_read(&source, pap_read_byte_buffer, 1) != 1 ? -1 : (s16)pap_read_byte_buffer[0];
    if (requested != -1) {
        if (requested != 0) {
            available = ppp_frame_length(source);
            destination = pap_message_buffer();
            copied = (s16)ppp_buffer_copy_out(source, *destination, requested);
            (*destination)[copied] = 0;
            options->message = *destination;
            result = 1;
            if (copied < requested || requested < (s16)available) {
            } else {
                result = 0;
            }
            return result;
        }
        return 0;
    }
    return -1;
}

static inline void pap_auth_done(PppFsm *self, u32 pending_bit) {
    PppProtoBlocks *link = self->blocks;
    self->flags &= ~pending_bit;
    if (!(self->flags & 0x30)) {
        self->state = 5;
    }
    lobby_timer_stop(&self->timer);
    link->auth_pending &= ~pending_bit;
    start_ipcp_after_auth(link);
}
void PP_pap_proc(PppFsm *self, PppFrame *source) {
    PppFsm *connection;
    PppHeader header;
    PapOptions *options;
    options = pap_options(self);
    if (fsm_read_header(&header, &source)) {
        return;
    }
    header.len -= 4;
    connection = self;
    ppp_buffer_truncate(&source, header.len);
    switch (header.code) {
    case 1:
        if (pap_recv_auth_request(connection, &header, source)) {
            return;
        }
        pap_auth_done(connection, 0x10);
        return;
    case 2:
        if (pap_read_reply_message((PapOptions *)connection->opts, header.id, connection->id, source) != 0) {
            return;
        }
        pap_auth_done(self, 0x20);
        return;
    case 3:
        if (pap_read_reply_message((PapOptions *)self->opts, header.id, self->id, source) != 0) {
            return;
        }
        lobby_timer_stop(&connection->timer);
        options->peer_id = NULL;
        options->password = NULL;
        connection->abort = 1;
        self->state = 0;
        ppp_auth_failed = 1;
        return;
    }
}

#pragma pop

s32 pap_set_secret(u8 *source, u8 *pap_password, PppFsm *ppp_fsm) {
    PppPapAuthenticationState *g;
    PapOptions *opts;
    u32 n;
    u32 m;
    opts = (PapOptions *)ppp_fsm->opts;
    g = &ppp_pap_authentication_state;
    n = NetStringLength((const char *)(source));
    if (n >= 0x80) {
        n = 0x7F;
    }
    NetMemcpy(g->peer_id, source, n);
    g->peer_id[n] = 0;
    m = NetStringLength((const char *)(pap_password));
    if (m >= 0x80) {
        m = 0x7F;
    }
    NetMemcpy(g->password, pap_password, m);
    g->password[m] = 0;
    opts->peer_id = g->peer_id;
    opts->password = g->password;
    return 0;
}

void PP_pap_down(PppFsm *fsm) {
    if (fsm->opts != NULL) {
        fsm->flags = 0;
        switch (fsm->state) {
        case 0:
            break;
        case 2:
            lobby_timer_stop(&fsm->timer);
        case 1:
        case 5:
        case 6:
            fsm->state = 0;
            break;
        }
    }
}

void handle_request_timeout(PppFsm *self) {
    PppFsm *fsm;
    PapOptions *opts;

    fsm = (PppFsm *)self;
    opts = (PapOptions *)fsm->opts;
    if (fsm->retries != 0) {
        opts->message = (u8 *)"Request timeout";
        fsm_send_config_request(fsm);
        return;
    }
    opts->message = (u8 *)"Request retry exceeded";
    update_connection_state(&fsm->blocks->lcp);
    fsm->abort = 1;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
static inline s32 frame_valid(PppFrame **s) {
    s32 r = 0;
    if (s != NULL && *s != NULL) {
        r = 1;
    }
    return r;
}
static inline s32 frame_has_byte(PppFrame **s) {
    s32 r = 0;
    if (frame_valid(s) && (*s)->len > 1) {
        r = 1;
    }
    return r;
}
static inline s32 frame_get_byte(PppFrame **s) {
    if (frame_has_byte(s)) {
        (*s)->len--;
        return *(*s)->data++;
    }
    if (ppp_buffer_read(s, pap_read_byte_buffer, 1) != 1) {
        return -1;
    }
    return (s16)pap_read_byte_buffer[0];
}
s16 pap_recv_auth_request(PppFsm *fsm, PppHeader *header, PppFrame *val) {
    u8 *p1 = 0;
    u8 *p2 = 0;
    s16 ch;
    s16 res;
    const char *secret;
    s16 st;
    u8 *ptr;
    s16 n;
    PppFrame *ent;

    ch = (ppp_buffer_read(&val, pap_read_byte_buffer, 1) != 1) ? -1 : (s16)pap_read_byte_buffer[0];
    if (ch != -1) {
        s16 cnt;
        u8 *out;
        p1 = pap_state.peer_id;
        out = p1;
        for (cnt = ch; cnt-- > 0;) {
            *out++ = frame_get_byte(&val);
        }
        *out = 0;
    }

    ch = (ppp_buffer_read(&val, pap_read_byte_buffer, 1) != 1) ? -1 : (s16)pap_read_byte_buffer[0];
    if (ch != -1) {
        s16 cnt;
        u8 *out;
        p2 = pap_state.password;
        out = p2;
        for (cnt = ch; cnt-- > 0;) {
            *out++ = frame_get_byte(&val);
        }
        *out = 0;
    }

    if (lobby_session_flags & 2) {
        secret = ppp_find_auth_secret((const char *)p1);
        if (secret == NULL) {
            res = -1;
        } else if (NetCompareStrings((const char *)p2, secret) != 0) {
            res = -1;
        } else {
            goto zero;
        }
    } else {
zero:
        res = 0;
    }

    if (res == 0) {
        fsm->blocks->pap_peer_id = p1;
        ptr = (u8 *)" Welcome";
        st = 2;
    } else {
        ptr = (u8 *)" Invalid username or password";
        st = 3;
    }
    n = (s16)NetStringLength((const char *)(ptr));
    ent = ppp_buffer_from_bytes(ptr, n);
    *ent->data = n - 1;
    ppp_fsm_send_packet(fsm, st, header->id, ent);

    if (st == 3) {
        if (fsm->peer_attempts_left != 0) {
            fsm->peer_attempts_left--;
        } else {
            update_connection_state(&fsm->blocks->lcp);
        }
    }
    return st != 2;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
PppFrame *pap_build_auth_request(PppFsm *fsm) {
    PppFrame *blk;
    PapOptions *opts;
    u8 *buf;
    s32 n1;
    s32 n2;
    s32 len;
    u16 old;

    opts = (PapOptions *)fsm->opts;
    if (opts->peer_id == NULL || opts->password == NULL) {
        return NULL;
    }
    blk = init_net_buffer_entry(0);
    if (blk == NULL) {
        return NULL;
    }
    buf = blk->data;
    n1 = NetStringLength((const char *)opts->peer_id);
    *buf++ = n1;
    NetMemcpy(buf, opts->peer_id, n1);
    buf += n1;
    n2 = NetStringLength((const char *)opts->password);
    *buf++ = n2;
    NetMemcpy(buf, opts->password, n2);
    old = blk->len;
    len = n1 + n2;
    if (!len && !len) {
    }
    len += old;
    blk->len = len + 2;
    return blk;
}
#pragma pop

PppPapState pap_state;
PppPapAuthenticationState ppp_pap_authentication_state;
