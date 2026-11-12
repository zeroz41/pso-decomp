#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/door/TODoorJungleMain.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/door/TODoorBase.h"
#include "pso/object/door/TODoorJungleMain.h"
#include "pso/object/key/TOKeyJungleMain.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/object/door/TODoorAncient01.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/task/TObject.h"

struct Vec_8029B640 { s32 x, y, z; };
struct Ids_8029B428 {
    s32 v[3];
};

extern "C" {
extern char lbl_80465340[];
extern char lbl_80465358[];
extern char lbl_80465370[];
extern char lbl_80465388[];
extern char lbl_804653A0[];
extern char lbl_804653AC[];
const char *bm_o_jungle_doormain_model_names[5] = {
    lbl_80465340, lbl_80465358, lbl_80465370, lbl_80465388, NULL,
};
__declspec(section ".data") const char *bm_o_jungle_doormain_motion_names[2] = {lbl_804653A0, NULL};
BmlResourceDescriptor bm_o_jungle_doormain_resource_descriptor = {
    lbl_804653AC, bm_o_jungle_doormain_model_names, bm_o_jungle_doormain_motion_names, 4, 1,
};
CollisionBody TODoorJungleMain_collision_body_parts[1] = {
    {{0.0f, 0.0f, 0.0f}, 20.0f, 80.0f, 1, 0x10003},
};
extern s32 TODoorJungleMain__name;
extern Vec_8029B640 lbl_804653E8;
extern Vec_8029B640 lbl_804653F4;
extern Ids_8029B428 door_jungle_main_ids;
}

extern "C" u8 *TODoorJungleMain__ct(TODoorJungleMain *arg0, s32 arg1, s32 arg2);

extern "C" {

s32 update_object_view_visibility__16TODoorJungleMainFff(s32 arg0, f32 farg0, f32 farg1);
f32 xz_distance_squared(s32, s32);
s32 update_object_view_visibility__8TObjBaseFff(s32, f32, f32);

extern s32 camera_ctrl_instance;

s32 TODoorJungleMain::update_object_view_visibility(f32 farg0, f32 farg1) {
    s32 arg0 = (s32)this;
    if (xz_distance_squared(arg0 + 0x38, camera_ctrl_instance + 0x178) < (farg1 * farg1)) {
        return 1;
    }
    return update_object_view_visibility__8TObjBaseFff(arg0, farg0, farg1);
}

void TODoorJungleMain::vfunc_6(s16 *arg1, s32 arg2) {
    if ((arg1 != NULL) && ((s16) *arg1 == 1)) {
        this->door_flags = (s32) (this->door_flags | 1);
        if (arg2 == 0) {
            *(f32 *)&this->animation_end_frame = (f32) (*(u32 *)((s8 *)(*(void * *)&this->motion) + 4) - 1);
            set_indexed_flags(0, 8);
            if ((u32) this->m_dc != 0U) {
                ((TObject *)(*(void * *)&this->m_dc))->queue_destruction();
                this->m_dc = 0U;
            }
        }
    }
}

}
s32 is_any_player_near(s32 arg0);
s32 is_any_player_near(s32 arg0) {
  f32 temp_f31;
  s32 temp_r31;
  s32 var_r29;
  s32 new_var;
  u8 *player;
  temp_f31 = 2500.0f;
  var_r29 = 0;
  loop_1:
  player = (u8 *) get_player_by_client_id(var_r29);
  if (player != 0)
  {
    temp_r31 = ((TObjPlayer *)player)->get_floor();
    new_var = get_current_floor();
    if ((new_var == temp_r31) && (((f32 (*)(void *, void *))xz_distance_squared)((void *)(player + 0x38), (void *)(arg0 + 0x38)) < temp_f31))
    {
      return 1;
    }
  }
  var_r29 += 1;
  if (var_r29 >= 4)
  {
    return 0;
  }
  goto loop_1;
}

void clear_story_flag_in_bank(s32 n, s32 flag);
extern "C" {
void TLobby__sub_8029B2A4(void* p);
void *TODoorJungleMain__create(void *arg0);
void *__nw__7TObjectFUl(int);

void TLobby__sub_8029B2A4(void* p) { TOKeyJungleMain::init_key_slots(p); }

extern void *tl_05;

void TOKeyJungleMain::init_key_slots(void* _w0) {
    s32 i;
    s32 j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            clear_story_flag_in_bank(i, TOKeyJungleMain__data_804653C8[j]);
        }
    }
}

void *TODoorJungleMain__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xE0);
    if (o != NULL) {
        o = ((void * (*)(void *, void *, void *))TODoorJungleMain__ct)(o, tl_05, arg0);
    }
    return o;
}
}

struct RecoveredGlobal_8019A9B8_lbl_80446184 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8019A9B8_lbl_804B8F60 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8019A880_lbl_804B8F70 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8019A880___vt__8TObjTank {
    s32 value;
    u8 remaining[0x38];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_3C { u8 bytes[0x3c]; };

struct RecoveredGlobal_8029B924_lbl_804DC014 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8029B924___vt__16TODoorJungleMain {
    s32 value;
    u8 remaining[0x54];
};

struct VBase_8029B428 { char pad[0x18]; };

struct VObj_8029B428 : VBase_8029B428 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Door_8029B428 : VObj_8029B428 {
    u8 pad1c[0x38 - 0x1C];
    u8 xf[0x28];
    s32 f60;
    u8 pad64[0xB4 - 0x64];
    f32 fb4;
    u8 padb8[4];
    s32 fbc;
    f32 fc0;
    f32 fc4;
    u8 padc8[8];
    u32 flags;
    s32 count;
};

extern "C" {
u32 TODoorJungleMain__bml_resource;
u32 door_jungle_main_gvm_texture;
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
u8 * load_gvm_texture_file(s32);
s32 get_bml_motion(void *, s32);
u32 init_collision_body_parts(void *, s32, s32);
void *__ct__10TODoorBaseFP7TObject(void *a0);
extern s32 __vt__16TODoorJungleMain[];
void *get_bml_model(u32, int);
s32 rotate_matrix_y(int, int);
int push_matrix(void *);
int post_translate_matrix(void *);
void *set_global_param__8TObjFishFl(void *);
s32 draw_ginja_model_with_motion(void *, int, f32);
}
struct Door_8029B524 {
    u8 pad0[0x38];
    u8 xf[0x98];
    u32 flags;
    s32 count;
};

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct Mtx_8029B640 { f32 m[12]; };

extern "C" {
extern s32 game_difficulty_selection;
s32 minimap_render_gate(void *, u32, u16, s32, s32);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
s32 matrix_mult_vec(void *, void *, void *);

#pragma pop

void *__dt__16TODoorJungleMainFv(void *arg0, s16 arg1);
void free_bin_model_request(void*, int);
s32 release_texture_list(void*);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);

void TODoorJungleMain::free_static_resources() {
    if ((u32) door_jungle_main_gvm_texture != 0U) {
        release_texture_list((void*)door_jungle_main_gvm_texture);
        TAdSinglePlyChrSelectGC::safe_free(door_jungle_main_gvm_texture);
        door_jungle_main_gvm_texture = 0U;
    }
    if ((u32) TODoorJungleMain__bml_resource != 0U) {
        free_bin_model_request((void*)TODoorJungleMain__bml_resource, 1);
        TODoorJungleMain__bml_resource = 0U;
    }
}

typedef char RecoveredGlobal_8019A880_lbl_804B8F70_size[sizeof(RecoveredGlobal_8019A880_lbl_804B8F70) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8019A880___vt__8TObjTank_size[sizeof(RecoveredGlobal_8019A880___vt__8TObjTank) == 0x3C ? 1 : -1];
typedef char RecoveredGlobal_8019A9B8_lbl_80446184_size[sizeof(RecoveredGlobal_8019A9B8_lbl_80446184) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_8019A9B8_lbl_804B8F60_size[sizeof(RecoveredGlobal_8019A9B8_lbl_804B8F60) == 0x10 ? 1 : -1];
void TODoorJungleMain::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 0x1, &bm_o_jungle_doormain_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TODoorJungleMain__bml_resource) = var_r0;
    (*(u8 * *)&door_jungle_main_gvm_texture) = load_gvm_texture_file((s32) "o_jungle_doormain.gvm");
}

void TODoorJungleMain::render() {
    Door_8029B428 *self = (Door_8029B428 *)this;
    Ids_8029B428 ids = door_jungle_main_ids;
    s32 i;
    if (self->m8(self->fc0, self->fc4) == 1) {
        push_matrix(set_global_param__8TObjFishFl((void *)door_jungle_main_gvm_texture));
        post_translate_matrix(self->xf);
        rotate_matrix_y(0, self->f60);
        if (self->flags & 1) {
            draw_ginja_model_with_motion(get_bml_model(TODoorJungleMain__bml_resource, 3), self->fbc, self->fb4);
        } else {
            draw_ginja_object(get_bml_model(TODoorJungleMain__bml_resource, 3));
            for (i = 0; i < 3 - self->count; i++) {
                draw_ginja_object(get_bml_model(TODoorJungleMain__bml_resource, ids.v[i]));
            }
        }
        pop_matrix();
    }
}

void TODoorJungleMain::update_door_switch_state() {
    Door_8029B524 *self = (Door_8029B524 *)this;
    s16 sp8;
    s32 lvl;
    s32 prev;
    s32 i;

    if (!(self->flags & 1)) {
        lvl = game_difficulty_selection;
        prev = self->count;
        self->count = 0;
        for (i = 0; i < 3; i++) {
            if (TLevelSelect::get_difficulty_flag_bit(lvl, TOKeyJungleMain__data_804653C8[i]) != 0) {
                self->count++;
            }
        }
        if (self->count > 0 && self->count != prev) {
            play_sound_effect(0x4C123, self->xf, 0, 0);
        }
        if (self->count == 3 && is_any_player_near((s32)self) != 0) {
            self->flags |= 1;
        } else {
            self->flags &= ~1;
        }
        if ((self->flags & 1) && ((TObjCollidable *)self)->access_object_saved_state(&sp8, 1) == 1) {
            sp8 = 1;
            ((TObjCollidable *)self)->send_object_state_update(&sp8);
        }
    }
}
void TODoorJungleMain::run_task() {
    u8 *arg0 = (u8 *)this;
    Vec_8029B640 a;
    Vec_8029B640 b;
    Mtx_8029B640 mtx;
    s32 flag;
    f32 t;

    this->update_door_switch_state();
    if (this->door_flags & 1) {
        flag = 0;
        *(f32 *)&this->animation_end_frame += this->animation_step;
        t = *(f32 *)&this->animation_end_frame;
        if ((f32)(u32)(*(s32 *)((s8 *)(*(u8 * *)&this->motion) + 4) - 1) - 70.0f < t &&
            t < (f32)(u32)(*(s32 *)((s8 *)(*(u8 * *)&this->motion) + 4) - 1)) {
            ((TObjCollidable *)arg0)->set_indexed_flags(0, 8);
            if (*(void * *)&this->m_dc != NULL) {
                ((TObject *)(*(void * *)&this->m_dc))->queue_destruction();
                *(void * *)&this->m_dc = NULL;
            }
        } else {
            flag = 1;
        }
        if (*(f32 *)&this->animation_end_frame > (f32)(u32)(*(s32 *)((s8 *)(*(u8 * *)&this->motion) + 4) - 1)) {
            flag = 0;
            *(f32 *)&this->animation_end_frame = (f32)(u32)(*(s32 *)((s8 *)(*(u8 * *)&this->motion) + 4) - 1);
        } else {
            play_persistent_sound(0x43220, (s32)arg0, (u32)&this->position, 0, 0);
        }
        if (flag != 0) {
            if (++*(s32 *)&this->m_d8 % 30 == 0) {
                a = lbl_804653E8;
                b = lbl_804653F4;
                set_matrix_identity((u8 *)&mtx);
                translate_matrix_vec3((u8 *)&mtx, (u8 *)&this->position);
                rotate_matrix_y((int)&mtx, this->rotation_y);
                matrix_mult_vec(&mtx, &a, &a);
                matrix_mult_vec(&mtx, &b, &b);
                spawn_particle_effect_with_flags(&a, 0x229, 0x800);
                spawn_particle_effect_with_flags(&b, 0x229, 0x800);
            }
        }
        minimap_render_gate((u8 *)&this->position, 0xFF00FF00, this->rotation_y, 0, 0);
    } else {
        minimap_render_gate((u8 *)&this->position, 0xFFFF0000, this->rotation_y, 0, 0);
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 8);
    }
}
}
TODoorJungleMain::~TODoorJungleMain() {
    if (*(void **)((s8 *)this + 0xDC) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0xDC)))->queue_destruction(); this->m_dc = 0; }
    ((TObjCollidable *)this)->unregister_object_by_id();
    free_collision_body_parts(this);
}
extern "C" {
typedef char RecoveredGlobal_8029B924_lbl_804DC014_size[sizeof(RecoveredGlobal_8029B924_lbl_804DC014) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8029B924___vt__16TODoorJungleMain_size[sizeof(RecoveredGlobal_8029B924___vt__16TODoorJungleMain) == 0x58 ? 1 : -1];
u8 *TODoorJungleMain__ct(TODoorJungleMain *arg0, s32 arg1, s32 arg2) {
    struct CopyStack_8029B924 { u8 bytes[0x3C]; };
    CopyStack_8029B924 copy_storage_8029B924;
    s32 temp_r4;
    __ct__10TODoorBaseFP7TObject(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8029B924___vt__16TODoorJungleMain *)&__vt__16TODoorJungleMain).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TODoorJungleMain__name;
    ((TODoorJungleMain *)(arg0))->apply_object_set_data((void *)arg2);
    arg0->motion = (AnimationMotion *)get_bml_motion((*(u8 * *)&TODoorJungleMain__bml_resource), 0);
    arg0->animation_step = 1.0f;
    *(f32 *)((s8 *)arg0 + 0xB4) = 0.0f;
    init_collision_body_parts(arg0, (s32) TODoorJungleMain_collision_body_parts, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    arg0->view_range = 800.0f;
    temp_r4 = arg2 - 4;
    *(f32 *)((s8 *)arg0 + 0xC4) = 120.0f;
    arg0->m_d4 = 0;
    arg0->m_d8 = 0;
    *(ByteBlock_3C *)(copy_storage_8029B924.bytes) = *(const ByteBlock_3C *)(temp_r4 + 4);
    (*(f32 *)(copy_storage_8029B924.bytes + 0x24)) = 160.0f;
    (*(f32 *)(copy_storage_8029B924.bytes + 0x28)) = 100.0f;
    (*(f32 *)(copy_storage_8029B924.bytes + 0x2C)) = 40.0f;
    (*(s32 *)(copy_storage_8029B924.bytes + 0x30)) = 2;
    arg0->m_dc = TObjMapCsn::create((s32)copy_storage_8029B924.bytes);
    return (u8 *)arg0;
}

}
