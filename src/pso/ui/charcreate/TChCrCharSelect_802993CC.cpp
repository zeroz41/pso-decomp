#include "types.h"
#include "pso/ui/charcreate/CreationInput.h"
#include "pso/ui/charcreate/TChCrCharSelect.h"
#include "pso/ui/charcreate/TObjCMProportion.h"


void TChCrCharSelect::reset_proportions() { TObjCMProportion::poll_pad_buttons(); update_creation_direction_repeat(); }

