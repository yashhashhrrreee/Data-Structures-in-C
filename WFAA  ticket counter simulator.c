#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_CUSTOMERS 100
#define NUM_FREQUENT_FLYERS 10

struct customer {
    int arrival_time;
    int service_time;
    bool is_frequent_flyer;
};

// Comparison function for priority queue
int compare_customers(const void *a, const void *b) {
    struct customer *c1 = (struct customer *)a;
    struct customer *c2 = (struct customer *)b;
    if (c1->is_frequent_flyer < c2->is_frequent_flyer) {
        return -1;
    } else if (c1->is_frequent_flyer > c2->is_frequent_flyer) {
        return 1;
    } else {
        if (c1->arrival_time < c2->arrival_time) {
            return -1;
        } else if (c1->arrival_time > c2->arrival_time) {
            return 1;
        } else {
            return 0;
        }
    }
}

int main() {
    srand(time(NULL));

    struct customer customers[NUM_CUSTOMERS];
    int i;
    for (i = 0; i < NUM_CUSTOMERS; i++) {
        customers[i].arrival_time = rand() % NUM_CUSTOMERS;
        customers[i].service_time = rand() % NUM_CUSTOMERS;
        customers[i].is_frequent_flyer = i < NUM_FREQUENT_FLYERS;
    }

    // Sort customers by priority
    qsort(customers, NUM_CUSTOMERS, sizeof(struct customer), compare_customers);

    int current_time = 0;
    int total_wait_time = 0;
    for (i = 0; i < NUM_CUSTOMERS; i++) {
        struct customer c = customers[i];
        if (c.arrival_time > current_time) {
            current_time = c.arrival_time;
        }
        int wait_time = current_time - c.arrival_time;
        total_wait_time += wait_time;
        current_time += c.service_time;
    }

    double average_wait_time = (double)total_wait_time / NUM_CUSTOMERS;
    printf("Average wait time: %f\n", average_wait_time);

    return 0;
}

