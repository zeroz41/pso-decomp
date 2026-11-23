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
LAYOUT_ASSERT(CharacterTextureList_size, sizeof(CharacterTextureList) == 8);
LAYOUT_ASSERT(CharacterTextureArchive_size, sizeof(CharacterTextureArchive) == 16);
LAYOUT_ASSERT(CharacterClassAppearance_size, sizeof(CharacterClassAppearance) == 44);

LAYOUT_ASSERT(CharacterTextureList_entries_offset, offsetof(CharacterTextureList, entries) == 0x0);
LAYOUT_ASSERT(CharacterTextureList_count_offset, offsetof(CharacterTextureList, count) == 0x4);
LAYOUT_ASSERT(CharacterTextureArchive_archiveId_offset, offsetof(CharacterTextureArchive, archiveId) == 0x0);
LAYOUT_ASSERT(CharacterTextureArchive_count_offset, offsetof(CharacterTextureArchive, count) == 0x4);
LAYOUT_ASSERT(CharacterTextureArchive_archiveName_offset, offsetof(CharacterTextureArchive, archiveName) == 0x8);
LAYOUT_ASSERT(CharacterTextureArchive_textureNames_offset, offsetof(CharacterTextureArchive, textureNames) == 0xC);
LAYOUT_ASSERT(CharacterClassAppearance_counts_offset, offsetof(CharacterClassAppearance, counts) == 0x0);
LAYOUT_ASSERT(CharacterClassAppearance_hairModels_offset, offsetof(CharacterClassAppearance, hairModels) == 0x10);
LAYOUT_ASSERT(CharacterClassAppearance_capModels_offset, offsetof(CharacterClassAppearance, capModels) == 0x14);
LAYOUT_ASSERT(CharacterClassAppearance_headModels_offset, offsetof(CharacterClassAppearance, headModels) == 0x18);
LAYOUT_ASSERT(CharacterClassAppearance_bodyModel_offset, offsetof(CharacterClassAppearance, bodyModel) == 0x1C);
LAYOUT_ASSERT(CharacterClassAppearance_hairTextures_offset, offsetof(CharacterClassAppearance, hairTextures) == 0x20);
LAYOUT_ASSERT(CharacterClassAppearance_headTextures_offset, offsetof(CharacterClassAppearance, headTextures) == 0x24);
LAYOUT_ASSERT(CharacterClassAppearance_bodyTextures_offset, offsetof(CharacterClassAppearance, bodyTextures) == 0x28);
LAYOUT_ASSERT(CharacterAppearanceFields_name_offset, offsetof(CharacterAppearanceFields, name) == 0x0);
LAYOUT_ASSERT(CharacterAppearanceFields_section_offset, offsetof(CharacterAppearanceFields, section) == 0x30);
LAYOUT_ASSERT(CharacterAppearanceFields_classId_offset, offsetof(CharacterAppearanceFields, classId) == 0x31);
LAYOUT_ASSERT(CharacterAppearanceFields_flags_offset, offsetof(CharacterAppearanceFields, flags) == 0x32);
LAYOUT_ASSERT(CharacterAppearanceFields_version_offset, offsetof(CharacterAppearanceFields, version) == 0x33);
LAYOUT_ASSERT(CharacterAppearanceFields_classFlags_offset, offsetof(CharacterAppearanceFields, classFlags) == 0x34);
LAYOUT_ASSERT(CharacterAppearanceFields_costume_offset, offsetof(CharacterAppearanceFields, costume) == 0x38);
LAYOUT_ASSERT(CharacterAppearanceFields_skin_offset, offsetof(CharacterAppearanceFields, skin) == 0x3A);
LAYOUT_ASSERT(CharacterAppearanceFields_face_offset, offsetof(CharacterAppearanceFields, face) == 0x3C);
LAYOUT_ASSERT(CharacterAppearanceFields_head_offset, offsetof(CharacterAppearanceFields, head) == 0x3E);
LAYOUT_ASSERT(CharacterAppearanceFields_hair_offset, offsetof(CharacterAppearanceFields, hair) == 0x40);
LAYOUT_ASSERT(CharacterAppearanceFields_red_offset, offsetof(CharacterAppearanceFields, red) == 0x42);
LAYOUT_ASSERT(CharacterAppearanceFields_green_offset, offsetof(CharacterAppearanceFields, green) == 0x44);
LAYOUT_ASSERT(CharacterAppearanceFields_blue_offset, offsetof(CharacterAppearanceFields, blue) == 0x46);
LAYOUT_ASSERT(CharacterAppearanceFields_width_offset, offsetof(CharacterAppearanceFields, width) == 0x48);
LAYOUT_ASSERT(CharacterAppearanceFields_height_offset, offsetof(CharacterAppearanceFields, height) == 0x4C);

extern "C" {
extern CharacterTextureArchive player_class_texture_archive_table[19];
extern CharacterClassAppearance class_appearance_table[19];
extern CharacterAppearanceFields class_appearance_preset_table[13];
}
extern const char *chara_select_creation_shape_rel_files[19];
#endif
