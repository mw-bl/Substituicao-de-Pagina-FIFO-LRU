#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fifo(int pags[], int length, int num_frames) {
    int frames[num_frames];
    int falta_de_pag = 0;
    int frame_index = 0;

    for (int i = 0; i < num_frames; i++) {
        frames[i] = -1;
    }

    for (int i = 0; i < length; i++) {
        int pag = pags[i];
        int found = 0;

        for (int j = 0; j < num_frames; j++) {
            if (frames[j] == pag) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[frame_index] = pag;
            frame_index = (frame_index + 1) % num_frames;
            falta_de_pag++;
        }
    }

    return falta_de_pag;
}

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
