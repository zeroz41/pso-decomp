#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/object/door/GreenDoorResource.h"
#include "pso/system/memory.h"
#include "pso/system/BmlResource.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/network/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/map/FloorArea.h"
#include "pso/object/base/TObjCharaHelpers.h"

u8 *get_green_door_motion(s32 index) {
    if (green_door_bml_resource != NULL) {
        return (u8 *)get_bml_motion(green_door_bml_resource, index);
    }
    return NULL;
}
NJS_TEXLIST *get_green_door_texlist(s32 index) {
    if (green_door_bml_resource != NULL) {
        return get_bml_texlist(green_door_bml_resource, index);
    }
    return NULL;
}
u8 *get_green_door_model(s32 index) {
    if (green_door_bml_resource != NULL) {
        return (u8 *)get_bml_model(green_door_bml_resource, index);
    }
    return NULL;
}

BmlResource *green_door_bml_resource;
NJS_TEXLIST *green_door_texture_handle;

void free_green_door_resources() {
    if (green_door_texture_handle != NULL) {
        release_texture_list(green_door_texture_handle);
        safe_free(green_door_texture_handle);
        green_door_texture_handle = NULL;
    }
    if (green_door_bml_resource != NULL) {
        delete green_door_bml_resource;
        green_door_bml_resource = NULL;
    }
}

extern BmlResourceDescriptor bm_obj_door_ruins_resource_descriptor;
extern BmlResourceDescriptor bm_obj_door_space_resource_descriptor;
void load_green_door_resources(void) {
    BmlResource *resource;
    green_door_bml_resource = 0;
    green_door_texture_handle = 0;
    switch (get_current_floor_area()) {
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        resource = new BmlResource(5, (BmlResourceDescriptor *)&bm_obj_door_ruins_resource_descriptor, 0, 0, NULL);
        green_door_bml_resource = resource;
        green_door_texture_handle = LoadPvmFileTls("obj_door_ruins_green.gvm");
        break;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        resource = new BmlResource(5, (BmlResourceDescriptor *)&bm_obj_door_space_resource_descriptor, 0, 0, NULL);
        green_door_bml_resource = resource;
        green_door_texture_handle = LoadPvmFileTls("obj_door_space_green.gvm");
        break;
    }
}
