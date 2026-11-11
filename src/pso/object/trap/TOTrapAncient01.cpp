#include "types.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F764.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/RenderFadeState_800D7BFC.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/trap/TOTrapAncient02R.h"
#include "pso/object/trap/TOTrap.h"
#include "pso/object/trap/TOTrapAncient01.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/render/RenderFadeState.h"
#include "pso/object/TMotorcycle.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/math/MatrixTransforms.h"
#include <stdlib.h>
#include "pso/unk/text_803D96A8.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/render_util.h"
#include "pso/render/model_render_state.h"
#include "pso/math/ScratchVectors.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TUnk_804B6C24.h"
#include "pso/boss/volopt/TObjVoloptCage.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/network/client_id.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_800FD8A0.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/object/TObjChip.h"
#include "pso/system/SoundEffect.h"

#include "pso/system/NinjaTypes.h"

BmlResource *TOTrapAncient01__bml_resource;

const char *bm_o_trap_ancient01_model_names[] = {
    "fe_obj_o_turigane_hahen01.gj",
    "fe_obj_o_turigane_hahen02.gj",
    "fe_obj_o_turigane_hahen03.gj",
    "fs_obj_o_turigane.gj",
    NULL,
};
const char *bm_o_trap_ancient01_motion_names[] = {NULL};
BmlResourceDescriptor bm_o_trap_ancient01_resource_descriptor = {
    "bm_o_trap_ancient01.bml", bm_o_trap_ancient01_model_names, bm_o_trap_ancient01_motion_names, 4, 0,
};
// name inferred: the one body the ctor hands to init_collision_body_parts
static CollisionBody trap_ancient01_collision_body[1] = {
    {{0.0f, 20.0f, 0.0f}, 14.0f, 0.0f, 0, 0x08011F04, {0.0f, 0.0f, 0.0f}, 0.0f},
};
const char *TOTrapAncient01__class_name = "TOTrapAncient01";

struct VBase_801797D4 { char pad[0x18]; };

struct VObj_801797D4 : VBase_801797D4 {
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
    virtual void m21(void *, void *, s32, s32, s32);
    virtual void m22();
    virtual void m23(void *, f32);
};

struct Ent_801797D4 { u8 pad[0xC]; f32 fC; };

struct Pair_801797D4 { s32 a; s32 b; };

struct Trap_801797D4 : VObj_801797D4 {
    u8 pad1C[0xA4 - 0x1C];
    Ent_801797D4 *fA4;
    u8 padA8[0x2A8 - 0xA8];
    s32 f2A8;
    u8 pad2AC[0x344 - 0x2AC];
    Pair_801797D4 f344;
    u8 pad34C[0x354 - 0x34C];
    f32 f354;
};

extern "C" {
VObj_801797D4 *get_battle_param__10TObjPlayerFi(s32);
s32 check_value_equals__13TUnk_804B6C24Fl(void *, s32);
extern s32 lbl_805D3530;
void TOTrapAncient02R__sub_80154D78(void *);
}

void TOTrapAncient02R::vfunc_86() {
    if (is_current_room(this) == 1) {
        fn_80141CF0(&home_position, &scratch_vec, &trap_ancient_light_color);
        TOTrapAncient02R__sub_80154D78(this);
    }
}

f32 TObjPlayer__sub_8017A1A4(TObjCollidable *actor, s32 body) {
    return actor->bodies[body].radius;
}

#pragma push
#pragma fp_contract on
TOTrapAncient01::TOTrapAncient01(TObject *parent, void *set_data) : TOTrap(parent) {
    s32 i;
    m_name = TOTrapAncient01__class_name;
    apply_object_set_data(set_data);
    ((TObjPlayer *)this)->init_position_vectors();
    calc_attach_pos();
    model = (void *)get_bml_model(TOTrapAncient01__bml_resource, 3);
    texlist = TObjFish__sub_8001EDB0(TOTrapAncient01__bml_resource, 3);
    mode = 0;
    range = 0.5f * scale.x + 30.0f;
    if (scale.y < 0.0f) {
        scale.y = 0.0f;
    }
    if (scale.z < 1.0f) {
        scale.z = 1.0f;
    }
    scale_step = -scale.y / scale.z;
    damage_delay = 30.0f + (f32)set_params[2];
    if (get_main_phase() == 0xE) {
        damage_delay *= 0.33f;
    }
    if (damage_delay < 0.0f) {
        damage_delay = 0.0f;
    }
    damage_timer = damage_delay;
    if (set_params[0] < 0) {
        set_params[0] = 0;
    }
    payload.power = scale_by_table_value((f32)set_params[0]);
    if (set_params[1] < 0) {
        set_params[1] = 0;
    } else if (set_params[1] > 5) {
        set_params[1] = 5;
    }
    payload.kind = set_params[1];
    dist = 15.0f;
    player = 0xFFFF;
    init_collision_body_parts(this, trap_ancient01_collision_body, 1);
    refresh_collision_body_centers();
    actorFlags |= 0x60040000;
    get_or_assign_entity_id(0);
    ((TObjPlayer *)this)->register_object_by_id();
    for (i = 0; i < 4; i++) {
        fades[i].activate_and_dispatch();
    }
}
#pragma pop

TOTrapAncient01::~TOTrapAncient01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TOTrapAncient01::load_resources() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_o_trap_ancient01_resource_descriptor, 0, 0, 0);
    }
    TOTrapAncient01__bml_resource = resource;
    TMotorcycle::add_entry(0x39, get_bml_model(TOTrapAncient01__bml_resource, 3), TObjFish__sub_8001EDB0(resource, 3), 20.0f, 0.0f);
}

void TOTrapAncient01::release_static_resource() {
    if (TOTrapAncient01__bml_resource != NULL) {
        free_bin_model_request(TOTrapAncient01__bml_resource, 1);
        TOTrapAncient01__bml_resource = NULL;
    }
}

void *TOTrapAncient01::create() {
    return new TOTrapAncient01(tl_05, this);
}

#pragma push
#pragma opt_lifetimes off
#pragma fp_contract on
void TOTrapAncient01::render() {
    RenderFadeState *fade;
    NJS_OBJECT *n;
    s32 i;
    Vec v;
    i = 0;
    if (is_split_screen() != 0) {
        i = TCameraCtrl::get_camera_mode();
    }
    fade = &fades[i];
    fade->update();
    m_340 = update_object_view_visibility(400.0f, 20.0f);
    if (m_340 == 1) {
        if (fade->updateFromCamera(&position.x) == 1) {
            saved_model_render_flags = model_render_flags;
            saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
            saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
            fade->set_flags_and_apply_damage_color();
        }
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        if (TObjPlayer::check_demo_mode() != 1 && scale.y <= 0.0f) {
            v.x = 0.1f * (3.0517578125e-05f * (f32)rand()) - 0.05f;
            v.y = 0.0f;
            v.z = 0.1f * (3.0517578125e-05f * (f32)rand()) - 0.05f;
            post_translate_matrix(&v.x);
        }
        TObjFish::set_global_param(texlist);
        n = (NJS_OBJECT *)model;
        push_matrix();
        translate_matrix(0, 0.0f, scale.y, 0.0f);
        post_translate_matrix(n->pos);
        draw_ginja_model((s32)((NJS_OBJECT *)model)->model);
        n = n->child;
        push_matrix();
        post_translate_matrix(n->pos);
        TParticleCtrl::begin_effect_render();
        draw_ginja_model((s32)n->model);
        TParticleCtrl::end_effect_render();
        pop_matrix();
        pop_matrix();
        pop_matrix();
        if (fade->updateFromCamera(&position.x) == 1) {
            fade->clear_flag_and_notify();
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            model_render_flags = saved_model_render_flags;
        }
    }
}
#pragma pop

void TOTrapAncient01::vfunc_81() {
    TObjPlayer *player;
    f32 dist;
    scale.y += scale_step;
    if (0.0f < scale.y) {
        switch (get_current_floor_area()) {
        case AREA_PIONEER2_EP1:
            break;
        case AREA_CAVE1:
        case AREA_CAVE2:
        case AREA_CAVE3:
            play_persistent_sound(0x4321A, (s32)this, (u32)&position, 0, 0);
            break;
        case AREA_MINE1:
        case AREA_MINE2:
            play_persistent_sound(0x4004B211, (s32)this, (u32)&position, 0, 0);
            break;
        case AREA_RUINS1:
        case AREA_RUINS2:
        case AREA_RUINS3:
            play_persistent_sound(0x4004B217, (s32)this, (u32)&position, 0, 0);
            break;
        case AREA_VR_SPACESHIP_ALPHA:
        case AREA_VR_SPACESHIP_BETA:
            play_persistent_sound(0x4004B212, (s32)this, (u32)&position, 0, 0);
            break;
        }
    } else {
        mode = 3;
        scale.y = 0.0f;
        calc_attach_pos();
        clear_player_status_flag(0, 0x08001F04);
        set_indexed_flags(0, 0x8003);
        obj_clearFlags30(0x40000);
        spawn_particle_effect(&position, 0x8F);
        spawn_particle_effect(&position, 0x8F);
        this->player = find_nearest_visible_player((TObjEnemy *)this, NULL, range);
        if (this->player != 0xFFFF) {
            player = get_player_by_client_id(this->player);
            target = (u8 *)player;
            if (target != NULL) {
                dist = horizontal_distance_squared(&((TObjBase *)target)->position, &position);
                this->dist -= TObjPlayer__sub_8017A1A4(player, 0);
                if (dist < this->dist * this->dist) {
                    if (TObjPlayer::is_locally_controlled(target) != 0) {
                        send_6x2C_impose_hold(player, &position, -1, 0, this->dist);
                        obj_set_flag_20000(player);
                    }
                } else {
                    this->player = 0xFFFF;
                    target = NULL;
                }
            }
        } else {
            target = NULL;
        }
    }
}

void TOTrapAncient01::vfunc_82() {
    s32 i;
    VObj_801797D4 *p;
    this->calc_attach_pos();
    ((Trap_801797D4 *)this)->f354 -= 1.0f;
    if (((Trap_801797D4 *)this)->f354 < 0.0f) {
        ((Trap_801797D4 *)this)->fA4->fC = 15.0f;
        set_indexed_flags(0, 0x100);
        TObjPlayer::init_all_slots();
        ((TObjPlayer *)this)->check_object_collisions();
        for (i = 0; i < 16; i++) {
            p = get_battle_param__10TObjPlayerFi(i);
            if (p == 0) {
                break;
            }
            if (obj_is_hit_receivable((u8 *)p) == 0) {
                break;
            }
            if (check_value_equals__13TUnk_804B6C24Fl(p, lbl_805D3530) == 0) {
                break;
            }
            {
            Pair_801797D4 v = ((Trap_801797D4 *)this)->f344;
            p->m21(this, &v, 0, -1, -1);
            }
            if (((Trap_801797D4 *)this)->f344.a < 5) {
                p->m23(((Trap_801797D4 *)this), 0.0f);
            }
        }
        ((Trap_801797D4 *)this)->m20(((Trap_801797D4 *)this)->f2A8, 1.0f);
    }
    submit_cursor_candidate(((Trap_801797D4 *)this), -1);
    switch (get_current_floor_area()) {
    case AREA_RUINS1:
    case AREA_RUINS2:
    case AREA_RUINS3:
        play_persistent_sound(0x4004C618, (s32)this, (u32)&position, 0, 0);
        break;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_persistent_sound(0x4004C610, (s32)this, (u32)&position, 0, 0);
        break;
    case AREA_PIONEER2_EP1:
        return;
    case AREA_FOREST1:
        break;
    case AREA_FOREST2:
        return;
    case AREA_CAVE1:
        break;
    case AREA_CAVE2:
        return;
    case AREA_CAVE3:
        break;
    case AREA_MINE1:
        return;
    case AREA_MINE2:
        break;
    case AREA_DRAGON:
        break;
    case AREA_DE_ROL_LE:
        return;
    case AREA_VOL_OPT:
        break;
    case AREA_DARK_FALZ:
        return;
    case AREA_LOBBY:
        break;
    case AREA_BATTLE1:
        return;
    case AREA_BATTLE2:
        break;
    case AREA_PIONEER2_EP2:
        return;
    case AREA_VR_TEMPLE_ALPHA:
        break;
    case AREA_VR_TEMPLE_BETA:
        return;
    }
}

void TOTrapAncient01::vfunc_84() {  }

f32 TOTrapAncient01::receive_physical_attack(void *arg1, f32 farg0) {
    release_trapped_player();
    return TOTrap::receive_physical_attack(arg1, farg0);
}

void TOTrapAncient01::play_sounds() {
    const TObjChipParams chip0 = {
        {0.5f, 0.03f, 0.15f}, {position.x, position.y, position.z}, {3.0f, 5.0f, 3.0f},
        {0x800, 0x100, 0x800}, {4, 30}, {position.y, 1.0f},
        get_bml_model(TOTrapAncient01__bml_resource, 0), TObjFish__sub_8001EDB0(TOTrapAncient01__bml_resource, 0), 22,
    };
    const TObjChipParams chip1 = {
        {0.5f, 0.03f, 0.15f}, {position.x, position.y, position.z}, {3.0f, 5.0f, 3.0f},
        {0x800, 0x100, 0x800}, {4, 30}, {position.y, 1.0f},
        get_bml_model(TOTrapAncient01__bml_resource, 1), TObjFish__sub_8001EDB0(TOTrapAncient01__bml_resource, 1), 22,
    };
    const TObjChipParams chip2 = {
        {0.5f, 0.03f, 0.15f}, {position.x, position.y, position.z}, {3.0f, 5.0f, 3.0f},
        {0x800, 0x100, 0x800}, {4, 30}, {position.y, 1.0f},
        get_bml_model(TOTrapAncient01__bml_resource, 2), TObjFish__sub_8001EDB0(TOTrapAncient01__bml_resource, 2), 22,
    };
    new TObjChip(tl_06, (TObjChipParams *)&chip0);
    new TObjChip(tl_06, (TObjChipParams *)&chip1);
    new TObjChip(tl_06, (TObjChipParams *)&chip2);
    TParticleCtrl *particle = (TParticleCtrl *)spawn_particle_effect(&position, 0x8B);
    if (particle != NULL) {
        particle->set_scale(1.25f, 1.25f);
    }
    switch (get_current_floor_area()) {
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4004C118, &position, 0, 0);
        break;
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        play_sound_effect(0x4BC07, &position, 0, 0);
        break;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_sound_effect(0x4004BC07, &position, 0, 0);
        break;
    case AREA_SEASIDE_NIGHT:
        play_sound_effect(0x4004BC19, &position, 0, 0);
        break;
    case AREA_TOWER:
        play_sound_effect(0x4004BC19, &position, 0, 0);
        break;
    default:
        play_sound_effect(0x4004BC12, &position, 0, 0);
        break;
    }
}

void TOTrapAncient01::release_trapped_player() {
    TObjPlayer *player;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        if (target != NULL) {
            player = get_player_by_client_id(get_entity_id((TObjBase *)target));
            if (player != NULL) {
                if (((TLobby *)player)->check_player_flag1() != 0) {
                    TObjPlayer::send_code_45_1((s32)player);
                }
                obj_clear_flag30_20000(player);
            }
        }
    } else if (target != NULL && local_client_id == get_entity_id((TObjBase *)target)) {
        player = get_player_by_client_id(local_client_id);
        if (player != NULL) {
            if (((TLobby *)player)->check_player_flag1() != 0) {
                TObjPlayer::send_code_45_1((s32)player);
            }
            obj_clear_flag30_20000(player);
        }
    }
}

void TOTrapAncient01::vfunc_6(s16 *arg1, s32 arg2) {
    if ((s16) *arg1 == 4) {
        if (arg2 == 1) {
            this->play_sounds();
        }
        this->release_trapped_player();
        set_flag8();
        queue_destruction__7TObjectFv(this);
    }
}

void TOTrapAncient01::vfunc_88() {  }

void TOTrapAncient01::vfunc_86() {  }
