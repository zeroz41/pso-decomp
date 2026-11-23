#ifndef PSO_AUDIO_AIX_PLAYER_H
#define PSO_AUDIO_AIX_PLAYER_H

#include "types.h"
#include "pso/audio/SjRingBuffer.h"

class TLobby;
struct AdxStreamFile;
struct VObj_803C9E38;

// One interleaved track of an AIX file; each layer feeds its own ADXT player.
struct AixLayer {
    u8 channel_count;
    u8 pad_1[3];
    s32 sample_rate;
    u8 pad_8[8];
};

// Byte range of one AIX segment inside the file; players seek by 2048-byte sectors.
struct AixSegment {
    s32 offset;
    s32 size;
    s32 sample_count;
    s32 sample_rate;
};

// Decoded "AIXF" file header.
struct AixHeader {
    u8 f0;
    u8 f1;
    u8 pad_2[2];
    s32 f4;
    f32 f8;
    s8 layer_count;
    u8 pad_d[3];
    AixLayer layers[32];
    s32 segment_count;
    AixSegment segments[32];
    s32 info_count;
    s16 info[4][4];
};

// Header of one "AIXP" packet; "AIXE" marks the end of the data.
struct AixPacketHeader {
    u32 magic;
    s32 size;
    u8 layer;
    u8 layer_count;
    s16 data_size;
    s32 result;
};

// Splits one AIX input ring buffer into a ring buffer per layer.
struct AixDemuxer {
    s8 used;
    s8 state;
    s8 max_layers;
    s8 paused;
    s8 continuous;
    u8 pad_5[3];
    s32 bytes_consumed;
    u8 pad_c[0x10];
    SjRingBuffer *input;
    SjRingBuffer *layer_outputs[32];
    AixHeader header;
};

// Plays one AIX file: a demuxer fed from a file stream, one ADXT track per layer.
struct AixPlayer {
    u8 used;
    s8 state;
    u8 pad_2;
    s8 track_count;
    AixDemuxer *demuxer;
    AdxStreamFile *stream;
    TLobby *tracks[33];
    VObj_803C9E38 *track_inputs[70];
    u8 loop;
    u8 continue_segments;
    u8 pad_1aa[6];
    s32 segment;
    s32 start_segment;
    s32 loop_start;
    s32 loop_end;
};

LAYOUT_ASSERT(AixHeader_size, sizeof(AixHeader) == 0x438);
LAYOUT_ASSERT(AixPacketHeader_size, sizeof(AixPacketHeader) == 0x10);
LAYOUT_ASSERT(AixDemuxer_size, sizeof(AixDemuxer) == 0x4D8);
LAYOUT_ASSERT(AixPlayer_size, sizeof(AixPlayer) == 0x1C0);

extern "C" {
s32 demux_stream_chunks(AixDemuxer *demuxer);
s32 parse_aix_header(u8 *data, s32 size, AixHeader *header);
void get_entry_pair(AixDemuxer *demuxer, s32 segment, s32 *offset, s32 *size);
s32 TLobby__sub_803CE1D8(AixDemuxer *demuxer);
void set_flag_4(AixDemuxer *demuxer, s8 continuous);
void set_client_slot(AixDemuxer *demuxer, s8 paused);
s32 TLobby__sub_803CE1F4(AixDemuxer *demuxer);
void TLobby__sub_803CE2A0(AixPlayer *player);
}

#endif
