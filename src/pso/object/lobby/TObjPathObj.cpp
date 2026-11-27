#include "pso/system/NinjaTypes.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/system/memory.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/animation/MotionContext.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/object/lobby/LobbyPigeonPath.h"

#include "types.h"
#include "pso/render/ChunkModelDraw.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/vector.h"
#include "pso/network/TLobby.h"
#include "pso/unk/TLobbyEventTheme.h"
#include "pso/render/TextureState.h"
#include "pso/object/TObjPathObj.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/TObjSeabedDolphin.h"
#include "pso/object/TObjJungleEbi.h"
#include "pso/object/TObjJungleBird.h"
#include "pso/object/TObjJungleKamome.h"
#include "pso/object/TObjLobbyPigeon.h"
#include "pso/math/MatrixReflect.h"
#include "pso/render/DebugFont.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include <stdlib.h>
#include "pso/render/GinjaTexture.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/BmlResourceDescriptor.h"


// Resource descriptors of the path-following objects: seabed dolphin, jungle ebi, jungle bird,
// jungle kamome and lobby pigeon.
const char *bm_obj_seabed_dolphin_model_names[2] = { "d_dolf.nj", NULL };
const char *bm_obj_seabed_dolphin_motion_names[7] = { "d_20mcircle.njm", "d_30mcircle.njm", "d_30mx_01.njm", "d_30mx_02.njm", "d_30mx_03.njm", "d_dolf.njm", NULL };
BmlResourceDescriptor bm_obj_seabed_dolphin_resource_descriptor = { "bm_obj_seabed_dolphin.bml", bm_obj_seabed_dolphin_model_names, bm_obj_seabed_dolphin_motion_names, 1, 6 };
const char *bm_obj_jungle_ebi_model_names[2] = { "fe_obj_h_ebi.nj", NULL };
const char *bm_obj_jungle_ebi_motion_names[5] = { "fe_obj_h_ebi.njm", "path01_h_ebi.njm", "path02_h_ebi.njm", "path03_h_ebi.njm", NULL };
BmlResourceDescriptor bm_obj_jungle_ebi_resource_descriptor = { "bm_obj_jungle_ebi.bml", bm_obj_jungle_ebi_model_names, bm_obj_jungle_ebi_motion_names, 1, 4 };
const char *bm_obj_jungle_bird_model_names[2] = { "fe_obj_h_tori.nj", NULL };
const char *bm_obj_jungle_bird_motion_names[5] = { "fe_obj_h_tori.njm", "path01_h_tori.njm", "path02_h_tori.njm", "path03_h_tori.njm", NULL };
BmlResourceDescriptor bm_obj_jungle_bird_resource_descriptor = { "bm_obj_jungle_bird.bml", bm_obj_jungle_bird_model_names, bm_obj_jungle_bird_motion_names, 1, 4 };
const char *bm_obj_jungle_kamome_model_names[2] = { "fe_obj_h_kamome.nj", NULL };
const char *bm_obj_jungle_kamome_motion_names[5] = { "fe_obj_h_kamome.njm", "path01_h2_tori.njm", "path02_h2_tori.njm", "path03_h2_tori.njm", NULL };
BmlResourceDescriptor bm_obj_jungle_kamome_resource_descriptor = { "bm_obj_jungle_kamome.bml", bm_obj_jungle_kamome_model_names, bm_obj_jungle_kamome_motion_names, 1, 4 };
const char *bm_obj_lobby_pigeon_model_names[3] = { "lobby_obj_hato.nj", "lobby_obj_karasu.nj", NULL };
const char *bm_obj_lobby_pigeon_motion_names[5] = { "lobby_obj_hato.njm", "path01_h_pigeon.njm", "path02_h_pigeon.njm", "path03_h_pigeon.njm", NULL };
BmlResourceDescriptor bm_obj_lobby_pigeon_resource_descriptor = { "bm_obj_lobby_pigeon.bml", bm_obj_lobby_pigeon_model_names, bm_obj_lobby_pigeon_motion_names, 2, 4 };

BmlResource *seabed_dolphin_bml_archive;
NJS_TEXLIST *seabed_dolphin_texture_handle;
BmlResource *jungle_ebi_model_resource;
NJS_TEXLIST *jungle_ebi_texture_gvm_handle;
BmlResource *jungle_bird_bml_resource;
NJS_TEXLIST *lobby_pigeon_texture_gvm;
BmlResource *lobby_kamome_model_resource;
NJS_TEXLIST *lobby_kamome_texture_gvm_handle;
BmlResource *lobby_pigeon_bml_archive;
NJS_TEXLIST *lobby_pigeon_lobby_type;

// TObjPathObj's class name.
const char *path_obj_name = "TObjPathObj";

// Path profiles: {path motion, path speed, motion speed, look-ahead frames, turn step};
// a turn step of 182 is one degree in 0x10000 units.
extern const PathProfile seabed_dolphin_path_profiles[5] = {
    {0, 0.2f, 0.6f, 0.1f, 182},
    {1, 0.2f, 0.6f, 0.1f, 182},
    {2, 0.2f, 0.6f, 0.1f, 182},
    {3, 0.2f, 0.6f, 0.1f, 182},
    {4, 0.2f, 0.6f, 0.1f, 182},
};
// The dolphin's one action (mode 1, motion 5 at 0.6 speed); inferred name: the action table of
// seabed_dolphin_anim_binding, which load_seabed_dolphin hands to TObjNpcEnemy::register_animated_chunk.
TObjMotionAction seabed_dolphin_actions[1] = {
    {1, 0, 5, 0.6f, 0},
};
extern const NpcAnimationBinding seabed_dolphin_anim_binding = { NULL, seabed_dolphin_actions, 0, 0, 1 };
extern const EbiPathProfile jungle_ebi_path_profiles[3] = {
    {1, 0.01f, 0.6f, 0.1f, 182, 5},
    {2, 0.01f, 0.6f, 0.1f, 182, 5},
    {3, 0.01f, 0.6f, 0.1f, 364, 5},
};
extern const PathProfile lobby_pigeon_path_parameters[3] = {
    {1, 0.1f, 0.6f, 0.1f, 364},
    {2, 0.1f, 0.6f, 0.1f, 364},
    {3, 0.1f, 0.6f, 0.1f, 546},
};
extern const PathProfile jungle_seagull_path_profiles[3] = {
    {1, 0.1f, 0.6f, 0.1f, 364},
    {2, 0.1f, 0.6f, 0.1f, 364},
    {3, 0.1f, 0.6f, 0.1f, 546},
};
extern const Vec path_zero_vec = {0.0f, 0.0f, 0.0f};
extern const PathProfile lobby_pigeon_path_profiles[3] = {
    {1, 0.1f, 2.0f, 0.1f, 364},
    {2, 0.1f, 2.0f, 0.1f, 364},
    {3, 0.1f, 2.0f, 0.1f, 546},
};
extern const Vec lobby_pigeon_zero_vec = {0.0f, 0.0f, 0.0f};
extern const f64 path_angle_units_per_radian[1] = {10430.38043493439};


#include "pso/map/CsnGroundQuery.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/render_util.h"


#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/MatrixOps.h"


#pragma push
#pragma readonly_strings on
void TObjPathObj::update() {  }

void TObjPathObj::draw() {  }

TObjPathObj::TObjPathObj(TObject *parent, ObjectSetData *set_data) : TObjBase(parent) {
    m_name = path_obj_name;
    apply_object_set_data(set_data);
    view_distance = 5e+02f;
    view_radius = 1.5e+02f;
}

TObjPathObj::~TObjPathObj() {}

void TObjPathObj::run_task() {
    update();
}

void TObjPathObj::render() {
    if (TMainTask::get_render_pass() != 1 && update_object_view_visibility(view_distance, view_radius) != 0) {
        draw();
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 TObjPathObj::sample_clamped_path_position(NJS_OBJECT *node, NJS_MOTION *motion, Vec *pos, f32 frame) {
    s32 ang[3];
    f32 scl[3];
    f32 quat[4];
    s32 in_range;
    u32 last;

    in_range = 1;
    last = motion->nbFrame - 1;
    if (frame > (f32)last) {
        in_range = 0;
        frame = (f32)last;
    }
    bind_motion_context(motion, frame);
    sample_motion_node_transform(node, &pos->x, ang, scl, quat);
    return in_range;
}
#pragma pop

#pragma push
#pragma fp_contract on

void TObjPathObj::draw_line_strip(NJS_OBJECT *node, NJS_MOTION *motion, f32 step) {
    Vec from;
    Vec to;
    f32 frame;
    s32 more;

    frame = 0.0f;
    do {
        sample_clamped_path_position(node, motion, &from, frame);
        frame += step;
        more = sample_clamped_path_position(node, motion, &to, frame);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation.y);
        debug_draw_line(&from, &to, 0xF0F0F0FF, 0xF0F0F0FF);
        pop_matrix();
    } while (more != 0);
}
#pragma pop

#pragma push
#pragma fp_contract on
TObjSeabedDolphin::TObjSeabedDolphin(TObject *parent, ObjectSetData *set_data) : TObjPathObj(parent, set_data) {
  s32 clamped_profile;
  s32 raw_profile;
  model = get_bml_model(seabed_dolphin_bml_archive, 0);
  motion = get_bml_motion(seabed_dolphin_bml_archive, 5);
  raw_profile = set_params[0];
  if (raw_profile < 0)
  {
    clamped_profile = 0;
  }
  else
  {
    clamped_profile = 4;
    if (raw_profile <= 4)
    {
      clamped_profile = raw_profile;
    }
  }
  profile = clamped_profile;
  path = get_bml_motion(seabed_dolphin_bml_archive, seabed_dolphin_path_profiles[profile].path_motion);
  path_frame = 0.0f;
  motion_frame = 0.0f;
  initialize_path();
}

TObjSeabedDolphin::~TObjSeabedDolphin() {}

void TObjSeabedDolphin::update() {
    const PathProfile *e = seabed_dolphin_path_profiles;
    f32 ox;
    e += this->profile;
    ox = this->path_frame;
    this->path_frame = ox + e->path_speed;
    if (update_path_steering() == 0) {
        this->path_frame = (0.0f);
    }
    this->motion_frame = this->motion_frame + seabed_dolphin_path_profiles[this->profile].motion_speed;
    if (this->motion_frame > (f32)(this->motion->nbFrame - 1)) {
        this->motion_frame = (0.0f);
    }
}

void TObjSeabedDolphin::draw() {
    if ((check_demo_mode() == 1) && (TMainTask::get_render_pass() == 0)) {
        draw_line_strip(this->model, this->path, (1.0f));
    }
    set_texture_list(seabed_dolphin_texture_handle);
    push_matrix();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation.y);
    post_translate_matrix(&this->path_position.x);
    rotate_matrix_y(0, this->path_yaw);
    rotate_matrix_z(0, this->path_roll);
    set_motion_packed_rotation();
    draw_model_motion(this->model, this->motion, this->motion_frame);
    clear_motion_packed_rotation();
    pop_matrix();
}

s32 TObjSeabedDolphin::initialize_path() {
    Vec a;
    Vec b;
    Vec d;
    s32 tmp;
    s32 r;
    this->path_yaw = 0;
    this->path_pitch = 0;
    this->path_roll = 0;
    this->roll_speed = 0;
    sample_clamped_path_position(this->model, this->path, &a, (0.0f));
    VecCopy(&this->path_position, &a);
    r = sample_clamped_path_position(this->model, this->path, &b, seabed_dolphin_path_profiles[this->profile].look_ahead);
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &this->path_pitch, &tmp);
    this->path_yaw = (s32)(path_angle_units_per_radian[0] * atan2_float(b.x - a.x, b.z - a.z));
    return r;
}

s32 TObjSeabedDolphin::update_path_steering() {
    Vec a;
    Vec b;
    Vec d;
    s32 tmp;
    s32 tmp2;
    s32 r;
    s32 old;
    s32 diff;
    sample_clamped_path_position(this->model, this->path, &a, this->path_frame);
    VecCopy(&this->path_position, &a);
    r = sample_clamped_path_position(this->model, this->path, &b, this->path_frame + seabed_dolphin_path_profiles[this->profile].look_ahead);
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &tmp, &tmp2);
    this->path_pitch = approach_angle_limited(this->path_pitch, tmp, seabed_dolphin_path_profiles[this->profile].turn_step);
    old = this->path_yaw;
    tmp = (s32)(path_angle_units_per_radian[0] * atan2_float(b.x - a.x, b.z - a.z));
    this->path_yaw = approach_angle_limited(old, tmp, seabed_dolphin_path_profiles[this->profile].turn_step);
    diff = angle_diff_s16(old, tmp);
    if (diff > 0x30) {
        if (this->roll_speed > 0) {
            this->roll_speed = 0;
        }
        this->roll_speed -= 0x40;
        if (this->roll_speed < -0x200) {
            this->roll_speed = -0x200;
        }
        this->path_roll += this->roll_speed;
        if (this->path_roll < -0x2000) {
            this->path_roll = -0x2000;
        }
    } else if (diff < -0x30) {
        if (this->roll_speed < 0) {
            this->roll_speed = 0;
        }
        this->roll_speed += 0x40;
        if (this->roll_speed > 0x200) {
            this->roll_speed = 0x200;
        }
        this->path_roll += this->roll_speed;
        if (this->path_roll > 0x2000) {
            this->path_roll = 0x2000;
        }
    } else {
        this->roll_speed = 0;
        if (this->path_roll > 0x100) {
            this->path_roll -= 0x100;
        } else if (this->path_roll < -0x100) {
            this->path_roll += 0x100;
        } else {
            this->path_roll = 0;
        }
    }
    return r;
}

void TObjSeabedDolphin::load_static_resource() {
    seabed_dolphin_bml_archive = new BmlResource(5, &bm_obj_seabed_dolphin_resource_descriptor, 0, 0, NULL);
    seabed_dolphin_texture_handle = LoadPvmFileTls("obj_seabed_dolphin.gvm");
    NpcAnimationBinding binding = seabed_dolphin_anim_binding;
    binding.motions = seabed_dolphin_bml_archive->motions;
    TObjNpcEnemy::register_animated_chunk(0x40,
        get_bml_model(seabed_dolphin_bml_archive, 0),
        seabed_dolphin_texture_handle, &binding, 16.0f, 10.0f);
}
#pragma pop

#pragma push
#pragma fp_contract on

void TObjSeabedDolphin::destroy_instance() {
    if (seabed_dolphin_texture_handle != NULL) {
        release_texture_list(seabed_dolphin_texture_handle);
        safe_free(seabed_dolphin_texture_handle);
        seabed_dolphin_texture_handle = NULL;
    }
    if (seabed_dolphin_bml_archive != NULL) {
        delete seabed_dolphin_bml_archive;
        seabed_dolphin_bml_archive = NULL;
    }
}

void *TObjSeabedDolphin::create(ObjectSetData *set_data) {
    return new TObjSeabedDolphin(tl_05, set_data);
}
#pragma pop

#pragma push
#pragma fp_contract on
TObjJungleEbi::TObjJungleEbi(TObject *parent, ObjectSetData *set_data) : TObjPathObj(parent, set_data) {
  s32 clamped_profile;
  s32 raw_profile;
  model = get_bml_model(jungle_ebi_model_resource, 0);
  motion = get_bml_motion(jungle_ebi_model_resource, 0);
  raw_profile = set_params[0];
  if (raw_profile < 0)
  {
    clamped_profile = 0;
  }
  else
  {
    clamped_profile = 2;
    if (raw_profile <= 2)
    {
      clamped_profile = raw_profile;
    }
  }
  profile = clamped_profile;
  path = get_bml_motion(jungle_ebi_model_resource, jungle_ebi_path_profiles[profile].path_motion);
  path_frame = 0.0f;
  motion_frame = 0.0f;
  initialize_path();
}

TObjJungleEbi::~TObjJungleEbi() {}

void TObjJungleEbi::update() {
    const EbiPathProfile *e = jungle_ebi_path_profiles;
    e += this->profile;
    f32 ox = this->path_frame;
    this->path_frame = ox + e->path_speed;
    if (update_path_follow_rotation(e, ox) == 0) {
        this->path_frame = (0.0f);
    }
    this->motion_frame = this->motion_frame + jungle_ebi_path_profiles[this->profile].motion_speed;
    if (this->motion_frame > (f32)(this->motion->nbFrame - 1)) {
        this->motion_frame = (0.0f);
    }
}

void TObjJungleEbi::draw() {
    if ((check_demo_mode() == 1) && (TMainTask::get_render_pass() == 0)) {
        draw_line_strip(this->model, this->path, (1.0f));
    }
    set_texture_list(jungle_ebi_texture_gvm_handle);
    push_matrix();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation.y);
    post_translate_matrix(&this->path_position.x);
    rotate_matrix_y(0, this->path_yaw);
    rotate_matrix_z(0, this->path_roll);
    draw_model_motion(this->model, this->motion, this->motion_frame);
    pop_matrix();
}

s32 TObjJungleEbi::initialize_path() {
    Vec a;
    Vec b;
    Vec d;
    s32 tmp;
    s32 r;
    this->path_yaw = 0;
    this->path_pitch = 0;
    this->path_roll = 0;
    this->roll_speed = 0;
    sample_clamped_path_position(this->model, this->path, &a, (0.0f));
    VecCopy(&this->path_position, &a);
    r = sample_clamped_path_position(this->model, this->path, &b, jungle_ebi_path_profiles[this->profile].look_ahead);
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &this->path_pitch, &tmp);
    this->path_yaw = (s32)(path_angle_units_per_radian[0] * atan2_float(b.x - a.x, b.z - a.z));
    return r;
}

s32 TObjJungleEbi::update_path_follow_rotation(const EbiPathProfile *, f32) {
    s32 r;
    const EbiPathProfile *e;
    s32 old;
    s32 diff;
    Vec a;
    Vec b;
    s32 tmp;
    s32 tmp2;
    e = &jungle_ebi_path_profiles[this->profile];
    if (!(e->flags & 1)) {
        return 1;
    }
    sample_clamped_path_position(this->model, this->path, &a, this->path_frame);
    VecCopy(&this->path_position, &a);
    r = sample_clamped_path_position(this->model, this->path, &b, this->path_frame + e->look_ahead);
    if (this->visibility != 0) {
        Vec p = this->path_position;
        CsnHit *hit;
        vec3_add_to(&p, &this->position);
        p.y += (1e+04f);
        hit = csnVecterUnder(&p, 0x16EF);
        if (hit != NULL) {
            this->position.y = hit->contact->point.y;
        }
    }
    {
    Vec d;
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)(&d), &tmp, &tmp2);
    }
    this->path_pitch = approach_angle_limited(this->path_pitch, tmp, e->turn_step);
    old = this->path_yaw;
    tmp = (s32)(path_angle_units_per_radian[0] * atan2_float(b.x - a.x, b.z - a.z));
    if (!(e->flags & 2)) {
        this->path_yaw = approach_angle_limited(old, tmp, e->turn_step);
    }
    if (!(e->flags & 4)) {
        diff = angle_diff_s16(old, tmp);
        if (diff > 0x30) {
            if (this->roll_speed > 0) {
                this->roll_speed = 0;
            }
            this->roll_speed -= 0x40;
            if (this->roll_speed < -0x200) {
                this->roll_speed = -0x200;
            }
            this->path_roll += this->roll_speed;
            if (this->path_roll < -0x2000) {
                this->path_roll = -0x2000;
            }
        } else if (diff < -0x30) {
            if (this->roll_speed < 0) {
                this->roll_speed = 0;
            }
            this->roll_speed += 0x40;
            if (this->roll_speed > 0x200) {
                this->roll_speed = 0x200;
            }
            this->path_roll += this->roll_speed;
            if (this->path_roll > 0x2000) {
                this->path_roll = 0x2000;
            }
        } else {
            this->roll_speed = 0;
            if (this->path_roll > 0x100) {
                this->path_roll -= 0x100;
            } else if (this->path_roll < -0x100) {
                this->path_roll += 0x100;
            } else {
                this->path_roll = 0;
            }
        }
    }
    return r;
}

void TObjJungleEbi::load_static_resource() {
    jungle_ebi_model_resource = new BmlResource(5, &bm_obj_jungle_ebi_resource_descriptor, 0, 0, NULL);
    jungle_ebi_texture_gvm_handle = LoadPvmFileTls("obj_jungle_ebi.gvm");
}

void TObjJungleEbi::destroy_instance() {
    if (jungle_ebi_texture_gvm_handle != NULL) {
        release_texture_list(jungle_ebi_texture_gvm_handle);
        safe_free(jungle_ebi_texture_gvm_handle);
        jungle_ebi_texture_gvm_handle = NULL;
    }
    if (jungle_ebi_model_resource != NULL) {
        delete jungle_ebi_model_resource;
        jungle_ebi_model_resource = NULL;
    }
}

void *TObjJungleEbi::create(ObjectSetData *set_data) {
    return new TObjJungleEbi(tl_05, set_data);
}

TObjJungleBird::TObjJungleBird(TObject *parent, ObjectSetData *set_data) : TObjPathObj(parent, set_data) {
  s32 clamped_profile;
  s32 raw_profile;
  model = get_bml_model(jungle_bird_bml_resource, 0);
  motion = get_bml_motion(jungle_bird_bml_resource, 0);
  raw_profile = set_params[0];
  if (raw_profile < 0)
  {
    clamped_profile = 0;
  }
  else
  {
    clamped_profile = 2;
    if (raw_profile <= 2)
    {
      clamped_profile = raw_profile;
    }
  }
  profile = clamped_profile;
  path = get_bml_motion(jungle_bird_bml_resource, lobby_pigeon_path_parameters[profile].path_motion);
  path_frame = 0.0f;
  motion_frame = 0.0f;
  initialize_path();
}

TObjJungleBird::~TObjJungleBird() {}

void TObjJungleBird::update() {
    this->path_frame += lobby_pigeon_path_parameters[this->profile].path_speed;
    if (update_path_steering() == 0) {
        this->path_frame = (0.0f);
    }
    this->motion_frame = this->motion_frame + lobby_pigeon_path_parameters[this->profile].motion_speed;
    if (this->motion_frame > (f32)(this->motion->nbFrame - 1)) {
        this->motion_frame = (0.0f);
    }
}

void TObjJungleBird::draw() {
    if ((check_demo_mode() == 1) && (TMainTask::get_render_pass() == 0)) {
        draw_line_strip(this->model, this->path, (1.0f));
    }
    set_texture_list(lobby_pigeon_texture_gvm);
    push_matrix();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation.y);
    post_translate_matrix(&this->path_position.x);
    rotate_matrix_y(0, this->path_yaw);
    rotate_matrix_z(0, this->path_roll);
    draw_model_motion(this->model, this->motion, this->motion_frame);
    pop_matrix();
}

s32 TObjJungleBird::initialize_path() {
    Vec a;
    Vec b;
    Vec d;
    s32 tmp;
    s32 r;
    this->path_yaw = 0;
    this->path_pitch = 0;
    this->path_roll = 0;
    this->roll_speed = 0;
    sample_clamped_path_position(this->model, this->path, &a, (0.0f));
    VecCopy(&this->path_position, &a);
    r = sample_clamped_path_position(this->model, this->path, &b, lobby_pigeon_path_parameters[this->profile].look_ahead);
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &this->path_pitch, &tmp);
    this->path_yaw = (s32)(path_angle_units_per_radian[0] * atan2_float(b.x - a.x, b.z - a.z));
    return r;
}

s32 TObjJungleBird::update_path_steering() {
    Vec a;
    Vec b;
    Vec d;
    s32 tmp;
    s32 tmp2;
    s32 r;
    s32 old;
    s32 diff;
    sample_clamped_path_position(this->model, this->path, &a, this->path_frame);
    VecCopy(&this->path_position, &a);
    r = sample_clamped_path_position(this->model, this->path, &b, this->path_frame + lobby_pigeon_path_parameters[this->profile].look_ahead);
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &tmp, &tmp2);
    this->path_pitch = approach_angle_limited(this->path_pitch, tmp, lobby_pigeon_path_parameters[this->profile].turn_step);
    old = this->path_yaw;
    tmp = (s32)(path_angle_units_per_radian[0] * atan2_float(b.x - a.x, b.z - a.z));
    this->path_yaw = approach_angle_limited(old, tmp, lobby_pigeon_path_parameters[this->profile].turn_step);
    diff = angle_diff_s16(old, tmp);
    if (diff > 0x30) {
        if (this->roll_speed > 0) {
            this->roll_speed = 0;
        }
        this->roll_speed -= 0x40;
        if (this->roll_speed < -0x200) {
            this->roll_speed = -0x200;
        }
        this->path_roll += this->roll_speed;
        if (this->path_roll < -0x2000) {
            this->path_roll = -0x2000;
        }
    } else if (diff < -0x30) {
        if (this->roll_speed < 0) {
            this->roll_speed = 0;
        }
        this->roll_speed += 0x40;
        if (this->roll_speed > 0x200) {
            this->roll_speed = 0x200;
        }
        this->path_roll += this->roll_speed;
        if (this->path_roll > 0x2000) {
            this->path_roll = 0x2000;
        }
    } else {
        this->roll_speed = 0;
        if (this->path_roll > 0x100) {
            this->path_roll -= 0x100;
        } else if (this->path_roll < -0x100) {
            this->path_roll += 0x100;
        } else {
            this->path_roll = 0;
        }
    }
    return r;
}

void TObjJungleBird::load_static_resource() {
    jungle_bird_bml_resource = new BmlResource(5, &bm_obj_jungle_bird_resource_descriptor, 0, 0, NULL);
    lobby_pigeon_texture_gvm = LoadPvmFileTls("obj_jungle_bird.gvm");
}

void TObjJungleBird::destroy_instance() {
    if (lobby_pigeon_texture_gvm != NULL) {
        release_texture_list(lobby_pigeon_texture_gvm);
        safe_free(lobby_pigeon_texture_gvm);
        lobby_pigeon_texture_gvm = NULL;
    }
    if (jungle_bird_bml_resource != NULL) {
        delete jungle_bird_bml_resource;
        jungle_bird_bml_resource = NULL;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on

void *TObjJungleBird::create(ObjectSetData *set_data) {
    return new TObjJungleBird(tl_05, set_data);
}
#pragma pop

#pragma push
#pragma fp_contract on
TObjJungleKamome::TObjJungleKamome(TObject *parent, ObjectSetData *set_data) : TObjPathObj(parent, set_data) {
    s32 raw_profile;
    s32 clamped_profile;

    model = get_bml_model(lobby_kamome_model_resource, 0);
    motion = get_bml_motion(lobby_kamome_model_resource, 0);
    raw_profile = set_params[0];
    clamped_profile = (raw_profile < 0) ? 0 : (raw_profile > 2) ? 2 : raw_profile;
    profile = clamped_profile;
    path = get_bml_motion(lobby_kamome_model_resource, jungle_seagull_path_profiles[profile].path_motion);
    path_frame = 0.0f;
    motion_frame = 0.0f;
    initialize_path();
    view_distance = 1e+03f;
    cry_delay = (s32) (((3e+01f) * ((4.0f) * ((3.0517578e-05f) * (f32) rand()))) + (1.5e+02f));
}

TObjJungleKamome::~TObjJungleKamome() {}

void TObjJungleKamome::update() {
    Mtx34 m;
    s32 cry_delay_left;

    this->path_frame += jungle_seagull_path_profiles[this->profile].path_speed;
    if (update_path_steering() == 0) {
        this->path_frame = (0.0f);
    }
    this->motion_frame += jungle_seagull_path_profiles[this->profile].motion_speed;
    if (this->motion_frame > (f32) (this->motion->nbFrame - 1)) {
        this->motion_frame = (0.0f);
    }
    cry_delay_left = this->cry_delay - 1;
    this->cry_delay = cry_delay_left;
    if (cry_delay_left < 0) {
        Vec v = path_zero_vec;
        set_matrix_identity((u8 *)m);
        translate_matrix_vec3((u8 *)m, (u8 *)&this->position);
        rotate_matrix_y(m, this->rotation.y);
        translate_matrix_vec3((u8 *)m, (u8 *)&this->path_position);
        matrix_mult_vec(m, &v, &v);
        play_sound_effect(0x4BC04, &this->position, 0x7F, 0);
        this->cry_delay = (s32) (((3e+01f) * ((4.0f) * ((3.0517578e-05f) * (f32) rand()))) + (1.5e+02f));
    }
}

void TObjJungleKamome::draw() {
    if ((check_demo_mode() == 1) && (TMainTask::get_render_pass() == 0)) {
        draw_line_strip(this->model, this->path, (1.0f));
    }
    set_texture_list(lobby_kamome_texture_gvm_handle);
    push_matrix();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation.y);
    post_translate_matrix(&this->path_position.x);
    rotate_matrix_y(0, this->path_yaw);
    rotate_matrix_z(0, this->path_roll);
    draw_model_motion(this->model, this->motion, this->motion_frame);
    pop_matrix();
}

s32 TObjJungleKamome::initialize_path() {
    Vec a;
    Vec b;
    Vec d;
    s32 tmp;
    s32 r;
    this->path_yaw = 0;
    this->path_pitch = 0;
    this->path_roll = 0;
    this->roll_speed = 0;
    sample_clamped_path_position(this->model, this->path, &a, (0.0f));
    VecCopy(&this->path_position, &a);
    r = sample_clamped_path_position(this->model, this->path, &b, jungle_seagull_path_profiles[this->profile].look_ahead);
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &this->path_pitch, &tmp);
    this->path_yaw = (s32)(path_angle_units_per_radian[0] * atan2_float(b.x - a.x, b.z - a.z));
    return r;
}

s32 TObjJungleKamome::update_path_steering() {
    Vec a;
    Vec b;
    Vec d;
    s32 tmp;
    s32 tmp2;
    s32 r;
    s32 old;
    s32 diff;
    sample_clamped_path_position(this->model, this->path, &a, this->path_frame);
    VecCopy(&this->path_position, &a);
    r = sample_clamped_path_position(this->model, this->path, &b, this->path_frame + jungle_seagull_path_profiles[this->profile].look_ahead);
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &tmp, &tmp2);
    this->path_pitch = approach_angle_limited(this->path_pitch, tmp, jungle_seagull_path_profiles[this->profile].turn_step);
    old = this->path_yaw;
    tmp = (s32)(path_angle_units_per_radian[0] * atan2_float(b.x - a.x, b.z - a.z));
    this->path_yaw = approach_angle_limited(old, tmp, jungle_seagull_path_profiles[this->profile].turn_step);
    diff = angle_diff_s16(old, tmp);
    if (diff > 0x30) {
        if (this->roll_speed > 0) {
            this->roll_speed = 0;
        }
        this->roll_speed -= 0x40;
        if (this->roll_speed < -0x200) {
            this->roll_speed = -0x200;
        }
        this->path_roll += this->roll_speed;
        if (this->path_roll < -0x2000) {
            this->path_roll = -0x2000;
        }
    } else if (diff < -0x30) {
        if (this->roll_speed < 0) {
            this->roll_speed = 0;
        }
        this->roll_speed += 0x40;
        if (this->roll_speed > 0x200) {
            this->roll_speed = 0x200;
        }
        this->path_roll += this->roll_speed;
        if (this->path_roll > 0x2000) {
            this->path_roll = 0x2000;
        }
    } else {
        this->roll_speed = 0;
        if (this->path_roll > 0x100) {
            this->path_roll -= 0x100;
        } else if (this->path_roll < -0x100) {
            this->path_roll += 0x100;
        } else {
            this->path_roll = 0;
        }
    }
    return r;
}

void TObjJungleKamome::load_static_resource() {
    lobby_kamome_model_resource = new BmlResource(5, &bm_obj_jungle_kamome_resource_descriptor, 0, 0, NULL);
    lobby_kamome_texture_gvm_handle = LoadPvmFileTls("obj_jungle_kamome.gvm");
}

void TObjJungleKamome::destroy_instance() {
    if (lobby_kamome_texture_gvm_handle != NULL) {
        release_texture_list(lobby_kamome_texture_gvm_handle);
        safe_free(lobby_kamome_texture_gvm_handle);
        lobby_kamome_texture_gvm_handle = NULL;
    }
    if (lobby_kamome_model_resource != NULL) {
        delete lobby_kamome_model_resource;
        lobby_kamome_model_resource = NULL;
    }
}

void *TObjJungleKamome::create(ObjectSetData *set_data) {
    return new TObjJungleKamome(tl_05, set_data);
}

TObjLobbyPigeon::TObjLobbyPigeon(TObject *parent, ObjectSetData *set_data) : TObjPathObj(parent, set_data) {
    s32 movement;
    s32 selector;
    select_lobby_pigeon_model();
    this->scale = (1.0f);
    this->model = get_bml_model(lobby_pigeon_bml_archive, this->model_index);
    this->motion = get_bml_motion(lobby_pigeon_bml_archive, 0);
    selector = this->set_params[0];
    if (selector < 0) movement = 0;
    else {
        movement = 2;
        if (selector <= 2) movement = selector;
    }
    this->profile = movement;
    this->path = get_bml_motion(lobby_pigeon_bml_archive, lobby_pigeon_path_profiles[this->profile].path_motion);
    this->path_frame = (0.0f);
    this->motion_frame = (0.0f);
    initialize_lobby_pigeon_path();
    this->view_distance = (1e+03f);
    this->random_delay =
        (s32)((3e+01f) * ((4.0f) * ((3.0517578e-05f) * (f32)rand())) +
              (1.5e+02f));
}
#pragma pop

TObjLobbyPigeon::~TObjLobbyPigeon() {}

void TObjLobbyPigeon::update_lobby_pigeon_visibility() {
  switch (this->phase) {
  case 0:
    if (this->theme == filter_lobby_pigeon_theme(this)) {
      this->phase = 2;
    }
    break;
  case 2: {
    f32 lim = 1.0f;
    this->scale += 0.1f;
    if (this->scale >= lim) {
      this->scale = lim;
      this->phase = 3;
    }
  } break;
  case 1: {
    f32 lim = 0.0f;
    this->scale -= 0.1f;
    if (this->scale <= lim) {
      this->scale = lim;
      this->phase = 0;
    }
  } break;
  case 3:
  default:
    if (this->theme != filter_lobby_pigeon_theme(this)) {
      this->phase = 1;
    }
    break;
  }
}

#pragma push
#pragma fp_contract on
void TObjLobbyPigeon::update() {
  update_lobby_pigeon_visibility();
  this->path_frame += lobby_pigeon_path_profiles[this->profile].path_speed;
  if (advance_lobby_pigeon_path() == 0) {
    this->path_frame = (0.0f);
  }
  this->motion_frame += lobby_pigeon_path_profiles[this->profile].motion_speed;
  if (this->motion_frame > (f32)(u32)(this->motion->nbFrame - 1)) {
    this->motion_frame = (0.0f);
  }
  if (--this->random_delay < 0) {
    Mtx34 m;
    Vec v = lobby_pigeon_zero_vec;
    set_matrix_identity((u8 *)m);
    translate_matrix_vec3((u8 *)m, (u8 *)&this->position);
    rotate_matrix_y(m, this->rotation.y);
    translate_matrix_vec3((u8 *)m, (u8 *)&this->path_position);
    matrix_mult_vec(m, &v, &v);
    this->random_delay =
        (s32)((3e+01f) * ((4.0f) * ((3.0517578e-05f) * (f32)rand())) +
              (1.5e+02f));
  }
}

void TObjLobbyPigeon::draw() {
  if (check_demo_mode() == 1 &&
      TMainTask::get_render_pass() == 0)
    draw_line_strip(this->model, this->path, (1.0f));
  if (this->phase == 0 || lobby_pigeon_lobby_type == NULL)
    return;
  set_texture_list(lobby_pigeon_lobby_type);
  push_matrix();
  post_translate_matrix(&this->position.x);
  rotate_matrix_y(0, this->rotation.y);
  post_translate_matrix(&this->path_position.x);
  rotate_matrix_y(0, this->path_yaw);
  rotate_matrix_z(0, this->path_roll);
  if (this->phase != 3)
    scale_matrix(0, this->scale, this->scale, this->scale);
  draw_model_motion(this->model, this->motion, this->motion_frame);
  pop_matrix();
}
#pragma pop

void TObjLobbyPigeon::select_lobby_pigeon_model() {
    s32 theme_param;

    if ((s32) this->set_params[2] < 1) {
        this->model_index = 0;
    } else {
        this->model_index = 1;
    }
    theme_param = this->set_params[1];
    if (theme_param < 1) {
        this->theme = 0;
    } else if (this->model_index == 0) {
        if (theme_param > 1) {
            this->theme = 3;
        } else {
            this->theme = 0xA;
        }
    } else {
        this->theme = 5;
    }
    if (this->theme == filter_lobby_pigeon_theme(this)) {
        this->phase = 3;
        return;
    }
    this->phase = 0;
}

s32 TObjLobbyPigeon::initialize_lobby_pigeon_path() {
    Vec a;
    Vec b;
    Vec d;
    s32 tmp;
    s32 r;
    this->path_yaw = 0;
    this->path_pitch = 0;
    this->path_roll = 0;
    this->roll_speed = 0;
    sample_clamped_path_position(this->model, this->path, &a, (0.0f));
    VecCopy(&this->path_position, &a);
    r = sample_clamped_path_position(this->model, this->path, &b, lobby_pigeon_path_profiles[this->profile].look_ahead);
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &this->path_pitch, &tmp);
    this->path_yaw = (s32)(path_angle_units_per_radian[0] * atan2_float(b.x - a.x, b.z - a.z));
    return r;
}

s32 TObjLobbyPigeon::advance_lobby_pigeon_path() {
    Vec a;
    Vec b;
    Vec d;
    s32 tmp;
    s32 tmp2;
    s32 r;
    s32 old;
    s32 diff;
    sample_clamped_path_position(this->model, this->path, &a, this->path_frame);
    VecCopy(&this->path_position, &a);
    r = sample_clamped_path_position(this->model, this->path, &b, this->path_frame + lobby_pigeon_path_profiles[this->profile].look_ahead);
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &tmp, &tmp2);
    this->path_pitch = approach_angle_limited(this->path_pitch, tmp, lobby_pigeon_path_profiles[this->profile].turn_step);
    old = this->path_yaw;
    tmp = (s32)(path_angle_units_per_radian[0] * atan2_float(b.x - a.x, b.z - a.z));
    this->path_yaw = approach_angle_limited(old, tmp, lobby_pigeon_path_profiles[this->profile].turn_step);
    diff = angle_diff_s16(old, tmp);
    if (diff > 0x30) {
        if (this->roll_speed > 0) {
            this->roll_speed = 0;
        }
        this->roll_speed -= 0x40;
        if (this->roll_speed < -0x200) {
            this->roll_speed = -0x200;
        }
        this->path_roll += this->roll_speed;
        if (this->path_roll < -0x2000) {
            this->path_roll = -0x2000;
        }
    } else if (diff < -0x30) {
        if (this->roll_speed < 0) {
            this->roll_speed = 0;
        }
        this->roll_speed += 0x40;
        if (this->roll_speed > 0x200) {
            this->roll_speed = 0x200;
        }
        this->path_roll += this->roll_speed;
        if (this->path_roll > 0x2000) {
            this->path_roll = 0x2000;
        }
    } else {
        this->roll_speed = 0;
        if (this->path_roll > 0x100) {
            this->path_roll -= 0x100;
        } else if (this->path_roll < -0x100) {
            this->path_roll += 0x100;
        } else {
            this->path_roll = 0;
        }
    }
    return r;
}

// The callers pass the pigeon; the theme does not depend on it.
s32 filter_lobby_pigeon_theme(void *) {
    s32 filtered_event_theme;

    filtered_event_theme = TLobby::get_filtered_event_theme();
    switch (filtered_event_theme) {
    case 3:
    case 9:
        filtered_event_theme = 3;
        break;
    }
    return filtered_event_theme;
}

void TObjLobbyPigeon::load_static_resource() {
    lobby_pigeon_bml_archive = new BmlResource(5, &bm_obj_lobby_pigeon_resource_descriptor, 0, 0, NULL);
    lobby_pigeon_lobby_type = get_lobby_main_texlist();
}

void TObjLobbyPigeon::destroy_instance() {
    if (lobby_pigeon_bml_archive != NULL) {
        delete lobby_pigeon_bml_archive;
        lobby_pigeon_bml_archive = NULL;
    }
}

void *TObjLobbyPigeon::create(ObjectSetData *set_data) {
    return new TObjLobbyPigeon(tl_05, set_data);
}
