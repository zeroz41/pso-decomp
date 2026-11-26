#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include "pso/unk/TLobby_800FC3CC.h"
#include "pso/ui/UISprite.h"
#include "pso/camera/CreationCamera.h"
#include "pso/network/TLobby.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/charcreate/TObjCMMainMenu_8028EA88.h"


void TLobby::free_all_resources() { fn_80291138(); TLobby::stop_audio_streams(); delete (BmlResource *)creation_menu_main_obj; creation_menu_main_obj = 0; TAdSinglePlyChrSelectGC::free_global(); TAdSinglePlyChrSelectGC::free_singleton_805D65C0(); end_creation_view(); TCameraCtrl::reset(); TCameraCtrl::reset_default_view(); TWindowCtrlMain::free_all_windows(); free_keyboard_resources(); TLobby::free_ending_callback(); TLobby::free_keyboard_soft_resources(); TLobby::refresh_render_state(); }
