#include "types.h"
#include "pso/effect/TEF_PvrWave.h"
#include "pso/unk/TTextureWave.h"
#include "pso/system/scene/TSceneMaterial.h"

TEF_PvrWave::~TEF_PvrWave() {
    NJS_TEXLIST *list;
    list = reinterpret_cast<NJS_TEXLIST *>(get_scene_material_root()->texlist);
    list->textures[texture_index].texture = saved_entry.texture;
    list->textures[texture_index].attr = saved_entry.attr;
    list->textures[texture_index].filename = saved_entry.filename;
    delete wave;
}

const char *TEF_PvrWave::class_name = "TEF_PvrWave";

TEF_PvrWave::TEF_PvrWave(TObject *parent, u8 *image, s32 size, s32 index) : TObject(parent) {
    NJS_TEXLIST *list;
    m_name = class_name;
    texture_index = index;
    wave = new TTextureWave(&texture_list);
    wave->init_image_buffer(image, size);
    list = reinterpret_cast<NJS_TEXLIST *>(get_scene_material_root()->texlist);
    saved_entry.texture = list->textures[index].texture;
    saved_entry.attr = list->textures[index].attr;
    saved_entry.filename = list->textures[index].filename;
    list->textures[index].texture = texture_list.textures->texture;
    list->textures[index].attr = texture_list.textures->attr;
    list->textures[index].filename = texture_list.textures->filename;
}

SceneMaterialRoot *get_scene_material_root() {
    return scene_material_root;
}
