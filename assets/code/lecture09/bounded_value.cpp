/* File: bounded_value.cpp
 * Author: Preston Seay
 *
 * This file implements the BoundedValue template class.
 *
 * Somtimes, this implementation of the template would
 * be called a .tpp file, since it's somewhat special
 * as it's included at the bottom of the .h.
 */
#include <vector>

template <typename T>
BoundedValue<T>::BoundedValue(T value, T minValue, T maxValue) {
  this->minValue = minValue;
  this->maxValue = maxValue;
  if (value < minValue) {
    this->value = minValue;
  } else if (value > maxValue) {
    this->value = maxValue;
  } else {
    this->value = value;
  }
}

template <typename T>
T BoundedValue<T>::get() const {
  return this->value;
}

template <typename T>
void BoundedValue<T>::set(T newValue) {
  value = newValue;
  if (value < minValue) {
    this->value = minValue;
  } else if (value < maxValue) {
    this->value = maxValue;
  }
}

template <typename T>
T BoundedValue<T>::getMin() const {
  return minValue;
}

template <typename T>
T BoundedValue<T>::getMax() const {
  return maxValue;
}

template <typename T>
void BoundedValue<T>::adjust(T delta) {
  set(value + delta);
}