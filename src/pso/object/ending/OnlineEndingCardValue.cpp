#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"
#include "pso/object/ending/TObjOnlineEnding.h"


s32 TObjOnlineEnding::get_card_window_value() {
    if (get_character_save_record(0xFFFF) == NULL) {
        return (s16)(0x3E7);
    }
    return get_character_save_record(0xFFFF)->challenge.tombstone.deaths;
}
