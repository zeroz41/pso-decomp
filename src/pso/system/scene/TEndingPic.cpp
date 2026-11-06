#include "pso/system/scene/TEndingPic.h"
#include "pso/system/scene/TEndingPicStage.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"

#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80352F6C___vt__10TEndingPic { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_80352F6C___vt__10TEndingPic_size[sizeof(RecoveredGlobal_80352F6C___vt__10TEndingPic) == 0x18 ? 1 : -1];

extern "C" {
int TKeyBoardControl__sub_8000F828(void);
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_80352F6C___vt__10TEndingPic __vt__10TEndingPic;
extern s32 lbl_805D4378;
extern s32 TEndingPic__animation_state;
extern s32 ending_pic_wall_texture_list;

void TEndingPic::advance_animation_state() {
    s32 temp_r0;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 temp_r3_4;
    s32 temp_r4;
    s32 temp_r4_2;

    switch ((s32) TEndingPic__animation_state) {
    case 1:
        temp_r3 = *(s32 *)((s8 *)this + 0x1C) + 1;
        *(s32 *)((s8 *)this + 0x1C) = temp_r3;
        temp_r4 = *(s32 *)((s8 *)this + 0xEC);
        if (temp_r3 > (s32) ((temp_r4 * 3) - temp_r4)) {
            TEndingPic__animation_state = 2;
            TEndingPicStage::set_picture(*(s32 *)((s8 *)this + 0x24));
            *(s32 *)((s8 *)this + 0x24) = (s32) (*(s32 *)((s8 *)this + 0x24) + 1);
        }
        break;
    case 2:
        temp_r3_2 = *(s32 *)((s8 *)this + 0x1C) + 1;
        *(s32 *)((s8 *)this + 0x1C) = temp_r3_2;
        if (temp_r3_2 > (s32) (*(s32 *)((s8 *)this + 0xEC) * 0xD)) {
            TEndingPic__animation_state = 3;
            return;
        }
        break;
    case 3:
        temp_r3_3 = *(s32 *)((s8 *)this + 0x1C) + 1;
        *(s32 *)((s8 *)this + 0x1C) = temp_r3_3;
        temp_r4_2 = *(s32 *)((s8 *)this + 0xEC);
        if (temp_r3_3 > (s32) ((temp_r4_2 * 0xE) - temp_r4_2)) {
            TEndingPic__animation_state = 4;
            TEndingPicStage::set_picture(*(s32 *)((s8 *)this + 0x24));
            *(s32 *)((s8 *)this + 0x24) = (s32) (*(s32 *)((s8 *)this + 0x24) + 1);
            return;
        }
        break;
    case 4:
        temp_r3_4 = *(s32 *)((s8 *)this + 0x1C) + 1;
        *(s32 *)((s8 *)this + 0x1C) = temp_r3_4;
        if (temp_r3_4 > (s32) (*(s32 *)((s8 *)this + 0xEC) * 0x18)) {
            *(s32 *)((s8 *)this + 0x1C) = 0;
            TEndingPic__animation_state = 1;
            temp_r0 = *(s32 *)((s8 *)this + 0x28) + 1;
            *(s32 *)((s8 *)this + 0x28) = temp_r0;
            if (temp_r0 > 5) {
                *(s32 *)((s8 *)this + 0x28) = 5;
                TEndingPic__animation_state = 5;
                return;
            }
        }
        break;
    case 5:
        *(s32 *)((s8 *)this + 0x28) = 5;
        break;
    }
}

extern const f32 lbl_805DFEF0;

void TEndingPic::draw_current_pic() {
    u8 *arg0 = (u8 *)this;
    begin_screen_draw(1);
    switch ((s32) TEndingPic__animation_state) {
    case 1:
    case 3:
        break;
    case 2:
        set_draw_texture_and_color(((*(s32 *)((s8 *)arg0 + 0x28) * 2) + 2), -1);
        draw_textured_quad_at_depth((f32 *)(arg0 + 0xAC), lbl_805DFEF0);
        break;
    case 4:
    case 5:
        set_draw_texture_and_color(((*(s32 *)((s8 *)arg0 + 0x28) * 2) + 3), -1);
        draw_textured_quad_at_depth((f32 *)(arg0 + 0xCC), lbl_805DFEF0);
        break;
    default:
        break;
    }
    TWindowSubStatusDisp::get_player();
}

    extern const float lbl_805DFEF4;
    extern const float lbl_805DFEF8;
    extern const float lbl_805DFEFC;
    extern const float lbl_805DFF00;
    extern const float lbl_805DFF04;
    extern const float lbl_805DFF08;
    extern const float lbl_805DFF0C;
    extern const float lbl_805DFF10;
    extern const float lbl_805DFF14;
    extern const float lbl_805DFF18;
    extern const float lbl_805DFF1C;
    extern const float lbl_805DFF20;
    extern const float lbl_805DFF24;
    extern const float lbl_805DFF28;
void TEndingPic::init_positions() { *(float*)((char*)this + 0x2c) = lbl_805DFEF4; *(float*)((char*)this + 0x30) = lbl_805DFEF8; *(float*)((char*)this + 0x34) = lbl_805DFEFC; *(float*)((char*)this + 0x38) = lbl_805DFF00; *(float*)((char*)this + 0x3c) = lbl_805DFF04; *(float*)((char*)this + 0x40) = lbl_805DFEF8; *(float*)((char*)this + 0x44) = lbl_805DFF08; *(float*)((char*)this + 0x48) = lbl_805DFF0C; *(float*)((char*)this + 0x4c) = lbl_805DFEF8; *(float*)((char*)this + 0x50) = lbl_805DFEF8; *(float*)((char*)this + 0x54) = lbl_805DFF10; *(float*)((char*)this + 0x58) = lbl_805DFF00; *(float*)((char*)this + 0x5c) = lbl_805DFEF8; *(float*)((char*)this + 0x60) = lbl_805DFEF8; *(float*)((char*)this + 0x64) = lbl_805DFF04; *(float*)((char*)this + 0x68) = lbl_805DFF0C; *(float*)((char*)this + 0x6c) = lbl_805DFEF4; *(float*)((char*)this + 0x70) = lbl_805DFEF8; *(float*)((char*)this + 0x74) = lbl_805DFEFC; *(float*)((char*)this + 0x78) = lbl_805DFF00; *(float*)((char*)this + 0x7c) = lbl_805DFF04; *(float*)((char*)this + 0x80) = lbl_805DFEF8; *(float*)((char*)this + 0x84) = lbl_805DFF08; *(float*)((char*)this + 0x88) = lbl_805DFF0C; *(float*)((char*)this + 0x8c) = lbl_805DFEF8; *(float*)((char*)this + 0x90) = lbl_805DFEF8; *(float*)((char*)this + 0x94) = lbl_805DFF10; *(float*)((char*)this + 0x98) = lbl_805DFF00; *(float*)((char*)this + 0x9c) = lbl_805DFEF8; *(float*)((char*)this + 0xa0) = lbl_805DFEF8; *(float*)((char*)this + 0xa4) = lbl_805DFF04; *(float*)((char*)this + 0xa8) = lbl_805DFF0C; *(float*)((char*)this + 0xac) = lbl_805DFF14; *(float*)((char*)this + 0xb0) = lbl_805DFF18; *(float*)((char*)this + 0xb4) = lbl_805DFF1C; *(float*)((char*)this + 0xb8) = lbl_805DFF20; *(float*)((char*)this + 0xbc) = lbl_805DFEF8; *(float*)((char*)this + 0xc0) = lbl_805DFEF8; *(float*)((char*)this + 0xc4) = lbl_805DFF08; *(float*)((char*)this + 0xc8) = lbl_805DFF08; *(float*)((char*)this + 0xcc) = lbl_805DFF14; *(float*)((char*)this + 0xd0) = lbl_805DFF24; *(float*)((char*)this + 0xd4) = lbl_805DFF1C; *(float*)((char*)this + 0xd8) = lbl_805DFF28; *(float*)((char*)this + 0xdc) = lbl_805DFEF8; *(float*)((char*)this + 0xe0) = lbl_805DFEF8; *(float*)((char*)this + 0xe4) = lbl_805DFF08; *(float*)((char*)this + 0xe8) = lbl_805DFF08; }

void TEndingPic::render() {
    s32 arg0 = (s32)this;
    if ((s32) TEndingPic__animation_state != 0) {
        TObjFish::set_global_param(ending_pic_wall_texture_list);
        draw_current_pic();
    }
}

void TEndingPic::run_task() { advance_animation_state(); }

    extern int ending_ab_wall_texture_list;

TEndingPic::~TEndingPic() {}
u8 *__ct__10TEndingPicFv(u8 *ending_pic, u8 *arg1) {
    __ct__7TObjectFP7TObject(ending_pic, arg1);
    *(s32 **)((s8 *)ending_pic + 0x18) = &__vt__10TEndingPic.value;
    *(s32 *)((s8 *)ending_pic + 0) = (s32) lbl_805D4378;
    *(s32 *)((s8 *)ending_pic + 0x1C) = -1;
    TEndingPic__animation_state = 0;
    *(s32 *)((s8 *)ending_pic + 0x20) = 0xFF;
    *(s32 *)((s8 *)ending_pic + 0x28) = 0;
    *(s32 *)((s8 *)ending_pic + 0x24) = 0;
    ending_pic_wall_texture_list = ((s32)get_ending_ab_wall_texture_list());
    ((TEndingPic *)ending_pic)->init_positions();
    switch (TKeyBoardControl__sub_8000F828()) {
    case 0:
        *(s32 *)((s8 *)ending_pic + 0xEC) = 0x1E;
        break;
    case 1:
        *(s32 *)((s8 *)ending_pic + 0xEC) = 0x19;
        break;
    }
    return ending_pic;
}
}

int get_ending_ab_wall_texture_list(void) {  return ending_ab_wall_texture_list; }
