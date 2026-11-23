#ifndef PSO_UI_CHARCREATE_CHARACTERCREATIONMODELS_H
#define PSO_UI_CHARCREATE_CHARACTERCREATIONMODELS_H

#include "types.h"
#include "pso/ui/charcreate/CharacterAppearance.h"

struct CreationModelPart {
    u32 present;
    uaddr model;
};

extern "C" {
extern CreationModelPart creation_hair_model_parts[10];
extern CreationModelPart creation_cap_model_parts[10];
extern CreationModelPart creation_head_model_parts[5];
extern u32 creation_models_ready;
extern uaddr chara_select_hair_node_a;
extern uaddr chara_select_hair_node_b;
extern uaddr chara_select_head_node;
extern saddr chara_select_preview_resource;
}
extern CharacterAppearanceFields *creation_player_character;

class TCMCharacter;
// The character creation figure, while one exists.
extern TCMCharacter *creation_figure_object;
// Its turn about Y.
extern u32 creation_figure_rotation_y;
// 1 once the figure is drawn, 0 while its resources are loading.
extern int char_creation_figure_draw_flag;
// 0 loading, 1 waiting on the figure's resources, 2 ready.
extern s32 creation_resource_ready_state;
int get_char_creation_figure_draw_flag(void);
// Plays creation motion `motion` on the figure.
void request_creation_motion(s32 motion);

#endif
