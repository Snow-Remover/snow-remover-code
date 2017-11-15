
//
// public
//


template <class AnyType>
boolean Comparable<AnyType>::operator<(const AnyType other_object) const
{
  return _compare_with(other_object) == Comparison::Less;
}


template <class AnyType>
boolean Comparable<AnyType>::operator<=(const AnyType other_object) const
{
  return (*this < other_object) || (*this == other_object);
}


template <class AnyType>
boolean Comparable<AnyType>::operator==(const AnyType other_object) const
{
  return _compare_with(other_object) == Comparison::Equal;
}


template <class AnyType>
boolean Comparable<AnyType>::operator!=(const AnyType other_object) const
{
  return !(*this == other_object);
}


template <class AnyType>
boolean Comparable<AnyType>::operator>(const AnyType other_object) const
{
  return _compare_with(other_object) == Comparison::Greater;
}


template <class AnyType>
boolean Comparable<AnyType>::operator>=(const AnyType other_object) const
{
  return (*this > other_object) || (*this == other_object);
}


template <class AnyType>
boolean Comparable<AnyType>::is_between(const AnyType start_range_object, const AnyType end_range_object) const
{
  return (*this > start_range_object) && (*this < end_range_object);
}


//
// private
//
