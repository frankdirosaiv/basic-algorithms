////////////////////////////////////////////////////////////////////////////////
/// Partner 1: Frank DiRosa IV
/// Partner 2: Briana Martinez
/// UIN 1: 223008529
/// UIN 2: 124001108
/// @brief Algorithms, e.g., sorting
/// @ingroup MySTL
/// @todo Implement swap
/// @todo Implement bubble sort
/// @todo Implement one of:
///       - Insertion Sort (in place)
///       - Selection Sort (in place)
/// @todo Implement one of:
///       - Heap Sort (in place)
///       - Merge Sort
///       - Quick Sort (in place)
/// @bonus Each extra sort you implement will be worth bonus points
////////////////////////////////////////////////////////////////////////////////

#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include <limits>
#include <vector>
#include <queue>
#include <iostream>

namespace mystl {

////////////////////////////////////////////////////////////////////////////////
/// @brief Swap values of two elements
/// @tparam T Value type
/// @param a First value
/// @param b Second value
template<typename T>
  void swap(T& a, T& b) {
    /// @todo Implement swapping values
      T temp = a;
      a = b;
      b = temp;
  }

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) into nondecreasing order
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
/// Bubble Sort
template<class RandomAccessIterator, class Compare>
  void bubble_sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
    /// @todo Implement Bubble sort
      bool swapped = true;
      int count = 0;
      while(swapped){
          swapped = false;
          ++count;
          for(RandomAccessIterator it = first; it != (last - count); ++it){
              if(comp(*(it + 1), *it)){
                  swap(*it, *(it + 1));
                  swapped = true;
              }
          }
      }
  }

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) into nondecreasing order
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
/// Selection Sort.
template<class RandomAccessIterator, class Compare>
  void selection_sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
    RandomAccessIterator minIt;
    for (RandomAccessIterator it = first; it != (last-1); ++it) {
      minIt = it;
      for (RandomAccessIterator subIt = it + 1; subIt != last; ++subIt) {
        if(comp(*subIt, *minIt)){
          minIt = subIt;
        }
      }
      if (minIt != it) {
        swap(*minIt, *it);
      }
    }
  }

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) into nondecreasing order
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
/// Insertion Sort
template<class RandomAccessIterator, class Compare>
  void insertion_sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
    RandomAccessIterator traverseIt;
    for (RandomAccessIterator it = first + 1; it != last; ++it) {
      traverseIt = it;
      while (traverseIt != first && comp(*traverseIt, *(traverseIt - 1))){
        swap(*traverseIt, *(traverseIt - 1));
        --traverseIt;
      }
    }
  }

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) into nondecreasing order
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
/// Slow sort sorts in a non-optimal fashion. Select and implement one of:
///   -(a) insertion sort
///   -(b) selection sort
/// Your sort should be inplace (uses no extra memory).
template<class RandomAccessIterator, class Compare>
  void slow_sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
    /// @todo Call your slow sort of choice
    insertion_sort(first, last, comp);
  }

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) into nondecreasing order
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
/// Heap Sort.
template<class RandomAccessIterator, class Compare>
  void heap_sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
    int size = distance(first, last);
    int largest = 0;
    int left = 0;
    int right = 0;
    for (int j = 0; j < size; ++j) {
      int i = 0;
      if (j >= 1) swap(*(first + i), *(first + size-j));
      while(i < size - j){
        largest = i;
        left = 2*largest + 1;
        right = 2*largest + 2;
        if(left < size - j && comp(*(first + largest), *(first + left))){
            largest = left;
        }
        if(right < size - j  && comp(*(first + largest), *(first + right))){
            largest = right;
        }
        if(largest != i){
          swap(*(first + i), *(first + largest));
          if(i != 0 && largest == left){
              i = (i-1)/2;
          }
          else if (i > 1 && largest == right){
              i = (i-2)/2;
          }
        }
        else {
            ++i;
        }             
      } 
    }
  }

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) into nondecreasing order
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
/// Merge Sort.
template<class RandomAccessIterator, class Compare>
  void merge_sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {

    typedef typename std::iterator_traits<RandomAccessIterator>::value_type value;
    std::vector<value> v;

      
      typedef typename std::iterator_traits<RandomAccessIterator>::value_type value;
      
      RandomAccessIterator middle = first;
      advance(middle, distance(first, last)/2); //Determines the middle of the vector
      
      unsigned int i = 0;
      unsigned int j = 0;
      unsigned int count = 0;
      
      if(first != (last -1)){ //Keeps doing this until it is just a single element
          
          merge_sort(first, middle, comp);
          merge_sort(middle, last, comp);
          
          std::vector<value> v1; //Puts the first half into a subvector called v1
          for(RandomAccessIterator it = first; it != middle; ++it){
              v1.push_back(*it);
          }
          std::vector<value> v2; //Puts the second half into a subvector called v2
          for(RandomAccessIterator it = middle; it != last; ++it){
              v2.push_back(*it);
          }
          
          while(i < v1.size() && j < v2.size()){ //Keeps comparing until one vector is empty
              if(comp(v1.at(i), v2.at(j))){
                  *(first + count) = v1.at(i);
                  ++i;
              }
              else{
                  *(first + count) = v2.at(j);
                  ++j;
              }
              ++count;
          }
          while (i < v1.size()){ //Puts the rest of v1
              *(first + count) = v1.at(i);
              ++i;
              ++count;
          }
          while (j < v2.size()){ //Puts the rest of v2
              *(first + count) = v2.at(j);
              ++j;
              ++count;
          }
      }     
    return;
  }

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) into nondecreasing order
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
/// Quick Sort.
template<class RandomAccessIterator, class Compare>
  void quick_sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
    RandomAccessIterator left = first;
    RandomAccessIterator right = last - 1;
    if (distance(first, last) <= 1) return;
    RandomAccessIterator pivot = first + distance(first, last) / 2;
    while (distance(first, right) - distance(first, left) >= 1) {
      while (comp(*left, *pivot))
        left++;
      while (comp(*pivot, *right))
        right--;
      if (distance(first, right) - distance(first, left) > 0 ) {
        swap(*left, *right);
        if (left == pivot)
          pivot = right;
        else if (right == pivot)
          pivot = left;
        left++;
      }
    }
    if (distance(first, pivot) > 1)
      quick_sort(first, pivot, comp);
    if (distance(pivot, last) > 1)
      quick_sort(pivot, last, comp);
  }

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) into nondecreasing order
/// @tparam RandomAccessIterator Random Access Iterator
/// @tparam Compare Comparator function
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
/// @param comp Binary function that accepts two elements in the range as
///             arguments and returns a value convertable to bool. The value
///             returned indicates whether the element passed as first argument
///             is considered to go before the second in the ordering it
///             defines.
///
/// Sort sorts in an optimal fashion. Select and implement one of:
///   -(a) heap sort  (in place)
///   -(b) merge sort
///   -(c) quick sort (in place)
template<class RandomAccessIterator, class Compare>
  void sort(RandomAccessIterator first, RandomAccessIterator last,
      Compare comp) {
    /// @todo Call your fast sort of choice
    merge_sort(first, last, comp);
  }

////////////////////////////////////////////////////////////////////////////////
/// @brief Sort the range [first, last) of integral types into nondecreading
///        order
/// @tparam RandomAccessIterator Random Access Iterator
/// @param first Initial position of sequence to be sorted
/// @param last Final position of sequence to be sorted
///
/// Sorts with Radix sort. Should do radix on decimal representation of integer
/// type, i.e., number of buckets is always 10.
/// typename RandomAccessIterator::value_type is required to be some integral
/// type, i.e., char, short, int, long, etc.
template<class RandomAccessIterator>
  void radix_sort(RandomAccessIterator first, RandomAccessIterator last) {
    /// @bonus Implement radix_sort
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type value;
    std::queue<value> bins[10];
    int maxDigits = 3;
    int currentDigit = 0;

    while (currentDigit <= maxDigits) {
      for (int i = 0; i<distance(first, last); i++) { //loop through whole array
        int divisor = pow(10, currentDigit);
        int num = *(first + i); //set to current value of array position
        int digitValue = static_cast<int>(num / divisor) % 10; //get the decimal digit at current digit
        bins[digitValue].push(num); //put digits in corresponding bins
      }
      //Transfer results of bins back into main array
      int i = 0;
      for (int k = 0; k<10; k++) { //loop through all bins
        while (!bins[k].empty()) { //push all elements in bin[k] until empty to a
          int temp = bins[k].front();
          *(first + i) = temp;
          bins[k].pop();
          i++;
        }
      }
      currentDigit++;
    }
    return;
  }

}

#endif
