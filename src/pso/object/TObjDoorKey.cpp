#include "types.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/object/TObjEnvSoundGlobal.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/TObjDoorJung.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TObjDoorKey.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOKeyAncient01.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"

extern char lbl_80445650[];
extern char lbl_8044566C[];
extern char lbl_80445684[];
extern char lbl_804456A0[];
extern const char *abeno_fs_obj001_fosuno_model_names[4];
extern BmlResourceDescriptor TObjDoorKey__resource_descriptor;
extern const char *abeno_fs_obj001_fosuno_motion_names[1];

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
void debug_printf_at(int, void *, ...);
extern u8 lbl_804456C8[];
extern const f32 lbl_805DBE08;
s32 get_bml_model(s32, int);
s32 load_resource_from_descriptor(s32, int, void *, int, int, int);
u8 *load_gvm_texture_file(s32 arg0);
extern u8 lbl_804456D8[];
extern s32 TObjDoorKey__ginja_model_table[];
extern u32 door_key_resource_handle;
extern s32 TObjDoorKey__texture_handle;
extern s16 door_key_id_counter;
extern s32 TObjDoorKey__data_805D5C04;
void scroll_ginja_mesh_uvs(void *, int, int, int, int);
void PPCSync();
void rotate_matrix_y(int, int);
void push_matrix();
void post_translate_matrix(void *);
extern u8 chunk_material_color_half_alpha_f32[];
extern u8 door_key_beam_color_table[][0x10];
extern s32 actor_frame_tick;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
void play_sound_effect(int, void *, int, int);
void *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
s32 init_collision_body_parts(void *, void *, int);
s32 init_key__5TOKeyFPv(void *, void *);
void *__ct__5TOKeyFP7TObject(TOKey *arg0);
extern u8 TObjDoorKey__collision_body_parts[];
extern s32 __vt__11TObjDoorKey[];
extern s32 TObjDoorKey__class_name;
extern const f32 lbl_805DBE0C;
void TLobby__sub_8001FE7C(void*, int);
int update_armed_switch__5TOKeyFv(void*);
s32 free_collision_body_parts(void *);
int submit_cursor_candidate(void*, int);
s32 __dl__7TObjectFPv(void *);
void *__dt__5TOKeyFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);
void *fn_8018FA6C();
int is_not_split_screen__13TRaderMapCoreFv(void *);

void TObjDoorKey__sub_8018FAEC(void) {
    void *temp_r3;

    temp_r3 = fn_8018FA6C();
    if (temp_r3 != NULL) {
        *(s32 *)((s8 *)temp_r3 + 0xE8) = 1;
    }
}

extern const f32 lbl_805DBE00;
extern const f32 lbl_805DBE04;

void TObjDoorKey::render() {

    if (((TObjDoorKeyVObj_8018FAEC*)this)->m8(lbl_805DBE00, lbl_805DBE04) == 0) {
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
    set_constant_material((const NJS_ARGB *)(((f32 *)door_key_beam_color_table[arg0->f8C])));
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
    set_constant_material((const NJS_ARGB *)(((f32 *)door_key_beam_color_table[arg0->f8C])));
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
    arg0->f78 = arg0->f78 + lbl_805DBE08;
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130022, lbl_804456C8, arg0->f8C);
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
void TObjDoorKey::update_armed_switch() { update_armed_switch__5TOKeyFv(this); }

void TObjDoorKey::run_task() {
    struct VObj_8018FF74_8018FAEC *o = (struct VObj_8018FF74_8018FAEC *)this;
    o->m22();
}

void *__dt__11TObjDoorKeyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TObjDoorKey;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        if ((u32) ((TObjDoorKey *)arg0)->m_f8 != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0xF8));
            ((TObjDoorKey *)arg0)->m_f8 = 0U;
        }
        __dt__5TOKeyFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_05;

void *TObjDoorKey__ct(TObjDoorKey *door_key, void *arg1, void *arg2) {
    __ct__5TOKeyFP7TObject(door_key);
    *(u8 **)((s8 *)door_key + 0x18) = ((u8 *)&__vt__11TObjDoorKey);
    *(s32 *)((s8 *)door_key + 0) = TObjDoorKey__class_name;
    init_key__5TOKeyFPv(door_key, arg2);
    door_key->m_e8 = 0;
    door_key->m_f0 = 0;
    *(s32 *)((s8 *)door_key + 0xEC) = 0x14;
    *(s32 *)((s8 *)door_key + 0xF4) = 0;
    *(s32 *)&door_key->m_f8 = 0;
    door_key->m_id = (*(u16 *)&door_key_id_counter)++;
    if (*(s32 *)&door_key->set_params[2] < 0) {
        *(s32 *)&door_key->set_params[2] = 0;
    }
    if (*(s32 *)&door_key->set_params[2] > 9) {
        *(s32 *)&door_key->set_params[2] = 9;
    }
    init_collision_body_parts(door_key, TObjDoorKey__collision_body_parts, 1);
    *(s32 *)&door_key->actorFlags |= 0x40000000;
    ((TObjPlayer *)door_key)->register_object_by_id();
    Vec_80190020 pos = *(Vec_80190020 *)((s8 *)door_key + 0x38);
    pos.y += lbl_805DBE0C;
    *(s32 *)&door_key->m_f8 = (s32)spawn_continuous_particle_effect_with_flags(&pos, 0x60, 0x40);
    door_key->cursor_action.set_use();
    return door_key;
}

void *TObjDoorKey__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xFC);
    if (o != NULL) {
        o = TObjDoorKey__ct((TObjDoorKey *)o, tl_05, arg0);
    }
    return o;
}

void TObjDoorKey::free_key() {
    if ((u32) door_key_resource_handle != 0U) {
        TLobby__sub_8001FE7C((void*)door_key_resource_handle, 1);
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
    TObjDoorKey__texture_handle = (s32)load_gvm_texture_file((s32)lbl_804456D8);
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

__declspec(section ".data") const char *abeno_fs_obj001_fosuno_model_names[4] = { lbl_80445650, lbl_8044566C, lbl_80445684, NULL };
BmlResourceDescriptor TObjDoorKey__resource_descriptor = { lbl_804456A0, abeno_fs_obj001_fosuno_model_names, abeno_fs_obj001_fosuno_motion_names, 3, 0 };
__declspec(section ".sdata") const char *abeno_fs_obj001_fosuno_motion_names[1] = { NULL };
}
