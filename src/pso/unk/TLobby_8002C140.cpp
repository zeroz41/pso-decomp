#include "pso/system/memory.h"
#include "pso/system/BmlResource.h"
#include "pso/boss/dragon/ObjBoss1CommonResource.h"
#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

s32 release_texture_list(void*);

void TLobby::free_char_select() {
    if (dragon_common_texture_list != NULL) {
        release_texture_list(dragon_common_texture_list);
        safe_free(dragon_common_texture_list);
        dragon_common_texture_list = NULL;
    }
    delete dragon_ground_resource;
    dragon_ground_resource = 0;
}

}
