#include <standard_libs.h>
#define INT_SIZE 4

int main() {
    setbuf(stdout, NULL);

    array_hashset_t *hashset = create_hashset(1);

    for (int i = 0; i < STANDARD_BUCKET_SIZE; i++) {
        int_dynamic_array_t *p;
        if ((p = malloc(sizeof(int_dynamic_array_t *)))
            == NULL) { break; }
        hashset_add(hashset, p);
    }

    for (int i = 0; i < STANDARD_BUCKET_SIZE; i++) {
        printf("%i\n", hashset->container[0][i]);
    }

    if (hashset == NULL) {
        printf("-1 ");
    } else {
        printf("00 ");
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 10; j++) {

        }
    }

    return 0;
}
