#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/trap/TOTrap.h"
#include "pso/object/trap/TOTrapAncient02.h"
#include "pso/object/trap/TOTrapAncient02R.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/object/switch/TSwitch.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_80083594.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/technique/TTecZonde.h"
#include "pso/technique/TTecFoie.h"
#include "pso/technique/TTecGiBarta.h"
#include "pso/technique/TTecGiFoie.h"
#include "pso/technique/TTecMegid.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/frontend/TAdEnterPasswordGC.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_800FD8A0.h"
#include "pso/map/FloorArea.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/ScratchVectors.h"
#include "pso/network/client_id.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaUvScroll.h"
#include "pso/render/NinjaUtil.h"
#include "pso/render/render_util.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"

extern s32 game_difficulty_selection;

const char *bm_fs_obj_o_torabasami_model_names[] = {"fs_obj_o_torabasami.gj", NULL};
const char *bm_fs_obj_o_torabasami_motion_names[] = {NULL};
BmlResourceDescriptor bm_fs_obj_o_torabasami_resource_descriptor = {
    "bm_fs_obj_o_torabasami.bml", bm_fs_obj_o_torabasami_model_names, bm_fs_obj_o_torabasami_motion_names, 1, 0,
};
const char *bm_obj_ruins_pillar_model_names[] = {"fe_obj_o_torabasami02.gj", NULL};
const char *bm_obj_ruins_pillar_motion_names[] = {NULL};
BmlResourceDescriptor bm_obj_ruins_pillar_resource_descriptor = {
    "bm_obj_ruins_pillar.bml", bm_obj_ruins_pillar_model_names, bm_obj_ruins_pillar_motion_names, 1, 0,
};
const char *bm_obj_seabed_pillar_model_names[] = {"obj_o_tarabasami03.gj", NULL};
const char *bm_obj_seabed_pillar_motion_names[] = {NULL};
BmlResourceDescriptor bm_obj_seabed_pillar_resource_descriptor = {
    "bm_obj_seabed_pillar.bml", bm_obj_seabed_pillar_model_names, bm_obj_seabed_pillar_motion_names, 1, 0,
};
CollisionBody trap_ancient02_collision_body = {
    {0.0f, 8.5f, 0.0f}, 2.0f, 0.0f, 0, 0x38003, {0.0f, 0.0f, 0.0f}, 0.0f,
};
const char *TOTrapAncient02__name = "TOTrapAncient02";
const char *TOTrapAncient02R__name = "TOTrapAncient02R";

BmlResource *TOTrapAncient02__shared_resource;
s32 lbl_805D5ADC;   // the actor_frame_tick the uv scroll last ran on
void *lbl_805D5AE0; // the model vfunc_84 scrolls the uvs of
s32 lbl_805D5AE4;   // the mesh of it that scrolls

void TOTrapAncient02R::init_trap_object_id() {
    switch_id = set_params[1];
    if (switch_id < 0 || switch_id >= 0x100) {
        switch_id = -1;
    }
}

void TOTrapAncient02R::clamp_trap_level_param() {
    technique = set_params[2];
    if (technique < 0) {
        technique = 0;
    } else if (technique >= 5) {
        technique = 4;
    }
}

void TOTrapAncient02R::init_trap_param_clamped() {
    hits = scale.y;
    if (hits < 1) {
        hits = 1;
    } else if (hits > 0x100) {
        hits = 0x100;
    }
}

f32 TOTrapAncient02R::receive_weapon_special_attack(void *, void *) {
    return receive_physical_attack(NULL, 1.0f);
}

f32 TOTrapAncient02R::receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32) {
    return receive_physical_attack(NULL, 1.0f);
}

int TOTrapAncient02R::calc_distance_accuracy_penalty(void *, void *, void *, float) {
    return 1;
}

s32 TOTrapAncient02R::select_melee_contact_body(void *, f32) {
    return 1;
}

s32 TOTrapAncient02R::roll_physical_accuracy(void *, s32, f32) {
    return 1;
}

s32 TOTrapAncient02R::try_start_action(s32, s32) {
    return 1;
}

s32 TOTrapAncient02R::is_any_player_matching_stat() {
    return 0;
}

void TOTrapAncient02R::submit_cursor_and_notify() {
    find_target_player();
}

TOTrapAncient02::TOTrapAncient02(TObject *parent, void *set_data) : TOTrap(parent) {
    m_name = TOTrapAncient02__name;
    apply_object_set_data(set_data);
    ((TObjPlayer *)this)->init_position_vectors();
    calc_attach_pos();
    model = (void *)TOTrapAncient02__shared_resource->models->model;
    texlist = TOTrapAncient02__shared_resource->models->m_c;
    mode = 0;
    phase = 0;
    range = 0.5f * scale.x + 30.0f;
    dist = range;
    reset = 30.0f + (f32)set_params[0];
    if (reset < 0) {
        reset = 0;
    }
    timer = reset;
    player = 0xFFFF;
    init_collision_body_parts(this, &trap_ancient02_collision_body, 1);
    refresh_collision_body_centers();
    actorFlags |= 0x60000000;
    ((TObjPlayer *)this)->register_object_by_id();
    h348 = 0.0f;
    h344 = 0.0f;
    spin_angle = 0;
    if (rotation_z > 0) {
        particle_tev = 1;
    } else {
        particle_tev = 0;
    }
}

TOTrapAncient02::~TOTrapAncient02() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TOTrapAncient02::load_resources() {
    BmlResource *resource;
    switch (get_current_floor_area()) {
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 1, &bm_obj_ruins_pillar_resource_descriptor, 0, 0, 0);
        }
        TOTrapAncient02__shared_resource = resource;
        lbl_805D5AE0 = find_object_node((NJS_OBJECT *)get_bml_model(resource, 0), 2)->model;
        lbl_805D5AE4 = 2;
        lbl_805D5ADC = 0;
        break;
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
    case AREA_SEASIDE_NIGHT:
    case AREA_TOWER:
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 1, &bm_obj_seabed_pillar_resource_descriptor, 0, 0, 0);
        }
        TOTrapAncient02__shared_resource = resource;
        lbl_805D5AE0 = find_object_node((NJS_OBJECT *)get_bml_model(resource, 0), 2)->model;
        lbl_805D5AE4 = 1;
        lbl_805D5ADC = 0;
        break;
    default:
        resource = (BmlResource *)::operator new(0x440);
        if (resource != NULL) {
            resource = load_resource_from_descriptor(resource, 1, &bm_fs_obj_o_torabasami_resource_descriptor, 0, 0, 0);
        }
        TOTrapAncient02__shared_resource = resource;
        lbl_805D5AE0 = ((NJS_OBJECT *)resource->models->model)->child->child->model;
        lbl_805D5AE4 = 1;
        lbl_805D5ADC = 0;
        break;
    }
}

void TOTrapAncient02::destroy_instance() {
    if (TOTrapAncient02__shared_resource != NULL) {
        free_bin_model_request(TOTrapAncient02__shared_resource, 1);
        TOTrapAncient02__shared_resource = NULL;
    }
}

void *TOTrapAncient02::create(void *set_data) {
    return new TOTrapAncient02(tl_05, set_data);
}

void TOTrapAncient02::render() {
    if (TMainTask::get_render_pass() != 1) {
        m_340 = update_object_view_visibility(400.0f, 20.0f);
        if (m_340 == 1 && (particle_tev == 0 || is_split_screen() != 0 || dispatch_input_to_instance__18TAdEnterPasswordGCFi((s32)this) == 0)) {
            set_draw_list_mask(3);
            if (particle_tev != 0) {
                render_particle_chain();
            } else {
                draw_effect_chain();
            }
            restore_draw_list_mask();
        }
    }
}

void TOTrapAncient02::draw_effect_chain() {
    NJS_OBJECT *n;
    push_matrix();
    TObjFish::set_global_param(texlist);
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    n = (NJS_OBJECT *)model;
    translate_matrix(0, n->pos[0], n->pos[1] + h344, n->pos[2]);
    draw_ginja_model((s32)n->model);
    push_matrix();
    n = n->child;
    translate_matrix(0, n->pos[0], n->pos[1] + h348, n->pos[2]);
    draw_ginja_model((s32)n->model);
    TParticleCtrl::begin_effect_render();
    push_matrix();
    n = n->child;
    post_translate_matrix(n->pos);
    draw_ginja_model((s32)n->model);
    pop_matrix();
    push_matrix();
    n = n->sibling;
    post_translate_matrix(n->pos);
    rotate_matrix_y(0, spin_angle);
    draw_ginja_model((s32)n->model);
    pop_matrix();
    TParticleCtrl::end_effect_render();
    pop_matrix();
    pop_matrix();
}

void TOTrapAncient02::render_particle_chain() {
    NJS_OBJECT *n;
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    n = (NJS_OBJECT *)model;
    translate_matrix(0, n->pos[0], n->pos[1] + h344, n->pos[2]);
    setup_particle_tev(0);
    TObjFish::set_global_param(texlist);
    load_projection_tex_matrix(0x38E);
    draw_ginja_model((s32)n->model);
    reset_particle_tev();
    push_matrix();
    n = n->child;
    translate_matrix(0, n->pos[0], n->pos[1] + h348, n->pos[2]);
    setup_particle_tev(0);
    TObjFish::set_global_param(texlist);
    load_projection_tex_matrix(0x38E);
    draw_ginja_model((s32)n->model);
    reset_particle_tev();
    TParticleCtrl::begin_effect_render();
    push_matrix();
    n = n->child;
    post_translate_matrix(n->pos);
    setup_particle_tev(1);
    TObjFish::set_global_param(texlist);
    load_projection_tex_matrix(0x38E);
    draw_ginja_model((s32)n->model);
    reset_particle_tev();
    pop_matrix();
    push_matrix();
    n = n->sibling;
    post_translate_matrix(n->pos);
    rotate_matrix_y(0, spin_angle);
    setup_particle_tev(0);
    TObjFish::set_global_param(texlist);
    load_projection_tex_matrix(0x38E);
    draw_ginja_model((s32)n->model);
    reset_particle_tev();
    pop_matrix();
    TParticleCtrl::end_effect_render();
    pop_matrix();
    pop_matrix();
}

void TOTrapAncient02::vfunc_81() {
    TObjPlayer *p;
    f32 d;
    submit_cursor_candidate(this, -1);
    switch (phase) {
    case 0:
        if (h344 < 7.0f) {
            h344 += 1.0f;
        } else {
            phase = 1;
            h344 = 7.0f;
        }
        break;
    case 1:
        h348 += 1.0f;
        if (10.15f <= h348) {
            phase = 2;
            h348 = 10.15f;
        }
        break;
    case 2:
        player = find_nearest_visible_player((TObjEnemy *)this, NULL, range);
        if (player != 0xFFFF) {
            p = get_player_by_client_id(player);
            target = (u8 *)p;
            if (target != NULL) {
                d = horizontal_distance_squared(&((TObjBase *)target)->position, &position);
                dist = range - TObjPlayer__sub_8017A1A4(p, 0);
                if (d < dist * dist) {
                    if (player == local_client_id) {
                        send_6x2C_impose_hold(p, &position, timer, 0, dist);
                    }
                    mode = 3;
                    phase = 2;
                } else {
                    player = 0xFFFF;
                    target = NULL;
                }
            }
        } else {
            target = NULL;
        }
        if (target == NULL) {
            phase = 3;
        }
        break;
    case 3:
        if (0.0f < h348) {
            h348 -= 1.0f;
        } else {
            phase = 4;
            h348 = 0.0f;
        }
        break;
    case 4:
        if (0.0f < h344) {
            h344 -= 1.0f;
        } else {
            mode = 0;
            phase = 0;
            h344 = 0.0f;
            player = 0xFFFF;
            target = NULL;
        }
        break;
    }
}

void TOTrapAncient02::vfunc_82() {
    TObjPlayer *p;
    submit_cursor_candidate(this, -1);
    switch (phase) {
    case 0:
    case 1:
        phase = 2;
    case 2:
        if (target != NULL) {
            obj_setFlags30(target, 0x200);
            ((TObjEnemy *)target)->sub_8002AE64();
            ((TObjEnemy *)target)->sub_800A7798(1.0f);
            timer--;
            if (timer < 0) {
                phase = 3;
                timer = reset;
                if (target != NULL && local_client_id == get_entity_id((TObjBase *)target)) {
                    p = get_player_by_client_id(local_client_id);
                    if (p != NULL && ((TLobby *)p)->check_player_flag1() != 0) {
                        TObjPlayer::send_code_45_1((s32)p);
                    }
                }
            }
        } else {
            phase = 3;
            timer = reset;
        }
        break;
    case 3:
        if (0.0f < h348) {
            h348 -= 1.0f;
        } else {
            phase = 4;
            h348 = 0.0f;
        }
        break;
    case 4:
        if (0.0f < h344) {
            h344 -= 1.0f;
        } else {
            mode = 0;
            phase = 0;
            h344 = 0.0f;
            player = 0xFFFF;
            target = NULL;
        }
        break;
    }
}

void TOTrapAncient02::vfunc_84() {
    if (lbl_805D5ADC != actor_frame_tick && lbl_805D5AE0 != NULL) {
        lbl_805D5ADC = actor_frame_tick;
        scroll_ginja_mesh_uvs(lbl_805D5AE0, 0, 0xE, lbl_805D5AE4, 1);
    }
    spin_angle += 0x888;
    switch (mode) {
    case 1:
    case 2:
    case 3:
        switch (get_current_floor_area()) {
        case AREA_CAVE1:
        case AREA_CAVE2:
        case AREA_CAVE3:
            play_persistent_sound(0x4461B, (s32)this, (u32)&position, 0, 0);
            return;
        case AREA_MINE1:
        case AREA_MINE2:
            play_persistent_sound(0x4004C612, (s32)this, (u32)&position, 0, 0);
            return;
        case AREA_RUINS1:
        case AREA_RUINS2:
        case AREA_RUINS3:
            play_persistent_sound(0x4004C618, (s32)this, (u32)&position, 0, 0);
            return;
        case AREA_VR_SPACESHIP_ALPHA:
        case AREA_VR_SPACESHIP_BETA:
            play_persistent_sound(0x4004C610, (s32)this, (u32)&position, 0, 0);
        case AREA_PIONEER2_EP1:
            return;
        case AREA_FOREST1:
            return;
        case AREA_FOREST2:
            return;
        case AREA_DRAGON:
            return;
        case AREA_DE_ROL_LE:
            return;
        case AREA_VOL_OPT:
            return;
        case AREA_DARK_FALZ:
            return;
        case AREA_LOBBY:
            return;
        case AREA_BATTLE1:
            return;
        case AREA_BATTLE2:
            return;
        case AREA_PIONEER2_EP2:
            return;
        case AREA_VR_TEMPLE_ALPHA:
            return;
        case AREA_VR_TEMPLE_BETA:
            return;
        }
        break;
    }
}

void TOTrapAncient02::vfunc_88() {}

void TOTrapAncient02::vfunc_86() {}

TOTrapAncient02R::TOTrapAncient02R(TObject *parent, void *set_data) : TOTrapAncient02(parent, set_data) {
    m_name = TOTrapAncient02R__name;
    apply_object_set_data(set_data);
    ((TObjPlayer *)this)->init_position_vectors();
    calc_attach_pos();
    model = (void *)TOTrapAncient02__shared_resource->models->model;
    texlist = TOTrapAncient02__shared_resource->models->m_c;
    mode = 0;
    phase = 0;
    range = 0.5f * scale.x + 30.0f;
    dist = range;
    reset = 30.0f + (f32)set_params[0];
    if (reset < 0) {
        reset = 0;
    }
    timer = reset;
    init_trap_object_id();
    clamp_trap_level_param();
    calc_trap_count();
    init_trap_param_clamped();
    player = 0xFFFF;
    target = NULL;
    h348 = 0.0f;
    h344 = 0.0f;
    spin_angle = 0;
    if (rotation_z > 0) {
        particle_tev = 1;
    } else {
        particle_tev = 0;
    }
}

TOTrapAncient02R::~TOTrapAncient02R() {}

void *TOTrapAncient02R::create(void *set_data) {
    return new TOTrapAncient02R(tl_05, set_data);
}

f32 TOTrapAncient02R::receive_physical_attack(void *, f32) {
    s16 state;
    if (entity_id >= 0x4000 && set_entry != NULL) {
        Vec v = position;
        v.y += h344 + h348;
        spawn_particle_effect(&v, 0x1D0);
        spawn_particle_effect(&v, 1);
        if (--hits <= 0) {
            hits = 0;
            if (access_object_saved_state(&state, 1) != 0) {
                mode = 4;
                state = mode;
                send_object_state_update(&state);
                access_object_saved_state(&state, 0);
                vfunc_6(&state, 1);
            }
        }
    }
    return 0.0f;
}

void TOTrapAncient02R::find_target_player() {
    clear_player_status_flag(0, 1);
    calc_attach_pos();
    if (switch_id == -1 || is_current_floor_switch_set((u16)switch_id) == 1) {
        player = find_nearest_visible_player((TObjEnemy *)this, NULL, range);
        if (player != 0xFFFF) {
            target = (u8 *)get_player_by_client_id(player);
            if (target != NULL) {
                if (horizontal_distance_squared(&((TObjBase *)target)->position, &position) < range * range) {
                    mode = 2;
                }
            } else {
                player = 0xFFFF;
                target = NULL;
            }
        } else {
            target = NULL;
        }
    }
}

void TOTrapAncient02R::vfunc_81() {
    f32 d;
    s32 ang;
    set_indexed_flags(0, 1);
    submit_cursor_candidate(this, -1);
    switch (phase) {
    case 0:
        if (h344 < 7.0f) {
            h344 += 1.0f;
        } else {
            phase = 1;
            h344 = 7.0f;
        }
        break;
    case 1:
        h348 += 1.0f;
        if (10.15f <= h348) {
            phase = 2;
            h348 = 10.15f;
        }
        break;
    case 2:
        player = find_nearest_visible_player((TObjEnemy *)this, NULL, range);
        if (player != 0xFFFF) {
            TObjPlayer *p = get_player_by_client_id(player);
            target = (u8 *)p;
            if (target != NULL && p->get_floor() == get_current_floor() &&
                (((TObjBase *)target)->alt_room == alt_room || ((TObjBase *)target)->room == room ||
                 ((TObjBase *)target)->room == alt_room)) {
                d = horizontal_distance_squared(&((TObjBase *)target)->position, &position);
                dist = range + get_collision_body_radius((TObjCollidable *)target, 0);
                if (d < dist * dist) {
                    mode = 3;
                    phase = 2;
                    VecCopy(&scratch_vec, &position);
                    scratch_vec.y += h344 + h348;
                    VecCopy(&lbl_8050BF00, (Vec *)&((TObjChara *)target)->m_2fc);
                    subtract_vector(&lbl_8050BF00, &scratch_vec);
                    if (((TObjBoss2Tunnel *)&lbl_8050BF00)->update_scale() < 1e-5f) {
                        lbl_8050BF00.x = lbl_8050BF00.y = 0.0f;
                        lbl_8050BF00.z = 1.0f;
                        push_matrix_from(identity_matrix);
                        rotate_matrix_y(0, rotation_y);
                        rotate_vector_by_matrix(0, &lbl_8050BF00, &lbl_8050BF00);
                        pop_matrix();
                    }
                    ang = 10430.38043493439 * atan2_float(lbl_8050BF00.x, lbl_8050BF00.z);
                    switch (technique) {
                    case 1: {
                        DirectAttackPayload payload;
                        payload.kind = 3;
                        payload.power = scale_by_table_value(20.0f * (f32)tech_level + 240.0f);
                        ((TObjChara *)target)->receive_direct_attack(this, payload, NULL, -1, -1);
                        spawn_particle_effect(&scratch_vec, 0xB9);
                        spawn_particle_effect(&scratch_vec, 0xBA);
                        {
                            void *t = TObject::operator new(0x260);
                            if (t != NULL) {
                                ((TTecZonde *)t)->construct_bolt_effect((u8 *)tl_07, (u8 *)&scratch_vec, (u8 *)&lbl_8050BF00, 0x14000000, 0x14, range, 1.8f);
                            }
                        }
                        play_sound_effect(0x4002A408, &scratch_vec, 0, 0);
                        break;
                    }
                    case 0:
                        TTecFoie::create_ex(this, &scratch_vec, (Vec *)&((TObjChara *)target)->m_2fc, (void *)tech_level);
                        break;
                    case 2:
                        ((TTecGiBarta *)this)->create_ex(&scratch_vec, (void *)ang, (void *)tech_level);
                        break;
                    case 3:
                        TTecMegid::create((s32)this, (s32)&scratch_vec, (s32)(Vec *)&((TObjChara *)target)->m_2fc, tech_level);
                        break;
                    case 4:
                        TTecGiFoie::create(this, &scratch_vec, (void *)tech_level);
                        break;
                    }
                } else {
                    player = 0xFFFF;
                    target = NULL;
                }
            } else {
                player = 0xFFFF;
                target = NULL;
            }
        } else {
            target = NULL;
        }
        if (target == NULL) {
            phase = 3;
        }
        break;
    case 3:
        if (0.0f < h348) {
            h348 -= 1.0f;
        } else {
            phase = 4;
            h348 = 0.0f;
        }
        break;
    case 4:
        if (0.0f < h344) {
            h344 -= 1.0f;
        } else {
            mode = 0;
            phase = 0;
            h344 = 0.0f;
            player = 0xFFFF;
            target = NULL;
        }
        break;
    }
}

void TOTrapAncient02R::vfunc_82() {
    set_indexed_flags(0, 1);
    submit_cursor_candidate(this, -1);
    switch (phase) {
    case 0:
    case 1:
        phase = 2;
    case 2:
        timer = timer - 1;
        if (timer < 0) {
            phase = 3;
            timer = reset;
        }
        break;
    case 3:
        if (0.0f < h348) {
            h348 -= 1.0f;
            return;
        }
        phase = 4;
        h348 = 0.0f;
        return;
    case 4:
        if (0.0f < h344) {
            h344 -= 1.0f;
            return;
        }
        mode = 0;
        phase = 0;
        h344 = 0.0f;
        player = 0xFFFF;
        target = NULL;
        break;
    }
}

void TOTrapAncient02R::calc_trap_count() {
    tech_level = scale.z + (2.0f * (f32)game_difficulty_selection + 1.0f);
    if (tech_level < 0) {
        tech_level = 0;
    } else if (game_difficulty_selection == 3) {
        if (tech_level > 0x1D) {
            tech_level = 0x1D;
        }
    } else if (tech_level > 0xE) {
        tech_level = 0xE;
    }
}

void TOTrapAncient02R::vfunc_88() {}

void TOTrapAncient02R::vfunc_86() {
    if (is_current_room(this) == 1) {
        fn_80141CF0(&home_position, &scratch_vec, &trap_ancient_light_color);
        TOTrapAncient02R__sub_80154D78(this);
    }
}
