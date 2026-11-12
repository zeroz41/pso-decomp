#define TOBJECT_OUT_OF_LINE_HELPERS
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
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/task/TObject.h"
#include "pso/object/key/TOKey.h"
#include "pso/player/TUnk_804B6C24.h"

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

s32 TObjDoorKey__ginja_model_table[4];
u32 door_key_resource_handle;
s32 TObjDoorKey__texture_handle;
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
        if (((TUnk_804B6C24 *)cur)->check_value_equals((s32)TObjDoorKey__class_name) != 0 && cur->id == id) {
            return cur;
        }
    }
    return 0;
}

}


struct TObjDoorKeyBase_8018FAEC { char pad[0x18]; };
struct TObjDoorKeyVObj_8018FAEC : TObjDoorKeyBase_8018FAEC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};
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

struct Node_8018FBB8 { s32 pad0; void *f4; };

struct Key_8018FBB8 { u8 pad0[0x38]; u8 f38[0x28]; s32 f60; u8 pad64[0x28]; s32 f8C; u8 pad90[0x60]; s32 fF0; };

struct Node_8018FCD8 { s32 pad0; void *f4; };

struct Key_8018FCD8 { u8 pad0[0x38]; u8 f38[0x28]; s32 f60; u8 pad64[0x28]; s32 f8C; u8 pad90[0x60]; s32 fF0; };

struct Vec_80190020 { f32 x, y, z; };

extern "C" {
void debug_draw_key_id__5TOKeyFv();
s32 get_bml_model(s32, int);
s32 load_resource_from_descriptor(s32, int, void *, int, int, int);
u8 *load_gvm_texture_file(s32 arg0);
void scroll_ginja_mesh_uvs(void *, int, int, int, int);
void PPCSync();
void push_matrix();
void post_translate_matrix(void *);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 actor_frame_tick;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
void *__ct__5TOKeyFP7TObject(TOKey *arg0);
extern s32 __vt__11TObjDoorKey[];
void free_bin_model_request(void*, int);
s32 __dl__7TObjectFPv(void *);
void *__dt__5TOKeyFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);
int is_not_split_screen__13TRaderMapCoreFv(void *);

void TObjDoorKey__sub_8018FAEC(u16 id, u16) {
    Obj_8018FA6C *temp_r3;

    temp_r3 = fn_8018FA6C(id);
    if (temp_r3 != NULL) {
        *(s32 *)((s8 *)temp_r3 + 0xE8) = 1;
    }
}


void TObjDoorKey::render() {

    if (((TObjDoorKeyVObj_8018FAEC*)this)->m8(400.0f, 20.0f) == 0) {
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

s32 TObjDoorKey::draw_active_beam() {
    Key_8018FBB8 *arg0 = (Key_8018FBB8 *)this;
    if (TObjDoorKey__data_805D5C04 != actor_frame_tick) {
        scroll_ginja_mesh_uvs(((Node_8018FBB8 *)TObjDoorKey__ginja_model_table[1])->f4, 0, 0x14, 0xE, 1);
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
    set_constant_material(&door_key_beam_color_table[arg0->f8C]);
    draw_ginja_object((void *)TObjDoorKey__ginja_model_table[1]);
    rotate_matrix_y(0, arg0->fF0);
    s32 *g = TObjDoorKey__ginja_model_table;
    ((TObjDoorJung *)(((Node_8018FBB8 *)g[2])->f4))->free_children((void *)((u16)arg0->f8C));
    draw_ginja_object((void *)g[2]);
    set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

s32 TObjDoorKey::draw_inactive_badge() {
    Key_8018FCD8 *arg0 = (Key_8018FCD8 *)this;
    TObjFish::set_global_param(TObjDoorKey__texture_handle);
    push_matrix();
    post_translate_matrix(arg0->f38);
    rotate_matrix_y(0, arg0->f60);
    draw_ginja_object((void *)TObjDoorKey__ginja_model_table[0]);
    TParticleCtrl::begin_effect_render();
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    set_constant_material(&door_key_beam_color_table[arg0->f8C]);
    s32 *g = TObjDoorKey__ginja_model_table;
    ((TObjDoorJung *)(((Node_8018FCD8 *)g[2])->f4))->free_children((void *)((u16)arg0->f8C));
    draw_ginja_object((void *)g[2]);
    set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TObjDoorKey::debug_draw_key_id() {
    Key_8018FD9C *arg0 = (Key_8018FD9C *)this;
    debug_draw_key_id__5TOKeyFv();
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
        play_sound_effect(0x42D0A, ((u8 *)this) + 0x38, 0, 0);
        break;
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        play_sound_effect(0x4C601, ((u8 *)this) + 0x38, 0, 0);
        break;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_sound_effect(0x4004C601, ((u8 *)this) + 0x38, 0, 0);
        break;
    default:
        play_sound_effect(0x4C60A, ((u8 *)this) + 0x38, 0, 0);
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

}
TObjDoorKey::~TObjDoorKey() {
    ((TObjCollidable *)this)->unregister_object_by_id();
    free_collision_body_parts(this);
    if ((u32) this->m_f8 != 0U) {
        ((TObject *)(*(void **)((s8 *)this + 0xF8)))->queue_destruction();
        this->m_f8 = 0U;
    }
}
TObjDoorKey::TObjDoorKey(TObject *arg1, void *arg2) : TOKey(arg1) {
    *(const char **)((s8 *)this + 0) = TObjDoorKey__class_name;
    init_key(arg2);
    this->m_e8 = 0;
    this->m_f0 = 0;
    *(s32 *)((s8 *)this + 0xEC) = 0x14;
    *(s32 *)((s8 *)this + 0xF4) = 0;
    *(s32 *)&this->m_f8 = 0;
    this->m_id = (*(u16 *)&door_key_id_counter)++;
    if (*(s32 *)&this->set_params[2] < 0) {
        *(s32 *)&this->set_params[2] = 0;
    }
    if (*(s32 *)&this->set_params[2] > 9) {
        *(s32 *)&this->set_params[2] = 9;
    }
    init_collision_body_parts(this, TObjDoorKey__collision_body_parts, 1);
    *(s32 *)&this->actorFlags |= 0x40000000;
    ((TObjPlayer *)this)->register_object_by_id();
    Vec_80190020 pos = *(Vec_80190020 *)((s8 *)this + 0x38);
    pos.y += 10.0f;
    *(s32 *)&this->m_f8 = (s32)spawn_continuous_particle_effect_with_flags(&pos, 0x60, 0x40);
    this->cursor_action.set_use();
}
extern "C" {

void *TObjDoorKey__create(void *arg0) {
    void *o = (void *)new TObjDoorKey((TObject *)tl_05, (void *)arg0);
    return o;
}

void TObjDoorKey::free_key() {
    if ((u32) door_key_resource_handle != 0U) {
        free_bin_model_request((void*)door_key_resource_handle, 1);
        door_key_resource_handle = 0U;
    }
    TObjPlayer::free_if_valid(TObjDoorKey__texture_handle);
    TObjDoorKey__texture_handle = 0;
    TObjDoorKey__data_805D5C04 = 0;
}

void TObjDoorKey::load_resources() {
    s32 r = (int)::operator new(0x440);
    if (r != 0) {
        r = load_resource_from_descriptor(r, 5, &TObjDoorKey__resource_descriptor, 0, 0, 0);
    }
    (*(s32 *)&door_key_resource_handle) = r;
    TObjDoorKey__texture_handle = (s32)load_gvm_texture_file((s32)"fe_obj_switch.gvm");
    TObjDoorKey__ginja_model_table[0] = get_bml_model((*(s32 *)&door_key_resource_handle), 1);
    TObjDoorKey__ginja_model_table[1] = get_bml_model((*(s32 *)&door_key_resource_handle), 2);
    s32 t = get_bml_model((*(s32 *)&door_key_resource_handle), 0);
    door_key_id_counter = 0;
    TObjDoorKey__ginja_model_table[2] = t;
    TObjDoorKey__data_805D5C04 = 0;
}

void * TObjEnvSoundGlobal__create(void *rader_map_core) {
    void *o;
    if (is_not_split_screen__13TRaderMapCoreFv(rader_map_core) == 1) {
        return NULL;
    }
    o = __nw__7TObjectFUl(0x9C);
    if (o != NULL) {
        o = TObjEnvSoundGlobal__ct((u8 *)o, (s32)tl_05, (s32)rader_map_core);
    }
    return o;
}

}
