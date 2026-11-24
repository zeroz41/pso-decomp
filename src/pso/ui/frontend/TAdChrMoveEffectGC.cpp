#pragma push

#include "types.h"
#include "pso/render/ColorCopy.h"
#include "pso/render/Draw2D.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"


const f32 chr_move_effect_pos_table[7][2] = {
    { 28.0f, 182.0f }, { 28.0f, 225.0f }, { 28.0f, 268.0f },
    { 434.0f, 182.0f }, { 434.0f, 225.0f }, { 434.0f, 268.0f }, { 434.0f, 311.0f },
};
const u8 lbl_804786E8[2][4] = { { 0x25, 0x76, 0x68, 0xFF }, { 0x25, 0x76, 0x30, 0xFF } };
const f32 lbl_804786F0[2] = { 180.0f, 38.0f };
const char *TAdChrMoveEffectGC__class_name = "TAdChrMoveEffectGC";


struct S_803491F8 { u32 w[8]; };

struct E_8034923C {
    NJS_POINT2 start;
    NJS_POINT2 end;
    u8 col0[4];
    u8 col1[4];
    u8 pad18[8];
    NJS_POINT2 cur;
    u8 curcol[4];
    u8 f2C;
    u8 pad2D[3];
    u32 flags;
    s32 cnt;
};

struct O_8034923C { u8 pad0[0x1C]; s32 n; s32 active; E_8034923C e[16]; };

extern "C" {
void copy_effect_data__18TAdChrMoveEffectGCFPvPv(S_803491F8 *arg0, S_803491F8 *arg1);
#pragma push
#pragma fp_contract on
void TAdChrMoveEffectGC::sub_80348E34() {
    NJS_POINT2 pos[4];
    NJS_POINT2COL desc;
    NJS_COLOR col[4];
    u8 *e;
    s32 i;
    u8 *src;
    if (*(s32 *)&this->m_20 != 0) {
        for (i = 0; i < 16; i++) {
            e = ((u8 *)this) + i * 0x38;
            if (*(u32 *)((s8 *)e + 0x54) & 1) {
                desc.p = pos;
                desc.col = col;
                desc.tex = NULL;
                desc.num = 4;
                copy_vec2(pos, e + 0x44);
                src = e + 0x4C;
                copy4(&desc.col[0].color, src);
                reinterpret_cast<u8 *>(&desc.col[0].color)[3] = *(u8 *)((s8 *)e + 0x50);
                desc.p[1].x = *(f32 *)((s8 *)e + 0x44);
                desc.p[1].y = *(f32 *)((s8 *)e + 0x48) + *(f32 *)((s8 *)e + 0x40);
                copy4(&desc.col[1].color, src);
                reinterpret_cast<u8 *>(&desc.col[1].color)[3] = *(u8 *)((s8 *)e + 0x50);
                desc.p[2].x = *(f32 *)((s8 *)e + 0x44) + *(f32 *)((s8 *)e + 0x3C);
                desc.p[2].y = *(f32 *)((s8 *)e + 0x48) + *(f32 *)((s8 *)e + 0x40);
                copy4(&desc.col[2].color, src);
                reinterpret_cast<u8 *>(&desc.col[2].color)[3] = *(u8 *)((s8 *)e + 0x50);
                desc.p[3].x = *(f32 *)((s8 *)e + 0x44) + *(f32 *)((s8 *)e + 0x3C);
                desc.p[3].y = *(f32 *)((s8 *)e + 0x48);
                copy4(&desc.col[3].color, src);
                reinterpret_cast<u8 *>(&desc.col[3].color)[3] = *(u8 *)((s8 *)e + 0x50);
                draw_polygon_2d(&desc, 4, 7, 1e-05f * (f32)i + (-1.01f));
            }
        }
    }
}
#pragma pop

}

#pragma pop

#pragma push

struct E_803490AC { u32 flags; u8 pad[0x34]; };

struct O_803490AC { u8 pad[0x20]; s32 n; u8 pad2[0x30]; E_803490AC e[16]; };

struct E_80349194 { u8 b[0x38]; };

struct W_80349194 { u8 pad0[0x20]; s32 f20; E_80349194 e[16]; };

struct E_80349038 { u8 pad0[0x1C]; s32 f1C; u8 pad20[4]; u8 v24[8]; u8 pad2C[8]; u8 v34[4]; u8 pad38[0xC]; u8 v44[8]; u8 v4C[4]; s32 f50; s32 f54; s32 f58; };

struct V2_803490D8 { u8 b[8]; };

struct C4_803490D8 { u8 b[4]; };

struct P_803490D8 { V2_803490D8 a; V2_803490D8 b; C4_803490D8 c; C4_803490D8 d; V2_803490D8 e; };

TAdChrMoveEffectGC *lbl_805D6E78;
extern "C" {
void TAdChrMoveEffectGC__sub_80349194(W_80349194 *arg0, void *arg1);


void TAdChrMoveEffectGC::render() { if (TMainTask::get_render_pass() != 1) { set_color_blending_mode(0, 8); set_color_blending_mode(1, 10); sub_80348E34(); set_color_blending_mode(0, 8); set_color_blending_mode(1, 6); } }

void TAdChrMoveEffectGC::reset_effect_entries() {
    E_80349038 *e;
    s32 i;
    ((E_80349038 *)this)->f1C = 0;
    for (i = 0; i < 16; i++) {
        e = (E_80349038 *)((u8 *)this + i * 0x38);
        copy_vec2((e->v44), e->v24);
        copy4(e->v4C, e->v34);
        *(u8 *)&e->f50 = e->v34[3];
        e->f54 = 0;
        e->f58 = 0;
    }
}

void TAdChrMoveEffectGC::clear_entries() {
    O_803490AC *self = (O_803490AC *)this;
    s32 i;
    this->m_20 = 0;
    for (i = 0; i < 16; i++) {
        self->e[i].flags &= ~1;
    }
}

struct W_80349194;
void TAdChrMoveEffectGC::setup_move_effect_params(s32 arg1, s32 arg2) {
    P_803490D8 p;
    copy_vec2((&p.a), (void *)&chr_move_effect_pos_table[arg1]);
    copy_vec2((&p.b), (void *)&chr_move_effect_pos_table[arg2]);
    copy4(&p.c, (void *)(arg1 < 3 ? &lbl_804786E8[0] : &lbl_804786E8[1]));
    copy4(&p.d, (void *)(arg2 < 3 ? &lbl_804786E8[0] : &lbl_804786E8[1]));
    copy_vec2((&p.e), (void *)lbl_804786F0);
    TAdChrMoveEffectGC__sub_80349194((W_80349194 *)this, &p);
}

void TAdChrMoveEffectGC__sub_80349194(W_80349194 *arg0, void *arg1) {
    s32 i;
    for (i = 0; i < 16; i++) {
        copy_effect_data__18TAdChrMoveEffectGCFPvPv((S_803491F8 *)(&arg0->e[i]), (S_803491F8 *)(arg1));
    }
    ((TAdChrMoveEffectGC *)arg0)->reset_effect_entries();
    arg0->f20 = 1;
}

#pragma push
#pragma optimization_level 1
void copy_effect_data__18TAdChrMoveEffectGCFPvPv(S_803491F8 *arg0, S_803491F8 *arg1) {
    u32 b, a;
    a = arg1->w[0]; b = arg1->w[1]; arg0->w[0] = a; arg0->w[1] = b;
    a = arg1->w[2]; b = arg1->w[3]; arg0->w[2] = a; arg0->w[3] = b;
    arg0->w[4] = arg1->w[4];
    arg0->w[5] = arg1->w[5];
    a = arg1->w[6]; b = arg1->w[7]; arg0->w[6] = a; arg0->w[7] = b;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TAdChrMoveEffectGC::run_task() {
    O_8034923C *self = (O_8034923C *)this;
    s32 i;
    f32 dx;
    f32 dy;
    f32 vx;
    f32 vy;
    s32 t;
    f32 c0;
    f32 c1;
    f32 c2;
    f32 c3;
    if (self->active == 0) {
        return;
    }
    if (++self->n < 0x11) {
        self->e[self->n].flags |= 1;
    } else if (self->n > 0x28) {
        reset_effect_entries();
    }
    for (i = 0; i < 16; i++) {
        if (self->e[i].flags & 1) {
            if (self->e[i].cnt < 0x1E) {
                dx = (self->e[i].end.x - self->e[i].start.x) / 14.4f;
                dy = (self->e[i].end.y - self->e[i].start.y) / 14.4f;
                vx = -dx / 30.0f * (f32)self->e[i].cnt + dx;
                vy = -dy / 30.0f * (f32)self->e[i].cnt + dy;
                if (self->e[i].cnt == 0) {
                    copy_vec2((&self->e[i].cur), &self->e[i].start);
                    copy4(self->e[i].curcol, self->e[i].col0);
                } else {
                    self->e[i].cur.x += vx;
                    self->e[i].cur.y += vy;
                    c3 = (f32)(self->e[i].col1[3] - self->e[i].col0[3]) / 30.0f;
                    c0 = (f32)(self->e[i].col1[0] - self->e[i].col0[0]) / 30.0f;
                    c1 = (f32)(self->e[i].col1[1] - self->e[i].col0[1]) / 30.0f;
                    c2 = (f32)(self->e[i].col1[2] - self->e[i].col0[2]) / 30.0f;
                    self->e[i].curcol[3] += (s32)(0.5f + c3);
                    self->e[i].curcol[0] += (s32)(0.5f + c0);
                    self->e[i].curcol[1] += (s32)(0.5f + c1);
                    self->e[i].curcol[2] += (s32)(0.5f + c2);
                }
                self->e[i].f2C = self->e[i].curcol[3] / 5;
                self->e[i].cnt++;
            } else {
                copy_vec2((&self->e[i].cur), &self->e[i].end);
                copy4(self->e[i].curcol, self->e[i].col1);
                t = self->e[i].col1[3] / 10;
                self->e[i].f2C = (self->e[i].f2C > t) ? self->e[i].f2C - t : 0;
            }
        }
    }
}
#pragma pop

}
TAdChrMoveEffectGC::~TAdChrMoveEffectGC() {
    if (lbl_805D6E78 != NULL) {
        lbl_805D6E78 = NULL;
    }
}


TAdChrMoveEffectGC::TAdChrMoveEffectGC(TObject *parent) : TObject(parent) {
    m_name = TAdChrMoveEffectGC__class_name;
    m_20 = 0;
}


#pragma pop
