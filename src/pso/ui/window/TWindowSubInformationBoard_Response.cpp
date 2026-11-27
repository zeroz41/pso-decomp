#include "types.h"
#include "pso/network/InfoBoardState.h"
#include "pso/ui/window/TWindowSubInformationBoard.h"
#include "pso/network/InfoBoardState.h"


void TWindowSubInformationBoard::clear_if_current(TRecvInfoBoard *board) {
    if (information_board_response_buffer == board) {
        information_board_response_buffer = NULL;
    }
}
