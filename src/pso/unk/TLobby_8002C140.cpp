#include "pso/system/BmlResource.h"
#include "pso/boss/dragon/ObjBoss1CommonResource.h"
#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

s32 release_texture_list(void*);

extern uaddr dragon_common_texture_list;

void TLobby::free_char_select() {
    if ((u32) dragon_common_texture_list != 0U) {
        release_texture_list((void*)dragon_common_texture_list);
        TAdSinglePlyChrSelectGC::safe_free(dragon_common_texture_list);
        dragon_common_texture_list = 0U;
    }
    delete dragon_ground_resource;
    dragon_ground_resource = 0;
}

}
