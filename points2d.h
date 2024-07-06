// --> Farhin Bhuiyan
// The Points2D class represents a sequence of 2D points. Each point is represented as an array of two elements of type Object. 
// The class supports basic operations such as copying, moving, addition of sequences, and reading/writing from/to streams.

#ifndef CSCI335_HOMEWORK1_POINTS2D_H_
#define CSCI335_HOMEWORK1_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {

// The Points2D class template.
template<typename Object>
class Points2D {
  public:
    // Default constructor.
    // Initializes size_ to 0 and sequence_ to nullptr.
    Points2D() : size_{0}, sequence_{nullptr} {}

    // Copy constructor.
    // Creates a deep copy of the given Points2D object.
    Points2D(const Points2D &rhs) : size_{rhs.size_}, sequence_{new std::array<Object, 2>[rhs.size_]} {
        for (size_t i = 0; i < size_; ++i) {
            sequence_[i] = rhs.sequence_[i];
        }
    }

    // Copy assignment operator.
    // Uses the copy-and-swap idiom to assign a copy of rhs to this object.
    Points2D& operator=(const Points2D &rhs) {
        if (this != &rhs) {
            Points2D copy = rhs;
            std::swap(*this, copy);
        }
        return *this;
    }

    // Move constructor.
    // Transfers ownership of the data from rhs to this object.
    Points2D(Points2D &&rhs) : size_{rhs.size_}, sequence_{rhs.sequence_} {
        rhs.size_ = 0;
        rhs.sequence_ = nullptr;
    }

    // Move assignment operator.
    // Uses std::swap to transfer ownership of the data from rhs to this object.
    Points2D& operator=(Points2D &&rhs) {
        if (this != &rhs) {
            std::swap(size_, rhs.size_);
            std::swap(sequence_, rhs.sequence_);
        }
        return *this;
    }

    // Destructor.
    // Releases the dynamically allocated memory.
    ~Points2D() {
        delete[] sequence_;
    }

    // One parameter constructor.
    // Initializes the sequence with one point.
    Points2D(const std::array<Object, 2>& item) : size_{1}, sequence_{new std::array<Object, 2>[1]} {
        sequence_[0] = item;
    }

    // Returns the size of the sequence.
    size_t size() const {
        return size_;
    }

    // Overloading the [] operator.
    // Provides access to the point at the given index.
    // Aborts if the index is out of range.
    const std::array<Object, 2>& operator[](size_t location) const {
        if (location >= size_) {
            std::cerr << "Index out of range" << std::endl;
            abort();
        }
        return sequence_[location];
    }

    // Overloading the + operator.
    // Combines two Points2D sequences into one.
    friend Points2D operator+(const Points2D &c1, const Points2D &c2) {
        Points2D result;
        result.size_ = c1.size_ + c2.size_;
        result.sequence_ = new std::array<Object, 2>[result.size_];
        size_t i = 0;
        for (; i < c1.size_; ++i) {
            result.sequence_[i] = c1.sequence_[i];
        }
        for (size_t j = 0; j < c2.size_; ++j, ++i) {
            result.sequence_[i] = c2.sequence_[j];
        }
        return result;
    }

    // Overloading the << operator.
    // Prints the sequence of points to the output stream.
    friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points) {
        for (size_t i = 0; i < some_points.size_; ++i) {
            out << "(" << some_points.sequence_[i][0] << ", " << some_points.sequence_[i][1] << ") ";
        }
        out << std::endl;
        return out;
    }

    // Overloading the >> operator.
    // Reads a sequence of points from the input stream.
    friend std::istream &operator>>(std::istream &in, Points2D &some_points) {
        size_t new_size;
        in >> new_size;
        delete[] some_points.sequence_;
        some_points.size_ = new_size;
        some_points.sequence_ = new std::array<Object, 2>[new_size];
        for (size_t i = 0; i < new_size; ++i) {
            in >> some_points.sequence_[i][0] >> some_points.sequence_[i][1];
        }
        return in;
    }

  private:
    // Pointer to the sequence of points.
    std::array<Object, 2> *sequence_;
    // Size of the sequence.
    size_t size_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS2D_H_