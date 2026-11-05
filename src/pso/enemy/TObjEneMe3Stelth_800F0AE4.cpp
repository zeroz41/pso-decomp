#include "types.h"
#include "pso/enemy/TObjEneMe3Stelth.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

#pragma readonly_strings on

extern "C" {
u8 *load_gvm_texture_file(s32 arg0);
extern u32 blob_shadow_texture_list;
s32 release_texture_list(void*);

void TObjEneMe3Stelth::destroy_resources() {
    if ((u32) blob_shadow_texture_list != 0U) {
        release_texture_list((void*)blob_shadow_texture_list);
        TAdSinglePlyChrSelectGC::safe_free(blob_shadow_texture_list);
        blob_shadow_texture_list = 0U;
    }
}
}
void load_ha_u032_kage(void) { (*(int *)&blob_shadow_texture_list) = (int)load_gvm_texture_file((s32)(unsigned char *)"ha_u032_kage.gvm"); }
