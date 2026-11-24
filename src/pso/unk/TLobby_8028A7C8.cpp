#include "pso/system/memory.h"
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_8028A820.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"


BmlResource *green_door_bml_resource;
NJS_TEXLIST *green_door_texture_handle;

void TLobby::free_shared_objects() {
    if (green_door_texture_handle != NULL) {
        release_texture_list(green_door_texture_handle);
        safe_free(green_door_texture_handle);
        green_door_texture_handle = NULL;
    }
    if (green_door_bml_resource != NULL) {
        delete (BmlResource *)green_door_bml_resource;
        green_door_bml_resource = NULL;
    }
}
