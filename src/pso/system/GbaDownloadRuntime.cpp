#include <stdlib.h>
#include <string.h>
#include <dolphin/gba.h>
#include "pso/system/ResourceFile.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/network/GbaJoybootState.h"
#include "pso/system/GbaDownloadRuntime.h"
#include "pso/system/GbaAramCache.h"
#include "pso/unk/TLobby_801F2D2C.h"
#include "pso/ui/frontend/TAdWarningBaseGC.h"
#include "pso/system/date.h"
#include "pso/unk/TLobby.h"
#include "pso/render/TDLGraph.h"
#include "pso/ui/Language.h"
#include "pso/system/task/TObject.h"
#include "pso/system/memory.h"

extern "C" {
u8 *gba_download_data_buffer;
uaddr gba_download_graph;
u32 gba_download_data_size;
s32 TLobby__data_805D6CCC;
s32 gba_joyboot_send_length;
u8 *gba_joyboot_send_buffer;
u8 gba_joyboot_status;
unsigned char lbl_805D6CD9;
short lbl_805D6CDA;
// The game code the GBA program header carries at 0xAC (calc_joyboot_checksum copies it in).
const u8 joyboot_game_code[4] = {'G', 'P', 'O', 'E'};

u32 SIProbe(s32);


void TLobby::destroy_singleton() {
    if ((u32) gba_download_graph != 0U) {
        ((TObject *)gba_download_graph)->queue_destruction();
        gba_download_graph = 0U;
    }
    *(s8 *)((s8 *)TLobby__data_805434A8 + 7) = 0;
}

void TLobby::init_graph() {
    uaddr temp_r3;

    if ((u32) gba_download_graph == 0U) {
        temp_r3 = (uaddr)TDLGraph::create();
        gba_download_graph = temp_r3;
        if (temp_r3 != 0U) {
            ((TDLGraph *)temp_r3)->set_graph_param(2);
        }
    }
}

void TLobby::free_buffer() {
    if (gba_download_data_buffer != NULL) {
        xfree(gba_download_data_buffer);
        gba_download_data_buffer = NULL;
    }
    gba_download_data_size = 0;
}

void TLobby::alloc_buffer() {
    gba_download_data_buffer = NULL;
    gba_download_data_size = 0;
    gba_download_data_buffer = static_cast<u8 *>(xmalloc(0x40000));
    gba_download_data_size = 0;
}
}

void gba_joyboot_transfer_callback(s32 channel, s32 arg1) {
    switch (arg1) {
    case 0:
        TLobby__data_805D6CCC = 4;
        break;
    case 1:
    case 3:
    case 4:
        TLobby__data_805D6CCC = 1;
        break;
    default:
        TLobby__data_805D6CCC = 1;
        break;
    }
    GbaJoybootState* q = TLobby__data_805434A8;
    q->timeout_counter = q->timeout_counter + 1;
    if ((f32)q->timeout_counter >= 120.0f) {
        TLobby__data_805434A8[0].timeout_counter = 0x78;
        TLobby__data_805D6CCC = 2;
    }
}

void TLobby::send_data(const char *filename) {
    u32 resource_file_size;

    resource_file_size = get_resource_file_size(filename);
    gba_download_data_size = resource_file_size;
    if (resource_file_size > 0x40000U) {
        gba_download_data_size = 0U;
        return;
    }
    if (gba_download_data_buffer != NULL) {
        read_disc_file(filename, gba_download_data_buffer);
        return;
    }
    gba_download_data_size = 0U;
}

void TLobby::update_alloc_size() {
    u32 temp_r3;

    temp_r3 = TAdWarningBaseGC__sub_8032D020();
    gba_download_data_size = temp_r3;
    if (temp_r3 > 0x40000U) {
        gba_download_data_size = 0U;
        return;
    }
    if (gba_download_data_buffer != NULL) {
        TAdWarningBaseGC::load_from_aram_sync(reinterpret_cast<saddr>(gba_download_data_buffer));
        gba_download_data_size = TAdWarningBaseGC::get_alloc_size();
        return;
    }
    gba_download_data_size = 0U;
}

void gba_init(void) { GBAInit(); }

u8 TLobby::get_selected_slot() {
    u8 percentp;

    if (TLobby__sub_801F34F8() == 3) {
        if (GBAGetProcessStatus(3, &percentp) == 0) {
            return 0U;
        }
        if ((u32) gba_download_graph != 0U) {
            TDLGraph::update_graph(percentp + 1, 0x65);
        }
        return percentp;
    }
    return 0U;
}

#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
GbaJoybootState TLobby__data_805434A8[1];

struct DateStamp_8032C9A8 { s32 days; s32 mins; s32 ticks; };

struct Rec_8032C9A8 { u32 a; u32 b; u32 c; };

extern "C" {


#pragma push
#pragma fp_contract on
void stamp_joyboot_image(s32 arg0, s32 arg1) {
    u32 secs;
    Rec_8032C9A8 rec;
    DateStamp_8032C9A8 ds;
    u8 *obj;
    u8 *st;
    memset(&rec, 0, 0xC);
    obj = gba_joyboot_send_buffer;
    st = TAdSinglePlyChrSelectGC::get_global_state();
    if (st != 0) {
        if (arg1 != 0) {
            getDateStamp((DateStamp *)&ds);
            DateToSeconds((DateStamp *)&ds, (int *)&secs);
            secs = 100.0f * (3.0517578e-05f * rand()) + secs;
            memmove(&rec.a, st + 0x118, 4);
            memmove(&rec.b, &secs, 4);
            memmove(obj + 0x2C0, &rec, 8);
        }
        memset(obj + 0xCC, (u8) current_language, 1);
    }
}
#pragma pop

void TLobby::calc_joyboot_checksum() {
    u8 *q;
    s32 i;
    u8 *data = gba_joyboot_send_buffer;
    s32 k;
    u8 c;
    for (i = 0; i < 4; i++) {
        data[0xAC + i] = joyboot_game_code[i];
    }
    q = data + 0xA0;
    c = 0xE7;
    k = 0xA0;
    for (i = 0; i < 0x1D; i++) {
        k++;
        c -= *q++;
    }
    data[k] = c;
}

s32 TLobby::start_gba_joyboot() {
    if (GBAJoyBootAsync(3, 0, 4, gba_joyboot_send_buffer, gba_joyboot_send_length, &gba_joyboot_status, gba_joyboot_transfer_callback) == 0) {
        TLobby__data_805D6CCC = 3;
        return 1;
    }
    TLobby__data_805D6CCC = 1;
    return 0;
}
}

void probe_gba_device(void) {
    TLobby__data_805434A8[0].probe_counter = TLobby__data_805434A8[0].probe_counter + 1;
    if (SIProbe(3) == 0x40000) {
        TLobby__data_805434A8[0].probe_counter = 0;
        TLobby__data_805434A8[0].device_present = 1;
    } else {
        if (TLobby__data_805434A8[0].probe_counter >= 120.0f) {
            *(volatile u16 *)&TLobby__data_805434A8[0].probe_counter = 0x78;
            *(volatile s8 *)&TLobby__data_805434A8[0].device_present = 0;
            *(volatile s32 *)&TLobby__data_805D6CCC = 2;
        } else {
            *(volatile s32 *)&TLobby__data_805D6CCC = 1;
        }
    }
}

void update_gba_joyboot_transfer(void) {
    probe_gba_device();
    if (TLobby__sub_801F34F8() == 2) {
        TLobby__data_805434A8[0].phase = 0;
    }
    switch (TLobby__data_805434A8[0].phase) {
    case 0:
        if (TLobby__data_805434A8[0].device_present != 0) {
            TLobby__data_805434A8[0].phase = 1;
        }
        break;
    case 1:
        stamp_joyboot_image(*(u16 *)&lbl_805D6CDA - 1, lbl_805D6CD9);
        TLobby__sub_8032CDC0();
        TLobby::calc_joyboot_checksum();
        TLobby__data_805434A8[0].phase = 2;
        break;
    case 2:
        if (TLobby__data_805434A8[0].device_present != 0) {
            TLobby::start_gba_joyboot();
            if (TLobby__sub_801F34F8() != 1) {
                TLobby__data_805434A8[0].phase = 3;
            }
            GbaJoybootState *q = TLobby__data_805434A8;
            q->timeout_counter = q->timeout_counter + 1;
            if ((f32)q->timeout_counter >= 120.0f) {
                TLobby__data_805434A8[0].timeout_counter = 0x78;
                TLobby__data_805D6CCC = 2;
            }
        }
        break;
    case 3:
        if (TLobby__sub_801F34F8() != 4 && TLobby__sub_801F34F8() != 3) {
            TLobby__data_805434A8[0].phase = 0;
        }
        break;
    }
}

#pragma push
#pragma optimization_level 1
#pragma dont_inline on

void TLobby::set_send_buffer(u8 *arg0, s32 arg1) {
    gba_joyboot_send_buffer = arg0;
    gba_joyboot_send_length = arg1;
    gba_joyboot_status = 0;
    reset_joyboot_state(TLobby__data_805434A8);
    TLobby__data_805D6CCC = 0;
}
#pragma pop

void TLobby__sub_8032CDC0(void) { lbl_805D6CD9 = 0; lbl_805D6CDA = 0; }

void reset_joyboot_state(void* p) { *(s16*)((char*)p + 0x0) = 0; *(s16*)((char*)p + 0x2) = 0; *(s16*)((char*)p + 0x4) = 0; *(u8*)((char*)p + 0x6) = 0; *(u8*)((char*)p + 0x7) = 0; }
