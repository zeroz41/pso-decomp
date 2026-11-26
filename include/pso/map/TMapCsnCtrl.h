#ifndef PSO_MAP_TMAPCSNCTRL_H
#define PSO_MAP_TMAPCSNCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <stddef.h>

struct CsnGroup;

class TMapCsnCtrl : public TObject {
public:
    static const char *class_name;
    TMapCsnCtrl(TObject *parent);
    virtual ~TMapCsnCtrl();
    void clear_groups();
    CsnGroup **get_collision_groups();

    CsnGroup *groups[0x200];
};
LAYOUT_ASSERT(TMapCsnCtrlExtent, sizeof(TMapCsnCtrl) == 0x81C);

LAYOUT_ASSERT(TMapCsnCtrlGroupsOffset, offsetof(TMapCsnCtrl, groups) == 0x1C);

struct TObjMapCsn;

extern "C" {
void remove_map_collision(TMapCsnCtrl *controller, TObjMapCsn *object);
}
void remove_collision_group(TMapCsnCtrl *controller, CsnGroup *group);
extern "C" {
void register_map_collision(TMapCsnCtrl *controller, TObjMapCsn *object);
}
void register_slot(TMapCsnCtrl *controller, CsnGroup *group);
void collect_collision_groups(TMapCsnCtrl *controller, CsnGroup *groups);

#endif
