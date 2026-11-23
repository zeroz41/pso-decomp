#ifndef PSO_ITEM_MAG_TITEMMAGSUB_H
#define PSO_ITEM_MAG_TITEMMAGSUB_H
#include "pso/item/TItemHeapObject.h"

struct NJS_OBJECT;
#include "types.h"
#include <stddef.h>
#include <dolphin/mtx/GeoTypes.h>

struct NJS_TEXLIST;

class TObjPlayer;
struct TItemMag;

struct MagNodeOscillationState {
    // Takes over another state, as the mag model table lists it.
    void copy_from(MagNodeOscillationState *src);
    // Flags 0xE0: the node does not oscillate.
    void disable();
    s32 is_disabled();
    // Bits 0-2: the model node it turns; bits 5-7: the axis (x, y, z).
    int node_index();
    int uses_x();
    int uses_y();
    int uses_z();
    s32 get_angle();
    // One frame: value swings between minimum and maximum by speed (bit 3:
    // rising), or with bit 4 set steps by maximum and wraps to minimum.
    void update();

    s8 flags;
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
LAYOUT_ASSERT(MagFollowParametersSize, sizeof(MagFollowParameters)==0x64);
LAYOUT_ASSERT(MagOscillationStateSize, sizeof(MagNodeOscillationState)==8);
class TItemMagSub : public TItemHeapObject {
public:
    TItemMag *item;
    TObjPlayer *owner;
    void *model, *animation;
    NJS_TEXLIST *textures;
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
    Vec follow_anchor;
    f32 translation_offset[3];
    f32 material_parameters[4];
    f32 owner_height_scale;
    MagNodeOscillationState oscillations[2];
    Vec cached_position;

    static TItemMagSub *drawing;
    static s32 drawn_node;

    static void clear_optional_oscillation_flag(void *sub);
    void reset_oscillation(s32 from, s32 to);
    void apply_node_oscillation(void* node);
    static void update_node_oscillation(NJS_OBJECT *node);
    s32 get_world_position(Vec *output);
    void apply_placement_matrix();
    s32 resolve_owner_heading();
    void update_special_pose();
    void update_transition();
    void update_follow();
    void reset();
    void clear_growth_flag();
    void clear_flags(u32 v);
    void set_growth_flag();
    void set_flags(u32 value);
    void set_node_id(s32 index, s32 id);
    void set_material_node(s32 node, void* parameters);
    void set_model(void* model, NJS_TEXLIST *textures, void* animation);
    void scale_owner_height(f32 factor);
    int is_growth_inactive();
    u32 test_flags(u32 mask);
    void release_model_and_destroy();
    void set_motion_type(s32 type);
    void transition_motion_type(s32 type);
    TItemMagSub(TObjPlayer *owner, TItemMag *item);
    virtual ~TItemMagSub();
    virtual void run_task();
    virtual void render();
    virtual void render_shadows();
};
LAYOUT_ASSERT(MagChildSize, sizeof(TItemMagSub)==0xE8);
LAYOUT_ASSERT(MagChild_item, offsetof(TItemMagSub,item)==0x1C);
LAYOUT_ASSERT(MagChild_owner, offsetof(TItemMagSub,owner)==0x20);
LAYOUT_ASSERT(MagChild_model, offsetof(TItemMagSub,model)==0x24);
LAYOUT_ASSERT(MagChild_animation, offsetof(TItemMagSub,animation)==0x28);
LAYOUT_ASSERT(MagChild_textures, offsetof(TItemMagSub,textures)==0x2C);
LAYOUT_ASSERT(MagChild_motion, offsetof(TItemMagSub,motion)==0x30);
LAYOUT_ASSERT(MagChild_rotation_delta, offsetof(TItemMagSub,rotation_delta)==0x34);
LAYOUT_ASSERT(MagChild_rotation_phase, offsetof(TItemMagSub,rotation_phase)==0x40);
LAYOUT_ASSERT(MagChild_translation_phase, offsetof(TItemMagSub,translation_phase)==0x4C);
LAYOUT_ASSERT(MagChild_drift_phase, offsetof(TItemMagSub,drift_phase)==0x58);
LAYOUT_ASSERT(MagChild_flags, offsetof(TItemMagSub,flags)==0x64);
LAYOUT_ASSERT(MagChild_selected_node, offsetof(TItemMagSub,selected_node)==0x6C);
LAYOUT_ASSERT(MagChild_node_ids, offsetof(TItemMagSub,node_ids)==0x70);
LAYOUT_ASSERT(MagChild_transition_frame, offsetof(TItemMagSub,transition_frame)==0x7C);
LAYOUT_ASSERT(MagChild_animation_frame, offsetof(TItemMagSub,animation_frame)==0x80);
LAYOUT_ASSERT(MagChild_animation_length, offsetof(TItemMagSub,animation_length)==0x84);
LAYOUT_ASSERT(MagChild_drift_offset, offsetof(TItemMagSub,drift_offset)==0x94);
LAYOUT_ASSERT(MagChild_follow_anchor, offsetof(TItemMagSub,follow_anchor)==0xA0);
LAYOUT_ASSERT(MagChild_translation_offset, offsetof(TItemMagSub,translation_offset)==0xAC);
LAYOUT_ASSERT(MagChild_material_parameters, offsetof(TItemMagSub,material_parameters)==0xB8);
LAYOUT_ASSERT(MagChild_owner_height_scale, offsetof(TItemMagSub,owner_height_scale)==0xC8);
LAYOUT_ASSERT(MagChild_oscillations, offsetof(TItemMagSub,oscillations)==0xCC);
LAYOUT_ASSERT(MagChild_cached_position, offsetof(TItemMagSub,cached_position)==0xDC);
#endif
