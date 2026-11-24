#include "types.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/WindowSpritePart.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TWindowStatusGauge.h"
#include "pso/unk/TWindowStatusGaugeFeedback.h"
#include "pso/unk/TUnk_804CF998.h"
#include "pso/unk/TUnk_804CF9C8.h"
#include "pso/unk/TUnk_804EF440.h"
#include "pso/ui/window/TWindowSubStatusDisp_80256B94.h"
#include "pso/ui/window/TWindowSubStatusDisp_80257BC0.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/item/TItemData.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/map/FloorArea.h"
#include "pso/render/render_util.h"
#include "pso/ui/ItemListRow.h"
#include "pso/unk/TWindowLayoutEntry.h"


extern "C" {

struct Desc_80257D44 {
    u32 cols;
    u32 rows;
    u32 recs[1];
};


void * TWindowHelpItem__sub_8025A594(void *, void *, s32);
void * TWindowHelpItem__sub_8025A95C(void *, void *, s32);
}
u8 *construct_text_entry(u8 *arg0, u8 *arg1, s32 arg2);
extern "C" {

__declspec(section ".sdata2") f32 lbl_805DCEF0 = 7.5f;

void draw_visible_window_entries(const void *, const WindowLayoutEntries *entries, WindowDrawContext *context) {
    void *const *part;
    u32 remaining;
    for (remaining = entries->count, part = entries->items; remaining != 0; remaining--, part++) {
        TWindowLayoutEntry *entry = static_cast<TWindowLayoutEntry *>(*part);
        if (!(entry->flags & 2)) {
            entry->render(context);
        }
    }
}

void TWindowBase::update_window_entry_list(const WindowLayoutEntries *entries) {
    void *const *part;
    u32 remaining;
    if (!(window_flags & 0x2000) && (f32)open_tick < lbl_805DCEF0) {
        return;
    }
    remaining = entries->count;
    part = entries->items;
    while (remaining-- != 0) {
        static_cast<TWindowLayoutEntry *>(*part)->update();
        part++;
    }
}

void WindowLayoutEntries::destroy_all_items() {
    uaddr address;
    u32 remaining;
    remaining = count;
    if (remaining != 0) {
        address = reinterpret_cast<uaddr>(items);
        address += (remaining - 1) * sizeof(*items);
        // Use a target address so the final decrement forms no out-of-bounds pointer.
        while (remaining-- != 0) {
            delete static_cast<TWindowLayoutEntry *>(*reinterpret_cast<void **>(address));
            address -= sizeof(*items);
        }
        mem_free(items);
        count = 0;
        items = NULL;
    }
}

void init_window_layout_entries(WindowLayoutEntries *entries, const void *layout, s32 client) {
    const Desc_80257D44 *desc = static_cast<const Desc_80257D44 *>(layout);
    u32 cols;
    u32 rows;
    u32 *rec;
    void **out;
    void *o;
    if (desc == NULL) {
        entries->count = 0;
        entries->items = NULL;
        return;
    }
    rows = desc->rows;
    entries->count = desc->cols * rows;
    if (entries->count == 0) {
        entries->count = 0;
        entries->items = NULL;
        return;
    }
    entries->items = (void **)mem_alloc(entries->count * 4);
    out = entries->items;
    while (rows-- != 0) {
        cols = desc->cols;
        rec = const_cast<u32 *>(desc->recs);
        while (cols-- != 0) {
            switch (*rec) {
            case 0:
                o = ::operator new(0x18);
                if (o != NULL) {
                    o = __ct__13TUnk_804CF998FPUcl(o, (u8 *)rec, client);
                }
                *out = o;
                rec += 0x14 / 4;
                break;
            case 1:
                o = new TWindowStatusGauge(reinterpret_cast<StatusGaugeLayout *>(rec), client);
                *out = o;
                rec += sizeof(StatusGaugeLayout) / 4;
                break;
            case 2:
                o = new TWindowStatusGaugeFeedback(reinterpret_cast<LayoutEntryCopyRecord *>(rec), client);
                *out = o;
                rec += sizeof(LayoutEntryCopyRecord) / 4;
                break;
            case 3:
                o = ::operator new(0x2C);
                if (o != NULL) {
                    o = construct_text_entry((u8 *)o, (u8 *)rec, client);
                }
                *out = o;
                rec += 0x1C / 4;
                break;
            case 4:
                o = ::operator new(0x24);
                if (o != NULL) {
                    o = __ct__13TUnk_804CF9C8FPUcl(o, (u8 *)rec, client);
                }
                *out = o;
                rec += 0x1C / 4;
                break;
            case 5:
                o = ::operator new(0x30);
                if (o != NULL) {
                    o = __ct__13TUnk_804CF9E0FPUcl(o, (u8 *)rec, client);
                }
                *out = o;
                rec += 0x1C / 4;
                break;
            case 6:
                o = ::operator new(sizeof(WindowSpritePart));
                if (o != NULL) {
                    o = static_cast<WindowSpritePart *>(o)->init_part_scaled(reinterpret_cast<SpritePartLayoutRecord *>(rec), client);
                }
                *out = o;
                rec += sizeof(SpritePartLayoutRecord) / 4;
                break;
            case 7:
                o = ::operator new(sizeof(WindowSpritePart));
                if (o != NULL) {
                    o = static_cast<WindowSpritePart *>(o)->init_part_direct(reinterpret_cast<DirectSpritePartLayoutRecord *>(rec), client);
                }
                *out = o;
                rec += sizeof(DirectSpritePartLayoutRecord) / 4;
                break;
            case 8:
                o = ::operator new(0x38);
                if (o != NULL) {
                    o = __ct__11ItemListRowFPUcl(o, (u8 *)rec, client);
                }
                *out = o;
                rec += 1;
                break;
            case 9:
                o = ::operator new(0x28);
                if (o != NULL) {
                    o = ((TWindowSubComCard *)o)->init_fields((saddr)rec, (int)client);
                }
                *out = o;
                rec += 1;
                break;
            case 10:
                o = ::operator new(0x14);
                if (o != NULL) {
                    o = TWindowHelpItem__sub_8025A95C(o, rec, client);
                }
                *out = o;
                rec += 0xC / 4;
                break;
            case 11:
                o = ::operator new(0x24);
                if (o != NULL) {
                    o = TWindowHelpItem__sub_8025A594(o, rec, client);
                }
                *out = o;
                rec += 0xC / 4;
                break;
            case 12:
                o = ::operator new(0x28);
                if (o != NULL) {
                    o = __ct__13TUnk_804EF440FPUcl(o, (u8 *)rec, client);
                }
                *out = o;
                rec += 1;
                break;
            }
            out++;
        }
    }
}
}
