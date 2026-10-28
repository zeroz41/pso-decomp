#include "types.h"
#include "pso/misc/TScene_80203304.h"
#include "pso/misc/TContainerAncient01.h"
#include "pso/misc/TScene.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/map/CurrentArea.h"

struct Tbl_8020335C { s32 v[8]; };

extern struct Tbl_8020335C group_selection_area_id_table;
    extern int TScene__render_callback;

s32 *resolve_indirect_object_record(s32 arg0, u8 *arg1) {
    if (*(s32 *)((s8 *)arg1 + 0x1C) & 0x200) {
        return (long *) (**(s32 **)((s8 *)arg1 + 0));
    }
    return *(s32 **)((s8 *)arg1 + 0);
}

s32 *resolve_indirect_node_record(s32 arg0, u8 *arg1) {
    if (*(s32 *)((s8 *)arg1 + 0xC) & 0x200) {
        return (long *) (**(s32 **)((s8 *)arg1 + 0));
    }
    return *(s32 **)((s8 *)arg1 + 0);
}

void TScene::set_instance(int a0) { TScene__render_callback = a0; }

    extern int TScene__active_scene_callback;
void TScene::set_active_scene(int a0) { TScene__active_scene_callback = a0; }

    extern int TScene__map_section_render_callback;
void TScene::set_id(int a0) { TScene__map_section_render_callback = a0; }
s32 TContainerAncient01::is_global_state_in_table() {
    struct Tbl_8020335C t = group_selection_area_id_table;
    s32 state = get_current_area();
    s32 i;
    for (i = 0; t.v[i] != -1;) {
        if (state == t.v[i++]) {
            return 1;
        }
    }
    return 0;
}
