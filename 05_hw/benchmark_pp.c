#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack.h"

// ������� ��� ��������� ������� ���������� �������� push
void measurePushPerformance(Stack* stack, size_t elementCount) {
    clock_t startTime = clock();
    for (size_t i = 0; i < elementCount; ++i) {
        push(stack, (int)i);
    }
    clock_t endTime = clock();
    printf("Push operation for %zu elements took: %.6f seconds\n", elementCount, (double)(endTime - startTime) / CLOCKS_PER_SEC);
}

// ������� ��� ��������� ������� ���������� �������� pop
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

    // ���������� ��������� ��� ������������
    size_t testElementCount = 1500000;

    // ��������� ������������������ �������� push
    measurePushPerformance(&stack, testElementCount);

    // ���������� ����� ��� ������������ pop
    for (size_t i = 0; i < testElementCount; ++i) {
        push(&stack, (int)i);
    }

    // ��������� ������������������ �������� pop
    measurePopPerformance(&stack, testElementCount);

    destroyStack(&stack);
    return 0;
}
