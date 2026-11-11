#include "pso/ui/charcreate/TChCrTagInformationStr.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/render_util.h"
#include "pso/ui/MenuText.h"
#include "pso/unk/TLobby_80132ED0.h"

// Where the first line of the tag text is drawn; each line goes 20 below the last.
struct TagTextOrigin {
    f32 x, y;
};

extern "C" {
void TCameraCtrl__sub_80068EF0(void);
extern const f32 TChCrTagInformationStr__data_805DF108;
extern const f32 lbl_805DF10C;
extern const f32 lbl_805DF110;
extern const f32 lbl_805DF114;
extern const f32 lbl_805DF118;
extern const f32 lbl_805DF11C;
extern const f32 lbl_805DF120;
s32 queue_destruction__7TObjectFv();
extern s32 char_creation_tag_info_selected_index;
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
}

// Seven lines of text; while fading in, each line also gets rings of faint copies that close in on it.
void TChCrTagInformationStr::render() {
    if (TChCrTagInformationStr__data_805DF108 != alpha) {
        TCameraCtrl::restore_full_screen_view();
        set_depth_buffer_settings_1();
        TagTextOrigin pos = {315.0f, 280.0f};
        f32 radius_step;
        f32 spread;
        f32 sq;
        f32 a;
        u32 color;
        u32 glow_color;
        a = alpha;
        sq = a * a;
        color = ((u32)(lbl_805DF10C * sq) << 24) | 0xFFFFFF;
        spread = lbl_805DF110 - sq;
        glow_color = ((u32)(lbl_805DF114 * alpha * sin_table_lookup(lbl_805DF118 * a)) << 24) | 0xFFFFFF;
        radius_step = lbl_805DF11C * spread;
        s32 line;
        for (line = 0; line < 7; line++) {
            const char *text = (const char *)get_localized_text_entry(text_group, first_text_entry + line);
            draw_menu_text(pos.x, pos.y, text, color);
            if (spread > TChCrTagInformationStr__data_805DF108) {
                s32 ring;
                for (ring = 1; ring < 5; ring++) {
                    f32 radius = ring * radius_step;
                    s32 angle;
                    for (angle = 0; angle < 0x10000; angle += 0x10000 / (ring * 4)) {
                        f32 dx = radius * sin_table_lookup(angle);
                        f32 dy = radius * cos_table_lookup(angle);
                        draw_menu_text(pos.x + dx, pos.y + dy, text, glow_color);
                    }
                }
            }
            pos.y += lbl_805DF120;
        }
        restore_saved_depth_alpha_state();
        TCameraCtrl__sub_80068EF0();
    }
}

extern "C" {
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

TChCrTagInformationStr::~TChCrTagInformationStr() {}

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
