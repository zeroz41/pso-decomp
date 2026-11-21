#ifndef PSO_UI_CHARCREATE_CHARACTERAPPEARANCE_H
#define PSO_UI_CHARCREATE_CHARACTERAPPEARANCE_H
#include "types.h"
#include <stddef.h>

// The player's visual record (same 0x50-byte layout as disp_data_part2 in TPlyDispData.h, whose
// names nameColor/extraModel/version follow).
struct CharacterAppearanceFields {
    char name[0x10];
    u8 pad_10[0x18 - 0x10];
    u32 nameColor;
    u8 extraModel;
    u8 pad_1D[0x30 - 0x1D];
    s8 section;
    s8 classId;
    s8 flags;
    u8 version;
    u32 classFlags;
    s16 costume, skin, face, head, hair, red, green, blue;
    f32 width, height;
};
LAYOUT_ASSERT(CharacterAppearanceFields_size, sizeof(CharacterAppearanceFields) == 0x50);
LAYOUT_ASSERT(CharacterAppearanceFields_head, offsetof(CharacterAppearanceFields, head) == 0x3e);
LAYOUT_ASSERT(CharacterAppearanceFields_rgb, offsetof(CharacterAppearanceFields, red) == 0x42);

struct CreationModelNodeState { void *node; u32 flags; };
struct CreationHeadModelStates { CreationModelNodeState nodes[5]; };
struct CreationBodyModelStates { CreationModelNodeState nodes[65]; };
LAYOUT_ASSERT(CreationHeadModelStates_size, sizeof(CreationHeadModelStates) == 0x28);
LAYOUT_ASSERT(CreationBodyModelStates_size, sizeof(CreationBodyModelStates) == 0x208);

f32 calc_character_height(CharacterAppearanceFields *appearance);

extern "C" {
// The appearance may come from a live record or a serialized player save.
s32 character_display_index(uaddr appearance_record);
void TCharaMaking__draw_colored_hair(f32 alpha, saddr model, CharacterAppearanceFields *appearance, s32 specialColor);
void TCharaMaking__bind_head_shape_nodes(CharacterAppearanceFields *appearance, void *model);
void TCharaMaking__bind_body_shape_nodes(CharacterAppearanceFields *appearance, void *model);
}
#endif
