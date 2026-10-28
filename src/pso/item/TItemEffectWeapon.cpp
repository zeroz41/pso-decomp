#include "pso/item/TItemEffectWeapon.h"
#include "pso/item/TItemEquipVariant_8012A82C.h"
#include "pso/render/depth_buffer.h"
#include "pso/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TObject.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_80141D1C.h"

#pragma readonly_strings on
const char *TItemEffectWeapon__class_name = "TItemEffectWeapon";

extern "C" {
s32 get_mode__11TCameraCtrlFPv(void *p);
void restore_saved_depth_alpha_state();
void TObjPlayer__sub_803DF768(s32);
void set_render_deferred__7TObjectFv(void*);
void *mem_alloc(u32 size);
extern u32 saved_model_render_flags;
extern u32 model_render_flags;

void *__dt__13TUnk_804F28E0Fv(void *arg0, s16 arg1);
void TItemEffectWeapon__sub_8036340C(void);
void TItemEffectWeapon__sub_80363410(void);

void decrement_timer__17TItemEffectWeaponFv(void *, s32);
void mem_free(void *p);
void* memcpy(void* destination, const void* source, size_t size);
f32 xyz_distance(const f32 *a, const f32 *b);
f32 normalize_vector(f32 *v);

extern s32 lbl_804F28E0[];

void *__dt__13TUnk_804F28E0Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804F28E0;
        __dt__13TUnk_804A4948Fv(arg0, 0);
        if (arg1 > 0) {
            TItem::operator delete(arg0);
        }
    }
    return arg0;
}

void TItemEffectWeapon__sub_8036340C(void) {  }
void TItemEffectWeapon__sub_80363410(void) {  }
}
void reset_player_transform();
void draw_untextured_trail_strip(void *arg0, void *arg1);

void TItemEffectWeapon::run_task() {
    s32 offset;
    TrailVertex* segment;
    s32 i;
    i = 0;
    offset = 0;
    while (i != vertex_count / 2) {
        segment = (TrailVertex*)((u8*)vertices + offset);
        decrement_timer__17TItemEffectWeaponFv(&segment[0].color, 0x3F);
        if ((segment[0].color & 0xFF000000) == 0) {
            vertex_count = i << 1;
            return;
        }
        decrement_timer__17TItemEffectWeaponFv((u8*)vertices + offset + 0x1C, 0x3F);
        i++;
        offset += 0x20;
    }
}

#pragma push
#pragma fp_contract on
void TItemEffectWeapon::push_trail_interpolated(const f32 *first, const f32 *second) {
    if (vertices != NULL && first != NULL && second != NULL) {
        if (vertex_count != 0) {
            TrailVertex *prev = vertices;
            f32 base[3];
            f32 tip[3];
            f32 dir[3];
            f32 base_x = prev[1].x;
            f32 base_y = prev[1].y;
            f32 base_z = prev[1].z;
            f32 tip_x = prev[0].x;
            f32 tip_y = prev[0].y;
            f32 tip_z = prev[0].z;
            f32 tip_dx = (second[0] - tip_x) / 2.0f;
            f32 tip_dy = (second[1] - tip_y) / 2.0f;
            f32 tip_dz = (second[2] - tip_z) / 2.0f;
            f32 base_dx = (first[0] - base_x) / 2.0f;
            f32 base_dy = (first[1] - base_y) / 2.0f;
            f32 base_dz = (first[2] - base_z) / 2.0f;
            f32 length = xyz_distance(first, second);
            s32 i;
            for (i = 1; i < 2; i++) {
                base[0] = base_dx * i + base_x;
                base[1] = base_dy * i + base_y;
                base[2] = base_dz * i + base_z;
                tip[0] = tip_dx * i + tip_x;
                tip[1] = tip_dy * i + tip_y;
                tip[2] = tip_dz * i + tip_z;
                dir[0] = tip[0] - base[0];
                dir[1] = tip[1] - base[1];
                dir[2] = tip[2] - base[2];
                normalize_vector(dir);
                base[0] = 0.01f * dir[0] + base[0];
                base[1] = 0.01f * dir[1] + base[1];
                base[2] = 0.01f * dir[2] + base[2];
                tip[0] = dir[0] * length + base[0];
                tip[1] = dir[1] * length + base[1];
                tip[2] = dir[2] * length + base[2];
                push_trail_entry(base, tip);
            }
        }
        push_trail_entry(first, second);
    }
}
#pragma pop

void TItemEffectWeapon::push_trail_entry(const f32* first, const f32* second) {
    if (vertices != NULL && first != NULL && second != NULL) {
        if (vertex_count == 0x20) {
            vertex_count -= 2;
        }
        s32 count = vertex_count;
        if (count != 0) {
            TrailVertex* buffer = vertices;
            memcpy(buffer + 2, buffer, count * sizeof(TrailVertex));
        }
        vertices[0].x = second[0];
        vertices[0].y = second[1];
        vertices[0].z = second[2];
        vertices[0].color = color;
        vertices[1].x = first[0];
        vertices[1].y = first[1];
        vertices[1].z = first[2];
        vertices[1].color = color & 0x4FFFFFFF;
        vertex_count += 2;
    }
}

void TItemEffectWeapon::render_trail() {
    if (get_mode__11TCameraCtrlFPv(((u8 *)&main_task)) & 0x200) {
        if (vertex_count != 0 && vertices != NULL) {
            TParticleCtrl::begin_effect_render();
            saved_model_render_flags = model_render_flags;
            set_depth_buffer_settings_1();
            model_render_flags |= 0x8000;
            set_additive_blend();
            if (vertex_count > 2) {
                TObjPlayer__sub_803DF768(1);
                draw_untextured_trail_strip((void *)vertices, (void *)vertex_count);
                reset_player_transform();
            }
            set_default_alpha_blend();
            model_render_flags = saved_model_render_flags;
            restore_saved_depth_alpha_state();
            TParticleCtrl::end_effect_render();
        }
    } else {
        set_render_deferred__7TObjectFv(this);
    }
}


TItemEffectWeapon::~TItemEffectWeapon() {
    TItemEffectWeapon::release_trail_buffer((void*)*(s32 *)((s8 *)this + 0x1C));
}

TItemEffectWeapon::TItemEffectWeapon(s32 arg1, s32 param) : TItemHeapObject((TObject*)arg1) {
    m_name = TItemEffectWeapon__class_name;
    *(s32 *)((s8 *)this + 0x1C) = (s32)TItemEffectWeapon::allocate_trail_buffer();
    this->color = param;
    this->vertex_count = 0;
    this->field_28 = 0;
}

    extern TItemEffectWeapon::TrailVertex* item_weapon_trail_vertex_buffer;
    extern s32* weapon_trail_slot_bitmap;

void TItemEffectWeapon::release_trail_buffer(void* buffer) {
    if (buffer != NULL) {
        s32 vertex_offset = ((u8*)buffer - (u8*)item_weapon_trail_vertex_buffer) / 16;
        weapon_trail_slot_bitmap[(u32)vertex_offset >> 5] = 0;
    }
}

TItemEffectWeapon::TrailVertex* TItemEffectWeapon::allocate_trail_buffer() {
    s32* allocated = weapon_trail_slot_bitmap;
    for (s32 i = 0; i < 16; i++) {
        if (allocated[i] == 0) {
            allocated[i] = 1;
            return item_weapon_trail_vertex_buffer + i * 32;
        }
    }
    return NULL;
}

void TItemEffectWeapon::free_static_effects() {
    mem_free(weapon_trail_slot_bitmap);
    mem_free(item_weapon_trail_vertex_buffer);
    weapon_trail_slot_bitmap = NULL;
    item_weapon_trail_vertex_buffer = NULL;
}

void TItemEffectWeapon::initialize_static_effects() {
    item_weapon_trail_vertex_buffer = (TrailVertex*)mem_alloc(16 * 32 * sizeof(TrailVertex));
    weapon_trail_slot_bitmap = (s32*)mem_alloc(16 * sizeof(s32));
    for (s32 i = 0; i < 16; i++) {
        weapon_trail_slot_bitmap[i] = 0;
    }
}
