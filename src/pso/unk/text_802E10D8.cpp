#include "types.h"
#include "pso/unk/text_802E10D8.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/system/BmlResourceLoader.h"


extern "C" {
extern s32 TAdMultiPlyChrSelectGC__resource_bundle;
void fn_802E10D8(void) {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &creation_menu_resource_descriptor, 0, 0, 0));
    }
    TAdMultiPlyChrSelectGC__resource_bundle = var_r0;
}

}
