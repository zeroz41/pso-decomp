#pragma push

#include "types.h"
#include "pso/TMainTask.h"
#include "pso/ui/TAdChrMoveEffectGC.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/TObjCMHairMenu.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"


struct S_803491F8 { u32 w[8]; };

struct V2_8034923C { f32 x, y; };

struct E_8034923C {
    V2_8034923C start;
    V2_8034923C end;
    u8 col0[4];
    u8 col1[4];
    u8 pad18[8];
    V2_8034923C cur;
    u8 curcol[4];
    u8 f2C;
    u8 pad2D[3];
    u32 flags;
    s32 cnt;
};

struct O_8034923C { u8 pad0[0x1C]; s32 n; s32 active; E_8034923C e[16]; };

extern "C" {
extern const f32 lbl_805DFCE8;
extern const f32 lbl_805DFCEC;
void copy_effect_data__18TAdChrMoveEffectGCFPvPv(S_803491F8 *arg0, S_803491F8 *arg1);
#pragma push
#pragma fp_contract on
typedef struct {
    f32 *pos;
    u8 *col;
    s32 a;
    s32 n;
} Desc_80348E34;
void TAdChrMoveEffectGC::sub_80348E34() {
    f32 pos[8];
    Desc_80348E34 desc;
    u8 col[16];
    u8 *e;
    s32 i;
    u8 *src;
    if (*(s32 *)&this->m_20 != 0) {
        for (i = 0; i < 16; i++) {
            e = ((u8 *)this) + i * 0x38;
            if (*(u32 *)((s8 *)e + 0x54) & 1) {
                desc.pos = pos;
                desc.col = col;
                desc.a = 0;
                desc.n = 4;
                ((TWindowSubSymbolChatPartsSet *)pos)->copy_vec2(e + 0x44);
                src = e + 0x4C;
                ((TAdChrMoveEffectGC *)(desc.col))->copy4(src);
                desc.col[3] = *(u8 *)((s8 *)e + 0x50);
                desc.pos[2] = *(f32 *)((s8 *)e + 0x44);
                desc.pos[3] = *(f32 *)((s8 *)e + 0x48) + *(f32 *)((s8 *)e + 0x40);
                ((TAdChrMoveEffectGC *)(desc.col + 4))->copy4(src);
                desc.col[7] = *(u8 *)((s8 *)e + 0x50);
                desc.pos[4] = *(f32 *)((s8 *)e + 0x44) + *(f32 *)((s8 *)e + 0x3C);
                desc.pos[5] = *(f32 *)((s8 *)e + 0x48) + *(f32 *)((s8 *)e + 0x40);
                ((TAdChrMoveEffectGC *)(desc.col + 8))->copy4(src);
                desc.col[11] = *(u8 *)((s8 *)e + 0x50);
                desc.pos[6] = *(f32 *)((s8 *)e + 0x44) + *(f32 *)((s8 *)e + 0x3C);
                desc.pos[7] = *(f32 *)((s8 *)e + 0x48);
                ((TAdChrMoveEffectGC *)(desc.col + 12))->copy4(src);
                desc.col[15] = *(u8 *)((s8 *)e + 0x50);
                ((TObjCMHairMenu *)(&desc))->draw_tri_fan_2d(4, 7, lbl_805DFCEC * (f32)i + lbl_805DFCE8);
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

extern "C" {
void TAdChrMoveEffectGC__sub_80349194(W_80349194 *arg0, void *arg1);
extern V2_803490D8 chr_move_effect_pos_table[];
extern C4_803490D8 lbl_804786E8[];
extern u8 lbl_804786F0[];
void __ct__7TObjectFP7TObject(void *);


void TAdChrMoveEffectGC::render() { if (TMainTask::get_render_pass() != 1) { set_color_blending_mode(0, 8); set_color_blending_mode(1, 10); sub_80348E34(); set_color_blending_mode(0, 8); set_color_blending_mode(1, 6); } }

extern s32 __vt__18TAdChrMoveEffectGC[];
extern u32 lbl_805D6E78;

void TAdChrMoveEffectGC::reset_effect_entries() {
    E_80349038 *e;
    s32 i;
    ((E_80349038 *)this)->f1C = 0;
    for (i = 0; i < 16; i++) {
        e = (E_80349038 *)((u8 *)this + i * 0x38);
        ((TWindowSubSymbolChatPartsSet *)(e->v44))->copy_vec2(e->v24);
        ((TAdChrMoveEffectGC *)(e->v4C))->copy4(e->v34);
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
    ((TWindowSubSymbolChatPartsSet *)(&p.a))->copy_vec2(&chr_move_effect_pos_table[arg1]);
    ((TWindowSubSymbolChatPartsSet *)(&p.b))->copy_vec2(&chr_move_effect_pos_table[arg2]);
    ((TAdChrMoveEffectGC *)(&p.c))->copy4(arg1 < 3 ? &lbl_804786E8[0] : &lbl_804786E8[1]);
    ((TAdChrMoveEffectGC *)(&p.d))->copy4(arg2 < 3 ? &lbl_804786E8[0] : &lbl_804786E8[1]);
    ((TWindowSubSymbolChatPartsSet *)(&p.e))->copy_vec2(lbl_804786F0);
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
                    ((TWindowSubSymbolChatPartsSet *)(&self->e[i].cur))->copy_vec2(&self->e[i].start);
                    ((TAdChrMoveEffectGC *)(self->e[i].curcol))->copy4(self->e[i].col0);
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
                ((TWindowSubSymbolChatPartsSet *)(&self->e[i].cur))->copy_vec2(&self->e[i].end);
                ((TAdChrMoveEffectGC *)(self->e[i].curcol))->copy4(self->e[i].col1);
                t = self->e[i].col1[3] / 10;
                self->e[i].f2C = (self->e[i].f2C > t) ? self->e[i].f2C - t : 0;
            }
        }
    }
}
#pragma pop

}
TAdChrMoveEffectGC::~TAdChrMoveEffectGC() {
    if ((u32) lbl_805D6E78 != 0U) {
        lbl_805D6E78 = 0U;
    }
}


extern void *lbl_805D42F0;

void *TAdChrMoveEffectGC__ct(void *ad_chr_move_effect_gc) {
    __ct__7TObjectFP7TObject(ad_chr_move_effect_gc);
    *(s32 **)((s8 *)ad_chr_move_effect_gc + 0x18) = __vt__18TAdChrMoveEffectGC;
    *(void * *)&((TAdChrMoveEffectGC *)ad_chr_move_effect_gc)->m_name = lbl_805D42F0;
    ((TAdChrMoveEffectGC *)ad_chr_move_effect_gc)->m_20 = 0;
    return ad_chr_move_effect_gc;
}


#pragma pop
