#include "types.h"
#include "pso/object/container/TOContainerAncientItemRare.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/container/TOContainerAncientItemNone.h"

extern "C" {

void *TOContainerAncientItemNone__ct(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TOContainerAncientItemNone::vfunc_6(s16 *arg1, s32 arg2) {
    if ((s16) *arg1 == 1) {
        if (arg2 != 0) {
            this->vfunc_79();
        }
        this->mode = 1;
        set_flag8();
        queue_destruction__7TObjectFv(this);
    }
}

void *TOContainerAncientItemNone::create(void *container_ancient_item_none) {
    void *o = __nw__7TObjectFUl(0x368);
    if (o != NULL) {
        o = TOContainerAncientItemNone__ct(o, container_ancient_item_none);
    }
    return o;
}

extern s32 __vt__26TOContainerAncientItemNone[];

void *__dt__26TOContainerAncientItemNoneFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__26TOContainerAncientItemNone;
        __dt__26TOContainerAncientItemRareFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
