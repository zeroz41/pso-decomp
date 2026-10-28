#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TObjPlayer_80363BE0.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/player/TUnk_804F29F8.h"
#include "pso/item/EquippedItemDrawQueue.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80141D1C.h"

struct DrawPrefix { u8 prefix[0x18]; };

struct DrawTarget : DrawPrefix {
    virtual void reserved0();
    virtual void reserved1();
    virtual void reserved2();
    virtual void reserved3();
    virtual void reserved4();
    virtual void reserved5();
    virtual void reserved6();
    virtual void reserved7();
    virtual void reserved8();
    virtual void reserved9();
    virtual void reserved10();
    virtual void reserved11();
    virtual void reserved12();
    virtual void reserved13();
    virtual void reserved14();
    virtual void reserved15();
    virtual void reserved16();
    virtual void reserved17();
    virtual void reserved18();
    virtual void reserved19();
    virtual void reserved20();
    virtual void reserved21();
    virtual void reserved22();
    virtual void reserved23();
    virtual void render();
};

struct Color { f32 a, r, g, b; };

extern "C" {
extern u32 model_render_flags, chunk_polygon_flags_and_mask, chunk_polygon_flags_or_mask;
extern u32 saved_model_render_flags, saved_chunk_polygon_flags_and_mask, saved_chunk_polygon_flags_or_mask;
extern Color saved_model_draw_color, model_material_color;
extern EquippedItemDrawQueue *player_item_id_list;

void TItem::push_equipped_id(s32 id) { ((TObjPlayer *)player_item_id_list)->push_to_list(id); }
void TUnk_804F29F8::render() {
    set_default_alpha_blend();
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    copy_argb((NJS_ARGB *)&saved_model_draw_color, (NJS_ARGB *)&model_material_color);
    u32 *id = player_item_id_list->item_ids;
    s32 remaining = player_item_id_list->count;
    while (remaining != 0) {
        DrawTarget *item = (DrawTarget *)find_equipped_item(*id++);
        if (item) {
            item->render();
            set_default_alpha_blend();
            copy_argb((NJS_ARGB *)&model_material_color, (NJS_ARGB *)&saved_model_draw_color);
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            model_render_flags = saved_model_render_flags;
        }
        --remaining;
    }
}

}
