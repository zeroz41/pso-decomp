#ifndef PSO_SYSTEM_SCENE_TSCENEMATERIAL_H
#define PSO_SYSTEM_SCENE_TSCENEMATERIAL_H
#include "types.h"
struct SceneMaterialNode {u32 flags;void* model;};
struct SceneMaterialUv {u16 id,texture;f32 u,v,du,dv;void* buffer;};
struct SceneMaterialCycle {u16 id,reserved,texture,index;s32 timer;};
struct SceneMaterialStatic {SceneMaterialNode* node;SceneMaterialUv* uv;SceneMaterialCycle* cycle;u32 flags;};
struct SceneMaterialAnimated {SceneMaterialNode* node;void* motion;u32 unknown;f32 frame,speed;SceneMaterialUv* uv;SceneMaterialCycle* cycle;u32 flags;};
struct SceneMaterialSection {s32 id;f32 position[3];s32 angles[3];f32 radius;SceneMaterialStatic* objects;SceneMaterialAnimated* animated;s32 count,animatedCount;u32 flags;};
struct SceneMaterialRoot {u32 format,flags;s16 count,reserved;f32 radius;SceneMaterialSection* sections;};
typedef char SceneMaterialUv_size[sizeof(SceneMaterialUv)==24?1:-1];
typedef char SceneMaterialStatic_size[sizeof(SceneMaterialStatic)==16?1:-1];
typedef char SceneMaterialAnimated_size[sizeof(SceneMaterialAnimated)==32?1:-1];
typedef char SceneMaterialSection_size[sizeof(SceneMaterialSection)==52?1:-1];
#endif
