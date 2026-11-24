#include "pso/boss/darkfalz/TBoss4ZakoTexture.h"
#include "pso/system/BmlAccessors.h"
#include "pso/system/BmlResource.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/CameraViewParams.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/system/vector.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Zako.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/darkfalz/TBoss4ZakoDraw.h"
#include "pso/boss/darkfalz/TBoss4ZakoDrawBuffer.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/render/Draw2D.h"

extern "C" {
void post_translate_matrix(void *);
f32 xyz_distance(void *, void *);
void TObjPlayer__sub_8030A9B0();
}

void draw_chunk_model(void *);
extern u32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
NJS_TEXLIST *falz_zako_texture_list;
void *falz_zako_chunk_model;
s32 TBoss4ZakoDraw__draw_buffer_index;
s32 TBoss4ZakoDraw__rotation_phase;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern u32 model_render_flags;



void TBoss4ZakoDraw::render() { TObjPlayer::toggle_particle_effect(); TBoss4ZakoDraw::draw_queued(); TParticleCtrl::end_effect_render(); }
void TBoss4ZakoDraw::run_task() {
    s32 old;
    if (dark_falz_controller_instance == NULL) {
        queue_destruction();
        return;
    }
    old = TBoss4ZakoDraw__draw_buffer_index;
    boss4_zako_draw_buffers[old].count = 0;
    TBoss4ZakoDraw__draw_buffer_index = old ^ 1;
    if (++TBoss4ZakoDraw__rotation_phase >= 4) {
        TBoss4ZakoDraw__rotation_phase = 0;
    }
}
TBoss4ZakoDraw::~TBoss4ZakoDraw() {}

#pragma push
#pragma readonly_strings on
extern "C" const char *TBoss4ZakoDraw__class_name = "TBoss4ZakoDraw";
#pragma pop

TBoss4ZakoDraw::TBoss4ZakoDraw(TObject *parent) : TObject(parent) {
    m_name = TBoss4ZakoDraw__class_name;
}

extern "C" {
#pragma push
#pragma fp_contract on
void TObjPlayer__sub_8030A9B0() {
    Vec pos;
    Boss4ZakoDrawBuffer *tbl;
    Boss4ZakoDrawEntry *e;
    s32 rot;
    s32 i;
    f32 d;
    f32 t;
    f32 k;
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags &= ~0x10U;
    model_render_flags |= zako_model_render_flags;
    set_chunk_material_override_pair(0xFF00, 0x900);
    tbl = &boss4_zako_draw_buffers[TBoss4ZakoDraw__draw_buffer_index];
    e = tbl->entries;
    rot = (TBoss4ZakoDraw__rotation_phase << 16) / 16;
    // The shared camera slot retains its legacy byte-pointer declaration.
    VecCopy(&pos, &camera_ctrl_instance->pos);
    i = 0;
    pos.y = zako_draw_height;
    for (; i < tbl->count; i++, e++) {
        if (e->rotation_x != 0 || e->position.y < zako_min_height) {
            continue;
        }
        d = xyz_distance(&e->position, &pos);
        if (d >= zako_fade_distance) {
            continue;
        }
        t = d / zako_fade_distance;
        k = zako_fade_full - t * (t * t);
        push_matrix();
        // Copy initialization retains the native word copy without an assignment helper.
        Vec v = e->position;
        v.y = zako_draw_height;
        post_translate_matrix(&v.x);
        rotate_matrix_y(0, e->rotation_y + rot);
        NJS_ARGB col;
        col.b = zako_fade_color;
        col.g = zako_fade_color;
        col.a = zako_draw_height * k + zako_fade_color;
        col.r = zako_fade_color;
        set_constant_material(&col);
        draw_chunk_model(falz_zako_chunk_model);
        pop_matrix();
    }
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    model_render_flags = saved_model_render_flags;
}
#pragma pop
}

void TObjPlayer::draw_area_chunk_objects() {
    NJS_OBJECT *model;
    Boss4ZakoDrawBuffer *t = &boss4_zako_draw_buffers[TBoss4ZakoDraw__draw_buffer_index];
    Boss4ZakoDrawEntry *p = t->entries;
    s32 i;
    model = get_bml_model(TBoss4Uro::get_instance_count(), 8);
    TObjPlayer::begin_alpha_blend(zako_fade_full);
    TObjFish::set_global_param(falz_zako_texture_list);
    for (i = 0; i < t->count; i++, p++) {
        push_matrix();
        post_translate_matrix(&p->position.x);
        rotate_matrix_y(0, p->rotation_y);
        rotate_matrix_x(0, p->rotation_x);
        draw_chunk_object(model);
        pop_matrix();
    }
    TObjPlayer::sync_player_globals();
}

// File-scope constants of the zako draw: .sdata2 objects in this order, defined after their
// users: defined before TObjPlayer__sub_8030A9B0, 1.0f is scheduled after push_matrix;
// defined before draw_area_chunk_objects, its 1.0f becomes a new pooled literal.
// Names inferred from the uses.
__declspec(section ".sdata2") const u32 zako_model_render_flags = 0x82C;
__declspec(section ".sdata2") const f32 zako_draw_height = 0.5f;
__declspec(section ".sdata2") const f32 zako_min_height = -9.5f;
__declspec(section ".sdata2") const f32 zako_fade_distance = 75.0f;
__declspec(section ".sdata2") const f32 zako_fade_full = 1.0f;
__declspec(section ".sdata2") const f32 zako_fade_color = -1.0f;

void TBoss4ZakoDraw::draw_queued() {
    if (boss4_zako_draw_buffers[TBoss4ZakoDraw__draw_buffer_index].count != 0) {
        const TileRect *rect = &TCameraCtrl::view_params.scissor;
        if (is_split_screen() == 0) {
            set_viewport_scissor(2, rect);
        }
        NJS_OBJECT *model = get_bml_model(TBoss4Uro::get_instance_count(), 8);
        model->child->ang[1] = TBoss4ZakoDraw__rotation_phase << 12;
        TObjPlayer::draw_area_chunk_objects();
        TObjPlayer__sub_8030A9B0();
    }
}

s32 TBoss4Zako::queue_entry(void *v, s32 a, s32 b) {
    Boss4ZakoDrawBuffer *t = &boss4_zako_draw_buffers[TBoss4ZakoDraw__draw_buffer_index ^ 1];
    s32 n = t->count;
    Boss4ZakoDrawEntry *e = &t->entries[n];
    if (n >= 0x60) {
        return 0;
    }
    VecCopy(&e->position, (const Vec *)v);
    e->rotation_x = a;
    e->rotation_y = b;
    t->count += 1;
    return 1;
}

void TBoss4DarkFalz::clear_uro_link_state() {
    s32 i;
    for (i = 0; i < 2; i++) {
        boss4_zako_draw_buffers[i].count = 0;
    }
    TBoss4ZakoDraw__draw_buffer_index = 0;
}


Boss4ZakoDrawBuffer boss4_zako_draw_buffers[2];

void TBoss4DarkFalz::release_uro_link() { clear_uro_link_state(); }

void TBoss4DarkFalz::init_uro_link() {
    falz_zako_texture_list = get_bml_texlist(TBoss4Uro::get_instance_count(), 8);
    NJS_OBJECT *child = get_bml_model(TBoss4Uro::get_instance_count(), 8)->child;
    child->evalflags &= ~NJD_EVAL_UNIT_ANG;
    if (child->model != NULL) {
        falz_zako_chunk_model = child->model;
        TBoss4ZakoDraw__rotation_phase = 0;
        TBoss4DarkFalz::clear_uro_link_state();
    }
}
