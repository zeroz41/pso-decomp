#include "types.h"
#include "pso/unk/text_802E10D8.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"


extern s32 multi_ply_chr_select_resource_bundle;
void fn_802E10D8(void) {
    multi_ply_chr_select_resource_bundle = (saddr)new BmlResource(1, (BmlResourceDescriptor *)&creation_menu_resource_descriptor, 0, 0, NULL);
}

