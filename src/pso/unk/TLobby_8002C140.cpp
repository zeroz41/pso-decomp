#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

s32 free_bin_model_request(s32, s32);
s32 release_texture_list(void*);

extern s32 lbl_805D4B50;
extern u32 dragon_common_texture_list;

void TLobby::free_char_select() {
    if ((u32) dragon_common_texture_list != 0U) {
        release_texture_list((void*)dragon_common_texture_list);
        TAdSinglePlyChrSelectGC::safe_free(dragon_common_texture_list);
        dragon_common_texture_list = 0U;
    }
    free_bin_model_request(lbl_805D4B50, 1);
    lbl_805D4B50 = 0;
}

}
