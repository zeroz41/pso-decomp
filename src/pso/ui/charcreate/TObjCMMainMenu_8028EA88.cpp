#include "types.h"
#include "pso/player/TPlyCharData.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/keyboard/TKeyBoardControl_80131C58.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/unk/TLobby_80227A2C.h"
#include "pso/ui/charcreate/TObjCMMainMenu_8028D9A8.h"
#include "pso/ui/charcreate/TObjCMMainMenu_8028EA88.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8029A914.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8028D5D4.h"
#include "pso/unk/text_802910EC.h"
#include "pso/camera/CreationCamera.h"
#include "pso/ui/charcreate/TObjCMMainMenu.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/unk/TLobby.h"

#pragma readonly_strings on


struct CreationMenuEntry {
    s32 kind;
    void (TObjCMMainMenu::*select)(void *);
};

extern char character_creation_name_buffer[0x18];
extern CreationMenuEntry TObjCMMainMenu__data_804DB9C8[10];
extern "C" {
u8 *TCameraCtrl__ct(u8 *arg0, void *parent);
s32 init_menu_scene_lights(s32 *, s32);
void *__nw__7TObjectFUl(s32);
s32 init_and_create__15TChCrCharSelectFv(s32);
}
extern s32 default_scene_light_config[];
extern s32 tl_camera;
extern s32 tl_03;
extern void *creation_menu_main_obj;
extern s32 TObjCMMainMenu__data_805D659C;

void init_creation_menu_scene(void) {
    void *p;
    init_menu_scene_lights(default_scene_light_config, 4);
    TCameraCtrl::reset_view_state();
    TCameraCtrl::init_default_view();
    p = __nw__7TObjectFUl(0x1D4);
    if (p != NULL) {
        TCameraCtrl__ct((u8 *)p, (void *)tl_camera);
    }
    TCameraCtrl::select_active_controller(8);
    begin_creation_view();
    register_texture_f256_ad_pic_2();
    register_texture_f256_backtext();
    TLobby::update_keyboard_menu();
    TLobby::set_ending_callback();
    TKeyBoardControl__sub_80131F60();
    TWindowCtrlMain::reset_all((void*)1);
    p = (void *)new TWindowCtrlMain();
    p = ::operator new(0x440);
    if (p != NULL) {
        p = load_resource_from_descriptor(p, 1, &creation_menu_resource_descriptor, 0, 0, 0);
    }
    creation_menu_main_obj = p;
    if (p != NULL) {
        fn_80291178();
        fn_8028D940();
        load_floor_sound_bank(0);
        play_area_music("CHARA.adx");
        if (TObjCMMainMenu::get_current_char_flag() != 0) {
            TObjCMMainMenu__sub_8028EC34();
            TObjCMMainMenu__sub_8028EC24();
            TObjCMMainMenu__sub_8028D9F8();
            init_and_create__15TChCrCharSelectFv(tl_03);
            TObjCMMainMenu::create_fade_effect((void *)0xF, (void *)1);
        } else {
            TObjCMMainMenu__sub_8028EC18();
            TObjCMMainMenu::select_char_menu();
            TObjCMMainMenu__sub_8028D9F8();
            TCharaMaking::create((void *)tl_03, (void *)&get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF)->m_disp_data.m_disp_part2);
            TObjCMMainMenu::create_fade_effect((void *)0xF, (void *)1);
        }
    }
}

s32 TObjCMMainMenu__sub_8028EBCC(TObjCMMainMenu *menu) {
    return TObjCMMainMenu__data_804DB9C8[menu->entries[menu->selected_entry]].kind;
}

u8 TObjCMMainMenu::is_state_4() {
    return (u8) (TObjCMMainMenu__data_805D659C == 4);
}

u8 TObjCMMainMenu::is_state_3() {
    return (u8) (TObjCMMainMenu__data_805D659C == 3);
}

    extern int creation_dressing_room_mode_flag;
void TObjCMMainMenu__sub_8028EC18(void) { creation_dressing_room_mode_flag = 1; }

void TObjCMMainMenu__sub_8028EC24(void) {
    character_creation_name_buffer[0] = 0;
}

void TObjCMMainMenu__sub_8028EC34(void) { creation_dressing_room_mode_flag = 0; }
