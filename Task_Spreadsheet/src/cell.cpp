
/*#include <string>
#include <iostream>
#include <sstream>
#include <vector>*/
#include "../header/cell.h"


std::istream& operator>>(std::istream& in, std::vector<int>& ob)
{
     ob.clear();
    int tmp{};
    while (in >> tmp) {
        ob.push_back(tmp);
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, const std::vector<int>& ob)
{
    for(size_t i = 0; i < ob.size(); ++i)
    {
        out << ob[i] << ' ';
    }
    return out;
}


   Cell::Cell()
    : m_str{}
    {}

   Cell::Cell(std::string val)
    : m_str(val)
    {}

//std::string getValue() const { return m_str; }

//void setValue(const std::string& value) { m_str = value; } };

    Cell::Cell(const Cell& other )//copy ctor
     : m_str {other.m_str}
     {}

    Cell::Cell(Cell&& other )
     : m_str(std::move(other.m_str)) //move ctor
     {}

    Cell::Cell(double val){
         m_str = std::to_string(val);
    }

   Cell::Cell(int val){
         m_str = std::to_string(val);
    }

    Cell::Cell(char val){
         m_str = val;
    }

   Cell::Cell(bool val){
         m_str =  (val == true) ? "true" : "false";
    }

      const Cell& Cell::operator=(const Cell& rhv){
        if(*this != &rhv){
             m_str = rhv.m_str;
            }
        return *this;
    }

    const Cell& Cell:: operator=( Cell&& rhv){
        if(*this != &rhv){
            this->m_str.clear();
            this->m_str =std::move(rhv.m_str);
            }
        return *this;
    }


    const Cell& Cell::operator=(int rhv){
        m_str = std::to_string(rhv);
        return *this;
    }

    const Cell& Cell::operator=(double rhv){
        m_str = std::to_string(rhv);
        return *this;
    }

    const Cell& Cell::operator=(bool rhv){
        m_str = (rhv == true) ? "true": "false";
        return *this;
    }
    
    const Cell& Cell::operator=(char rhv){
        m_str = rhv;
        return *this;
    }

    const Cell& Cell::operator=(std::string rhv){
        m_str = rhv;
        return *this;
    }

    const Cell& Cell::operator=(const std::vector<int>& rhv){
        std::stringstream ss;
         ss << rhv;
       m_str = ss.str();
        return *this;
    }

    Cell::operator int() const{
         return  std::stoi(this->m_str);
    }

    Cell::operator double() const{
        return std::stod(this->m_str);
    }

    Cell::operator bool() const{
        return (m_str == "true") ? true : false;
    }

    Cell::operator char() const{
        if(m_str.size() != 1){
            return '\0';
        }
      return m_str[0];
    }

   Cell::operator std::string() const{
        return m_str;
    }

    Cell::operator std::vector<int>() const{
        std::vector<int> vec;
        vec.push_back(std::stoi(m_str));
        return vec;
    }

    bool operator==(const Cell& lhv, const Cell& rhv){
        return static_cast<std::string>(lhv) == static_cast<std::string>(rhv);
    }

    bool operator!=(const Cell& lhv, const Cell& rhv){
        return static_cast<std::string>(lhv) != static_cast<std::string>(rhv);
    }


   std::ostream& operator>>(std::ostream& out, const Cell& ob){
             out << ob.operator std::string();
             return out;  
  }

    std::istream& operator>>(std::istream& in, Cell& ob){
        std::string str;
        in >> str;
        ob = static_cast<Cell>(str);
        return in;
    }


//#endif

