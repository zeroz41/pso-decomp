#include "types.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8001ED80.h"
#include "pso/ui/charcreate/TChCrLoadAfsTextureReq.h"
#include "pso/ui/charcreate/TChCrLoadGmNjReq.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

// The argument block create passes to the second constructor.
struct TChCrLoadAfsTextureReqArgs {
    GinjaTextureList *textures;
    s32 m_6c;
    s32 *m_34;
    s32 m_70;
};

typedef void (TChCrLoadAfsTextureReq::*TChCrLoadAfsTextureReqHandler)();

extern "C" {
void queue_destruction__7TObjectFv(void *);
u32 get_bml_model(void *, int);
s32 free_bin_model_request(void *, int);
void *init_bin_model_request(void *, int, char **, u32 *, int, int, int);
extern const char *lbl_805D3B50;
s32 TLobby__sub_803CC4C0(s32);
f64 log();

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
        queue_destruction__7TObjectFv(this);
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
        if (TLobby__sub_803CC4C0(this->load_handle) == 2) {
            ((TLobby *)this->load_handle)->adxf_stop();
        }
        ((TLobby *)this->load_handle)->close_adxf_handle();
        this->load_handle = 0;
    }
    this->finish_request();
    for (i = 0; i < this->count; i++) {
        if (this->buffers[i] != 0) {
            TAdSinglePlyChrSelectGC::safe_free(this->buffers[i]);
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
    count = textures->count;
    if (count <= 0 || count > 8) return;
    for (i = 0; i < 8; i++) buffers[i] = 0;
    m_1c = 0;
    state = 0;
    index = 0;
    m_28 = 0;
    m_64 = 0x14FA;
    m_68 = 0;
}

TChCrLoadAfsTextureReq::TChCrLoadAfsTextureReq(TObject *parent, GinjaTextureList *textures, s32 *arg3, s32 arg4)
    : TObject(parent) {
    m_name = lbl_805D3B50;
    this->textures = textures;
    m_34 = arg3;
    *m_34 = 0;
    m_6c = 0;
    m_70 = arg4;
    init_texture_table();
}

TChCrLoadAfsTextureReq::TChCrLoadAfsTextureReq(TObject *parent, void *args) : TObject(parent) {
    m_name = lbl_805D3B50;
    textures = ((TChCrLoadAfsTextureReqArgs *)args)->textures;
    m_6c = ((TChCrLoadAfsTextureReqArgs *)args)->m_6c;
    m_34 = ((TChCrLoadAfsTextureReqArgs *)args)->m_34;
    m_70 = ((TChCrLoadAfsTextureReqArgs *)args)->m_70;
    init_texture_table();
}

TChCrLoadAfsTextureReq *create_ch_cr_load_afs_texture_req(void *parent, void *textures, void *arg2, void *arg3) {
    return new TChCrLoadAfsTextureReq((TObject *)parent, (GinjaTextureList *)textures, (s32 *)arg2, (s32)arg3);
}

void *TChCrLoadAfsTextureReq::create(void *parent, void *args) {
    return new TChCrLoadAfsTextureReq((TObject *)parent, args);
}

extern "C" f32 TLobby__sub_8028C50C(void) {
    return (f32) log();
}
void TLobby::update_model_load() {
    s32 timer;
    u32 bml_model;
    void *request;
    TChCrLoadGmNjReq *req = (TChCrLoadGmNjReq *)this;
    timer = req->m_74 - 1;
    req->m_74 = timer;
    if (timer < 0) {
        if (req->m_68 != NULL) {
            free_bin_model_request(req->m_68, 1);
        } else {
            return;
        }
        request = ::operator new(0x440);
        if (request != NULL) {
            request = init_bin_model_request(request, 6, &req->m_60, &req->m_64, 0, 0, req->m_24->start_load_default());
        }
        req->m_68 = request;
        if (request != NULL) {
            req->m_74 = 0x12C;
        }
    } else if (fn_8001ED90(req->m_68) != 0) {
        bml_model = get_bml_model(req->m_68, 0);
        *req->m_1c = bml_model;
        if (bml_model != 0U) {
            req->m_24->alloc_load_buffer(TLobby__sub_8001ED88(req->m_68));
            free_bin_model_request(req->m_68, 1);
            req->m_68 = NULL;
            req->sub_8028C8A8();
            *req->m_28 &= ~req->m_20;
            queue_destruction__7TObjectFv(this);
        }
    }
}
