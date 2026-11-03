#include "types.h"
#include "pso/misc/TButterfly.h"
#include "pso/misc/TButterfly.h"
#include "pso/misc/TButterfly_8017F364.h"
#include "pso/system/vector.h"
#include "pso/misc/TButterfly.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

void TLobby__sub_8001FE7C(void*, int);
void __ct__8TObjBaseFP7TObject(void *);
void *__nw__7TObjectFUl(int);

extern s32 __vt__10TButterfly[];
extern void *TButterfly__name;

}
TButterfly::TButterfly(TObject *arg1, void *arg2) : TObjBase(arg1) {
    *(void * *)&this->m_name = TButterfly__name;
    VecCopy((Vec *)((char *)this + 56), (const Vec *)((char *)arg2 + 12));
    copy_xyz((char *)this + 92, (void *)((char *)arg2 + 24));
    VecCopy((Vec *)((char *)this + 104), (const Vec *)((char *)arg2 + 36));
    this->init_motion();
}
extern "C" {

extern void *tl_05;

void *TButterfly__create(void *arg0) {
    void *o = (void *)new TButterfly((TObject *)tl_05, (void *)arg0);
    return o;
}

extern u32 butterfly_bml_resource;

void TButterfly::destroy_instance() {
    if ((u32) butterfly_bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)butterfly_bml_resource, 1);
        butterfly_bml_resource = 0U;
    }
}

extern BmlResourceDescriptor bm_o_abe_butterfly_resource_descriptor;
u8 *load_resource_from_descriptor(void *, s32, BmlResourceDescriptor *, s32, s32, s32);

void TButterfly::load_resources() {
    void *resource;
    u32 loaded;
    resource = ::operator new(0x440);
    loaded = (u32)resource;
    if (loaded != 0) {
        loaded = (u32)load_resource_from_descriptor(resource, 1, &bm_o_abe_butterfly_resource_descriptor, 0, 0, 0);
    }
    butterfly_bml_resource = loaded;
}

}
