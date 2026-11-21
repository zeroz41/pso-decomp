#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

s32 release_texture_list(void*);

extern saddr lbl_805D4B50;
extern uaddr dragon_common_texture_list;

void TLobby::free_char_select() {
    if ((u32) dragon_common_texture_list != 0U) {
        release_texture_list((void*)dragon_common_texture_list);
        TAdSinglePlyChrSelectGC::safe_free(dragon_common_texture_list);
        dragon_common_texture_list = 0U;
    }
    delete (BmlResource *)lbl_805D4B50;
    lbl_805D4B50 = 0;
}

}
