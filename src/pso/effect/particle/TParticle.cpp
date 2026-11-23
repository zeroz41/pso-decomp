#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/effect/sprite/TQuadSprite.h"
#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"
#include "pso/render/ChunkMaterialState.h"
#include "types.h"
#include "pso/render/GinjaView.h"
#include "pso/effect/TEffect.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticle.h"
#include "pso/effect/particle/TParticleBallistic.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/particle/ParticleRadial.h"
#include "pso/system/THeap.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"

#include "pso/effect/TEffIndirectSampler.h"
#include "pso/effect/particle/ParticleStrip.h"
#include "pso/player/TObjPlayer_80083594.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_803DC86C.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D853C.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/effect/sprite/TQuadSpriteSclColRot.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803DA798.h"

THeap *TParticleCtrl::heap;

TParticle *TParticleCtrl::generate_child_default(void *param, void *pos, void *parent) {
    Vec dir = {0.0f, 0.0f, 0.0f};
    return alloc_child_particle(param, pos, &dir, parent);
}

#pragma readonly_strings on
ParticleGenerator particle_ctrl_generator_table[] = {
    {"EMIT", TParticleCtrl::create_random_spread},
    {"SPAIRAL", TParticleCtrl::generate_child_default},
    {"VACUUM", create_random_particle},
};
#pragma readonly_strings reset

void TParticleCtrl::init_heap(u32 size) {
    if (heap == NULL) {
        heap = new THeap(size, 16);
    }
}

void TParticleCtrl::free_heap() {
    if (heap != NULL) {
        delete heap;
        heap = NULL;
    }
}

void *TParticle::operator new(size_t size) {
    TParticle *p = (TParticle *)alt_heap->heap_alloc(size);
    if (p == NULL) {
        if (TParticleCtrl::heap != NULL) {
            p = (TParticle *)TParticleCtrl::heap->heap_alloc(size);
            if (p != NULL) {
                p->from_particle_heap = 1;
            }
        }
    } else {
        p->from_particle_heap = 0;
    }
    return p;
}

void TParticle::operator delete(void *p) {
    if (p != NULL) {
        if (((TParticle *)p)->from_particle_heap != 0) {
            TParticleCtrl::heap->heap_free(p);
            return;
        }
        alt_heap->heap_free(p);
    }
}

TParticle::TParticle(ParticleParam *src, TObject *parent) : TObject(parent) {
    f32 v;
    model = NULL;
    texlist = NULL;
    motion = NULL;
    motion_frame = 0.0f;
    tint.a = 0.0f;
    tint.r = 0.0f;
    tint.g = 0.0f;
    tint.b = 0.0f;
    rot_x = 0;
    rot_y = 0;
    rot_z = 0;
    scale_x = 1.0f;
    scale_y = 1.0f;
    param = src;
    v = 0.0f;
    if (param->fade_in_end > 0.0f) {
        v = 1.0f / param->fade_in_end;
    }
    fade_in_scale = v;
    v = 0.0f;
    if (param->fade_out_start > 0.0f) {
        v = 1.0f / param->fade_out_start;
    }
    fade_out_scale = v;
    sprite_index = find_particle_texture_index(param->sprite_id);
    size_x = 1.0f;
    size_y = 1.0f;
    step.x = 0.0f;
    step.y = 0.0f;
    step.z = 0.0f;
    age = 0.0f;
    age_rate = 0.0f;
    sprite.pos.x = 0.0f;
    sprite.pos.y = 0.0f;
    sprite.pos.z = 0.0f;
    sprite.offset.x = 0.0f;
    sprite.offset.y = 0.0f;
    sprite.offset.z = 0.0f;
    sprite.scale_x = 0.0f;
    sprite.scale_y = 0.0f;
    sprite.color = 0;
    sprite.uv_index = 0;
    sprite.type = 0;
    sprite.angle = 0;
    sprite.next = 0;
    flags = 0;
    target_id = 0xFFFF;
}

TParticle::~TParticle() {
    param = NULL;
}

void TParticle::apply_particle_model_fade_color(s32 mode) {
    NJS_ARGB f;
    if (mode != 0) {
        set_color_blend_mode(1, 4, 1, 0);
        NJS_COLOR c;
        c.color = sprite.color;
        f.a = 0.0f;
        f.r = -(1.0f - c.argb.r / 255.0f);
        f.g = -(1.0f - c.argb.g / 255.0f);
        f.b = -(1.0f - c.argb.b / 255.0f);
    } else {
        set_color_blend_mode(1, 4, 5, 0);
        NJS_COLOR c;
        c.color = sprite.color;
        f.a = -(1.0f - c.argb.a / 255.0f);
        f.r = 0.0f;
        f.g = 0.0f;
        f.b = 0.0f;
    }
    set_constant_material(&f);
}

void TParticle::draw_particle_refraction_quad() {
    Vec p;
    ParticleStripVertex v[4];
    s32 cell;
    const f32 *uv;
    cell = sprite.uv_index;
    if (is_split_screen() != 0) {
        return;
    }
    TParticleCtrl::begin_effect_render();
    uv = particle_definitions[sprite_index].uvs[cell];
    p.x = sprite.pos.x + sprite.offset.x;
    p.y = sprite.pos.y + sprite.offset.y;
    p.z = sprite.pos.z + sprite.offset.z;
    v[0].x = 10.0f * sprite.scale_x; v[0].y = 10.0f * sprite.scale_y; v[0].z = 0.0f; v[0].u = uv[0]; v[0].v = uv[1]; v[0].color = sprite.color;
    v[1].x = 10.0f * sprite.scale_x; v[1].y = -10.0f * sprite.scale_y; v[1].z = 0.0f; v[1].u = uv[2]; v[1].v = uv[1]; v[1].color = sprite.color;
    v[2].x = -10.0f * sprite.scale_x; v[2].y = 10.0f * sprite.scale_y; v[2].z = 0.0f; v[2].u = uv[0]; v[2].v = uv[3]; v[2].color = sprite.color;
    v[3].x = -10.0f * sprite.scale_x; v[3].y = -10.0f * sprite.scale_y; v[3].z = 0.0f; v[3].u = uv[2]; v[3].v = uv[3]; v[3].color = sprite.color;
    push_matrix();
    post_translate_matrix(&p.x);
    rotate_matrix_y(0, camera_ctrl_instance->yaw);
    rotate_matrix_x(0, camera_ctrl_instance->pitch);
    load_projected_texture_matrix(1.1333334f);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(particle_definitions[9].texlist));
    set_texture_num(sprite_index);
    TParticleCtrl::setup_particle_draw(1);
    GXSetNumTevStages(2);
    GXSetNumTexGens(2);
    GXSetTevOp(GX_TEVSTAGE0, GX_MODULATE);
    play_indirect_effect_recipe(0x1F, 0, 1);
    TObjPlayer::setup_tev_stage();
    emit_particle_strip_vertices(v, 4);
    TParticleCtrl::reset_particles();
    reset_particle_tev();
    reset_indirect_tev(1);
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

void TParticle::mark_active() {
    flags |= 0x2000;
    request_indirect_effect(0x1F);
}

s32 TParticle::is_particle_sprite_additive(s32) {
    return particle_sprites[sprite_index]->definition->flags & 1;
}

#pragma push
#pragma fp_contract on
void TParticleBallistic::draw_sprite_quad(s32 kind) {
    Vec view;
    Vec world;
    RotatedQuadSpriteRect quad;
    const f32 *uv;
    f32 sx;
    f32 sy;
    f32 x;
    f32 cy;
    f32 z;
    f32 y;
    f32 c;
    f32 s;
    u32 flags;
    f32 a;
    f32 b;

    flags = particle_definitions[kind].flags;
    if (flags & 2) {
        if (flags & 4) {
            set_inverse_alpha_blend();
        } else {
            set_default_alpha_blend();
        }
    } else if (flags & 4) {
        set_inverse_color_blend();
    } else {
        set_additive_blend();
    }
    sy = screen_projection.distance;
    x = screen_projection.center_x;
    cy = screen_projection.center_y;
    sx = sy * (480.0f / (480.0f * screen_projection.width));
    TParticleCtrl::begin_effect_render();
    begin_screen_draw(1);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(particle_definitions[kind].texlist));
    set_draw_texture_and_color(particle_definitions[kind].texture, particle_definitions[kind].color);
    uv = particle_definitions[kind].uvs[sprite.uv_index];
    quad.u = uv[0];
    quad.v = uv[1];
    quad.edge_a_u = uv[2] - uv[0];
    quad.edge_b_u = quad.edge_a_v = 0.0f;
    quad.edge_b_v = uv[3] - uv[1];
    world.x = sprite.pos.x + sprite.offset.x;
    world.y = sprite.pos.y + sprite.offset.y;
    world.z = sprite.pos.z + sprite.offset.z;
    if (sprite.type != 1) {
        matrix_mult_vec(0, &world, &view);
        view.y = -view.y;
    } else {
        VecCopy(&view, &world);
    }
    if (view.z <= -1.0f || sprite.type == 1) {
        set_constant_material_color(sprite.color);
        if (sprite.type != 1) {
            z = 1.0f / -view.z;
            a = sx * z;
            b = sy * z;
            sx = a;
            sy = b;
            x = view.x * a + x;
            y = view.y * b + cy;
        } else {
            sx = 1.0f;
            z = view.z;
            sy = sx;
            x = view.x;
            y = view.y;
        }
        sx *= particle_definitions[kind].width;
        sy *= particle_definitions[kind].height;
        sx *= sprite.scale_x;
        sy *= sprite.scale_y;
        c = cos_table_lookup(sprite.angle);
        s = -sin_table_lookup(sprite.angle);
        quad.depth = z;
        quad.x = x - (sx * c + sy * s);
        quad.y = y - (-sx * s + sy * c);
        sy = sy + sy;
        sx = sx + sx;
        quad.edge_a_x = sx * c;
        quad.edge_a_y = -sx * s;
        quad.edge_b_x = sy * s;
        quad.edge_b_y = sy * c;
        DVDConvertEntrynumToPath(&quad.x);
    }
    TWindowSubStatusDisp::get_player();
    TParticleCtrl::end_effect_render();
    set_default_alpha_blend();
}
#pragma pop
