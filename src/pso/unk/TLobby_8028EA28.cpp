#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_80131C58.h"
#include "pso/unk/TLobby_800FC3CC.h"
#include "pso/unk/text_802910EC.h"
#include "pso/camera/CreationCamera.h"
#include "pso/unk/TLobby.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {

int free_bin_model_request(void*, void*);
void reset__11TCameraCtrlFv(void);

    extern int creation_menu_main_obj;
void TLobby::free_all_resources() { fn_80291138(); TLobby::stop_audio_streams(); free_bin_model_request((void*)creation_menu_main_obj, (void*)1); creation_menu_main_obj = 0; TAdSinglePlyChrSelectGC::free_global(); TAdSinglePlyChrSelectGC::free_singleton_805D65C0(); end_creation_view(); reset__11TCameraCtrlFv(); TCameraCtrl::reset_default_view(); TWindowCtrlMain::free_all_windows(); TKeyBoardControl__sub_80131F5C(); TLobby__sub_800FC3CC(); TLobby::free_keyboard_soft_resources(); TLobby::refresh_render_state(); }

}
