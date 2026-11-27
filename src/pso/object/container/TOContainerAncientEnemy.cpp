#include "pso/system/memory.h"
#include "pso/system/BmlAccessors.h"
#include "pso/network/FloorEventCommand.h"
#include "pso/object/container/ContainerBreakEffects.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/system/GameModeQueries.h"
#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"
#include "pso/system/byteswap.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/TLanguage.h"
#include "pso/map/FloorArea.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/container/TObjContainerBase.h"
#include "pso/object/container/TOContainerAncientItem.h"
#include "pso/object/container/TOContainerAncientEnemy.h"
#include "pso/object/container/TOContainerAncientEnemyCommon.h"
#include "pso/object/container/TOContainerAncientEnemyRare.h"
#include "pso/object/container/TOContainerAncientItemRare.h"
#include "pso/object/container/TOContainerAncientItemNone.h"
#include "pso/object/container/TOContainerAncientItemCommon.h"
#include "pso/object/container/TObjContainerItem.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/CameraDistanceFade.h"
#include "pso/network/TLobby.h"
#include "pso/network/TGameProtocol.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/render/TextureState.h"
#include "pso/object/cave/TOAirconCave01.h"
#include "pso/object/TObjChip.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerCommands.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/math/MatrixReflect.h"
#include "pso/render/DebugFont.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/BmlResource.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/network/client_id.h"
#include "pso/network/TProtocol.h"
#include "pso/system/task/TObject.h"

static __declspec(section ".rodata") const char ancient_container_model[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_container.gj";
static __declspec(section ".rodata") const char ancient_container_fragment1_model[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_container_hahen01.gj";
static __declspec(section ".rodata") const char ancient_container_fragment2_model[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_container_hahen02.gj";
static __declspec(section ".rodata") const char ancient_container_bml[] ATTRIBUTE_ALIGN(4) = "bm_o_container_ancient.bml";
static __declspec(section ".rodata") const char vs2_container_fragment1_model[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_vs2container_hahen1.gj";
static __declspec(section ".rodata") const char vs2_container_fragment2_model[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_vs2container_hahen2.gj";
static __declspec(section ".rodata") const char vs2_container_model[] ATTRIBUTE_ALIGN(4) = "fs_obj_o_vs2container.gj";
static __declspec(section ".rodata") const char vs2_container_bml[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_vs2container.bml";
static __declspec(section ".rodata") const char ep2_box_model[] ATTRIBUTE_ALIGN(4) = "fs_obj_ex_box1.gj";
static __declspec(section ".rodata") const char ep2_box_fragment1_model[] ATTRIBUTE_ALIGN(4) = "fe_obj_ex_box1_hahen01.gj";
static __declspec(section ".rodata") const char ep2_box_fragment2_model[] ATTRIBUTE_ALIGN(4) = "fe_obj_ex_box1_hahen02.gj";

LAYOUT_ASSERT(AncientContainerBmlSize, sizeof(AncientContainerBml) == 0x20);
LAYOUT_ASSERT(AncientContainerBmlDescriptorOffset, offsetof(AncientContainerBml, descriptor) == 0x10);

// The 6x67 packet receive_physical_attack sends (its fields are not named yet).
extern const f32 ancient_container_one;
extern const f32 ancient_container_zero;
extern const f32 ancient_container_debug_radius;

const char *bm_o_container_ancient_motion_names[1] = { NULL };
const char *fe_obj_o_vs2container_motion_names[1] = { NULL };
const char *fe_obj_ex_box1_motion_names[1] = { NULL };
AncientContainerBml bm_o_container_ancient_resource_bundle = { { ancient_container_model, ancient_container_fragment1_model, ancient_container_fragment2_model, NULL }, { ancient_container_bml, bm_o_container_ancient_resource_bundle.model_filenames, bm_o_container_ancient_motion_names, 3, 0 } };
AncientContainerBml fe_obj_o_vs2container_resource_bundle = { { vs2_container_fragment1_model, vs2_container_fragment2_model, vs2_container_model, NULL }, { vs2_container_bml, fe_obj_o_vs2container_resource_bundle.model_filenames, fe_obj_o_vs2container_motion_names, 3, 0 } };
AncientContainerBml fe_obj_ex_box1_resource_bundle = { { ep2_box_model, ep2_box_fragment1_model, ep2_box_fragment2_model, NULL }, { "fe_obj_ex_box1.bml", fe_obj_ex_box1_resource_bundle.model_filenames, fe_obj_ex_box1_motion_names, 3, 0 } };
CollisionBody container_ancient_enemy_collision_body_params = { { 0.0f, 6.5f, 0.0f }, 7.5f, 7.5f, 0, 0x38003, { 0.0f, 0.0f, 0.0f }, 0.0f };

const char *container_ancient_item_common_name = "TOContainerAncientItemCommon";
const char *container_ancient_item_rare_name = "TOContainerAncientItemRare";
const char *container_ancient_item_none_name = "TOContainerAncientItemNone";
const char *container_ancient_enemy_name = "TOContainerAncientEnemy";
const char *container_ancient_enemy_common_name = "TOContainerAncientEnemyCommon";
const char *TOContainerAncientEnemyRare::class_name = "TOContainerAncientEnemyRare";

// The three fragment texture lists of the current floor, loaded with the
// archive (ancient_container_resource_bundle) by
// load_ancient_container_resources. Both share one 8-aligned
// .sbss block that stays unclaimed until the bundle can be
// defined here (see spawn_break_effects).
extern NJS_TEXLIST **ancient_container_fragment_texture_lists;

static const TObjChipParams fish_break_debris_desc = {
    0.5f, 0.07f, 0.26f, { 0.0f, 0.0f, 0.0f }, { 5.0f, 5.0f, 5.0f }, { 0x400, 0x100, 0x400 }, 5, 0x32, 0.0f, 0.6f, 0, 0, 0x16,
};
static const TObjChipParams fish_break_debris_desc_b = {
    0.5f, 0.07f, 0.26f, { 0.0f, 0.0f, 0.0f }, { 4.0f, 4.5f, 4.0f }, { 0x200, 0x100, 0x200 }, 6, 0x32, 0.0f, 0.5f, 0, 0, 0x16,
};
static const TObjChipParams ancient_enemy_break_debris_desc = {
    0.5f, 0.07f, 0.26f, { 0.0f, 0.0f, 0.0f }, { 5.0f, 5.0f, 5.0f }, { 0x400, 0x100, 0x400 }, 5, 0x32, 0.0f, 0.6f, 0, 0, 0x16,
};
static const TObjChipParams ancient_enemy_break_debris_desc_b = {
    0.5f, 0.07f, 0.26f, { 0.0f, 0.0f, 0.0f }, { 4.0f, 4.5f, 4.0f }, { 0x200, 0x100, 0x200 }, 6, 0x32, 0.0f, 0.5f, 0, 0, 0x16,
};
static __declspec(section ".rodata") const char ancient_enemy_event_format[] ATTRIBUTE_ALIGN(4) = "EVT NO : %d";
static __declspec(section ".rodata") const char fs_obj_ex_box2_texture[] ATTRIBUTE_ALIGN(4) = "fs_obj_ex_box2.gvm";
static __declspec(section ".rodata") const char fe_obj_ex_box2_hahen01_texture[] ATTRIBUTE_ALIGN(4) = "fe_obj_ex_box2_hahen01.gvm";
static __declspec(section ".rodata") const char fe_obj_ex_box2_hahen02_texture[] ATTRIBUTE_ALIGN(4) = "fe_obj_ex_box2_hahen02.gvm";
static __declspec(section ".rodata") const char fs_obj_o_vs2container_r_texture[] ATTRIBUTE_ALIGN(4) = "fs_obj_o_vs2container_r.gvm";
static __declspec(section ".rodata") const char fe_obj_o_vs2cont_hahen1_r_texture[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_vs2cont_hahen1_r.gvm";
static __declspec(section ".rodata") const char fe_obj_o_vs2cont_hahen2_r_texture[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_vs2cont_hahen2_r.gvm";
static __declspec(section ".rodata") const char fe_obj_o_container_r_texture[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_container_r.gvm";
static __declspec(section ".rodata") const char fe_obj_o_container_hahen01r_texture[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_container_hahen01r.gvm";
static __declspec(section ".rodata") const char fe_obj_o_container_hahen02r_texture[] ATTRIBUTE_ALIGN(4) = "fe_obj_o_container_hahen02r.gvm";


// Built with -inline off,deferred: the compiler emits the functions (and the
// vtables) last-to-first, so the definitions below run backwards from the
// original code order.

void G_FloorEvent_6x67::init() {
    header.subcommand = 0x67;
    header.size = 4;
}

void G_FloorEvent_6x67::bswap() {
    header.bswap();
    bswap_32(reinterpret_cast<u32 *>(&floor));
    bswap_32(reinterpret_cast<u32 *>(&event_id));
    bswap_32(reinterpret_cast<u32 *>(&sender_client_id));
}

void G_FloorEvent_6x67::send() {
    bswap();
    send_subcommand(this);
}

void TObjContainerBase::apply_saved_state(s16 *, s32) {  }

TObjContainerBase::~TObjContainerBase() {
}

s32 TObjContainerBase::roll_physical_accuracy(TObjChara *, s32, f32) { return 1; }

s32 TObjContainerBase::try_start_action(TObjChara *, s32, f32) { return 1; }

void TObjContainerBase::apply_knockback_from_attacker(TObjBase *, f32) {  }

f32 TObjContainerBase::receive_weapon_special_attack(TObjChara *, CollisionBody *) {
    receive_physical_attack(NULL, ancient_container_one);
    return ancient_container_zero;
}

int TObjContainerBase::calc_distance_accuracy_penalty(TObjChara *, CollisionBody *, const Vec *, float) { return 1; }

extern BmlResource *ancient_container_resource_bundle;

void load_ancient_container_resources(void) {
    // The archive bundles occupy three consecutive linker records in base, VS2,
    // and Episode II order. Use the record layout to reach their descriptors.
    const uaddr table = reinterpret_cast<uaddr>(&bm_o_container_ancient_resource_bundle);
    const size_t stride = sizeof(AncientContainerBml);
    const size_t descriptor_offset = offsetof(AncientContainerBml, descriptor);
    s32 area = get_current_floor_area();
    BmlResource *p;
    if (enable_v2_features == 1 &&
        (area == AREA_BATTLE1 || area == AREA_VR_SPACESHIP_ALPHA || area == AREA_VR_SPACESHIP_BETA || area == AREA_GOL_DRAGON)) {
        p = new BmlResource(1, reinterpret_cast<BmlResourceDescriptor *>(table + 2 * stride + descriptor_offset), 0, 0, NULL);
        ancient_container_resource_bundle = p;
        ancient_container_fragment_texture_lists = static_cast<NJS_TEXLIST **>(mem_alloc(3 * sizeof(NJS_TEXLIST *)));
        ancient_container_fragment_texture_lists[0] = LoadPvmFileTls(fs_obj_ex_box2_texture);
        ancient_container_fragment_texture_lists[1] = LoadPvmFileTls(fe_obj_ex_box2_hahen01_texture);
        ancient_container_fragment_texture_lists[2] = LoadPvmFileTls(fe_obj_ex_box2_hahen02_texture);
    } else if (enable_v2_features == 1 &&
               (area == AREA_BATTLE2 || area == AREA_VR_TEMPLE_ALPHA || area == AREA_VR_TEMPLE_BETA || area == AREA_BARBA_RAY)) {
        p = new BmlResource(1, reinterpret_cast<BmlResourceDescriptor *>(table + stride + descriptor_offset), 0, 0, NULL);
        ancient_container_resource_bundle = p;
        ancient_container_fragment_texture_lists = static_cast<NJS_TEXLIST **>(mem_alloc(3 * sizeof(NJS_TEXLIST *)));
        ancient_container_fragment_texture_lists[0] = LoadPvmFileTls(fs_obj_o_vs2container_r_texture);
        ancient_container_fragment_texture_lists[1] = LoadPvmFileTls(fe_obj_o_vs2cont_hahen1_r_texture);
        ancient_container_fragment_texture_lists[2] = LoadPvmFileTls(fe_obj_o_vs2cont_hahen2_r_texture);
    } else {
        p = new BmlResource(1, reinterpret_cast<BmlResourceDescriptor *>(table + descriptor_offset), 0, 0, NULL);
        ancient_container_resource_bundle = p;
        ancient_container_fragment_texture_lists = static_cast<NJS_TEXLIST **>(mem_alloc(3 * sizeof(NJS_TEXLIST *)));
        ancient_container_fragment_texture_lists[0] = LoadPvmFileTls(fe_obj_o_container_r_texture);
        ancient_container_fragment_texture_lists[1] = LoadPvmFileTls(fe_obj_o_container_hahen01r_texture);
        ancient_container_fragment_texture_lists[2] = LoadPvmFileTls(fe_obj_o_container_hahen02r_texture);
    }
}

#pragma push
#pragma fp_contract on
void free_ancient_container_resources(void) {
    extern BmlResource *ancient_container_resource_bundle;
    s32 i;
    void *p;
    if (ancient_container_fragment_texture_lists != NULL) {
        i = 0;
        do {
            TObjPlayer::free_if_valid((saddr)ancient_container_fragment_texture_lists[i]);
            i += 1;
        } while (i < 3);
        p = ancient_container_fragment_texture_lists;
        if (p != NULL) {
            mem_free(p);
            ancient_container_fragment_texture_lists = NULL;
        }
    }
    BmlResource *resource = ancient_container_resource_bundle;
    if (resource != NULL) {
        delete resource;
        ancient_container_resource_bundle = NULL;
    }
}

#pragma pop

TOContainerAncientItem::TOContainerAncientItem(void *set_data) : TObjContainerBase(tl_05, set_data) {
    mode = 0;
    actorFlags |= 0x60000000U;
    init_collision_body_parts(this, &container_ancient_enemy_collision_body_params, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy(&body_center, &position);
    center.y += container_ancient_enemy_collision_body_params.offset.y;
    model = get_bml_model(ancient_container_resource_bundle, 0);
    texlist = get_bml_texlist(ancient_container_resource_bundle, 0);
}

TOContainerAncientItem::~TOContainerAncientItem() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TOContainerAncientItem::update_state() {
    switch (this->mode) {
    case 0:
        if (this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
        break;
    }
}

void TOContainerAncientItem::draw_model() {
    NJS_OBJECT *obj;
    NJS_OBJECT *child;
    NJS_OBJECT *sibling;
    if (ancient_container_resource_bundle != NULL) {
        switch (this->mode) {
        case 0:
            push_matrix();
            post_translate_matrix(&this->position.x);
            rotate_matrix_y(0, this->rotation_y);
            set_texture_list(this->texlist);
            obj = this->model;
            push_matrix();
            post_translate_matrix(obj->pos);
            draw_ginja_model(obj->model);
            child = obj->child;
            push_matrix();
            post_translate_matrix(child->pos);
            draw_ginja_model(child->model);
            pop_matrix();
            sibling = child->sibling;
            push_matrix();
            post_translate_matrix(sibling->pos);
            TParticleCtrl::begin_effect_render();
            draw_ginja_model(sibling->model);
            TParticleCtrl::end_effect_render();
            pop_matrix();
            pop_matrix();
            pop_matrix();
            break;
        }
    }
}

void TOContainerAncientItem::spawn_break_effects() const {
    if (this->mode == 1) {
        return;
    }
    TObjChipParams a = fish_break_debris_desc;
    a.pos.x = this->position.x;
    a.pos.y = this->position.y;
    a.pos.z = this->position.z;
    a.floor_y = a.pos.y;
    a.model = get_bml_model(ancient_container_resource_bundle, 1);
    a.textures = get_bml_texlist(ancient_container_resource_bundle, 1);
    TObjChipParams b = fish_break_debris_desc_b;
    b.pos.x = this->position.x;
    b.pos.y = this->position.y;
    b.pos.z = this->position.z;
    b.floor_y = b.pos.y;
    b.model = get_bml_model(ancient_container_resource_bundle, 2);
    b.textures = get_bml_texlist(ancient_container_resource_bundle, 2);
    if (check_value_equals(container_ancient_item_rare_name) != 0) {
        a.textures = ancient_container_fragment_texture_lists[1];
        b.textures = ancient_container_fragment_texture_lists[2];
    }
    new TObjChip(tl_05, &a);
    new TObjChip(tl_05, &b);
    spawn_particle_effect(&this->position, 0x45);
    spawn_particle_effect(&this->position, 0x46);
    play_container_break_sound(this);
}

TOContainerAncientItemCommon::TOContainerAncientItemCommon(void *set_data) : TOContainerAncientItem(set_data) {
    m_name = container_ancient_item_common_name;
}

TOContainerAncientItemCommon::~TOContainerAncientItemCommon() {
}

void *TOContainerAncientItemCommon::create(void *set_data) {
    if (((s32) enable_v2_features == 1) && (get_game_play_mode() == 1) && (is_quest_active() == 1)) {
        return new TOContainerAncientItemCommon(set_data);
    }
    return new TOContainerAncientItemCommon(set_data);
}

void TOContainerAncientItemCommon::apply_saved_state(s16 *state, s32 live) {
    if ((s16) *state == 1) {
        if (live != 0) {
            this->spawn_break_effects();
            request_configured_item_drop(this);
        }
        this->mode = 1;
        set_flag8();
        queue_destruction();
    }
}

TOContainerAncientItemRare::TOContainerAncientItemRare(void *set_data) : TOContainerAncientItem(set_data) {
    m_name = container_ancient_item_rare_name;
    texlist = ancient_container_fragment_texture_lists[0];
}

TOContainerAncientItemRare::~TOContainerAncientItemRare() {
}

void TOContainerAncientItemRare::apply_saved_state(s16 *state, s32 live) {
    if ((s16) *state == 1) {
        if (live != 0) {
            this->spawn_break_effects();
            request_box_item_drop(&position, 1);
        }
        this->mode = 1;
        set_flag8();
        queue_destruction();
    }
}

TOContainerAncientItemNone::TOContainerAncientItemNone(void *set_data) : TOContainerAncientItemRare(set_data) {
    m_name = container_ancient_item_none_name;
}

TOContainerAncientItemNone::~TOContainerAncientItemNone() {
}

void *TOContainerAncientItemNone::create(void *set_data) {
    return new TOContainerAncientItemNone(set_data);
}

void TOContainerAncientItemNone::apply_saved_state(s16 *state, s32 live) {
    if ((s16) *state == 1) {
        if (live != 0) {
            this->spawn_break_effects();
        }
        this->mode = 1;
        set_flag8();
        queue_destruction();
    }
}

TOContainerAncientEnemy::TOContainerAncientEnemy(void *set_data) : TObjContainerBase(tl_05, set_data) {
    m_name = container_ancient_enemy_name;
    mode = 0;
    actorFlags |= 0x60000000U;
    init_collision_body_parts(this, &container_ancient_enemy_collision_body_params, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy(&body_center, &position);
    center.y += container_ancient_enemy_collision_body_params.offset.y;
    model = get_bml_model(ancient_container_resource_bundle, 0);
    texlist = get_bml_texlist(ancient_container_resource_bundle, 0);
}

TOContainerAncientEnemy::~TOContainerAncientEnemy() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TOContainerAncientEnemy::update_state() {
    switch (this->mode) {
    case 0:
        if (this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
        break;
    }
}

void TOContainerAncientEnemy::draw_model() {
    NJS_OBJECT *obj;
    NJS_OBJECT *child;
    NJS_OBJECT *sibling;
    if (ancient_container_resource_bundle != NULL) {
        switch (this->mode) {
        case 0:
            push_matrix();
            post_translate_matrix(&this->position.x);
            rotate_matrix_y(0, this->rotation_y);
            set_texture_list(this->texlist);
            obj = this->model;
            push_matrix();
            post_translate_matrix(obj->pos);
            draw_ginja_model(obj->model);
            child = obj->child;
            push_matrix();
            post_translate_matrix(child->pos);
            draw_ginja_model(child->model);
            pop_matrix();
            sibling = child->sibling;
            push_matrix();
            post_translate_matrix(sibling->pos);
            TParticleCtrl::begin_effect_render();
            draw_ginja_model(sibling->model);
            TParticleCtrl::end_effect_render();
            pop_matrix();
            pop_matrix();
            pop_matrix();
            break;
        }
    }
}

void TOContainerAncientEnemy::debug_print_item_box_info() {
    set_debug_text_color(0xFF00FF);
    debug_printf_at(0x130020, ancient_enemy_event_format, this->set_params[0]);
    set_debug_text_color(0xF0F0F0FF);
    debug_draw_sphere(&this->position, &debug_color_blue_alpha30, ancient_container_debug_radius);
}

f32 TOContainerAncientEnemy::receive_physical_attack(TObjChara *, f32) {
    s16 saved_state;
    G_FloorEvent_6x67 pk;
    if (this->entity_id >= 0x1000U && this->set_entry != NULL && access_object_saved_state(&saved_state, 1) != 0) {
        saved_state = 1;
        access_object_saved_state(&saved_state, 0);
        send_object_state_update(&saved_state);
        pk.init();
        pk.header.client_id = this->entity_id;
        pk.floor = get_current_floor();
        pk.event_id = this->set_params[0];
        pk.sender_client_id = local_client_id;
        pk.send();
    }
    return ancient_container_zero;
}

void TOContainerAncientEnemy::spawn_break_effects() const {
    if (this->mode != 1) {
        TObjChipParams a = ancient_enemy_break_debris_desc;
        a.pos.x = this->position.x;
        a.pos.y = this->position.y;
        a.pos.z = this->position.z;
        a.floor_y = this->position.y;
        a.model = get_bml_model(ancient_container_resource_bundle, 1);
        a.textures = get_bml_texlist(ancient_container_resource_bundle, 1);
        TObjChipParams b = ancient_enemy_break_debris_desc_b;
        b.pos.x = this->position.x;
        b.pos.y = this->position.y;
        b.pos.z = this->position.z;
        b.floor_y = this->position.y;
        b.model = get_bml_model(ancient_container_resource_bundle, 2);
        b.textures = get_bml_texlist(ancient_container_resource_bundle, 2);
        if (check_value_equals(TOContainerAncientEnemyRare::class_name) != 0) {
            a.textures = ancient_container_fragment_texture_lists[1];
            b.textures = ancient_container_fragment_texture_lists[2];
        }
        spawn_particle_effect(&this->position, 0x45);
        spawn_particle_effect(&this->position, 0x46);
        new TObjChip(tl_05, &a);
        new TObjChip(tl_05, &b);
        play_container_break_sound(this);
    }
}

void TOContainerAncientEnemy::apply_saved_state(s16 *state, s32 live) {
    if ((s16) *state == 1) {
        if (live != 0) {
            this->spawn_break_effects();
        }
        this->mode = 1;
        set_flag8();
        queue_destruction();
    }
}

TOContainerAncientEnemyCommon::TOContainerAncientEnemyCommon(void *set_data) : TOContainerAncientEnemy(set_data) {
    m_name = container_ancient_enemy_common_name;
}

TOContainerAncientEnemyCommon::~TOContainerAncientEnemyCommon() {
}

void *TOContainerAncientEnemyCommon::create(void *set_data) {
    if (((s32) enable_v2_features == 1) && (get_game_play_mode() == 1) && (is_quest_active() == 1)) {
        return new TOContainerAncientEnemyCommon(set_data);
    }
    return new TOContainerAncientEnemyCommon(set_data);
}

TOContainerAncientEnemyRare::TOContainerAncientEnemyRare(void *set_data) : TOContainerAncientEnemy(set_data) {
    m_name = TOContainerAncientEnemyRare::class_name;
    texlist = *ancient_container_fragment_texture_lists;
}

TOContainerAncientEnemyRare::~TOContainerAncientEnemyRare() {
}


BmlResource *ancient_container_resource_bundle;
NJS_TEXLIST **ancient_container_fragment_texture_lists;
extern const f32 ancient_container_one = 1.0f;
extern const f32 ancient_container_zero = 0.0f;
extern const f32 ancient_container_debug_radius = 40.0f;
