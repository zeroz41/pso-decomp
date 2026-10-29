#include "types.h"
#include "pso/ui/UISprite.h"
#include "pso/object/TObjCMIcon_80299488.h"
#include "pso/render/render_util.h"

#include "pso/TObjCMIcon.h"
#include "pso/object/TObjCMMainMenu.h"






struct Grp_802995A0 {
    s32 n;
    s32 ids[4];
};



struct Grp_802997DC { s32 n; s32 ids[4]; };

#pragma common off
CreationIconState creation_icon_states[7];
f32 TObjCMIcon__horizontal_scroll_offset;
#pragma common reset

extern "C" {
s32 get_creation_sprite_id__14TObjCMMainMenuFl(s32);
extern f32 cm_icon_screen_position[];
extern Grp_802995A0 TObjCMIcon__icon_group_table[];
extern const f32 lbl_805DDC44;
extern const f32 lbl_805DDC48;
extern const f32 lbl_805DDC4C;
extern const f32 lbl_805DDC50;
extern const f32 lbl_805DDC54;

void TObjCMIcon::reset_icon_flags() {
    s32 i;
    CreationIconState *p = creation_icon_states;
    for (i = 0; i < 7; i++) {
        p->hidden = 1;
        p++;
    }
}

void TObjCMIcon__sub_802994B0(s32 arg0) {
    creation_icon_states[arg0].hidden = 0;
}


void TObjCMIcon__sub_802994C8(s32 arg0, s32 *arg1) {
    s32 i;
    TObjCMIcon::reset_icon_flags();
    for (i = 0; i < arg0; i++) {
        TObjCMIcon__sub_802994B0(arg1[i]);
    }
}

void TObjCMIcon::init_icon_table() {
    CreationIconState *entry;
    s32 i;
    i = 0;
    entry = creation_icon_states;
    do {
        TObjCMIcon__sub_8029957C(entry, &creation_initial_icon_state);
        i += 1;
        entry++;
    } while (i < 7);
    TObjCMIcon__horizontal_scroll_offset = 0.0f;
}

void TObjCMIcon__sub_8029957C(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); *(f32*)((char*)p + 0x4) = *(f32*)((char*)q + 0x4); *(f32*)((char*)p + 0x8) = *(f32*)((char*)q + 0x8); }
s32 TObjCMIcon__sub_80299598(s32 arg0, s32 arg1) {
    return arg1;
}
void render__10TObjCMIconFv(s32 self) {
    s32 idx[7];
    f32 keys[7];
    vec2f pos;
    s32 i;
    s32 j;
    s32 id;
    CreationIconState *e;
    Grp_802995A0 *g;
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
    x0 = cm_icon_screen_position[0] - TObjCMIcon__horizontal_scroll_offset;
    for (i = 0; i < 7; i++) {
        id = idx[i];
        depth = keys[i];
        g = &TObjCMIcon__icon_group_table[id];
        pos.x = x0 + (creation_icon_states)[id].x;
        pos.y = cm_icon_screen_position[1] * TObjCMMainMenu::get_scale();
        z = (-2.0f) - (1.0f - (f32)(i / 7));
        for (n = 0; n < g->n; n++) {
            s = TObjCMIcon__sub_80299598(self, g->ids[n]);
            draw_ui_sprite(s, &pos, z, depth);
            pos.x += (f32)(get_creation_sprite_id__14TObjCMMainMenuFl(s) + 4);
        }
    }
    restore_saved_depth_alpha_state();
}
#pragma push
#pragma fp_contract on
void run_task__10TObjCMIconFv(s32 arg0) {
    CreationIconState *p;
    Grp_802997DC *g;
    s32 i;
    f32 v;
    f32 x;
    p = creation_icon_states;
    for (i = 0; i < 7; i++, p++) {
        if (p->hidden == 0) {
            if ((p->fade += lbl_805DDC44) > 1.0f) {
                p->fade = 1.0f;
            }
        } else {
            if ((p->fade += lbl_805DDC48) < 0.0f) {
                p->fade = 0.0f;
            }
        }
    }
    x = 0.0f;
    g = ((Grp_802997DC *)&TObjCMIcon__icon_group_table);
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
            p->x += lbl_805DDC4C * (x - p->x);
            for (j = 0; j < g->n; j++) {
                x += (f32)(get_creation_sprite_id__14TObjCMMainMenuFl(TObjCMIcon__sub_80299598(arg0, g->ids[j])) + 4);
            }
            x += lbl_805DDC50;
        }
    }
    }
    TObjCMIcon__horizontal_scroll_offset += lbl_805DDC54 * (x - TObjCMIcon__horizontal_scroll_offset);
}
#pragma pop

}
