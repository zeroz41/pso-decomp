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
#include "pso/unk/TLobby.h"
#include "pso/object/key/TOKeyAncient01.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#define CAT2(a, b) a##b
#define CAT(a, b) CAT2(a, b)
#define PADV4 virtual void CAT(pa, __LINE__)(); virtual void CAT(pb, __LINE__)(); virtual void CAT(pc, __LINE__)(); virtual void CAT(pd, __LINE__)();
#include "pso/object/TObjChip.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_804B6C24.h"
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
#include "pso/unk/text_8018A3E0.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/object/seabed/TObjSeabedSuisoBrakable.h"
#include "pso/object/container/TContainerAncient01.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/MatrixOps.h"


#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/GinjaTexture.h"

struct Obj_80188884 { u8 pad0[0x38]; u8 pos[0x28]; s32 id; u8 pad1[0x326 - 0x64]; s16 state; };
struct Obj_80188814 { u8 pad0[0x38]; u8 pos[0x4c]; s32 id; };
struct Obj_8018860C {
    u8 pad[0x38];
    Vec pos;
    u8 pad44[0x326 - 0x44];
    s16 state;
};
struct Obj_80188C8C { u8 pad0[0x38]; u8 pos[0x28]; s32 id; u8 pad1[0x326 - 0x64]; s16 state; };
struct Obj_8018990C { u8 pad[0x38]; f32 x, y, z; u8 pad44[0x326 - 0x44]; s16 f326; };
struct Obj_801895A4 { u8 pad0[0x38]; u8 pos[0x4c]; s32 id; };
struct CE_80189614 { u8 pad[0x34]; saddr f34; u8 f38[0x28]; s32 angle; u8 pad2[0x326 - 0x64]; s16 mode; };
struct Box_80189A50 {
    u8 pad00[0x34];
    saddr model;
    u8 pos[0x28];
    s32 rot;
    u8 pad64[0x326 - 0x64];
    s16 state;
};
struct Item_80189E3C { u8 pad[0x30]; s32 data[3]; };
struct Obj_80189E3C {
    u8 pad[0x68];
    f32 x68;
    u8 pad6c[0x84 - 0x6C];
    s32 data[3];
    u8 pad90[0x360 - 0x90];
    s32 x360;
};
struct Base_8018A0B4 { char pad[0x18]; };
struct VObj_8018A0B4 : Base_8018A0B4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20(s32, f32);
};
struct SubBase_80189F24 { u8 pad[0x14]; };
struct Sub_80189F24 : SubBase_80189F24 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    u8 pad[0x24 - 0x18];
};
struct VBase_80189F24 { u8 pad[0x18]; };
struct Obj_80189F24 : VBase_80189F24 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    u8 pad1c[0x38 - 0x1C];
    f32 pos[3];
    u8 pad44[0x334 - 0x44];
    f32 x334;
    f32 x338;
    u8 pad33c[0x340 - 0x33C];
    Sub_80189F24 sub;
    s32 x364;
};

struct ForestBoxCollisionBody {
    f32 center[3];
    f32 radius;
    f32 height;
    u32 unknown_14;
    u32 flags;
    u32 unknown_1c[4];
};

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

ForestBoxCollisionBody forest_box_collision_body_parts = {
    { 0.0f, 6.0f, 0.0f }, 9.0f, 9.0f, 0, 0x38003, { 0, 0, 0, 0 },
};

static TObjChipParams forest_box_break_params[4] = {
    { 0.5f, 0.03f, 0.2f, { 0.0f, 0.0f, 0.0f }, { 3.0f, 5.0f, 3.0f }, { 0x800, 0x100, 0x800 }, 7, 0x32, 0.0f, 1.0f, 0, 0, 0x16 },
    { 0.5f, 0.03f, 0.19f, { 0.0f, 0.0f, 0.0f }, { 3.5f, 5.0f, 3.5f }, { 0x400, 0x100, 0x400 }, 5, 0x32, 0.0f, 1.0f, 0, 0, 0x16 },
    { 0.5f, 0.03f, 0.2f, { 0.0f, 0.0f, 0.0f }, { 3.0f, 5.0f, 3.0f }, { 0x800, 0x100, 0x800 }, 7, 0x32, 0.0f, 0.5f, 0, 0, 0x16 },
    { 0.5f, 0.03f, 0.19f, { 0.0f, 0.0f, 0.0f }, { 3.5f, 5.0f, 3.5f }, { 0x400, 0x100, 0x400 }, 5, 0x32, 0.0f, 0.5f, 0, 0, 0x16 },
};

// TObjContainerBase's name (the containers' constructors install it)
const char *TObjContainerBase__name = "TObjContainerBase";
const char *TObjContainerItem__name = "TObjContainerItem";
const char *TObjContainerEnemy__name = "TObjContainerEnemy";
const char *TObjContainerNoItem__name = "TObjContainerNoItem";

extern const TObjChipParams container_break_particle_parameters = {
    0.5f, 0.07f, 0.26f, { 0.0f, 0.0f, 0.0f }, { 5.0f, 5.0f, 5.0f }, { 0x400, 0x100, 0x400 }, 5, 0x32, 0.0f, 0.6f, 0, 0, 0x14,
};
extern const TObjChipParams container_break_small_debris_parameters = {
    0.5f, 0.07f, 0.26f, { 0.0f, 0.0f, 0.0f }, { 4.0f, 4.5f, 4.0f }, { 0x200, 0x100, 0x200 }, 6, 0x32, 0.0f, 0.5f, 0, 0, 0x14,
};

const char *TObjContainerAbeEnemy__name = "TObjContainerAbeEnemy";

extern const TObjChipParams lbl_80444E5C = {
    0.5f, 0.07f, 0.26f, { 0.0f, 0.0f, 0.0f }, { 5.0f, 5.0f, 5.0f }, { 0x400, 0x100, 0x400 }, 5, 0x32, 0.0f, 0.6f, 0, 0, 0x14,
};
extern const TObjChipParams lbl_80444EA8 = {
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
extern "C" {
void post_translate_matrix(const void *);
extern const f32 lbl_805DBCF8;
u32 init_collision_body_parts(void *, void *, s32);
s32 free_collision_body_parts(void *);
}
extern s32 local_client_id;
NJS_OBJECT *get_container_breakup_model(s32 index);
extern const f32 lbl_805DBCF4;
NJS_OBJECT *get_forest_box_model(s32 index);
extern const f32 lbl_805DBCFC;
extern const f32 lbl_805DBD0C;
extern const f32 lbl_805DBCF0;
extern const f32 lbl_805DBD00;
extern const f32 lbl_805DBD04;
extern const f32 lbl_805DBD08;

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

void TLazerFenceSw__sub_8018A554(void* p, f32 v) { *(f32*)((char*)p + 0x1c) = v; }

void TUnk_804B6C24::vfunc_79() const {  }

void TUnk_804B6C24::vfunc_80() {  }

void TUnk_804B6C24::vfunc_81() {  }

void load_forest_box_resources(void) {
    BmlResource *bundle;
    NJS_OBJECT *node;
    forest_box_model_archive = NULL;
    forest_box_textures = NULL;
    switch (get_current_floor_area()) {
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
    case AREA_OLGA_FLOW:
        bundle = new BmlResource(5, (BmlResourceDescriptor *)&bm_obj_seabed_con_resource_descriptor, 0, 0, NULL);
        forest_box_model_archive = bundle;
        forest_box_textures = load_gvm_texture_file(seabed_container_texture_filename);
        forest_box_debris_primary = &forest_box_break_params[2];
        forest_box_debris_secondary = &forest_box_break_params[3];
        node = find_object_node((NJS_OBJECT *)get_bml_model((BmlResource *)forest_box_model_archive, 1), 2);
        if (node != NULL) {
            node->evalflags |= 0x100000;
        }
        break;
    default:
        bundle = new BmlResource(5, (BmlResourceDescriptor *)&fe_obj_hako01_hahen02_resource_descriptor, 0, 0, NULL);
        forest_box_model_archive = bundle;
        forest_box_textures = TLobby::is_online_ready() != 0 ? load_gvm_texture_file(forest_box_texture_filename_a) : load_gvm_texture_file(forest_box_texture_filename_n);
        forest_box_debris_primary = &forest_box_break_params[0];
        forest_box_debris_secondary = &forest_box_break_params[1];
        break;
    }
    TObjNpcEnemy::register_ginja(1, get_forest_box_model(1), forest_box_textures, lbl_805DBD0C, lbl_805DBCF4);
}

void free_forest_box_resources() {
    if (forest_box_textures != NULL) {
        release_texture_list(forest_box_textures);
        safe_free(forest_box_textures);
        forest_box_textures = NULL;
    }
    if ((uaddr) forest_box_model_archive != 0U) {
        delete (BmlResource *)forest_box_model_archive;
        forest_box_model_archive = NULL;
    }
}

NJS_OBJECT *get_forest_box_model(s32 index) { return (NJS_OBJECT *)get_bml_model((BmlResource *)forest_box_model_archive, index); }

void load_container_breakup_resources() {
    void *p;
    container_breakup_model_archive = 0;
    switch (get_current_floor_area()) {
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
    case AREA_OLGA_FLOW:
        p = new BmlResource(5, &bm_obj_seabed_con_rare_resource_descriptor, 0, 0, NULL);
        container_breakup_model_archive = (BmlResource *)p;
        container_breakup_textures = load_gvm_texture_file("obj_seabed_con_rare.gvm");
        break;
    case AREA_GAL_GRYPHON:
    default:
        p = new BmlResource(5, &fe_obj_con_hahen1_resource_descriptor, 0, 0, NULL);
        container_breakup_model_archive = (BmlResource *)p;
        container_breakup_textures = load_gvm_texture_file("obj_abecon.gvm");
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
    return (NJS_OBJECT *)get_bml_model((BmlResource *)container_breakup_model_archive, index);
}

#pragma push
#pragma fp_contract on
TUnk_804B6C24::TUnk_804B6C24(TObject *parent, void *set_data) : TObjChara(parent) {
    m_name = TObjContainerBase__name;
    apply_object_set_data(set_data);
    view_range = lbl_805DBD00;
    model_radius = lbl_805DBD04;
    melee_range_sq = lbl_805DBD00;
    if (scale.x > lbl_805DBCF4) {
        random_item = 1;
    } else {
        random_item = 0;
    }
    distance_fade.reset();
    TLazerFenceSw__sub_8018A554(&distance_fade, lbl_805DBD08);
    in_view = 0;
}

#pragma pop

s32 TUnk_804B6C24::select_melee_contact_body(void *target, f32) {
    return xyz_distance_squared(&((TObjBase *)target)->position, &position) < melee_range_sq;
}

f32 TUnk_804B6C24::receive_direct_attack(void *arg1, DirectAttackPayload payload, void *, s32, s32) {
    s32 kind;
    struct VObj_8018A0B4 *o = (struct VObj_8018A0B4 *)this;

    kind = payload.kind;
    if ((kind == 0) || ((kind - 1) <= 3U) || (kind == 0x13)) {
        o->m20(0, lbl_805DBCF0);
    }
    return lbl_805DBCF4;
}

f32 TUnk_804B6C24::receive_physical_attack(void *, f32) {
    u8 *arg0 = (u8 *)this;
    s16 sp8;
    if (((u16) this->entity_id >= 0x1000U) && ((u32) *(u32 *)((s8 *)arg0 + 0x80) != 0U) && (((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 1) != 0)) {
        sp8 = 1;
        ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 0);
        ((TObjCollidable *)arg0)->send_object_state_update(&sp8);
    }
    return lbl_805DBCF4;
}

void TUnk_804B6C24::run_task() {
    distance_fade.step_fade();
    vfunc_80();
    in_view = 0;
}

void TUnk_804B6C24::render() {
    Obj_80189F24 *self = (Obj_80189F24 *)this;
    if (self->m8(self->x334, self->x338) != 1) {
        return;
    }
    self->x364 = 1;
    if (((CameraDistanceFade *)&self->sub)->update_visibility((Vec *)self->pos) != 1) {
        return;
    }
    if (((CameraDistanceFade *)&self->sub)->is_translucent() == 1) {
        self->sub.m6();
        self->m79();
        self->sub.m7();
    } else {
        self->m79();
    }
}

#pragma pool_data off
void TUnk_804B6C24::debug_print_item_box_info() {
    Obj_80189E3C *self = (Obj_80189E3C *)this;
    Item_80189E3C item;
    if (this->scale.x > lbl_805DBCF4) {
        this->random_item = 1;
    } else {
        this->random_item = 0;
    }
    if (this->random_item != 0) {
        TObjNpcEnemy::set_global_count(0xFFFFFF);
        debug_printf_at(0x13001C, container_random_item_message);
    } else {
        TObjNpcEnemy::set_global_count(0xFF00FF);
        debug_printf_at(0x13001C, container_fixed_item_message);
        debug_printf_at(0x130020, container_item_parameter_message);
        item.data[0] = self->data[0];
        item.data[1] = self->data[1];
        item.data[2] = self->data[2];
        debug_print_item_param(&item);
    }
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}
#pragma pool_data reset

void play_container_break_sound(const TUnk_804B6C24 *container) {
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

void TUnk_804B6C24::request_configured_item_drop(TUnk_804B6C24 *container) {
    container->request_box_item_drop(&position, random_item);
}

TObjContainerItem::TObjContainerItem(TObject *parent, void *set_data) : TUnk_804B6C24(parent, set_data) {
    m_name = TObjContainerItem__name;
    model = (void *)get_forest_box_model(1);
    mode = 0;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, &forest_box_collision_body_parts, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy(&body_center, &position);
    center.y += forest_box_collision_body_parts.center[1];
}

TObjContainerItem::~TObjContainerItem() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TObjContainerItem::create(void *set_data) {
    return new TObjContainerItem(tl_05, set_data);
}

void TObjContainerItem::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void TObjContainerItem::vfunc_81() {
    struct Box_80189A50 *self = (struct Box_80189A50 *)this;
    if (forest_box_model_archive != 0) {
        switch (self->state) {
        case 0:
            TObjFish::set_global_param(forest_box_textures);
            push_matrix();
            post_translate_matrix(self->pos);
            rotate_matrix_y(0, self->rot);
            scale_matrix(0, lbl_805DBCFC, lbl_805DBCFC, lbl_805DBCFC);
            draw_ginja_box_tree((u8 *)self->model);
            pop_matrix();
            break;
        case 1:
            break;
        }
    }
}

void TObjContainerItem::vfunc_79() const {
    const Obj_8018990C *self = (const Obj_8018990C *)this;
    if (this->mode != 1) {
        TObjChipParams a = *forest_box_debris_primary;
        TObjChipParams b = *forest_box_debris_secondary;
        VecCopy(&a.pos, (const Vec *)&self->x);
        a.floor_y = self->y;
        a.model = get_forest_box_model(2);
        a.textures = forest_box_textures;
        VecCopy(&b.pos, (const Vec *)&self->x);
        b.floor_y = self->y;
        b.model = get_forest_box_model(0);
        b.textures = forest_box_textures;
        spawn_particle_effect_with_flags((const Vec *)&self->x, 0x45, 0x40);
        spawn_particle_effect_with_flags((const Vec *)&self->x, 0x46, 0x40);
        new TObjChip(tl_05, &a);
        new TObjChip(tl_05, &b);
        play_container_break_sound(this);
    }
}

void TObjContainerItem::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            this->vfunc_79();
            request_box_item_drop(&position, 1);
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

TObjContainerEnemy::TObjContainerEnemy(TObject *parent, void *set_data) : TUnk_804B6C24(parent, set_data) {
    m_name = TObjContainerEnemy__name;
    model = (void *)get_forest_box_model(1);
    mode = 0;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, &forest_box_collision_body_parts, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy(&body_center, &position);
    center.y += forest_box_collision_body_parts.center[1];
}

TObjContainerEnemy::~TObjContainerEnemy() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TObjContainerEnemy::create(void *set_data) {
    return new TObjContainerEnemy(tl_05, set_data);
}

void TObjContainerEnemy::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void TObjContainerEnemy::vfunc_81() {
    CE_80189614 *self = (CE_80189614 *)this;
    if (forest_box_model_archive == 0) {
        return;
    }
    switch (self->mode) {
    case 0:
        TObjFish::set_global_param(forest_box_textures);
        push_matrix();
        post_translate_matrix(self->f38);
        rotate_matrix_y(0, self->angle);
        scale_matrix(0, lbl_805DBCFC, lbl_805DBCFC, lbl_805DBCFC);
        draw_ginja_box_tree((u8 *)self->f34);
        pop_matrix();
        break;
    case 1:
        break;
    }
}

void TObjContainerEnemy::debug_print_item_box_info() {
    Obj_801895A4 *self = (Obj_801895A4 *)this;
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, container_event_number_format, this->set_params[0]);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    debug_draw_sphere((const Vec *)self->pos, &debug_color_blue_alpha30, lbl_805DBCF8);
}

f32 TObjContainerEnemy::receive_physical_attack(void *, f32) {
    s16 sp8;
    G_FloorEvent_6x67 pkt;
    if ((this->entity_id >= 0x1000U) && (set_entry != NULL) && (access_object_saved_state(&sp8, 1) != 0)) {
        sp8 = 1;
        access_object_saved_state(&sp8, 0);
        send_object_state_update(&sp8);
        pkt.init();
        pkt.header.client_id = this->entity_id;
        pkt.floor = get_current_floor();
        pkt.event_id = this->set_params[0];
        pkt.sender_client_id = local_client_id;
        pkt.send();
    }
    return lbl_805DBCF4;
}

void TObjContainerEnemy::vfunc_79() const {
    const Obj_8018990C *self = (const Obj_8018990C *)this;
    if (this->mode != 1) {
        TObjChipParams a = *forest_box_debris_primary;
        TObjChipParams b = *forest_box_debris_secondary;
        VecCopy(&a.pos, (const Vec *)&self->x);
        a.floor_y = self->y;
        a.model = get_forest_box_model(2);
        a.textures = forest_box_textures;
        VecCopy(&b.pos, (const Vec *)&self->x);
        b.floor_y = self->y;
        b.model = get_forest_box_model(0);
        b.textures = forest_box_textures;
        spawn_particle_effect_with_flags((const Vec *)&self->x, 0x45, 0x40);
        spawn_particle_effect_with_flags((const Vec *)&self->x, 0x46, 0x40);
        new TObjChip(tl_05, &a);
        new TObjChip(tl_05, &b);
        play_container_break_sound(this);
    }
}

void TObjContainerEnemy::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            this->vfunc_79();
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

TObjContainerNoItem::TObjContainerNoItem(TObject *parent, void *set_data) : TUnk_804B6C24(parent, set_data) {
    m_name = TObjContainerNoItem__name;
    model = (void *)get_forest_box_model(1);
    mode = 0;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, &forest_box_collision_body_parts, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy(&body_center, &position);
    center.y += forest_box_collision_body_parts.center[1];
}

TObjContainerNoItem::~TObjContainerNoItem() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TObjContainerNoItem::create(void *set_data) {
    return new TObjContainerNoItem(tl_05, set_data);
}

void TObjContainerNoItem::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void TObjContainerNoItem::vfunc_81() {
    u8 *arg0 = (u8 *)this;
    if (forest_box_model_archive != 0U) {
        switch (this->mode) {
        case 1:
            break;
        case 0:
        TObjFish::set_global_param(forest_box_textures);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        scale_matrix(0, lbl_805DBCFC, lbl_805DBCFC, lbl_805DBCFC);
        draw_ginja_box_tree((u8 *)(*(saddr *)((s8 *)arg0 + 0x34)));
        pop_matrix();
            break;
        }
    }
}

f32 TObjContainerNoItem::receive_physical_attack(void *, f32) {
    u8 *arg0 = (u8 *)this;
    s16 sp8;
    if (((u16) this->entity_id >= 0x1000U) && ((u32) *(u32 *)((s8 *)arg0 + 0x80) != 0U) && (((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 1) != 0)) {
        sp8 = 1;
        ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 0);
        ((TObjCollidable *)arg0)->send_object_state_update(&sp8);
    }
    return lbl_805DBCF4;
}

void TObjContainerNoItem::vfunc_79() const {
    const Obj_8018990C *self = (const Obj_8018990C *)this;
    if (this->mode != 1) {
        TObjChipParams a = *forest_box_debris_primary;
        TObjChipParams b = *forest_box_debris_secondary;
        VecCopy(&a.pos, (const Vec *)&self->x);
        a.floor_y = self->y;
        a.model = get_forest_box_model(2);
        a.textures = forest_box_textures;
        VecCopy(&b.pos, (const Vec *)&self->x);
        b.floor_y = self->y;
        b.model = get_forest_box_model(0);
        b.textures = forest_box_textures;
        spawn_particle_effect_with_flags((const Vec *)&self->x, 0x45, 0x40);
        spawn_particle_effect_with_flags((const Vec *)&self->x, 0x46, 0x40);
        new TObjChip(tl_05, &a);
        new TObjChip(tl_05, &b);
        play_container_break_sound(this);
    }
}

void TObjContainerNoItem::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            this->vfunc_79();
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

TObjContainerBase::TObjContainerBase(TObject *parent, void *set_data) : TUnk_804B6C24(parent, set_data) {
    m_name = TObjContainerBase__name;
    mode = 0;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, &forest_box_collision_body_parts, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy(&body_center, &position);
    center.y += forest_box_collision_body_parts.center[1];
}

TObjContainerBase::~TObjContainerBase() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjContainerBase::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void TObjContainerBase::vfunc_81() {
    Obj_80188C8C *self = (Obj_80188C8C *)this;
    if (container_breakup_model_archive != 0) {
        switch (this->mode) {
        case 0:
            TObjFish::set_global_param(container_breakup_textures);
            push_matrix();
            post_translate_matrix(self->pos);
            rotate_matrix_y(0, this->rotation_y);
            draw_ginja_box_tree((u8 *)get_container_breakup_model(2));
            pop_matrix();
            break;
        case 1:
            break;
        }
    }
}

#pragma push
#pragma opt_propagation off
void TObjContainerBase::vfunc_79() const {
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

void TObjContainerBase::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            this->vfunc_79();
            request_configured_item_drop(this);
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

void *TObjContainerBase::create(void *set_data) {
    return new TObjContainerBase(tl_05, set_data);
}

TObjContainerAbeEnemy::TObjContainerAbeEnemy(TObject *parent, void *set_data) : TUnk_804B6C24(parent, set_data) {
    m_name = TObjContainerAbeEnemy__name;
    mode = 0;
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, &forest_box_collision_body_parts, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    VecCopy(&body_center, &position);
    center.y += forest_box_collision_body_parts.center[1];
}

TObjContainerAbeEnemy::~TObjContainerAbeEnemy() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjContainerAbeEnemy::vfunc_80() {

    switch (this->mode) {
    case 0:
        if ((s32) this->in_view != 0) {
            submit_cursor_candidate(this, -1);
        }
    case 1:
        return;
    }
}

void TObjContainerAbeEnemy::vfunc_81() {
    Obj_80188884 *self = (Obj_80188884 *)this;
    if (container_breakup_model_archive != 0) {
        switch (this->mode) {
        case 0:
            TObjFish::set_global_param(container_breakup_textures);
            push_matrix();
            post_translate_matrix(self->pos);
            rotate_matrix_y(0, this->rotation_y);
            draw_ginja_box_tree((u8 *)get_container_breakup_model(2));
            pop_matrix();
            break;
        case 1:
            break;
        }
    }
}

void TObjContainerAbeEnemy::debug_print_item_box_info() {
    Obj_80188814 *self = (Obj_80188814 *)this;
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, container_event_number_format, this->set_params[0]);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    debug_draw_sphere((const Vec *)self->pos, &debug_color_blue_alpha30, lbl_805DBCF8);
}

f32 TObjContainerAbeEnemy::receive_physical_attack(void *, f32) {
    s16 sp8;
    G_FloorEvent_6x67 pkt;
    if ((this->entity_id >= 0x1000U) && (set_entry != NULL) && (access_object_saved_state(&sp8, 1) != 0)) {
        sp8 = 1;
        access_object_saved_state(&sp8, 0);
        send_object_state_update(&sp8);
        pkt.init();
        pkt.header.client_id = this->entity_id;
        pkt.floor = get_current_floor();
        pkt.event_id = this->set_params[0];
        pkt.sender_client_id = local_client_id;
        pkt.send();
    }
    return lbl_805DBCF4;
}

#pragma push
#pragma opt_propagation off
void TObjContainerAbeEnemy::vfunc_79() const {
    const Obj_8018860C *self = (const Obj_8018860C *)this;
    if (this->mode != 1) {
        TObjChipParams a = lbl_80444E5C;
        f32 za;
        f32 ya;
        f32 xa;
        xa = self->pos.x;
        ya = self->pos.y;
        za = self->pos.z;
        a.pos.x = xa;
        a.pos.y = ya;
        a.pos.z = za;
        a.floor_y = ya;
        a.model = get_container_breakup_model(0);
        a.textures = container_breakup_textures;
        TObjChipParams b = lbl_80444EA8;
        f32 zb;
        f32 yb;
        f32 xb;
        xb = self->pos.x;
        yb = self->pos.y;
        zb = self->pos.z;
        b.pos.x = xb;
        b.pos.y = yb;
        b.pos.z = zb;
        b.floor_y = yb;
        b.model = get_container_breakup_model(1);
        b.textures = container_breakup_textures;
        spawn_particle_effect_with_flags(&self->pos, 0x45, 0x40);
        spawn_particle_effect_with_flags(&self->pos, 0x46, 0x40);
        new TObjChip(tl_05, &a);
        new TObjChip(tl_05, &b);
        play_container_break_sound(this);
    }
}

#pragma pop

void TObjContainerAbeEnemy::vfunc_6(s16 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            this->vfunc_79();
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


extern const f32 lbl_805DBCF0 = 1.0f;
extern const f32 lbl_805DBCF4 = 0.0f;
extern const f32 lbl_805DBCF8 = 40.0f;
extern const f32 lbl_805DBCFC = 0.85f;
extern const f32 lbl_805DBD00 = 400.0f;
extern const f32 lbl_805DBD04 = 10.0f;
extern const f32 lbl_805DBD08 = 300.0f;
extern const f32 lbl_805DBD0C = 9.0f;
