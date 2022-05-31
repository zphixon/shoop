#pragma once

typedef struct {
    void* handle;
    int (*getX)();
    void (*setX)(int);
    int x;
} object;

