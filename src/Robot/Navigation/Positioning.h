#ifndef _ROBOT_NAVIGATION_POSITIONING_H_
#define _ROBOT_NAVIGATION_POSITIONING_H_


namespace Robot
{
  namespace Navigation
  {
    
    class Positioning
    {
      
      public:
      
      static Position get();
      
      static void setup();
      
      private:
      
      static const uint8_t _num_anchors;                                    // the number of anchors
      static uint16_t _anchors[];     // the network id of the anchors: change these to the network ids of your anchors.
      static int32_t _anchors_x[];               // anchor x-coorindates in mm
      static int32_t _anchors_y[];                  // anchor y-coordinates in mm
      static int32_t _heights[];              // anchor z-coordinates in mm
      static uint8_t _algorithm;             // positioning algorithm to use. try POZYX_POS_ALG_TRACKING for fast moving objects.
      static uint8_t _dimension;                           // positioning dimension
      static int32_t _height;                                  // height of device, required in 2.5D positioning
      
      static void _set_anchors_manual(); // function to manually set the anchor coordinates
      
    };
    
  }  
}

#endif
