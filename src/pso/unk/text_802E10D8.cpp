#include "types.h"
#include "pso/unk/text_802E10D8.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"


extern s32 TAdMultiPlyChrSelectGC__resource_bundle;
void fn_802E10D8(void) {
    saddr temp_r3;
    s32 var_r0;
    var_r0 = (saddr)new BmlResource(1, (BmlResourceDescriptor *)&creation_menu_resource_descriptor, 0, 0, NULL);
    TAdMultiPlyChrSelectGC__resource_bundle = var_r0;
}

