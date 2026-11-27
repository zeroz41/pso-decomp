#include "pso/system/BmlResource.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/BmlAccessors.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"

#include "pso/object/container/TContainerAncient01.h"

#include "pso/object/base/TObjChara.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/object/container/TContainerAncient01R.h"

#include "pso/system/BmlResourceDescriptor.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/system/BmlResourceLoad.h"

#include "pso/map/FloorArea.h"

#include "pso/math/MatrixReflect.h"

#include "pso/system/SoundEffect.h"

#include "pso/object/base/TObjCharaHelpers.h"


#include "pso/system/task/TObject.h"

static const f32 ancient01_one[1] = {1.0f};

static const f32 ancient01_zero[1] = {0.0f};

#include "pso/player/TObjPlayer.h"


#include "pso/system/vector.h"


#include "pso/enemy/panarms/TObjEnePanarms.h"

#include "pso/render/TextureState.h"
#include "pso/render/NinjaUtil.h"
#include "pso/render/render_util.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/system/MatrixStack.h"
#include "pso/object/base/TObjCollidable.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/player/PlayerCommands.h"

// Effect ids load_resources picks per area (0x230/0x231 or 0x45/0x46) and the
// pair TContainerAncient01R::init_table_entries copies for its open effect.
s32 container_ancient01_effect_id_table[2];

saddr container_ancient01_open_effect_table[2];



const char *fe_obj_h_s_konte_model_names[3] = { "fe_obj_h_s_konte.gj", "fe_obj_h_s_konte2.gj", NULL };

const char *fe_obj_h_s_konte_motion_names[3] = { "fe_obj_h_s_konte.njm", "fe_obj_h_s_konte2.njm", NULL };

BmlResourceDescriptor container_ancient01_resource_descriptor = {
    "fe_obj_h_s_konte.bml", fe_obj_h_s_konte_model_names, fe_obj_h_s_konte_motion_names, 2, 2,
};

const char *bm_obj_geenest_model_names[3] = { "obj_o_geenest01.gj", "obj_o_geenest02.gj", NULL };

const char *bm_obj_geenest_motion_names[3] = { "obj_o_geenest01.njm", "obj_o_geenest02.njm", NULL };

BmlResourceDescriptor container_ancient01_resource_descriptor_2 = {
    "bm_obj_geenest.bml", bm_obj_geenest_model_names, bm_obj_geenest_motion_names, 2, 2,
};

CollisionBody container_ancient01_collision_body_parts = {
    { 0.0f, 8.0f, 0.0f }, 10.0f, 10.0f, 0, 0x38003, { 0.0f, 0.0f, 0.0f }, 0.0f,
};

TObjMotionAction container_ancient01_anim_table[3] = {
    {1, 0, 0, 1.0f, 1},
    {1, 0, 0, 6.0f, 1},
    {2, 0, 1, 1.0f, 4},
};

// The constructors install these names (TObject::m_name).
const char *container_ancient01_name = "TContainerAncient01";

// The kind-3 preview uses this action table and the current floor archive's motions.
static const NpcAnimationBinding container_ancient_anim_binding = {
    NULL, container_ancient01_anim_table, 0, 0, 3,
};

const char *container_ancient01_r_name = "TContainerAncient01R";

#include "pso/render/GinjaMaterial.h"

#include "pso/system/MatrixStack.h"


#include "pso/npc/TObjNpcEnemy.h"


#include "pso/render/RenderFadeState.h"

#include "pso/ui/hud/TRaderMapCore.h"

#include "pso/object/container/TObjContainerJungEnemy.h"

#include "pso/object/container/TObjContainerIdo.h"

#include "pso/object/container/TObjContainerIdoBase.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/PlayerSlots.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/quest/QuestFloorDesignation.h"

BmlResource *container_ancient01_bml_resource;
BmlResource *container_ancient01_r_bml_resource;

s32 TContainerAncient01::roll_physical_accuracy(TObjChara *, s32, f32) { return 1; }

s32 TContainerAncient01::try_start_action(TObjChara *, s32, f32) { return 1; }

void TContainerAncient01::apply_knockback_from_attacker(TObjBase *, f32) {  }

f32 TContainerAncient01::receive_weapon_special_attack(TObjChara *, CollisionBody *) {
    receive_physical_attack(NULL, ancient01_one[0]);
    return ancient01_zero[0];
}

BmlResource *TContainerAncient01::get_bml_resource() {
    return container_ancient01_bml_resource;
}

int TContainerAncient01::get_table_entry(int a0) {  return container_ancient01_effect_id_table[a0]; }

s32 TContainerAncient01R::roll_physical_accuracy(TObjChara *, s32, f32) { return 1; }

s32 TContainerAncient01R::try_start_action(TObjChara *, s32, f32) { return 1; }

void TContainerAncient01R::apply_knockback_from_attacker(TObjBase *, f32) {  }

f32 TContainerAncient01R::receive_weapon_special_attack(TObjChara *, CollisionBody *) {
    receive_physical_attack(NULL, ancient01_one[0]);
    return ancient01_zero[0];
}

#pragma push
#pragma fp_contract on
TContainerAncient01::TContainerAncient01(TObject *parent, ObjectSetData *set_data) : TObjChara(parent) {
    m_name = container_ancient01_name;
    this->apply_object_set_data(set_data);
    this->model = get_bml_model(container_ancient01_bml_resource, 0);
    this->texlist = get_bml_texlist(container_ancient01_bml_resource, 0);
    this->action_table = container_ancient01_anim_table;
    this->set_action_table(this->action_table);
    this->motion_list = container_ancient01_bml_resource->motions;
    this->requested_action = 0;
    this->set_animation((this->requested_action));
    this->set_requested_action((int) (this->requested_action));
    this->actorFlags = (s32) (this->actorFlags | 0x60000000);
    init_collision_body_parts(this, &container_ancient01_collision_body_parts, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    center.y = (f32) ((container_ancient01_collision_body_parts.offset.y / 2.0f) + center.y);
    VecCopy(&body_center, &center);
    this->mode = 0;
    this->init_state_vectors();
}

#pragma pop
TContainerAncient01::~TContainerAncient01() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TContainerAncient01::load_resources() {
    BmlResource *p;
    container_ancient01_bml_resource = NULL;
    if (TContainerAncient01::is_global_state_in_table() != 0) {
        p = new BmlResource(5, &container_ancient01_resource_descriptor_2, 0, 0, NULL);
        container_ancient01_effect_id_table[0] = 0x230;
        container_ancient01_bml_resource = p;
        container_ancient01_effect_id_table[1] = 0x231;
    } else {
        p = new BmlResource(5, &container_ancient01_resource_descriptor, 0, 0, NULL);
        container_ancient01_effect_id_table[0] = 0x45;
        container_ancient01_bml_resource = p;
        container_ancient01_effect_id_table[1] = 0x46;
    }
    NpcAnimationBinding prm = container_ancient_anim_binding;
    prm.motions = container_ancient01_bml_resource->motions;
    TObjNpcEnemy::register_animated_ginja(0x3B, get_bml_model(container_ancient01_bml_resource, 0),
                                             get_bml_texlist(container_ancient01_bml_resource, 0), &prm,
                                             10.0f, ancient01_zero[0]);
}

void TContainerAncient01::release_static_resource() {
    if (container_ancient01_bml_resource != NULL) {
        delete container_ancient01_bml_resource;
        container_ancient01_bml_resource = NULL;
    }
}

void *TContainerAncient01::create(ObjectSetData *set_data) {
    return new TContainerAncient01(tl_05, set_data);
}

void TContainerAncient01::run_task() {
    f32 frame_timer;
    f32 y;
    if (check_demo_mode() == 0) {
        if ((s32) this->opened == 0) {
            switch (this->mode) {
            case 0:
                this->update_wait_for_player();
                break;
            case 1:
                this->update_spawning();
                break;
            case 2:
                this->update_blast();
                break;
            default:
                this->mode = 0;
                this->requested_action = (s16) this->mode;
                this->frame_timer = (f32) (-1.0f);
                this->update_wait_for_player();
                break;
            }
            frame_timer = this->frame_timer;
            this->frame_timer = (f32) (frame_timer + ancient01_one[0]);
            submit_cursor_candidate(this, -1);
        } else {
            y = this->open_scale.y;
            if (y <= 0.2f) {
                position.y = (f32) (position.y - 0.025f);
                if (position.y <= ((-1e+01f) * this->open_scale.y)) {
                    this->TObject::queue_destruction();
                }
            } else {
                this->open_scale.y = (f32) (y - 0.025f);
            }
        }
    }
    if (static_cast<const void *>(current_motion) == get_bml_motion(container_ancient01_bml_resource, 0)) {
        this->model = get_bml_model(container_ancient01_bml_resource, 0);
    }
    if (static_cast<const void *>(current_motion) == get_bml_motion(container_ancient01_bml_resource, 1)) {
        this->model = get_bml_model(container_ancient01_bml_resource, 1);
    }
    this->TObject::run_task();
}

void TContainerAncient01::render() {
    if (this->update_object_view_visibility(3e+02f, 2e+01f) != 0) {
        set_texture_list(this->texlist);
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(0, this->rotation.y);
        if ((s32) this->opened != 0) {
            scale_current_matrix(&this->open_scale.x);
        }
        if (check_demo_mode() == 1) {
            draw_ginja_object(this->model);
        } else {
            draw_ginja_model_with_motion((this->model), (this->current_motion), this->frame);
        }
        pop_matrix();
    }
}

s32 TContainerAncient01::select_melee_contact_body(TObjChara *target, f32) {
    return xyz_distance_squared(&target->position, &position) < 4e+02f;
}

int TContainerAncient01::calc_distance_accuracy_penalty(TObjChara *, CollisionBody *, const Vec *, float) { return 1; }

f32 TContainerAncient01::receive_direct_attack(TObjBase *, DirectAttackPayload payload, CollisionBody *, s32, s32) {
    s32 kind;

    kind = payload.kind;
    if ((kind == 0) || ((kind - 1) <= 3U) || (kind == 0x13)) {
        receive_physical_attack(NULL, ancient01_one[0]);
    }
    return ancient01_zero[0];
}

f32 TContainerAncient01::receive_physical_attack(TObjChara *, f32) {
    QuestObjectEntry saved_state;

    if ((u16) this->entity_id >= 0x1000U) {
        reset_state();
        if (((uaddr) this->set_entry != 0U) && (access_object_saved_state(&saved_state, 1) != 0)) {
            saved_state.flags = 1;
            access_object_saved_state(&saved_state, 0);
            send_object_state_update(&saved_state);
        }
    }
    return ancient01_zero[0];
}

void TContainerAncient01::open_container() {
    if ((s32)opened == 0) {
        opened = 1;
        clear_player_status_flag(0, 1);
        spawn_effect(&this->position, container_ancient01_effect_id_table[0]);
        spawn_effect(&this->position, container_ancient01_effect_id_table[1]);
        if (TContainerAncient01::is_global_state_in_table() == 0) {
            request_box_item_drop(&position, 1);
        }
        set_flag8();
    }
}

void TContainerAncient01::apply_saved_state(QuestObjectEntry *state, s32 live) {
    if (live != 0) {
        if (state->flags == 1) {
            open_container();
            this->opened = 1;
        }
    } else if (state->flags == 1) {
        this->opened = 1;
    }
}
#pragma push
#pragma fp_contract on
void TContainerAncient01::init_state_vectors() {
    this->wait_limit = (f32) (3e+02f + (this->scale.x - ancient01_one[0]));
    this->active_limit = (f32) (2.1e+02f + (this->scale.y - ancient01_one[0]));
    this->range = (f32) (4e+02f + (this->scale.z - ancient01_one[0]));
    this->spawns_per_second = this->set_params[2] + 4;
    VecCopy(&this->lower_effect_position, &this->position);
    this->lower_effect_position.y = (f32) (this->lower_effect_position.y + container_ancient01_collision_body_parts.offset.y);
    VecCopy(&this->upper_effect_position, &this->lower_effect_position);
    this->upper_effect_position.y = (f32) ((1.25f * container_ancient01_collision_body_parts.offset.y) + this->upper_effect_position.y);
    this->opened = 0;
    this->open_scale.x = (f32) ancient01_one[0];
    this->open_scale.y = (f32) ancient01_one[0];
    this->open_scale.z = (f32) ancient01_one[0];
}

void TContainerAncient01::update_wait_for_player() {
    s32 flag;
    u16 i;
    u8 *p;
    f32 c;
    advance_animation();
    flag = 0;
    if (wait_limit <= this->frame_timer) {
        flag = 1;
    } else {
        c = 6.4e+03f;
        for (i = 0; i < 4; i++) {
            p = (u8 *)get_player_by_client_id(i);
            if (p != 0 && horizontal_distance_squared(&position, &((TObjPlayer *)p)->position) < c) {
                flag = 1;
            }
        }
    }
    if (flag != 0) {
        this->mode = 1;
        requested_action = this->mode;
        this->frame_timer = (-1.0f);
    }
}
#pragma pop
void TContainerAncient01::update_spawning() {
  advance_animation();
  if (((u32)this->frame_timer % 15) == 0)
  {
    spawn_effect(&this->lower_effect_position, 0x7D);
  }
  if (6e+01f <= (this->frame_timer))
  {
    this->mode = 2;
    this->requested_action = this->mode;
    this->frame_timer = (f32) (-1.0f);
  }
}

void TContainerAncient01::update_blast() {
    u32 period;
    u32 phase;
    f32 t;
    this->advance_animation();
    if (1e+01f == this->frame_timer) {
        switch (get_current_floor_area()) {
        case AREA_CENTRAL_CONTROL_AREA:
        case AREA_JUNGLE_NORTH:
        case AREA_JUNGLE_EAST:
        case AREA_MOUNTAIN:
        case AREA_SEASIDE:
            play_sound_effect(0x4BC1C, &this->position, 0, 0);
            break;
        case AREA_SEASIDE_NIGHT:
            play_sound_effect(0x4004BC1C, &this->position, 0, 0);
            break;
        case AREA_TOWER:
            play_sound_effect(0x4004BC1C, &this->position, 0, 0);
            break;
        default:
            play_sound_effect(0x4004BC16, &this->position, 0, 0);
            break;
        }
    }
    if (1e+01f == this->frame_timer || 12.0f == this->frame_timer || 14.0f == this->frame_timer) {
        spawn_effect(&this->upper_effect_position, 0x7D);
    }
    if (4e+01f == this->frame_timer) {
        spawn_effect(&this->lower_effect_position, 0x7E);
    }
    period = (u32)(3e+01f / (f32)this->spawns_per_second);
    phase = (u32)(t = this->frame_timer) % period;
    if (14.0f < t && t < 6e+01f && phase == 0) {
        spawn_effect(&this->upper_effect_position, 0x7E);
    }
    if (6e+01f < this->frame_timer && phase == 0) {
        spawn_effect(&this->lower_effect_position, 0x7E);
    }
    attack_nearby_players(this->range);
    if (this->active_limit <= this->frame_timer) {
        this->reset_state();
    }
}

void TContainerAncient01::reset_state() { this->mode = 0; this->requested_action = this->mode; this->frame_timer = (-1.0f); }

void TContainerAncient01::attack_nearby_players(f32 range) {
    u16 i;
    TObjPlayer *pl;
    for (i = 0; i < 4; i++) {
        pl = get_player_by_client_id(i);
        if (pl != NULL) {
            if (pl->get_floor() == get_current_floor() && pl->test_actor_flags(1) == 0 &&
                horizontal_distance_squared(&position, &pl->position) < range) {
                DirectAttackPayload atk;
                atk.kind = 0xF;
                atk.power = 1e+02f;
                pl->receive_direct_attack(this, atk, NULL, -1, -1);
            }
        }
    }
}

void TContainerAncient01::spawn_effect(const Vec *position, s32 effect_id) {
    spawn_particle_effect(position, effect_id);
}
#pragma push
#pragma fp_contract on
TContainerAncient01R::TContainerAncient01R(TObject *parent, ObjectSetData *set_data) : TObjChara(parent) {
    m_name = container_ancient01_r_name;
    apply_object_set_data(set_data);
    model = get_bml_model(container_ancient01_r_bml_resource, 0);
    texlist = get_bml_texlist(container_ancient01_r_bml_resource, 0);
    action_table = container_ancient01_anim_table;
    set_action_table(action_table);
    motion_list = container_ancient01_r_bml_resource->motions;
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    actorFlags |= 0x60000000;
    init_collision_body_parts(this, &container_ancient01_collision_body_parts, 1);
    register_object_by_id();
    VecCopy(&center, &position);
    center.y = container_ancient01_collision_body_parts.offset.y / 2.0f + center.y;
    VecCopy(&body_center, &center);
    mode = 0;
    init_positions();
}
#pragma pop
TContainerAncient01R::~TContainerAncient01R() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TContainerAncient01R::init_table_entries() {
    container_ancient01_r_bml_resource = TContainerAncient01::get_bml_resource();
    container_ancient01_open_effect_table[0] = TContainerAncient01::get_table_entry(0);
    container_ancient01_open_effect_table[1] = TContainerAncient01::get_table_entry(1);
}

void TContainerAncient01R::free_resources() { container_ancient01_r_bml_resource = NULL; }

void *TContainerAncient01R::create(ObjectSetData *parent) {
    return new TContainerAncient01R(tl_05, parent);
}

void TContainerAncient01R::run_task() {
    f32 frame_timer;
    f32 y;
    if (check_demo_mode() == 0) {
        if ((s32) this->opened == 0) {
            switch (this->mode) {
            case 0:
                this->check_open_trigger();
                break;
            case 1:
                this->update_spawning();
                break;
            case 2:
                this->update_blast();
                break;
            default:
                this->mode = 0;
                this->requested_action = (s16) this->mode;
                this->frame_timer = (f32) (-1.0f);
                this->check_open_trigger();
                break;
            }
            frame_timer = this->frame_timer;
            this->frame_timer = (f32) (frame_timer + ancient01_one[0]);
            submit_cursor_candidate(this, -1);
        } else {
            y = this->open_scale.y;
            if (y <= 0.2f) {
                position.y = (f32) (position.y - 0.025f);
                if (position.y <= ((-1e+01f) * this->open_scale.y)) {
                    this->TObject::queue_destruction();
                }
            } else {
                this->open_scale.y = (f32) (y - 0.025f);
            }
        }
    }
    if (static_cast<const void *>(current_motion) == get_bml_motion(container_ancient01_r_bml_resource, 0)) {
        this->model = get_bml_model(container_ancient01_r_bml_resource, 0);
    }
    if (static_cast<const void *>(current_motion) == get_bml_motion(container_ancient01_r_bml_resource, 1)) {
        this->model = get_bml_model(container_ancient01_r_bml_resource, 1);
    }
    this->TObject::run_task();
}

void TContainerAncient01R::render() {
    if (this->update_object_view_visibility(3e+02f, 2e+01f) != 0) {
        set_texture_list(this->texlist);
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(0, this->rotation.y);
        if ((s32) this->opened != 0) {
            scale_current_matrix(&this->open_scale.x);
        }
        if (check_demo_mode() == 1) {
            draw_ginja_object(this->model);
        } else {
            draw_ginja_model_with_motion((this->model), (this->current_motion), this->frame);
        }
        pop_matrix();
    }
}

s32 TContainerAncient01R::select_melee_contact_body(TObjChara *target, f32) {
    return xyz_distance_squared(&target->position, &position) < 4e+02f;
}

int TContainerAncient01R::calc_distance_accuracy_penalty(TObjChara *, CollisionBody *, const Vec *, float) { return 1; }

f32 TContainerAncient01R::receive_direct_attack(TObjBase *, DirectAttackPayload payload, CollisionBody *, s32, s32) {
    s32 kind;

    kind = payload.kind;
    if ((kind == 0) || ((kind - 1) <= 3U) || (kind == 0x13)) {
        receive_physical_attack(NULL, ancient01_one[0]);
    }
    return ancient01_zero[0];
}

f32 TContainerAncient01R::receive_physical_attack(TObjChara *, f32) {
    QuestObjectEntry saved_state;
    if ((u16) this->entity_id >= 0x1000U) {
        this->hit_count = (this->hit_count + 1);
        if (((uaddr) this->set_entry != 0U) && (access_object_saved_state(&saved_state, 1) != 0)) {
            saved_state.flags = this->hit_count;
            access_object_saved_state(&saved_state, 0);
            send_object_state_update(&saved_state);
        }
    }
    return ancient01_zero[0];
}

void TContainerAncient01R::open_container() {
    if (opened == 0) {
        opened = 1;
        clear_player_status_flag(0, 1);
        trigger_spawn(&this->position, container_ancient01_open_effect_table[0]);
        trigger_spawn(&this->position, container_ancient01_open_effect_table[1]);
        if (TContainerAncient01::is_global_state_in_table() == 0) {
            request_box_item_drop(&position, 1);
        }
        set_flag8();
    }
}

void TContainerAncient01R::apply_saved_state(QuestObjectEntry *state, s32 live) {
    this->hit_count = state->flags;
    if (live != 0) {
        if ((this->hp - this->hit_count) <= 0) {
            this->reset_state();
            this->open_container();
            this->opened = 1;
        }
    } else if ((this->hp - this->hit_count) <= 0) {
        this->opened = 1;
    }
}
#pragma push
#pragma fp_contract on
void TContainerAncient01R::init_positions() {
    this->wait_limit = (f32) (3e+02f + (this->scale.x - ancient01_one[0]));
    this->active_limit = (f32) (2.1e+02f + (this->scale.y - ancient01_one[0]));
    this->range = (f32) (4e+02f + (this->scale.z - ancient01_one[0]));
    this->spawns_per_second = (this->set_params[2] + 4);
    VecCopy(&this->lower_effect_position, &this->position);
    this->lower_effect_position.y = (f32) (this->lower_effect_position.y + container_ancient01_collision_body_parts.offset.y);
    VecCopy(&this->upper_effect_position, &this->lower_effect_position);
    this->upper_effect_position.y = (f32) ((1.25f * container_ancient01_collision_body_parts.offset.y) + this->upper_effect_position.y);
    this->opened = 0;
    this->open_scale.x = (f32) ancient01_one[0];
    this->open_scale.y = (f32) ancient01_one[0];
    this->open_scale.z = (f32) ancient01_one[0];
    this->hp = (s16) this->rotation.z;
    if ((s16) this->hp < 1) {
        this->hp = 1;
    }
    this->hit_count = 0;
}
#pragma pop
void TContainerAncient01R::check_open_trigger() {
    s32 hit;
    u16 i;
    TObjPlayer *pl;
    f32 range;

    advance_animation();
    hit = 0;
    if (this->wait_limit <= this->frame_timer) {
        hit = 1;
    } else {
        range = 6.4e+03f;
        for (i = 0; i < registered_player_count; i++) {
            pl = get_player_by_client_id(i);
            if (pl != NULL && horizontal_distance_squared(&position, &pl->position) < range) {
                hit = 1;
            }
        }
    }
    if (hit != 0) {
        this->mode = 1;
        this->requested_action = this->mode;
        this->frame_timer = (-1.0f);
    }
}

void TContainerAncient01R::update_spawning() {
  advance_animation();
  if (((u32)this->frame_timer % 15) == 0)
  {
    trigger_spawn(&this->lower_effect_position, 0x7D);
  }
  if (6e+01f <= (this->frame_timer))
  {
    this->mode = 2;
    this->requested_action = this->mode;
    this->frame_timer = (f32) (-1.0f);
  }
}

void TContainerAncient01R::update_blast() {
    u32 period;
    f32 t;
    u32 rem;

    this->advance_animation();
    if (1e+01f == this->frame_timer) {
        switch (get_current_floor_area()) {
        case AREA_CENTRAL_CONTROL_AREA:
        case AREA_JUNGLE_NORTH:
        case AREA_JUNGLE_EAST:
        case AREA_MOUNTAIN:
        case AREA_SEASIDE:
            play_sound_effect(0x4BC1C, &this->position, 0, 0);
            break;
        case AREA_SEASIDE_NIGHT:
            play_sound_effect(0x4004BC1C, &this->position, 0, 0);
            break;
        case AREA_TOWER:
            play_sound_effect(0x4004BC1C, &this->position, 0, 0);
            break;
        default:
            play_sound_effect(0x4004BC16, &this->position, 0, 0);
            break;
        }
    }
    if (1e+01f == this->frame_timer || 12.0f == this->frame_timer || 14.0f == this->frame_timer) {
        trigger_spawn(&this->upper_effect_position, 0x7D);
    }
    if (4e+01f == this->frame_timer) {
        trigger_spawn(&this->lower_effect_position, 0x7E);
    }
    period = (u32)(3e+01f / (f32)this->spawns_per_second);
    rem = (u32)(t = this->frame_timer) % period;
    if (14.0f < t && t < 6e+01f && rem == 0) {
        trigger_spawn(&this->upper_effect_position, 0x7E);
    }
    if (6e+01f < this->frame_timer && rem == 0) {
        trigger_spawn(&this->lower_effect_position, 0x7E);
    }
    attack_nearby_players(this->range);
    if (this->active_limit <= this->frame_timer) {
        this->reset_state();
    }
}

void TContainerAncient01R::reset_state() { this->mode = 0; this->requested_action = this->mode; this->frame_timer = (-1.0f); }

void TContainerAncient01R::attack_nearby_players(f32 range) {
    u16 i;
    TObjPlayer *pl;
    for (i = 0; i < 4; i++) {
        pl = get_player_by_client_id(i);
        if (pl != NULL) {
            if (pl->get_floor() == get_current_floor() && pl->test_actor_flags(1) == 0 &&
                horizontal_distance_squared(&position, &pl->position) < range) {
                DirectAttackPayload atk;
                atk.kind = 0xF;
                atk.power = 1e+02f;
                pl->receive_direct_attack(this, atk, NULL, -1, -1);
            }
        }
    }
}
