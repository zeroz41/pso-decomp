#ifndef PSO_SYSTEM_SCENE_TSCENE_H
#define PSO_SYSTEM_SCENE_TSCENE_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct SceneMaterialSection;
struct Vec;

/* A map section's rotation, its node's angles plus the section's (passed to the section render callback). */
struct SceneSectionAngles { s32 x, y, z; };

class TScene : public TObject
{
public:
    u32 m_1c;
    u8 _pad20[0x10];
    u32 m_30;
    u32 m_34;
    u32 m_38;
    u32 m_3c;

    TScene(TObject *parent);
    void initialize_fmt2_materials();
    virtual ~TScene();
    virtual void run_task();
    virtual void render();
    void sub_80204D7C();
    void cull_sections();
    void update_room_visibility_from_camera();
    void update_records_in_range();

    void dispatch_material_animation();
    void tick_material_fmt1();
    void tick_material_fmt2();
public:
    static const char *class_name;

    static void bind_ending_wall_textures();
    static void set_scene(int scene);
    static void apply_single_screen_state();
    static void set_ready();
    static void reset_counter();
    static int get_status();
    static void set_instance(void (*callback)(void));
    static void set_active_scene(void (*callback)(s32 flags));
    static void set_id(void (*callback)(Vec *pos, SceneSectionAngles *angles, u32 flags));
    // The map section the player with client_id stands in, or -1.
    static s32 find_player_section(u16 client_id);
    void render_map_sections();
    void render_static_map_section(SceneMaterialSection *arg1, s32 arg2);
    void render_animated_map_section(SceneMaterialSection *arg1, s32 arg2);
    void update_room_object_visibility(SceneMaterialSection *room);
    void set_field4();
    void advance_scene_object_animations();
    void init_material_nodes();
    static void create_texture_wave_tasks(TObject *parent);
    void copy_header_and_vec(void* q);
    void initialize_fmt1_materials();
    void initialize_materials();
    void cleanup_materials();
    void cleanup_fmt1_materials();
    void cleanup_fmt2_materials();
    static void create();
    static void load_floor_rel_file(saddr name);
    static void load_tam_file(saddr name);
    static void free_scene_resources();
    static void load_file_to_buffer(saddr name);
    static void load_floor_bin_file(saddr name);
    static void load_map_texture_archive(saddr name);
    static void load_supplementary_t_rel(saddr name);
    static void load_scene_rel_file(saddr ent);
    static void load_scene_data(saddr name);
    static void load_current_floor();
    // Reflection pass: only the sections flagged 0x100 render while it is active.
    static void begin_reflection_pass();
    static void end_reflection_pass();
    static void set_visibility_radius_margin(f32 margin);
    void offset_position(s32 arg1, s32 arg2);
    void apply_uv_offset(s16 arg1, s16 arg2);
    void *destroy_buffers(s16 arg1);
    void *init_buffers(saddr arg1, s32 arg2);
};

#include <stddef.h>
LAYOUT_ASSERT(TScene_size, sizeof(TScene) == 0x40);
LAYOUT_ASSERT(TScene_field_1c_offset, offsetof(TScene, m_1c) == 0x1C);
LAYOUT_ASSERT(TScene_field_30_offset, offsetof(TScene, m_30) == 0x30);
LAYOUT_ASSERT(TScene_field_34_offset, offsetof(TScene, m_34) == 0x34);
LAYOUT_ASSERT(TScene_field_38_offset, offsetof(TScene, m_38) == 0x38);
LAYOUT_ASSERT(TScene_field_3c_offset, offsetof(TScene, m_3c) == 0x3C);

void load_scene_collision_file(saddr scene_file_index);
// The id of the nearest map section whose radius holds pos, or -1.
s32 find_section_at_position(Vec *pos);

extern s32 scene_resource_index;
extern s32 lobby_online_ready_flag;
extern s8 floor_scene_ready_flag;
extern s32 reflection_pass_active;
extern f32 visibility_radius_margin;

extern "C" s32 is_item_area_enabled(s32 area);

#endif
