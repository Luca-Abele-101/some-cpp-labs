#ifndef NOTE_HPP
#define NOTE_HPP

#include <string>
#include <iostream>

namespace lutsaj
{
  struct note_t
  {
    std::string number;
    std::string name;
  };
  std::ostream& operator<<(std::ostream& out, const note_t& note);
}

#endif
