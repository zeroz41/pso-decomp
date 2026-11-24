#include "pso/system/memory.h"
#include "pso/ui/charcreate/CharacterPreview.h"
#include "pso/render/GinjaTextureInput.h"
#include "pso/system/Adxf.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/math/FloatRounding.h"
#include "types.h"
#include "pso/ui/charcreate/TChCrLoadAfs.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_803CC294.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/TChCrLoadAfs.h"
#include "pso/unk/TLobby.h"
#include <string.h>

int CharacterPreview::is_unloaded() { return completion_flags == 0; }

extern "C" s32 chcr_load_afs_busy_flag;

void TChCrLoadAfs::release_load_slot() {
    if (state_30 != 0) {
        if (chcr_load_afs_busy_flag == 0) {
            load_state = 3;
            return;
        }
        state_30 = 0;
        chcr_load_afs_busy_flag = 0;
    }
}

s32 TChCrLoadAfs::try_begin_load() {
    if (state_30 != 0) {
        load_state = 3;
        return 0;
    }
    if (chcr_load_afs_busy_flag != 0) {
        return 0;
    }
    state_30 = 1;
    chcr_load_afs_busy_flag = 1;
    return 1;
}

extern "C" {
}

void TChCrLoadAfs::sub_8028B940() {  }
void TChCrLoadAfs::sub_8028B944() {  }
void TChCrLoadAfs::poll_load() {
    switch (ADXF_GetStat(load_handle)) {
    case 2:
        return;
    case 3:
        ADXF_Close(load_handle);
        load_handle = 0;
        break;
    case 1:
    default:
        load_state = 3;
        return;
    }
    release_load_slot();
    load_state = 2;
}

#include "pso/ui/charcreate/TChCrLoadAfsTextureReq.h"
#include "pso/ui/charcreate/CharacterAppearanceTables.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
extern "C" { extern const char TChCrLoadAfs__class_name_string[13] = "TChCrLoadAfs"; }
extern "C" { extern const char TChCrLoadAfsTextureReq__class_name_string[23] = "TChCrLoadAfsTextureReq"; }

extern "C" {
f32 TLobby__sub_8028C50C(f32);
s32 load_texture_list(NJS_TEXLIST *);
}

void TChCrLoadAfs::start_download() {
    s32 count;
    AdxfHandle *handle;
    u8 *buffer;

    if (try_begin_load() != 0) {
        handle = ADXF_OpenAfs(source_20, source_24);
        load_handle = handle;
        if (handle == NULL) {
            load_state = 3;
            return;
        }
        count = ADXF_GetFsizeSct(load_handle);
        buffer = static_cast<u8 *>(TQuestVmDownLoadServer::alloc(count << 0xB));
        buffer_address = buffer;
        if (buffer == NULL) {
            load_state = 3;
            return;
        }
        ADXF_ReadNw(load_handle, count, (void *)buffer_address);
        load_state = 1;
    }
}

typedef void (TChCrLoadAfs::*TChCrLoadAfsHandler)();

extern "C" {
s32 chcr_load_afs_busy_flag;
}

void TChCrLoadAfs::run_task() {
    if (--timer < 0) {
        load_state = 3;
        return;
    }
    static TChCrLoadAfsHandler tbl[] = {
        &TChCrLoadAfs::start_download,
        &TChCrLoadAfs::poll_load,
        &TChCrLoadAfs::sub_8028B944,
        &TChCrLoadAfs::sub_8028B940,
    };
    (this->*tbl[load_state])();
}

TChCrLoadAfs::~TChCrLoadAfs() {
    AdxfHandle *handle = load_handle;
    if (handle != 0) {
        if (ADXF_GetStat(handle) == 2) ADXF_Stop(load_handle);
        ADXF_Close(load_handle);
        load_handle = 0;
    }
    u8 *buffer = buffer_address;
    if (buffer != NULL) {
        safe_free(buffer);
        buffer_address = 0;
    }
    release_load_slot();
}

const char *lbl_805D3B48 = TChCrLoadAfs__class_name_string;
TChCrLoadAfs::TChCrLoadAfs(TObject *object, u32 archive, u32 entry) : TObject(object) {
    m_name = lbl_805D3B48;
    load_handle = 0;
    source_20 = archive;
    source_24 = entry;
    buffer_address = 0;
    load_state = 0;
    state_30 = 0;
    timer = 900;
}

TChCrLoadAfs *TChCrLoadAfs::create(TObject *parent, u32 archive, u32 entry) {
    return new TChCrLoadAfs(parent, archive, entry);
}

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
    count = player_class_texture_archive_table[req->m_70].count;
    l2 = TLobby__sub_8028C50C(2.0f);
    steps = (s32)ceil_to_float(TLobby__sub_8028C50C(count) / l2) + 1;
    mid = (count + 1) >> 1;
    step = (mid + 1) >> 1;
    list = player_class_texture_archive_table[req->m_70].textureNames;
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
        if (++m_20 >= 3) {
            return;
        }
        retry = 1;
        break;
    case 2:
        if (++m_24 >= 150) {
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
        safe_free(reinterpret_cast<void *>(buffers[index]));
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
        reinterpret_cast<GinjaTextureInput *>(m_74[i])->set_render_rect(reinterpret_cast<void *>(buffers[i]), 0, 0, 0);
        set_texture_name(&textures->textures[i], reinterpret_cast<GinjaTextureInput *>(m_74[i]), 0, 0x40000000);
    }
    if (load_texture_list(textures) != -1) {
        m_1c = 1;
        queue_destruction();
    }
}

void TChCrLoadAfsTextureReq::start_read() {
    s32 n;
    AdxfHandle *handle;
    uaddr buf;
    handle = ADXF_OpenAfs(player_class_texture_archive_table[m_70].archiveId, find_player_texture_name_ordinal((u8 *)this));
    load_handle = handle;
    if (handle != 0) {
        m_20 = 0;
        m_24 = 0;
        n = ADXF_GetFsizeSct(load_handle);
        buf = (uaddr)TQuestVmDownLoadServer::alloc(n << 11);
        buffers[index] = buf;
        if (buf != 0) {
            ADXF_ReadNw(load_handle, n, (void *)buffers[index]);
            state = 2;
        }
    }
}
