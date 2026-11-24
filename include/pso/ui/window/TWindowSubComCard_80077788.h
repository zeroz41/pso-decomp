#ifndef PSO_UI_WINDOW_TWINDOWSUBCOMCARD_80077788_H
#define PSO_UI_WINDOW_TWINDOWSUBCOMCARD_80077788_H

#include "types.h"

struct ChoiceSearchSelection;
struct TPlyChoiceSearchConfig;

extern "C" {
u8 *copy_struct28__17TWindowSubComCardFii(saddr dest, saddr src);
int fn_80077788(void);
int fn_80077790(void);
}

// Copies the saved choice search selections into the search request.
void copy_choice_search_selections(ChoiceSearchSelection *selections, TPlyChoiceSearchConfig *config);

#endif
