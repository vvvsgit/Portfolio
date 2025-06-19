#include "headers/Algorithms.hpp"

template <typename DataStructure, typename ValueType>
int 
iterativeLinear(const DataStructure& data, const int size, const ValueType& value)
{
    for (int i = 0; i < size; ++i) {
        if (data[i] == value) return i;
    }
    return -1;
}

template <typename Iterator, typename ValueType>
Iterator 
iterativeLinear(Iterator first, Iterator last, const ValueType& value)
{
    while (first != last) {
        if (*first == value) return first;
        ++first;
    }
    return last;
}

template <typename DataStructure, typename ValueType>
int 
recursiveLinear(const DataStructure& data, const int size, const ValueType& value, const int next)
{
    if (next == size) return -1;
    if (data[next] == value) return next;
    return recursiveLinear(data, size, value, next + 1);
}

template <typename Iterator, typename ValueType>
Iterator 
recursiveLinear(Iterator first, Iterator last, const ValueType& value)
{
    if (first == last) return last;
    if (*first == value) return first;
    ++first;
    return recursiveLinear(first, last, value);
}

template <typename DataStructure, typename ValueType>
int 
iterativeBinary(const DataStructure& data, int size, const ValueType& value)
{
    int start = 0;
    while (size > start) {
        const int mid = (start + size) / 2;
        if (data[mid] == value) return mid;
        if (data[mid] < value) start = mid + 1;
        if (data[mid] > value) size = mid;
    }
    return -1;
}

template <typename Iterator, typename ValueType>
Iterator 
iterativeBinary(Iterator first, Iterator last, int size, const ValueType& value)
{
    int start = 0;
    while (size > start) 
    {
        const int mid = (start + size) / 2;
        if (*(first + mid) == value) return first + mid;
        if (*(first + mid) < value) start = mid + 1;
        if (*(first + mid) > value) size = mid;
    }
    return last;
}

template <typename DataStructure, typename ValueType>
int 
recursiveBinary(const DataStructure& data, const int size, const ValueType& value, const int start)
{
    if (size <= start) return -1;
    const int mid = (start + size) / 2;
    if (data[mid] < value) return recursiveBinary(data, size, value, mid + 1);
    if (data[mid] > value) return recursiveBinary(data, mid, value, start);
    return mid;
}

template <typename Iterator, typename ValueType>
Iterator 
recursiveBinary(Iterator first, Iterator last, const int size, const ValueType& value, const int start)
{
    if (size <= start) return last;
    const int mid = (start + size) / 2;
    if (*(first + mid) < value) return recursiveBinary(first, last, size, value, mid + 1);
    if (*(first + mid) > value) return recursiveBinary(first, last, mid, value, start);
    return first + mid;
}


template <typename Iterator>
bool 
isSorted(Iterator first, Iterator last)
{
    if (first == last) return true;
    while (first + 1 != last) {
        if (*first > *(first + 1)) return false;
        ++first;
    }
    return true;
}

template <typename DataStructure>
void 
insertion(DataStructure& data, const int size)
{
    for (int i = 1; i < size; ++i) {
        if (data[i] < data[i - 1]) {
            for (int j = i - 1; j >= 0; --j) {
                if (data[j] <= data[j + 1]) break;
                std::swap(data[j], data[j + 1]);
            }
        }
    }
}

template <typename Iterator>
void 
insertion(Iterator first, Iterator last)
{
    for (Iterator i = first + 1; i != last; ++i) {
        if (*i < *(i - 1)) {
            for (Iterator j = i - 1; j != first - 1; --j) {
                if (*j <= *(j + 1)) break;
                std::swap(*j, *(j + 1));
            }
        }
    }
}

template <typename DataStructure>
void 
selection(DataStructure& data, const int size)
{
    for (int i = 0; i < size; ++i) {
        int min = i;
        for (int j = i; j < size; ++j) {
            if (data[j] < data[min]) min = j;
        }
        std::swap(data[i], data[min]);
    }
}

template <typename Iterator>
void 
selection(Iterator first, Iterator last)
{
    for (Iterator i = first; i != last; ++i) {
        Iterator min = i;
        for (Iterator j = i; j != last; ++j) {
            if (*j < *min) min = j;
        }
        std::swap(*i, *min);
    }
}

template <typename DataStructure>
void 
bubble(DataStructure& data, const int size)
{
    for (int i = size - 1; i >= 0; --i) {
        bool swapped = false;
        for (int j = 1; j <= i; ++j) {
            if (data[j] < data[j - 1]) {
                std::swap(data[j], data[j - 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

template <typename Iterator>
void 
bubble(Iterator first, Iterator last)
{
    for (Iterator i = last - 1; i != first - 1; --i) {
        bool swapped = false;
        for (Iterator j = first + 1; j != i + 1; ++j) {
            if (*j < *(j - 1)) {
                std::swap(*j, *(j - 1));
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

template <typename DataStructure>
void 
quickRecursive(DataStructure& data, const int size, const int first)
{
    if (first >= size) return;
    size_t start = first;
    size_t end = size - 1;
    partition(data, start, end);
    quickRecursive(data, end, first);
    quickRecursive(data, size, start + 1);
}

template <typename DataStructure>
void 
partition(DataStructure& data, size_t& start, size_t& end)
{
    while (end != start) {
        for (; end > start; --end) {
            if (data[end] < data[start]) {
                std::swap(data[end], data[start]);
                ++start;
                break;
            }
        }
        for (; start < end; ++start) {
            if (data[start] > data[end]) {
                std::swap(data[start], data[end]);
                --end;
                break;
            }
        }
    }
}

template <typename DataStructure>
void 
quickIterative(DataStructure& data, const int size)
{
    Stack<std::pair<int, int> > s;
    size_t first = 0;
    size_t last = size;
    while (first < last) {
        size_t start = first;
        size_t end = size - 1;
        partition(data, start, end);
        s.push(std::make_pair(first, end));
        s.push(std::make_pair(start + 1, last));
        first = s.top().first;
        last = s.top().second;
        s.pop();
    }
}

template <typename Iterator>
void 
quickIterative(Iterator first, Iterator last)
{
    Stack<std::pair<Iterator, Iterator> > s;
    while (first != last) {
        Iterator start = first;
        Iterator end = last - 1;
        partition(start, end);
        s.push(std::make_pair(first, end));
        s.push(std::make_pair(start + 1, last));
        first = s.top().first;
        last = s.top().second;
        s.pop();
    }
}

template <typename Iterator>
void 
quickRecursive(Iterator first, Iterator last)
{
    if (first == last) return;
    Iterator start = first;
    Iterator end = last - 1;
    partition(start, end);
    quickRecursive(first, end);
    quickRecursive(start + 1, last);
}

template <typename Iterator>
void 
partition(Iterator start, Iterator end)
{
    while (end != start) {
        for (; end != start; --end) {
            if (*end < *start) {
                std::swap(*end, *start);
                ++start;
                break;
            }
        }
        for (; start != end; ++start) {
            if (*start > *end) {
                std::swap(*start, *end);
                --end;
                break;
            }
        }
    }
}

template <typename DataStructure>
void 
radix(DataStructure& data, const int size)
{
    int max = 0;
    for (int i = 0; i < size; ++i)
    {
        if (data[max] < data[i]) max = i;
    }
    int terminate = 0;
    typename DataStructure::value_type temp = data[max];
    while (temp != 0)
    {
        temp /= 10;
        ++terminate;
    }

    Vector<DataStructure> radix(10);
    for (int i = 0; i < 10; ++i) radix[i].resize(size);

    for (int power = 1, stop = 0; stop < terminate; ++stop, power *= 10) {
        for (int i = 0; i < size; ++i) {
            radix[data[i] / power % 10][i] = data[i]; 
        }

        for (int i = 0, row = 0; i < size; ++row) {
            for (int j = 0; j < size; ++j) {
                if (radix[row][j] > 0) {
                    data[i] = radix[row][j];
                    ++i;
                }
            }
        }
    }
}

template <typename Iterator>
void 
radix(Iterator first, Iterator last)
{
    if (first == last) return;
    typedef typename std::iterator_traits<Iterator>::value_type value_type;

    value_type max = *first;
    for (Iterator i = first; i != last; ++i) {
        if(max < *i) max = *i;
    }
    int terminate = 0;
    while (max != 0)
    {
        max /= 10;
        ++terminate;
    }
    int size = 0;
    for (Iterator i = first; i != last; ++i) {
        ++size;
    }

    Vector<Vector<value_type> > radix(10);
    for (int i = 0; i < 10; ++i) radix[i].reserve(size);

    for (int power = 1, stop = 0; stop < terminate; ++stop, power *= 10) {
        for (Iterator i = first; i != last; ++i) {
            radix[*i / power % 10].push_back(*i);
        }

        int row = 0;
        for (Iterator i = first; i != last; ++row) {
            const int column = radix[row].size();
            for (int j = 0; j < column; ++j) {
                *i = radix[row][j];
                ++i;
            }
            radix[row].clear();
        }
    }
}

template <typename DataStructure>
void 
bucket(DataStructure& data, const int size)
{
    int max = 0;
    int min = 0;
    for (int i = 0; i < size; ++i)
    {
        if (data[max] < data[i]) max = i;
        if (data[min] > data[i]) min = i;
    }
    typedef typename DataStructure::value_type value_type;
    value_type range = (data[max] - data[min]) / size;

    Vector<Vector<value_type> > bucket((data[max] - data[min]) / range + 1);
    for (size_t i = 0; i < bucket.size(); ++i) bucket[i].reserve(size);

    for (int i = 0; i < size; ++i) {
        bucket[(data[i] - data[min]) / range].push_back(data[i]);
    }

    for (size_t i = 0; i < bucket.size(); ++i) insertion(bucket[i], bucket[i].size());

    for (int i = 0, row = 0; i < size; ++row) {
        const int column = bucket[row].size();
        for (int j = 0; j < column; ++j) {
            data[i] = bucket[row][j];
            ++i;
        }
    }
}

template <typename Iterator>
void 
bucket(Iterator first, Iterator last)
{
    if (first == last) return;
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    value_type max = *first;
    value_type min = *first;
    int size = 0;
    for (Iterator i = first; i != last; ++i) {
        if(max < *i) max = *i;
        if(min > *i) min = *i;
        ++size;
    }
    value_type range = (max - min) / size;

    Vector<Vector<value_type> > bucket((max - min) / range + 1);
    for (size_t i = 0; i < bucket.size(); ++i) bucket[i].reserve(size);

    for (Iterator i = first; i != last; ++i) {
        bucket[(*i - min) / range].push_back(*i);
    }

    for (size_t i = 0; i < bucket.size(); ++i) insertion(bucket[i], bucket[i].size());

    int row = 0;
    for (Iterator i = first; i != last; ++row) {
        const int column = bucket[row].size();
        for (int j = 0; j < column; ++j) {
            *i = bucket[row][j];
            ++i;
        }
    }
}

template <typename DataStructure>
void 
countSort(DataStructure& data, const int size)
{
    int max = 0;
    for (int i = 0; i < size; ++i) {
        if (data[max] < data[i]) max = i;
    }
    typedef typename DataStructure::value_type value_type;
    value_type countArray[data[max] + 1] = { 0 };
    for (int i = 0; i < size; ++i) {
        ++countArray[data[i]];
    }
    for (int i = 1; i < data[max] + 1; ++i) {
        countArray[i] += countArray[i - 1];
    }
   
    value_type output[size] = { 0 };
    for (int i = size - 1; i >= 0; --i) {
        output[countArray[data[i]] - 1] = data[i];
        --countArray[data[i]];
    }
    for (int i = 0; i < size; ++i) {
        data[i] = output[i];
    }
}

template <typename Iterator>
void 
countSort(Iterator first, Iterator last)
{
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    value_type max = *first;
    int size = 0;
    for (Iterator i = first; i != last; ++i) {
        if (max < *i) max = *i;
        ++size;
    }
    value_type countArray[max + 1] = { 0 };
    for (Iterator i = first; i != last; ++i) {
        ++countArray[*i];
    }
    for (int i = 1; i < max + 1; ++i) {
        countArray[i] += countArray[i - 1];
    }
   
    value_type output[size] = { 0 };
    for (Iterator i = last - 1; i != first - 1; --i) {
        output[countArray[*i] - 1] = *i;
        --countArray[*i];
    }
    for (int i = 0; i < size; ++i) {
        *first = output[i];
        ++first;
    }
}

template <typename DataStructure>
void 
shellSort(DataStructure& data, const int size)
{
    typedef typename DataStructure::value_type value_type;
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {
            value_type temp = data[i];
            int j;
            for (j = i; j >= gap && data[j - gap] > temp; j -= gap) {
                data[j] = data[j - gap];
            }
            data[j] = temp;
        }
    }
}

template <typename Iterator>
void 
shellSort(Iterator first, Iterator last)
{
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    int size = 0;
    for (Iterator i = first; i != last; ++i) ++size;
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (Iterator i = first + gap; i != last; ++i) {
            value_type temp = *i;
            Iterator j;
            for (j = i; j >= first + gap && *(j - gap) > temp; j = j - gap) {
                *j = *(j - gap);
            }
            *j = temp;
        }
    }
}

template <typename ValueType>
void
mergeRecursive(ValueType data[], const int size)
{
    ValueType result[size];
    mergeSortRecursive(data, 0, size, result);
}

template <typename ValueType>
void
mergeSortRecursive(ValueType from[], int first, int last, ValueType to[])
{
    if (last - first <= 1) return;

    const int mid = (first + last) / 2;

    mergeSortRecursive(from, first, mid, to);
    mergeSortRecursive(from, mid, last, to);

    int i = first;
    int left = first;
    int right = mid;
    while (left < mid && right < last) {
        if (from[left] < from[right]) {
            to[i++] = from[left++];
        } else {
            to[i++] = from[right++];
        }
    }
    while (left < mid) {
        to[i++] = from[left++];
    }
    while (right < last) {
        to[i++] = from[right++];
    }
    for (int j = first; j < last; ++j) {
        from[j] = to[j];
    }
}

template <typename DataStructure>
void 
mergeRecursive(DataStructure& data, const int size)
{
    DataStructure result(size);
    mergeSortRecursive(data, 0, size, result);
}

template <typename DataStructure>
void 
mergeSortRecursive(DataStructure& from, int first, int last, DataStructure& to)
{
    if (last - first <= 1) return;
    
    const int mid = (first + last) / 2;

    mergeSortRecursive(from, first, mid, to);
    mergeSortRecursive(from, mid, last, to);

    int i = first;
    int left = first;
    int right = mid;
    while (left < mid && right < last) {
        if (from[left] < from[right]) {
            to[i++] = from[left++];
        } else {
            to[i++] = from[right++];
        }
    }
    while (left < mid) {
        to[i++] = from[left++];
    }
    while (right < last) {
        to[i++] = from[right++];
    }
    for (int j = first; j < last; ++j) {
        from[j] = to[j];
    }
}

template <typename Iterator>
void 
mergeRecursive(Iterator first, Iterator last)
{
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    std::vector<value_type> result(std::distance(first, last));
    mergeSortRecursive(first, last, result.begin());
}

template <typename Iterator, typename Iterator2>
void 
mergeSortRecursive(Iterator first, Iterator last, Iterator2 buffer) 
{
    int size = std::distance(first, last);
    if (size <= 1) return;

    Iterator mid = first + size / 2;

    mergeSortRecursive(first, mid, buffer);
    mergeSortRecursive(mid, last, buffer);

    Iterator left = first;
    Iterator right = mid;
    Iterator2 out = buffer;

    while (left != mid && right != last) {
        if (*left < *right) {
            *out++ = *left++;
            continue;
        } 
        *out++ = *right++;
    }
    while (left != mid) {
        *out++ = *left++;
    }
    while (right != last) {
        *out++ = *right++;
    }
    for (int i = 0; i < size; ++i) {
        *(first + i) = *(buffer + i);
    }
}


template <typename ForwardIterator, typename T>
void 
fill(ForwardIterator first, ForwardIterator last, const T& value)
{
    while (first != last) {
        *first = value;
        ++first;
    }
}

template <typename OutputIterator, typename Size, typename T>
OutputIterator 
fill_n(OutputIterator first, Size n, const T& value)
{
    for (Size i = 0; i < n; ++i) {
        *first = value;
        ++first; 
    }
    return first;
}

template <typename ForwardIterator, typename Generator>
void 
generate(ForwardIterator first, ForwardIterator last, Generator gen)
{
    while (first != last) {
        *first = gen();
        ++first;
    }
}

template <typename OutputIterator, typename Size, typename Generator>
OutputIterator 
generate_n(OutputIterator first, Size n, Generator gen)
{
    for (Size i = 0; i < n; ++i) {
        *first = gen();
        ++first; 
    }
    return first;
}

template <typename InputIterator, typename OutputIterator>
OutputIterator 
copy(InputIterator first, InputIterator last, OutputIterator result)
{
    while (first != last) {
        *result = *first;
        ++result;
        ++first;
    }
    return result;
}

template <typename InputIterator, typename Size, typename OutputIterator>
OutputIterator 
copy_n(InputIterator first, Size count, OutputIterator result)
{
    for (Size i = 0; i < count; ++i) {
        *result = *first;
        ++result;
        ++first;
    }
    return result;
}

template <typename ForwardIterator, typename T>
void 
iota(ForwardIterator first, ForwardIterator last, T value)
{
    while (first != last) {
        *first = value;
        ++first;
        ++value;
    }
}

template <typename InputIterator, typename T>
T 
accumulate(InputIterator first, InputIterator last, T init)
{
    while (first != last) {
        init += *first;
        ++first;
    }
    return init;
}

template <typename InputIterator, typename T, typename BinaryFunction>
T 
accumulate(InputIterator first, InputIterator last, T init, BinaryFunction binary_op)
{
    while (first != last) {
        init = binary_op(init, *first);
        ++first;
    }
    return init;
}

template <typename InputIterator, typename EqualityComparable, typename Size>
void 
count(InputIterator first, InputIterator last, const EqualityComparable& value, Size& n)
{
    while (first != last) {
        if (*first == value) ++n;
        ++first;
    }
}

template <typename InputIterator1, typename InputIterator2>
bool 
includes(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
{
    while (first1 != last1 && first2 != last2) {
        if (*first1 == *first2) ++first2;
        ++first1;
    }
    return first2 == last2;
}

template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator 
set_union(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result)
{
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *first2) {
            *result = *first1;
            ++result;
            ++first1;
            continue;
        }
        if (*first2 < *first1) {
            *result = *first2;
            ++result;
            ++first2;
            continue;
        }
        *result = *first1;
        ++result;
        ++first1;
        ++first2;
    }
    while (first1 != last1) {
        *result = *first1;
        ++result;
        ++first1;
    }
    while (first2 != last2) {
        *result = *first2;
        ++result;
        ++first2;
    }
    return result;
}

template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator 
set_intersection(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result)
{
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *first2) {
            ++first1;
            continue;
        }
        if (*first2 < *first1) {
            ++first2;
            continue;
        }
        *result = *first1;
        ++result;
        ++first1;
        ++first2;
    }
    return result;
}

template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator 
set_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result)
{
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *first2) {
            *result = *first1;
            ++result;
            ++first1;
            continue;
        }
        if (*first2 < *first1) {
            ++first2;
            continue;
        }
        ++first1;
        ++first2;
    }
    while (first1 != last1) {
        *result = *first1;
        ++result;
        ++first1;
    }
    return result;
}

template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator 
set_symmetric_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result)
{
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *first2) {
            *result = *first1;
            ++result;
            ++first1;
            continue;
        }
        if (*first2 < *first1) {
            *result = *first2;
            ++result;
            ++first2;
            continue;
        }
        ++first1;
        ++first2;
    }
    while (first1 != last1) {
        *result = *first1;
        ++result;
        ++first1;
    }
    while (first2 != last2) {
        *result = *first2;
        ++result;
        ++first2;
    }
    return result;
}

template <typename InputIterator, typename Distance>
void 
distance(InputIterator first, InputIterator last, Distance& n)
{
    while (first != last) {
        ++n;
        ++first;
    }
}

template <typename InputIterator, typename Distance>
void 
advance(InputIterator& i, Distance n)
{
    if (n < 0) {
        while (n != 0) {
            --n;
            ++i;
        }
        return;
    } 
    while (n != 0) {
        ++n;
        --i;
    }
}

template <typename InputIterator, typename EqualityComparable>
InputIterator 
find(InputIterator first, InputIterator last, const EqualityComparable& value)
{
    while (first != last) {
        if (*first == value) return first;
        ++first;
    }
    return last;
}

template <typename ForwardIterator>
ForwardIterator 
adjacent_find(ForwardIterator first, ForwardIterator last)
{
    if (first == last) return last;

    ForwardIterator next = first;
    ++next;
    while (next != last) {
        if (*first == *next) return first;
        ++first;
        ++next;
    }
    return last;
}

template <typename InputIterator, typename ForwardIterator>
InputIterator 
find_first_of(InputIterator first1, InputIterator last1, ForwardIterator first2, ForwardIterator last2)
{
    while (first1 != last1) {
        ForwardIterator temp = first2; 
        while (temp != last2) {
            if (*first1 == *temp) return first1;
            ++temp;
        }
        ++first1;
    }
    return last1;
}

template <typename InputIterator, typename EqualityComparable, typename Size>
void 
count(InputIterator first, InputIterator last, const EqualityComparable& value, Size& n)
{
    while (first != last) {
        if (*first == value) ++n;
        ++first;
    }
}

template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 
search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2)
{
    while (first1 != last1) {
        ForwardIterator2 temp = first2; 
        while (temp != last2) {
            if (*first1 != *temp) break;
            ++temp;
        }
        if (temp == last2) return first1;
        ++first1;
    }
    return last1;
}

template <typename ForwardIterator, typename Integer, typename T>
ForwardIterator 
search_n(ForwardIterator first, ForwardIterator last, Integer count, const T& value)
{
    Integer i = 0; 
    ForwardIterator beginning = first;
    while (first != last) {
        if (i == count) return beginning;
        if (*first != value) {
            i = 0;
            ++first;
            beginning = first;
            continue;
        }
        ++i;
        ++first;
    }
    return last;
}

template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 
find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2)
{
    ForwardIterator1 end = last1;
    while (first1 != last1) {
        ForwardIterator2 temp = first2; 
        while (temp != last2) {
            if (*first1 != *temp) break;
            ++temp;
        }
        if (temp == last2) end = first1;
        ++first1;
    }
    return end;
}

template <typename RandomAccessIterator>
void 
sort(RandomAccessIterator first, RandomAccessIterator last)
{
    if (last - first <= 1) return;

    const typename std::iterator_traits<RandomAccessIterator>::value_type pivot = *(first + (last - first) / 2);

    RandomAccessIterator left = first;
    RandomAccessIterator right = last - 1;

    while (left <= right) {
        while (*left < pivot) ++left;
        while (*right > pivot) --right;

        if (left <= right) {
            std::swap(*left++, *right--);
        }
    }

    sort(first, right + 1);
    sort(left, last);
}

template <typename RandomAccessIterator>
void 
stable_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;
    std::vector<value_type> result(std::distance(first, last));
    mergeSort(first, last, result.begin());
}

template <typename RandomAccessIterator, typename RandomAccessIterator2>
void 
mergeSort(RandomAccessIterator first, RandomAccessIterator last, RandomAccessIterator2 buffer) 
{
    int size = std::distance(first, last);
    if (size <= 1) return;

    RandomAccessIterator mid = first + size / 2;

    mergeSortRecursive(first, mid, buffer);
    mergeSortRecursive(mid, last, buffer);

    RandomAccessIterator left = first;
    RandomAccessIterator right = mid;
    RandomAccessIterator2 out = buffer;

    while (left != mid && right != last) {
        if (*right < *left) {
            *out++ = *right++;
            continue;
        } 
        *out++ = *left++;
    }
    while (left != mid) {
        *out++ = *left++;
    }
    while (right != last) {
        *out++ = *right++;
    }
    for (int i = 0; i < size; ++i) {
        *(first + i) = *(buffer + i);
    }
}

template <typename RandomAccessIterator>
void 
partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last)
{
    while (first != middle) {
        for (RandomAccessIterator it = first + 1; it != last; ++it) {
            if (*it < *first) std::swap(*first, *it);
        }
        ++first;
    }
}

template <typename InputIterator, typename RandomAccessIterator>
RandomAccessIterator 
partial_sort_copy(InputIterator first, InputIterator last, RandomAccessIterator result_first, RandomAccessIterator result_last)
{
    for (RandomAccessIterator it = result_first; first != last; ++it) {
        *it = *first;
        ++first;
    }
    while (result_first != result_last) {
        for (RandomAccessIterator it = result_first + 1; it != result_last; ++it) {
            if (comp(*it, *result_first)) std::swap(*result_first, *it);
        }
        ++result_first;
    }
}

template <typename ForwardIterator>
bool 
is_sorted(ForwardIterator first, ForwardIterator last)
{
    if (first == last) return true;
    ForwardIterator next = first;
    ++next;
    while (next != last) {
        if (*next < *first) return false;
        ++first;
        ++next;
    }
    return true;
}

template <typename ForwardIterator, typename LessThanComparable>
ForwardIterator 
lower_bound(ForwardIterator first, ForwardIterator last, const LessThanComparable& value)
{
    while (first != last) {
        if (!(*first < value)) return first;
        ++first;
    }
    return last;
}

template <typename ForwardIterator, typename LessThanComparable>
ForwardIterator 
upper_bound(ForwardIterator first, ForwardIterator last, const LessThanComparable& value)
{
    while (first != last) {
        if (value < *first) return first;
        ++first;
    }
    return last;
}

template <typename ForwardIterator, typename LessThanComparable> 
std::pair<ForwardIterator, ForwardIterator> 
equal_range(ForwardIterator first, ForwardIterator last, const LessThanComparable& value)
{
    ForwardIterator lower = last;
    while (first != last) {
        if (!(*first < value)) {
            lower = first;
            break;
        }
        ++first;
    }
    ForwardIterator upper = last;
    while (first != last) {
        if (value < *first) {
            upper = first;
            break;
        }
        ++first;
    }
    return std::make_pair(lower, upper);
}

template <typename ForwardIterator, typename LessThanComparable>
bool 
binary_search(ForwardIterator first, ForwardIterator last, const LessThanComparable& value)
{
    while (first != last) {
        ForwardIterator middle = first;
        int size = 0;
        std::distance(first, last, size);
        size /= 2;
        std::advance(middle, size);

        if (value == *middle) return true;
        if (value < *middle) {
            last = middle;
            continue;
        } 
        first = ++middle;
    }
    return false;
}

template <typename RandomAccessIterator>
void 
nth_element(RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;

    while (last - first > 1) {
        const value_type pivot = *(first + (last - first) / 2);

        RandomAccessIterator left = first;
        RandomAccessIterator right = last - 1;

        while (left < right) {
            while (*left < pivot) ++left;
            while (pivot < *right) --right;

            if (left > right) break;
            std::swap(*left++, *right--);
        }
        if (pivot == *nth) return;

        if (nth <= right) {
            last = right + 1;
        }
        else {
            first = left;
        }
    }
}

template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename StrictWeakOrdering>
OutputIterator 
merge(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result, StrictWeakOrdering comp)
{
    while (first1 != last1 && first2 != last2) {
        if (comp(*first1, *first2)) {
            *result = *first1;
            ++first1;
        } else {
            *result = *first1;
            ++first2;
        }
        ++result;
    }
    while (first1 != last1) {
        *result = *first1;
        ++first1;
        ++result;
    }
    while (first2 != last2) {
        *result = *first2;
        ++first2;
        ++result;
    }
    return result;
}

template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
bool 
lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, BinaryPredicate comp)
{
    while (first1 != last1 && first2 != last2) {
        if (comp(*first2, *first1)) return false;
        ++first1;
        ++first2;
    }
    if (first1 == last1 && first2 != last2) return true;
    return false;
}

template <typename InputIterator, typename UnaryFunction>
UnaryFunction 
for_each(InputIterator first, InputIterator last, UnaryFunction f)
{
    while (first != last) {
        f(*first);
        ++first;
    }
    return f;
}

template <typename InputIterator, typename Predicate>
InputIterator 
find_if(InputIterator first, InputIterator last, Predicate pred)
{
    while (first != last) {
        if (pred(*first)) return first;
        ++first;
    }
    return last;
}

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator 
adjacent_find(ForwardIterator first, ForwardIterator last, BinaryPredicate binary_pred)
{
    if (first == last) return last;

    ForwardIterator next = first;
    ++next;
    while (next != last) {
        if (binary_pred(*first, *next)) return first;
        ++first;
        ++next;
    }
    return last;
}

template <typename InputIterator, typename ForwardIterator, typename BinaryPredicate>
InputIterator 
find_first_of(InputIterator first1, InputIterator last1, ForwardIterator first2, ForwardIterator last2, BinaryPredicate comp)
{
    while (first1 != last1) {
        ForwardIterator temp = first2; 
        while (temp != last2) {
            if (comp(*first1, *temp)) return first1;
            ++temp;
        }
        ++first1;
    }
    return last1;
}

template <typename InputIterator, typename Predicate, typename Size>
void 
count_if(InputIterator first, InputIterator last, Predicate pred, Size& n)
{
    while (first != last) {
        if (pred(*first)) ++n;
        ++first;
    }
}

template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
std::pair<InputIterator1, InputIterator2> 
mismatch(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate binary_pred)
{
    while (first1 != last1) {
        if (!binary_pred(*first1, *first2)) return std::make_pair(first1, first2);
        ++first1;
        ++first2;
    }
    return std::make_pair(first1, first2);
}

template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
bool 
equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate binary_pred)
{
    while (first1 != last1) {
        if (!binary_pred(*first1, *first2)) return false;
        ++first1;
        ++first2;
    }
    return true;
}

template <typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
ForwardIterator1 
search(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate binary_pred)
{
    while (first1 != last1) {
        ForwardIterator2 temp = first2; 
        while (temp != last2) {
            if (binary_pred(*first1, *temp)) break;
            ++temp;
        }
        if (temp == last2) return first1;
        ++first1;
    }
    return last1;
}

template <typename ForwardIterator, typename Integer, typename T, typename BinaryPredicate>
ForwardIterator
search_n(ForwardIterator first, ForwardIterator last, Integer count, const T& value, BinaryPredicate binary_pred)
{
    Integer i = 0; 
    ForwardIterator beginning = first;
    while (first != last) {
        if (i == count) return beginning;
        if (!binary_pred(*first, value)) {
            i = 0;
            ++first;
            beginning = first;
            continue;
        }
        ++i;
        ++first;
    }
    return last;
}

template <typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
ForwardIterator1 
find_end(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate comp)
{
    ForwardIterator1 end = last1;
    while (first1 != last1) {
        ForwardIterator2 temp = first2; 
        while (temp != last2) {
            if (!comp(*first1, *temp)) break;
            ++temp;
        }
        if (temp == last2) end = first1;
        ++first1;
    }
    return end;
}

template <typename InputIterator, typename OutputIterator, typename UnaryFunction>
OutputIterator 
transform(InputIterator first, InputIterator last, OutputIterator result, UnaryFunction op)
{
    while (first != last) {
        *result = op(*first);
        ++first;
        ++result;
    }
    return result;
}

template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename BinaryFunction>
OutputIterator 
transform(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, OutputIterator result, BinaryFunction binary_op)
{
    while (first1 != last1) {
        *result = binary_op(*first1, first2);
        ++first1;
        ++first2;
        ++result;
    }
    return result;
}

template <typename ForwardIterator, typename Predicate, typename T>
void 
replace_if(ForwardIterator first, ForwardIterator last, Predicate pred, const T& new_value)
{
    while (first != last) {
        if (pred(*first)) {
            *first = new_value;
            ++first;
        }
    }
}

template <typename InputIterator, typename OutputIterator, typename Predicate, typename T>
OutputIterator 
replace_copy_if(InputIterator first, InputIterator last, OutputIterator result, Predicate pred, const T& new_value)
{
    while (first != last) {
        *result = pred(*first) ? new_value : *first;
        ++first;
        ++result;
    }
    return result;
}

template <typename ForwardIterator, typename Generator>
void 
generate(ForwardIterator first, ForwardIterator last, Generator gen)
{
    while (first != last) {
        *first = gen();
        ++first;
    }
}

template <typename OutputIterator, typename Size, typename Generator>
OutputIterator 
generate_n(OutputIterator first, Size n, Generator gen)
{
    for (Size i = 0; i < n; ++i) {
        *first = gen();
        ++first;
    }
    return first;
}

template <typename ForwardIterator, typename Predicate>
ForwardIterator
remove_if(ForwardIterator first, ForwardIterator last, Predicate pred)
{
    ForwardIterator result = last;
    while (first != last) {
        if (pred(*first)) {
            ForwardIterator shift = first;
            ForwardIterator with = shift;
            ++with;
            result = with;
            while (with != last) {
                std::swap(*shift, *with);
                ++shift;
                ++with;
            }
        }
        ++first;
    }
    return result;
}

template <typename InputIterator, typename OutputIterator, typename Predicate>
OutputIterator 
remove_copy_if(InputIterator first, InputIterator last, OutputIterator result, Predicate pred)
{
    while (first != last) {
        if (pred(*first)) continue;
        *result = *first;
        ++result;
        ++first;
    }
    return result;
}

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator 
unique(ForwardIterator first, ForwardIterator last, BinaryPredicate binary_pred)
{
    if (first == last) return last;
    ForwardIterator result = last;
    ForwardIterator next = first;
    ++next;
    while (next != last) {
        if (binary_pred(*first, *next)) {
            ForwardIterator shift = next;
            ForwardIterator with = shift;
            ++with;
            result = with;
            while (with != last) {
                std::swap(*shift, *with);
                ++shift;
                ++with;
            }
        }
        ++first;
        ++next;
    }
    return result;
}

template <typename InputIterator, typename OutputIterator, typename BinaryPredicate>
OutputIterator 
unique_copy(InputIterator first, InputIterator last, OutputIterator result, BinaryPredicate binary_pred)
{
    if (first == last) return last;
    InputIterator next = first;
    ++next;
    while (next != last) {
        if (binary_pred(*first, *next)) {
            *result = *first;
            ++result;
            const typename std::iterator_traits<InputIterator>::value_type duplicate = *first;
            while (duplicate == *first && next != last) {
                ++first;
                ++next;
            }
            continue;
        }
        ++first;
        ++next;
    }
    return result;
}

template <typename RandomAccessIterator, typename RandomNumberGenerator>
void 
random_shuffle(RandomAccessIterator first, RandomAccessIterator last, RandomNumberGenerator& rand)
{
    RandomAccessIterator with = first;
    while (first != last) {
        std::swap(*first, *(with + rand()));
        ++first;
    }
}

template <typename InputIterator, typename RandomAccessIterator, typename RandomNumberGenerator>
void
random_sample(InputIterator first, InputIterator last, RandomAccessIterator ofirst, RandomAccessIterator olast, RandomNumberGenerator& rand)
{
    const int size = olast - ofirst;
    std::vector<bool> v(size);
    int n = 0;
    for (; n < size && first != last; ++n, ++first) {
        int i = rand();
        while (v[i]) {
            i = rand();
        }
        v[i] = true;
        *(ofirst +i) = *first;
    }
}

template <class ForwardIterator, class OutputIterator, class Distance, class RandomNumberGenerator>
OutputIterator 
random_sample_n(ForwardIterator first, ForwardIterator last, OutputIterator out, Distance n, RandomNumberGenerator& rand)
{
    std::vector<bool> v(n);
    for (Distance i = 0; i < n && first != last; ++i, ++first) {
        int random = rand();
        while (v[random]) {
            random = rand();
        }
        v[random] = true;
        *out = *(std::advance(first, random));
    }
    return out;
}

template <typename ForwardIterator, typename Predicate>
ForwardIterator
partition(ForwardIterator first, ForwardIterator last, Predicate pred)
{
    ForwardIterator result = first;
    while (first != last) {
        if (pred(*first)) {
            std::swap(*result, *first);
            ++result;
        }
        ++first;
    }
    return result;
}

template <typename ForwardIterator, typename Predicate>
ForwardIterator
stable_partition(ForwardIterator first, ForwardIterator last, Predicate pred)
{
    ForwardIterator result = last;
    while (first != last) {
        if (pred(*first)) {
            ForwardIterator shift = first;
            ForwardIterator with = shift;
            ++with;
            result = with;
            while (with != last) {
                std::swap(*shift, *with);
                ++shift;
                ++with;
            }
        }
        ++first;
    }
    return result;
}

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void 
sort(RandomAccessIterator first, RandomAccessIterator last, StrictWeakOrdering comp)
{
    if (last - first <= 1) return;

    const typename std::iterator_traits<RandomAccessIterator>::value_type pivot = *(first + (last - first) / 2);

    RandomAccessIterator left = first;
    RandomAccessIterator right = last - 1;

    while (left <= right) {
        while (comp(*left, pivot)) ++left;
        while (comp(pivot, *right)) --right;

        if (left <= right) {
            std::swap(*left++, *right--);
        }
    }

    sort(first, right + 1);
    sort(left, last);
}

template <class RandomAccessIterator, class StrictWeakOrdering>
void 
stable_sort(RandomAccessIterator first, RandomAccessIterator last, StrictWeakOrdering comp)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;
    std::vector<value_type> result(std::distance(first, last));
    mergeSort(first, last, result.begin(), comp);
}

template <typename RandomAccessIterator, typename RandomAccessIterator2, class StrictWeakOrdering>
void 
mergeSort(RandomAccessIterator first, RandomAccessIterator last, RandomAccessIterator2 buffer, StrictWeakOrdering comp)
{
    int size = std::distance(first, last);
    if (size <= 1) return;

    RandomAccessIterator mid = first + size / 2;

    mergeSortRecursive(first, mid, buffer);
    mergeSortRecursive(mid, last, buffer);

    RandomAccessIterator left = first;
    RandomAccessIterator right = mid;
    RandomAccessIterator2 out = buffer;

    while (left != mid && right != last) {
        if (comp(*right, *left)) {
            *out++ = *right++;
            continue;
        }
        *out++ = *left++;
    }
    while (left != mid) {
        *out++ = *left++;
    }
    while (right != last) {
        *out++ = *right++;
    }
    for (int i = 0; i < size; ++i) {
        *(first + i) = *(buffer + i);
    }

}

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void 
partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last, StrictWeakOrdering comp)
{
    while (first != middle) {
        for (RandomAccessIterator it = first + 1; it != last; ++it) {
            if (comp(*it, *first)) std::swap(*first, *it);
        }
        ++first;
    }
}

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void 
partial_stable_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last, StrictWeakOrdering comp)
{
    while (first != middle) {
        for (RandomAccessIterator it = first + 1; it != last; ++it) {
            if (comp(*it, *first)) {
                for (RandomAccessIterator shift = first; shift != it; ++shift) {
                    std::swap(*shift, *it);
                }
            }
        }
        ++first;
    }
}

template <typename ForwardIterator, typename StrictWeakOrdering>
bool 
is_sorted(ForwardIterator first, ForwardIterator last, StrictWeakOrdering comp)
{
    if (first == last) return true;
    ForwardIterator next = first;
    ++next;
    while (next != last) {
        if (pred(*next, *first)) return false;
        ++next;
        ++first;
    }
    return true;
}

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void 
nth_element(RandomAccessIterator first, RandomAccessIterator nth, RandomAccessIterator last, StrictWeakOrdering comp)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type value_type;

    while (last - first > 1) {
        const value_type pivot = *(first + (last - first) / 2);

        RandomAccessIterator left = first;
        RandomAccessIterator right = last - 1;

        while (left < right) {
            while (comp(*left, pivot)) ++left;
            while (comp(pivot, *right)) --right;

            if (left > right) break;
            std::swap(*left++, *right--);
        }
        if (!comp(pivot, *nth) && !comp(*nth, pivot)) return;

        if (nth <= right) {
            last = right + 1;
        }
        else {
            first = left;
        }
    }
}

template <class ForwardIterator, class T, class StrictWeakOrdering>
ForwardIterator 
lower_bound(ForwardIterator first, ForwardIterator last, const T& value, StrictWeakOrdering comp)
{
     while (first != last) {
        if (!(comp(*first, value))) return first;
        ++first;
    }
    return last;
}

template <class ForwardIterator, class T, class StrictWeakOrdering>
ForwardIterator 
upper_bound(ForwardIterator first, ForwardIterator last, const T& value, StrictWeakOrdering comp)
{
    while (first != last) {
        if (comp(value, *first)) return first;
        ++first;
    }
    return last;
}

template <class ForwardIterator, class T, class StrictWeakOrdering>
std::pair<ForwardIterator, ForwardIterator> 
equal_range(ForwardIterator first, ForwardIterator last, const T& value, StrictWeakOrdering comp)
{
    ForwardIterator lower = last;
    while (first != last) {
        if (!(comp(*first, value))) {
            lower = first;
            break;
        }
        ++first;
    }
    ForwardIterator upper = last;
    while (first != last) {
        if (comp(value, *first)) {
            upper = first;
            break;
        }
        ++first;
    }
    return std::make_pair(lower, upper);
}

template <class ForwardIterator, class T, class StrictWeakOrdering>
bool 
binary_search(ForwardIterator first, ForwardIterator last, const T& value, StrictWeakOrdering comp)
{
    while (first != last) {
        ForwardIterator middle = first;
        int size = 0;
        std::distance(first, last, size);
        size /= 2;
        std::advance(middle, size);

        if (comp(value, *middle)) {
            last = middle;
            continue;
        }
        if (comp(*middle, value)) {
            first = ++middle;
            continue;
        }
        return true;
    }
    return false;
}


template <typename BidirectionalIterator, typename StrictWeakOrdering>
inline void 
inplace_merge(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last, StrictWeakOrdering comp)
{
    typedef typename std::iterator_traits<BidirectionalIterator>::value_type value_type;

    std::vector<value_type> left(first, middle);

    typename std::vector<value_type>::iterator leftIt = left.begin();
    BidirectionalIterator rightIt = middle;
    BidirectionalIterator it = first;

    while (leftIt != left.end() && rightIt != last) {
        if (comp(*rightIt, *leftIt)) {
            *it = *rightIt;
            ++it; ++rightIt;
            continue;
        } 
        *it = *leftIt;
        ++it;
        ++leftIt;
    }

    while (leftIt != left.end()) {
        *it = *leftIt;
        ++it;
        ++leftIt;
    }
}

template <typename InputIterator1, typename InputIterator2, typename StrictWeakOrdering>
bool
includes(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, StrictWeakOrdering comp)
{
    while (first1 != last1 && first2 != last2) {
        if (comp(*first1, *first2)) ++first2;
        ++first1;
    }
    return first2 == last2;

}

template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename StrictWeakOrdering>
OutputIterator 
set_union(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result, StrictWeakOrdering comp)
{
    while (first1 != last1 && first2 != last2) {
        if (comp(*first1, *first2)) {
            *result = *first1;
            ++result;
            ++first1;
            continue;
        }
        if (comp(*first2, *first1)) {
            *result = *first2;
            ++result;
            ++first2;
            continue;
        }
        *result = *first1;
        ++result;
        ++first1;
        ++first2;
    }
    while (first1 != last1) {
        *result = *first1;
        ++result;
        ++first1;
    }
    while (first2 != last2) {
        *result = *first2;
        ++result;
        ++first2;
    }
    return result;
}

template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename StrictWeakOrdering>
OutputIterator 
set_intersection(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result, StrictWeakOrdering comp)
{
    while (first1 != last1 && first2 != last2) {
        if (comp(*first1, *first2)) {
            ++first1;
            continue;
        }
        if (comp(*first2, *first1)) {
            ++first2;
            continue;
        }
        *result = *first1;
        ++result;
        ++first1;
        ++first2;
    }
    return result;
}

template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename StrictWeakOrdering>
OutputIterator 
set_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result, StrictWeakOrdering comp)
{
    while (first1 != last1 && first2 != last2) {
        if (comp(*first1, *first2)) {
            *result = *first1;
            ++result;
            ++first1;
            continue;
        }
        if (comp(*first2, *first1)) {
            ++first2;
            continue;
        }
        ++first1;
        ++first2;
    }
    while (first1 != last1) {
        *result = *first1;
        ++result;
        ++first1;
    }
    return result;
}

template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename StrictWeakOrdering>
OutputIterator 
set_symmetric_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, OutputIterator result, StrictWeakOrdering comp)
{
    while (first1 != last1 && first2 != last2) {
        if (comp(*first1, *first2)) {
            *result = *first1;
            ++result;
            ++first1;
            continue;
        }
        if (comp(*first2, *first1)) {
            *result = *first2;
            ++result;
            ++first2;
            continue;
        }
        ++first1;
        ++first2;
    }
    while (first1 != last1) {
        *result = *first1;
        ++result;
        ++first1;
    }
    while (first2 != last2) {
        *result = *first2;
        ++result;
        ++first2;
    }
    return result;
}

template <typename T, typename BinaryPredicate>
const T& 
min(const T& a, const T& b, BinaryPredicate comp)
{
    if (comp(b, a)) return b;
    return a;
}

template <typename T, typename BinaryPredicate>
const T&
max(const T& a, const T& b, BinaryPredicate comp)
{
    if (comp(a, b)) return b;
    return a;
}

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator
min_element(ForwardIterator first, ForwardIterator last, BinaryPredicate comp)
{
    ForwardIterator result = first;
    while (first != last) {
        if (comp(*first, *result)) result = first;
        ++first;
    }
    return result;
}

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator 
max_element(ForwardIterator first, ForwardIterator last, BinaryPredicate comp)
{
    ForwardIterator result = first;
    while (first != last) {
        if (comp(*result, *first)) result = first;
        ++first;
    }
    return result;
}

template <typename BidirectionalIterator, typename StrictWeakOrdering>
bool
next_permutation(BidirectionalIterator first, BidirectionalIterator last, StrictWeakOrdering comp)
{
    if (first == last) return false;
    BidirectionalIterator f = last;
    --f;
    BidirectionalIterator l = first;
    --l;
    BidirectionalIterator next = f;
    --next;
    while (next != l) {
        if (comp(*next, *f)) {
            std::swap(*next, *f);
            return true;
        }
        --f;
        --next;
    }
    --last;
    while (first != last) {
        std::swap(*first, *(last));
        --last;
        if (first == last) break;
        ++first;
    }
    return false;
}

template <typename BidirectionalIterator, typename StrictWeakOrdering>
bool 
prev_permutation(BidirectionalIterator first, BidirectionalIterator last, StrictWeakOrdering comp)
{
    if (first == last) return false;
    BidirectionalIterator f = last;
    --f;
    BidirectionalIterator l = first;
    --l;
    BidirectionalIterator next = f;
    --next;
    while (next != l) {
        if (comp(*f, *next)) {
            std::swap(*next, *f);
            return true;
        }
        --f;
        --next;
    }
    --last;
    while (first != last) {
        std::swap(*first, *(last));
        --last;
        if (first == last) break;
        ++first;
    }
    return false;
}

template <typename InputIterator1, typename InputIterator2, typename T, typename BinaryFunction1, typename BinaryFunction2>
T 
inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init, BinaryFunction1 binary_op1, BinaryFunction2 binary_op2)
{
    T result = init;
    while (first1 != last1) {
        result = binary_op1(result, binary_op2(*first1, *first2));
        ++first1;
        ++first2;
    }
    return result;
}

template <typename InputIterator, typename OutputIterator, typename BinaryOperation>
OutputIterator 
partial_sum(InputIterator first, InputIterator last, OutputIterator result, BinaryOperation binary_op)
{
    if (first == last) return result;
    typename std::iterator_traits<InputIterator>::value_type sum = *first;
    *result = sum;
    ++result;
    ++first;
    while (first != last) {
        sum = binary_op(*sum, *first);
        *result = sum;
        ++result;
        ++first;
    }
    return result;
}

template <typename InputIterator, typename OutputIterator, typename BinaryFunction>
OutputIterator 
adjacent_difference(InputIterator first, InputIterator last, OutputIterator result, BinaryFunction binary_op)
{
    if (first == last) return result;
    *result = *first;
    ++result;
    InputIterator next = first;
    ++next;
    while (next != last) {
        *result = binary_op(*next, *first);
        ++result;
        ++first;
        ++next;
    }
    return result;
}

template <typename T, typename Integer, typename MonoidOperation>
T 
power(T x, Integer n, MonoidOperation op)
{
    T result = x;
    if (0 == n) return identity_element(op);
    for (Integer i = 1; i < n; ++i) {
        result = op(result, x);
    }
    return result;
}

