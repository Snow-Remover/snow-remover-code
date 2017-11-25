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
      
      update();
    }
    
    
    void Positioning::update()
    {
      _position = _get();
    }
    
    
    //
    // private
    //
    
    
    Position Positioning::_position;
    const uint8_t Positioning::_num_anchors = 4;  // must be 4 for now
    // y 151cm
    // | 0x6032       0x6035
    // |       <robot>
    // | 0x601B       0x6046
    // +----------------------x 216cm
    uint16_t Positioning::_anchors[_num_anchors] = {0x601B, 0x6046, 0x6032, 0x6035};
    int32_t Positioning::_anchors_x[_num_anchors] = {0, 2160, 0, 2160};
    int32_t Positioning::_anchors_y[_num_anchors] = {0, 0, 1510, 1510};
    int32_t Positioning::_heights[_num_anchors] = {0, 0, 0, 0};
    uint8_t Positioning::_algorithm = POZYX_POS_ALG_UWB_ONLY;
    uint8_t Positioning::_dimension = POZYX_2D;
    int32_t Positioning::_height = 180;
    
    
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
      //heading -= Measurement::CoterminalAngle::from_degrees(117.4); // coordinate space direction adjustment
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
    
  }
} 
