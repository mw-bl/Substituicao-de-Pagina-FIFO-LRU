#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int reference_string[50];
    gerarStringDeReferencia(reference_string, 50);
    int num_frames_list[] = {2, 3, 4, 5};
    int num_frames_list_length = sizeof(num_frames_list) / sizeof(num_frames_list[0]);

    for (int i = 0; i < num_frames_list_length; i++) {
        int num_frames = num_frames_list[i];
        int fifo_faults = fifo(reference_string, 50, num_frames);
        int lru_faults = lru(reference_string, 50, num_frames);

        printf("Número de frames: %d\n", num_frames);
        printf("FIFO Falta de páginas: %d\n", fifo_faults);
        printf("LRU Falta de páginas: %d\n\n", lru_faults);
    }

    return 0;
}
