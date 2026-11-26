#include "pso/ui/window/TWindowHelpItem.h"

// Interim data-only unit: the attribute area names that follow the TWindowHelpItem TU's
// .rodata. show_weapon_attributes reaches each with its own lis/addi while it reaches its own
// TU's data through one pooled base, so they are not that TU's data.

__declspec(section ".rodata") const char native_attribute_label[7] ATTRIBUTE_ALIGN(4) = "Native";
__declspec(section ".rodata") const char abeast_attribute_label[8] = "A.Beast";
__declspec(section ".rodata") const char machine_attribute_label[8] = "Machine";
__declspec(section ".rodata") const char dark_attribute_label[5] ATTRIBUTE_ALIGN(4) = "Dark";
