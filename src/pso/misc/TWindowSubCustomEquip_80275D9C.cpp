#include "types.h"
#include "pso/misc/TWindowSubCustomEquip.h"
#include "pso/misc/TWindowSubCustomSelect.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80141D1C.h"

struct Obj_80275DB4 { u8 pad[0x60]; char f60; u8 pad2[0x6c - 0x61]; void *f6c; };

struct Vec2_80275DE8 { f32 x, y; };

struct Win_80275F90 { u8 pad[0x66]; s16 f66; };

struct Rect_80275DE8 { f32 x0, y0, x1, y1, u0, v0, u1, v1; };

extern "C" {
void *get_player_by_client_id(s32);
s32 can_use_palette_action__10TObjPlayerFPvUcUc(void *, u8, u8);
u8 *get_array_entry__13TUnk_804CE018Fi(void *, s32);
void update_palette_item_count_label(u8 *, u8 *, s32, s32, s32);
void draw_action_palette_icon(u8 *, s32, s32);
extern u8 lbl_8044F738[];
extern u8 lbl_8044F740[];
extern const f32 lbl_805DD564;
s32 try_open__19TWindowKeyBoardSoftFii(s32 arg0, s32 arg1);
void begin_screen_draw(s32 arg0);
void draw_textured_quad_at_depth(f32 *q, f32 depth);
void set_draw_texture_and_color(s32 idx, s32 arg1);
extern Vec2_80275DE8 custom_equip_cursor_frame_uv_table[];
extern s32 lbl_805D63F0;
extern const f32 lbl_805DD550;
extern const f32 lbl_805DD554;
extern const f32 lbl_805DD560;
void draw_cursor_sprite__21TWindowSubCustomEquipFPvPvif(u8 *arg0, Vec2_80275DE8 *arg1, s32 arg2, f32 farg0);
int TWindowSubCustomEquip__sub_80275DA8(void* p);

int TWindowSubCustomEquip::is_selected() { return this->m_60 & 0x1; }
int TWindowSubCustomEquip__sub_80275DA8(void* p) { return *(u8*)((char*)p + 0x60) & 0x2; }
void TWindowSubCustomEquip::clear_flag_and_set_entry_state() {
    Obj_80275DB4 *o = (Obj_80275DB4 *)this;
    o->f60 &= ~1;
    ((TWindowSubStatusDisp *)(o->f6c))->set_entry_state(1);
}

#pragma push
#pragma fp_contract on
void draw_cursor_sprite__21TWindowSubCustomEquipFPvPvif(u8 *arg0, Vec2_80275DE8 *arg1, s32 arg2, f32 farg0) {
    Rect_80275DE8 r;
    Vec2_80275DE8 *t;
    f32 scale;
    if (*(s32 *)((s8 *)arg0 + 0x30) < 0) {
        return;
    }
    t = &custom_equip_cursor_frame_uv_table[arg2 & 0xF];
    scale = lbl_805DD550 / (lbl_805DD554 * farg0 + *(f32 *)((s8 *)arg0 + 0x38));
    set_additive_blend();
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D63F0);
    set_draw_texture_and_color(0xC, -1);
    r.x0 = arg1->x + *(f32 *)((s8 *)arg0 + 0x10);
    r.y0 = arg1->y + *(f32 *)((s8 *)arg0 + 0x14);
    r.x1 = 72.32f + r.x0;
    r.y1 = 72.32f + r.y0;
    r.u0 = t->x / 256.0f;
    r.v0 = t->y / 256.0f;
    r.u1 = (lbl_805DD560 + t->x) / 256.0f;
    r.v1 = (lbl_805DD560 + t->y) / 256.0f;
    if (try_open__19TWindowKeyBoardSoftFii((s32)arg0, (s32)&r) != 0) {
        draw_textured_quad_at_depth((f32 *)&r, scale);
    }
    TWindowSubStatusDisp::get_player();
    set_default_alpha_blend();
}
#pragma pop

void TWindowSubCustomEquip::sub_80275F08(void *window_sub_custom_equip) {
    s8 idx;
    if ((s8)((u8 *)this)[0x64] == 0) {
        idx = ((u8 *)this)[0x61] + ((u8 *)this)[0x62] * 3;
    } else {
        idx = ((u8 *)this)[0x61] + (1 - ((u8 *)this)[0x62]) * 3;
    }
    u8 *e = get_array_entry__13TUnk_804CE018Fi(this, lbl_8044F738[idx]);
    ((TWindowSubCustomEquip *)window_sub_custom_equip)->set_relative_pos(e);
}

void TWindowSubCustomEquip::draw_cursor(u8 *arg1) {
    Win_80275F90 *arg0 = (Win_80275F90 *)this;
    Vec2_80275DE8 pos;
    ((TWindowSubCustomEquip *)arg0)->sub_80275F08(&pos);
    ((void (*)(f32, u8 *, Vec2_80275DE8 *, s32))draw_cursor_sprite__21TWindowSubCustomEquipFPvPvif)(lbl_805DD564, arg1, &pos, arg0->f66);
}

void TWindowSubCustomEquip::update_palette_slot(s32 arg1, s32 kind, s32 arg3) {
    void *pl;
    u8 *a;
    u8 *b;
    pl = get_player_by_client_id(this->m_20);
    if (pl != NULL) {
        a = get_array_entry__13TUnk_804CE018Fi(this, lbl_8044F738[arg1]);
        b = get_array_entry__13TUnk_804CE018Fi(this, lbl_8044F740[arg1]);
        if (can_use_palette_action__10TObjPlayerFPvUcUc(pl, kind, arg3) != 0) {
            *(s32 *)(a + 0x2C) = -1;
        } else {
            *(s32 *)(a + 0x2C) = 0xFF404040;
        }
        draw_action_palette_icon(a, kind, arg3);
        update_palette_item_count_label(b, a, kind, arg3, this->m_20);
    }
}

}
