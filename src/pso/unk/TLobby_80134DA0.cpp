#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TProtocol.h"
#include "pso/network/protocol/choice_search.h"

extern "C" s32 set_clock_offset_from_server_time();

void TLobby::set_lobby_event_theme(int theme) { event_theme_id = theme; }

void TLobby::handle_info_board(TRecvInfoBoard *info_board) { init_once(info_board); }
void TLobby::handle_choice_search_results(ChoiceSearchResultList *results) { store_choice_search_results(results); }
void TLobby::handle_choice_search_options(TRecvChoiceSearchOptions *options) { store_choice_search_options(options); }

void TLobby::reset_lobby_state() {
    set_clock_offset_from_server_time();
    protocol_instance->send_server_time_accepted();
}
