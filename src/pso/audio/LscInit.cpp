// CRI LSC init and finish (lsc_ini.c in other CRI builds): the stream table and the build string.
#include "pso/audio/LscStream.h"
#include "pso/unk/TLobby.h"
#include <string.h>

extern "C" {
void notify_dvd_read__6TLobbyFv(void *);
void enter_lock__6TLobbyFv(void *);

const char *const volatile lsc_version_string = "\nLSC/GC Ver 2.07 Build:Jun 13 2002 19:00:24\n";
s32 lsc_init_count;
LscStream lsc_slot_table[16];

void lsc_shutdown(void) {
    u8 lock[8];
    s32 i;
    ((void (*)(void *))enter_lock__6TLobbyFv)(lock);
    if (--lsc_init_count == 0) {
        for (i = 0; i < 16; i++) {
            if ((s32)lsc_slot_table[i].in_use == 1) {
                lsc_destroy(&lsc_slot_table[i]);
            }
        }
        memset(lsc_slot_table, 0, sizeof(lsc_slot_table));
        TLobby::set_callback(0, 0);
    }
    ((void (*)(void *))notify_dvd_read__6TLobbyFv)(lock);
}

void lsc_init(void) {
    u8 lock[8];
    lsc_version_string;
    ((void (*)(void *))enter_lock__6TLobbyFv)(lock);
    if (lsc_init_count == 0) {
        memset(lsc_slot_table, 0, sizeof(lsc_slot_table));
        TLobby::set_callback(0, 0);
    }
    lsc_init_count++;
    ((void (*)(void *))notify_dvd_read__6TLobbyFv)(lock);
}
}
