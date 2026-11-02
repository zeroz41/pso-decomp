#include "types.h"
#include "pso/misc/TCharaMaking_8028E790.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/unk/text_8028D8B8.h"
#include "pso/camera/CreationCamera.h"
#include "pso/misc/TCharaMaking.h"
#include "pso/TChCrCharSelect.h"
#include "pso/TSaveChCr.h"

struct RecoveredGlobal_8028E9A4___vt__12TCharaMaking { s32 value; u8 remaining[0x18]; };
typedef char RecoveredGlobal_8028E9A4___vt__12TCharaMaking_size[sizeof(RecoveredGlobal_8028E9A4___vt__12TCharaMaking) == 0x1C ? 1 : -1];

struct RecoveredGlobal_8028E794_TObjLight__data_80506320 {
    s32 value;
    u8 remaining[0x4C];
};

struct RecoveredGlobal_8028E940___vt__12TCharaMaking {
    s32 value;
    u8 remaining[0x18];
};

extern "C" {
void *__nw__7TObjectFUl(int);
s32 __ct__7TObjectFP7TObject(void *, void *);
void *TCMCharacter__ct(void *arg0, void *arg1);
s32 create__14TObjCMMainMenuFv(void *);
extern RecoveredGlobal_8028E9A4___vt__12TCharaMaking __vt__12TCharaMaking;
extern s32 creation_main_menu_obj;
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
extern RecoveredGlobal_8028E794_TObjLight__data_80506320 TObjLight__scene_light_state;
u8 * __dt__7TObjectFv(void *, s16);
void __dl__7TObjectFPv(s32);
extern void *creation_player_character;
s32 is_active__23TAdSinglePlyChrSelectGCFv(void *self);
s32 is_state_3__14TObjCMMainMenuFv(s32);
s32 is_state_4__14TObjCMMainMenuFv(s32);

void TCharaMaking__sub_8028E790(void) {  }

extern s32 tl_03;
extern s32 creation_dressing_room_mode_flag;

typedef char RecoveredGlobal_8028E794_TObjLight__data_80506320_size[sizeof(RecoveredGlobal_8028E794_TObjLight__data_80506320) == 0x50 ? 1 : -1];
void TCharaMaking::update_light_direction() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f31;
    *(f32 *)((s8 *)&TObjLight__scene_light_state.value + 4) = (f32) (-1.0f * sin_table_lookup(*(s32 *)((s8 *)arg0 + 0x1C)));
    temp_f31 = cos_table_lookup(*(s32 *)((s8 *)arg0 + 0x1C));
    *(f32 *)((s8 *)&TObjLight__scene_light_state.value + 0) = (f32) (temp_f31 * sin_table_lookup(this->m_20));
    *(f32 *)((s8 *)&TObjLight__scene_light_state.value + 8) = (f32) (temp_f31 * cos_table_lookup(this->m_20));
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
    void *o;
    creation_player_character = arg1;
    o = __nw__7TObjectFUl(0x24);
    if (o != NULL) {
        o = TCharaMaking__ct((u8 *)o, (s32)arg0);
    }
    return o;
}

typedef char RecoveredGlobal_8028E940___vt__12TCharaMaking_size[sizeof(RecoveredGlobal_8028E940___vt__12TCharaMaking) == 0x1C ? 1 : -1];
u8 *__dt__12TCharaMakingFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8028E940___vt__12TCharaMaking *)&__vt__12TCharaMaking).value;
        (*(s32 *)&creation_player_character) = 0;
        creation_main_menu_obj = 0;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

u8 *TCharaMaking__ct(u8 *arg0, s32 arg1) {
    u32 motion;
    __ct__7TObjectFP7TObject((void *)arg0, (void *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &__vt__12TCharaMaking.value;
    ((TCharaMaking *)arg0)->m_name = lbl_805D3B6C;
    motion = ((u32)__nw__7TObjectFUl(0x10C));
    if (motion != 0U) {
        TCMCharacter__ct((void *)motion, (arg0));
    }
    creation_main_menu_obj = create__14TObjCMMainMenuFv(arg0);
    *(s32 *)((s8 *)arg0 + 0x1C) = 0x1555;
    ((TCharaMaking *)arg0)->m_20 = 0x9000;
    ((TCharaMaking *)arg0)->update_light_direction();
    return arg0;
}

}
