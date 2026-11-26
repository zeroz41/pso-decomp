#include "pso/ui/window/WindowSpritePart.h"
#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowSubCustomEquip.h"
#include "pso/ui/window/TWindowSubCustomSelect.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/ControllerInput.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/system/vector.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/unk/TWindowLayoutNumber.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal_8002ADD8.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/SoundEffect.h"
#include "pso/ui/window/WindowLayout.h"
#include "pso/ui/window/TWindowSubCustomEquip_80275D9C.h"





const char *TWindowSubCustomEquip::class_name = "TWindowSubCustomEquip";

// Window entries of the palette icon and of its count label, per cursor cell (column + row * 3).
static const u8 lbl_8044F738[6] = {12, 10, 11, 3, 1, 2};
static const u8 lbl_8044F740[6] = {15, 13, 14, 6, 4, 5};

static const NJS_POINT2 custom_equip_entry_offset_table[3] = {
    {50.0f, 32.0f},
    {6.0f, 58.0f},
    {94.0f, 6.0f},
};

// Texel origin of each cursor animation frame (4 x 4 grid of 64 x 64 cells).
static const NJS_POINT2 custom_equip_cursor_frame_uv_table[16] = {
    {0.0f, 0.0f}, {64.0f, 0.0f}, {128.0f, 0.0f}, {192.0f, 0.0f},
    {0.0f, 64.0f}, {64.0f, 64.0f}, {128.0f, 64.0f}, {192.0f, 64.0f},
    {0.0f, 128.0f}, {64.0f, 128.0f}, {128.0f, 128.0f}, {192.0f, 128.0f},
    {0.0f, 192.0f}, {64.0f, 192.0f}, {128.0f, 192.0f}, {192.0f, 192.0f},
};

// Window layout: two rows of panel, three palette icons, three count labels and two tabs.
struct CustomEquipLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    SpritePartLayoutRecord rec_1;
    SpritePartLayoutRecord rec_2;
    SpritePartLayoutRecord rec_3;
    ValueLayoutRecord rec_4;
    ValueLayoutRecord rec_5;
    ValueLayoutRecord rec_6;
    SpritePartLayoutRecord rec_7;
    SpritePartLayoutRecord rec_8;
    SpritePartLayoutRecord rec_9;
    SpritePartLayoutRecord rec_10;
    SpritePartLayoutRecord rec_11;
    SpritePartLayoutRecord rec_12;
    ValueLayoutRecord rec_13;
    ValueLayoutRecord rec_14;
    ValueLayoutRecord rec_15;
    SpritePartLayoutRecord rec_16;
    SpritePartLayoutRecord rec_17;
};

CustomEquipLayout lbl_804D1198 = {
    18, 1,
    {6, {51.0f, 59.0f}, {150.0f, 107.0f}, 0.0f, 0.0f, 0.1f, -1, &hud_texlist, 2, 4},
    {6, {0.0f, 0.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.2f, -1, &hud_texlist, 4, 4},
    {6, {0.0f, 0.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.2f, -1, &hud_texlist, 4, 4},
    {6, {0.0f, 0.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.2f, -1, &hud_texlist, 4, 4},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {6, {96.0f, 112.0f}, {91.0f, 54.0f}, 92.0f, 0.0f, 0.6f, 0xFF666666, &hud_texlist, 0, 6},
    {6, {96.0f, 112.0f}, {91.0f, 54.0f}, 93.0f, 108.0f, 0.6f, -1, &hud_texlist, 2, 6},
    {6, {3.0f, 9.0f}, {150.0f, 107.0f}, 0.0f, 0.0f, 0.6f, -1, &hud_texlist, 2, 4},
    {6, {0.0f, 0.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.7f, -1, &hud_texlist, 4, 4},
    {6, {0.0f, 0.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.7f, -1, &hud_texlist, 4, 4},
    {6, {0.0f, 0.0f}, {50.0f, 43.0f}, 150.0f, 86.0f, 0.7f, -1, &hud_texlist, 4, 4},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {4, {79.0f, 85.0f}, 0.5f, 0xFFFFFFFF, 4, 0},
    {6, {48.0f, 62.0f}, {91.0f, 54.0f}, 92.0f, 0.0f, 0.6f, 0xFF666666, &hud_texlist, 0, 6},
    {6, {48.0f, 62.0f}, {91.0f, 54.0f}, 93.0f, 108.0f, 0.6f, -1, &hud_texlist, 2, 6},
};

WindowDescriptor lbl_804D1488 = {
    {212.0f, 188.0f}, 50050.0f, &lbl_804D1198, 3,
};


int TWindowSubCustomEquip::is_selected() { return this->state_flags & 0x1; }
int TWindowSubCustomEquip__sub_80275DA8(void* p) { return ((TWindowSubCustomEquip *)p)->state_flags & 0x2; }
void TWindowSubCustomEquip::clear_flag_and_set_entry_state() {
    *(s8 *)&this->state_flags &= ~1;
    status_disp->set_entry_state(1);
}

#pragma push
#pragma fp_contract on
void TWindowSubCustomEquip::draw_cursor_sprite(f32 depth_scale, WindowDrawContext *context, NJS_POINT2 *position, s32 frame) {
    TexturedQuad r;
    const NJS_POINT2 *t;
    f32 scale;
    if (context->open_tick < 0) {
        return;
    }
    t = &custom_equip_cursor_frame_uv_table[frame & 0xF];
    scale = (-1.0f) / (0.299f * depth_scale + context->depth);
    set_additive_blend();
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(0xC, -1);
    r.x0 = position->x + context->inner_x;
    r.y0 = position->y + context->inner_y;
    r.x1 = 72.32f + r.x0;
    r.y1 = 72.32f + r.y0;
    r.u0 = t->x / 256.0f;
    r.v0 = t->y / 256.0f;
    r.u1 = (64.0f + t->x) / 256.0f;
    r.v1 = (64.0f + t->y) / 256.0f;
    if (context->clip_and_transform_quad(&r) != 0) {
        draw_textured_quad_at_depth(&r.x0, scale);
    }
    TWindowSubStatusDisp::get_player();
    set_default_alpha_blend();
}
#pragma pop

void TWindowSubCustomEquip::get_cursor_origin(NJS_POINT2 *position) {
    s8 idx;
    if ((s8)front_bank == 0) {
        idx = slot + bank * 3;
    } else {
        idx = slot + (1 - bank) * 3;
    }
    WindowSpritePart *entry = static_cast<WindowSpritePart *>(get_array_entry(lbl_8044F738[idx]));
    set_relative_pos(position, entry);
}

void TWindowSubCustomEquip::draw_cursor(WindowDrawContext *context) {
    NJS_POINT2 position;
    get_cursor_origin(&position);
    draw_cursor_sprite(0.8f, context, &position, cursor_frame);
}

void TWindowSubCustomEquip::update_palette_slot(s32 arg1, u16 kind, u16 index) {
    TObjPlayer *pl;
    WindowSpritePart *icon;
    TWindowLayoutNumber *label;
    pl = get_player_by_client_id(this->client_index);
    if (pl != NULL) {
        icon = static_cast<WindowSpritePart *>(get_array_entry(lbl_8044F738[arg1]));
        label = static_cast<TWindowLayoutNumber *>(get_array_entry(lbl_8044F740[arg1]));
        if (pl->can_use_palette_action(kind, index) != 0) {
            icon->color = -1;
        } else {
            icon->color = 0xFF404040;
        }
        draw_action_palette_icon(icon, kind, index);
        update_palette_item_count_label(label, icon, kind, index, this->client_index);
    }
}



s32 TWindowSubCustomEquip::is_type_valid(u8 type) {

    switch ((s8) this->bank) {
    case 0:
        return 0;
    default:
    case 1:
        return 1;
    }
}
s32 TWindowSubCustomEquip::get_saved_slot_for_index(u8 slot) {
    switch ((s8)slot) {
    case 0:
        return 2;
    case 1:
        return 1;
    case 2: break;
    }
    return 3;
}


// An action palette slot reference: the tag mode and the slot it points to.
struct PaletteTag { u16 mode; u16 slot; };

void TWindowSubCustomEquip::get_cursor_pos(void *tag_out) {
    PaletteTag *tag = (PaletteTag *)tag_out;
    s32 i;
    TObjPlayer *player;
    s32 saved_slot;
    TPlyDispConfigSmth *palette;

    if ((player = get_player_by_client_id(this->client_index)) == NULL || (palette = player->select_action_palette(0)) == NULL) {
        tag->mode = 0;
        tag->slot = 0;
        return;
    }
    i = is_type_valid(this->bank);
    saved_slot = get_saved_slot_for_index(this->slot);
    tag->mode = palette->get_tag_mode(i, saved_slot);
    tag->slot = (s16)palette->get_tag_slot(i, saved_slot);
}
void TWindowSubCustomEquip::remove_duplicate_bindings(void *tag_ptr) {
    PaletteTag *tag = (PaletteTag *)tag_ptr;
    TObjPlayer *player;
    TPlyDispConfigSmth *palette;
    if ((player = get_player_by_client_id(this->client_index)) == NULL || (palette = player->select_action_palette(0)) == NULL) {
        return;
    }
    if (tag->mode == (u16)palette->get_tag_mode(0, 1) && tag->slot == (u16)palette->get_tag_slot(0, 1)) {
        player->set_action_palette_entry(0, 0, 1, 0, 0);
    }
    if (tag->mode == (u16)palette->get_tag_mode(0, 3) && tag->slot == (u16)palette->get_tag_slot(0, 3)) {
        player->set_action_palette_entry(0, 0, 3, 0, 0);
    }
    if (tag->mode == (u16)palette->get_tag_mode(0, 2) && tag->slot == (u16)palette->get_tag_slot(0, 2)) {
        player->set_action_palette_entry(0, 0, 2, 0, 0);
    }
    if (tag->mode == (u16)palette->get_tag_mode(1, 1) && tag->slot == (u16)palette->get_tag_slot(1, 1)) {
        player->set_action_palette_entry(0, 1, 1, 0, 0);
    }
    if (tag->mode == (u16)palette->get_tag_mode(1, 3) && tag->slot == (u16)palette->get_tag_slot(1, 3)) {
        player->set_action_palette_entry(0, 1, 3, 0, 0);
    }
    if (tag->mode == (u16)palette->get_tag_mode(1, 2) && tag->slot == (u16)palette->get_tag_slot(1, 2)) {
        player->set_action_palette_entry(0, 1, 2, 0, 0);
    }
}
void TWindowSubCustomEquip::toggle_action_binding(void *tag_ptr) {
    PaletteTag *tag = (PaletteTag *)tag_ptr;
    TObjPlayer *player;
    TPlyDispConfigSmth *palette;
    s32 valid;
    s32 idx;
    if ((player = get_player_by_client_id(this->client_index)) == NULL || (palette = player->select_action_palette(0)) == NULL) {
        return;
    }
    valid = is_type_valid(this->bank);
    idx = get_saved_slot_for_index(this->slot);
    if (tag->mode == (u16)palette->get_tag_mode(valid, idx) && tag->slot == (u16)palette->get_tag_slot(valid, idx)) {
        player->set_action_palette_entry(0, valid, idx, 0, 0);
        return;
    }
    remove_duplicate_bindings(tag_ptr);
    player->set_action_palette_entry(0, valid, idx, tag->mode, tag->slot);
}

f32 TWindowSubCustomEquip::ring_scale;
u8 TWindowSubCustomEquip::bank_ring_init_done;
f32 lbl_805D6478;
u8 lbl_805D647C;


void set_relative_pos(NJS_POINT2 *position, WindowSpritePart *entry) {
    position->x = entry->x - 11.0f;
    position->y = entry->y - 15.0f;
}

void TWindowSubCustomEquip::layout_selection_parts(void *arg1) {
    NJS_POINT2 pos;
    WindowSpritePart *p;
    WindowSpritePart *a;
    WindowSpritePart *b;
    WindowSpritePart *c;
    WindowSpritePart *d;
    if (*(s8 *)&this->front_bank == 0) {
        a = static_cast<WindowSpritePart *>(get_array_entry(0x11));
        b = static_cast<WindowSpritePart *>(get_array_entry(0x10));
        c = static_cast<WindowSpritePart *>(get_array_entry(8));
        d = static_cast<WindowSpritePart *>(get_array_entry(7));
        p = static_cast<WindowSpritePart *>(get_array_entry(9));
    } else {
        a = static_cast<WindowSpritePart *>(get_array_entry(8));
        b = static_cast<WindowSpritePart *>(get_array_entry(7));
        c = static_cast<WindowSpritePart *>(get_array_entry(0x11));
        d = static_cast<WindowSpritePart *>(get_array_entry(0x10));
        p = static_cast<WindowSpritePart *>(get_array_entry(0));
    }
    pos.x = 45.0f + p->x;
    pos.y = 53.0f + p->y;
    TWindowHelpItem::set_help_text((saddr)b, (s32)this->client_index);
    copy_vec2(&a->x, &pos);
    copy_vec2(&b->x, &pos);
    a->depth = p->depth;
    b->depth = p->depth;
    a->color = p->color;
    a->flags &= ~2;
    b->flags &= ~2;
    c->flags |= 2;
    d->flags |= 2;
}

void TWindowSubCustomEquip::layout_entry_group(void *index) {
  WindowSpritePart *base;
  WindowSpritePart *e1;
  TWindowLayoutNumber *e2;
  u32 i;
  s32 idx;
  s32 v;
  base = static_cast<WindowSpritePart *>(get_array_entry((saddr) index));
  for (i = 0; i < 3; i++)
  {
    idx = ((saddr) index) + i;
    e1 = static_cast<WindowSpritePart *>(get_array_entry(idx + 1));
    e2 = static_cast<TWindowLayoutNumber *>(get_array_entry(idx + 4));
    e1->x = base->x + custom_equip_entry_offset_table[i].x;
    e1->y = base->y + custom_equip_entry_offset_table[i].y;
    e1->depth = 0.1f + base->depth;
    e2->depth = 0.2f + base->depth;
    e2->style = base->color;
    v = 0.003921569f * (((unsigned char) (((u32)base->color) & 0xFF)) * (((u32)e1->color) & 0xFF));
    e1->color = (v & 0xFF) | ((((v & 0xFF) << 16) | 0xFF000000) | ((v & 0xFF) << 8));
  }
}

void TWindowSubCustomEquip::reset_selection() { layout_entry_group(((void*)9)); layout_entry_group(((void*)0)); layout_selection_parts(((void*)9)); }

void TWindowSubCustomEquip::refresh_palette_slots() {
    TObjPlayer *player;
    TPlyDispConfigSmth *palette;
    player = get_player_by_client_id(this->client_index);
    if (player == NULL || (palette = player->select_action_palette(0)) == NULL) {
        return;
    }
    update_palette_slot(0, palette->get_tag_mode(*(s8 *)&this->front_bank, 2), palette->get_tag_slot(*(s8 *)&this->front_bank, 2));
    update_palette_slot(1, palette->get_tag_mode(*(s8 *)&this->front_bank, 1), palette->get_tag_slot(*(s8 *)&this->front_bank, 1));
    update_palette_slot(2, palette->get_tag_mode(*(s8 *)&this->front_bank, 3), palette->get_tag_slot(*(s8 *)&this->front_bank, 3));
    update_palette_slot(3, palette->get_tag_mode(*(s8 *)&this->back_bank, 2), palette->get_tag_slot(*(s8 *)&this->back_bank, 2));
    update_palette_slot(4, palette->get_tag_mode(*(s8 *)&this->back_bank, 1), palette->get_tag_slot(*(s8 *)&this->back_bank, 1));
    update_palette_slot(5, palette->get_tag_mode(*(s8 *)&this->back_bank, 3), palette->get_tag_slot(*(s8 *)&this->back_bank, 3));
}

#pragma push
#pragma fp_contract on
void TWindowSubCustomEquip::place_bank_slot_on_ring(s32 angle, s32 index) {
    f32 shade;
    f32 sin_value;
    f32 cos_value;
    s32 brightness;
    WindowSpritePart *part;
    if ((s8) TWindowSubCustomEquip::bank_ring_init_done == 0) {
        TWindowSubCustomEquip::bank_ring_init_done = 1;
        TWindowSubCustomEquip::ring_scale = 75.0f;
    }
    if ((s8) lbl_805D647C == 0) {
        lbl_805D647C = 1;
        lbl_805D6478 = 25.0f;
    }
    sin_value = sin_table_lookup(angle);
    cos_value = cos_table_lookup(angle);
    part = static_cast<WindowSpritePart *>(this->get_array_entry(index));
    part->x = (f32) ((TWindowSubCustomEquip::ring_scale * cos_value) + 27.0f);
    part->y = (f32) ((lbl_805D6478 * sin_value) + 34.0f);
    if ((angle - 0x7200) & 0x8000) {
        shade = (0.5f * cos_table_lookup(angle + 0xFFFF4E00)) + 1.0f;
        part->depth = 0.1f;
        brightness = (s32) (255.0f * shade);
        part->color = (s32) ((u8) brightness | (((brightness << 0x10) & 0xFF0000) | 0xFF000000 | ((brightness << 8) & 0xFF00)));
        return;
    }
    part->depth = 0.6f;
    part->color = -1;
}
#pragma pop

void TWindowSubCustomEquip::update_rotate_anim() {
    s32 angle;
    s32 target_angle;

    target_angle = 0xB200;
    if ((s8) this->bank > 0) {
        target_angle = 0x13200;
    }
    angle = this->angle;
    if (target_angle != angle) {
        if ((s32) (u16) (target_angle - angle) < 0xC00) {
            this->angle = target_angle;
        } else {
            this->angle = (angle + 0xC00);
        }
    }
    if (this->angle & 0x8000) {
        this->front_bank = 0;
        this->back_bank = 1;
        place_bank_slot_on_ring(this->angle, 9);
        place_bank_slot_on_ring(this->angle + 0x8000, 0);
        return;
    }
    this->front_bank = 1;
    this->back_bank = 0;
    place_bank_slot_on_ring(this->angle + 0x8000, 9);
    place_bank_slot_on_ring(this->angle, 0);
}

void TWindowSubCustomEquip::handle_cancel() {
    if (is_selected() == 0) {
        play_sound_effect(0x52F16, 0, 0, 0);
        this->state_flags = (u8) (this->state_flags | 2);
    }
}

void TWindowSubCustomEquip::handle_decide() {
    play_sound_effect(0x52D01, 0, 0, 0);
    this->state_flags = (u8) (this->state_flags | 1);
    status_disp->set_entry_state(2);
}

void TWindowSubCustomEquip::handle_cursor_input() {
    s32 controller_index;
    u8 slot_now;
    u8 slot_wrapped;
    u8 timer;
    WindowSpritePart *entry_10;
    ControllerInputContext *window_choice_setting;
    WindowSpritePart *array_entry;
    controller_index = is_player_input_active((this->client_index));
    entry_10 = static_cast<WindowSpritePart *>(get_array_entry(0x10));
    array_entry = static_cast<WindowSpritePart *>(get_array_entry(7));
    timer = this->bank_swap_timer;
    if ((s8) timer > 0) {
        this->bank_swap_timer = (timer - 1);
        entry_10->color = -1;
        array_entry->color = -1;
    } else {
        entry_10->color = 0xFF666666;
        array_entry->color = 0xFF666666;
    }
    window_choice_setting = &controller_input_state.controllers[controller_index];
    if ((test_buttons_press_or_repeat(window_choice_setting, 0xF0, 6, 1) != 0) || (test_pressed_buttons_packed(window_choice_setting, (int) (fn_8002AE08((int)this->client_index))) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0xF0, 6, 1) != 0)) {
        play_sound_effect(0x54100, 0, 0, 0);
        if (test_pressed_buttons_packed(window_choice_setting, (int) (fn_8002AE08((int)this->client_index))) != 0) {
            this->bank = (u8) (1 - this->bank);
            this->bank_swap_timer = 3U;
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
            this->slot = (this->slot - 1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
            this->slot = (this->slot + 1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x80, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x80, 6, 1) != 0)) {
            this->slot = (this->slot - 1);
        }
        if ((test_buttons_press_or_repeat(window_choice_setting, 0x40, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x40, 6, 1) != 0)) {
            this->slot = (this->slot + 1);
        }
        slot_now = this->slot;
        if ((s8) slot_now < 0) {
            this->slot = (slot_now + 3);
        }
        slot_wrapped = this->slot;
        if ((s8) slot_wrapped >= 3) {
            this->slot = (slot_wrapped - 3);
        }
    }
}

void TWindowSubCustomEquip::render() {
    WindowDrawContext *context = draw_default_entry();
    draw_window_frame(context);
    draw_visible_window_entries(this, &entry_list, context);
    draw_cursor(context);
    status_disp->forward_render(context);
}

void TWindowSubCustomEquip::run_task() {
    s32 controller_index;
    ControllerInputContext *context;
    controller_index = is_player_input_active(((s32) this->client_index));
    if (this->is_selected() == 0) {
        this->handle_cursor_input();
        context = &controller_input_state.controllers[controller_index];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            handle_decide();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            handle_cancel();
        }
    }
    update_rotate_anim();
    reset_selection();
    refresh_palette_slots();
    if ((f32)open_tick >= 7.5f) {
        status_disp->update_subwindow();
    }
    update_window();
    this->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&this->entry_list));
    this->cursor_frame = (this->cursor_frame + 1);
}

TWindowSubCustomEquip::~TWindowSubCustomEquip() {
    TWindowSubStatusDisp::destroy_status_display(reinterpret_cast<saddr>(status_disp), 1);
}

TWindowSubCustomEquip::TWindowSubCustomEquip(s32 slot) : TWindowBase((u8 *)&lbl_804D1488, slot, (u8 *)get_window_layout_position(0xF)) {
    void *heading;
    this->m_name = TWindowSubCustomEquip::class_name;
    this->client_index = slot;
    this->state_flags = 0;
    this->slot = 1;
    this->bank = 0;
    this->bank_swap_timer = 0;
    this->front_bank = 0;
    this->back_bank = 1;
    this->cursor_frame = 0;
    this->angle = 0xB200;
    heading = (void *)::operator new(0x24);
    if (heading != NULL) {
        heading = ((TWindowSubStatusDisp *)heading)->construct_type1_heading((saddr)TWindowSubStatusDisp::get_message_10(0x23), this->client_index);
    }
    status_disp = static_cast<TWindowSubStatusDisp *>(heading);
    this->refresh_palette_slots();
}

void *TWindowSubCustomSelect::get_selected_action() {
    return reinterpret_cast<void *>(action_table + (static_cast<s8>(column) + static_cast<s8>(row) * 3) * 4);
}
