#include "musyx/musyx.h"
#include "musyx/runtime/musyx_internal.h"

extern "C" {

s32 sndFXCtrl(u32 vid, u8 ctrl, u8 value) {
    s32 ret;
    hwDisableIrq();
    ret = synthFXSetCtrl(vid, ctrl, value);
    hwEnableIrq();
    return ret;
}

s32 sndFXCtrl14(u32 vid, u8 ctrl, u16 value) {
    s32 ret;
    hwDisableIrq();
    ret = synthFXSetCtrl14(vid, ctrl, value);
    hwEnableIrq();
    return ret;
}

s32 sndFXKeyOff(s32 vid) {
    s32 ret;
    hwDisableIrq();
    ret = synthSendKeyOff(vid);
    hwEnableIrq();
    return ret;
}

u32 sndFXStartParaInfo(u16 fid, u8 vol, u8 pan, u8 studio, SndParaInfo *req) {
    u32 id;
    u8 i;
    SndParaEntry *e;
    u8 t;
    hwDisableIrq();
    id = synthFXStart(fid, vol, pan, studio, synthITDDefault[studio].sfx);
    if (id != 0xFFFFFFFF) {
        e = req->ents;
        i = 0;
        while (i < req->count) {
            t = e->type;
            if (t < 0x40 || t == 0x80 || t == 0x84) {
                synthFXSetCtrl14(id, t, e->v.w);
            } else {
                synthFXSetCtrl(id, t, e->v.b);
            }
            e++;
            i++;
        }
    }
    hwEnableIrq();
    return id;
}

u32 sndFXCheck(u32 id) {
    if (vidGetInternalId(id) != 0xFFFFFFFF) return id;
    return 0xFFFFFFFF;
}

void sndVolume(u8 volume, u16 time, u8 vGroup) {
    hwDisableIrq();
    synthVolume(volume, time, vGroup, 0, -1);
    hwEnableIrq();
}

void sndOutputMode(s32 mode) {
    u32 old = synthFlags;
    u32 i;

    switch (mode) {
    case 0:
        synthFlags = old | 1;
        synthFlags &= ~2;
        hwDisableHRTF();
        break;
    case 1:
        synthFlags = old & ~1;
        synthFlags &= ~2;
        hwDisableHRTF();
        break;
    case 2:
        synthFlags = old & ~1;
        synthFlags |= 2;
        hwDisableHRTF();
        break;
    }
    if (old != (u32)synthFlags) {
        for (i = 0; i < synthInfo.voiceNum; i++) {
            synthVoice[i].cFlags |= 0x200000000000ULL;
        }
        streamOutputModeChanged();
    }
}

void sndSetAuxProcessingCallbacks(u8 studio, SND_AUX_CALLBACK auxA, void *userA, u8 midiA, SND_SEQID seqIDA,
                                  SND_AUX_CALLBACK auxB, void *userB, u8 midiB, SND_SEQID seqIDB) {
    hwDisableIrq();
    if (auxA != 0) {
        if ((synthAuxAMIDI[studio] = midiA) != 0xFF) {
            synthAuxAMIDISet[studio] = seqGetPrivateId(seqIDA);
            synthAuxACallback[studio] = auxA;
            synthAuxAUser[studio] = userA;
        }
    } else {
        synthAuxACallback[studio] = 0;
        synthAuxAMIDI[studio] = 0xFF;
    }
    if (auxB != 0) {
        if ((synthAuxBMIDI[studio] = midiB) != 0xFF) {
            synthAuxBMIDISet[studio] = seqGetPrivateId(seqIDB);
            synthAuxBCallback[studio] = auxB;
            synthAuxBUser[studio] = userB;
        }
    } else {
        synthAuxBCallback[studio] = 0;
        synthAuxBMIDI[studio] = 0xFF;
    }
    hwSetAUXProcessingCallbacks(studio, auxA, userA, auxB, userB);
    hwEnableIrq();
}
#pragma push
#pragma opt_common_subs on
void synthActivateStudio(u8 studio, u32 isMaster, u32 type) {
    hwDisableIrq();
    synthAuxACallback[studio] = 0;
    synthAuxBCallback[studio] = 0;
    synthAuxAMIDI[studio] = 0xFF;
    synthAuxBMIDI[studio] = 0xFF;
    synthITDDefault[studio].sfx = 0;
    synthITDDefault[studio].music = 0;
    hwActivateStudio(studio, isMaster, type);
    hwEnableIrq();
}
#pragma pop

void synthDeactivateStudio(u8 studio) {
    u32 i;
    for (i = 0; i < synthInfo.voiceNum; ++i) {
        SynthVoice *sv;
        if (studio == (sv = &synthVoice[i])->studio) {
            if (sv->id != 0xFFFFFFFF) {
                voiceKillSound(sv->vidList->vid);
            } else if (hwIsActive(i)) {
                hwOff(i);
            }
        }
    }
    hwDisableIrq();
    synthAuxACallback[studio] = 0;
    synthAuxBCallback[studio] = 0;
    synthAuxAMIDI[studio] = 0xFF;
    synthAuxBMIDI[studio] = 0xFF;
    hwEnableIrq();
    hwDeactivateStudio(studio);
}

void synthAddStudioInput(u8 studio, SND_STUDIO_INPUT *in_desc) {
    hwAddInput(studio, in_desc);
}

void synthRemoveStudioInput(u8 studio, SND_STUDIO_INPUT *in_desc) {
    hwRemoveInput(studio, in_desc);
}

}
