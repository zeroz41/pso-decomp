#include "types.h"
#include "pso/enemy/TObjEnemy.h"

#include "pso/unk/TLobby.h"
#include "pso/render/StripBufferPair.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

extern "C" {
extern StripUvRef *plist_strip_write_ptr;
extern s16 *plist_strip_uv_write_ptr;
extern s32 plist_texture_matches_filter;

StripBufferPair::StripBufferPair(NJS_OBJECT *model, s32 texture_filter) {
    strip_count = 0;
    uv_count = 0;
    plist_texture_matches_filter = 0;
    count_model_strips_by_texture(model, texture_filter);
    strips = (StripUvRef *)mem_alloc(strip_count * 8);
    uvs = (s16 *)mem_alloc(uv_count * 4);
    plist_strip_write_ptr = strips;
    plist_strip_uv_write_ptr = uvs;
    plist_texture_matches_filter = 0;
    collect_model_strips_by_texture(model, texture_filter);
}
void TObjEnemy::clear_lobby_object_state() {
    EnemyStateRecord record;
    if (this->exchange_object_state(&record, 1) != 0) {
        record.flags = 0;
        record.damage = 0;
        this->exchange_object_state(&record, 0);
    }
}

}
