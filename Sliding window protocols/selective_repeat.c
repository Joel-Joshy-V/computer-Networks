#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int totalFrames, windowSize, i, j, transmitted = 0;
    int ack[50] = {0}; // Acknowledgment tracking
    srand(time(NULL));

    printf("Enter the total number of frames: ");
    scanf("%d", &totalFrames);
    printf("Enter the window size: ");
    scanf("%d", &windowSize);

    i = 1;

    while (i <= totalFrames) {
        // Transmit a window of frames
        printf("\nSending frames in the window:\n");
        for (j = i; j < i + windowSize && j <= totalFrames; j++) {
            if (ack[j] == 0) {
                printf("Frame %d transmitted\n", j);
                transmitted++;
            }
        }

        // Simulate acknowledgments
        for (j = i; j < i + windowSize && j <= totalFrames; j++) {
            if (ack[j] == 0) {
                int flag = rand() % 2;
                if (flag == 1) {
                    printf("ACK for frame %d received\n", j);
                    ack[j] = 1;
                } else {
                    printf("ACK for frame %d not received (will be retransmitted)\n", j);
                }
            }
        }

        // Slide the window
        while (ack[i] == 1 && i <= totalFrames) {
            i++;
        }
    }

    printf("\nAll frames sent and acknowledged.\n");
    printf("Total transmissions including retransmissions: %d\n", transmitted);

    return 0;
}
