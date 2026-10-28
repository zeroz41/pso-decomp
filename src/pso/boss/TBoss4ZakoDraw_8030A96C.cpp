#include "pso/system/NinjaTypes.h"
void set_constant_material(const NJS_ARGB *color);
#include "types.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/system/vector.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TBoss4Zako.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/TBoss4Uro.h"
#include "pso/object/TObjFish.h"

struct RecoveredGlobal_8030ABF4_TCameraCtrl__data_804FF634 {
    s32 value;
    u8 remaining[0x44];
};

struct RecoveredGlobal_8030ABF4_lbl_80541E58 {
    s32 value;
    u8 remaining[0xF04];
};

struct E_8030AD08 { s32 a; u8 pad[0x780]; };

struct Ent_8030AB48 { u8 pad[0xc]; s32 f0c; s32 f10; };

struct Tbl_8030AB48 { s32 count; Ent_8030AB48 ents[96]; u8 pad[0x784 - 4 - 96 * 0x14]; };

struct Ent_8030AC7C { u8 pad[0xc]; s32 f0c; s32 f10; };

struct Tbl_8030AC7C { s32 count; Ent_8030AC7C ents[96]; u8 pad[0x784 - 4 - 96 * 0x14]; };

extern "C" {
s32 is_split_screen();
u8 *get_bml_model(s32, s32);
s32 set_viewport_scissor__11TCameraCtrlFiPv(int, int);
void TObjPlayer__sub_8030A9B0();
extern RecoveredGlobal_8030ABF4_TCameraCtrl__data_804FF634 TCameraCtrl__data_804FF634;
extern RecoveredGlobal_8030ABF4_lbl_80541E58 boss4_zako_draw_buffers;
extern s32 TBoss4ZakoDraw__draw_buffer_index;
extern s32 TBoss4ZakoDraw__rotation_phase;
void TCameraCtrl__sub_8030ABF4(void);
extern RecoveredGlobal_8030ABF4_lbl_80541E58 boss4_zako_draw_buffers;
extern s32 TBoss4ZakoDraw__draw_buffer_index;
u8 *get_bml_model(s32, s32);
void TObjPlayer__sub_80052390(f32);
void rotate_matrix_y(int, int);
void rotate_matrix_x(int, int);
void push_matrix(void);
void pop_matrix(void);
void post_translate_matrix(void *);
void draw_chunk_object(int);
extern RecoveredGlobal_8030ABF4_lbl_80541E58 boss4_zako_draw_buffers;
extern s32 falz_zako_texture_list;
extern s32 TBoss4ZakoDraw__draw_buffer_index;
extern const f32 lbl_805DF148;
extern RecoveredGlobal_8030ABF4_lbl_80541E58 boss4_zako_draw_buffers;
extern s32 TBoss4ZakoDraw__draw_buffer_index;
struct Raw_8030A9B0 { u8 b[12]; };
struct Ent_8030A9B0 { f32 x; f32 y; f32 z; s32 f0c; s32 f10; };
struct Tbl_8030A9B0 { s32 count; Ent_8030A9B0 ents[1]; };
struct Col_8030A9B0 { f32 r, g, b, a; };

void set_chunk_material_override_pair(int, int);
f32 xyz_distance(void *, void *);
}
void draw_chunk_model(void *arg0);
extern u8 *camera_ctrl_instance;
extern u32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 falz_zako_chunk_model;
extern s32 TBoss4ZakoDraw__draw_buffer_index;
extern s32 TBoss4ZakoDraw__rotation_phase;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern u32 model_render_flags;
extern u32 lbl_805DF138;
extern const f32 lbl_805DF13C;
extern const f32 lbl_805DF140;
extern const f32 lbl_805DF144;
extern const f32 lbl_805DF148;
extern const f32 lbl_805DF14C;

extern "C" {

void *__ct__14TBoss4ZakoDrawFv(void *arg0);
void __ct__7TObjectFP7TObject(void *);

extern s32 __vt__14TBoss4ZakoDraw[];
extern void *TBoss4ZakoDraw__class_name;

void *__ct__14TBoss4ZakoDrawFv(void *object) {
    __ct__7TObjectFP7TObject(object);
    *(s32 **)((s8 *)object + 0x18) = __vt__14TBoss4ZakoDraw;
    *(void **)((s8 *)object + 0x0) = TBoss4ZakoDraw__class_name;
    return object;
}
typedef char RecoveredGlobal_8030ABF4_TCameraCtrl__data_804FF634_size[sizeof(RecoveredGlobal_8030ABF4_TCameraCtrl__data_804FF634) == 0x48 ? 1 : -1];
typedef char RecoveredGlobal_8030ABF4_lbl_80541E58_size[sizeof(RecoveredGlobal_8030ABF4_lbl_80541E58) == 0xF08 ? 1 : -1];

#pragma push
#pragma fp_contract on
#pragma inline_depth(1)
#pragma dont_inline off
void TObjPlayer__sub_8030A9B0() {
    Raw_8030A9B0 pos;
    Raw_8030A9B0 v;
    Col_8030A9B0 col;
    Tbl_8030A9B0 *tbl;
    Ent_8030A9B0 *e;
    s32 rot;
    s32 i;
    f32 d;
    f32 t;
    f32 k;
    u32 old;

    old = model_render_flags;
    model_render_flags = old & ~0x10;
    saved_model_render_flags = old;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= lbl_805DF138;
    ((void (*)(int, int, u32, s32, s32, u32))set_chunk_material_override_pair)(0xFF00, 0x900, old & ~0x10, chunk_polygon_flags_or_mask, chunk_polygon_flags_and_mask, old);
    tbl = (Tbl_8030A9B0 *)((u8 *)&boss4_zako_draw_buffers + TBoss4ZakoDraw__draw_buffer_index * 0x784);
    e = tbl->ents;
    rot = (TBoss4ZakoDraw__rotation_phase << 16) / 16;
    VecCopy((Vec *)&pos, (const Vec *)(camera_ctrl_instance + 0x178));
    i = 0;
    *(f32 *)((s8 *)&pos + 4) = lbl_805DF13C;
    for (; i < tbl->count; i++, e++) {
        if (e->f0c != 0 || e->y < lbl_805DF140) {
            continue;
        }
        d = xyz_distance(e, &pos);
        if (d >= lbl_805DF144) {
            continue;
        }
        t = d / lbl_805DF144;
        k = lbl_805DF148 - t * (t * t);
        push_matrix();
        v = *(Raw_8030A9B0 *)e;
        *(f32 *)((s8 *)&v + 4) = lbl_805DF13C;
        post_translate_matrix(&v);
        rotate_matrix_y(0, e->f10 + rot);
        col.a = lbl_805DF14C;
        col.b = lbl_805DF14C;
        col.r = lbl_805DF13C * k + lbl_805DF14C;
        col.g = lbl_805DF14C;
        set_constant_material((const NJS_ARGB *)(((f32 *)&col)));
        draw_chunk_model((void *)falz_zako_chunk_model);
        pop_matrix();
    }
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    model_render_flags = saved_model_render_flags;
}
void TObjPlayer__sub_8030A9B0();
#pragma pop

void TObjPlayer::draw_area_chunk_objects() {
    Tbl_8030AB48 *t = &((Tbl_8030AB48 *)&boss4_zako_draw_buffers)[TBoss4ZakoDraw__draw_buffer_index];
    Ent_8030AB48 *p = t->ents;
    s32 r31;
    s32 i;
    r31 = ((s32)get_bml_model((s32)(TBoss4Uro::get_instance_count()), 8));
    TObjPlayer__sub_80052390(lbl_805DF148);
    TObjFish::set_global_param(falz_zako_texture_list);
    for (i = 0; i < t->count; i++, p++) {
        push_matrix();
        post_translate_matrix(p);
        rotate_matrix_y(0, p->f10);
        rotate_matrix_x(0, p->f0c);
        draw_chunk_object(r31);
        pop_matrix();
    }
    TObjPlayer::sync_player_globals();
}

void TCameraCtrl__sub_8030ABF4(void) {
    s32 *var_r3;
    u8 *var_r31;
    u8 *var_r4;
    var_r3 = (s32 *)&boss4_zako_draw_buffers.value;
    var_r3 = (s32 *)&boss4_zako_draw_buffers.value;
    if ((s32) *(s32 *)((s8 *)((u8 *)&boss4_zako_draw_buffers.value + (TBoss4ZakoDraw__draw_buffer_index * 0x784)) + 0) != 0) {
        var_r3 = (s32 *)&TCameraCtrl__data_804FF634.value;
        var_r3 = (s32 *)&TCameraCtrl__data_804FF634.value;
        var_r31 = (u8 *)&TCameraCtrl__data_804FF634.value + 0x30;
        if (is_split_screen() == 0) {
            var_r4 = var_r31;
            var_r3 = (s32 *)((u8 *)((s32 *)2));
            set_viewport_scissor__11TCameraCtrlFiPv(2, (int)var_r4);
        }
        var_r4 = (u8 *)((void *)8);
        var_r3 = (s32 *)(*(s32 **)((s8 *)(get_bml_model(TBoss4Uro::get_instance_count(), 8)) + 0x2C));
        *(s32 *)((s8 *)var_r3 + 0x18) = (s32) (TBoss4ZakoDraw__rotation_phase << 0xC);
        TObjPlayer::draw_area_chunk_objects();
        TObjPlayer__sub_8030A9B0();
    }
}

s32 TBoss4Zako::queue_entry(void *v, s32 a, s32 b) {
    Tbl_8030AC7C *t = &((Tbl_8030AC7C *)&boss4_zako_draw_buffers)[TBoss4ZakoDraw__draw_buffer_index ^ 1];
    s32 n = t->count;
    Ent_8030AC7C *e = &t->ents[n];
    if (n >= 0x60) {
        return 0;
    }
    VecCopy((Vec *)e, (const Vec *)v);
    e->f0c = a;
    e->f10 = b;
    t->count += 1;
    return 1;
}

void TBoss4DarkFalz::clear_uro_link_state() {
    s32 i;
    for (i = 0; i < 2; i++) {
        ((E_8030AD08 *)&boss4_zako_draw_buffers)[i].a = 0;
    }
    TBoss4ZakoDraw__draw_buffer_index = 0;
}

}
