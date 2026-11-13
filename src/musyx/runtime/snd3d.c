#include "musyx/runtime/musyx_runtime_a.h"

#define synthVoice ((SYNTH_VOICE_803B2438 *)synthVoice)
extern "C" {

s8 lbl_805D7498;
s32 lbl_805D749C;
s32 lbl_805D74A0;
s32 lbl_805D74A4;
s32 lbl_805D74A8;
s32 lbl_805D74AC;
s8 lbl_805D74B0;
s8 lbl_805D74B1;
s8 lbl_805D74B2;
u8 lbl_805D74B3;
u8 lbl_805D74B4;
u8 lbl_805D74B5;

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
#pragma opt_common_subs on
void UpdateRoomDistances(void) {
    Vec_803B9438 d;
    B_803B9438 *r;
    A_803B9438 *li;
    f32 distance;
    u32 n;
    for (n = 0, li = (*(A_803B9438 * *)&lbl_805D74A0); li != 0; li = li->next, ++n)
        ;
    if (n != 0) {
        for (r = (*(B_803B9438 * *)&lbl_805D74A4); r != 0; r = r->next) {
            if (r->studio != 0xFF) {
                distance = 0.f;
                for (li = (*(A_803B9438 * *)&lbl_805D74A0); li != 0; li = li->next) {
                    d.x = r->pos.x - li->pos.x;
                    d.y = r->pos.y - li->pos.y;
                    d.z = r->pos.z - li->pos.z;
                    distance += d.x * d.x + d.y * d.y + d.z * d.z;
                }
                r->distance = distance / n;
            }
        }
    }
}
#pragma pop

#define s3dCallCnt (*(u8 *)&lbl_805D7498)
#define s3dEmitterRoot (*(Emitter_S3D **)&lbl_805D749C)
#define s3dListenerRoot (*(Listener_S3D **)&lbl_805D74A0)
#define s3dRoomRoot (*(Room_S3D **)&lbl_805D74A4)
#define s3dDoorRoot (*(Door_S3D **)&lbl_805D74A8)
#define snd_used_studios (*(u32 *)&lbl_805D74AC)
#define snd_base_studio (*(u8 *)&lbl_805D74B0)
#define snd_max_studios (*(u8 *)&lbl_805D74B1)
#define s3dUseMaxVoices (*(u8 *)&lbl_805D74B2)

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
#pragma opt_common_subs on
void CheckRoomStatus(void) {
    Listener_S3D *li;
    Emitter_S3D *em;
    Room_S3D *r;
    Room_S3D *max_room;
    Room_S3D *room;
    FVec_S3D d;
    f32 distance;
    f32 maxDis;
    u32 li_num;
    u32 i;
    u32 mask;
    u8 has_listener;

    UpdateRoomDistances();

    for (li_num = 0, li = s3dListenerRoot; li != 0; li = li->next, ++li_num)
        ;

    if (li_num != 0) {
        for (room = s3dRoomRoot; room != 0; room = room->next) {
            if (room->studio == 0xff) {
                distance = 0.f;
                for (li = s3dListenerRoot; li != 0; li = li->next) {
                    d.x = room->pos.x - li->pos.x;
                    d.y = room->pos.y - li->pos.y;
                    d.z = room->pos.z - li->pos.z;
                    distance += d.x * d.x + d.y * d.y + d.z * d.z;
                }

                distance = distance / li_num;

                has_listener = 0;
                for (li = s3dListenerRoot; li != 0; li = li->next) {
                    if (li->room == room) {
                        has_listener = 1;
                        break;
                    }
                }

                mask = ~(-1 << snd_max_studios);

                if (mask != (snd_used_studios & mask)) {
                    for (i = 0; i < snd_max_studios; ++i) {
                        if (!(snd_used_studios & (1 << i))) {
                            break;
                        }
                    }

                    snd_used_studios |= (1 << i);
                    room->studio = i + snd_base_studio;
                } else {
                    maxDis = -1.f;

                    for (r = s3dRoomRoot; r != 0; r = r->next) {
                        if (r->studio != 0xFF && maxDis < r->distance) {
                            maxDis = r->distance;
                            max_room = r;
                        }
                    }

                    if (has_listener || maxDis > distance) {
                        for (em = s3dEmitterRoot; em != 0; em = em->next) {
                            if (em->room == max_room) {
                                synthSendKeyOff(em->vid);
                                em->flags |= 0x80000;
                                em->vid = -1;
                            }
                        }

                        if (max_room->deActivateReverb != 0) {
                            max_room->deActivateReverb(max_room->studio);
                        }

                        synthDeactivateStudio(max_room->studio);
                        room->studio = max_room->studio;
                        max_room->studio = 0xff;
                        max_room->flags = 0;
                    } else {
                        continue;
                    }
                }
                room->distance = distance;
                room->curMVol = has_listener ? 0x7f0000 : 0;

                if (room->curMVol * 1.2014794e-07f >= 0.5) {
                    synthActivateStudio(room->studio, 1, 0);
                } else {
                    synthActivateStudio(room->studio, 0, 0);
                }

                if (room->activateReverb != 0) {
                    room->activateReverb(room->studio, room->user);
                }
            } else {
                if (room->flags & 0x80000000) {
                    room->curMVol += 0x40000;
                    if (room->curMVol >= 0x7F0000) {
                        room->curMVol = 0x7F0000;
                        room->flags &= ~0x80000000;
                    }

                    if (room->curMVol * 1.2014794e-07f >= 0.5) {
                        synthActivateStudio(room->studio, 1, 0);
                    } else {
                        synthActivateStudio(room->studio, 0, 0);
                    }
                }

                if ((room->flags & 0x40000000) != 0) {
                    room->curMVol = room->curMVol - 0x40000;
                    if ((int)room->curMVol >= 0) {
                        room->curMVol = 0;
                        room->flags &= ~0x40000000;
                    }
                    if (room->curMVol * 1.2014794e-07f >= 0.5) {
                        synthActivateStudio(room->studio, 1, 0);
                    } else {
                        synthActivateStudio(room->studio, 0, 0);
                    }
                }
            }
        }
    }
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
#pragma opt_common_subs on
static inline void CalcDoorParameters_S3D(Door_S3D *door) {
    f32 f;
    f32 v;
    v = door->open;
    f = (1.f - door->open) * door->dampen;
    door->input.volA = door->fxVol * v;
    door->input.volB = 0;
    door->input.vol = v * 127.f;
}

void CheckDoorStatus(void) {
    Door_S3D *door;

    for (door = s3dDoorRoot; door != 0; door = door->next) {
        if (!(door->flags & 0x80000000)) {
            if (door->a->studio != 0xFF) {
                if (door->b->studio != 0xFF) {
                    CalcDoorParameters_S3D(door);
                    if (door->flags & 1) {
                        door->input.srcStudio = door->b->studio;
                        synthAddStudioInput(door->a->studio, &door->input);
                    } else {
                        door->input.srcStudio = door->a->studio;
                        synthAddStudioInput(door->b->studio, &door->input);
                    }

                    door->flags |= 0x80000000;
                }
            }
        } else if (door->a->studio == 0xFF || door->b->studio == 0xFF) {
            if ((door->a->studio != 0xFF && door->a->studio == door->destStudio) ||
                (door->b->studio != 0xFF && door->b->studio == door->destStudio)) {
                synthRemoveStudioInput(door->destStudio, &door->input);
            }

            door->flags &= ~0x80000000;
        } else {
            CalcDoorParameters_S3D(door);
        }
    }
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
#pragma opt_common_subs on
static inline f32 sqrtf_S3D(f32 x) {
    static const f64 _half = .5;
    static const f64 _three = 3.0;
    volatile f32 y;
    if (x > 0.0f) {
        f64 guess = __frsqrte((f64)x);
        guess = _half * guess * (_three - guess * guess * x);
        guess = _half * guess * (_three - guess * guess * x);
        guess = _half * guess * (_three - guess * guess * x);
        y = (f32)(x * guess);
        return y;
    }
    return x;
}

void CalcEmitter(Emitter_S3D *em, f32 *vol, f32 *doppler, f32 *xPan, f32 *yPan, f32 *zPan) {
    Listener_S3D *li;
    FVec_S3D d;
    FVec_S3D v;
    FVec_S3D p;
    f32 relspeed;
    f32 distance;
    f32 new_distance;
    f32 ft;
    f32 vd;
    FVec_S3D pan;
    u32 n;

    ft = 1.f / 60.f;
    *vol = 0.f;
    *doppler = 1.f;

    pan.x = pan.y = pan.z = 0.f;

    for (n = 0, li = s3dListenerRoot; li != 0; li = li->next, ++n) {
        d.x = em->pos.x - (li->pos.x + li->heading.x * li->volPosOff);
        d.y = em->pos.y - (li->pos.y + li->heading.y * li->volPosOff);
        d.z = em->pos.z - (li->pos.z + li->heading.z * li->volPosOff);

        distance = sqrtf_S3D(d.x * d.x + d.y * d.y + d.z * d.z);

        if (em->maxDis >= distance) {
            vd = distance / em->maxDis;

            if (em->volPush >= 0.f) {
                *vol += li->vol * (em->minVol + (em->maxVol - em->minVol) *
                                                    (1.f - ((1.f - em->volPush) * vd + em->volPush * vd * vd)));
            } else {
                *vol += li->vol * (em->minVol + (em->maxVol - em->minVol) *
                                                    (1.f - ((em->volPush + 1.f) * vd -
                                                            em->volPush * (1.f - (1.f - vd) * (1.f - vd)))));
            }

            if (em->flags & 0x80000) {
                continue;
            }
            if ((em->flags & 0x8) || (li->flags & 1)) {
                v.x = li->dir.x - em->dir.x;
                v.y = li->dir.y - em->dir.y;
                v.z = li->dir.z - em->dir.z;
                relspeed = sqrtf_S3D(v.x * v.x + v.y * v.y + v.z * v.z);

                if (relspeed > 0.f) {
                    d.x = (em->pos.x + em->dir.x * ft) - (li->pos.x + li->dir.x * ft);
                    d.y = (em->pos.y + em->dir.y * ft) - (li->pos.y + li->dir.y * ft);
                    d.z = (em->pos.z + em->dir.z * ft) - (li->pos.z + li->dir.z * ft);

                    new_distance = sqrtf_S3D(d.x * d.x + d.y * d.y + d.z * d.z);

                    if (new_distance < distance) {
                        *doppler = li->soundSpeed / (li->soundSpeed - relspeed);
                    } else {
                        *doppler = li->soundSpeed / (li->soundSpeed + relspeed);
                    }
                }
            }

            if (distance != 0.f) {
                salApplyMatrix(&li->mat, &em->pos, &p);

                if (p.z <= 0.f) {
                    pan.z += -li->surroundDisFront < p.z ? -p.z / li->surroundDisFront : 1.f;
                } else {
                    pan.z += li->surroundDisBack > p.z ? -p.z / li->surroundDisBack : -1.f;
                }

                if (p.x != 0.f || p.y != 0.f || p.z != 0.f) {
                    salNormalizeVector(&p);
                }

                pan.x += p.x;
                pan.y -= p.y;
            }
        }
    }

    if (n != 0) {
        *xPan = pan.x / n;
        *yPan = pan.y / n;
        *zPan = pan.z / n;
    }
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
#pragma opt_common_subs on
static inline u8 clip127_S3D(u8 v) {
    if (v > 0x7f) {
        return 0x7f;
    }
    return v;
}

static inline u16 clip3FFF_S3D(u32 v) {
    if (v > 0x3fff) {
        return 0x3fff;
    }
    return v;
}

void SetFXParameters(Emitter_S3D *const em, f32 vol, f32 xPan, f32 yPan, f32 zPan, f32 doppler) {
    u32 vid;
    u8 i;
    Param_S3D *pPtr;

    vid = em->vid;
    if ((em->flags & 0x100000) != 0) {
        synthFXSetCtrl(vid, 7, clip127_S3D((em->fade * vol) * 127.f));
    } else {
        synthFXSetCtrl(vid, 7, clip127_S3D(vol * 127.f));
    }

    synthFXSetCtrl(vid, 10, clip127_S3D((1.f + xPan) * 64.f));
    synthFXSetCtrl(vid, 131, clip127_S3D((1.f - zPan) * 64.f));
    synthFXSetCtrl14(vid, 132, clip3FFF_S3D(doppler * 8192.0f));

    if (em->paraInfo != 0) {
        pPtr = em->paraInfo->paraArray;
        for (i = 0; i < em->paraInfo->numPara; ++pPtr, ++i) {
            if (pPtr->ctrl < 0x40 || pPtr->ctrl == 0x80 || pPtr->ctrl == 0x84) {
                synthFXSetCtrl14(vid, pPtr->ctrl, (pPtr->paraData).value14);
            } else {
                synthFXSetCtrl(vid, pPtr->ctrl, (pPtr->paraData).value7);
            }
        }
    }
}
#pragma pop

void EmitterShutdown(Node_803BA1B8 *arg0) {
    if (arg0->next != 0) {
        arg0->next->prev = arg0->prev;
    }
    if (arg0->prev != 0) {
        arg0->prev->next = arg0->next;
    } else {
        (*(Node_803BA1B8 * *)&lbl_805D749C) = arg0->next;
    }
    arg0->f10 = (u16)arg0->f10;
    if (arg0->id != 0xFFFFFFFF) {
        synthSendKeyOff((int)(arg0->id));
    }
}

void s3dKillEmitterByFXID(Ent_803BA228 *arg0, u32 arg1) {
    Node_803BA228 *n;
    Node_803BA228 *next;
    u32 i;

    for (n = *(Node_803BA228 **)&lbl_805D749C; n != 0; n = next) {
        next = n->next;
        for (i = 0; i < arg1; i++) {
            if (n->id == arg0[i].id) {
                if (sndActive != 0) {
                    hwDisableIrq();
                    if (n->f10 & 0x10000) {
                        EmitterShutdown((Node_803BA1B8 *)n);
                    }
                    hwEnableIrq();
                }
                break;
            }
        }
    }
}

Emitter_S3D tmp_em_S3D;
static StartGroup_S3D startGroup_S3D[64];
static StartList_S3D startListNum_S3D[64];
static RunList_S3D runList_S3D[64];
Emitter_S3D em_80567908_S3D;

#define startGroup startGroup_S3D
#define startListNum startListNum_S3D
#define runList runList_S3D
#define startGroupNum lbl_805D74B3
#define startListNumnum lbl_805D74B4
#define runListNum lbl_805D74B5

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
#pragma opt_common_subs on
void AddRunningEmitter(Emitter_S3D *em, f32 vol) {
    s32 i;
    RunList_S3D *rl;
    RunList_S3D *lrl;

    for (i = 0; i < startGroupNum; ++i) {
        if (em->group == startGroup[i].id) {
            break;
        }
    }

    if (i == startGroupNum) {
        startGroup[i].list = 0;
        startGroup[i].running = 0;
        startGroup[i].numRunning = 0;
        startGroup[i].id = em->group;
        ++startGroupNum;
    }

    ++startGroup[i].numRunning;

    lrl = 0;
    for (rl = startGroup[i].running; rl != 0; rl = rl->next) {
        if (rl->vol > vol) {
            break;
        }
        lrl = rl;
    }

    if (lrl == 0) {
        startGroup[i].running = &runList[runListNum];
    } else {
        lrl->next = &runList[runListNum];
    }

    runList[runListNum].next = rl;
    runList[runListNum].em = em;
    runList[runListNum++].vol = vol;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
#pragma opt_common_subs on
u32 AddStartingEmitter(Emitter_S3D *em, f32 vol, f32 xPan, f32 yPan, f32 zPan, f32 pitch) {
    s32 i;
    StartList_S3D *sl;

    for (i = 0; i < startGroupNum; ++i) {
        if (em->group == startGroup[i].id) {
            break;
        }
    }

    if (i == startGroupNum) {
        if (startGroupNum == 64) {
            return 0;
        }

        startGroup[i].list = 0;
        startGroup[i].running = 0;
        startGroup[i].numRunning = 0;
        startGroup[i].id = em->group;
        ++startGroupNum;
    }

    if (startListNumnum == 64) {
        return 0;
    }

    if ((sl = startGroup[i].list) != 0) {
        for (; sl->next != 0; sl = sl->next) {
            if (sl->vol < vol) {
                break;
            }
        }
        startListNum[startListNumnum].next = sl->next;
        sl->next = &startListNum[startListNumnum];
    } else {
        startListNum[startListNumnum].next = startGroup[i].list;
        startGroup[i].list = &startListNum[startListNumnum];
    }

    startListNum[startListNumnum].em = em;
    startListNum[startListNumnum].pitch = pitch;
    startListNum[startListNumnum].xPan = xPan;
    startListNum[startListNumnum].yPan = yPan;
    startListNum[startListNumnum].zPan = zPan;
    startListNum[startListNumnum++].vol = vol;

    return 1;
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
#pragma opt_common_subs on
#pragma bool off
void StartContinousEmitters(void) {
    s32 synthFXStart(u16 fid, u8 vol, u8 pan, u8 studio, u32 itd);
    s32 i;
    StartList_S3D *sl;
    Emitter_S3D *em;
    f32 dv;

    for (i = 0; i < startGroupNum; ++i) {
        for (sl = startGroup[i].list; sl != 0; sl = sl->next) {
            if ((startGroup[i].running != 0) &&
                !(((s3dUseMaxVoices != 0 && ((startGroup[i].id & 0x80000000) != 0)) &&
                   (startGroup[i].numRunning < startGroup[i].list->em->maxVoices)))) {

                dv = sl->vol - (startGroup[i].running)->vol;
                if (dv <= 0.08f) {
                    continue;
                } else if (dv <= 0.15f) {
                    if (++sl->em->VolLevelCnt < 20) {
                        continue;
                    }
                } else {
                    sl->em->VolLevelCnt = 0;
                }
            }
            em = sl->em;

            if (em->room != 0 && em->room->studio == 0xFF) {
                goto set_flags;
            }
            if ((em->vid = synthFXStart(em->fxid, 127, 64, em->room != 0 ? em->room->studio : em->studio,
                                          (em->flags & 0x10) != 0)) == -1) {
            set_flags:
                if (!(em->flags & 0x2)) {
                    em->flags |= 0x40000;
                    em->flags &= ~0x20000;
                }
            } else {
                if (!(em->flags & 0x20)) {
                    em->flags |= 0x100000;
                    em->fade = 0.f;
                } else {
                    em->fade = 1.f;
                }
                SetFXParameters(em, sl->vol, sl->xPan, sl->yPan, sl->zPan, sl->pitch);
                em->flags &= ~0x20000;
                ++startGroup[i].numRunning;
                if (startGroup[i].running != 0) {
                    startGroup[i].running = startGroup[i].running->next;
                }
            }
        }
    }
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
#pragma auto_inline on
#pragma opt_common_subs on
#pragma bool off
static inline void ClearStartList_S3D(void) {
    startGroupNum = 0;
    startListNumnum = 0;
    runListNum = 0;
}

static inline void EmitterShutdown_S3D(Emitter_S3D *em) {
    if (em->next != 0) {
        em->next->prev = em->prev;
    }

    if (em->prev != 0) {
        em->prev->next = em->next;
    } else {
        s3dEmitterRoot = em->next;
    }

    em->flags &= 0xFFFF;
    if (em->vid != -1) {
        synthSendKeyOff(em->vid);
    }
}

void s3dHandle(void) {
    s32 synthFXStart(u16 fid, u8 vol, u8 pan, u8 studio, u32 itd);
    Emitter_S3D *em;
    Emitter_S3D *nem;
    f32 vol;
    f32 xPan;
    f32 yPan;
    f32 zPan;
    f32 pitch;

    if (s3dCallCnt != 0) {
        --s3dCallCnt;
        return;
    }
    s3dCallCnt = 3;
    ClearStartList_S3D();
    em = s3dEmitterRoot;
    for (; em != 0; em = nem) {
        nem = em->next;
        if ((em->flags & 0x40000) != 0) {
            EmitterShutdown_S3D(em);
            continue;
        }
        if ((em->flags & 0x20001) != 0) {
            CalcEmitter(em, &vol, &pitch, &xPan, &yPan, &zPan);
        }

        if (!(em->flags & 0x80000)) {
            if (em->flags & 0x20000) {
                if (vol == 0.f && em->flags & 0x4) {
                    em->flags |= 0x80000;
                    em->flags &= ~0x20000;
                    goto found_emitter;
                } else if (vol == 0.f && em->flags & 0x40) {
                    EmitterShutdown_S3D(em);
                    continue;
                }

                if (em->flags & 1) {
                    if (AddStartingEmitter(em, vol, xPan, yPan, zPan, pitch)) {
                        continue;
                    }
                } else if (em->room == 0 || em->room->studio != 0xFF) {
                    if ((em->vid = synthFXStart(em->fxid, 127, 64, em->room != 0 ? em->room->studio : em->studio,
                                                  (em->flags & 0x10) != 0)) == -1) {
                    derp:
                        if (!(em->flags & 2)) {
                            em->flags |= 0x40000;
                            em->flags &= ~0x20000;
                        } else {
                            continue;
                        }
                    }
                } else {
                    goto derp;
                }
            } else if ((em->vid = sndFXCheck(em->vid)) == -1) {
                if ((em->flags & 2)) {
                    em->flags |= 0x20000;
                } else {
                    em->flags |= 0x40000;
                }
            }

        found_emitter:
            if (em->vid != -1) {
                if ((em->flags & 1) != 0) {
                    AddRunningEmitter(em, vol);
                }
                if ((vol == 0.f) && ((em->flags & 4) != 0)) {
                    synthSendKeyOff(em->vid);
                    em->vid = 0xffffffff;
                    if ((em->flags & 2)) {
                        em->flags |= 0x80000;
                    } else {
                        em->flags |= 0x40000;
                    }
                } else {
                    SetFXParameters(em, vol, xPan, yPan, zPan, pitch);
                }
            }
            if ((em->flags & 0x100000) != 0) {
                em->fade += .3f;
                if (em->fade >= 1.f) {
                    em->flags &= ~0x100000;
                }
            }
        } else if ((em->room == 0 || (em->room != 0 && em->room->studio != 0xff)) && vol != 0.f) {
            em->flags &= ~0x80000;
            em->flags |= 0x20000;
        }
    }
    StartContinousEmitters();
    CheckRoomStatus();
    CheckDoorStatus();
}
#pragma pop

void s3dInit(s32 arg0) {
    lbl_805D749C = 0;
    lbl_805D74A0 = 0;
    lbl_805D74A4 = 0;
    lbl_805D74A8 = 0;
    lbl_805D74AC = 0;
    lbl_805D74B0 = 1;
    lbl_805D74B1 = 3;
    lbl_805D7498 = 0;
    lbl_805D74B2 = (arg0 & 2) != 0;
}

}
