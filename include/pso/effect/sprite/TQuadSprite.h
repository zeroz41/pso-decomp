#ifndef PSO_EFFECT_SPRITE_TQUADSPRITE_H
#define PSO_EFFECT_SPRITE_TQUADSPRITE_H
#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/task/TObject.h"

struct ParticleDefinition;

// One sprite queued for this frame's draw. It sits in the list of its uv cell
// (definition->uvs[uv_index]); pos + offset is where it is drawn.
struct QuadSpriteNode {
    QuadSpriteNode *next;
    Vec pos;
    Vec offset;
    f32 scale_x;
    f32 scale_y;
    u32 color;
    s8 uv_index;
    s8 type;  // 1: pos is already in screen space
    s16 angle;
};

// The eight floats draw_textured_quad_at_depth reads: the screen rectangle,
// then its texture coordinates.
struct QuadSpriteRect {
    f32 x0, y0, x1, y1;
    f32 u0, v0, u1, v1;
};

// Base of the TQuadSprite* classes: one list of queued sprites per uv cell of
// its ParticleDefinition, drawn and emptied once a frame.
class TQuadSprite : public TObject {
public:
    TQuadSprite(TObject *parent, ParticleDefinition *sprite_definition);
    virtual ~TQuadSprite();
    // Queues node at the end of the list of its uv cell.
    void append_node_to_tail(QuadSpriteNode *node);
    void quad_sprite_reset_entries();
    virtual void render();
    QuadSpriteNode *lists;   // one head node per uv cell; lists[i].next is the first sprite
    QuadSpriteNode **tails;  // last node of each list
    s32 queued;              // set when a sprite is added, cleared after the draw
    ParticleDefinition *definition;
};

#endif
