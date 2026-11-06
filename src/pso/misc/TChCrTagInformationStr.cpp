#include "pso/ui/TChCrTagInformationStr.h"

TChCrTagInformationStr::~TChCrTagInformationStr() {}

#include "types.h"

extern "C" {
s32 queue_destruction__7TObjectFv();
extern s32 char_creation_tag_info_selected_index;
extern const f32 TChCrTagInformationStr__data_805DF108;
extern const f32 lbl_805DF110;
extern const f32 lbl_805DF124;
extern const f32 lbl_805DF128;
extern const f32 lbl_805DF12C;
s32 __ct__7TObjectFP7TObject();
void *__nw__7TObjectFUl(int);

void *TChCrTagInformationStr::create(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x38);
    if (o != NULL) {
        o = __ct__22TChCrTagInformationStrFv((void *)o, (s32)arg0, (s32)arg1);
    }
    return o;
}

extern s32 __vt__22TChCrTagInformationStr[];
extern s32 TChCrTagInformationStr__class_name;

#pragma push
#pragma opt_common_subs off
void run_task__22TChCrTagInformationStrFv(u8 *arg0) {
    s32 temp_r0_2;
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) (*(s32 *)((s8 *)arg0 + 0x34) + 1);
    if (((s32) *(s32 *)((s8 *)arg0 + 0x1C) != 2) && ((s32) *(s32 *)((s8 *)arg0 + 0x20) != (s32) char_creation_tag_info_selected_index)) {
        *(s32 *)((s8 *)arg0 + 0x1C) = 2;
    }
    switch (*(s32 *)((s8 *)arg0 + 0x1C)) {
    case 0:
        temp_r0_2 = *(s32 *)((s8 *)arg0 + 0x2C) - 1;
        *(s32 *)((s8 *)arg0 + 0x2C) = temp_r0_2;
        if (temp_r0_2 <= 0) {
            *(s32 *)((s8 *)arg0 + 0x2C) = 0;
            *(s32 *)((s8 *)arg0 + 0x1C) = 1;
            break;
        }
        break;
    case 1:
        *(f32 *)((s8 *)arg0 + 0x30) = (f32) (*(f32 *)((s8 *)arg0 + 0x30) + lbl_805DF124);
        if (*(f32 *)((s8 *)arg0 + 0x30) > lbl_805DF110) {
            *(f32 *)((s8 *)arg0 + 0x30) = (f32) lbl_805DF110;
            break;
        }
        break;
    case 2:
        if ((s32) char_creation_tag_info_selected_index == -1) {
            *(f32 *)((s8 *)arg0 + 0x30) = (f32) (*(f32 *)((s8 *)arg0 + 0x30) + lbl_805DF128);
        } else {
            *(f32 *)((s8 *)arg0 + 0x30) = (f32) (*(f32 *)((s8 *)arg0 + 0x30) + lbl_805DF12C);
        }
        if (*(f32 *)((s8 *)arg0 + 0x30) <= (*(f32 *)&TChCrTagInformationStr__data_805DF108)) {
            *(f32 *)((s8 *)arg0 + 0x30) = (f32) (*(f32 *)&TChCrTagInformationStr__data_805DF108);
            queue_destruction__7TObjectFv();
        }
        break;
    }
}
#pragma pop

void *__ct__22TChCrTagInformationStrFv(void *arg0, s32 arg1, s32 arg2) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__22TChCrTagInformationStr;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TChCrTagInformationStr__class_name;
    *(s32 *)((s8 *)arg0 + 0x20) = arg2;
    if ((s32) *(s32 *)((s8 *)arg0 + 0x20) <= 2) {
        *(s32 *)((s8 *)arg0 + 0x24) = 0x11;
        *(s32 *)((s8 *)arg0 + 0x28) = (s32) (*(s32 *)((s8 *)arg0 + 0x20) * 7);
    } else {
        *(s32 *)((s8 *)arg0 + 0x24) = 0x12;
        *(s32 *)((s8 *)arg0 + 0x28) = (s32) ((*(s32 *)((s8 *)arg0 + 0x20) - 3) * 7);
    }
    *(s32 *)((s8 *)arg0 + 0x34) = 0;
    *(s32 *)((s8 *)arg0 + 0x2C) = 5;
    *(f32 *)((s8 *)arg0 + 0x30) = (f32) TChCrTagInformationStr__data_805DF108;
    *(s32 *)((s8 *)arg0 + 0x1C) = 0;
    return arg0;
}

}
