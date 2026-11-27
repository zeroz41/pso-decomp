#include "pso/system/memory.h"
#include "pso/render/GinjaTextureInput.h"
#include "pso/audio/Adxf.h"
#include "pso/math/FloatRounding.h"
#include "types.h"
#include "pso/ui/charcreate/TChCrLoadAfs.h"
#include "pso/network/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/task/TObject.h"
#include <string.h>

s32 chcr_load_afs_busy_flag;

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


void TChCrLoadAfs::empty_state_3() {  }
void TChCrLoadAfs::empty_state_2() {  }
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
        buffer = static_cast<u8 *>(alloc(count << 0xB));
        buffer_address = buffer;
        if (buffer == NULL) {
            load_state = 3;
            return;
        }
        ADXF_ReadNw(load_handle, count, buffer_address);
        load_state = 1;
    }
}

typedef void (TChCrLoadAfs::*TChCrLoadAfsHandler)();

void TChCrLoadAfs::run_task() {
    if (--timer < 0) {
        load_state = 3;
        return;
    }
    static TChCrLoadAfsHandler tbl[] = {
        &TChCrLoadAfs::start_download,
        &TChCrLoadAfs::poll_load,
        &TChCrLoadAfs::empty_state_2,
        &TChCrLoadAfs::empty_state_3,
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

#pragma push
#pragma readonly_strings on
const char *TChCrLoadAfs::name = "TChCrLoadAfs";
#pragma pop

TChCrLoadAfs::TChCrLoadAfs(TObject *object, u32 archive, u32 entry) : TObject(object) {
    m_name = TChCrLoadAfs::name;
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
