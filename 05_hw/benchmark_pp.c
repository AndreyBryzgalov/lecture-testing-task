#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

// Функция для измерения времени выполнения операции push
void measurePushPerformance(Stack* stack, size_t elementCount) {
    clock_t startTime = clock();
    for (size_t i = 0; i < elementCount; ++i) {
        push(stack, (int)i);
    }
    clock_t endTime = clock();
    printf("Push operation for %zu elements took: %.6f seconds\n", elementCount, (double)(endTime - startTime) / CLOCKS_PER_SEC);
}

// Функция для измерения времени выполнения операции pop
void measurePopPerformance(Stack* stack, size_t elementCount) {
    clock_t startTime = clock();
    for (size_t i = 0; i < elementCount; ++i) {
        pop(stack);
    }
    clock_t endTime = clock();
    printf("Pop operation for %zu elements took: %.6f seconds\n", elementCount, (double)(endTime - startTime) / CLOCKS_PER_SEC);
}

int main() {
    Stack stack;
    initStack(&stack);

    // Количество элементов для тестирования
    size_t testElementCount = 1500000;

    // Измерение производительности операций push
    measurePushPerformance(&stack, testElementCount);

    // Заполнение стека для тестирования pop
    for (size_t i = 0; i < testElementCount; ++i) {
        push(&stack, (int)i);
    }

    // Измерение производительности операций pop
    measurePopPerformance(&stack, testElementCount);

    destroyStack(&stack);
    return 0;
}
