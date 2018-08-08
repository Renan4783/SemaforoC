/*
 * main.c
 *
 *  Created on: 17 de fev de 2016
 *      Author: Renan
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/sem.h>

#define N 100;

typedef int semaphore;
semaphore mutex = 1;
semaphore empty = N;
semaphore full = 0;

void producer (void){
	int it;
	while (true){
		it = produce_item();
		down(&empty);
		down(&mutex);
		insert_item(it);
		up(&mutex);
		up(&full);
	}
}
