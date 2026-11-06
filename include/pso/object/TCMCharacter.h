#ifndef PSO_OBJECT_TCMCHARACTER_H
#define PSO_OBJECT_TCMCHARACTER_H
#include "pso/object/base/TObjMotion.h"
#include "pso/ui/charcreate/CharacterCreationModels.h"
class TCMCharacter : public TObjMotion {
public:
    virtual ~TCMCharacter();
    virtual void run_task();
    void apply_character_appearance();
    void update_chara_preview();
    void reset_model_parts();
    s32 bind_model_parts(u32 *selected, const char **names, CreationModelPart *parts, s32 part, s32 model_index);
    void load_model_parts();
    s32 shape_rel;
    s32 shape_rel_size;
    s32 shape_rel_ready;
    u32 unknown108;
};
typedef char TCMCharacterSize[sizeof(TCMCharacter)==0x10C?1:-1];
typedef char CreationShapeRelOffset[offsetof(TCMCharacter,shape_rel)==0xFC?1:-1];
typedef char CreationShapeRelSizeOffset[offsetof(TCMCharacter,shape_rel_size)==0x100?1:-1];
typedef char CreationShapeReadyOffset[offsetof(TCMCharacter,shape_rel_ready)==0x104?1:-1];
#endif
