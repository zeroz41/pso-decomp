#ifndef MUSYX_MUSYX_H
#define MUSYX_MUSYX_H

#include "types.h"

typedef u32 SND_SEQID;

typedef struct SND_FVECTOR {
    f32 x;
    f32 y;
    f32 z;
} SND_FVECTOR;

typedef struct SND_FMATRIX {
    f32 m[3][3];
    f32 t[3];
} SND_FMATRIX;

typedef struct SND_AUX_INFO {
    union SND_AUX_DATA {
        struct SND_AUX_BUFFERUPDATE {
            s32 *left;
            s32 *right;
            s32 *surround;
        } bufferUpdate;
        struct SND_AUX_PARAMETERUPDATE {
            u16 para[4];
        } parameterUpdate;
    } data;
} SND_AUX_INFO;

typedef void (*SND_AUX_CALLBACK)(u8 reason, SND_AUX_INFO *info, void *user);

typedef struct SND_STUDIO_INPUT {
    u8 vol;
    u8 volA;
    u8 volB;
    u8 srcStudio;
} SND_STUDIO_INPUT;

extern "C" {
void sndSetAuxProcessingCallbacks(u8 studio, SND_AUX_CALLBACK auxA, void *userA, u8 midiA, SND_SEQID seqIDA,
                                  SND_AUX_CALLBACK auxB, void *userB, u8 midiB, SND_SEQID seqIDB);
void sndAuxCallbackReverbHI(u8 reason, SND_AUX_INFO *info, void *user);
void sndAuxCallbackChorus(u8 reason, SND_AUX_INFO *info, void *user);
}

#endif
