#include "types.h"
#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/TEffect.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/sprite/TQuadSpriteNormal.h"
#include "pso/effect/sprite/TQuadSpriteScl.h"
#include "pso/effect/sprite/TQuadSpriteCol.h"
#include "pso/effect/sprite/TQuadSpriteSclCol.h"
#include "pso/effect/sprite/TQuadSpriteSclColRot.h"
#include "pso/system/task/TMainTask.h"

NJS_TEXLIST *particle_texture_lists[2] = { &shared_effect_texture_list, 0 };


extern f32 particle_sprite_atlas_uv_rects[0x10][4];
extern f32 particle_full_texture_uv[1][4];

void TParticleCtrl::reset_emitter_table() {
    s32 i;
    for (i = 0; i < 0x6C; i++) {
        particle_definitions[i].texlist = NULL;
        particle_sprites[i] = 0;
    }
    for (i = 0; i < 0x6C; i++) {
        particle_definitions[i].texlist = NULL;
    }
}

void TParticleCtrl::create_quad_sprites() {
    s32 index = 0;
    ParticleDefinition *definitions = particle_definitions;
    TQuadSprite **sprites = particle_sprites;
    TQuadSprite *sprite;

    do {
        ParticleDefinition *definition = &definitions[index];

        switch (definitions[index].sprite_type) {
        case 0:
            sprite = new TQuadSpriteNormal(tl_particle, definition);
            break;
        case 1:
            sprite = new TQuadSpriteScl(tl_particle, definition);
            break;
        case 2:
            sprite = new TQuadSpriteCol(tl_particle, definition);
            break;
        case 3:
            sprite = new TQuadSpriteSclCol(tl_particle, definition);
            break;
        case 4:
            sprite = new TQuadSpriteSclColRot(tl_particle, definition);
            break;
        }

        sprites[index] = sprite;
        index++;
    } while (index < 0x6C);
}

void init_particle_sprite_atlas(void) {
    f32 (*p)[4];
    s32 y;
    s32 x;
    s32 i;
    f32 left;
    f32 u;
    f32 top;
    f32 v;

    p = particle_sprite_atlas_uv_rects;
    v = 0.0f;
    for (y = 0; y < 4; y++) {
        top = v;
        u = 0.0f;
        v += 0.25f;
        for (x = 0; x < 4; x++) {
            left = u;
            u += 0.25f;
            (*p)[0] = left;
            (*p)[1] = top;
            (*p)[2] = u;
            (*p)[3] = v;
            p++;
        }
    }
    for (i = 0; i < 0x6C; i++) {
        particle_definitions[i].texlist = particle_texture_lists[particle_definitions[i].texlist_index];
        particle_sprites[i] = 0;
    }
}

TQuadSprite *particle_sprites[0x6C];
f32 particle_sprite_atlas_uv_rects[0x10][4];

ParticleDefinition particle_definitions[0x6C] = {
    {2, &shared_effect_texture_list, 0, 1, particle_full_texture_uv, 4.0f, 4.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 1, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {2, &shared_effect_texture_list, 2, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 3, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {2, &shared_effect_texture_list, 4, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 5, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 6, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 7, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 8, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 9, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 10, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 11, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 12, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 13, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 14, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 15, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 16, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 17, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 18, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 19, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 20, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 21, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 22, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 23, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 24, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 25, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 26, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 27, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 28, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 29, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 30, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 31, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 32, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 33, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 34, 16, particle_sprite_atlas_uv_rects, 8.0f, 8.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 35, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 36, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 37, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 38, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 39, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 40, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {2, &shared_effect_texture_list, 41, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 42, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 43, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 44, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 45, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 46, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 47, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 48, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 49, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 50, 16, particle_sprite_atlas_uv_rects, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {2, &shared_effect_texture_list, 51, 1, particle_full_texture_uv, 8.0f, 8.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 52, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {2, &shared_effect_texture_list, 53, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {6, &shared_effect_texture_list, 0, 1, particle_full_texture_uv, 4.0f, 4.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 1, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {6, &shared_effect_texture_list, 2, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 3, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {6, &shared_effect_texture_list, 4, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 5, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 6, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 7, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 8, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 9, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 10, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 11, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 12, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 13, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 14, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 15, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 16, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 17, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 18, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 19, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 20, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 21, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 22, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 23, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 24, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 25, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 26, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 27, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 28, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 29, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 30, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 31, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 32, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 33, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 34, 16, particle_sprite_atlas_uv_rects, 8.0f, 8.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 35, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 36, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 37, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 38, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 39, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 40, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {6, &shared_effect_texture_list, 41, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 42, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 43, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 44, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 45, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 46, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 47, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 48, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 49, 16, particle_sprite_atlas_uv_rects, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 50, 16, particle_sprite_atlas_uv_rects, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {6, &shared_effect_texture_list, 51, 1, particle_full_texture_uv, 8.0f, 8.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 52, 1, particle_full_texture_uv, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {6, &shared_effect_texture_list, 53, 1, particle_full_texture_uv, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
};

// Full-texture rect for the single-frame kinds.
f32 particle_full_texture_uv[1][4] = {{0.0f, 0.0f, 1.0f, 1.0f}};
