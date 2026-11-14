#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
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
#include "pso/object/container/TOContainerAncientItemNone_8015BF38.h"
#include "pso/object/container/TOContainerAncientItemCommon.h"
#include "pso/object/container/TObjContainerBase.h"
#include "pso/object/container/TObjContainerItem.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/CameraDistanceFade.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_8015C944.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/cave/TOAirconCave01.h"
#include "pso/object/TObjChip.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_8015C048.h"
#include "pso/unk/text_8015C534.h"
#include "pso/unk/text_8018A150.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/network/client_id.h"
#include "pso/network/TProtocol.h"
#include "pso/system/task/TObject.h"

struct BmlResourceBlock_804B0068 { const char *model_filenames[4]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B0068_size[(sizeof(BmlResourceBlock_804B0068) == 0x20) ? 1 : -1];
typedef char BmlResourceBlock_804B0068_descriptor_offset[(offsetof(BmlResourceBlock_804B0068, descriptor) == 0x10) ? 1 : -1];
struct BmlResourceBlock_804B0088 { const char *model_filenames[4]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B0088_size[(sizeof(BmlResourceBlock_804B0088) == 0x20) ? 1 : -1];
typedef char BmlResourceBlock_804B0088_descriptor_offset[(offsetof(BmlResourceBlock_804B0088, descriptor) == 0x10) ? 1 : -1];
struct BmlResourceBlock_804B00A8 { const char *model_filenames[4]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B00A8_size[(sizeof(BmlResourceBlock_804B00A8) == 0x20) ? 1 : -1];
typedef char BmlResourceBlock_804B00A8_descriptor_offset[(offsetof(BmlResourceBlock_804B00A8, descriptor) == 0x10) ? 1 : -1];

// The 6x67 packet receive_physical_attack sends (its fields are not named yet).
struct Pk_8015BAE0 { u8 pad[2]; u16 id; s32 a; s32 b; s32 c; };

void play_container_break_sound(s32 arg0);

extern "C" {

extern s32 __vt__27TOContainerAncientEnemyRare[];
extern s32 __vt__29TOContainerAncientEnemyCommon[];
extern s32 __vt__23TOContainerAncientEnemy[];
extern s32 __vt__26TOContainerAncientItemNone[];
extern s32 __vt__26TOContainerAncientItemRare[];
extern s32 __vt__28TOContainerAncientItemCommon[];
extern s32 lbl_804B08BC[];
extern s32 lbl_804B6C24[];

extern const f32 lbl_805DB398;
extern const f32 lbl_805DB39C;
extern const f32 lbl_805DB3A0;

const char *bm_o_container_ancient_motion_names[1] = { NULL };
const char *fe_obj_o_vs2container_motion_names[1] = { NULL };
const char *fe_obj_ex_box1_motion_names[1] = { NULL };
BmlResourceBlock_804B0068 bm_o_container_ancient_resource_bundle = { { "fe_obj_o_container.gj", "fe_obj_o_container_hahen01.gj", "fe_obj_o_container_hahen02.gj", NULL }, { "bm_o_container_ancient.bml", bm_o_container_ancient_resource_bundle.model_filenames, bm_o_container_ancient_motion_names, 3, 0 } };
BmlResourceBlock_804B0088 fe_obj_o_vs2container_resource_bundle = { { "fe_obj_o_vs2container_hahen1.gj", "fe_obj_o_vs2container_hahen2.gj", "fs_obj_o_vs2container.gj", NULL }, { "fe_obj_o_vs2container.bml", fe_obj_o_vs2container_resource_bundle.model_filenames, fe_obj_o_vs2container_motion_names, 3, 0 } };
BmlResourceBlock_804B00A8 fe_obj_ex_box1_resource_bundle = { { "fs_obj_ex_box1.gj", "fe_obj_ex_box1_hahen01.gj", "fe_obj_ex_box1_hahen02.gj", NULL }, { "fe_obj_ex_box1.bml", fe_obj_ex_box1_resource_bundle.model_filenames, fe_obj_ex_box1_motion_names, 3, 0 } };
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
extern u32 *ancient_container_fragment_texture_lists;

static const TObjChipParams fish_break_debris_desc = {
    { 0.5f, 0.07f, 0.26f }, { 0.0f, 0.0f, 0.0f }, { 5.0f, 5.0f, 5.0f }, { 0x400, 0x100, 0x400 }, { 5, 0x32 }, { 0.0f, 0.6f }, 0, 0, 0x16,
};
static const TObjChipParams lbl_8044074C = {
    { 0.5f, 0.07f, 0.26f }, { 0.0f, 0.0f, 0.0f }, { 4.0f, 4.5f, 4.0f }, { 0x200, 0x100, 0x200 }, { 6, 0x32 }, { 0.0f, 0.5f }, 0, 0, 0x16,
};
static const TObjChipParams ancient_enemy_break_debris_desc = {
    { 0.5f, 0.07f, 0.26f }, { 0.0f, 0.0f, 0.0f }, { 5.0f, 5.0f, 5.0f }, { 0x400, 0x100, 0x400 }, { 5, 0x32 }, { 0.0f, 0.6f }, 0, 0, 0x16,
};
static const TObjChipParams ancient_enemy_break_debris_desc_b = {
    { 0.5f, 0.07f, 0.26f }, { 0.0f, 0.0f, 0.0f }, { 4.0f, 4.5f, 4.0f }, { 0x200, 0x100, 0x200 }, { 6, 0x32 }, { 0.0f, 0.5f }, 0, 0, 0x16,
};

TOContainerAncientEnemy *TOContainerAncientEnemy__ct(TOContainerAncientEnemy *container, s32 arg1);
u8 *TOContainerAncientEnemyCommon__ct(u8 *arg0, s32 arg1);
void *__dt__23TOContainerAncientEnemyFv(void *arg0, s16 arg1);

void *__dt__27TOContainerAncientEnemyRareFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__27TOContainerAncientEnemyRare;
        __dt__23TOContainerAncientEnemyFv(arg0, 0);
        if (arg1 > 0) {
            TObject::operator delete(arg0);
        }
    }
    return arg0;
}

u8 *TOContainerAncientEnemyRare__ct(u8 *container_ancient_enemy_rare, s32 arg1) {
    TOContainerAncientEnemy__ct((TOContainerAncientEnemy *)container_ancient_enemy_rare, arg1);
    *(s32 **)((s8 *)container_ancient_enemy_rare + 0x18) = __vt__27TOContainerAncientEnemyRare;
    ((TOContainerAncientEnemyRare *)container_ancient_enemy_rare)->m_name = lbl_805D2F10;
    ((TOContainerAncientEnemyRare *)container_ancient_enemy_rare)->texlist = (s32) *ancient_container_fragment_texture_lists;
    return container_ancient_enemy_rare;
}

s32 TOContainerAncientEnemyCommon__create(s32 container_ancient_enemy_common) {
    u8 *o;
    if (((s32) enable_v2_features == 1) && (get_game_play_mode() == 1) && (is_quest_active() == 1)) {
        o = (u8 *)TObject::operator new(0x368);
        if (o != NULL) {
            o = TOContainerAncientEnemyCommon__ct(o, container_ancient_enemy_common);
        }
        return (s32)o;
    }
    o = (u8 *)TObject::operator new(0x368);
    if (o != NULL) {
        o = TOContainerAncientEnemyCommon__ct(o, container_ancient_enemy_common);
    }
    return (s32)o;
}

void *__dt__29TOContainerAncientEnemyCommonFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__29TOContainerAncientEnemyCommon;
        __dt__23TOContainerAncientEnemyFv(arg0, 0);
        if (arg1 > 0) {
            TObject::operator delete(arg0);
        }
    }
    return arg0;
}

u8 *TOContainerAncientEnemyCommon__ct(u8 *container_ancient_enemy_common, s32 arg1) {
    TOContainerAncientEnemy__ct((TOContainerAncientEnemy *)container_ancient_enemy_common, arg1);
    *(s32 **)((s8 *)container_ancient_enemy_common + 0x18) = __vt__29TOContainerAncientEnemyCommon;
    ((TOContainerAncientEnemyCommon *)container_ancient_enemy_common)->m_name = TOContainerAncientEnemyCommon__name;
    return container_ancient_enemy_common;
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

void TOContainerAncientEnemy::vfunc_79() {
    extern const u32 ancient_container_resource_bundle;
    if (this->mode != 1) {
        TObjChipParams a = ancient_enemy_break_debris_desc;
        a.pos[0] = this->position.x;
        a.pos[1] = this->position.y;
        a.pos[2] = this->position.z;
        a.pad_38[0] = this->position.y;
        a.model = get_bml_model((BmlResource *)ancient_container_resource_bundle, 1);
        a.textures = TObjFish__sub_8001EDB0((BmlResource *)ancient_container_resource_bundle, 1);
        TObjChipParams b = ancient_enemy_break_debris_desc_b;
        b.pos[0] = this->position.x;
        b.pos[1] = this->position.y;
        b.pos[2] = this->position.z;
        b.pad_38[0] = this->position.y;
        b.model = get_bml_model((BmlResource *)ancient_container_resource_bundle, 2);
        b.textures = TObjFish__sub_8001EDB0((BmlResource *)ancient_container_resource_bundle, 2);
        if (check_value_equals((s32)lbl_805D2F10) != 0) {
            a.textures = ancient_container_fragment_texture_lists[1];
            b.textures = ancient_container_fragment_texture_lists[2];
        }
        spawn_particle_effect(&this->position, 0x45);
        spawn_particle_effect(&this->position, 0x46);
        new TObjChip(tl_05, &a);
        new TObjChip(tl_05, &b);
        play_container_break_sound((s32)this);
    }
}

f32 TOContainerAncientEnemy::receive_physical_attack(void *, f32) {
    s16 sp8;
    Pk_8015BAE0 pk;
    if (this->entity_id >= 0x1000U && this->set_entry != NULL && access_object_saved_state(&sp8, 1) != 0) {
        sp8 = 1;
        access_object_saved_state(&sp8, 0);
        send_object_state_update(&sp8);
        ((TLobby *)(&pk))->init_packet_67_04();
        pk.id = this->entity_id;
        pk.a = get_current_floor();
        pk.b = this->set_params[0];
        pk.c = local_client_id;
        ((TLobby *)(&pk))->byteswap_and_send();
    }
    return lbl_805DB39C;
}

void TOContainerAncientEnemy::debug_print_item_box_info() {
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, "EVT NO : %d", this->set_params[0]);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    debug_draw_sphere(&this->position, &debug_color_blue_alpha30, lbl_805DB3A0);
}

void TOContainerAncientEnemy::vfunc_81() {
    extern BmlResource *ancient_container_resource_bundle;
    NJS_OBJECT *obj;
    NJS_OBJECT *child;
    NJS_OBJECT *sibling;
    if (ancient_container_resource_bundle != NULL) {
        switch (this->mode) {
        case 0:
            push_matrix();
            post_translate_matrix(&this->position.x);
            rotate_matrix_y(0, this->rotation_y);
            TObjFish::set_global_param(this->texlist);
            obj = (NJS_OBJECT *)this->model;
            push_matrix();
            post_translate_matrix(obj->pos);
            draw_ginja_model((s32)obj->model);
            child = obj->child;
            push_matrix();
            post_translate_matrix(child->pos);
            draw_ginja_model((s32)child->model);
            pop_matrix();
            sibling = child->sibling;
            push_matrix();
            post_translate_matrix(sibling->pos);
            TParticleCtrl::begin_effect_render();
            draw_ginja_model((s32)sibling->model);
            TParticleCtrl::end_effect_render();
            pop_matrix();
            pop_matrix();
            pop_matrix();
            break;
        }
    }
}

void TOContainerAncientEnemy::vfunc_80() {
    switch (this->mode) {
    case 0:
        if (this->m_364 != 0) {
            submit_cursor_candidate(this, -1);
        }
        break;
    }
}

void *__dt__23TOContainerAncientEnemyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__23TOContainerAncientEnemy;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts((TObjCollidable *)arg0);
        ((TUnk_804B6C24 *)arg0)->destroy_container_object(0);
        if (arg1 > 0) {
            TObject::operator delete(arg0);
        }
    }
    return arg0;
}

TOContainerAncientEnemy *TOContainerAncientEnemy__ct(TOContainerAncientEnemy *container, s32 arg1) {
    extern BmlResource *ancient_container_resource_bundle;
    init_container_base((u8 *)container, (s32)tl_05, arg1);
    *(s32 **)((s8 *)container + 0x18) = __vt__23TOContainerAncientEnemy;
    container->m_name = TOContainerAncientEnemy__name;
    container->mode = 0;
    container->actorFlags |= 0x60000000;
    init_collision_body_parts(container, &TOContainerAncientEnemy__collision_body_params, 1);
    container->register_object_by_id();
    VecCopy(&container->center, &container->position);
    VecCopy((Vec *)&container->m_2fc, &container->position);
    container->center.y += TOContainerAncientEnemy__collision_body_params.offset.y;
    container->model = (void *)get_bml_model(ancient_container_resource_bundle, 0);
    container->texlist = TObjFish__sub_8001EDB0(ancient_container_resource_bundle, 0);
    return container;
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

void *TOContainerAncientItemNone::create(void *container_ancient_item_none) {
    void *o = TObject::operator new(0x368);
    if (o != NULL) {
        o = TOContainerAncientItemNone__ct(o, container_ancient_item_none);
    }
    return o;
}

void *__dt__26TOContainerAncientItemNoneFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__26TOContainerAncientItemNone;
        __dt__26TOContainerAncientItemRareFv(arg0, 0);
        if (arg1 > 0) {
            TObject::operator delete(arg0);
        }
    }
    return arg0;
}

void *TOContainerAncientItemNone__ct(void *container_ancient_item_none, void *parent) {
    TOContainerAncientItemRare__ct((u8 *)container_ancient_item_none, (s32)parent);
    *(s32 **)((s8 *)container_ancient_item_none + 0x18) = __vt__26TOContainerAncientItemNone;
    ((TOContainerAncientItemNone *)container_ancient_item_none)->m_name = TOContainerAncientItemNone__name;
    return container_ancient_item_none;
}

void TOContainerAncientItemRare::vfunc_6(s16 *arg1, s32 arg2) {
    if ((s16) *arg1 == 1) {
        if (arg2 != 0) {
            this->vfunc_79();
            request_box_item_drop((u8 *)&this->position, 1);
        }
        this->mode = 1;
        set_flag8();
        queue_destruction();
    }
}

void *__dt__26TOContainerAncientItemRareFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__26TOContainerAncientItemRare;
        ((TUnk_804B08BC *)arg0)->destroy_ancient_container(0);
        if (arg1 > 0) {
            TObject::operator delete(arg0);
        }
    }
    return arg0;
}

u8 *TOContainerAncientItemRare__ct(u8 *container_ancient_item_rare, s32 arg1) {
    init_ancient_container(container_ancient_item_rare, arg1);
    *(s32 **)((s8 *)container_ancient_item_rare + 0x18) = __vt__26TOContainerAncientItemRare;
    *(s32 *)((s8 *)container_ancient_item_rare + 0) = (s32) TOContainerAncientItemRare__name;
    ((TOContainerAncientItemRare *)container_ancient_item_rare)->texlist = ancient_container_fragment_texture_lists[0];
    return container_ancient_item_rare;
}

void TOContainerAncientItemCommon::vfunc_6(s16 *arg1, s32 arg2) {
    if ((s16) *arg1 == 1) {
        if (arg2 != 0) {
            this->vfunc_79();
            this->spawn_item((s32)this);
        }
        this->mode = 1;
        set_flag8();
        queue_destruction();
    }
}

s32 TOContainerAncientItemCommon::create() {
    void *o;
    if (((s32) enable_v2_features == 1) && (get_game_play_mode() == 1) && (is_quest_active() == 1)) {
        o = TObject::operator new(0x368);
        if (o != NULL) {
            o = TOContainerAncientItemCommon__ct(o, this);
        }
        return (s32)o;
    }
    o = TObject::operator new(0x368);
    if (o != NULL) {
        o = TOContainerAncientItemCommon__ct(o, this);
    }
    return (s32)o;
}

void *__dt__28TOContainerAncientItemCommonFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__28TOContainerAncientItemCommon;
        ((TUnk_804B08BC *)arg0)->destroy_ancient_container(0);
        if (arg1 > 0) {
            TObject::operator delete(arg0);
        }
    }
    return arg0;
}

void *TOContainerAncientItemCommon__ct(void *container_ancient_item_common, void * _w1) {
    init_ancient_container((u8 *)container_ancient_item_common, (s32)_w1);
    *(s32 **)((s8 *)container_ancient_item_common + 0x18) = __vt__28TOContainerAncientItemCommon;
    ((TOContainerAncientItemCommon *)container_ancient_item_common)->m_name = TOContainerAncientItemCommon__name;
    return container_ancient_item_common;
}

void TUnk_804B08BC::vfunc_79() {
    extern const u32 ancient_container_resource_bundle;
    if (this->mode == 1) {
        return;
    }
    TObjChipParams a = fish_break_debris_desc;
    a.pos[0] = this->position.x;
    a.pos[1] = this->position.y;
    a.pos[2] = this->position.z;
    a.pad_38[0] = a.pos[1];
    a.model = get_bml_model((BmlResource *)ancient_container_resource_bundle, 1);
    a.textures = TObjFish__sub_8001EDB0((BmlResource *)ancient_container_resource_bundle, 1);
    TObjChipParams b = lbl_8044074C;
    b.pos[0] = this->position.x;
    b.pos[1] = this->position.y;
    b.pos[2] = this->position.z;
    b.pad_38[0] = b.pos[1];
    b.model = get_bml_model((BmlResource *)ancient_container_resource_bundle, 2);
    b.textures = TObjFish__sub_8001EDB0((BmlResource *)ancient_container_resource_bundle, 2);
    if (check_value_equals((s32)TOContainerAncientItemRare__name) != 0) {
        a.textures = ancient_container_fragment_texture_lists[1];
        b.textures = ancient_container_fragment_texture_lists[2];
    }
    new TObjChip(tl_05, &a);
    new TObjChip(tl_05, &b);
    spawn_particle_effect(&this->position, 0x45);
    spawn_particle_effect(&this->position, 0x46);
    play_container_break_sound((s32)this);
}

void TUnk_804B08BC::vfunc_81() {
    extern BmlResource *ancient_container_resource_bundle;
    NJS_OBJECT *obj;
    NJS_OBJECT *child;
    NJS_OBJECT *sibling;
    if (ancient_container_resource_bundle != NULL) {
        switch (this->mode) {
        case 0:
            push_matrix();
            post_translate_matrix(&this->position.x);
            rotate_matrix_y(0, this->rotation_y);
            TObjFish::set_global_param(this->texlist);
            obj = (NJS_OBJECT *)this->model;
            push_matrix();
            post_translate_matrix(obj->pos);
            draw_ginja_model((s32)obj->model);
            child = obj->child;
            push_matrix();
            post_translate_matrix(child->pos);
            draw_ginja_model((s32)child->model);
            pop_matrix();
            sibling = child->sibling;
            push_matrix();
            post_translate_matrix(sibling->pos);
            TParticleCtrl::begin_effect_render();
            draw_ginja_model((s32)sibling->model);
            TParticleCtrl::end_effect_render();
            pop_matrix();
            pop_matrix();
            pop_matrix();
            break;
        }
    }
}
void TUnk_804B08BC::vfunc_80() {
    switch (this->mode) {
    case 0:
        if (this->m_364 != 0) {
            submit_cursor_candidate(this, -1);
        }
        break;
    }
}

void *TUnk_804B08BC::destroy_ancient_container(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804B08BC;
        unregister_object_by_id();
        free_collision_body_parts(this);
        destroy_container_object(0);
        if (arg1 > 0) {
            TObject::operator delete(this);
        }
    }
    return this;
}

}

u8 *init_ancient_container(u8 *arg0, s32 arg1) {
    extern BmlResource *ancient_container_resource_bundle;
    init_container_base(arg0, (s32)tl_05, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = lbl_804B08BC;
    ((TUnk_804B08BC *)arg0)->mode = 0;
    ((TUnk_804B08BC *)arg0)->actorFlags |= 0x60000000;
    init_collision_body_parts((TUnk_804B08BC *)arg0, &TOContainerAncientEnemy__collision_body_params, 1);
    ((TUnk_804B08BC *)arg0)->register_object_by_id();
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    ((TUnk_804B08BC *)arg0)->center.y += TOContainerAncientEnemy__collision_body_params.offset.y;
    ((TUnk_804B08BC *)arg0)->model = (void *)get_bml_model(ancient_container_resource_bundle, 0);
    ((TUnk_804B08BC *)arg0)->texlist = TObjFish__sub_8001EDB0(ancient_container_resource_bundle, 0);
    return arg0;
}

#pragma push
#pragma fp_contract on

void free_ancient_container_resources(void) {
    extern BmlResource *ancient_container_resource_bundle;
    s32 var_r31;
    s32 var_r30;
    void *p;
    if (ancient_container_fragment_texture_lists != NULL) {
        var_r30 = 0;
        var_r31 = 0;
        do {
            TObjPlayer::free_if_valid((int) (*(s32 *)((s8 *)ancient_container_fragment_texture_lists + var_r31)));
            var_r30 += 1;
            var_r31 += 4;
        } while (var_r30 < 3);
        p = ancient_container_fragment_texture_lists;
        if (p != NULL) {
            mem_free(p);
            ancient_container_fragment_texture_lists = NULL;
        }
    }
    p = ancient_container_resource_bundle;
    if (p != NULL) {
        free_bin_model_request((BmlResource *)p, 1);
        ancient_container_resource_bundle = NULL;
    }
}
#pragma pop

extern "C" {

void TLanguage::load_container_fragment_textures() {
    extern BmlResource *ancient_container_resource_bundle;
    u8 *tbl = (u8 *)&bm_o_container_ancient_resource_bundle;
    s32 area = get_current_floor_area();
    void *p;
    if (enable_v2_features == 1 &&
        (area == AREA_BATTLE1 || area == AREA_VR_SPACESHIP_ALPHA || area == AREA_VR_SPACESHIP_BETA || area == AREA_GOL_DRAGON)) {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, (BmlResourceDescriptor *)(tbl + 0x50), 0, 0, 0);
        }
        ancient_container_resource_bundle = (BmlResource *)p;
        ancient_container_fragment_texture_lists = (u32 *)mem_alloc(0xC);
        ancient_container_fragment_texture_lists[0] = (u32)load_gvm_texture_file((s32)"fs_obj_ex_box2.gvm");
        ancient_container_fragment_texture_lists[1] = (u32)load_gvm_texture_file((s32)"fe_obj_ex_box2_hahen01.gvm");
        ancient_container_fragment_texture_lists[2] = (u32)load_gvm_texture_file((s32)"fe_obj_ex_box2_hahen02.gvm");
    } else if (enable_v2_features == 1 &&
               (area == AREA_BATTLE2 || area == AREA_VR_TEMPLE_ALPHA || area == AREA_VR_TEMPLE_BETA || area == AREA_BARBA_RAY)) {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, (BmlResourceDescriptor *)(tbl + 0x30), 0, 0, 0);
        }
        ancient_container_resource_bundle = (BmlResource *)p;
        ancient_container_fragment_texture_lists = (u32 *)mem_alloc(0xC);
        ancient_container_fragment_texture_lists[0] = (u32)load_gvm_texture_file((s32)"fs_obj_o_vs2container_r.gvm");
        ancient_container_fragment_texture_lists[1] = (u32)load_gvm_texture_file((s32)"fe_obj_o_vs2cont_hahen1_r.gvm");
        ancient_container_fragment_texture_lists[2] = (u32)load_gvm_texture_file((s32)"fe_obj_o_vs2cont_hahen2_r.gvm");
    } else {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, (BmlResourceDescriptor *)(tbl + 0x10), 0, 0, 0);
        }
        ancient_container_resource_bundle = (BmlResource *)p;
        ancient_container_fragment_texture_lists = (u32 *)mem_alloc(0xC);
        ancient_container_fragment_texture_lists[0] = (u32)load_gvm_texture_file((s32)"fe_obj_o_container_r.gvm");
        ancient_container_fragment_texture_lists[1] = (u32)load_gvm_texture_file((s32)"fe_obj_o_container_hahen01r.gvm");
        ancient_container_fragment_texture_lists[2] = (u32)load_gvm_texture_file((s32)"fe_obj_o_container_hahen02r.gvm");
    }
}

int TUnk_804B6C24::calc_distance_accuracy_penalty(void *, void *, void *, float) { return 1; }

f32 TUnk_804B6C24::receive_weapon_special_attack(void *, void *) {
    receive_physical_attack(NULL, lbl_805DB398);
    return lbl_805DB39C;
}

void TUnk_804B6C24::apply_knockback_from_attacker(u8 *, f32) {  }
s32 TUnk_804B6C24::try_start_action(s32, s32) { return 1; }
s32 TUnk_804B6C24::roll_physical_accuracy(void *, s32, f32) { return 1; }

void *TUnk_804B6C24::destroy_container_object(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804B6C24;
        ((CameraDistanceFade *)((s8 *)this + 0x340))->CameraDistanceFade::~CameraDistanceFade();
        __dt__9TObjCharaFv(this, 0);
        if (arg1 > 0) {
            TObject::operator delete(this);
        }
    }
    return this;
}

void TUnk_804B6C24::vfunc_6(s16 *, s32) {  }

void TLobby::byteswap_and_send() {
    s32 arg0 = (s32)this;
    ((s32 (*)())byteswap_event_packet__6TLobbyFi)();
    send_subcommand((u8 *)arg0);
}

void byteswap_event_packet__6TLobbyFi(s32 packet) {
    ((G_ClientIDHeader *)packet)->bswap();
    bswap_32((u32 *)(packet + 4));
    bswap_32((u32 *)(packet + 8));
    bswap_32((u32 *)(packet + 0xC));
}
void TLobby::init_packet_67_04() { *(u8 *)&this->m_name = 103; *(u8*)((char*)this + 0x1) = 4; }

}
