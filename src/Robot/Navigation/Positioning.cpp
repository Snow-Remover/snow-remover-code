#include "Navigation.h"


namespace Robot
{
  namespace Navigation
  {
    
    //
    // public
    //
    
    
    Position Positioning::get()
    {
      return _position;
    }
    
    
    void Positioning::setup()
    {
      if(Pozyx.begin() == POZYX_FAILURE)
      {
        Serial.println(F("ERROR: Unable to connect to POZYX shield"));
        Serial.println(F("Reset required"));
        delay(100);
        end();
      }
      
      // clear all previous devices in the device list
      Pozyx.clearDevices();
      // sets the anchor manually
      _set_anchors_manual();
      // sets the positioning algorithm
      Pozyx.setPositionAlgorithm(_algorithm, _dimension);
      //printCalibrationResult();
      delay(2000);
      
      _update_timer.reset();
      _update();
    }
    
    
    void Positioning::tick()
    {
      if (_update_timer.is_complete())
      {
        _update();
        _update_timer.increment_interval();
      }
    }
    
    
    //
    // private
    //
    
    
    PeriodicTimer Positioning::_update_timer = PeriodicTimer(250, PeriodicTimer::Units::Milliseconds);
    Position Positioning::_position;
    const uint8_t Positioning::_num_anchors = 4;  // must be 4 for now
    // y 151cm
    // | 0x6032       0x6035
    // |       <robot>
    // | 0x601B       0x6046
    // +----------------------x 216cm
    uint16_t Positioning::_anchors[_num_anchors] = {0x601B, 0x6046, 0x6032, 0x6035};
    int32_t Positioning::_anchors_x[_num_anchors] = {0, 1830, 0, 1830};
    int32_t Positioning::_anchors_y[_num_anchors] = {0, 0, 1210, 1210};
    int32_t Positioning::_heights[_num_anchors] = {0, 0, 0, 0};
    //uint8_t Positioning::_algorithm = POZYX_POS_ALG_UWB_ONLY;
    uint8_t Positioning::_algorithm = POZYX_POS_ALG_TRACKING;
    //uint8_t Positioning::_dimension = POZYX_2D;
    uint8_t Positioning::_dimension = POZYX_3D;
    int32_t Positioning::_height = 100;
    
    
    Position Positioning::_get()
    {
      int status;
      
      coordinates_t position;
      status = Pozyx.doPositioning(&position, _dimension, _height, _algorithm);
      if (status != POZYX_SUCCESS)
      {
        Serial.println("ERROR: in Positioning::get() in Pozyx.doPositioning()");
        //end();
      }
      //position.x
      //position.y
      //position.z
      Measurement::Distance x = Measurement::Distance::from_millimeters(position.x);
      //x = Measurement::Distance::from_millimeters(position.x); // adjustment
      Measurement::Distance y = Measurement::Distance::from_millimeters(position.y);
      //y = Measurement::Distance::from_millimeters(position.y); // adjustment
      
      euler_angles_t euler_angles;
      status = Pozyx.getEulerAngles_deg(&euler_angles);
      if (status != POZYX_SUCCESS)
      {
        Serial.println("ERROR: in Positioning::get() in Pozyx.getEulerAngles_deg()");
        end();
      }
      //euler_angles.heading
      //euler_angles.roll
      //euler_angles.pitch
      Measurement::CoterminalAngle heading = Measurement::CoterminalAngle::from_degrees(euler_angles.heading);
      heading += Measurement::CoterminalAngle::from_degrees(90.0); // shield direction adjustment
      heading -= Measurement::CoterminalAngle::from_degrees(176.0); // coordinate space direction adjustment
      Serial.print("heading: ");
      Serial.println(heading.degrees());
      return Position(x, y, heading);
    }
    
    
    void Positioning::_set_anchors_manual()
    {
      for(int i = 0; i < _num_anchors; i++)
      {
        device_coordinates_t anchor;
        anchor.network_id = _anchors[i];
        anchor.flag = 0x1;
        anchor.pos.x = _anchors_x[i];
        anchor.pos.y = _anchors_y[i];
        anchor.pos.z = _heights[i];
        Pozyx.addDevice(anchor);
      }
    }
    
    
    void Positioning::_update()
    {
      //Measurement::Distance old_x = _position.x();
      //Measurement::Distance old_y = _position.y();
      
      Position new_position = _get();
      //Measurement::Distance new_x = new_position.x();
      //Measurement::Distance new_y = new_position.y();
      //Measurement::CoterminalAngle new_heading = new_position.heading();
      
      //Measurement::Distance filtered_x = old_x * 0.9 + new_x * 0.1;
      //Measurement::Distance filtered_y = old_y * 0.9 + new_y * 0.1;
      //Position filtered_position = Position(filtered_x, filtered_y, new_heading);
      
      //_position = filtered_position;
      _position = new_position;
    }
    
  }
} 
