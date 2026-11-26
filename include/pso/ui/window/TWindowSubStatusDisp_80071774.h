#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80071774_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80071774_H

#include "types.h"
#include "pso/quest/challenge/ChallengeRecord.h"

// The challenge records of player `client` (see get_character_save_record); set: a ChallengeRecordSet.
s32 get_challenge_title_color(u16 client);
s32 challenge_title_color(ChallengeRecord *record);
char *get_challenge_rank_title(u16 client);
extern "C" char *decode_challenge_rank_title(ChallengeRecord *record);
s32 get_challenge_rank(u16 client, s32 set);
// The current set's total time plus the base time; the maximum while a stage is not cleared.
s32 get_challenge_total_time();
s32 get_challenge_set_time(u16 client, s32 set);
s32 get_challenge_stage_time(s32 stage, u16 client, s32 set);

#endif
