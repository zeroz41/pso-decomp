#include "types.h"
#include "pso/ui/charcreate/TObjCMIcon.h"
#include "pso/system/task/TObject.h"
extern "C" { extern char TObjCMIcon__class_name_string[]; }
const char *cm_icon_name_ptr = TObjCMIcon__class_name_string;


void *TObjCMIcon::create(void *object) {
    return new TObjCMIcon((TObject *)object);
}

CreationIconGroup TObjCMIcon__icon_group_table[7] = {
    {2, {0x38, 0xA8, 0, 0}},
    {2, {0x38, 0xA9, 0, 0}},
    {2, {0x38, 0xAA, 0, 0}},
    {3, {0x38, 0x37, 0xAA, 0}},
    {2, {0x37, 0xA7, 0, 0}},
    {2, {0x37, 0xAB, 0, 0}},
    {2, {0x37, 0xAC, 0, 0}},
};
__declspec(section ".data") vec2f cm_icon_screen_position = {604.0f, 443.0f};

TObjCMIcon::~TObjCMIcon() {}


TObjCMIcon::TObjCMIcon(TObject *parent) : TObject(parent) {
    m_name = cm_icon_name_ptr;
}
