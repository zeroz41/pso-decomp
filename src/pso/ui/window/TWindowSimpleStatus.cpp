#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "pso/render/ColorLineList.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025B050.h"
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
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TWindowStatusGaugeFeedback.h"
#include "pso/unk/TWindowLayoutNumber.h"
#include "pso/player/PlayerSlots.h"
#include <string.h>
#include "pso/map/FloorArea.h"
#include "pso/ui/window/TWindowSubStatusDisp_8026F6DC.h"
#include "pso/ui/window/TWindowDD.h"

#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/window/WindowLayout.h"
#include <stdlib.h>
#include "pso/map/area/AreaScene.h"

struct Params_80270244 { f32 x; f32 y; u8 pad8[0x18]; f32 f20; f32 f24; f32 f28; f32 f2c; s32 f30; };

#pragma push
#pragma readonly_strings on
const char *TWindowSimpleStatus__name = "TWindowSimpleStatus";
#pragma pop

// inferred: photon_blast_gauge_ring_offset, the ring's offset inside the window that
// draw_background passes to draw_photon_blast_gauge_ring.
static const NJS_POINT2 photon_blast_gauge_ring_offset = {24.0f, 19.0f};

// One colour per hundred points of photon blast charge (0..500); the ring draws [n] and [n + 1].
const u32 photon_blast_gauge_ring_color_table[7] = {
    0xFF3C3C3C, 0xFFD8CF00, 0xFFD88A00, 0xFFD84500, 0xFFD80000, 0xFFFFFFFF, 0,
};


// inferred: simple_status_window_layout_entries, the layout table simple_status_window_layout
// points at (frame sprite, two text/value entries, the HP and TP gauges, three icon sprites).
struct SimpleStatusWindowLayout {
    u32 cols;
    u32 rows;
    SpritePartLayoutRecord rec_0;
    TextLayoutRecord rec_1;
    ValueLayoutRecord rec_2;
    LayoutEntryCopyRecord rec_3;
    LayoutEntryCopyRecord rec_4;
    SpritePartLayoutRecord rec_5;
    SpritePartLayoutRecord rec_6;
    SpritePartLayoutRecord rec_7;
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

struct VObj_8026ff0c;

struct VObj_8026ff0c {
    char pad[0x18];
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
    virtual s32 m6();
    virtual s32 m7();
    virtual s32 m8();
    virtual s32 m9();
    virtual s32 m10();
    virtual s32 m11();
    virtual s32 m12();
    virtual s32 m13();
    virtual s32 m14();
    virtual s32 m15();
    virtual s32 m16();
    virtual s32 m17();
    virtual s32 m18();
    virtual s32 m19();
    virtual s32 m20();
    virtual s32 m21();
    virtual s32 m22();
    virtual s32 m23();
    virtual s32 m24();
    virtual s32 m25();
    virtual s32 m26();
    virtual s32 m27();
    virtual s32 m28();
    virtual s32 m29();
    virtual s32 m30();
    virtual s32 m31();
};

struct Slots_80270060 { s32 type[4]; u32 id[4]; };


extern "C" {
s32 get_photon_blast_chain(Slots_80270060 *);
s32 end_window_sweep_draw(s32);
s32 draw_window_sweep_strip(TexturedQuad *, u8 *);
s32 begin_window_sweep_draw(s32);
s32 start_text_color_transition(void *, s32, f32);
}
s32 get_status_effect_icon_index(u32 arg0);
void set_text_entry_string(u8 *arg0, uaddr str, s32 arg2);
extern "C" {
void begin_screen_draw(s32 mode);
s32 draw_textured_quad_at_depth(TexturedQuad *, f32);
void set_draw_texture_and_color(s32 idx, s32 color);

void TWindowSimpleStatus::start_hp_text_color_transition() {
    TWindowStatusGaugeFeedback *gauge = (TWindowStatusGaugeFeedback *)get_array_entry(4);
    gauge->maximum = 0.0f;
    gauge->target = 0.0f;
    start_text_color_transition(gauge, 0xFF008CFC, 1.0f);
}

void TWindowSimpleStatus::init_gauge_entry() {
    TWindowStatusGaugeFeedback *gauge = (TWindowStatusGaugeFeedback *)get_array_entry(3);
    gauge->maximum = 0.0f;
    gauge->target = 0.0f;
    gauge->calc_bar_width();
    start_text_color_transition(gauge, 0xFF00FF15, 1.0f);
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
    start_text_color_transition(gauge, rgb, 11.1f);
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
    start_text_color_transition(gauge, rgb, 11.1f);
    return color;
}

void TWindowSimpleStatus::update_status_icons(void *ofs) {
    Slots_80270060 buf;
    s32 k;
    s32 count;
    saddr i;
    s32 j;
    s32 name;
    TWindowBase *window;
    void *player;
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
    i = ((s32 (*)(Slots_80270060 *, s32))get_photon_blast_chain)(&buf, this->client_index);
    if (i == 1 || i == 2) {
        for (i = 0; buf.type[i] != -1; i++) {
            if (buf.id[i] == this->client_index) {
                break;
            }
        }
        name = (saddr)((TWindowComCard *)i)->get_card_name_ptr();
        window = this->w[j];
        if (window == NULL) {
            window = new TWindowComCardFollower(this, (NJS_POINT2 *)ofs, 0, name, this->client_index);
            this->w[j] = window;
            this->w[j]->set_depth(1.0f + get_scale());
        } else {
            ((TWindowComCardFollower *)window)->set_column(0);
            ((TWindowComCardFollower *)this->w[j])->set_selected_index(name);
        }
        count = 1;
    } else if (this->w[j] != NULL) {
        this->w[j]->close();
        this->w[j] = NULL;
    }
    j++;
    for (k = 0; k < 4; k++, j++) {
        s32 word = ((TObjChara *)player)->get_status_effect_type(k);
        if (word == 0) {
            if (this->w[j] != NULL) {
                this->w[j]->close();
                this->w[j] = NULL;
            }
        } else {
            name = get_status_effect_icon_index(word);
            window = this->w[j];
            if (window == NULL) {
                window = new TWindowComCardFollower(this, (NJS_POINT2 *)ofs, count, name, this->client_index);
                this->w[j] = window;
                this->w[j]->set_depth(2.0f + ((f32)k + get_scale()));
            } else {
                ((TWindowComCardFollower *)window)->set_column(count);
                ((TWindowComCardFollower *)this->w[j])->set_selected_index(name);
            }
            count++;
        }
    }
}

#pragma push
#pragma fp_contract on
void draw_photon_blast_fan(saddr window_simple_status, NJS_POINT2 *njs_point2, Params_80270244 *arg2, u32 arg3, f32 arg6, s32 arg4, s32 arg5, f32 arg7) {
    NJS_POINT2 verts[3];
    NJS_POINT2COL prim;
    NJS_COLOR colors[3];
    s32 end = arg5;
    s32 angle = arg4;
    f32 amp_x;
    f32 amp_y;
    f32 depth;

    depth = ((TWindowSimpleStatus *)window_simple_status)->draw_depth + 0.299f * arg6;
    amp_x = arg7 * arg2->f28;
    amp_y = arg7 * arg2->f2c;
    prim.p = verts;
    prim.col = colors;
    prim.tex = NULL;
    prim.num = 1;
    colors[2].color = colors[1].color = colors[0].color = (arg3 << 8) | (arg3 >> 24);
    verts[0].x = arg2->f20 + arg2->f28 * (njs_point2->x - arg2->f20);
    verts[0].y = arg2->f24 + arg2->f2c * (njs_point2->y - arg2->f24);
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
    saddr temp_r31;
    saddr temp_r31_2;
    temp_r31 = reinterpret_cast<saddr>(this->get_array_entry(6));
    *(s32 *)((s8 *)temp_r31 + 0x2C) = this->update_hp_entry();
    temp_r31_2 = reinterpret_cast<saddr>(this->get_array_entry(7));
    *(s32 *)((s8 *)temp_r31_2 + 0x2C) = this->update_hp_gauge();
    update_status_entry();
}

void TWindowLockOn::update_for_player_index(s32 id) {
    saddr str;
    struct VObj_8026ff0c *player;
    u8 *temp_r29;

    player = (VObj_8026ff0c *)get_player_by_client_id(id);
    if (player == NULL) {
        ((TWindowHelpItem *)(this))->set_flag0_bit2();
        return;
    }
    temp_r29 = (u8 *)player + 0x85C;
    if (temp_r29 == NULL) {
        ((TWindowHelpItem *)(this))->set_flag0_bit2();
        return;
    }
    str = player->m10();
    if (str == 0) {
        ((TWindowHelpItem *)(this))->set_flag0_bit2();
        return;
    }
    if (((TObjPlayer *)player)->is_inactive() == 0) {
        ((TWindowHelpItem *)(this))->set_flag0_bit2();
        return;
    }
    ((TWindowSubStatusDisp *)(this))->clear_visible_flag();
    if ((((TWindowSubComCard *)(this))->get_field_20() == 0U) || (strcmp((const char *)((TWindowSubComCard *)(this))->get_field_20(), (const char *)str) != 0)) {
        set_text_entry_string(((u8 *)this), str, 0x20);
    }
    if (player->m31() != 0) {
        *(s32 *)&this->entry_list = 0xFFFF0000;
        return;
    }
    *(s32 *)&this->entry_list = (s32) *(s32 *)((s8 *)temp_r29 + 0x18);
}

void update_lockon_window(u8 *window_simple_status) {
    saddr temp_r31;
    temp_r31 = reinterpret_cast<saddr>(((TWindowBase *)window_simple_status)->get_array_entry(1));
    ((TWindowLockOn *)temp_r31)->update_for_player_index(((TWindowSimpleStatus *)window_simple_status)->get_width());
}
}

void update_photon_blast_player_marker(saddr help, s32 arg1) {
    Slots_80270060 s;
    s32 type;
    u32 key;
    s32 r;
    s32 i;
    TObjPlayer *p;
    key = arg1;
    type = -1;
    if (key != 0xFFFF) {
        r = get_photon_blast_chain(&s);
        if (r == 1 || r == 2) {
            s32 t;
            for (i = 0; (t = s.type[i]) != -1; i++) {
                if (s.id[i] == key) {
                    break;
                }
            }
            type = t;
        }
        switch (type) {
        case 5:
            set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(help), 0.0f, 173.0f);
            break;
        case 4:
            set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(help), 34.0f, 173.0f);
            break;
        case 3:
            set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(help), 68.0f, 173.0f);
            break;
        case 1:
            set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(help), 102.0f, 173.0f);
            break;
        case 2:
            set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(help), 136.0f, 173.0f);
            break;
        case 0:
            set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(help), 170.0f, 173.0f);
            break;
        default:
            if (((TLobby *)lobby_rule_settings)->get_rule_field_a() == 1 && (p = get_player_by_client_id(key)) != 0) {
                key = p->pk_state.get_team() - 1;
            }
            set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(help), 34.0f * key, 202.0f);
            break;
        }
    }
}

void update_status_help_item(saddr arg0) {
    s32 var_r31;

    var_r31 = ((TWindowSimpleStatus *)arg0)->get_width();
    if (get_current_floor_area() == AREA_LOBBY) {
        var_r31 = 0;
    }
    update_photon_blast_player_marker((saddr)((TWindowBase *)arg0)->get_array_entry(0), var_r31);
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
extern "C" {
void draw_photon_blast_gauge_ring(s32 window_simple_status, Params_80270244 *ctx, const NJS_POINT2 *pos, f32 farg0, f32 farg1) {
    NJS_POINT2 p;
    u32 n;
    if (farg0 > 500.0f) {
        farg0 = 500.0f;
    }
    n = TWindowSubComCard::trunc_float(0.01f * farg0);
    farg0 -= 100.0f * n;
    if (ctx->f30 >= 0) {
        p.x = ctx->x + pos->x;
        p.y = ctx->y + pos->y;
        draw_photon_blast_fan(window_simple_status, &p, ctx, photon_blast_gauge_ring_color_table[n], 0.0f, 0, 0xD700, farg1);
        draw_photon_blast_fan(window_simple_status, &p, ctx, photon_blast_gauge_ring_color_table[++n], 0.1f, 55040.0f - 0.01f * (55040.0f * farg0), 0xD700, farg1);
    }
}
}
#pragma pop

void TWindowSimpleStatus::draw_background(u8 *ctx) {
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
    draw_photon_blast_gauge_ring((saddr)this, (Params_80270244 *)(ctx), &photon_blast_gauge_ring_offset, f, 17.0f);
    pos.x = 6.0f + *(f32 *)((s8 *)ctx + 0x10);
    pos.y = 2.0f + *(f32 *)((s8 *)ctx + 0x14);
    size.x = 36.0f;
    size.y = 35.0f;
    scale = -1.0f / this->draw_depth;
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(0xB, *(s32 *)((s8 *)ctx + 0x34));
    r.x0 = pos.x;
    r.y0 = pos.y;
    r.x1 = r.x0 + size.x;
    r.y1 = r.y0 + size.y;
    r.u0 = 0.7421875f;
    r.v0 = 0.3125f;
    r.u1 = 0.8828125f;
    r.v1 = 0.44921875f;
    ((WindowDrawContext *)ctx)->transform_quad((TexturedQuad *)&r);
    draw_textured_quad_at_depth(&r, scale);
    TWindowSubStatusDisp::get_player();
    if (TWindowSubComCard__sub_80245558(ctx, &pos, &size) != 0) {
        begin_window_sweep_draw(0xB);
        draw_window_sweep_strip(&r, ctx);
        end_window_sweep_draw(0xB);
    }
}

void TWindowSimpleStatus::render() {
    saddr ctx;
    ctx = reinterpret_cast<saddr>(draw_default_entry());
    draw_background((u8 *)ctx);
    draw_visible_window_entries(
        this,
        &this->entry_list,
        reinterpret_cast<WindowDrawContext *>(ctx));
}

void TWindowSimpleStatus::run_task() {
    update_hp_tp_level();
    update_lockon_window((u8 *)this);
    update_status_help_item((saddr)this);
    update_status_icons((void *)(get_window_layout_position(0x1D)));
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

TWindowSimpleStatus::TWindowSimpleStatus(void *position, s32 client, u8 *descriptor)
    : TWindowBase(descriptor, (s16)client, (u8 *)position) {
    m_name = TWindowSimpleStatus__name;
    client_index = (s16)client;
    shake_ticks = 0;
    m_58 = -1.0f;
    for (s32 i = 0; i < 5; i++) {
        w[i] = NULL;
    }
}

TWindowSimpleStatus *TWindowSimpleStatus::create(void *position, s32 client) {
    return new TWindowSimpleStatus(position, client, (u8 *)&simple_status_window_layout);
}
