#ifndef UARRAY2
#define UARRAY2

#define T UArray2_T
typedef struct T *T;

extern T UArray2_new (int height, int width, int size);
extern void UArray2_free (T *uarray2);
extern int UArray2_width (T uarray2);
extern int UArray2_height (T uarray2);
extern int UArray2_size (T uarray2);
extern void *UArray2_at (T uarray2, int row, int col);
extern void UArray2_map_row_major(T uarray2, void apply(int element,
                        int value, void *cl), void *cl);
extern void UArray2_map_col_major(T uarray2, void apply(int element,
                        int value, void *cl), void *cl);
extern void UArray2_init(T uarray2, int height, int width, int size,
                        void *elements);

#undef T
#endif
