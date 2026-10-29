#ifndef PSO_GINJA_MODEL_H
#define PSO_GINJA_MODEL_H
#ifndef TYPES_H
#include "types.h"
#endif
typedef struct GinjaDrawRecord {
  void *parameters;
  u32 parameter_count;
  void *display_list;
  u32 display_list_size;
} GinjaDrawRecord;
typedef struct GinjaModel {
  void *vertices;
  u32 reserved04;
  GinjaDrawRecord *primary;
  GinjaDrawRecord *secondary;
  u16 primary_count;
  u16 secondary_count;
} GinjaModel;
// A Ginja model followed by its bounding radius.
typedef struct GinjaModelBounds {
  GinjaModel model;
  f32 radius;
} GinjaModelBounds;
typedef char GinjaDrawRecordSize[(sizeof(GinjaDrawRecord) == 0x10) ? 1 : -1];
typedef char GinjaModelPrefixSize[(sizeof(GinjaModel) == 0x14) ? 1 : -1];
#endif
