// CRI adx_bsps.c: the SPSD decoder (ADXB_CheckSpsd, ADXB_ExecOneSpsd, header decode and info).
#include "types.h"
#include <string.h>
#include "pso/network/TLobby.h"
#include "pso/audio/AdxbDecoder.h"
#include "pso/audio/AdxExpand.h"

extern "C" {

s32 adxb_is_spsd_header(const u8 *hdr) {
    if (memcmp(hdr, "SPSD", 4) == 0) {
        return 1;
    }
    return 0;
}

void adxb_exec_one_spsd(AdxbDecoder *adxb) {
    u16 *src = (u16 *)adxb->src;
    if (adxb->state == 1 && adxb->channel->get_state() == 0) {
        s16 *l;
        s16 *r;
        s32 i;
        s32 n;
        adxb->read(adxb->readArg, &adxb->pos, &adxb->avail, &adxb->remaining);
        n = adxb->bufLen - adxb->pos;
        if (n > adxb->avail) {
            n = adxb->avail;
        }
        if (n > adxb->maxLen) {
            n = adxb->maxLen;
        }
        l = adxb->buf + adxb->pos;
        if (adxb->channels == 2) {
            r = adxb->buf + (adxb->rOff + adxb->pos);
            for (i = 0; i < n; i++) {
                l[i] = src[i * 2];
                r[i] = src[i * 2 + 1];
            }
        } else {
            for (i = 0; i < n; i++) {
                l[i] = src[i];
            }
        }
        adxb->n = n;
        adxb->bytes = adxb->channels * (n * 2);
        adxb->state = 2;
    }
    if (adxb->state == 2) {
        adxb->done(adxb->doneArg, adxb->bytes, adxb->n);
        adxb->state = 3;
    }
}

s32 adxb_decode_header_spsd(AdxbDecoder *adxb, u8 *hdr, s32 size) {
    s16 len;
    adxb->m_02 = 1;
    if (adx_parse_spsd_header((SpsdHeader *)hdr, size, &len, &adxb->encoding_type, &adxb->bits, &adxb->block_bytes, &adxb->channels, &adxb->rate, &adxb->samples, &adxb->block_samples, &adxb->encoding) < 0) {
        return 0;
    }
    adxb->cutoff = 0;
    adxb->m_4A = 0;
    adxb->m_48 = 0;
    adxb->loop_count = 0;
    adxb->loop_type = 0;
    adxb->loop_end_byte = 0;
    adxb->loop_end_sample = 0;
    adxb->loop_start_byte = 0;
    adxb->loop_start_sample = 0;
    adxb->loop_enabled = 0;
    adxb->stream_channels = adxb->channels;
    adxb->stream_block_bytes = adxb->block_bytes;
    adxb->stream_block_samples = adxb->block_samples;
    adxb->buf = adxb->output_buffer;
    adxb->bufLen = adxb->wrap_len;
    adxb->rOff = adxb->wrap_offset;
    adxb->m_7C = adxb->m_48;
    adxb->m_7E = adxb->m_4A;
    adxb->m_80 = adxb->m_4C;
    adxb->write_pos = 0;
    adxb->total_written = 0;
    adxb->format = 2;
    memset(adxb->m_4C, 0, 4);
    return len;
}

s32 adx_parse_spsd_header(SpsdHeader *hdr, s32 size, s16 *len, s8 *encoding_type, s8 *bits, s8 *block_bytes, s8 *channels, s32 *rate, s32 *samples, s32 *block_samples, s16 *encoding) {
    *len = hdr->header_length * 0x10;
    *channels = (hdr->channel_flags & 3) + 1;
    *rate = hdr->rate;
    switch (hdr->encoding) {
    case 0:
        *bits = 0x10;
        *block_bytes = *channels * 2;
        *block_samples = 1;
        *samples = hdr->data_size / 2;
        *encoding = 0;
        break;
    case 1:
        *bits = 8;
        *block_bytes = *channels;
        *block_samples = 1;
        *samples = hdr->data_size;
        *encoding = 1;
        break;
    case 2:
    case 3:
        *bits = 4;
        *block_bytes = *channels;
        *block_samples = 2;
        *samples = hdr->data_size * 2;
        *encoding = 2;
        break;
    }
    *block_bytes = 2;
    *block_samples = 1;
    *samples = hdr->data_size / 2;
    *bits = 0x10;
    *encoding_type = -1;
    return 0;
}

}
