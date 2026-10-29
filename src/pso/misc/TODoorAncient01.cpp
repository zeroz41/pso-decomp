#include "types.h"
#include "pso/misc/TODoorAncient01.h"
#include "pso/misc/TODoorBase.h"

extern const float lbl_805DB3DC;

TODoorBase::TODoorBase(TObject *parent) : TObjMapObject(parent) {
    switch_id = -1;
    lock_mode = 0;
    door_flags = 0;
    m_ac = 0;
    m_b8 = lbl_805DB3DC;
}

void TODoorBase::update_demo() {}
void TODoorAncient01::update_demo() {}
