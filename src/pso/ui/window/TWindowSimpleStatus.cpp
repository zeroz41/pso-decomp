#include "pso/math/FloatRound.h"
#include "pso/render/ColorLineList.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/render/Draw2D.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/ui/window/TWindowComCard.h"
#include "pso/ui/window/TWindowComCardFollower.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/ui/window/TWindowSimpleStatus.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/object/base/TObjChara.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/window/TWindowStatusGaugeFeedback.h"
#include "pso/ui/window/TWindowLayoutNumber.h"
#include "pso/player/PlayerSlots.h"
#include <string.h>
#include "pso/map/FloorArea.h"
#include "pso/ui/window/TWindowDD.h"

#include "pso/ui/window/WindowLayoutRecord.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/window/WindowLayout.h"
#include <stdlib.h>
#include "pso/map/area/AreaScene.h"
#include "pso/player/PhotonBlastResults.h"
#include "pso/ui/window/ScreenQuadDraw.h"
#include "pso/ui/window/WindowSpritePart.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/charcreate/CharacterAppearance.h"


#pragma push
#pragma readonly_strings on
const char *TWindowSimpleStatus::class_name = "TWindowSimpleStatus";
#pragma pop

// photon_blast_gauge_ring_offset, the ring's offset inside the window that
// draw_background passes to draw_photon_blast_gauge_ring.
static const NJS_POINT2 photon_blast_gauge_ring_offset = {24.0f, 19.0f};

// One colour per hundred points of photon blast charge (0..500); the ring draws [n] and [n + 1].
const u32 photon_blast_gauge_ring_color_table[7] = {
    0xFF3C3C3C, 0xFFD8CF00, 0xFFD88A00, 0xFFD84500, 0xFFD80000, 0xFFFFFFFF, 0,
};


SimpleStatusWindowLayout simple_status_window_layout_entries = {
    8, 1,
    {6, {7.0f, 5.0f}, {34.0f, 29.0f}, 112.0f, 84.0f, 0.5f, -1, &hud_texlist, 0, 4},
    {3, {47.0f, 26.0f}, 0.5f, 0xFFFFFFFF, 4, NULL},
    {4, {47.0f, 39.0f}, 0.5f, 0xFFFFFFFF, 4, 1},
    {{2, {67.0f, 4.0f}, 0.5f, 0xFF00FF15, 0x28, 85.0f, 0, 0}, 0xFF00CA9E, 0xFFFF2924},
    {{2, {67.0f, 16.0f}, 0.5f, 0xFF008CFC, 0x28, 85.0f, 0, 0}, 0xFF008DEE, 0xFFFF2924},
    {6, {2.0f, 39.0f}, {15.0f, 11.0f}, 230.0f, 104.0f, 0.5f, -1, &hud_texlist, 0xB, 4},
    {6, {47.0f, 3.0f}, {19.0f, 10.0f}, 230.0f, 80.0f, 0.5f, -1, &hud_texlist, 0xB, 4},
    {6, {47.0f, 15.0f}, {19.0f, 10.0f}, 230.0f, 92.0f, 0.5f, -1, &hud_texlist, 0xB, 4},
};
WindowDescriptor simple_status_window_layout = {
    {153.0f, 50.0f}, 50100.0f, &simple_status_window_layout_entries, 0xB28,
};


void TWindowSimpleStatus::start_hp_text_color_transition() {
    TWindowStatusGaugeFeedback *gauge = (TWindowStatusGaugeFeedback *)get_array_entry(4);
    gauge->maximum = 0.0f;
    gauge->target = 0.0f;
    gauge->start_text_color_transition(0xFF008CFC, 1.0f);
}

void TWindowSimpleStatus::init_gauge_entry() {
    TWindowStatusGaugeFeedback *gauge = (TWindowStatusGaugeFeedback *)get_array_entry(3);
    gauge->maximum = 0.0f;
    gauge->target = 0.0f;
    gauge->calc_bar_width();
    gauge->start_text_color_transition(0xFF00FF15, 1.0f);
}

void TWindowSimpleStatus::update_status_entry() {
    TObjPlayer *player = get_player_by_client_id(get_width());
    if (player != NULL) {
        TWindowLayoutNumber *level = (TWindowLayoutNumber *)get_array_entry(2);
        level->value = player->get_actor_level_index() + 1;
    }
}

s32 TWindowSimpleStatus::update_hp_gauge() {
    s32 rgb;
    s32 color;
    TWindowStatusGaugeFeedback *gauge;
    TObjPlayer *player;

    player = get_player_by_client_id(get_width());
    if (player == NULL) {
        start_hp_text_color_transition();
        return 0xFF008CFC;
    }
    gauge = (TWindowStatusGaugeFeedback *)get_array_entry(4);
    gauge->maximum = (f32)player->get_tpmax();
    gauge->target = (f32)player->tp;
    if (gauge->target > (0.2f * gauge->maximum)) {
        color = -1;
        rgb = 0xFF008CFC;
    } else {
        rgb = -0x3EEC;
        color = -0x3EEC;
    }
    gauge->start_text_color_transition(rgb, 11.1f);
    return color;
}

s32 TWindowSimpleStatus::update_hp_entry() {
    s32 color;
    s32 rgb;
    TWindowStatusGaugeFeedback *gauge;
    TObjPlayer *player;
    player = get_player_by_client_id(get_width());
    if (player == NULL) {
        this->init_gauge_entry();
        return 0xFF00FF15;
    }
    gauge = (TWindowStatusGaugeFeedback *)get_array_entry(3);
    gauge->maximum = (f32)player->get_hpmax();
    if (gauge->target > (f32)player->hp) {
        this->shake_ticks = 4;
    }
    gauge->target = (f32)player->hp;
    if (gauge->target > (0.2f * gauge->maximum)) {
        color = -1;
        rgb = 0xFF00FF15;
    } else {
        rgb = 0xFFF2FF19;
        color = 0xFFF2FF19;
    }
    gauge->start_text_color_transition(rgb, 11.1f);
    return color;
}

void TWindowSimpleStatus::update_status_icons(NJS_POINT2 *ofs) {
    PhotonBlastChainCopy chain;
    s32 k;
    s32 count;
    saddr i;
    s32 j;
    s32 help_mode;
    TWindowComCardFollower *window;
    TObjPlayer *player;
    player = get_player_by_client_id(this->client_index);
    if (player == NULL || is_open_and_unblocked() == 0) {
        for (i = 0; i < 5; i++) {
            if (this->w[i] != NULL) {
                this->w[i]->close();
                this->w[i] = NULL;
            }
        }
        return;
    }
    count = 0;
    j = 0;
    i = get_photon_blast_chain(&chain, this->client_index);
    if (i == 1 || i == 2) {
        for (i = 0; chain.kinds[i] != -1; i++) {
            if (chain.participants[i] == this->client_index) {
                break;
            }
        }
        help_mode = get_chain_help_mode(i);
        window = (TWindowComCardFollower *)(this->w[j]);
        if (window == NULL) {
            window = new TWindowComCardFollower(this, ofs, 0, help_mode, this->client_index);
            this->w[j] = window;
            this->w[j]->set_depth(1.0f + get_scale());
        } else {
            window->set_column(0);
            ((TWindowComCardFollower *)this->w[j])->set_selected_index(help_mode);
        }
        count = 1;
    } else if (this->w[j] != NULL) {
        this->w[j]->close();
        this->w[j] = NULL;
    }
    j++;
    for (k = 0; k < 4; k++, j++) {
        s32 word = player->get_status_effect_type(k);
        if (word == 0) {
            if (this->w[j] != NULL) {
                this->w[j]->close();
                this->w[j] = NULL;
            }
        } else {
            help_mode = get_status_effect_icon_index(word);
            window = (TWindowComCardFollower *)(this->w[j]);
            if (window == NULL) {
                window = new TWindowComCardFollower(this, ofs, count, help_mode, this->client_index);
                this->w[j] = window;
                this->w[j]->set_depth(2.0f + ((f32)k + get_scale()));
            } else {
                window->set_column(count);
                ((TWindowComCardFollower *)this->w[j])->set_selected_index(help_mode);
            }
            count++;
        }
    }
}

#pragma push
#pragma fp_contract on
void draw_photon_blast_fan(TWindowSimpleStatus *window, NJS_POINT2 *center, WindowDrawContext *ctx, u32 color, f32 depth_offset, s32 start_angle, s32 end_angle, f32 radius) {
    NJS_POINT2 verts[3];
    NJS_POINT2COL prim;
    NJS_COLOR colors[3];
    s32 end = end_angle;
    s32 angle = start_angle;
    f32 amp_x;
    f32 amp_y;
    f32 depth;

    depth = window->draw_depth + 0.299f * depth_offset;
    amp_x = radius * ctx->scale[0];
    amp_y = radius * ctx->scale[1];
    prim.p = verts;
    prim.col = colors;
    prim.tex = NULL;
    prim.num = 1;
    colors[2].color = colors[1].color = colors[0].color = (color << 8) | (color >> 24);
    verts[0].x = ctx->pivot[0] + ctx->scale[0] * (center->x - ctx->pivot[0]);
    verts[0].y = ctx->pivot[1] + ctx->scale[1] * (center->y - ctx->pivot[1]);
    verts[2].x = amp_x * cos_table_lookup(angle) + verts[0].x;
    verts[2].y = amp_y * sin_table_lookup(angle) + verts[0].y;
    while (angle < end) {
        verts[1].x = verts[2].x;
        verts[1].y = verts[2].y;
        angle += 0x800;
        if (angle > end) {
            angle = end & 0xFFFFFFFFFFFFFFFFu;
        }
        verts[2].x = amp_x * cos_table_lookup(angle) + verts[0].x;
        verts[2].y = amp_y * sin_table_lookup(angle) + verts[0].y;
        draw_polygon_2d(&prim, 3, 2, depth);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TWindowSimpleStatus::apply_random_shake() {
    s32 ang;
    f32 dist;

    if (this->shake_ticks != 0) {
        (this->shake_ticks)--;
        ang = (s32)(65536.0f * (3.0517578e-05f * (f32)rand()));
        dist = 5.0f * (3.0517578e-05f * (f32)rand());
        this->frame_position[0] += dist * cos_table_lookup(ang);
        this->frame_position[1] += dist * sin_table_lookup(ang);
    }
}
#pragma pop

void TWindowSimpleStatus::update_hp_tp_level() {
    WindowSpritePart *hp_label;
    WindowSpritePart *tp_label;
    hp_label = (WindowSpritePart *)this->get_array_entry(6);
    hp_label->color = this->update_hp_entry();
    tp_label = (WindowSpritePart *)this->get_array_entry(7);
    tp_label->color = this->update_hp_gauge();
    update_status_entry();
}

void WindowTextEntry::show_player_name(s32 client_id) {
    const char *str;
    TObjPlayer *player;
    CharacterAppearanceFields *appearance;

    player = get_player_by_client_id(client_id);
    if (player == NULL) {
        hide();
        return;
    }
    appearance = &player->appearance;
    if (appearance == NULL) {
        hide();
        return;
    }
    str = player->get_name();
    if (str == 0) {
        hide();
        return;
    }
    if (player->is_inactive() == 0) {
        hide();
        return;
    }
    show();
    if ((get_text() == NULL) || (strcmp(get_text(), str) != 0)) {
        set_text_entry_string(this, str, 0x20);
    }
    if (player->is_actor_dead() != 0) {
        color = 0xFFFF0000;
        return;
    }
    color = appearance->nameColor;
}

void update_lockon_window(TWindowSimpleStatus *window) {
    WindowTextEntry *name;
    name = (WindowTextEntry *)window->get_array_entry(1);
    name->show_player_name(window->get_width());
}

void update_photon_blast_player_marker(WindowSpritePart *help, s32 client_id) {
    PhotonBlastChainCopy chain;
    s32 type;
    u32 key;
    s32 r;
    s32 i;
    TObjPlayer *p;
    key = client_id;
    type = -1;
    if (key != 0xFFFF) {
        r = get_photon_blast_chain(&chain, client_id);
        if (r == 1 || r == 2) {
            s32 t;
            for (i = 0; (t = chain.kinds[i]) != -1; i++) {
                if (chain.participants[i] == key) {
                    break;
                }
            }
            type = t;
        }
        switch (type) {
        case 5:
            help->set_sprite_uv_from_pixels(0.0f, 173.0f);
            break;
        case 4:
            help->set_sprite_uv_from_pixels(34.0f, 173.0f);
            break;
        case 3:
            help->set_sprite_uv_from_pixels(68.0f, 173.0f);
            break;
        case 1:
            help->set_sprite_uv_from_pixels(102.0f, 173.0f);
            break;
        case 2:
            help->set_sprite_uv_from_pixels(136.0f, 173.0f);
            break;
        case 0:
            help->set_sprite_uv_from_pixels(170.0f, 173.0f);
            break;
        default:
            if (lobby_rule_settings.get_is_teams() == 1 && (p = get_player_by_client_id(key)) != 0) {
                key = p->pk_state.get_team() - 1;
            }
            help->set_sprite_uv_from_pixels(34.0f * key, 202.0f);
            break;
        }
    }
}

void update_status_help_item(TWindowSimpleStatus *window) {
    s32 client_id;

    client_id = window->get_width();
    if (get_current_floor_area() == AREA_LOBBY) {
        client_id = 0;
    }
    update_photon_blast_player_marker(static_cast<WindowSpritePart *>(window->get_array_entry(0)), client_id);
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void draw_photon_blast_gauge_ring(TWindowSimpleStatus *window, WindowDrawContext *ctx, const NJS_POINT2 *pos, f32 charge, f32 radius) {
    NJS_POINT2 p;
    u32 n;
    if (charge > 500.0f) {
        charge = 500.0f;
    }
    n = trunc_float(0.01f * charge);
    charge -= 100.0f * n;
    if (ctx->open_tick >= 0) {
        p.x = ctx->x + pos->x;
        p.y = ctx->y + pos->y;
        draw_photon_blast_fan(window, &p, ctx, photon_blast_gauge_ring_color_table[n], 0.0f, 0, 0xD700, radius);
        draw_photon_blast_fan(window, &p, ctx, photon_blast_gauge_ring_color_table[++n], 0.1f, 55040.0f - 0.01f * (55040.0f * charge), 0xD700, radius);
    }
}
#pragma pop

void TWindowSimpleStatus::draw_background(WindowDrawContext *ctx) {
    TexturedQuad r;
    NJS_POINT2 pos;
    NJS_POINT2 size;
    f32 scale;
    f32 f;

    TObjPlayer *player = get_player_by_client_id(TWindowSimpleStatus::get_width());
    if (player != 0) {
        f = player->get_photon_blast_charge();
    } else {
        f = 0.0f;
    }
    draw_photon_blast_gauge_ring(this, ctx, &photon_blast_gauge_ring_offset, f, 17.0f);
    pos.x = 6.0f + ctx->inner_x;
    pos.y = 2.0f + ctx->inner_y;
    size.x = 36.0f;
    size.y = 35.0f;
    scale = -1.0f / this->draw_depth;
    begin_screen_draw(1);
    set_texture_list(hud_texlist);
    set_draw_texture_and_color(0xB, ctx->color);
    r.x0 = pos.x;
    r.y0 = pos.y;
    r.x1 = r.x0 + size.x;
    r.y1 = r.y0 + size.y;
    r.u0 = 0.7421875f;
    r.v0 = 0.3125f;
    r.u1 = 0.8828125f;
    r.v1 = 0.44921875f;
    ctx->transform_quad(&r);
    draw_textured_quad_at_depth(&r.x0, scale);
    end_screen_draw();
    if (scanline_crosses_window(ctx, &pos.x, &size.x) != 0) {
        begin_window_sweep_draw(0xB);
        draw_window_sweep_strip(&r, ctx);
        end_window_sweep_draw(0xB);
    }
}

void TWindowSimpleStatus::render() {
    WindowDrawContext *ctx;
    ctx = draw_default_entry();
    draw_background(ctx);
    draw_visible_window_entries(this, &this->entry_list, ctx);
}

void TWindowSimpleStatus::run_task() {
    update_hp_tp_level();
    update_lockon_window(this);
    update_status_help_item(this);
    update_status_icons(const_cast<NJS_POINT2 *>(get_window_layout_position(0x1D)));
    update_window();
    update_fade();
    update_window_entry_list(&entry_list);
    apply_random_shake();
}


TWindowSimpleStatus::~TWindowSimpleStatus() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (w[i] != NULL) {
            w[i]->close();
            w[i] = NULL;
        }
    }
}

TWindowSimpleStatus::TWindowSimpleStatus(const NJS_POINT2 *position, s32 client, u8 *descriptor)
    : TWindowBase(descriptor, (s16)client, (u8 *)position) {
    m_name = TWindowSimpleStatus::class_name;
    client_index = (s16)client;
    shake_ticks = 0;
    display_age = -1.0f;
    for (s32 i = 0; i < 5; i++) {
        w[i] = NULL;
    }
}

TWindowSimpleStatus *TWindowSimpleStatus::create(const NJS_POINT2 *position, s32 client) {
    return new TWindowSimpleStatus(position, client, (u8 *)&simple_status_window_layout);
}
