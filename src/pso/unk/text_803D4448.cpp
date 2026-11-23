#include "types.h"
#include "pso/unk/TLobby.h"
// RNA sound stream volume/pan control block: sndStream handles h[], per-channel
// pan, master vol (negative dB index into gcrna_volume_table) and mix feeds.
struct SndStreamVolumeState {
    u8 pad[8];
    u32 flags;
    u8 padc[4];
    s32 nch;
    u8 pad14[0x2C];
    s32 h[2];
    u8 pad48[0x10];
    s32 pan[2];
    s32 vol;
    s32 vol2; // mirrors vol when a parameter update fires
    s32 x68; // kept: feeds volume_table product into mix arg 5, identity unknown
    s32 x6c; // kept: feeds volume_table product into mix arg 6, identity unknown
    s32 x70; // kept: inverted (0x7F - x70) into mix arg 4, identity unknown
};

// Same stream object seen by set_stream_frequency: sample rate + play mode
// drive sndStreamFrq scaling (mode 1 rescales rate by 1125-step table math).
struct SndStreamFreqState {
    u8 pad[0xC];
    s32 nch;
    u8 pad10[4];
    s32 rate;
    u8 pad18[0x28];
    s32 h[2];
    u8 pad48[0x2C];
    s32 mode;
};

extern "C" {
void sndStreamMixParameterEx(s32 h, u8 a, u8 b, u8 c, u8 d, u8 e);
extern u8 gcrna_volume_table[];
extern s32 gcrna_pan_table[];
void set_sound_stream_volume(SndStreamVolumeState *o, s32 vol);
void sndStreamFrq(s32, s32);
// flags bit 1 marks a stream playing enough to push mix parameter updates.
inline s32 stat_803D4448(SndStreamVolumeState *o) {
    if (o == 0) {
        return -1;
    }
    return (o->flags >> 1) & 1;
}

void TLobby::set_stream_channel_pan(s32 ch, s32 pan) {
    SndStreamVolumeState *o = (SndStreamVolumeState *)this;
    if (o == 0) {
        return;
    }
    pan = (pan < 15) ? pan : 15;
    pan = (pan > -15) ? pan : -15;
    if (pan == o->pan[ch]) {
        return;
    }
    o->pan[ch] = pan;
    if (stat_803D4448(o) != 1) {
        return;
    }
    sndStreamMixParameterEx(o->h[ch], gcrna_volume_table[-o->vol2], gcrna_pan_table[o->pan[ch] + 15],
                         0x7F - o->x70,
                         (u32)(gcrna_volume_table[-o->vol] * gcrna_volume_table[-o->x68]) >> 7,
                         (u32)(gcrna_volume_table[-o->vol] * gcrna_volume_table[-o->x6c]) >> 7);
}

void set_sound_stream_volume(SndStreamVolumeState *o, s32 vol) {
    s32 i;
    if (o == 0) {
        return;
    }
    vol = (vol < 0) ? vol : 0;
    vol = (vol > -999) ? vol : -999;
    if (vol == o->vol) {
        return;
    }
    o->vol = vol;
    o->vol2 = o->vol;
    if (stat_803D4448(o) != 1) {
        return;
    }
    for (i = 0; i < o->nch; i++) {
        sndStreamMixParameterEx(o->h[i], gcrna_volume_table[-o->vol2], gcrna_pan_table[o->pan[i] + 15],
                             0x7F - o->x70,
                             (u32)(gcrna_volume_table[-o->vol] * gcrna_volume_table[-o->x68]) >> 7,
                             (u32)(gcrna_volume_table[-o->vol] * gcrna_volume_table[-o->x6c]) >> 7);
    }
}

void TLobby::set_stream_frequency(s32 rate) {
    s32 i;
    if (this == 0) {
        return;
    }
    ((SndStreamFreqState *)this)->rate = rate;
    for (i = 0; i < ((SndStreamFreqState *)this)->nch; i++) {
        if (((SndStreamFreqState *)this)->mode == 1) {
            sndStreamFrq(((SndStreamFreqState *)this)->h[i], (((SndStreamFreqState *)this)->rate * 0x464 + 0x464) / 1125);
        } else {
            sndStreamFrq(((SndStreamFreqState *)this)->h[i], ((SndStreamFreqState *)this)->rate);
        }
    }
}

}
