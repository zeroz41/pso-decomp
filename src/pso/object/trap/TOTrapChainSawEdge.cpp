#include "pso/system/BmlAccessors.h"
#pragma defer_codegen on

#include "pso/object/trap/TOTrapAncient02R.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/network/protocol/protocol_types.h"

#include "types.h"
#include <string.h>

#include "pso/render/GinjaMotionDraw.h"

#include "pso/system/task/TObject.h"

#include "pso/object/trap/TOTrapChainSawEdge.h"
#include "pso/render/ModelDrawContext.h"

#include "pso/player/TObjPlayer.h"

#include "pso/object/trap/TOTrapChainSawDamage.h"

#include "pso/object/trap/TOTrapChainSawKey.h"

#include "pso/object/trap/TOTrapChainSaw.h"

#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/ActorCollision.h"

#include "pso/map/FloorArea.h"

#include "pso/player/TObjPlayer_801AF2F0.h"

#include "pso/unk/text_803D853C.h"

#include "pso/unk/text_803D96A8.h"


#include "pso/object/base/TObjMapObject.h"

#include "pso/effect/particle/TParticleCtrl.h"

#include "pso/network/TLobby.h"

#include "pso/object/key/TOKey.h"

#include "pso/ui/hud/TRaderMapCore.h"

#include "pso/npc/TObjNpcEnemy.h"

#include "pso/object/ambient/TObjFish.h"
#include "pso/object/base/TObjBase.h"
#include "pso/network/client_id.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/system/MatrixStack.h"
#include "pso/ui/TLevelSelect.h"

#pragma readonly_strings on


typedef struct P_802C86D4 {
    u8 pad0[2];
    u16 sA;
    s16 sC;
    u8 pad6[2];
    s16 s10;
    s8 b12;
    s8 b13;
} P_802C86D4;


struct Pair_802C80F0 { s32 v[2]; };


struct T_802C8F68 { s32 r[3][3]; };

struct Copy_802C8E24 { u32 a; struct { u32 w[14]; } b; };


struct Pair_802C8C60 { s32 v[2]; };

struct Obj_802C8C60 {
    u8 pad0[0x24];
    saddr f24;
    u8 pad28[0x70 - 0x28];
    f32 f70;
    u8 pad74[0xB4 - 0x74];
    f32 fB4;
    f32 fB8;
    saddr motion;
    u8 padC0[0xC8 - 0xC0];
    s32 model;
    u8 padCC[0xF8 - 0xCC];
    s32 fF8;
};


typedef struct F4_802C8FF8 { f32 v[4]; } F4_802C8FF8;





extern "C" {
s8 get_current_floor(int);

f32 fabs_float(f32);





s32 get_area_table_value__17TOTrapChainSawKeyFii(TOTrapChainSaw *trap, s32 sound_index);

void vfunc_14__14TOTrapChainSawFv(void);



void rotate_matrix_y(int, void *);


NJS_OBJECT *seabed_suiso_linked_switch_counts[5];
NJS_OBJECT *seabed_suiso_switch_counts[5];


const char *chainsaw_ginja_model_filenames[6] = {
    "fe_obj_nokogiri_2m.gj", "fe_obj_nokogiri_4m.gj", "fe_obj_sekigai_light_moto.gj",
    "fe_obj_sekigai2m_moto.gj", "fe_obj_sekigai4m_moto.gj", NULL,
};

const char *bm_obj_jungle_nokogiri_motion_names[6] = {
    "fe_obj_nokogiri_2m.njm", "fe_obj_nokogiri_4m.njm", "fe_obj_sekigai_light_moto.njm",
    "fe_obj_sekigai2m_moto.njm", "fe_obj_sekigai4m_moto.njm", NULL,
};

BmlResourceDescriptor bm_obj_jungle_nokogiri_resource_descriptor = {
    "bm_obj_jungle_nokogiri.bml", chainsaw_ginja_model_filenames, bm_obj_jungle_nokogiri_motion_names, 5, 5,
};

const char *trap_chain_saw_name = "TOTrapChainSaw";

__declspec(section ".rodata") F4_802C8FF8 trap_chain_saw_level_scale_table = { 1.0f, 2.0f, 3.0f, 6.0f };

const T_802C8F68 chainsaw_area_table_values = { { { 0x4D01F, 0x4C122, 0x4BC21 }, { 0x4004D01F, 0x4004C122, 0x4004BC21 }, { 0x4004D01F, 0x4004C122, 0x4004BC21 } } };

const char *TOTrapChainSawDamage_class_name = "TOTrapChainSawDamage";

const s32 lbl_80471F28[2] = { 0, 1 };

const s32 lbl_80471F30[2] = { 0, 1 };

const char *trap_chain_saw_key_name = "TOTrapChainSawKey";

const s32 lbl_80471F4C[2] = { 3, 4 };

const s32 lbl_80471F54[2] = { 3, 4 };

const char *TOTrapChainSawEdge_class_name = "TOTrapChainSawEdge";

const s32 lbl_80471F70[2] = { 0, 1 };

const s32 lbl_80471F78[2] = { 0, 1 };

// Two collision bodies per variant, picked by the variant word at 0xF8.
CollisionBody chain_saw_damage_collision_body_parts[2][2] = {
    { { { -5.0f, 0.0f, 0.0f }, 3.0f, 0.0f, 0, 0x10403, { 0.0f, 0.0f, 0.0f }, 0.0f },
      { { -12.0f, 0.0f, 0.0f }, 2.0f, 8.0f, 1, 0x10503, { 0.0f, 0.0f, 0.0f }, 0.0f }, },
    { { { -5.0f, 0.0f, 0.0f }, 3.0f, 0.0f, 0, 0x10403, { 0.0f, 0.0f, 0.0f }, 0.0f },
      { { -20.0f, 0.0f, 0.0f }, 2.0f, 16.0f, 1, 0x10503, { 0.0f, 0.0f, 0.0f }, 0.0f }, },
};

CollisionBody chain_saw_collision_body_part_table[2][2] = {
    { { { 0.0f, 0.0f, 0.0f }, 3.0f, 0.0f, 0, 0x10403, { 0.0f, 0.0f, 0.0f }, 0.0f },
      { { -10.0f, 0.0f, 0.0f }, 2.0f, 8.0f, 1, 0x10503, { 0.0f, 0.0f, 0.0f }, 0.0f }, },
    { { { 0.0f, 0.0f, 0.0f }, 3.0f, 0.0f, 0, 0x10403, { 0.0f, 0.0f, 0.0f }, 0.0f },
      { { -20.0f, 0.0f, 0.0f }, 2.0f, 18.0f, 1, 0x10503, { 0.0f, 0.0f, 0.0f }, 0.0f }, },
};

static const f32 lbl_805DE620 = -1.0f;

BmlResource *lbl_805D6808;

}

#include "pso/render/NinjaUtil.h"

#include "pso/object/seabed/TObjSeabedSuisoBrakable.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/SoundEffect.h"

void TOTrapChainSaw::vfunc_16() {  }

void TOTrapChainSaw::vfunc_25() {  }

void TOTrapChainSawDamage__sub_802C9C00(u8 *arg0, s32 arg1) {
    *(s32 *)((s8 *)arg0 + 0x100) = (s32) (*(s32 *)((s8 *)arg0 + 0x100) + arg1);
}

void TOTrapChainSawDamage::set_damage(s32 v) { this->m_f8 = v; }

void TOTrapChainSaw::vfunc_29() {  }

void TOTrapChainSaw::vfunc_28() {  }

void TOTrapChainSaw::vfunc_27() {  }

void TOTrapChainSaw::vfunc_26() {  }

void TOTrapChainSaw::vfunc_18(TObjPlayer *) {  }

void TOTrapChainSawEdge::check_player_contact() {  }

void TOTrapChainSaw::load_shared_resource() {
    BmlResource *p;
    s32 i;
    NJS_OBJECT *root;
    p = new BmlResource(5, (BmlResourceDescriptor *)&bm_obj_jungle_nokogiri_resource_descriptor, 0, 0, NULL);
    lbl_805D6808 = p;
    for (i = 0; i < 5; i++) {
        seabed_suiso_linked_switch_counts[i] = NULL;
    }
    for (i = 0; i < 5; i++) {
        seabed_suiso_switch_counts[i] = NULL;
    }
    if (p != NULL) {
        root = (NJS_OBJECT *)get_bml_model(p, 3);
        if (root != NULL) {
            seabed_suiso_linked_switch_counts[1] = find_object_node(root, 3);
            seabed_suiso_linked_switch_counts[2] = find_object_node(root, 4);
            seabed_suiso_linked_switch_counts[3] = find_object_node(root, 5);
            seabed_suiso_linked_switch_counts[4] = find_object_node(root, 6);
        }
        root = (NJS_OBJECT *)get_bml_model((BmlResource *)lbl_805D6808, 4);
        if (root != NULL) {
            seabed_suiso_switch_counts[1] = find_object_node(root, 3);
            seabed_suiso_switch_counts[2] = find_object_node(root, 4);
            seabed_suiso_switch_counts[3] = find_object_node(root, 5);
            seabed_suiso_switch_counts[4] = find_object_node(root, 6);
        }
    }
}

void TOTrapChainSaw::unload_static_data() {
    s32 i;
    if (lbl_805D6808 != NULL) {
        delete (BmlResource *)lbl_805D6808;
        lbl_805D6808 = NULL;
    }
    for (i = 0; i < 5; i++) {
        seabed_suiso_linked_switch_counts[i] = NULL;
    }
    for (i = 0; i < 5; i++) {
        seabed_suiso_switch_counts[i] = NULL;
    }
}

NJS_OBJECT *TOTrapChainSawKey::get_model(s32 index) {
    if (lbl_805D6808 != NULL) {
        return (NJS_OBJECT *)get_bml_model((BmlResource *)lbl_805D6808, index);
    }
    return NULL;
}

AnimationMotion *TOTrapChainSawKey::get_motion(s32 index) {
    if (lbl_805D6808 != NULL) {
        return get_bml_motion(lbl_805D6808, index);
    }
    return NULL;
}

NJS_TEXLIST *fn_802C9924(s32 index) {
    if (lbl_805D6808 != NULL) {
        return get_bml_texlist((BmlResource *)lbl_805D6808, index);
    }
    return NULL;
}

TOTrapChainSaw::TOTrapChainSaw(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = trap_chain_saw_name;
    apply_object_set_data(set_data);
    clear_field_d8();
    yaw_offset = 0;
    max_offset = 0;
    step = 0;
    m_c8 = 0;
    behavior = 0;
    switch_id = 0;
    pause_timer = 0;
}

TOTrapChainSaw::~TOTrapChainSaw() {}

void TOTrapChainSaw::decode_params() {
    s32 var_r0;
    s32 temp_r3;
    u32 var_r0_2;
    u32 temp_r3_2;

    switch_id = (s32) (u16) this->set_params[0];
    temp_r3 = switch_id;
    if (temp_r3 < 0) {
        var_r0 = 0;
    } else {
        var_r0 = 0xFF;
        if (temp_r3 <= 0xFF) {
            var_r0 = temp_r3;
        }
    }
    switch_id = var_r0;
    if (is_current_floor_switch_set((u16) switch_id) == 1) {
        switch_on = 1;
    } else {
        switch_on = 0;
    }
    max_offset = (u32) ((u32) set_params[1] >> 0x10U);
    step = (s32) (u16) set_params[1];
    behavior = (u32) ((u32) set_params[2] >> 0x10U);
    temp_r3_2 = behavior;
    if ((s32) temp_r3_2 < 0) {
        var_r0_2 = 0;
    } else {
        var_r0_2 = 1;
        if ((s32) temp_r3_2 <= 1) {
            var_r0_2 = temp_r3_2;
        }
    }
    behavior = var_r0_2;
}

void TOTrapChainSaw::run_task() {
    this->update_state();
    this->check_player_contact();
    if (is_current_floor_switch_set((u16) switch_id) == 1) {
        switch_on = 1;
        return;
    }
    switch_on = 0;
}
#pragma push
#pragma opt_propagation off
void TOTrapChainSaw::update_state() {
    static void (TOTrapChainSaw::*tbl[2])() = { &TOTrapChainSaw::update_extension, &TOTrapChainSaw::update_sweep };
    (this->*tbl[behavior])();
    // This trap keeps its frame at 0xB4, the frame step at 0xB8 and its motion at 0xBC
    // (TObjMapObject's fields are laid out differently).
    if (*(u8 **)((s8 *)this + 0xBC) != NULL) {
        *(f32 *)((s8 *)this + 0xB4) = *(f32 *)((s8 *)this + 0xB4) + *(f32 *)((s8 *)this + 0xB8);
        if (*(f32 *)((s8 *)this + 0xB4) > (f32) (u32) (*(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0xBC)) + 4) - 1)) {
            *(f32 *)((s8 *)this + 0xB4) = (0.0f);
        }
    }
}
#pragma pop
void TOTrapChainSaw::update_sweep() {
    if (switch_on == 0) {
        if ((s32) yaw_offset == 0) {
            this->vfunc_26();
        }
        this->vfunc_27();
        yaw_offset = (saddr) (yaw_offset + step);
        return;
    }
    yaw_offset = (s32) (yaw_offset - step);
    if ((s32) yaw_offset < 0) {
        yaw_offset = 0;
    }
}

void TOTrapChainSaw::update_extension() {
    if (switch_on == 0) {
        if (pause_timer > 0) {
            pause_timer = pause_timer - 1;
            return;
        }
        if (yaw_offset == 0) {
            vfunc_26();
        }
        vfunc_27();
        yaw_offset = yaw_offset + step;
        if (yaw_offset < 0) {
            yaw_offset = 0;
            step = (s32)((f32)step * *(const volatile f32 *)&lbl_805DE620);
            pause_timer = (s32)(30.0f * (f32)(u16)set_params[2]);
            vfunc_29();
        }
        if (yaw_offset > max_offset) {
            yaw_offset = max_offset;
            step = (s32)((f32)step * *(const volatile f32 *)&lbl_805DE620);
            vfunc_28();
        }
    } else {
        step = (s32)fabs_float((f32)step);
        yaw_offset = yaw_offset - step;
        if (yaw_offset < 0) {
            yaw_offset = 0;
        }
    }
}

void TOTrapChainSaw::check_player_contact() {
    s32 i;
    TObjPlayer *p;
    s32 t;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        for (i = 0; i < 4; i++) {
            p = get_player_by_client_id(i);
            if (p != 0 && this->consume_counter(p) == 0) {
                if (p->get_floor() == ((s32 (*)(void))get_current_floor)()) {
                    t = rotation_y;
                    rotation_y = t + yaw_offset;
                    if (check_actor_body_contact(p, (f32)((1e+02f))) != 0) {
                        vfunc_18(p);
                        this->set_hit_cooldown_for_player(p);
                    }
                    rotation_y = t;
                }
            }
        }
    } else {
        TObjPlayer *q;
        s32 t2;
        q = get_player_by_client_id(local_client_id);
        if (q != 0 && this->consume_counter(q) == 0) {
            if (q->get_floor() == ((s32 (*)(void))get_current_floor)()) {
                t2 = rotation_y;
                rotation_y = t2 + yaw_offset;
                if (check_actor_body_contact(q, (f32)((1e+02f))) != 0) {
                    vfunc_18(q);
                    this->set_hit_cooldown_for_player(q);
                }
                rotation_y = t2;
            }
        }
    }
}

s32 TOTrapChainSaw::consume_counter(TObjPlayer *player) {
    s32 i = player->get_entity_id();
    if (i >= 0 && i < 4) {
        if (hit_cooldown[i] > 0) {
            hit_cooldown[i] = hit_cooldown[i] - 1;
            return 1;
        }
    }
    return 0;
}

void TOTrapChainSaw::set_hit_cooldown_for_player(TObjPlayer *player) {
    s32 i = player->get_entity_id();
    if (i >= 0 && i < 4) {
        hit_cooldown[i] = 0x96;
    }
}

void TOTrapChainSaw::clear_field_d8() { memset(hit_cooldown, 0, sizeof(hit_cooldown)); }

void TOTrapChainSaw::render() {
    if (this->update_object_view_visibility((4e+02f), (5e+01f)) == 1) {
        this->vfunc_25();
        this->update_demo();
    }
}

void TOTrapChainSaw::vfunc_14() {  }

void TOTrapChainSaw::update_demo() {
    s32 temp_r31;

    if (TObjPlayer::check_demo_mode() == 1) {
        temp_r31 = rotation_y;
        rotation_y = (saddr) (temp_r31 + yaw_offset);
        sub_80154D78();
        rotation_y = temp_r31;
    }
}

f32 TOTrapChainSaw::scale_by_level(f32 level) {
    F4_802C8FF8 t = trap_chain_saw_level_scale_table;
    return level * t.v[game_difficulty_selection];
}
#pragma push
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_depth(1)
s32 get_area_table_value__17TOTrapChainSawKeyFii(TOTrapChainSaw *trap, s32 sound_index) {
    T_802C8F68 t = chainsaw_area_table_values;
    s32 *p = t.r[0];
    switch (get_current_floor_area()) {
    case AREA_SEASIDE_NIGHT:
        p = t.r[1];
        break;
    case AREA_TOWER:
        p = t.r[2];
        break;
    }
    return p[sound_index];
}
TOTrapChainSawDamage::TOTrapChainSawDamage(TObject *parent, void *set_data) : TOTrapChainSaw(parent, set_data) {
    void *o;
    *(saddr *)(((u8 *)((u8 *)this)) + 0) = (saddr) TOTrapChainSawDamage_class_name;
    this->decode_params();
    this->vfunc_16();
    init_collision_body_parts(this, chain_saw_damage_collision_body_parts[*(s32 *)(((u8 *)((u8 *)this)) + 0xF8)], 2);
    this->refresh_collision_body_centers();
    this->register_object_by_id();
    *(f32 *)(((u8 *)((u8 *)this)) + 0x3C) += (5.0f);
    {
        Copy_802C8E24 c = *(Copy_802C8E24 *)set_data;
        *(f32 *)((u8 *)&c + 0x10) += (1e+01f);
        o = new TOTrapChainSawEdge((TObject *)this, &c);
        *(void **)(((u8 *)((u8 *)this)) + 0x104) = o;
        *(f32 *)((u8 *)&c + 0x10) += (5.0f);
        o = new TOTrapChainSawEdge((TObject *)this, &c);
        *(void **)(((u8 *)((u8 *)this)) + 0x108) = o;
    }
}
TOTrapChainSawDamage::~TOTrapChainSawDamage() {
    ((TObjCollidable *)this)->unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TOTrapChainSawDamage::create(void *set_data) {
    return new TOTrapChainSawDamage(tl_05, set_data);
}

void TOTrapChainSawDamage::decode_params() {
    TOTrapChainSaw::decode_params();
    *(f32 *)((s8 *)this + 0xFC) = (f32) this->scale.y;
}

void TOTrapChainSawDamage::vfunc_16() {
    Obj_802C8C60 *arg0 = (Obj_802C8C60 *)this;
    Pair_802C8C60 a = *(Pair_802C8C60 *)lbl_80471F28;
    Pair_802C8C60 b = *(Pair_802C8C60 *)lbl_80471F30;
    s32 v;
    arg0->fF8 = (s32)arg0->f70;
    v = arg0->fF8;
    arg0->fF8 = v < 0 ? 0 : (v > 1 ? 1 : v);
    arg0->model = (saddr)TOTrapChainSawKey::get_model(a.v[arg0->fF8]);
    arg0->motion = (saddr)TOTrapChainSawKey::get_motion(b.v[arg0->fF8]);
    arg0->f24 = (saddr)fn_802C9924(0);
    arg0->fB4 = (0.0f);
    arg0->fB8 = (1.0f);
}
void TOTrapChainSawDamage::vfunc_18(TObjPlayer *player) {
    DirectAttackPayload attack;
    attack.kind = 0;
    attack.power = scale_by_level(*(f32 *)((s8 *)this + 0xFC));
    player->receive_direct_attack(this, attack, NULL, -1, -1);
    player->set_actor_flags(0x400);
}
void TOTrapChainSawDamage::update_state() {
    TOTrapChainSaw::update_state();
    if ((s32) *(s32 *)((s8 *)this + 0xF0) == 1) {
        this->clear_player_status_flag(1, 0x100);
        return;
    }
    set_indexed_flags(1, 0x100);
}
#pragma pop
void TOTrapChainSawDamage::vfunc_25() {
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(*(void **)((s8 *)this + 0x24)));
    push_matrix();
    post_translate_matrix(&this->position.x);
    push_matrix();
    rotate_matrix_y(0, *(void **)((s8 *)this + 0x60));
    rotate_matrix_y(0, *(void **)((s8 *)this + 0xD4));
    draw_ginja_model_with_motion(*(void **)((s8 *)this + 0xC8), *(void **)((s8 *)this + 0xBC), this->animation_end_frame);
    pop_matrix();
    pop_matrix();
}

void TOTrapChainSawDamage::vfunc_14() {
    vfunc_14__14TOTrapChainSawFv();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    ((void (*)(int, void *, ...))debug_printf_at)(0x13001D, (void *)"<- DAMAGE POWER");
    ((void (*)(int, void *, ...))debug_printf_at)(0x13001E, (void *)"<- SELECT A MODEL");
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TOTrapChainSawDamage::vfunc_26() { *(s32*)((char*)this + 0x100) = 0; }
#pragma push
#pragma fp_contract on
void TOTrapChainSawDamage::vfunc_27() {
    *(s32 *)((s8 *)((u8 *)this) + 0x100) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x100) + 1);
    void *p;
    if (((s32) *(s32 *)((s8 *)((u8 *)this) + 0x100) == 5) && ((p = *(void **)((s8 *)((u8 *)this) + 0x104)) != NULL)) {
        TOTrapChainSawDamage__sub_802C9C00((u8 *)p, 1);
    }
    if (((s32) *(s32 *)((s8 *)((u8 *)this) + 0x100) == 0xA) && ((p = *(void **)((s8 *)((u8 *)this) + 0x108)) != NULL)) {
        TOTrapChainSawDamage__sub_802C9C00((u8 *)p, 1);
    }
    play_persistent_sound(get_area_table_value__17TOTrapChainSawKeyFii(this, 0), this, &position, 0, 0);
}
#pragma pop
void TOTrapChainSawDamage::vfunc_28() {
    if (*(void **)((s8 *)this + 0x104) != NULL) {
        ((TOTrapChainSawDamage *)(*(void **)((s8 *)this + 0x104)))->set_damage((saddr)(*(void **)((s8 *)this + 0xD4)));
    }
    if (*(void **)((s8 *)this + 0x108) != NULL) {
        ((TOTrapChainSawDamage *)(*(void **)((s8 *)this + 0x108)))->set_damage((saddr)(*(void **)((s8 *)this + 0xD4)));
    }
}
TOTrapChainSawKey::TOTrapChainSawKey(TObject *parent, void *set_data) : TOTrapChainSaw(parent, set_data) {
    *(saddr *)((s8 *)((u8 *)this) + 0) = (saddr) trap_chain_saw_key_name;
    this->decode_params();
    this->vfunc_16();
    init_collision_body_parts(this, chain_saw_collision_body_part_table[*(s32 *)((s8 *)((u8 *)this) + 0xF8)], 2);
    this->refresh_collision_body_centers();
    this->register_object_by_id();
}
TOTrapChainSawKey::~TOTrapChainSawKey() {
    ((TObjCollidable *)this)->unregister_object_by_id();
    free_collision_body_parts(this);
}

void *TOTrapChainSawKey::create(void *set_data) {
    return new TOTrapChainSawKey(tl_05, set_data);
}

void TOTrapChainSawKey::decode_params() { TOTrapChainSaw::decode_params(); }

void TOTrapChainSawKey::vfunc_16() {
    Pair_802C80F0 a = *(Pair_802C80F0 *)lbl_80471F4C;
    Pair_802C80F0 b = *(Pair_802C80F0 *)lbl_80471F54;
    s32 x;
    *(s32 *)((s8 *)((u8 *)this) + 0xF8) = (s32) *(f32 *)((s8 *)((u8 *)this) + 0x70);
    x = *(s32 *)((s8 *)((u8 *)this) + 0xF8);
    *(s32 *)((s8 *)((u8 *)this) + 0xF8) = (x < 0) ? 0 : ((x > 1) ? 1 : x);
    *(s32 *)((s8 *)((u8 *)this) + 0xC8) = (saddr)TOTrapChainSawKey::get_model(a.v[*(s32 *)((s8 *)((u8 *)this) + 0xF8)]);
    *(s32 *)((s8 *)((u8 *)this) + 0xBC) = (saddr)TOTrapChainSawKey::get_motion((s32)(b.v[*(s32 *)((s8 *)((u8 *)this) + 0xF8)]));
    *(saddr *)((s8 *)((u8 *)this) + 0x24) = (saddr)fn_802C9924(3);
    *(f32 *)((s8 *)((u8 *)this) + 0xB4) = (0.0f);
    *(f32 *)((s8 *)((u8 *)this) + 0xB8) = (1.0f);
    *(s32 *)((s8 *)((u8 *)this) + 0xFC) = (saddr)TOTrapChainSawKey::get_model(2);
    *(s32 *)((s8 *)((u8 *)this) + 0x100) = (saddr)TOTrapChainSawKey::get_motion(2);
    *(f32 *)((s8 *)((u8 *)this) + 0x104) = (0.0f);
    *(f32 *)((s8 *)((u8 *)this) + 0x108) = (1.0f);
}

void TOTrapChainSawKey::vfunc_18(TObjPlayer *) {
    P_802C86D4 p;
    ((G_SwitchStateChanged_6x05 *)(&p))->init();
    p.sC = 0;
    p.sA = 0xFFFF;
    p.s10 = static_cast<s16>(switch_id);
    p.b12 = get_current_floor(0xFFFF);
    p.b13 = 1;
    ((G_SwitchStateChanged_6x05 *)(&p))->send();
}

void TOTrapChainSawKey::update_state() {
    TOTrapChainSaw::update_state();
    *(f32 *)((s8 *)this + 0x104) = (f32) (*(f32 *)((s8 *)this + 0x104) + *(f32 *)((s8 *)this + 0x108));
    if (*(f32 *)((s8 *)this + 0x104) > (f32) (u32) (*(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x100)) + 4) - 1)) {
        *(f32 *)((s8 *)this + 0x104) = 0.0f;
    }
    play_persistent_sound(get_area_table_value__17TOTrapChainSawKeyFii(this, 2), this, &position, 0, 0);
    if ((s32) *(s32 *)((s8 *)this + 0xF0) == 1) {
        play_persistent_sound(get_area_table_value__17TOTrapChainSawKeyFii(this, 1), this, &position, 0, 0);
    }
}

void TOTrapChainSawKey::vfunc_14() {
    ((s32 (*)(void))vfunc_14__14TOTrapChainSawFv)();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x13001E, "<- SELECT A MODEL");
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TOTrapChainSawKey::vfunc_25() {
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(*(void **)((s8 *)this + 0x24)));
    push_matrix();
    post_translate_matrix(&this->position.x);
    push_matrix();
    rotate_matrix_y(0, *(void **)((s8 *)this + 0x60));
    rotate_matrix_y(0, *(void **)((s8 *)this + 0xD4));
    set_model_node_callback(TParticleCtrl__sub_802C8464);
    draw_ginja_motion(*(NJS_OBJECT **)((s8 *)this + 0xC8), *(NJS_MOTION **)((s8 *)this + 0xBC), this->animation_end_frame);
    set_model_node_callback(0);
    if (*(s32 *)((s8 *)this + 0xF0) == 1) {
        TParticleCtrl::begin_effect_render();
        draw_ginja_model_with_motion(*(void **)((s8 *)this + 0xFC), *(void **)((s8 *)this + 0x100), *(f32 *)((s8 *)this + 0x104));
        TParticleCtrl::end_effect_render();
    }
    pop_matrix();
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

void TOTrapChainSawKey::check_player_contact() { if (*(int*)((char*)this + 0xf0) != 1) { TOTrapChainSaw::check_player_contact(); } }

void TOTrapChainSawKey::vfunc_27() {  }

void TParticleCtrl__sub_802C8464(NJS_OBJECT *arg0) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (arg0 == seabed_suiso_linked_switch_counts[i]) {
            TParticleCtrl::begin_effect_render();
            return;
        }
    }
    for (i = 0; i < 5; i++) {
        if (arg0 == seabed_suiso_switch_counts[i]) {
            TParticleCtrl::begin_effect_render();
            return;
        }
    }
    TParticleCtrl::end_effect_render();
}

#define trap_chain_saw_edge ((u8 *)this)
TOTrapChainSawEdge::TOTrapChainSawEdge(TObject *parent, void *set_data) : TOTrapChainSaw(parent, set_data) {
    *(saddr *)((s8 *)trap_chain_saw_edge + 0) = (saddr) TOTrapChainSawEdge_class_name;
    ((TOTrapChainSawEdge *)(trap_chain_saw_edge))->decode_params();
    ((TOTrapChainSawEdge *)(trap_chain_saw_edge))->vfunc_16();
    *(s32 *)((s8 *)trap_chain_saw_edge + 0x100) = 0;
    *(s32 *)((s8 *)trap_chain_saw_edge + 0x104) = 0;
}

#undef trap_chain_saw_edge
TOTrapChainSawEdge::~TOTrapChainSawEdge() {}

void TOTrapChainSawEdge::update_extension() {
    s32 temp_r4;
    s32 temp_r4_2;

    switch (*(saddr *)((s8 *)this + 0x104)) {
    case 0:
        temp_r4 = *(s32 *)((s8 *)this + 0x100);
        if (temp_r4 > 0) {
            *(s32 *)((s8 *)this + 0x100) = (temp_r4 - 1);
            *(s32 *)((s8 *)this + 0xF8) = (saddr) *(s32 *)((s8 *)this + 0xCC);
            *(s32 *)((s8 *)this + 0x104) = 1;
        }
        break;
    case 1:
        yaw_offset = (saddr) (yaw_offset + *(s32 *)((s8 *)this + 0xD0));
        if ((s32) yaw_offset < 0) {
            yaw_offset = 0;
            *(s32 *)((s8 *)this + 0xD0) = (saddr) ((f32) *(s32 *)((s8 *)this + 0xD0) * *(const volatile f32 *)&lbl_805DE620);
            *(s32 *)((s8 *)this + 0x104) = 0;
        }
        if (yaw_offset > (temp_r4_2 = *(s32 *)((s8 *)this + 0xCC))) {
            yaw_offset = temp_r4_2;
            *(s32 *)((s8 *)this + 0xD0) = (saddr) ((f32) *(s32 *)((s8 *)this + 0xD0) * *(const volatile f32 *)&lbl_805DE620);
        }
        break;
    }
}

void TOTrapChainSawEdge::update_sweep() {
    s32 temp_r4;

    switch (*(s32 *)((s8 *)this + 0x104)) {
    case 0:
        temp_r4 = *(s32 *)((s8 *)this + 0x100);
        if (temp_r4 > 0) {
            *(s32 *)((s8 *)this + 0x100) = (temp_r4 - 1);
            *(s32 *)((s8 *)this + 0xF8) = (s32) *(s32 *)((s8 *)this + 0xCC);
            *(s32 *)((s8 *)this + 0x104) = 1;
        }
        return;
    case 1:
        yaw_offset = (s32) (yaw_offset + *(s32 *)((s8 *)this + 0xD0));
        return;
    }
}

void TOTrapChainSawEdge::vfunc_25() {
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(*(void **)((s8 *)this + 0x24)));
    push_matrix();
    post_translate_matrix(&this->position.x);
    push_matrix();
    rotate_matrix_y(0, *(void **)((s8 *)this + 0x60));
    rotate_matrix_y(0, *(void **)((s8 *)this + 0xD4));
    draw_ginja_model_with_motion(*(void **)((s8 *)this + 0xC8), *(void **)((s8 *)this + 0xBC), this->animation_end_frame);
    pop_matrix();
    pop_matrix();
}

void TOTrapChainSawEdge::vfunc_16() {
    Pair_802C80F0 a = *(Pair_802C80F0 *)lbl_80471F70;
    Pair_802C80F0 b = *(Pair_802C80F0 *)lbl_80471F78;
    s32 x;
    *(s32 *)((s8 *)this + 0xFC) = (s32) this->scale.z;
    x = *(s32 *)((s8 *)this + 0xFC);
    *(s32 *)((s8 *)this + 0xFC) = x < 0 ? 0 : (x > 1 ? 1 : x);
    *(s32 *)((s8 *)this + 0xC8) = (saddr)TOTrapChainSawKey::get_model(a.v[*(s32 *)((s8 *)this + 0xFC)]);
    *(s32 *)((s8 *)this + 0xBC) = (saddr)TOTrapChainSawKey::get_motion(b.v[*(s32 *)((s8 *)this + 0xFC)]);
    this->texlist = fn_802C9924(0);
    this->animation_end_frame = (0.0f);
    this->animation_step = (1.0f);
}
