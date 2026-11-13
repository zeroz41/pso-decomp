#include "types.h"
#include "pso/ui/charcreate/TCharaMaking_8028E790.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8028D5D4.h"
#include "pso/camera/CreationCamera.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/ui/charcreate/TObjCMMainMenu.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/system/save/TSaveChCr.h"
#include <dolphin/mtx.h>

extern "C" {
void *__nw__7TObjectFUl(int);
void *TCMCharacter__ct(void *arg0, void *arg1);
extern void *__vt__12TCharaMaking[];
extern s32 creation_main_menu_obj;
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern Vec TObjLight__scene_light_state;
u8 * __dt__7TObjectFv(void *, s16);
void __dl__7TObjectFPv(s32);
extern void *creation_player_character;
s32 is_active__23TAdSinglePlyChrSelectGCFv(void *self);
s32 is_state_3__14TObjCMMainMenuFv(s32);
s32 is_state_4__14TObjCMMainMenuFv(s32);

void TCharaMaking__sub_8028E790(void) {  }

extern s32 tl_03;
extern s32 creation_dressing_room_mode_flag;

void TCharaMaking::update_light_direction() {
    f32 temp_f31;
    TObjLight__scene_light_state.y = -1.0f * sin_table_lookup(m_1c);
    temp_f31 = cos_table_lookup(m_1c);
    TObjLight__scene_light_state.x = temp_f31 * sin_table_lookup(m_20);
    TObjLight__scene_light_state.z = temp_f31 * cos_table_lookup(m_20);
}

s32 TCharaMaking::update_main_menu(s32 arg0) {
    s32 var_r3;

    if (is_state_3__14TObjCMMainMenuFv(creation_main_menu_obj) != 0) {
        fn_8028D8F4();
        var_r3 = 0;
        if ((s32) creation_dressing_room_mode_flag == 1) {
            var_r3 = 1;
        }
        TSaveChCr::create((void *)var_r3);
        end_creation_view();
        queue_destruction__7TObjectFv((void *)arg0);
        return 1;
    }
    if (is_state_4__14TObjCMMainMenuFv(creation_main_menu_obj) != 0) {
        queue_destruction__7TObjectFv((void *)arg0);
        TChCrCharSelect::create((void *)tl_03);
        return 1;
    }
    return 0;
}

void TCharaMaking::run_task() {
    if (!is_active__23TAdSinglePlyChrSelectGCFv(this)) return;
    if (TCharaMaking::update_main_menu((s32)this)) return;
}

void *TCharaMaking::create(void *arg0, void *arg1) {
    creation_player_character = arg1;
    return new TCharaMaking((TObject *)arg0);
}

TCharaMaking *__dt__12TCharaMakingFv(TCharaMaking *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(void ***)((u8 *)arg0 + 0x18) = __vt__12TCharaMaking;
        creation_player_character = NULL;
        creation_main_menu_obj = 0;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

}

TCharaMaking::TCharaMaking(TObject *parent) : TObject(parent) {
    u32 motion;
    m_name = TCharaMaking__name;
    motion = ((u32)__nw__7TObjectFUl(0x10C));
    if (motion != 0U) {
        TCMCharacter__ct((void *)motion, this);
    }
    creation_main_menu_obj = (s32)TObjCMMainMenu::create(this);
    m_1c = 0x1555;
    m_20 = 0x9000;
    update_light_direction();
}
