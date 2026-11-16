#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "libs/dolphin/include/dolphin/mtx/GeoTypes.h"
#include "pso/technique/TTecKafun.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/effect/TUnk_804CC148.h"


#pragma readonly_strings on


const char *tec_kafun_class_name_ptr = "TTecKafun";


extern "C" {
void *find_entity_by_id(u16 id);
u16 get_entity_id(void *);
s32 play_sound_effect(s32, Vec *, s16, s32);
u8 * construct_area_technique_base(void *, s32, s32, s32, s16);
extern s32 __vt__9TTecKafun[];
extern const char *tec_kafun_class_name_ptr;
u8 *TTecKafun__sub_802A9948(TTecKafun *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, f32 farg0, f32 farg1);
u8 *TTecKafun__ct(TTecKafun *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, f32 farg0, f32 farg1);

}
TTecKafun::~TTecKafun() {

}


void TTecKafun::render() {  }
void TTecKafun::run_task() {
    u8 *arg0 = (u8 *)this;
    if ((u32) this->m_e8 == 0U) {
        ((TObject *)arg0)->queue_destruction();
        return;
    }
    this->source = (u32)find_entity_by_id((this->m_b4));
    if ((u32) this->source == 0U) {
        ((TObject *)arg0)->queue_destruction();
        return;
    }
    spawn_particle_effect((arg0 + 0x20), (this->m_f0));
    if ((s32) this->m_fc == 1) {
        spawn_particle_effect((arg0 + 0x20), (this->m_f4));
    }
    ((TUnk_804CC148 *)arg0)->apply_technique_to_area_targets();
    ((TObject *)arg0)->queue_destruction();
}

u8 *TTecKafun__ct(TTecKafun *tec_kafun, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 arg6, f32 farg0, f32 farg1) {
    u8 *temp_r3;
    u8 *temp_r3_2;
    construct_area_technique_base(tec_kafun, arg1, arg2, arg2, arg6);
    *(s32 **)((s8 *)tec_kafun + 0x18) = __vt__9TTecKafun;
    *(s32 *)((s8 *)tec_kafun + 0) = (s32) ((s32)tec_kafun_class_name_ptr);
    *(f32 *)((s8 *)tec_kafun + 0xEC) = farg0;
    tec_kafun->m_f8 = arg3;
    tec_kafun->m_fc = 1;
    tec_kafun->m_f0 = arg4;
    tec_kafun->m_f4 = arg5;
    temp_r3 = (u8 *)(*(u8 **)((s8 *)tec_kafun + 0xE8));
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 0xA4)) + 0xC) = farg1;
    }
    play_sound_effect(0x4002A50A, (Vec *)((u32)((u8 *)tec_kafun + 0x20)), 0, 0);
    temp_r3_2 = (u8 *)(*(u8 **)((s8 *)tec_kafun + 0x1C));
    if (temp_r3_2 != NULL) {
        tec_kafun->m_b4 = get_entity_id(temp_r3_2);
    }
    return (u8 *)tec_kafun;
}

u8 *TTecKafun__sub_802A9948(TTecKafun *tec_kafun, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, f32 farg0, f32 farg1) {
    u8 *temp_r3;
    u8 *temp_r3_2;
    construct_area_technique_base(tec_kafun, arg1, arg2, arg2, arg5);
    *(s32 **)((s8 *)tec_kafun + 0x18) = __vt__9TTecKafun;
    *(s32 *)((s8 *)tec_kafun + 0) = (s32) ((s32)tec_kafun_class_name_ptr);
    *(f32 *)((s8 *)tec_kafun + 0xEC) = farg0;
    tec_kafun->m_f8 = arg3;
    tec_kafun->m_fc = 0;
    tec_kafun->m_f0 = arg4;
    temp_r3 = (u8 *)(*(u8 **)((s8 *)tec_kafun + 0xE8));
    if (temp_r3 != NULL) {
        *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 0xA4)) + 0xC) = farg1;
    }
    play_sound_effect(0x4002A50A, (Vec *)((u32)((u8 *)tec_kafun + 0x20)), 0, 0);
    temp_r3_2 = (u8 *)(*(u8 **)((s8 *)tec_kafun + 0x1C));
    if (temp_r3_2 != NULL) {
        tec_kafun->m_b4 = get_entity_id(temp_r3_2);
    }
    return (u8 *)tec_kafun;
}

