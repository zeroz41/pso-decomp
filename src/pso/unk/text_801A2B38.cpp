#include "types.h"
#include "pso/object/container/TOContainerAncientEnemyRare.h"
#include "pso/object/collision/TObjRaderHideCol.h"
#include "pso/unk/text_8015C048.h"
#include "pso/item/TObjItemLight.h"
#include "pso/object/collision/TObjBgmCol_8017E7F0.h"
#include "pso/object/collision/TObjRaderCol.h"
#include "pso/unk/text_801A2B38.h"

extern "C" {

void *TObjCityMainWarpChallenge__ct(void *, void *, void *);
void *TObjContainerAbeEnemy__ct(void *, void *, void *);
void *__nw__7TObjectFUl(int);

void *TOContainerAncientItemRare__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x368);
    if (o != NULL) {
        o = TOContainerAncientItemRare__ct((u8 *)o, (s32)arg0);
    }
    return o;
}

void *TOContainerAncientEnemyRare__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x368);
    if (o != NULL) {
        o = TOContainerAncientEnemyRare__ct((u8 *)o, (s32)arg0);
    }
    return o;
}

extern void *tl_05;

void *TObjRaderCol__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xA0);
    if (o != NULL) {
        o = TObjRaderCol__ct((TObjRaderCol *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

void *TObjRaderHideCol__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x98);
    if (o != NULL) {
        o = TObjRaderHideCol__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void *TObjContainerAbeEnemy__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x368);
    if (o != NULL) {
        o = TObjContainerAbeEnemy__ct(o, tl_05, arg0);
    }
    return o;
}

void *TObjBgmCol__create(void *set) {
    void *o = __nw__7TObjectFUl(0xA0);
    if (o != NULL) {
        o = TObjBgmCol__ct((TObjBgmCol *)o, (s32)tl_05, set);
    }
    return o;
}

void *TObjItemLight__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x98);
    if (o != NULL) {
        o = TObjItemLight__ct((TObjItemLight *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

void *TObjCityMainWarpChallenge__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x180);
    if (o != NULL) {
        o = TObjCityMainWarpChallenge__ct(o, tl_05, arg0);
    }
    return o;
}

}
