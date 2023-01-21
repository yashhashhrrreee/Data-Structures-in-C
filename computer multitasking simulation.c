#include <stdio.h>
#include <pthread.h>

void *download_task(void *arg) {
    printf("Download task started...\n");
    // simulate download operation
    for (int i = 0; i < 10; i++) {
        printf("Downloading... %d%%\n", i * 10);
        sleep(1);
    }
    printf("Download task completed.\n");
    pthread_exit(NULL);
}

void *music_task(void *arg) {
    printf("Music task started...\n");
    // simulate music playback
    for (int i = 0; i < 15; i++) {
        printf("Playing music... %d sec\n", i + 1);
        sleep(1);
    }
    printf("Music task completed.\n");
    pthread_exit(NULL);
}

void *game_task(void *arg) {
    printf("Game task started...\n");
    // simulate game operation
    for (int i = 0; i < 20; i++) {
        printf("Playing game... %d sec\n", i + 1);
        sleep(1);
    }
    printf("Game task completed.\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t download_thread, music_thread, game_thread;

    // create and start download thread with highest priority
    pthread_create(&download_thread, NULL, download_task, NULL);
    pthread_join(download_thread, NULL);

    // create and start music thread
    pthread_create(&music_thread, NULL, music_task, NULL);

    // create and start game thread with lowest priority
    pthread_create(&game_thread, NULL, game_task, NULL);

    pthread_join(music_thread, NULL);
    pthread_join(game_thread, NULL);

    printf("All tasks completed.\n");
    return 0;
}

