#include "Navigation.h"


namespace Robot
{
  namespace Navigation
  {
    
    //
    // public
    //
    
    
    boolean TranslationCompensation::is_complete() // crossed finish line?
    {
      if (!_complete)
      {
        if (_start_point == _finish_point)
          _complete = true;
        else
        {
          Geometry::Line trajectory = Geometry::Line::from_points(_start_point, _finish_point);
          Geometry::Line finish_line = trajectory.perpendicular_through(_finish_point);
          Geometry::Line::Side side_of_start = finish_line.get_side_of(_start_point);
          Geometry::Line::Side side_of_robot = finish_line.get_side_of(_robot_point());
          _complete = side_of_start != side_of_robot;
        }
      }
      return _complete;
    }
    
    
    void TranslationCompensation::set_target(Location location)
    {
      _start_point = _finish_point;
      _finish_point = Geometry::Point(location.x().meters(), location.y().meters());
      _complete = false;
    }
    
    
    void TranslationCompensation::setup()
    {
      _start_point = _robot_point();
      //_start_point = Geometry::Point(0.0, 0.8);;
      //_finish_point = _start_point;
      _finish_point = Geometry::Point(0.8, 0.8);
      _adjustment_timer.reset();
      _complete_timer.reset();
      _complete = false;
    }
    
    
    void TranslationCompensation::tick()
    {
      if (_adjustment_timer.is_complete())
      {
        _adjustment_update();
        _adjustment_timer.increment_interval();
      }
      if (_complete_timer.is_complete())
      {
        _complete_update();
        _complete_timer.increment_interval();
      }
    }
    
    
    //
    // private
    //
    
    
    PeriodicTimer TranslationCompensation::_adjustment_timer = PeriodicTimer(500, PeriodicTimer::Units::Milliseconds);
    PeriodicTimer TranslationCompensation::_complete_timer = PeriodicTimer(200, PeriodicTimer::Units::Milliseconds);
    Geometry::Point TranslationCompensation::_start_point;
    Geometry::Point TranslationCompensation::_finish_point;
    boolean TranslationCompensation::_complete;
    
    
    Geometry::Point TranslationCompensation::_robot_point()
    {
      Location location = Positioning::get().location();
      return Geometry::Point(location.x().meters(), location.y().meters());
      //return Geometry::Point(0, 0.4);
    }
    
    
    void TranslationCompensation::_adjustment_update()
    {
      if (_start_point != _finish_point)
      {
        Geometry::Line trajectory = Geometry::Line::from_points(_start_point, _finish_point); // can't build line if _start_point == _finish_point
        Serial.print("robot_point: ");
        Serial.print(_robot_point().x());
        Serial.print(" ");
        Serial.print(_robot_point().y());
        Serial.println();
        Geometry::Point direction = trajectory.direction().normalized();
        //Serial.print("trajectory.point: ");
        //Serial.print(trajectory.point().x());
        //Serial.print(" ");
        //Serial.print(trajectory.point().y());
        //Serial.println();
        //Serial.print("trajectory.direction: ");
        //Serial.print(trajectory.direction().x());
        //Serial.print(" ");
        //Serial.print(trajectory.direction().y());
        //Serial.println();
        Geometry::Point rotate_point_target;
        if (trajectory.get_side_of(_robot_point()) == Geometry::Line::Side::OnLine)
        {
          rotate_point_target = _robot_point() + (direction * 0.3); // 30 cm in front of ideal robot point
          //Serial.println("robot on trajectory");
        }
        else
        {
          Geometry::Line progress_line = trajectory.perpendicular_through(_robot_point()); // can't build line if robot_point lies on trajectory
          //Serial.print("progress_line.direction: ");
          //Serial.print(progress_line.direction().x());
          //Serial.print(" ");
          //Serial.print(progress_line.direction().y());
          //Serial.println();
          Geometry::Point progress_point = trajectory.intersects_with(progress_line);
          //Serial.print("progress_point: ");
          //Serial.print(progress_point.x());
          //Serial.print(" ");
          //Serial.print(progress_point.y());
          //Serial.println();
          rotate_point_target = progress_point + (direction * 0.3); // 30 cm in front of ideal robot point
        }
        //Serial.print("rotate_point_target: ");
        //Serial.print(rotate_point_target.x());
        //Serial.print(" ");
        //Serial.print(rotate_point_target.y());
        //Serial.println();
        Measurement::CoterminalAngle rotate_angle_target = _robot_point().angle_to(rotate_point_target);
        Measurement::CoterminalAngle rotate_heading_target = Measurement::CoterminalAngle::from_degrees(90.0) - rotate_angle_target;
        RotationCompensation::set_target(rotate_heading_target);
      }
    }
    
    
    void TranslationCompensation::_complete_update()
    {
      if (is_complete())
      {
        MotorMixer::set_left_translation_input(0.0);
        MotorMixer::set_right_translation_input(0.0);
      }
      else
      {
        MotorMixer::set_left_translation_input(100.0);
        MotorMixer::set_right_translation_input(100.0);
      }
    }
    
    
  }
} 
