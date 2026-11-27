#include "types.h"
#include "pso/object/door/TODoorFourLightRuins.h"
#include "pso/object/door/TODoorFourLightSpace.h"
#include "pso/object/door/TODoorFourLightSeabed.h"
#include "pso/object/door/TODoorFourLightSeabedU.h"
#include "pso/object/door/TODoorLabo.h"
#include "pso/object/door/TODoorLaboNormal.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/collision/TObjInfoCol.h"
#include "pso/system/vector.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/warp/TObjWarpLobby.h"
#include "pso/object/warp/TObjAreaWarpEnding.h"
#include "pso/object/warp/TObjAreaWarpQuest.h"
#include "pso/object/warp/TObjAreaWarpForest.h"
#include "pso/object/warp/TObjMapWarpForest.h"
#include "pso/object/warp/TObjMapForceWarp.h"
#include "pso/system/task/TObject.h"

void *TODoorFourLightSeabed::create(ObjectSetData *set_data) {
    return new TODoorFourLightSeabed(tl_05, set_data);
}

void *TODoorFourLightSeabedU::create(ObjectSetData *set_data) {
    return new TODoorFourLightSeabedU(tl_05, set_data);
}

void *TODoorLabo::create(ObjectSetData *set_data) {
    return new TODoorLabo(tl_05, set_data);
}

void *TODoorLaboNormal::create(ObjectSetData *set_data) {
    return new TODoorLaboNormal(tl_05, set_data);
}

void *TODoorFourLightRuins::create(ObjectSetData *set_data) {
    void *o = new TODoorFourLightRuins(tl_05, set_data);
    return o;
}

void *TODoorFourLightSpace::create(ObjectSetData *set_data) {
    void *o = new TODoorFourLightSpace(tl_05, set_data);
    return o;
}

void *TObjInfoCol::create(ObjectSetData *set_data) {
    void *o = new TObjInfoCol(tl_05, set_data);
    return o;
}

void *TObjWarpLobby::create(ObjectSetData *set_data) {
    return new TObjWarpLobby(tl_05, set_data);
}

void *TObjAreaWarpEnding::create(ObjectSetData *set_data) {
    return new TObjAreaWarpEnding(tl_05, set_data);
}

void *TObjAreaWarpQuest::create(ObjectSetData *set_data) {
    return new TObjAreaWarpQuest(tl_05, set_data);
}

void *TObjAreaWarpForest::create(ObjectSetData *set_data) {
    return new TObjAreaWarpForest(tl_05, set_data);
}

void *TObjMapWarpForest::create(ObjectSetData *set_data) {
    return new TObjMapWarpForest(tl_05, set_data);
}

void *TObjMapForceWarp::create(ObjectSetData *set_data) {
    return new TObjMapForceWarp(tl_05, set_data);
}

