#include "pso/system/memory.h"
#include "pso/system/Adxf.h"
#include "pso/ui/charcreate/CharacterLoadBuffer.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8001ED80.h"
#include "pso/ui/charcreate/TChCrLoadAfsTextureReq.h"
#include "pso/ui/charcreate/TChCrLoadGmNjReq.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby_8001EF5C.h"

typedef void (TChCrLoadAfsTextureReq::*TChCrLoadAfsTextureReqHandler)();

extern "C" {

extern "C" { extern char TChCrLoadAfsTextureReq__class_name_string[]; }
const char *lbl_805D3B50 = TChCrLoadAfsTextureReq__class_name_string;
f64 log(f64);

void TChCrLoadAfsTextureReq::try_begin_load() {
    if (try_acquire_load_slot() != 0) {
        state = 1;
    }
}

s32 TChCrLoadAfsTextureReq__active_load_count;

void TChCrLoadAfsTextureReq::run_task() {
    if (m_28 == 1) {
        return;
    }
    if (--m_64 <= 0) {
        return;
    }
    static TChCrLoadAfsTextureReqHandler tbl[] = {
        &TChCrLoadAfsTextureReq::try_begin_load,
        &TChCrLoadAfsTextureReq::start_read,
        &TChCrLoadAfsTextureReq::update_loading,
    };
    if (state < 0 || state >= 3) {
        queue_destruction();
        return;
    }
    (this->*tbl[state])();
}

void TChCrLoadAfsTextureReq::finish_request() {
    s32 count;

    if (m_68 != 0 && TChCrLoadAfsTextureReq__active_load_count <= 3) {
        count = TChCrLoadAfsTextureReq__active_load_count - 1;
        TChCrLoadAfsTextureReq__active_load_count = count;
        if (count >= 0) {
            m_68 = 0;
        }
    }
}

s32 TChCrLoadAfsTextureReq::try_acquire_load_slot() {
    if (TChCrLoadAfsTextureReq__active_load_count < 0 || TChCrLoadAfsTextureReq__active_load_count > 3) {
        return 0;
    }
    if (m_68 == 1) {
        return 0;
    }
    if (TChCrLoadAfsTextureReq__active_load_count >= 3) {
        return 0;
    }
    TChCrLoadAfsTextureReq__active_load_count += 1;
    m_68 = 1;
    return 1;
}
TChCrLoadAfsTextureReq::~TChCrLoadAfsTextureReq() {
    s32 i;
    if (this->m_1c == 0 && this->buffers[0] != 0) {
        if (ADXF_GetStat(this->load_handle) == 2) {
            ADXF_Stop(this->load_handle);
        }
        ADXF_Close(this->load_handle);
        this->load_handle = 0;
    }
    this->finish_request();
    for (i = 0; i < this->count; i++) {
        if (this->buffers[i] != 0) {
            safe_free(reinterpret_cast<void *>(this->buffers[i]));
            this->buffers[i] = 0;
        }
    }
    if (this->m_1c == 1) {
        if (this->m_6c != 0) {
            *this->m_34 &= ~this->m_6c;
        } else if (this->m_34 != NULL) {
            *this->m_34 = 1;
        }
    }
}

}

void TChCrLoadAfsTextureReq::init_texture_table() {
    s32 i;
    count = textures->nbTexture;
    if (count <= 0 || count > 8) return;
    for (i = 0; i < 8; i++) buffers[i] = 0;
    m_1c = 0;
    state = 0;
    index = 0;
    m_28 = 0;
    m_64 = 0x14FA;
    m_68 = 0;
}

TChCrLoadAfsTextureReq::TChCrLoadAfsTextureReq(TObject *parent, NJS_TEXLIST *textures, s32 *arg3, s32 arg4)
    : TObject(parent) {
    m_name = lbl_805D3B50;
    this->textures = textures;
    m_34 = arg3;
    *m_34 = 0;
    m_6c = 0;
    m_70 = arg4;
    init_texture_table();
}

TChCrLoadAfsTextureReq::TChCrLoadAfsTextureReq(TObject *parent, TChCrLoadAfsTextureReqArgs *args) : TObject(parent) {
    m_name = lbl_805D3B50;
    textures = args->textures;
    m_6c = args->completion_mask;
    m_34 = args->completion_flags;
    m_70 = args->display_index;
    init_texture_table();
}

TChCrLoadAfsTextureReq *create_ch_cr_load_afs_texture_req(void *parent, void *textures, void *slot, void *index) {
    return new TChCrLoadAfsTextureReq((TObject *)parent, (NJS_TEXLIST *)textures, (s32 *)slot, (saddr)index);
}

TChCrLoadAfsTextureReq *TChCrLoadAfsTextureReq::create(TObject *parent, TChCrLoadAfsTextureReqArgs *args) {
    return new TChCrLoadAfsTextureReq(parent, args);
}

extern "C" f32 TLobby__sub_8028C50C(f32 x) {
    return (f32) log(x);
}
void TChCrLoadGmNjReq::update_model_load() {
    s32 timer;
    NJS_OBJECT *bml_model;
    BmlResource *request;
    timer = load_timer - 1;
    load_timer = timer;
    if (timer < 0) {
        if (loaded_bml != NULL) {
            delete loaded_bml;
        } else {
            return;
        }
        request = static_cast<BmlResource *>(::operator new(sizeof(BmlResource)));
        if (request != NULL) {
            request = init_bin_model_request(request, 6, model_ids, &model_ids[1], NULL, NULL, get_character_load_buffer(load_slot));
        }
        loaded_bml = (BmlResource *)request;
        if (request != NULL) {
            load_timer = 0x12C;
        }
    } else if (fn_8001ED90(loaded_bml) != 0) {
        bml_model = get_bml_model(loaded_bml, 0);
        *model_out = bml_model;
        if (bml_model != NULL) {
            advance_character_load_buffer(load_slot, TLobby__sub_8001ED88(loaded_bml));
            delete loaded_bml;
            loaded_bml = NULL;
            sub_8028C8A8();
            *completion_flags &= ~completion_mask;
            queue_destruction();
        }
    }
}
