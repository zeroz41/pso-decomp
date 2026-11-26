// CRI adx_bsc.c: the ADXB decoder handles (ADXB_ExecHndl, the ADX block step, header decode, create/destroy).
#include "types.h"
#include "pso/audio/AdxError.h"
#include <string.h>
#include "pso/audio/AudioStreamInput.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/network/TLobby.h"
#include "pso/audio/AdxbDecoder.h"
#include "pso/audio/AdxExpand.h"
#include "pso/audio/AdxHeader.h"

extern "C" {
AdxbDecoder adx_channel_record_pool[16];

void adxb_exec_handle(AdxbDecoder *adxb) {
    s16 s = adxb->format;
    if (s == 0) {
        adxb_exec_one_adx(adxb);
    } else if (s == 10) {
        adxb_exec_one_ahx(adxb);
    } else if (s == 2) {
        adxb_exec_one_spsd(adxb);
    } else if (s == 3) {
        adxb_exec_one_aiff(adxb);
    } else if (s == 4) {
        adxb_exec_one_au(adxb);
    } else if (s == 1) {
        adxb_exec_one_wav(adxb);
    }
}

// One step of the stream decoder, including the decode request (ADXB_ExecOneAdx and ADXB_EvokeDecode).
#pragma push
#pragma opt_common_subs off
#pragma opt_lifetimes off
#pragma opt_propagation off
void adxb_exec_one_adx(AdxbDecoder *adxb) {
    s32 rem;
    int room;
    s32 width;
    s32 blk;
    if (adxb->state == 1 && adxb->channel->get_state() == 0) {
        s32 room_ext;
        s32 pad;
        s32 channels;
        s32 maxLen;
        s32 n;
        s32 block;
        s32 pos;
        s32 avail;
        s32 nblk;
        s32 remaining;
        s32 ofst;
        s32 bufLen;
        s32 avail_blocks;
        adxb->read(adxb->readArg, &adxb->pos, &adxb->avail, &adxb->remaining);
        block = adxb->stream_block_samples;
        remaining = adxb->remaining;
        pos = adxb->pos;
        bufLen = adxb->bufLen;
        avail = adxb->avail;
        maxLen = adxb->maxLen;
        channels = adxb->stream_channels;
        n = maxLen / channels;
        ofst = block - 1;
        pad = ofst;
        ofst = remaining + ofst;
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
        if (remaining < avail) {
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
        if (adxb->stream_channels == 2) {
            AdxDecoderChannel *channel = adxb->channel;
            s16 *dst = adxb->buf;
            dst += adxb->pos;
            channel->post_request((s8 *)adxb->src, n * 2, dst, dst + adxb->rOff);
            adx_decoder_channel_start(channel);
        } else {
            AdxDecoderChannel *channel = adxb->channel;
            channel->try_post_command((s8 *)adxb->src, n, adxb->buf + adxb->pos);
            adx_decoder_channel_start(channel);
        }
        adxb->state = 2;
    }
    if (adxb->state == 2) {
        adxb->channel->update_receive_check();
        if (adxb->channel->get_state() == 3) {
            s32 last;
            s32 rOff;
            s32 size;
            s32 pos;
            s16 *buf;
            blk = adxb->stream_block_samples;
            last = blk - 1;
            last = adxb->remaining + last;
            rem = (blk - 1) - last % blk;
            width = adxb->stream_block_bytes;
            pos = adxb->pos;
            buf = adxb->buf;
            size = adxb->wrap_len;
            rOff = adxb->wrap_offset;
            s32 got = adxb->channel->get_decoded_count();
            s32 nblk = last / blk;
            s32 channels = adxb->stream_channels;
            s32 n = (got * blk) / channels;
            if (nblk * channels <= got) {
                n -= rem;
            }
            adxb->n = n;
            adxb->bytes = got * width;
            pos += n;
            if (pos >= size) {
                pos -= size;
                if (adxb->stream_channels == 2) {
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
            adxb->channel->clear_done_state();
            adxb->done(adxb->doneArg, adxb->bytes, adxb->n);
            adxb->state = 3;
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

void AdxbDecoder::reset() {
    if (state == 3) {
        channel->clear_done_state();
        write_pos = 0;
        state = 0;
    }
}

void AdxbDecoder::stop() {
    channel->reset_client_state();
    state = 0;
}

void AdxbDecoder::start() {
    if (state == 0) {
        state = 1;
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

s32 AdxbDecoder::get_total_samples() {
    return samples;
}

s32 AdxbDecoder::get_block_samples() {
    return block_samples;
}

s32 AdxbDecoder::get_bits_per_sample() {
    s16 s = format;
    if (s == 0) {
        return 0x10;
    }
    if (s == 2) {
        if (encoding == 2) {
            return 4;
        }
        if (encoding == 1) {
            return 8;
        }
        return 0x10;
    }
    if (s == 1) {
        if (encoding == 2) {
            return 4;
        }
        return 0x10;
    }
    return 0x10;
}

s32 AdxbDecoder::get_channels() const {
    return channels;
}

s32 AdxbDecoder::get_rate() {
    return rate;
}

s32 AdxbDecoder::get_format() {
    return format;
}

s16 *AdxbDecoder::get_output_buffer() {
    return output_buffer;
}

void adxb_set_read_callback(AdxbDecoder *adxb, s16 *(*read)(void *, s32 *, s32 *, s32 *), void *obj) {
    adxb->read = read;
    adxb->readArg = obj;
}

s32 adxb_decode_header(AdxbDecoder *adxb, u8 *hdr, s32 size) {
    if (*(u16 *)hdr == 0x8000) {
        return ADXB_DecodeHeaderAdx(adxb, hdr, size);
    }
    if (adxb_is_spsd_header(hdr) != 0) {
        return adxb_decode_header_spsd(adxb, hdr, size);
    }
    if (adxb_is_wav_header(hdr) != 0) {
        return adxb_decode_header_wav(adxb, hdr, size);
    }
    if (adxb_is_aiff_header(hdr) != 0) {
        return adxb_decode_header_aiff(adxb, hdr, size);
    }
    if (adxb_is_au_header(hdr) != 0) {
        return adxb_decode_header_au(adxb, hdr, size);
    }
    return 0;
}

s32 ADXB_DecodeHeaderAdx(AdxbDecoder *adxb, u8 *hdr, s32 size) {
    s32 sp18;
    s32 sp14;
    s16 header_size;
    u8 *buffer;
    adxb->m_02 = 1;
    if (adx_parse_header_info(hdr, size, &header_size, (u8 *)&adxb->encoding_type, &adxb->bits, &adxb->block_bytes, (u8 *)&adxb->channels, &adxb->rate, &adxb->samples, &adxb->block_samples) < 0) {
        return 0;
    }
    if (adxb->encoding_type > 4) {
        if (adxb->ahx_handle == NULL) {
            adxerr_report_pair("E1060101 ADXB_DecodeHeaderAdx: ", "can't play AHX data by this handle");
            return 0;
        }
        adxb->bits = 8;
        adxb->block_bytes = (u8)(adxb->channels * 0xC0);
        adxb->block_samples = 0x60;
        adxb->format = 0xA;
        goto block_11;
    }
    if (adx_parse_header_cutoff(hdr, size, (u16 *)&adxb->cutoff) < 0) {
        return 0;
    }
    if (adx_parse_header_loop_points(hdr, size, (u16 *)&sp18, (u16 *)&sp14) < 0) {
        return 0;
    }
    adxb->channel->calc_adx_coeffs_at_offset(adxb->rate, adxb->cutoff);
    adx_decoder_channel_set_delay(adxb->channel, (u8 *)&sp18, (s16 *)&sp14);
    adx_parse_header_loop(hdr, size, &adxb->loop_enabled, &adxb->loop_type, &adxb->loop_count, &adxb->loop_start_sample, &adxb->loop_start_byte, &adxb->loop_end_sample, &adxb->loop_end_byte);
    adxb->format = 0;
block_11:
    buffer = adxb->m_4C;
    adxb->stream_channels = adxb->channels;
    adxb->stream_block_bytes = adxb->block_bytes;
    adxb->stream_block_samples = adxb->block_samples;
    adxb->buf = adxb->output_buffer;
    adxb->bufLen = adxb->wrap_len;
    adxb->rOff = adxb->wrap_offset;
    adxb->m_7C = adxb->m_48;
    adxb->m_7E = adxb->m_4A;
    adxb->m_80 = buffer;
    adxb->write_pos = 0;
    memset(buffer, 0, 4);
    return header_size;
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
    r->buffer_channels = channels;
    r->output_buffer = (s16 *)buffer;
    r->wrap_len = size;
    r->wrap_offset = wrap_offset;
    r->read = adxb_default_read;
    r->readArg = r;
    r->done = adxb_default_done;
    r->doneArg = r;
    return r;
}

void adxb_default_done(void *obj, s32 bytes, s32 samples) {
    AdxbDecoder *h = (AdxbDecoder *)obj;
    h->write_pos += samples;
    h->total_written += samples;
}

s16 *adxb_default_read(void *obj, s32 *pos, s32 *avail, s32 *remaining) {
    AdxbDecoder *h = (AdxbDecoder *)obj;
    *pos = h->write_pos;
    *avail = h->wrap_len - h->write_pos;
    *remaining = h->samples - h->total_written;
    return h->output_buffer;
}
void AdxbDecoder::clear_pool() {
    AdxDecoderChannel::clear_pool();
    memset(adx_channel_record_pool, 0, sizeof(adx_channel_record_pool));
}

}
