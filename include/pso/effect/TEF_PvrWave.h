#ifndef PSO_UNK_TEF_PVRWAVE_H
#define PSO_UNK_TEF_PVRWAVE_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/render/GinjaMaterialState.h"

class TUnk_804C57E0;
struct SceneMaterialRoot;

// A scene texture animated by a texture wave: while it lives, entry
// texture_index of the scene's texture list shows the wave's texture.
class TEF_PvrWave : public TObject {
public:
    TEF_PvrWave(TObject *parent, u8 *image, s32 size, s32 texture_index);
    virtual ~TEF_PvrWave();
    virtual void render();
    virtual void run_task();

    TUnk_804C57E0 *wave;
    s32 texture_index;
    GinjaTextureList texture_list;  // the wave's one-entry texture list
    GinjaTextureEntry saved_entry;  // the scene entry it replaced, put back on destruction
};
LAYOUT_ASSERT(TEF_PvrWave_size, sizeof(TEF_PvrWave) == 0x38);

SceneMaterialRoot *get_scene_material_root();

#endif
