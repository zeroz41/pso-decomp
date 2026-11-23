#include "types.h"
#include "pso/audio/GcrnaStream.h"

extern "C" {
void sndStreamMixParameterEx(u32 stream_id, u8 volume, u8 pan, u8 surround_pan, u8 aux_a, u8 aux_b);
void sndStreamFrq(u32 stream_id, s32 frequency);
extern u8 gcrna_volume_table[1000];
extern u32 gcrna_pan_table[31];

inline s32 gcrna_get_play_switch(GcrnaStream *stream) {
    if (stream == 0) {
        return -1;
    }
    return (stream->flags >> 1) & 1;
}

void set_stream_channel_pan(GcrnaStream *stream, s32 channel, s32 pan) {
    if (stream == 0) {
        return;
    }
    pan = (pan < 15) ? pan : 15;
    pan = (pan > -15) ? pan : -15;
    if (pan == stream->pan[channel]) {
        return;
    }
    stream->pan[channel] = pan;
    if (gcrna_get_play_switch(stream) != 1) {
        return;
    }
    sndStreamMixParameterEx(stream->stream_ids[channel], gcrna_volume_table[-stream->output_volume],
                            gcrna_pan_table[stream->pan[channel] + 15], 127 - stream->surround_pan,
                            (u32)(gcrna_volume_table[-stream->volume] * gcrna_volume_table[-stream->aux_a_send]) >> 7,
                            (u32)(gcrna_volume_table[-stream->volume] * gcrna_volume_table[-stream->aux_b_send]) >> 7);
}

void set_sound_stream_volume(GcrnaStream *stream, s32 volume) {
    s32 channel;
    if (stream == 0) {
        return;
    }
    volume = (volume < 0) ? volume : 0;
    volume = (volume > -999) ? volume : -999;
    if (volume == stream->volume) {
        return;
    }
    stream->volume = volume;
    stream->output_volume = stream->volume;
    if (gcrna_get_play_switch(stream) != 1) {
        return;
    }
    for (channel = 0; channel < stream->stream_count; channel++) {
        sndStreamMixParameterEx(stream->stream_ids[channel], gcrna_volume_table[-stream->output_volume],
                                gcrna_pan_table[stream->pan[channel] + 15], 127 - stream->surround_pan,
                                (u32)(gcrna_volume_table[-stream->volume] * gcrna_volume_table[-stream->aux_a_send]) >> 7,
                                (u32)(gcrna_volume_table[-stream->volume] * gcrna_volume_table[-stream->aux_b_send]) >> 7);
    }
}

void set_stream_frequency(GcrnaStream *stream, s32 frequency) {
    s32 channel;
    if (stream == 0) {
        return;
    }
    stream->frequency = frequency;
    for (channel = 0; channel < stream->allocated_channels; channel++) {
        if (stream->frequency_mode == 1) {
            sndStreamFrq(stream->stream_ids[channel], (stream->frequency * 1124 + 1124) / 1125);
        } else {
            sndStreamFrq(stream->stream_ids[channel], stream->frequency);
        }
    }
}

}
