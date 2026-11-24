#include "pso/boss/galgryphon/TObjBoss5Pillar_8028B714.h"
#include "pso/ui/charcreate/CharacterPreview.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/system/memory.h"
#include "pso/ui/charcreate/TChCrLoadReq.h"

CharacterPreview *free_chcr_resources(CharacterPreview *data, s16 release_storage) {
    if (data != NULL) {
        if (data->request != NULL && data->is_unloaded() == 0) {
            delete data->request;
            data->request = NULL;
        }
        if (data->head_textures.present != 0) {
            if (!(data->completion_flags & 1)) {
                free_texture_if_valid(&data->head_textures.list);
            }
            data->head_textures.present = 0;
        }
        if (data->other_textures.present != 0) {
            if (!(data->completion_flags & 2)) {
                free_texture_if_valid(&data->other_textures.list);
            }
            data->other_textures.present = 0;
        }
        if (data->body_textures.present != 0) {
            if (!(data->completion_flags & 4)) {
                free_texture_if_valid(&data->body_textures.list);
            }
            data->body_textures.present = 0;
        }
        if (release_storage > 0) {
            ::operator delete(data);
        }
    }
    return data;
}
