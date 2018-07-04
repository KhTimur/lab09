#include "catch.hpp"
#include <algorithm>
#include <chrono>
#include <inser.h>
#include <merge_sort.h>
#include <quick_sort.h>
#include <heapSort.h>

int main(int argc, char** argv)
   {
    int nums[] = { 1,2,3,4,5,6,7,8,9,10 };
    int *begi = std::begin(nums);
    int *en = std::end(nums);
    auto start_time = std::chrono::high_resolution_clock::now();
    for(long int i=0;i<3628800;i++)
    {
        std::next_permutation(begi,en);
        inser(begi, en);
   	}
    auto end_time = std::chrono::high_resolution_clock::now();
    std::cout<< "insert time  ";
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ":";
std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << "\n";

    int nums[] = { 1,2,3,4,5,6,7,8,9,10 };
    int *begi = std::begin(nums);
    int *en = std::end(nums);
    auto start_time = std::chrono::high_resolution_clock::now();
    for(long int i=0;i<3628800;i++)
    {
        std::next_permutation(begi,en);
        merge_sort(begi, en);
   	}
    auto end_time = std::chrono::high_resolution_clock::now();
    std::cout<< "merge time  ";
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ":";
std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << "\n";





    int nums[] = { 1,2,3,4,5,6,7,8,9,10 };
    int *begi = std::begin(nums);
    int *en = std::end(nums);
    auto start_time = std::chrono::high_resolution_clock::now();
    for(long int i=0;i<3628800;i++)
    {
        std::next_permutation(begi,en);
        heapSort(begi, en);
   	}
    auto end_time = std::chrono::high_resolution_clock::now();
    std::cout<< "heap time  ";
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ":";
std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << "\n";





    int nums[] = { 1,2,3,4,5,6,7,8,9,10 };
    int *begi = std::begin(nums);
    int *en = std::end(nums);
    auto start_time = std::chrono::high_resolution_clock::now();
    for(long int i=0;i<3628800;i++)
    {
        std::next_permutation(begi,en);
        quick_sort(begi, en);
   	}
    auto end_time = std::chrono::high_resolution_clock::now();
    
  std::cout<< "quick time  ";
    std::cout << std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time).count() << ":";
std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << "\n";
  
© 2018 GitHub, Inc
