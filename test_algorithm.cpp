#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "algorithm.h"

#include "unit_test.h"

using std::equal;
using std::string;
using std::vector;

////////////////////////////////////////////////////////////////////////////////
/// @brief Testing of algorithm
/// @ingroup Testing
////////////////////////////////////////////////////////////////////////////////
class algorithm_test : public test_class {

  protected:

    void test() {
      test_bubble_sort_integers();

      test_bubble_sort_integers_already_sorted();

      test_bubble_sort_strings();

      test_selection_sort_integers();

      test_selection_sort_integers_already_sorted();

      test_selection_sort_strings();

      test_insertion_sort_integers();

      test_insertion_sort_integers_already_sorted();

      test_insertion_sort_strings();

      test_slow_sort_integers();

      test_slow_sort_integers_already_sorted();

      test_heap_sort_integers();

      test_heap_sort_integers_already_sorted();

      test_sort_integers_already_sorted();

      test_quick_sort_integers();

      test_quick_sort_integers_already_sorted();

      test_quick_sort_strings();

      test_merge_sort_integers();

      test_merge_sort_integers_already_sorted();

      test_merge_sort_strings();

      test_sort_integers();

      test_sort_integers_already_sorted();

      test_sort_strings();

      test_radix_integers();

      test_radix_integers_already_sorted();
    }

  private:

    ///@brief Test bubble_sort using integers
    void test_bubble_sort_integers() {
      vector<int> v = {3, 2, 5, 6, 8, 4, 3, 1};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      mystl::bubble_sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Bubble sort on integers failed");
    }

    ///@brief Test bubble_sort using integers on an already sorted list
    void test_bubble_sort_integers_already_sorted() {
      vector<int> v = {1, 2, 3, 3, 4, 5, 6, 8};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      mystl::bubble_sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Bubble sort on integers already sorted failed");
    }

    ///@brief Test bubble_sort using strings
    void test_bubble_sort_strings() {
      vector<string> v = {"a", "h", "b", "z", "b", "e", "d"};
      vector<string> sorted = {"z", "h", "e", "d", "b", "b", "a"};

      mystl::bubble_sort(v.begin(), v.end(), std::greater<string>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Bubble sort on strings failed");
    }

    ///@brief Test selection_sort using strings
    void test_selection_sort_integers() {
      vector<int> v = {3, 2, 5, 6, 8, 4, 3, 1};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      mystl::selection_sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Selection sort sort on integers failed");
    }

    void test_selection_sort_integers_already_sorted() {
      vector<int> v = {1, 2, 3, 3, 4, 5, 6, 8};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      mystl::selection_sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Selection sort on integers already sorted failed");
    }

    void test_selection_sort_strings() {
      vector<string> v = {"a", "h", "b", "z", "b", "e", "d"};
      vector<string> sorted = {"z", "h", "e", "d", "b", "b", "a"};

      mystl::selection_sort(v.begin(), v.end(), std::greater<string>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Selection sort on strings failed");
    }

    void test_insertion_sort_integers() {
      vector<int> v = {3, 2, 5, 6, 8, 4, 3, 1};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      mystl::insertion_sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Insertion sort sort on integers failed");
    }

    void test_insertion_sort_integers_already_sorted() {
      vector<int> v = {1, 2, 3, 3, 4, 5, 6, 8};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      mystl::insertion_sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Insertion sort on integers already sorted failed");
    }

    void test_insertion_sort_strings() {
      vector<string> v = {"a", "h", "b", "z", "b", "e", "d"};
      vector<string> sorted = {"z", "h", "e", "d", "b", "b", "a"};

      mystl::insertion_sort(v.begin(), v.end(), std::greater<string>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Insertion sort on strings failed");
    }

    ///@brief Test slow_sort using integers
    void test_slow_sort_integers() {
      vector<int> v = {3, 2, 5, 6, 8, 4, 3, 1};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      mystl::slow_sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Slow sort on integers failed");
    }

    ///@brief Test slow_sort using integers on an already sorted list
    void test_slow_sort_integers_already_sorted() {
      vector<int> v = {1, 2, 3, 3, 4, 5, 6, 8};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      mystl::slow_sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Slow sort on integers already sorted failed");
    }

    ///@brief Test slow_sort using strings
    void test_slow_sort_strings() {
      vector<string> v = {"a", "h", "b", "z", "b", "e", "d"};
      vector<string> sorted = {"z", "h", "e", "d", "b", "b", "a"};

      mystl::slow_sort(v.begin(), v.end(), std::greater<string>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Slow sort on strings failed");
    }

        ///@brief Test slow_sort using integers
    void test_heap_sort_integers() {
      vector<int> v = {3, 2, 5, 6, 8, 4, 3, 1};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      mystl::heap_sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Heap sort on integers failed");
    }

    ///@brief Test slow_sort using integers on an already sorted list
    void test_heap_sort_integers_already_sorted() {
      vector<int> v = {1, 2, 3, 3, 4, 5, 6, 8};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      mystl::heap_sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Heap sort on integers already sorted failed");
    }

        ///@brief Test sort using integers
    void test_quick_sort_integers() {
      vector<int> v = {3, 2, 5, 6, 8, 4, 3, 1};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      mystl::quick_sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Quick sort on integers failed");
    }

    ///@brief Test sort using integers on an already sorted list
    void test_quick_sort_integers_already_sorted() {
      vector<int> v = {1, 2, 3, 3, 4, 5, 6, 8};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      mystl::quick_sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Quick sort on integers already sorted failed");
    }

    ///@brief Test sort using strings
    void test_quick_sort_strings() {
      vector<string> v = {"a", "h", "b", "z", "b", "e", "d"};
      vector<string> sorted = {"z", "h", "e", "d", "b", "b", "a"};

      mystl::quick_sort(v.begin(), v.end(), std::greater<string>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Quick sort on strings failed");
    }

            ///@brief Test sort using integers
    void test_merge_sort_integers() {
      vector<int> v = {3, 2, 5, 6, 8, 4, 3, 1};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      mystl::merge_sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Merge sort on integers failed");
    }

    ///@brief Test sort using integers on an already sorted list
    void test_merge_sort_integers_already_sorted() {
      vector<int> v = {1, 2, 3, 3, 4, 5, 6, 8};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      mystl::merge_sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Merge sort on integers already sorted failed");
    }

    ///@brief Test sort using strings
    void test_merge_sort_strings() {
      vector<string> v = {"a", "h", "b", "z", "b", "e", "d"};
      vector<string> sorted = {"z", "h", "e", "d", "b", "b", "a"};

      mystl::merge_sort(v.begin(), v.end(), std::greater<string>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Merge sort on strings failed");
    }

    ///@brief Test sort using integers
    void test_sort_integers() {
      vector<int> v = {3, 2, 5, 6, 8, 4, 3, 1};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      mystl::sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Sort on integers failed");
    }

    ///@brief Test sort using integers on an already sorted list
    void test_sort_integers_already_sorted() {
      vector<int> v = {1, 2, 3, 3, 4, 5, 6, 8};
      vector<int> sorted = {1, 2, 3, 3, 4, 5, 6, 8};

      mystl::sort(v.begin(), v.end(), std::less<int>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Sort on integers already sorted failed");
    }

    ///@brief Test sort using strings
    void test_sort_strings() {
      vector<string> v = {"a", "h", "b", "z", "b", "e", "d"};
      vector<string> sorted = {"z", "h", "e", "d", "b", "b", "a"};

      mystl::sort(v.begin(), v.end(), std::greater<string>());

      assert_msg(v.size() == sorted.size() &&
          equal(sorted.begin(), sorted.end(), v.begin()),
          "Sort on strings failed");
    }

      ///@brief Test sort using integers
  void test_radix_integers() {
    vector<int> v = { 3, 2, 5, 6, 8, 4, 3, 1, 11, 23 };
    vector<int> sorted = { 1, 2, 3, 3, 4, 5, 6, 8, 11, 23 };

    mystl::radix_sort(v.begin(), v.end());

    assert_msg(v.size() == sorted.size() &&
      equal(sorted.begin(), sorted.end(), v.begin()),
      "Radix on integers failed");
  }

  ///@brief Test sort using integers on an already sorted list
  void test_radix_integers_already_sorted() {
    vector<int> v = { 1, 2, 3, 3, 4, 5, 6, 8, 22, 53 };
    vector<int> sorted = { 1, 2, 3, 3, 4, 5, 6, 8, 22, 53 };

    mystl::radix_sort(v.begin(), v.end());

    assert_msg(v.size() == sorted.size() &&
      equal(sorted.begin(), sorted.end(), v.begin()),
      "Radix on integers already sorted failed");
  }

};

int main() {
  algorithm_test at;

  if(at.run())
    std::cout << "All tests passed." << std::endl;

  return 0;
}

