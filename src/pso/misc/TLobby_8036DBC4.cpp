#include "types.h"
#include "pso/misc/TLobby_8036DBC4.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TLanguage.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {
u8 *load_gvm_texture_file(s32 arg0);
void set_global_param__8TObjFishFl();
extern u8 lbl_8047AD08[];
extern u8 lbl_8047AD14[];
extern u8 lbl_8047AD20[];
extern u32 TBGMulti__textures;
extern s32 split_screen_hud_animation_frame;
s32 release_texture_list(void*);

void TLobby::free_singleton_805D7018() {
    if ((u32) TBGMulti__textures != 0U) {
        release_texture_list((void*)TBGMulti__textures);
        TAdSinglePlyChrSelectGC::safe_free(TBGMulti__textures);
        TBGMulti__textures = 0U;
    }
}
void TBGMulti__ct(void) {
    s32 sp8[4];
    if (TCameraCtrl::get_camera_id() == 3) {
        sp8[0] = TLobby::tmp_buf_use_req((const char *)lbl_8047AD08);
        TLanguage::draw_string(lbl_8047AD14, sp8, 0x4D);
        TLobby::tmp_buf_release((const char *)lbl_8047AD08);
        (*(s32 *)&TBGMulti__textures) = (s32)load_gvm_texture_file((s32)lbl_8047AD20);
        set_global_param__8TObjFishFl();
        TLanguage::set_entry_index(0, 0x4D);
    }
    split_screen_hud_animation_frame = 0x384;
}

}
