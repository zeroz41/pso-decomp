#include "types.h"
#include "pso/network/protocol/choice_search.h"
#include "pso/network/TPlyMeetUserExtension.h"
#include "pso/player/TPlyGuildCardTag.h"

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
