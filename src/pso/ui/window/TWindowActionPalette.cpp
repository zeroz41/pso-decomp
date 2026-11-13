#include "types.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TPlyDispData.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowEffectLight.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_802598E4.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025B050.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/unk/text_80072004.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include <stddef.h>

// Built with deferred code generation: data come first, functions come out
// in reverse source order (so they are written last to first).
#pragma defer_codegen on

typedef char palette_children_offset[offsetof(TWindowActionPalette, children) == 0x24 ? 1 : -1];
typedef char palette_x_offset[offsetof(TWindowActionPalette, x) == 0x40 ? 1 : -1];
typedef char palette_resources_offset[offsetof(TWindowActionPalette, resources) == 0x60 ? 1 : -1];
typedef char palette_state_offset[offsetof(TWindowActionPalette, state) == 0x6C ? 1 : -1];
typedef char palette_scale_offset[offsetof(TWindowActionPalette, scale) == 0x70 ? 1 : -1];
typedef char palette_size[sizeof(TWindowActionPalette) == 0x78 ? 1 : -1];
typedef char icon_kind_offset[offsetof(Icon_80243630, kind) == 0x34 ? 1 : -1];

#pragma push
#pragma readonly_strings on
const char *TWindowActionPalette__name = "TWindowActionPalette";
#pragma pop

struct PaletteItemKind { u8 group; u8 index; };

struct Rect_80243B6C { f32 x0, y0, x1, y1, u0, v0, u1, v1; };

struct Ctx_80243B6C { f32 x; f32 y; u8 pad8[0x34 - 0x8]; s32 tex; };

struct Pt_802437C4 { f32 x, y; };

extern "C" {
s8 clamp_char_at__10TObjPlayerFl(u32, s32);
s32 fn_801B7CEC(void *player, s32 kind, u8 group, u8 index);
s32 fn_8002AE08(s32);
s32 is_on_current_screen__11TCameraCtrlFv(void *, s32);
u16 select_action_palette_and_apply__10TObjPlayerFlll(TObjPlayer *, int, int, int);
u16 get_entry_by_index__20TWindowActionPaletteFPll(int, int);
u16 get_slot_type_for_index__20TWindowActionPaletteFPll(int, int);
s32 is_action_channel_available__10TObjPlayerFii(TObjPlayer *, s32);
s32 TObjPlayer__sub_80354D5C(int);
s32 TObjPlayer__sub_80354C7C(s32);
extern u8 controller_input_state[];
s32 get_window_layout_position(s32);
void *__construct_array(void *, void *, void *, u32, u32);
extern u32 __vt__20TWindowActionPalette[6];
f32 TWindowSubComCard__sub_80244784(TWindowSubComCard *);
s32 TWindowSubComCard__sub_802452DC(int);
s32 TWindowSubComCard__sub_80245320(void *, void *);
s32 TWindowSubComCard__sub_802454E4(int);
s32 TWindowSubComCard__sub_80245558(void *, void *, void *);
s32 apply_context_transform_to_rect(void *, void *);
extern s32 lbl_805D63F0;
void draw_visible_window_entries(void *, void *, int);
void __dl__7TObjectFPv(void *);
void __destroy_arr(void *, void *, int, int);
}

const PaletteItemKind lbl_8044E5E8[13] = {
    {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {6, 0},
    {6, 1}, {3, 0}, {4, 0}, {5, 0}, {7, 0}, {8, 0},
};

struct UV_80243630 { f32 u; f32 v; };

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

const f32 TWindowActionPalette__bank_panel_uv_origins[4][2] = {
    {0.0f, 0.0f}, {0.0f, 56.0f}, {0.0f, 112.0f}, {92.0f, 112.0f},
};

const u8 lbl_805DCA10[3] = {2, 4, 6};
const u8 lbl_805DCA14[3] = {1, 2, 3};
const u8 lbl_805DCA18[3] = {3, 5, 7};

struct ActionPaletteWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    SpritePartLayoutRecord rec_1;
    SpritePartLayoutRecord rec_2;
    ValueLayoutRecord rec_3;
    SpritePartLayoutRecord rec_4;
    ValueLayoutRecord rec_5;
    SpritePartLayoutRecord rec_6;
    ValueLayoutRecord rec_7;
};

ActionPaletteWindowLayout lbl_804CDE50 = {
    8, 1,
    {6, {45.0f, 53.0f}, {91.0f, 54.0f}, 92.0f, 0.0f, 0.4f, 0xFF666666, &lbl_805D63F0, 0, 0x14},
    {6, {13.0f, 0.0f}, {91.0f, 54.0f}, 0.0f, 0.0f, 0.4f, -1, &lbl_805D63F0, 0, 0x14},
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

TWindowActionPalette *TWindowActionPalette__ct(TWindowActionPalette *self, s16 slot) {
    u32 i;
    ((TWindowDD *)self)->construct_base((u8 *)&twindow_action_palette_layout, (s16)slot, (u8 *)(get_window_layout_position(0x1F)));
    *(u32 **)((u8 *)self + 0x18) = __vt__20TWindowActionPalette;
    __construct_array(self->resources, (void *)init_gc_tag, (void *)TPlyDispConfig::free_if_valid, 4, 3);
    self->m_name = TWindowActionPalette__name;
    if (TCameraCtrl::get_camera_id() > 2) {
        self->scale.x = 0.5f;
        self->scale.y = 0.5f;
    } else if (TCameraCtrl::get_camera_id() == 2) {
        self->scale.x = 0.7f;
        self->scale.y = 0.7f;
    } else {
        self->scale.x = 1.0f;
        self->scale.y = 1.0f;
    }
    self->m_58 = -1.0f;
    self->state = 0;
    self->m_20 = slot;
    for (i = 0; i < 3; i++) {
        ((TWindowActionPalette *)self->resources)->set_mode(0);
        ((TWindowActionPalette *)self->resources)->set_slot(0);
    }
    return self;
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

void TWindowActionPalette::run_task() {
    TObjPlayer *player;
    s32 effect;
    s32 slot;
    u16 v;
    u16 target;
    u8 cnt;
    u8 *help;
    player = get_player_by_client_id(m_20);
    if (player == NULL || (effect = player->refresh_effect()) == 0) {
        return;
    }
    if (!(*(s32 *)((s8 *)this + 0x2C) & 2)) {
        m_5c = 0x01000000;
    }
    slot = is_player_input_active(m_20);
    if (is_on_current_screen__11TCameraCtrlFv(controller_input_state + slot * 0x50 + 0x20, fn_8002AE08(m_20)) != 0) {
        state = 3;
    }
    help = (u8 *)get_array_entry(0);
    TWindowHelpItem::set_help_text((s32)help, m_20);
    cnt = state;
    if ((s8)cnt > 0) {
        state = cnt - 1;
        ((TWindowHelpItem *)help)->m_2c = -1;
    } else {
        ((TWindowHelpItem *)help)->m_2c = 0xFF666666;
    }
    v = select_action_palette_and_apply__10TObjPlayerFlll(player, 0, 0, 0);
    if (v == 0) {
        v = get_entry_by_index__20TWindowActionPaletteFPll(effect, 1);
        update_slot_sprites(0, get_slot_type_for_index__20TWindowActionPaletteFPll(effect, 1), v);
    } else {
        update_slot_sprites(0, 7, v);
    }
    if (TObjPlayer__sub_80354D5C((u16)m_20) != 0 && ((TWindowActionPalette *)((u8 *)player + 0x500))->handle_input_forward() != 0) {
        update_slot_icon(1, 7, 7);
    } else {
        v = get_entry_by_index__20TWindowActionPaletteFPll(effect, 2);
        update_slot_sprites(1, get_slot_type_for_index__20TWindowActionPaletteFPll(effect, 2), v);
    }
    v = get_entry_by_index__20TWindowActionPaletteFPll(effect, 3);
    update_slot_sprites(2, get_slot_type_for_index__20TWindowActionPaletteFPll(effect, 3), v);
    target = TObjPlayer::get_current_target_id();
    if (target == 0xFFFF || target == m_20 || player->get_photon_blast_charge() <= 0) {
        if (((TWindowActionPalette *)((u8 *)player + 0x500))->handle_input_forward() != 0) {
            if (is_split_screen() != 0) {
                set_bank_panel_art(3);
            } else {
                set_bank_panel_art(0);
            }
        } else {
            set_bank_panel_art(1);
        }
    } else {
        set_bank_panel_art(2);
    }
    ((TWindowDD *)this)->initialize_subwindow();
    update_fade();
    update_window_entry_list(&children);
}

void TWindowActionPalette::render() {
    s32 context = setup_window_draw_context((s32)&scale);
    draw_visible_window_entries(this, &children, context);
    draw_frame(context);
}

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
        draw_textured_quad_at_depth((f32 *)&r1, depth);
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
    draw_textured_quad_at_depth((f32 *)&r2, depth);
    r3.x0 = 45.0f + ctx->x;
    r3.y0 = 53.0f + ctx->y;
    r3.x1 = 91.0f + r3.x0;
    r3.y1 = 54.0f + r3.y0;
    r3.u0 = 0.36328125f;
    r3.v0 = 0.421875f;
    r3.u1 = 0.71875f;
    r3.v1 = 0.6328125f;
    apply_context_transform_to_rect(ctx, &r3);
    draw_textured_quad_at_depth((f32 *)&r3, depth);
    r4.x0 = ctx->x;
    r4.y0 = ctx->y;
    r4.x1 = 150.0f + r4.x0;
    r4.y1 = 107.0f + r4.y0;
    r4.v0 = r4.u0 = 0.0f;
    r4.u1 = 0.5859375f;
    r4.v1 = 0.41796875f;
    apply_context_transform_to_rect(ctx, &r4);
    draw_textured_quad_at_depth((f32 *)&r4, depth);
    TWindowSubStatusDisp::get_player();
    if (TWindowSubComCard__sub_80245558(ctx, (u8 *)ctx + 0x10, (u8 *)ctx + 0x18) != 0) {
        TWindowSubComCard__sub_802454E4(2);
        TWindowSubComCard__sub_80245320(&r4, ctx);
        TWindowSubComCard__sub_802452DC(2);
    }
}
#pragma pop

void TWindowActionPalette::update_slot_sprites(int idx, u16 mode, u16 slot) {
    TObjPlayer *player;
    Icon_80243630 *help;
    u8 *cursor;

    player = get_player_by_client_id(m_20);
    if (player != NULL) {
        help = (Icon_80243630 *)get_array_entry(lbl_805DCA10[idx]);
        if (is_action_channel_available__10TObjPlayerFii(player, lbl_805DCA14[idx]) != 0) {
            help->color = -1;
        } else {
            help->color = 0xFF404040;
        }
        update_palette_item_count_label((TWindowHelpItem *)get_array_entry(lbl_805DCA18[idx]), help, mode, slot, m_20);
        cursor = resources[idx];
        if (mode != ((TMainCursor *)cursor)->get_type() || ((TMainCursor *)cursor)->get_enabled() != slot) {
            ((TWindowActionPalette *)cursor)->set_mode(mode);
            ((TWindowActionPalette *)cursor)->set_slot(slot);
            draw_action_palette_icon(help, mode, slot);
        }
    }
}

void TWindowActionPalette::update_slot_icon(int idx, u16 mode, u16 slot) {
    if (get_player_by_client_id(m_20) != NULL) {
        Icon_80243630 *icon = (Icon_80243630 *)get_array_entry(4);
        if (TObjPlayer__sub_80354C7C((u16)m_20) != 0) {
            icon->color = -1;
        } else {
            icon->color = 0xFF404040;
        }
        ((TWindowHelpItem *)get_array_entry(5))->set_flag0_bit2();
        void *cur = &resources[idx];
        if (mode != ((TMainCursor *)cur)->get_type() || ((TMainCursor *)cur)->get_enabled() != slot) {
            ((TWindowActionPalette *)cur)->set_mode(mode);
            ((TWindowActionPalette *)cur)->set_slot(slot);
            draw_action_palette_icon(icon, mode, slot);
        }
    }
}

void TWindowActionPalette::set_bank_panel_art(unsigned short state) {
    u8 *sprite = (u8 *)get_array_entry(1);
    set_sprite_uv_from_pixels(sprite, TWindowActionPalette__bank_panel_uv_origins[state][0], TWindowActionPalette__bank_panel_uv_origins[state][1]);
}

#pragma push
#pragma fp_contract on
void spawn_action_palette_slot_light(TWindowActionPalette *palette, s32 slot) {
    Pt_802437C4 pt;
    s32 kind;
    Icon_80243630 *e;
    f32 s;
    f32 hw;
    f32 s2;
    f32 hw2;
    if (palette->sub_80244994() == 0) {
        return;
    }
    switch (slot) {
    case 1:
        kind = 0;
        e = (Icon_80243630 *)palette->get_array_entry(2);
        break;
    case 2:
        kind = 2;
        e = (Icon_80243630 *)palette->get_array_entry(4);
        break;
    case 3:
        kind = 1;
        e = (Icon_80243630 *)palette->get_array_entry(6);
        break;
        return;
    default:
        return;
    }
    if (is_split_screen() != 0) {
        hw = 0.5f * palette->w;
        s = palette->scale.x;
        pt.x = s * ((0.5f * e->w + e->x) - hw) + (hw * s + palette->x);
        hw2 = 0.5f * palette->h;
        s2 = palette->scale.y;
        pt.y = s2 * ((0.5f * e->h + e->y) - hw2) + (hw2 * s2 + palette->y);
    } else {
        pt.x = 0.5f * e->w + (palette->x + e->x);
        pt.y = 0.5f * e->h + (palette->y + e->y);
    }
    TWindowEffectLight::create(&pt, (void *)kind, (void *)palette->m_20);
}
#pragma pop

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
        row = lbl_804CDDF8;
        icon->u0 = row[index].u;
        icon->v0 = row[index].v;
        break;
    case 3:
        icon->kind = 3;
        row = action_palette_icon_uv_tables;
        icon->u0 = row[index].u;
        icon->v0 = row[index].v;
        break;
    case 4:
        if (index >= 13) {
            icon->kind = 5;
        } else {
            icon->kind = 4;
        }
        row = lbl_804CDD40;
        icon->u0 = row[index].u;
        icon->v0 = row[index].v;
        break;
    case 5:
        icon->kind = 3;
        row = lbl_804CDDC8;
        icon->u0 = row[index].u;
        icon->v0 = row[index].v;
        break;
    case 7:
        if (index >= 7) {
            icon->kind = 5;
        } else {
            icon->kind = 4;
        }
        row = lbl_804CDE10;
        icon->u0 = row[index].u;
        icon->v0 = row[index].v;
        break;
    }
    icon->u1 = 50.0f + icon->u0;
    icon->v1 = 43.0f + icon->v0;
    icon->u0 = icon->u0 / 256.0f;
    icon->v0 = icon->v0 / 256.0f;
    icon->u1 = icon->u1 / 256.0f;
    icon->v1 = icon->v1 / 256.0f;
}

#pragma push
#pragma fp_contract on
void update_palette_item_count_label(TWindowHelpItem *window_help_item, Icon_80243630 *icon, u16 group, u16 index, s32 client_id) {
    s32 v;
    u32 p;
    if (group != 4) {
        window_help_item->set_flag0_bit2();
        return;
    }
    if (index >= 0xD) {
        p = (u32)get_player_by_client_id(client_id);
        if (p == 0) {
            v = 0;
        } else {
            v = clamp_char_at__10TObjPlayerFl(p + 0x7C4, index - 0xD);
        }
    } else {
        v = TWindowHelpItem::get_help_value(index, client_id);
    }
    if (v <= 0) {
        window_help_item->set_flag0_bit2();
        return;
    }
    ((TWindowSubStatusDisp *)window_help_item)->clear_visible_flag();
    *(s32 *)((s8 *)window_help_item + 0x1C) = icon->color;
    *(s32 *)((s8 *)window_help_item + 0x20) = v;
    draw_right_aligned_number(window_help_item);
    window_help_item->m_8 = (icon->x - -25.0f) + 0.5f * *(f32 *)((s8 *)window_help_item + 0x10);
    *(f32 *)((s8 *)window_help_item + 0xC) = icon->y - -28.0f;
}
#pragma pop

s32 get_palette_consumable_count(u16 slot, s32 client_id) {
    TObjPlayer *player = get_player_by_client_id(client_id);
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

// The amount of the item in palette slot `slot` of the player `client_id`
// (0 when the slot holds no item).
s32 TWindowHelpItem::get_help_value(u16 slot, s32 client_id) {
    s32 id = get_palette_consumable_count(slot, client_id);
    if (id == -1) {
        return 0;
    }
    TItem *item = find_item_by_id(id);
    if (item == NULL) {
        return 0;
    }
    return item->get_amount();
}

void TWindowHelpItem::set_help_text(s32 arg0, s32 arg1) {
    if (((TBoss8Dragon *)arg1)->test_card_flag_2() != 0) {
        set_sprite_uv_from_pixels((u8 *)arg0, 92.0f, 56.0f);
        return;
    }
    set_sprite_uv_from_pixels((u8 *)arg0, 92.0f, 0.0f);
}
