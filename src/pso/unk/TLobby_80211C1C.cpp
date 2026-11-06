#include "types.h"
#include "pso/unk/TLobby.h"

extern "C" {

int get_selected_quest_id__16TQuestListOnlineFv(void*);

int TLobby::get_selected_quest_id() { return get_selected_quest_id__16TQuestListOnlineFv(this); }

}
