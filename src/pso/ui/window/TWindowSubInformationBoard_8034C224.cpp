#include "types.h"
#include "pso/ui/window/TWindowSubInformationBoard.h"

extern u32 information_board_response_buffer;

void TWindowSubInformationBoard::clear_if_current(u32 arg0) {
    if ((u32) information_board_response_buffer == arg0) {
        information_board_response_buffer = 0U;
    }
}
