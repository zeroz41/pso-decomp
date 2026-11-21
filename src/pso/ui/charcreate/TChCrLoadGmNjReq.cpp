#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "pso/ui/charcreate/TChCrLoadGmNjReq.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include <string.h>


#include "types.h"

#pragma push
#pragma readonly_strings on
const char *TChCrLoadGmNjReq__name = "TChCrLoadGmNjReq";
#pragma pop

// The argument block create_ch_cr_load_gm_nj_req passes to the constructor.
struct TChCrLoadGmNjReqArgs {
    const char *name;
    u32 *m_1c;
    TLobby *m_24;
    s32 m_20;
    s32 *m_28;
};

extern "C" {


void TChCrLoadGmNjReq::run_task() {
    s32 timer;
    timer = m_70 - 1;
    m_70 = timer;
    if (timer < 0) {
        queue_destruction();
        return;
    }
    switch (state) {
    case 0:
        ((TAdSinglePlyChrSelectGC *)this)->start_character_load_task();
        return;
    case 1:
        ((TLobby *)this)->update_model_load();
        return;
    }
}

TChCrLoadGmNjReq::~TChCrLoadGmNjReq() {
    sub_8028C8A8();
    if (m_68 != nullptr) {
        delete (BmlResource *)m_68;
    }
}
}

TChCrLoadGmNjReq::TChCrLoadGmNjReq(TObject *parent, void *args) : TObject(parent) {
    m_name = TChCrLoadGmNjReq__name;
    m_24 = ((TChCrLoadGmNjReqArgs *)args)->m_24;
    m_28 = ((TChCrLoadGmNjReqArgs *)args)->m_28;
    m_1c = ((TChCrLoadGmNjReqArgs *)args)->m_1c;
    m_20 = ((TChCrLoadGmNjReqArgs *)args)->m_20;
    strncpy(name, ((TChCrLoadGmNjReqArgs *)args)->name, 48);
    m_60 = name;
    m_64 = 0;
    m_68 = 0;
    m_6c = 0;
    m_70 = 5370;
    state = 0;
}

void *create_ch_cr_load_gm_nj_req(void *parent, void *args) {
    return new TChCrLoadGmNjReq((TObject *)parent, args);
}
