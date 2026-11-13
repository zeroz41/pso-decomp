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
void queue_destruction__7TObjectFv(void *);
extern s32 char_creation_tag_info_selected_index;

void *TChCrTagInformationStr::create(void *arg0, void *arg1) {
    return new TChCrTagInformationStr((TObject *)arg0, (s32)arg1);
}
}

// Seven lines of text; while fading in, each line also gets rings of faint copies that close in on it.
void TChCrTagInformationStr::render() {
    if (0.0f != alpha) {
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
        color = ((u32)(255.0f * sq) << 24) | 0xFFFFFF;
        spread = 1.0f - sq;
        glow_color = ((u32)(16.0f * alpha * sin_table_lookup(32768.0f * a)) << 24) | 0xFFFFFF;
        radius_step = 1.5f * spread;
        s32 line;
        for (line = 0; line < 7; line++) {
            const char *text = (const char *)get_localized_text_entry(text_group, first_text_entry + line);
            draw_menu_text(pos.x, pos.y, text, color);
            if (spread > 0.0f) {
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
            pos.y += 20.0f;
        }
        restore_saved_depth_alpha_state();
        TCameraCtrl__sub_80068EF0();
    }
}

extern "C" {
extern const char *TChCrTagInformationStr__class_name;

#pragma push
#pragma opt_common_subs off
void TChCrTagInformationStr::run_task() {
    s32 remaining;
    frame = frame + 1;
    if (state != 2 && tag_index != char_creation_tag_info_selected_index) {
        state = 2;
    }
    switch (state) {
    case 0:
        remaining = delay - 1;
        delay = remaining;
        if (remaining <= 0) {
            delay = 0;
            state = 1;
            break;
        }
        break;
    case 1:
        alpha += 0.026666667f;
        if (alpha > 1.0f) {
            alpha = 1.0f;
            break;
        }
        break;
    case 2:
        if (char_creation_tag_info_selected_index == -1) {
            alpha += -0.13333334f;
        } else {
            alpha += -0.033333335f;
        }
        if (alpha <= 0.0f) {
            alpha = 0.0f;
            queue_destruction__7TObjectFv(this);
        }
        break;
    }
}
#pragma pop

TChCrTagInformationStr::~TChCrTagInformationStr() {}

}

TChCrTagInformationStr::TChCrTagInformationStr(TObject *parent, s32 tag_index) : TObject(parent) {
    m_name = TChCrTagInformationStr__class_name;
    this->tag_index = tag_index;
    if (this->tag_index <= 2) {
        text_group = 0x11;
        first_text_entry = this->tag_index * 7;
    } else {
        text_group = 0x12;
        first_text_entry = (this->tag_index - 3) * 7;
    }
    frame = 0;
    delay = 5;
    alpha = 0.0f;
    state = 0;
}
