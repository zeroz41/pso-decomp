#ifndef PSO_RENDER_REFLECTION_H
#define PSO_RENDER_REFLECTION_H
#include "types.h"
#include <dolphin/mtx.h>

struct ReflectionPlane;
struct NJS_TEXLIST;
struct SceneSectionAngles;

s32 push_reflection_matrix(Vec *point);
s32 push_player_reflection_matrix(u16 client_id, s32 clip);
s32 set_reflection_scissor(const Vec *point, s32);
void restore_render_scissor(s32 reset_scissor);
void reset_reflection_tev_stages();
void play_reflection_particles(s16 effect_id);
void destroy_reflection_target();
void create_reflection_target();
// Forces the next reflection pass even when the player's floor ray missed.
void request_reflection_render();

// Finds a reflective floor (collision flag 0x4000) below pos; writes its point and normal to plane.
s32 find_reflective_floor(const Vec *pos, ReflectionPlane *plane);
void load_reflection_texture(void);
// Map section callback while the reflection is up: projects the reflection
// texture onto sections drawn with flag 0x80.
void setup_projection_texture(Vec *pos, SceneSectionAngles *angles, u32 flags);
// Undoes setup_projection_texture after a section drawn with flag 0x80.
void end_projection_texture(s32 flags);
// Points the reflected scene's texture list at texture_list.
void set_reflection_texture_list(NJS_TEXLIST *texture_list);
// Sets the direction find_reflective_floor casts its ray along.
void set_reflection_ray_direction(const Vec *direction);

#endif
