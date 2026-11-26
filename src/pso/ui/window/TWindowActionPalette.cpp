#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/ui/window/WindowSpritePart.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/unk/TWindowLayoutNumber.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TPlyDispData.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowEffectLight.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_802598E4.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025B050.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/hud/TMainCursor.h"
#include "pso/unk/text_803DA798.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include <stddef.h>
#include "pso/system/ControllerInput.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal_8002ADD8.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/player/PlayerSlots.h"

// Built with deferred code generation: data come first, functions come out
// in reverse source order (so they are written last to first).
#pragma defer_codegen on

LAYOUT_ASSERT(palette_children_offset, offsetof(TWindowActionPalette, entry_list) == 0x24);
LAYOUT_ASSERT(palette_x_offset, offsetof(TWindowActionPalette, frame_position[0]) == 0x40);
LAYOUT_ASSERT(palette_resources_offset, offsetof(TWindowActionPalette, resources) == 0x60);
LAYOUT_ASSERT(palette_state_offset, offsetof(TWindowActionPalette, state) == 0x6C);
LAYOUT_ASSERT(palette_scale_offset, offsetof(TWindowActionPalette, scale) == 0x70);
LAYOUT_ASSERT(palette_size, sizeof(TWindowActionPalette) == 0x78);

#pragma push
#pragma readonly_strings on
const char *TWindowActionPalette::class_name = "TWindowActionPalette";
#pragma pop

struct PaletteItemKind { u8 group; u8 index; };



// update_palette_item_count_label is the first caller of these two: their copies close the TU.
void TWindowHelpItem::set_flag0_bit2() { *(u16*)(this + 0x0) |= 0x2; }
void TWindowSubStatusDisp::clear_visible_flag() { *(u16 *)&this->m_name &= 0xfffffffd; }

extern "C" {
s32 fn_801B7CEC(void *player, s32 kind, u8 group, u8 index);
s32 is_palettex_activated(u16 client_index);
s32 is_palettex_enabled(u16);
}

const PaletteItemKind action_palette_item_kinds[13] = {
    {0, 0}, {0, 1}, {0, 2}, {1, 0}, {1, 1}, {1, 2}, {6, 0},
    {6, 1}, {3, 0}, {4, 0}, {5, 0}, {7, 0}, {8, 0},
};

struct PaletteIconUV { f32 u; f32 v; };

PaletteIconUV action_palette_icon_uv_tables[19] = {
    {50.0f, 0.0f}, {50.0f, 43.0f}, {50.0f, 86.0f}, {100.0f, 0.0f},
    {100.0f, 43.0f}, {100.0f, 86.0f}, {0.0f, 0.0f}, {0.0f, 43.0f},
    {0.0f, 86.0f}, {200.0f, 0.0f}, {0.0f, 129.0f}, {50.0f, 172.0f},
    {0.0f, 172.0f}, {50.0f, 129.0f}, {200.0f, 86.0f}, {150.0f, 0.0f},
    {150.0f, 86.0f}, {150.0f, 43.0f}, {200.0f, 43.0f},
};
PaletteIconUV lbl_804CDD40[17] = {
    {0.0f, 0.0f}, {0.0f, 43.0f}, {0.0f, 86.0f}, {50.0f, 0.0f},
    {50.0f, 43.0f}, {50.0f, 86.0f}, {100.0f, 0.0f}, {50.0f, 129.0f},
    {100.0f, 43.0f}, {0.0f, 172.0f}, {0.0f, 129.0f}, {150.0f, 43.0f},
    {50.0f, 172.0f}, {0.0f, 129.0f}, {0.0f, 0.0f}, {0.0f, 86.0f},
    {0.0f, 43.0f},
};
PaletteIconUV action_palette_photon_blast_icon_uvs[6] = {
    {200.0f, 172.0f}, {150.0f, 129.0f}, {150.0f, 172.0f}, {200.0f, 129.0f},
    {100.0f, 172.0f}, {100.0f, 129.0f},
};
PaletteIconUV lbl_804CDDF8[3] = {
    {200.0f, 43.0f}, {200.0f, 0.0f}, {200.0f, 86.0f},
};
PaletteIconUV lbl_804CDE10[8] = {
    {0.0f, 0.0f}, {100.0f, 129.0f}, {100.0f, 172.0f}, {200.0f, 129.0f},
    {200.0f, 172.0f}, {100.0f, 86.0f}, {100.0f, 86.0f}, {50.0f, 0.0f},
};

const f32 TWindowActionPalette::bank_panel_uv_origins[4][2] = {
    {0.0f, 0.0f}, {0.0f, 56.0f}, {0.0f, 112.0f}, {92.0f, 112.0f},
};

const u8 action_palette_slot_icon_entries[3] = {2, 4, 6};
const u8 action_palette_slot_channels[3] = {1, 2, 3};
const u8 action_palette_slot_count_entries[3] = {3, 5, 7};

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

ActionPaletteWindowLayout action_palette_layout_entries = {
    8, 1,
    {6, {45.0f, 53.0f}, {91.0f, 54.0f}, 92.0f, 0.0f, 0.4f, 0xFF666666, &hud_texlist, 0, 0x14},
    {6, {13.0f, 0.0f}, {91.0f, 54.0f}, 0.0f, 0.0f, 0.4f, -1, &hud_texlist, 0, 0x14},
    {6, {50.0f, 32.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.4f, -1, &hud_texlist, 4, 0x14},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 6, 0},
    {6, {94.0f, 6.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.4f, -1, &hud_texlist, 4, 0x14},
    {4, {34.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 6, 0},
    {6, {6.0f, 58.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.4f, -1, &hud_texlist, 4, 0x14},
    {4, {124.0f, 60.0f}, 0.5f, 0xFFFFFFFF, 6, 0},
};

WindowDescriptor twindow_action_palette_layout = {
    {150.0f, 107.0f}, 50000.0f, &action_palette_layout_entries, 0xB28,
};

TWindowActionPalette::TWindowActionPalette(s32 slot) : TWindowBase((u8 *)&twindow_action_palette_layout, (s16)slot, (u8 *)(get_window_layout_position(0x1F))) {
    u32 i;

    this->m_name = TWindowActionPalette::class_name;
    if (TCameraCtrl::get_camera_id() > 2) {
        this->scale.x = 0.5f;
        this->scale.y = 0.5f;
    } else if (TCameraCtrl::get_camera_id() == 2) {
        this->scale.x = 0.7f;
        this->scale.y = 0.7f;
    } else {
        this->scale.x = 1.0f;
        this->scale.y = 1.0f;
    }
    this->m_58 = -1.0f;
    this->state = 0;
    this->client_index = slot;
    for (i = 0; i < 3; i++) {
        set_action_palette_tag_mode(this->resources, 0);
        set_action_palette_tag_slot(this->resources, 0);
    }
}

TWindowActionPalette::~TWindowActionPalette() {}

void TWindowActionPalette::run_task() {
    TObjPlayer *player;
    TPlyDispConfigSmth *palette;
    s32 slot;
    u16 v;
    u16 target;
    u8 cnt;
    TWindowHelpItem *help;
    player = get_player_by_client_id(client_index);
    if (player == NULL || (palette = player->refresh_effect()) == NULL) {
        return;
    }
    if (!(this->window_flags & 2)) {
        open_tick = 0x01000000;
    }
    slot = is_player_input_active(client_index);
    if (test_previous_buttons_packed(&controller_input_state.controllers[slot], fn_8002AE08(client_index)) != 0) {
        state = 3;
    }
    help = (TWindowHelpItem *)get_array_entry(0);
    TWindowHelpItem::set_help_text((saddr)help, client_index);
    cnt = state;
    if ((s8)cnt > 0) {
        state = cnt - 1;
        help->window_flags = -1;
    } else {
        help->window_flags = 0xFF666666;
    }
    v = player->select_action_palette_and_apply(0, 0, 0);
    if (v == 0) {
        v = palette->get_current_tag_slot(1);
        update_slot_sprites(0, palette->get_current_tag_mode(1), v);
    } else {
        update_slot_sprites(0, 7, v);
    }
    if (is_palettex_activated((u16)client_index) != 0 && ((TPlyDispConfig *)((u8 *)player + 0x500))->is_primary_first_bank() != 0) {
        update_slot_icon(1, 7, 7);
    } else {
        v = palette->get_current_tag_slot(2);
        update_slot_sprites(1, palette->get_current_tag_mode(2), v);
    }
    v = palette->get_current_tag_slot(3);
    update_slot_sprites(2, palette->get_current_tag_mode(3), v);
    target = TObjPlayer::get_current_target_id();
    if (target == 0xFFFF || target == client_index || player->get_photon_blast_charge() <= 0) {
        if (((TPlyDispConfig *)((u8 *)player + 0x500))->is_primary_first_bank() != 0) {
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
    update_window();
    update_fade();
    update_window_entry_list(&entry_list);
}

void TWindowActionPalette::render() {
    saddr context = reinterpret_cast<saddr>(setup_window_draw_context((f32 *)&scale));
    draw_visible_window_entries(
        this,
        reinterpret_cast<const WindowLayoutEntries *>(&entry_list),
        reinterpret_cast<WindowDrawContext *>(context));
    draw_frame(context);
}

#pragma push
#pragma fp_contract on
void TWindowActionPalette::draw_frame(saddr context) {
    TexturedQuad corner;
    TexturedQuad top_row;
    TexturedQuad frame;
    TexturedQuad bottom_row;
    WindowDrawContext *ctx = (WindowDrawContext *)context;
    f32 scale;
    f32 depth;
    scale = get_transition_progress();
    depth = (-1.0f) / this->draw_depth;
    begin_screen_draw(1);
    set_texture_list(hud_texlist);
    set_draw_texture_and_color(2, ctx->color);
    if (is_split_screen() == 0) {
        corner.x0 = 640.0f - 71.0f * scale;
        corner.y0 = 480.0f - 76.0f * scale;
        corner.x1 = 71.0f + corner.x0;
        corner.y1 = 83.0f + corner.y0;
        corner.u0 = 0.0f;
        corner.v0 = 0.63671875f;
        corner.u1 = 0.27734375f;
        corner.v1 = 0.9609375f;
        draw_textured_quad_at_depth((f32 *)&corner, depth);
    }
    top_row.x0 = 13.0f + ctx->x;
    top_row.y0 = ctx->y;
    top_row.x1 = 91.0f + top_row.x0;
    top_row.y1 = 54.0f + top_row.y0;
    top_row.u0 = 0.0f;
    top_row.v0 = 0.421875f;
    top_row.u1 = 0.35546875f;
    top_row.v1 = 0.6328125f;
    ctx->transform_quad(&top_row);
    draw_textured_quad_at_depth((f32 *)&top_row, depth);
    bottom_row.x0 = 45.0f + ctx->x;
    bottom_row.y0 = 53.0f + ctx->y;
    bottom_row.x1 = 91.0f + bottom_row.x0;
    bottom_row.y1 = 54.0f + bottom_row.y0;
    bottom_row.u0 = 0.36328125f;
    bottom_row.v0 = 0.421875f;
    bottom_row.u1 = 0.71875f;
    bottom_row.v1 = 0.6328125f;
    ctx->transform_quad(&bottom_row);
    draw_textured_quad_at_depth((f32 *)&bottom_row, depth);
    frame.x0 = ctx->x;
    frame.y0 = ctx->y;
    frame.x1 = 150.0f + frame.x0;
    frame.y1 = 107.0f + frame.y0;
    frame.v0 = frame.u0 = 0.0f;
    frame.u1 = 0.5859375f;
    frame.v1 = 0.41796875f;
    ctx->transform_quad(&frame);
    draw_textured_quad_at_depth((f32 *)&frame, depth);
    end_screen_draw();
    if (scanline_crosses_window(ctx, &ctx->inner_x, &ctx->inner_w) != 0) {
        begin_window_sweep_draw(2);
        draw_window_sweep_strip(&frame, ctx);
        end_window_sweep_draw(2);
    }
}
#pragma pop

void TWindowActionPalette::update_slot_sprites(int idx, u16 mode, u16 slot) {
    TObjPlayer *player;
    WindowSpritePart *help;
    gc_tag *cursor;

    player = get_player_by_client_id(client_index);
    if (player != NULL) {
        help = static_cast<WindowSpritePart *>(get_array_entry(action_palette_slot_icon_entries[idx]));
        if (player->is_action_channel_available((s32)action_palette_slot_channels[idx]) != 0) {
            help->color = -1;
        } else {
            help->color = 0xFF404040;
        }
        update_palette_item_count_label(static_cast<TWindowLayoutNumber *>(get_array_entry(action_palette_slot_count_entries[idx])), help, mode, slot, client_index);
        cursor = &resources[idx];
        if (mode != get_action_palette_tag_mode(cursor) || get_action_palette_tag_slot(cursor) != slot) {
            set_action_palette_tag_mode(cursor, mode);
            set_action_palette_tag_slot(cursor, slot);
            draw_action_palette_icon(help, mode, slot);
        }
    }
}

void TWindowActionPalette::update_slot_icon(int idx, u16 mode, u16 slot) {
    if (get_player_by_client_id(client_index) != NULL) {
        WindowSpritePart *icon = static_cast<WindowSpritePart *>(get_array_entry(4));
        if (is_palettex_enabled((u16)client_index) != 0) {
            icon->color = -1;
        } else {
            icon->color = 0xFF404040;
        }
        ((TWindowHelpItem *)get_array_entry(5))->set_flag0_bit2();
        ActionPaletteTag *cur = &resources[idx];
        if (mode != get_action_palette_tag_mode(cur) || get_action_palette_tag_slot(cur) != slot) {
            set_action_palette_tag_mode(cur, mode);
            set_action_palette_tag_slot(cur, slot);
            draw_action_palette_icon(icon, mode, slot);
        }
    }
}

void TWindowActionPalette::set_bank_panel_art(unsigned short state) {
    WindowSpritePart *sprite = (WindowSpritePart *)get_array_entry(1);
    set_sprite_uv_from_pixels(sprite, TWindowActionPalette::bank_panel_uv_origins[state][0], TWindowActionPalette::bank_panel_uv_origins[state][1]);
}

#pragma push
#pragma fp_contract on
void spawn_action_palette_slot_light(TWindowActionPalette *palette, s32 slot) {
    NJS_POINT2 pt;
    s16 kind;
    WindowSpritePart *e;
    f32 s;
    f32 hw;
    f32 s2;
    f32 hw2;
    if (palette->is_open_and_unblocked() == 0) {
        return;
    }
    switch (slot) {
    case 1:
        kind = 0;
        e = static_cast<WindowSpritePart *>(palette->get_array_entry(2));
        break;
    case 2:
        kind = 2;
        e = static_cast<WindowSpritePart *>(palette->get_array_entry(4));
        break;
    case 3:
        kind = 1;
        e = static_cast<WindowSpritePart *>(palette->get_array_entry(6));
        break;
        return;
    default:
        return;
    }
    if (is_split_screen() != 0) {
        hw = 0.5f * palette->frame_size[0];
        s = palette->scale.x;
        pt.x = s * ((0.5f * e->w + e->x) - hw) + (hw * s + palette->frame_position[0]);
        hw2 = 0.5f * palette->frame_size[1];
        s2 = palette->scale.y;
        pt.y = s2 * ((0.5f * e->h + e->y) - hw2) + (hw2 * s2 + palette->frame_position[1]);
    } else {
        pt.x = 0.5f * e->w + (palette->frame_position[0] + e->x);
        pt.y = 0.5f * e->h + (palette->frame_position[1] + e->y);
    }
    TWindowEffectLight::create(&pt, kind, palette->client_index);
}
#pragma pop

void draw_action_palette_icon(WindowSpritePart *icon, u16 group, u16 index) {
    PaletteIconUV *row;
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
        row = action_palette_photon_blast_icon_uvs;
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
void update_palette_item_count_label(TWindowLayoutNumber *label, WindowSpritePart *icon, u16 group, u16 index, s32 client_id) {
    s32 v;
    TObjPlayer *p;
    if (group != 4) {
        reinterpret_cast<TWindowHelpItem *>(label)->set_flag0_bit2();
        return;
    }
    if (index >= 0xD) {
        p = get_player_by_client_id(client_id);
        if (p == NULL) {
            v = 0;
        } else {
            v = p->trap_counts.get_count(index - 0xD);
        }
    } else {
        v = TWindowHelpItem::get_help_value(index, client_id);
    }
    if (v <= 0) {
        reinterpret_cast<TWindowHelpItem *>(label)->set_flag0_bit2();
        return;
    }
    reinterpret_cast<TWindowSubStatusDisp *>(label)->clear_visible_flag();
    label->style = icon->color;
    label->value = v;
    draw_right_aligned_number(label);
    label->x = (icon->x - -25.0f) + 0.5f * label->width;
    label->y = icon->y - -28.0f;
}
#pragma pop

s32 get_palette_consumable_count(u16 slot, s32 client_id) {
    TObjPlayer *player = get_player_by_client_id(client_id);
    if (player == NULL) {
        return -1;
    }
    if (slot >= 13) {
        if (player->trap_counts.get_count(slot - 13) > 0) {
            return slot;
        }
        return -1;
    }
    const PaletteItemKind *kind = &action_palette_item_kinds[slot];
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

void TWindowHelpItem::set_help_text(saddr help, saddr client_id) {
    if (TWindowKeyBoardHard::test_card_flag_2(client_id) != 0) {
        set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(help), 92.0f, 56.0f);
        return;
    }
    set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(help), 92.0f, 0.0f);
}
