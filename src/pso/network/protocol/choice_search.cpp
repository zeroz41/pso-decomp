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
struct ByteBlock_28 { u8 bytes[0x28]; };

TRecvChoiceSearchOptions *choice_search_options;
ChoiceSearchResultList *choice_search_results;
extern "C" {
void clear_choice_search_selections(ChoiceSearchSelection *arr);

int fn_80077788(void) { return 0; }
int fn_80077790(void) { return 0; }

}

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

extern "C" {

saddr TWindowSubComCard::get_com_count() {
    return (saddr)choice_search_results;
}
void TWindowSubComCard::release() {
    if (choice_search_results != NULL) {
        delete choice_search_results;
        choice_search_results = NULL;
    }
}
saddr TWindowSubComCard::get_chr_select() {
    return (saddr)choice_search_options;
}

void rebuild_choice_search_selections(ChoiceSearchSelection *arr, TRecvChoiceSearchOptions *chr_select) {
    s32 i;
    s32 n;
    u16 id;
    u32 k;
    ChoiceSearchSelection *dst;
    ChoiceSearchOption *e;
    ChoiceSearchSelection tmp[5];
    copy_struct28__17TWindowSubComCardFii((saddr) tmp, (saddr) arr);
    clear_choice_search_selections((ChoiceSearchSelection *) arr);
    n = chr_select->header.flags;
    dst = arr;
    e = chr_select->entries;
    i = 0;
    while (i < n) {
        if (e->choice.parent_choice_id == 0) {
            id = dst->parent_choice_id = e->choice.choice_id;
            k = find_choice_search_value(tmp, id);
            dst->choice_id = (u16) find_table_entry_id(chr_select, id, k);
            dst++;
        }
        i++;
        e++;
    }
}

u8 * copy_struct28__17TWindowSubComCardFii(saddr dest, saddr src) {
    *(ByteBlock_28 *)(dest) = *(const ByteBlock_28 *)(src);
    return (u8 *)dest;
}
void clear_choice_search_selections(ChoiceSearchSelection *arr) {
    s32 i;
    for (i = 0; i < 5; i++) {
        arr->parent_choice_id = 0;
        arr->choice_id = 0;
        arr++;
    }
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
