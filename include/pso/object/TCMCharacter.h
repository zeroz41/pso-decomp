#ifndef PSO_OBJECT_TCMCHARACTER_H
#define PSO_OBJECT_TCMCHARACTER_H
#include "pso/object/base/TObjMotion.h"
#include "pso/ui/charcreate/CharacterCreationModels.h"
class TCMCharacter : public TObjMotion {
public:
    TCMCharacter(TObject *parent);
    virtual ~TCMCharacter();
    virtual void run_task();
    virtual void render();
    void free_field_FC();
    void draw_player_model();
    void draw_creation_figure();
    void apply_character_appearance();
    void update_chara_preview();
    void reset_model_parts();
    s32 bind_model_parts(uaddr *selected, const char **names, CreationModelPart *parts, s32 part, s32 model_index);
    void load_model_parts();
    void *shape_rel;
    s32 shape_rel_size;
    s32 shape_rel_ready;
    u32 unknown108;
};
LAYOUT_ASSERT(TCMCharacterSize, sizeof(TCMCharacter)==0x10C);
LAYOUT_ASSERT(CreationShapeRelOffset, offsetof(TCMCharacter,shape_rel)==0xFC);
LAYOUT_ASSERT(CreationShapeRelSizeOffset, offsetof(TCMCharacter,shape_rel_size)==0x100);
LAYOUT_ASSERT(CreationShapeReadyOffset, offsetof(TCMCharacter,shape_rel_ready)==0x104);
#endif
