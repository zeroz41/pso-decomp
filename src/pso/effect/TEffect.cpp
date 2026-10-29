#pragma readonly_strings on
#include "pso/effect/TEffect.h"
#include "pso/TMainTask.h"
#include "pso/misc/TLobby.h"
#include "pso/system/GinjaTexture.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/unk/text_800F9B84.h"

struct EffectTextureFile {
    GinjaTextureList *texlist;
    const char *filename;
};

static const EffectTextureFile effect_texture_file = {&shared_effect_texture_list, "effect_nt.gvm"};
const char *TEffect__class_name = "TEffect";

s32 effect_rel;
s32 particle_texture_id_table[54];

void approach_vector_in_place(Vec *current, const Vec *target, f32 step) {
    Vec next;
    approach_vector_fixed_distance((const Vec *)current, (const Vec *)target, (Vec *)&next, step);
    current->x = next.x;
    current->y = next.y;
    current->z = next.z;
}

s32 approach_alpha_clamped(f32 *current, const f32 *target, f32 step) {
    f32 v;
    if (*current == *target) {
        return 1;
    }
    if (*current < *target) {
        v = *current + step;
        *current = (v < 0.0f) ? 0.0f : ((v < *target) ? v : *target);
    } else {
        v = *current - step;
        *current = (v < *target) ? *target : ((v < 1.0f) ? v : 1.0f);
    }
    return 0;
}

void approach_rgb_clamped(NJS_ARGB *current, const NJS_ARGB *target, f32 step) {
    if (current->r < target->r) {
        f32 v = current->r + step;
        current->r = (v < 0.0f) ? 0.0f : ((v < target->r) ? v : target->r);
    } else {
        f32 v = current->r - step;
        current->r = (v < target->r) ? target->r : ((v < 1.0f) ? v : 1.0f);
    }
    if (current->g < target->g) {
        f32 v = current->g + step;
        current->g = (v < 0.0f) ? 0.0f : ((v < target->g) ? v : target->g);
    } else {
        f32 v = current->g - step;
        current->g = (v < target->g) ? target->g : ((v < 1.0f) ? v : 1.0f);
    }
    if (current->b < target->b) {
        f32 v = current->b + step;
        current->b = (v < 0.0f) ? 0.0f : ((v < target->b) ? v : target->b);
    } else {
        f32 v = current->b - step;
        current->b = (v < target->b) ? target->b : ((v < 1.0f) ? v : 1.0f);
    }
}

s32 find_particle_texture_index(s32 id) {
    s32 index = 0;
    s32 i;
    for (i = 0; i < 54; i++) {
        if (id == particle_texture_id_table[i]) {
            index = i;
            break;
        }
    }
    return index;
}

void copy_slot_to_anim_frame(TextureFrameSlot *slot) {
    slot->frames->entries[slot->frame].texture = slot->texlist->entries[slot->slot].texture;
    slot->frames->entries[slot->frame].value04 = slot->texlist->entries[slot->slot].value04;
    slot->frames->entries[slot->frame].name = slot->texlist->entries[slot->slot].name;
}

void copy_anim_frame_to_slot(TextureFrameSlot *slot) {
    slot->texlist->entries[slot->slot].texture = slot->frames->entries[slot->frame].texture;
    slot->texlist->entries[slot->slot].value04 = slot->frames->entries[slot->frame].value04;
    slot->texlist->entries[slot->slot].name = slot->frames->entries[slot->frame].name;
}

void free_effect_resources() {
    release_texture_list(effect_texture_file.texlist);
    TLobby::free_nodes_with_id(effect_rel);
    effect_rel = 0;
}

void load_effect_resources() {
    s32 i;
    effect_rel = create_named_object((s32)"EFFECT_NT.REL");
    bind_gvm_texture_list(effect_texture_file.filename, effect_texture_file.texlist);
    for (i = 0; i < 54; i++) {
        particle_texture_id_table[i] = shared_effect_texture_list.entries[i].texture->surface->id;
    }
}

TEffect::~TEffect() {
    source = 0;
}

TEffect::TEffect() : TObject(tl_particle) {
    m_name = TEffect__class_name;
    position.x = 0.0f;
    position.y = 0.0f;
    position.z = 0.0f;
    color.a = 0.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
    scale.x = 1.0f;
    scale.y = 1.0f;
    scale.z = 1.0f;
    direction.x = 0.0f;
    direction.y = 0.0f;
    direction.z = 0.0f;
    angles[0] = 0;
    angles[1] = 0;
    angles[2] = 0;
    field_60 = 0.0f;
    speed = 0.0f;
    age = 0;
    state = 0;
    source = 0;
}
