#include "pso/ui/window/TWindowCtrlMain_8024674C.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_8036AEF8.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/memory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/math/AngleLookup.h"

struct Col_8036B1AC { s8 r; u8 g, b, a; };

struct Obj_8036B1AC {
    u32 f0;
    u16 ids[4];
    Col_8036B1AC cols[12];
};

extern "C" {
extern s32 lbl_804F3610[];
s32 lbl_805D7000;
void TLobby__sub_8036B1AC(Obj_8036B1AC *payload);

s32 **TBoss8Dragon__sub_8036AEF8(s32 **arg0, s16 arg1) {
    if (arg0 != NULL) {
        *arg0 = lbl_804F3610;
        if (arg1 > 0) {
            ::operator delete(arg0);
        }
    }
    return arg0;
}

void TBoss8Dragon__sub_8036AF40(s32 **arg0) {
    *arg0 = lbl_804F3610;
}

#pragma push
#pragma fp_contract on
void TBoss8Dragon__sub_8036AF50(f32 *o, f32 *p, s32 a, s32 b) {
    f32 q[18];
    f32 s;
    f32 c;
    f32 s2;
    f32 c2;
    s = 128.0f * sin_table_lookup(a);
    c = 128.0f * cos_table_lookup(a);
    q[0] = (o[0] - 0.5f * (c * p[0])) + 0.5f * (s * p[1]);
    q[1] = (o[1] - 0.5f * (s * p[0])) - 0.5f * (c * p[1]);
    q[3] = c * p[0];
    q[4] = s * p[0];
    q[5] = -s * p[1];
    q[6] = c * p[1];
    q[2] = 0.5f;
    s2 = 128.0f * sin_table_lookup(b);
    c2 = 128.0f * cos_table_lookup(b);
    q[8] = (0.5f * s2 + (156.0f - 0.5f * c2)) / 256.0f;
    q[9] = ((156.0f - 0.5f * s2) - 0.5f * c2) / 256.0f;
    q[10] = c2 / 256.0f;
    q[11] = s2 / 256.0f;
    q[12] = -s2 / 256.0f;
    q[13] = c2 / 256.0f;
    DVDConvertEntrynumToPath(q);
}
#pragma pop

void TBoss8Dragon__sub_8036B088(void) {
    f32 o[2];
    f32 p[2];
    s32 ang;
    ang = (-lbl_805D7000 << 16) / 30;
    set_additive_blend();
    TParticleCtrl::begin_effect_render();
    TCameraCtrl::restore_full_screen_view();
    begin_screen_draw(1);
    TObjFish::set_global_param(hud_texlist);
    set_draw_texture_and_color(5, -1);
    o[0] = (545.0f);
    o[1] = (3.9e+02f);
    p[1] = p[0] = 1.0f;
    TBoss8Dragon__sub_8036AF50(o, p, 0, ang);
    p[0] = 1.0f;
    p[1] = (0.5f);
    TBoss8Dragon__sub_8036AF50(o, p, 0, ang);
    p[0] = 1.0f;
    p[1] = (0.5f);
    TBoss8Dragon__sub_8036AF50(o, p, 0x2000, ang);
    p[0] = 1.0f;
    p[1] = (0.5f);
    TBoss8Dragon__sub_8036AF50(o, p, -0x2000, ang);
    TWindowSubStatusDisp::get_player();
    set_default_alpha_blend();
}

void fn_8036B18C(void) {
    s32 temp_r3;

    temp_r3 = lbl_805D7000 + 1;
    lbl_805D7000 = temp_r3;
    if (temp_r3 >= 0x1E) {
        lbl_805D7000 = temp_r3 - 0x1E;
    }
}
void TLobby__sub_8036B1AC(Obj_8036B1AC *payload) {
    s32 i;
    payload->f0 = 0;
    for (i = 0; i < 4; i++) {
        payload->ids[i] = 0xFF;
    }
    for (i = 0; i < 12; i++) {
        payload->cols[i].r = -1;
        payload->cols[i].g = 0;
        payload->cols[i].b = 0;
        payload->cols[i].a = 0;
    }
}

}
