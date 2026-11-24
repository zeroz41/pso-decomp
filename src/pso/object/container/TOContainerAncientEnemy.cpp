#include "pso/system/memory.h"
#include "pso/system/BmlAccessors.h"
#include "pso/network/FloorEventCommand.h"
#include "pso/object/container/ContainerBreakEffects.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/render/render_util.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/vector.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/byteswap.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/TLanguage.h"
#include "pso/map/FloorArea.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/player/TUnk_804B08BC.h"
#include "pso/object/container/TOContainerAncientEnemy.h"
#include "pso/object/container/TOContainerAncientEnemyCommon.h"
#include "pso/object/container/TOContainerAncientEnemyRare.h"
#include "pso/object/container/TOContainerAncientItemRare.h"
#include "pso/object/container/TOContainerAncientItemNone.h"
#include "pso/object/container/TOContainerAncientItemCommon.h"
#include "pso/object/container/TObjContainerBase.h"
#include "pso/object/container/TObjContainerItem.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/CameraDistanceFade.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/cave/TOAirconCave01.h"
#include "pso/object/TObjChip.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_8015C534.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/BmlResource.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_801542CC.h"
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

struct AncientContainerBml {
    const char *model_filenames[4];
    BmlResourceDescriptor descriptor;
};
LAYOUT_ASSERT(AncientContainerBmlSize, sizeof(AncientContainerBml) == 0x20);
LAYOUT_ASSERT(AncientContainerBmlDescriptorOffset, offsetof(AncientContainerBml, descriptor) == 0x10);

// The 6x67 packet receive_physical_attack sends (its fields are not named yet).
extern const f32 lbl_805DB398;
extern const f32 lbl_805DB39C;
extern const f32 lbl_805DB3A0;

const char *bm_o_container_ancient_motion_names[1] = { NULL };
const char *fe_obj_o_vs2container_motion_names[1] = { NULL };
const char *fe_obj_ex_box1_motion_names[1] = { NULL };
AncientContainerBml bm_o_container_ancient_resource_bundle = { { ancient_container_model, ancient_container_fragment1_model, ancient_container_fragment2_model, NULL }, { ancient_container_bml, bm_o_container_ancient_resource_bundle.model_filenames, bm_o_container_ancient_motion_names, 3, 0 } };
AncientContainerBml fe_obj_o_vs2container_resource_bundle = { { vs2_container_fragment1_model, vs2_container_fragment2_model, vs2_container_model, NULL }, { vs2_container_bml, fe_obj_o_vs2container_resource_bundle.model_filenames, fe_obj_o_vs2container_motion_names, 3, 0 } };
AncientContainerBml fe_obj_ex_box1_resource_bundle = { { ep2_box_model, ep2_box_fragment1_model, ep2_box_fragment2_model, NULL }, { "fe_obj_ex_box1.bml", fe_obj_ex_box1_resource_bundle.model_filenames, fe_obj_ex_box1_motion_names, 3, 0 } };
CollisionBody TOContainerAncientEnemy__collision_body_params = { { 0.0f, 6.5f, 0.0f }, 7.5f, 7.5f, 0, 0x38003, { 0.0f, 0.0f, 0.0f }, 0.0f };

const char *TOContainerAncientItemCommon__name = "TOContainerAncientItemCommon";
const char *TOContainerAncientItemRare__name = "TOContainerAncientItemRare";
const char *TOContainerAncientItemNone__name = "TOContainerAncientItemNone";
const char *TOContainerAncientEnemy__name = "TOContainerAncientEnemy";
const char *TOContainerAncientEnemyCommon__name = "TOContainerAncientEnemyCommon";
const char *lbl_805D2F10 = "TOContainerAncientEnemyRare";

// The three fragment texture lists of the current floor, loaded with the
// archive (ancient_container_resource_bundle) by
// TLanguage::load_container_fragment_textures. Both share one 8-aligned
// .sbss block (0x805D58E8) that stays unclaimed until the bundle can be
// defined here (see vfunc_79).
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

void TUnk_804B6C24::vfunc_6(s16 *, s32) {  }

TUnk_804B6C24::~TUnk_804B6C24() {
}

s32 TUnk_804B6C24::roll_physical_accuracy(void *, s32, f32) { return 1; }

s32 TUnk_804B6C24::try_start_action(s32, s32) { return 1; }

void TUnk_804B6C24::apply_knockback_from_attacker(u8 *, f32) {  }

f32 TUnk_804B6C24::receive_weapon_special_attack(void *, void *) {
    receive_physical_attack(NULL, lbl_805DB398);
    return lbl_805DB39C;
}

int TUnk_804B6C24::calc_distance_accuracy_penalty(void *, void *, void *, float) { return 1; }

extern BmlResource *ancient_container_resource_bundle;

void TLanguage::load_container_fragment_textures() {
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
        ancient_container_fragment_texture_lists[0] = load_gvm_texture_file(fs_obj_ex_box2_texture);
        ancient_container_fragment_texture_lists[1] = load_gvm_texture_file(fe_obj_ex_box2_hahen01_texture);
        ancient_container_fragment_texture_lists[2] = load_gvm_texture_file(fe_obj_ex_box2_hahen02_texture);
    } else if (enable_v2_features == 1 &&
               (area == AREA_BATTLE2 || area == AREA_VR_TEMPLE_ALPHA || area == AREA_VR_TEMPLE_BETA || area == AREA_BARBA_RAY)) {
        p = new BmlResource(1, reinterpret_cast<BmlResourceDescriptor *>(table + stride + descriptor_offset), 0, 0, NULL);
        ancient_container_resource_bundle = p;
        ancient_container_fragment_texture_lists = static_cast<NJS_TEXLIST **>(mem_alloc(3 * sizeof(NJS_TEXLIST *)));
        ancient_container_fragment_texture_lists[0] = load_gvm_texture_file(fs_obj_o_vs2container_r_texture);
        ancient_container_fragment_texture_lists[1] = load_gvm_texture_file(fe_obj_o_vs2cont_hahen1_r_texture);
        ancient_container_fragment_texture_lists[2] = load_gvm_texture_file(fe_obj_o_vs2cont_hahen2_r_texture);
    } else {
        p = new BmlResource(1, reinterpret_cast<BmlResourceDescriptor *>(table + descriptor_offset), 0, 0, NULL);
        ancient_container_resource_bundle = p;
        ancient_container_fragment_texture_lists = static_cast<NJS_TEXLIST **>(mem_alloc(3 * sizeof(NJS_TEXLIST *)));
        ancient_container_fragment_texture_lists[0] = load_gvm_texture_file(fe_obj_o_container_r_texture);
        ancient_container_fragment_texture_lists[1] = load_gvm_texture_file(fe_obj_o_container_hahen01r_texture);
        ancient_container_fragment_texture_lists[2] = load_gvm_texture_file(fe_obj_o_container_hahen02r_texture);
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

TUnk_804B08BC::TUnk_804B08BC(void *set_data) : TUnk_804B6C24(tl_05, set_data) {
    mode = 0;
    actorFlags |= 0x60000000U;
    init_collision_body_parts(this, &TOContainerAncientEnemy__collision_body_params, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy(&body_center, &position);
    center.y += TOContainerAncientEnemy__collision_body_params.offset.y;
    model = (void *)get_bml_model((BmlResource *)ancient_container_resource_bundle, 0);
    texlist = get_bml_texlist((BmlResource *)ancient_container_resource_bundle, 0);
}

TUnk_804B08BC::~TUnk_804B08BC() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TUnk_804B08BC::vfunc_80() {
    switch (this->mode) {
    case 0:
        if (this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
        break;
    }
}

void TUnk_804B08BC::vfunc_81() {
    NJS_OBJECT *obj;
    NJS_OBJECT *child;
    NJS_OBJECT *sibling;
    if (ancient_container_resource_bundle != NULL) {
        switch (this->mode) {
        case 0:
            push_matrix();
            post_translate_matrix(&this->position.x);
            rotate_matrix_y(0, this->rotation_y);
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
            obj = (NJS_OBJECT *)this->model;
            push_matrix();
            post_translate_matrix(obj->pos);
            draw_ginja_model((void *)obj->model);
            child = obj->child;
            push_matrix();
            post_translate_matrix(child->pos);
            draw_ginja_model((void *)child->model);
            pop_matrix();
            sibling = child->sibling;
            push_matrix();
            post_translate_matrix(sibling->pos);
            TParticleCtrl::begin_effect_render();
            draw_ginja_model((void *)sibling->model);
            TParticleCtrl::end_effect_render();
            pop_matrix();
            pop_matrix();
            pop_matrix();
            break;
        }
    }
}

void TUnk_804B08BC::vfunc_79() const {
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
    if (check_value_equals(TOContainerAncientItemRare__name) != 0) {
        a.textures = ancient_container_fragment_texture_lists[1];
        b.textures = ancient_container_fragment_texture_lists[2];
    }
    new TObjChip(tl_05, &a);
    new TObjChip(tl_05, &b);
    spawn_particle_effect(&this->position, 0x45);
    spawn_particle_effect(&this->position, 0x46);
    play_container_break_sound(this);
}

TOContainerAncientItemCommon::TOContainerAncientItemCommon(void *set_data) : TUnk_804B08BC(set_data) {
    m_name = TOContainerAncientItemCommon__name;
}

TOContainerAncientItemCommon::~TOContainerAncientItemCommon() {
}

void *TOContainerAncientItemCommon::create(void *set_data) {
    if (((s32) enable_v2_features == 1) && (get_game_play_mode() == 1) && (is_quest_active() == 1)) {
        return new TOContainerAncientItemCommon(set_data);
    }
    return new TOContainerAncientItemCommon(set_data);
}

void TOContainerAncientItemCommon::vfunc_6(s16 *arg1, s32 arg2) {
    if ((s16) *arg1 == 1) {
        if (arg2 != 0) {
            this->vfunc_79();
            request_configured_item_drop(this);
        }
        this->mode = 1;
        set_flag8();
        queue_destruction();
    }
}

TOContainerAncientItemRare::TOContainerAncientItemRare(void *set_data) : TUnk_804B08BC(set_data) {
    m_name = TOContainerAncientItemRare__name;
    texlist = ancient_container_fragment_texture_lists[0];
}

TOContainerAncientItemRare::~TOContainerAncientItemRare() {
}

void TOContainerAncientItemRare::vfunc_6(s16 *arg1, s32 arg2) {
    if ((s16) *arg1 == 1) {
        if (arg2 != 0) {
            this->vfunc_79();
            request_box_item_drop(&position, 1);
        }
        this->mode = 1;
        set_flag8();
        queue_destruction();
    }
}

TOContainerAncientItemNone::TOContainerAncientItemNone(void *set_data) : TOContainerAncientItemRare(set_data) {
    m_name = TOContainerAncientItemNone__name;
}

TOContainerAncientItemNone::~TOContainerAncientItemNone() {
}

void *TOContainerAncientItemNone::create(void *set_data) {
    return new TOContainerAncientItemNone(set_data);
}

void TOContainerAncientItemNone::vfunc_6(s16 *arg1, s32 arg2) {
    if ((s16) *arg1 == 1) {
        if (arg2 != 0) {
            this->vfunc_79();
        }
        this->mode = 1;
        set_flag8();
        queue_destruction();
    }
}

TOContainerAncientEnemy::TOContainerAncientEnemy(void *set_data) : TUnk_804B6C24(tl_05, set_data) {
    m_name = TOContainerAncientEnemy__name;
    mode = 0;
    actorFlags |= 0x60000000U;
    init_collision_body_parts(this, &TOContainerAncientEnemy__collision_body_params, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy(&body_center, &position);
    center.y += TOContainerAncientEnemy__collision_body_params.offset.y;
    model = (void *)get_bml_model((BmlResource *)ancient_container_resource_bundle, 0);
    texlist = get_bml_texlist((BmlResource *)ancient_container_resource_bundle, 0);
}

TOContainerAncientEnemy::~TOContainerAncientEnemy() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TOContainerAncientEnemy::vfunc_80() {
    switch (this->mode) {
    case 0:
        if (this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
        break;
    }
}

void TOContainerAncientEnemy::vfunc_81() {
    NJS_OBJECT *obj;
    NJS_OBJECT *child;
    NJS_OBJECT *sibling;
    if (ancient_container_resource_bundle != NULL) {
        switch (this->mode) {
        case 0:
            push_matrix();
            post_translate_matrix(&this->position.x);
            rotate_matrix_y(0, this->rotation_y);
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
            obj = (NJS_OBJECT *)this->model;
            push_matrix();
            post_translate_matrix(obj->pos);
            draw_ginja_model((void *)obj->model);
            child = obj->child;
            push_matrix();
            post_translate_matrix(child->pos);
            draw_ginja_model((void *)child->model);
            pop_matrix();
            sibling = child->sibling;
            push_matrix();
            post_translate_matrix(sibling->pos);
            TParticleCtrl::begin_effect_render();
            draw_ginja_model((void *)sibling->model);
            TParticleCtrl::end_effect_render();
            pop_matrix();
            pop_matrix();
            pop_matrix();
            break;
        }
    }
}

void TOContainerAncientEnemy::debug_print_item_box_info() {
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, ancient_enemy_event_format, this->set_params[0]);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    debug_draw_sphere(&this->position, &debug_color_blue_alpha30, lbl_805DB3A0);
}

f32 TOContainerAncientEnemy::receive_physical_attack(void *, f32) {
    s16 sp8;
    G_FloorEvent_6x67 pk;
    if (this->entity_id >= 0x1000U && this->set_entry != NULL && access_object_saved_state(&sp8, 1) != 0) {
        sp8 = 1;
        access_object_saved_state(&sp8, 0);
        send_object_state_update(&sp8);
        pk.init();
        pk.header.client_id = this->entity_id;
        pk.floor = get_current_floor();
        pk.event_id = this->set_params[0];
        pk.sender_client_id = local_client_id;
        pk.send();
    }
    return lbl_805DB39C;
}

void TOContainerAncientEnemy::vfunc_79() const {
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
        if (check_value_equals(lbl_805D2F10) != 0) {
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

void TOContainerAncientEnemy::vfunc_6(s16 *arg1, s32 arg2) {
    if ((s16) *arg1 == 1) {
        if (arg2 != 0) {
            this->vfunc_79();
        }
        this->mode = 1;
        set_flag8();
        queue_destruction();
    }
}

TOContainerAncientEnemyCommon::TOContainerAncientEnemyCommon(void *set_data) : TOContainerAncientEnemy(set_data) {
    m_name = TOContainerAncientEnemyCommon__name;
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
    m_name = lbl_805D2F10;
    texlist = *ancient_container_fragment_texture_lists;
}

TOContainerAncientEnemyRare::~TOContainerAncientEnemyRare() {
}


BmlResource *ancient_container_resource_bundle;
NJS_TEXLIST **ancient_container_fragment_texture_lists;
extern const f32 lbl_805DB398 = 1.0f;
extern const f32 lbl_805DB39C = 0.0f;
extern const f32 lbl_805DB3A0 = 40.0f;
