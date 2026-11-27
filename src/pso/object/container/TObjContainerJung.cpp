#include "pso/system/BmlAccessors.h"
#include "pso/network/FloorEventCommand.h"
#include "pso/object/container/ContainerBreakEffects.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/render/RenderFadeState.h"
#include "pso/system/vector.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/TextureState.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/container/TObjContainerJungEnemy.h"
#include "pso/object/container/TObjContainerIdo.h"
#include "pso/item/TUnk_804B97C0.h"
#include "pso/object/container/TContainerAncient01.h"
#include "pso/object/container/TContainerAncient01R.h"
#include "types.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/network/TLobby.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/container/TObjContainerBase.h"
#include "pso/object/TObjChip.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/container/TObjContainerJungEx.h"
#include "pso/object/container/TObjContainerItem.h"
#include "pso/object/container/TObjContainerJung.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/math/MatrixReflect.h"
#include "pso/player/PlayerCommands.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/DebugFont.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/client_id.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/base/TObjCollidable.h"
#include "pso/object/base/ActorCollision.h"

#pragma readonly_strings on

static __declspec(section ".rodata") const char fe_obj_hako01_gj[] ATTRIBUTE_ALIGN(4) = "fe_obj_hako01.gj";
static __declspec(section ".rodata") const char fe_obj_hako01_hahen1_gj[] ATTRIBUTE_ALIGN(4) = "fe_obj_hako01_hahen1.gj";
static __declspec(section ".rodata") const char fe_obj_hako01_hahen2_gj[] ATTRIBUTE_ALIGN(4) = "fe_obj_hako01_hahen2.gj";
static __declspec(section ".rodata") const char fe_obj_hako01_light_gj[] ATTRIBUTE_ALIGN(4) = "fe_obj_hako01_light.gj";
static __declspec(section ".rodata") const char bm_obj_hako01_bml[] ATTRIBUTE_ALIGN(4) = "bm_obj_hako01.bml";
static __declspec(section ".rodata") const char fe_obj_hako02_gj[] ATTRIBUTE_ALIGN(4) = "fe_obj_hako02.gj";
static __declspec(section ".rodata") const char fe_obj_hako02_hahen1_gj[] ATTRIBUTE_ALIGN(4) = "fe_obj_hako02_hahen1.gj";
static __declspec(section ".rodata") const char fe_obj_hako02_hahen2_gj[] ATTRIBUTE_ALIGN(4) = "fe_obj_hako02_hahen2.gj";
static __declspec(section ".rodata") const char fe_obj_hako02_light_gj[] ATTRIBUTE_ALIGN(4) = "fe_obj_hako02_light.gj";
static __declspec(section ".rodata") const char fe_obj_hako02_bml[] ATTRIBUTE_ALIGN(4) = "fe_obj_hako02.bml";

const char *bm_obj_hako01_model_names[5] = {
    fe_obj_hako01_gj, fe_obj_hako01_hahen1_gj, fe_obj_hako01_hahen2_gj, fe_obj_hako01_light_gj, NULL,
};
const char *bm_obj_hako01_motion_names[1] = { NULL };
BmlResourceDescriptor container_jung_resource_descriptor = {
    bm_obj_hako01_bml, bm_obj_hako01_model_names, bm_obj_hako01_motion_names, 4, 0,
};

const char *fe_obj_hako02_model_names[5] = {
    fe_obj_hako02_gj, fe_obj_hako02_hahen1_gj, fe_obj_hako02_hahen2_gj, fe_obj_hako02_light_gj, NULL,
};
const char *fe_obj_hako02_motion_names[1] = { NULL };
// Loaded by TObjContainerJungEx::load_resource_instance.
BmlResourceDescriptor fe_obj_hako02_resource_descriptor = {
    fe_obj_hako02_bml, fe_obj_hako02_model_names, fe_obj_hako02_motion_names, 4, 0,
};

CollisionBody container_jung_collision_desc = {
    { 0.0f, 6.0f, 0.0f }, 9.0f, 9.0f, 0, 0x38003, { 0.0f, 0.0f, 0.0f }, 0.0f,
};

const char *container_jung_name = "TObjContainerJung";
BmlResource *jungle_container_archive;
NJS_TEXLIST *jungle_container_textures;
BmlResource *jungle_container_ex_archive;

extern const TObjChipParams container_jung_debris_desc = {
    0.5f, 0.03f, 0.3f, { 0.0f, 0.0f, 0.0f }, { 3.0f, 6.0f, 3.0f }, { 0x800, 0x100, 0x800 }, 4, 0x32, 0.0f, 0.8f, 0, 0, 0x16,
};
extern const TObjChipParams container_jung_spawn_params = {
    0.5f, 0.03f, 0.2f, { 0.0f, 0.0f, 0.0f }, { 3.5f, 6.0f, 3.5f }, { 0x400, 0x100, 0x400 }, 4, 0x32, 0.0f, 0.7f, 0, 0, 0x16,
};

const char *container_jung_ex_name = "TObjContainerJungEx";

extern const TObjChipParams container_jung_ex_spawn_params_a = {
    0.5f, 0.07f, 0.26f, { 0.0f, 0.0f, 0.0f }, { 5.0f, 5.0f, 5.0f }, { 0x400, 0x100, 0x400 }, 5, 0x32, 0.0f, 0.6f, 0, 0, 0x16,
};
extern const TObjChipParams container_jung_ex_spawn_params_b = {
    0.5f, 0.07f, 0.26f, { 0.0f, 0.0f, 0.0f }, { 4.0f, 4.5f, 4.0f }, { 0x200, 0x100, 0x200 }, 6, 0x32, 0.0f, 0.5f, 0, 0, 0x16,
};

const char *container_jung_enemy_name = "TObjContainerJungEnemy";

extern const TObjChipParams container_jung_enemy_spawn_params_a = {
    0.5f, 0.03f, 0.2f, { 0.0f, 0.0f, 0.0f }, { 3.0f, 5.0f, 3.0f }, { 0x800, 0x100, 0x800 }, 7, 0x32, 0.0f, 1.0f, 0, 0, 0x16,
};
extern const TObjChipParams container_jung_enemy_spawn_params_b = {
    0.5f, 0.03f, 0.19f, { 0.0f, 0.0f, 0.0f }, { 3.5f, 5.0f, 3.5f }, { 0x400, 0x100, 0x400 }, 5, 0x32, 0.0f, 1.0f, 0, 0, 0x16,
};



// This TU was compiled -inline deferred: the functions below are written
// last-to-first, so the compiler emits them (and the three vtables) in
// address order.

void TObjContainerJungEx::load_resource_instance() {
    BmlResource *bundle = new BmlResource(5, &fe_obj_hako02_resource_descriptor, 0, 0, NULL);
    jungle_container_ex_archive = bundle;
}

void TObjContainerJungEx::free_data() {
    if (jungle_container_ex_archive != NULL) {
        delete jungle_container_ex_archive;
        jungle_container_ex_archive = NULL;
    }
}

NJS_OBJECT *TObjContainerJungEx::get_model(s32 index) {
    if (jungle_container_ex_archive != NULL) {
        return get_bml_model(jungle_container_ex_archive, index);
    }
    return NULL;
}

NJS_TEXLIST *TObjContainerJungEx::get_textures(s32 index) {
    if (jungle_container_ex_archive != NULL) {
        return get_bml_texlist(jungle_container_ex_archive, index);
    }
    return 0;
}

TObjContainerJung::TObjContainerJung(TObject *parent, ObjectSetData *set_data) : TObjContainerBase(parent, set_data) {
    m_name = container_jung_name;
    mode = 0;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, &container_jung_collision_desc, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy(&body_center, &position);
    center.y += container_jung_collision_desc.offset.y;
}

TObjContainerJung::~TObjContainerJung() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjContainerJung::update_state() {

    switch (this->mode) {
    case 0:
        if ((s32) this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void TObjContainerJung::draw_model() {
    if (jungle_container_archive != NULL) {
        switch (this->mode) {
        case 0:
            set_texture_list(jungle_container_textures);
            push_matrix();
            post_translate_matrix(&this->position.x);
            rotate_matrix_y(0, this->rotation.y);
            scale_matrix(0, 0.85f, 0.85f, 0.85f);
            draw_ginja_object(get_bml_model(jungle_container_archive, 0));
            begin_effect_render();
            draw_ginja_object(get_bml_model(jungle_container_archive, 3));
            end_effect_render();
            pop_matrix();
            break;
        case 1:
            break;
        }
    }
}

void TObjContainerJung::apply_saved_state(s16 *state, s32 live) {
    if (live != 0) {
        if ((s16) *state == 1) {
            this->spawn_break_effects();
            request_box_item_drop(&position, 1);
            this->clear_player_status_flag(0, 1);
            this->set_flag8();
            this->queue_destruction();
            this->mode = 1;
        }
    } else if ((s16) *state == 1) {
        this->clear_player_status_flag(0, 1);
        this->set_flag8();
        this->queue_destruction();
        this->mode = 1;
    }
}

#pragma push
#pragma opt_propagation off
void TObjContainerJung::spawn_break_effects() const {
    if (mode != 1) {
        TObjChipParams a = container_jung_debris_desc;
        f32 pz;
        f32 py;
        f32 px;
        px = position.x;
        py = position.y;
        pz = position.z;
        a.pos.x = px;
        a.pos.y = py;
        a.pos.z = pz;
        a.floor_y = py;
        a.model = get_bml_model(jungle_container_archive, 1);
        a.textures = jungle_container_textures;
        TObjChipParams b = container_jung_spawn_params;
        f32 qz;
        f32 qy;
        f32 qx;
        qx = position.x;
        qy = position.y;
        qz = position.z;
        b.pos.x = qx;
        b.pos.y = qy;
        b.pos.z = qz;
        b.floor_y = qy;
        b.model = get_bml_model(jungle_container_archive, 2);
        b.textures = jungle_container_textures;
        spawn_particle_effect_with_flags(&position, 0x45, 0x40);
        spawn_particle_effect_with_flags(&position, 0x46, 0x40);
        new TObjChip(tl_05, &a);
        new TObjChip(tl_05, &b);
        play_container_break_sound(this);
    }
}
#pragma pop

void TObjContainerJung::load_resources() {
    BmlResource *archive = new BmlResource(5, &container_jung_resource_descriptor, 0, 0, NULL);
    jungle_container_archive = archive;
    jungle_container_textures = get_bml_texlist(archive, 0);
}

void TObjContainerJung::release() {
    delete jungle_container_archive;
    jungle_container_archive = NULL;
    jungle_container_textures = NULL;
}

void *TObjContainerJung::create(ObjectSetData *set_data) {
    return new TObjContainerJung(tl_05, set_data);
}

NJS_OBJECT *TObjContainerJung::get_model_by_index(s32 index) {
    if (jungle_container_archive != NULL) {
        return get_bml_model(jungle_container_archive, index);
    }
    return NULL;
}

NJS_TEXLIST *TObjContainerJung::get_textures(s32) {
    return jungle_container_textures;
}

TObjContainerJungEx::TObjContainerJungEx(TObject *parent, ObjectSetData *set_data) : TObjContainerBase(parent, set_data) {
    m_name = container_jung_ex_name;
    mode = 0;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, &container_jung_collision_desc, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy(&body_center, &position);
    center.y += container_jung_collision_desc.offset.y;
}

TObjContainerJungEx::~TObjContainerJungEx() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjContainerJungEx::update_state() {

    switch (this->mode) {
    case 0:
        if ((s32) this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void TObjContainerJungEx::draw_model() {

    switch (this->mode) {
    case 0:
        set_texture_list(TObjContainerJungEx::get_textures(0));
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(0, this->rotation.y);
        scale_matrix(0, 0.85f, 0.85f, 0.85f);
        draw_ginja_object(TObjContainerJungEx::get_model(0));
        begin_effect_render();
        draw_ginja_object(TObjContainerJungEx::get_model(3));
        end_effect_render();
        pop_matrix();
    case 1:
        return;
    }
}

void TObjContainerJungEx::apply_saved_state(s16 *state, s32 live) {
    if (live != 0) {
        if ((s16) *state == 1) {
            this->spawn_break_effects();
            request_configured_item_drop(this);
            this->set_flag8();
            this->queue_destruction();
            this->mode = 1;
        }
    } else if ((s16) *state == 1) {
        this->set_flag8();
        this->queue_destruction();
        this->mode = 1;
    }
}

#pragma push
#pragma opt_propagation off
void TObjContainerJungEx::spawn_break_effects() const {
    TObjChipParams a = container_jung_ex_spawn_params_a;
    f32 pz;
    f32 py;
    f32 px;
    px = position.x;
    py = position.y;
    pz = position.z;
    a.pos.x = px;
    a.pos.y = py;
    a.pos.z = pz;
    a.floor_y = py;
    a.model = TObjContainerJungEx::get_model(1);
    a.textures = TObjContainerJungEx::get_textures(0);
    TObjChipParams b = container_jung_ex_spawn_params_b;
    f32 qz;
    f32 qy;
    f32 qx;
    qx = position.x;
    qy = position.y;
    qz = position.z;
    b.pos.x = qx;
    b.pos.y = qy;
    b.pos.z = qz;
    b.floor_y = qy;
    b.model = TObjContainerJungEx::get_model(2);
    b.textures = TObjContainerJungEx::get_textures(0);
    spawn_particle_effect_with_flags(&position, 0x45, 0x40);
    spawn_particle_effect_with_flags(&position, 0x46, 0x40);
    new TObjChip(tl_05, &a);
    new TObjChip(tl_05, &b);
    play_container_break_sound(this);
}
#pragma pop

void *TObjContainerJungEx::create(ObjectSetData *set_data) {
    return new TObjContainerJungEx(tl_05, set_data);
}

TObjContainerJungEnemy::TObjContainerJungEnemy(TObject *parent, ObjectSetData *set_data) : TObjContainerBase(parent, set_data) {
    m_name = container_jung_enemy_name;
    load_models();
    mode = 0;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, &container_jung_collision_desc, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy(&body_center, &position);
    center.y += container_jung_collision_desc.offset.y;
}

TObjContainerJungEnemy::~TObjContainerJungEnemy() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TObjContainerJungEnemy::create(ObjectSetData *set_data) {
    return new TObjContainerJungEnemy(tl_05, set_data);
}

void TObjContainerJungEnemy::load_models() {
    saddr variant;
    s32 param = this->set_params[1];
    if (param < 0) {
        variant = 0;
    } else {
        variant = 1;
        if (param <= 1) {
            variant = param;
        }
    }
    switch (variant) {
    case 0:
        this->body_model = TObjContainerJung::get_model_by_index(0);
        this->large_fragment_model = TObjContainerJung::get_model_by_index(1);
        this->small_fragment_model = TObjContainerJung::get_model_by_index(2);
        this->light_model = TObjContainerJung::get_model_by_index(3);
        this->texlist = TObjContainerJung::get_textures(0);
        return;
    default:
    case 1:
        this->body_model = TObjContainerJungEx::get_model(0);
        this->large_fragment_model = TObjContainerJungEx::get_model(1);
        this->small_fragment_model = TObjContainerJungEx::get_model(2);
        this->light_model = TObjContainerJungEx::get_model(3);
        this->texlist = TObjContainerJungEx::get_textures(0);
        return;
    }
}

void TObjContainerJungEnemy::update_state() {

    switch (this->mode) {
    case 0:
        if ((s32) this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void TObjContainerJungEnemy::draw_model() {

    switch (this->mode) {
    case 0:
        set_texture_list(this->texlist);
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(0, this->rotation.y);
        scale_matrix(0, 0.85f, 0.85f, 0.85f);
        draw_ginja_object(this->body_model);
        begin_effect_render();
        draw_ginja_object(this->light_model);
        end_effect_render();
        pop_matrix();
    case 1:
        return;
    }
}

void TObjContainerJungEnemy::debug_print_item_box_info() {
    load_models();
    set_debug_text_color(0xFF00FF);
    debug_printf_at(0x130020, "EVT NO : %d", this->set_params[0]);
    debug_printf_at(0x130021, "MODEL SELECT");
    set_debug_text_color(0xF0F0F0FF);
}

f32 TObjContainerJungEnemy::receive_physical_attack(TObjChara *, f32) {
    s16 saved_state;
    G_FloorEvent_6x67 pkt;
    if ((this->entity_id >= 0x1000U) && (set_entry != NULL) && (access_object_saved_state(&saved_state, 1) != 0)) {
        saved_state = 1;
        access_object_saved_state(&saved_state, 0);
        send_object_state_update(&saved_state);
        pkt.init();
        pkt.header.client_id = this->entity_id;
        pkt.floor = get_current_floor();
        pkt.event_id = this->set_params[0];
        pkt.sender_client_id = local_client_id;
        pkt.send();
    }
    return 0.0f;
}

#pragma push
#pragma opt_propagation off
void TObjContainerJungEnemy::spawn_break_effects() const {
    if (mode != 1) {
        TObjChipParams a = container_jung_enemy_spawn_params_a;
        f32 za;
        f32 ya;
        f32 xa;
        xa = position.x;
        ya = position.y;
        za = position.z;
        a.pos.x = xa;
        a.pos.y = ya;
        a.pos.z = za;
        a.floor_y = ya;
        a.model = large_fragment_model;
        a.textures = texlist;
        TObjChipParams b = container_jung_enemy_spawn_params_b;
        f32 zb;
        f32 yb;
        f32 xb;
        xb = position.x;
        yb = position.y;
        zb = position.z;
        b.pos.x = xb;
        b.pos.y = yb;
        b.pos.z = zb;
        b.floor_y = yb;
        b.model = small_fragment_model;
        b.textures = texlist;
        spawn_particle_effect_with_flags(&position, 0x45, 0x40);
        spawn_particle_effect_with_flags(&position, 0x46, 0x40);
        new TObjChip(tl_05, &a);
        new TObjChip(tl_05, &b);
        play_container_break_sound(this);
    }
}
#pragma pop

void TObjContainerJungEnemy::apply_saved_state(s16 *state, s32 live) {
    if (live != 0) {
        if ((s16) *state == 1) {
            this->spawn_break_effects();
            this->clear_player_status_flag(0, 1);
            this->set_flag8();
            this->queue_destruction();
            this->mode = 1;
        }
    } else if ((s16) *state == 1) {
        this->clear_player_status_flag(0, 1);
        this->set_flag8();
        this->queue_destruction();
        this->mode = 1;
    }
}
