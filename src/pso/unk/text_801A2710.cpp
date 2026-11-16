#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/collision/TObjInfoCol.h"
#include "pso/unk/text_801A2710.h"
#include "pso/system/vector.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/warp/TObjWarpLobby.h"
#include "pso/object/warp/TObjAreaWarpEnding.h"
#include "pso/object/warp/TObjAreaWarpQuest.h"
#include "pso/object/warp/TObjAreaWarpForest.h"
#include "pso/object/warp/TObjMapWarpForest.h"
#include "pso/object/warp/TObjMapForceWarp.h"

extern "C" {
u8 *TODoorFourLightRuins__ct(u8 *arg0, s32 arg1, s32 arg2);
void *TODoorFourLightSeabedU__ct(void *, void *, void *);
void *TODoorFourLightSeabed__ct(void *, void *, void *);
u8 *TODoorFourLightSpace__ct(u8 *arg0, s32 arg1, s32 arg2);
void *TODoorLaboNormal__ct(void *, void *, void *);
void *TODoorLabo__ct(void *, void *, void *);
void *__nw__7TObjectFUl(int);


}
void *TODoorFourLightSeabed__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xFC);
    if (o != NULL) {
        o = TODoorFourLightSeabed__ct(o, tl_05, arg0);
    }
    return o;
}

void *TODoorFourLightSeabedU__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xFC);
    if (o != NULL) {
        o = TODoorFourLightSeabedU__ct(o, tl_05, arg0);
    }
    return o;
}

void *TODoorLabo__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xFC);
    if (o != NULL) {
        o = TODoorLabo__ct(o, tl_05, arg0);
    }
    return o;
}

void *TODoorLaboNormal__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xFC);
    if (o != NULL) {
        o = TODoorLaboNormal__ct(o, tl_05, arg0);
    }
    return o;
}

void *TODoorFourLightRuins__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xF8);
    if (o != NULL) {
        o = TODoorFourLightRuins__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void *TODoorFourLightSpace__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xF8);
    if (o != NULL) {
        o = TODoorFourLightSpace__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void *TObjInfoCol__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xB0);
    if (o != NULL) {
        o = TObjInfoCol__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void *TObjWarpLobby__create(void *set_data) {
    return new TObjWarpLobby(tl_05, set_data);
}

void *TObjAreaWarpEnding__create(void *set_data) {
    return new TObjAreaWarpEnding(tl_05, set_data);
}

void *TObjAreaWarpQuest__create(void *set_data) {
    return new TObjAreaWarpQuest(tl_05, set_data);
}

void *TObjAreaWarpForest__create(void *set_data) {
    return new TObjAreaWarpForest(tl_05, set_data);
}

void *TObjMapWarpForest__create(void *set_data) {
    return new TObjMapWarpForest(tl_05, set_data);
}

void *TObjMapForceWarp__create(void *set_data) {
    return new TObjMapForceWarp(tl_05, set_data);
}

