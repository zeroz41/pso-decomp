#include "types.h"
#include "pso/unk/text_801E3F24.h"
#include "pso/system/debug_print.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/map/CurrentArea.h"

struct Ent_801E3FA4 {
    u16 id;
    u16 mask;
    void (*fn)(void *);
};

struct Msg_801E3FA4 {
    u8 a;
    u8 b;
};

extern "C" {
int sprintf(char *, const char *, ...);
extern char pso_data2_receive_log_format[];
extern u8 subcommand_area_masks[];
extern Ent_801E3FA4 pso_command_dispatch_table[];
void dispatch_6x_subcommand(Msg_801E3FA4 *arg0);
s32 TObjDoorKey__sub_8018FAEC(u16, u16);
s32 bswap_switch_activate_token__6TLobbyFv();

void TObjPlayer__sub_801E3F24(s32 arg0) {
    *(s32 *)0xCC008000 = arg0;
}

void TObjPlayer__sub_801E3F30(f32 farg0, f32 farg1, f32 farg2) {
    *(f32 *)0xCC008000 = farg0;
    *(f32 *)0xCC008000 = farg1;
    *(f32 *)0xCC008000 = farg2;
}

void fn_801E3F44(f32 farg0, f32 farg1) {
    *(f32 *)0xCC008000 = farg0;
    *(f32 *)0xCC008000 = farg1;
}

void TObjCMHairMenu__sub_801E3F54(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); }
}

void handle_6x9E_player_camera_shutter_sound(void) {

}

void handle_6x04_legacy_activate_switch_by_token(void *arg0) {
    bswap_switch_activate_token__6TLobbyFv();
    TObjDoorKey__sub_8018FAEC(*(u16 *)((s8 *)arg0 + 2), *(u16 *)((s8 *)arg0 + 4));
}

void handle_6x03(void) {  }
void handle_6x02(void) {  }

void dispatch_6x_subcommand(Msg_801E3FA4 *arg0) {
    s32 i;
    char buf[0x80];
    s32 key = arg0->a;
    for (i = 0; pso_command_dispatch_table[i].id != 0; i++) {
        if (key == pso_command_dispatch_table[i].id && (pso_command_dispatch_table[i].mask & subcommand_area_masks[get_current_area()])) {
            sprintf(buf, pso_data2_receive_log_format, arg0->a, arg0->b);
            debug_print(buf);
            pso_command_dispatch_table[i].fn(arg0);
            return;
        }
    }
}
