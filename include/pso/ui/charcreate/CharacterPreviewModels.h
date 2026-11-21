#ifndef PSO_UI_CHARCREATE_CHARACTERPREVIEWMODELS_H
#define PSO_UI_CHARCREATE_CHARACTERPREVIEWMODELS_H

#include <stddef.h>
#include "types.h"

struct CharacterAppearanceFields;
struct NJS_OBJECT;

struct CharacterPreviewModels {
    CharacterAppearanceFields *appearance;
    NJS_OBJECT *head;
    NJS_OBJECT *body;
    s32 sample_indices[3];
    NJS_OBJECT *head_samples[3];
    NJS_OBJECT *body_samples[3];
};

typedef char CharacterPreviewModels_size[sizeof(CharacterPreviewModels) == 0x30 ? 1 : -1];
typedef char CharacterPreviewModels_head_offset[offsetof(CharacterPreviewModels, head) == 0x4 ? 1 : -1];
typedef char CharacterPreviewModels_indices_offset[offsetof(CharacterPreviewModels, sample_indices) == 0xC ? 1 : -1];
typedef char CharacterPreviewModels_head_samples_offset[offsetof(CharacterPreviewModels, head_samples) == 0x18 ? 1 : -1];
typedef char CharacterPreviewModels_body_samples_offset[offsetof(CharacterPreviewModels, body_samples) == 0x24 ? 1 : -1];

extern "C" {
void bind_character_preview_models(const CharacterPreviewModels *models);
void get_sorted_character_proportion_samples(const f32 *point, s32 *samples);
}

#endif
