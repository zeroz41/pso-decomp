#include "musyx/runtime/musyx_runtime_a.h"

#define ARR_GET_803A3D8C(arr, offset) ((void *)(offset + (u32)arr))
#define SEQ_CUR (*(SEQ_INSTANCE_803A49C8 **)&lbl_805D7360)
#define SEQ_FREE_LIST ((SEQ_INSTANCE_803A49C8 *)lbl_805D7378)
#define SEQ_RUN_LIST ((SEQ_INSTANCE_803A49C8 *)lbl_805D737C)
#define SEQ_RUN_L (*(SEQ_INSTANCE_803A49C8 **)&lbl_805D737C)
#define ARR_GET_803A5A78(arr, offset) ((void *)(offset + (u32)arr))
#define ARR_GET_803A6364(arr, offset) ((void *)(offset + (u32)arr))
#define TBL ((Ent_803ACEC4 *)((u8 *)t + 0x4E00))
#define macTimeQueueRoot ((SYNTH_VOICE_803B19AC *)lbl_805D7420)
#define macActiveMacroRoot ((SYNTH_VOICE_803B19AC *)lbl_805D741C)
#define macRealTime lbl_805D7428
#define FLAGS (*(u64 *)&o->fh)
#define HEAD (*(Voice_803B2128 **)&lbl_805D741C)
#define synthVoice ((SYNTH_VOICE_803B2438 *)synthVoice)
#define vidCurrentId (*(u32 *)&lbl_805D7438)
#define vidRoot (*(VID_LIST_SV **)&lbl_805D743C)
#define vidFree (*(VID_LIST_SV **)&lbl_805D7440)
extern "C" {

Rec_803B59E4 lbl_805663D8[8];

u32 lbl_805D7458;
u16 *lbl_805D745C;
u16 *lbl_805D7460;
u16 lbl_805D7464;
u16 *lbl_805D7468;
u16 *lbl_805D746C;
u16 *lbl_805D7470;
u16 lbl_805D7474;
u16 *lbl_805D7478;
u32 lbl_805D747C;
s32 lbl_805D7480;
s32 *lbl_805D7484;
void *lbl_805D7488;
DSPvoice_803B5500 *lbl_805D748C;
s32 (*salMessageCallback)(s32, s32);

#define dspStudio lbl_805663D8
#define salNumVoices lbl_805D74C5
#define salMaxStudioNum lbl_805D74C4
#define dspARAMZeroBuffer lbl_805D7458
#define dspCmdList lbl_805D7478
#define dspSurround lbl_805D7484
#define dspVoice lbl_805D748C
#define dspITDBuffer lbl_805D7488
#define dspHrtfHistoryBuffer (*(void **)&lbl_805D7480)

#pragma push
#pragma opt_common_subs on
#pragma bool off

u32 salInitDspCtrl(u8 numVoices, u8 numStudios, u32 defaultStudioDPL2) {
    u32 i;
    u32 j;
    u32 itdPtr;

    salNumVoices = numVoices;
    salMaxStudioNum = numStudios;

    dspARAMZeroBuffer = aramGetZeroBuffer();
    if ((dspCmdList = (u16 *)salMalloc(1024 * sizeof(u16)))) {
        if ((dspSurround = (s32 *)salMalloc(160 * sizeof(s32)))) {
            memset(dspSurround, 0, 160 * sizeof(s32));
            DCFlushRange(dspSurround, 160 * sizeof(long));
            if ((dspVoice = (DSPvoice_803B5500 *)salMalloc(salNumVoices * sizeof(DSPvoice_803B5500)))) {
                if ((dspITDBuffer = salMalloc(salNumVoices * 64))) {
                    DCInvalidateRange(dspITDBuffer, salNumVoices * 64);
                    itdPtr = (u32)dspITDBuffer;
                    for (i = 0; i < salNumVoices; ++i) {
                        dspVoice[i].state = 0;
                        dspVoice[i].postBreak = 0;
                        dspVoice[i].startupBreak = 0;
                        dspVoice[i].lastUpdatePitch = 0xff;
                        dspVoice[i].lastUpdateVol = 0xff;
                        dspVoice[i].lastUpdateVolA = 0xff;
                        dspVoice[i].lastUpdateVolB = 0xff;
                        dspVoice[i].pb = (_PB_803B5500 *)salMalloc(sizeof(_PB_803B5500));
                        memset(dspVoice[i].pb, 0, sizeof(_PB_803B5500));
                        dspVoice[i].patchData = salMalloc(0x80);
                        dspVoice[i].pb->currHi = ((u32)dspVoice[i].pb >> 16);
                        dspVoice[i].pb->currLo = (u16)(u32)dspVoice[i].pb;
                        dspVoice[i].pb->updateDataHi = ((u32)dspVoice[i].patchData >> 16);
                        dspVoice[i].pb->updateDataLo = ((u16)(u32)dspVoice[i].patchData);
                        dspVoice[i].pb->itdBufferHi = ((u32)itdPtr >> 16);
                        dspVoice[i].pb->itdBufferLo = ((u16)itdPtr);
                        dspVoice[i].itdBuffer = (void *)itdPtr;
                        itdPtr += 0x40;
                        dspVoice[i].virtualSampleID = 0xFFFFFFFF;
                        DCStoreRangeNoSync(dspVoice[i].pb, sizeof(_PB_803B5500));
                        for (j = 0; j < 5; ++j) {
                            dspVoice[i].changed[j] = 0;
                        }
                    }

                    for (i = 0; i < salMaxStudioNum; ++i) {
                        dspStudio[i].state = 0;
                        if (!(dspStudio[i].spb = salMalloc(0x36))) {
                            return 0;
                        }

                        if (!(dspStudio[i].main[0] = (s32 *)salMalloc(0x3c00))) {
                            return 0;
                        }

                        memset(dspStudio[i].main[0], 0, 0x3c00);
                        DCFlushRangeNoSync(dspStudio[i].main[0], 0x3c00);
                        dspStudio[i].main[1] = dspStudio[i].main[0] + 0x1e0;
                        dspStudio[i].auxA[0] = dspStudio[i].main[1] + 0x1e0;
                        dspStudio[i].auxA[1] = dspStudio[i].auxA[0] + 0x1e0;
                        dspStudio[i].auxA[2] = dspStudio[i].auxA[1] + 0x1e0;
                        dspStudio[i].auxB[0] = dspStudio[i].auxA[2] + 0x1e0;
                        dspStudio[i].auxB[1] = dspStudio[i].auxB[0] + 0x1e0;
                        dspStudio[i].auxB[2] = dspStudio[i].auxB[1] + 0x1e0;
                        memset(dspStudio[i].spb, 0, 0x36);
                        dspStudio[i].hostDPopSum.l = dspStudio[i].hostDPopSum.r = dspStudio[i].hostDPopSum.s = 0;
                        dspStudio[i].hostDPopSum.lA = dspStudio[i].hostDPopSum.rA = dspStudio[i].hostDPopSum.sA = 0;
                        dspStudio[i].hostDPopSum.lB = dspStudio[i].hostDPopSum.rB = dspStudio[i].hostDPopSum.sB = 0;
                        DCFlushRangeNoSync(dspStudio[i].spb, 0x36);
                    }
                    salActivateStudio(0, 1, defaultStudioDPL2 != 0 ? 1 : 0);
                    if (!(dspHrtfHistoryBuffer = salMalloc(0x100))) {
                        return 0;
                    }

                    salInitHRTFBuffer();
                    return 1;
                }
            }
        }
    }

    return 0;
}

#pragma pop
#undef dspStudio

void salInitHRTFBuffer(void) {
    memset((void *) (lbl_805D7480), (int) (0), (int) (0x100));
    DCFlushRangeNoSync((void *) (lbl_805D7480), (int) (0x100));
}

#define dspStudio lbl_805663D8
#pragma push
#pragma opt_common_subs on
#pragma bool off

void salActivateStudio(u8 studio, u32 isMaster, u32 type) {
    memset(dspStudio[studio].main[0], 0, 0x3c00);
    DCFlushRangeNoSync(dspStudio[studio].main[0], 0x3c00);
    memset(dspStudio[studio].spb, 0, 0x36);
    dspStudio[studio].hostDPopSum.l = dspStudio[studio].hostDPopSum.r =
        dspStudio[studio].hostDPopSum.s = 0;
    dspStudio[studio].hostDPopSum.lA = dspStudio[studio].hostDPopSum.rA =
        dspStudio[studio].hostDPopSum.sA = 0;
    dspStudio[studio].hostDPopSum.lB = dspStudio[studio].hostDPopSum.rB =
        dspStudio[studio].hostDPopSum.sB = 0;
    DCFlushRangeNoSync(dspStudio[studio].spb, 0x36);
    memset(dspStudio[studio].auxA[0], 0, 0x780);
    DCFlushRangeNoSync(dspStudio[studio].auxA[0], 0x780);
    memset(dspStudio[studio].auxB[0], 0, 0x780);
    DCFlushRangeNoSync(dspStudio[studio].auxB[0], 0x780);
    dspStudio[studio].voiceRoot = NULL;
    dspStudio[studio].alienVoiceRoot = NULL;
    dspStudio[studio].state = 1;
    dspStudio[studio].isMaster = isMaster;
    dspStudio[studio].numInputs = 0;
    dspStudio[studio].type = type;
    dspStudio[studio].auxAHandler = dspStudio[studio].auxBHandler = NULL;
}

#pragma pop
#undef dspStudio

void salDeactivateStudio(u8 i) {
    lbl_805663D8[i].f50 = 0;
}

#pragma push
#pragma opt_common_subs on
#pragma bool off

u32 salCheckVolErrorAndResetDelta(u16 *dsp_vol, u16 *dsp_delta, u16 *last_vol, u16 targetVol,
                         u16 *resetFlags, u16 resetMask) {
    s16 d;
    s16 x;

    if (targetVol != *last_vol) {
        d = (s16)targetVol - (s16)*last_vol;
        if ((s16)d >= 32 && (s16)d < 160) {
            x = (s16)d >> 5;
            if ((s16)x < 5) {
                resetFlags[x] |= resetMask;
            }

            *dsp_delta = 1;
            *last_vol += (x << 5);
            return 1;
        }

        if (-32 >= (s16)d && -160 < (s16)d) {
            x = -(s16)d >> 5;
            if (x < 5) {
                resetFlags[x] |= resetMask;
            }
            *dsp_delta = 0xFFFF;
            *last_vol -= x << 5;
            return 1;
        }

        if (targetVol == 0 && (s16)d > -32) {
            *dsp_vol = *last_vol = 0;
        }
    }

    *dsp_delta = 0;
    return 0;
}

#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)

static inline void AddDpop_803B5AF8(s32 *sum, s16 delta) {
    *sum += (int)delta;
    *sum = (*sum > 0x7fffff) ? 0x7fffff : (*sum < -0x7fffff ? -0x7fffff : *sum);
}

void HandleDepopVoice(DSPstudioinfo_803B5AF8 *stp, DSPvoice_803B5AF8 *dsp_vptr) {
    _PB_803B5AF8 *pb;
    dsp_vptr->postBreak = 0;
    dsp_vptr->pb->state = 0;
    pb = dsp_vptr->pb;

    AddDpop_803B5AF8(&stp->hostDPopSum.l, pb->dpop.aL);
    AddDpop_803B5AF8(&stp->hostDPopSum.r, pb->dpop.aR);

    if ((pb->mixerCtrl & 0x04) != 0) {
        AddDpop_803B5AF8(&stp->hostDPopSum.s, pb->dpop.aS);
    }

    if ((pb->mixerCtrl & 0x01) != 0) {
        AddDpop_803B5AF8(&stp->hostDPopSum.lA, pb->dpop.aAuxAL);
        AddDpop_803B5AF8(&stp->hostDPopSum.rA, pb->dpop.aAuxAR);

        if ((pb->mixerCtrl & 0x14) != 0) {
            AddDpop_803B5AF8(&stp->hostDPopSum.sA, pb->dpop.aAuxAS);
        }
    }

    if ((pb->mixerCtrl & 0x12) != 0) {
        AddDpop_803B5AF8(&stp->hostDPopSum.lB, pb->dpop.aAuxBL);
        AddDpop_803B5AF8(&stp->hostDPopSum.rB, pb->dpop.aAuxBR);

        if ((pb->mixerCtrl & 0x4) != 0) {
            AddDpop_803B5AF8(&stp->hostDPopSum.sB, pb->dpop.aAuxBS);
        }
    }
}

#pragma pop

void SortVoices(Ent_803B5DB0 **v, s32 left, s32 right) {
    Ent_803B5DB0 **pm;
    s32 i;
    s32 last;
    Ent_803B5DB0 *t;
    Ent_803B5DB0 *e;
    Ent_803B5DB0 **pl;
    Ent_803B5DB0 **pi;

    if (left >= right) {
        return;
    }
    pl = &v[left];
    pm = &v[(left + right) / 2];
    t = *pl;
    *pl = *pm;
    *pm = t;
    last = left;
    for (i = left + 1; i <= right; i++) {
        e = v[i];
        if (e->key < (*pl)->key) {
            last++;
            t = v[last];
            v[last] = e;
            v[i] = t;
        }
    }
    pm = &v[last];
    t = *pl;
    *pl = *pm;
    *pm = t;
    SortVoices(v, left, last - 1);
    SortVoices(v, last + 1, right);
}

#undef dspStudio
#define dspStudio ((DSPstudioinfo *)lbl_805663D8)
#define dspCmdLastLoad lbl_805D745C
#define dspCmdLastBase lbl_805D7460
#define dspCmdLastSize lbl_805D7464
#define dspCmdCurBase lbl_805D7468
#define dspCmdMaxPtr lbl_805D746C
#define dspCmdPtr lbl_805D7470
#define dspCmdFirstSize lbl_805D7474
#define dspHRTFOn lbl_805D747C
#define salAuxFrame lbl_805D74C6
#define salFrame lbl_805D74C7
#define dspMixerCycles lbl_8047C2B8
#define pbOffsets lbl_8047C2F8
#define dspSRCCycles lbl_804F6EE0
extern u16 *lbl_805D745C;
extern u16 *lbl_805D7460;
extern u16 lbl_805D7464;
extern u16 *lbl_805D7468;
extern u16 *lbl_805D746C;
extern u16 *lbl_805D7470;
extern u16 lbl_805D7474;
extern u32 lbl_805D747C;
extern u8 lbl_805D74C7;
u32 __OSBusClock : 0x800000F8;

const u16 lbl_8047C2B8[32] = {
    1470, 2940, 2940, 4410, 2230, 4460, 4460, 6690, 2470, 4940, 4940, 7410, 3735, 7470, 7470, 11205,
    2940, 3386, 2940, 3386, 2940, 3386, 2940, 3386, 4940, 5687, 4940, 5687, 4940, 5687, 4940, 5687,
};
const u16 lbl_8047C2F8[9] = {10, 12, 24, 14, 16, 26, 18, 20, 22};
u16 lbl_804F6EE0[3][3] = {
    {2990, 2990, 1115},
    {3300, 3300, 1115},
    {3700, 3700, 1115},
};

typedef struct SND_AUX_INFO {
  union SND_AUX_DATA {
    struct SND_AUX_BUFFERUPDATE {
      s32* left;
      s32* right;
      s32* surround;
    } bufferUpdate;
    struct SND_AUX_PARAMETERUPDATE {
      u16 para[4];
    } parameterUpdate;
  } data;
} SND_AUX_INFO;
typedef enum {
  SND_STUDIO_TYPE_STD = 0,
  SND_STUDIO_TYPE_DPL2,
  SND_STUDIO_TYPE_RESERVED1,
  SND_STUDIO_TYPE_RESERVED2
} SND_STUDIO_TYPE;
typedef void (*SND_AUX_CALLBACK)(u8 reason, SND_AUX_INFO* info, void* user);
typedef struct SND_STUDIO_INPUT {
  u8 vol;
  u8 volA;
  u8 volB;
  u8 srcStudio;
} SND_STUDIO_INPUT;
typedef struct DSPADPCMblock {
  signed short Y0;
  signed short Y1;
  unsigned char PS;
  unsigned char reserved;
} DSPADPCMblock;
typedef struct DSPADPCMplusInfo {
  unsigned short numCoef;
  unsigned char initialPS;
  unsigned char loopPS;
  signed short loopY0;
  signed short loopY1;
  signed short coefTab[8][2];
  DSPADPCMblock blk[1];
} DSPADPCMplusInfo;
typedef struct ADSR_VARS {
  u8 mode;
  u8 state;
  u32 cnt;
  s32 currentVolume;
  s32 currentIndex;
  s32 currentDelta;
  union data {
    struct _dls {
      u32 aTime;
      u32 dTime;
      u16 sLevel;
      u32 rTime;
      u16 cutOff;
      u8 aMode;
    } dls;
    struct _linear {
      u32 aTime;
      u32 dTime;
      u16 sLevel;
      u32 rTime;
    } linear;
  } data;
} ADSR_VARS;
typedef struct SAMPLE_INFO {
  u32 info;
  void* addr;
  void* extraData;
  u32 offset;
  u32 length;
  u32 loop;
  u32 loopLength;
  u8 compType;
} SAMPLE_INFO;
typedef struct _PBMIX {
  u16 vL;
  u16 vDeltaL;
  u16 vR;
  u16 vDeltaR;
  u16 vAuxAL;
  u16 vDeltaAuxAL;
  u16 vAuxAR;
  u16 vDeltaAuxAR;
  u16 vAuxBL;
  u16 vDeltaAuxBL;
  u16 vAuxBR;
  u16 vDeltaAuxBR;
  u16 vAuxBS;
  u16 vDeltaAuxBS;
  u16 vS;
  u16 vDeltaS;
  u16 vAuxAS;
  u16 vDeltaAuxAS;
} _PBMIX;
typedef struct _PBITD {
  u16 flag;
  u16 bufferHi;
  u16 bufferLo;
  u16 shiftL;
  u16 shiftR;
  u16 targetShiftL;
  u16 targetShiftR;
} _PBITD;
typedef struct _PBUPDATE {
  u16 updNum[5];
  u16 dataHi;
  u16 dataLo;
} _PBUPDATE;
typedef struct _PBDPOP {
  u16 aL;
  u16 aAuxAL;
  u16 aAuxBL;
  u16 aR;
  u16 aAuxAR;
  u16 aAuxBR;
  u16 aS;
  u16 aAuxAS;
  u16 aAuxBS;
} _PBDPOP;
typedef struct _PBVE {
  u16 currentVolume;
  u16 currentDelta;
} _PBVE;
typedef struct _PBFIR {
  u16 numCoefs;
  u16 coefsHi;
  u16 coefsLo;
} _PBFIR;
typedef struct _PBADDR {
  u16 loopFlag;
  u16 format;
  u16 loopAddressHi;
  u16 loopAddressLo;
  u16 endAddressHi;
  u16 endAddressLo;
  u16 currentAddressHi;
  u16 currentAddressLo;
} _PBADDR;
typedef struct _PBADPCM {
  u16 a[8][2];
  u16 gain;
  u16 pred_scale;
  u16 yn1;
  u16 yn2;
} _PBADPCM;
typedef struct _PBSRC {
  u16 ratioHi;
  u16 ratioLo;
  u16 currentAddressFrac;
  u16 last_samples[4];
} _PBSRC;
typedef struct _PBADPCMLOOP {
  u16 loop_pred_scale;
  u16 loop_yn1;
  u16 loop_yn2;
} _PBADPCMLOOP;
typedef struct _PB {
  u16 nextHi;
  u16 nextLo;
  u16 currHi;
  u16 currLo;
  u16 srcSelect;
  u16 coefSelect;
  u16 mixerCtrl;
  u16 state;
  u16 loopType;
  _PBMIX mix;
  _PBITD itd;
  _PBUPDATE update;
  _PBDPOP dpop;
  _PBVE ve;
  _PBFIR fir;
  _PBADDR addr;
  _PBADPCM adpcm;
  _PBSRC src;
  _PBADPCMLOOP adpcmLoop;
  u16 streamLoopCnt;
} _PB;
typedef struct VSampleInfo {
  void* loopBufferAddr;
  u32 loopBufferLength;
  u8 inLoopBuffer;
} VSampleInfo;
typedef struct _SPB {
  u16 dpopLHi;
  u16 dpopLLo;
  u16 dpopLDelta;
  u16 dpopRHi;
  u16 dpopRLo;
  u16 dpopRDelta;
  u16 dpopSHi;
  u16 dpopSLo;
  u16 dpopSDelta;
  u16 dpopALHi;
  u16 dpopALLo;
  u16 dpopALDelta;
  u16 dpopARHi;
  u16 dpopARLo;
  u16 dpopARDelta;
  u16 dpopASHi;
  u16 dpopASLo;
  u16 dpopASDelta;
  u16 dpopBLHi;
  u16 dpopBLLo;
  u16 dpopBLDelta;
  u16 dpopBRHi;
  u16 dpopBRLo;
  u16 dpopBRDelta;
  u16 dpopBSHi;
  u16 dpopBSLo;
  u16 dpopBSDelta;
} _SPB;
typedef struct DSPvoice {
  _PB* pb;
  void* patchData;
  void* itdBuffer;
  struct DSPvoice* next;
  struct DSPvoice* prev;
  struct DSPvoice* nextAlien;
  u32 mesgCallBackUserValue;
  u32 prio;
  u32 currentAddr;
  u32 changed[5];
  u32 pitch[5];
  u16 volL;
  u16 volR;
  u16 volS;
  u16 volLa;
  u16 volRa;
  u16 volSa;
  u16 volLb;
  u16 volRb;
  u16 volSb;
  u16 lastVolL;
  u16 lastVolR;
  u16 lastVolS;
  u16 lastVolLa;
  u16 lastVolRa;
  u16 lastVolSa;
  u16 lastVolLb;
  u16 lastVolRb;
  u16 lastVolSb;
  u16 smp_id;
  SAMPLE_INFO smp_info;
  VSampleInfo vSampleInfo;
  u8 streamLoopPS;
  ADSR_VARS adsr;
  u16 srcTypeSelect;
  u16 srcCoefSelect;
  u16 itdShiftL;
  u16 itdShiftR;
  u8 singleOffset;
  struct {
    u32 posHi;
    u32 posLo;
    u32 pitch;
  } playInfo;
  struct {
    u8 pitch;
    u8 vol;
    u8 volA;
    u8 volB;
  } lastUpdate;
  u32 virtualSampleID;
  u8 state;
  u8 postBreak;
  u8 startupBreak;
  u8 studio;
  u32 flags;
} DSPvoice;
typedef struct DSPhostDPop {
  s32 l;
  s32 r;
  s32 s;
  s32 lA;
  s32 rA;
  s32 sA;
  s32 lB;
  s32 rB;
  s32 sB;
} DSPhostDPop;
typedef struct DSPinput {
  u8 studio;
  u16 vol;
  u16 volA;
  u16 volB;
  SND_STUDIO_INPUT* desc;
} DSPinput;
typedef struct DSPstudioinfo {
  _SPB* spb;
  DSPhostDPop hostDPopSum;
  s32* main[2];
  s32* auxA[3];
  s32* auxB[3];
  DSPvoice* voiceRoot;
  DSPvoice* alienVoiceRoot;
  u8 state;
  u8 isMaster;
  u8 numInputs;
  SND_STUDIO_TYPE type;
  DSPinput in[7];
  SND_AUX_CALLBACK auxAHandler;
  SND_AUX_CALLBACK auxBHandler;
  void* auxAUser;
  void* auxBUser;
} DSPstudioinfo;
typedef struct SNDADPCMinfo {
  u16 numCoef;
  u8 initialPS;
  u8 loopPS;
  s16 loopY0;
  s16 loopY1;
  s16 coefTab[8][2];
} SNDADPCMinfo;

#pragma push
#pragma opt_common_subs on
#pragma bool off
#pragma dont_inline off
#pragma inline_depth(4)

static inline void sal_setup_dspvol(u16 *dsp_delta, u16 *last_vol, u16 vol) {
  *dsp_delta = ((s16)vol - (s16)*last_vol) / 160;
  *last_vol += (s16)*dsp_delta * 160;
}
static inline void sal_update_hostplayinfo(DSPvoice *dsp_vptr) {
  u32 old_lo;
  u32 pitch;
  if (dsp_vptr->smp_info.loopLength != 0) {
    return;
  }
  if (dsp_vptr->pb->srcSelect != 2) {
    pitch = dsp_vptr->playInfo.pitch << 5;
  } else {
    pitch = 0x200000;
  }
  old_lo = dsp_vptr->playInfo.posLo;
  dsp_vptr->playInfo.posLo += pitch * 0x10000;
  if (old_lo > dsp_vptr->playInfo.posLo) {
    dsp_vptr->playInfo.posHi += (pitch >> 16) + 1;
  } else {
    dsp_vptr->playInfo.posHi += (pitch >> 16);
  }
}
static inline void AddDpop(s32 *sum, s16 delta) {
  *sum += (int)delta;
  *sum = (*sum > 0x7fffff) ? 0x7fffff : (*sum < -0x7fffff ? -0x7fffff : *sum);
}
static inline void DoDepopFade(long *dspStart, s16 *dspDelta, long *hostSum) {
  if (*hostSum <= -160) {
    *dspDelta = (*hostSum <= -3200) ? 0x14 : (s16)(-*hostSum / 160);
  } else if (*hostSum >= 160) {
    *dspDelta = (*hostSum >= 3200) ? -0x14 : (s16)(-*hostSum / 160);
  } else {
    *dspDelta = 0;
  }
  *dspStart = *hostSum;
  *hostSum += *dspDelta * 160;
}

void salBuildCommandList(s16 *dest, u32 nsDelay) {
  static DSPvoice *voices[64];
  u16 size;
  u8 s;
  u8 mix_start;
  u8 st;
  u8 st1;
  u8 getAuxFrame;
  u16 rampResetOffsetFlags[5];
  DSPvoice *dsp_vptr;
  DSPvoice *next_dsp_vptr;
  u32 tmp_addr;
  u32 addr;
  u32 base;
  u32 in;
  u32 voiceNum;
  u32 cyclesUsed;
  u16 *pptr;
  u16 *pend;
  u16 adsr_start;
  u16 adsr_delta;
  u16 old_adsr_delta;
  s32 current_delta;
  s32 v;
  _PB *pb;
  _PB *last_pb;
  u32 VoiceDone;
  u32 needsDelta;
  u32 newVoice;
  _SPB *spb;
  DSPstudioinfo *stp;
  u32 procVoiceFlag;
  u32 offset;
  u32 endAddr;
  u32 loopAddr;
  u32 zeroAddr;
  dspCmdCurBase = dspCmdPtr = dspCmdList;
  dspCmdMaxPtr = dspCmdPtr + 0xC0;
  dspCmdLastLoad = 0;
  if (nsDelay < 200) {
    cyclesUsed = 10430;
  } else {
    cyclesUsed = ((nsDelay - 200) * ((__OSBusClock / 400) / 5000)) + 10430;
  }
  if (dspHRTFOn != 0) {
    cyclesUsed += 45000;
  }
  rampResetOffsetFlags[0] = 0;
  for (st = 0; st < salMaxStudioNum; st++) {
    if (dspStudio[st].state == 1) {
      stp = &dspStudio[st];
      for (dsp_vptr = stp->voiceRoot; dsp_vptr; dsp_vptr = next_dsp_vptr) {
        next_dsp_vptr = dsp_vptr->next;
        if ((dsp_vptr->postBreak != 0) || ((dsp_vptr->changed[0] & 0x20) != 0)) {
          HandleDepopVoice((DSPstudioinfo_803B5AF8 *)stp, (DSPvoice_803B5AF8 *)dsp_vptr);
          if (dsp_vptr->virtualSampleID != -1) {
            salSynthSendMessage((u8 *)dsp_vptr, 3);
          }
          if ((dsp_vptr->state != 1) || (dsp_vptr->startupBreak != 0)) {
            salDeactivateVoice((Ent_803B89B4 *)dsp_vptr);
            dsp_vptr->startupBreak = 0;
          }
        }
      }
      dsp_vptr = stp->alienVoiceRoot;
      while (dsp_vptr) {
        HandleDepopVoice((DSPstudioinfo_803B5AF8 *)stp, (DSPvoice_803B5AF8 *)dsp_vptr);
        dsp_vptr = dsp_vptr->nextAlien;
      }
      stp->alienVoiceRoot = 0;
      if ((dspCmdPtr + 3) > (dspCmdMaxPtr - 4)) {
        dspCmdPtr[0] = 13;
        dspCmdPtr[1] = (u32)dspCmdMaxPtr >> 16;
        dspCmdPtr[2] = (u32)dspCmdMaxPtr;
        size = (((u32)(dspCmdPtr + 4) - (u32)dspCmdCurBase) + 3) & 0xFFFC;
        if (dspCmdLastLoad) {
          dspCmdLastLoad[3] = size;
          DCStoreRangeNoSync(dspCmdLastBase, dspCmdLastSize);
        } else {
          dspCmdFirstSize = size;
        }
        dspCmdLastLoad = dspCmdPtr;
        dspCmdLastSize = size;
        dspCmdLastBase = dspCmdCurBase;
        dspCmdCurBase = dspCmdPtr = dspCmdMaxPtr;
        dspCmdMaxPtr = dspCmdPtr + 0xC0;
      }
      dspCmdPtr[0] = 0;
      dspCmdPtr[1] = (u32)stp->spb >> 16;
      dspCmdPtr[2] = (u32)stp->spb;
      dspCmdPtr += 3;
      cyclesUsed += 0x2C62;
      for (in = 0; in < stp->numInputs; in++) {
        if ((dspCmdPtr + 6) > (dspCmdMaxPtr - 4)) {
          dspCmdPtr[0] = 0xD;
          dspCmdPtr[1] = (u32)dspCmdMaxPtr >> 16;
          dspCmdPtr[2] = (u32)dspCmdMaxPtr;
          size = (((u32)(dspCmdPtr + 4) - (u32)dspCmdCurBase) + 3) & 0xFFFC;
          if (dspCmdLastLoad) {
            dspCmdLastLoad[3] = size;
            DCStoreRangeNoSync(dspCmdLastBase, dspCmdLastSize);
          } else {
            dspCmdFirstSize = size;
          }
          dspCmdLastLoad = dspCmdPtr;
          dspCmdLastSize = size;
          dspCmdLastBase = dspCmdCurBase;
          dspCmdCurBase = dspCmdPtr = dspCmdMaxPtr;
          dspCmdMaxPtr = dspCmdPtr + 0xC0;
        }
        dspCmdPtr[0] = 1;
        dspCmdPtr[1] = (u32)dspStudio[stp->in[in].studio].main[salFrame ^ 1] >> 16;
        dspCmdPtr[2] = (u32)dspStudio[stp->in[in].studio].main[salFrame ^ 1];
        dspCmdPtr[3] = stp->in[in].vol;
        dspCmdPtr[4] = stp->in[in].volA;
        dspCmdPtr[5] = stp->in[in].volB;
        dspCmdPtr += 6;
        cyclesUsed += 0x294D;
      }
      last_pb = 0;
      for (v = 0, dsp_vptr = stp->voiceRoot; dsp_vptr;
           v++, dsp_vptr = dsp_vptr->next) {
        voices[v] = dsp_vptr;
      }
      voiceNum = (int)v;
      SortVoices((Ent_803B5DB0 **)voices, 0, voiceNum - 1);
      procVoiceFlag = 0;
      for (v = voiceNum; v > 0; v--) {
        dsp_vptr = voices[v - 1];
        if (dsp_vptr->state != 0) {
          u8 i;
          pb = dsp_vptr->pb;
          for (s = 1; s < 5; s++) {
            rampResetOffsetFlags[s] = 0;
          }
          if (dsp_vptr->state == 1) {
            dsp_vptr->virtualSampleID = -1;
            dsp_vptr->pb->ve.currentDelta = 0x8000;
            if (adsrSetup((u8 *)&dsp_vptr->adsr) != 0) {
              salSynthSendMessage((u8 *)dsp_vptr, 0);
              salDeactivateVoice((Ent_803B89B4 *)dsp_vptr);
              continue;
            }
            dsp_vptr->virtualSampleID = -1;
            switch (dsp_vptr->smp_info.compType) {
            case 5:
              dsp_vptr->vSampleInfo.loopBufferLength = 0;
              dsp_vptr->virtualSampleID =
                  salSynthSendMessage((u8 *)dsp_vptr, 2);
              if (dsp_vptr->vSampleInfo.loopBufferLength == 0) {
                salSynthSendMessage((u8 *)dsp_vptr, 1);
                salDeactivateVoice((Ent_803B89B4 *)dsp_vptr);
                continue;
              }
              break;
            }
            pb->src.currentAddressFrac = 0;
            pb->src.last_samples[0] = 0;
            pb->src.last_samples[1] = 0;
            pb->src.last_samples[2] = 0;
            pb->src.last_samples[3] = 0;
            if ((dsp_vptr->flags & 0x80000000) != 0) {
              memset(dsp_vptr->itdBuffer, 0, 0x40);
              DCFlushRange(dsp_vptr->itdBuffer, 0x40);
              pb->itd.targetShiftL = dsp_vptr->itdShiftL;
              pb->itd.shiftL = dsp_vptr->itdShiftL;
              pb->itd.targetShiftR = dsp_vptr->itdShiftR;
              pb->itd.shiftR = dsp_vptr->itdShiftR;
              pb->itd.flag = 1;
            } else {
              pb->itd.flag = 0;
            }
            switch (dsp_vptr->smp_info.compType) {
            case 0:
            case 4:
            case 5: {
              SNDADPCMinfo *adpcmInfo;
              u8 i;
              pb->addr.format = 0;
              pb->adpcm.gain = 0;
              adpcmInfo = (SNDADPCMinfo *)dsp_vptr->smp_info.extraData;
              pb->adpcm.yn2 = 0;
              pb->adpcm.yn1 = 0;
              pb->adpcm.pred_scale = adpcmInfo->initialPS;
              for (i = 0; i < 8; i++) {
                pb->adpcm.a[i][0] = adpcmInfo->coefTab[i][0];
                pb->adpcm.a[i][1] = adpcmInfo->coefTab[i][1];
              }
              addr = (base = (u32)dsp_vptr->smp_info.addr * 2) + 2;
              dsp_vptr->playInfo.posHi = dsp_vptr->playInfo.posLo = 0;
              if ((dsp_vptr->smp_info.compType == 4) ||
                  (dsp_vptr->smp_info.compType == 5)) {
                pb->loopType = 1;
              } else {
                pb->adpcmLoop.loop_yn2 = adpcmInfo->loopY0;
                pb->adpcmLoop.loop_yn1 = adpcmInfo->loopY1;
                pb->adpcmLoop.loop_pred_scale = adpcmInfo->loopPS;
                pb->loopType = 0;
              }
            } break;
            case 1: {
              DSPADPCMplusInfo *adpcmInfo;
              u8 i;
              pb->addr.format = 0;
              pb->adpcm.gain = 0;
              offset = (dsp_vptr->smp_info.offset + 0xD) / 14;
              adpcmInfo = (DSPADPCMplusInfo *)dsp_vptr->smp_info.extraData;
              pb->adpcm.yn2 = adpcmInfo->blk[offset].Y0;
              pb->adpcm.yn1 = adpcmInfo->blk[offset].Y1;
              pb->adpcm.pred_scale = adpcmInfo->blk[offset].PS;
              pb->adpcmLoop.loop_yn2 = adpcmInfo->loopY0;
              pb->adpcmLoop.loop_yn1 = adpcmInfo->loopY1;
              pb->adpcmLoop.loop_pred_scale = adpcmInfo->loopPS;
              for (i = 0; i < 8; i++) {
                pb->adpcm.a[i][0] = adpcmInfo->coefTab[i][0];
                pb->adpcm.a[i][1] = adpcmInfo->coefTab[i][1];
              }
              addr = (base = (u32)dsp_vptr->smp_info.addr * 2) + offset * 16 + 2;
              dsp_vptr->playInfo.posHi = offset * 0xE;
              dsp_vptr->playInfo.posLo = 0;
            } break;
            case 3: {
              u8 i;
              pb->addr.format = 0x19;
              pb->adpcm.gain = 0x100;
              for (i = 0; i < 8; i++) {
                pb->adpcm.a[i][0] = 0;
                pb->adpcm.a[i][1] = 0;
              }
              addr = (u32)dsp_vptr->smp_info.offset + (base = (u32)dsp_vptr->smp_info.addr);
              dsp_vptr->playInfo.posHi = dsp_vptr->smp_info.offset;
              dsp_vptr->playInfo.posLo = 0;
            } break;
            case 2:
            {
              u8 i;
              pb->addr.format = 0xA;
              pb->adpcm.gain = 0x800;
              for (i = 0; i < 8; i++) {
                pb->adpcm.a[i][0] = 0;
                pb->adpcm.a[i][1] = 0;
              }
              addr = dsp_vptr->smp_info.offset + (base = (u32)dsp_vptr->smp_info.addr >> 1);
              dsp_vptr->playInfo.posHi = dsp_vptr->smp_info.offset;
              dsp_vptr->playInfo.posLo = 0;
            } break;
            default:
              ;
              break;
            }
            pb->addr.currentAddressHi = addr >> 0x10;
            pb->addr.currentAddressLo = addr;
            dsp_vptr->currentAddr = addr;
            if (dsp_vptr->smp_info.loopLength != 0) {
              pb->addr.loopFlag = 1;
              switch (dsp_vptr->smp_info.compType) {
              case 0:
              case 1:
              case 4: {
                u32 bn;
                u32 bo;
                bn = dsp_vptr->smp_info.loop / 14;
                bo = dsp_vptr->smp_info.loop - (bn * 0xE);
                loopAddr = base + bn * 16 + 2 + bo;
                endAddr = dsp_vptr->smp_info.loop + dsp_vptr->smp_info.loopLength - 1;
                bn = endAddr / 14;
                bo = endAddr - (bn * 0xE);
                endAddr = base + bn * 16 + 2 + bo;
              } break;
              case 5: {
                u32 bn;
                u32 bo;
                loopAddr = ((u32)dsp_vptr->vSampleInfo.loopBufferAddr * 2) + 2;
                endAddr = dsp_vptr->smp_info.loop + dsp_vptr->smp_info.loopLength - 1;
                bn = endAddr / 14;
                bo = endAddr - (bn * 0xE);
                endAddr = base + bn * 16 + 2 + bo;
                dsp_vptr->vSampleInfo.inLoopBuffer = 0;
              } break;
              case 2:
              case 3:
              default:
                loopAddr = base + dsp_vptr->smp_info.loop;
                endAddr = base + dsp_vptr->smp_info.loop + dsp_vptr->smp_info.loopLength - 1;
                break;
              }
              pb->addr.loopAddressHi = loopAddr >> 16;
              pb->addr.loopAddressLo = loopAddr;
              pb->addr.endAddressHi = endAddr >> 16;
              pb->addr.endAddressLo = endAddr;
              pb->streamLoopCnt = 0;
            } else {
              pb->addr.loopFlag = 0;
              switch (dsp_vptr->smp_info.compType) {
              case 0:
              case 1:
              case 4:
              case 5: {
                u32 bn;
                u32 bo;
                bn = dsp_vptr->smp_info.length / 14;
                bo = dsp_vptr->smp_info.length - (bn * 0xE);
                tmp_addr = base + bn * 16 + 2 + bo;
                zeroAddr = (dspARAMZeroBuffer * 2) + 2;
              } break;
              case 3:
                tmp_addr = base + dsp_vptr->smp_info.length;
                zeroAddr = dspARAMZeroBuffer;
                break;
              case 2:
                tmp_addr = base + dsp_vptr->smp_info.length;
                zeroAddr = dspARAMZeroBuffer >> 1;
                break;
              }
              pb->addr.loopAddressHi = zeroAddr >> 16;
              pb->addr.loopAddressLo = zeroAddr;
              pb->addr.endAddressHi = tmp_addr >> 16;
              pb->addr.endAddressLo = tmp_addr;
            }
            pb->srcSelect = dsp_vptr->srcTypeSelect;
            pb->coefSelect = dsp_vptr->srcCoefSelect;
            pb->state =
                (mix_start = dsp_vptr->singleOffset) ? 0 : 1;
            pb->mix.vL = dsp_vptr->lastVolL = dsp_vptr->volL;
            pb->mix.vR = dsp_vptr->lastVolR = dsp_vptr->volR;
            pb->mix.vS = dsp_vptr->lastVolS = dsp_vptr->volS;
            pb->mix.vAuxAL = dsp_vptr->lastVolLa = dsp_vptr->volLa;
            pb->mix.vAuxAR = dsp_vptr->lastVolRa = dsp_vptr->volRa;
            pb->mix.vAuxAS = dsp_vptr->lastVolSa = dsp_vptr->volSa;
            pb->mixerCtrl = (pb->mix.vAuxAS | (pb->mix.vAuxAL | pb->mix.vAuxAR)) != 0 ? 1 : 0;
            pb->mix.vAuxBL = dsp_vptr->lastVolLb = dsp_vptr->volLb;
            pb->mix.vAuxBR = dsp_vptr->lastVolRb = dsp_vptr->volRb;
            pb->mix.vAuxBS = dsp_vptr->lastVolSb = dsp_vptr->volSb;
            pb->mix.vDeltaL = 0;
            pb->mix.vDeltaR = 0;
            pb->mix.vDeltaS = 0;
            pb->mix.vDeltaAuxAL = 0;
            pb->mix.vDeltaAuxAR = 0;
            pb->mix.vDeltaAuxAS = 0;
            pb->mix.vDeltaAuxBL = 0;
            pb->mix.vDeltaAuxBR = 0;
            pb->mix.vDeltaAuxBS = 0;
            if (stp->type == SND_STUDIO_TYPE_STD) {
              if ((pb->mix.vAuxBS | (pb->mix.vAuxBL | pb->mix.vAuxBR)) != 0) {
                pb->mixerCtrl |= 2;
              }
              if ((pb->mix.vAuxBS | (pb->mix.vS | pb->mix.vAuxAS)) != 0) {
                pb->mixerCtrl |= 4;
              }
            } else if ((pb->mix.vAuxAS | (pb->mix.vAuxBL | pb->mix.vAuxBR)) != 0) {
              pb->mixerCtrl |= 0x10;
            }
            dsp_vptr->state = 2;
            newVoice = 1;
            goto block_186;
          }
          if ((dsp_vptr->smp_info.compType == 4) ||
              (dsp_vptr->smp_info.compType == 5)) {
            pb->adpcmLoop.loop_pred_scale = dsp_vptr->streamLoopPS;
            if ((dsp_vptr->smp_info.compType == 5) &&
                (dsp_vptr->vSampleInfo.inLoopBuffer == 0) && (pb->streamLoopCnt != 0)) {
              u32 bn;
              u32 bo;
              bn = (dsp_vptr->vSampleInfo.loopBufferLength - 1) / 14;
              bo = (dsp_vptr->vSampleInfo.loopBufferLength - 1) - (bn * 14);
              tmp_addr = ((u32)dsp_vptr->vSampleInfo.loopBufferAddr * 2) + bn * 16 + 2 + bo;
              dsp_vptr->smp_info.addr = dsp_vptr->vSampleInfo.loopBufferAddr;
              pb->addr.endAddressHi = tmp_addr >> 0x10;
              pb->addr.endAddressLo = tmp_addr;
              dsp_vptr->vSampleInfo.inLoopBuffer = 1;
            }
          }
          if ((dsp_vptr->smp_info.loopLength == 0) &&
              (dsp_vptr->playInfo.posHi >= dsp_vptr->smp_info.length)) {
            salSynthSendMessage((u8 *)dsp_vptr, 0);
            salDeactivateVoice((Ent_803B89B4 *)dsp_vptr);
            continue;
          }
          if (((dsp_vptr->changed[0] & 0x10) != 0) && (adsrSetup((u8 *)&dsp_vptr->adsr) != 0)) {
            salSynthSendMessage((u8 *)dsp_vptr, 0);
            salDeactivateVoice((Ent_803B89B4 *)dsp_vptr);
            continue;
          }
          if ((dsp_vptr->changed[0] & 1) != 0) {
            sal_setup_dspvol(&pb->mix.vDeltaL, &dsp_vptr->lastVolL, dsp_vptr->volL);
            sal_setup_dspvol(&pb->mix.vDeltaR, &dsp_vptr->lastVolR, dsp_vptr->volR);
            sal_setup_dspvol(&pb->mix.vDeltaS, &dsp_vptr->lastVolS, dsp_vptr->volS);
            needsDelta = 1;
          } else {
            needsDelta =
                salCheckVolErrorAndResetDelta(&pb->mix.vL, &pb->mix.vDeltaL, &dsp_vptr->lastVolL,
                                              dsp_vptr->volL, rampResetOffsetFlags, 1);
            needsDelta |=
                salCheckVolErrorAndResetDelta(&pb->mix.vR, &pb->mix.vDeltaR, &dsp_vptr->lastVolR,
                                              dsp_vptr->volR, rampResetOffsetFlags, 2);
            needsDelta |=
                salCheckVolErrorAndResetDelta(&pb->mix.vS, &pb->mix.vDeltaS, &dsp_vptr->lastVolS,
                                              dsp_vptr->volS, rampResetOffsetFlags, 4);
          }
          if ((dsp_vptr->changed[0] & 2) != 0) {
            sal_setup_dspvol(&pb->mix.vDeltaAuxAL, &dsp_vptr->lastVolLa, dsp_vptr->volLa);
            sal_setup_dspvol(&pb->mix.vDeltaAuxAR, &dsp_vptr->lastVolRa, dsp_vptr->volRa);
            sal_setup_dspvol(&pb->mix.vDeltaAuxAS, &dsp_vptr->lastVolSa, dsp_vptr->volSa);
            if ((pb->mix.vDeltaAuxAS | (pb->mix.vDeltaAuxAL | pb->mix.vDeltaAuxAR)) != 0) {
              pb->mixerCtrl |= 1;
              needsDelta = 1;
            } else if ((pb->mix.vAuxAS | (pb->mix.vAuxAL | pb->mix.vAuxAR)) != 0) {
              pb->mixerCtrl |= 1;
            } else {
              pb->mixerCtrl &= ~1;
            }
          }
          else if ((pb->mixerCtrl & 1) != 0) {
            u32 localNeedsDelta;
            localNeedsDelta = salCheckVolErrorAndResetDelta(&pb->mix.vAuxAL, &pb->mix.vDeltaAuxAL,
                                                            &dsp_vptr->lastVolLa, dsp_vptr->volLa,
                                                            rampResetOffsetFlags, 8);
            localNeedsDelta |= salCheckVolErrorAndResetDelta(&pb->mix.vAuxAR, &pb->mix.vDeltaAuxAR,
                                                             &dsp_vptr->lastVolRa, dsp_vptr->volRa,
                                                             rampResetOffsetFlags, 0x10);
            localNeedsDelta |= salCheckVolErrorAndResetDelta(&pb->mix.vAuxAS, &pb->mix.vDeltaAuxAS,
                                                             &dsp_vptr->lastVolSa, dsp_vptr->volSa,
                                                             rampResetOffsetFlags, 0x20);
            if ((localNeedsDelta | (pb->mix.vAuxAS | (pb->mix.vAuxAL | pb->mix.vAuxAR))) == 0) {
              pb->mixerCtrl &= ~1;
            } else {
              needsDelta = 1;
            }
          } else {
            pb->mix.vDeltaAuxAL = 0;
            pb->mix.vDeltaAuxAR = 0;
            pb->mix.vDeltaAuxAS = 0;
          }
          if ((dsp_vptr->changed[0] & 4) != 0) {
            if (stp->type == SND_STUDIO_TYPE_STD) {
              sal_setup_dspvol(&pb->mix.vDeltaAuxBL, &dsp_vptr->lastVolLb, dsp_vptr->volLb);
              sal_setup_dspvol(&pb->mix.vDeltaAuxBR, &dsp_vptr->lastVolRb, dsp_vptr->volRb);
              sal_setup_dspvol(&pb->mix.vDeltaAuxBS, &dsp_vptr->lastVolSb, dsp_vptr->volSb);
              if ((pb->mix.vDeltaAuxBS | (pb->mix.vDeltaAuxBL | pb->mix.vDeltaAuxBR)) != 0) {
                pb->mixerCtrl |= 2;
                needsDelta = 1;
              } else if ((pb->mix.vAuxBS | (pb->mix.vAuxBL | pb->mix.vAuxBR)) != 0) {
                pb->mixerCtrl |= 2;
              } else {
                pb->mixerCtrl &= ~2;
              }
            } else {
              sal_setup_dspvol(&pb->mix.vDeltaAuxBL, &dsp_vptr->lastVolLb, dsp_vptr->volLb);
              sal_setup_dspvol(&pb->mix.vDeltaAuxBR, &dsp_vptr->lastVolRb, dsp_vptr->volRb);
              if ((pb->mix.vDeltaAuxBL | pb->mix.vDeltaAuxBR) != 0) {
                pb->mixerCtrl |= 0x10;
                needsDelta = 1;
              } else if ((pb->mix.vAuxBL | pb->mix.vAuxBR) != 0) {
                pb->mixerCtrl |= 0x10;
              } else {
                pb->mixerCtrl &= ~0x10;
              }
            }
          } else if (stp->type == SND_STUDIO_TYPE_STD) {
            if ((pb->mixerCtrl & (0x020000 <= ((2 << 16) | (0 << 8) | (0)) ? 2 : 0x600)) != 0) {
              u32 localNeedsDelta;
              localNeedsDelta = salCheckVolErrorAndResetDelta(&pb->mix.vAuxBL, &pb->mix.vDeltaAuxBL,
                                                              &dsp_vptr->lastVolLb, dsp_vptr->volLb,
                                                              rampResetOffsetFlags, 0x40);
              localNeedsDelta |= salCheckVolErrorAndResetDelta(
                  &pb->mix.vAuxBR, &pb->mix.vDeltaAuxBR, &dsp_vptr->lastVolRb, dsp_vptr->volRb,
                  rampResetOffsetFlags, 0x80);
              localNeedsDelta |= salCheckVolErrorAndResetDelta(
                  &pb->mix.vAuxBS, &pb->mix.vDeltaAuxBS, &dsp_vptr->lastVolSb, dsp_vptr->volSb,
                  rampResetOffsetFlags, 0x100);
              if ((localNeedsDelta | (pb->mix.vAuxBS | (pb->mix.vAuxBL | pb->mix.vAuxBR))) == 0) {
                pb->mixerCtrl &= ~2;
              } else {
                needsDelta = 1;
              }
            } else {
              pb->mix.vDeltaAuxBL = 0;
              pb->mix.vDeltaAuxBR = 0;
              pb->mix.vDeltaAuxBS = 0;
            }
          } else if ((pb->mixerCtrl &
                      (0x020000 <= ((2 << 16) | (0 << 8) | (0)) ? 0x10 : 0x4600)) != 0) {
            u32 localNeedsDelta;
            localNeedsDelta = salCheckVolErrorAndResetDelta(&pb->mix.vAuxBL, &pb->mix.vDeltaAuxBL,
                                                            &dsp_vptr->lastVolLb, dsp_vptr->volLb,
                                                            rampResetOffsetFlags, 0x40);
            localNeedsDelta |= salCheckVolErrorAndResetDelta(&pb->mix.vAuxBR, &pb->mix.vDeltaAuxBR,
                                                             &dsp_vptr->lastVolRb, dsp_vptr->volRb,
                                                             rampResetOffsetFlags, 0x80);
            if ((localNeedsDelta | (pb->mix.vAuxBL | pb->mix.vAuxBR)) == 0) {
              if ((pb->mix.vAuxAS | pb->mix.vDeltaAuxAS) == 0) {
                pb->mixerCtrl &= ~0x10;
              }
            } else {
              needsDelta = 1;
            }
          } else {
            pb->mix.vDeltaAuxBL = 0;
            pb->mix.vDeltaAuxBR = 0;
          }
          if (needsDelta != 0) {
            pb->mixerCtrl |= 8;
          } else {
            pb->mixerCtrl &= ~8;
          }
          if (stp->type == SND_STUDIO_TYPE_STD) {
            if ((pb->mix.vS != 0) || (pb->mix.vDeltaS != 0) || (pb->mix.vAuxAS != 0) ||
                (pb->mix.vDeltaAuxAS != 0) || (pb->mix.vAuxBS != 0) || (pb->mix.vDeltaAuxBS != 0)) {
              pb->mixerCtrl |= 4;
            } else {
              pb->mixerCtrl &= ~4;
            }
          }
          if ((dsp_vptr->changed[0] & 0x200) != 0) {
            pb->itd.targetShiftL = dsp_vptr->itdShiftL;
            pb->itd.targetShiftR = dsp_vptr->itdShiftR;
          }
          if ((dsp_vptr->changed[0] & 0x100) != 0) {
            pb->srcSelect = dsp_vptr->srcTypeSelect;
          }
          if ((dsp_vptr->changed[0] & 0x80) != 0) {
            pb->coefSelect = dsp_vptr->srcCoefSelect;
          }
          mix_start = 0;
          newVoice = 0;
          dsp_vptr->currentAddr = (pb->addr.currentAddressHi << 0x10) | pb->addr.currentAddressLo;
        block_186:
          if ((dsp_vptr->changed[mix_start] & 0x40) != 0) {
            adsrRelease((struct Envelope_803B431C *)&dsp_vptr->adsr);
          }
          if ((dsp_vptr->changed[mix_start] & 8) != 0) {
            pb->src.ratioHi = dsp_vptr->pitch[mix_start] >> 0x10;
            pb->src.ratioLo = dsp_vptr->pitch[mix_start];
            dsp_vptr->playInfo.pitch = dsp_vptr->pitch[mix_start];
          }
          VoiceDone = adsrHandle(&dsp_vptr->adsr, &pb->ve.currentVolume, &pb->ve.currentDelta);
          old_adsr_delta = pb->ve.currentDelta;
          for (s = 0; s < 5; s++) {
            pb->update.updNum[s] = 0;
          }
          pptr = (u16 *)dsp_vptr->patchData;
          pend = (u16 *)((u32)dsp_vptr->patchData + 0x80);
          if (mix_start != 0) {
            ;
            pptr[0] = 7;
            pptr[1] = 1;
            pptr += 2;
            pb->update.updNum[mix_start]++;
          }
          sal_update_hostplayinfo(dsp_vptr);
          for (s = mix_start + 1; s < 5; s++) {
            if (VoiceDone != 0) {
              ;
              pptr[0] = 7;
              pptr[1] = 0;
              pptr += 2;
              pb->update.updNum[s]++;
              salSynthSendMessage((u8 *)dsp_vptr, 0);
              salDeactivateVoice((Ent_803B89B4 *)dsp_vptr);
              break;
            } else {
              if (rampResetOffsetFlags[s] != 0) {
                for (i = 0; i < 9; i++) {
                  if (((1 << i) & rampResetOffsetFlags[s]) != 0) {
                    ;
                    pptr[0] = pbOffsets[i];
                    pptr[1] = 0;
                    pptr += 2;
                    pb->update.updNum[s]++;
                  }
                }
              }
              if ((dsp_vptr->changed[s] & 0x20) != 0) {
                adsrStartRelease((ADSR_VARS_803B41C8 *)&dsp_vptr->adsr, 10);
                dsp_vptr->postBreak = 1;
              } else if (dsp_vptr->postBreak == 0) {
                if ((dsp_vptr->changed[s] & 0x40) != 0) {
                  adsrRelease((struct Envelope_803B431C *)&dsp_vptr->adsr);
                }
                if ((dsp_vptr->changed[s] & 8) != 0) {
                  ;
                  pptr[0] = 0x53;
                  pptr[1] = dsp_vptr->pitch[s] >> 16;
                  pptr[2] = 0x54;
                  pptr[3] = dsp_vptr->pitch[s];
                  pptr += 4;
                  pb->update.updNum[s] += 2;
                  dsp_vptr->playInfo.pitch = dsp_vptr->pitch[s];
                }
              }
              current_delta = dsp_vptr->adsr.currentDelta;
              VoiceDone = adsrHandle(&dsp_vptr->adsr, &adsr_start, &adsr_delta);
              if (old_adsr_delta == adsr_delta) {
                if (current_delta != 0) {
                  ;
                  pptr[0] = 0x32;
                  pptr[1] = adsr_start;
                  pptr += 2;
                  pb->update.updNum[s]++;
                }
              } else {
                ;
                pptr[0] = 0x32;
                pptr[1] = adsr_start;
                pptr[2] = 0x33;
                pptr[3] = adsr_delta;
                pptr += 4;
                pb->update.updNum[s] += 2;
                old_adsr_delta = adsr_delta;
              }
              sal_update_hostplayinfo(dsp_vptr);
            }
          }
          if (VoiceDone != 0) {
            salSynthSendMessage((u8 *)dsp_vptr, 0);
            salDeactivateVoice((Ent_803B89B4 *)dsp_vptr);
          }
          DCStoreRangeNoSync(dsp_vptr->patchData, (u32)pptr - (u32)dsp_vptr->patchData);
          cyclesUsed += dspMixerCycles[pb->mixerCtrl] + 0x4FE;
          switch (pb->src.ratioHi) {
          case 0:
          case 1:
            cyclesUsed += dspSRCCycles[pb->src.ratioHi][pb->srcSelect];
            break;
          default:
            cyclesUsed += dspSRCCycles[2][pb->srcSelect];
            break;
          }
          for (s = 0; s < 5; s++) {
            cyclesUsed += pb->update.updNum[s] * 4;
          }
          if (cyclesUsed > (__OSBusClock / 400)) {
            if ((newVoice == 0) && (VoiceDone == 0)) {
              HandleDepopVoice((DSPstudioinfo_803B5AF8 *)stp, (DSPvoice_803B5AF8 *)dsp_vptr);
            }
            salDeactivateVoice((Ent_803B89B4 *)dsp_vptr);
            salSynthSendMessage((u8 *)dsp_vptr, 1);
            for (v = v - 1; v > 0; v--) {
              if (voices[v - 1]->state == 2) {
                HandleDepopVoice((DSPstudioinfo_803B5AF8 *)stp, (DSPvoice_803B5AF8 *)voices[v - 1]);
              }
              salDeactivateVoice((Ent_803B89B4 *)voices[v - 1]);
              salSynthSendMessage((u8 *)voices[v - 1], 1);
            }
            for (st1 = st + 1; st1 < salMaxStudioNum; st1++) {
              if (dspStudio[st1].state == 1) {
                for (dsp_vptr = dspStudio[st1].voiceRoot; dsp_vptr; dsp_vptr = next_dsp_vptr) {
                  next_dsp_vptr = dsp_vptr->next;
                  if (dsp_vptr->state == 2) {
                    HandleDepopVoice((DSPstudioinfo_803B5AF8 *)&dspStudio[st1], (DSPvoice_803B5AF8 *)dsp_vptr);
                  }
                  salDeactivateVoice((Ent_803B89B4 *)dsp_vptr);
                  salSynthSendMessage((u8 *)dsp_vptr, 1);
                }
              }
            }
            break;
          } else {
            if (!last_pb) {
              if ((dspCmdPtr + 3) > (dspCmdMaxPtr - 4)) {
                dspCmdPtr[0] = 13;
                dspCmdPtr[1] = (u32)dspCmdMaxPtr >> 16;
                dspCmdPtr[2] = (u32)dspCmdMaxPtr;
                size = (((u32)(dspCmdPtr + 4) - (u32)dspCmdCurBase) + 3) & 0xFFFC;
                if (dspCmdLastLoad) {
                  dspCmdLastLoad[3] = size;
                  DCStoreRangeNoSync(dspCmdLastBase, dspCmdLastSize);
                } else {
                  dspCmdFirstSize = size;
                }
                dspCmdLastLoad = dspCmdPtr;
                dspCmdLastSize = size;
                dspCmdLastBase = dspCmdCurBase;
                dspCmdCurBase = dspCmdPtr = dspCmdMaxPtr;
                dspCmdMaxPtr = dspCmdPtr + 0xC0;
              }
              dspCmdPtr[0] = 2;
              dspCmdPtr[1] = (u32)pb >> 0x10;
              dspCmdPtr[2] = (u32)pb;
              dspCmdPtr += 3;
              procVoiceFlag = 1;
            } else {
              last_pb->nextHi = (u32)pb >> 16;
              last_pb->nextLo = (u32)pb;
              procVoiceFlag = 1;
              DCFlushRangeNoSync(last_pb, sizeof(_PB));
            }
            last_pb = pb;
          }
        }
      }
      if (procVoiceFlag != 0) {
        if ((dspCmdPtr + 1) > (dspCmdMaxPtr - 4)) {
          dspCmdPtr[0] = 13;
          dspCmdPtr[1] = (u32)dspCmdMaxPtr >> 16;
          dspCmdPtr[2] = (u32)dspCmdMaxPtr;
          size = (((u32)(dspCmdPtr + 4) - (u32)dspCmdCurBase) + 3) & 0xFFFC;
          if (dspCmdLastLoad) {
            dspCmdLastLoad[3] = size;
            DCStoreRangeNoSync(dspCmdLastBase, dspCmdLastSize);
          } else {
            dspCmdFirstSize = size;
          }
          dspCmdLastLoad = dspCmdPtr;
          dspCmdLastSize = size;
          dspCmdLastBase = dspCmdCurBase;
          dspCmdCurBase = dspCmdPtr = dspCmdMaxPtr;
          dspCmdMaxPtr = dspCmdPtr + 0xC0;
        }
        *dspCmdPtr++ = 3;
      }
      if (last_pb) {
        last_pb->nextHi = 0;
        last_pb->nextLo = 0;
        DCFlushRangeNoSync(last_pb, sizeof(_PB));
      }
      getAuxFrame = (salAuxFrame + 1) % 3;
      if (stp->auxAHandler) {
        if ((dspCmdPtr + 5) > (dspCmdMaxPtr - 4)) {
          dspCmdPtr[0] = 13;
          dspCmdPtr[1] = (u32)dspCmdMaxPtr >> 16;
          dspCmdPtr[2] = (u32)dspCmdMaxPtr;
          size = (((u32)(dspCmdPtr + 4) - (u32)dspCmdCurBase) + 3) & 0xFFFC;
          if (dspCmdLastLoad) {
            dspCmdLastLoad[3] = size;
            DCStoreRangeNoSync(dspCmdLastBase, dspCmdLastSize);
          } else {
            dspCmdFirstSize = size;
          }
          dspCmdLastLoad = dspCmdPtr;
          dspCmdLastSize = size;
          dspCmdLastBase = dspCmdCurBase;
          dspCmdCurBase = dspCmdPtr = dspCmdMaxPtr;
          dspCmdMaxPtr = dspCmdPtr + 0xC0;
        }
        dspCmdPtr[0] = 4;
        dspCmdPtr[1] = (u32)stp->auxA[salAuxFrame] >> 16;
        dspCmdPtr[2] = (u32)stp->auxA[salAuxFrame];
        dspCmdPtr[3] = (u32)stp->auxA[getAuxFrame] >> 16;
        dspCmdPtr[4] = (u32)stp->auxA[getAuxFrame];
        dspCmdPtr += 5;
      }
      if (stp->type == SND_STUDIO_TYPE_STD) {
        if (stp->auxBHandler) {
          if ((dspCmdPtr + 5) > (dspCmdMaxPtr - 4)) {
            dspCmdPtr[0] = 13;
            dspCmdPtr[1] = (u32)dspCmdMaxPtr >> 16;
            dspCmdPtr[2] = (u32)dspCmdMaxPtr;
            size = (((u32)(dspCmdPtr + 4) - (u32)dspCmdCurBase) + 3) & 0xFFFC;
            if (dspCmdLastLoad) {
              dspCmdLastLoad[3] = size;
              DCStoreRangeNoSync(dspCmdLastBase, dspCmdLastSize);
            } else {
              dspCmdFirstSize = size;
            }
            dspCmdLastLoad = dspCmdPtr;
            dspCmdLastSize = size;
            dspCmdLastBase = dspCmdCurBase;
            dspCmdCurBase = dspCmdPtr = dspCmdMaxPtr;
            dspCmdMaxPtr = dspCmdPtr + 0xC0;
          }
          dspCmdPtr[0] = 5;
          dspCmdPtr[1] = (u32)stp->auxB[salAuxFrame] >> 16;
          dspCmdPtr[2] = (u32)stp->auxB[salAuxFrame];
          dspCmdPtr[3] = (u32)stp->auxB[getAuxFrame] >> 16;
          dspCmdPtr[4] = (u32)stp->auxB[getAuxFrame];
          dspCmdPtr += 5;
        }
      } else {
        if ((dspCmdPtr + 5) > (dspCmdMaxPtr - 4)) {
          dspCmdPtr[0] = 13;
          dspCmdPtr[1] = (u32)dspCmdMaxPtr >> 16;
          dspCmdPtr[2] = (u32)dspCmdMaxPtr;
          size = (((u32)(dspCmdPtr + 4) - (u32)dspCmdCurBase) + 3) & 0xFFFC;
          if (dspCmdLastLoad) {
            dspCmdLastLoad[3] = size;
            DCStoreRangeNoSync(dspCmdLastBase, dspCmdLastSize);
          } else {
            dspCmdFirstSize = size;
          }
          dspCmdLastLoad = dspCmdPtr;
          dspCmdLastSize = size;
          dspCmdLastBase = dspCmdCurBase;
          dspCmdCurBase = dspCmdPtr = dspCmdMaxPtr;
          dspCmdMaxPtr = dspCmdPtr + 0xC0;
        }
        dspCmdPtr[0] = 16;
        dspCmdPtr[1] = (u32)stp->auxB[salFrame] >> 16;
        dspCmdPtr[2] = (u32)stp->auxB[salFrame];
        dspCmdPtr[3] = (u32)stp->auxB[salFrame ^ 1] >> 16;
        dspCmdPtr[4] = (u32)stp->auxB[salFrame ^ 1];
        dspCmdPtr += 5;
      }
      if ((dspCmdPtr + 3) > (dspCmdMaxPtr - 4)) {
        dspCmdPtr[0] = 13;
        dspCmdPtr[1] = (u32)dspCmdMaxPtr >> 16;
        dspCmdPtr[2] = (u32)dspCmdMaxPtr;
        size = (((u32)(dspCmdPtr + 4) - (u32)dspCmdCurBase) + 3) & 0xFFFC;
        if (dspCmdLastLoad) {
          dspCmdLastLoad[3] = size;
          DCStoreRangeNoSync(dspCmdLastBase, dspCmdLastSize);
        } else {
          dspCmdFirstSize = size;
        }
        dspCmdLastLoad = dspCmdPtr;
        dspCmdLastSize = size;
        dspCmdLastBase = dspCmdCurBase;
        dspCmdCurBase = dspCmdPtr = dspCmdMaxPtr;
        dspCmdMaxPtr = dspCmdPtr + 0xC0;
      }
      dspCmdPtr[0] = 6;
      dspCmdPtr[1] = (u32)stp->main[salFrame] >> 16;
      dspCmdPtr[2] = (u32)stp->main[salFrame];
      dspCmdPtr += 3;
      spb = stp->spb;
      DoDepopFade((long *)&spb->dpopLHi, (s16 *)&spb->dpopLDelta, &stp->hostDPopSum.l);
      DoDepopFade((long *)&spb->dpopRHi, (s16 *)&spb->dpopRDelta, &stp->hostDPopSum.r);
      DoDepopFade((long *)&spb->dpopSHi, (s16 *)&spb->dpopSDelta, &stp->hostDPopSum.s);
      DoDepopFade((long *)&spb->dpopALHi, (s16 *)&spb->dpopALDelta, &stp->hostDPopSum.lA);
      DoDepopFade((long *)&spb->dpopARHi, (s16 *)&spb->dpopARDelta, &stp->hostDPopSum.rA);
      DoDepopFade((long *)&spb->dpopASHi, (s16 *)&spb->dpopASDelta, &stp->hostDPopSum.sA);
      DoDepopFade((long *)&spb->dpopBLHi, (s16 *)&spb->dpopBLDelta, &stp->hostDPopSum.lB);
      DoDepopFade((long *)&spb->dpopBRHi, (s16 *)&spb->dpopBRDelta, &stp->hostDPopSum.rB);
      DoDepopFade((long *)&spb->dpopBSHi, (s16 *)&spb->dpopBSDelta, &stp->hostDPopSum.sB);
      DCFlushRangeNoSync(spb, sizeof(_SPB));
    }
  }
  if ((dspCmdPtr + 3) > (dspCmdMaxPtr - 4)) {
    dspCmdPtr[0] = 13;
    dspCmdPtr[1] = (u32)dspCmdMaxPtr >> 16;
    dspCmdPtr[2] = (u32)dspCmdMaxPtr;
    size = (((u32)(dspCmdPtr + 4) - (u32)dspCmdCurBase) + 3) & 0xFFFC;
    if (dspCmdLastLoad) {
      dspCmdLastLoad[3] = size;
      DCStoreRangeNoSync(dspCmdLastBase, dspCmdLastSize);
    } else {
      dspCmdFirstSize = size;
    }
    dspCmdLastLoad = dspCmdPtr;
    dspCmdLastSize = size;
    dspCmdLastBase = dspCmdCurBase;
    dspCmdCurBase = dspCmdPtr = dspCmdMaxPtr;
    dspCmdMaxPtr = dspCmdPtr + 0xC0;
  }
  dspCmdPtr[0] = 17;
  dspCmdPtr[1] = (u32)dspSurround >> 16;
  dspCmdPtr[2] = (u32)dspSurround;
  dspCmdPtr += 3;
  for (st = 0; st < salMaxStudioNum; st++) {
    if ((dspStudio[st].state == 1) && (dspStudio[st].isMaster != 0)) {
      if ((dspCmdPtr + 3) > (dspCmdMaxPtr - 4)) {
        dspCmdPtr[0] = 13;
        dspCmdPtr[1] = (u32)dspCmdMaxPtr >> 16;
        dspCmdPtr[2] = (u32)dspCmdMaxPtr;
        size = (((u32)(dspCmdPtr + 4) - (u32)dspCmdCurBase) + 3) & 0xFFFC;
        if (dspCmdLastLoad) {
          dspCmdLastLoad[3] = size;
          DCStoreRangeNoSync(dspCmdLastBase, dspCmdLastSize);
        } else {
          dspCmdFirstSize = size;
        }
        dspCmdLastLoad = dspCmdPtr;
        dspCmdLastSize = size;
        dspCmdLastBase = dspCmdCurBase;
        dspCmdCurBase = dspCmdPtr = dspCmdMaxPtr;
        dspCmdMaxPtr = dspCmdPtr + 0xC0;
      }
      dspCmdPtr[0] = 9;
      dspCmdPtr[1] = (u32)dspStudio[st].main[salFrame] >> 16;
      dspCmdPtr[2] = (u32)dspStudio[st].main[salFrame];
      dspCmdPtr += 3;
    }
  }
  if ((dspCmdPtr + 5) > (dspCmdMaxPtr - 4)) {
    dspCmdPtr[0] = 13;
    dspCmdPtr[1] = (u32)dspCmdMaxPtr >> 16;
    dspCmdPtr[2] = (u32)dspCmdMaxPtr;
    size = (((u32)(dspCmdPtr + 4) - (u32)dspCmdCurBase) + 3) & 0xFFFC;
    if (dspCmdLastLoad) {
      dspCmdLastLoad[3] = size;
      DCStoreRangeNoSync(dspCmdLastBase, dspCmdLastSize);
    } else {
      dspCmdFirstSize = size;
    }
    dspCmdLastLoad = dspCmdPtr;
    dspCmdLastSize = size;
    dspCmdLastBase = dspCmdCurBase;
    dspCmdCurBase = dspCmdPtr = dspCmdMaxPtr;
    dspCmdMaxPtr = dspCmdPtr + 0xC0;
  }
  {
    dspCmdPtr[0] = 14;
    dspCmdPtr[1] = (u32)dspSurround >> 16;
    dspCmdPtr[2] = (u32)dspSurround;
    dspCmdPtr[3] = (u32)dest >> 16;
    dspCmdPtr[4] = (u32)dest;
    dspCmdPtr += 5;
    *dspCmdPtr++ = 15;
    size = (((u32)dspCmdPtr - (u32)dspCmdCurBase) + 3) & 0xFFFC;
    if (dspCmdLastLoad) {
      dspCmdLastLoad[3] = size;
      DCStoreRangeNoSync(dspCmdLastBase, dspCmdLastSize);
    } else {
      dspCmdFirstSize = size;
    }
  }
  DCStoreRangeNoSync(dspCmdCurBase, (u32)dspCmdPtr - (u32)dspCmdCurBase);
}

#pragma pop

#undef dspStudio
#define dspStudio lbl_805663D8
#undef dspCmdLastLoad
#undef dspCmdLastBase
#undef dspCmdLastSize
#undef dspCmdCurBase
#undef dspCmdMaxPtr
#undef dspCmdPtr
#undef dspCmdFirstSize
#undef dspHRTFOn
#undef salAuxFrame
#undef salFrame
#undef dspMixerCycles
#undef pbOffsets
#undef dspSRCCycles

s32 salSynthSendMessage(u8 *arg0, s32 arg1) {
    struct Fields_arg0 { u8 pad_0[24]; s32 field_18; };
    if (((s32 (*)(s32, s32)) salMessageCallback) == NULL) {
        return 0;
    }
    return salMessageCallback(arg1, ((Fields_arg0*)arg0)->field_18);
}
#pragma push
#pragma opt_common_subs on
void salActivateVoice(Ent_803B8910 *dsp_vptr, u8 studio) {
    if (dsp_vptr->active != 0) {
        salDeactivateVoice((Ent_803B89B4 *)dsp_vptr);
        dsp_vptr->flags |= 0x20;
    }
    dsp_vptr->fED = 0;
    if ((dsp_vptr->next = (Ent_803B8910 *)lbl_805663D8[studio].voiceRoot) != 0) {
        dsp_vptr->next->prev = dsp_vptr;
    }
    dsp_vptr->prev = 0;
    lbl_805663D8[studio].voiceRoot = dsp_vptr;
    dsp_vptr->fEE = 0;
    dsp_vptr->active = 1;
    dsp_vptr->idx = studio;
}
#pragma pop

void salDeactivateVoice(Ent_803B89B4 *arg0) {
    if (arg0->active != 0) {
        if (arg0->prev != 0) {
            arg0->prev->next = arg0->next;
        } else {
            lbl_805663D8[arg0->idx].head = arg0->next;
        }
        if (arg0->next != 0) {
            arg0->next->prev = arg0->prev;
        }
        arg0->active = 0;
    }
}

#pragma push
#pragma opt_common_subs on
s32 salAddStudioInput(Obj_803B8A14 *stp, Src_803B8A14 *desc) {
    if (stp->numInputs < 7) {
        stp->in[stp->numInputs].studio = desc->srcStudio;
        stp->in[stp->numInputs].vol = ((u16)desc->vol << 8) | ((u16)desc->vol << 1);
        stp->in[stp->numInputs].volA = ((u16)desc->volA << 8) | ((u16)desc->volA << 1);
        stp->in[stp->numInputs].volB = ((u16)desc->volB << 8) | ((u16)desc->volB << 1);
        stp->in[stp->numInputs].desc = desc;
        ++stp->numInputs;
        return 1;
    }
    return 0;
}
#pragma pop

s32 salRemoveStudioInput(Obj_803B8ABC *arg0, u32 arg1) {
    s32 i;

    for (i = 0; i < arg0->count; i++) {
        if (arg0->slots[i].src == arg1) {
            for (; i <= arg0->count - 2; i++) {
                arg0->slots[i] = arg0->slots[i + 1];
            }
            arg0->count--;
            return 1;
        }
    }
    return 0;
}

void salHandleAuxProcessing(void) {
    s32 bufs[3];
    u8 i;
    Voice_803B8B40 *v;
    s32 buf;

    i = 0;
    v = (Voice_803B8B40 *)lbl_805663D8;
    while (i < lbl_805D74C4) {
        if (v->b50 == 1) {
            if (v->cbA != 0) {
                buf = v->bufA[(lbl_805D74C6 + 2) % 3];
                bufs[0] = buf;
                bufs[1] = buf + 0x280;
                bufs[2] = buf + 0x500;
                v->cbA(0, bufs, v->argA, lbl_805D74C6 + 2);
                DCFlushRangeNoSync((void *)buf, 0x780);
            }
            if (v->i54 == 0 && v->cbB != 0) {
                buf = v->bufB[(lbl_805D74C6 + 2) % 3];
                bufs[0] = buf;
                bufs[1] = buf + 0x280;
                bufs[2] = buf + 0x500;
                v->cbB(0, bufs, v->argB, lbl_805D74C6 + 2);
                DCFlushRangeNoSync((void *)buf, 0x780);
            }
        }
        i++;
        v++;
    }
}

}
