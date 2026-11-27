#ifndef PSO_SYSTEM_SCENE_TSCENEMATERIAL_H
#define PSO_SYSTEM_SCENE_TSCENEMATERIAL_H
#include "types.h"
#include "pso/render/GinjaModel.h"
#include "pso/system/NinjaTypes.h"
// A scene model: a Ginja model followed by its bounding sphere.
struct SceneModel {GinjaModel model;f32 center[3];f32 radius;};
class TEffIndirect;
class UvScrollBuffer;
// The indirect-texture record of a flag-0x200 scene object: the model it draws and
// the effect, sampler and scale of its indirect stage (from the material info file).
struct SceneIndirectRecord {NJS_OBJECT* node;TEffIndirect* effect;u32 sampler;u16 material_id;u8 scale;u8 effect_id;};
struct SceneMaterialUv {u16 id,texture;f32 u,v,du,dv;UvScrollBuffer* buffer;};
struct SceneMaterialCycle {u16 id,reserved,texture;s16 index;s32 timer;};
struct SceneMaterialStatic {union {NJS_OBJECT* node;SceneIndirectRecord* indirect;};SceneMaterialUv* uv;SceneMaterialCycle* cycle;u32 flags;};
struct SceneMaterialAnimated {union {NJS_OBJECT* node;SceneIndirectRecord* indirect;};NJS_MOTION* motion;u32 unknown;f32 frame,speed;SceneMaterialUv* uv;SceneMaterialCycle* cycle;u32 flags;};
struct SceneMaterialSection {s32 id;Vec position;s32 angles[3];f32 radius;SceneMaterialStatic* objects;SceneMaterialAnimated* animated;s32 count,animatedCount;u32 flags;};
// texlist: the texture list the scene's model pass hands to set_texture_list.
struct SceneMaterialRoot {u32 format,flags;s16 count,reserved;f32 radius;SceneMaterialSection* sections;NJS_TEXLIST* texlist;};
// The current map's scene, loaded from its relocatable file.
extern SceneMaterialRoot *scene_material_root;
LAYOUT_ASSERT(SceneIndirectRecord_size, sizeof(SceneIndirectRecord)==0x10);
LAYOUT_ASSERT(SceneMaterialUv_size, sizeof(SceneMaterialUv)==24);
LAYOUT_ASSERT(SceneMaterialStatic_size, sizeof(SceneMaterialStatic)==16);
LAYOUT_ASSERT(SceneMaterialAnimated_size, sizeof(SceneMaterialAnimated)==32);
LAYOUT_ASSERT(SceneMaterialSection_size, sizeof(SceneMaterialSection)==52);
LAYOUT_ASSERT(SceneModel_size, sizeof(SceneModel)==0x24);
#endif
