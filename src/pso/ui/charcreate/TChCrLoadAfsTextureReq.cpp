#include "pso/system/memory.h"
#include "pso/system/Adxf.h"
#include "pso/ui/charcreate/CharacterLoadBuffer.h"
#include "pso/system/BmlAccessors.h"
#include "pso/system/BmlResource.h"
#include "types.h"
#include <math.h>
#include "pso/ui/charcreate/TChCrLoadAfsTextureReq.h"
#include "pso/ui/charcreate/TChCrLoadGmNjReq.h"
#include "pso/network/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/BmlResource.h"
#include "pso/render/TextureLoad.h"
#include "pso/ui/charcreate/TChCrLoadAfs.h"
#include "pso/ui/charcreate/CharacterAppearanceTables.h"
#include "pso/math/FloatRounding.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/render/GinjaTextureInput.h"
#include <string.h>

typedef void (TChCrLoadAfsTextureReq::*TChCrLoadAfsTextureReqHandler)();

#pragma push
#pragma readonly_strings on
const char *TChCrLoadAfsTextureReq::name = "TChCrLoadAfsTextureReq";
#pragma pop

s32 find_player_texture_name_ordinal(u8 *object) {
    const char *name;
    s32 count;
    s32 steps;
    s32 mid;
    s32 step;
    const char **list;
    s32 i;
    f32 l2;
    s32 r;
    TChCrLoadAfsTextureReq *req = (TChCrLoadAfsTextureReq *)object;
    name = req->textures->textures[req->index].filename;
    count = player_class_texture_archive_table[req->display_index].count;
    l2 = logf(2.0f);
    steps = (s32)ceil_to_float(logf(count) / l2) + 1;
    mid = (count + 1) >> 1;
    step = (mid + 1) >> 1;
    list = player_class_texture_archive_table[req->display_index].textureNames;
    for (i = 0; i < steps; i++) {
        r = strcmp(name + 3, list[mid] + 3);
        if (r == 0) {
            return mid;
        }
        if (r < 0) {
            mid -= step;
            if (mid < 0) {
                mid = 0;
            }
        } else {
            mid += step;
            if (mid >= count) {
                mid = count - 1;
            }
        }
        step = (step + 1) >> 1;
        if (step < 1) {
            step = 1;
        }
    }
    ((TObject *)object)->queue_destruction();
    return 0;
}

void TChCrLoadAfsTextureReq::update_loading() {
    s32 retry;
    s32 i;
    retry = 0;
    switch (ADXF_GetStat(load_handle)) {
    case 1:
        if (++stop_count >= 3) {
            return;
        }
        retry = 1;
        break;
    case 2:
        if (++read_frames >= 150) {
            retry = 1;
            break;
        }
        return;
    case 3:
        break;
    default:
        return;
    }
    if (retry != 0) {
        ADXF_Close(load_handle);
        load_handle = 0;
        safe_free(buffers[index]);
        buffers[index] = 0;
        state = 1;
        return;
    }
    ADXF_Close(load_handle);
    load_handle = 0;
    if (++index != count) {
        state = 1;
        return;
    }
    for (i = 0; i < count; i++) {
        texture_inputs[i].set_render_rect(buffers[i], 0, 0, 0);
        set_texture_name(&textures->textures[i], &texture_inputs[i], 0, 0x40000000);
    }
    if (load_texture_list(textures) != -1) {
        textures_loaded = 1;
        queue_destruction();
    }
}

void TChCrLoadAfsTextureReq::start_read() {
    s32 n;
    AdxfHandle *handle;
    void *buf;
    handle = ADXF_OpenAfs(player_class_texture_archive_table[display_index].archiveId, find_player_texture_name_ordinal((u8 *)this));
    load_handle = handle;
    if (handle != 0) {
        stop_count = 0;
        read_frames = 0;
        n = ADXF_GetFsizeSct(load_handle);
        buf = alloc(n << 11);
        buffers[index] = buf;
        if (buf != 0) {
            ADXF_ReadNw(load_handle, n, buffers[index]);
            state = 2;
        }
    }
}

void TChCrLoadAfsTextureReq::try_begin_load() {
    if (try_acquire_load_slot() != 0) {
        state = 1;
    }
}

s32 TChCrLoadAfsTextureReq::active_load_count;

void TChCrLoadAfsTextureReq::run_task() {
    if (suspended == 1) {
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
    if (this->textures_loaded == 0 && this->buffers[0] != 0) {
        if (ADXF_GetStat(this->load_handle) == 2) {
            ADXF_Stop(this->load_handle);
        }
        ADXF_Close(this->load_handle);
        this->load_handle = 0;
    }
    this->finish_request();
    for (i = 0; i < this->count; i++) {
        if (this->buffers[i] != 0) {
            safe_free(this->buffers[i]);
            this->buffers[i] = 0;
        }
    }
    if (this->textures_loaded == 1) {
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
    textures_loaded = 0;
    state = 0;
    index = 0;
    suspended = 0;
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

TChCrLoadAfsTextureReq *create_ch_cr_load_afs_texture_req(TObject *parent, NJS_TEXLIST *textures, s32 *completion_flags, s32 display_index) {
    return new TChCrLoadAfsTextureReq(parent, textures, completion_flags, display_index);
}

TChCrLoadAfsTextureReq *TChCrLoadAfsTextureReq::create(TObject *parent, TChCrLoadAfsTextureReqArgs *args) {
    return new TChCrLoadAfsTextureReq(parent, args);
}

float logf(float x) {
    return (float)log(x);
}
