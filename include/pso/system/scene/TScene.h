#ifndef PSO_SYSTEM_SCENE_TSCENE_H
#define PSO_SYSTEM_SCENE_TSCENE_H

#include "pso/system/task/TObject.h"
#include "types.h"

struct SceneMaterialSection;
struct SceneMaterialNode;
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
    u8 scale_index;
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

// Per area, whether players use the auxiliary surface flags there.
struct SurfaceAreaTable { s32 enabled[36]; };

// The areas of the group-selection list, ended by -1 (a struct so it copies by value).
struct GroupSelectionAreaList { s32 areas[8]; };

// The floor b.bin room visibility table: per room, the run of room ids seen from it;
// the s16 room ids follow the entries.
struct RoomVisibilityEntry { s32 id; s32 count; s32 start; };
struct RoomVisibilityTable { u32 pad_00; s32 count; RoomVisibilityEntry entries[1]; };

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
    // Cull mode 0: marks the sections in front of the camera within the map radius visible.
    void cull_sections_within_map_radius();
    void cull_sections();
    // Whether pos lies in front of the camera and no further than depth.
    BOOL is_in_view_depth(Vec *pos, f32 depth, f32);
    // True when the camera is inside the node's model radius or the node is in view depth.
    s32 is_node_visible(SceneMaterialNode *node, f32 depth, f32 near_depth);
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
    void reset_root_flags();
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
};

#include <stddef.h>
LAYOUT_ASSERT(TScene_size, sizeof(TScene) == 0x40);
LAYOUT_ASSERT(TScene_field_1c_offset, offsetof(TScene, visible_section_count) == 0x1C);

void load_scene_collision_file(saddr scene_file_index);
void load_scene_map_file(saddr name);
void load_floor_scene(void);
// The id of the nearest map section whose radius holds pos, or -1.
s32 find_section_at_position(Vec *pos);
SceneMaterialSection *find_scene_room_by_id(s32 id);

extern s32 scene_resource_index;
extern s32 lobby_online_ready_flag;
extern s32 current_lobby_id;
extern s32 area_total;
extern s8 floor_scene_ready_flag;
extern s32 reflection_pass_active;
extern f32 visibility_radius_margin;

s32 is_item_area_enabled(s32 area);

struct SceneMaterialCycle;
struct SceneMaterialStatic;
struct SceneMaterialAnimated;

s32 load_texture_sequence_frame(void *task, SceneMaterialCycle *c);
SceneMaterialNode *resolve_indirect_node_record(void *, SceneMaterialStatic *record);
SceneMaterialNode *resolve_indirect_object_record(void *, SceneMaterialAnimated *record);

s32 player_auxiliary_surfaces_enabled();

#endif
