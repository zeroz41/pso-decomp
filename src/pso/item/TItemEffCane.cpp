#include "pso/item/TItemEffCane.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/item/TItem.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/misc/TNowLoading.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
u32 test_flags_1b8__11TItemWeaponFUl(TItem* item, u32 flags);
extern const char* TItemEffCane__class_name;
}

void TItemEffCane::run_task() {
    f32 position[3];
    TItem* item = (TItem *)find_item_by_id(item_id);
    if (item == NULL) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    if (((TItem *)item)->get_mode() != 2 ||
        test_flags_1b8__11TItemWeaponFUl(item, 0x10) == 0 || effect == NULL) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    ((TObjPlayer *)item)->draw_icon((s32)attachment_index, (s32)position);
    ((TNowLoading *)effect)->copy_pos(position);
}

TItemEffCane::~TItemEffCane() {
    TBoss4Type2::request_destroy((u32)effect);
}

TItemEffCane::TItemEffCane(TObject* parent, TItem* item, s32 attachment, s32 effect_id)
    : TObject(parent) {
    f32 position[3];
    m_name = TItemEffCane__class_name;
    item_id = ((TItem *)item)->get_item_id();
    attachment_index = attachment;
    ((TObjPlayer *)item)->draw_icon((s32)attachment_index, (s32)position);
    if (effect_id != -1) {
        effect = create_particle_emitter(position, effect_id);
    } else {
        effect = NULL;
    }
    disallow_rendering__7TObjectFv(this);
}
