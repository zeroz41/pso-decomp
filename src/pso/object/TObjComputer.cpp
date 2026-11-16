#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TObjComputer.h"
#include "pso/object/TObjGbAdvance.h"
#include "pso/object/TObjMesBase.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/container/TObjContainerAbeEnemy.h"
#include "pso/map/FloorArea.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/object/key/TOKeyAncient01.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D853C.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/task/TObject.h"


struct Obj_801884A0 {
    const char *unk0;
    u8 pad4[0x18 - 0x4];
    void *vtbl;
    u8 pad1C[0x30 - 0x1C];
    u32 flags30;
    u8 pad34[0x88 - 0x34];
    s32 selector;
    u8 pad8C[0x98 - 0x8C];
    u8 aux98[0xBC - 0x98];
    void *model;
    f32 unkC0;
    s32 unkC4;
};

struct Model_8018807C {
    u32 flags0;
    u8 pad0[8 - 4];
    u8 pos8[0x14 - 8];
    u8 angles14[0x2C - 0x14];
    u8 *sub2c;
};

struct Computer_8018807C {
    u8 pad0[0x38];
    u8 pos38[0x60 - 0x38];
    s32 yaw60;
    u8 pad1[0x88 - 0x64];
    s32 kind88;
    u8 pad2[0xBC - 0x8C];
    Model_8018807C *model;
    f32 time_c0;
    u32 tick_c4;
};


extern "C" {
s32 push_matrix();
s32 post_translate_matrix(void *);
s32 rotate_matrix_y(s32, s32);
s32 get_bml_model(void *, s32);
u32 init_collision_body_parts(void *, void *, s32);
void *TObjMesBase__ct(TObjMesBase *arg0, s32 arg1, s32 arg2);
extern s32 __vt__12TObjComputer[];
void *TObjComputer__ct(void *arg0, void *parent, void *row);
void *load_resource_from_descriptor(void *, int, void *, int, int, int);
}
u8 *load_gvm_texture_file(s32 arg0);
extern "C" {
s32 scroll_ginja_mesh_uvs(void *, s32, s32, u16, s32);
s32 PPCSync();
s32 rotate_matrix_by_node_angles(void *, u32);
extern u32 actor_frame_tick;
void *__nw__7TObjectFUl(int);
extern void *tl_05;
void free_bin_model_request(void*, int);
s32 release_texture_list(void*);
s32 free_collision_body_parts(void *);
s32 vfunc_14__11TObjMesBaseFv();
s32 clear_ref_if_destroyed__11TObjMesBaseFv();

extern s32 __vt__13TObjGbAdvance[];

s32 get_bml_texlist(void *, s32);
u8 *TObjGbAdvance__ct(u8 *arg0, s32 arg1, s32 arg2);
}
void load_computer_resources(void);
const char *fe_obj_tanmatu02_model_names[3] = {"fe_obj_tanmatu02.gj", "fs_obj_tanmatu01.gj", NULL};
const char *fe_obj_tanmatu02_motion_names[1] = {NULL};
BmlResourceDescriptor fe_obj_tanmatu02_resource_descriptor = {
    "fe_obj_tanmatu02.bml", fe_obj_tanmatu02_model_names, fe_obj_tanmatu02_motion_names, 2, 0,
};
const char *bm_obj_gba_model_names[5] = {
    "gba_white_body.gj", "gba_white_disp.gj", "gba_white_footsw.gj", "gba_white_scan.gj", NULL,
};
const char *bm_obj_gba_motion_names[1] = {NULL};
BmlResourceDescriptor bm_obj_gba_resource_descriptor = {
    "bm_obj_gba.bml", bm_obj_gba_model_names, bm_obj_gba_motion_names, 4, 0,
};
const char *fs_obj_tanmatu02_model_names[3] = {"fe_obj_tanmatu02.gj", "fs_obj_tanmatu01.gj", NULL};
const char *fs_obj_tanmatu02_motion_names[1] = {NULL};
BmlResourceDescriptor fs_obj_tanmatu02_resource_descriptor = {
    "fs_obj_tanmatu02.bml", fs_obj_tanmatu02_model_names, fs_obj_tanmatu02_motion_names, 2, 0,
};
const char *TObjComputer__class_name = "TObjComputer";
const char *TObjGbAdvance__class_name = "TObjGbAdvance";
const s16 TObjComputer__data_805DBCD8[2] = {1, 0};

u32 TObjComputer__model_archive;
u32 TObjComputer__texture_gvm_handle;
s16 computer_uv_scroll_phase;
u32 TObjGbAdvance__data_805D5B74;

CollisionBody obj_computer_collision_body_parts = {{0.0f, 7.0f, 0.0f}, 7.0f, 7.0f, 1, 0x30003, {0.0f, 0.0f, 0.0f}, 0.0f};
CollisionBody gb_advance_collision_body_parts = {{0.0f, 20.0f, -10.0f}, 5.0f, 5.0f, 1, 0x30003, {0.0f, 0.0f, 0.0f}, 0.0f};


void *TObjComputer__ct(void *arg0, void *parent, void *row) {
    Obj_801884A0 *self = (Obj_801884A0 *)arg0;
    TObjMesBase__ct((TObjMesBase *)self, (s32)parent, (s32)row);
    self->vtbl = __vt__12TObjComputer;
    self->unk0 = TObjComputer__class_name;
    if (self->selector < 0) {
        self->selector = 0;
    }
    if (self->selector > 1) {
        self->selector = 1;
    }
    if (TObjComputer__model_archive != 0U) {
        self->model = (void *)get_bml_model((void *)TObjComputer__model_archive, TObjComputer__data_805DBCD8[self->selector]);
    } else {
        ((TObject *)self)->queue_destruction();
        return self;
    }
    init_collision_body_parts(self, &obj_computer_collision_body_parts, 1);
    ((TObjPlayer *)self)->actorFlags |= 0x40000000;
    ((TObjPlayer *)self)->register_object_by_id();
    ((TObjComputer *)self)->cursor_action.set_use();
    ((TObjPlayer *)self)->frame = 0.0f;
    self->unkC4 = 0;
    return self;
}

TObjComputer::~TObjComputer() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}

void load_computer_resources(void) {
    void *p;
    switch (get_current_floor_area()) {
    case AREA_CENTRAL_CONTROL_AREA: case AREA_JUNGLE_NORTH: case AREA_JUNGLE_EAST: case AREA_MOUNTAIN: case AREA_SEASIDE: case AREA_SEABED_UPPER: case AREA_SEABED_LOWER:
    case AREA_SEASIDE_NIGHT: case AREA_TOWER:
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, &fs_obj_tanmatu02_resource_descriptor, 0, 0, 0);
        }
        TObjComputer__model_archive = (u32) p;
        TObjComputer__texture_gvm_handle = (u32)load_gvm_texture_file((s32)"fs_obj_tanmatu02.gvm");
        computer_uv_scroll_phase = 0;
        break;
    default:
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, &fe_obj_tanmatu02_resource_descriptor, 0, 0, 0);
        }
        TObjComputer__model_archive = (u32) p;
        TObjComputer__texture_gvm_handle = (u32)load_gvm_texture_file((s32)"fe_obj_computer.gvm");
        computer_uv_scroll_phase = 1;
        break;
    }
}

void TObjComputer::free_resources() {
    if ((u32) TObjComputer__texture_gvm_handle != 0U) {
        release_texture_list((void*)TObjComputer__texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjComputer__texture_gvm_handle);
        TObjComputer__texture_gvm_handle = 0U;
    }
    if ((u32) TObjComputer__model_archive != 0U) {
        free_bin_model_request((void*)TObjComputer__model_archive, 1);
        TObjComputer__model_archive = 0U;
    }
}

void *TObjComputer::create() {
    void *o = __nw__7TObjectFUl(0xC8);
    if (o != NULL) {
        o = TObjComputer__ct(o, tl_05, this);
    }
    return o;
}

void TObjComputer::vfunc_14() {
    vfunc_14__11TObjMesBaseFv();
    if ((s32) this->messageLabel != 0) {
        submit_cursor_candidate(this, -1);
    }
    this->uv_scroll_time += 0.2f;
}

void TObjComputer::clear_ref_if_destroyed() {
    clear_ref_if_destroyed__11TObjMesBaseFv();
    this->uv_scroll_time += 0.2f;
}

void TObjComputer::render() {
    if (this->update_object_view_visibility(400.0f, 20.0f) != 0) {
        draw_model();
    }
}

s32 TObjComputer::draw_model() {
    Computer_8018807C *self = (Computer_8018807C *)this;
    if (self->model == NULL) {
        return;
    }
    TObjFish::set_global_param(TObjComputer__texture_gvm_handle);
    push_matrix();
    post_translate_matrix(self->pos38);
    rotate_matrix_y(0, self->yaw60);
    if (TObjComputer__data_805DBCD8[self->kind88] == 1) {
        u32 tick = actor_frame_tick;
        if (tick != self->tick_c4 && self->time_c0 >= 1.0f) {
            self->tick_c4 = tick;
            scroll_ginja_mesh_uvs(*(void **)((s8 *)self->model->sub2c + 4), 0, (s32)self->time_c0, (*(u16 *)&computer_uv_scroll_phase), 1);
            PPCSync();
            f32 time = self->time_c0;
            self->time_c0 = time - (f32)(s32)time;
        }
        post_translate_matrix(self->model->pos8);
        rotate_matrix_by_node_angles(self->model->angles14, self->model->flags0 & 0x20);
        draw_ginja_object(self->model);
        if (self->model->sub2c != NULL) {
            TParticleCtrl::begin_effect_render();
            draw_ginja_object(self->model->sub2c);
            TParticleCtrl::end_effect_render();
        }
    } else {
        draw_ginja_object(self->model);
    }
    pop_matrix();
}

void TObjComputer::debug_draw_label() {
    this->TObjMesBase::debug_draw_label();
    this->set_params[1] = this->set_params[1] % 2;
    this->m_bc = get_bml_model((void *)TObjComputer__model_archive, TObjComputer__data_805DBCD8[this->set_params[1]]);
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130021, "<- MODEL SELECT");
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

u8 *TObjGbAdvance__ct(u8 *mes_base, s32 arg1, s32 arg2) {
    TObjMesBase__ct((TObjMesBase *)mes_base, arg1, arg2);
    *(s32 **)((s8 *)mes_base + 0x18) = __vt__13TObjGbAdvance;
    ((TObjGbAdvance *)mes_base)->m_name = TObjGbAdvance__class_name;
    init_collision_body_parts(mes_base, &gb_advance_collision_body_parts, 1);
    ((TObjGbAdvance *)mes_base)->actorFlags = (s32) (((TObjGbAdvance *)mes_base)->actorFlags | 0x40000000);
    ((TObjPlayer *)mes_base)->register_object_by_id();
    ((TObjGbAdvance *)mes_base)->cursor_action.set_use();
    return mes_base;
}

TObjGbAdvance::~TObjGbAdvance() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjGbAdvance::vfunc_14() {
    vfunc_14__11TObjMesBaseFv();
    if ((s32) this->messageLabel != 0) {
        submit_cursor_candidate(this, -1);
    }
}

void TObjGbAdvance::render() {
    if (this->update_object_view_visibility(400.0f, 20.0f) != 0) {
        TObjFish::set_global_param(get_bml_texlist((void *)TObjGbAdvance__data_805D5B74, 0));
        push_matrix();
        post_translate_matrix(&this->position);
        rotate_matrix_y(0, this->rotation_y);
        draw_ginja_object((void *)get_bml_model((void *)TObjGbAdvance__data_805D5B74, 0));
        draw_ginja_object((void *)get_bml_model((void *)TObjGbAdvance__data_805D5B74, 1));
        draw_ginja_object((void *)get_bml_model((void *)TObjGbAdvance__data_805D5B74, 2));
        draw_ginja_object((void *)get_bml_model((void *)TObjGbAdvance__data_805D5B74, 3));
        pop_matrix();
    }
}

void TObjGbAdvance::load_resource_instance() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &bm_obj_gba_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TObjGbAdvance__data_805D5B74) = var_r0;
}

void TObjGbAdvance::free_shared_data() {
    if ((u32) TObjGbAdvance__data_805D5B74 != 0U) {
        free_bin_model_request((void*)TObjGbAdvance__data_805D5B74, 1);
        TObjGbAdvance__data_805D5B74 = 0U;
    }
}
