#include "types.h"
#include "pso/misc/TChCrTagName.h"
#include "pso/ui/TChCrTagOccupation.h"
#include "pso/ui/TChCrCharSelect.h"
#include "pso/TChCrTagPlBack.h"
#include "pso/TChCrTagPlGraphic.h"
#include "pso/misc/TChCrTagInformation.h"

void TChCrCharSelect::init_widgets() { TChCrTagOccupation::create_all(); create_all__12TChCrTagNameFv(); create_all_ch_cr_tag_headers(); TChCrTagPlBack::create_default(); TChCrTagPlGraphic::create_matching_tags(); TChCrTagInformation::create_default(); }
