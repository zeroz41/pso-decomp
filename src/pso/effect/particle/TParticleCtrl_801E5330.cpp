#include "types.h"
#include "pso/effect/particle/TParticleCtrl_801E5330.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/TEffect.h"

// One quad-sprite particle kind; create_quad_sprites builds sprite_type's
// TQuadSprite* class for each. Field names inferred from the users.
struct ParticleDefinition {
    u32 flags;
    GinjaTextureList *texlist;
    s32 texture;
    s32 uv_count;
    f32 (*uvs)[4];
    f32 width;
    f32 height;
    u32 color;
    s32 texlist_index;
    s32 sprite_type;
};
extern "C" {

void *__nw__7TObjectFUl(u32);
void *TQuadSpriteNormal__ct(void *, void *, ParticleDefinition *);
void *TQuadSpriteScl__ct(void *, void *, ParticleDefinition *);
void *TQuadSpriteCol__ct(void *, void *, ParticleDefinition *);
void *TQuadSpriteSclCol__ct(void *, void *, ParticleDefinition *);
void *TQuadSpriteSclColRot__ct(void *, void *, ParticleDefinition *);

extern ParticleDefinition lbl_804C5820[];
extern void *TParticleCtrl__data_80511F70[];
extern void *tl_particle;
extern f32 particle_sprite_atlas_uv_rects[0x10][4];
extern GinjaTextureList *lbl_805D35A0[2];
extern f32 lbl_804C6900[1][4];

void TParticleCtrl::reset_emitter_table() {
    s32 i;
    for (i = 0; i < 0x6C; i++) {
        lbl_804C5820[i].texlist = NULL;
        TParticleCtrl__data_80511F70[i] = 0;
    }
    for (i = 0; i < 0x6C; i++) {
        lbl_804C5820[i].texlist = NULL;
    }
}

void TParticleCtrl::create_quad_sprites() {
    s32 index = 0;
    ParticleDefinition *definitions = lbl_804C5820;
    void **sprites = TParticleCtrl__data_80511F70;
    void *sprite;

    do {
        ParticleDefinition *definition = &definitions[index];
        void *object;

        switch (definitions[index].sprite_type) {
        case 0:
            object = __nw__7TObjectFUl(0x2C);
            if (object != NULL) {
                object = TQuadSpriteNormal__ct(object, tl_particle, definition);
            }
            sprite = object;
            break;
        case 1:
            object = __nw__7TObjectFUl(0x2C);
            if (object != NULL) {
                object = TQuadSpriteScl__ct(object, tl_particle, definition);
            }
            sprite = object;
            break;
        case 2:
            object = __nw__7TObjectFUl(0x2C);
            if (object != NULL) {
                object = TQuadSpriteCol__ct(object, tl_particle, definition);
            }
            sprite = object;
            break;
        case 3:
            object = __nw__7TObjectFUl(0x2C);
            if (object != NULL) {
                object = TQuadSpriteSclCol__ct(object, tl_particle, definition);
            }
            sprite = object;
            break;
        case 4:
            object = __nw__7TObjectFUl(0x2C);
            if (object != NULL) {
                object = TQuadSpriteSclColRot__ct(object, tl_particle, definition);
            }
            sprite = object;
            break;
        }

        sprites[index] = sprite;
        index++;
    } while (index < 0x6C);
}
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
        lbl_804C5820[i].texlist = lbl_805D35A0[lbl_804C5820[i].texlist_index];
        TParticleCtrl__data_80511F70[i] = 0;
    }
}

void *TParticleCtrl__data_80511F70[0x6C];
f32 particle_sprite_atlas_uv_rects[0x10][4];

ParticleDefinition lbl_804C5820[0x6C] = {
    {2, &shared_effect_texture_list, 0, 1, lbl_804C6900, 4.0f, 4.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 1, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {2, &shared_effect_texture_list, 2, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 3, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {2, &shared_effect_texture_list, 4, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 5, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 6, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 7, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 8, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 9, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 10, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 11, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 12, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 13, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 14, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 15, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 16, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 17, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 18, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 19, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 20, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 21, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 22, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 23, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 24, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 25, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 26, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 27, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 28, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 29, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 30, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 31, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 32, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 33, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 34, 16, particle_sprite_atlas_uv_rects, 8.0f, 8.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 35, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 36, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 37, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 38, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {1, &shared_effect_texture_list, 39, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
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
    {2, &shared_effect_texture_list, 51, 1, lbl_804C6900, 8.0f, 8.0f, 0xFFFFFFFF, 0, 4},
    {1, &shared_effect_texture_list, 52, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {2, &shared_effect_texture_list, 53, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {6, &shared_effect_texture_list, 0, 1, lbl_804C6900, 4.0f, 4.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 1, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {6, &shared_effect_texture_list, 2, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 3, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {6, &shared_effect_texture_list, 4, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 5, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 6, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 7, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 8, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 9, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 10, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 11, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 12, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 13, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 14, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 15, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 16, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 17, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 18, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 19, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 20, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 21, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 22, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 23, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 24, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 25, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 26, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 27, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 28, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 29, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 30, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 31, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 32, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 33, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 34, 16, particle_sprite_atlas_uv_rects, 8.0f, 8.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 35, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 36, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 37, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 38, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
    {5, &shared_effect_texture_list, 39, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 3},
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
    {6, &shared_effect_texture_list, 51, 1, lbl_804C6900, 8.0f, 8.0f, 0xFFFFFFFF, 0, 4},
    {5, &shared_effect_texture_list, 52, 1, lbl_804C6900, 16.0f, 16.0f, 0xFFFFFFFF, 0, 3},
    {6, &shared_effect_texture_list, 53, 1, lbl_804C6900, 32.0f, 32.0f, 0xFFFFFFFF, 0, 4},
};

// Full-texture rect for the single-frame kinds.
f32 lbl_804C6900[1][4] = {{0.0f, 0.0f, 1.0f, 1.0f}};
