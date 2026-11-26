#include "pso/system/memory.h"
#include "pso/system/Adxf.h"
#include "pso/ui/charcreate/CharacterLoadBuffer.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "types.h"
#include <math.h>
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_8001ED80.h"
#include "pso/ui/charcreate/TChCrLoadAfsTextureReq.h"
#include "pso/ui/charcreate/TChCrLoadGmNjReq.h"
#include "pso/network/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby_8001EF5C.h"

typedef void (TChCrLoadAfsTextureReq::*TChCrLoadAfsTextureReqHandler)();

extern "C" { extern char TChCrLoadAfsTextureReq__class_name_string[]; }
const char *TChCrLoadAfsTextureReq::name = TChCrLoadAfsTextureReq__class_name_string;

void TChCrLoadAfsTextureReq::try_begin_load() {
    if (try_acquire_load_slot() != 0) {
        state = 1;
    }
}

s32 TChCrLoadAfsTextureReq::active_load_count;

void TChCrLoadAfsTextureReq::run_task() {
    if (m_28 == 1) {
        return;
    }
    if (--timeout_frames <= 0) {
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

    if (holds_load_slot != 0 && TChCrLoadAfsTextureReq::active_load_count <= 3) {
        count = TChCrLoadAfsTextureReq::active_load_count - 1;
        TChCrLoadAfsTextureReq::active_load_count = count;
        if (count >= 0) {
            holds_load_slot = 0;
        }
    }
}

s32 TChCrLoadAfsTextureReq::try_acquire_load_slot() {
    if (TChCrLoadAfsTextureReq::active_load_count < 0 || TChCrLoadAfsTextureReq::active_load_count > 3) {
        return 0;
    }
    if (holds_load_slot == 1) {
        return 0;
    }
    if (TChCrLoadAfsTextureReq::active_load_count >= 3) {
        return 0;
    }
    TChCrLoadAfsTextureReq::active_load_count += 1;
    holds_load_slot = 1;
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
        if (this->completion_mask != 0) {
            *this->completion_flags &= ~this->completion_mask;
        } else if (this->completion_flags != NULL) {
            *this->completion_flags = 1;
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
    timeout_frames = 0x14FA;
    holds_load_slot = 0;
}

TChCrLoadAfsTextureReq::TChCrLoadAfsTextureReq(TObject *parent, NJS_TEXLIST *textures, s32 *completion_flags, s32 display_index)
    : TObject(parent) {
    m_name = name;
    this->textures = textures;
    this->completion_flags = completion_flags;
    *this->completion_flags = 0;
    completion_mask = 0;
    this->display_index = display_index;
    init_texture_table();
}

TChCrLoadAfsTextureReq::TChCrLoadAfsTextureReq(TObject *parent, TChCrLoadAfsTextureReqArgs *args) : TObject(parent) {
    m_name = name;
    textures = args->textures;
    completion_mask = args->completion_mask;
    completion_flags = args->completion_flags;
    display_index = args->display_index;
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
