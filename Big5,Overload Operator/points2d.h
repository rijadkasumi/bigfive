// Rijad Kasumi (rijad.kasumi11@myhunter.cuny.edu)
// Date 09-09-2022
// points2d.h Header file
// Class Points2D main purpose is to read the input from the test_input_file.txt and print out the expected output
// Class Points2D reads and prints out the a set of sequence with the desired size of 2D two dimensional array of points
// The Big Five is implementated which includes (The Desctructor, Copy Constructor, Copy Assignment Operator, Move Constructor, Move Assignment Operator)
// Implemenation of the overloaded operators


#ifndef CSCI335_HOMEWORK1_POINTS2D_H_
#define CSCI335_HOMEWORK1_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {


template<typename Object>

class Points2D {
  public:
    // Zero-parameter constructor.
    // Size set to 0.
    Points2D() { 
        sequence_ = nullptr;
        size_= 0;  
    };

    // Copy-constructor
    // Used to create a new object by copying the state of an existing object
    Points2D(const Points2D &rhs){
        size_ = rhs.size();
        sequence_ = new std::array<Object, 2>[rhs.size()];
        for (size_t i = 0; i < rhs.size(); i++){
            sequence_[i][0] = rhs.sequence_[i][0];
            sequence_[i][1] = rhs.sequence_[i][1];
     }
        };
    // Copy-assignment
    // Used to change the state of the object by changing it into the state of some existing object by copying that state into one that is being changed 
    Points2D& operator=(const Points2D &rhs)  {
        Points2D copy = rhs;
        std::swap(*this, copy);
        return *this; 
    };

    // Move-constructor.
    // Used to create a new object by copying the state of a temporary r-value
    Points2D(Points2D &&rhs) {
        size_ = std::move(rhs.size_);
        sequence_ = std::move(rhs.sequence_);
        rhs.sequence_ = nullptr;
        rhs.size_ = 0;
    };

    // Move-assignment.
    // Used to change the state of an existing object by copying the state of a temporary r-value object into the new object
    // Moving the content of the temporary object into the current object 
    // Return the refrence of this object by derefrencing the this pointer
    Points2D& operator=(Points2D &&rhs) {
        std::swap(size_, rhs.size_);  
        std::swap(sequence_, rhs.sequence_);
        return *this; 
 
    };
    // Destructor
    // Used when an object goes out of scope and is ready to be removed - free
    // Returning the memory to the heap
    ~Points2D() {
        delete [] sequence_; 
    };

    // End of big-five.

    // One parameter constructor.
    Points2D(const std::array<Object, 2>& item) {
        sequence_ = new std::array<Object,2>{item}; 
        size_ = 1; 
        sequence_[0] = item;
    };

    size_t size() const {
        return size_;
    };

    // @location: an index to a location in the sequence.
    // @returns the point at @location.
    // const version.
    // abort() if out-of-range.
    const std::array<Object, 2>& operator[](size_t location) const { // Overload array operator

        //Checks if location is out of range
        if(location < 0 or location > size_){ 
        abort(); // abort if out-of-range.
         }
        return sequence_[location];
    };

    //  @c1: A sequence.
    //  @c2: A second sequence.
    //  @return their sum. If the sequences are not of the same size, append the
    //    result with the remaining part of the larger sequence.
    friend Points2D operator+(const Points2D &c1, const Points2D &c2) {
    Points2D<Object> sum_Of_Sequences; 
    size_t temporary_Size = 0; // //temporary_Size in case one of the sequences is greater than the other one
    size_t i_Append_The_Result = 0; //i_Append_The_Result
    bool not_Equal_Size; // Depending on size return true or false  
    bool c1_Bigger = false; //c1_Bigger
    bool c2_Bigger = false; //c2_Bigger
    size_t final_Size = 0; //final_Size is the size of the bigger sequence
    if (c1.size() == c2.size()){ //If both sequences have the same size
        //final_size and temporary_Size are the same
        final_Size = c2.size();
        not_Equal_Size = false; 
        temporary_Size =  c2.size();
    }
    else if(c1.size() > c2.size()){ //If the size of c1 is greater than c2
        final_Size = c1.size();
        not_Equal_Size = true;
        temporary_Size = c2.size();
        c1_Bigger = true;
    }
    else if(c2.size() > c1.size()){ //If the size of c2 is greater than c1
        final_Size = c2.size();
        not_Equal_Size = true;
        temporary_Size = c1.size();
        c2_Bigger = true;
    }
    sum_Of_Sequences.size_ = final_Size;
    sum_Of_Sequences.sequence_ = new std::array<Object, 2>[final_Size]; //Store new array dynamically
    //for loop which saves the sum of each sequence into sum_Of_Sequences
    //using temporary_Size since we don't know if one sequence will be larger than the other
    for (size_t i = 0; i < temporary_Size; i++) {
        sum_Of_Sequences.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0]; 
        sum_Of_Sequences.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1]; 
        i_Append_The_Result++;
    }
    if(not_Equal_Size){ //If they are not equal size
        if (c2_Bigger){ //If c2 size is bigger
            for(size_t i  =  i_Append_The_Result; i < sum_Of_Sequences.size_; i++){ //Copy the remaining arrays of c2 into sum_of_two_sequences
                sum_Of_Sequences.sequence_[i][0] = c2.sequence_[i][0];
                sum_Of_Sequences.sequence_[i][1] = c2.sequence_[i][1];
            }
        }
        else if (c1_Bigger){ //If c1 size is bigger
            for(size_t i = i_Append_The_Result; i < sum_Of_Sequences.size_; i++){ //Copy the remaining arrays of c1 into sum_of_two_sequences
                sum_Of_Sequences.sequence_[i][0] = c1.sequence_[i][0];
                sum_Of_Sequences.sequence_[i][1] = c1.sequence_[i][1];
            }
        }
    }
    return sum_Of_Sequences;
    
  };
    // Overloading the ostream << operator.
    friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points) {
        if (some_points.size() > 0){      //If the sequence not 0 (is not empty)
        for( size_t i = 0;  i < some_points.size(); i++){
            out << "(" << some_points.sequence_[i][0] << ", " << some_points.sequence_[i][1] << ") ";
        }
    }
    else if (some_points.size() == 0){ //If the sequence equal 0 (is empty)
        out << "()"; //The program will print a pair of brackets
   }
        out << std::endl;
         return out;
  };
    // Overloading the istream >> operator.
    // Read a chain from an input stream (e.g., standard input).
    friend std::istream &operator>>(std::istream &in, Points2D &some_points) {
        size_t size_Of_Sequence;
        // Get the size first
        in >> size_Of_Sequence;
        some_points.size_=  size_Of_Sequence;
        // Dynamically store the sequence
        some_points.sequence_ = new std::array<Object, 2>[some_points.size_];
        for(size_t i = 0;  i < some_points.size(); i++){
        // Get the rest of the input and save them inside the some_points
        in >> some_points.sequence_[i][0];
        in >> some_points.sequence_[i][1];
    } 
        // Once no more input abort()
       if(in.fail()){
        std::abort();
    }
        std::cout << std::endl;
        return in;
    };

  private:
    // Sequence of points.
    std::array<Object, 2> *sequence_;
    // Size of sequence.
    size_t size_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_Points2D_H_
