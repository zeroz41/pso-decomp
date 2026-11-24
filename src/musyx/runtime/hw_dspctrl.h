#ifndef MUSYX_HW_DSPCTRL_H
#define MUSYX_HW_DSPCTRL_H

#include "types.h"
#include "musyx/musyx.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  SND_STUDIO_TYPE_STD = 0,
  SND_STUDIO_TYPE_DPL2,
  SND_STUDIO_TYPE_RESERVED1,
  SND_STUDIO_TYPE_RESERVED2
} SND_STUDIO_TYPE;

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

typedef struct ADSR_INFO {
  union ai_data {
    struct {
      s32 atime;
      s32 dtime;
      u16 slevel;
      u16 rtime;
    } dls;
    struct {
      u16 atime;
      u16 dtime;
      u16 slevel;
      u16 rtime;
    } linear;
  } data;
} ADSR_INFO;

typedef struct SAL_VOLINFO {
  f32 volL;
  f32 volR;
  f32 volS;
  f32 volAuxAL;
  f32 volAuxAR;
  f32 volAuxAS;
  f32 volAuxBL;
  f32 volAuxBR;
  f32 volAuxBS;
} SAL_VOLINFO;

typedef u32 (*SND_MESSAGE_CALLBACK)(u32 mesg, u32 data);

extern DSPvoice *dspVoice;
extern DSPstudioinfo dspStudio[8];
extern SND_MESSAGE_CALLBACK salMessageCallback;

#ifdef __cplusplus
}
#endif

#endif
