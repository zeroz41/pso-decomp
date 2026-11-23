#include "types.h"
#include "pso/ui/TAdChrSelPlayerGC.h"
#include "pso/ui/frontend/TAdPlyStatusGC.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

extern "C" { extern char lbl_804728D0[]; }
const char *lbl_805D3F78 = lbl_804728D0;
extern "C" {

void TAdChrSelPlayerGC::init_selection_model(s32 arg1) {
    this->m_name = lbl_805D3F78;
    state = 0;
    this->m_100 = 0;
    this->status_index = 0;
    layout_mode = arg1;
    this->m_170 = 0;
    *(s32 *)&this->joint_matrices = (saddr)mem_alloc(0xC00);
    TAdPlyStatusGC::get_instance(this, arg1);
    place_model_for_mode(layout_mode);
}

}
