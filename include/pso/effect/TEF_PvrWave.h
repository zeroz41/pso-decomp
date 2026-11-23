#ifndef PSO_UNK_TEF_PVRWAVE_H
#define PSO_UNK_TEF_PVRWAVE_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/render/GinjaMaterialState.h"

class TTextureWave;
struct SceneMaterialRoot;

// A scene texture animated by a texture wave: while it lives, entry
// texture_index of the scene's texture list shows the wave's texture.
class TEF_PvrWave : public TObject {
public:
    static const char *class_name;
    TEF_PvrWave(TObject *parent, u8 *image, s32 size, s32 texture_index);
    virtual ~TEF_PvrWave();
    virtual void render();
    virtual void run_task();

    TTextureWave *wave;
    s32 texture_index;
    NJS_TEXLIST texture_list;  // the wave's one-entry texture list
    NJS_TEXNAME saved_entry;  // the scene entry it replaced, put back on destruction
};
LAYOUT_ASSERT(TEF_PvrWave_size, sizeof(TEF_PvrWave) == 0x38);

SceneMaterialRoot *get_scene_material_root();

#endif
