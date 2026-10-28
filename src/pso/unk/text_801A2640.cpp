#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjInfoCol.h"
#include "pso/unk/text_801A2640.h"
#include "pso/system/vector.h"

extern "C" {
extern const f32 lbl_805DC098;
extern const f32 lbl_805DC0A0;
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
TUnk_804B9870::TUnk_804B9870(TObject *parent) : TObject(parent) {
    actorFlags = 0;
    entity_id = 0xFFFF;
    room = -1;
    set_group = 0;
    set_index = -1;
    m_20 = 1;
    texture_id = 0;
    model = NULL;
    set_entry = NULL;
    position[0] = lbl_805DC098;
    position[1] = lbl_805DC098;
    position[2] = lbl_805DC098;
    VecCopy(&prev_position, (const Vec *)position);
    VecCopy(&home_position, (const Vec *)position);
    rotation_x = 0;
    rotation_y = 0;
    rotation_z = 0;
    scale.x = lbl_805DC0A0;
    scale.y = lbl_805DC0A0;
    scale.z = lbl_805DC0A0;
    center.x = lbl_805DC098;
    center.y = lbl_805DC098;
    center.z = lbl_805DC098;
    visibility = 0;
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

