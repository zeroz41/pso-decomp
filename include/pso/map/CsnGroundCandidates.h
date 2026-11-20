#ifndef PSO_MAP_CSN_GROUND_CANDIDATES_H
#define PSO_MAP_CSN_GROUND_CANDIDATES_H

struct CsnGroup;

extern "C" {
CsnGroup **initialize_ground_candidates(CsnGroup **candidates);
void clear_ground_candidates(CsnGroup **candidates);
}

#endif
