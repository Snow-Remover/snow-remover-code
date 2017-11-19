#ifndef _MEASUREMENT_COTERMINAL_ANGLE_H_
#define _MEASUREMENT_COTERMINAL_ANGLE_H_

/* It should be noted that in the context of the this project,
 * coterminal angles can only range from 0 to 360 degrees, that is an
 * angle of 10 degrees is equivalent to 370 degrees and -350 degress.
 * 
 * The main purpose this class exists is to allow other code to easily
 * work with and compare angles, with out requiring the classes to
 * implement all the comparison logic.
 * 
 * This class also offers the conversion between degrees and
 * revolutions (a revolution being 360 degrees)
 */

namespace Measurement
{
  
  class CoterminalAngle : public BaseAngle<CoterminalAngle>
  {
    friend BaseAngle;
    
    public:
    
    using BaseAngle::BaseAngle;
    
    CoterminalAngle difference_from(const CoterminalAngle other_angle);
    boolean is_between(const CoterminalAngle start_angle, const CoterminalAngle end_angle);
    boolean operator==(const CoterminalAngle other_angle);
    boolean operator!=(const CoterminalAngle other_angle);
    
    public:
    
    void _clean(); // ensure angle is only between 0 and 360 degress
    void _set_degrees(const float degrees);
    void _set_revolutions(const float revolutions);
    
  };
  
}

#endif
