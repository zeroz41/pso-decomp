#include "types.h"
#include "pso/object/container/TOContainerAncientEnemyRare.h"
#include "pso/object/collision/TObjRaderHideCol.h"
#include "pso/object/container/TOContainerAncientItemRare.h"
#include "pso/object/container/TObjContainerAbeEnemy.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TObjItemLight.h"
#include "pso/object/collision/TObjBgmCol.h"
#include "pso/object/collision/TObjBgmCol_8017E7F0.h"
#include "pso/object/collision/TObjRaderCol.h"
#include "pso/object/warp/TObjCityMainWarpChallenge.h"
#include "pso/system/task/TObject.h"


void *TOContainerAncientItemRare::create(void *set_data) {
    return new TOContainerAncientItemRare(set_data);
}

void *TOContainerAncientEnemyRare::create(void *set_data) {
    return new TOContainerAncientEnemyRare(set_data);
}

void *TObjRaderCol::create(void *set_data) {
    return new TObjRaderCol((TObject *)tl_05, set_data);
}

void *TObjRaderHideCol::create(void *set_data) {
    return new TObjRaderHideCol(tl_05, set_data);
}

void *TObjContainerAbeEnemy::create(void *set_data) {
    return new TObjContainerAbeEnemy(tl_05, set_data);
}

void *TObjBgmCol::create(void *set) {
    return new TObjBgmCol((TObject *)tl_05, set);
}

void *TObjItemLight::create(void *set_data) {
    return new TObjItemLight((TObject *)tl_05, (saddr)set_data);
}

void *TObjCityMainWarpChallenge::create(void *set_data) {
    return new TObjCityMainWarpChallenge(tl_05, set_data);
}
