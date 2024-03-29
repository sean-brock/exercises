#ifndef SBDS_ARRAY_H
#define SBDS_ARRAY_H

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <stdexcept>

template <typename T> class Array {
public:
  Array(std::size_t length) : length_(length) { data_ = new T[length_]; }

  Array(std::size_t length, const T &value) : length_(length) {
    data_ = new T[length_];
    std::fill_n(data_, length_, value);
  }

  void display(std::ostream &stream = std::cout,
               const std::string &delim = " ") {
    for (std::size_t i = 0; i < length_; i++) {
      stream << data_[i] << delim;
    }
    stream << std::endl;
  }

  void append(const T &item) {
    T *new_data = new T[length_ + 1];
    std::copy_n(data_, length_, new_data);
    new_data[length_] = item;

    delete[] data_;
    data_ = new_data;
    length_++;
  }

  void insert(std::size_t index, const T &item) {
    indexInRange(index);

    T *new_data = new T[length_ + 1];
    // 0 1 2 n 3 4
    //       ^ inserted item before index(3)
    if (index > 0) {
      std::copy_n(data_, index, new_data);
    }
    new_data[index] = item;
    std::copy_n(data_ + index, length_ - index, new_data + index + 1);
    delete[] data_;
    data_ = new_data;
    length_++;
  }

  T remove(std::size_t index) {
    indexInRange(index);

    T removed = data_[index];
    T *new_data = new T[length_ - 1];
    // 0 1 2 3 4
    //       ^ remove index 3
    if (index > 0) {
      std::copy_n(data_, index, new_data);
    }
    std::copy_n(data_ + index + 1, length_ - index - 1, new_data + index);

    delete[] data_;
    data_ = new_data;
    length_--;

    return removed;
  }

  void set(std::size_t index, const T &value) {
    indexInRange(index);

    data_[index] = value;
  }

  T &get(std::size_t index) {
    indexInRange(index);

    return data_[index];
  }

  struct SearchResult {
    bool found;
    std::size_t index;
  };

  SearchResult linearSearch(const T &target) const {
    for (std::size_t i = 0; i < length_; i++)
      if (data_[i] == target) {
        // transpose
        if (i > 0) {
          auto tmp = data_[i];
          data_[i] = data_[i - 1];
          data_[i - 1] = tmp;
          return {true, i - 1};
        }
        return {true, i};
      }

    return {false, 0};
  }

  SearchResult binarySearch(const T &target) const {}

  T &min();
  T &max();
  void reverse();
  void shift();

  ~Array() { delete[] data_; }

private:
  std::size_t length_;
  T *data_;

  inline void indexInRange(std::size_t index) const {
    if (index >= length_)
      throw std::out_of_range("Index exceeds array length.");
  }
};

#endif // SBDS_ARRAY_H