/* The network stack's transport (a C library, built with GC/1.2.5n): the modem/PPPoE send path with its ring buffer
 * and queue thread, the start-up parameters, and the functions that fill the stack's configuration records with
 * this file's static buffers. */
#include "pso/network/NetworkRuntimeSlots.h"
#include "pso/network/NetworkTransport.h"
#include "pso/network/ModemRuntime.h"
#include "dolphin/os/OSThread.h"
#include "pso/network/NetPppLink.h"
#include "pso/network/NetStackTypes.h"
#include "pso/network/netcfg.h"
#include "pso/network/TLobby_80426CAC.h"
#include "pso/network/TLobby_80428374.h"

#include "types.h"

/* The CHAP and PAP buffers init_net_buffer_table and init_net_block_620_params hand out (PppAuthState, PppPapState). */
typedef struct PppAuthBuffers {
    u8 auth20[0x100];
    u8 auth1C[0x100];
    u8 auth18[0x184];           /* 0x181 used */
    u8 auth14[0x184];           /* 0x181 used */
    u8 auth10[0x100];
    u8 authC[0x100];
    u8 auth8[0x80];
    u8 auth4[0x80];
    u8 auth0[0x80];
    u8 pap_message[0x100];
    u8 pap_password[0x80];
    u8 pap_peer_id[0x80];
} PppAuthBuffers;
LAYOUT_ASSERT(PppAuthBuffers_size, sizeof(PppAuthBuffers) == 0xA88);

typedef struct NetworkPacketBufferStorage {
    u8 packet_slots[4][1500];
    u32 workspace_70_a[70];
    u32 workspace_550_a[550];
    u32 workspace_550_b[550];
    u32 workspace_1030[1030];
    u32 workspace_70_b[70];
    u32 workspace_550_pair[2][550];
} NetworkPacketBufferStorage;
LAYOUT_ASSERT(NetworkPacketBufferStorage_size, sizeof(NetworkPacketBufferStorage) == 0x4C18);



typedef struct NetSendChunk {
    u8 *data;
    s32 length;
} NetSendChunk;
LAYOUT_ASSERT(NetSendChunkSize, sizeof(NetSendChunk) == 8);

void net_sleep_ms(s32);
s32 TLobby__sub_80428094(s16);
void run_net_thread_loop(void);
void subtract_network_queue_timeout(s32 elapsed_ms);
void set_lobby_map_state_code(s32 code);
NetSendChunk *get_next_send_chunk(void);
s32 AT_SetWorkArea(u8 *data, s32 size);
s32 AT_GetInitParam(NetTransportParams *arg0);
void TLobby__sub_803F76F0(void);
void TLobby__sub_803F778C(void);
void TLobby__sub_803F77E0(void);
void TLobby__sub_803F7980(void);
void TLobby__sub_803F79AC(void);
void TLobby__sub_803F79BC(void);
u32 compute_range_end(NetTransportParams *params, s32 base, u32 limit);

/* CodeWarrior emits these .sbss globals in reverse order of definition. */
s16 net_slot_id = -1;
s32 lobby_send_chunk_size;
s16 network_pppoe_transport_enabled;
s32 queue_timeout_remaining;
s32 lobby_map_state_code;
NetSendChunk next_send_chunk;
s32 lobby_send_ring_pending_bytes;
s32 lobby_send_ring_read_pos;
s32 lobby_ring_buffer_write_pos;
s32 lobby_ring_buffer_size;
u8 *send_ring_buffer_base;
s32 send_ring_mutex;
NetThreadHandle queue_thread_handle;
/* inferred: PppLink.used for the 4 packet slots init_buffer_desc_b hands out */
s16 packet_buffer_used[4];
/* the modem script's integer variables (ModemSessionState.ints) */
s16 modem_script_ints[4];

__declspec(section ".sdata2") const char modem_tone_dial_command[] = "ATDT";
__declspec(section ".sdata2") const char modem_pulse_dial_command[] = "ATDP";
__declspec(section ".sdata2") const char modem_answer_command[] = "ATA";
__declspec(section ".sdata2") const char modem_ok_response[] = "OK";
__declspec(section ".sdata2") const char modem_connect_response[] = "CONNECT";
__declspec(section ".sdata2") const char modem_busy_response[] = "BUSY";
__declspec(section ".sdata2") const char modem_error_response[] = "ERROR";
__declspec(section ".sdata2") const char modem_delayed_response[] = "DELAYED";
__declspec(section ".sdata2") const char modem_ring_response[] = "RING";
__declspec(section ".sdata2") const char modem_default_connect_argument[] = "00";

static PppAuthBuffers ppp_auth_buffers;
static ModemConfig modem_default_config;
static u8 modem_rx_buf[0x80];
static u8 modem_window_buf[0x80];
static u8 modem_expect_buf[0x80];
static u8 modem_out_buf[0x80];
static u8 modem_cmd_buf[0x80];
static u8 modem_token_buf[0x80];
static u8 modem_line_buf[0x80];
static ModemFieldSlot modem_script_fields[4];
static char modem_script_strings[4][0x80];
static const char *modem_script_subst[6];
static NetworkPacketBufferStorage network_packet_buffer_storage;
static PppoeNames pppoe_discovery_name_storage;
static const char modem_no_carrier_response[] = "NO CARRIER";
static const char modem_no_dialtone_response[] = "NO DIALTONE";
static const char modem_initialization_script[] = "send \"AT&FE0\\r\"\nwait \"OK\\r\\n\",3\nsend \"ATS0=1\\r\"\nwait \"OK\\r\\n\",3\nsend \"ATW2\\r\"\nwait \"OK\\r\\n\",3\nsend \"ATX3&C1&D2\\r\"\nwait \"OK\\r\\n\",3\n";
static const char modem_dial_script[] = "dial \"%t\"\n";

void TLobby__sub_803F76F0(void) {

}

void init_net_buffer_table(PppAuthState *auth) {
    auth->p0 = ppp_auth_buffers.auth0;
    auth->p4 = ppp_auth_buffers.auth4;
    auth->p8 = ppp_auth_buffers.auth8;
    auth->pC = ppp_auth_buffers.authC;
    auth->p10 = ppp_auth_buffers.auth10;
    auth->p14 = ppp_auth_buffers.auth14;
    auth->p18 = ppp_auth_buffers.auth18;
    auth->p1C = ppp_auth_buffers.auth1C;
    auth->p20 = (char *)ppp_auth_buffers.auth20;
    auth->size0 = 0x80;
    auth->size4 = 0x80;
    auth->size8 = 0x80;
    auth->sizeC = 0x100;
    auth->size10 = 0x100;
    auth->size14 = 0x181;
    auth->size18 = 0x181;
    auth->size1C = 0x100;
    auth->size20 = 0x100;
    auth->f36 = 0xA;
    auth->f37 = 5;
    auth->f38 = 3;
}

void TLobby__sub_803F778C(void) {

}

void init_net_block_620_params(PppPapState *pap) {
    pap->peer_id = ppp_auth_buffers.pap_peer_id;
    pap->password = ppp_auth_buffers.pap_password;
    pap->message = ppp_auth_buffers.pap_message;
    pap->peer_id_size = 0x80;
    pap->password_size = 0x80;
    pap->message_size = 0x100;
    pap->f12 = 0xA;
    pap->f13 = 5;
    pap->f14 = 3;
}

void TLobby__sub_803F77E0(void) {

}

void init_modem_buffer_config(ModemSessionState *state) {
    state->subst = modem_script_subst;
    state->subst_count = 6;
    state->strbuf = modem_script_strings[0];
    state->strbuf_count = 4;
    state->strstride = 0x80;
    state->fields = modem_script_fields;
    state->field_count = 4;
    state->ints = modem_script_ints;
    state->int_count = 4;
    state->line = modem_line_buf;
    state->token = modem_token_buf;
    state->cmd = modem_cmd_buf;
    state->out = modem_out_buf;
    state->expect = modem_expect_buf;
    state->window = modem_window_buf;
    state->rxbuf = modem_rx_buf;
    state->line_len = 0x80;
    state->token_len = 0x80;
    state->cmd_len = 0x80;
    state->out_len = 0x80;
    state->expect_len = 0x80;
    state->window_len = 0x80;
    state->rxlen = 0x80;
    state->config = &modem_default_config;
    state->config->h0 = 1;
    state->config->h2 = 1;
    state->config->h4 = 1;
    state->config->h6 = 0;
    state->config->numeric_result = 1;
    state->config->tone_dial_command = modem_tone_dial_command;
    state->config->pulse_dial_command = modem_pulse_dial_command;
    state->config->answer_command = modem_answer_command;
    state->config->ok_response = modem_ok_response;
    state->config->connect_response = modem_connect_response;
    state->config->busy_response = modem_busy_response;
    state->config->error_response = modem_error_response;
    state->config->delayed_response = modem_delayed_response;
    state->config->no_carrier_response = modem_no_carrier_response;
    state->config->no_dialtone_response = modem_no_dialtone_response;
    state->config->ring_response = modem_ring_response;
    state->config->terminator = 0xD;
    state->config->init_script = modem_initialization_script;
    state->config->dial_script = modem_dial_script;
    state->config->hangup_script = 0;
}

void TLobby__sub_803F7980(void) {

}

void init_buffer_desc_b(PppLink *link) {
    link->used = packet_buffer_used;
    link->buffers = network_packet_buffer_storage.packet_slots[0];
    link->count = 4;
    link->size = 0x5DC;
}

void TLobby__sub_803F79AC(void) {

}

void TLobby__sub_803F79B0(NetThreadState *t) {
    t->poll_ms = 0x28;
}

void TLobby__sub_803F79BC(void) {

}

void init_net_buffer_desc(PppBuffers *bufs) {
    bufs->pool = (u8 *)network_packet_buffer_storage.workspace_550_pair;
    bufs->npool = 2;
    bufs->pool_words = 0x226;
    bufs->packet = (PppFrame *)network_packet_buffer_storage.workspace_70_b;
    bufs->frame_out = (PppFrame *)network_packet_buffer_storage.workspace_1030;
    bufs->ip_out = (PppFrame *)network_packet_buffer_storage.workspace_550_b;
    bufs->frame_in = (PppFrame *)network_packet_buffer_storage.workspace_550_a;
    bufs->reply = (PppFrame *)network_packet_buffer_storage.workspace_70_a;
    bufs->headroom = 0x18;
    bufs->packet_words = 0x46;
    bufs->frame_out_words = 0x406;
    bufs->ip_out_words = 0x226;
    bufs->frame_in_words = 0x226;
    bufs->reply_words = 0x46;
}

void stop_network_thread(void) {
    lock_mutex(net_thread_state.mutex);
    cancel_thread_if_running((void *)net_thread_state.thread);
    deactivate_entry_by_key(net_thread_state.thread);
    unlock_mutex(net_thread_state.mutex);
    NetReleaseMutex(net_thread_state.mutex);
}

void start_network_thread(void) {
    if (TLobby__sub_803F96AC(&net_thread_state.mutex) < 0 || TLobby__sub_803F9B94(run_net_thread_loop, &net_thread_state.thread) < 0) {
        return;
    }
    NetResumeThread(net_thread_state.thread);
}

/* Send thread: takes chunks from the send ring and hands them to the modem, waiting for each to drain. */
void queue_thread_main(void) {
    NetSendChunk *p;
    for (;;) {
        p = get_next_send_chunk();
        if (p == NULL) {
            NetSuspendCurrentThread();
            continue;
        }
        queue_timeout_remaining = p->length;
        for (;;) {
            if (fn_8042E184() == 0) {
                if (fn_8042DD70(p->data, p->length, subtract_network_queue_timeout) == 1) {
                    break;
                }
            }
            NetYieldThread();
        }
        for (;;) {
            if (queue_timeout_remaining <= 0) {
                break;
            }
            NetYieldThread();
        }
        NetYieldThread();
    }
}

/* Consumes the previous chunk and returns the next contiguous run (at most 0x200 bytes) of the send ring, or NULL. */
NetSendChunk *get_next_send_chunk(void) {
    s32 pos;
    lock_mutex(send_ring_mutex);
    lobby_send_ring_pending_bytes -= lobby_send_chunk_size;
    if (lobby_send_ring_pending_bytes <= 0) {
        lobby_send_ring_pending_bytes = 0;
        lobby_send_chunk_size = 0;
        unlock_mutex(send_ring_mutex);
        return NULL;
    }
    pos = lobby_send_ring_read_pos;
    if (pos + lobby_send_ring_pending_bytes >= lobby_ring_buffer_size) {
        lobby_send_chunk_size = lobby_ring_buffer_size - pos;
    } else {
        lobby_send_chunk_size = lobby_send_ring_pending_bytes;
    }
    if (lobby_send_chunk_size > 0x200) {
        lobby_send_chunk_size = 0x200;
    }
    lobby_send_ring_read_pos += lobby_send_chunk_size;
    if (lobby_send_ring_read_pos >= lobby_ring_buffer_size) {
        lobby_send_ring_read_pos = 0;
    }
    next_send_chunk.data = send_ring_buffer_base + pos;
    next_send_chunk.length = lobby_send_chunk_size;
    unlock_mutex(send_ring_mutex);
    return &next_send_chunk;
}

/* Appends len bytes to the send ring (wrapping) and wakes the send thread; returns 0 if there is no room. */
s32 write_ring_buffer(u8 *src, s32 len) {
    s32 first;
    s32 over;
    s32 end;
    s32 thread;
    u8 pad[8];
    thread = queue_thread_handle;
    lock_mutex(send_ring_mutex);
    if (lobby_ring_buffer_size - lobby_send_ring_pending_bytes < len) {
        unlock_mutex(send_ring_mutex);
        if (OSIsThreadSuspended((OSThread *)thread) == 1) {
            resume_thread(queue_thread_handle);
        }
        return 0;
    }
    end = lobby_ring_buffer_write_pos + len;
    if (end >= lobby_ring_buffer_size) {
        over = end - lobby_ring_buffer_size;
        first = len - over;
        NetMemcpy(send_ring_buffer_base + lobby_ring_buffer_write_pos, src, first);
        NetMemcpy(send_ring_buffer_base, src + first, over);
        lobby_ring_buffer_write_pos = over;
    } else {
        NetMemcpy(send_ring_buffer_base + lobby_ring_buffer_write_pos, src, len);
        lobby_ring_buffer_write_pos += len;
    }
    lobby_send_ring_pending_bytes += len;
    unlock_mutex(send_ring_mutex);
    if (OSIsThreadSuspended((OSThread *)thread) == 1) {
        resume_thread(queue_thread_handle);
    }
    return 1;
}

void set_lobby_map_state_code(s32 code) {
    lobby_map_state_code = code;
}

void subtract_network_queue_timeout(s32 elapsed_ms) {
    queue_timeout_remaining -= elapsed_ms;
}

/* Maps lobby_map_state_code to a mode id (-1 for state 4). */
s16 map_state_to_mode_id(void) {
    switch ((u32)lobby_map_state_code) {
    case 3:
        return 0;
    case 2:
        return 2;
    case 0:
        return 3;
    case 4:
        return -1;
    case 1:
        return 8;
    case 5:
        return 9;
    case 6:
        return 0xA;
    case 7:
        return 0xB;
    default:
        return 1;
    }
}

s32 map_state_to_code(const char *number, s16 kind) {
    s32 mode;
    switch (kind) {
    case 0:
        mode = 1;
        break;
    case 1:
        mode = 2;
        break;
    default:
        return -1;
    }
    lobby_map_state_code = 4;
    if (modem_dial(number, mode, set_lobby_map_state_code) != 1) {
        return -1;
    }
    return 0;
}

s32 configure_modem_options(s32 ms_mode, s32 error_correction, s32 compression, s32 count, char *cmd) {
    s32 value;
    s32 valid;
    u32 cmd_len;
    s32 result;
    valid = 1;
    switch (ms_mode) {
    case 1: value = 1; break;
    case 2: value = 2; break;
    case 3: value = 3; break;
    case 4: value = 4; break;
    case 5: value = 5; break;
    case 0: value = 2; break;
    default: valid = 0; break;
    }
    if (valid != 0 && MDMConnectMode(value) != 1) {
        return -1;
    }
    valid = 1;
    switch (error_correction) {
    case 1: value = 1; break;
    case 2: value = 2; break;
    case 3: value = 3; break;
    case 0:
    default: valid = 0; break;
    }
    if (valid != 0 && MDMErrorCorrectMode(value) != 1) {
        return -1;
    }
    valid = 1;
    switch (compression) {
    case 1: value = 1; break;
    case 2: value = 2; break;
    case 3: value = 3; break;
    case 4: value = 4; break;
    case 0:
    default: valid = 0; break;
    }
    if (valid != 0 && MDMCompressMode(value) != 1) {
        return -1;
    }
    while (count != 0) {
        cmd_len = NetStringLength(cmd);
        if (cmd_len > 0x3FU) {
            return -1;
        }
        result = modem_send_at_command(cmd);
        if (result != 1 && result != -8) {
            return -1;
        }
        cmd = (char *)(cmd_len + (uaddr)cmd);
        cmd++;
        count--;
    }
    return 0;
}

s32 send_atx_command_mode(s32 extended) {
    s32 mode;
    if (extended == 0) {
        mode = 1;
    } else {
        mode = 2;
    }
    if (MDMWaitToneMode(mode) == 1) {
        return 0;
    }
    return -1;
}

void TLobby__sub_803F808C(void) {

}

u16 is_transport_connected(void) {
    ModemConnectionInfo info;
    if (network_pppoe_transport_enabled != 0) {
        if (net_slot_id < 0) {
            return 0;
        }
        pppoe_recv_packet(NULL, 0, NULL);
        if (get_pppoe_session_id(net_slot_id) == 4) {
            return 1;
        }
        return 0;
    }
    if (copy_default_and_get_state(&info) == 3) {
        return 1;
    }
    return 0;
}

s32 TLobby__sub_803F811C(s16 *out) {
    *out = 0;
    return 0;
}

s32 recv_network_frame(u16 max_len, void *lobby, u16 *out_len) {
    if (network_pppoe_transport_enabled != 0) {
        if (net_slot_id < 0) {
            return 6;
        }
        {
            s16 slot = pppoe_recv_packet(lobby, max_len, out_len);
            if (slot != net_slot_id) {
                return 6;
            }
        }
    } else {
        s32 result = fn_8042D7E0(lobby);
        if (result < 0) {
            *out_len = 0;
        } else {
            *out_len = result;
        }
    }
    return 0;
}

/* Sends a frame over PPPoE or the modem send ring; returns 5 on failure. */
s32 send_network_frame(u16 len, u8 *src) {
    if ((s16) network_pppoe_transport_enabled != 0) {
        if ((s16) net_slot_id < 0) {
            return 5;
        }
        if (TLobby__sub_80427F48(net_slot_id, src, len) < 0) {
            return 5;
        }
        goto block_7;
    }
    if (((u16)write_ring_buffer(src, (s32) len)) == 0) {
        return 5;
    }
block_7:
    return 0;
}

void close_network_transport(void) {
    s32 tries;
    if ((s16) network_pppoe_transport_enabled != 0) {
        if ((s16) net_slot_id >= 0) {
            TLobby__sub_80428094(net_slot_id);
            tries = 0;
retry_close:
            net_sleep_ms(0xA);
            if ((pppoe_recv_packet(NULL, 0U, NULL) >= 0) && (get_pppoe_session_id(net_slot_id) != -1)) {
                tries += 1;
                if (tries < 0x12C) {
                    goto retry_close;
                }
            }
            if (get_pppoe_session_id(net_slot_id) != -1) {
                TLobby__sub_80428094(net_slot_id);
            }
            net_slot_id = -1;
            goto after_close;
        }
    } else {
        cancel_thread_if_running((void *)queue_thread_handle);
        deactivate_entry_by_key((u32) queue_thread_handle);
        NetReleaseMutex(send_ring_mutex);
after_close:
        if ((u32) (copy_default_and_get_state(NULL) - 2) <= 1U) {
            modem_hangup();
        }
    }
}

s32 open_network_transport(NetTransportOpenCfg *cfg) {
    PppoeNames *names = &pppoe_discovery_name_storage;
    char *name;
    s32 ret;
    if (send_ring_buffer_base == NULL) {
        return 2;
    }
    if (cfg->use_pppoe != 0) {
        network_pppoe_transport_enabled = 1;
        names->name[0] = 0;
        names->service[0] = 0;
        net_slot_id = TLobby__sub_804281DC(names);
        if (net_slot_id < 0) {
            return 2;
        }
    } else {
        network_pppoe_transport_enabled = 0;
        if (cfg->modem_name != NULL) {
            name = cfg->modem_name;
        } else {
            name = (char *)modem_default_connect_argument;
        }
        unlock_mutex(net_thread_state.mutex);
        ret = modem_init(name);
        lock_mutex(net_thread_state.mutex);
        if (ret == 1) {
            fn_8042E488(5);
            if (TLobby__sub_803F96AC(&send_ring_mutex) < 0) {
                return 2;
            }
            if (TLobby__sub_803F9B94(queue_thread_main, &queue_thread_handle) < 0) {
                return 2;
            }
            NetResumeThread(queue_thread_handle);
        } else {
            return 2;
        }
    }
    return 0;
}

#pragma push
#pragma opt_common_subs off
/* Places the send ring at base; returns its end, or 0 (and clears the ring) if it passes limit. */
u32 compute_range_end(NetTransportParams *params, s32 base, u32 limit) {
    u32 end;
    send_ring_buffer_base = (u8 *)base;
    lobby_ring_buffer_size = params->ring_buffer_size;
    end = base + lobby_ring_buffer_size;
    if (end > limit) {
        send_ring_buffer_base = NULL;
        lobby_ring_buffer_size = 0;
        return 0U;
    }
    return end;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
s32 AT_SetWorkArea(u8 *data, s32 size) {
    NetTransportParams params;
    uaddr end;
    u8 *cur;
    s32 header_size;
    uaddr after_tables;
    end = (uaddr)(data + size);
    header_size = AT_GetInitParam((NetTransportParams *)((saddr)&params));
    if (size < 0) {
        return -1;
    }
    if (size < header_size) {
        return -1;
    }
    net_transport_buffer_ptr_a = (uaddr)data;
    cur = data + params.player_count * 0x44;
    if ((uaddr)cur > end) {
        return -1;
    }
    net_transport_buffer_ptr_b = (uaddr)cur;
    cur += params.room_count * 0x544;
    if ((uaddr)cur > end) {
        return -1;
    }
    after_tables = (uaddr)layout_buffers(&params, cur, (u8 *)end);
    if (after_tables == 0) {
        return -1;
    }
    if (params.b != 0 && compute_range_end(&params, after_tables, end) == 0) {
        return -1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
s32 AT_SetInitParam(NetTransportParams *params) {
    u8 *raw = (u8 *)params;
    s32 e;
    if ((u16) params->player_count > 0x200U) {
        return -1;
    }
    if ((u16) params->room_count > 0x400U) {
        return -1;
    }
    e = params->e;
    if ((e < 0x400) || (e > 0xFFFF)) {
        return -1;
    }
    net_param_a = params->a;
    net_param_b = *(s16 *)((s8 *)raw + 2);
    net_param_player_count = params->player_count;
    net_param_room_count = params->room_count;
    net_param_word_e = params->e;
    net_param_word_f = params->f;
    net_param_ring_buffer_size = params->ring_buffer_size;
    net_param_word_h = params->h;
    net_param_word_i = *(s32 *)((s8 *)raw + 0x18);
    return AT_GetInitParam((NetTransportParams *)(0));
}
#pragma pop

s32 AT_GetInitParam(NetTransportParams *out) {
    NetTransportParams local;
    s32 rooms_size;
    s32 players_size;
    s32 total;
    if (out == NULL) {
        out = &local;
    }
    out->a = net_param_a;
    out->b = net_param_b;
    out->player_count = net_param_player_count;
    players_size = net_param_player_count * 0x44;
    out->room_count = net_param_room_count;
    rooms_size = net_param_room_count * 0x544;
    out->ring_buffer_size = net_param_ring_buffer_size;
    total = players_size + rooms_size;
    total += net_param_ring_buffer_size;
    out->e = net_param_word_e;
    out->f = net_param_word_f;
    out->h = net_param_word_h;
    out->i = net_param_word_i;
    total += TLobby__sub_803F8D24(out);
    return total;
}
