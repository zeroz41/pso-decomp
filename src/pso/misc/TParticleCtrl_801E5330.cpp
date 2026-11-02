#include "types.h"
#include "pso/misc/TParticleCtrl_801E5330.h"
#include "pso/TParticleCtrl.h"

struct ParticleDefinition {
    u8 data[0x24];
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
extern f32 particle_sprite_atlas_uv_rects[][4];
extern s32 lbl_805D35A0[2];
extern const f32 lbl_805DC458;
extern const f32 lbl_805DC45C;

void TParticleCtrl::reset_emitter_table() {
    s32 i;
    for (i = 0; i < 0x6C; i++) {
        *(s32 *)(lbl_804C5820[i].data + 4) = 0;
        TParticleCtrl__data_80511F70[i] = 0;
    }
    for (i = 0; i < 0x6C; i++) {
        *(s32 *)(lbl_804C5820[i].data + 4) = 0;
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
    v = lbl_805DC458;
    for (y = 0; y < 4; y++) {
        top = v;
        u = lbl_805DC458;
        v += lbl_805DC45C;
        for (x = 0; x < 4; x++) {
            left = u;
            u += lbl_805DC45C;
            (*p)[0] = left;
            (*p)[1] = top;
            (*p)[2] = u;
            (*p)[3] = v;
            p++;
        }
    }
    for (i = 0; i < 0x6C; i++) {
        *(s32 *)(lbl_804C5820[i].data + 4) = lbl_805D35A0[*(s32 *)(lbl_804C5820[i].data + 0x20)];
        TParticleCtrl__data_80511F70[i] = 0;
    }
}

void *TParticleCtrl__data_80511F70[0x6C];
f32 particle_sprite_atlas_uv_rects[0x10][4];
