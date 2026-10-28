#include "types.h"
#include "pso/unk/text_801C51D4.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801C50A8.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/map/CurrentArea.h"

extern "C" {
extern int active_character_save_record;
    extern int duel_result_window;
void queue_destruction__7TObjectFv(void *arg0);
extern u32 ad_single_ply_chr_select_instance;
u32 __nw__7TObjectFUl(s32);
extern s32 tl_00;
void TAdSinglePlyChrSelectGC::set_slot(int a0) { *(short*)((char*)active_character_save_record + 0x21b0) = a0; }
u16 TAdSinglePlyChrSelectGC::get_char_select_slot() {
    return *(u16 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0x21B0);
}
void TAdSinglePlyChrSelectGC__sub_801C50C0(int a0) { *(short*)((char*)active_character_save_record + 0x21ae) = a0; }
u16 TAdSinglePlyChrSelectGC__sub_801C50CC(void) {
    return *(u16 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0x21AE);
}
void TAdSinglePlyChrSelectGC__sub_801C50D8(int a0) { *(short*)((char*)active_character_save_record + 0x21ac) = a0; }
u16 TAdSinglePlyChrSelectGC__sub_801C50E4(void) {
    return *(u16 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0x21AC);
}
void TAdSinglePlyChrSelectGC__sub_801C50F0(int a0) { *(short*)((char*)active_character_save_record + 0x21aa) = a0; }
u16 TAdSinglePlyChrSelectGC__sub_801C50FC(void) {
    return *(u16 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0x21AA);
}
void TAdSinglePlyChrSelectGC__sub_801C5108(int a0) { *(short*)((char*)active_character_save_record + 0x21a8) = a0; }
u16 TAdSinglePlyChrSelectGC__sub_801C5114(void) {
    return *(u16 *)((s8 *)(*(u8 * *)&active_character_save_record) + 0x21A8);
}
void TAdSinglePlyChrSelectGC__sub_801C5120(void) { duel_result_window = 0; }
void TAdSinglePlyChrSelectGC::destroy() {
    if ((u32) ad_single_ply_chr_select_instance != 0U) {
        queue_destruction__7TObjectFv((void *)ad_single_ply_chr_select_instance);
    }
}
void TAdSinglePlyChrSelectGC__sub_801C5158(void) { (*(int *)&ad_single_ply_chr_select_instance) = 0; }
s32 TAdSinglePlyChrSelectGC::create_if_key_pressed() {
    s32 global_state;
    u32 var_r0;
    global_state = get_current_area();
    if ((global_state != 0x10) && (global_state != 0x11)) {
        return 0;
    }
    if ((u32) ad_single_ply_chr_select_instance != 0U) {
        return 0;
    }
    var_r0 = __nw__7TObjectFUl(0x28);
    if (var_r0 != 0U) {
        var_r0 = (u32)fn_801C5380((u8 *)var_r0, tl_00);
    }
    ad_single_ply_chr_select_instance = var_r0;
    return 1;
}

}
