#include "types.h"
#include "pso/effect/TEF_PvrWave.h"
#include "pso/unk/TTextureWave.h"
#include "pso/system/scene/TSceneMaterial.h"

extern "C" void *construct_texture_wave(void *wave, GinjaTextureList *texture_list);

TEF_PvrWave::~TEF_PvrWave() {
    GinjaTextureList *list;
    list = reinterpret_cast<GinjaTextureList *>(get_scene_material_root()->texlist);
    list->entries[texture_index].texture = saved_entry.texture;
    list->entries[texture_index].value04 = saved_entry.value04;
    list->entries[texture_index].name = saved_entry.name;
    delete wave;
}

const char *TEF_PvrWave::class_name = "TEF_PvrWave";

TEF_PvrWave::TEF_PvrWave(TObject *parent, u8 *image, s32 size, s32 index) : TObject(parent) {
    void *memory;
    GinjaTextureList *list;
    m_name = class_name;
    texture_index = index;
    memory = ::operator new(sizeof(TTextureWave));
    if (memory != NULL) {
        memory = construct_texture_wave(memory, &texture_list);
    }
    wave = (TTextureWave *)memory;
    wave->init_image_buffer(image, size);
    list = reinterpret_cast<GinjaTextureList *>(get_scene_material_root()->texlist);
    saved_entry.texture = list->entries[index].texture;
    saved_entry.value04 = list->entries[index].value04;
    saved_entry.name = list->entries[index].name;
    list->entries[index].texture = texture_list.entries->texture;
    list->entries[index].value04 = texture_list.entries->value04;
    list->entries[index].name = texture_list.entries->name;
}

SceneMaterialRoot *get_scene_material_root() {
    return scene_material_root;
}
