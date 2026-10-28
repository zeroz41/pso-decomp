#include "types.h"
#include "pso/misc/TLobby_8001D6A0.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {

void __dt__5THeapFv(void*, int);

extern u32 TLobby__data_805D6104;
extern u32 TLobby__data_805D6108;
extern u32 TLobby__data_805D6138;
extern u32 TLobby__data_805D613C;
extern u32 quest_object_entries;
extern u32 TLobby__data_805D6144;

void TLobby::free_resources() {
    if ((u32) TLobby__data_805D6144 != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((u32)((void*)TLobby__data_805D6144));
        TLobby__data_805D6144 = 0U;
    }
    if ((u32) quest_object_entries != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((u32)((void*)quest_object_entries));
        quest_object_entries = 0U;
    }
    if ((u32) TLobby__data_805D6108 != 0U) {
        __dt__5THeapFv((void*)TLobby__data_805D6108, 1);
        TLobby__data_805D6108 = 0U;
    }
    if ((u32) TLobby__data_805D6104 != 0U) {
        free_and_delete__6TLobbyFPvs((u32 *)TLobby__data_805D6104, 1);
        TLobby__data_805D6104 = 0U;
    }
    if ((u32) TLobby__data_805D613C != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((u32)((void*)TLobby__data_805D613C));
        TLobby__data_805D613C = 0U;
    }
    if ((u32) TLobby__data_805D6138 != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((u32)((void*)TLobby__data_805D6138));
        TLobby__data_805D6138 = 0U;
    }
}

}
