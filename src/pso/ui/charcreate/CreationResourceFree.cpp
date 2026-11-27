#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include "pso/unk/SmallFontMetrics.h"
#include "pso/ui/UISprite.h"
#include "pso/camera/CreationCamera.h"
#include "pso/network/TLobby.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/charcreate/TObjCMMainMenu.h"
#include "pso/ui/charcreate/CreationResourceFree.h"
#include "pso/ui/window/SmallFontText.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"
#include "pso/audio/MusicControl.h"
#include "pso/audio/SoundPlayback.h"


void free_all_resources() { free_creation_sprites(); stop_audio_streams(); delete (BmlResource *)creation_menu_main_obj; creation_menu_main_obj = 0; TAdSinglePlyChrSelectGC::free_global(); TAdSinglePlyChrSelectGC::free_texture_f256_backtext(); end_creation_view(); TCameraCtrl::reset(); TCameraCtrl::reset_default_view(); TWindowCtrlMain::free_all_windows(); free_keyboard_resources(); free_ending_callback(); free_keyboard_soft_resources(); refresh_render_state(); }
