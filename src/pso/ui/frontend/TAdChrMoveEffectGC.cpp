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
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/system/task/TObject.h"

const f32 chr_move_effect_pos_table[7][2] = {
    { 28.0f, 182.0f }, { 28.0f, 225.0f }, { 28.0f, 268.0f },
    { 434.0f, 182.0f }, { 434.0f, 225.0f }, { 434.0f, 268.0f }, { 434.0f, 311.0f },
};
const u8 chr_move_effect_color_table[2][4] = { { 0x25, 0x76, 0x68, 0xFF }, { 0x25, 0x76, 0x30, 0xFF } };
const f32 chr_move_effect_size[2] = { 180.0f, 38.0f };
const char *TAdChrMoveEffectGC::class_name = "TAdChrMoveEffectGC";

struct ChrMoveEffectParamsWords { u32 w[8]; };

extern "C" {
void copy_effect_data__18TAdChrMoveEffectGCFPvPv(ChrMoveEffectParamsWords *dest, ChrMoveEffectParamsWords *source);
}

#pragma push
#pragma fp_contract on
void TAdChrMoveEffectGC::draw_entries() {
    NJS_POINT2 pos[4];
    NJS_POINT2COL desc;
    NJS_COLOR col[4];
    ChrMoveEffectSlot *e;
    s32 i;
    u8 *src;
    if (this->active != 0) {
        for (i = 0; i < 16; i++) {
            e = (ChrMoveEffectSlot *)((u8 *)this + i * 0x38);
            if (e->entry.flags & 1) {
                desc.p = pos;
                desc.col = col;
                desc.tex = NULL;
                desc.num = 4;
                copy_vec2(pos, &e->entry.current);
                src = e->entry.current_color;
                copy4(&desc.col[0].color, src);
                reinterpret_cast<u8 *>(&desc.col[0].color)[3] = e->entry.alpha;
                desc.p[1].x = e->entry.current.x;
                desc.p[1].y = e->entry.current.y + e->entry.size.y;
                copy4(&desc.col[1].color, src);
                reinterpret_cast<u8 *>(&desc.col[1].color)[3] = e->entry.alpha;
                desc.p[2].x = e->entry.current.x + e->entry.size.x;
                desc.p[2].y = e->entry.current.y + e->entry.size.y;
                copy4(&desc.col[2].color, src);
                reinterpret_cast<u8 *>(&desc.col[2].color)[3] = e->entry.alpha;
                desc.p[3].x = e->entry.current.x + e->entry.size.x;
                desc.p[3].y = e->entry.current.y;
                copy4(&desc.col[3].color, src);
                reinterpret_cast<u8 *>(&desc.col[3].color)[3] = e->entry.alpha;
                draw_polygon_2d(&desc, 4, 7, 1e-05f * (f32)i + (-1.01f));
            }
        }
    }
}
#pragma pop

#pragma pop

#pragma push

TAdChrMoveEffectGC *chr_move_effect_instance;

void TAdChrMoveEffectGC::render() { if (TMainTask::get_render_pass() != 1) { set_color_blending_mode(0, 8); set_color_blending_mode(1, 10); draw_entries(); set_color_blending_mode(0, 8); set_color_blending_mode(1, 6); } }

void TAdChrMoveEffectGC::reset_effect_entries() {
    ChrMoveEffectSlot *e;
    s32 i;
    this->step = 0;
    for (i = 0; i < 16; i++) {
        e = (ChrMoveEffectSlot *)((u8 *)this + i * 0x38);
        copy_vec2(&e->entry.current, &e->entry.start);
        copy4(e->entry.current_color, e->entry.start_color);
        e->entry.alpha = e->entry.start_color[3];
        e->entry.flags = 0;
        e->entry.frame = 0;
    }
}

void TAdChrMoveEffectGC::clear_entries() {
    s32 i;
    this->active = 0;
    for (i = 0; i < 16; i++) {
        this->entries[i].flags &= ~1;
    }
}

void TAdChrMoveEffectGC::setup_move_effect_params(s32 from_index, s32 to_index) {
    ChrMoveEffectParams p;
    copy_vec2(&p.start, (void *)&chr_move_effect_pos_table[from_index]);
    copy_vec2(&p.end, (void *)&chr_move_effect_pos_table[to_index]);
    copy4(p.start_color, (from_index < 3 ? &chr_move_effect_color_table[0] : &chr_move_effect_color_table[1]));
    copy4(p.end_color, (to_index < 3 ? &chr_move_effect_color_table[0] : &chr_move_effect_color_table[1]));
    copy_vec2(&p.size, (void *)chr_move_effect_size);
    start_move_effect(&p);
}

void TAdChrMoveEffectGC::start_move_effect(ChrMoveEffectParams *params) {
    s32 i;
    for (i = 0; i < 16; i++) {
        copy_effect_data__18TAdChrMoveEffectGCFPvPv((ChrMoveEffectParamsWords *)(&entries[i]), (ChrMoveEffectParamsWords *)(params));
    }
    reset_effect_entries();
    active = 1;
}

#pragma push
#pragma optimization_level 1
void copy_effect_data__18TAdChrMoveEffectGCFPvPv(ChrMoveEffectParamsWords *dest, ChrMoveEffectParamsWords *source) {
    u32 b, a;
    a = source->w[0]; b = source->w[1]; dest->w[0] = a; dest->w[1] = b;
    a = source->w[2]; b = source->w[3]; dest->w[2] = a; dest->w[3] = b;
    dest->w[4] = source->w[4];
    dest->w[5] = source->w[5];
    a = source->w[6]; b = source->w[7]; dest->w[6] = a; dest->w[7] = b;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TAdChrMoveEffectGC::run_task() {
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
    if (this->active == 0) {
        return;
    }
    if (++this->step < 0x11) {
        this->entries[this->step].flags |= 1;
    } else if (this->step > 0x28) {
        reset_effect_entries();
    }
    for (i = 0; i < 16; i++) {
        if (this->entries[i].flags & 1) {
            if (this->entries[i].frame < 0x1E) {
                dx = (this->entries[i].end.x - this->entries[i].start.x) / 14.4f;
                dy = (this->entries[i].end.y - this->entries[i].start.y) / 14.4f;
                vx = -dx / 30.0f * (f32)this->entries[i].frame + dx;
                vy = -dy / 30.0f * (f32)this->entries[i].frame + dy;
                if (this->entries[i].frame == 0) {
                    copy_vec2((&this->entries[i].current), &this->entries[i].start);
                    copy4(this->entries[i].current_color, this->entries[i].start_color);
                } else {
                    this->entries[i].current.x += vx;
                    this->entries[i].current.y += vy;
                    c3 = (f32)(this->entries[i].end_color[3] - this->entries[i].start_color[3]) / 30.0f;
                    c0 = (f32)(this->entries[i].end_color[0] - this->entries[i].start_color[0]) / 30.0f;
                    c1 = (f32)(this->entries[i].end_color[1] - this->entries[i].start_color[1]) / 30.0f;
                    c2 = (f32)(this->entries[i].end_color[2] - this->entries[i].start_color[2]) / 30.0f;
                    this->entries[i].current_color[3] += (s32)(0.5f + c3);
                    this->entries[i].current_color[0] += (s32)(0.5f + c0);
                    this->entries[i].current_color[1] += (s32)(0.5f + c1);
                    this->entries[i].current_color[2] += (s32)(0.5f + c2);
                }
                this->entries[i].alpha = this->entries[i].current_color[3] / 5;
                this->entries[i].frame++;
            } else {
                copy_vec2((&this->entries[i].current), &this->entries[i].end);
                copy4(this->entries[i].current_color, this->entries[i].end_color);
                t = this->entries[i].end_color[3] / 10;
                this->entries[i].alpha = (this->entries[i].alpha > t) ? this->entries[i].alpha - t : 0;
            }
        }
    }
}
#pragma pop

TAdChrMoveEffectGC::~TAdChrMoveEffectGC() {
    if (chr_move_effect_instance != NULL) {
        chr_move_effect_instance = NULL;
    }
}

TAdChrMoveEffectGC::TAdChrMoveEffectGC(TObject *parent) : TObject(parent) {
    m_name = TAdChrMoveEffectGC::class_name;
    active = 0;
}

#pragma pop

TAdChrMoveEffectGC *TAdMultiPlyChrSelectGC::get_move_effect(TObject *ad_chr_move_effect_gc) {
    if (chr_move_effect_instance == NULL) {
        chr_move_effect_instance = new TAdChrMoveEffectGC(ad_chr_move_effect_gc);
    }
    return chr_move_effect_instance;
}
