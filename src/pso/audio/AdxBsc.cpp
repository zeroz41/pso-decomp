// CRI adx_bsc.c: the ADXB decoder handles (ADXB_ExecHndl, the ADX block step, header decode, create/destroy).
#include "types.h"
#include <string.h>
#include "pso/unk/TLobby_803C4698.h"
#include "pso/unk/TLobby_803BFE50.h"
#include "pso/unk/TLobby_803C1A58.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/unk/TLobby.h"
#include "pso/audio/AdxbDecoder.h"
#include "pso/audio/AdxExpand.h"

extern "C" {
AdxbDecoder adx_channel_record_pool[16];
void TLobby__sub_803C19D8(void *);

void TLobby__sub_803C34F4(AdxbDecoder *h) {
    s16 s = h->format;
    if (s == 0) {
        TLobby__sub_803C3570(h);
    } else if (s == 10) {
        TLobby__sub_803C19D8(h);
    } else if (s == 2) {
        TLobby__sub_803C40D0(h);
    } else if (s == 3) {
        ((TLobby *)h)->dispatch_network_state();
    } else if (s == 4) {
        ((TLobby *)h)->dispatch_by_state();
    } else if (s == 1) {
        decode_adxb_pcm_stream((u8 *)h);
    }
}

// One step of the stream decoder, including the decode request (inferred: ADXB_ExecOneAdx and ADXB_EvokeDecode).
#pragma push
#pragma opt_common_subs off
#pragma opt_lifetimes off
#pragma opt_propagation off
void TLobby__sub_803C3570(AdxbDecoder *o) {
    s32 rem;
    int room;
    s32 width;
    s32 blk;
    if (o->state == 1 && o->channel->get_state() == 0) {
        s32 room_ext;
        s32 pad;
        s32 channels;
        s32 maxLen;
        s32 n;
        s32 block;
        s32 pos;
        s32 avail;
        s32 nblk;
        s32 x78;
        s32 ofst;
        s32 bufLen;
        s32 avail_blocks;
        o->read(o->readArg, &o->pos, &o->avail, &o->x78);
        block = o->stream_block_samples;
        x78 = o->x78;
        pos = o->pos;
        bufLen = o->bufLen;
        avail = o->avail;
        maxLen = o->maxLen;
        channels = o->stream_channels;
        n = maxLen / channels;
        ofst = block - 1;
        pad = ofst;
        ofst = x78 + ofst;
        nblk = ofst / block;
        s32 space = bufLen - pos - 1;
        pad -= ofst % block;
        space = block + space;
        room = space / block;
        room_ext = room;
        s32 room_end = room * block;
        if (nblk < room && pos + room_end - pad < bufLen) {
            ++room_ext;
        }
        if (x78 < avail) {
            avail += pad;
        }
        avail_blocks = avail / block;
        if (n > avail_blocks) {
            n = avail_blocks;
        }
        if (n > nblk) {
            n = nblk;
        }
        if (n > room_ext) {
            n = room_ext;
        }
        if (o->stream_channels == 2) {
            AdxDecoderChannel *channel = o->channel;
            s16 *dst = o->buf;
            dst += o->pos;
            channel->post_request((saddr)o->src, n * 2, (saddr)dst, (saddr)(dst + o->rOff));
            TLobby__sub_803CB4A4(channel);
        } else {
            AdxDecoderChannel *channel = o->channel;
            channel->try_post_command((saddr)o->src, n, (saddr)(o->buf + o->pos));
            TLobby__sub_803CB4A4(channel);
        }
        o->state = 2;
    }
    if (o->state == 2) {
        o->channel->update_receive_check();
        if (o->channel->get_state() == 3) {
            s32 last;
            s32 rOff;
            s32 size;
            s32 pos;
            s16 *buf;
            blk = o->stream_block_samples;
            last = blk - 1;
            last = o->x78 + last;
            rem = (blk - 1) - last % blk;
            width = o->stream_block_bytes;
            pos = o->pos;
            buf = o->buf;
            size = o->wrap_len;
            rOff = o->wrap_offset;
            s32 got = o->channel->get_decoded_count();
            s32 nblk = last / blk;
            s32 channels = o->stream_channels;
            s32 n = (got * blk) / channels;
            if (nblk * channels <= got) {
                n -= rem;
            }
            o->n = n;
            o->bytes = got * width;
            pos += n;
            if (pos >= size) {
                pos -= size;
                if (o->stream_channels == 2) {
                    s16 *dst = buf;
                    s16 *src = buf + size;
                    s32 i;
                    for (i = pos; i > 0; --i) {
                        *dst++ = *src++;
                    }
                    src = buf + (rOff + size);
                    dst = buf + rOff;
                    for (i = pos; i > 0; --i) {
                        *dst++ = *src++;
                    }
                } else {
                    s16 *src = buf + size;
                    for (s32 i = pos; i > 0; --i) {
                        *buf++ = *src++;
                    }
                }
            }
            o->channel->clear_done_state();
            o->done(o->doneArg, o->bytes, o->n);
            o->state = 3;
        }
    }
}
#pragma pop


s32 AdxbDecoder::get_decoded_samples() {
    return n;
}

s32 AdxbDecoder::get_decoded_bytes() {
    return bytes;
}

void TLobby__sub_803C3984(u8 *arg0) {
    AdxbDecoder *h = (AdxbDecoder *)arg0;
    if (h->state == 3) {
        h->channel->clear_done_state();
        h->m_9C = 0;
        h->state = 0;
    }
}

void TLobby__sub_803C39CC(u8 *arg0) {
    AdxbDecoder *h = (AdxbDecoder *)arg0;
    h->channel->reset_client_state();
    h->state = 0;
}

void TLobby__sub_803C3A04(u8 *arg0) {
    AdxbDecoder *h = (AdxbDecoder *)arg0;
    if (h->state == 0) {
        h->state = 1;
    }
}

void AdxbDecoder::set_source(u8 *data, s32 size) {
    if (format == 0) {
        src = data;
        maxLen = size / block_bytes;
        source_offset = 0;
        n = 0;
        bytes = 0;
        return;
    }
    src = data;
    maxLen = size / ((bits / 8) * channels);
    source_offset = 0;
    n = 0;
    bytes = 0;
}

s32 AdxbDecoder::get_state() {
    return state;
}

s32 AdxbDecoder::get_loop_end_byte() {
    return loop_end_byte;
}

s32 AdxbDecoder::get_loop_end_sample() {
    return loop_end_sample;
}

s32 AdxbDecoder::get_loop_start_byte() {
    return loop_start_byte;
}

s32 AdxbDecoder::get_loop_start_sample() {
    return loop_start_sample;
}

s32 AdxbDecoder::get_loop_type() {
    return loop_type;
}

s32 TLobby__sub_803C3ABC(u8 *adxb_decoder) {
    return ((AdxbDecoder *)adxb_decoder)->samples;
}

s32 TLobby__sub_803C3AC4(u8 *adxb_decoder) {
    return ((AdxbDecoder *)adxb_decoder)->block_samples;
}

s32 AdxbDecoder::get_packet_flag_for_state() {
    s16 s = format;
    if (s == 0) {
        return 0x10;
    }
    if (s == 2) {
        if (m_AA == 2) {
            return 4;
        }
        if (m_AA == 1) {
            return 8;
        }
        return 0x10;
    }
    if (s == 1) {
        if (m_AA == 2) {
            return 4;
        }
        return 0x10;
    }
    return 0x10;
}

s32 TLobby__sub_803C3B38(const AdxbDecoder *decoder) {
    return decoder->channels;
}

s32 TLobby__sub_803C3B44(u8 *adxb_decoder) {
    return ((AdxbDecoder *)adxb_decoder)->rate;
}

s32 AdxbDecoder::get_format() {
    return format;
}

s16 *AdxbDecoder::get_output_buffer() {
    return output_buffer;
}

void TLobby__sub_803C3B5C(u8 *arg0, void (*arg1)(s32, s32 *, s32 *, s32 *), saddr arg2) {
    AdxbDecoder *h = (AdxbDecoder *)arg0;
    h->read = arg1;
    h->readArg = arg2;
}

s32 TLobby__sub_803C3B68(saddr decoder, u16 *hdr, saddr size) {
    if ((u16) *(u16 *)((s8 *)hdr + 0) == 0x8000) {
        return TRK__write_aram((void *)decoder, hdr, (void *)size);
    }
    if (((TLobby *)hdr)->is_spsd_header() != 0) {
        return TLobby__sub_803C43A8((void *)decoder, (void *)hdr, (void *)size);
    }
    if (((TLobby *)hdr)->is_riff_wave() != 0) {
        return sub_803C1668((AdxbDecoder *)decoder, (u8 *)hdr, size);
    }
    if (((TLobby *)hdr)->is_aiff_header() != 0) {
        return ((TLobby *)decoder)->parse_stream_header((void *)hdr, (void *)size);
    }
    if (((TLobby *)hdr)->is_snd_header() != 0) {
        return TLobby__sub_803C30E8((u8 *)decoder, (saddr)hdr, (s32)size);
    }
    return 0;
}

s32 TRK__write_aram(void *arg0p, void *hdr, void *size) {
    AdxbDecoder *h = (AdxbDecoder *)arg0p;
    s32 sp18;
    s32 sp14;
    s16 sp10;
    u8 *temp_r3;
    h->m_02 = 1;
    if (sub_803C4910((u8 *)hdr, (saddr)size, &sp10, (u8 *)&h->m_0C, &h->bits, &h->block_bytes, (u8 *)&h->channels, &h->rate, &h->samples, &h->block_samples) < 0) {
        return 0;
    }
    if (h->m_0C > 4) {
        if (h->ahx_handle == NULL) {
            TLobby::report_adx_error("E1060101 ADXB_DecodeHeaderAdx: ", "can't play AHX data by this handle");
            return 0;
        }
        h->bits = 8;
        h->block_bytes = (u8)(h->channels * 0xC0);
        h->block_samples = 0x60;
        h->format = 0xA;
        goto block_11;
    }
    if (TLobby__sub_803C48C8((u8 *)hdr, (saddr)size, (u16 *)&h->m_1C) < 0) {
        return 0;
    }
    if (((TLobby *)hdr)->parse_header_loop_points((saddr)size, (u16 *)&sp18, (u16 *)&sp14) < 0) {
        return 0;
    }
    h->channel->calc_adx_coeffs_at_offset(h->rate, h->m_1C);
    TLobby__sub_803CB570(h->channel, (u8 *)&sp18, (s16 *)&sp14);
    sub_803C46DC((u8 *)hdr, (saddr)size, &h->loop_enabled, &h->loop_type, &h->loop_count, &h->loop_start_sample, &h->loop_start_byte, &h->loop_end_sample, &h->loop_end_byte);
    h->format = 0;
block_11:
    temp_r3 = h->m_4C;
    h->stream_channels = h->channels;
    h->stream_block_bytes = h->block_bytes;
    h->stream_block_samples = h->block_samples;
    h->buf = h->output_buffer;
    h->bufLen = h->wrap_len;
    h->rOff = h->wrap_offset;
    h->m_7C = h->m_48;
    h->m_7E = h->m_4A;
    h->m_80 = temp_r3;
    h->m_9C = 0;
    memset(temp_r3, 0, 4);
    return sp10;
}

void AdxbDecoder::clear_record() {
    if (this != NULL) {
        channel->clear_record_data();
        memset(this, 0, sizeof(AdxbDecoder));
        used = 0;
    }
}

inline void free_803C3E88(AdxbDecoder *r) {
    if (r != NULL) {
        r->channel->clear_record_data();
        memset(r, 0, sizeof(AdxbDecoder));
        r->used = 0;
    }
}
AdxbDecoder *AdxbDecoder::alloc_record(s32 channels, saddr buffer, s32 size, s32 wrap_offset) {
    s32 i;
    AdxbDecoder *r;
    for (i = 0; i < 16; i++) {
        if (adx_channel_record_pool[i].used == 0) {
            break;
        }
    }
    if (i == 16) {
        return NULL;
    }
    r = &adx_channel_record_pool[i];
    memset(r, 0, sizeof(AdxbDecoder));
    r->used = 1;
    r->channel = adx_allocate_decoder_channel();
    if (r->channel == NULL) {
        free_803C3E88(r);
        return NULL;
    }
    r->m_38 = channels;
    r->output_buffer = (s16 *)buffer;
    r->wrap_len = size;
    r->wrap_offset = wrap_offset;
    r->read = (void (*)(s32, s32 *, s32 *, s32 *))get_progress_info__6TLobbyFPvPvPvPv;
    r->readArg = (saddr)r;
    r->done = (void (*)(s32, s32, s32))TLobby__sub_803C4020;
    r->doneArg = (saddr)r;
    return r;
}

void TLobby__sub_803C4020(u8 *arg0, s32 arg1, s32 arg2) {
    AdxbDecoder *h = (AdxbDecoder *)arg0;
    h->m_9C += arg2;
    h->m_98 += arg2;
}

s32 get_progress_info__6TLobbyFPvPvPvPv(u8 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    AdxbDecoder *h = (AdxbDecoder *)arg0;
    *arg1 = h->m_9C;
    *arg2 = h->wrap_len - h->m_9C;
    *arg3 = h->samples - h->m_98;
    return (saddr)h->output_buffer;
}
void TLobby__sub_803C406C(void) {
    AdxDecoderChannel::clear_pool();
    memset(adx_channel_record_pool, 0, sizeof(adx_channel_record_pool));
}

}
