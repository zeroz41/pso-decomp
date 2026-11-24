#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/network/TProtocol.h"
#include "pso/ui/window/TWindowSubComCard_80077788.h"
#include "pso/system/CharacterSaveRecordLookup.h"

void TLobby::send_packet(s32 arg0, s32 src) {
    TPlyChoiceSearchConfig parameters;

    copy_choice_search_selections((ChoiceSearchSelection *)(saddr)src, &parameters);
    protocol_instance->send_choice_search(parameters);
}
