#ifndef PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_801FBF54_H
#define PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_801FBF54_H

#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"
#include "pso/system/save/CardSaveFile.h"
#include "pso/system/date.h"

class TPlyCharData;
struct CharacterFile;
struct CharacterFileSlot;
struct CharacterSaveRecord;
struct SubtractiveRng;

extern SubtractiveRng chr_select_rng_state;
// The two serial number generator seeds.
extern s32 chr_select_serial_seeds[];
extern char memory_card_character_dir_name[0x20];

CharacterFileSlot *get_selected_character_slot(CharacterFile *file);
CharacterSaveRecord *get_selected_save_record(CharacterFile *file);
struct GuildCardSaveData;

// What the card slot summary lookups report about a character slot of a card file.
struct CardSlotSummary {
    const char *name;
    s32 level;
    u32 copied;     // the slot's CharacterFileSlot::copied
    s32 play_time;  // seconds played (CharacterSaveRecord::play_time)
};

// The summary of slot i of the slot A card file, NULL when i is out of range or the slot is empty.
CardSlotSummary *get_card_slot_summary(u32 i);
// The same for the slot B card file (secondary_card_character_save_buffer).
CardSlotSummary *get_secondary_slot_summary(u32 i);
s32 is_secondary_slot_active(u32 i);
s32 load_character_file_slot_b(s32);
s32 poll_secondary_card_load(void);
void rebuild_guild_card_save_file(void);
void decrypt_secondary_card_buffer(void);

s32 save_active_character_to_card(void);
int start_system_file_write(s32 chan);
s32 begin_character_card_save(void);
void set_character_file_seed(CharacterFile *file, s32 value);
s32 get_character_file_seed(CharacterFile *file);
s32 start_character_file_write(void);
void decrypt_guild_card_payload(GuildCardSaveData *data);
void encrypt_guild_card_payload(GuildCardSaveData *data, void *);
u32 calc_crc32_bitwise(u8 *data, u32 size);
s32 alloc_global_buffer(void);
s32 buffer_init(void);
void game_state_load(void);
CharacterSaveRecord *get_split_screen_character_save_record(int client);
s32 init_buffer(void);
void init_fresh_character_card(void);
void init_fresh_character_slot(s32 slot);
void init_timestamped_data(void);
s32 load_and_verify_data(s32 verify_only);
s32 load_guild_card_save(void);
extern "C" {
s32 load_pso_system(void);
}
s32 load_system_file(s32 mode);
void load_tables(int a0);
s32 pso_system_load_gc(void);

// The date the selected character was loaded at; the union keeps the 12 bytes and 4-byte alignment of the original object.
union CharSelectDate {
    DateStamp stamp;
    u32 words[3];
};

// The save writers address the neighboring card records relative to the character record.
struct CardSaveMetadataBlock {
    CharacterCardMetadata character;
    char system_filename[0x20];
    char system_dir_name[0x20];
    char character_dir_name[0x20];
    EpisodeCardMetadata episode;
    GuildCardFile guild_card;
};

extern u8 quest_memcard_key[];

void delete_character_save_file(void);
void delete_guild_card_save_file(void);
struct Pso3CharacterFile;
void decrypt_character_save(Pso3CharacterFile *save_data);
struct NJS_OBJECT;
void draw_ginja_box_tree(NJS_OBJECT *node);
#endif
