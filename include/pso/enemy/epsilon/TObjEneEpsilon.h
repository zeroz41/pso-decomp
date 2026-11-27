#ifndef PSO_ENEMY_EPSILON_TOBJENEEPSILON_H
#define PSO_ENEMY_EPSILON_TOBJENEEPSILON_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/RenderFadeState.h"
#include <dolphin/mtx/GeoTypes.h>

struct BmlResource;
class TBreakUpMdlData;

struct TObjEneEpsilon : public TObjEneDD_ST {
    TObjEneEpsilon(TObject *parent);
    virtual ~TObjEneEpsilon();
    s32 update_movement_status();
    s32 is_target_in_attack_range();
    RenderFadeState fades[4];  // built and destroyed by TObjEneEpsilon
    static void free_shared_resources();
    static void load_assets();
};

// bm_ene_epsilon.bml and the two breakup models built from its fragments (TObjEneEpsilon::load_assets).
extern BmlResource *epsilon_bml_resource;
extern TBreakUpMdlData *epsilon_body_breakup_model;   // model 5, re6_hahen1.nj; the body breaks into it
extern TBreakUpMdlData *epsilon_guard_breakup_model;  // model 6, re6_b1_hahen2.nj; each guard breaks into it
// The chunk polygon lists of the nine guard parts; TObjEneEpsilonBody::set_guard_part_colors rewrites their
// material colour bytes.
extern u8 *epsilon_guard_part_color_table[9];

#endif
