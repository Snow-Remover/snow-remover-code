#ifndef _MEASUREMENT_DISTANCE_H_
#define _MEASUREMENT_DISTANCE_H_


namespace Measurement
{
  
  class Distance : public Comparable<Distance>
  {
    
    public:
    
    static Distance from_centimeters(const float centimeters);
    static Distance from_meters(const float meters);
    static Distance from_millimeters(const float millimeters);
    static Distance zero();
    
    Distance();
    
    float centimeters() const;
    float meters() const;
    float millimeters() const;
    Distance absolute() const;
    Distance operator+(const Distance& other_distance) const;
    Distance& operator+=(const Distance& other_distance);
    Distance operator-() const;
    Distance operator-(const Distance& other_distance) const;
    Distance& operator-=(const Distance& other_distance);
    template <typename Numeric>
    Distance operator*(const Numeric number) const;
    template <typename Numeric>
    Distance& operator*=(const Numeric number);
    template <typename Numeric>
    Distance operator/(const Numeric number) const;
    template <typename Numeric>
    Distance& operator/=(const Numeric number);
    template <typename Numeric>
    Numeric operator/(const Distance& other_distance) const;
    Distance operator%(Distance& other_distance) const;
    Distance& operator%=(Distance& other_distance);
    Distance& operator=(const Distance& other_distance);
    
    protected:
    
    float _meters;
    
    Comparable<Distance>::Comparison _compare_with(const Distance other_distance) const;
    void _set_centimeters(float centimeters);
    void _set_meters(float meters);
    void _set_millimeters(float millimeters);
    
  };
  
}

#endif
