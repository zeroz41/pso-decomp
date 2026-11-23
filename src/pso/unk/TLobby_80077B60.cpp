#include "types.h"
#include "pso/network/protocol/choice_search.h"

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
