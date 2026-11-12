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

struct Obj_80188814 { u8 pad0[0x38]; u8 pos[0x4c]; s32 id; };

struct Obj_8015B94C { u8 pad[0x38]; f32 x, y, z; u8 pad44[0x326 - 0x44]; s16 f326; };

struct O_8015BAE0 { u8 pad[0x1C]; u16 id; u8 pad1e[0x80 - 0x1E]; u32 f80; s32 f84; };

struct Pk_8015BAE0 { u8 pad[2]; u16 id; s32 a; s32 b; s32 c; };

struct Obj_8015BCC0 { u8 pad[0x326]; s16 a326; u8 pad2[0x364 - 0x328]; s32 a364; };

struct RecoveredGlobal_8015B76C___vt__27TOContainerAncientEnemyRare {
    s32 value;
    u8 remaining[0x148];
};

struct RecoveredGlobal_8015BD68___vt__23TOContainerAncientEnemy {
    s32 value;
    u8 remaining[0x148];
};

struct RecoveredGlobal_8015BD68_lbl_804B00C8 {
    s32 value;
    u8 remaining[0x28];
};
typedef char RecoveredGlobal_8015BD68_lbl_804B00C8_size[sizeof(RecoveredGlobal_8015BD68_lbl_804B00C8) == 0x2C ? 1 : -1];

struct Obj_8015C234 {
    u8 pad0[0x38];
    f32 x;
    f32 y;
    f32 z;
    u8 pad44[0x326 - 0x44];
    s16 f326;
};
struct Obj_8015C48C { u8 pad[0x326]; s16 a326; u8 pad2[0x364 - 0x328]; s32 a364; };

struct Base_8015BF38 { char pad[0x18]; };
#define M0(x) virtual void m##x();
struct VObj_8015BF38 : Base_8015BF38 {
    M0(0) M0(1) M0(2) M0(3) M0(4) M0(5) M0(6) M0(7) M0(8) M0(9)
    M0(10) M0(11) M0(12) M0(13) M0(14) M0(15) M0(16) M0(17) M0(18) M0(19)
    M0(20) M0(21) M0(22) M0(23) M0(24) M0(25) M0(26) M0(27) M0(28) M0(29)
    M0(30) M0(31) M0(32) M0(33) M0(34) M0(35) M0(36) M0(37) M0(38) M0(39)
    M0(40) M0(41) M0(42) M0(43) M0(44) M0(45) M0(46) M0(47) M0(48) M0(49)
    M0(50) M0(51) M0(52) M0(53) M0(54) M0(55) M0(56) M0(57) M0(58) M0(59)
    M0(60) M0(61) M0(62) M0(63) M0(64) M0(65) M0(66) M0(67) M0(68) M0(69)
    M0(70) M0(71) M0(72) M0(73) M0(74) M0(75) M0(76)
    virtual void m77();
};

struct BmlResourceBlock_804B0068 { const char *model_filenames[4]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B0068_size[(sizeof(BmlResourceBlock_804B0068) == 0x20) ? 1 : -1];
typedef char BmlResourceBlock_804B0068_descriptor_offset[(offsetof(BmlResourceBlock_804B0068, descriptor) == 0x10) ? 1 : -1];
struct BmlResourceBlock_804B0088 { const char *model_filenames[4]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B0088_size[(sizeof(BmlResourceBlock_804B0088) == 0x20) ? 1 : -1];
typedef char BmlResourceBlock_804B0088_descriptor_offset[(offsetof(BmlResourceBlock_804B0088, descriptor) == 0x10) ? 1 : -1];
struct BmlResourceBlock_804B00A8 { const char *model_filenames[4]; BmlResourceDescriptor descriptor; };
typedef char BmlResourceBlock_804B00A8_size[(sizeof(BmlResourceBlock_804B00A8) == 0x20) ? 1 : -1];
typedef char BmlResourceBlock_804B00A8_descriptor_offset[(offsetof(BmlResourceBlock_804B00A8, descriptor) == 0x10) ? 1 : -1];

struct Obj_8015C88C {
    u8 pad[0x18];
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(s32 a, f32 b);
};

void play_container_break_sound(s32 arg0);

extern "C" {
int is_quest_active(void);
s32 push_matrix();
s32 post_translate_matrix(void *);
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
s32 init_collision_body_parts(void *, void *, int);
s32 free_collision_body_parts(void *);
s32 check_value_equals__13TUnk_804B6C24Fl(void *, s32);
void byteswap_and_send__6TLobbyFv(void *, int);
s32 free_bin_model_request(void *, int);
void mem_free(void *p);
void *mem_alloc(u32 size);
void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
u8 *load_gvm_texture_file(s32 arg0);

extern s32 enable_v2_features;
extern s32 local_client_id;
extern s32 tl_05;
extern u32 *ancient_container_fragment_texture_lists;

extern s32 __vt__27TOContainerAncientEnemyRare[];
extern s32 __vt__29TOContainerAncientEnemyCommon[];
extern s32 __vt__23TOContainerAncientEnemy[];
extern s32 __vt__26TOContainerAncientItemNone[];
extern s32 __vt__26TOContainerAncientItemRare[];
extern s32 __vt__28TOContainerAncientItemCommon[];
extern s32 lbl_804B08BC[];
extern s32 lbl_804B6C24[];
extern RecoveredGlobal_8015BD68_lbl_804B00C8 TOContainerAncientEnemy__collision_body_params;

extern const f32 lbl_805DB398;
extern const f32 lbl_805DB39C;
extern const f32 lbl_805DB3A0;

const char *bm_o_container_ancient_motion_names[1] = { NULL };
const char *fe_obj_o_vs2container_motion_names[1] = { NULL };
const char *fe_obj_ex_box1_motion_names[1] = { NULL };
BmlResourceBlock_804B0068 bm_o_container_ancient_resource_bundle = { { "fe_obj_o_container.gj", "fe_obj_o_container_hahen01.gj", "fe_obj_o_container_hahen02.gj", NULL }, { "bm_o_container_ancient.bml", bm_o_container_ancient_resource_bundle.model_filenames, bm_o_container_ancient_motion_names, 3, 0 } };
BmlResourceBlock_804B0088 fe_obj_o_vs2container_resource_bundle = { { "fe_obj_o_vs2container_hahen1.gj", "fe_obj_o_vs2container_hahen2.gj", "fs_obj_o_vs2container.gj", NULL }, { "fe_obj_o_vs2container.bml", fe_obj_o_vs2container_resource_bundle.model_filenames, fe_obj_o_vs2container_motion_names, 3, 0 } };
BmlResourceBlock_804B00A8 fe_obj_ex_box1_resource_bundle = { { "fs_obj_ex_box1.gj", "fe_obj_ex_box1_hahen01.gj", "fe_obj_ex_box1_hahen02.gj", NULL }, { "fe_obj_ex_box1.bml", fe_obj_ex_box1_resource_bundle.model_filenames, fe_obj_ex_box1_motion_names, 3, 0 } };

const char *TOContainerAncientItemCommon__name = "TOContainerAncientItemCommon";
const char *TOContainerAncientItemRare__name = "TOContainerAncientItemRare";
const char *TOContainerAncientItemNone__name = "TOContainerAncientItemNone";
const char *TOContainerAncientEnemy__name = "TOContainerAncientEnemy";
const char *TOContainerAncientEnemyCommon__name = "TOContainerAncientEnemyCommon";
const char *lbl_805D2F10 = "TOContainerAncientEnemyRare";

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

u8 *TOContainerAncientEnemy__ct(u8 *arg0, s32 arg1);
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

typedef char RecoveredGlobal_8015B76C___vt__27TOContainerAncientEnemyRare_size[sizeof(RecoveredGlobal_8015B76C___vt__27TOContainerAncientEnemyRare) == 0x14C ? 1 : -1];
u8 *TOContainerAncientEnemyRare__ct(u8 *container_ancient_enemy_rare, s32 arg1) {
    TOContainerAncientEnemy__ct(container_ancient_enemy_rare, arg1);
    *(s32 **)((s8 *)container_ancient_enemy_rare + 0x18) = &(*(RecoveredGlobal_8015B76C___vt__27TOContainerAncientEnemyRare *)&__vt__27TOContainerAncientEnemyRare).value;
    *(s32 *)((s8 *)container_ancient_enemy_rare + 0) = (s32) lbl_805D2F10;
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
    TOContainerAncientEnemy__ct(container_ancient_enemy_common, arg1);
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
        queue_destruction__7TObjectFv(this);
    }
}

void TOContainerAncientEnemy::vfunc_79() {
    extern const u32 ancient_container_resource_bundle;
    Obj_8015B94C *self = (Obj_8015B94C *)this;
    void *o;
    if (this->mode != 1) {
        TObjChipParams a = ancient_enemy_break_debris_desc;
        a.pos[0] = self->x;
        a.pos[1] = self->y;
        a.pos[2] = self->z;
        a.pad_38[0] = self->y;
        a.model = get_bml_model((void *)ancient_container_resource_bundle, 1);
        a.textures = TObjFish__sub_8001EDB0((void *)ancient_container_resource_bundle, 1);
        TObjChipParams b = ancient_enemy_break_debris_desc_b;
        b.pos[0] = self->x;
        b.pos[1] = self->y;
        b.pos[2] = self->z;
        b.pad_38[0] = self->y;
        b.model = get_bml_model((void *)ancient_container_resource_bundle, 2);
        b.textures = TObjFish__sub_8001EDB0((void *)ancient_container_resource_bundle, 2);
        if (check_value_equals__13TUnk_804B6C24Fl(self, (s32)lbl_805D2F10) != 0) {
            a.textures = ancient_container_fragment_texture_lists[1];
            b.textures = ancient_container_fragment_texture_lists[2];
        }
        spawn_particle_effect(&self->x, 0x45);
        spawn_particle_effect(&self->x, 0x46);
        o = TObject::operator new(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&a);
        }
        o = TObject::operator new(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)o, (u8 *)tl_05, (u8 *)&b);
        }
        play_container_break_sound((s32)self);
    }
}

f32 TOContainerAncientEnemy::receive_physical_attack(void *, f32) {
    O_8015BAE0 *arg0 = (O_8015BAE0 *)this;
    s16 sp8;
    s32 r4;
    Pk_8015BAE0 pk;
    if (this->entity_id >= 0x1000U && arg0->f80 != 0U && ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 1) != 0) {
        sp8 = 1;
        ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 0);
        ((TObjCollidable *)arg0)->send_object_state_update(&sp8);
        ((TLobby *)(&pk))->init_packet_67_04();
        pk.id = this->entity_id;
        pk.a = get_current_floor();
        r4 = this->set_params[0];
        pk.b = r4;
        pk.c = local_client_id;
        byteswap_and_send__6TLobbyFv(&pk, r4);
    }
    return lbl_805DB39C;
}

void TOContainerAncientEnemy::debug_print_item_box_info() {
    Obj_80188814 *self = (Obj_80188814 *)this;
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, "EVT NO : %d", this->set_params[0]);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    debug_draw_sphere((const Vec *)self->pos, &debug_color_blue_alpha30, lbl_805DB3A0);
}

void TOContainerAncientEnemy::vfunc_81() {
    extern void *ancient_container_resource_bundle;
    u8 *temp_r31;
    u8 *temp_r31_2;
    u8 *temp_r31_3;
    if ((u32) ancient_container_resource_bundle != 0U) {
        switch (this->mode) {
        case 0:
            push_matrix();
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            TObjFish::set_global_param(this->texlist);
            temp_r31 = (unsigned char *) (this->model);
            push_matrix();
            post_translate_matrix(temp_r31 + 8);
            draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
            temp_r31_2 = (unsigned char *) (*(void **)((s8 *)temp_r31 + 0x2C));
            push_matrix();
            post_translate_matrix(temp_r31_2 + 8);
            draw_ginja_model((*(s32 *)((s8 *)temp_r31_2 + 4)));
            pop_matrix();
            temp_r31_3 = (unsigned char *) (*(void **)((s8 *)temp_r31_2 + 0x30));
            push_matrix();
            post_translate_matrix(temp_r31_3 + 8);
            TParticleCtrl::begin_effect_render();
            draw_ginja_model((*(s32 *)((s8 *)temp_r31_3 + 4)));
            TParticleCtrl::end_effect_render();
            pop_matrix();
            pop_matrix();
            pop_matrix();
            break;
        }
    }
}

void TOContainerAncientEnemy::vfunc_80() {
    Obj_8015BCC0 *self = (Obj_8015BCC0 *)this;
    switch (this->mode) {
    case 0:
        if (this->m_364 != 0) {
            submit_cursor_candidate(self, -1);
        }
        break;
    }
}

void *__dt__23TOContainerAncientEnemyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__23TOContainerAncientEnemy;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B6C24 *)arg0)->destroy_container_object(0);
        if (arg1 > 0) {
            TObject::operator delete(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8015BD68___vt__23TOContainerAncientEnemy_size[sizeof(RecoveredGlobal_8015BD68___vt__23TOContainerAncientEnemy) == 0x14C ? 1 : -1];
u8 *TOContainerAncientEnemy__ct(u8 *arg0, s32 arg1) {
    extern void *ancient_container_resource_bundle;
    init_container_base((arg0), (tl_05), (arg1));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8015BD68___vt__23TOContainerAncientEnemy *)&__vt__23TOContainerAncientEnemy).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TOContainerAncientEnemy__name;
    ((TOContainerAncientEnemy *)arg0)->mode = 0;
    ((TOContainerAncientEnemy *)arg0)->actorFlags = (s32) (((TOContainerAncientEnemy *)arg0)->actorFlags | 0x60000000);
    init_collision_body_parts(arg0, (void *)&TOContainerAncientEnemy__collision_body_params.value, 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x78) = (f32) (*(f32 *)((s8 *)arg0 + 0x78) + *(f32 *)((s8 *)&TOContainerAncientEnemy__collision_body_params.value + 4));
    *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model((void *) ((*(s32 *)&ancient_container_resource_bundle)), 0);
    ((TOContainerAncientEnemy *)arg0)->texlist = TObjFish__sub_8001EDB0((void *) ((*(s32 *)&ancient_container_resource_bundle)), 0);
    return arg0;
}

void TOContainerAncientItemNone::vfunc_6(s16 *arg1, s32 arg2) {
    if ((s16) *arg1 == 1) {
        if (arg2 != 0) {
            this->vfunc_79();
        }
        this->mode = 1;
        set_flag8();
        queue_destruction__7TObjectFv(this);
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
    u8 *arg0 = (u8 *)this;
    if ((s16) *arg1 == 1) {
        if (arg2 != 0) {
            ((VObj_8015BF38*)arg0)->m77();
            ((TObjChara *)arg0)->request_box_item_drop((u8 *)&this->position, 1);
        }
        this->mode = 1;
        ((TObjCollidable *)arg0)->set_flag8();
        queue_destruction__7TObjectFv(arg0);
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
            ((VObj_8015BF38 *) this)->m77();
            this->spawn_item((s32)this);
        }
        this->mode = 1;
        set_flag8();
        queue_destruction__7TObjectFv(this);
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
    Obj_8015C234 *self = (Obj_8015C234 *)this;
    if (this->mode == 1) {
        return;
    }
    TObjChipParams a = fish_break_debris_desc;
    a.pos[0] = self->x;
    a.pos[1] = self->y;
    a.pos[2] = self->z;
    a.pad_38[0] = a.pos[1];
    a.model = get_bml_model((void *)ancient_container_resource_bundle, 1);
    a.textures = TObjFish__sub_8001EDB0((void *)ancient_container_resource_bundle, 1);
    TObjChipParams b = lbl_8044074C;
    b.pos[0] = self->x;
    b.pos[1] = self->y;
    b.pos[2] = self->z;
    b.pad_38[0] = b.pos[1];
    b.model = get_bml_model((void *)ancient_container_resource_bundle, 2);
    b.textures = TObjFish__sub_8001EDB0((void *)ancient_container_resource_bundle, 2);
    if (check_value_equals__13TUnk_804B6C24Fl(self, (s32)TOContainerAncientItemRare__name) != 0) {
        a.textures = ancient_container_fragment_texture_lists[1];
        b.textures = ancient_container_fragment_texture_lists[2];
    }
    {
        u8 *o = (u8 *)TObject::operator new(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams(o, (u8 *)tl_05, (u8 *)&a);
        }
    }
    {
        u8 *o = (u8 *)TObject::operator new(0x234);
        if (o != NULL) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams(o, (u8 *)tl_05, (u8 *)&b);
        }
    }
    spawn_particle_effect(&self->x, 0x45);
    spawn_particle_effect(&self->x, 0x46);
    play_container_break_sound((s32)self);
}

void TUnk_804B08BC::vfunc_81() {
    extern void *ancient_container_resource_bundle;
    u8 *temp_r31;
    u8 *temp_r31_2;
    u8 *temp_r31_3;
    if ((u32) ancient_container_resource_bundle != 0U) {
        switch (this->mode) {
        case 0:
            push_matrix();
            post_translate_matrix((u8 *)&this->position);
            rotate_matrix_y(0, this->rotation_y);
            TObjFish::set_global_param(this->texlist);
            temp_r31 = (unsigned char *) (this->model);
            push_matrix();
            post_translate_matrix(temp_r31 + 8);
            draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
            temp_r31_2 = (unsigned char *) (*(void **)((s8 *)temp_r31 + 0x2C));
            push_matrix();
            post_translate_matrix(temp_r31_2 + 8);
            draw_ginja_model((*(s32 *)((s8 *)temp_r31_2 + 4)));
            pop_matrix();
            temp_r31_3 = (unsigned char *) (*(void **)((s8 *)temp_r31_2 + 0x30));
            push_matrix();
            post_translate_matrix(temp_r31_3 + 8);
            TParticleCtrl::begin_effect_render();
            draw_ginja_model((*(s32 *)((s8 *)temp_r31_3 + 4)));
            TParticleCtrl::end_effect_render();
            pop_matrix();
            pop_matrix();
            pop_matrix();
            break;
        }
    }
}
void TUnk_804B08BC::vfunc_80() {
    Obj_8015C48C *self = (Obj_8015C48C *)this;
    switch (this->mode) {
    case 0:
        if (this->m_364 != 0) {
            submit_cursor_candidate(self, -1);
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
    extern void *ancient_container_resource_bundle;
    init_container_base((arg0), (tl_05), (arg1));
    *(s32 **)((s8 *)arg0 + 0x18) = lbl_804B08BC;
    ((TUnk_804B08BC *)arg0)->mode = 0;
    ((TUnk_804B08BC *)arg0)->actorFlags = (s32) (((TUnk_804B08BC *)arg0)->actorFlags | 0x60000000);
    init_collision_body_parts(arg0, (void *)&TOContainerAncientEnemy__collision_body_params.value, 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x78) = (f32) (*(f32 *)((s8 *)arg0 + 0x78) + *(f32 *)((s8 *)&TOContainerAncientEnemy__collision_body_params.value + 4));
    *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model((void *) ((*(s32 *)&ancient_container_resource_bundle)), 0);
    ((TUnk_804B08BC *)arg0)->texlist = TObjFish__sub_8001EDB0((void *) ((*(s32 *)&ancient_container_resource_bundle)), 0);
    return arg0;
}

#pragma push
#pragma fp_contract on

void free_ancient_container_resources(void) {
    extern void *ancient_container_resource_bundle;
    s32 var_r31;
    s32 var_r30;
    void *p;
    if ((u32) ancient_container_fragment_texture_lists != 0U) {
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
        free_bin_model_request(p, 1);
        ancient_container_resource_bundle = NULL;
    }
}
#pragma pop

extern "C" {

void TLanguage::load_container_fragment_textures() {
    extern void *ancient_container_resource_bundle;
    u8 *tbl = (u8 *)&bm_o_container_ancient_resource_bundle;
    s32 area = get_current_floor_area();
    void *p;
    if (enable_v2_features == 1 &&
        (area == AREA_BATTLE1 || area == AREA_VR_SPACESHIP_ALPHA || area == AREA_VR_SPACESHIP_BETA || area == AREA_GOL_DRAGON)) {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, tbl + 0x50, 0, 0, 0);
        }
        ancient_container_resource_bundle = p;
        ancient_container_fragment_texture_lists = (u32 *)mem_alloc(0xC);
        ancient_container_fragment_texture_lists[0] = (u32)load_gvm_texture_file((s32)"fs_obj_ex_box2.gvm");
        ancient_container_fragment_texture_lists[1] = (u32)load_gvm_texture_file((s32)"fe_obj_ex_box2_hahen01.gvm");
        ancient_container_fragment_texture_lists[2] = (u32)load_gvm_texture_file((s32)"fe_obj_ex_box2_hahen02.gvm");
    } else if (enable_v2_features == 1 &&
               (area == AREA_BATTLE2 || area == AREA_VR_TEMPLE_ALPHA || area == AREA_VR_TEMPLE_BETA || area == AREA_BARBA_RAY)) {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, tbl + 0x30, 0, 0, 0);
        }
        ancient_container_resource_bundle = p;
        ancient_container_fragment_texture_lists = (u32 *)mem_alloc(0xC);
        ancient_container_fragment_texture_lists[0] = (u32)load_gvm_texture_file((s32)"fs_obj_o_vs2container_r.gvm");
        ancient_container_fragment_texture_lists[1] = (u32)load_gvm_texture_file((s32)"fe_obj_o_vs2cont_hahen1_r.gvm");
        ancient_container_fragment_texture_lists[2] = (u32)load_gvm_texture_file((s32)"fe_obj_o_vs2cont_hahen2_r.gvm");
    } else {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, tbl + 0x10, 0, 0, 0);
        }
        ancient_container_resource_bundle = p;
        ancient_container_fragment_texture_lists = (u32 *)mem_alloc(0xC);
        ancient_container_fragment_texture_lists[0] = (u32)load_gvm_texture_file((s32)"fe_obj_o_container_r.gvm");
        ancient_container_fragment_texture_lists[1] = (u32)load_gvm_texture_file((s32)"fe_obj_o_container_hahen01r.gvm");
        ancient_container_fragment_texture_lists[2] = (u32)load_gvm_texture_file((s32)"fe_obj_o_container_hahen02r.gvm");
    }
}

int TUnk_804B6C24::calc_distance_accuracy_penalty(void *, void *, void *, float) { return 1; }

f32 TUnk_804B6C24::receive_weapon_special_attack(void *, void *) {
    Obj_8015C88C *self = (Obj_8015C88C *)this;
    self->m20(0, lbl_805DB398);
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
