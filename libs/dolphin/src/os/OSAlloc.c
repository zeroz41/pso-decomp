#ifndef PSO_SDK_COMPACT_MATH
#define PSO_SDK_COMPACT_MATH 1
#endif
#include <dolphin/dolphin.h>
#include <dolphin/os.h>

#define ALIGNMENT 32

#define InRange(cell, arenaStart, arenaEnd) \
    ((u32) arenaStart <= (u32) cell) && ((u32) cell < (u32) arenaEnd)

#define HEADERSIZE 32u
#define MINOBJSIZE 64u

#if DEBUG
#define ENABLE_HEAPDESC
#endif

typedef struct Cell Cell;
typedef struct HeapDesc HeapDesc;
struct Cell {
    Cell* prev;
    Cell* next;
    s32 size;
#ifdef ENABLE_HEAPDESC
    HeapDesc* hd;
    s32 requested;
#endif
};

struct HeapDesc {
    s32 size;
    Cell* free;
    Cell* allocated;
#ifdef ENABLE_HEAPDESC
    u32 paddingBytes;
    u32 headerBytes;
    u32 payloadBytes;
#endif
};

volatile int __OSCurrHeap = -1;

static HeapDesc* HeapArray;
static int NumHeaps;
static void* ArenaStart;
static void* ArenaEnd;


static Cell* DLAddFront(Cell* list, Cell* cell);
static Cell* DLLookup(Cell* list, Cell* cell);
static Cell* DLExtract(Cell* list, Cell* cell);
static Cell* DLInsert(Cell* list, Cell* cell);
static int DLOverlap(Cell* list, void* start, void* end);
static s32 DLSize(Cell* list);

static Cell* DLAddFront(Cell* list, Cell* cell) {
    cell->next = list;
    cell->prev = 0;
    if (list) {
        list->prev = cell;
    }
    return cell;
}

static Cell* DLLookup(Cell* list, Cell* cell) {
    for(; list; list = list->next) {
        if (list == cell) {
            return list;
        }
    }
    return NULL;
}

static Cell* DLExtract(Cell* list, Cell* cell) {
    if (cell->next) {
        cell->next->prev = cell->prev;
    }
    if (cell->prev == NULL) {
        return cell->next;
    }
    cell->prev->next = cell->next;
    return list;
}

static Cell* DLInsert(Cell* list, Cell* cell) {
    Cell* prev;
    Cell* next;

    for(next = list, prev = NULL; next != 0; prev = next, next = next->next) {
        if (cell <= next) {
            break;
        }
    }

    cell->next = next;
    cell->prev = prev;
    if (next) {
        next->prev = cell;
        if ((u8*)cell + cell->size == (u8*)next) {
            cell->size += next->size;
            next = next->next;
            cell->next = next;
            if (next) {
                next->prev = cell;
            }
        }
    }
    if (prev) {
        prev->next = cell;
        if ((u8*)prev + prev->size == (u8*)cell) {
            prev->size += cell->size;
            prev->next = next;
            if (next) {
                next->prev = prev;
            }
        }
        return list;
    }
    return cell;
}

static int DLOverlap(Cell* list, void* start, void* end) {
    Cell* cell = list;

    while(cell) {
        if (((start <= cell)
            && (cell < end))
            || ((start < (void* ) ((u8*)cell + cell->size))
            && ((void* ) ((u8*)cell + cell->size) <= end))) {
            return 1;
        }
        cell = cell->next;
    }
    return 0;
}

static s32 DLSize(Cell* list) {
    Cell* cell;
    s32 size;

    size = 0;
    cell = list;

    while(cell) {
        size += cell->size;
        cell = cell->next;
    }

    return size;
}

void* OSAllocFromHeap(int heap, u32 size) {
    HeapDesc* hd;
    Cell* cell;
    Cell* newCell;
    s32 leftoverSize;
    s32 requested;

    requested = size;
    ASSERTMSGLINE(337, HeapArray, "OSAllocFromHeap(): heap is not initialized.");
    ASSERTMSGLINE(338, (s32)size > 0, "OSAllocFromHeap(): invalid size.");
    ASSERTMSGLINE(339, heap >= 0 && heap < NumHeaps, "OSAllocFromHeap(): invalid heap handle.");
    ASSERTMSGLINE(340, HeapArray[heap].size >= 0, "OSAllocFromHeap(): invalid heap handle.");

    hd = &HeapArray[heap];
    size += HEADERSIZE;
    size = (size + 0x1F) & 0xFFFFFFE0;

    for(cell = hd->free; cell != NULL; cell = cell->next) {
        if ((signed)size <= (signed)cell->size) {
            break;
        }
    }

    if (cell == NULL) {
#if DEBUG
        OSReport("OSAllocFromHeap: Warning- failed to allocate %d bytes\n", size);
#endif
        return NULL;
    }
    ASSERTMSGLINE(364, !((s32)cell & 0x1F), "OSAllocFromHeap(): heap is broken.");
    ASSERTMSGLINE(365, cell->hd == NULL, "OSAllocFromHeap(): heap is broken.");

    leftoverSize = cell->size - size;
    if (leftoverSize < MINOBJSIZE) {
        hd->free = DLExtract(hd->free, cell);
    } else {
        cell->size = size;
        newCell = (void*)((u8*)cell + size);
        newCell->size = leftoverSize;
#ifdef ENABLE_HEAPDESC
        newCell->hd = 0;
#endif
        newCell->prev = cell->prev;
        newCell->next = cell->next;
        if (newCell->next != NULL) {
            newCell->next->prev = newCell;
        }
        if (newCell->prev != NULL) {
            newCell->prev->next = newCell;
        } else {
            ASSERTMSGLINE(394, hd->free == cell, "OSAllocFromHeap(): heap is broken.");
            hd->free = newCell;
        }
    }

    hd->allocated = DLAddFront(hd->allocated, cell);
#ifdef ENABLE_HEAPDESC
    cell->hd = hd;
    cell->requested = requested;
    hd->headerBytes += HEADERSIZE;
    hd->paddingBytes += (cell->size - (requested + HEADERSIZE));
    hd->payloadBytes += requested;
#endif
    return (u8*)cell + HEADERSIZE;
}

void* OSAllocFixed(void* rstart, void* rend) {
    int i;
    Cell* cell;
    Cell* newCell;
    HeapDesc* hd;
    void* start;
    void* end;
    void* cellEnd;

    start = (void*)((*(u32*)rstart) & ~((32)-1));
    end = (void*)((*(u32*)rend + 0x1FU) & ~((32)-1));

    ASSERTMSGLINE(436, HeapArray, "OSAllocFixed(): heap is not initialized.");
    ASSERTMSGLINE(437, (u32)start < (u32)end, "OSAllocFixed(): invalid range.");
    ASSERTMSGLINE(439, ((u32) ArenaStart <= (u32) start) && ((u32) end <= (u32) ArenaEnd), "OSAllocFixed(): invalid range.");

    for(i = 0; i < NumHeaps; i++) {
        hd = &HeapArray[i];
        if(hd->size >= 0) {
            if (DLOverlap(hd->allocated, start, end)) {
#if DEBUG
                OSReport("OSAllocFixed: Warning - failed to allocate from %p to %p\n", start, end);
#endif
                return NULL;
            }
        }
    }

    for(i = 0; i < NumHeaps; i++) {
        hd = &HeapArray[i];
        if (hd->size >= 0) {
            for(cell = hd->free; cell; cell = cell->next) {
                cellEnd = ((u8*)cell + cell->size);
                if(cellEnd > start) {
                    if (end <= cell) {
                        break;
                    }
                    if ((char*)start - HEADERSIZE <= (char*)cell && cell < end && (start <= cellEnd) && (cellEnd < ((char*)end + MINOBJSIZE))) {
                        if (cell < start) {
                            start = cell;
                        }
                        if (end < cellEnd) {
                            end = cellEnd;
                        }
                        hd->free = DLExtract(hd->free, cell);
                        hd->size -= cell->size;
                    } else if((char*)start - HEADERSIZE <= (char*)cell && cell < end) {
                            if (cell < start) {
                                start = cell;
                            }
                            ASSERTLINE(503, MINOBJSIZE <= (char*) cellEnd - (char*) end);
                            newCell = (Cell*)end;

                            newCell->size = (s32) ((char*)cellEnd - (char*)end);
#ifdef ENABLE_HEAPDESC
                            newCell->hd = 0;
#endif
                            newCell->next = cell->next;
                            if (newCell->next) {
                                newCell->next->prev = newCell;
                            }
                            newCell->prev = cell->prev;
                            if (newCell->prev) {
                                newCell->prev->next = newCell;
                            } else {
                                hd->free = newCell;
                            }
                            hd->size -= ((char*)end - (char*)cell);
                            break;
                    } else {
                        if ((start <= cellEnd) && (cellEnd < ((char*)end + MINOBJSIZE))) {
                            if (end < cellEnd) {
                                end = cellEnd;
                            }
                            ASSERTLINE(528, MINOBJSIZE <= (char*) start - (char*) cell);
                            hd->size -= ((char*)cellEnd - (char*)start);
                            cell->size = ((char*)start - (char*)cell);
                        } else {
                            ASSERTLINE(535, MINOBJSIZE <= (char*) cellEnd - (char*) end);
                            newCell = (Cell*)end;
                            newCell->size = ((char*)cellEnd - (char*)end);
#ifdef ENABLE_HEAPDESC
                            newCell->hd = 0;
#endif
                            newCell->next = cell->next;
                            if (newCell->next) {
                                newCell->next->prev = newCell;
                            }
                            newCell->prev = cell;
                            cell->next = newCell;
                            cell->size = ((char*)start - (char*)cell);
                            hd->size -= ((char*)end - (char*)start);
                            break;
                        }
                    }
                }
            }
            ASSERTLINE(550, 0 <= hd->size);
        }
    }
    ASSERTLINE(553, OFFSET(start, ALIGNMENT) == 0);
    ASSERTLINE(554, OFFSET(end, ALIGNMENT) == 0);
    ASSERTLINE(555, start < end);
    *(u32*)rstart = (u32)start;
    *(u32*)rend = (u32)end;
    return (void*)*(u32*)rstart;
}

void OSFreeToHeap(int heap, void* ptr) {
    HeapDesc* hd;
    Cell* cell;

    ASSERTMSGLINE(577, HeapArray, "OSFreeToHeap(): heap is not initialized.");
    ASSERTMSGLINE(579, ((u32)ArenaStart + HEADERSIZE) <= (u32)ptr && (u32)ptr < (u32)ArenaEnd, "OSFreeToHeap(): invalid pointer.");
    ASSERTMSGLINE(580, OFFSET(ptr, ALIGNMENT) == 0, "OSFreeToHeap(): invalid pointer.");
    ASSERTMSGLINE(581, HeapArray[heap].size >= 0, "OSFreeToHeap(): invalid heap handle.");
    cell = (void*)((u32)ptr - HEADERSIZE);
    hd = &HeapArray[heap];
    ASSERTMSGLINE(586, cell->hd == hd, "OSFreeToHeap(): invalid pointer.");
    ASSERTMSGLINE(587, DLLookup(hd->allocated, cell), "OSFreeToHeap(): invalid pointer.");
#ifdef ENABLE_HEAPDESC
    cell->hd = 0;
    hd->headerBytes -= HEADERSIZE;
    hd->paddingBytes -= (cell->size - (cell->requested + HEADERSIZE));
    hd->payloadBytes -= cell->requested;
#endif
    hd->allocated = DLExtract(hd->allocated, cell);
    hd->free = DLInsert(hd->free, cell);
}

int OSSetCurrentHeap(int heap) {
    int prev;

    ASSERTMSGLINE(619, HeapArray, "OSSetCurrentHeap(): heap is not initialized.");
    ASSERTMSGLINE(620, (heap >= 0) && (heap < NumHeaps), "OSSetCurrentHeap(): invalid heap handle.");
    ASSERTMSGLINE(621, HeapArray[heap].size >= 0, "OSSetCurrentHeap(): invalid heap handle.");
    prev = __OSCurrHeap;
    __OSCurrHeap = heap;
    return prev;
}

void* OSInitAlloc(void* arenaStart, void* arenaEnd, int maxHeaps) {
    u32 arraySize;
    int i;
    HeapDesc* hd;

    ASSERTMSGLINE(647, maxHeaps > 0, "OSInitAlloc(): invalid number of heaps.");
    ASSERTMSGLINE(649, (u32)arenaStart < (u32)arenaEnd, "OSInitAlloc(): invalid range.");
    ASSERTMSGLINE(652, maxHeaps <= (((u32)arenaEnd - (u32)arenaStart) / 24U), "OSInitAlloc(): too small range.");
    arraySize = maxHeaps * sizeof(HeapDesc);
    HeapArray = arenaStart;
    NumHeaps = maxHeaps;

    for(i = 0; i < NumHeaps; i++) {
        hd = &HeapArray[i];
        hd->size = -1;
        hd->free = hd->allocated = 0;
#ifdef ENABLE_HEAPDESC
        hd->paddingBytes = hd->headerBytes = hd->payloadBytes = 0;
#endif
    }
    __OSCurrHeap = -1;
    arenaStart = (void*) ((u32)((char*)HeapArray + arraySize));
    arenaStart = (void*) (((u32)arenaStart + 0x1F) & 0xFFFFFFE0);
    ArenaStart = arenaStart;
    ArenaEnd = (void*) ((u32)arenaEnd & 0xFFFFFFE0);
    ASSERTMSGLINE(680, ((u32)ArenaEnd - (u32)ArenaStart) >= MINOBJSIZE, "OSInitAlloc(): too small range.");
    return arenaStart;
}

int OSCreateHeap(void* start, void* end) {
    int heap;
    HeapDesc* hd;
    Cell* cell;

    ASSERTMSGLINE(705, HeapArray, "OSCreateHeap(): heap is not initialized.");
    ASSERTMSGLINE(706, (u32)start < (u32)end, "OSCreateHeap(): invalid range.");

    start = (void*)(((u32)start + 0x1FU) & ~((32)-1));
    end = (void*)(((u32)end) & ~((32)-1));

    ASSERTMSGLINE(709, (u32)start < (u32)end, "OSCreateHeap(): invalid range.");
    ASSERTMSGLINE(711, (u32)ArenaStart <= (u32)start && (u32)end <= (u32)ArenaEnd, "OSCreateHeap(): invalid range.");
    ASSERTMSGLINE(713, ((u32)end - (u32)start) >= MINOBJSIZE, "OSCreateHeap(): too small range.");

#if DEBUG
    for(heap = 0; heap < NumHeaps; heap++) {
        if (HeapArray[heap].size >= 0) {
            ASSERTMSGLINE(723, !DLOverlap(HeapArray[heap].free, start, end), "OSCreateHeap(): invalid range.");
            ASSERTMSGLINE(725, !DLOverlap(HeapArray[heap].allocated, start, end), "OSCreateHeap(): invalid range.");
        }
    }
#endif

    for(heap = 0; heap < NumHeaps; heap++) {
        hd = &HeapArray[heap];
        if (hd->size < 0) {
            hd->size = (u32)end - (u32)start;
            cell = start;
            cell->prev = 0;
            cell->next = 0;
            cell->size = hd->size;
#ifdef ENABLE_HEAPDESC
            cell->hd = 0;
#endif
            hd->free = cell;
            hd->allocated = 0;
#ifdef ENABLE_HEAPDESC
            hd->paddingBytes = hd->headerBytes = hd->payloadBytes = 0;
#endif
            return heap;
        }
    }
#if DEBUG
    OSReport("OSCreateHeap: Warning - Failed to find free heap descriptor.");
#endif
    return -1;
}

void OSDestroyHeap(int heap) {
    HeapDesc* hd;
    s32 size;

    ASSERTMSGLINE(782, HeapArray, "OSDestroyHeap(): heap is not initialized.");
    ASSERTMSGLINE(783, (heap >= 0) && (heap < NumHeaps), "OSDestroyHeap(): invalid heap handle.");
    ASSERTMSGLINE(784, HeapArray[heap].size >= 0, "OSDestroyHeap(): invalid heap handle.");

    hd = &HeapArray[heap];
#if DEBUG
    size = DLSize(hd->free);

    if (hd->size != size) {
        OSReport("OSDestroyHeap(%d): Warning - free list size %d, heap size %d\n", heap, size, hd->size);
    }
#endif

    hd->size = -1;
    hd->free = hd->allocated = 0;
#ifdef ENABLE_HEAPDESC
    hd->paddingBytes = hd->headerBytes = hd->payloadBytes = 0;
    if (__OSCurrHeap == heap) {
        __OSCurrHeap = -1;
    }
#endif
}

void OSAddToHeap(int heap, void* start, void* end) {
    HeapDesc* hd;
    Cell* cell;
    int i;

    ASSERTMSGLINE(830, HeapArray, "OSAddToHeap(): heap is not initialized.");
    ASSERTMSGLINE(831, (heap >= 0) && (heap < NumHeaps), "OSAddToHeap(): invalid heap handle.");
    ASSERTMSGLINE(832, HeapArray[heap].size >= 0, "OSAddToHeap(): invalid heap handle.");

    hd = &HeapArray[heap];

    ASSERTMSGLINE(836, (u32)start < (u32)end, "OSAddToHeap(): invalid range.");

    start = (void*)(((u32)start + 0x1F) & ~((32)-1));
    end = (void*)(((u32)end) & ~((32)-1));

    ASSERTMSGLINE(840, ((u32)end - (u32)start) >= MINOBJSIZE, "OSAddToHeap(): too small range.");
    ASSERTMSGLINE(842, (u32)ArenaStart <= (u32)start && (u32)end <= (u32)ArenaEnd, "OSAddToHeap(): invalid range.");

#if DEBUG
    for(i = 0; i < NumHeaps; i++) {
        if (HeapArray[i].size >= 0) {
            ASSERTMSGLINE(852, !DLOverlap(HeapArray[i].free, start, end), "OSAddToHeap(): invalid range.");
            ASSERTMSGLINE(854, !DLOverlap(HeapArray[i].allocated, start, end), "OSAddToHeap(): invalid range.");
        }
    }
#endif
    cell = (Cell*)start;
    cell->size = ((char*)end - (char*)start);
#ifdef ENABLE_HEAPDESC
    cell->hd = 0;
#endif
    hd->size += cell->size;
    hd->free = DLInsert(hd->free, cell);
}


#define ASSERTREPORT(line, cond) \
    if (!(cond)) { OSReport("OSCheckHeap: Failed " #cond " in %d", line); return -1; }




















































u32 OSReferentSize(void* ptr) {
    Cell* cell;

    ASSERTMSGLINE(960, HeapArray, "OSReferentSize(): heap is not initialized.");
    ASSERTMSGLINE(962, InRange(ptr, ArenaStart+HEADERSIZE, ArenaEnd), "OSReferentSize(): invalid pointer.");
    ASSERTMSGLINE(963, !OFFSET(ptr, 32), "OSReferentSize(): invalid pointer.");
    cell = (void*)((u32)ptr-HEADERSIZE);
    ASSERTMSGLINE(967, cell->hd, "OSReferentSize(): invalid pointer.");
    ASSERTMSGLINE(969, !(((u32)cell->hd - (u32)HeapArray) % 24), "OSReferentSize(): invalid pointer.");
    ASSERTMSGLINE(971, ((u32)HeapArray <= (u32)cell->hd) && ((u32)cell->hd < (u32)((u32)HeapArray + (NumHeaps * 0x18))), "OSReferentSize(): invalid pointer.");
    ASSERTMSGLINE(972, cell->hd->size >= 0, "OSReferentSize(): invalid pointer.");
    ASSERTMSGLINE(974, DLLookup(cell->hd->allocated, cell), "OSReferentSize(): invalid pointer.");
    return (s32)((u32)cell->size-HEADERSIZE);
}



































void OSVisitAllocated(void (*visitor)(void*, u32)) {
    u32 heap;
    Cell* cell;

    for(heap = 0; heap < NumHeaps; heap++) {
        if (HeapArray[heap].size >= 0) {
            for(cell = HeapArray[heap].allocated; cell; cell = cell->next) {
                visitor((char*)cell+HEADERSIZE, cell->size);
            }
        }
    }
}
