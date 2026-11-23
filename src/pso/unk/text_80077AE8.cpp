#include "types.h"
#include "pso/network/protocol/choice_search.h"

void store_choice_search_options(TRecvChoiceSearchOptions *options) {
    if (choice_search_options == NULL) {
        choice_search_options = new TRecvChoiceSearchOptions;
    }
    *choice_search_options = *options;
}
