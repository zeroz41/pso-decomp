#include "types.h"
#include "pso/TPlyCharData.h"
#include "pso/misc/TWindowCtrlMain.h"
#include "pso/misc/TKeyBoardControl_80131C58.h"
#include "pso/misc/TLoadCtrl_80227390.h"
#include "pso/misc/TLobby_80227A2C.h"
#include "pso/object/TObjCMMainMenu_8028D9A8.h"
#include "pso/object/TObjCMMainMenu_8028EA88.h"
#include "pso/ui/TAdBackTxtGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_8029A914.h"
#include "pso/unk/text_8028D8B8.h"
#include "pso/unk/text_802910EC.h"
#include "pso/camera/CreationCamera.h"
#include "pso/object/TObjCMMainMenu.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TCharaMaking.h"
#include "pso/misc/TLobby.h"


struct RecoveredGlobal_8028EC24_lbl_8051C07C {
    s8 value;
    u8 remaining[0x17];
};

struct RecoveredGlobal_8028EBCC_TObjCMMainMenu__data_804DB9C8 {
    s32 value;
    u8 remaining[0x9C];
};

extern RecoveredGlobal_8028EC24_lbl_8051C07C character_creation_name_buffer;
extern RecoveredGlobal_8028EBCC_TObjCMMainMenu__data_804DB9C8 TObjCMMainMenu__data_804DB9C8;
extern "C" {
void *load_resource_from_descriptor(void *, s32, s32 *, s32, s32, s32);
u8 *TCameraCtrl__ct(u8 *arg0, void *parent);
s32 init_menu_scene_lights(s32 *, s32);
void *__nw__7TObjectFUl(s32);
s32 init_and_create__15TChCrCharSelectFv(s32);
}
extern s32 lbl_80451290[];
extern s32 default_scene_light_config[];
extern s32 creation_menu_resource_descriptor[];
extern s32 tl_camera;
extern s32 tl_03;
extern void *creation_menu_main_obj;
extern s32 TObjCMMainMenu__data_805D659C;

typedef char RecoveredGlobal_8028EBCC_TObjCMMainMenu__data_804DB9C8_size[sizeof(RecoveredGlobal_8028EBCC_TObjCMMainMenu__data_804DB9C8) == 0xA0 ? 1 : -1];

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
        p = load_resource_from_descriptor(p, 1, creation_menu_resource_descriptor, 0, 0, 0);
    }
    creation_menu_main_obj = p;
    if (p != NULL) {
        fn_80291178();
        fn_8028D940();
        load_floor_sound_bank(0);
        play_area_music((char *)lbl_80451290);
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

s32 TObjCMMainMenu__sub_8028EBCC(u8 *arg0) {
    return *(s32 *)((s8 *)((u8 *)&TObjCMMainMenu__data_804DB9C8.value + (*(s32 *)((s8 *)(*(s32 *)((s8 *)arg0 + 0x24) + (*(s32 *)((s8 *)arg0 + 0x2C) * 4)) + 0) * 0x10)) + 0);
}

u8 TObjCMMainMenu::is_state_4() {
    return (u8) (TObjCMMainMenu__data_805D659C == 4);
}

u8 TObjCMMainMenu::is_state_3() {
    return (u8) (TObjCMMainMenu__data_805D659C == 3);
}

    extern int creation_dressing_room_mode_flag;
void TObjCMMainMenu__sub_8028EC18(void) { creation_dressing_room_mode_flag = 1; }

typedef char RecoveredGlobal_8028EC24_lbl_8051C07C_size[sizeof(RecoveredGlobal_8028EC24_lbl_8051C07C) == 0x18 ? 1 : -1];
void TObjCMMainMenu__sub_8028EC24(void) {
    character_creation_name_buffer.value = 0;
}

void TObjCMMainMenu__sub_8028EC34(void) { creation_dressing_room_mode_flag = 0; }
