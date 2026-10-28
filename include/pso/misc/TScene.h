#ifndef PSO_MISC_TSCENE_H
#define PSO_MISC_TSCENE_H

#include "pso/TObject.h"
#include "types.h"

struct SceneMaterialSection;
class TScene : public TObject
{
public:
    u32 m_1c;
    u8 _pad20[0x10];
    u32 m_30;
    u32 m_34;
    u32 m_38;
    u32 m_3c;

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
    static void bind_ending_wall_textures();
    static void set_scene(int a0);
    static void apply_single_screen_state();
    int update_lobby_scene();
    static void set_ready();
    static void reset_counter();
    static int get_status();
    static void set_instance(int a0);
    static void set_active_scene(int a0);
    static void set_id(int a0);
    s32 find_section_at_position();
    static s32 get_player_ctrl_field(u16 arg0);
    void render_map_sections();
    void render_static_map_section(SceneMaterialSection *arg1, s32 arg2);
    void render_animated_map_section(SceneMaterialSection *arg1, s32 arg2);
    void update_room_object_visibility(SceneMaterialSection *room);
    void set_field4();
    void advance_scene_object_animations();
    void init_material_nodes();
    static void create_texture_wave_tasks(s32 arg0);
    void copy_header_and_vec(void* q);
    void initialize_fmt1_materials();
    void initialize_materials();
    void cleanup_materials();
    void cleanup_fmt1_materials();
    void cleanup_fmt2_materials();
    static void create();
    static void load_floor_rel_file(s32 arg0);
    static void load_tam_file(s32 arg0);
    static void free_scene_resources();
    static void load_file_to_buffer(s32 arg0);
    static void load_floor_bin_file(s32 arg0);
    static void load_map_texture_archive(s32 arg0);
    static void load_supplementary_t_rel(s32 arg0);
    static void load_scene_rel_file(s32 arg0);
    static void load_scene_data(s32 arg0);
    static void load_current_floor();
    static void set_indirect_tev(s32 ignored, s32 arg1);
    void draw_field_1c(s32 arg1, s32 arg2, s32 arg3);
    void offset_position(s32 arg1, s32 arg2);
    void apply_uv_offset(s16 arg1, s16 arg2);
    void *destroy_buffers(s16 arg1);
    void *init_buffers(s32 arg1, s32 arg2);
public:
    static int set_scene_callbacks();
};

#include <stddef.h>
typedef char TScene_size[sizeof(TScene) == 0x40 ? 1 : -1];
typedef char TScene_field_1c_offset[offsetof(TScene, m_1c) == 0x1C ? 1 : -1];
typedef char TScene_field_30_offset[offsetof(TScene, m_30) == 0x30 ? 1 : -1];
typedef char TScene_field_34_offset[offsetof(TScene, m_34) == 0x34 ? 1 : -1];
typedef char TScene_field_38_offset[offsetof(TScene, m_38) == 0x38 ? 1 : -1];
typedef char TScene_field_3c_offset[offsetof(TScene, m_3c) == 0x3C ? 1 : -1];

void load_scene_collision_file(s32 scene_file_index);

#endif
