#ifndef PSO_ITEM_TITEMMAGSUB_H
#define PSO_ITEM_TITEMMAGSUB_H
#include "pso/item/TItemHeapObject.h"
#include "types.h"
#include <stddef.h>

struct MagDrawOwner { u8 prefix[0x2FC]; f32 center[3]; };
struct MagNodeOscillationState {
    // Takes over another state, as the mag model table lists it.
    void copy_from(MagNodeOscillationState *src);

    u8 flags;
    s8 speed;
    s16 value, minimum, maximum;
};
struct MagAxisOscillationParameters {
    f32 amplitude;
    u32 unknown04;
    s32 phase_offset;
    s32 phase_velocity;
};
struct MagFollowParameters {
    s32 joint_index;
    u8 unknown04;
    s8 rotation_offset[3];
    f32 follow_scale;
    u8 moving_pitch;
    s8 drift_angle_offset[3];
    f32 drift_amplitude[3];
    s32 base_rotation[3];
    s32 drift_velocity[3];
    MagAxisOscillationParameters translation[3];
};
typedef char MagFollowParametersSize[sizeof(MagFollowParameters)==0x64?1:-1];
typedef char MagOscillationStateSize[sizeof(MagNodeOscillationState)==8?1:-1];
class TItemMagSub : public TItemHeapObject {
public:
    void* item;
    MagDrawOwner* owner;
    void *model, *animation;
    u32 textures;
    MagFollowParameters* motion;
    s32 rotation_delta[3];
    s32 rotation_phase[3];
    s32 translation_phase[3];
    s32 drift_phase[3];
    u32 flags;
    s32 motion_type;
    s32 selected_node;
    s32 node_ids[3];
    f32 transition_frame;
    f32 animation_frame, animation_length;
    u8 unknown88[12];
    f32 drift_offset[3];
    f32 follow_anchor[3];
    f32 translation_offset[3];
    f32 material_parameters[4];
    f32 owner_height_scale;
    MagNodeOscillationState oscillations[2];
    f32 cached_position[3];

    static void clear_optional_oscillation_flag(void* arg0);
    void reset_oscillation();
    void apply_node_oscillation(void* node);
    static void update_node_oscillation(void* node);
    s32 get_world_position(void* output);
    void apply_placement_matrix();
    s32 resolve_owner_heading();
    void update_special_pose();
    void update_transition();
    void update_follow();
    void reset();
    void clear_growth_flag();
    void clear_flags(u32 v);
    int set_growth_flag();
    void set_flags(u32 value);
    void set_node_id(s32 index, s32 id);
    void set_material_node(s32 node, void* parameters);
    void set_model(void* model, u32 textures, void* animation);
    void scale_owner_height(f32 factor);
    int is_growth_inactive();
    int test_flags(u32 mask);
    void release_model_and_destroy();
    void set_motion_type(s32 type);
    void transition_motion_type(s32 type);
    TItemMagSub(MagDrawOwner* player, TObject* item);
    virtual ~TItemMagSub();
    virtual void run_task();
    virtual void render();
    virtual void render_shadows();
};
typedef char MagDrawOwnerCenter[offsetof(MagDrawOwner,center)==0x2FC?1:-1];
typedef char MagChildSize[sizeof(TItemMagSub)==0xE8?1:-1];
typedef char MagChild_item[offsetof(TItemMagSub,item)==0x1C?1:-1];
typedef char MagChild_owner[offsetof(TItemMagSub,owner)==0x20?1:-1];
typedef char MagChild_model[offsetof(TItemMagSub,model)==0x24?1:-1];
typedef char MagChild_animation[offsetof(TItemMagSub,animation)==0x28?1:-1];
typedef char MagChild_textures[offsetof(TItemMagSub,textures)==0x2C?1:-1];
typedef char MagChild_motion[offsetof(TItemMagSub,motion)==0x30?1:-1];
typedef char MagChild_rotation_delta[offsetof(TItemMagSub,rotation_delta)==0x34?1:-1];
typedef char MagChild_rotation_phase[offsetof(TItemMagSub,rotation_phase)==0x40?1:-1];
typedef char MagChild_translation_phase[offsetof(TItemMagSub,translation_phase)==0x4C?1:-1];
typedef char MagChild_drift_phase[offsetof(TItemMagSub,drift_phase)==0x58?1:-1];
typedef char MagChild_flags[offsetof(TItemMagSub,flags)==0x64?1:-1];
typedef char MagChild_selected_node[offsetof(TItemMagSub,selected_node)==0x6C?1:-1];
typedef char MagChild_node_ids[offsetof(TItemMagSub,node_ids)==0x70?1:-1];
typedef char MagChild_transition_frame[offsetof(TItemMagSub,transition_frame)==0x7C?1:-1];
typedef char MagChild_animation_frame[offsetof(TItemMagSub,animation_frame)==0x80?1:-1];
typedef char MagChild_animation_length[offsetof(TItemMagSub,animation_length)==0x84?1:-1];
typedef char MagChild_drift_offset[offsetof(TItemMagSub,drift_offset)==0x94?1:-1];
typedef char MagChild_follow_anchor[offsetof(TItemMagSub,follow_anchor)==0xA0?1:-1];
typedef char MagChild_translation_offset[offsetof(TItemMagSub,translation_offset)==0xAC?1:-1];
typedef char MagChild_material_parameters[offsetof(TItemMagSub,material_parameters)==0xB8?1:-1];
typedef char MagChild_owner_height_scale[offsetof(TItemMagSub,owner_height_scale)==0xC8?1:-1];
typedef char MagChild_oscillations[offsetof(TItemMagSub,oscillations)==0xCC?1:-1];
typedef char MagChild_cached_position[offsetof(TItemMagSub,cached_position)==0xDC?1:-1];
#endif
