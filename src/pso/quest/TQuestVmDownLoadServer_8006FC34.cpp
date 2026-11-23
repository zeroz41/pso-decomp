#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"
#include <string.h>
#include "pso/system/date.h"
#include "pso/system/vector.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/challenge/TChallenge.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/object/TObjTombstone.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_8026A14C.h"
#include "pso/player/PlayerSlots.h"

struct Table_8006FE7C {
    s32 v0;
    s32 v4;
    s32 v8;
    u8 padC[0x270 - 0xC];
    ChallengeTombstonePlayerSlot recs[4];
};

struct Date_8006FC7C { u16 year; u8 a; u8 b; u8 c; u8 d; u8 pad[6]; };

struct Card_8006FC7C {
    u8 reserved[0x2224];
    TObjTombstoneRecord tombstone;
};

struct Unit_8006FC7C { u8 pad[0x370]; s32 f370; };

extern "C" {
extern Table_8006FE7C challenge_mode_state;
extern void *tl_07;
char *TLobby__sub_80070ACC(u8, u8, s32);
Unit_8006FC7C *find_entity_by_id(void);
extern char lbl_8043857C[];
extern s32 local_client_id;
void TQuestVmDownLoadServer::split_time_hms(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    *arg1 = arg0 / 3600;
    if ((s32) *arg1 > 0x63) {
        *arg1 = 0x63;
    }
    *arg2 = (arg0 / 60) % 60;
    *arg3 = arg0 % 60;
}

void TChallenge::update_card_save_info() {
    char buf[0x60];
    char name[0x20];
    Date_8006FC7C date;
    Card_8006FC7C *card;
    TObjPlayer *ply;
    s32 n;
    s32 v;
    u8 b;
    u8 c;
    Unit_8006FC7C *u;
    char *s;
    char *unit;
    s32 id;
    if (((Card_8006FC7C *)get_character_save_record(0xFFFF)) == NULL) {
        return;
    }
    card = reinterpret_cast<Card_8006FC7C *>(get_character_save_record(0xFFFF));
    ply = static_cast<TObjPlayer *>(get_player_by_client_id(local_client_id));
    if (ply == NULL) {
        return;
    }
    card->tombstone.phase = TWindowSubStatusDisp::resolve_player_slot(-1);
    card->tombstone.layout = challenge_mode_state.v0;
    card->tombstone.floor = get_current_floor();
    if (card->tombstone.unk_4 < 0) {
        card->tombstone.unk_4 = 0x270F;
    }
    if (++card->tombstone.unk_4 > 0x270F) {
        card->tombstone.unk_4 = 0x270F;
    }
    VecCopy((Vec *)&card->tombstone.position, (const Vec *)&ply->position);
    getDateStamp((DateStamp *)&date);
    if (date.year / 100 != 20) {
        v = 0xF;
    } else {
        n = date.year % 100;
        v = n;
        if (n > 0xF) {
            v = 0xF;
        }
    }
    v <<= 4;
    v |= date.a;
    v <<= 8;
    v |= (b = date.b);
    v <<= 8;
    v |= (c = date.c);
    v <<= 8;
    v |= date.d;
    card->tombstone.date = v;
    strncpy(card->tombstone.display_name, TLobby__sub_80070ACC(c, b, v), 0x13);
    card->tombstone.display_name[0x13] = 0;
    unit = card->tombstone.unit_name;
    card->tombstone.unit_name[0] = 0;
    s = (char *)TLobby::get_unit_list();
    if (s != NULL) {
        strncpy(buf, s, 0x5F);
        buf[0x5F] = 0;
        n = strlen(buf);
        if (n != 0) {
            if (n <= 0x1F) {
                strncpy(name, buf, 0x1F);
            } else {
                strncpy(name, lbl_8043857C, 4);
                fn_8026A1C4(name + 4, buf, 0x1B);
            }
            name[0x1F] = 0;
            strcpy(unit, name);
        }
    }
    id = -1;
    if ((((TObjPlayer *)ply)->get_attacker_id() & 0xF000) == 0x1000) {
        u = find_entity_by_id();
        if (u != NULL) {
            id = u->f370;
        }
    }
    card->tombstone.rt_index = id;
}

void TLobby::spawn_player_tombstones() {
    saddr i;
    ChallengeTombstonePlayerSlot *rec;
    TObjTombstoneRecord *info;
    TLobby::reset_tombstone_values();
    for (i = 0; i < 4; i++) {
        rec = &challenge_mode_state.recs[i];
        if (rec->active != 0 && get_player_by_client_id(i) != NULL) {
            info = &rec->record;
            if (info->unk_4 > 0 && info->phase == TWindowSubStatusDisp::resolve_player_slot(-1)
                && info->layout == challenge_mode_state.v0 && static_cast<s8>(info->floor) == challenge_mode_state.v8) {
                TObjTombstone::create(static_cast<TObject *>(tl_07), i, info);
            }
        }
    }
}

}
