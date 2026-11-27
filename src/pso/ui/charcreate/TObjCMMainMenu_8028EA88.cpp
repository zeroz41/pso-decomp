#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TPlyCharData.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/keyboard/KeyboardKeyState.h"
#include "pso/audio/MusicControl.h"
#include "pso/audio/SoundPlayback.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8028D5D4.h"
#include "pso/ui/UISprite.h"
#include "pso/camera/CreationCamera.h"
#include "pso/ui/charcreate/TObjCMMainMenu.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/ui/charcreate/TChCrEffFade.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/network/TLobby.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/window/SmallFontText.h"
#include "pso/ui/keyboard/KeyBoardMenu.h"

#pragma readonly_strings on


CharacterCreationEffects character_creation_effects;
char character_creation_name_buffer[0x18];
CharacterAppearanceFields character_creation_visual_record;
BmlResource *creation_menu_main_obj;
int creation_dressing_room_mode_flag;

void init_creation_menu_scene(void) {
    BmlResource *p;
    init_menu_scene_lights(&default_scene_light_config, 4);
    TCameraCtrl::reset_view_state();
    TCameraCtrl::init_default_view();
    new TCameraCtrl(tl_camera);
    TCameraCtrl::select_active_controller(8);
    begin_creation_view();
    register_texture_f256_ad_pic_2();
    register_texture_f256_backtext();
    update_keyboard_menu();
    set_ending_callback();
    load_keyboard_resources();
    TWindowCtrlMain::reset_all((void*)1);
    new TWindowCtrlMain();
    p = new BmlResource(1, (BmlResourceDescriptor *)&creation_menu_resource_descriptor, 0, 0, NULL);
    creation_menu_main_obj = p;
    if (p != NULL) {
        load_creation_sprites();
        create_character_creation_effects();
        load_floor_sound_bank(0);
        play_area_music("CHARA.adx");
        if (get_current_char_flag() != 0) {
            disable_dressing_room_mode();
            clear_creation_name_buffer();
            invalidate_creation_visual_record();
            TChCrCharSelect::init_and_create(tl_03);
            create_fade_effect(0xF, 1);
        } else {
            enable_dressing_room_mode();
            select_char_menu();
            invalidate_creation_visual_record();
            TCharaMaking::create(tl_03, &TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)->m_disp_part2);
            create_fade_effect(0xF, 1);
        }
    }
}

s32 TObjCMMainMenu::get_selected_menu_entry_kind() {
    return menu_entries[entries[selected_entry]].kind;
}

s32 TObjCMMainMenu::is_state_4() {
    return TObjCMMainMenu::state == 4;
}

s32 TObjCMMainMenu::is_state_3() {
    return TObjCMMainMenu::state == 3;
}

void enable_dressing_room_mode(void) { creation_dressing_room_mode_flag = 1; }

void clear_creation_name_buffer(void) {
    character_creation_name_buffer[0] = 0;
}

void disable_dressing_room_mode(void) { creation_dressing_room_mode_flag = 0; }
