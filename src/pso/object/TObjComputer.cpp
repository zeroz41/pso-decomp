#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/object/TObjComputer.h"
#include "pso/object/TObjMotion.h"
#include "pso/item/TObjContainerAbeEnemy.h"
#include "pso/map/FloorArea.h"

#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKeyAncient01.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"

#define CAT2(a, b) a##b
#define CAT(a, b) CAT2(a, b)
#define PADV4 virtual void CAT(pa, __LINE__)(); virtual void CAT(pb, __LINE__)(); virtual void CAT(pc, __LINE__)(); virtual void CAT(pd, __LINE__)();
struct Base_TOC_801881D4 { char pad[0x18]; };
struct V_TOC_801881D4 : Base_TOC_801881D4 {
    PADV4
    PADV4
    virtual s32 m8(f32, f32);
};

struct Obj_80188884 { u8 pad0[0x38]; u8 pos[0x28]; s32 id; u8 pad1[0x326 - 0x64]; s16 state; };

struct Obj_80188814 { u8 pad0[0x38]; u8 pos[0x4c]; s32 id; };

struct Obj_801884A0 {
    s32 unk0;
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

struct Obj_80188768 { u8 pad0[0x1C]; u16 f1C; u8 pad1[0x62]; u32 f80; s32 f84; };

struct Pkt_80188768 { u16 a; u16 b; s32 c; s32 d; s32 e; };

struct Vec_8018860C { f32 x, y, z; };

struct ChipParam_8018860C {
    u32 x00;
    u32 x04;
    u32 x08;
    Vec_8018860C pos;
    u8 pad18[0x20];
    f32 y2;
    u32 pad3C;
    s32 res;
    s32 x44;
    u32 x48;
};

struct Obj_8018860C {
    u8 pad[0x38];
    Vec_8018860C pos;
    u8 pad44[0x326 - 0x44];
    s16 state;
};

extern "C" {
void queue_destruction__7TObjectFv(void *arg0);
s32 push_matrix();
s32 post_translate_matrix(void *);
s32 rotate_matrix_y(s32, s32);
void draw_ginja_box_tree(void);
s32 pop_matrix();
extern void *container_breakup_model_archive;
extern s32 lbl_805D5B8C;
void debug_printf_at(s32 id, const char *fmt, ...);
extern char lbl_80444EF4[];
extern const f32 lbl_805DBCF8;
s32 get_bml_model(void *, s32);
u32 init_collision_body_parts(void *, void *, s32);
void *TObjMesBase__ct(TObjMesBase *arg0, s32 arg1, s32 arg2);
extern s32 obj_computer_collision_body_parts[];
extern s32 __vt__12TObjComputer[];
extern s32 lbl_805D32CC;
extern u32 TObjComputer__model_archive;
extern s16 TObjComputer__data_805DBCD8[2];
extern const f32 lbl_805DBCEC;
void *TObjComputer__ct(void *arg0, void *parent, void *row);
void *load_resource_from_descriptor(void *, int, void *, int, int, int);
u8 *load_gvm_texture_file(s32 arg0);
s32 scroll_ginja_mesh_uvs(void *, s32, s32, u16, s32);
s32 PPCSync();
s32 rotate_matrix_by_node_angles(void *, u32);
void draw_ginja_object(void *child);
extern u32 actor_frame_tick;
extern const f32 lbl_805DBCE4;
s32 get_current_floor();
extern s32 local_client_id;
extern const f32 lbl_805DBCF4;
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
u8 *__ct__8TObjChipFP7TObjectP14TObjChipParams(u8 *arg0, u8 *arg1, u8 *arg2);
}
extern s32 fe_obj_tanmatu02_resource_descriptor[];
extern s32 fs_obj_tanmatu02_resource_descriptor[];
extern u32 TObjComputer__texture_gvm_handle;
extern s16 computer_uv_scroll_phase;
void load_computer_resources(void);
void play_container_break_sound(s32 arg0);
extern "C" {
s32 dispatch_fish_event__6TLobbyFPv(void *a0);
void *__nw__7TObjectFUl(int);
extern ChipParam_8018860C lbl_80444E5C;
extern ChipParam_8018860C lbl_80444EA8;
extern void *tl_05;
void TObjContainerAbeEnemy__vt77(const Obj_8018860C *self);
void TLobby__sub_8001FE7C(void*, int);
s32 release_texture_list(void*);
s32 free_collision_body_parts(void *);
s32 vfunc_14__11TObjMesBaseFv();
s32 submit_cursor_candidate(void *, s32);
s32 clear_ref_if_destroyed__11TObjMesBaseFv();

extern const f32 lbl_805DBCDC;
extern const f32 lbl_805DBCE0;

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
        if (tick != self->tick_c4 && self->time_c0 >= lbl_805DBCE4) {
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

void TObjComputer::render() {
    u8 *arg0 = (u8 *)this;
    if (((V_TOC_801881D4 *)arg0)->m8(lbl_805DBCDC, lbl_805DBCE0) != 0) {
        draw_model();
    }
}

extern f32 lbl_805DBCE8;

void TObjComputer::clear_ref_if_destroyed() {
    clear_ref_if_destroyed__11TObjMesBaseFv();
    *(f32 *)&this->_padC0 = (f32) (*(f32 *)&this->_padC0 + lbl_805DBCE8);
}

void TObjComputer::vfunc_14() {
    vfunc_14__11TObjMesBaseFv();
    if ((s32) this->messageLabel != 0) {
        submit_cursor_candidate(this, -1);
    }
    *(f32 *)&this->_padC0 = (f32) (*(f32 *)&this->_padC0 + lbl_805DBCE8);
}

void *TObjComputer::create() {
    void *o = __nw__7TObjectFUl(0xC8);
    if (o != NULL) {
        o = TObjComputer__ct(o, tl_05, this);
    }
    return o;
}

void TObjComputer::free_resources() {
    if ((u32) TObjComputer__texture_gvm_handle != 0U) {
        release_texture_list((void*)TObjComputer__texture_gvm_handle);
        TAdSinglePlyChrSelectGC::safe_free(TObjComputer__texture_gvm_handle);
        TObjComputer__texture_gvm_handle = 0U;
    }
    if ((u32) TObjComputer__model_archive != 0U) {
        TLobby__sub_8001FE7C((void*)TObjComputer__model_archive, 1);
        TObjComputer__model_archive = 0U;
    }
}
}

void load_computer_resources(void) {
    void *p;
    switch (get_current_floor_area()) {
    case AREA_CENTRAL_CONTROL_AREA: case AREA_JUNGLE_NORTH: case AREA_JUNGLE_EAST: case AREA_MOUNTAIN: case AREA_SEASIDE: case AREA_SEABED_UPPER: case AREA_SEABED_LOWER:
    case AREA_SEASIDE_NIGHT: case AREA_TOWER:
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, fs_obj_tanmatu02_resource_descriptor, 0, 0, 0);
        }
        TObjComputer__model_archive = (u32) p;
        TObjComputer__texture_gvm_handle = (u32)load_gvm_texture_file((s32)"fs_obj_tanmatu02.gvm");
        computer_uv_scroll_phase = 0;
        break;
    default:
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, fe_obj_tanmatu02_resource_descriptor, 0, 0, 0);
        }
        TObjComputer__model_archive = (u32) p;
        TObjComputer__texture_gvm_handle = (u32)load_gvm_texture_file((s32)"fe_obj_computer.gvm");
        computer_uv_scroll_phase = 1;
        break;
    }
}

TObjComputer::~TObjComputer() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TObjComputer__ct(void *arg0, void *parent, void *row) {
    Obj_801884A0 *self = (Obj_801884A0 *)arg0;
    TObjMesBase__ct((TObjMesBase *)self, (s32)parent, (s32)row);
    self->vtbl = __vt__12TObjComputer;
    self->unk0 = lbl_805D32CC;
    if (self->selector < 0) {
        self->selector = 0;
    }
    if (self->selector > 1) {
        self->selector = 1;
    }
    if (TObjComputer__model_archive != 0U) {
        self->model = (void *)get_bml_model((void *)TObjComputer__model_archive, TObjComputer__data_805DBCD8[self->selector]);
    } else {
        queue_destruction__7TObjectFv(self);
        return self;
    }
    init_collision_body_parts(self, obj_computer_collision_body_parts, 1);
    ((TObjPlayer *)self)->actorFlags |= 0x40000000;
    ((TObjPlayer *)self)->register_object_by_id();
    ((TObjComputer *)self)->cursor_action.set_use();
    ((TObjPlayer *)self)->frame = lbl_805DBCEC;
    self->unkC4 = 0;
    return self;
}
