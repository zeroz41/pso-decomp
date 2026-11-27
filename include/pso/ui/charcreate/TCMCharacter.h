#ifndef PSO_UI_CHARCREATE_TCMCHARACTER_H
#define PSO_UI_CHARCREATE_TCMCHARACTER_H
#include "pso/object/base/TObjMotion.h"
#include "pso/ui/charcreate/CharacterCreationModels.h"
class TCMCharacter : public TObjMotion {
public:
    static const char *name;
    TCMCharacter(TObject *parent);
    virtual ~TCMCharacter();
    virtual void run_task();
    virtual void render();
    void free_shape_rel();
    void draw_player_model();
    void draw_creation_figure();
    void apply_character_appearance();
    void update_chara_preview();
    void reset_model_parts();
    s32 bind_model_parts(NJS_OBJECT **selected, const char **names, CreationModelPart *parts, s32 part, s32 model_index);
    void load_model_parts();
    void *shape_rel;
    s32 shape_rel_size;
    s32 shape_rel_ready;
    u32 pad_108;
};
LAYOUT_ASSERT(TCMCharacterSize, sizeof(TCMCharacter)==0x10C);
LAYOUT_ASSERT(CreationShapeRelOffset, offsetof(TCMCharacter,shape_rel)==0xFC);
LAYOUT_ASSERT(CreationShapeRelSizeOffset, offsetof(TCMCharacter,shape_rel_size)==0x100);
LAYOUT_ASSERT(CreationShapeReadyOffset, offsetof(TCMCharacter,shape_rel_ready)==0x104);
// Blends the character-creation proportion morph shapes for one point.
void blend_creation_proportion_shapes(f32 *point);
void prefetch_creation_textures(s32 part);

s32 is_char_select_active();

#endif
