#ifndef PSO_UI_CITY_JUDGEITEM_H
#define PSO_UI_CITY_JUDGEITEM_H

#include "types.h"

struct TItemData;

struct AppraisalScoreEntry {
    s8 roll;
    u8 score;
};

struct AppraisalRollEntry {
    u8 adjustment;
    u8 weight;
    u8 favored_weight;
};

struct AppraisalRollTable {
    AppraisalRollEntry *entries;
    s32 count;
};

// Contents of JudgeItem.rel.
struct ItemAppraisalRules {
    AppraisalRollTable *special_rolls;
    AppraisalRollTable *grind_rolls;
    AppraisalRollTable *percentage_rolls;
    AppraisalScoreEntry *special_and_percentage_scores;
    AppraisalScoreEntry *grind_scores;
};

extern ItemAppraisalRules *item_appraisal_rules;
extern s32 item_appraisal_favored_weapon;
extern s32 item_appraisal_score;

u8 lookup_appraisal_grind_score(s8 roll);
u8 lookup_appraisal_score(s8 roll);
void adjust_appraisal_percentages(TItemData *item);
void adjust_appraisal_grind(TItemData *item);
void adjust_appraisal_special(TItemData *item);
s32 is_section_favored_weapon(TItemData *item);
void update_item_appraisal(TItemData *appraisal);
void free_judge_item();
void load_judge_item(void);

#endif
