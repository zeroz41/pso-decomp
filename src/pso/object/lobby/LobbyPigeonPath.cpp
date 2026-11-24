#include "pso/animation/ActorAnimationState.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/memory.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/animation/MotionContext.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/object/lobby/LobbyPigeonPath.h"

#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/vector.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/TObjPathObj.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/TObjSeabedDolphin.h"
#include "pso/object/TObjJungleEbi.h"
#include "pso/object/TObjJungleBird.h"
#include "pso/object/TObjJungleKamome.h"
#include "pso/object/TObjLobbyPigeon.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include <stdlib.h>
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/lobby/LobbyPigeonTheme.h"

struct Entry_802C0CAC { s32 a; union { f32 pa; s32 b; }; union { f32 pb; s32 c; }; f32 d; s32 e; };

struct Entry_802C1660 { s32 a; f32 b; f32 c; f32 d; s32 e; };
struct Entry_802C1E34 { s32 a; f32 b; f32 c; f32 d; s32 e; };
struct Entry_802C2548 { s32 a; f32 b; f32 c; f32 d; s32 e; s32 f; };
struct Entry_802C2C48 { s32 a; f32 b; f32 c; f32 d; s32 e; };
typedef Entry_802C0CAC Ent_802C0F3C;

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
const char *TObjPathObj__name = "TObjPathObj";

// Path profiles: {path motion, path speed, motion speed, look-ahead frames, turn step};
// a turn step of 182 is one degree in 0x10000 units.
extern const Entry_802C2C48 seabed_dolphin_path_profiles[5] = {
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
extern const Entry_802C2548 jungle_ebi_path_profiles[3] = {
    {1, 0.01f, 0.6f, 0.1f, 182, 5},
    {2, 0.01f, 0.6f, 0.1f, 182, 5},
    {3, 0.01f, 0.6f, 0.1f, 364, 5},
};
extern const Entry_802C1E34 lobby_pigeon_path_parameters[3] = {
    {1, 0.1f, 0.6f, 0.1f, 364},
    {2, 0.1f, 0.6f, 0.1f, 364},
    {3, 0.1f, 0.6f, 0.1f, 546},
};
extern const Entry_802C1660 jungle_seagull_path_profiles[3] = {
    {1, 0.1f, 0.6f, 0.1f, 364},
    {2, 0.1f, 0.6f, 0.1f, 364},
    {3, 0.1f, 0.6f, 0.1f, 546},
};
extern const Vec lbl_80471908 = {0.0f, 0.0f, 0.0f};
extern const Ent_802C0F3C lobby_pigeon_path_profiles[3] = {
    {1, 0.1f, 2.0f, 0.1f, 364},
    {2, 0.1f, 2.0f, 0.1f, 364},
    {3, 0.1f, 2.0f, 0.1f, 546},
};
extern const Vec lobby_pigeon_zero_vec = {0.0f, 0.0f, 0.0f};
extern const f64 lbl_80471960[1] = {10430.38043493439};


#include "pso/map/CsnGroundQuery.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/render_util.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"

extern "C" {


s32 post_translate_matrix(void *);

struct Ent_802C1FD0 { s32 a; f32 b; f32 c; s32 d; s32 e; };
struct Ent_802C26E4 { s32 a; f32 b; f32 c; s32 d; s32 e; s32 f; };

struct Mtx_802C0F3C { f32 m[3][4]; };

typedef struct { f32 m[3][4]; } Mtx_802C17FC;



void matrix_mult_vec(void *, void *, void *);

}

#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/MatrixOps.h"


#pragma push
#pragma readonly_strings on
void TObjPathObj::update() {  }

void TObjPathObj::draw() {  }

TObjPathObj::TObjPathObj(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TObjPathObj__name;
    apply_object_set_data(set_data);
    view_distance = 5e+02f;
    m_94 = 1.5e+02f;
}

TObjPathObj::~TObjPathObj() {}

void TObjPathObj::run_task() {
    update();
}

void TObjPathObj::render() {
    if (TMainTask::get_render_pass() != 1 && update_object_view_visibility(view_distance, m_94) != 0) {
        draw();
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 TObjPathObj::sample_clamped_path_position(NJS_OBJECT *node, AnimationMotion *motion, Vec *pos, f32 frame) {
    s32 ang[3];
    f32 scl[3];
    f32 quat[4];
    s32 in_range;
    u32 last;

    in_range = 1;
    last = motion->frameCount - 1;
    if (frame > (f32)last) {
        in_range = 0;
        frame = (f32)last;
    }
    bind_motion_context((NJS_MOTION *)motion, frame);
    sample_motion_node_transform(node, &pos->x, ang, scl, quat);
    return in_range;
}
#pragma pop

#pragma push
#pragma fp_contract on

void TObjPathObj::draw_line_strip(NJS_OBJECT *node, AnimationMotion *motion, f32 step) {
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
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        debug_draw_line(&from, &to, 0xF0F0F0FF, 0xF0F0F0FF);
        pop_matrix();
    } while (more != 0);
}
#pragma pop

#pragma push
#pragma fp_contract on
TObjSeabedDolphin::TObjSeabedDolphin(TObject *parent, void *set_data) : TObjPathObj(parent, set_data) {
  s32 var_r0;
  s32 temp_r3;
  model = get_bml_model(seabed_dolphin_bml_archive, 0);
  motion = get_bml_motion(seabed_dolphin_bml_archive, 5);
  temp_r3 = set_params[0];
  if (temp_r3 < 0)
  {
    var_r0 = 0;
  }
  else
  {
    var_r0 = 4;
    if (temp_r3 <= 4)
    {
      var_r0 = temp_r3;
    }
  }
  profile = var_r0;
  path = get_bml_motion(seabed_dolphin_bml_archive, seabed_dolphin_path_profiles[profile].a);
  path_frame = 0.0f;
  motion_frame = 0.0f;
  initialize_path();
}

TObjSeabedDolphin::~TObjSeabedDolphin() {}

void TObjSeabedDolphin::update() {
    const Entry_802C2C48 *e = seabed_dolphin_path_profiles;
    f32 ox;
    e += this->profile;
    ox = this->path_frame;
    this->path_frame = ox + e->b;
    if (update_path_steering() == 0) {
        this->path_frame = (0.0f);
    }
    this->motion_frame = this->motion_frame + seabed_dolphin_path_profiles[this->profile].c;
    if (this->motion_frame > (f32)(this->motion->frameCount - 1)) {
        this->motion_frame = (0.0f);
    }
}

void TObjSeabedDolphin::draw() {
    if ((TObjPlayer::check_demo_mode() == 1) && (TMainTask::get_render_pass() == 0)) {
        draw_line_strip(this->model, this->path, (1.0f));
    }
    TObjFish::set_global_param(seabed_dolphin_texture_handle);
    push_matrix();
    post_translate_matrix(&this->position);
    rotate_matrix_y(0, this->rotation_y);
    post_translate_matrix(&this->path_position);
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
    r = sample_clamped_path_position(this->model, this->path, &b, seabed_dolphin_path_profiles[this->profile].d);
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &this->path_pitch, &tmp);
    this->path_yaw = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
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
    r = sample_clamped_path_position(this->model, this->path, &b, this->path_frame + seabed_dolphin_path_profiles[this->profile].d);
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &tmp, &tmp2);
    this->path_pitch = approach_angle_limited(this->path_pitch, tmp, seabed_dolphin_path_profiles[this->profile].e);
    old = this->path_yaw;
    tmp = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    this->path_yaw = approach_angle_limited(old, tmp, seabed_dolphin_path_profiles[this->profile].e);
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
    seabed_dolphin_texture_handle = load_gvm_texture_file("obj_seabed_dolphin.gvm");
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

void *TObjSeabedDolphin::create(void *set_data) {
    return new TObjSeabedDolphin(tl_05, set_data);
}
#pragma pop

#pragma push
#pragma fp_contract on
TObjJungleEbi::TObjJungleEbi(TObject *parent, void *set_data) : TObjPathObj(parent, set_data) {
  s32 var_r0;
  s32 temp_r3;
  model = get_bml_model(jungle_ebi_model_resource, 0);
  motion = get_bml_motion(jungle_ebi_model_resource, 0);
  temp_r3 = set_params[0];
  if (temp_r3 < 0)
  {
    var_r0 = 0;
  }
  else
  {
    var_r0 = 2;
    if (temp_r3 <= 2)
    {
      var_r0 = temp_r3;
    }
  }
  profile = var_r0;
  path = get_bml_motion(jungle_ebi_model_resource, jungle_ebi_path_profiles[profile].a);
  path_frame = 0.0f;
  motion_frame = 0.0f;
  initialize_path();
}

TObjJungleEbi::~TObjJungleEbi() {}

void TObjJungleEbi::update() {
    Ent_802C26E4 *e = (Ent_802C26E4 *)jungle_ebi_path_profiles;
    e += this->profile;
    f32 ox = this->path_frame;
    this->path_frame = ox + e->b;
    if (update_path_follow_rotation((Ent_802C26E4 *)(e), ox) == 0) {
        this->path_frame = (0.0f);
    }
    this->motion_frame = this->motion_frame + jungle_ebi_path_profiles[this->profile].c;
    if (this->motion_frame > (f32)(this->motion->frameCount - 1)) {
        this->motion_frame = (0.0f);
    }
}

void TObjJungleEbi::draw() {
    if ((TObjPlayer::check_demo_mode() == 1) && (TMainTask::get_render_pass() == 0)) {
        draw_line_strip(this->model, this->path, (1.0f));
    }
    TObjFish::set_global_param(jungle_ebi_texture_gvm_handle);
    push_matrix();
    post_translate_matrix(&this->position);
    rotate_matrix_y(0, this->rotation_y);
    post_translate_matrix(&this->path_position);
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
    r = sample_clamped_path_position(this->model, this->path, &b, jungle_ebi_path_profiles[this->profile].d);
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &this->path_pitch, &tmp);
    this->path_yaw = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    return r;
}

s32 TObjJungleEbi::update_path_follow_rotation(void *, f32) {
    s32 r;
    const Entry_802C2548 *e;
    s32 old;
    s32 diff;
    Vec a;
    Vec b;
    s32 tmp;
    s32 tmp2;
    e = &jungle_ebi_path_profiles[this->profile];
    if (!(e->f & 1)) {
        return 1;
    }
    sample_clamped_path_position(this->model, this->path, &a, this->path_frame);
    VecCopy(&this->path_position, &a);
    r = sample_clamped_path_position(this->model, this->path, &b, this->path_frame + e->d);
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
    direction_to_rotation_xz((u8 *)((Vec *)&d), &tmp, &tmp2);
    }
    this->path_pitch = approach_angle_limited(this->path_pitch, tmp, e->e);
    old = this->path_yaw;
    tmp = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    if (!(e->f & 2)) {
        this->path_yaw = approach_angle_limited(old, tmp, e->e);
    }
    if (!(e->f & 4)) {
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
    jungle_ebi_texture_gvm_handle = load_gvm_texture_file("obj_jungle_ebi.gvm");
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

void *TObjJungleEbi::create(void *set_data) {
    return new TObjJungleEbi(tl_05, set_data);
}

TObjJungleBird::TObjJungleBird(TObject *parent, void *set_data) : TObjPathObj(parent, set_data) {
  s32 var_r0;
  s32 temp_r3;
  model = get_bml_model(jungle_bird_bml_resource, 0);
  motion = get_bml_motion(jungle_bird_bml_resource, 0);
  temp_r3 = set_params[0];
  if (temp_r3 < 0)
  {
    var_r0 = 0;
  }
  else
  {
    var_r0 = 2;
    if (temp_r3 <= 2)
    {
      var_r0 = temp_r3;
    }
  }
  profile = var_r0;
  path = get_bml_motion(jungle_bird_bml_resource, lobby_pigeon_path_parameters[profile].a);
  path_frame = 0.0f;
  motion_frame = 0.0f;
  initialize_path();
}

TObjJungleBird::~TObjJungleBird() {}

void TObjJungleBird::update() {
    u8 *t = (u8 *)lobby_pigeon_path_parameters;
    t = t + this->profile * 0x14;
    Ent_802C1FD0 *e = (Ent_802C1FD0 *)t;
    f32 ox = this->path_frame;
    this->path_frame = ox + e->b;
    if (update_path_steering() == 0) {
        this->path_frame = (0.0f);
    }
    this->motion_frame = this->motion_frame + lobby_pigeon_path_parameters[this->profile].c;
    if (this->motion_frame > (f32)(this->motion->frameCount - 1)) {
        this->motion_frame = (0.0f);
    }
}

void TObjJungleBird::draw() {
    if ((TObjPlayer::check_demo_mode() == 1) && (TMainTask::get_render_pass() == 0)) {
        draw_line_strip(this->model, this->path, (1.0f));
    }
    TObjFish::set_global_param(lobby_pigeon_texture_gvm);
    push_matrix();
    post_translate_matrix(&this->position);
    rotate_matrix_y(0, this->rotation_y);
    post_translate_matrix(&this->path_position);
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
    r = sample_clamped_path_position(this->model, this->path, &b, lobby_pigeon_path_parameters[this->profile].d);
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &this->path_pitch, &tmp);
    this->path_yaw = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
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
    r = sample_clamped_path_position(this->model, this->path, &b, this->path_frame + lobby_pigeon_path_parameters[this->profile].d);
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &tmp, &tmp2);
    this->path_pitch = approach_angle_limited(this->path_pitch, tmp, lobby_pigeon_path_parameters[this->profile].e);
    old = this->path_yaw;
    tmp = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    this->path_yaw = approach_angle_limited(old, tmp, lobby_pigeon_path_parameters[this->profile].e);
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
    lobby_pigeon_texture_gvm = load_gvm_texture_file("obj_jungle_bird.gvm");
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

void *TObjJungleBird::create(void *set_data) {
    return new TObjJungleBird(tl_05, set_data);
}
#pragma pop

#pragma push
#pragma fp_contract on
TObjJungleKamome::TObjJungleKamome(TObject *parent, void *set_data) : TObjPathObj(parent, set_data) {
    s32 temp_r3;
    s32 var_r0;

    model = get_bml_model(lobby_kamome_model_resource, 0);
    motion = get_bml_motion(lobby_kamome_model_resource, 0);
    temp_r3 = set_params[0];
    var_r0 = (temp_r3 < 0) ? 0 : (temp_r3 > 2) ? 2 : temp_r3;
    profile = var_r0;
    path = get_bml_motion(lobby_kamome_model_resource, jungle_seagull_path_profiles[profile].a);
    path_frame = 0.0f;
    motion_frame = 0.0f;
    initialize_path();
    view_distance = 1e+03f;
    cry_delay = (s32) (((3e+01f) * ((4.0f) * ((3.0517578e-05f) * (f32) rand()))) + (1.5e+02f));
}

TObjJungleKamome::~TObjJungleKamome() {}

void TObjJungleKamome::update() {
    Mtx_802C17FC m;
    s32 temp_r0;

    this->path_frame += jungle_seagull_path_profiles[this->profile].b;
    if (update_path_steering() == 0) {
        this->path_frame = (0.0f);
    }
    this->motion_frame += jungle_seagull_path_profiles[this->profile].c;
    if (this->motion_frame > (f32) (this->motion->frameCount - 1)) {
        this->motion_frame = (0.0f);
    }
    temp_r0 = this->cry_delay - 1;
    this->cry_delay = temp_r0;
    if (temp_r0 < 0) {
        Vec v = lbl_80471908;
        set_matrix_identity((u8 *)&m);
        translate_matrix_vec3((u8 *)&m, (u8 *)&this->position);
        ((s32 (*)(void *, int))rotate_matrix_y)(&m, this->rotation_y);
        translate_matrix_vec3((u8 *)&m, (u8 *)&this->path_position);
        ((s32 (*)(void *, void *, void *))matrix_mult_vec)(&m, &v, &v);
        play_sound_effect(0x4BC04, &this->position, 0x7F, 0);
        this->cry_delay = (s32) (((3e+01f) * ((4.0f) * ((3.0517578e-05f) * (f32) rand()))) + (1.5e+02f));
    }
}

void TObjJungleKamome::draw() {
    if ((TObjPlayer::check_demo_mode() == 1) && (TMainTask::get_render_pass() == 0)) {
        draw_line_strip(this->model, this->path, (1.0f));
    }
    TObjFish::set_global_param(lobby_kamome_texture_gvm_handle);
    push_matrix();
    post_translate_matrix(&this->position);
    rotate_matrix_y(0, this->rotation_y);
    post_translate_matrix(&this->path_position);
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
    r = sample_clamped_path_position(this->model, this->path, &b, jungle_seagull_path_profiles[this->profile].d);
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &this->path_pitch, &tmp);
    this->path_yaw = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
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
    r = sample_clamped_path_position(this->model, this->path, &b, this->path_frame + jungle_seagull_path_profiles[this->profile].d);
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &tmp, &tmp2);
    this->path_pitch = approach_angle_limited(this->path_pitch, tmp, jungle_seagull_path_profiles[this->profile].e);
    old = this->path_yaw;
    tmp = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    this->path_yaw = approach_angle_limited(old, tmp, jungle_seagull_path_profiles[this->profile].e);
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
    lobby_kamome_texture_gvm_handle = load_gvm_texture_file("obj_jungle_kamome.gvm");
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

void *TObjJungleKamome::create(void *set_data) {
    return new TObjJungleKamome(tl_05, set_data);
}

TObjLobbyPigeon::TObjLobbyPigeon(TObject *parent, void *set_data) : TObjPathObj(parent, set_data) {
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
    this->path = get_bml_motion(lobby_pigeon_bml_archive, lobby_pigeon_path_profiles[this->profile].a);
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
  this->path_frame += lobby_pigeon_path_profiles[this->profile].pa;
  if (advance_lobby_pigeon_path() == 0) {
    this->path_frame = (0.0f);
  }
  this->motion_frame += lobby_pigeon_path_profiles[this->profile].pb;
  if (this->motion_frame > (f32)(u32)(this->motion->frameCount - 1)) {
    this->motion_frame = (0.0f);
  }
  if (--this->random_delay < 0) {
    Mtx_802C0F3C m;
    Vec v = lobby_pigeon_zero_vec;
    set_matrix_identity((u8 *)&m);
    translate_matrix_vec3((u8 *)&m, (u8 *)&this->position);
    ((void (*)(void *, s32))rotate_matrix_y)(&m, this->rotation_y);
    translate_matrix_vec3((u8 *)&m, (u8 *)&this->path_position);
    matrix_mult_vec(&m, &v, &v);
    this->random_delay =
        (s32)((3e+01f) * ((4.0f) * ((3.0517578e-05f) * (f32)rand())) +
              (1.5e+02f));
  }
}

void TObjLobbyPigeon::draw() {
  if (TObjPlayer::check_demo_mode() == 1 &&
      TMainTask::get_render_pass() == 0)
    draw_line_strip(this->model, this->path, (1.0f));
  if (this->phase == 0 || lobby_pigeon_lobby_type == NULL)
    return;
  TObjFish::set_global_param(lobby_pigeon_lobby_type);
  push_matrix();
  post_translate_matrix(&this->position);
  rotate_matrix_y(0, this->rotation_y);
  post_translate_matrix(&this->path_position);
  rotate_matrix_y(0, this->path_yaw);
  rotate_matrix_z(0, this->path_roll);
  if (this->phase != 3)
    scale_matrix(0, this->scale, this->scale, this->scale);
  draw_model_motion(this->model, this->motion, this->motion_frame);
  pop_matrix();
}
#pragma pop

void TObjLobbyPigeon::select_lobby_pigeon_model() {
    s32 temp_r3;

    if ((s32) this->set_params[2] < 1) {
        this->model_index = 0;
    } else {
        this->model_index = 1;
    }
    temp_r3 = this->set_params[1];
    if (temp_r3 < 1) {
        this->theme = 0;
    } else if (this->model_index == 0) {
        if (temp_r3 > 1) {
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
    r = sample_clamped_path_position(this->model, this->path, &b, lobby_pigeon_path_profiles[this->profile].d);
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &this->path_pitch, &tmp);
    this->path_yaw = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
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
    r = sample_clamped_path_position(this->model, this->path, &b, this->path_frame + lobby_pigeon_path_profiles[this->profile].d);
    VecCopy(&d, &b);
    subtract_vector(&d, &a);
    direction_to_rotation_xz((u8 *)&d, &tmp, &tmp2);
    this->path_pitch = approach_angle_limited(this->path_pitch, tmp, lobby_pigeon_path_profiles[this->profile].e);
    old = this->path_yaw;
    tmp = (s32)(lbl_80471960[0] * atan2_float(b.x - a.x, b.z - a.z));
    this->path_yaw = approach_angle_limited(old, tmp, lobby_pigeon_path_profiles[this->profile].e);
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
    saddr temp_r3;
    lobby_pigeon_bml_archive = new BmlResource(5, &bm_obj_lobby_pigeon_resource_descriptor, 0, 0, NULL);
    lobby_pigeon_lobby_type = TLobby::get_lobby_texlist();
}

void TObjLobbyPigeon::destroy_instance() {
    if (lobby_pigeon_bml_archive != NULL) {
        delete (BmlResource *)lobby_pigeon_bml_archive;
        lobby_pigeon_bml_archive = NULL;
    }
}

void *TObjLobbyPigeon::create(void *set_data) {
    return new TObjLobbyPigeon(tl_05, set_data);
}
