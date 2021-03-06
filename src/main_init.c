#include <stdio.h>

static void init(int argc, char **argv, char **envp) {
    printf("> %s\n", __FUNCTION__);
}

static void fini(void) {
    printf("< %s\n", __FUNCTION__);
}


__attribute__((section(".init_array"), used)) static typeof(init) *init_p = init;
__attribute__((section(".fini_array"), used)) static typeof(fini) *fini_p = fini;

int main(void) {
    printf("\t%s\n", __FUNCTION__);
    return 0;
}
