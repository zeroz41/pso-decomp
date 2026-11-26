#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/unk/text_8028A714.h"
#include "pso/unk/text_8028A820.h"


u8 *get_green_door_motion(s32 index) {
    if (green_door_bml_resource != NULL) {
        return (u8 *)get_bml_motion(green_door_bml_resource, index);
    }
    return NULL;
}
NJS_TEXLIST *get_green_door_texlist(s32 index) {
    if (green_door_bml_resource != NULL) {
        return get_bml_texlist((BmlResource *)green_door_bml_resource, index);
    }
    return NULL;
}
u8 *get_green_door_model(s32 index) {
    if (green_door_bml_resource != NULL) {
        return (u8 *)get_bml_model((BmlResource *)green_door_bml_resource, index);
    }
    return NULL;
}
