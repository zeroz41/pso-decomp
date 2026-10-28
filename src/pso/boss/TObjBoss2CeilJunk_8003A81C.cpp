#include "types.h"
#include "pso/boss/TObjBoss2CeilJunk_8003A81C.h"
#include "pso/boss/TObjBoss2CeilJunk.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/misc/TLobby.h"

extern "C" {
extern void *lbl_804FE9C8[];
extern void *lbl_805D4BEC;
extern void *boss2_tunnel_instance;
void release_texture_list(void *);
void TLobby__sub_8001FE7C(void *, int);
void *TObjBoss2CeilJunk__ct(void *, void *, void *);
void *__nw__7TObjectFUl(int);
void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern BmlResourceDescriptor bm_obj_boss2_common_resource_descriptor;
extern const char lbl_80435E0C[];
extern const char lbl_80435E24[];

extern void *tl_05;

void *TObjBoss2CeilJunk::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xB8);
    if (o != NULL) {
        o = TObjBoss2CeilJunk__ct(o, tl_05, arg0);
    }
    return o;
}

    extern float lbl_805D4BE0;
    extern const float lbl_805D8258;
void TObjBoss2CeilJunk__sub_8003A868(void) { lbl_805D4BE0 = lbl_805D8258; }
void TLobby__sub_8003A874(void) {
    s32 i;
    for (i = 0; i < 7; i++) {
        lbl_804FE9C8[i] = 0;
    }
    release_texture_list(lbl_805D4BEC);
    TLobby__sub_8001FE7C(boss2_tunnel_instance, 1);
    boss2_tunnel_instance = 0;
}

void TLobby__sub_8003A8D0(void) {
    void *p = (void *)::operator new(0x440);
    if (p != NULL) {
        p = load_resource_from_descriptor(p, 5, &bm_obj_boss2_common_resource_descriptor, 0, 0, 0);
    }
    boss2_tunnel_instance = p;
    lbl_805D4BEC = *(void **)(*(u8 **)((u8 *)p + 0x42C) + 0x6C);
    if (TObjEneDD::check_v2_mode() != 0) {
        TLobby::load_texture_pvm_file(lbl_80435E0C, (s32)lbl_805D4BEC);
    } else {
        TLobby::load_texture_pvm_file(lbl_80435E24, (s32)lbl_805D4BEC);
    }
}

}

__declspec(section ".ctors") static void *const __sinit_TObjBoss2CeilJunk_8003A81C_cpp_ref = (void *)TObjBoss2CeilJunk__sub_8003A868;
