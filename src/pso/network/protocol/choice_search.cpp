#include "types.h"
#include "pso/network/protocol/choice_search.h"
#include "pso/network/protocol/packet_classes.h"
#include "pso/network/TPlyMeetUserExtension.h"
#include "pso/player/TPlyGuildCardTag.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/system/ChoiceSearchSelection.h"
#include "pso/system/memory.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/window/TWindowSubComCard.h"

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
TRecvChoiceSearchOptions *choice_search_options;
ChoiceSearchResultList *choice_search_results;
int quest_hack_check_b_stub(void) { return 0; }
int quest_hack_check_a_stub(void) { return 0; }

void copy_choice_search_selections(ChoiceSearchSelection *selections, TPlyChoiceSearchConfig *config) {
    s32 i;
    TPlyChoiceSearchConfig::Entry *entry = config->entries;
    for (i = 0; i < 5; i++) {
        entry->parent_choice_id = selections->parent_choice_id;
        entry->choice_id = selections->choice_id;
        selections++;
        entry++;
    }
}

extern "C" {

u32 find_table_entry_id(TRecvChoiceSearchOptions *t, u16 a, u32 b) {
    s32 i;
    ChoiceSearchOption *e;
    if (b == 0) {
        return 0;
    }
    e = t->entries;
    for (i = 0; i < t->header.flags; i++) {
        if (e->choice.parent_choice_id == a && e->choice.choice_id == b) {
            return e->choice.choice_id;
        }
        e++;
    }
    return 0;
}

void set_value_by_key(ChoiceSearchSelection *arr, u16 key, s32 val) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (arr->parent_choice_id == key) {
            arr->choice_id = val;
            return;
        }
        arr++;
    }
}

}

s32 find_choice_search_value(ChoiceSearchSelection *selections, u16 parent_choice_id) {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (selections->parent_choice_id == parent_choice_id) {
            return selections->choice_id;
        }
        selections++;
    }
    return 0;
}

ChoiceSearchResultList *TWindowSubComCard::get_choice_search_results() {
    return choice_search_results;
}
void TWindowSubComCard::release() {
    if (choice_search_results != NULL) {
        delete choice_search_results;
        choice_search_results = NULL;
    }
}
TRecvChoiceSearchOptions *TWindowSubComCard::get_choice_search_options() {
    return choice_search_options;
}
extern "C" {

void rebuild_choice_search_selections(ChoiceSearchSelection *arr, TRecvChoiceSearchOptions *chr_select) {
    s32 i;
    s32 n;
    u16 id;
    u32 k;
    ChoiceSearchSelection *dst;
    ChoiceSearchOption *e;
    ChoiceSearchSelections tmp;
    copy_choice_search_block(&tmp, (ChoiceSearchSelections *)arr);
    clear_choice_search_selections(arr);
    n = chr_select->header.flags;
    dst = arr;
    e = chr_select->entries;
    i = 0;
    while (i < n) {
        if (e->choice.parent_choice_id == 0) {
            id = dst->parent_choice_id = e->choice.choice_id;
            k = find_choice_search_value(tmp.entries, id);
            dst->choice_id = (u16) find_table_entry_id(chr_select, id, k);
            dst++;
        }
        i++;
        e++;
    }
}
}

ChoiceSearchSelections *copy_choice_search_block(ChoiceSearchSelections *dest, const ChoiceSearchSelections *src) {
    *dest = *src;
    return dest;
}
void clear_choice_search_selections(ChoiceSearchSelection *arr) {
    s32 i;
    for (i = 0; i < 5; i++) {
        arr->parent_choice_id = 0;
        arr->choice_id = 0;
        arr++;
    }
}

#pragma pop

void store_choice_search_results(ChoiceSearchResultList *results) {
    if (choice_search_results == NULL) {
        choice_search_results = new ChoiceSearchResultList;
    }
    *choice_search_results = *results;
}

ChoiceSearchResultList::ChoiceSearchResultList() {}

ChoiceSearchResult::ChoiceSearchResult() {}

TPlyMeetUserExtension::TPlyMeetUserExtension() {}

void store_choice_search_options(TRecvChoiceSearchOptions *options) {
    if (choice_search_options == NULL) {
        choice_search_options = new TRecvChoiceSearchOptions;
    }
    *choice_search_options = *options;
}

void free_choice_search_data() {
    if (choice_search_results != NULL) {
        delete choice_search_results;
        choice_search_results = NULL;
    }
    if (choice_search_options != NULL) {
        delete choice_search_options;
        choice_search_options = NULL;
    }
}

void reset_choice_search_data() {
    choice_search_options = NULL;
    choice_search_results = NULL;
}

TPlyGuildCardTag::TPlyGuildCardTag() {}
