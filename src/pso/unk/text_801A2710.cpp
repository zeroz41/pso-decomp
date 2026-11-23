#include "types.h"
#include "pso/object/door/TODoorFourLightRuins.h"
#include "pso/object/door/TODoorFourLightSpace.h"
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
#include "pso/system/task/TObject.h"

extern "C" {
void *TODoorFourLightSeabedU__ct(void *, void *, void *);
void *TODoorFourLightSeabed__ct(void *, void *, void *);
void *TODoorLaboNormal__ct(void *, void *, void *);
void *TODoorLabo__ct(void *, void *, void *);


}
void *TODoorFourLightSeabed__create(void *arg0) {
    void *o = TObject::operator new(0xFC);
    if (o != NULL) {
        o = TODoorFourLightSeabed__ct(o, tl_05, arg0);
    }
    return o;
}

void *TODoorFourLightSeabedU__create(void *arg0) {
    void *o = TObject::operator new(0xFC);
    if (o != NULL) {
        o = TODoorFourLightSeabedU__ct(o, tl_05, arg0);
    }
    return o;
}

void *TODoorLabo__create(void *arg0) {
    void *o = TObject::operator new(0xFC);
    if (o != NULL) {
        o = TODoorLabo__ct(o, tl_05, arg0);
    }
    return o;
}

void *TODoorLaboNormal__create(void *arg0) {
    void *o = TObject::operator new(0xFC);
    if (o != NULL) {
        o = TODoorLaboNormal__ct(o, tl_05, arg0);
    }
    return o;
}

void *TODoorFourLightRuins::create(void *arg0) {
    void *o = (void *)new TODoorFourLightRuins((saddr)tl_05, (saddr)arg0);
    return o;
}

void *TODoorFourLightSpace::create(void *arg0) {
    void *o = (void *)new TODoorFourLightSpace((saddr)tl_05, (saddr)arg0);
    return o;
}

void *TObjInfoCol::create(void *arg0) {
    void *o = (void *)new TObjInfoCol((saddr)tl_05, (saddr)arg0);
    return o;
}

void *TObjWarpLobby::create(void *set_data) {
    return new TObjWarpLobby(tl_05, set_data);
}

void *TObjAreaWarpEnding::create(void *set_data) {
    return new TObjAreaWarpEnding(tl_05, set_data);
}

void *TObjAreaWarpQuest::create(void *set_data) {
    return new TObjAreaWarpQuest(tl_05, set_data);
}

void *TObjAreaWarpForest::create(void *set_data) {
    return new TObjAreaWarpForest(tl_05, set_data);
}

void *TObjMapWarpForest::create(void *set_data) {
    return new TObjMapWarpForest(tl_05, set_data);
}

void *TObjMapForceWarp::create(void *set_data) {
    return new TObjMapForceWarp(tl_05, set_data);
}

