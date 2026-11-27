#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"
#include "pso/ui/window/ChallengeRank.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/network/TLobby.h"
#include "pso/quest/challenge/ChallengeMode.h"

static char no_rank_title[4] = "";

s32 get_challenge_title_color(u16 client_index) {
    CharacterSaveRecord *record = get_character_save_record(client_index);
    if (record == NULL) {
        return -1;
    }
    return challenge_title_color(&record->challenge);
}

s32 challenge_title_color(ChallengeRecord *record) {
    if (record == NULL) {
        return -1;
    }
    return rgb555_to_argb(record->title_color);
}

static char no_record_title[4] = "";

char *get_challenge_rank_title(u16 client) {
    CharacterSaveRecord *record = get_character_save_record(client);
    if (record == NULL) {
        return no_record_title;
    }
    return decode_challenge_rank_title(&record->challenge);
}

char *decode_challenge_rank_title(ChallengeRecord *record) {
    if (record == NULL) {
        return no_rank_title;
    }
    decode_obfuscated_string(challenge_rank_title, record->rank_title, 0xC);
    return challenge_rank_title;
}

s32 get_challenge_rank(u16 client, s32 set) {
    CharacterSaveRecord *record = get_character_save_record(client);
    s32 index;
    s32 rank;
    if (record == NULL) {
        return 0;
    }
    index = resolve_challenge_record_set(set);
    if (index < 3) {
        rank = record->challenge.ranks[index].rank;
    } else {
        rank = record->challenge.ep2_split_rank.rank;
    }
    return decode_challenge_count(rank);
}

s32 get_challenge_total_time(void) {
    s32 last;
    s32 max;
    s32 sum;
    s32 i;
    s32 r;
    max = challenge_set_max_time(RECORD_SET_CURRENT);
    if (is_challenge_mode() == 0 || get_character_save_record(0xFFFF) == NULL) {
        return max;
    }
    sum = 0;
    last = challenge_set_stage_count(RECORD_SET_CURRENT);
    for (i = 0; i <= last - 2; i++) {
        r = get_challenge_stage_time(i, 0xFFFF, RECORD_SET_CURRENT);
        if (r == 0) {
            return max;
        }
        sum += r;
    }
    sum += challenge_mode_state.base_time;
    return sum;
}

s32 get_challenge_set_time(u16 client, s32 set) {
    s32 *p;
    s32 n;
    s32 r;
    s32 sum;
    s32 i;
    CharacterSaveRecord *record = get_character_save_record(client);
    if (record == NULL) {
        return 0;
    }
    p = challenge_set_stage_times(&record->challenge, set);
    sum = 0;
    n = challenge_set_stage_count(set);
    for (i = 0; i < n; i++, p++) {
        r = decode_challenge_time(*p);
        if (r == 0) {
            return 0;
        }
        sum += r;
    }
    return sum;
}

s32 get_challenge_stage_time(s32 stage, u16 client, s32 set) {
    s32 count;
    CharacterSaveRecord *record = get_character_save_record(client);
    count = challenge_set_stage_count(set);
    if (stage < 0 || stage >= count || record == NULL) {
        return 0;
    }
    return decode_challenge_time(challenge_set_stage_times(&record->challenge, set)[stage]);
}
