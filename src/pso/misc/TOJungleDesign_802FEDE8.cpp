#include "types.h"
#include "pso/unk/text_802FF028.h"
#include "pso/misc/TOJungleDesign.h"
#pragma fp_contract on

extern s32 jungle_design_variant_table[];

void TOJungleDesign::init_design_variant() {
    this->m_b0 = (s32) this->set_params[0];
    if ((s32) this->m_b0 < 0) {
        this->m_b0 = 0;
    }
    if ((s32) this->m_b0 > 2) {
        this->m_b0 = 2;
    }
    this->m_ac = (s32)fn_802FF064(jungle_design_variant_table[this->m_b0]);
    this->texture_id = (s32)fn_802FF028(0);
}
