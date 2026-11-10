#include "types.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/enemy/deldepth/DelDepthData.h"

extern "C" {
extern TObjMotionAction lbl_804E8194[];
extern TObjMotionAction lbl_804E81F4[];
extern const char lbl_80475BD8[] = "swim_body.nj";
extern const char deldepth_model_name_swim_disc_nj[] = "swim_disc.nj";
extern const char deldepth_model_name_swim_kirai_nj[] = "swim_kirai.nj";
extern const char deldepth_motion_name_changea_swim_disc_njm[] = "changea_swim_disc.njm";
extern const char deldepth_motion_name_changeb_swim_disc_njm[] = "changeb_swim_disc.njm";
extern const char deldepth_motion_name_damage_swim_disc_njm[] = "damage_swim_disc.njm";
extern const char deldepth_motion_name_dead_swim_disc_njm[] = "dead_swim_disc.njm";
extern const char deldepth_motion_name_move_swim_disc_njm[] = "move_swim_disc.njm";
extern const char deldepth_motion_name_attack_swim_body_njm[] = "attack_swim_body.njm";
extern const char deldepth_motion_name_attack2_swim_body_njm[] = "attack2_swim_body.njm";
extern const char deldepth_motion_name_changea_swim_body_njm[] = "changea_swim_body.njm";
extern const char deldepth_motion_name_changeb_swim_body_njm[] = "changeb_swim_body.njm";
extern const char deldepth_motion_name_damage_swim_body_njm[] = "damage_swim_body.njm";
extern const char deldepth_motion_name_dead_swim_body_njm[] = "dead_swim_body.njm";
extern const char deldepth_motion_name_wait_swim_body_njm[] = "wait_swim_body.njm";
extern const char bm_ene_del_depth_bml_filename[] = "bm_ene_del_depth.bml";
extern const char deldepth_model_name_lo_swim_body_nj[] = "lo_swim_body.nj";
extern const char bm_ene_del_depth_low_bml_filename[] = "bm_ene_del_depth_low.bml";
extern const char TObjEneDelDepth__class_name_string[] = "TObjEneDelDepth";
extern const Vec lbl_80475D6C = {2.5f, 0.0f, 2.5f};
extern const Vec lbl_80475D78 = {1.0f, 1.0f, 1.0f};
extern const DelDepthAnimationBinding deldepth_anim_binding = {NULL, lbl_804E8194, 0, 6, 0};
extern const DelDepthAnimationBinding deldepth_anim_binding_b = {NULL, lbl_804E81F4, 0, 1, 0};
extern const Vec lbl_80475DA4 = {2.0f, 2.0f, 2.0f};
extern const Vec lbl_80475DB0 = {0.0f, 0.0f, 0.0f};
extern const char TObjEneDelDepthBomb__class_name_string[] = "TObjEneDelDepthBomb";
extern const f64 TObjEneDelDepth__data_80475DD0 = 10430.38043493439;

const char *TObjEneDelDepth__name = TObjEneDelDepth__class_name_string;
const char *TObjEneDelDepthBomb__name = TObjEneDelDepthBomb__class_name_string;
DelDepthParameters *TObjEneDelDepth__tune_params;
BmlResource *TObjEneDelDepth__shared_resource;
f32 lbl_805D6AC8;
u8 TObjEneDelDepth__state_complete_flag;
f32 TObjEneDelDepth__animation_end_frame;
u8 TObjEneDelDepth__animation_end_frame_initialized;

}
