#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/player/TPlyDispData.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowBase.h"
#include <stddef.h>
#include "types.h"
#include "pso/item/mag/TItemMag.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/item/TItem.h"
#include "pso/ui/window/TWindowHelpItem_80243408.h"
#include "pso/ui/window/TWindowSubStatusDisp_802598E4.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/ui/window/TWindowEffectLight.h"

#include "pso/unk/WindowLayoutRecord.h"

struct PaletteItemKind { u8 group; u8 index; };

static const char TWindowActionPalette__class_name_string[] = "TWindowActionPalette";
extern const PaletteItemKind lbl_8044E5E8[13];
const PaletteItemKind lbl_8044E5E8[13] = {
    {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {6, 0},
    {6, 1}, {3, 0}, {4, 0}, {5, 0}, {7, 0}, {8, 0},
};
extern const float TWindowActionPalette__bank_panel_uv_origins[4][2];
const float TWindowActionPalette__bank_panel_uv_origins[4][2] = {
    {0.0f, 0.0f}, {0.0f, 56.0f}, {0.0f, 112.0f}, {92.0f, 112.0f},
};

extern "C" {
extern const char *lbl_805D3870;
const char *lbl_805D3870 = TWindowActionPalette__class_name_string;

extern const u8 lbl_805DCA10[4] = {2, 4, 6, 0};
extern const u8 lbl_805DCA14[4] = {1, 2, 3, 0};
extern const u8 lbl_805DCA18[4] = {3, 5, 7, 0};
}

struct Base_80243464 { char pad[0x18]; };
struct VObj_80243464 : Base_80243464 {
    virtual void m0();   virtual void m1();   virtual void m2();   virtual void m3();
    virtual void m4();   virtual void m5();   virtual void m6();   virtual void m7();
    virtual void m8();   virtual void m9();   virtual void m10();  virtual void m11();
    virtual void m12();  virtual void m13();  virtual void m14();  virtual void m15();
    virtual void m16();  virtual void m17();  virtual void m18();  virtual void m19();
    virtual void m20();  virtual void m21();  virtual void m22();  virtual void m23();
    virtual void m24();  virtual void m25();  virtual void m26();  virtual void m27();
    virtual void m28();  virtual void m29();  virtual void m30();  virtual void m31();
    virtual void m32();  virtual void m33();  virtual s32 m34();
};

struct Icon_80243630 {
    u8 pad0[0x1C];
    f32 u0;
    f32 v0;
    f32 u1;
    f32 v1;
    u8 pad2c[0x34 - 0x2C];
    s32 kind;
};

struct UV_80243630 { f32 u; f32 v; };


extern "C" {
void *get_player_by_client_id(s32 i);
s8 clamp_char_at__10TObjPlayerFl(u32, s32);
void draw_action_palette_icon(Icon_80243630 *icon, u16 group, u16 index);
s32 fn_801B7CEC(void *player, s32 kind, u8 group, u8 index);
}
s32 get_palette_consumable_count(u16 slot, s32 client_id);
void set_sprite_uv_from_pixels(u8 *arg0, f32 farg0, f32 farg1);


void TWindowHelpItem::set_help_text(s32 arg0, s32 arg1) {
    if (((TBoss8Dragon *)arg1)->test_card_flag_2() != 0) {
        set_sprite_uv_from_pixels((u8 *)arg0, 92.0f, 56.0f);
        return;
    }
    set_sprite_uv_from_pixels((u8 *)arg0, 92.0f, 0.0f);
}

s32 get_help_value__15TWindowHelpItemFv(void) {
    struct VObj_80243464 *o;

    s32 id = ((s32 (*)(void))get_palette_consumable_count)();
    if (id == -1) {
        return 0;
    }
    o = (struct VObj_80243464 *)find_item_by_id(id);
    if (o == NULL) {
        return 0;
    }
    return o->m34();
}

s32 get_palette_consumable_count(u16 slot, s32 client_id) {
    void *player = get_player_by_client_id(client_id);
    if (player == NULL) {
        return -1;
    }
    if (slot >= 13) {
        if (clamp_char_at__10TObjPlayerFl((u32)player + 0x7C4, slot - 13) > 0) {
            return slot;
        }
        return -1;
    }
    const PaletteItemKind *kind = &lbl_8044E5E8[slot];
    return fn_801B7CEC(player, 3, kind->group, kind->index);
}
#pragma push
#pragma fp_contract on
void update_palette_item_count_label(TWindowHelpItem *window_help_item, u8 *arg1, u16 arg2, u16 arg3, s32 arg4) {
    s32 v;
    u32 p;
    if (arg2 != 4) {
        window_help_item->set_flag0_bit2();
        return;
    }
    if (arg3 >= 0xD) {
        p = (u32)get_player_by_client_id(arg4);
        if (p == 0) {
            v = 0;
        } else {
            v = clamp_char_at__10TObjPlayerFl(p + 0x7C4, arg3 - 0xD);
        }
    } else {
        v = ((s32 (*)(u16, s32))get_help_value__15TWindowHelpItemFv)(arg3, arg4);
    }
    if (v <= 0) {
        window_help_item->set_flag0_bit2();
        return;
    }
    ((TWindowSubStatusDisp *)window_help_item)->clear_visible_flag();
    *(s32 *)((s8 *)window_help_item + 0x1C) = *(s32 *)((s8 *)arg1 + 0x2C);
    *(s32 *)((s8 *)window_help_item + 0x20) = v;
    draw_right_aligned_number(window_help_item);
    window_help_item->m_8 = (*(f32 *)((s8 *)arg1 + 8) - (-25.0f)) + 0.5f * *(f32 *)((s8 *)window_help_item + 0x10);
    *(f32 *)((s8 *)window_help_item + 0xC) = *(f32 *)((s8 *)arg1 + 0xC) - (-28.0f);
}
#pragma pop

#define TB(x) (x)
UV_80243630 action_palette_icon_uv_tables[19] = {
    {50.0f, 0.0f}, {50.0f, 43.0f}, {50.0f, 86.0f}, {100.0f, 0.0f},
    {100.0f, 43.0f}, {100.0f, 86.0f}, {0.0f, 0.0f}, {0.0f, 43.0f},
    {0.0f, 86.0f}, {200.0f, 0.0f}, {0.0f, 129.0f}, {50.0f, 172.0f},
    {0.0f, 172.0f}, {50.0f, 129.0f}, {200.0f, 86.0f}, {150.0f, 0.0f},
    {150.0f, 86.0f}, {150.0f, 43.0f}, {200.0f, 43.0f},
};
UV_80243630 lbl_804CDD40[17] = {
    {0.0f, 0.0f}, {0.0f, 43.0f}, {0.0f, 86.0f}, {50.0f, 0.0f},
    {50.0f, 43.0f}, {50.0f, 86.0f}, {100.0f, 0.0f}, {50.0f, 129.0f},
    {100.0f, 43.0f}, {0.0f, 172.0f}, {0.0f, 129.0f}, {150.0f, 43.0f},
    {50.0f, 172.0f}, {0.0f, 129.0f}, {0.0f, 0.0f}, {0.0f, 86.0f},
    {0.0f, 43.0f},
};
UV_80243630 lbl_804CDDC8[6] = {
    {200.0f, 172.0f}, {150.0f, 129.0f}, {150.0f, 172.0f}, {200.0f, 129.0f},
    {100.0f, 172.0f}, {100.0f, 129.0f},
};
UV_80243630 lbl_804CDDF8[3] = {
    {200.0f, 43.0f}, {200.0f, 0.0f}, {200.0f, 86.0f},
};
UV_80243630 lbl_804CDE10[8] = {
    {0.0f, 0.0f}, {100.0f, 129.0f}, {100.0f, 172.0f}, {200.0f, 129.0f},
    {200.0f, 172.0f}, {100.0f, 86.0f}, {100.0f, 86.0f}, {50.0f, 0.0f},
};
extern "C" s32 lbl_805D63F0;

struct ActionPaletteWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord frame;
    SpritePartLayoutRecord help;
    SpritePartLayoutRecord icon_0;
    ValueLayoutRecord count_0;
    SpritePartLayoutRecord icon_1;
    ValueLayoutRecord count_1;
    SpritePartLayoutRecord icon_2;
    ValueLayoutRecord count_2;
};

ActionPaletteWindowLayout lbl_804CDE50 = {
    8, 1,
    {6, {45.0f, 53.0f}, {91.0f, 54.0f}, 92.0f, 0.0f, 0.4f, 0xFF666666, &lbl_805D63F0, 0, 0x14},
    {6, {13.0f, 0.0f}, {91.0f, 54.0f}, 0.0f, 0.0f, 0.4f, 0xFFFFFFFF, &lbl_805D63F0, 0, 0x14},
    {6, {50.0f, 32.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.4f, -1, &lbl_805D63F0, 4, 0x14},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 6, 0},
    {6, {94.0f, 6.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.4f, -1, &lbl_805D63F0, 4, 0x14},
    {4, {34.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 6, 0},
    {6, {6.0f, 58.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.4f, -1, &lbl_805D63F0, 4, 0x14},
    {4, {124.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 6, 0},
};

WindowDescriptor twindow_action_palette_layout = {
    {150.0f, 107.0f}, 50000.0f, &lbl_804CDE50, 0xB28,
};

extern "C" {
u8 *__dt__20TWindowActionPaletteFv(u8 *self, s16 delete_flag);
void run_task__20TWindowActionPaletteFv(u8 *arg0);
void render__20TWindowActionPaletteFv();
void render_shadows__7TObjectFv();
}

void *__vt__20TWindowActionPalette[6] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__20TWindowActionPaletteFv, (void *)&run_task__20TWindowActionPaletteFv,
    (void *)&render__20TWindowActionPaletteFv, (void *)&render_shadows__7TObjectFv,
};

void draw_action_palette_icon(Icon_80243630 *icon, u16 group, u16 index) {
    UV_80243630 *row;
    switch (group) {
    case 0:
        icon->kind = 4;
        icon->u0 = 150.0f;
        icon->v0 = 86.0f;
        break;
    case 2:
        icon->kind = 4;
        row = TB(lbl_804CDDF8);
        icon->u0 = row[index].u;
        icon->v0 = row[index].v;
        break;
    case 3:
        icon->kind = 3;
        row = TB(action_palette_icon_uv_tables);
        icon->u0 = row[index].u;
        icon->v0 = row[index].v;
        break;
    case 4:
        if (index >= 13) {
            icon->kind = 5;
        } else {
            icon->kind = 4;
        }
        row = TB(lbl_804CDD40);
        icon->u0 = row[index].u;
        icon->v0 = row[index].v;
        break;
    case 5:
        icon->kind = 3;
        row = TB(lbl_804CDDC8);
        icon->u0 = row[index].u;
        icon->v0 = row[index].v;
        break;
    case 7:
        if (index >= 7) {
            icon->kind = 5;
        } else {
            icon->kind = 4;
        }
        row = TB(lbl_804CDE10);
        icon->u0 = row[index].u;
        icon->v0 = row[index].v;
        break;
    }
    icon->u1 = 50.0f + icon->u0;
    icon->v1 = 43.0f + icon->v0;
    {
        f32 texel = 0.00390625f;
        icon->u0 = icon->u0 * texel;
        icon->v0 = icon->v0 * texel;
        icon->u1 = icon->u1 * texel;
        icon->v1 = icon->v1 * texel;
    }
}

struct Win_802437C4 {
    u8 pad0[0x20];
    s16 id;
    u8 pad22[0x40 - 0x22];
    f32 x, y, w, h;
    u8 pad50[0x70 - 0x50];
    f32 sx, sy;
};

struct Ent_802437C4 { u8 pad0[8]; f32 x, y, w, h; };

struct Pt_802437C4 { f32 x, y; };

extern "C" {
s32 is_split_screen();
s32 sub_80244994__11TWindowBaseFv();
void spawn_action_palette_slot_light(Win_802437C4 *arg0, s32 arg1);
#pragma push
#pragma fp_contract on
void spawn_action_palette_slot_light(Win_802437C4 *arg0, s32 arg1) {
    Pt_802437C4 pt;
    s32 kind;
    Ent_802437C4 *e;
    f32 s;
    f32 hw;
    f32 s2;
    f32 hw2;
    if (sub_80244994__11TWindowBaseFv() == 0) {
        return;
    }
    switch (arg1) {
    case 1:
        kind = 0;
        e = (Ent_802437C4 *)((TWindowBase *)arg0)->get_array_entry(2);
        break;
    case 2:
        kind = 2;
        e = (Ent_802437C4 *)((TWindowBase *)arg0)->get_array_entry(4);
        break;
    case 3:
        kind = 1;
        e = (Ent_802437C4 *)((TWindowBase *)arg0)->get_array_entry(6);
        break;
        return;
    default:
        return;
    }
    if (is_split_screen() != 0) {
        hw = 0.5f * arg0->w;
        s = arg0->sx;
        pt.x = s * ((0.5f * e->w + e->x) - hw) + (hw * s + arg0->x);
        hw2 = 0.5f * arg0->h;
        s2 = arg0->sy;
        pt.y = s2 * ((0.5f * e->h + e->y) - hw2) + (hw2 * s2 + arg0->y);
    } else {
        pt.x = 0.5f * e->w + (arg0->x + e->x);
        pt.y = 0.5f * e->h + (arg0->y + e->y);
    }
    TWindowEffectLight::create(&pt, (void *)kind, (void *)arg0->id);
}
#pragma pop

}


typedef char palette_children_offset[offsetof(TWindowActionPalette, children) == 0x24 ? 1 : -1];
typedef char palette_resources_offset[offsetof(TWindowActionPalette, resources) == 0x60 ? 1 : -1];
typedef char palette_state_offset[offsetof(TWindowActionPalette, state) == 0x6C ? 1 : -1];
typedef char palette_scale_offset[offsetof(TWindowActionPalette, scale) == 0x70 ? 1 : -1];
typedef char palette_size[sizeof(TWindowActionPalette) == 0x78 ? 1 : -1];



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
s32 fn_8002AE08(s32);
s32 is_on_current_screen__11TCameraCtrlFv(void *, s32);
u16 select_action_palette_and_apply__10TObjPlayerFlll(int, int, int, int);
u16 get_entry_by_index__20TWindowActionPaletteFPll(int, int);
s32 get_slot_type_for_index__20TWindowActionPaletteFPll(int, int);
s32 set_help_text__15TWindowHelpItemFll(void *, int);
s32 is_action_channel_available__10TObjPlayerFii(s32, s32);
s32 is_player_input_active(int);
s32 TObjPlayer__sub_80354D5C(int);
extern u8 controller_input_state[];
void run_task__20TWindowActionPaletteFv(u8 *arg0);
s32 get_window_layout_position(s32);
void *__construct_array(void *, void *, void *, u32, u32);
s32 init_gc_tag(s32 arg0);
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
s32 TObjPlayer__sub_80354C7C(s32);
s32 setup_window_draw_context__11TWindowBaseFl(void *, void *);
void draw_visible_window_entries(void *, void *, int);
void __dl__7TObjectFPv(void *);
void __destroy_arr(void *, void *, int, int);
}
void set_sprite_uv_from_pixels(u8 *arg0, f32 farg0, f32 farg1);

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

    player = (s32)get_player_by_client_id(this->m_20);
    if (player != 0) {
        help = (u8 *)get_array_entry__11TWindowBaseFi((TWindowActionPalette *)this, lbl_805DCA10[idx]);
        if (is_action_channel_available__10TObjPlayerFii(player, lbl_805DCA14[idx]) != 0) {
            *(s32 *)(help + 0x2C) = -1;
        } else {
            *(s32 *)(help + 0x2C) = 0xFF404040;
        }
        ((void (*)(void *, void *, int, u16, s32))update_palette_item_count_label)(get_array_entry__11TWindowBaseFi((TWindowActionPalette *)this, lbl_805DCA18[idx]), help, mode, slot, this->m_20);
        cursor = (u8 *)this + 0x60 + idx * 4;
        if ((u16)mode != ((TMainCursor *)cursor)->get_type() || ((TMainCursor *)cursor)->get_enabled() != slot) {
            ((TWindowActionPalette *)cursor)->set_mode(mode);
            ((TWindowActionPalette *)cursor)->set_slot(slot);
            ((void (*)(void *, int, u16))draw_action_palette_icon)(help, mode, slot);
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
    depth = (-1.0f) / this->m_54;
    begin_screen_draw(1);
    TObjFish::set_global_param((s32)((void *)lbl_805D63F0));
    set_draw_texture_and_color(2, ctx->tex);
    if (is_split_screen() == 0) {
        r1.x0 = 640.0f - 71.0f * scale;
        r1.y0 = 480.0f - 76.0f * scale;
        r1.x1 = 71.0f + r1.x0;
        r1.y1 = 83.0f + r1.y0;
        r1.u0 = 0.0f;
        r1.v0 = 0.63671875f;
        r1.u1 = 0.27734375f;
        r1.v1 = 0.9609375f;
        draw_textured_quad_at_depth(&r1, depth);
    }
    r2.x0 = 13.0f + ctx->x;
    r2.y0 = ctx->y;
    r2.x1 = 91.0f + r2.x0;
    r2.y1 = 54.0f + r2.y0;
    r2.u0 = 0.0f;
    r2.v0 = 0.421875f;
    r2.u1 = 0.35546875f;
    r2.v1 = 0.6328125f;
    apply_context_transform_to_rect(ctx, &r2);
    draw_textured_quad_at_depth(&r2, depth);
    r3.x0 = 45.0f + ctx->x;
    r3.y0 = 53.0f + ctx->y;
    r3.x1 = 91.0f + r3.x0;
    r3.y1 = 54.0f + r3.y0;
    r3.u0 = 0.36328125f;
    r3.v0 = 0.421875f;
    r3.u1 = 0.71875f;
    r3.v1 = 0.6328125f;
    apply_context_transform_to_rect(ctx, &r3);
    draw_textured_quad_at_depth(&r3, depth);
    r4.x0 = ctx->x;
    r4.y0 = ctx->y;
    r4.x1 = 150.0f + r4.x0;
    r4.y1 = 107.0f + r4.y0;
    r4.v0 = r4.u0 = 0.0f;
    r4.u1 = 0.5859375f;
    r4.v1 = 0.41796875f;
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
    player = (s32)get_player_by_client_id(((TWindowActionPalette *)arg0)->m_20);
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
        *(void ***)(self + 0x18) = __vt__20TWindowActionPalette;
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
    ((TWindowDD *)self)->construct_base((u8 *)&twindow_action_palette_layout, (s16)slot, (u8 *)(get_window_layout_position(0x1F)));
    self->vt = (u32 *)__vt__20TWindowActionPalette;
    __construct_array(self->arr, (void *)init_gc_tag, (void *)TPlyDispConfig::free_if_valid, 4, 3);
    self->f0 = (s32)lbl_805D3870;
    if (TCameraCtrl::get_camera_id() > 2) {
        self->f70 = 0.5f;
        self->f74 = 0.5f;
    } else if (TCameraCtrl::get_camera_id() == 2) {
        self->f70 = 0.7f;
        self->f74 = 0.7f;
    } else {
        self->f70 = 1.0f;
        self->f74 = 1.0f;
    }
    self->f58 = (-1.0f);
    self->f6c = 0;
    self->slot = slot;
    for (i = 0; i < 3; i++) {
        ((TWindowActionPalette *)(self->arr))->set_mode(0);
        ((TWindowActionPalette *)(self->arr))->set_slot(0);
    }
    return self;
}
