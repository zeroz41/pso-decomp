#include "types.h"
#include "pso/misc/TWindowComCard.h"
#include "pso/misc/TWindowLockOn.h"
#include "pso/misc/TWindowSimpleStatus.h"
#include "pso/misc/TUnk_804CE018.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/item/TItemProShield.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowHelpItem.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"

struct Disp_8026F9F4 { u8 p0[0x20]; s16 id; u8 p1[0x42]; void *windows[5]; };

struct Vec2_80270244 { f32 x; f32 y; };

struct Params_80270244 { f32 x; f32 y; u8 pad8[0x28]; s32 f30; };

extern "C" {
int obj_getArrWord_254(void *p, int i);
void * get_player_by_client_id();
void *__nw__7TObjectFUl(int);
void TWindow__close(u8 *arg0);
void TWindowComCard__sub_80249D7C(u8 *arg0, s32 arg1);
void *TWindowComCard__sub_80249ED8(void *, void *, void *, s32, s32, s32);
extern const f32 lbl_805DD38C;
extern const f32 lbl_805DD398;
s32 draw_photon_blast_fan(s32, Vec2_80270244 *, Params_80270244 *, u32, s32, s32, f32, f32);
extern u32 photon_blast_gauge_ring_color_table[];
extern const f32 lbl_805DD388;
extern const f32 lbl_805DD3C8;
extern const f32 lbl_805DD3CC;
extern const f32 lbl_805DD3D0;
extern const f32 lbl_805DD3D4;
extern const f32 lbl_805DD3D8;
void draw_photon_blast_gauge_ring(s32 arg0, Params_80270244 *arg1, const Vec2_80270244 *arg2, f32 farg0, f32 farg1);
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

struct Vec2_80270394 { f32 x; f32 y; };

struct Rect_80270394 { f32 x0; f32 y0; f32 x1; f32 y1; f32 u0; f32 v0; f32 u1; f32 v1; };

s16 obj_getS16_2BA(u8 *p);
s32 get_sub_value__8TItemMagFv();
s32 get_photon_blast_chain(Slots_80270060 *);
s32 TLobby__sub_801C19D0(void *);
void * get_array_entry__13TUnk_804CE018Fi(void *, s32);
s32 TWindowSubComCard__sub_802452DC(s32);
s32 TWindowSubComCard__sub_80245320(Rect_80270394 *, u8 *);
s32 TWindowSubComCard__sub_802454E4(s32);
s32 TWindowSubComCard__sub_80245558(u8 *, Vec2_80270394 *, Vec2_80270394 *);
s32 get_width__19TWindowSimpleStatusFv();
s32 apply_context_transform_to_rect(u8 *, Rect_80270394 *);
s32 start_text_color_transition(void *, s32, f32);
}
s32 get_status_effect_icon_index(u32 arg0);
void set_text_entry_string(u8 *arg0, u32 str, s32 arg2);
void set_sprite_uv_from_pixels(u8 *arg0, f32 farg0, f32 farg1);
extern "C" {
void update_lockon_window(u8 *arg0);
s32 update_photon_blast_player_marker(s32 arg0, s32 arg1);
s32 rand(void);
s32 strcmp(s32, s32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
void begin_screen_draw(s32 arg0);
s32 draw_textured_quad_at_depth(Rect_80270394 *, f32);
void set_draw_texture_and_color(s32 idx, s32 arg1);

extern s32 lbl_8044F5E4[];
extern s32 lobby_rule_settings[];
extern s32 lbl_805D63F0;
extern const f32 lbl_805DD390;
extern const f32 lbl_805DD394;
extern const f32 lbl_805DD3A0;
extern const f32 lbl_805DD3A4;
extern const f32 lbl_805DD3A8;
extern const f32 lbl_805DD3AC;
extern const f32 lbl_805DD3B0;
extern const f32 lbl_805DD3B4;
extern const f32 lbl_805DD3B8;
extern const f32 lbl_805DD3BC;
extern const f32 lbl_805DD3C0;
extern const f32 lbl_805DD3C4;
extern const f32 lbl_805DD3DC;
extern const f32 lbl_805DD3E0;
extern const f32 lbl_805DD3E4;
extern const f32 lbl_805DD3E8;
extern const f32 lbl_805DD3EC;
extern const f32 lbl_805DD3F0;
extern const f32 lbl_805DD3F4;
extern const f32 lbl_805DD3F8;
extern const f32 lbl_805DD3FC;

void TWindowSubStatusDisp::start_hp_text_color_transition() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    temp_r3 = (u8 *)(((s32)get_array_entry__13TUnk_804CE018Fi(arg0, 4)));
    *(f32 *)((s8 *)temp_r3 + 0x20) = (f32) (*(const f32 *)&lbl_805DD388);
    *(f32 *)((s8 *)temp_r3 + 0x24) = (f32) (*(const f32 *)&lbl_805DD388);
    start_text_color_transition(temp_r3, (s32)(0xFF008CFCU), (*(const f32 *)&lbl_805DD38C));
}

void TWindowSubStatusDisp::init_gauge_entry() {
    VObj3_8026f71c_more_8026f8cc_0 *temp_r3;
    f32 temp_f0;

    temp_r3 = (VObj3_8026f71c_more_8026f8cc_0 *) get_array_entry__13TUnk_804CE018Fi(this, 3);
    temp_f0 = lbl_805DD388;
    *(f32 *)((s8 *)temp_r3 + 0x20) = temp_f0;
    *(f32 *)((s8 *)temp_r3 + 0x24) = temp_f0;
    temp_r3->m3();
    start_text_color_transition(temp_r3, 0xFF00FF15, lbl_805DD38C);
}

void TWindowSubStatusDisp::update_status_entry() {
    s32 arg0 = (s32)this;
    void *temp_r31;
    VObj_8026F77C_more_8026f8cc_0 *player;

    get_width__19TWindowSimpleStatusFv();
    player = (VObj_8026F77C_more_8026f8cc_0 *) get_player_by_client_id();
    if (player != NULL) {
        temp_r31 = get_array_entry__13TUnk_804CE018Fi((void *)arg0, 2);
        *(s32 *)((s8 *)temp_r31 + 0x20) = player->m14() + 1;
    }
}

s32 TWindowSubStatusDisp::update_hp_gauge() {
    s32 var_r4;
    s32 var_r31;
    void *temp_r30;
    void *temp_r3;
    s32 arg0 = (s32)this;

    get_width__19TWindowSimpleStatusFv();
    temp_r3 = get_player_by_client_id();
    if (temp_r3 == NULL) {
        ((TWindowSubStatusDisp *)arg0)->start_hp_text_color_transition();
        return 0xFF008CFC;
    }
    temp_r30 = get_array_entry__13TUnk_804CE018Fi((void *)arg0, 4);
    *(f32 *)((s8 *)temp_r30 + 0x20) = (f32) obj_getS16_2BA((u8 *)temp_r3);
    *(f32 *)((s8 *)temp_r30 + 0x24) = (f32) *(s16 *)((s8 *)temp_r3 + 0x32E);
    if (*(f32 *)((s8 *)temp_r30 + 0x24) > (lbl_805DD390 * *(f32 *)((s8 *)temp_r30 + 0x20))) {
        var_r31 = -1;
        var_r4 = 0xFF008CFC;
    } else {
        var_r4 = -0x3EEC;
        var_r31 = -0x3EEC;
    }
    start_text_color_transition(temp_r30, var_r4, lbl_805DD394);
    return var_r31;
}

s32 TWindowSubStatusDisp::update_hp_entry() {
    s32 var_r30;
    s32 var_r4;
    u8 *temp_r31;
    u8 *player;
    get_width__19TWindowSimpleStatusFv();
    player = (u8 *)(((u8 *)get_player_by_client_id()));
    if (player == NULL) {
        this->init_gauge_entry();
        return 0xFF00FF15;
    }
    temp_r31 = (u8 *)(((u8 *)get_array_entry__13TUnk_804CE018Fi(this, 3)));
    *(f32 *)((s8 *)temp_r31 + 0x20) = (f32) ((TItemProShield *)player)->get_field_2b8();
    if (*(f32 *)((s8 *)temp_r31 + 0x24) > (f32) *(s16 *)((s8 *)player + 0x32C)) {
        *(s32 *)((s8 *)((u8 *)this) + 0x60) = 4;
    }
    *(f32 *)((s8 *)temp_r31 + 0x24) = (f32) *(s16 *)((s8 *)player + 0x32C);
    if (*(f32 *)((s8 *)temp_r31 + 0x24) > (lbl_805DD390 * *(f32 *)((s8 *)temp_r31 + 0x20))) {
        var_r30 = -1;
        var_r4 = 0xFF00FF15;
    } else {
        var_r4 = 0xFFF2FF19;
        var_r30 = 0xFFF2FF19;
    }
    start_text_color_transition(temp_r31, var_r4, lbl_805DD394);
    return var_r30;
}

void TWindowSimpleStatus::update_status_icons(void *ofs) {
    Slots_80270060 buf;
    s32 k;
    s32 count;
    s32 i;
    s32 j;
    s32 name;
    void *w;
    void *player;
    player = ((void *(*)(s32))get_player_by_client_id)(((Disp_8026F9F4 *)this)->id);
    if (player == NULL || sub_80244994() == 0) {
        for (i = 0; i < 5; i++) {
            if (((Disp_8026F9F4 *)this)->windows[i] != NULL) {
                TWindow__close((u8 *)(((Disp_8026F9F4 *)this)->windows[i]));
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
        name = (s32)((TWindowComCard *)i)->get_card_name_ptr();
        w = ((Disp_8026F9F4 *)this)->windows[j];
        if (w == NULL) {
            w = __nw__7TObjectFUl(0x74);
            if (w != NULL) {
                w = TWindowComCard__sub_80249ED8(w, ((Disp_8026F9F4 *)this), ofs, 0, name, ((Disp_8026F9F4 *)this)->id);
            }
            ((Disp_8026F9F4 *)this)->windows[j] = w;
            ((TLobby *)(((Disp_8026F9F4 *)this)->windows[j]))->set_field_1c(lbl_805DD38C + ((TUnk_804CE018 *)((Disp_8026F9F4 *)this))->get_scale());
        } else {
            TWindowComCard__sub_80249D7C((u8 *)w, 0);
            ((TWindowComCard *)(((Disp_8026F9F4 *)this)->windows[j]))->set_selected_index(name);
        }
        count = 1;
    } else if (((Disp_8026F9F4 *)this)->windows[j] != NULL) {
        TWindow__close((u8 *)(((Disp_8026F9F4 *)this)->windows[j]));
        ((Disp_8026F9F4 *)this)->windows[j] = NULL;
    }
    j++;
    for (k = 0; k < 4; k++, j++) {
        s32 word = obj_getArrWord_254(player, k);
        if (word == 0) {
            if (((Disp_8026F9F4 *)this)->windows[j] != NULL) {
                TWindow__close((u8 *)(((Disp_8026F9F4 *)this)->windows[j]));
                ((Disp_8026F9F4 *)this)->windows[j] = NULL;
            }
        } else {
            name = get_status_effect_icon_index(word);
            w = ((Disp_8026F9F4 *)this)->windows[j];
            if (w == NULL) {
                w = __nw__7TObjectFUl(0x74);
                if (w != NULL) {
                    w = TWindowComCard__sub_80249ED8(w, ((Disp_8026F9F4 *)this), ofs, count, name, ((Disp_8026F9F4 *)this)->id);
                }
                ((Disp_8026F9F4 *)this)->windows[j] = w;
                ((TLobby *)(((Disp_8026F9F4 *)this)->windows[j]))->set_field_1c(lbl_805DD398 + ((f32)k + ((TUnk_804CE018 *)((Disp_8026F9F4 *)this))->get_scale()));
            } else {
                TWindowComCard__sub_80249D7C((u8 *)w, count);
                ((TWindowComCard *)(((Disp_8026F9F4 *)this)->windows[j]))->set_selected_index(name);
            }
            count++;
        }
    }
}

#pragma push
#pragma fp_contract on
void TWindowSimpleStatus::apply_random_shake() {
    s32 ang;
    f32 dist;

    if (this->m_60 != 0) {
        (this->m_60)--;
        ang = (s32)(lbl_805DD3A0 * (lbl_805DD3A4 * (f32)rand()));
        dist = lbl_805DD3A8 * (lbl_805DD3A4 * (f32)rand());
        this->m_40 += dist * cos_table_lookup(ang);
        *(f32 *)(((u8 *)this) + 0x44) += dist * sin_table_lookup(ang);
    }
}
#pragma pop

void TWindowSubStatusDisp::update_hp_tp_level() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r31;
    s32 temp_r31_2;
    temp_r31 = ((s32 (*)(void *, int))get_array_entry__13TUnk_804CE018Fi)(arg0, 6);
    *(s32 *)((s8 *)temp_r31 + 0x2C) = ((TWindowSubStatusDisp *)arg0)->update_hp_entry();
    temp_r31_2 = ((s32 (*)(void *, int))get_array_entry__13TUnk_804CE018Fi)(arg0, 7);
    *(s32 *)((s8 *)temp_r31_2 + 0x2C) = ((TWindowSubStatusDisp *)arg0)->update_hp_gauge();
    update_status_entry();
}

void TWindowLockOn::update_for_player_index(s32 arg1) {
    s32 temp_r31;
    struct VObj_8026ff0c *temp_r30;
    u8 *temp_r29;

    temp_r30 = ((VObj_8026ff0c * (*)(s32))get_player_by_client_id)(arg1);
    if (temp_r30 == NULL) {
        ((TWindowHelpItem *)((u8 *)this))->set_flag0_bit2();
        return;
    }
    temp_r29 = (u8 *)temp_r30 + 0x85C;
    if (temp_r29 == NULL) {
        ((TWindowHelpItem *)((u8 *)this))->set_flag0_bit2();
        return;
    }
    temp_r31 = temp_r30->m10();
    if (temp_r31 == 0) {
        ((TWindowHelpItem *)((u8 *)this))->set_flag0_bit2();
        return;
    }
    if (((TObjPlayer *)temp_r30)->is_inactive() == 0) {
        ((TWindowHelpItem *)((u8 *)this))->set_flag0_bit2();
        return;
    }
    ((TWindowSubStatusDisp *)((u8 *)this))->clear_visible_flag();
    if ((((TWindowSubComCard *)((u8 *)this))->get_field_20() == 0U) || (strcmp(((TWindowSubComCard *)((u8 *)this))->get_field_20(), temp_r31) != 0)) {
        set_text_entry_string(((u8 *)this), temp_r31, 0x20);
    }
    if (temp_r30->m31() != 0) {
        *(s32 *)&this->m_24 = 0xFFFF0000;
        return;
    }
    *(s32 *)&this->m_24 = (s32) *(s32 *)((s8 *)temp_r29 + 0x18);
}

void update_lockon_window(u8 *arg0) {
    s32 temp_r31;
    temp_r31 = ((s32 (*)(void *, int))get_array_entry__13TUnk_804CE018Fi)(arg0, 1);
    ((TWindowLockOn *)temp_r31)->update_for_player_index(((s32 (*)(void *))get_width__19TWindowSimpleStatusFv)(arg0));
}

s32 update_photon_blast_player_marker(s32 arg0, s32 arg1) {
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
            set_sprite_uv_from_pixels((u8 *)arg0, lbl_805DD388, lbl_805DD3AC);
            break;
        case 4:
            set_sprite_uv_from_pixels((u8 *)arg0, lbl_805DD3B0, lbl_805DD3AC);
            break;
        case 3:
            set_sprite_uv_from_pixels((u8 *)arg0, lbl_805DD3B4, lbl_805DD3AC);
            break;
        case 1:
            set_sprite_uv_from_pixels((u8 *)arg0, lbl_805DD3B8, lbl_805DD3AC);
            break;
        case 2:
            set_sprite_uv_from_pixels((u8 *)arg0, lbl_805DD3BC, lbl_805DD3AC);
            break;
        case 0:
            set_sprite_uv_from_pixels((u8 *)arg0, lbl_805DD3C0, lbl_805DD3AC);
            break;
        default:
            if (((TLobby *)lobby_rule_settings)->get_rule_field_a() == 1 && (p = ((u8 * (*)(u32))get_player_by_client_id)(key)) != 0) {
                key = TLobby__sub_801C19D0(p + 0x828) - 1;
            }
            set_sprite_uv_from_pixels((u8 *)arg0, lbl_805DD3B0 * key, lbl_805DD3C4);
            break;
        }
    }
}

void update_status_help_item(s32 arg0) {
    s32 var_r31;

    var_r31 = get_width__19TWindowSimpleStatusFv();
    if (get_current_floor_area() == AREA_LOBBY) {
        var_r31 = 0;
    }
    update_photon_blast_player_marker((s32)(((s32 (*)(s32, s32))get_array_entry__13TUnk_804CE018Fi)(arg0, 0)), var_r31);
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void draw_photon_blast_gauge_ring(s32 arg0, Params_80270244 *arg1, const Vec2_80270244 *arg2, f32 farg0, f32 farg1) {
    Vec2_80270244 p;
    u32 n;
    if (farg0 > lbl_805DD3C8) {
        farg0 = lbl_805DD3C8;
    }
    n = TWindowSubComCard::trunc_float(lbl_805DD3CC * farg0);
    farg0 -= lbl_805DD3D0 * n;
    if (arg1->f30 >= 0) {
        p.x = arg1->x + arg2->x;
        p.y = arg1->y + arg2->y;
        draw_photon_blast_fan(arg0, &p, arg1, photon_blast_gauge_ring_color_table[n], 0, 0xD700, lbl_805DD388, farg1);
        draw_photon_blast_fan(arg0, &p, arg1, photon_blast_gauge_ring_color_table[++n], lbl_805DD3D8 - lbl_805DD3CC * (lbl_805DD3D8 * farg0), 0xD700, lbl_805DD3D4, farg1);
    }
}
#pragma pop

void TWindowSimpleStatus::draw_background(u8 *arg1) {
    Rect_80270394 r;
    Vec2_80270394 pos;
    Vec2_80270394 size;
    f32 scale;
    f32 f;

    get_width__19TWindowSimpleStatusFv();
    if (((u32 (*)(void))get_player_by_client_id)() != 0) {
        f = get_sub_value__8TItemMagFv();
    } else {
        f = lbl_805DD388;
    }
    draw_photon_blast_gauge_ring((s32)this, (Params_80270244 *)(arg1), (const Vec2_80270244 *)(lbl_8044F5E4), f, lbl_805DD3DC);
    pos.x = lbl_805DD3E0 + *(f32 *)((s8 *)arg1 + 0x10);
    pos.y = lbl_805DD398 + *(f32 *)((s8 *)arg1 + 0x14);
    size.x = lbl_805DD3E4;
    size.y = lbl_805DD3E8;
    scale = lbl_805DD3EC / this->m_54;
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D63F0);
    set_draw_texture_and_color(0xB, *(s32 *)((s8 *)arg1 + 0x34));
    r.x0 = pos.x;
    r.y0 = pos.y;
    r.x1 = r.x0 + size.x;
    r.y1 = r.y0 + size.y;
    r.u0 = lbl_805DD3F0;
    r.v0 = lbl_805DD3F4;
    r.u1 = lbl_805DD3F8;
    r.v1 = lbl_805DD3FC;
    apply_context_transform_to_rect(arg1, &r);
    draw_textured_quad_at_depth(&r, scale);
    TWindowSubStatusDisp::get_player();
    if (TWindowSubComCard__sub_80245558(arg1, &pos, &size) != 0) {
        TWindowSubComCard__sub_802454E4(0xB);
        TWindowSubComCard__sub_80245320(&r, arg1);
        TWindowSubComCard__sub_802452DC(0xB);
    }
}
}
