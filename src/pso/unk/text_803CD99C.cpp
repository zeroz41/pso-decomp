#include <string.h>
#include "pso/unk/text_803D2F1C.h"
#include "pso/unk/text_803CD99C.h"
#include "pso/audio/AixPlayer.h"

#include "pso/system/MiddlewareInterruptLock.h"

#include "types.h"

#pragma readonly_strings on

#define READ_BE32(p) (((p)[0] << 24) | ((p)[1] << 16) | ((p)[2] << 8) | (p)[3])
#define READ_BE16(p) (((p)[0] << 8) | (p)[1])

extern "C" {
char *cri_copyright_string = "(c)CRI";

AixDemuxer aix_demuxer_pool[4];

void TLobby__sub_803CD99C(void) {
    AixDemuxer *demuxer;
    s32 i;
    s32 size;
    SjRingBuffer *input;
    SjChunk rest;
    s32 used;
    SjChunk chunk;

    for (i = 0; i < 4; i++) {
        demuxer = &aix_demuxer_pool[i];
        used = demuxer->used;
        if (used == 1) {
            if (demuxer->state == 1) {
                input = demuxer->input;
                input->interface->get_chunk(input, 1, 0x1800, &chunk);
                size = parse_aix_header(chunk.data, chunk.size, &demuxer->header);
                if (size == 0) {
                    input->interface->unget_chunk(input, 1, &chunk);
                } else {
                    if (size != chunk.size) {
                        while (1) {
                        }
                    }
                    TLobby__sub_803D3130(&chunk, size, &chunk, &rest);
                    input->interface->put_chunk(input, 0, &chunk);
                    input->interface->unget_chunk(input, 1, &rest);
                    demuxer->bytes_consumed += size;
                    demuxer->state = 2;
                }
            } else if (demuxer->state == 2 && demuxer->paused == 0) {
                if (demux_stream_chunks(demuxer) == -1) {
                    demux_stream_chunks(demuxer);
                }
            }
        }
    }
}

static inline s32 parse_aix_packet_header(u8 *data, u32 size, void *out) {
    AixPacketHeader *header = (AixPacketHeader *)out;
    u8 *p;
    if (size < 0x10) {
        return 0;
    }
    p = data;
    header->magic = READ_BE32(p);
    p += 4;
    header->size = READ_BE32(p);
    p += 4;
    header->layer = *p++;
    header->layer_count = *p++;
    header->data_size = READ_BE16(p);
    p += 2;
    header->result = READ_BE32(p);
    p += 4;
    if (p - data != sizeof(AixPacketHeader)) {
        while (1) {
        }
    }
    return 0x10;
}

s32 demux_stream_chunks(AixDemuxer *demuxer) {
    SjRingBuffer *input;
    SjRingBuffer **outputs;
    s32 layer_count;
    s32 i;
    s32 ret;
    s32 layer;
    s32 len;
    s32 j;
    AixPacketHeader header;
    SjChunk packet;
    SjChunk rest;
    SjChunk out;
    ret = -3;
    outputs = demuxer->layer_outputs;
    layer_count = demuxer->header.layer_count;
    input = demuxer->input;
    for (i = 0; i < layer_count; i++) {
        input->interface->get_chunk(input, 1, 0x7FFFFFFF, &packet);
        if (parse_aix_packet_header(packet.data, packet.size, &header) == 0) {
            input->interface->unget_chunk(input, 1, &packet);
            return ret;
        }
        if (packet.size < header.size + 8) {
            input->interface->unget_chunk(input, 1, &packet);
            return ret;
        }
        if (header.magic == 0x41495845) {
            TLobby__sub_803D3130(&packet, header.size + 8, &packet, &rest);
            input->interface->put_chunk(input, 0, &packet);
            input->interface->unget_chunk(input, 1, &rest);
            if (input->interface->get_available(input, 1) <= 0) {
                demuxer->continuous = 0;
            }
            if (demuxer->continuous == 0) {
                demuxer->state = 3;
            }
            return ret;
        }
        layer = header.layer;
        if (layer >= demuxer->max_layers) {
            while (1) {
            }
        }
        if (outputs[layer]->interface->get_available(outputs[layer], 0) < header.data_size) {
            input->interface->unget_chunk(input, 1, &packet);
            return ret;
        }
        middleware_interrupt_lock_enter();
        ret = header.result;
        TLobby__sub_803D3130(&packet, header.size + 8, &packet, &rest);
        input->interface->unget_chunk(input, 1, &rest);
        TLobby__sub_803D3130(&packet, 0x10, &packet, &rest);
        if (rest.size < header.data_size) {
            while (1) {
            }
        }
        len = header.data_size;
        for (j = 0; j < len; j += out.size) {
            outputs[layer]->interface->get_chunk(outputs[layer], 0, rest.size - j, &out);
            memcpy(out.data, rest.data + j, out.size);
            outputs[layer]->interface->put_chunk(outputs[layer], 1, &out);
        }
        input->interface->put_chunk(input, 0, &packet);
        input->interface->put_chunk(input, 0, &rest);
        demuxer->bytes_consumed = rest.size + (packet.size + demuxer->bytes_consumed);
        middleware_interrupt_lock_leave();
    }
    return ret;
}

s32 parse_aix_header(u8 *data, s32 size, AixHeader *header) {
    s32 len;
    s32 header_size;
    u8 *p;
    s32 i;
    len = strlen(cri_copyright_string);
    if (size < 0x1800) {
        return 0;
    }
    if (READ_BE32(data) != 0x41495846) {
        return 0;
    }
    header_size = READ_BE32(data + 4);
    if (memcmp(data + (header_size + 8 - len), cri_copyright_string, len) != 0) {
        return 0;
    }
    header->f0 = data[8];
    header->f1 = data[9];
    header->f8 = (s32)READ_BE16(data + 0xA);
    header->f4 = READ_BE32(data + 0xC);
    header->segment_count = READ_BE16(data + 0x18);
    p = data + 0x20;
    for (i = 0; i < header->segment_count; i++) {
        header->segments[i].offset = READ_BE32(p);
        header->segments[i].size = READ_BE32(p + 4);
        header->segments[i].sample_count = READ_BE32(p + 8);
        header->segments[i].sample_rate = READ_BE32(p + 12);
        p += 0x10;
    }
    header->info_count = (s8)p[0];
    p += 8;
    for (i = 0; i < header->info_count; i++) {
        header->info[i][0] = READ_BE16(p);
        header->info[i][1] = READ_BE16(p + 2);
        header->info[i][2] = READ_BE16(p + 4);
        header->info[i][3] = READ_BE16(p + 6);
        p += 8;
    }
    header->layer_count = p[0];
    p += 8;
    for (i = 0; i < header->layer_count; i++) {
        header->layers[i].sample_rate = READ_BE32(p);
        header->layers[i].channel_count = p[4];
        p += 8;
    }
    return header_size + 8;
}

void get_entry_pair(AixDemuxer *demuxer, s32 segment, s32 *offset, s32 *size) {
    AixHeader *header = &demuxer->header;
    if (offset != 0) {
        *offset = header->segments[segment].offset;
    }
    if (size != 0) {
        *size = header->segments[segment].size;
    }
}

}
