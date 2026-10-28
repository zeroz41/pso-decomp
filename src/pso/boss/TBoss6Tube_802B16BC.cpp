#include "types.h"
#include "pso/boss/TBoss6Tube_802B15F4.h"
#include "pso/boss/TBoss6Tube.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {
s32 load_resource_from_descriptor(s32, int, void *, int, int, int);
u8 *load_gvm_texture_file(s32 arg0);
extern u8 lbl_80470A68[];
extern u8 boss06_tube_dat_resource_descriptor[];
extern u32 boss6_tube_bml_resource;
extern u32 boss6_tube_texture_list;
void TLobby__sub_8001FE7C(void*, int);
s32 release_texture_list(void*);
void *__nw__7TObjectFUl(int);

void *TBoss6Tube::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x30);
    if (o != NULL) {
        o = TBoss6Tube__ct((TBoss6Tube *)((u8 *)o), (u8 *)arg0);
    }
    return o;
}

void TBoss6Tube::free_resources() {
    if ((u32) boss6_tube_bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)boss6_tube_bml_resource, 1);
        boss6_tube_bml_resource = 0U;
    }
    if ((u32) boss6_tube_texture_list != 0U) {
        release_texture_list((void*)boss6_tube_texture_list);
        TAdSinglePlyChrSelectGC::safe_free(boss6_tube_texture_list);
        boss6_tube_texture_list = 0U;
    }
    TBoss6Tube::reset_state();
}
void TBoss6Tube::load_resources() {
    s32 r;
    TBoss6Tube::reset_state();
    r = (int)::operator new(0x440);
    if (r != 0) {
        r = load_resource_from_descriptor(r, 5, boss06_tube_dat_resource_descriptor, 0, 0, 0);
    }
    boss6_tube_bml_resource = r;
    boss6_tube_texture_list = (u32)load_gvm_texture_file((s32)lbl_80470A68);
    if (boss6_tube_bml_resource != 0 && boss6_tube_texture_list != 0) {
        return;
    }
}

}
