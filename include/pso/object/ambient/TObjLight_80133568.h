#ifndef PSO_OBJECT_AMBIENT_TOBJLIGHT_80133568_H
#define PSO_OBJECT_AMBIENT_TOBJLIGHT_80133568_H

#include "types.h"

extern "C" {
int TLobby__sub_80134A20(void *p);
void TObjBoss2Tunnel__sub_801339EC(f32 farg0, f32 farg1, f32 farg2);
void render__13TUnk_804A6F78Fv(void);
void TObjLight__sub_801336DC(void);
void TObjLight__sub_80133714(void);
void TObjLight__sub_8013379C(void);
void TObjLight__sub_801337F8(void);
void TObjLight__sub_801337FC(void);
void TObjLight__sub_8013397C(void *_w0);
u8 *TObjLight__sub_80133980(u8 *arg0, int _w1);
void *__dt__13TUnk_804A6F78Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804A6F90Fv(void *arg0, s16 arg1);
void *__dt__13TUnk_804A7008Fv(void *arg0, s16 arg1);
}
void apply_environment_light(s32 arg0);
void init_area_lights(void);
void init_map_lights(u8 *arg0);
extern "C" {
void init_menu_scene_lights(u8 *arg0);
}
void load_light_entry_file(void);
extern "C" {
void publish_actor_light_scalars(u32 arg0, f32 farg0, f32 farg1);
void publish_light_direction_color(u32 id, void *dir, void *color);
void register_actor_light(s32 arg0, s32 arg1);
void run_task__13TUnk_804A6FA8Fv(void);
void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
}
void set_scene_light_diffuse(void *_w0);
void submit_scene_ambient_color(void);
void submit_scene_light_direction(void *_w0);

#endif
