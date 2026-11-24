/* PPP PAP, the protocol that names itself "Pap", and its state objects (a C library, built with GC/1.2.5n). */
#include "types.h"
#include "pso/network/TLobby_803FAEA0.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/NetworkTransport.h"

#include "pso/network/NetStackTypes.h"

s32 TLobby__sub_803F778C(void *);
void net_sleep_ms(int);
#include "pso/network/PppBuffer.h"
#include "pso/network/PppFsm.h"


void init_net_block_620(void) {
    TLobby__sub_803F778C(&lbl_805C0620);
}

s32 init_net_block_620_secondary(void) {
    init_net_block_620_params(&lbl_805C0620);
    return 0;
}

s16 PP_pap_monitor(void *arg0, u32 timeout) {
    PppFsm *c = (PppFsm *)arg0;
    NetThreadState *g;
    u8 *sub;

    sub = c->sub;
    g = &lbl_805C18A0;
    c->abort = 0;
    while (c->state != 5) {
        if (is_timed_out() != 0 || c->abort != 0 || *sub == 4) {
            update_connection_state(c);
            update_connection_state(c->sub + 4);
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
            update_connection_state(c);
            update_connection_state(c->sub + 4);
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

PppFrame *TLobby__sub_80403634(PppFsm *fsm);
void pap_init(u8 *arg0) {
    PppPapAuthenticationState *g;
    PppFsmProtocol *p;
    PppFsm *fsm;
    PppFsmTimer *timer;

    g = &ppp_pap_authentication_state;
    p = &g->proto;
    fsm = (PppFsm *)(arg0 + 0x38);
    if (fsm->opts == NULL) {
        timer = &fsm->timer;
        p->name = "Pap";
        p->proto = 0xC023;
        p->h6 = 0xE;
        p->tx_counter_index = 1;
        p->max_terminate_attempts = 0;
        /* The settings follow the options and name buffers in BSS. */
        p->max_request_attempts = *(u8 *)((uaddr)g + (sizeof(*g) + offsetof(PppPapState, f12)));
        p->max_peer_attempts = *(u8 *)((uaddr)g + (sizeof(*g) + offsetof(PppPapState, f13)));
        p->timeout = *(u16 *)((uaddr)g + (sizeof(*g) + offsetof(PppPapState, f14))) * 1000;
        p->release_resources = TLobby__sub_803FE84C;
        p->reset_options = TLobby__sub_803FE84C;
        p->start_negotiation = TLobby__sub_803FE84C;
        p->link_opened = TLobby__sub_803FE84C;
        p->link_closed = TLobby__sub_803FE84C;
        p->finish_termination = TLobby__sub_803FE84C;
        p->build_config_request = TLobby__sub_80403634;
        p->check_config_request = TLobby__sub_803FE844;
        p->check_config_ack = TLobby__sub_803FE844;
        p->check_config_nak = TLobby__sub_803FE844;
        p->check_config_reject = TLobby__sub_803FE844;
        fsm->sub = arg0;
        fsm->proto = p;
        fsm->opts = &g->options;
        fsm->f4 = fsm->proto->max_request_attempts;
        fsm->f7 = fsm->proto->max_peer_attempts;
        fsm->f5 = fsm->proto->max_terminate_attempts;
        fsm->state = 0;
        fsm->retries = fsm->f4;
        fsm->f6 = fsm->f7;
        timer->callback = handle_request_timeout;
        timer->arg = fsm;
        lobby_timer_add((N_80405298 *)timer, fsm->proto->timeout);
    }
}

s32 mark_ready(void *self) {
    u8 *link = (u8 *)self;
    PppFsm *fsm = (PppFsm *)(link + 0x38);
    fsm->state = 2;
    fsm->f2 |= 0x20;
    link[2] |= 0x20;
    return 0;
}

void set_active(void *self) {
    u8 *link = (u8 *)self;
    PppFsm *fsm = (PppFsm *)(link + 0x38);
    fsm->state = 1;
    fsm->f2 |= 0x10;
    link[2] |= 0x10;
    fsm->retries = fsm->f4;
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
    u8 **value = (u8 **)&lbl_805C0620.message;
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
            available = get_field_4(source);
            destination = pap_message_buffer();
            copied = (s16)TLobby__sub_80401ABC((u8 *)source, *destination, requested);
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
    u8 *link = self->sub;
    ((u8 *)self)[2] &= ~pending_bit;
    if (!(((u8 *)self)[2] & 0x30)) {
        self->state = 5;
    }
    lobby_timer_stop(&self->timer);
    link[2] &= ~pending_bit;
    start_ipcp_after_auth((O_80400ACC *)link);
}
void pap_input(PppFsm *self, PppFrame *source) {
    PppFsm *connection;
    PppHeader header;
    PapOptions *options;
    options = pap_options(self);
    if (TLobby__sub_803FE8BC(&header, &source)) {
        return;
    }
    header.len -= 4;
    connection = self;
    TLobby__sub_80401CAC(&source, header.len);
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

s32 TLobby__sub_80403168(u8 *source, u8 *pap_password, u8 *ppp_fsm) {
    PppPapAuthenticationState *g;
    PapOptions *opts;
    u32 n;
    u32 m;
    opts = (PapOptions *)((PppFsm *)ppp_fsm)->opts;
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

void PP_pap_down(void *self) {
    PppFsm *fsm;

    fsm = (PppFsm *)self;
    if (fsm->opts != NULL) {
        fsm->f2 = 0;
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
        TLobby__sub_803FE658(fsm);
        return;
    }
    opts->message = (u8 *)"Request retry exceeded";
    update_connection_state(fsm->sub + 4);
    fsm->abort = 1;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline s32 valid_80403308(PppFrame **s) {
    s32 r = 0;
    if (s != NULL && *s != NULL) {
        r = 1;
    }
    return r;
}
inline s32 avail_80403308(PppFrame **s) {
    s32 r = 0;
    if (valid_80403308(s) && (*s)->len > 1) {
        r = 1;
    }
    return r;
}
inline s32 get_80403308(PppFrame **s) {
    if (avail_80403308(s)) {
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
        p1 = lbl_805C0620.peer_id;
        out = p1;
        for (cnt = ch; cnt-- > 0;) {
            *out++ = get_80403308(&val);
        }
        *out = 0;
    }

    ch = (ppp_buffer_read(&val, pap_read_byte_buffer, 1) != 1) ? -1 : (s16)pap_read_byte_buffer[0];
    if (ch != -1) {
        s16 cnt;
        u8 *out;
        p2 = lbl_805C0620.password;
        out = p2;
        for (cnt = ch; cnt-- > 0;) {
            *out++ = get_80403308(&val);
        }
        *out = 0;
    }

    if (lbl_805D7A90 & 2) {
        secret = TLobby__sub_803F7684((const char *)p1);
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
        ((PppFsmLink *)fsm->sub)->pap_peer_id = p1;
        ptr = (u8 *)" Welcome";
        st = 2;
    } else {
        ptr = (u8 *)" Invalid username or password";
        st = 3;
    }
    n = (s16)NetStringLength((const char *)(ptr));
    ent = TLobby__sub_80401B20(ptr, n);
    *ent->data = n - 1;
    ppp_fsm_send_packet(fsm, st, header->id, ent);

    if (st == 3) {
        if (fsm->f6 != 0) {
            fsm->f6--;
        } else {
            update_connection_state(fsm->sub + 4);
        }
    }
    return st != 2;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
PppFrame *TLobby__sub_80403634(PppFsm *fsm) {
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

PppPapState lbl_805C0620;
PppPapAuthenticationState ppp_pap_authentication_state;
