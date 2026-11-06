#include "types.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_802F2070.h"
#include "pso/unk/text_802F0F04.h"
#include "pso/object/warp/TObjAreaWarpForest.h"

extern "C" {

void TObjAreaWarpForest__ct(void *);
void __dl__7TObjectFPv(void *);
void *__dt__18TObjAreaWarpForestFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

void TObjAreaWarpForest::render_if_active() { if (*(int*)((char*)this + 0xdc) != 0) { TObjAreaWarpForest::render(); } }

void TObjAreaWarpForest__sub_802F0F30(TObjAreaWarpForest *area_warp_forest) {
    if (TObjBoss2Tunnel__sub_802F2070() != 0) {
        *(s32 *)((s8 *)area_warp_forest + 0xDC) = 1;
    }
    area_warp_forest->TObjAreaWarpForest::run_task();
}

extern s32 lbl_804E48D8[];

void *__dt__13TUnk_804E48D8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804E48D8;
        __dt__18TObjAreaWarpForestFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *TObjAreaWarpForest::init(void *, void *) {
    TObjAreaWarpForest__ct(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804E48D8;
    *(u32 *)((s8 *)this + 0xDC) = 0;
    return this;
}

extern void *tl_05;

void *TObjAreaWarpForest::alloc_and_init() {
    void *o = __nw__7TObjectFUl(0xE0);
    if (o != NULL) {
        o = ((TObjAreaWarpForest *)o)->init(tl_05, this);
    }
    return o;
}

}
