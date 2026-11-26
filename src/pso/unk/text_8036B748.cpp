#include "types.h"
#include "pso/unk/text_8036B748.h"
#include "pso/network/protocol/protocol_types.h"

extern "C" {
s32 validate_subcommand_client();
}

s32 validate_6x0D_remove_status_effect(G_ClientIDHeader *packet) {
    return validate_subcommand_client() ? 1 : 0;
}
s32 validate_6x0C_add_status_effect(G_ClientIDHeader *packet) {
    return validate_subcommand_client() ? 1 : 0;
}

extern "C" {
s32 fn_8036B798(void) {
    return validate_subcommand_client() ? 1 : 0;
}
s32 fn_8036B7C0(void) {
    return validate_subcommand_client() ? 1 : 0;
}

}
