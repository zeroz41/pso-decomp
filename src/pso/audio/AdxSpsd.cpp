// CRI adx_bsps.c: the SPSD decoder (ADXB_CheckSpsd, ADXB_ExecOneSpsd, header decode and info).
#include "types.h"
#include "pso/unk/TLobby_803C1A58.h"
#include "pso/unk/TLobby.h"
#include "pso/audio/AdxbDecoder.h"

extern "C" {
s32 memset(void *, int, int);
int memcmp(const void *a, const void *b, unsigned long n);

s32 TLobby::is_spsd_header() {
    if (memcmp(this, "SPSD", 4) == 0) {
        return 1;
    }
    return 0;
}

void TLobby__sub_803C40D0(AdxbDecoder *o) {
    u16 *src = (u16 *)o->src;
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
                l[i] = src[i * 2];
                r[i] = src[i * 2 + 1];
            }
        } else {
            for (i = 0; i < n; i++) {
                l[i] = src[i];
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

s32 TLobby__sub_803C43A8(void *decoder, void *hdr, void *size) {
    AdxbDecoder *o = (AdxbDecoder *)decoder;
    s16 len;
    o->m_02 = 1;
    if (TLobby__sub_803C44C0((SpsdHeader *)hdr, (s32)size, &len, &o->m_0C, &o->bits, &o->block_bytes, &o->channels, &o->rate, &o->samples, &o->block_samples, &o->m_AA) < 0) {
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
    o->m_A8 = 2;
    memset(o->m_4C, 0, 4);
    return len;
}

s32 TLobby__sub_803C44C0(SpsdHeader *hdr, s32 size, s16 *len, s8 *out_0C, s8 *bits, s8 *block_bytes, s8 *channels, s32 *rate, s32 *samples, s32 *block_samples, s16 *format) {
    *len = hdr->m_07 * 0x10;
    *channels = (hdr->m_09 & 3) + 1;
    *rate = hdr->m_2A;
    switch (hdr->m_08) {
    case 0:
        *bits = 0x10;
        *block_bytes = *channels * 2;
        *block_samples = 1;
        *samples = hdr->m_0C / 2;
        *format = 0;
        break;
    case 1:
        *bits = 8;
        *block_bytes = *channels;
        *block_samples = 1;
        *samples = hdr->m_0C;
        *format = 1;
        break;
    case 2:
    case 3:
        *bits = 4;
        *block_bytes = *channels;
        *block_samples = 2;
        *samples = hdr->m_0C * 2;
        *format = 2;
        break;
    }
    *block_bytes = 2;
    *block_samples = 1;
    *samples = hdr->m_0C / 2;
    *bits = 0x10;
    *out_0C = -1;
    return 0;
}

}
