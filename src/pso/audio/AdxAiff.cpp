// CRI adx_baif.c: the AIFF decoder (ADXB_ExecOneAiff and its 8/16-bit steps, header check and parse).
#include "types.h"
#include "pso/unk/TLobby_803C1A58.h"
#include "pso/unk/TLobby.h"
#include "pso/audio/AdxbDecoder.h"
#include "pso/audio/AiffHeader.h"

extern "C" {
s32 memset(void *, int, int);
int memcmp(const void *a, const void *b, unsigned long n);

void TLobby::dispatch_network_state() {
    AdxbDecoder *o = (AdxbDecoder *)this;
    if (o->m_AA == 1) {
        decode_pcm8_stream();
        return;
    }
    copy_byteswapped_pcm_samples();
}

void TLobby::decode_pcm8_stream() {
    AdxbDecoder *o = (AdxbDecoder *)this;
    u8 *src = o->src;
    if (o->state == 1 && o->id->get_client_count() == 0) {
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

void TLobby::copy_byteswapped_pcm_samples() {
    AdxbDecoder *o = (AdxbDecoder *)this;
    u16 *src = (u16 *)o->src;
    u16 *l;
    s32 v;
    u16 *r;
    s32 i;
    s32 n;
    if (o->state == 1 && o->id->get_client_count() == 0) {
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

s32 TLobby::parse_stream_header(void *hdr, void *size) {
    AdxbDecoder *o = (AdxbDecoder *)this;
    u8 *p = (u8 *)hdr;
    s32 frames;
    s32 bits;
    s32 channels;
    s32 rate;
    s16 len;
    s32 st;
    u8 *e;
    o->m_02 = 1;
    if ((s32)size < 0x1000) {
        len = 0;
        st = -1;
    } else if ((e = TLobby__sub_803C2388(p, &rate, &channels, &bits, &frames)) == NULL) {
        st = -1;
    } else if ((len = e - p) <= 0) {
        st = -1;
    } else {
        o->rate = rate;
        o->channels = channels;
        o->bits = bits;
        o->samples = frames;
        o->m_0C = -1;
        o->block_bytes = (o->channels * o->bits) / 8;
        o->block_samples = 1;
        st = 0;
    }
    if (st < 0) {
        return 0;
    }
    o->m_1C = 0;
    o->m_4A = 0;
    o->m_48 = 0;
    o->m_26 = 0;
    o->m_24 = 0;
    o->m_34 = 0;
    o->m_30 = 0;
    o->m_2C = 0;
    o->m_28 = 0;
    o->m_20 = 0;
    o->stream_channels = o->channels;
    o->stream_block_bytes = o->block_bytes;
    o->stream_block_samples = o->block_samples;
    o->buf = o->m_3C;
    o->bufLen = o->wrap_len;
    o->rOff = o->wrap_offset;
    o->m_7C = o->m_48;
    o->m_7E = o->m_4A;
    o->m_80 = o->m_4C;
    o->m_9C = 0;
    o->m_98 = 0;
    o->m_A8 = 3;
    if (o->bits == 8) {
        o->m_AA = 1;
    } else {
        o->m_AA = 0;
    }
    memset(o->m_4C, 0, 4);
    return len;
}

s32 TLobby::is_aiff_header() {
    AiffFormHeader *h = (AiffFormHeader *)this;
    if (memcmp(h->id, "FORM", 4) == 0 && memcmp(h->type, "AIFF", 4) == 0) {
        return 1;
    }
    return 0;
}

// Little-endian reads of big-endian header fields, swapped in place afterwards.
#define READ_LE32(b) ((b)[0] | ((b)[1] << 8) | ((b)[2] << 16) | ((b)[3] << 24))
#define SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | ((x) << 24))
#define READ_LE16(b) ((u16)(b)[0] | ((u16)(b)[1] << 8))
#define SWAP16(x) ((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00))

// Walks the chunks of an AIFF ("FORM"/"AIFF") header, whose fields are big-endian: COMM gives
// the format, SSND the start of the sample data, which is returned (NULL if not an AIFF).
u8 *TLobby__sub_803C2388(u8 *hdr, s32 *rate, s32 *channels, s32 *bits, s32 *frames) {
    u8 *p;
    u8 *end;
    u8 *data;
    s32 id;
    s32 size;
    s32 type;
    s32 have_comm;
    s32 have_ssnd;
    u16 exponent;
    u16 mantissa;
    u32 offset;

    p = hdr + 12;
    have_comm = 0;
    have_ssnd = 0;
    data = NULL;
    id = READ_LE32(hdr);
    size = READ_LE32(hdr + 4);
    size = SWAP32(size);
    type = READ_LE32(hdr + 8);
    if (id != 0x4D524F46) {
        return NULL;
    }
    if (type != 0x46464941) {
        return NULL;
    }
    end = p + size - 4;
    while (p < end) {
        id = READ_LE32(p);
        size = READ_LE32(p + 4);
        size = SWAP32(size);
        p += 8;
        switch (id) {
        case 0x4D4D4F43:
            if (have_comm != 0) {
                break;
            }
            if (size < 18) {
                return NULL;
            }
            have_comm = 1;
            *channels = READ_LE16(p);
            *channels = SWAP16(*channels);
            *frames = READ_LE32(p + 2);
            *frames = SWAP32(*frames);
            *bits = READ_LE16(p + 6);
            *bits = SWAP16(*bits);
            exponent = READ_LE16(p + 8);
            exponent = SWAP16(exponent);
            mantissa = READ_LE16(p + 10);
            mantissa = SWAP16(mantissa);
            p += 18;
            *rate = mantissa >> (0x400E - exponent);
            if (have_ssnd != 0) {
                return data;
            }
            break;
        case 0x444E5353:
            if (have_ssnd != 0) {
                break;
            }
            have_ssnd = 1;
            offset = READ_LE32(p);
            offset = SWAP32(offset);
            p += 4;
            data = p + offset;
            if (have_comm != 0) {
                return data;
            }
            break;
        default:
            p += (size + 1) & ~1;
            break;
        }
    }
    return data;
}

}
