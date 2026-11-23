#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/unk/text_8028A820.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_80011014.h"
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
        green_door_texture_handle = load_gvm_texture_file("obj_door_ruins_green.gvm");
        break;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        resource = new BmlResource(5, (BmlResourceDescriptor *)&bm_obj_door_space_resource_descriptor, 0, 0, NULL);
        green_door_bml_resource = resource;
        green_door_texture_handle = load_gvm_texture_file("obj_door_space_green.gvm");
        break;
    }
}
