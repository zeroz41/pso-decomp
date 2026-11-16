#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/RenderFadeState.h"
#include "libs/dolphin/include/dolphin/mtx/GeoTypes.h"
#include "pso/system/vector.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/container/TObjContainerJungEnemy.h"
#include "pso/object/container/TObjContainerIdo.h"
#include "pso/item/TUnk_804B97C0.h"
#include "pso/object/container/TContainerAncient01.h"
#include "pso/object/container/TContainerAncient01R.h"
#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/container/TObjContainerJungEx_8018D900.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/object/TObjChip.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/container/TObjContainerJungEx.h"
#include "pso/object/container/TObjContainerItem.h"
#include "pso/object/container/TObjContainerJung.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D853C.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

const char *bm_obj_hako01_model_names[5] = {
    "fe_obj_hako01.gj", "fe_obj_hako01_hahen1.gj", "fe_obj_hako01_hahen2.gj", "fe_obj_hako01_light.gj", NULL,
};
const char *bm_obj_hako01_motion_names[1] = { NULL };
BmlResourceDescriptor TObjContainerJung__resource_descriptor = {
    "bm_obj_hako01.bml", bm_obj_hako01_model_names, bm_obj_hako01_motion_names, 4, 0,
};

const char *fe_obj_hako02_model_names[5] = {
    "fe_obj_hako02.gj", "fe_obj_hako02_hahen1.gj", "fe_obj_hako02_hahen2.gj", "fe_obj_hako02_light.gj", NULL,
};
const char *fe_obj_hako02_motion_names[1] = { NULL };
// Loaded by TObjContainerJungEx::load_resource_instance.
BmlResourceDescriptor fe_obj_hako02_resource_descriptor = {
    "fe_obj_hako02.bml", fe_obj_hako02_model_names, fe_obj_hako02_motion_names, 4, 0,
};

CollisionBody container_jung_collision_desc = {
    { 0.0f, 6.0f, 0.0f }, 9.0f, 9.0f, 0, 0x38003, { 0.0f, 0.0f, 0.0f }, 0.0f,
};

const char *TObjContainerJung__name = "TObjContainerJung";
s32 TObjContainerJung__bml_model_resource;
s32 TObjContainerJung__bml_aux_handle;
void *TObjContainerJungEx__resource_bundle;

extern const TObjChipParams container_jung_debris_desc = {
    { 0.5f, 0.03f, 0.3f }, { 0.0f, 0.0f, 0.0f }, { 3.0f, 6.0f, 3.0f }, { 0x800, 0x100, 0x800 }, { 4, 0x32 }, { 0.0f, 0.8f }, 0, 0, 0x16,
};
extern const TObjChipParams container_jung_spawn_params = {
    { 0.5f, 0.03f, 0.2f }, { 0.0f, 0.0f, 0.0f }, { 3.5f, 6.0f, 3.5f }, { 0x400, 0x100, 0x400 }, { 4, 0x32 }, { 0.0f, 0.7f }, 0, 0, 0x16,
};

const char *TObjContainerJungEx__name = "TObjContainerJungEx";

extern const TObjChipParams container_jung_ex_spawn_params_a = {
    { 0.5f, 0.07f, 0.26f }, { 0.0f, 0.0f, 0.0f }, { 5.0f, 5.0f, 5.0f }, { 0x400, 0x100, 0x400 }, { 5, 0x32 }, { 0.0f, 0.6f }, 0, 0, 0x16,
};
extern const TObjChipParams container_jung_ex_spawn_params_b = {
    { 0.5f, 0.07f, 0.26f }, { 0.0f, 0.0f, 0.0f }, { 4.0f, 4.5f, 4.0f }, { 0x200, 0x100, 0x200 }, { 6, 0x32 }, { 0.0f, 0.5f }, 0, 0, 0x16,
};

const char *TObjContainerJungEnemy__name = "TObjContainerJungEnemy";

extern const TObjChipParams lbl_80445398 = {
    { 0.5f, 0.03f, 0.2f }, { 0.0f, 0.0f, 0.0f }, { 3.0f, 5.0f, 3.0f }, { 0x800, 0x100, 0x800 }, { 7, 0x32 }, { 0.0f, 1.0f }, 0, 0, 0x16,
};
extern const TObjChipParams lbl_804453E4 = {
    { 0.5f, 0.03f, 0.19f }, { 0.0f, 0.0f, 0.0f }, { 3.5f, 5.0f, 3.5f }, { 0x400, 0x100, 0x400 }, { 5, 0x32 }, { 0.0f, 1.0f }, 0, 0, 0x16,
};

extern "C" {
u32 init_collision_body_parts(void *, s32, s32);
s32 free_collision_body_parts(void *);
s32 post_translate_matrix(void *);
s32 push_matrix();
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern s32 local_client_id;
u8 *__ct__8TObjChipFP7TObjectPC14TObjChipParams(u8 *arg0, u8 *arg1, u8 *arg2);
s32 get_model__19TObjContainerJungExFl(s32);
s32 get_model_by_index__17TObjContainerJungFl(s32);
s32 set_global_param__8TObjFishFl();
u8 *get_bml_model(void *, int);
s32 free_bin_model_request(s32, s32);
}
void play_container_break_sound(s32 arg0);

struct Obj_8018CBF0 { u8 pad0[0x84]; s32 id; };
struct Obj_8018CB44 { u8 pad0[0x1C]; u16 f1C; u8 pad1[0x62]; u32 f80; s32 f84; };
struct Pkt_8018CB44 { u16 a; u16 b; s32 c; s32 d; s32 e; };
struct Obj_8018C9F0 {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x10];
    Vec pos;
    u8 pad44[0x326 - 0x44];
    s16 f326;
    u8 pad328[0x36C - 0x328];
    s32 f36c;
    s32 f370;
};
struct Obj_8018CFD4 { u8 pad[0x38]; Vec pos; };
struct Obj_8018D4DC {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x326 - 0x44];
    s16 f326;
};

// This TU was compiled -inline deferred: the functions below are written
// last-to-first, so the compiler emits them (and the three vtables) in
// address order.

void TObjContainerJungEx::load_resource_instance() {
    void *memory = ::operator new(0x440);
    void *bundle = memory;
    if (bundle != NULL) {
        bundle = load_resource_from_descriptor(memory, 5, &fe_obj_hako02_resource_descriptor, 0, 0, 0);
    }
    TObjContainerJungEx__resource_bundle = bundle;
}

void TObjContainerJungEx::free_data() {
    if (TObjContainerJungEx__resource_bundle != NULL) {
        free_bin_model_request((s32)TObjContainerJungEx__resource_bundle, 1);
        TObjContainerJungEx__resource_bundle = NULL;
    }
}

u8 *TObjContainerJungEx::get_model(s32 index) {
    if (TObjContainerJungEx__resource_bundle != NULL) {
        return get_bml_model(TObjContainerJungEx__resource_bundle, index);
    }
    return NULL;
}

s32 TObjContainerJungEx__sub_8018D900(s32 index) {
    if (TObjContainerJungEx__resource_bundle != NULL) {
        return get_bml_texlist((BmlResource *)TObjContainerJungEx__resource_bundle, index);
    }
    return 0;
}

TObjContainerJung::TObjContainerJung(TObject *parent, void *set_data) : TUnk_804B6C24(parent, set_data) {
    m_name = TObjContainerJung__name;
    mode = 0;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, (s32)&container_jung_collision_desc, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy((Vec *)&m_2fc, &position);
    center.y += container_jung_collision_desc.offset.y;
}

TObjContainerJung::~TObjContainerJung() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjContainerJung::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void TObjContainerJung::vfunc_81() {
    if ((void *)(*(u8 **)&TObjContainerJung__bml_model_resource) != NULL) {
        switch (this->mode) {
        case 0:
            TObjFish::set_global_param(TObjContainerJung__bml_aux_handle);
            push_matrix();
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            scale_matrix(0, 0.85f, 0.85f, 0.85f);
            draw_ginja_object((void *)get_bml_model(*(u8 **)&TObjContainerJung__bml_model_resource, 0));
            TParticleCtrl::begin_effect_render();
            draw_ginja_object((void *)get_bml_model(*(u8 **)&TObjContainerJung__bml_model_resource, 3));
            TParticleCtrl::end_effect_render();
            pop_matrix();
            break;
        case 1:
            break;
        }
    }
}

void TObjContainerJung::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            this->vfunc_79();
            ((TObjChara *)arg0)->request_box_item_drop((u8 *)&this->position, 1);
            ((TObjCollidable *)arg0)->clear_player_status_flag(0, 1);
            ((TObjCollidable *)arg0)->set_flag8();
            ((TObject *)arg0)->queue_destruction();
            this->mode = 1;
        }
    } else if ((s16) *arg1 == 1) {
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 1);
        ((TObjCollidable *)arg0)->set_flag8();
        ((TObject *)arg0)->queue_destruction();
        this->mode = 1;
    }
}

#pragma push
#pragma opt_propagation off
void TObjContainerJung::vfunc_79() const {
    const Obj_8018D4DC *self = (const Obj_8018D4DC *)this;
    void *o;
    if (self->f326 != 1) {
        TObjChipParams a = container_jung_debris_desc;
        f32 pz;
        f32 py;
        f32 px;
        px = self->pos.x;
        py = self->pos.y;
        pz = self->pos.z;
        a.pos[0] = px;
        a.pos[1] = py;
        a.pos[2] = pz;
        a.pad_38[0] = py;
        a.model = (s32) get_bml_model((void *) TObjContainerJung__bml_model_resource, 1);
        a.textures = TObjContainerJung__bml_aux_handle;
        TObjChipParams b = container_jung_spawn_params;
        f32 qz;
        f32 qy;
        f32 qx;
        qx = self->pos.x;
        qy = self->pos.y;
        qz = self->pos.z;
        b.pos[0] = qx;
        b.pos[1] = qy;
        b.pos[2] = qz;
        b.pad_38[0] = qy;
        b.model = (s32) get_bml_model((void *) TObjContainerJung__bml_model_resource, 2);
        b.textures = TObjContainerJung__bml_aux_handle;
        spawn_particle_effect_with_flags(&self->pos, 0x45, 0x40);
        spawn_particle_effect_with_flags(&self->pos, 0x46, 0x40);
        o = TObject::operator new(0x234);
        if (o != 0) {
            __ct__8TObjChipFP7TObjectPC14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&a);
        }
        o = TObject::operator new(0x234);
        if (o != 0) {
            __ct__8TObjChipFP7TObjectPC14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&b);
        }
        play_container_break_sound((s32)self);
    }
}
#pragma pop

void TObjContainerJung::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &TObjContainerJung__resource_descriptor, 0, 0, 0));
    }
    (*(u8 * *)&TObjContainerJung__bml_model_resource) = (unsigned char *) ((void *) var_r0);
    TObjContainerJung__bml_aux_handle = get_bml_texlist((BmlResource *) var_r0, 0);
}

void TObjContainerJung::release() {
    free_bin_model_request(TObjContainerJung__bml_model_resource, 1);
    TObjContainerJung__bml_model_resource = 0;
    TObjContainerJung__bml_aux_handle = 0;
}

void *TObjContainerJung::create(void *set_data) {
    return new TObjContainerJung(tl_05, set_data);
}

u8 *TObjContainerJung::get_model_by_index(s32 arg0) {
    if ((void *) (*(u8 * *)&TObjContainerJung__bml_model_resource) != NULL) {
        return get_bml_model((*(u8 * *)&TObjContainerJung__bml_model_resource), arg0);
    }
    return NULL;
}

s32 TObjContainerJung__sub_8018D3B8(s32) {
    return TObjContainerJung__bml_aux_handle;
}

TObjContainerJungEx::TObjContainerJungEx(TObject *parent, void *set_data) : TUnk_804B6C24(parent, set_data) {
    m_name = TObjContainerJungEx__name;
    mode = 0;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, (s32)&container_jung_collision_desc, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy((Vec *)&m_2fc, &position);
    center.y += container_jung_collision_desc.offset.y;
}

TObjContainerJungEx::~TObjContainerJungEx() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjContainerJungEx::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void TObjContainerJungEx::vfunc_81() {

    switch (this->mode) {
    case 0:
        TObjContainerJungEx__sub_8018D900(0);
        set_global_param__8TObjFishFl();
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        scale_matrix(0, 0.85f, 0.85f, 0.85f);
        draw_ginja_object((void *)TObjContainerJungEx::get_model(0));
        TParticleCtrl::begin_effect_render();
        draw_ginja_object((void *)TObjContainerJungEx::get_model(3));
        TParticleCtrl::end_effect_render();
        pop_matrix();
    case 1:
        return;
    }
}

void TObjContainerJungEx::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            this->vfunc_79();
            ((TUnk_804B6C24 *)arg0)->spawn_item((s32)arg0);
            ((TObjCollidable *)arg0)->set_flag8();
            ((TObject *)arg0)->queue_destruction();
            this->mode = 1;
        }
    } else if ((s16) *arg1 == 1) {
        ((TObjCollidable *)arg0)->set_flag8();
        ((TObject *)arg0)->queue_destruction();
        this->mode = 1;
    }
}

#pragma push
#pragma opt_propagation off
void TObjContainerJungEx::vfunc_79() const {
    const Obj_8018CFD4 *self = (const Obj_8018CFD4 *)this;
    TObjChipParams a = container_jung_ex_spawn_params_a;
    f32 pz;
    f32 py;
    f32 px;
    px = self->pos.x;
    py = self->pos.y;
    pz = self->pos.z;
    a.pos[0] = px;
    a.pos[1] = py;
    a.pos[2] = pz;
    a.pad_38[0] = py;
    a.model = get_model__19TObjContainerJungExFl(1);
    a.textures = TObjContainerJungEx__sub_8018D900(0);
    TObjChipParams b = container_jung_ex_spawn_params_b;
    f32 qz;
    f32 qy;
    f32 qx;
    qx = self->pos.x;
    qy = self->pos.y;
    qz = self->pos.z;
    b.pos[0] = qx;
    b.pos[1] = qy;
    b.pos[2] = qz;
    b.pad_38[0] = qy;
    b.model = get_model__19TObjContainerJungExFl(2);
    b.textures = TObjContainerJungEx__sub_8018D900(0);
    spawn_particle_effect_with_flags(&self->pos, 0x45, 0x40);
    spawn_particle_effect_with_flags(&self->pos, 0x46, 0x40);
    void *o = TObject::operator new(0x234);
    if (o != NULL) {
        __ct__8TObjChipFP7TObjectPC14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&a);
    }
    o = TObject::operator new(0x234);
    if (o != NULL) {
        __ct__8TObjChipFP7TObjectPC14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&b);
    }
    play_container_break_sound((s32)self);
}
#pragma pop

void *TObjContainerJungEx::create(void *set_data) {
    return new TObjContainerJungEx(tl_05, set_data);
}

TObjContainerJungEnemy::TObjContainerJungEnemy(TObject *parent, void *set_data) : TUnk_804B6C24(parent, set_data) {
    m_name = TObjContainerJungEnemy__name;
    load_models();
    mode = 0;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, (s32)&container_jung_collision_desc, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy((Vec *)&m_2fc, &position);
    center.y += container_jung_collision_desc.offset.y;
}

TObjContainerJungEnemy::~TObjContainerJungEnemy() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TObjContainerJungEnemy::create(void *set_data) {
    return new TObjContainerJungEnemy(tl_05, set_data);
}

void TObjContainerJungEnemy::load_models() {
    s32 var_r0;
    s32 temp_r3 = this->set_params[1];
    if (temp_r3 < 0) {
        var_r0 = 0;
    } else {
        var_r0 = 1;
        if (temp_r3 <= 1) {
            var_r0 = temp_r3;
        }
    }
    switch (var_r0) {
    case 0:
        this->m_368 = get_model_by_index__17TObjContainerJungFl(0);
        this->m_36c = get_model_by_index__17TObjContainerJungFl(1);
        this->m_370 = get_model_by_index__17TObjContainerJungFl(2);
        this->m_374 = get_model_by_index__17TObjContainerJungFl(3);
        this->texlist = TObjContainerJung__sub_8018D3B8(0);
        return;
    default:
    case 1:
        this->m_368 = get_model__19TObjContainerJungExFl(0);
        this->m_36c = get_model__19TObjContainerJungExFl(1);
        this->m_370 = get_model__19TObjContainerJungExFl(2);
        this->m_374 = get_model__19TObjContainerJungExFl(3);
        this->texlist = TObjContainerJungEx__sub_8018D900(0);
        return;
    }
}

void TObjContainerJungEnemy::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void TObjContainerJungEnemy::vfunc_81() {

    switch (this->mode) {
    case 0:
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        scale_matrix(0, 0.85f, 0.85f, 0.85f);
        draw_ginja_object(*(void * *)&this->m_368);
        TParticleCtrl::begin_effect_render();
        draw_ginja_object(*(void * *)&this->m_374);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    case 1:
        return;
    }
}

void TObjContainerJungEnemy::debug_print_item_box_info() {
    Obj_8018CBF0 *self = (Obj_8018CBF0 *)this;
    ((TObjContainerJungEnemy *)self)->load_models();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, "EVT NO : %d", this->set_params[0]);
    debug_printf_at(0x130021, "MODEL SELECT");
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

f32 TObjContainerJungEnemy::receive_physical_attack(void *, f32) {
    Obj_8018CB44 *arg0 = (Obj_8018CB44 *)this;
    s16 sp8;
    Pkt_8018CB44 pkt;
    if ((this->entity_id >= 0x1000U) && (arg0->f80 != 0U) && (((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 1) != 0)) {
        sp8 = 1;
        ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 0);
        ((TObjCollidable *)arg0)->send_object_state_update(&sp8);
        ((TLobby *)(&pkt))->init_packet_67_04();
        pkt.b = this->entity_id;
        pkt.c = get_current_floor();
        pkt.d = this->set_params[0];
        pkt.e = local_client_id;
        ((TLobby *)(&pkt))->byteswap_and_send();
    }
    return 0.0f;
}

#pragma push
#pragma opt_propagation off
void TObjContainerJungEnemy::vfunc_79() const {
    const Obj_8018C9F0 *self = (const Obj_8018C9F0 *)this;
    if (self->f326 != 1) {
        TObjChipParams a = lbl_80445398;
        f32 za;
        f32 ya;
        f32 xa;
        xa = self->pos.x;
        ya = self->pos.y;
        za = self->pos.z;
        a.pos[0] = xa;
        a.pos[1] = ya;
        a.pos[2] = za;
        a.pad_38[0] = ya;
        a.model = self->f36c;
        a.textures = self->f24;
        TObjChipParams b = lbl_804453E4;
        f32 zb;
        f32 yb;
        f32 xb;
        xb = self->pos.x;
        yb = self->pos.y;
        zb = self->pos.z;
        b.pos[0] = xb;
        b.pos[1] = yb;
        b.pos[2] = zb;
        b.pad_38[0] = yb;
        b.model = self->f370;
        b.textures = self->f24;
        spawn_particle_effect_with_flags(&self->pos, 0x45, 0x40);
        spawn_particle_effect_with_flags(&self->pos, 0x46, 0x40);
        void *o = TObject::operator new(0x234);
        if (o != 0) {
            __ct__8TObjChipFP7TObjectPC14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&a);
        }
        o = TObject::operator new(0x234);
        if (o != 0) {
            __ct__8TObjChipFP7TObjectPC14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&b);
        }
        play_container_break_sound((s32)self);
    }
}
#pragma pop

void TObjContainerJungEnemy::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            ((TObjContainerJungEnemy *)arg0)->vfunc_79();
            ((TObjCollidable *)arg0)->clear_player_status_flag(0, 1);
            ((TObjCollidable *)arg0)->set_flag8();
            ((TObject *)arg0)->queue_destruction();
            this->mode = 1;
        }
    } else if ((s16) *arg1 == 1) {
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 1);
        ((TObjCollidable *)arg0)->set_flag8();
        ((TObject *)arg0)->queue_destruction();
        this->mode = 1;
    }
}
