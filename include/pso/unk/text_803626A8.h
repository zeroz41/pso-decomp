#ifndef PSO_UNK_TEXT_803626A8_H
#define PSO_UNK_TEXT_803626A8_H

#include "types.h"

struct BmlResource;
class TUnk_8048FA00;

// bm_ene_epsilon.bml and the two breakup models built from its fragments (TObjEneEpsilonGuard::load_assets).
extern BmlResource *epsilon_bml_resource;
extern TUnk_8048FA00 *epsilon_body_breakup_model;   // model 5, re6_hahen1.nj; the body breaks into it
extern TUnk_8048FA00 *epsilon_guard_breakup_model;  // model 6, re6_b1_hahen2.nj; each guard breaks into it

#endif
