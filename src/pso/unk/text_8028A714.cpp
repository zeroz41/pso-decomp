#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/unk/text_8028A714.h"
#include "pso/unk/text_8028A820.h"


u8 *fn_8028A714(s32 index) {
    if (green_door_bml_resource != NULL) {
        return (u8 *)get_bml_motion(green_door_bml_resource, index);
    }
    return NULL;
}
NJS_TEXLIST *fn_8028A750(s32 index) {
    if (green_door_bml_resource != NULL) {
        return get_bml_texlist((BmlResource *)green_door_bml_resource, index);
    }
    return NULL;
}
u8 *fn_8028A78C(s32 index) {
    if (green_door_bml_resource != NULL) {
        return (u8 *)get_bml_model((BmlResource *)green_door_bml_resource, index);
    }
    return NULL;
}
