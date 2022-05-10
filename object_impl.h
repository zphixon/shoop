typedef struct {
    int (*getX)();
    void (*setX)(int);
    int x;
} object;

