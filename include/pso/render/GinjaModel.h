#ifndef PSO_RENDER_GINJAMODEL_H
#define PSO_RENDER_GINJAMODEL_H
#ifndef TYPES_H
#include "types.h"
#endif
typedef struct GinjaParameter GinjaParameter;
// One vertex array of a model; the list ends with attribute 0xFF.
typedef struct GinjaVertexArray {
  u8 attribute; /* index into ginja_vertex_attributes */
  u8 stride;
  u16 count;
  u8 pad_04[4];
  void *data;
  u32 pad_0C;
} GinjaVertexArray;
typedef struct GinjaDrawRecord {
  GinjaParameter *parameters;
  u32 parameter_count;
  void *display_list;
  u32 display_list_size;
} GinjaDrawRecord;
typedef struct GinjaModel {
  GinjaVertexArray *vertices;
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
LAYOUT_ASSERT(GinjaDrawRecordSize, sizeof(GinjaDrawRecord) == 0x10);
LAYOUT_ASSERT(GinjaModelPrefixSize, sizeof(GinjaModel) == 0x14);
#endif
