#ifndef _COMPARABLE_H_
#define _COMPARABLE_H_

/*
 * The Comparable mixin is used by classes whose objects may be ordered.
 * The class must define the '_compare_with(other_object)' method, which
 * compares the receiver against another object, returning
 * Less, Equal, or Greater depending on whether the receiver is less than,
 * equal to, or greater than the other object. Comparable uses the
 * 'compare_with(other_object)' method, to implement the conventional
 * comparison operators (<, <=, ==, >=, and >) and the method
 * is_between(start, end).
 * 
 * This class was based off Ruby's Comparable mixin and 
 *   https://codereview.stackexchange.com/questions/112430/a-mixin-comparator-class
 * 
 * 
 * Example use:
 * 
 * class Example : public Comparable<Example>
 * {
 *   
 *   Comparable<Example>::Comparison _compare_with(Example other_object)
 *   {
 *     if (...) // less then
 *       return Comparable::Comparison::Less;
 *     else if (...) // greater then
 *       return Comparable::Comparison::Greater;
 *     else // equal
 *       return Comparable::Comparison::Equal;
 *   }
 *
 *    //...
 * 
 * };
 * 
 * 
 * Author: Rob Fors
 * Last Revision Date: 20171113
 */


#include <Arduino.h>

template <class AnyType>
class Comparable
{
  
  public:
  
  enum class Comparison { Equal, Less, Greater };
  
  boolean operator<(const AnyType other_object) const;
  boolean operator<=(const AnyType other_object) const;
  boolean operator==(const AnyType other_object) const;
  boolean operator!=(const AnyType other_object) const;
  boolean operator>(const AnyType other_object) const;
  boolean operator>=(const AnyType other_object) const;
  boolean is_between(const AnyType start_range_object, const AnyType end_range_object) const;
  
  protected:
  
  virtual Comparison _compare_with(const AnyType other_object) const;
  
};

// Include implementation file at the end of the header. This way,
// implementation is still separated from declaration, but is accessible
// to the compiler.
#include "Comparable.tpp"

#endif
