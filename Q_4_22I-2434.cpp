
/*
    Mohammad Hassaan Ejaz
    22i - 2434
    Design and Analysis of Algorithms
    Question 4
*/

#include <iostream>

long long countDisorderedPairsDuringMerge(long long numbers[], long long helperArray[], long long startIdx, long long middleIdx, long long endIdx) {
    long long leftIdx = startIdx;
    long long rightIdx = middleIdx;
    long long helperIdx = startIdx;
    long long disorderCount = 0;

    while (leftIdx < middleIdx && rightIdx <= endIdx) {
        if (numbers[leftIdx] <= numbers[rightIdx]) {
            helperArray[helperIdx++] = numbers[leftIdx++];
        } else {
            helperArray[helperIdx++] = numbers[rightIdx++];
            disorderCount += (middleIdx - leftIdx);
        }
    }

    while (leftIdx < middleIdx) {
        helperArray[helperIdx++] = numbers[leftIdx++];
    }

    while (rightIdx <= endIdx) {
        helperArray[helperIdx++] = numbers[rightIdx++];
    }

    for (long long copyIdx = startIdx; copyIdx <= endIdx; copyIdx++) {
        numbers[copyIdx] = helperArray[copyIdx];
    }

    return disorderCount;
}

long long countDisorderWithMergeSort(long long numbers[], long long helperArray[], long long startIdx, long long endIdx) {
    long long disorderCount = 0;
    if (endIdx > startIdx) {
        long long midPoint = startIdx + (endIdx - startIdx) / 2;
        disorderCount += countDisorderWithMergeSort(numbers, helperArray, startIdx, midPoint);
        disorderCount += countDisorderWithMergeSort(numbers, helperArray, midPoint + 1, endIdx);
        disorderCount += countDisorderedPairsDuringMerge(numbers, helperArray, startIdx, midPoint + 1, endIdx);
    }
    return disorderCount;
}

long long calculateTotalDisorder(long long numbers[], long long count) {
    long long* helper = new long long[count];
    long long totalDisorder = countDisorderWithMergeSort(numbers, helper, 0, count - 1);
    delete[] helper;
    return totalDisorder;
}

int main() {
    long long testCases;
    std::cin >> testCases;
    
    while (testCases--) {
        long long itemCount;
        std::cin >> itemCount;
        long long* qualityScores = new long long[itemCount];
        
        for (long long i = 0; i < itemCount; i++) {
            std::cin >> qualityScores[i];
        }
        
        std::cout << calculateTotalDisorder(qualityScores, itemCount) << std::endl;
        delete[] qualityScores;
    }
    
    return 0;
}