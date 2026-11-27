#include "types.h"
#include "pso/object/container/TOContainerAncientEnemyRare.h"
#include "pso/object/collision/TObjRaderHideCol.h"
#include "pso/object/container/TOContainerAncientItemRare.h"
#include "pso/object/container/TObjContainerAbeEnemy.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TObjItemLight.h"
#include "pso/object/collision/TObjBgmCol.h"
#include "pso/object/collision/TObjRaderCol.h"
#include "pso/object/warp/TObjCityMainWarpChallenge.h"
#include "pso/system/task/TObject.h"


void *TOContainerAncientItemRare::create(ObjectSetData *set_data) {
    return new TOContainerAncientItemRare(set_data);
}

void *TOContainerAncientEnemyRare::create(ObjectSetData *set_data) {
    return new TOContainerAncientEnemyRare(set_data);
}

void *TObjRaderCol::create(ObjectSetData *set_data) {
    return new TObjRaderCol(tl_05, set_data);
}

void *TObjRaderHideCol::create(ObjectSetData *set_data) {
    return new TObjRaderHideCol(tl_05, set_data);
}

void *TObjContainerAbeEnemy::create(ObjectSetData *set_data) {
    return new TObjContainerAbeEnemy(tl_05, set_data);
}

void *TObjBgmCol::create(ObjectSetData *set) {
    return new TObjBgmCol(tl_05, set);
}

void *TObjItemLight::create(ObjectSetData *set_data) {
    return new TObjItemLight(tl_05, set_data);
}

void *TObjCityMainWarpChallenge::create(ObjectSetData *set_data) {
    return new TObjCityMainWarpChallenge(tl_05, set_data);
}
