#ifndef PSO_SYSTEM_CHOICESEARCHSELECTION_H
#define PSO_SYSTEM_CHOICESEARCHSELECTION_H

#include "types.h"

// One choice search setting: the category and the option picked in it.
struct ChoiceSearchSelection {
    u32 parent_choice_id;
    u32 choice_id;
};

#endif
