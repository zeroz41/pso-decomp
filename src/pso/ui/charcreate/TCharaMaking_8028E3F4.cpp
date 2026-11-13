#include "types.h"
#include "pso/ui/charcreate/TCharaMaking_8028E3F4.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/ui/charcreate/TCharaMaking.h"
#include "pso/ui/charcreate/CharacterAppearanceTables.h"
#include "pso/quest/TQuestVmDownLoadServer.h"

#pragma readonly_strings on

struct OutputSlot {u8 *name; unsigned int field4,field8;};

struct TextureOutput {int loaded; u8 names[8][32]; struct OutputSlot slots[8]; struct OutputSlot *entries; int count;};

extern "C" {
s32 TLobby__sub_801E3E9C(s32, const void *, void *, s32);
extern void *player_class_texture_buffer_table[];
u8 lbl_80518880[0x228];
u8 lbl_80518AA8[0x384];
u8 lbl_80518E2C[0x354];
u8 lbl_80519180[0x2B8];
u8 lbl_80519438[0x384];
u8 lbl_805197BC[0x41C];
u8 lbl_80519BD8[0x3B8];
u8 lbl_80519F90[0x3DC];
u8 lbl_8051A36C[0x520];
u8 lbl_8051A88C[0x41C];
u8 lbl_8051ACA8[0x398];
u8 lbl_8051B040[0x3B0];
u8 lbl_8051B3F0[0x138];
u8 lbl_8051B528[0x138];
u8 lbl_8051B660[0x134];
u8 lbl_8051B794[0x134];
u8 lbl_8051B8C8[0x134];
u8 lbl_8051B9FC[0x134];
u8 lbl_8051BB30[0x134];
u8 chara_making_load_buffer[0x40C];
void build_appearance_texture_names__12TCharaMakingFv(TextureOutput *output, CharacterAppearanceFields *appearance, CharacterClassAppearance *definition, CharacterTextureList *source);
int is_quest_active(void);

s32 TCharaMaking::is_end() {
    if ((get_main_phase() == 0xF) || (is_quest_active() != 0)) {
        return 1;
    }
    return 0;
}

s32 TCharaMaking::get_display_index() {
    s8 temp;

    if (!(((CharacterAppearanceFields *)this)->flags & 0xA)) {
        return ((CharacterAppearanceFields *)this)->classId;
    }
    if (((s8)((CharacterAppearanceFields *)this)->version <= 0) ||
        ((temp = *(s8 *)&((CharacterAppearanceFields *)this)->extraModel) < 0) ||
        (temp >= 7)) {
        return ((CharacterAppearanceFields *)this)->classId;
    }
    if (TCharaMaking::is_end() != 0) {
        return 0x12 - *(s8 *)&((CharacterAppearanceFields *)this)->extraModel;
    }
    return ((CharacterAppearanceFields *)this)->classId;
}

struct TextureOutput;
unsigned int strlen(u8 *); u8 *strncpy(u8 *,u8 *,unsigned int);
void build_appearance_texture_names__12TCharaMakingFv(TextureOutput *output, CharacterAppearanceFields *appearance, CharacterClassAppearance *definition, CharacterTextureList *source) {
    if (source->count <= 8) {
        int index;
        OutputSlot *slot;
        u8 **entry;
        u8 *name;
        slot = output->entries = output->slots;
        index = 0;
        output->count = source->count;
        entry = (u8 **)source->entries;
        for (; index < source->count; ++index, ++entry, ++slot) {
            name = output->names[index];
            strlen(*entry);
            strncpy(name, *entry, 31);
            name[31] = 0;
            if (definition->counts[0] > 0) {
                char *digit = (char *)&name[6];
                if (*digit++ != '0' || *digit != '0') {
                switch ((s8)name[4]) {
                case 'b': case 't':
                    { int costume = appearance->costume + 1;
                    name[6] = costume / 10 + '0';
                    *digit = costume % 10 + '0'; }
                    break;
                }
            }
            }
            if (definition->counts[1] > 0 && name[8] != 'z') {
                switch ((s8)name[4]) {
                case 'b': case 'f': case 't': name[8] = appearance->skin + 'a'; break;
                }
            }
            if (definition->counts[2] > 0 && name[7] != '0') {
                switch (name[4]) {
                case 'f': name[7] = appearance->face + '1'; break;
                }
            }
            if (name[4] == 'c') {
                if (appearance->flags & 1 || (s8)appearance->section == -1) name[8] = 'z';
                else name[8] = appearance->section + 'a';
            }
            slot->name = name;
            slot->field8 = 0;
            slot->field4 = 0;
        }
    }
}

void request_chara_making_archives(void) {
    s32 i;
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        return;
    }
    for (i = 0; i < 0x13; i++) {
        if (TQuestVmDownLoadServer::is_ready() != 0) {
            return;
        }
        if (TLobby__sub_801E3E9C(player_class_texture_archive_table[i].archiveId, player_class_texture_archive_table[i].archiveName, player_class_texture_buffer_table[i], lbl_8045122C[i]) != 0) {
            if (TQuestVmDownLoadServer::is_ready() == 0) {
                return;
            }
            return;
        }
    }
    if (TQuestVmDownLoadServer::is_ready() != 0) {
        return;
    }
    if (TLobby__sub_801E3E9C(0xDB, "PLZSMPNJ.AFS", chara_making_load_buffer, 0x17A) != 0) {
        if (TQuestVmDownLoadServer::is_ready() == 0) {
            return;
        }
    }
}

}
