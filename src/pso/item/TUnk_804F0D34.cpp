#pragma readonly_strings on
#define TOBJECT_OUT_OF_LINE_HELPERS

#include "types.h"
#include "pso/TObject.h"
#include "pso/TMainTask.h"
#include "pso/item/TItemObject.h"
#include "pso/item/TUnk_804F0D34.h"
#include "pso/item/TItemObject_80115D6C.h"
#include "pso/misc/TLoadCtrl_80227390.h"
#include "pso/object/TObjBgmColCtrl_8017E8E4.h"
#include "pso/object/TUnk_804F0D1C.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"

/* Transitional until TItem's virtual block, TItemObject's constructor and the
   object-heap allocator's return type are real (see report). */
extern "C" {
void *__nw__5TItemFUl(u32 size);
extern void *item_object_dispatch_table[];
}

static char *event_music_adx_table[] = {
    "WEDDING.adx",
    "Event.adx",
    "hearts.adx",
    "open.adx",
    "Live.adx",
    "DreamS_KIDS.adx",
    "ED_PIANO.adx",
};

static TUnk_804F0D1C *pending_destroy_object;

void TUnk_804F0D1C::run_task() {
    if (get_quest_bgm_issued_flag() != 0) {
        queue_destruction();
    }
}

TUnk_804F0D1C::~TUnk_804F0D1C() {
    if (pending_destroy_object == this) {
        pending_destroy_object = NULL;
    }
}

TUnk_804F0D1C::TUnk_804F0D1C(TObject *parent, u32 track) : TObject(parent) {
    if (pending_destroy_object != NULL) {
        pending_destroy_object->queue_destruction();
    }
    pending_destroy_object = this;
    play_area_music(event_music_adx_table[track]);
}

void create_quest_bgm_object(TObject *parent, u32 track) {
    if (track >= 7) {
        track = 0;
    }
    if (get_quest_bgm_issued_flag() == 0) {
        new TUnk_804F0D1C(tl_05, track);
    }
}

void TUnk_804F0D34::vfunc_44() {
    create_quest_bgm_object(tl_05, get_item_index());
}

extern "C" {

void *__dt__13TUnk_804F0D34Fv(TUnk_804F0D34 *self, s16 mode) {
    if (self != NULL) {
        *(void ***)((u8 *)self + 0x18) = item_object_dispatch_table;
        __dt__11TItemObjectFv(self, 0);
        if (mode > 0) {
            TItem::operator delete(self);
        }
    }
    return self;
}

TUnk_804F0D34 *fn_80350588(TUnk_804F0D34 *self, TObject *parent, void *item) {
    TItemObject__ct(self, parent, item);
    *(void ***)((u8 *)self + 0x18) = item_object_dispatch_table;
    return self;
}

TUnk_804F0D34 *fn_803505C4(void *item) {
    if (item != NULL) {
        TUnk_804F0D34 *obj = (TUnk_804F0D34 *)__nw__5TItemFUl(sizeof(TUnk_804F0D34));
        if (obj != NULL) {
            obj = fn_80350588(obj, tl_05, item);
        }
        return obj;
    }
    return NULL;
}

}
