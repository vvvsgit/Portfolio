#ifndef __ALGORITHMS_HPP__
#define __ALGORITHMS_HPP__

#include "Vector.hpp" // my vector
#include "List.hpp"   // my list
#include "Set.hpp"    // my set

#include <utility>
#include <vector>
#include <list>
#include <set>

template <typename DataStructure, typename ValueType>
int iterativeLinear(const DataStructure& data, const int size, const ValueType& value);
template <typename Iterator, typename ValueType>
Iterator iterativeLinear(Iterator first, Iterator last, const ValueType& value);

template <typename DataStructure, typename ValueType>
int recursiveLinear(const DataStructure& data, const int size, const ValueType& value, const int next = 0);
template <typename Iterator, typename ValueType>
Iterator recursiveLinear(Iterator first, Iterator last, const ValueType& value);

template <typename DataStructure, typename ValueType>
int iterativeBinary(const DataStructure& data, int size, const ValueType& value);
template <typename Iterator, typename ValueType>
Iterator iterativeBinary(Iterator first, Iterator last, int size, const ValueType& value);

template <typename DataStructure, typename ValueType>
int recursiveBinary(const DataStructure& data, const int size, const ValueType& value, const int start = 0);
template <typename Iterator, typename ValueType>
Iterator recursiveBinary(Iterator first, Iterator last, const int size, const ValueType& value, const int start = 0);


template <typename Iterator>
bool isSorted(Iterator first, Iterator last);

template <typename DataStructure>
void insertion(DataStructure& data, const int size);
template <typename Iterator>
void insertion(Iterator first, Iterator last);

template <typename DataStructure>
void selection(DataStructure& data, const int size);
template <typename Iterator>
void selection(Iterator first, Iterator last);

template <typename DataStructure>
void bubble(DataStructure& data, const int size);
template <typename Iterator>
void bubble(Iterator first, Iterator last);

template <typename DataStructure>
void quickRecursive(DataStructure& data, const int size, const int first = 0);
template <typename DataStructure>
void partition(DataStructure& data, size_t& start, size_t& end);
template <typename DataStructure>
void quickIterative(DataStructure& data, const int size);
template <typename Iterator>
void quickIterative(Iterator first, Iterator last);
template <typename Iterator>
void quickRecursive(Iterator first, Iterator last);
template <typename Iterator>
void partition(Iterator start, Iterator end);

template <typename DataStructure>
void radix(DataStructure& data, const int size);
template <typename Iterator>
void radix(Iterator first, Iterator last);

template <typename DataStructure>
void bucket(DataStructure& data, const int size);
template <typename Iterator>
void bucket(Iterator first, Iterator last);

template <typename DataStructure>
void countSort(DataStructure& data, const int size);
template <typename Iterator>
void countSort(Iterator first, Iterator last);

template <typename DataStructure>
void shellSort(DataStructure& data, const int size);
template <typename Iterator>
void shellSort(Iterator first, Iterator last);

template <typename ValueType>
void mergeRecursive(ValueType data[], const int size);
template <typename ValueType>
void mergeSortRecursive(ValueType from[], int first, int last, ValueType to[]);
template <typename DataStructure>
void mergeRecursive(DataStructure& data, const int size);
template <typename DataStructure>
void mergeSortRecursive(DataStructure& from, int first1, int last2, DataStructure& to);
template <typename Iterator>
void mergeRecursive(Iterator first, Iterator last);
template <typename Iterator, typename Iterator2>
void mergeSortRecursive(Iterator first, Iterator last, Iterator2 buffer);

template <typename ForwardIterator, typename T>
void fill(ForwardIterator first, ForwardIterator last, const T& value);
template <typename OutputIterator, typename Size, typename T>
OutputIterator fill_n(OutputIterator first, Size n, const T& value);

template <typename ForwardIterator, typename Generator>
void generate(ForwardIterator first, ForwardIterator last, Generator gen);
template <typename OutputIterator, typename Size, typename Generator>
OutputIterator generate_n(OutputIterator first, Size n, Generator gen);

template <typename InputIterator, typename OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result);
template <typename InputIterator, typename Size, typename OutputIterator>
OutputIterator copy_n(InputIterator first, Size count, OutputIterator result);

template <typename ForwardIterator, typename T>
void iota(ForwardIterator first, ForwardIterator last, T value);

template <typename InputIterator, typename T>
T accumulate(InputIterator first, InputIterator last, T init);
template <typename InputIterator, typename T, typename BinaryFunction>
T accumulate(InputIterator first, InputIterator last, T init, BinaryFunction binary_op);

template <typename InputIterator, typename EqualityComparable, typename Size>
void count(InputIterator first, InputIterator last, const EqualityComparable& value, Size& size);

template <typename InputIterator1, typename InputIterator2>
bool includes(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator set_union(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator set_intersection(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator set_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator set_symmetric_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result);

template <typename InputIterator, typename Distance>
void distance(InputIterator first, InputIterator last, Distance& n);

template <typename InputIterator, typename Distance>
void advance(InputIterator& i, Distance n);

template <typename InputIterator, typename EqualityComparable>
InputIterator find(InputIterator first, InputIterator last, const EqualityComparable& value);

template <typename ForwardIterator>
ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last);

template <typename InputIterator, typename ForwardIterator>
InputIterator find_first_of(InputIterator first1, InputIterator last1, ForwardIterator first2, ForwardIterator last2);

template <typename InputIterator, typename EqualityComparable, typename Size>
void count(InputIterator first, InputIterator last, const EqualityComparable& value, Size& size);

template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2);

template <typename ForwardIterator, typename Integer, typename T>
ForwardIterator search_n(ForwardIterator first, ForwardIterator last, Integer count, const T& value);

template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2);

template <typename RandomAccessIterator>
void sort(RandomAccessIterator first, RandomAccessIterator last);

template <typename RandomAccessIterator>
void stable_sort(RandomAccessIterator first, RandomAccessIterator last);
template <typename RandomAccessIterator, typename RandomAccessIterator2>
void mergeSort(RandomAccessIterator first, RandomAccessIterator last, RandomAccessIterator2 buffer) ;

template <typename RandomAccessIterator>
void partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last);

template <typename InputIterator, typename RandomAccessIterator>
RandomAccessIterator partial_sort_copy(InputIterator first, InputIterator last, RandomAccessIterator result_first, RandomAccessIterator result_last);

template <typename ForwardIterator>
bool is_sorted(ForwardIterator first, ForwardIterator last);

template <typename ForwardIterator, typename LessThanComparable>
ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const LessThanComparable& value);

template <typename ForwardIterator, typename LessThanComparable>
ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, const LessThanComparable& value);

template <typename ForwardIterator, typename LessThanComparable>
std::pair<ForwardIterator, ForwardIterator> equal_range(ForwardIterator first, ForwardIterator last, const LessThanComparable& value);

template <typename ForwardIterator, typename LessThanComparable>
bool binary_search(ForwardIterator first, ForwardIterator last, const LessThanComparable& value);

template <typename RandomAccessIterator>
void nth_element(RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename StrictWeakOrdering>
OutputIterator merge(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result, StrictWeakOrdering comp);

template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, BinaryPredicate comp);

template <typename InputIterator, typename UnaryFunction>
UnaryFunction for_each(InputIterator first, InputIterator last, UnaryFunction f);

template <typename InputIterator, typename Predicate>
InputIterator find_if(InputIterator first, InputIterator last, Predicate pred);

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last, BinaryPredicate binary_pred);

template <typename InputIterator, typename ForwardIterator, typename BinaryPredicate>
InputIterator find_first_of(InputIterator first1, InputIterator last1, ForwardIterator first2, ForwardIterator last2, BinaryPredicate comp);

template <typename InputIterator, typename Predicate, typename Size>
void count_if(InputIterator first, InputIterator last, Predicate pred, Size& n);

template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
std::pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate binary_pred);

template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate binary_pred);

template <typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate binary_pred);

template <typename ForwardIterator, typename Integer, typename T, typename BinaryPredicate>
ForwardIterator search_n(ForwardIterator first, ForwardIterator last, Integer count, const T& value, BinaryPredicate binary_pred);

template <typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate comp);

template <typename InputIterator, typename OutputIterator, typename UnaryFunction>
OutputIterator transform(InputIterator first, InputIterator last, OutputIterator result, UnaryFunction op);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename BinaryFunction>
OutputIterator transform(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, OutputIterator result, BinaryFunction binary_op);

template <typename ForwardIterator, typename Predicate, typename T>
void replace_if(ForwardIterator first, ForwardIterator last, Predicate pred, const T& new_value);

template <typename InputIterator, typename OutputIterator, typename Predicate, typename T>
OutputIterator replace_copy_if(InputIterator first, InputIterator last, OutputIterator result, Predicate pred, const T& new_value);

template <typename ForwardIterator, typename Generator>
void generate(ForwardIterator first, ForwardIterator last, Generator gen);

template <typename OutputIterator, typename Size, typename Generator>
OutputIterator generate_n(OutputIterator first, Size n, Generator gen);

template <typename ForwardIterator, typename Predicate>
ForwardIterator remove_if(ForwardIterator first, ForwardIterator last, Predicate pred);

template <typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator remove_copy_if(InputIterator first, InputIterator last, OutputIterator result, Predicate pred);

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator unique(ForwardIterator first, ForwardIterator last, BinaryPredicate binary_pred);

template <typename InputIterator, typename OutputIterator, typename BinaryPredicate>
OutputIterator unique_copy(InputIterator first, InputIterator last, OutputIterator result, BinaryPredicate binary_pred);

template <typename RandomAccessIterator, typename RandomNumberGenerator>
void random_shuffle(RandomAccessIterator first, RandomAccessIterator last, RandomNumberGenerator& rand);

template <typename InputIterator, typename RandomAccessIterator, typename RandomNumberGenerator>
void random_sample(InputIterator first, InputIterator last, RandomAccessIterator ofirst, RandomAccessIterator olast, RandomNumberGenerator& rand);

template <class ForwardIterator, class OutputIterator, class Distance, class RandomNumberGenerator>
OutputIterator random_sample_n(ForwardIterator first, ForwardIterator last, OutputIterator out, Distance n, RandomNumberGenerator& rand);

template <typename ForwardIterator, typename Predicate>
ForwardIterator partition(ForwardIterator first, ForwardIterator last, Predicate pred);

template <typename ForwardIterator, typename Predicate>
ForwardIterator stable_partition(ForwardIterator first, ForwardIterator last, Predicate pred);

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void sort(RandomAccessIterator first, RandomAccessIterator last, StrictWeakOrdering comp);

template <class RandomAccessIterator, class StrictWeakOrdering>
void stable_sort(RandomAccessIterator first, RandomAccessIterator last, StrictWeakOrdering comp);
template <typename RandomAccessIterator, typename RandomAccessIterator2, class StrictWeakOrdering>
void mergeSort(RandomAccessIterator first, RandomAccessIterator last, RandomAccessIterator2 buffer, StrictWeakOrdering comp);

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last, StrictWeakOrdering comp);

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void partial_stable_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last, StrictWeakOrdering comp);

template <typename ForwardIterator, typename StrictWeakOrdering>
bool is_sorted(ForwardIterator first, ForwardIterator last, StrictWeakOrdering comp);

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void nth_element(RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last, StrictWeakOrdering comp);

template <class ForwardIterator, class T, class StrictWeakOrdering>
ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, const T& value, StrictWeakOrdering comp);

template <class ForwardIterator, class T, class StrictWeakOrdering>
ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, const T& value, StrictWeakOrdering comp);

template <class ForwardIterator, class T, class StrictWeakOrdering>
std::pair<ForwardIterator, ForwardIterator> equal_range(ForwardIterator first, ForwardIterator last, const T& value, StrictWeakOrdering comp);

template <class ForwardIterator, class T, class StrictWeakOrdering>
bool binary_search(ForwardIterator first, ForwardIterator last, const T& value, StrictWeakOrdering comp);

template <typename BidirectionalIterator, typename StrictWeakOrdering>
inline void inplace_merge(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last, StrictWeakOrdering comp);

template <typename InputIterator1, typename InputIterator2, typename StrictWeakOrdering>
bool includes(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, StrictWeakOrdering comp);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename StrictWeakOrdering>
OutputIterator set_union(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result, StrictWeakOrdering comp);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename StrictWeakOrdering>
OutputIterator set_intersection(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result, StrictWeakOrdering comp);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename StrictWeakOrdering>
OutputIterator set_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result, StrictWeakOrdering comp);

template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename StrictWeakOrdering>
OutputIterator set_symmetric_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result, StrictWeakOrdering comp);

template <typename T, typename BinaryPredicate>
const T& min(const T& a, const T& b, BinaryPredicate comp);

template <typename T, typename BinaryPredicate>
const T& max(const T& a, const T& b, BinaryPredicate comp);

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator min_element(ForwardIterator first, ForwardIterator last, BinaryPredicate comp);

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator max_element(ForwardIterator first, ForwardIterator last, BinaryPredicate comp);

template <typename BidirectionalIterator, typename StrictWeakOrdering>
bool next_permutation(BidirectionalIterator first, BidirectionalIterator last, StrictWeakOrdering comp);

template <typename BidirectionalIterator, typename StrictWeakOrdering>
bool prev_permutation(BidirectionalIterator first, BidirectionalIterator last, StrictWeakOrdering comp);

template <typename InputIterator1, typename InputIterator2, typename T, typename BinaryFunction1, typename BinaryFunction2>
T inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init, BinaryFunction1 binary_op1, BinaryFunction2 binary_op2);

template <typename InputIterator, typename OutputIterator, typename BinaryOperation>
OutputIterator partial_sum(InputIterator first, InputIterator last, OutputIterator result, BinaryOperation binary_op);

template <typename InputIterator, typename OutputIterator, typename BinaryFunction>
OutputIterator adjacent_difference(InputIterator first, InputIterator last, OutputIterator result, BinaryFunction binary_op);

template <typename T, typename Integer, typename MonoidOperation>
T power(T x, Integer n, MonoidOperation op);

#include "templates/Algorithms.cpp"

#endif

