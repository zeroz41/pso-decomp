#ifndef PSO_OBJECT_AMBIENT_TOBJLIGHT_80133568_H
#define PSO_OBJECT_AMBIENT_TOBJLIGHT_80133568_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

class TObjBase;
class TQuestThread;
class TUnk_804A6F78;
class TUnk_804A6F90;
struct TObjLight;

extern "C" {
TQuestThread *TLobby__sub_80134A20(void *p);
void TObjBoss2Tunnel__sub_801339EC(f32 farg0, f32 farg1, f32 farg2);
void TObjLight__sub_801337FC(void *light);
void *__dt__13TUnk_804A7008Fv(void *arg0, s16 arg1);
}
void init_area_lights(void);
void init_map_lights(u8 *arg0);
extern "C" {
// Every caller passes 4 as arg1; the body never reads it.
void init_menu_scene_lights(u8 *arg0, s32 arg1);
}
void load_light_entry_file(void);
extern "C" {
void publish_actor_light_scalars(u32 arg0, f32 farg0, f32 farg1);
void publish_light_direction_color(u32 id, void *dir, void *color);
void register_actor_light(s32 arg0, TObjLight *light);
void restore_scene_lighting(void);
void select_actor_lighting(TObjBase *obj);
}

// The scene's light as the map's light entry sets it up (init_map_lights).
struct TObjLightSceneLightState {
    Vec direction;          // 0x00: the configured direction, normalised
    Vec view_direction;     // 0x0C: direction rotated by matrix 0, what GX gets
    f32 pad_18;
    f32 intensity;          // 0x1C
    f32 ambient;            // 0x20: ambient intensity
    NJS_ARGB color;         // 0x24: diffuse colour
    NJS_ARGB ambient_color; // 0x34
    u8 pad_44[0xC];
};
extern TObjLightSceneLightState TObjLight__scene_light_state;
// The light init_map_lights sets up without a map light entry, laid out like
// the start of TObjLightSceneLightState ([7] intensity, [8] ambient).
extern f32 default_scene_light_config[];

extern TUnk_804A6F90 *lbl_805D5558;
extern void *lbl_805D555C;
extern TObjLight *current_scene_light;
extern TUnk_804A6F78 *lbl_805D5564;

#endif
