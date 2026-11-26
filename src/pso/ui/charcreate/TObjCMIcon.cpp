#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/UISprite.h"
#include "pso/render/render_util.h"
#include "pso/ui/charcreate/TObjCMIcon.h"
#include "pso/ui/charcreate/TObjCMMainMenu.h"
#include "pso/system/vector.h"
#include "pso/system/task/TObject.h"

void TObjCMIcon::set_screen_position(const vec2f *pos) {
    copy_vec2(&cm_icon_screen_position, (void *)pos);
}

#pragma common off
CreationIconState creation_icon_states[7];
f32 TObjCMIcon::horizontal_scroll_offset;
#pragma common reset

void TObjCMIcon::reset_icon_flags() {
    s32 i;
    CreationIconState *p = creation_icon_states;
    for (i = 0; i < 7; i++) {
        p->hidden = 1;
        p++;
    }
}

void TObjCMIcon::show_creation_icon(s32 index) {
    creation_icon_states[index].hidden = 0;
}

void TObjCMIcon::show_only_creation_icons(s32 count, const s32 *ids) {
    s32 i;
    reset_icon_flags();
    for (i = 0; i < count; i++) {
        show_creation_icon(ids[i]);
    }
}

 extern const char TObjCMIcon_class_name_string[11] = "TObjCMIcon"; __declspec(section ".rodata") CreationIconState creation_initial_icon_state = { 0x1 };
void TObjCMIcon::init_icon_table() {
    CreationIconState *entry;
    s32 i;
    i = 0;
    entry = creation_icon_states;
    do {
        copy_icon_state(entry, &creation_initial_icon_state);
        i += 1;
        entry++;
    } while (i < 7);
    horizontal_scroll_offset = 0.0f;
}

void TObjCMIcon::copy_icon_state(CreationIconState *dst, CreationIconState *src) {
    dst->hidden = src->hidden;
    dst->fade = src->fade;
    dst->x = src->x;
}
s32 TObjCMIcon::get_sprite_id(s32 sprite_id) {
    return sprite_id;
}
void TObjCMIcon::render() {
    s32 idx[7];
    f32 keys[7];
    vec2f pos;
    s32 i;
    s32 j;
    s32 id;
    CreationIconState *e;
    CreationIconGroup *g;
    s32 n;
    s32 tid;
    s32 s;
    f32 k;
    f32 tk;
    f32 z;
    f32 depth;
    f32 x0;
    e = creation_icon_states;
    for (i = 0; i < 7; i++, e++) {
        k = e->fade * e->fade;
        id = i;
        for (j = 0; j < i; j++) {
            if (k < keys[j]) {
                tk = k;
                tid = id;
                id = idx[j];
                k = keys[j];
                idx[j] = tid;
                keys[j] = tk;
            }
        }
        idx[j] = id;
        keys[j] = k;
    }
    set_depth_buffer_settings_1();
    set_draw_list_mask(2);
    x0 = cm_icon_screen_position.x - horizontal_scroll_offset;
    for (i = 0; i < 7; i++) {
        id = idx[i];
        depth = keys[i];
        g = &icon_group_table[id];
        pos.x = x0 + (creation_icon_states)[id].x;
        pos.y = cm_icon_screen_position.y * TObjCMMainMenu::get_scale();
        z = (-2.0f) - (1.0f - (f32)(i / 7));
        for (n = 0; n < g->count; n++) {
            s = get_sprite_id(g->sprite_ids[n]);
            draw_ui_sprite(s, &pos, z, depth);
            pos.x += (f32)(TObjCMMainMenu::get_creation_sprite_id(s) + 4);
        }
    }
    restore_saved_depth_alpha_state();
}
#pragma push
#pragma fp_contract on
void TObjCMIcon::run_task() {
    CreationIconState *p;
    CreationIconGroup *g;
    s32 i;
    f32 v;
    f32 x;
    p = creation_icon_states;
    for (i = 0; i < 7; i++, p++) {
        if (p->hidden == 0) {
            if ((p->fade += 0.16666667f) > 1.0f) {
                p->fade = 1.0f;
            }
        } else {
            if ((p->fade += -0.06666667f) < 0.0f) {
                p->fade = 0.0f;
            }
        }
    }
    x = 0.0f;
    g = icon_group_table;
    p = creation_icon_states;
    {
    s32 k;
    for (k = 0; k < 7; k++, p++, g++) {
        if (p->hidden == 1) {
            v = p->x - 1.0f;
            p->x = v;
            if (v < 0.0f) {
                p->x = 0.0f;
            }
        } else {
            s32 j;
            p->x += 0.05f * (x - p->x);
            for (j = 0; j < g->count; j++) {
                x += (f32)(TObjCMMainMenu::get_creation_sprite_id(get_sprite_id(g->sprite_ids[j])) + 4);
            }
            x += 8.0f;
        }
    }
    }
    horizontal_scroll_offset += 0.15f * (x - horizontal_scroll_offset);
}
#pragma pop

const char *cm_icon_name_ptr = TObjCMIcon_class_name_string;

void *TObjCMIcon::create(void *object) {
    return new TObjCMIcon((TObject *)object);
}

CreationIconGroup TObjCMIcon::icon_group_table[7] = {
    {2, {0x38, 0xA8, 0, 0}},
    {2, {0x38, 0xA9, 0, 0}},
    {2, {0x38, 0xAA, 0, 0}},
    {3, {0x38, 0x37, 0xAA, 0}},
    {2, {0x37, 0xA7, 0, 0}},
    {2, {0x37, 0xAB, 0, 0}},
    {2, {0x37, 0xAC, 0, 0}},
};
__declspec(section ".data") vec2f cm_icon_screen_position = {604.0f, 443.0f};

TObjCMIcon::~TObjCMIcon() {}

TObjCMIcon::TObjCMIcon(TObject *parent) : TObject(parent) {
    m_name = cm_icon_name_ptr;
}
