#include <stddef.h>
#include "types.h"

#include <stddef.h>
#include "pso/TChCrTagPlGraphic.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
struct Stack_802A3138 {
    f32 sp8;
    f32 spC;
    s32 sp10;
    f32 sp14;
};

struct RecoveredFields_802A3138_arg0 {
    u8 unknown_0[0x20];
    s32 field_20;
    u8 unknown_24[0x18];
    f32 field_3C;
    f32 field_40;
    f32 field_44;
};

extern "C" {
s32 draw_ui_sprite_shaded(f32, f32, f32, void *, void *, void *);
#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
typedef char RecoveredFields_802A3138_arg0_20_offset[offsetof(RecoveredFields_802A3138_arg0, field_20) == 0x20 ? 1 : -1];
typedef char RecoveredFields_802A3138_arg0_3C_offset[offsetof(RecoveredFields_802A3138_arg0, field_3C) == 0x3C ? 1 : -1];
typedef char RecoveredFields_802A3138_arg0_40_offset[offsetof(RecoveredFields_802A3138_arg0, field_40) == 0x40 ? 1 : -1];
typedef char RecoveredFields_802A3138_arg0_44_offset[offsetof(RecoveredFields_802A3138_arg0, field_44) == 0x44 ? 1 : -1];
void TChCrTagPlGraphic::draw_class_illustration() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_802A3138, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802A3138, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_802A3138, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_802A3138, sp14) == 0xC) ? 1 : -1];
    Stack_802A3138 stack;
    f32 temp_f0;
    f32 scale;
    s32 depth;
    if (!(((RecoveredFields_802A3138_arg0 *)arg0)->field_3C <= 0.0f)) {
        ((TWindowSubSymbolChatPartsSet *)(&stack.sp10))->copy_vec2(arg0 + 0x48);
        temp_f0 = ((RecoveredFields_802A3138_arg0 *)arg0)->field_44;
        stack.spC = temp_f0;
        stack.sp8 = temp_f0;
        scale = ((RecoveredFields_802A3138_arg0 *)arg0)->field_3C;
        depth = (((RecoveredFields_802A3138_arg0 *)arg0)->field_20 * 2) + 0x66;
        draw_ui_sprite_shaded((f32) (((RecoveredFields_802A3138_arg0 *)arg0)->field_40), (f32)scale, (f32)scale, (void *)depth, &stack.sp10, &stack.sp8);
        stack.sp14 += 255.5f * ((RecoveredFields_802A3138_arg0 *)arg0)->field_44;
        draw_ui_sprite_shaded((f32) (((RecoveredFields_802A3138_arg0 *)arg0)->field_40), scale, scale, (void *)(depth + 1), (void *)&stack.sp10, (void *)&stack.sp8);
    }
}
#pragma pop

}

#include "pso/TChCrTagPlGraphic.h"


#include "types.h"
#include "pso/ui/TChCrCharSelect.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"

struct RecoveredGlobal_802A3454___vt__17TChCrTagPlGraphic {
    s32 value;
    u8 remaining[0x1C];
};

extern "C" {
u8 * __ct__8TChCrTagFP7TObjectPv(void *, s32);
extern RecoveredGlobal_802A3454___vt__17TChCrTagPlGraphic __vt__17TChCrTagPlGraphic;
u8 *__ct__17TChCrTagPlGraphicFv(u8 *arg0, s32 arg1, s32 _w2);
void render__17TChCrTagPlGraphicFv(void* p);
void run_task__17TChCrTagPlGraphicFv(void* p);
void TChCrTagPlGraphic__sub_802A3230(u8 *tag);
void update_fade__8TChCrTagFPv(u8 *arg0);
void *__nw__7TObjectFUl(int);
void restore_saved_depth_alpha_state(void);
int set_depth_buffer_settings_1__Fv(void*);

void render__17TChCrTagPlGraphicFv(void* p) { set_depth_buffer_settings_1__Fv(p); ((TChCrTagPlGraphic *)p)->draw_class_illustration(); restore_saved_depth_alpha_state(); }


struct Ent_802A3230 { f32 v[6]; };

#pragma readonly_strings on
const char *ch_cr_tag_pl_graphic_class_name = "TChCrTagPlGraphic";
#pragma readonly_strings reset

const Ent_802A3230 TChCrTagPlGraphic__data_804664A4[12] = {
    {0.85f, -3.0625f, 337.0f, 158.0f, 405.0f, 127.0f},
    {0.8f, -3.140625f, 435.0f, 160.0f, 448.0f, 128.0f},
    {0.94f, -3.21875f, 343.0f, 125.0f, 489.0f, 127.0f},
    {0.88f, -3.296875f, 497.0f, 140.0f, 476.0f, 128.0f},
    {0.85f, -3.0625f, 467.0f, 168.0f, 447.0f, 122.0f},
    {0.8f, -3.140625f, 389.0f, 182.0f, 457.0f, 129.0f},
    {1.0f, -3.296875f, 317.0f, 117.0f, 430.0f, 132.0f},
    {0.75f, -3.21875f, 534.0f, 178.0f, 488.0f, 128.0f},
    {0.85f, -3.140625f, 447.0f, 130.0f, 472.0f, 124.0f},
    {0.83f, -3.296875f, 495.0f, 136.0f, 465.0f, 124.0f},
    {0.85f, -3.21875f, 327.0f, 142.0f, 461.0f, 129.0f},
    {0.85f, -3.0625f, 384.0f, 136.0f, 458.0f, 117.0f},
};

const f32 tag_player_graphic_match_value_table[4] = {-3.296875f, -3.21875f, -3.140625f, -3.0625f};

#pragma push
#pragma fp_contract on
void TChCrTagPlGraphic__sub_802A3230(u8 *tag) {
    const Ent_802A3230 *e;

    e = &TChCrTagPlGraphic__data_804664A4[*(s32 *)(tag + 0x20)];
    *(f32 *)(tag + 0x3C) = *(f32 *)(tag + 0x24) * *(f32 *)(tag + 0x30);
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        *(f32 *)(tag + 0x40) += 0.25f * (e->v[1] - *(f32 *)(tag + 0x40));
        *(f32 *)(tag + 0x44) += 0.25f * (e->v[0] - *(f32 *)(tag + 0x44));
        *(f32 *)(tag + 0x48) += 0.25f * (e->v[2] - *(f32 *)(tag + 0x48));
        *(f32 *)(tag + 0x4C) += 0.25f * (e->v[3] - *(f32 *)(tag + 0x4C));
        break;
    default:
        if (((TChCrTagPlGraphic *)tag)->vt4() != 0) {
            *(f32 *)(tag + 0x40) += 0.25f * (-2.75f - *(f32 *)(tag + 0x40));
            *(f32 *)(tag + 0x44) += 0.25f * (1.0f - *(f32 *)(tag + 0x44));
            *(f32 *)(tag + 0x48) += 0.25f * (e->v[4] - *(f32 *)(tag + 0x48));
            *(f32 *)(tag + 0x4C) += 0.25f * (e->v[5] - *(f32 *)(tag + 0x4C));
        }
        break;
    }
}
#pragma pop

void run_task__17TChCrTagPlGraphicFv(void* p) { update_fade__8TChCrTagFPv((u8 *)p); TChCrTagPlGraphic__sub_802A3230((u8 *)p); }

extern void *tl_03;

typedef char RecoveredGlobal_802A3454___vt__17TChCrTagPlGraphic_size[sizeof(RecoveredGlobal_802A3454___vt__17TChCrTagPlGraphic) == 0x20 ? 1 : -1];

s32 TChCrTagPlGraphic::vt4() {
    switch (TChCrCharSelect::get_selected_index()) {
    case 0:
        if (*(s32 *)((u8 *)this + 0x20) / 4 == TChCrCharSelect::get_selected_char()) {
            return 1;
        }
        break;
    default:
        if (*(s32 *)((u8 *)this + 0x20) == TChCrCharSelect::get_instance()) {
            return 1;
        }
        break;
    }
    return 0;
}

TChCrTagPlGraphic::~TChCrTagPlGraphic() {}

u8 *__ct__17TChCrTagPlGraphicFv(u8 *ch_cr_tag, s32 arg1, s32 _w2) {
    u8 *temp_r5;
    __ct__8TChCrTagFP7TObjectPv(ch_cr_tag, arg1);
    *(s32 **)((s8 *)ch_cr_tag + 0x18) = &__vt__17TChCrTagPlGraphic.value;
    *(s32 *)((s8 *)ch_cr_tag + 0) = (s32) ch_cr_tag_pl_graphic_class_name;
    *(f32 *)((s8 *)ch_cr_tag + 0x28) = 0.13333334f;
    *(f32 *)((s8 *)ch_cr_tag + 0x2C) = -0.06666667f;
    *(f32 *)((s8 *)ch_cr_tag + 0x34) = 0.13333334f;
    *(f32 *)((s8 *)ch_cr_tag + 0x38) = -0.06666667f;
    *(f32 *)((s8 *)ch_cr_tag + 0x3C) = 0.0f;
    temp_r5 = (u8 *)&TChCrTagPlGraphic__data_804664A4[*(s32 *)((s8 *)ch_cr_tag + 0x20)];
    *(f32 *)((s8 *)ch_cr_tag + 0x40) = (f32) *(f32 *)((s8 *)temp_r5 + 4);
    *(f32 *)((s8 *)ch_cr_tag + 0x44) = (f32) *(f32 *)((s8 *)temp_r5 + 0);
    ((TWindowSubSymbolChatPartsSet *)(ch_cr_tag + 0x48))->copy_vec2(temp_r5 + 8);
    return ch_cr_tag;
}

void *TChCrTagPlGraphic::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x50);
    if (o != NULL) {
        o = __ct__17TChCrTagPlGraphicFv((u8 *)o, (s32)tl_03, (s32)arg0);
    }
    return o;
}


void TChCrTagPlGraphic::create_matching_tags() {
    s32 i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 12; j++) {
            if (TChCrTagPlGraphic__data_804664A4[j].v[1] == tag_player_graphic_match_value_table[i]) {
                TChCrTagPlGraphic::create((void *)j);
            }
        }
    }
}

}
