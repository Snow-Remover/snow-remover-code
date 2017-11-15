#include "MessageBuffer.h"


//
// public
//


MessageBuffer::MessageBuffer(Stream &stream, byte length)
: _stream(stream)
{
  _message_available = false;
  _buffer_length = length;
  _buffer.reserve(_buffer_length);
}


boolean MessageBuffer::available()
{
  return _message_available;
}


String MessageBuffer::read()
{
  String message = "";
  if (_message_available)
  {
    _message_available = false;
    message = _buffer;
    _buffer = "";
  }
  return message;
}


void MessageBuffer::tick()
{
  if (!_message_available && _stream.available())
  {
    char c = _stream.read();
    if (c == '\n')
      _message_available = true;
    else
    {
      if (_buffer.length() <= _buffer_length)
        _buffer += c;
    }
  }
}


void MessageBuffer::write(String message)
{
  _stream.print(message);
  _stream.print('\n');
}


//
// private
//

