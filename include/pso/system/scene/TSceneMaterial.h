#ifndef PSO_SYSTEM_SCENE_TSCENEMATERIAL_H
#define PSO_SYSTEM_SCENE_TSCENEMATERIAL_H
#include "types.h"
#include "pso/render/GinjaModel.h"
#include "pso/system/NinjaTypes.h"
// A scene model: a Ginja model followed by its bounding sphere.
struct SceneModel {GinjaModel model;f32 center[3];f32 radius;};
// The head of a scene record's Ninja object: its model, position and rotation.
struct SceneMaterialNode {u32 flags;SceneModel* model;f32 position[3];s32 angles[3];};
struct SceneMaterialUv {u16 id,texture;f32 u,v,du,dv;void* buffer;};
struct SceneMaterialCycle {u16 id,reserved,texture;s16 index;s32 timer;};
struct SceneMaterialStatic {SceneMaterialNode* node;SceneMaterialUv* uv;SceneMaterialCycle* cycle;u32 flags;};
struct SceneMaterialAnimated {SceneMaterialNode* node;NJS_MOTION* motion;u32 unknown;f32 frame,speed;SceneMaterialUv* uv;SceneMaterialCycle* cycle;u32 flags;};
struct SceneMaterialSection {s32 id;f32 position[3];s32 angles[3];f32 radius;SceneMaterialStatic* objects;SceneMaterialAnimated* animated;s32 count,animatedCount;u32 flags;};
// texlist: the texture list the scene's model pass hands to TObjFish::set_global_param.
struct SceneMaterialRoot {u32 format,flags;s16 count,reserved;f32 radius;SceneMaterialSection* sections;uaddr texlist;};
// The current map's scene, loaded from its relocatable file.
extern SceneMaterialRoot *scene_material_root;
LAYOUT_ASSERT(SceneMaterialUv_size, sizeof(SceneMaterialUv)==24);
LAYOUT_ASSERT(SceneMaterialStatic_size, sizeof(SceneMaterialStatic)==16);
LAYOUT_ASSERT(SceneMaterialAnimated_size, sizeof(SceneMaterialAnimated)==32);
LAYOUT_ASSERT(SceneMaterialSection_size, sizeof(SceneMaterialSection)==52);
LAYOUT_ASSERT(SceneModel_size, sizeof(SceneModel)==0x24);
#endif
