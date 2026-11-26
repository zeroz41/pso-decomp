#include "types.h"
#include "pso/ui/window/TWindowSubInformationBoard.h"

extern u32 information_board_response_buffer;

void TWindowSubInformationBoard::clear_if_current(u32 response) {
    if ((u32) information_board_response_buffer == response) {
        information_board_response_buffer = 0U;
    }
}
