#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS

#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/render/NinjaUtil.h"

struct BmlResource;
struct NJS_TEXLIST;
struct AnimationMotion;

#include "pso/object/door/TODoorJungleMain.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/object/door/TODoorBase.h"


#include "pso/object/key/TOKeyJungleMain.h"

#include "pso/ui/TLevelSelect.h"

#include "pso/object/door/TODoorAncient01.h"

#include "pso/map/TObjMapCsn.h"

#include "pso/player/TObjPlayer.h"


#include "pso/system/BmlResourceDescriptor.h"

#include "pso/system/SoundEffect.h"

#include "pso/player/TObjPlayer_801AF2F0.h"

#include "pso/player/TObjPlayer_80011014.h"


#include "pso/unk/text_803D96A8.h"

#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"

#include "pso/render/GinjaMaterial.h"

#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/player/PlayerSlots.h"


struct Ids_8029B428 {
    s32 v[3];
};


const char *bm_o_jungle_doormain_model_names[5] = {
    "map_jungle01_light1.gj", "map_jungle01_light2.gj", "map_jungle01_light3.gj", "map_jungle01_tobira.gj", NULL,
};

const char *bm_o_jungle_doormain_motion_names[2] = {"tobira.njm", NULL};

BmlResourceDescriptor bm_o_jungle_doormain_resource_descriptor = {
    "bm_o_jungle_doormain.bml", bm_o_jungle_doormain_model_names, bm_o_jungle_doormain_motion_names, 4, 1,
};

CollisionBody TODoorJungleMain_collision_body_parts[1] = {
    {{0.0f, 0.0f, 0.0f}, 20.0f, 80.0f, 1, 0x10003},
};


// Story-flag ids of the three jungle switches (shared with TOKeyJungleMain).
const s32 TOKeyJungleMain__data_804653C8[3] = {0x46, 0x47, 0x48};

const char *TODoorJungleMain__name = "TODoorJungleMain";

extern "C" u8 *TODoorJungleMain__ct(TODoorJungleMain *arg0, s32 arg1, saddr arg2);

extern "C" {

void TLobby__sub_8029B2A4(void* p);



}
s32 is_any_player_near(saddr arg0);

void clear_story_flag_in_bank(s32 n, s32 flag);

#pragma inline_depth(1)

#pragma auto_inline off

#pragma dont_inline off

struct ByteBlock_3C { u8 bytes[0x3c]; };

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
    s32 angle;
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

BmlResource *TODoorJungleMain__bml_resource;

NJS_TEXLIST *door_jungle_main_gvm_texture;

extern "C" {

u32 init_collision_body_parts(void *, saddr, s32);

void *__ct__10TODoorBaseFP7TObject(void *a0);

extern s32 __vt__16TODoorJungleMain[];


int post_translate_matrix(void *);


s32 draw_ginja_model_with_motion(void *, int, f32);
}

struct Door_8029B524 {
    u8 pad0[0x38];
    u8 xf[0x98];
    u32 flags;
    s32 count;
};


extern "C" {

s32 minimap_render_gate(void *, u32, u16, s32, s32);


s32 release_texture_list(void*);

void free_collision_body_parts(void *);


u8 *TODoorJungleMain__ct(TODoorJungleMain *actor, s32 arg1, saddr set_data) {
    struct CopyStack_8029B924 { u8 bytes[0x3C]; };
    CopyStack_8029B924 copy_storage_8029B924;
    saddr temp_r4;
    __ct__10TODoorBaseFP7TObject(actor);
    *(s32 **)((s8 *)actor + 0x18) = __vt__16TODoorJungleMain;
    *(saddr *)((s8 *)actor + 0) = (saddr) TODoorJungleMain__name;
    ((TODoorJungleMain *)(actor))->apply_object_set_data((void *)set_data);
    actor->motion = (AnimationMotion *)get_bml_motion(TODoorJungleMain__bml_resource, 0);
    actor->animation_step = 1.0f;
    ((TODoorJungleMain *)actor)->animation_end_frame = 0.0f;
    init_collision_body_parts(actor, (saddr) TODoorJungleMain_collision_body_parts, 1);
    ((TObjCollidable *)actor)->refresh_collision_body_centers();
    ((TObjPlayer *)actor)->register_object_by_id();
    actor->view_range = 800.0f;
    temp_r4 = set_data - 4;
    ((TODoorJungleMain *)actor)->model_radius = 120.0f;
    actor->m_d4 = 0;
    actor->m_d8 = 0;
    *(ByteBlock_3C *)(copy_storage_8029B924.bytes) = *(const ByteBlock_3C *)(temp_r4 + 4);
    (*(f32 *)(copy_storage_8029B924.bytes + 0x24)) = 160.0f;
    (*(f32 *)(copy_storage_8029B924.bytes + 0x28)) = 100.0f;
    (*(f32 *)(copy_storage_8029B924.bytes + 0x2C)) = 40.0f;
    (*(s32 *)(copy_storage_8029B924.bytes + 0x30)) = 2;
    actor->m_dc = TObjMapCsn::create(copy_storage_8029B924.bytes);
    return (u8 *)actor;
}

}

TODoorJungleMain::~TODoorJungleMain() {
    if (m_dc != NULL) {
        m_dc->queue_destruction();
        m_dc = NULL;
    }
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}


void TODoorJungleMain::run_task() {
    u8 *arg0 = (u8 *)this;
    GC_Mtx mtx;
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
            if (m_dc != NULL) {
                m_dc->queue_destruction();
                m_dc = NULL;
            }
        } else {
            flag = 1;
        }
        if (*(f32 *)&this->animation_end_frame > (f32)(u32)(*(s32 *)((s8 *)(*(u8 * *)&this->motion) + 4) - 1)) {
            flag = 0;
            *(f32 *)&this->animation_end_frame = (f32)(u32)(*(s32 *)((s8 *)(*(u8 * *)&this->motion) + 4) - 1);
        } else {
            play_persistent_sound(0x43220, arg0, &this->position, 0, 0);
        }
        if (flag != 0) {
            if (++*(s32 *)&this->m_d8 % 30 == 0) {
                Vec a = {40.0f, 0.0f, 0.0f};
                Vec b = {-40.0f, 0.0f, 0.0f};
                set_matrix_identity((u8 *)&mtx);
                translate_matrix_vec3((u8 *)&mtx, (u8 *)&this->position);
                rotate_matrix_y(mtx, this->rotation_y);
                matrix_mult_vec(mtx, &a, &a);
                matrix_mult_vec(mtx, &b, &b);
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
            play_sound_effect(0x4C123, reinterpret_cast<const Vec *>(self->xf), 0, 0);
        }
        if (self->count == 3 && is_any_player_near((saddr)self) != 0) {
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

void TODoorJungleMain::render() {
    Door_8029B428 *self = (Door_8029B428 *)this;
    Ids_8029B428 ids = {{2, 1, 0}};
    s32 i;
    if (self->m8(self->fc0, self->fc4) == 1) {
        TObjFish::set_global_param(door_jungle_main_gvm_texture);
        push_matrix();
        post_translate_matrix(self->xf);
        rotate_matrix_y(NULL, self->angle);
        if (self->flags & 1) {
            draw_ginja_model_with_motion((void *)get_bml_model((BmlResource *)TODoorJungleMain__bml_resource, 3), self->fbc, self->fb4);
        } else {
            draw_ginja_object((void *)get_bml_model((BmlResource *)TODoorJungleMain__bml_resource, 3));
            for (i = 0; i < 3 - self->count; i++) {
                draw_ginja_object((void *)get_bml_model((BmlResource *)TODoorJungleMain__bml_resource, ids.v[i]));
            }
        }
        pop_matrix();
    }
}

void TODoorJungleMain::load_resources() {
    saddr var_r0;
    var_r0 = (saddr)new BmlResource(0x1, &bm_o_jungle_doormain_resource_descriptor, 0, 0, NULL);
    TODoorJungleMain__bml_resource = (BmlResource *)var_r0;
    door_jungle_main_gvm_texture = load_gvm_texture_file("o_jungle_doormain.gvm");
}

void TODoorJungleMain::free_static_resources() {
    if (door_jungle_main_gvm_texture != NULL) {
        release_texture_list(door_jungle_main_gvm_texture);
        safe_free(door_jungle_main_gvm_texture);
        door_jungle_main_gvm_texture = NULL;
    }
    if (TODoorJungleMain__bml_resource != NULL) {
        delete (BmlResource *)TODoorJungleMain__bml_resource;
        TODoorJungleMain__bml_resource = NULL;
    }
}

void *TODoorJungleMain::create(void *set_data) {
    void *o = TObject::operator new(0xE0);
    if (o != NULL) {
        o = ((void * (*)(void *, void *, void *))TODoorJungleMain__ct)(o, tl_05, set_data);
    }
    return o;
}

void TOKeyJungleMain::init_key_slots(void* _w0) {
    s32 i;
    s32 j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            clear_story_flag_in_bank(i, TOKeyJungleMain__data_804653C8[j]);
        }
    }
}

void TLobby__sub_8029B2A4(void* p) { TOKeyJungleMain::init_key_slots(p); }


s32 is_any_player_near(saddr arg0) {
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


void TODoorJungleMain::vfunc_6(s16 *arg1, s32 arg2) {
    if ((arg1 != NULL) && ((s16) *arg1 == 1)) {
        this->door_flags = (s32) (this->door_flags | 1);
        if (arg2 == 0) {
            this->animation_end_frame = (f32) (this->motion->frameCount - 1);
            set_indexed_flags(0, 8);
            if (m_dc != NULL) {
                m_dc->queue_destruction();
                m_dc = NULL;
            }
        }
    }
}

s32 TODoorJungleMain::update_object_view_visibility(f32 farg0, f32 farg1) {
    if (xz_distance_squared(&this->position, &camera_ctrl_instance->pos) < (farg1 * farg1)) {
        return 1;
    }
    return TObjBase::update_object_view_visibility(farg0, farg1);
}

