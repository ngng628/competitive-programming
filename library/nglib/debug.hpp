# ifndef DEBUG_HPP
# define DEBUG_HPP

# include "../font/font.h"
# include <bits/stdc++.h>

class CDebug {
public:
   CDebug() : buff("\a", 1) {}

   template <class T>
   void Log(const T& data) {
      std::cerr << "[ " << Font::Fore::Magenta << "LOG" << Font::Style::Reset << " ] ";

      auto s = toString(data);
      if (s == buff.first) {
         buff.second += 1;
         std::cerr << "\033[1A";
         std::cerr << Font::Back::Blue << Font::Fore::White << Font::Style::Bold;
         std::cerr << '(' << buff.second << ')';
         std::cerr << Font::Style::Reset;
         std::cerr << ' ';
      }
      else {
         buff.first = s;
         buff.second = 1;
      }

      std::cerr << s << std::endl;
   }

   template <class T>
   void Log(const std::vector<T>& data) {
      std::cerr << "[ " << Font::Fore::Magenta << "LOG" << Font::Style::Reset << " ] ";

      auto s = toString(data);
      if (s == buff.first) {
         buff.second += 1;
         std::cerr << "\033[1A";
         std::cerr << Font::Back::Blue << Font::Fore::White << Font::Style::Bold;
         std::cerr << '(' << buff.second << ')';
         std::cerr << Font::Style::Reset;
         std::cerr << ' ';
      }
      else {
         buff.first = s;
         buff.second = 1;
      }

      s = replaceAll(s, " ", ", ");

      std::cerr << "(" << data.size() << ") [";
      for (char c : s) {
         if (isdigit(c)) {
            std::cerr << Font::Fore::RGB(174, 129, 255);
            std::cerr << c;
            std::cerr << Font::Style::Reset;
         }
         else {
            std::cerr << c;
         }
      }
      std::cerr << "]" << std::endl;
   }


private:
   std::pair<std::string, int> buff;

   template <class T>
   std::string toString(const T& data) {
      std::stringstream ss;
      ss << data;
      return ss.str();
   }

   std::string replaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

} Debug;

# endif // DEBUG_HPP