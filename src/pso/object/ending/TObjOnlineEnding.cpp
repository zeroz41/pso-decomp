#include "pso/system/CharacterSaveRecordLookup.h"
#include "types.h"
#include "pso/object/ending/TObjOnlineEnding.h"


s32 TObjOnlineEnding::get_card_window_value() {
    if (reinterpret_cast<const void *>(get_character_save_record(0xFFFF)) == NULL) {
        return (s16)(0x3E7);
    }
    return (s16)(*(s16 *)((s8 *)(get_character_save_record(0xFFFF)) + 0x2228));
}
