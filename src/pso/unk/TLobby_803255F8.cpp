#include "types.h"
#include "pso/unk/TLobby_803255F8.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#pragma readonly_strings on


extern "C" {
    u8 *load_gvm_texture_file(s32 arg0);
extern u32 inazuma_texture_list;
s32 release_texture_list(void*);

void TLobby::free_char_select_singleton() {
    if ((u32) inazuma_texture_list != 0U) {
        release_texture_list((void*)inazuma_texture_list);
        TAdSinglePlyChrSelectGC::safe_free(inazuma_texture_list);
        inazuma_texture_list = 0U;
    }
}
}
void load_f512_inazuma(void) { (*(int *)&inazuma_texture_list) = (int)load_gvm_texture_file((s32)(unsigned char *)"f512_inazuma.gvm"); }
