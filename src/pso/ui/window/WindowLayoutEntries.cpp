#include "types.h"
#include "pso/ui/window/WindowLayoutRecord.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/WindowSpritePart.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowStatusGauge.h"
#include "pso/ui/window/TWindowStatusGaugeFeedback.h"
#include "pso/ui/window/TWindowLayoutRect.h"
#include "pso/ui/window/TWindowLayoutNumber.h"
#include "pso/ui/window/TGameListRow.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/technique/TTecRaFoie.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/item/TItemData.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/map/FloorArea.h"
#include "pso/render/render_util.h"
#include "pso/ui/window/ItemListRow.h"
#include "pso/ui/window/TWindowLayoutEntry.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/LabelValueRow.h"
#include "pso/ui/window/HelpItemStatCompareRow.h"
#include "pso/ui/window/HelpItemRarityStarRow.h"


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
    if (!(window_flags & 0x2000) && (f32)open_tick < 7.5f) {
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
        delete[] items;
        count = 0;
        items = NULL;
    }
}

void init_window_layout_entries(WindowLayoutEntries *entries, const void *layout, s32 client) {
    const WindowLayoutEntriesDesc *desc = static_cast<const WindowLayoutEntriesDesc *>(layout);
    u32 cols;
    u32 rows;
    u32 *rec;
    void **out;
    WindowSpritePart *o;
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
    entries->items = new void *[entries->count];
    out = entries->items;
    while (rows-- != 0) {
        cols = desc->cols;
        rec = const_cast<u32 *>(desc->recs);
        while (cols-- != 0) {
            // CodeWarrior: the entry classes are abstract there (their vtables keep calc_bar_width 0),
            // so each one is allocated and constructed by hand.
            switch (*rec) {
            case 0:
#ifdef __MWERKS__
                o = (WindowSpritePart *)(::operator new(0x18));
                if (o != NULL) {
                    o = (WindowSpritePart *)__ct__17TWindowLayoutRectFPUcl(o, (u8 *)rec, client);
                }
#else
                o = (WindowSpritePart *)(new TWindowLayoutRect((u8 *)rec, client));
#endif
                *out = o;
                rec += 0x14 / 4;
                break;
            case 1:
                o = (WindowSpritePart *)(new TWindowStatusGauge(reinterpret_cast<StatusGaugeLayout *>(rec), client));
                *out = o;
                rec += sizeof(StatusGaugeLayout) / 4;
                break;
            case 2:
                o = (WindowSpritePart *)(new TWindowStatusGaugeFeedback(reinterpret_cast<LayoutEntryCopyRecord *>(rec), client));
                *out = o;
                rec += sizeof(LayoutEntryCopyRecord) / 4;
                break;
            case 3:
#ifdef __MWERKS__
                o = (WindowSpritePart *)(::operator new(0x2C));
                if (o != NULL) {
                    o = (WindowSpritePart *)__ct__15WindowTextEntryFP16TextLayoutRecordl(o, reinterpret_cast<TextLayoutRecord *>(rec), client);
                }
#else
                o = (WindowSpritePart *)(new WindowTextEntry(reinterpret_cast<TextLayoutRecord *>(rec), client));
#endif
                *out = o;
                rec += 0x1C / 4;
                break;
            case 4:
#ifdef __MWERKS__
                o = (WindowSpritePart *)(::operator new(0x24));
                if (o != NULL) {
                    o = (WindowSpritePart *)__ct__19TWindowLayoutNumberFP17ValueLayoutRecordl(o, reinterpret_cast<ValueLayoutRecord *>(rec), client);
                }
#else
                o = (WindowSpritePart *)(new TWindowLayoutNumber(reinterpret_cast<ValueLayoutRecord *>(rec), client));
#endif
                *out = o;
                rec += 0x1C / 4;
                break;
            case 5:
#ifdef __MWERKS__
                o = (WindowSpritePart *)(::operator new(0x30));
                if (o != NULL) {
                    o = (WindowSpritePart *)__ct__27TWindowLayoutCountingNumberFP17ValueLayoutRecordl(o, reinterpret_cast<ValueLayoutRecord *>(rec), client);
                }
#else
                o = (WindowSpritePart *)(new TWindowLayoutCountingNumber(reinterpret_cast<ValueLayoutRecord *>(rec), client));
#endif
                *out = o;
                rec += 0x1C / 4;
                break;
            case 6:
#ifdef __MWERKS__
                o = (WindowSpritePart *)(::operator new(sizeof(WindowSpritePart)));
                if (o != NULL) {
                    o = (WindowSpritePart *)__ct__16WindowSpritePartFP22SpritePartLayoutRecordl(o, reinterpret_cast<SpritePartLayoutRecord *>(rec), client);
                }
#else
                o = (WindowSpritePart *)(new WindowSpritePart(reinterpret_cast<SpritePartLayoutRecord *>(rec), client));
#endif
                *out = o;
                rec += sizeof(SpritePartLayoutRecord) / 4;
                break;
            case 7:
#ifdef __MWERKS__
                o = (WindowSpritePart *)(::operator new(sizeof(WindowSpritePart)));
                if (o != NULL) {
                    o = (WindowSpritePart *)__ct__16WindowSpritePartFP28DirectSpritePartLayoutRecordl(o, reinterpret_cast<DirectSpritePartLayoutRecord *>(rec), client);
                }
#else
                o = (WindowSpritePart *)(new WindowSpritePart(reinterpret_cast<DirectSpritePartLayoutRecord *>(rec), client));
#endif
                *out = o;
                rec += sizeof(DirectSpritePartLayoutRecord) / 4;
                break;
            case 8:
#ifdef __MWERKS__
                o = (WindowSpritePart *)(::operator new(0x38));
                if (o != NULL) {
                    o = (WindowSpritePart *)__ct__11ItemListRowFPUcl(o, (u8 *)rec, client);
                }
#else
                o = (WindowSpritePart *)(new ItemListRow((u8 *)rec, client));
#endif
                *out = o;
                rec += 1;
                break;
            case 9:
#ifdef __MWERKS__
                o = (WindowSpritePart *)(::operator new(0x28));
                if (o != NULL) {
                    o = (WindowSpritePart *)__ct__13LabelValueRowFPUcl(o, (u8 *)rec, client);
                }
#else
                o = (WindowSpritePart *)(new LabelValueRow((u8 *)rec, client));
#endif
                *out = o;
                rec += 1;
                break;
            case 10:
#ifdef __MWERKS__
                o = (WindowSpritePart *)(::operator new(0x14));
                if (o != NULL) {
                    o = (WindowSpritePart *)__ct__21HelpItemRarityStarRowFP17PointLayoutRecordl(o, reinterpret_cast<PointLayoutRecord *>(rec), client);
                }
#else
                o = (WindowSpritePart *)(new HelpItemRarityStarRow(reinterpret_cast<PointLayoutRecord *>(rec), client));
#endif
                *out = o;
                rec += 0xC / 4;
                break;
            case 11:
#ifdef __MWERKS__
                o = (WindowSpritePart *)(::operator new(0x24));
                if (o != NULL) {
                    o = (WindowSpritePart *)__ct__22HelpItemStatCompareRowFP17PointLayoutRecordl(o, reinterpret_cast<PointLayoutRecord *>(rec), client);
                }
#else
                o = (WindowSpritePart *)(new HelpItemStatCompareRow(reinterpret_cast<PointLayoutRecord *>(rec), client));
#endif
                *out = o;
                rec += 0xC / 4;
                break;
            case 12:
#ifdef __MWERKS__
                o = (WindowSpritePart *)(::operator new(0x28));
                if (o != NULL) {
                    o = (WindowSpritePart *)__ct__12TGameListRowFPUcl(o, (u8 *)rec, client);
                }
#else
                o = (WindowSpritePart *)(new TGameListRow((u8 *)rec, client));
#endif
                *out = o;
                rec += 1;
                break;
            }
            out++;
        }
    }
}
