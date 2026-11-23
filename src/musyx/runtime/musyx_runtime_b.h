#ifndef MUSYX_RUNTIME_B_H
#define MUSYX_RUNTIME_B_H

#pragma dont_inline on
#include "types.h"
#include "musyx/musyx.h"
#include <string.h>
#include "musyx/runtime/musyx_dspvoice.h"
#include "pso/audio/SoundMixVoice.h"
#include "pso/audio/SoundReverb.h"

struct AdxbDecoder;

struct RecoveredGlobal_803C0B08_lbl_80570AC0 {
    s32 value;
    u8 remaining[0x9BC];
};

struct RecoveredGlobal_803C0AD8_lbl_80570AC0 {
    s32 value;
    u8 remaining[0x9BC];
};

struct RecoveredGlobal_803BD5C4_lbl_805663D8 {
    s32 value;
    u8 remaining[0x6DC];
};

struct TLobbySlot_803BD214 {
    u8 pad_0[0x24];
    s32 flags;
    u8 pad_28[0xA4];
    u16 code_cc;
    u16 code_ce;
    u8 pad_d0[0x24];
};

struct Obj_803BE860 {
    u8 pad[0x1c4];
    u8 flag;
    f32 a, b, c, d, e, f;
};

struct Rec_803BE528 { u8 data[0x280]; };

struct Slot_803BCCE0 {
    u8 pad_0[0x1c]; s32 f1c; u32 f20; u32 f24[4]; u8 pad_34[0x70 - 0x34];
    u16 f70; u8 pad_72[0x90 - 0x72]; u8 f90; u8 pad_91[3]; s32 f94; s32 f98;
    u8 f9c; u8 pad_9d[3]; u8 fa0; u8 pad_a1[0xd4 - 0xa1]; u8 fd4; u8 pad_d5[0xec - 0xd5];
    u8 fec; u8 pad_ed[0xf4 - 0xed];
};

struct Slot_803BD110 {
    u8 pad_0[0x1c]; s32 f1c; u32 f20; u32 f24[4]; u8 pad_34[0x70 - 0x34];
    u16 f70; u8 pad_72[0x90 - 0x72]; u8 f90; u8 pad_91[3]; s32 f94; s32 f98;
    u8 f9c; u8 pad_9d[3]; u8 fa0; u8 pad_a1[0xd4 - 0xa1]; u8 fd4; u8 pad_d5[0xec - 0xd5];
    u8 fec; u8 pad_ed[0xf4 - 0xed];
};

struct Slot_803BD124 {
    u8 pad_0[0x1c]; s32 f1c; u32 f20; u32 f24[4]; u8 pad_34[0x70 - 0x34];
    u16 f70; u8 pad_72[0x90 - 0x72]; u8 f90; u8 pad_91[3]; s32 f94; s32 f98;
    u8 f9c; u8 pad_9d[3]; u8 fa0; u8 pad_a1[0xd4 - 0xa1]; u8 fd4; u8 pad_d5[0xec - 0xd5];
    u8 fec; u8 pad_ed[0xf4 - 0xed];
};

struct Slot_803BD0FC {
    u8 pad_0[0x1c]; s32 f1c; u32 f20; u32 f24[4]; u8 pad_34[0x70 - 0x34];
    u16 f70; u8 pad_72[0x90 - 0x72]; u8 f90; u8 pad_91[3]; s32 f94; s32 f98;
    u8 f9c; u8 pad_9d[3]; u8 fa0; u8 pad_a1[0xd4 - 0xa1]; u8 fd4; u8 pad_d5[0xec - 0xd5];
    u8 fec; u8 pad_ed[0xf4 - 0xed];
};

struct Slot_803BCD08 {
    u8 pad_0[0x1c]; s32 f1c; u32 f20; u32 f24[4]; u8 pad_34[0x70 - 0x34];
    u16 f70; u8 pad_72[0x90 - 0x72]; u8 f90; u8 pad_91[3]; s32 f94; s32 f98;
    u8 f9c; u8 pad_9d[3]; u8 fa0; u8 pad_a1[0xd4 - 0xa1]; u8 fd4; u8 pad_d5[0xec - 0xd5];
    u8 fec; u8 pad_ed[0xf4 - 0xed];
};

struct Slot_803BD0C8 {
    u8 pad_0[0x1c]; s32 f1c; u32 f20; u32 f24[4]; u8 pad_34[0x70 - 0x34];
    u16 f70; u8 pad_72[0x90 - 0x72]; u8 f90; u8 pad_91[3]; s32 f94; s32 f98;
    u8 f9c; u8 pad_9d[3]; u8 fa0; u8 pad_a1[0xd4 - 0xa1]; u8 fd4; u8 pad_d5[0xec - 0xd5];
    u8 fec; u8 pad_ed[0xf4 - 0xed];
};

struct Slot_803BD0E8 {
    u8 pad_0[0x1c]; s32 f1c; u32 f20; u32 f24[4]; u8 pad_34[0x70 - 0x34];
    u16 f70; u8 pad_72[0x90 - 0x72]; u8 f90; u8 pad_91[3]; s32 f94; s32 f98;
    u8 f9c; u8 pad_9d[3]; u8 fa0; u8 pad_a1[0xd4 - 0xa1]; u8 fd4; u8 pad_d5[0xec - 0xd5];
    u8 fec; u8 pad_ed[0xf4 - 0xed];
};

struct Slot_803BD174 {
    u8 pad_0[0x1c]; s32 f1c; u32 f20; u32 f24[4]; u8 pad_34[0x70 - 0x34];
    u16 f70; u8 pad_72[0x90 - 0x72]; u8 f90; u8 pad_91[3]; s32 f94; s32 f98;
    u8 f9c; u8 pad_9d[3]; u8 fa0; u8 pad_a1[0xd4 - 0xa1]; u8 fd4; u8 pad_d5[0xec - 0xd5];
    u8 fec; u8 pad_ed[0xf4 - 0xed];
};

struct Slot_803BDA2C {
    u8 pad_0[0x1c]; s32 f1c; u32 f20; u32 f24[4]; u8 pad_34[0x70 - 0x34];
    u16 f70; u8 pad_72[0x90 - 0x72]; u8 f90; u8 pad_91[3]; s32 f94; s32 f98;
    u8 f9c; u8 pad_9d[3]; u8 fa0; u8 pad_a1[0xd4 - 0xa1]; u8 fd4; u8 pad_d5[0xec - 0xd5];
    u8 fec; u8 pad_ed[0xf4 - 0xed];
};

struct Obj_803BDCB8 { u8 pad[0x281]; volatile u8 busy; };

struct Slot_803BD138 {
    u8 pad_0[0x1c]; s32 f1c; u32 f20; u32 f24[4]; u8 pad_34[0x70 - 0x34];
    u16 f70; u8 pad_72[0x90 - 0x72]; u8 f90; u8 pad_91[3]; s32 f94; s32 f98;
    u8 f9c; u8 pad_9d[3]; u8 fa0; u8 pad_a1[0xd4 - 0xa1]; u8 fd4; u8 pad_d5[0xec - 0xd5];
    u8 fec; u8 pad_ed[0xf4 - 0xed];
};

struct Slot_803BCEC8 {
    u8 pad_0[0x24]; u32 f24[0x1f];
    u8 pad_a0[0xec - 0xa0]; u8 fec; u8 ffd; u8 fee; u8 pad_ef[5];
};

struct Slot_803BD19C {
    u8 pad_0[0x24]; u32 f24[4]; u32 f34; u32 f38[0x1f];
    u8 pad_b4[0xe4 - 0xb4 - 0x0]; u8 fe4; u8 pad_e5[0xf4 - 0xe5];
};

typedef s32 (*RecoveredCallback_d26337a2813d)();

struct Cb_803BE7D8 { s32 a; void (*fn)(s32); };

struct Slot_803BD26C {
    u8 pad_0[0xd0]; s16 fd0; s16 fd2; u8 pad_d4[0xf0 - 0xd4]; u32 ff0;
};

struct Ent_803BB8F0 { u8 code; u8 flags; u8 pad[2]; s32 val; };

struct Obj_803BB8F0 { Ent_803BB8F0 ents[4]; u8 pad20[2]; u8 count; };

struct Obj_803BC7E4 { u8 pad[0x121]; u8 b121; u8 b122; u8 pad123[0x1C4 - 0x123]; s16 v1c4; u8 pad1c6[0x1D0 - 0x1C6]; s16 v1d0; };

struct Obj_803BC884 { u8 pad[0x121]; u8 b121; u8 b122; };

struct Slot_803BD694 {
    u8 pad_0[0x20]; u32 f20; u8 pad_24[0x78 - 0x24]; u32 f78; u8 pad_7c[0x90 - 0x7C];
    u8 f90; u8 pad_91[0xEC - 0x91]; u8 fec; u8 pad_ed[0xF4 - 0xED];
};

struct Hdr_803BD8A8 { u32 f0; u32 info; };

struct Hdr_803BD93C { u32 f0; u32 info; };

typedef u8 * (*RecoveredCallback_fa840eeea008)(u8 *, u32);

#define SLOTS_803BCD1C (*(Slot_803BCD1C **)&dspVoice)
struct Blk_803BCD1C { s32 w[8]; };

struct Slot_803BCD1C {
    u8 pad_0[0x18]; s32 f18; s32 f1c; u8 pad_20[4]; s32 f24[19]; s16 f70; u8 pad_72[2];
    Blk_803BCD1C f74; u8 pad_94[0xA4 - 0x94]; s8 fa4; u8 pad_a5[0xB8 - 0xA5];
    s32 fb8; s32 fbc; s16 fc0; u8 pad_c2[2]; s32 fc4; u8 pad_c8[0xE4 - 0xC8];
    u8 fe4; u8 fe5; u8 fe6; u8 fe7; u8 pad_e8[0xF0 - 0xE8]; s32 ff0;
};

#define SLOTS_803BCF18 (*(Slot_803BCF18 **)&dspVoice)
struct Slot_803BCF18 {
    u8 pad_0[0x24]; s32 f24; u8 pad_28[0xA4 - 0x28]; s8 fa4; u8 pad_a5[0xB8 - 0xA5];
    s32 fb8; s32 fbc; u16 fc0; u8 pad_c2[2]; s32 fc4; s8 fc8; s8 fc9; s8 fca; u8 pad_cb[0xF4 - 0xCB];
};

struct ArgA_803BCF18 { u16 f0; u16 f2; u16 f4; u16 f6; };

struct ArgB_803BCF18 { s32 f0; s32 f4; u16 f8; u16 fa; };

struct Req_803BDAE4 {
    void *next; s32 owner; s32 type; s32 prio; u8 *src; u32 dst; u32 len; void *cb; void *f20; void *f24;
};

struct Q_803BDAE4 { Req_803BDAE4 reqs[16]; volatile u8 wp; volatile u8 count; };

struct ARQRequest_803BDCD0 {
    ARQRequest_803BDCD0 *next;
    u32 owner;
    u32 type;
    u32 priority;
    u32 source;
    u32 dest;
    u32 length;
    void (*callback)(u32);
};

struct ARAMTransferJob_803BDCD0 {
    ARQRequest_803BDCD0 arq;
    void (*callback)(u32);
    u32 user;
};

struct ARAMTransferQueue_803BDCD0 {
    ARAMTransferJob_803BDCD0 queue[16];
    volatile u8 write;
    volatile u8 valid;
};

struct AramQueues_803BDCD0 {
    ARAMTransferQueue_803BDCD0 lo;
    ARAMTransferQueue_803BDCD0 hi;
};

struct StreamBuffer_803BDCD0 {
    StreamBuffer_803BDCD0 *next;
    u32 aram;
    u32 length;
    u32 allocLength;
};

typedef struct S_803BF408 {
    u8 pad0[0x1A8];
    f32 f1A8;
    u8 pad1AC[0x1C4 - 0x1AC];
    u8 disabled;
} S_803BF408;

struct Src_803BF884 {
    s32 *dest;
    s32 *smpBase;
    s32 *old;
    u32 posLo;
    u32 posHi;
    u32 pitchLo;
    u32 pitchHi;
};

struct Work_803BF884 {
    s32 *lastLeft[3];
    s32 *lastRight[3];
    s32 *lastSur[3];
    u8 currentLast;
    s32 oldLeft[4];
    s32 oldRight[4];
    s32 oldSur[4];
    u32 currentPosLo;
    u32 currentPosHi;
    s32 pitchOffset;
    u32 pitchOffsetPeriodCount;
    u32 pitchOffsetPeriod;
    Src_803BF884 src;
};


typedef struct CTRL_SOURCE {
    u8 midiCtrl;
    u8 combine;
    s32 scale;
} CTRL_SOURCE;

typedef struct CTRL_DEST {
    CTRL_SOURCE source[4];
    u16 oldValue;
    u8 numSource;
} CTRL_DEST;

typedef struct SYNTH_LFO {
    u32 time;
    u32 period;
    s16 value;
    s16 lastValue;
} SYNTH_LFO;

typedef struct SYNTH_VOICE {
    u8 pad_0[0x90];
    u64 time;
    u8 pad_98[0xA8 - 0x98];
    u8 timeUsedByInput;
    u8 pad_a9[0x121 - 0xA9];
    u8 midi;
    u8 midiSet;
    u8 pad_123[0x12F - 0x123];
    u8 b12F;
    u8 pad_130[0x158 - 0x130];
    u32 w158;
    u8 pad_15c[0x1BC - 0x15C];
    SYNTH_LFO lfo[2];
    u8 lfoUsedByInput[2];
    u8 pad_1d6[0x214 - 0x1D6];
    u32 midiDirtyFlags;
    CTRL_DEST inpVolume;
    CTRL_DEST inpPanning;
    CTRL_DEST inpSurroundPanning;
    CTRL_DEST inpPitchBend;
    CTRL_DEST inpDoppler;
    CTRL_DEST inpModulation;
    CTRL_DEST inpPedal;
    CTRL_DEST inpPortamento;
    CTRL_DEST inpPreAuxA;
    CTRL_DEST inpReverb;
    CTRL_DEST inpPreAuxB;
    CTRL_DEST inpPostAuxB;
    CTRL_DEST inpTremolo;
} SYNTH_VOICE;

extern "C" {
extern s8 salTimeOffset;
void hwSetTimeOffset(s8 arg0);
extern s8 salTimeOffset;
u8 hwGetTimeOffset(void);
extern s32 salMessageCallback;
void hwSetMesgCallback(s32 arg0);
void hwSetSRCType(s32 index, u8 entry);
void hwSetPolyPhaseFilter(s32 index, u8 entry);
void hwSetITDMode(s32 i, u8 mode);
s32 salDeactivateVoice(void *);
void hwOff(s32 arg0);
void hwTransAddr(void);
void hwFrameDone(void);
extern u32 dspHRTFOn;
void hwDisableHRTF(void);
s32 hwGetVirtualSampleID(s32 arg0);
void aramRemoveData(s32 arg0, s32 arg1);
extern volatile u32 salDspIsDone;
extern volatile u32 salDspInitIsDone;
extern void (*userCallback)(void);
extern volatile u32 salLogicIsWaiting;
extern volatile u32 salLogicActive;
void AIInitDMA(uaddr addr, u32 length);
void AIRegisterDMACallback(void (*)(void));
void salCallback(void);
void dspInitCallback(void);
s32 get_offset_58__6TLobbyFi(s32 arg0);
s32 get_field_34__6TLobbyFPv(int);
void TLobby__sub_803BFE58(u8 *arg0);
s32 get_field30__6TLobbyFPv(int);
void dispatch_field4_event__6TLobbyFPv(u8 *arg0);
s32 get_field_2c__6TLobbyFPv(int);
void send_with_offset4_alt__6TLobbyFPv(u8 *arg0);
s32 get_field_28__6TLobbyFPv(int);
void notify_client__6TLobbyFPv(u8 *arg0);
s32 get_slot__6TLobbyFPv(int);
void TLobby__sub_803BFEE8(u8 *arg0);
s32 TLobby__sub_803C3ABC(int);
void send_packet_by_id__6TLobbyFPv(u8 *arg0);
s32 TLobby__sub_803C3AC4(int);
void notify_field_4_alt__6TLobbyFPv(u8 *arg0);
s32 TLobby__sub_803C3ACC(int);
void send_packet_by_id_2__6TLobbyFPv(u8 *arg0);
s32 TLobby__sub_803C3B38(const AdxbDecoder *decoder);
void send_with_offset4__6TLobbyFPv(u8 *arg0);
s32 TLobby__sub_803C3B44(int);
void notify_field_4__6TLobbyFPv(u8 *arg0);
s32 get_field_a8__6TLobbyFPv(int);
void audio_stream_get_format(u8 *arg0);
void set_field_44__6TLobbyFPvi(u8 *arg0, s32 arg1);
void set_field_40__6TLobbyFPvi(u8 *arg0, s32 arg1);
void set_field_3c__6TLobbyFPvi(u8 *arg0, s32 arg1);
void audio_stream_set_notify_callback(u8 *arg0, s32 arg1, s32 arg2);
void set_count__6TLobbyFPvi(u8 *arg0, s32 arg1);
s32 audio_stream_get_output_samples(u8 *lobby);
s32 TLobby__sub_803C39CC(int);
void reset_flag__6TLobbyFPv(u8 *arg0);
void audio_stream_start(u8 *lobby);
s32 TLobby__sub_803C1A00(int);
void set_network_result__6TLobbyFPvi(u8 *arg0, s32 arg1);
s32 TLobby__sub_803C1A24(int);
void set_param_and_notify__6TLobbyFPvi(u8 *arg0, s32 arg1);
void clear_record__6TLobbyFPv(void *);
void release_ref__6TLobbyFv(void);
void init_once__6TLobbyFv(void);
void TLobby__sub_803C07F4(u8 *arg0);
extern RecoveredGlobal_803C0B08_lbl_80570AC0 lbl_80570AC0;
void TLobby__sub_803C0AD8(void);
void TLobby__sub_803C406C(void);
extern RecoveredGlobal_803C0B08_lbl_80570AC0 lbl_80570AC0;
void TLobby__sub_803C0B08(void);
s32 sub_803C0BE8(void *);
s32 TLobby__sub_803C0F98(void *);
s32 TLobby__sub_803C133C(void *);
void decode_adxb_pcm_stream(u8 *lobby);
extern SoundStudioMixView dspStudio[];
void hwSetAUXProcessingCallbacks(u8 studio, SND_AUX_CALLBACK auxA, void *userA, SND_AUX_CALLBACK auxB, void *userB);
u8 inpTranslateExCtrl(u8 arg0);
s32 OSDisableInterrupts(void);
void hwIRQEnterCritical(void);
s32 OSRestoreInterrupts(s32 level);
extern volatile s32 oldState;
extern volatile u16 hwIrqLevel;
void hwEnableIrq(void);
s32 ReverbHICreate(SoundReverb *self, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f);
void sndAuxCallbackPrepareReverbHI(Obj_803BE860 *self);
s32 OSEnableInterrupts(void);
void hwIRQLeaveCritical(void);
s32 OSDisableInterrupts(void);
void hwInitIrq(void);
extern u8 salAIBufferIndex;
extern Rec_803BE528 *salAIBufferBase;
Rec_803BE528 *salAiGetDest(void);
s32 OSDisableInterrupts(void);
void hwDisableIrq(void);
struct ChannelDefaults_803BADF8 { u8 pbRange; };
struct SynthVoice_803BADF8 {
    u8 pad0[0xF4];
    u32 id;
    u8 padF8[0x121 - 0xF8];
    u8 midi;
    u8 midiSet;
    u8 pad123[0x1D6 - 0x123];
    u8 pbLowerKeyRange;
    u8 pbUpperKeyRange;
    u8 pad1D8[0x214 - 0x1D8];
    u32 midiDirtyFlags;
    u8 pad218[0x404 - 0x218];
};
extern SynthVoice_803BADF8 *synthVoice;
void synthKeyStateUpdate(SynthVoice_803BADF8 *svoice);
void inpFXCopyCtrl(u8 ctrl, SynthVoice_803BADF8 *dvoice, SynthVoice_803BADF8 *svoice);
#define lbl_8056E098 ((u8 (*)[16])inpChannelDefaults)
#define lbl_8056E118 ((u8 *)inpFXChannelDefaults)
u8 *inpGetChannelDefaults(u8 a, u8 b);
struct Ent_803BC490 { u8 pad[0x22]; u8 f22; u8 pad23; };
extern CTRL_DEST inpAuxB[8][4];
extern CTRL_DEST inpAuxA[8][4];
extern u32 lbl_804F7120[];
extern u32 lbl_804F7130[];
void inpSetGlobalMIDIDirtyFlag(u8 a, u8 b, u32 v);
bool hwIsActive(s32 i);
u16 hwGetSampleID(s32 i);
void hwSetStreamLoopPS(s32 i, u8 v);
extern u32 lbl_805D4630;
u16 sndRand(void);
u8 hwGetSampleType(s32 i);
void hwSetPriority(s32 i, s32 v);
void hwSetVirtualSampleLoopBuffer(s32 i, s32 a, s32 b);
u8 hwGetVirtualSampleState(s32 i);
extern s8 salTimeOffset;
void hwKeyOff(s32 i);
void salActivateStudio(u8 i, s32 a, s32 b);
void hwActivateStudio(u8 i, s32 a, s32 b);
uaddr hwGetStreamPlayBuffer(u8 i);
void hwSyncSampleMem(void);
void aramInit(u32 length);
u32 ARGetSize(void);
void InitStreamBuffers(void);
void hwInitSampleMem(void *self, void *p);
void aramFreeStreamBuffer(u8 i);
void hwExitStream(u8 i);
void salDeactivateStudio(u8 i);
void hwDeactivateStudio(u8 i);
bool hwVoiceInStartup(s32 i);
u8 hwInitStream(u32 size);
u32 ARGetBaseAddress(void);
u32 aramGetZeroBuffer(void);
extern AramQueues_803BDCD0 lbl_8056E158;
void aramSyncTransferQueue(void);
u32 aramGetStreamBufferAddress(u8 i, u32 *out);
void AIStartDMA(void);
void salStartAi(void);
extern s8 salTimeOffset; void salActivateVoice(Slot_803BD138 *s, s32 x);
void hwStart(s32 i, s32 x);
extern SoundStudioMixView dspStudio[];
s32 salAddStudioInput(SoundStudioMixView *stp, SND_STUDIO_INPUT *desc);
void hwAddInput(u8 studio, SND_STUDIO_INPUT *in_desc);
extern SoundStudioMixView dspStudio[];
s32 salRemoveStudioInput(SoundStudioMixView *stp, SND_STUDIO_INPUT *desc);
void hwRemoveInput(u8 studio, SND_STUDIO_INPUT *in_desc);
void inpResetChannelDefaults(u8 arg0, u8 arg1);
void inpSetMidiLastNote(u8 arg0, u8 arg1, u8 arg2);
u8 inpGetMidiLastNote(u8 midi, u8 midiSet);
u16 inpGetVolume(SYNTH_VOICE *svoice);
u16 inpGetPanning(SYNTH_VOICE *svoice);
u16 inpGetSurPanning(SYNTH_VOICE *svoice);
u16 inpGetPitchBend(SYNTH_VOICE *svoice);
u16 inpGetDoppler(SYNTH_VOICE *svoice);
u16 inpGetModulation(SYNTH_VOICE *svoice);
u16 inpGetPedal(SYNTH_VOICE *svoice);
u16 inpGetPreAuxA(SYNTH_VOICE *svoice);
u16 inpGetReverb(SYNTH_VOICE *svoice);
u16 inpGetPreAuxB(SYNTH_VOICE *svoice);
u16 inpGetPostAuxB(SYNTH_VOICE *svoice);
u16 inpGetTremolo(SYNTH_VOICE *svoice);
extern s16 lbl_804F7168[];
s16 sndSin(s32 angle);
u32 synthGetTicksPerSecond(void *);
void sndConvertTicks(u32 *ticks, saddr seqId);
extern s8 salTimeOffset;
void hwBreak(s32 i);
extern s8 salTimeOffset;
void hwSetPitch(s32 i, u16 v);
s32 PPCSync();
s32 salBuildCommandList(void *, int);
extern u16 dspCmdFirstSize;
extern u16 *dspCmdList;
void salCtrlDsp(saddr dest);
extern volatile u32 salLastTick;
u32 salGetStartDelay(void);
typedef struct SND_HOOKS {
    void *(*malloc)(u32 addr);
    void (*free)(void *addr);
} SND_HOOKS;
extern SND_HOOKS salHooks;
f32* salMalloc(s32 bytes);
void salFree(saddr arg0);
u8 inpTranslateExCtrl(u8 arg0);
void inpAddCtrl(Obj_803BB8F0 *ch, u8 arg1, s32 arg2, u8 x, u32 arg4);
u8 inpTranslateExCtrl(u8 arg0);
u16 inpGetMidiCtrl(u8 arg0, u8 channel, u8 set);
u16 inpGetExCtrl(Obj_803BC7E4 *arg0, u8 arg1);
u8 inpTranslateExCtrl(u8 arg0);
void inpSetExCtrl(Obj_803BC884 *svoice, u8 arg1, s16 arg2);
u32 hwGetPos(s32 arg0);
void DCStoreRange(void *addr, u32 nBytes);
u32 aramGetStreamBufferAddress(u8 i, u32 *out);
void hwFlushStream(u8 *base, u32 offset, u32 len, u8 i, void *cb, void *arg);
void hwSaveSample(Hdr_803BD8A8 **header, uaddr *data);
void aramRemoveData(s32 arg0, s32 arg1);
void hwRemoveSample(Hdr_803BD93C *arg0, u32 arg1);
void hwInitIrq(void);
void hwEnableIrq(void);
void salStartAi(void);
u32 salInitAi(void (*callback)(void), u32 unk, u32 *outFreq);
u32 salInitDspCtrl(u8 numVoices, u8 numStudios, bool defaultStudioDPL2);
u32 salInitDsp(u32 flags);
void snd_handle_irq(void);
extern s32 salMessageCallback;
extern u8 salAuxFrame;
extern u8 salFrame;
extern u8 salNumVoices;
extern u8 sndActive;
void seqHandle(s32);
void synthHandle(s32);
void streamHandle(void);
void streamCorrectLoops(void);
void vsSampleUpdates(void);
void salHandleAuxProcessing(void);
void s3dHandle(void);
struct Slot_803BCAA0 { u8 pad0[0x24]; u32 changed[5]; u8 pad38[0xF4 - 0x38]; };
s32 hwInit(uaddr frq, s32 numVoices, s32 numStudios, u32 flags);
void DCFlushRange(void *addr, u32 nBytes);
s32 aramStoreData(u8 *src, u32 size);
u8 aramAllocateStreamBuffer(u32 len);
void hwSetSRCType(s32 index, u8 entry);
void hwSetPolyPhaseFilter(s32 index, u8 entry);
void hwSetITDMode(s32 i, u8 mode);
extern s8 salTimeOffset;
void hwInitSamplePlayback(s32 n, s16 smpID, Blk_803BCD1C *newsmp, u32 set_defadsr, s32 prio, s32 callbackUserValue, u32 setSRC, u8 itdMode);
u16 adsrConvertTimeCents(s32);
extern u8 dspScale2IndexTab[];
void hwSetADSR(s32 n, void *arg1, u8 mode);
s32 OSDisableInterrupts(void);
s32 OSRestoreInterrupts(s32 level);
s32 ARQPostRequest(Req_803BDAE4 *, s32, s32, s32, u8 *, u32, u32, void *);
void aramQueueCallback(uaddr ptr);
extern AramQueues_803BDCD0 lbl_8056E158;
extern Obj_803BDCB8 lbl_8056E3DC;
void aramUploadData(u8 *src, u32 dst, u32 len, s32 dir, void *cb, void *arg);
void DoCrossTalk(void *, void *, f32, f32);
void HandleReverb(void *, void *, int);
void ReverbHICallback(void *sptr, void *arg1, void *arg2, S_803BF408 *rv);
extern SoundStudioMixView dspStudio[];
void salCalcVolume(u32 p, SoundMixCurveOutput *out, s32 x, s32 pan, bool f7, bool f8, f32 a, f32 b, f32 c);
void hwSetVolume(s32 idx, u32 p, u32 x, s32 surroundPan, f32 a, f32 b, f32 c);
void do_src1(void *);
void do_src2(void *);
extern u32 synthInfo[];
extern const f32 lbl_805E0C48;
u32 hwFrq2Pitch(u32 frq);
void sndSetHooks(SND_HOOKS *hooks);
s16 varGet(SYNTH_VOICE *, u32, u32);
u16 inpGetMidiCtrl(u8 arg0, u8 channel, u8 set);
extern u64 synthRealTime;
u16 _GetInputValue(SYNTH_VOICE *svoice, CTRL_DEST *inp, u8 midi, u8 midiSet);
void inpSetMidiCtrl(u8 ctrl, u8 channel, u8 set, u8 value);
void inpSetMidiCtrl14(u8 ctrl, u8 channel, u8 set, u16 value);
void *sndBSearch(void *key, void *base, s32 num, s32 len, s32 (*cmp)(void *, void *));
f32 salNormalizeVector(SND_FVECTOR *vec);
}

extern "C" {

void sndConvertMs(s32 *time);
u32 sndConvert2Ms(u32 time);
void salApplyMatrix(const SND_FMATRIX *mat, const SND_FVECTOR *in, SND_FVECTOR *out);
LAYOUT_ASSERT(RecoveredGlobal_803BD5C4_lbl_805663D8_size, sizeof(RecoveredGlobal_803BD5C4_lbl_805663D8) == 0x6E0);
extern "C" {
f32 powf(f32, f32);
}

typedef struct ChorusSrcInfo_803BFBF0 {
    s32 *dest;
    s32 *smpBase;
    s32 *old;
    u32 posLo;
    u32 posHi;
    u32 pitchLo;
    u32 pitchHi;
    u32 trigger;
    u32 target;
} ChorusSrcInfo_803BFBF0;

typedef struct ChorusWork_803BFBF0 {
    s32 *lastLeft[3];
    s32 *lastRight[3];
    s32 *lastSur[3];
    u8 currentLast;
    s32 oldLeft[4];
    s32 oldRight[4];
    s32 oldSur[4];
    u32 currentPosLo;
    u32 currentPosHi;
    s32 pitchOffset;
    u32 pitchOffsetPeriodCount;
    u32 pitchOffsetPeriod;
    ChorusSrcInfo_803BFBF0 src;
} ChorusWork_803BFBF0;

typedef struct AuxChorus_803BFBF0 {
    ChorusWork_803BFBF0 work;
    u32 baseDelay;
    u32 variation;
    u32 period;
} AuxChorus_803BFBF0;

}

extern "C" {
void salApplyMatrix(const SND_FMATRIX *mat, const SND_FVECTOR *in, SND_FVECTOR *out);
f32 salNormalizeVector(SND_FVECTOR *vec);
void inpSetGlobalMIDIDirtyFlag(u8 a, u8 b, u32 v);
void inpSetMidiCtrl(u8 ctrl, u8 channel, u8 set, u8 value);
void inpSetMidiCtrl14(u8 ctrl, u8 channel, u8 set, u16 value);
void inpResetMidiCtrl(u8 midi, u8 midiSet, u32 arg2);
u16 inpGetMidiCtrl(u8 ctrl, u8 channel, u8 set);
u8 *inpGetChannelDefaults(u8 a, u8 b);
void inpResetChannelDefaults(u8 arg0, u8 arg1);
void inpAddCtrl(Obj_803BB8F0 *ch, u8 arg1, s32 arg2, u8 x, u32 arg4);
void inpFXCopyCtrl(u8 ctrl, SynthVoice_803BADF8 *dvoice, SynthVoice_803BADF8 *svoice);
void inpSetMidiLastNote(u8 arg0, u8 arg1, u8 arg2);
u8 inpGetMidiLastNote(u8 midi, u8 midiSet);
u16 _GetInputValue(SYNTH_VOICE *svoice, CTRL_DEST *inp, u8 midi, u8 midiSet);
u16 inpGetVolume(SYNTH_VOICE *svoice);
u16 inpGetPanning(SYNTH_VOICE *svoice);
u16 inpGetSurPanning(SYNTH_VOICE *svoice);
u16 inpGetPitchBend(SYNTH_VOICE *svoice);
u16 inpGetDoppler(SYNTH_VOICE *svoice);
u16 inpGetModulation(SYNTH_VOICE *svoice);
u16 inpGetPedal(SYNTH_VOICE *svoice);
u16 inpGetPreAuxA(SYNTH_VOICE *svoice);
u16 inpGetReverb(SYNTH_VOICE *svoice);
u16 inpGetPreAuxB(SYNTH_VOICE *svoice);
u16 inpGetPostAuxB(SYNTH_VOICE *svoice);
u16 inpGetTremolo(SYNTH_VOICE *svoice);
u16 inpGetAuxA(u8 studio, u8 index, u8 midi, u8 midiSet);
u16 inpGetAuxB(u8 studio, u8 index, u8 midi, u8 midiSet);
void inpInit(SYNTH_VOICE *svoice);
u8 inpTranslateExCtrl(u8 arg0);
u16 inpGetExCtrl(Obj_803BC7E4 *arg0, u8 arg1);
void inpSetExCtrl(Obj_803BC884 *svoice, u8 arg1, s16 arg2);
u16 sndRand(void);
s16 sndSin(s32 angle);
void *sndBSearch(void *key, void *base, s32 num, s32 len, s32 (*cmp)(void *, void *));
void sndConvertMs(s32 *time);
void sndConvertTicks(u32 *ticks, saddr seqId);
u32 sndConvert2Ms(u32 time);
void snd_handle_irq(void);
s32 hwInit(uaddr frq, s32 numVoices, s32 numStudios, u32 flags);
void hwSetTimeOffset(s8 arg0);
u8 hwGetTimeOffset(void);
bool hwIsActive(s32 i);
void hwSetMesgCallback(s32 arg0);
void hwSetPriority(s32 i, s32 v);
void hwInitSamplePlayback(s32 n, s16 smpID, Blk_803BCD1C *newsmp, u32 set_defadsr, s32 prio, s32 callbackUserValue, u32 setSRC, u8 itdMode);
void hwBreak(s32 i);
void hwSetADSR(s32 n, void *arg1, u8 mode);
void hwSetVirtualSampleLoopBuffer(s32 i, s32 a, s32 b);
u8 hwGetVirtualSampleState(s32 i);
u8 hwGetSampleType(s32 i);
u16 hwGetSampleID(s32 i);
void hwSetStreamLoopPS(s32 i, u8 v);
void hwStart(s32 i, s32 x);
void hwKeyOff(s32 i);
void hwSetPitch(s32 i, u16 v);
void hwSetSRCType(s32 index, u8 entry);
void hwSetPolyPhaseFilter(s32 index, u8 entry);
void hwSetITDMode(s32 i, u8 mode);
void hwSetVolume(s32 voice, u32 volumeCurve, u32 pan, s32 surroundPan, f32 direct, f32 auxiliaryA, f32 auxiliaryB);
void hwOff(s32 arg0);
void hwSetAUXProcessingCallbacks(u8 studio, SND_AUX_CALLBACK auxA, void *userA, SND_AUX_CALLBACK auxB, void *userB);
void hwActivateStudio(u8 i, s32 a, s32 b);
void hwDeactivateStudio(u8 i);
void hwAddInput(u8 studio, SND_STUDIO_INPUT *in_desc);
void hwRemoveInput(u8 studio, SND_STUDIO_INPUT *in_desc);
u32 hwGetPos(s32 arg0);
void hwFlushStream(u8 *base, u32 offset, u32 len, u8 i, void *cb, void *arg);
u8 hwInitStream(u32 size);
void hwExitStream(u8 i);
uaddr hwGetStreamPlayBuffer(u8 i);
void hwTransAddr(void);
u32 hwFrq2Pitch(u32 frq);
void hwInitSampleMem(void *self, void *p);
void hwSaveSample(Hdr_803BD8A8 **header, uaddr *data);
void hwRemoveSample(Hdr_803BD93C *arg0, u32 arg1);
void hwSyncSampleMem(void);
void hwFrameDone(void);
void hwDisableHRTF(void);
s32 hwGetVirtualSampleID(s32 arg0);
bool hwVoiceInStartup(s32 i);
void aramUploadData(u8 *src, u32 dst, u32 len, s32 dir, void *cb, void *arg);
void aramSyncTransferQueue(void);
u32 aramGetZeroBuffer(void);
s32 aramStoreData(u8 *src, u32 size);
void aramRemoveData(s32 arg0, s32 arg1);
u8 aramAllocateStreamBuffer(u32 len);
u32 aramGetStreamBufferAddress(u8 i, u32 *out);
void salCallback(void);
void aramFreeStreamBuffer(u8 id);
void dspInitCallback(void);
void dspResumeCallback(void);
u32 salInitAi(void (*callback)(void), u32 unk, u32 *outFreq);
void salStartAi(void);
Rec_803BE528 *salAiGetDest(void);
void salCtrlDsp(saddr dest);
u32 salGetStartDelay(void);
void hwInitIrq(void);
void hwEnableIrq(void);
void hwDisableIrq(void);
void hwIRQEnterCritical(void);
void hwIRQLeaveCritical(void);
f32* salMalloc(s32 bytes);
void salFree(saddr arg0);
void sndAuxCallbackPrepareReverbHI(Obj_803BE860 *self);
s32 ReverbHICreate(SoundReverb * rv, float coloration, float time, float mix, float damping, float preDelay, float crossTalk);
void ReverbHICallback(void *sptr, void *arg1, void *arg2, S_803BF408 *rv);
u32 sndAuxCallbackPrepareChorus(AuxChorus_803BFBF0 *chorus);
}

#endif
