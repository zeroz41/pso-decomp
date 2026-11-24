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
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include <string.h>
#include "pso/map/FloorArea.h"
#include "pso/ui/window/TWindowSubStatusDisp_8026F6DC.h"
#include "pso/ui/window/TWindowDD.h"

#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include "pso/ui/window/WindowLayout.h"

struct Disp_8026F9F4 { u8 p0[0x20]; s16 id; u8 p1[0x42]; void *windows[5]; };

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

extern "C" {
void TWindowComCard__set_column(u8 *arg0, s32 arg1);
void *TWindowComCard__sub_80249ED8(void *, void *, void *, s32, s32, s32);
void draw_photon_blast_fan(saddr, NJS_POINT2 *, Params_80270244 *, u32, f32, s32, s32, f32);
void draw_photon_blast_gauge_ring(s32 arg0, Params_80270244 *arg1, const NJS_POINT2 *arg2, f32 farg0, f32 farg1);
struct VtBase4_8026f71c_more_8026f8cc_0 { void *vtable; };

struct VObj3_8026f71c_more_8026f8cc_0 : VtBase4_8026f71c_more_8026f8cc_0 { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); };

struct Base_8026F77C_more_8026f8cc_0 { char pad[0x18]; };

struct VObj_8026F77C_more_8026f8cc_0 : Base_8026F77C_more_8026f8cc_0 {
    virtual void m0();virtual void m1();virtual void m2();virtual void m3();
    virtual void m4();virtual void m5();virtual void m6();virtual void m7();
    virtual void m8();virtual void m9();virtual void m10();virtual void m11();
    virtual void m12();virtual void m13();
    virtual int m14();
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

struct Rect_80270394 { f32 x0; f32 y0; f32 x1; f32 y1; f32 u0; f32 v0; f32 u1; f32 v1; };

s32 get_photon_blast_chain(Slots_80270060 *);
s32 TLobby__sub_801C19D0(void *);
s32 TWindowSubComCard__sub_802452DC(s32);
s32 TWindowSubComCard__sub_80245320(Rect_80270394 *, u8 *);
s32 TWindowSubComCard__sub_802454E4(s32);
s32 start_text_color_transition(void *, s32, f32);
}
s32 get_status_effect_icon_index(u32 arg0);
void set_text_entry_string(u8 *arg0, uaddr str, s32 arg2);
extern "C" {
void update_lockon_window(u8 *arg0);
s32 rand(void);
void begin_screen_draw(s32 mode);
s32 draw_textured_quad_at_depth(Rect_80270394 *, f32);
void set_draw_texture_and_color(s32 idx, s32 color);

extern s32 lobby_rule_settings[];

void TWindowSubStatusDisp::start_hp_text_color_transition() {
    u8 *arg0 = (u8 *)this;
    u8 *array_entry;
    array_entry = (u8 *)(((saddr)((TWindowBase *)arg0)->get_array_entry(4)));
    *(f32 *)((s8 *)array_entry + 0x20) = 0.0f;
    *(f32 *)((s8 *)array_entry + 0x24) = 0.0f;
    start_text_color_transition(array_entry, (s32)(0xFF008CFCU), 1.0f);
}

void TWindowSubStatusDisp::init_gauge_entry() {
    VObj3_8026f71c_more_8026f8cc_0 *array_entry;
    f32 temp_f0;

    array_entry = (VObj3_8026f71c_more_8026f8cc_0 *) get_array_entry(3);
    temp_f0 = 0.0f;
    *(f32 *)((s8 *)array_entry + 0x20) = temp_f0;
    *(f32 *)((s8 *)array_entry + 0x24) = temp_f0;
    array_entry->m3();
    start_text_color_transition(array_entry, 0xFF00FF15, 1.0f);
}

void TWindowSubStatusDisp::update_status_entry() {
    saddr arg0 = (saddr)this;
    void *temp_r31;
    VObj_8026F77C_more_8026f8cc_0 *player;

    player = (VObj_8026F77C_more_8026f8cc_0 *) get_player_by_client_id(((TWindowSimpleStatus *)this)->get_width());
    if (player != NULL) {
        temp_r31 = (void *)((TWindowBase *)arg0)->get_array_entry(2);
        *(s32 *)((s8 *)temp_r31 + 0x20) = player->m14() + 1;
    }
}

s32 TWindowSubStatusDisp::update_hp_gauge() {
    s32 rgb;
    s32 var_r31;
    void *array_entry;
    void *player;
    saddr arg0 = (saddr)this;

    player = get_player_by_client_id(((TWindowSimpleStatus *)this)->get_width());
    if (player == NULL) {
        ((TWindowSubStatusDisp *)arg0)->start_hp_text_color_transition();
        return 0xFF008CFC;
    }
    array_entry = (void *)((TWindowBase *)arg0)->get_array_entry(4);
    *(f32 *)((s8 *)array_entry + 0x20) = (f32) obj_getS16_2BA((u8 *)player);
    *(f32 *)((s8 *)array_entry + 0x24) = (f32) *(s16 *)((s8 *)player + 0x32E);
    if (*(f32 *)((s8 *)array_entry + 0x24) > (0.2f * *(f32 *)((s8 *)array_entry + 0x20))) {
        var_r31 = -1;
        rgb = 0xFF008CFC;
    } else {
        rgb = -0x3EEC;
        var_r31 = -0x3EEC;
    }
    start_text_color_transition(array_entry, rgb, 11.1f);
    return var_r31;
}

s32 TWindowSubStatusDisp::update_hp_entry() {
    s32 var_r30;
    s32 rgb;
    u8 *array_entry;
    u8 *player;
    player = (u8 *)get_player_by_client_id(((TWindowSimpleStatus *)this)->get_width());
    if (player == NULL) {
        this->init_gauge_entry();
        return 0xFF00FF15;
    }
    array_entry = (u8 *)(((u8 *)get_array_entry(3)));
    *(f32 *)((s8 *)array_entry + 0x20) = (f32) ((TObjChara *)player)->get_hpmax();
    if (*(f32 *)((s8 *)array_entry + 0x24) > (f32) *(s16 *)((s8 *)player + 0x32C)) {
        *(s32 *)((s8 *)((u8 *)this) + 0x60) = 4;
    }
    *(f32 *)((s8 *)array_entry + 0x24) = (f32) *(s16 *)((s8 *)player + 0x32C);
    if (*(f32 *)((s8 *)array_entry + 0x24) > (0.2f * *(f32 *)((s8 *)array_entry + 0x20))) {
        var_r30 = -1;
        rgb = 0xFF00FF15;
    } else {
        rgb = 0xFFF2FF19;
        var_r30 = 0xFFF2FF19;
    }
    start_text_color_transition(array_entry, rgb, 11.1f);
    return var_r30;
}

void TWindowSimpleStatus::update_status_icons(void *ofs) {
    Slots_80270060 buf;
    s32 k;
    s32 count;
    saddr i;
    s32 j;
    s32 name;
    void *w;
    void *player;
    player = get_player_by_client_id(((Disp_8026F9F4 *)this)->id);
    if (player == NULL || sub_80244994() == 0) {
        for (i = 0; i < 5; i++) {
            if (((Disp_8026F9F4 *)this)->windows[i] != NULL) {
                ((TWindowBase *)(((Disp_8026F9F4 *)this)->windows[i]))->close();
                ((Disp_8026F9F4 *)this)->windows[i] = NULL;
            }
        }
        return;
    }
    count = 0;
    j = 0;
    i = ((s32 (*)(Slots_80270060 *, s32))get_photon_blast_chain)(&buf, ((Disp_8026F9F4 *)this)->id);
    if (i == 1 || i == 2) {
        for (i = 0; buf.type[i] != -1; i++) {
            if (buf.id[i] == ((Disp_8026F9F4 *)this)->id) {
                break;
            }
        }
        name = (saddr)((TWindowComCard *)i)->get_card_name_ptr();
        w = ((Disp_8026F9F4 *)this)->windows[j];
        if (w == NULL) {
            w = new TWindowComCardFollower(this, (NJS_POINT2 *)ofs, 0, name, ((Disp_8026F9F4 *)this)->id);
            ((Disp_8026F9F4 *)this)->windows[j] = w;
            ((TWindowBase *)(((Disp_8026F9F4 *)this)->windows[j]))->set_depth(1.0f + ((TWindowBase *)((Disp_8026F9F4 *)this))->get_scale());
        } else {
            ((TWindowComCardFollower *)w)->set_column(0);
            ((TWindowComCardFollower *)(((Disp_8026F9F4 *)this)->windows[j]))->set_selected_index(name);
        }
        count = 1;
    } else if (((Disp_8026F9F4 *)this)->windows[j] != NULL) {
        ((TWindowBase *)(((Disp_8026F9F4 *)this)->windows[j]))->close();
        ((Disp_8026F9F4 *)this)->windows[j] = NULL;
    }
    j++;
    for (k = 0; k < 4; k++, j++) {
        s32 word = ((TObjChara *)player)->get_status_effect_type(k);
        if (word == 0) {
            if (((Disp_8026F9F4 *)this)->windows[j] != NULL) {
                ((TWindowBase *)(((Disp_8026F9F4 *)this)->windows[j]))->close();
                ((Disp_8026F9F4 *)this)->windows[j] = NULL;
            }
        } else {
            name = get_status_effect_icon_index(word);
            w = ((Disp_8026F9F4 *)this)->windows[j];
            if (w == NULL) {
                w = new TWindowComCardFollower(this, (NJS_POINT2 *)ofs, count, name, ((Disp_8026F9F4 *)this)->id);
                ((Disp_8026F9F4 *)this)->windows[j] = w;
                ((TWindowBase *)(((Disp_8026F9F4 *)this)->windows[j]))->set_depth(2.0f + ((f32)k + ((TWindowBase *)((Disp_8026F9F4 *)this))->get_scale()));
            } else {
                ((TWindowComCardFollower *)w)->set_column(count);
                ((TWindowComCardFollower *)(((Disp_8026F9F4 *)this)->windows[j]))->set_selected_index(name);
            }
            count++;
        }
    }
}

#pragma push
#pragma fp_contract on
void draw_photon_blast_fan(saddr window_simple_status, NJS_POINT2 *arg1, Params_80270244 *arg2, u32 arg3, f32 arg6, s32 arg4, s32 arg5, f32 arg7) {
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
    verts[0].x = arg2->f20 + arg2->f28 * (arg1->x - arg2->f20);
    verts[0].y = arg2->f24 + arg2->f2c * (arg1->y - arg2->f24);
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

    if (this->m_60 != 0) {
        (this->m_60)--;
        ang = (s32)(65536.0f * (3.0517578e-05f * (f32)rand()));
        dist = 5.0f * (3.0517578e-05f * (f32)rand());
        this->frame_position[0] += dist * cos_table_lookup(ang);
        this->frame_position[1] += dist * sin_table_lookup(ang);
    }
}
#pragma pop

void TWindowSubStatusDisp::update_hp_tp_level() {
    u8 *arg0 = (u8 *)this;
    saddr temp_r31;
    saddr temp_r31_2;
    temp_r31 = reinterpret_cast<saddr>(((TWindowBase *)arg0)->get_array_entry(6));
    *(s32 *)((s8 *)temp_r31 + 0x2C) = ((TWindowSubStatusDisp *)arg0)->update_hp_entry();
    temp_r31_2 = reinterpret_cast<saddr>(((TWindowBase *)arg0)->get_array_entry(7));
    *(s32 *)((s8 *)temp_r31_2 + 0x2C) = ((TWindowSubStatusDisp *)arg0)->update_hp_gauge();
    update_status_entry();
}

void TWindowLockOn::update_for_player_index(s32 id) {
    saddr str;
    struct VObj_8026ff0c *player;
    u8 *temp_r29;

    player = (VObj_8026ff0c *)get_player_by_client_id(id);
    if (player == NULL) {
        ((TWindowHelpItem *)((u8 *)this))->set_flag0_bit2();
        return;
    }
    temp_r29 = (u8 *)player + 0x85C;
    if (temp_r29 == NULL) {
        ((TWindowHelpItem *)((u8 *)this))->set_flag0_bit2();
        return;
    }
    str = player->m10();
    if (str == 0) {
        ((TWindowHelpItem *)((u8 *)this))->set_flag0_bit2();
        return;
    }
    if (((TObjPlayer *)player)->is_inactive() == 0) {
        ((TWindowHelpItem *)((u8 *)this))->set_flag0_bit2();
        return;
    }
    ((TWindowSubStatusDisp *)((u8 *)this))->clear_visible_flag();
    if ((((TWindowSubComCard *)((u8 *)this))->get_field_20() == 0U) || (strcmp((const char *)((TWindowSubComCard *)((u8 *)this))->get_field_20(), (const char *)str) != 0)) {
        set_text_entry_string(((u8 *)this), str, 0x20);
    }
    if (player->m31() != 0) {
        *(s32 *)&this->entry_list = 0xFFFF0000;
        return;
    }
    *(s32 *)&this->entry_list = (s32) *(s32 *)((s8 *)temp_r29 + 0x18);
}

void update_lockon_window(u8 *arg0) {
    saddr temp_r31;
    temp_r31 = reinterpret_cast<saddr>(((TWindowBase *)arg0)->get_array_entry(1));
    ((TWindowLockOn *)temp_r31)->update_for_player_index(((TWindowSimpleStatus *)arg0)->get_width());
}

void update_photon_blast_player_marker(saddr help, s32 arg1) {
    Slots_80270060 s;
    s32 type;
    u32 key;
    s32 r;
    s32 i;
    u8 *p;
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
            if (((TLobby *)lobby_rule_settings)->get_rule_field_a() == 1 && (p = (u8 *)get_player_by_client_id(key)) != 0) {
                key = TLobby__sub_801C19D0(p + 0x828) - 1;
            }
            set_sprite_uv_from_pixels(reinterpret_cast<WindowSpritePart *>(help), 34.0f * key, 202.0f);
            break;
        }
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
    Rect_80270394 r;
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
        TWindowSubComCard__sub_802454E4(0xB);
        TWindowSubComCard__sub_80245320(&r, ctx);
        TWindowSubComCard__sub_802452DC(0xB);
    }
}

extern "C" {
extern u8 __vt__19TWindowSimpleStatus[];
s32 update_hp_tp_level__20TWindowSubStatusDispFv();

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
    saddr arg0 = (saddr)this;
    update_hp_tp_level__20TWindowSubStatusDispFv();
    update_lockon_window((u8 *)arg0);
    update_status_help_item(arg0);
    ((TWindowSimpleStatus *)arg0)->update_status_icons((void *)(get_window_layout_position(0x1D)));
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((void *)(arg0 + 0x24)));
    ((TWindowSimpleStatus *)arg0)->apply_random_shake();
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
    m_60 = 0;
    m_58 = -1.0f;
    for (s32 i = 0; i < 5; i++) {
        w[i] = NULL;
    }
}

TWindowSimpleStatus *TWindowSimpleStatus::create(void *position, s32 client) {
    return new TWindowSimpleStatus(position, client, (u8 *)&simple_status_window_layout);
}

}
