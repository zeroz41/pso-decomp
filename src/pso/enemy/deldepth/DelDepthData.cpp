#include "types.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/enemy/deldepth/DelDepthData.h"

extern "C" {
extern TObjMotionAction lbl_804E8194[];
extern TObjMotionAction lbl_804E81F4[];
extern const char lbl_80475BD8[] = "swim_body.nj";
extern const char lbl_80475BE8[] = "swim_disc.nj";
extern const char lbl_80475BF8[] = "swim_kirai.nj";
extern const char lbl_80475C08[] = "changea_swim_disc.njm";
extern const char lbl_80475C20[] = "changeb_swim_disc.njm";
extern const char lbl_80475C38[] = "damage_swim_disc.njm";
extern const char lbl_80475C50[] = "dead_swim_disc.njm";
extern const char lbl_80475C64[] = "move_swim_disc.njm";
extern const char lbl_80475C78[] = "attack_swim_body.njm";
extern const char lbl_80475C90[] = "attack2_swim_body.njm";
extern const char lbl_80475CA8[] = "changea_swim_body.njm";
extern const char lbl_80475CC0[] = "changeb_swim_body.njm";
extern const char lbl_80475CD8[] = "damage_swim_body.njm";
extern const char lbl_80475CF0[] = "dead_swim_body.njm";
extern const char lbl_80475D04[] = "wait_swim_body.njm";
extern const char lbl_80475D18[] = "bm_ene_del_depth.bml";
extern const char lbl_80475D30[] = "lo_swim_body.nj";
extern const char lbl_80475D40[] = "bm_ene_del_depth_low.bml";
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
