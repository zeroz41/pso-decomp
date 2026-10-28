#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjInfoCol.h"
#include "pso/unk/text_801A2710.h"
#include "pso/system/vector.h"

extern "C" {
u8 *TODoorFourLightRuins__ct(u8 *arg0, s32 arg1, s32 arg2);
void *TODoorFourLightSeabedU__ct(void *, void *, void *);
void *TODoorFourLightSeabed__ct(void *, void *, void *);
u8 *TODoorFourLightSpace__ct(u8 *arg0, s32 arg1, s32 arg2);
void *TODoorLaboNormal__ct(void *, void *, void *);
void *TODoorLabo__ct(void *, void *, void *);
u8 *TObjAreaWarpEnding__ct(u8 *arg0, s32 arg1, s32 arg2);
u8 *TObjAreaWarpForest__ct(u8 *arg0, s32 arg1, s32 arg2);
u8 *TObjAreaWarpQuest__ct(u8 *arg0, s32 arg1, s32 arg2);
void *TObjMapForceWarp__ct(void *, void *, void *);
void *TObjMapWarpForest__ct(void *, void *, void *);
void *TObjWarpLobby__ct(void *, void *, void *);
void *__nw__7TObjectFUl(int);

extern void *tl_05;

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

void *TObjWarpLobby__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xE0);
    if (o != NULL) {
        o = TObjWarpLobby__ct(o, tl_05, arg0);
    }
    return o;
}

void *TObjAreaWarpEnding__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xDC);
    if (o != NULL) {
        o = TObjAreaWarpEnding__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void *TObjAreaWarpQuest__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xE0);
    if (o != NULL) {
        o = TObjAreaWarpQuest__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void *TObjAreaWarpForest__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xDC);
    if (o != NULL) {
        o = TObjAreaWarpForest__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void *TObjMapWarpForest__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x110);
    if (o != NULL) {
        o = TObjMapWarpForest__ct(o, tl_05, arg0);
    }
    return o;
}

void *TObjMapForceWarp__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x100);
    if (o != NULL) {
        o = TObjMapForceWarp__ct(o, tl_05, arg0);
    }
    return o;
}

