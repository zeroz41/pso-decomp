#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

void TLobby__sub_8001FE7C(void*, int);
s32 release_texture_list(void*);

extern u32 green_door_bml_resource;
extern u32 green_door_texture_handle;

void TLobby::free_shared_objects() {
    if ((u32) green_door_texture_handle != 0U) {
        release_texture_list((void*)green_door_texture_handle);
        TAdSinglePlyChrSelectGC::safe_free(green_door_texture_handle);
        green_door_texture_handle = 0U;
    }
    if ((u32) green_door_bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)green_door_bml_resource, 1);
        green_door_bml_resource = 0U;
    }
}

}
