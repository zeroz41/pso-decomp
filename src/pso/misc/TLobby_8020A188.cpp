#include "types.h"
#include "pso/misc/TLobby_8020A188.h"
#include "pso/system/memory.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestVmDownLoadServer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {

int free_boss4rock__6TLobbyFs(void*, void*);
u32 find_type5_header__6TLobbyFPvi(s32, s32);
u32 find_chunk_by_id__6TLobbyFPvi(s32, s32);
u32 find_header_by_id__6TLobbyFPvi(s32, s32);
s32 TLobby__sub_80209D34(s32);

extern u32 lbl_805D60A8;
extern u32 lbl_805D60AC;
extern u32 TLobby__item_data_table_buffer;
extern s32 lbl_805D60B4;
extern s32 lbl_805D60BC;
extern s32 lbl_805D60C0;
extern s32 lbl_805D60C4;
extern s32 lbl_805D60C8;

void init_buffers__6TLobbyFii(s32 id, s32 arg1) {
    u32 temp_r3;

    lbl_805D60A8 = find_header_by_id__6TLobbyFPvi(arg1, id);
    lbl_805D60AC = find_chunk_by_id__6TLobbyFPvi(arg1, id);
    temp_r3 = find_type5_header__6TLobbyFPvi(arg1, id);
    TLobby__item_data_table_buffer = temp_r3;
    if (((u32) lbl_805D60A8 != 0U) && ((u32) lbl_805D60AC != 0U) && (temp_r3 != 0U)) {
        lbl_805D60B4 = (s32)TQuestVmDownLoadServer::alloc(0x9000);
        lbl_805D60BC = (s32)TQuestVmDownLoadServer::alloc(0x1400);
        lbl_805D60C0 = 0;
        lbl_805D60C4 = (s32)TQuestVmDownLoadServer::alloc(0x1000);
        lbl_805D60C8 = 0;
        TLobby__sub_80209D34(id);
        TAdSinglePlyChrSelectGC::safe_free(lbl_805D60C4);
        TAdSinglePlyChrSelectGC::safe_free(lbl_805D60BC);
        lbl_805D60BC = 0;
        TAdSinglePlyChrSelectGC::safe_free(lbl_805D60B4);
        lbl_805D60B4 = 0;
    }
}

    extern int item_drop_rng;
    extern int lbl_805D60A4;
void TLobby::free_boss4rock() { free_boss4rock__6TLobbyFs((void*)lbl_805D60A4, (void*)1); lbl_805D60A4 = 0; ::operator delete((void *)item_drop_rng); item_drop_rng = 0; }

}
