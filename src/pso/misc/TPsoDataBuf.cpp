#include "pso/packet_classes.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TPlyJoinLobbyEntry.h"
#include "pso/system/debug_print.h"
#include <stdio.h>
#include "pso/map/FloorArea.h"

extern "C" {
extern PsoCommandHandler pso_command_dispatch_table[];
extern u8 subcommand_area_masks[];
extern char lbl_8044975C[];
}

void TPsoDataBuf::recv_pso_data_buf(size_t size) {
    char message[0x80];
    s32 remaining;
    game_command_header *command;
    u8 *cursor;
    cursor = (u8 *)this;
    remaining = size;

    while (remaining > 0) {
        command = (game_command_header *)cursor;
        ((TLobby *)command)->bswap_packet_header();
        if ((u8)command->size != 0) {
            u32 command_size = (u8)command->size * 4;
            cursor += command_size;
            remaining -= command_size;
            ((TLobby *)command)->bswap_packet_header();
        } else {
            ((TLobby *)command)->bswap_packet_header();
            extended_game_command_header *extended = (extended_game_command_header *)cursor;
            bswap_extended_subcommand_header(extended);
            cursor += extended->size;
            remaining -= extended->size;
            bswap_extended_subcommand_header(extended);
        }

        for (s32 i = 0; pso_command_dispatch_table[i].command != 0; i++) {
            if ((u8)command->command == pso_command_dispatch_table[i].command) {
                sprintf(message, lbl_8044975C, (u8)command->command, (u8)command->size);
                debug_print(message);
                if (pso_command_dispatch_table[i].area_mask & subcommand_area_masks[get_current_floor_area()]) {
                    pso_command_dispatch_table[i].handle(command);
                }
                break;
            }
        }
    }
}
