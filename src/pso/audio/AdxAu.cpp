// CRI adx_bau.c: the Sun/NeXT .snd (AU) decoder (ADXB_ExecOneAu: mu-law, 8 and 16 bit).
#include "types.h"
#include <string.h>
#include "pso/unk/TLobby.h"
#include "pso/audio/AdxbDecoder.h"
#include "pso/audio/AdxExpand.h"

extern "C" {
/* mu-law sample expansion table (8-bit code -> s16 PCM) */
s16 stream_chunk_decode_table[256] = {
    -32124, -31100, -30076, -29052, -28028, -27004, -25980, -24956, -23932, -22908, -21884, -20860, -19836, -18812,
    -17788, -16764, -15996, -15484, -14972, -14460, -13948, -13436, -12924, -12412, -11900, -11388, -10876, -10364,
    -9852, -9340, -8828, -8316, -7932, -7676, -7420, -7164, -6908, -6652, -6396, -6140, -5884, -5628, -5372, -5116,
    -4860, -4604, -4348, -4092, -3900, -3772, -3644, -3516, -3388, -3260, -3132, -3004, -2876, -2748, -2620, -2492,
    -2364, -2236, -2108, -1980, -1884, -1820, -1756, -1692, -1628, -1564, -1500, -1436, -1372, -1308, -1244, -1180,
    -1116, -1052, -988, -924, -876, -844, -812, -780, -748, -716, -684, -652, -620, -588, -556, -524, -492, -460,
    -428, -396, -372, -356, -340, -324, -308, -292, -276, -260, -244, -228, -212, -196, -180, -164, -148, -132,
    -120, -112, -104, -96, -88, -80, -72, -64, -56, -48, -40, -32, -24, -16, -8, 0, 32124, 31100, 30076, 29052,
    28028, 27004, 25980, 24956, 23932, 22908, 21884, 20860, 19836, 18812, 17788, 16764, 15996, 15484, 14972, 14460,
    13948, 13436, 12924, 12412, 11900, 11388, 10876, 10364, 9852, 9340, 8828, 8316, 7932, 7676, 7420, 7164, 6908,
    6652, 6396, 6140, 5884, 5628, 5372, 5116, 4860, 4604, 4348, 4092, 3900, 3772, 3644, 3516, 3388, 3260, 3132,
    3004, 2876, 2748, 2620, 2492, 2364, 2236, 2108, 1980, 1884, 1820, 1756, 1692, 1628, 1564, 1500, 1436, 1372,
    1308, 1244, 1180, 1116, 1052, 988, 924, 876, 844, 812, 780, 748, 716, 684, 652, 620, 588, 556, 524, 492, 460,
    428, 396, 372, 356, 340, 324, 308, 292, 276, 260, 244, 228, 212, 196, 180, 164, 148, 132, 120, 112, 104, 96,
    88, 80, 72, 64, 56, 48, 40, 32, 24, 16, 8, 0
};

// Little-endian reads of big-endian header fields, swapped in place afterwards.
#define READ_LE32(b) ((b)[0] | ((b)[1] << 8) | ((b)[2] << 16) | ((b)[3] << 24))
#define SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | ((x) << 24))

void adxb_decode_au_ulaw(AdxbDecoder *o);

void adxb_exec_one_au(AdxbDecoder *adxb) {
    s16 kind;

    kind = adxb->encoding;
    if (kind == 2) {
        adxb_decode_au_ulaw(adxb);
        return;
    }
    if (kind == 1) {
        TLobby__sub_803C2A00(adxb);
        return;
    }
    process_byteswapped_pcm_transfer(adxb);
}

void adxb_decode_au_ulaw(AdxbDecoder *o) {
    u8 *src = o->src;

    if (o->state == 1 && o->channel->get_state() == 0) {
        s16 *dst;
        s16 *dst2;
        s32 i;
        s32 n;
        o->read(o->readArg, &o->pos, &o->avail, &o->x78);
        n = o->bufLen - o->pos;
        if (n > o->avail) {
            n = o->avail;
        }
        if (n > o->maxLen) {
            n = o->maxLen;
        }
        dst = o->buf + o->pos;
        if (o->channels == 2) {
            dst2 = o->buf + (o->rOff + o->pos);
            for (i = 0; i < n; i++) {
                dst[i] = stream_chunk_decode_table[src[i * 2]];
                dst2[i] = stream_chunk_decode_table[src[i * 2 + 1]];
            }
        } else {
            for (i = 0; i < n; i++) {
                dst[i] = stream_chunk_decode_table[src[i]];
            }
        }
        o->n = n;
        o->bytes = n * o->channels;
        o->state = 2;
    }
    if (o->state == 2) {
        o->done(o->doneArg, o->bytes, o->n);
        o->state = 3;
    }
}

void TLobby__sub_803C2A00(AdxbDecoder *o) {
    u8 *src = o->src;
    if (o->state == 1 && o->channel->get_state() == 0) {
        s16 *l;
        s16 *r;
        s32 i;
        s32 n;
        o->read(o->readArg, &o->pos, &o->avail, &o->x78);
        n = o->bufLen - o->pos;
        if (n > o->avail) {
            n = o->avail;
        }
        if (n > o->maxLen) {
            n = o->maxLen;
        }
        l = o->buf + o->pos;
        if (o->channels == 2) {
            r = o->buf + (o->rOff + o->pos);
            for (i = 0; i < n; i++) {
                l[i] = (src[i * 2] << 8) & 0xFF00;
                r[i] = (src[i * 2 + 1] << 8) & 0xFF00;
            }
        } else {
            for (i = 0; i < n; i++) {
                l[i] = (src[i] << 8) & 0xFF00;
            }
        }
        o->n = n;
        o->bytes = n * o->channels;
        o->state = 2;
    }
    if (o->state == 2) {
        o->done(o->doneArg, o->bytes, o->n);
        o->state = 3;
    }
}
}

void process_byteswapped_pcm_transfer(AdxbDecoder *o) {
    u16 *src = (u16 *)o->src;
    u16 *l;
    s32 v;
    u16 *r;
    s32 i;
    s32 n;
    if (o->state == 1 && o->channel->get_state() == 0) {
        o->read(o->readArg, &o->pos, &o->avail, &o->x78);
        n = o->bufLen - o->pos;
        if (n > o->avail) {
            n = o->avail;
        }
        if (n > o->maxLen) {
            n = o->maxLen;
        }
        l = (u16 *)o->buf + o->pos;
        if (o->channels == 2) {
            r = (u16 *)o->buf + (o->rOff + o->pos);
            for (i = 0; i < n; i++) {
                v = src[i * 2];
                l[i] = (src[i * 2] >> 8) | (v << 8);
                r[i] = (src[i * 2 + 1] >> 8) | (src[i * 2 + 1] << 8);
            }
        } else {
            for (i = 0; i < n; i++) {
                l[i] = (src[i] >> 8) | (src[i] << 8);
            }
        }
        o->n = n;
        o->bytes = o->channels * (n * 2);
        o->state = 2;
    }
    if (o->state == 2) {
        o->done(o->doneArg, o->bytes, o->n);
        o->state = 3;
    }
}
extern "C" {

s32 adxb_decode_header_au(AdxbDecoder *adxb, u8 *hdr, s32 size) {
    s32 format;
    s32 samples;
    s32 bits;
    s32 channels;
    s32 rate;
    s16 len;
    s32 err;
    u8 *data;
    u8 *buf;
    adxb->m_02 = 1;
    if (size < 8) {
        len = 0;
        err = -1;
    } else {
        data = adx_au_parse_header(hdr, size, &rate, &channels, &bits, &samples, &format);
        if (data == NULL) {
            err = -1;
        } else {
            len = data - hdr;
            if (len <= 0) {
                err = -1;
            } else {
                err = 0;
                adxb->rate = rate;
                adxb->channels = channels;
                adxb->bits = bits;
                adxb->samples = samples;
                adxb->encoding_type = -1;
                adxb->block_bytes = (adxb->channels * adxb->bits) / 8;
                adxb->block_samples = 1;
            }
        }
    }
    if (err < 0) {
        return 0;
    }
    buf = adxb->m_4C;
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
    adxb->m_80 = buf;
    adxb->write_pos = 0;
    adxb->total_written = 0;
    adxb->format = 4;
    adxb->encoding = format;
    memset(buf, 0, 4);
    return len;
}

s32 adxb_is_au_header(const u8 *hdr) {
    if (memcmp(hdr, ".snd", 4) == 0 || memcmp(hdr, ".sd", 4) == 0) {
        return 1;
    }
    return 0;
}

// The AU header's fields are big-endian.
u8 *adx_au_parse_header(u8 *hdr, s32 size, s32 *rate, s32 *channels, s32 *bits, s32 *samples, s32 *format) {
    u32 magic;
    u32 offset;
    u32 data_size;
    u32 encoding;

    magic = READ_LE32(hdr);
    if (magic != 0x0064732E && magic != 0x646E732E) {
        return NULL;
    }
    offset = READ_LE32(hdr + 4);
    offset = SWAP32(offset);
    if ((s32)offset > size) {
        return NULL;
    }
    data_size = READ_LE32(hdr + 8);
    data_size = SWAP32(data_size);
    encoding = READ_LE32(hdr + 12);
    encoding = SWAP32(encoding);
    switch (encoding) {
    case 1:
        *format = 2;
        *bits = 8;
        break;
    case 2:
        *format = 1;
        *bits = 8;
        break;
    case 3:
        *format = 0;
        *bits = 16;
        break;
    default:
        return NULL;
    }
    *rate = READ_LE32(hdr + 16);
    *rate = SWAP32(*rate);
    *channels = READ_LE32(hdr + 20);
    *channels = SWAP32(*channels);
    if (*format == 2) {
        *samples = (s32)data_size / *channels;
    } else if (*format == 1) {
        *samples = (s32)data_size / *channels;
    } else if (*format == 0) {
        *samples = (s32)data_size / 2 / *channels;
    } else {
        *samples = 0x7FFF0000;
    }
    return hdr + offset;
}
}
