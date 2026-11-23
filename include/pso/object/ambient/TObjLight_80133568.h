#ifndef PSO_OBJECT_AMBIENT_TOBJLIGHT_80133568_H
#define PSO_OBJECT_AMBIENT_TOBJLIGHT_80133568_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

class TObjBase;
class TQuestThread;
class TUnk_804A6F78;
class TUnk_804A6F90;
struct TObjLight;
struct PointLight;
struct LightEntry;

extern "C" {
TQuestThread *TLobby__sub_80134A20(void *p);
void TObjLight__sub_801337FC(void *light);
void *__dt__13TUnk_804A7008Fv(void *arg0, s16 arg1);
}
void init_area_lights(void);
void init_map_lights(LightEntry *entry);
// Sets the diffuse colour of the scene light.
void set_scene_light_color(f32 r, f32 g, f32 b);
// Lights the scene with a directional light along `dir` and an ambient intensity.
void set_light(const Vec *dir, const NJS_ARGB *color, f32 ambient);
extern "C" {
// Every caller passes 4 as the second argument; the body never reads it.
void init_menu_scene_lights(LightEntry *entry, s32);
}
void load_light_entry_file(void);
extern "C" {
void publish_actor_light_scalars(u32 id, f32 intensity, f32 ambient);
void publish_light_direction_color(u32 id, void *dir, void *color);
void register_actor_light(s32 id, TObjLight *light);
void restore_scene_lighting(void);
void select_actor_lighting(TObjBase *obj);
}

// One area's light setup: lightentry.bin holds one per area (big-endian on disc);
// init_map_lights makes it the scene light.
struct LightEntry {
    Vec direction;          // 0x00: the configured direction, normalised
    Vec view_direction;     // 0x0C: direction rotated by matrix 0, what GX gets
    f32 pad_18;
    f32 intensity;          // 0x1C
    f32 ambient;            // 0x20: ambient intensity
    NJS_ARGB color;         // 0x24: diffuse colour
    NJS_ARGB ambient_color; // 0x34
    void bswap_data();
};
LAYOUT_ASSERT(LightEntry_size, sizeof(LightEntry) == 0x44);

// A LightEntry as lightentry.bin stores it: copied as raw bytes, since it is
// still big-endian until bswap_data.
struct LightEntryBytes {
    u8 bytes[sizeof(LightEntry)];
};

// The scene's light as the map's light entry sets it up (init_map_lights).
struct TObjLightSceneLightState : public LightEntry {
    u8 pad_44[0xC];
};
extern TObjLightSceneLightState scene_light_state;
// The light init_map_lights sets up without a map light entry.
extern LightEntry default_scene_light_config;

// The light an actor is lit by (select_actor_lighting), kept per entity id.
struct ActorLight {
    Vec direction;  // 0x00
    NJS_ARGB color; // 0x0C
    f32 intensity;  // 0x1C
    f32 ambient;    // 0x20
    u32 flags;      // 0x24: 1 = intensity and ambient published, 2 = direction and colour published
    u32 id;         // 0x28: entity id, 0xFFFF when free
};
LAYOUT_ASSERT(ActorLight_size, sizeof(ActorLight) == 0x2C);

// register_actor_light appends one entry per actor in range (actor_light_count).
extern ActorLight actor_light_table[32];
extern s32 actor_light_count;
// publish_light_direction_color / publish_actor_light_scalars keep one entry per light id (light_count).
extern ActorLight light_table[8];
extern s32 light_count;
// The point lights alloc_light_slot hands out, one per GX light 2..4.
extern PointLight *light_slots[3];
extern s32 active_light_count;
// lightentry.bin as read from disc (load_light_entry_file).
extern LightEntry *light_entry_data;
extern s32 light_entry_file_size;
extern const char light_entry_file_name[];

extern TUnk_804A6F90 *lbl_805D5558;
extern void *lbl_805D555C;
extern TObjLight *current_scene_light;
extern TUnk_804A6F78 *lbl_805D5564;

#endif
