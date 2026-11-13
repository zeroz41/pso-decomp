#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/TObjCMIcon.h"
#include "types.h"

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

extern "C" {
extern void *lbl_805D3CF0;
}

TObjCMIcon::TObjCMIcon(TObject *parent) : TObject(parent) {
    m_name = (const char *)lbl_805D3CF0;
}
