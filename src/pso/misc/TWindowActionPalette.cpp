#include "pso/misc/TWindowActionPalette.h"
#include "pso/TPlyDispData.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TWindowBase.h"
#include <stddef.h>

typedef char palette_children_offset[offsetof(TWindowActionPalette, children) == 0x24 ? 1 : -1];
typedef char palette_resources_offset[offsetof(TWindowActionPalette, resources) == 0x60 ? 1 : -1];
typedef char palette_state_offset[offsetof(TWindowActionPalette, state) == 0x6C ? 1 : -1];
typedef char palette_scale_offset[offsetof(TWindowActionPalette, scale) == 0x70 ? 1 : -1];
typedef char palette_size[sizeof(TWindowActionPalette) == 0x78 ? 1 : -1];

#include "types.h"
#include "pso/item/TItemMag.h"
#include "pso/misc/TMainCursor.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"

struct TWindowActionPalette;

typedef struct Pal_80244108 {
    s32 f0;
    u8 pad4[0x14];
    u32 *vt;
    u8 pad1c[4];
    s16 slot;
    u8 pad22[0x36];
    f32 f58;
    u8 pad5c[4];
    u8 arr[0xC];
    s8 f6c;
    u8 pad6d[3];
    f32 f70;
    f32 f74;
} Pal_80244108;

struct Rect_80243B6C { f32 x0, y0, x1, y1, u0, v0, u1, v1; };

struct Ctx_80243B6C { f32 x; f32 y; u8 pad8[0x34 - 0x8]; s32 tex; };

struct Obj_80243968 { u8 pad[0x20]; s16 id; u8 pad22[0x3e]; u32 cur[3]; };

struct Ent_80243968 { u8 pad[0x2c]; s32 color; };

extern "C" {
void* get_array_entry__11TWindowBaseFi(TWindowActionPalette*,int);
s32 is_split_screen();
s32 fn_8002AE08(s32);
s32 is_on_current_screen__11TCameraCtrlFv(void *, s32);
u16 select_action_palette_and_apply__10TObjPlayerFlll(int, int, int, int);
s32 get_player_by_client_id(int);
u16 get_entry_by_index__20TWindowActionPaletteFPll(int, int);
s32 get_slot_type_for_index__20TWindowActionPaletteFPll(int, int);
s32 set_help_text__15TWindowHelpItemFll(void *, int);
s32 is_action_channel_available__10TObjPlayerFii(s32, s32);
void update_palette_item_count_label(void *, void *, int, u16, s32);
void draw_action_palette_icon(void *, int, u16);
extern const u8 lbl_805DCA10[4];
extern const u8 lbl_805DCA14[4];
extern const u8 lbl_805DCA18[4];
s32 is_player_input_active(int);
s32 TObjPlayer__sub_80354D5C(int);
extern u8 controller_input_state[];
void run_task__20TWindowActionPaletteFv(u8 *arg0);
s32 get_window_layout_position(s32);
void *__construct_array(void *, void *, void *, u32, u32);
s32 init_gc_tag(s32 arg0);
extern u8 twindow_action_palette_layout[];
extern u32 __vt__20TWindowActionPalette[6];
extern s32 lbl_805D3870;
extern const f32 lbl_805DCA2C;
extern const f32 lbl_805DCA48;
extern const f32 lbl_805DCAA0;
extern const f32 lbl_805DCAA4;
Pal_80244108 *TWindowActionPalette__ct(Pal_80244108 *self, s16 slot);
f32 TWindowSubComCard__sub_80244784(TWindowSubComCard *);
s32 TWindowSubComCard__sub_802452DC(int);
s32 TWindowSubComCard__sub_80245320(void *, void *);
s32 TWindowSubComCard__sub_802454E4(int);
s32 TWindowSubComCard__sub_80245558(void *, void *, void *);
s32 apply_context_transform_to_rect(void *, void *);
s32 begin_screen_draw(int);
s32 draw_textured_quad_at_depth(void *, f32);
s32 set_draw_texture_and_color(int, int);
extern s32 lbl_805D63F0;
extern const f32 lbl_805DCA24;
extern const f32 lbl_805DCA34;
extern const f32 lbl_805DCA4C;
extern const f32 lbl_805DCA50;
extern const f32 lbl_805DCA54;
extern const f32 lbl_805DCA58;
extern const f32 lbl_805DCA5C;
extern const f32 lbl_805DCA60;
extern const f32 lbl_805DCA64;
extern const f32 lbl_805DCA68;
extern const f32 lbl_805DCA6C;
extern const f32 lbl_805DCA70;
extern const f32 lbl_805DCA74;
extern const f32 lbl_805DCA78;
extern const f32 lbl_805DCA7C;
extern const f32 lbl_805DCA80;
extern const f32 lbl_805DCA84;
extern const f32 lbl_805DCA88;
extern const f32 lbl_805DCA8C;
extern const f32 lbl_805DCA90;
extern const f32 lbl_805DCA94;
extern const f32 lbl_805DCA98;
extern const f32 lbl_805DCA9C;
s32 TObjPlayer__sub_80354C7C(s32);
s32 setup_window_draw_context__11TWindowBaseFl(void *, void *);
void draw_visible_window_entries(void *, void *, int);
void __dl__7TObjectFPv(void *);
void __destroy_arr(void *, void *, int, int);
}
void set_sprite_uv_from_pixels(u8 *arg0, f32 farg0, f32 farg1);
extern float TWindowActionPalette__bank_panel_uv_origins[][2];

void TWindowActionPalette::set_bank_panel_art(unsigned short state) {
    void* sprite=get_array_entry__11TWindowBaseFi(this,1);
    set_sprite_uv_from_pixels((u8 *)sprite, TWindowActionPalette__bank_panel_uv_origins[state][0], TWindowActionPalette__bank_panel_uv_origins[state][1]);
}

#define self ((Obj_80243968 *)arg0)
void TWindowActionPalette::update_slot_icon(void *arg0, int idx, int mode, int slot) {
    if (((u32 (*)(int))get_player_by_client_id)(self->id) != 0) {
        Ent_80243968 *ent = (Ent_80243968 *)((void *)get_array_entry__11TWindowBaseFi((TWindowActionPalette*)(self), 4));
        if (TObjPlayer__sub_80354C7C((u16)self->id) != 0) {
            ent->color = -1;
        } else {
            ent->color = 0xFF404040;
        }
        ((TWindowHelpItem *)((void *)get_array_entry__11TWindowBaseFi((TWindowActionPalette*)(self), 5)))->set_flag0_bit2();
        void *cur = &self->cur[idx];
        if ((u16)mode != ((TMainCursor *)cur)->get_type() || ((TMainCursor *)cur)->get_enabled() != (u16)slot) {
            ((TWindowActionPalette *)cur)->set_mode(mode);
            ((TWindowActionPalette *)cur)->set_slot(slot);
            ((void (*)(void *, int, int))draw_action_palette_icon)(ent, mode, slot);
        }
    }
}
#undef self

void TWindowActionPalette::update_slot_sprites(int idx, int mode, u16 slot) {
    s32 player;
    u8 *help;
    u8 *cursor;

    player = get_player_by_client_id(this->m_20);
    if (player != 0) {
        help = (u8 *)get_array_entry__11TWindowBaseFi((TWindowActionPalette *)this, lbl_805DCA10[idx]);
        if (is_action_channel_available__10TObjPlayerFii(player, lbl_805DCA14[idx]) != 0) {
            *(s32 *)(help + 0x2C) = -1;
        } else {
            *(s32 *)(help + 0x2C) = 0xFF404040;
        }
        update_palette_item_count_label(get_array_entry__11TWindowBaseFi((TWindowActionPalette *)this, lbl_805DCA18[idx]), help, mode, slot, this->m_20);
        cursor = (u8 *)this + 0x60 + idx * 4;
        if ((u16)mode != ((TMainCursor *)cursor)->get_type() || ((TMainCursor *)cursor)->get_enabled() != slot) {
            ((TWindowActionPalette *)cursor)->set_mode(mode);
            ((TWindowActionPalette *)cursor)->set_slot(slot);
            draw_action_palette_icon(help, mode, slot);
        }
    }
}

#define SELF ((TWindowActionPalette *)arg0)

#pragma push
#pragma fp_contract on
void TWindowActionPalette::draw_frame(int arg1) {
    Rect_80243B6C r1;
    Rect_80243B6C r2;
    Rect_80243B6C r4;
    Rect_80243B6C r3;
    Ctx_80243B6C *ctx = (Ctx_80243B6C *)arg1;
    f32 scale;
    f32 depth;
    scale = TWindowSubComCard__sub_80244784((TWindowSubComCard *)this);
    depth = lbl_805DCA48 / this->m_54;
    begin_screen_draw(1);
    TObjFish::set_global_param((s32)((void *)lbl_805D63F0));
    set_draw_texture_and_color(2, ctx->tex);
    if (is_split_screen() == 0) {
        r1.x0 = lbl_805DCA4C - lbl_805DCA50 * scale;
        r1.y0 = lbl_805DCA54 - lbl_805DCA58 * scale;
        r1.x1 = lbl_805DCA50 + r1.x0;
        r1.y1 = lbl_805DCA5C + r1.y0;
        r1.u0 = lbl_805DCA24;
        r1.v0 = lbl_805DCA60;
        r1.u1 = lbl_805DCA64;
        r1.v1 = lbl_805DCA68;
        draw_textured_quad_at_depth(&r1, depth);
    }
    r2.x0 = lbl_805DCA6C + ctx->x;
    r2.y0 = ctx->y;
    r2.x1 = lbl_805DCA70 + r2.x0;
    r2.y1 = lbl_805DCA74 + r2.y0;
    r2.u0 = lbl_805DCA24;
    r2.v0 = lbl_805DCA78;
    r2.u1 = lbl_805DCA7C;
    r2.v1 = lbl_805DCA80;
    apply_context_transform_to_rect(ctx, &r2);
    draw_textured_quad_at_depth(&r2, depth);
    r3.x0 = lbl_805DCA84 + ctx->x;
    r3.y0 = lbl_805DCA88 + ctx->y;
    r3.x1 = lbl_805DCA70 + r3.x0;
    r3.y1 = lbl_805DCA74 + r3.y0;
    r3.u0 = lbl_805DCA8C;
    r3.v0 = lbl_805DCA78;
    r3.u1 = lbl_805DCA90;
    r3.v1 = lbl_805DCA80;
    apply_context_transform_to_rect(ctx, &r3);
    draw_textured_quad_at_depth(&r3, depth);
    r4.x0 = ctx->x;
    r4.y0 = ctx->y;
    r4.x1 = lbl_805DCA34 + r4.x0;
    r4.y1 = lbl_805DCA94 + r4.y0;
    r4.v0 = r4.u0 = lbl_805DCA24;
    r4.u1 = lbl_805DCA98;
    r4.v1 = lbl_805DCA9C;
    apply_context_transform_to_rect(ctx, &r4);
    draw_textured_quad_at_depth(&r4, depth);
    TWindowSubStatusDisp::get_player();
    if (TWindowSubComCard__sub_80245558(ctx, (u8 *)ctx + 0x10, (u8 *)ctx + 0x18) != 0) {
        TWindowSubComCard__sub_802454E4(2);
        TWindowSubComCard__sub_80245320(&r4, ctx);
        TWindowSubComCard__sub_802452DC(2);
    }
}
#pragma pop

void TWindowActionPalette::render() {
    s32 context = setup_window_draw_context__11TWindowBaseFl(this, &scale);
    draw_visible_window_entries(this, &children, context);
    draw_frame(context);
}

void run_task__20TWindowActionPaletteFv(u8 *arg0) {
    s32 player;
    s32 effect;
    s32 slot;
    u16 v;
    u16 target;
    u8 cnt;
    u8 *help;
    player = get_player_by_client_id(((TWindowActionPalette *)arg0)->m_20);
    if (player == 0 || (effect = ((TObjPlayer *)player)->refresh_effect()) == 0) {
        return;
    }
    if (!(*(s32 *)((s8 *)arg0 + 0x2C) & 2)) {
        ((TWindowActionPalette *)arg0)->m_5c = 0x01000000;
    }
    slot = is_player_input_active(((TWindowActionPalette *)arg0)->m_20);
    if (is_on_current_screen__11TCameraCtrlFv(controller_input_state + slot * 0x50 + 0x20, fn_8002AE08(((TWindowActionPalette *)arg0)->m_20)) != 0) {
        ((TWindowActionPalette *)arg0)->state = 3;
    }
    help = (u8 *)get_array_entry__11TWindowBaseFi(SELF, 0);
    set_help_text__15TWindowHelpItemFll(help, ((TWindowActionPalette *)arg0)->m_20);
    cnt = ((TWindowActionPalette *)arg0)->state;
    if ((s8)cnt > 0) {
        ((TWindowActionPalette *)arg0)->state = cnt - 1;
        ((TWindowHelpItem *)help)->m_2c = -1;
    } else {
        ((TWindowHelpItem *)help)->m_2c = 0xFF666666;
    }
    v = select_action_palette_and_apply__10TObjPlayerFlll(player, 0, 0, 0);
    if (v == 0) {
        v = get_entry_by_index__20TWindowActionPaletteFPll(effect, 1);
        ((TWindowActionPalette *)arg0)->update_slot_sprites(0, get_slot_type_for_index__20TWindowActionPaletteFPll(effect, 1), v);
    } else {
        ((TWindowActionPalette *)arg0)->update_slot_sprites(0, 7, v);
    }
    if (TObjPlayer__sub_80354D5C((u16)((TWindowActionPalette *)arg0)->m_20) != 0 && ((TWindowActionPalette *)(player + 0x500))->handle_input_forward() != 0) {
        TWindowActionPalette::update_slot_icon(arg0, 1, 7, 7);
    } else {
        v = get_entry_by_index__20TWindowActionPaletteFPll(effect, 2);
        ((TWindowActionPalette *)arg0)->update_slot_sprites(1, get_slot_type_for_index__20TWindowActionPaletteFPll(effect, 2), v);
    }
    v = get_entry_by_index__20TWindowActionPaletteFPll(effect, 3);
    ((TWindowActionPalette *)arg0)->update_slot_sprites(2, get_slot_type_for_index__20TWindowActionPaletteFPll(effect, 3), v);
    target = TObjPlayer::get_current_target_id();
    if (target == 0xFFFF || target == ((TWindowActionPalette *)arg0)->m_20 || ((TObjPlayer *)player)->get_photon_blast_charge() <= 0) {
        if (((TWindowActionPalette *)(player + 0x500))->handle_input_forward() != 0) {
            if (is_split_screen() != 0) {
                ((TWindowActionPalette *)SELF)->set_bank_panel_art(3);
            } else {
                ((TWindowActionPalette *)SELF)->set_bank_panel_art(0);
            }
        } else {
            ((TWindowActionPalette *)SELF)->set_bank_panel_art(1);
        }
    } else {
        ((TWindowActionPalette *)SELF)->set_bank_panel_art(2);
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list(arg0 + 0x24);
}

extern "C" u8 *__dt__20TWindowActionPaletteFv(u8 *self, s16 delete_flag) {
    if (self != NULL) {
        *(u32 **)(self + 0x18) = __vt__20TWindowActionPalette;
        __destroy_arr(self + 0x60,
                               (void *)TPlyDispConfig::free_if_valid, 4, 3);
        ((TWindowDD *)self)->destroy_window_base(0);
        if (delete_flag > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
Pal_80244108 *TWindowActionPalette__ct(Pal_80244108 *self, s16 slot) {
    u32 i;
    ((TWindowDD *)self)->construct_base((u8 *)twindow_action_palette_layout, (s16)slot, (u8 *)(get_window_layout_position(0x1F)));
    self->vt = __vt__20TWindowActionPalette;
    __construct_array(self->arr, (void *)init_gc_tag, (void *)TPlyDispConfig::free_if_valid, 4, 3);
    self->f0 = lbl_805D3870;
    if (TCameraCtrl::get_camera_id() > 2) {
        self->f70 = lbl_805DCA2C;
        self->f74 = lbl_805DCA2C;
    } else if (TCameraCtrl::get_camera_id() == 2) {
        self->f70 = lbl_805DCAA0;
        self->f74 = lbl_805DCAA0;
    } else {
        self->f70 = lbl_805DCAA4;
        self->f74 = lbl_805DCAA4;
    }
    self->f58 = lbl_805DCA48;
    self->f6c = 0;
    self->slot = slot;
    for (i = 0; i < 3; i++) {
        ((TWindowActionPalette *)(self->arr))->set_mode(0);
        ((TWindowActionPalette *)(self->arr))->set_slot(0);
    }
    return self;
}
