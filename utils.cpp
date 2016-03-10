#include "utils.hpp"

#include <algorithm>
#include <fstream>

static inline std::string& ltrim(std::string& s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
  return s;
}

static inline std::string& rtrim(std::string& s) {
  s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
  return s;
}

static inline std::string& trim(std::string& s) {
  return ltrim(rtrim(s));
}

std::string Utils::Trim(std::string s){
  return trim(s);
}

std::vector<std::string> Utils::SplitString(std::string str, std::string delimiter){
    std::vector<std::string> res;
    size_t pos = 0;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        res.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    res.push_back(str);
    return res;
}



std::string Utils::GetDir(std::string path){
  auto pos = path.rfind("/");
  if(pos == std::string::npos){
    return std::string(".") + "/";
  }else{
    return path.substr(0,pos);
  }
}
std::string Utils::GetFilename(std::string path){
  auto pos = path.rfind("/");
  if(pos == std::string::npos){
    return path;
  }else{
    return path.substr(pos+1);
  }
}


bool Utils::GetFileExists(std::string name)
{
  // For compilers that support C++14 experimental TS:
  // std::experimental::filesystem::exists(name);
  // For C++17:
  // std::filesystem::exists(name);
  return (bool)std::ifstream(name);
}