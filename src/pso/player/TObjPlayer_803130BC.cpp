#include "pso/player/PhotonBlastRequests.h"
#include "pso/player/PhotonBlastResults.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/TObjPlayer_803130BC.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
s32 test_flags_any(s32 *flags, s32 mask);

void PhotonBlastRequest::update_children() {
    int count = get_max_children(this);
    for (int i = 0; i < count; i++) {
        slots[i].clear();
    }
}

s16 PhotonBlastRequest::get_kind() {
    if (((kind < 0) || (kind >= 6)) && (kind != -1)) {
        return 0;
    }
    return kind;
}

void PhotonBlastRequest::reset() {
    client_id = 0xFFFF;
    kind = -1;
    flags.reset();
    update_children();
}

int PhotonBlastGauge::query_field40() { return test_flags_any(&flags.bits, 4); }
int TObjPlayer__sub_803131AC(const PhotonBlastRegistry *) { return 4; }

PhotonBlastRequestSlot *TObjPlayer__sub_803131B4(PhotonBlastRequest *slot, s32 index) {
    return &slot->slots[index];
}

void PhotonBlastRegistry::process_indexed_element(s32 index) {
    slots[index].reset();
}

void PhotonBlastRequest::check_flag_at_4() { flags.set(1); }
int TObjPlayer__sub_80313218(PhotonBlastRequest *slot) { return test_flags_any(&slot->flags.bits, 1) == 0; }
void PhotonBlastRequestSlot::set_client_id(u16 id) { client_id = id; }
void TObjPlayer__sub_80313250(PhotonBlastRequestSlot *entry, s32 amount) {
    entry->amount += amount;
}
int PhotonBlastRequest::get_max_children(const PhotonBlastRequest *) { return 4; }

}
