#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TPlyCharData.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/keyboard/TKeyBoardControl_80131C58.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/unk/TLobby_80227A2C.h"
#include "pso/ui/charcreate/TObjCMMainMenu_8028D9A8.h"
#include "pso/ui/charcreate/TObjCMMainMenu_8028EA88.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8028D5D4.h"
#include "pso/ui/UISprite.h"
#include "pso/camera/CreationCamera.h"
#include "pso/ui/charcreate/TObjCMMainMenu.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/unk/TLobby.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#pragma readonly_strings on


CharacterCreationEffects lbl_8051C070;
char character_creation_name_buffer[0x18];
CharacterAppearanceFields character_creation_visual_record;
extern "C" {
}
BmlResource *creation_menu_main_obj;
int creation_dressing_room_mode_flag;

void init_creation_menu_scene(void) {
    void *p;
    init_menu_scene_lights(&default_scene_light_config, 4);
    TCameraCtrl::reset_view_state();
    TCameraCtrl::init_default_view();
    new TCameraCtrl(tl_camera);
    TCameraCtrl::select_active_controller(8);
    begin_creation_view();
    register_texture_f256_ad_pic_2();
    register_texture_f256_backtext();
    TLobby::update_keyboard_menu();
    TLobby::set_ending_callback();
    TKeyBoardControl__sub_80131F60();
    TWindowCtrlMain::reset_all((void*)1);
    p = (void *)new TWindowCtrlMain();
    p = new BmlResource(1, (BmlResourceDescriptor *)&creation_menu_resource_descriptor, 0, 0, NULL);
    creation_menu_main_obj = (BmlResource *)p;
    if (p != NULL) {
        fn_80291178();
        fn_8028D940();
        load_floor_sound_bank(0);
        play_area_music("CHARA.adx");
        if (TObjCMMainMenu::get_current_char_flag() != 0) {
            TObjCMMainMenu__sub_8028EC34();
            TObjCMMainMenu__sub_8028EC24();
            TObjCMMainMenu__sub_8028D9F8();
            TChCrCharSelect::init_and_create(tl_03);
            TObjCMMainMenu::create_fade_effect((void *)0xF, (void *)1);
        } else {
            TObjCMMainMenu__sub_8028EC18();
            TObjCMMainMenu::select_char_menu();
            TObjCMMainMenu__sub_8028D9F8();
            TCharaMaking::create(tl_03, (void *)&TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)->m_disp_part2);
            TObjCMMainMenu::create_fade_effect((void *)0xF, (void *)1);
        }
    }
}

s32 TObjCMMainMenu__sub_8028EBCC(TObjCMMainMenu *menu) {
    return TObjCMMainMenu::menu_entries[menu->entries[menu->selected_entry]].kind;
}

s32 TObjCMMainMenu::is_state_4() {
    return TObjCMMainMenu::state == 4;
}

s32 TObjCMMainMenu::is_state_3() {
    return TObjCMMainMenu::state == 3;
}

void TObjCMMainMenu__sub_8028EC18(void) { creation_dressing_room_mode_flag = 1; }

void TObjCMMainMenu__sub_8028EC24(void) {
    character_creation_name_buffer[0] = 0;
}

void TObjCMMainMenu__sub_8028EC34(void) { creation_dressing_room_mode_flag = 0; }
