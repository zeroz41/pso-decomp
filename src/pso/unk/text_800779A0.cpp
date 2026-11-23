#include "types.h"
#include "pso/network/protocol/choice_search.h"

void store_choice_search_results(ChoiceSearchResultList *results) {
    if (choice_search_results == NULL) {
        choice_search_results = new ChoiceSearchResultList;
    }
    *choice_search_results = *results;
}

ChoiceSearchResultList::ChoiceSearchResultList() {}

ChoiceSearchResult::ChoiceSearchResult() {}
