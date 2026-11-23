#ifndef PSO_SYSTEM_SCENE_TSCENE_H
#define PSO_SYSTEM_SCENE_TSCENE_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct SceneMaterialSection;
struct Vec;

// One record of the area's texture UV animations (texture_animation_buffer).
struct TextureUvAnimation {
    u16 id;
    u16 texture;
    f32 u, v, du, dv;

    void copy_from(TextureUvAnimation *src);
};

// One entry of the material info file: the indirect-texture effect of a material id.
struct SceneMaterialInfo {
    u16 id;
    u8 texture_index;
    u8 pad_03;
    u8 effect_id;
    u8 pad_05[3];
};

// The material info file (<floor>i.bin): a header word, then count entries.
struct SceneMaterialInfoFile {
    s32 header;
    s32 count;
    SceneMaterialInfo entries[1];
};

// One record of the area's texture wave table, ended by a negative texture_index.
struct TextureWaveEntry {
    s16 texture_index;
    u8 pad_02[2];
    u8 *image;
    s32 size;
};

// A name and the index it selects: a scene format tag (scene_format_dispatch_tables) or a floor's
// scene file (get_floor_scene_table).
struct SceneNameIndex { char *name; s32 idx; };

/* A map section's rotation, its node's angles plus the section's (passed to the section render callback). */
struct SceneSectionAngles { s32 x, y, z; };

class TScene : public TObject
{
public:
    u32 visible_section_count; // sections the culling pass marked visible this frame
    u8 _pad20[0x10];
    u32 pad_30;  // pad_30-pad_3C: 0, 0, 50, 0 from the constructor
    u32 pad_34;
    u32 pad_38;
    u32 pad_3C;

    TScene(TObject *parent);
    void initialize_fmt2_materials();
    virtual ~TScene();
    virtual void run_task();
    virtual void render();
    void sub_80204D7C();
    void cull_sections();
    // Whether pos lies in front of the camera and no further than depth.
    BOOL is_in_view_depth(Vec *pos, f32 depth, f32);
    // Which of the four culling passes render runs this frame.
    s32 get_cull_mode();
    // Empty: the TEffIndirect nodes init_material_nodes creates are child tasks.
    void release_material_nodes();
    s32 is_within_view_edge(Vec *pos, Vec *dir, Vec *edge, f32 radius);
    s32 check_object_in_view_cone(SceneMaterialSection *section, Vec *pos, Vec *dir, s32 angle);
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
    void render_static_map_section(SceneMaterialSection *section, s32 flagged_only);
    void render_animated_map_section(SceneMaterialSection *section, s32 flagged_only);
    void update_room_object_visibility(SceneMaterialSection *room);
    void set_field4();
    void advance_scene_object_animations();
    void init_material_nodes();
    static void create_texture_wave_tasks(TObject *parent);
    s32 find_uv_animation(TextureUvAnimation *uv);
    SceneMaterialInfo *find_material_entry_by_id(u16 id);
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
    // Empty per-floor file loaders called after load_tam_file.
    static void empty_floor_loader_1(saddr ent);
    static void empty_floor_loader_2(saddr ent);
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
LAYOUT_ASSERT(TScene_field_1c_offset, offsetof(TScene, visible_section_count) == 0x1C);

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
