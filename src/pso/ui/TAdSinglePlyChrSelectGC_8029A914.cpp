#include "types.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_8029A914.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {
    extern unsigned char lbl_80465284[];
    extern unsigned char chr_select_ad_pic_2_texture_descriptor[];
u32 chr_select_ad_pic_texture;
void release_texture_list(void*);

void TAdSinglePlyChrSelectGC::free_global() {
    if ((u32) chr_select_ad_pic_texture != 0U) {
        release_texture_list((void*)chr_select_ad_pic_texture);
        chr_select_ad_pic_texture = 0U;
    }
}
void register_texture_f256_ad_pic_2(void) { (*(int *)&chr_select_ad_pic_texture) = (int)chr_select_ad_pic_2_texture_descriptor; TLobby__sub_8023E4B4((s32)lbl_80465284, (s32)chr_select_ad_pic_2_texture_descriptor); }

}
