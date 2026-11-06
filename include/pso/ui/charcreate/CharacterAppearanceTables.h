#ifndef PSO_UI_CHARCREATE_CHARACTERAPPEARANCETABLES_H
#define PSO_UI_CHARCREATE_CHARACTERAPPEARANCETABLES_H
#include "types.h"
#include "pso/ui/charcreate/CharacterAppearance.h"

struct CharacterTextureList { const char **entries; s32 count; };
struct CharacterTextureArchive {
    s32 archiveId; s32 count; const char *archiveName; const char **textureNames;
};
struct CharacterClassAppearance {
    s16 counts[8];
    const char **hairModels; const char **capModels; const char **headModels;
    const char *bodyModel;
    CharacterTextureList **hairTextures; CharacterTextureList **headTextures;
    CharacterTextureList *bodyTextures;
};
typedef char CharacterTextureList_size[sizeof(CharacterTextureList) == 8 ? 1 : -1];
typedef char CharacterTextureArchive_size[sizeof(CharacterTextureArchive) == 16 ? 1 : -1];
typedef char CharacterClassAppearance_size[sizeof(CharacterClassAppearance) == 44 ? 1 : -1];

typedef char CharacterTextureList_entries_offset[offsetof(CharacterTextureList, entries) == 0x0 ? 1 : -1];
typedef char CharacterTextureList_count_offset[offsetof(CharacterTextureList, count) == 0x4 ? 1 : -1];
typedef char CharacterTextureArchive_archiveId_offset[offsetof(CharacterTextureArchive, archiveId) == 0x0 ? 1 : -1];
typedef char CharacterTextureArchive_count_offset[offsetof(CharacterTextureArchive, count) == 0x4 ? 1 : -1];
typedef char CharacterTextureArchive_archiveName_offset[offsetof(CharacterTextureArchive, archiveName) == 0x8 ? 1 : -1];
typedef char CharacterTextureArchive_textureNames_offset[offsetof(CharacterTextureArchive, textureNames) == 0xC ? 1 : -1];
typedef char CharacterClassAppearance_counts_offset[offsetof(CharacterClassAppearance, counts) == 0x0 ? 1 : -1];
typedef char CharacterClassAppearance_hairModels_offset[offsetof(CharacterClassAppearance, hairModels) == 0x10 ? 1 : -1];
typedef char CharacterClassAppearance_capModels_offset[offsetof(CharacterClassAppearance, capModels) == 0x14 ? 1 : -1];
typedef char CharacterClassAppearance_headModels_offset[offsetof(CharacterClassAppearance, headModels) == 0x18 ? 1 : -1];
typedef char CharacterClassAppearance_bodyModel_offset[offsetof(CharacterClassAppearance, bodyModel) == 0x1C ? 1 : -1];
typedef char CharacterClassAppearance_hairTextures_offset[offsetof(CharacterClassAppearance, hairTextures) == 0x20 ? 1 : -1];
typedef char CharacterClassAppearance_headTextures_offset[offsetof(CharacterClassAppearance, headTextures) == 0x24 ? 1 : -1];
typedef char CharacterClassAppearance_bodyTextures_offset[offsetof(CharacterClassAppearance, bodyTextures) == 0x28 ? 1 : -1];
typedef char CharacterAppearanceFields_name_offset[offsetof(CharacterAppearanceFields, name) == 0x0 ? 1 : -1];
typedef char CharacterAppearanceFields_section_offset[offsetof(CharacterAppearanceFields, section) == 0x30 ? 1 : -1];
typedef char CharacterAppearanceFields_classId_offset[offsetof(CharacterAppearanceFields, classId) == 0x31 ? 1 : -1];
typedef char CharacterAppearanceFields_flags_offset[offsetof(CharacterAppearanceFields, flags) == 0x32 ? 1 : -1];
typedef char CharacterAppearanceFields_spare_offset[offsetof(CharacterAppearanceFields, spare) == 0x33 ? 1 : -1];
typedef char CharacterAppearanceFields_classFlags_offset[offsetof(CharacterAppearanceFields, classFlags) == 0x34 ? 1 : -1];
typedef char CharacterAppearanceFields_costume_offset[offsetof(CharacterAppearanceFields, costume) == 0x38 ? 1 : -1];
typedef char CharacterAppearanceFields_skin_offset[offsetof(CharacterAppearanceFields, skin) == 0x3A ? 1 : -1];
typedef char CharacterAppearanceFields_face_offset[offsetof(CharacterAppearanceFields, face) == 0x3C ? 1 : -1];
typedef char CharacterAppearanceFields_head_offset[offsetof(CharacterAppearanceFields, head) == 0x3E ? 1 : -1];
typedef char CharacterAppearanceFields_hair_offset[offsetof(CharacterAppearanceFields, hair) == 0x40 ? 1 : -1];
typedef char CharacterAppearanceFields_red_offset[offsetof(CharacterAppearanceFields, red) == 0x42 ? 1 : -1];
typedef char CharacterAppearanceFields_green_offset[offsetof(CharacterAppearanceFields, green) == 0x44 ? 1 : -1];
typedef char CharacterAppearanceFields_blue_offset[offsetof(CharacterAppearanceFields, blue) == 0x46 ? 1 : -1];
typedef char CharacterAppearanceFields_width_offset[offsetof(CharacterAppearanceFields, width) == 0x48 ? 1 : -1];
typedef char CharacterAppearanceFields_height_offset[offsetof(CharacterAppearanceFields, height) == 0x4C ? 1 : -1];

extern "C" {
extern CharacterTextureArchive player_class_texture_archive_table[19];
extern CharacterClassAppearance class_appearance_table[19];
extern CharacterAppearanceFields class_appearance_preset_table[13];
}
#endif
