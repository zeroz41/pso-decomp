#ifndef PSO_SYSTEM_SAVE_CARD_SAVE_FILE_H
#define PSO_SYSTEM_SAVE_CARD_SAVE_FILE_H

#include "types.h"
#include <stddef.h>

struct CardSaveDescriptor {
    char filename[0x12];
    char title[0x22];
    u8 key[0x10];
    const void *banner;
    const void *icon;
    s16 field_4c;
    s16 field_4e;
    s32 field_50;
    u16 omit_title_space;
    u8 *data;
    s32 size;
};

LAYOUT_ASSERT(CardSaveDescriptor_banner_offset, offsetof(CardSaveDescriptor, banner) == 0x44);
LAYOUT_ASSERT(CardSaveDescriptor_data_offset, offsetof(CardSaveDescriptor, data) == 0x58);
LAYOUT_ASSERT(CardSaveDescriptor_size, sizeof(CardSaveDescriptor) == 0x60);

// The memory card file holding the guild card list, and where downloaded cards go.
struct GuildCardFile_804C89BC {
    char filename[0x20];
    char comment[0x20];
    u32 flags;
    char download_name[0x10];
    char download_dir[0x20];
    u32 download_flags;
};

struct CharacterCardMetadata {
    char filename[0x20];
    char comment[0x20];
    u32 flags;
    u8 icon[0x10];
};

struct EpisodeCardMetadata {
    char game_name[0x14];
    char comment[0x20];
    u32 flags;
    u8 icon[0x10];
};

LAYOUT_ASSERT(CharacterCardMetadata_size, sizeof(CharacterCardMetadata) == 0x54);
LAYOUT_ASSERT(EpisodeCardMetadata_size, sizeof(EpisodeCardMetadata) == 0x48);

extern "C" CharacterCardMetadata pso_character_card_filename;
extern "C" EpisodeCardMetadata episode_i_and_ii_card_filename;
extern GuildCardFile_804C89BC pso_guildcard_card_filename;
// The memory card file name of the system save, "PSO_SYSTEM".
extern "C" char pso_system_card_filename[0x20];

void set_card_banner_and_icon(CardSaveDescriptor *file, s32 index);
s32 verify_card_save_header(CardSaveDescriptor *file, void *image);
// Empty counterpart of set_card_banner_and_icon, called once the save image is built.
void release_card_banner_and_icon(CardSaveDescriptor *file);

#endif
