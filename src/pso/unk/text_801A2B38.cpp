#include "types.h"
#include "pso/object/container/TOContainerAncientEnemyRare.h"
#include "pso/object/collision/TObjRaderHideCol.h"
#include "pso/object/container/TOContainerAncientItemRare.h"
#include "pso/object/container/TObjContainerAbeEnemy.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TObjItemLight.h"
#include "pso/object/collision/TObjBgmCol_8017E7F0.h"
#include "pso/object/collision/TObjRaderCol.h"
#include "pso/unk/text_801A2B38.h"
#include "pso/object/warp/TObjCityMainWarpChallenge.h"
#include "pso/system/task/TObject.h"

extern "C" {


void *TOContainerAncientItemRare__create(void *set_data) {
    return new TOContainerAncientItemRare(set_data);
}

void *TOContainerAncientEnemyRare__create(void *set_data) {
    return new TOContainerAncientEnemyRare(set_data);
}

void *TObjRaderCol__create(void *arg0) {
    void *o = TObject::operator new(0xA0);
    if (o != NULL) {
        o = TObjRaderCol__ct((TObjRaderCol *)((u8 *)o), (saddr)tl_05, (saddr)arg0);
    }
    return o;
}

void *TObjRaderHideCol__create(void *arg0) {
    void *o = TObject::operator new(0x98);
    if (o != NULL) {
        o = TObjRaderHideCol__ct((u8 *)o, (saddr)tl_05, (saddr)arg0);
    }
    return o;
}

void *TObjContainerAbeEnemy__create(void *set_data) {
    return new TObjContainerAbeEnemy(tl_05, set_data);
}

void *TObjBgmCol__create(void *set) {
    void *o = TObject::operator new(0xA0);
    if (o != NULL) {
        o = TObjBgmCol__ct((TObjBgmCol *)o, (saddr)tl_05, set);
    }
    return o;
}

void *TObjItemLight__create(void *arg0) {
    void *o = TObject::operator new(0x98);
    if (o != NULL) {
        o = TObjItemLight__ct((TObjItemLight *)((u8 *)o), (saddr)tl_05, (saddr)arg0);
    }
    return o;
}

void *TObjCityMainWarpChallenge__create(void *set_data) {
    return new TObjCityMainWarpChallenge(tl_05, set_data);
}

}
