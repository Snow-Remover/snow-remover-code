#ifndef _MESSAGE_BUFFER_H_
#define _MESSAGE_BUFFER_H_

#include <Arduino.h>


class MessageBuffer
{
  
  public:
  
  MessageBuffer(Stream &stream, byte length);
  
  boolean available();
  String read();
  void tick();
  void write(String message);
  
  private:
  
  String _buffer;
  byte _buffer_length;
  boolean _message_available;
  Stream& _stream;
  
};

#endif
