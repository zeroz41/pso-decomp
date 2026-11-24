/* The PPP option-negotiation state machine that LCP, IPCP and PAP drive (a C library, built with GC/1.2.5n). PppFsm is an inferred name; no string names this module. */
#include "types.h"
#include "pso/network/TLobby_803FC178.h"
#include "pso/network/TLobby_803FCF44.h"
#include "pso/network/TLobby_804050DC.h"
#include "pso/network/TLobby_8041112C.h"
#include "pso/network/NetworkRuntime.h"
#include "pso/network/TLobby_804048E8.h"
#include "pso/network/NetworkTransport.h"

#include "pso/network/NetStackTypes.h"

#include "pso/network/PppBuffer.h"
#include "pso/network/PppLcp.h"
#include "pso/network/PppFsm.h"
#include "pso/network/IPv4Header.h"

void update_countdown_state(PppFsm *);

/* The PPP FCS-16 lookup table of RFC 1662 (fcstab), which the HDLC framing (ppp_poll_input, ppp_output_frame)
 * reads. .data 804FD3A8, just before this file's jump tables; owner inferred: no TU between NetworkThreadRuntime.c
 * and this one has other .data, and this file holds the stack's other checksum code (TLobby__sub_803FE934). */
u16 ppp_fcs16_table[256] = {
    0x0000, 0x1189, 0x2312, 0x329b, 0x4624, 0x57ad, 0x6536, 0x74bf,
    0x8c48, 0x9dc1, 0xaf5a, 0xbed3, 0xca6c, 0xdbe5, 0xe97e, 0xf8f7,
    0x1081, 0x0108, 0x3393, 0x221a, 0x56a5, 0x472c, 0x75b7, 0x643e,
    0x9cc9, 0x8d40, 0xbfdb, 0xae52, 0xdaed, 0xcb64, 0xf9ff, 0xe876,
    0x2102, 0x308b, 0x0210, 0x1399, 0x6726, 0x76af, 0x4434, 0x55bd,
    0xad4a, 0xbcc3, 0x8e58, 0x9fd1, 0xeb6e, 0xfae7, 0xc87c, 0xd9f5,
    0x3183, 0x200a, 0x1291, 0x0318, 0x77a7, 0x662e, 0x54b5, 0x453c,
    0xbdcb, 0xac42, 0x9ed9, 0x8f50, 0xfbef, 0xea66, 0xd8fd, 0xc974,
    0x4204, 0x538d, 0x6116, 0x709f, 0x0420, 0x15a9, 0x2732, 0x36bb,
    0xce4c, 0xdfc5, 0xed5e, 0xfcd7, 0x8868, 0x99e1, 0xab7a, 0xbaf3,
    0x5285, 0x430c, 0x7197, 0x601e, 0x14a1, 0x0528, 0x37b3, 0x263a,
    0xdecd, 0xcf44, 0xfddf, 0xec56, 0x98e9, 0x8960, 0xbbfb, 0xaa72,
    0x6306, 0x728f, 0x4014, 0x519d, 0x2522, 0x34ab, 0x0630, 0x17b9,
    0xef4e, 0xfec7, 0xcc5c, 0xddd5, 0xa96a, 0xb8e3, 0x8a78, 0x9bf1,
    0x7387, 0x620e, 0x5095, 0x411c, 0x35a3, 0x242a, 0x16b1, 0x0738,
    0xffcf, 0xee46, 0xdcdd, 0xcd54, 0xb9eb, 0xa862, 0x9af9, 0x8b70,
    0x8408, 0x9581, 0xa71a, 0xb693, 0xc22c, 0xd3a5, 0xe13e, 0xf0b7,
    0x0840, 0x19c9, 0x2b52, 0x3adb, 0x4e64, 0x5fed, 0x6d76, 0x7cff,
    0x9489, 0x8500, 0xb79b, 0xa612, 0xd2ad, 0xc324, 0xf1bf, 0xe036,
    0x18c1, 0x0948, 0x3bd3, 0x2a5a, 0x5ee5, 0x4f6c, 0x7df7, 0x6c7e,
    0xa50a, 0xb483, 0x8618, 0x9791, 0xe32e, 0xf2a7, 0xc03c, 0xd1b5,
    0x2942, 0x38cb, 0x0a50, 0x1bd9, 0x6f66, 0x7eef, 0x4c74, 0x5dfd,
    0xb58b, 0xa402, 0x9699, 0x8710, 0xf3af, 0xe226, 0xd0bd, 0xc134,
    0x39c3, 0x284a, 0x1ad1, 0x0b58, 0x7fe7, 0x6e6e, 0x5cf5, 0x4d7c,
    0xc60c, 0xd785, 0xe51e, 0xf497, 0x8028, 0x91a1, 0xa33a, 0xb2b3,
    0x4a44, 0x5bcd, 0x6956, 0x78df, 0x0c60, 0x1de9, 0x2f72, 0x3efb,
    0xd68d, 0xc704, 0xf59f, 0xe416, 0x90a9, 0x8120, 0xb3bb, 0xa232,
    0x5ac5, 0x4b4c, 0x79d7, 0x685e, 0x1ce1, 0x0d68, 0x3ff3, 0x2e7a,
    0xe70e, 0xf687, 0xc41c, 0xd595, 0xa12a, 0xb0a3, 0x8238, 0x93b1,
    0x6b46, 0x7acf, 0x4854, 0x59dd, 0x2d62, 0x3ceb, 0x0e70, 0x1ff9,
    0xf78f, 0xe606, 0xd49d, 0xc514, 0xb1ab, 0xa022, 0x92b9, 0x8330,
    0x7bc7, 0x6a4e, 0x58d5, 0x495c, 0x3de3, 0x2c6a, 0x1ef1, 0x0f78,
};

/* How many PPP protocols have reached the opened state (5); IPCP's wait stops at 2 (.sbss 805D7AA0). */
s32 lbl_805D7AA0;

void TLobby__sub_803FD694(PppFsm *fsm) {
    PppFsmTimer *timer;
    timer = &fsm->timer;
    fsm->f4 = fsm->proto->max_request_attempts;
    fsm->f7 = fsm->proto->max_peer_attempts;
    fsm->f5 = fsm->proto->max_terminate_attempts;
    fsm->state = (fsm->f2 & 0xC0) ? 1 : 0;
    fsm->retries = fsm->f4;
    fsm->f6 = fsm->f7;
    fsm->proto->reset_options(fsm);
    timer->callback = update_countdown_state;
    timer->arg = fsm;
    lobby_timer_add((N_80405298 *)timer, fsm->proto->timeout);
}

void update_connection_state(void *arg0) {
    PppFsm *fsm;

    fsm = (PppFsm *)arg0;
    if (fsm->opts == 0) {
        return;
    }
    switch (fsm->state) {
    case 5:
        fsm->proto->link_closed(fsm);
    case 4:
        fsm->retries = fsm->f5;
        if (fsm->retries != 0) {
            fsm->retries--;
            lobby_timer_start((u8 *)&fsm->timer);
            ppp_fsm_send_packet((PppFsm *)arg0, 5, 0, 0);
        }
        fsm->state = 6;
        break;
    case 2:
    case 3:
        fsm->retries = 0;
        fsm->state = 6;
        break;
    case 1:
        if (lbl_805D7A90 & 2) {
            if (fsm->retries != 0) {
                fsm->retries--;
                lobby_timer_start((u8 *)&fsm->timer);
                ppp_fsm_send_packet((PppFsm *)arg0, 5, 0, 0);
            }
        }
        fsm->state = 0;
        break;
    case 6:
        break;
    }
}

void TLobby__sub_803FD85C(void *arg0) {
    PppFsm *fsm;

    fsm = (PppFsm *)arg0;
    if (fsm->opts != NULL) {
        switch (fsm->state) {
        case 2:
        case 3:
        case 4:
            lobby_timer_stop(&fsm->timer);
            fsm->state = (fsm->f2 & 0xC0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->reset_options(arg0);
            break;
        case 5:
            fsm->proto->link_closed(fsm);
        case 6:
            fsm->state = (fsm->f2 & 0xC0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->reset_options(fsm);
            break;
        }
    }
}

void TLobby__sub_803FD958(u8 *arg0) {
    PppFsm *fsm;

    fsm = (PppFsm *)arg0;
    if (fsm->opts != NULL && (fsm->f2 & 0xC0)) {
        switch (fsm->state) {
        case 0:
        case 1:
        case 6:
            fsm->proto->start_negotiation(fsm);
            fsm->state = (fsm->f2 & 0xC0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->reset_options(fsm);
            if (fsm->f2 & 0x80) {
                if (fsm->retries != 0) {
                    fsm->retries--;
                    lobby_timer_start((u8 *)&fsm->timer);
                    ppp_fsm_send_packet((PppFsm *)arg0, 1, 0, fsm->proto->build_config_request(fsm));
                }
                fsm->state = 2;
            }
            break;
        }
    }
}

void update_countdown_state(PppFsm *arg0) {
    PppFsm *fsm = (PppFsm *)(u8 *)arg0;
    switch (fsm->state) {
    case 2:
    case 3:
    case 4:
        if (fsm->retries != 0) {
            if (fsm->retries > 0) {
                fsm->retries--;
                lobby_timer_start((u8 *)&fsm->timer);
                ppp_fsm_send_packet(fsm, 1, 0, fsm->proto->build_config_request(fsm));
            }
            if (fsm->state == 3) {
                fsm->state = 2;
            }
        } else {
            fsm->state = (fsm->f2 & 0xC0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->reset_options(fsm);
            fsm->abort = 1;
        }
        break;
    case 6:
        if (fsm->retries != 0) {
            if (fsm->retries > 0) {
                fsm->retries--;
                lobby_timer_start((u8 *)&fsm->timer);
                ppp_fsm_send_packet(fsm, 5, 0, 0);
            }
        } else {
            fsm->proto->finish_termination(fsm);
            fsm->state = (fsm->f2 & 0xC0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->reset_options(fsm);
            fsm->abort = 1;
        }
        break;
    }
}

static inline s16 read_packet_header(PppHeader *dst, PppFrame **src, s32 with_ext) {
    u8 ext[8];
    u8 buf[4];
    if (dst == 0) {
        return -1;
    }
    if (ppp_buffer_read(src, buf, 4) < 4) {
        return -1;
    }
    dst->code = buf[0];
    dst->id = buf[1];
    dst->len = read_network_u16_be(buf + 2);
    if (with_ext && ppp_buffer_read(src, ext, 8) < 8) {
        return -1;
    }
    return 0;
}

#pragma push
#pragma opt_common_subs on
#pragma dont_inline off
#pragma inline_depth(4)
void TLobby__sub_803FDBF8(PppFsm *fsm, PppFrame *payload)
{
    PppHeader hdr;
    s16 rc;
    PppFrame *newbuf;
    u8 *dp;

    rc = read_packet_header(&hdr, &payload, 0);
    if (rc != 0) {
        return;
    }
    hdr.len -= 4;
    TLobby__sub_80401CAC(&payload, hdr.len);
    switch (hdr.code) {
    case 1:
        switch (fsm->state) {
        case 5:
            fsm->proto->link_closed(fsm);
            fsm->state = ((fsm->f2 & 0xC0) != 0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->reset_options(fsm);
        case 1:
            fsm->proto->start_negotiation(fsm);
            if (fsm->retries != 0) {
                fsm->retries--;
                lobby_timer_start((u8 *)&fsm->timer);
                ppp_fsm_send_packet(fsm, 1, 0, fsm->proto->build_config_request(fsm));
            }
        case 2:
        case 4:
            if (fsm->proto->check_config_request(fsm, &hdr, payload) == 0) {
                fsm->state = 4;
            } else {
                fsm->state = 2;
            }
            break;
        case 3:
            if (fsm->proto->check_config_request(fsm, &hdr, payload) == 0) {
                lobby_timer_stop(&fsm->timer);
                fsm->proto->link_opened(fsm);
                fsm->state = 5;
                lbl_805D7AA0++;
            } else {
                lobby_timer_start((u8 *)&fsm->timer);
            }
            break;
        case 0:
            ppp_fsm_send_packet(fsm, 6, hdr.id, 0);
            break;
        case 6:
            break;
        }
        break;
    case 2:
        switch (fsm->state) {
        case 2:
            if (fsm->proto->check_config_ack(fsm, &hdr, payload) == 0) {
                fsm->state = 3;
            }
            break;
        case 4:
            if (fsm->proto->check_config_ack(fsm, &hdr, payload) == 0) {
                lobby_timer_stop(&fsm->timer);
                fsm->proto->link_opened(fsm);
                fsm->state = 5;
                lbl_805D7AA0++;
            }
            break;
        case 5:
            fsm->proto->link_closed(fsm);
            fsm->proto->start_negotiation(fsm);
            fsm->state = ((fsm->f2 & 0xC0) != 0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->reset_options(fsm);
        case 3:
            if (fsm->retries != 0) {
                fsm->retries--;
                lobby_timer_start((u8 *)&fsm->timer);
                ppp_fsm_send_packet(fsm, 1, 0, fsm->proto->build_config_request(fsm));
            }
            fsm->state = 2;
            break;
        case 0:
        case 1:
            ppp_fsm_send_packet(fsm, 6, hdr.id, 0);
            break;
        case 6:
            break;
        }
        break;
    case 3:
        switch (fsm->state) {
        case 2:
        case 4:
            if (fsm->proto->check_config_nak(fsm, &hdr, payload) == 0) {
                if (fsm->retries != 0) {
                    fsm->retries--;
                    lobby_timer_start((u8 *)&fsm->timer);
                    ppp_fsm_send_packet(fsm, 1, 0, fsm->proto->build_config_request(fsm));
                }
            }
            break;
        case 5:
            fsm->proto->link_closed(fsm);
            fsm->proto->start_negotiation(fsm);
            fsm->state = ((fsm->f2 & 0xC0) != 0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->reset_options(fsm);
        case 3:
            if (fsm->retries != 0) {
                fsm->retries--;
                lobby_timer_start((u8 *)&fsm->timer);
                ppp_fsm_send_packet(fsm, 1, 0, fsm->proto->build_config_request(fsm));
            }
            fsm->state = 2;
            break;
        case 0:
        case 1:
            ppp_fsm_send_packet(fsm, 6, hdr.id, 0);
            break;
        case 6:
            break;
        }
        break;
    case 4:
        switch (fsm->state) {
        case 2:
        case 4:
            if (fsm->proto->check_config_reject(fsm, &hdr, payload) == 0) {
                if (fsm->retries != 0) {
                    fsm->retries--;
                    lobby_timer_start((u8 *)&fsm->timer);
                    ppp_fsm_send_packet(fsm, 1, 0, fsm->proto->build_config_request(fsm));
                }
            }
            break;
        case 5:
            fsm->proto->link_closed(fsm);
            fsm->proto->start_negotiation(fsm);
            fsm->state = ((fsm->f2 & 0xC0) != 0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->reset_options(fsm);
        case 3:
            if (fsm->retries != 0) {
                fsm->retries--;
                lobby_timer_start((u8 *)&fsm->timer);
                ppp_fsm_send_packet(fsm, 1, 0, fsm->proto->build_config_request(fsm));
            }
            fsm->state = 2;
            break;
        case 0:
        case 1:
            ppp_fsm_send_packet(fsm, 6, hdr.id, 0);
            break;
        case 6:
            break;
        }
        break;
    case 5:
        switch (fsm->state) {
        case 5:
            ppp_fsm_send_packet(fsm, 6, hdr.id, 0);
            fsm->proto->link_closed(fsm);
            fsm->proto->finish_termination(fsm);
            fsm->state = ((fsm->f2 & 0xC0) != 0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->reset_options(fsm);
            break;
        case 3:
        case 4:
            fsm->state = 2;
        case 0:
        case 1:
        case 2:
        case 6:
            ppp_fsm_send_packet(fsm, 6, hdr.id, 0);
            break;
        }
        break;
    case 6:
        switch (fsm->state) {
        case 6:
            lobby_timer_stop(&fsm->timer);
            fsm->proto->finish_termination(fsm);
            fsm->state = ((fsm->f2 & 0xC0) != 0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->reset_options(fsm);
            break;
        case 5:
            fsm->proto->link_closed(fsm);
            fsm->state = ((fsm->f2 & 0xC0) != 0) ? 1 : 0;
            fsm->retries = fsm->f4;
            fsm->f6 = fsm->f7;
            fsm->proto->reset_options(fsm);
            if (fsm->retries == 0) {
                rc = -1;
            } else {
                fsm->retries--;
                lobby_timer_start((u8 *)&fsm->timer);
                rc = ppp_fsm_send_packet(fsm, 1, 0, fsm->proto->build_config_request(fsm));
            }
            if (rc == 0) {
                fsm->state = 2;
            }
            break;
        case 3:
        case 4:
            fsm->state = 2;
            break;
        }
        break;
    case 7:
        fsm->proto->finish_termination(fsm);
        fsm->state = ((fsm->f2 & 0xC0) != 0) ? 1 : 0;
        fsm->retries = fsm->f4;
        fsm->f6 = fsm->f7;
        fsm->proto->reset_options(fsm);
        break;
    case 9:
        switch (fsm->state) {
        case 5:
            ppp_fsm_send_packet(fsm, 10, hdr.id, payload);
            break;
        case 2:
        case 3:
        case 4:
            break;
        case 0:
        case 1:
            ppp_fsm_send_packet(fsm, 6, hdr.id, 0);
            break;
        case 6:
            break;
        }
        break;
    case 8:
    case 10:
    case 11:
    case 12:
        break;
    case 0:
    default:
        hdr.len += 4;
        newbuf = alloc_from_buffer(payload, 4);
        dp = newbuf->data;
        *dp++ = hdr.code;
        *dp++ = hdr.id;
        write_network_u16_be(dp, hdr.len);
        payload = newbuf;
        ppp_fsm_send_packet(fsm, 7, hdr.id, payload);
        switch (fsm->state) {
        case 6:
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            fsm->state = 1;
            break;
        }
        break;
    }
}
#pragma pop
void TLobby__sub_803FE600(O_803FE600 *o) {
    PppFsm *fsm = (PppFsm *)o;

    fsm->state = (fsm->f2 & 0xC0) ? 1 : 0;
    fsm->retries = fsm->f4;
    fsm->f6 = fsm->f7;
    fsm->proto->reset_options(fsm);
}

s16 TLobby__sub_803FE658(PppFsm *fsm) {
    u8 count;

    count = fsm->retries;
    if (count == 0) {
        return -1;
    }
    fsm->retries = count - 1;
    lobby_timer_start((u8 *)&fsm->timer);
    return ppp_fsm_send_packet(fsm, 1, 0, fsm->proto->build_config_request(fsm));
}

#pragma push
#pragma optimization_level 0
#pragma opt_propagation on
static inline PppFrame *ppp_frame_clear_length(PppFrame *frame) {
    u16 *length = &frame->len;
    *length = 0;
    return (PppFrame *)((u8 *)length - offsetof(PppFrame, len));
}
#pragma pop
#pragma push
#pragma opt_lifetimes off
#pragma dont_inline off
#pragma inline_depth(4)
#pragma opt_common_subs off
#pragma opt_propagation on
s16 ppp_fsm_send_packet(PppFsm *self, u8 code, int reply_identifier, PppFrame *payload) {
    PppFsm *fsm = (PppFsm *)self;
    PppBuffers *buffers;
    PppFsmLink *link = (PppFsmLink *)fsm->sub;
    s32 command;
    u8 *length_field;
    s32 identifier;
    uaddr payload_length;
    u8 *write_network_u16_be(u8 *p, u32 v); /* declared here with other parameter types; the definition is u8 *(u8 *, u16) */

    if (payload == NULL) {
        PppFrame *empty = lbl_805C04A8.reply;
        empty->data = (u8 *)empty + ((*(buffers = &lbl_805C04A8)).headroom + 0x83 & ~3);
        payload = ppp_frame_clear_length(empty);
    }
    switch (command = (u8)code) {
    case 1:
    case 5:
    case 9:
        fsm->id = link->next_identifier;
    case 8:
    case 11:
        identifier = link->next_identifier;
        link->next_identifier = identifier + 1;
        break;
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
    case 10:
        identifier = reply_identifier;
        break;
    default:
        return -1;
    }
    switch (command) {
    case 9:
    case 10:
    case 11:
        write_network_u32_be(payload->data, ((LcpOpts *)fsm->opts)->local.got.magic);
        break;
    }
    payload_length = get_field_4(payload);
    {
        PppFrame *saved_frame = payload;
        /* Reuse the payload register for the length before restoring the frame. */
        payload = (PppFrame *)(payload_length + 4);
        {
            PppFrame *output = alloc_from_buffer(saved_frame, 4);
            u8 *data = output->data;
            *data++ = code;
            *data++ = identifier;
            length_field = data;
            write_network_u16_be(length_field, (uaddr)payload);
            payload = output;
        }
    }
    if (payload == NULL) {
        return -1;
    }
    {
        s16 count = link->transmitted[fsm->proto->tx_counter_index];
        link->transmitted[fsm->proto->tx_counter_index] = count + 1;
    }
    return TLobby__sub_80406624(0, 0, fsm->proto->proto, payload);
}
#pragma pop
void TLobby__sub_803FE820(saddr arg0) {
    lobby_timer_start((u8 *)&((PppFsm *)arg0)->timer);
}

s16 TLobby__sub_803FE844(PppFsm *fsm, PppHeader *header, PppFrame *frame) {
    return 0;
}

void TLobby__sub_803FE84C(PppFsm *fsm) {

}

s32 read_2_bytes(void *self, void *src) {
    u8 *dst = (u8 *)self;
    u8 buf[2];
    if (dst == 0) {
        return -1;
    }
    if (ppp_buffer_read(src, buf, 2) < 2) {
        return -1;
    }
    dst[0] = buf[0];
    dst[1] = buf[1];
    return 0;
}

s16 TLobby__sub_803FE8BC(PppHeader *dst, PppFrame **src) {
    u8 buf[4];
    if (dst == 0) {
        return -1;
    }
    if (ppp_buffer_read(src, buf, 4) < 4) {
        return -1;
    }
    dst->code = buf[0];
    dst->id = buf[1];
    dst->len = read_network_u16_be(buf + 2);
    return 0;
}

u16 TLobby__sub_803FE934(u8* p, PppFrame *buf, u16 count) {
    u32 sum = 0;
    s32 i;
    if (p != NULL) {
        i = 6; while (i--) { sum += *p++ << 8; sum += *p++; }
    }
    sum = TLobby__sub_803FE9F8(sum, buf, count);
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += sum >> 16;
    return ~sum & 0xFFFF;
}

u32 TLobby__sub_803FE9F8(u32 sum, PppFrame* buf, u16 count) {
    s16 n;
    u16 last;
    s32 odd;
    s16 half;
    s16 i;
    u8* data;
    data = buf->data;
    n = buf->len < count ? buf->len : count;
    if (n & 1) {
        odd = 1;
        last = data[n - 1];
        n--;
    } else {
        odd = 0;
        last = 0;
    }
    half = n >> 1;
    for (i = half; i > 0; i--) {
        sum += data[0] << 8;
        sum += data[1];
        data += 2;
    }
    if (odd) {
        sum += last << 8;
    }
    return sum;
}

s32 TLobby__sub_803FEA88(A_80403F4C *out, PppFrame **src) {
    PppFrame *e = *src;
    IPv4Header h;
    u32 hl;
    u16 frag;
    u32 optlen;
    IPv4Header *wire;

    wire = &h;
    if (ppp_buffer_read(src, wire, 20) != 20) {
        return 0xFFFF;
    }
    out->version = (h.ver_ihl >> 4) & 0xF;
    out->tos = h.tos;
    out->len = h.len;
    out->id = h.id;
    frag = h.frag;
    out->frag = (frag & 0x1FFF) << 3;
    if (frag & 0x2000) {
        out->mf = 1;
    } else {
        out->mf = 0;
    }
    if (frag & 0x4000) {
        out->df = 1;
    } else {
        out->df = 0;
    }
    out->ttl = h.ttl;
    out->proto = h.proto;
    out->cksum = h.cksum;
    out->src = h.src;
    out->dst = h.dst;
    if (out->len - 20 < e->len) {
        e->len = out->len - 20;
    }
    hl = (h.ver_ihl & 0xF) * 4;
    if (hl < 20) {
        out->optlen = 0;
        return 0xFFFF;
    }
    optlen = hl - 20;
    out->optlen = optlen;
    if (out->optlen != 0 && ppp_buffer_read(src, out->opts, out->optlen) < out->optlen) {
        return 0xFFFF;
    }
    return hl;
}

PppFrame *NetIPv4WriteHeader(A_80403F4C *ip, PppFrame *frame, s32 preserve_checksum) {
    u16 n;
    u8 wire[0x40];
    IPv4Header *hdr = (IPv4Header *)wire;
    u8 *data;
    u32 sum;
    u16 f;
    u32 tmp;
    u8 pad[0x8];

    tmp = ip->optlen + 0x14;
    n = tmp;
    if (n > 0x40) {
        n = 0x40;
    }
    frame = alloc_from_buffer(frame, n);
    data = frame->data;

    hdr->ver_ihl = (ip->version << 4) | (n >> 2);
    hdr->tos = ip->tos;
    hdr->len = ip->len;
    hdr->id = ip->id;
    f = (s32)ip->frag >> 3;
    if (ip->df != 0) {
        f |= 0x4000;
    }
    if (ip->mf != 0) {
        f |= 0x2000;
    }
    hdr->frag = f;
    hdr->ttl = ip->ttl;
    hdr->proto = ip->proto;
    if ((u16)preserve_checksum != 0) {
        hdr->cksum = ip->cksum;
    } else {
        hdr->cksum = 0;
    }
    hdr->src = ip->src;
    hdr->dst = ip->dst;

    if (ip->optlen != 0) {
        NetMemcpy((u8 *)hdr + sizeof(*hdr), ip->opts, (ip->optlen < 0x2C) ? ip->optlen : 0x2C);
    }
    {
        u32 m = (u16)n;
        NetMemcpy(data, hdr, m);
        if ((u16)preserve_checksum == 0) {
            sum = TLobby__sub_803FE9F8(0, frame, n);
            sum = (sum >> 16) + (sum & 0xFFFF);
            sum = (sum >> 16) + sum;
            hdr->cksum = ~sum;
        }
        NetMemcpy(data, hdr, m);
    }
    return frame;
}
