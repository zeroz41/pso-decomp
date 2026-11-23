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

void *TODoorFourLightSeabed::create(void *set_data) {
    return new TODoorFourLightSeabed(tl_05, set_data);
}

void *TODoorFourLightSeabedU::create(void *set_data) {
    return new TODoorFourLightSeabedU(tl_05, set_data);
}

void *TODoorLabo::create(void *set_data) {
    return new TODoorLabo(tl_05, set_data);
}

void *TODoorLaboNormal::create(void *set_data) {
    return new TODoorLaboNormal(tl_05, set_data);
}

void *TODoorFourLightRuins::create(void *set_data) {
    void *o = (void *)new TODoorFourLightRuins((saddr)tl_05, (saddr)set_data);
    return o;
}

void *TODoorFourLightSpace::create(void *set_data) {
    void *o = (void *)new TODoorFourLightSpace((saddr)tl_05, (saddr)set_data);
    return o;
}

void *TObjInfoCol::create(void *set_data) {
    void *o = (void *)new TObjInfoCol((saddr)tl_05, (saddr)set_data);
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

