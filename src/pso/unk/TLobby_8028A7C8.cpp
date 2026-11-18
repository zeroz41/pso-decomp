#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

void free_bin_model_request(void*, int);
s32 release_texture_list(void*);

void *green_door_bml_resource;
void *green_door_texture_handle;

void TLobby::free_shared_objects() {
    if (green_door_texture_handle != NULL) {
        release_texture_list(green_door_texture_handle);
        TAdSinglePlyChrSelectGC::safe_free((u32)green_door_texture_handle);
        green_door_texture_handle = NULL;
    }
    if (green_door_bml_resource != NULL) {
        free_bin_model_request(green_door_bml_resource, 1);
        green_door_bml_resource = NULL;
    }
}

}
