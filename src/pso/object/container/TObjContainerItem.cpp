#include "pso/system/memory.h"
#include "pso/system/BmlAccessors.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/object/container/ContainerResources.h"
#include "pso/network/FloorEventCommand.h"
#include "pso/object/container/ContainerBreakEffects.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/object/TObjComputer.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/container/TObjContainerAbeEnemy.h"
#include "pso/map/FloorArea.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/network/TLobby.h"
#include "pso/object/key/TOKeyAncient01.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/unk/text_803DA798.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/object/TObjChip.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/player/TObjContainerCommon.h"
#include "pso/object/container/TObjContainerBase.h"
#include "pso/object/container/TObjContainerItem.h"
#include "pso/ui/window/TWindowKeyBoardHard_801FBA48.h"
#include "pso/object/container/TObjContainerNoItem.h"
#include "pso/object/container/TObjContainerEnemy.h"
#include "pso/object/base/TObjChara.h"
#include "pso/item/TItem.h"
#include "pso/render/NinjaUtil.h"

#include "pso/object/fence/TLazerFenceSw.h"
#include "pso/camera/CameraDistanceFade.h"
#include "pso/object/cave/TOAirconCave01.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/TMotorcycle.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/object/seabed/TObjSeabedSuisoBrakable.h"
#include "pso/object/container/TContainerAncient01.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/MatrixOps.h"


#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/render/DebugFont.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/GinjaTexture.h"
#include "pso/object/base/TObjCollidable.h"
#include "pso/network/client_id.h"
#include "pso/object/base/ActorCollision.h"

struct Item_80189E3C { u8 pad[0x30]; s32 data[3]; };

static const char *fe_obj_hako01_hahen02_model_names[4] = {
    "fe_obj_hako01_hahen02.gj", "fs_obj_hako01.gj", "fs_obj_hako01_hahen01.gj", NULL,
};
const char *fe_obj_hako01_hahen02_motion_names[1] = { NULL };
static BmlResourceDescriptor fe_obj_hako01_hahen02_resource_descriptor = {
    "fe_obj_hako01_hahen02.bml", fe_obj_hako01_hahen02_model_names, fe_obj_hako01_hahen02_motion_names, 3, 0,
};

static const char *fe_obj_con_hahen1_model_names[5] = {
    "fe_obj_con_hahen1.gj", "fe_obj_con_hahen2.gj", "fs_obj_con_body.gj", "fs_obj_con_crush1.gj", NULL,
};
const char *fe_obj_con_hahen1_motion_names[1] = { NULL };
static BmlResourceDescriptor fe_obj_con_hahen1_resource_descriptor = {
    "fe_obj_con_hahen1.bml", fe_obj_con_hahen1_model_names, fe_obj_con_hahen1_motion_names, 4, 0,
};

static const char *bm_obj_seabed_con_model_names[4] = {
    "obj_o_sea_container_hahen04.gj", "obj_o_sea_container.gj", "obj_o_sea_container_hahen03.gj", NULL,
};
const char *bm_obj_seabed_con_motion_names[1] = { NULL };
static BmlResourceDescriptor bm_obj_seabed_con_resource_descriptor = {
    "bm_obj_seabed_con.bml", bm_obj_seabed_con_model_names, bm_obj_seabed_con_motion_names, 3, 0,
};

static const char *bm_obj_seabed_con_rare_model_names[4] = {
    "obj_o_sea_container_hahen01_r.gj", "obj_o_sea_container_hahen02_r.gj", "obj_o_sea_container_r.gj", NULL,
};
const char *bm_obj_seabed_con_rare_motion_names[1] = { NULL };
static BmlResourceDescriptor bm_obj_seabed_con_rare_resource_descriptor = {
    "bm_obj_seabed_con_rare.bml", bm_obj_seabed_con_rare_model_names, bm_obj_seabed_con_rare_motion_names, 3, 0,
};

CollisionBody forest_box_collision_body_parts = {
    { 0.0f, 6.0f, 0.0f }, 9.0f, 9.0f, 0, 0x38003, { 0.0f, 0.0f, 0.0f }, 0.0f,
};

static TObjChipParams forest_box_break_params[4] = {
    { 0.5f, 0.03f, 0.2f, { 0.0f, 0.0f, 0.0f }, { 3.0f, 5.0f, 3.0f }, { 0x800, 0x100, 0x800 }, 7, 0x32, 0.0f, 1.0f, 0, 0, 0x16 },
    { 0.5f, 0.03f, 0.19f, { 0.0f, 0.0f, 0.0f }, { 3.5f, 5.0f, 3.5f }, { 0x400, 0x100, 0x400 }, 5, 0x32, 0.0f, 1.0f, 0, 0, 0x16 },
    { 0.5f, 0.03f, 0.2f, { 0.0f, 0.0f, 0.0f }, { 3.0f, 5.0f, 3.0f }, { 0x800, 0x100, 0x800 }, 7, 0x32, 0.0f, 0.5f, 0, 0, 0x16 },
    { 0.5f, 0.03f, 0.19f, { 0.0f, 0.0f, 0.0f }, { 3.5f, 5.0f, 3.5f }, { 0x400, 0x100, 0x400 }, 5, 0x32, 0.0f, 0.5f, 0, 0, 0x16 },
};

// TObjContainerBase's name (the containers' constructors install it)
const char *container_base_name = "TObjContainerBase";
const char *container_item_name = "TObjContainerItem";
const char *container_enemy_name = "TObjContainerEnemy";
const char *container_no_item_name = "TObjContainerNoItem";

extern const TObjChipParams container_break_particle_parameters = {
    0.5f, 0.07f, 0.26f, { 0.0f, 0.0f, 0.0f }, { 5.0f, 5.0f, 5.0f }, { 0x400, 0x100, 0x400 }, 5, 0x32, 0.0f, 0.6f, 0, 0, 0x14,
};
extern const TObjChipParams container_break_small_debris_parameters = {
    0.5f, 0.07f, 0.26f, { 0.0f, 0.0f, 0.0f }, { 4.0f, 4.5f, 4.0f }, { 0x200, 0x100, 0x200 }, 6, 0x32, 0.0f, 0.5f, 0, 0, 0x14,
};

const char *container_abe_enemy_name = "TObjContainerAbeEnemy";

extern const TObjChipParams container_break_debris_desc = {
    0.5f, 0.07f, 0.26f, { 0.0f, 0.0f, 0.0f }, { 5.0f, 5.0f, 5.0f }, { 0x400, 0x100, 0x400 }, 5, 0x32, 0.0f, 0.6f, 0, 0, 0x14,
};
extern const TObjChipParams container_break_debris_desc_b = {
    0.5f, 0.07f, 0.26f, { 0.0f, 0.0f, 0.0f }, { 4.0f, 4.5f, 4.0f }, { 0x200, 0x100, 0x200 }, 6, 0x32, 0.0f, 0.5f, 0, 0, 0x14,
};
static __declspec(section ".rodata") const char container_event_number_format[] ATTRIBUTE_ALIGN(4) = "EVT NO : %d";
static __declspec(section ".rodata") const char container_random_item_message[] ATTRIBUTE_ALIGN(4) = "<- RANDOM ITEM";
static __declspec(section ".rodata") const char container_fixed_item_message[] ATTRIBUTE_ALIGN(4) = "<- FIXED ITEM";
static __declspec(section ".rodata") const char container_item_parameter_message[] ATTRIBUTE_ALIGN(4) = "<- ITEM PARAM";


// Texture archive names for load_forest_box_resources. They stay outside this unit's
// .rodata claim: the original reaches them by address while pooling .data, and a stock
// compiler would pool them too if this unit defined them.
extern const char seabed_container_texture_filename[];
extern const char forest_box_texture_filename_a[];
extern const char forest_box_texture_filename_n[];
BmlResource *forest_box_model_archive;
NJS_TEXLIST *forest_box_textures;
TObjChipParams *forest_box_debris_primary;
TObjChipParams *forest_box_debris_secondary;
BmlResource *container_breakup_model_archive;
NJS_TEXLIST *container_breakup_textures;
extern const f32 container_item_debug_radius;
NJS_OBJECT *get_container_breakup_model(s32 index);
extern const f32 container_item_zero;
NJS_OBJECT *get_forest_box_model(s32 index);
extern const f32 container_item_model_scale;
extern const f32 forest_box_ginja_radius;
extern const f32 container_item_one;
extern const f32 container_item_view_range;
extern const f32 container_item_model_radius;
extern const f32 container_item_fade_distance;

// ---- TObjComputer


// Built with -inline off,deferred: the compiler emits the functions (and the
// vtables) last-to-first, so the definitions below run backwards from the
// original code order.
// ---- TObjContainerAbeEnemy
// ---- TObjContainerBase
// ---- TObjContainerNoItem
// ---- TObjContainerEnemy
// ---- TObjContainerItem
// ---- TLazerFenceSw

void CameraDistanceFade::set_fade_distance(f32 distance) { fade_distance = distance; }

void TObjContainerCommon::spawn_break_effects() const {  }

void TObjContainerCommon::update_state() {  }

void TObjContainerCommon::draw_model() {  }

void load_forest_box_resources(void) {
    BmlResource *bundle;
    NJS_OBJECT *node;
    forest_box_model_archive = NULL;
    forest_box_textures = NULL;
    switch (get_current_floor_area()) {
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
    case AREA_OLGA_FLOW:
        bundle = new BmlResource(5, &bm_obj_seabed_con_resource_descriptor, 0, 0, NULL);
        forest_box_model_archive = bundle;
        forest_box_textures = LoadPvmFileTls(seabed_container_texture_filename);
        forest_box_debris_primary = &forest_box_break_params[2];
        forest_box_debris_secondary = &forest_box_break_params[3];
        node = find_object_node(get_bml_model(forest_box_model_archive, 1), 2);
        if (node != NULL) {
            node->evalflags |= 0x100000;
        }
        break;
    default:
        bundle = new BmlResource(5, &fe_obj_hako01_hahen02_resource_descriptor, 0, 0, NULL);
        forest_box_model_archive = bundle;
        forest_box_textures = TLobby::is_online_ready() != 0 ? LoadPvmFileTls(forest_box_texture_filename_a) : LoadPvmFileTls(forest_box_texture_filename_n);
        forest_box_debris_primary = &forest_box_break_params[0];
        forest_box_debris_secondary = &forest_box_break_params[1];
        break;
    }
    TObjNpcEnemy::register_ginja(1, get_forest_box_model(1), forest_box_textures, forest_box_ginja_radius, container_item_zero);
}

void free_forest_box_resources() {
    if (forest_box_textures != NULL) {
        release_texture_list(forest_box_textures);
        safe_free(forest_box_textures);
        forest_box_textures = NULL;
    }
    if ((uaddr) forest_box_model_archive != 0U) {
        delete forest_box_model_archive;
        forest_box_model_archive = NULL;
    }
}

NJS_OBJECT *get_forest_box_model(s32 index) { return get_bml_model(forest_box_model_archive, index); }

void load_container_breakup_resources() {
    BmlResource *p;
    container_breakup_model_archive = 0;
    switch (get_current_floor_area()) {
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
    case AREA_OLGA_FLOW:
        p = new BmlResource(5, &bm_obj_seabed_con_rare_resource_descriptor, 0, 0, NULL);
        container_breakup_model_archive = p;
        container_breakup_textures = LoadPvmFileTls("obj_seabed_con_rare.gvm");
        break;
    case AREA_GAL_GRYPHON:
    default:
        p = new BmlResource(5, &fe_obj_con_hahen1_resource_descriptor, 0, 0, NULL);
        container_breakup_model_archive = p;
        container_breakup_textures = LoadPvmFileTls("obj_abecon.gvm");
        break;
    }
}

void free_container_breakup_resources() {
    if (container_breakup_textures != NULL) {
        release_texture_list(container_breakup_textures);
        safe_free(container_breakup_textures);
        container_breakup_textures = NULL;
    }
    if ((uaddr) container_breakup_model_archive != 0U) {
        delete container_breakup_model_archive;
        container_breakup_model_archive = NULL;
    }
}

NJS_OBJECT *get_container_breakup_model(s32 index) {
    return get_bml_model(container_breakup_model_archive, index);
}

#pragma push
#pragma fp_contract on
TObjContainerCommon::TObjContainerCommon(TObject *parent, void *set_data) : TObjChara(parent) {
    m_name = container_base_name;
    apply_object_set_data(set_data);
    view_range = container_item_view_range;
    model_radius = container_item_model_radius;
    melee_range_sq = container_item_view_range;
    if (scale.x > container_item_zero) {
        random_item = 1;
    } else {
        random_item = 0;
    }
    distance_fade.reset();
    distance_fade.set_fade_distance(container_item_fade_distance);
    in_view = 0;
}

#pragma pop

s32 TObjContainerCommon::select_melee_contact_body(TObjChara *target, f32) {
    return xyz_distance_squared(&((TObjBase *)target)->position, &position) < melee_range_sq;
}

f32 TObjContainerCommon::receive_direct_attack(TObjBase *attacker, DirectAttackPayload payload, CollisionBody *, s32, s32) {
    s32 kind;

    kind = payload.kind;
    if ((kind == 0) || ((kind - 1) <= 3U) || (kind == 0x13)) {
        receive_physical_attack(NULL, container_item_one);
    }
    return container_item_zero;
}

f32 TObjContainerCommon::receive_physical_attack(TObjChara *, f32) {
    s16 saved_state;
    if (((u16) this->entity_id >= 0x1000U) && (set_entry != NULL) && (this->access_object_saved_state(&saved_state, 1) != 0)) {
        saved_state = 1;
        this->access_object_saved_state(&saved_state, 0);
        this->send_object_state_update(&saved_state);
    }
    return container_item_zero;
}

void TObjContainerCommon::run_task() {
    distance_fade.step_fade();
    update_state();
    in_view = 0;
}

void TObjContainerCommon::render() {
    if (update_object_view_visibility(view_range, model_radius) != 1) {
        return;
    }
    in_view = 1;
    if (distance_fade.update_visibility(&position) != 1) {
        return;
    }
    if (distance_fade.is_translucent() == 1) {
        distance_fade.set_flags_and_apply_damage_color();
        draw_model();
        distance_fade.clear_flag_and_notify();
    } else {
        draw_model();
    }
}

#pragma pool_data off
void TObjContainerCommon::debug_print_item_box_info() {
    Item_80189E3C item;
    if (this->scale.x > container_item_zero) {
        this->random_item = 1;
    } else {
        this->random_item = 0;
    }
    if (this->random_item != 0) {
        set_debug_text_color(0xFFFFFF);
        debug_printf_at(0x13001C, container_random_item_message);
    } else {
        set_debug_text_color(0xFF00FF);
        debug_printf_at(0x13001C, container_fixed_item_message);
        debug_printf_at(0x130020, container_item_parameter_message);
        item.data[0] = set_params[0];
        item.data[1] = set_params[1];
        item.data[2] = set_params[2];
        debug_print_item_param(&item);
    }
    set_debug_text_color(0xF0F0F0FF);
}
#pragma pool_data reset

void play_container_break_sound(const TObjContainerCommon *container) {
    u32 area;
    area = get_current_floor_area();
    switch (area) {
    case AREA_FOREST1:
    case AREA_FOREST2:
        play_sound_effect(0x4BC10, &container->position, 0, 0);
        return;
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        play_sound_effect(0x43C0F, &container->position, 0, 0);
        return;
    case AREA_MINE1:
    case AREA_MINE2:
        play_sound_effect(0x4004BC09, &container->position, 0, 0);
        return;
    case AREA_RUINS1:
    case AREA_RUINS2:
    case AREA_RUINS3:
        play_sound_effect(0x4004BC10, &container->position, 0, 0);
        return;
    case AREA_BATTLE1:
    case AREA_BATTLE2:
        play_sound_effect(0x4004BC05, &container->position, 0, 0);
        return;
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        play_sound_effect(0x4BC05, &container->position, 0, 0);
        return;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_sound_effect(0x4004BC05, &container->position, 0, 0);
        return;
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
        play_sound_effect(0x4BC16, &container->position, 0, 0);
        return;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4004BC16, &container->position, 0, 0);
        return;
    case AREA_SEASIDE_NIGHT:
        play_sound_effect(0x4004BC16, &container->position, 0, 0);
        return;
    case AREA_TOWER:
        play_sound_effect(0x4004BC16, &container->position, 0, 0);
    default:
        return;
    }
}

void TObjContainerCommon::request_configured_item_drop(TObjContainerCommon *container) {
    container->request_box_item_drop(&position, random_item);
}

TObjContainerItem::TObjContainerItem(TObject *parent, void *set_data) : TObjContainerCommon(parent, set_data) {
    m_name = container_item_name;
    model = get_forest_box_model(1);
    mode = 0;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, &forest_box_collision_body_parts, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy(&body_center, &position);
    center.y += forest_box_collision_body_parts.offset.y;
}

TObjContainerItem::~TObjContainerItem() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TObjContainerItem::create(void *set_data) {
    return new TObjContainerItem(tl_05, set_data);
}

void TObjContainerItem::update_state() {

    switch (this->mode) {
    case 0:
        if ((s32) this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void TObjContainerItem::draw_model() {
    if (forest_box_model_archive != 0) {
        switch (mode) {
        case 0:
            set_texture_list(forest_box_textures);
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, rotation_y);
            scale_matrix(0, container_item_model_scale, container_item_model_scale, container_item_model_scale);
            draw_ginja_box_tree(model);
            pop_matrix();
            break;
        case 1:
            break;
        }
    }
}

void TObjContainerItem::spawn_break_effects() const {
    if (this->mode != 1) {
        TObjChipParams a = *forest_box_debris_primary;
        TObjChipParams b = *forest_box_debris_secondary;
        VecCopy(&a.pos, &position);
        a.floor_y = position.y;
        a.model = get_forest_box_model(2);
        a.textures = forest_box_textures;
        VecCopy(&b.pos, &position);
        b.floor_y = position.y;
        b.model = get_forest_box_model(0);
        b.textures = forest_box_textures;
        spawn_particle_effect_with_flags(&position, 0x45, 0x40);
        spawn_particle_effect_with_flags(&position, 0x46, 0x40);
        new TObjChip(tl_05, &a);
        new TObjChip(tl_05, &b);
        play_container_break_sound(this);
    }
}

void TObjContainerItem::apply_saved_state(s16 *state, s32 live) {
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

TObjContainerEnemy::TObjContainerEnemy(TObject *parent, void *set_data) : TObjContainerCommon(parent, set_data) {
    m_name = container_enemy_name;
    model = get_forest_box_model(1);
    mode = 0;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, &forest_box_collision_body_parts, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy(&body_center, &position);
    center.y += forest_box_collision_body_parts.offset.y;
}

TObjContainerEnemy::~TObjContainerEnemy() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TObjContainerEnemy::create(void *set_data) {
    return new TObjContainerEnemy(tl_05, set_data);
}

void TObjContainerEnemy::update_state() {

    switch (this->mode) {
    case 0:
        if ((s32) this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void TObjContainerEnemy::draw_model() {
    if (forest_box_model_archive == 0) {
        return;
    }
    switch (mode) {
    case 0:
        set_texture_list(forest_box_textures);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        scale_matrix(0, container_item_model_scale, container_item_model_scale, container_item_model_scale);
        draw_ginja_box_tree(model);
        pop_matrix();
        break;
    case 1:
        break;
    }
}

void TObjContainerEnemy::debug_print_item_box_info() {
    set_debug_text_color(0xFF00FF);
    debug_printf_at(0x130020, container_event_number_format, this->set_params[0]);
    set_debug_text_color(0xF0F0F0FF);
    debug_draw_sphere(&position, &debug_color_blue_alpha30, container_item_debug_radius);
}

f32 TObjContainerEnemy::receive_physical_attack(TObjChara *, f32) {
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
    return container_item_zero;
}

void TObjContainerEnemy::spawn_break_effects() const {
    if (this->mode != 1) {
        TObjChipParams a = *forest_box_debris_primary;
        TObjChipParams b = *forest_box_debris_secondary;
        VecCopy(&a.pos, &position);
        a.floor_y = position.y;
        a.model = get_forest_box_model(2);
        a.textures = forest_box_textures;
        VecCopy(&b.pos, &position);
        b.floor_y = position.y;
        b.model = get_forest_box_model(0);
        b.textures = forest_box_textures;
        spawn_particle_effect_with_flags(&position, 0x45, 0x40);
        spawn_particle_effect_with_flags(&position, 0x46, 0x40);
        new TObjChip(tl_05, &a);
        new TObjChip(tl_05, &b);
        play_container_break_sound(this);
    }
}

void TObjContainerEnemy::apply_saved_state(s16 *state, s32 live) {
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

TObjContainerNoItem::TObjContainerNoItem(TObject *parent, void *set_data) : TObjContainerCommon(parent, set_data) {
    m_name = container_no_item_name;
    model = get_forest_box_model(1);
    mode = 0;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, &forest_box_collision_body_parts, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy(&body_center, &position);
    center.y += forest_box_collision_body_parts.offset.y;
}

TObjContainerNoItem::~TObjContainerNoItem() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TObjContainerNoItem::create(void *set_data) {
    return new TObjContainerNoItem(tl_05, set_data);
}

void TObjContainerNoItem::update_state() {

    switch (this->mode) {
    case 0:
        if ((s32) this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void TObjContainerNoItem::draw_model() {
    if (forest_box_model_archive != 0U) {
        switch (this->mode) {
        case 1:
            break;
        case 0:
        set_texture_list(forest_box_textures);
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(0, this->rotation_y);
        scale_matrix(0, container_item_model_scale, container_item_model_scale, container_item_model_scale);
        draw_ginja_box_tree((NJS_OBJECT *)(*(saddr *)((s8 *)this + 0x34)));
        pop_matrix();
            break;
        }
    }
}

f32 TObjContainerNoItem::receive_physical_attack(TObjChara *, f32) {
    s16 saved_state;
    if (((u16) this->entity_id >= 0x1000U) && (set_entry != NULL) && (this->access_object_saved_state(&saved_state, 1) != 0)) {
        saved_state = 1;
        this->access_object_saved_state(&saved_state, 0);
        this->send_object_state_update(&saved_state);
    }
    return container_item_zero;
}

void TObjContainerNoItem::spawn_break_effects() const {
    if (this->mode != 1) {
        TObjChipParams a = *forest_box_debris_primary;
        TObjChipParams b = *forest_box_debris_secondary;
        VecCopy(&a.pos, &position);
        a.floor_y = position.y;
        a.model = get_forest_box_model(2);
        a.textures = forest_box_textures;
        VecCopy(&b.pos, &position);
        b.floor_y = position.y;
        b.model = get_forest_box_model(0);
        b.textures = forest_box_textures;
        spawn_particle_effect_with_flags(&position, 0x45, 0x40);
        spawn_particle_effect_with_flags(&position, 0x46, 0x40);
        new TObjChip(tl_05, &a);
        new TObjChip(tl_05, &b);
        play_container_break_sound(this);
    }
}

void TObjContainerNoItem::apply_saved_state(s16 *state, s32 live) {
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

TObjContainerBase::TObjContainerBase(TObject *parent, void *set_data) : TObjContainerCommon(parent, set_data) {
    m_name = container_base_name;
    mode = 0;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, &forest_box_collision_body_parts, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy(&body_center, &position);
    center.y += forest_box_collision_body_parts.offset.y;
}

TObjContainerBase::~TObjContainerBase() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjContainerBase::update_state() {

    switch (this->mode) {
    case 0:
        if ((s32) this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void TObjContainerBase::draw_model() {
    if (container_breakup_model_archive != 0) {
        switch (this->mode) {
        case 0:
            set_texture_list(container_breakup_textures);
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, this->rotation_y);
            draw_ginja_box_tree(get_container_breakup_model(2));
            pop_matrix();
            break;
        case 1:
            break;
        }
    }
}

#pragma push
#pragma opt_propagation off
void TObjContainerBase::spawn_break_effects() const {
    TObjChipParams a = container_break_particle_parameters;
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
    a.model = get_container_breakup_model(0);
    a.textures = container_breakup_textures;
    TObjChipParams b = container_break_small_debris_parameters;
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
    b.model = get_container_breakup_model(1);
    b.textures = container_breakup_textures;
    spawn_particle_effect_with_flags(&position, 0x45, 0x40);
    spawn_particle_effect_with_flags(&position, 0x46, 0x40);
    new TObjChip(tl_05, &a);
    new TObjChip(tl_05, &b);
    play_container_break_sound(this);
}

#pragma pop

void TObjContainerBase::apply_saved_state(s16 *state, s32 live) {
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

void *TObjContainerBase::create(void *set_data) {
    return new TObjContainerBase(tl_05, set_data);
}

TObjContainerAbeEnemy::TObjContainerAbeEnemy(TObject *parent, void *set_data) : TObjContainerCommon(parent, set_data) {
    m_name = container_abe_enemy_name;
    mode = 0;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, &forest_box_collision_body_parts, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy(&body_center, &position);
    center.y += forest_box_collision_body_parts.offset.y;
}

TObjContainerAbeEnemy::~TObjContainerAbeEnemy() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjContainerAbeEnemy::update_state() {

    switch (this->mode) {
    case 0:
        if ((s32) this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void TObjContainerAbeEnemy::draw_model() {
    if (container_breakup_model_archive != 0) {
        switch (this->mode) {
        case 0:
            set_texture_list(container_breakup_textures);
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, this->rotation_y);
            draw_ginja_box_tree(get_container_breakup_model(2));
            pop_matrix();
            break;
        case 1:
            break;
        }
    }
}

void TObjContainerAbeEnemy::debug_print_item_box_info() {
    set_debug_text_color(0xFF00FF);
    debug_printf_at(0x130020, container_event_number_format, this->set_params[0]);
    set_debug_text_color(0xF0F0F0FF);
    debug_draw_sphere(&position, &debug_color_blue_alpha30, container_item_debug_radius);
}

f32 TObjContainerAbeEnemy::receive_physical_attack(TObjChara *, f32) {
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
    return container_item_zero;
}

#pragma push
#pragma opt_propagation off
void TObjContainerAbeEnemy::spawn_break_effects() const {
    if (this->mode != 1) {
        TObjChipParams a = container_break_debris_desc;
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
        a.model = get_container_breakup_model(0);
        a.textures = container_breakup_textures;
        TObjChipParams b = container_break_debris_desc_b;
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
        b.model = get_container_breakup_model(1);
        b.textures = container_breakup_textures;
        spawn_particle_effect_with_flags(&position, 0x45, 0x40);
        spawn_particle_effect_with_flags(&position, 0x46, 0x40);
        new TObjChip(tl_05, &a);
        new TObjChip(tl_05, &b);
        play_container_break_sound(this);
    }
}

#pragma pop

void TObjContainerAbeEnemy::apply_saved_state(s16 *state, s32 live) {
    if (live != 0) {
        if ((s16) *state == 1) {
            this->spawn_break_effects();
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


extern const f32 container_item_one = 1.0f;
extern const f32 container_item_zero = 0.0f;
extern const f32 container_item_debug_radius = 40.0f;
extern const f32 container_item_model_scale = 0.85f;
extern const f32 container_item_view_range = 400.0f;
extern const f32 container_item_model_radius = 10.0f;
extern const f32 container_item_fade_distance = 300.0f;
extern const f32 forest_box_ginja_radius = 9.0f;
