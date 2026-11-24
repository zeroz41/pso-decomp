#include "pso/system/BmlAccessors.h"
#include "pso/render/GinjaMaterialTextureSlot.h"
#include "pso/render/GinjaUvScroll.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/object/door/TObjDoorKey.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/object/ambient/TObjEnvSoundGlobal.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/door/TObjDoorJung.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/key/TOKeyAncient01.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/text_803D853C.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/task/TObject.h"
#include "pso/object/key/TOKey.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/TLanguage_801E4874.h"


struct BmlResource;
struct NJS_TEXLIST;

const char *abeno_fs_obj001_fosuno_model_names[4] = { "abeno_fs_obj001_fosuno.gj", "abesu_fs_obj001_fosu.gj", "abesu_fs_obj001_fotutu.gj", NULL };
const char *abeno_fs_obj001_fosuno_motion_names[1] = { NULL };
BmlResourceDescriptor TObjDoorKey__resource_descriptor = { "abeno_fs_obj001_fosuno.bml", abeno_fs_obj001_fosuno_model_names, abeno_fs_obj001_fosuno_motion_names, 3, 0 };
CollisionBody TObjDoorKey__collision_body_parts[] = {
    {{0.0f, 10.0f, 0.0f}, 7.0f, 50.0f, 0, 0x30003, {0.0f, 0.0f, 0.0f}, 0.0f}
};
/* beam colour (a, r, g, b) per key id */
NJS_ARGB door_key_beam_color_table[10] = {
    { 1.0f, 0.8235294f, 0.09803922f, 0.09803922f },
    { 1.0f, 0.09803922f, 0.09803922f, 0.8235294f },
    { 1.0f, 0.8235294f, 0.8235294f, 0.09803922f },
    { 1.0f, 0.09803922f, 0.8235294f, 0.8235294f },
    { 1.0f, 0.8235294f, 0.09803922f, 0.8235294f },
    { 1.0f, 0.8235294f, 0.5019608f, 0.09803922f },
    { 1.0f, 0.09803922f, 0.5019608f, 0.8235294f },
    { 1.0f, 0.7058824f, 0.9019608f, 0.09803922f },
    { 1.0f, 0.8235294f, 0.09803922f, 0.39215687f },
    { 1.0f, 1.0f, 1.0f, 1.0f },
};
const char *TObjDoorKey__class_name = "TObjDoorKey";

saddr TObjDoorKey__ginja_model_table[4];
BmlResource *door_key_resource_handle;
NJS_TEXLIST *TObjDoorKey__texture_handle;
s16 door_key_id_counter;
s32 TObjDoorKey__data_805D5C04;

struct Obj_8018FA6C { u8 pad0[0x6]; u16 id; u8 pad8[0x4]; Obj_8018FA6C *next; u8 pad10[0x4]; Obj_8018FA6C *children; };

extern "C" {
extern Obj_8018FA6C *tl_05;
Obj_8018FA6C *fn_8018FA6C(u16 id) {
    Obj_8018FA6C *next = tl_05->children;
    Obj_8018FA6C *cur;
    while (tl_05->children != 0 && next != 0) {
        cur = next;
        next = cur->next;
        if (reinterpret_cast<TObject *>(cur)->check_value_equals(TObjDoorKey__class_name) != 0 && cur->id == id) {
            return cur;
        }
    }
    return 0;
}

}


struct Base_8018FF74_8018FAEC { char pad[0x18]; };
struct VObj_8018FF74_8018FAEC : Base_8018FF74_8018FAEC {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
};

struct Key_8018FD9C { u8 pad0[0x38]; f32 f38[3]; u8 pad44[0x30]; f32 f74; f32 f78; u8 pad7C[0x10]; s32 f8C; };

struct Node_8018FBB8 { s32 pad0; void *model; };

struct Key_8018FBB8 { u8 pad0[0x38]; u8 f38[0x28]; s32 f60; u8 pad64[0x28]; s32 slot; u8 pad90[0x60]; s32 fF0; };

struct Node_8018FCD8 { s32 pad0; void *model; };

struct Key_8018FCD8 { u8 pad0[0x38]; u8 f38[0x28]; s32 angle; u8 pad64[0x28]; s32 slot; u8 pad90[0x60]; s32 fF0; };

extern "C" {
void PPCSync();
void post_translate_matrix(void *);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;

void TObjDoorKey__sub_8018FAEC(u16 id, u16) {
    Obj_8018FA6C *temp_r3;

    temp_r3 = fn_8018FA6C(id);
    if (temp_r3 != NULL) {
        *(s32 *)((s8 *)temp_r3 + 0xE8) = 1;
    }
}
}


void TObjDoorKey::render() {

    if (this->update_object_view_visibility(400.0f, 20.0f) == 0) {
        if ((u32) this->m_f8 != 0U) {
            ((TParticleCtrl *)(this->m_f8))->enable();
        }
    } else {
        if ((u32) this->m_f8 != 0U) {
            ((TParticleCtrl *)(this->m_f8))->clear_active_flag();
        }
        switch (this->is_on) {
        case 0:
            draw_inactive_badge();
            return;
        case 1:
            draw_active_beam();
            return;
        }
    }
}

void TObjDoorKey::draw_active_beam() {
    Key_8018FBB8 *arg0 = (Key_8018FBB8 *)this;
    if (TObjDoorKey__data_805D5C04 != actor_frame_tick) {
        scroll_ginja_mesh_uvs(static_cast<GinjaModel *>(((Node_8018FBB8 *)TObjDoorKey__ginja_model_table[1])->model), 0, 0x14, 0xE, 1);
        PPCSync();
        TObjDoorKey__data_805D5C04 = actor_frame_tick;
    }
    TObjFish::set_global_param(TObjDoorKey__texture_handle);
    push_matrix();
    post_translate_matrix(arg0->f38);
    rotate_matrix_y(0, arg0->f60);
    draw_ginja_object((void *)TObjDoorKey__ginja_model_table[0]);
    TParticleCtrl::begin_effect_render();
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    set_constant_material(&door_key_beam_color_table[arg0->slot]);
    draw_ginja_object((void *)TObjDoorKey__ginja_model_table[1]);
    rotate_matrix_y(0, arg0->fF0);
    saddr *g = TObjDoorKey__ginja_model_table;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((((Node_8018FBB8 *)g[2])->model)), ((u16)arg0->slot));
    draw_ginja_object((void *)g[2]);
    set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TObjDoorKey::draw_inactive_badge() {
    Key_8018FCD8 *arg0 = (Key_8018FCD8 *)this;
    TObjFish::set_global_param(TObjDoorKey__texture_handle);
    push_matrix();
    post_translate_matrix(arg0->f38);
    rotate_matrix_y(0, arg0->angle);
    draw_ginja_object((void *)TObjDoorKey__ginja_model_table[0]);
    TParticleCtrl::begin_effect_render();
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    set_constant_material(&door_key_beam_color_table[arg0->slot]);
    saddr *g = TObjDoorKey__ginja_model_table;
    set_ginja_model_texture_slot(reinterpret_cast<void *>((((Node_8018FCD8 *)g[2])->model)), ((u16)arg0->slot));
    draw_ginja_object((void *)g[2]);
    set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TObjDoorKey::debug_draw_key_id() {
    Key_8018FD9C *arg0 = (Key_8018FD9C *)this;
    TOKey::debug_draw_key_id();
    VecCopy((Vec *)&arg0->f74, (const Vec *)arg0->f38);
    arg0->f78 += 8.0f;
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130022, "PLATE NUM : %d", arg0->f8C);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    if (arg0->f8C < 0) {
        arg0->f8C = 0;
    }
    if (arg0->f8C > 9) {
        arg0->f8C = 9;
    }
}

void TObjDoorKey::trigger_deactivate_sound() {  }

void TObjDoorKey::trigger_activate_sound() {
    switch (get_current_floor_area()) {
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        play_sound_effect(0x42D0A, reinterpret_cast<const Vec *>(((u8 *)this) + 0x38), 0, 0);
        break;
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        play_sound_effect(0x4C601, reinterpret_cast<const Vec *>(((u8 *)this) + 0x38), 0, 0);
        break;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_sound_effect(0x4004C601, reinterpret_cast<const Vec *>(((u8 *)this) + 0x38), 0, 0);
        break;
    default:
        play_sound_effect(0x4C60A, reinterpret_cast<const Vec *>(((u8 *)this) + 0x38), 0, 0);
        break;
    }
    this->m_e8 = 1;
}

void TObjDoorKey::update_switch_on() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0xF4) = (s32) (*(s32 *)((s8 *)arg0 + 0xF4) + 0x14);
    this->m_f0 = (this->m_f0 + 0x200);
}

void TObjDoorKey::update_switch_off() { submit_cursor_candidate(this, -1); }
void TObjDoorKey::update_armed_switch() { TOKey::update_armed_switch(); }

void TObjDoorKey::run_task() {
    struct VObj_8018FF74_8018FAEC *o = (struct VObj_8018FF74_8018FAEC *)this;
    o->m22();
}
TObjDoorKey::~TObjDoorKey() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
    if ((u32) this->m_f8 != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0xF8)))->queue_destruction();
        this->m_f8 = 0U;
    }
}
TObjDoorKey::TObjDoorKey(TObject *parent, void *set_entry) : TOKey(parent) {
    this->m_name = TObjDoorKey__class_name;
    init_key(set_entry);
    this->m_e8 = 0;
    this->m_f0 = 0;
    *(s32 *)((s8 *)this + 0xEC) = 0x14;
    *(s32 *)((s8 *)this + 0xF4) = 0;
    this->m_f8 = 0;
    this->m_id = (*(u16 *)&door_key_id_counter)++;
    if (this->set_params[2] < 0) {
        this->set_params[2] = 0;
    }
    if (this->set_params[2] > 9) {
        this->set_params[2] = 9;
    }
    init_collision_body_parts(this, TObjDoorKey__collision_body_parts, 1);
    this->actorFlags |= 0x40000000;
    this->register_object_by_id();
    Vec pos = this->position;
    pos.y += 10.0f;
    this->m_f8 = (saddr)spawn_continuous_particle_effect_with_flags(&pos, 0x60, 0x40);
    this->cursor_action.set_use();
}


void *TObjDoorKey::create(void *set_entry) {
    void *o = (void *)new TObjDoorKey((TObject *)tl_05, (void *)set_entry);
    return o;
}

void TObjDoorKey::free_key() {
    if (door_key_resource_handle != NULL) {
        delete (BmlResource *)door_key_resource_handle;
        door_key_resource_handle = NULL;
    }
    TObjPlayer::free_if_valid((saddr)TObjDoorKey__texture_handle);
    TObjDoorKey__texture_handle = NULL;
    TObjDoorKey__data_805D5C04 = 0;
}

void TObjDoorKey::load_resources() {
    saddr r = (saddr)new BmlResource(5, &TObjDoorKey__resource_descriptor, 0, 0, NULL);
    door_key_resource_handle = (BmlResource *)r;
    TObjDoorKey__texture_handle = load_gvm_texture_file("fe_obj_switch.gvm");
    TObjDoorKey__ginja_model_table[0] = (saddr)get_bml_model((BmlResource *)door_key_resource_handle, 1);
    TObjDoorKey__ginja_model_table[1] = (saddr)get_bml_model((BmlResource *)door_key_resource_handle, 2);
    s32 t = (saddr)get_bml_model((BmlResource *)door_key_resource_handle, 0);
    door_key_id_counter = 0;
    TObjDoorKey__ginja_model_table[2] = t;
    TObjDoorKey__data_805D5C04 = 0;
}

void *TObjEnvSoundGlobal::create(void *rader_map_core) {
    if (TRaderMapCore::is_not_split_screen() == 1) {
        return NULL;
    }
    return new TObjEnvSoundGlobal((TObject *)tl_05, (saddr)rader_map_core);
}

