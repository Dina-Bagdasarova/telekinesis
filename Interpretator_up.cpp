#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <unordered_map>
#include <ctime>

using std::string;


struct Object {

   std::string name;
    void* value;

    int cnt;

    Object(string n, void* v, int c)
      : name{n},
        value{v},
        cnt{c}
    {}
    
    Object(const Object& rhv)
    : name{rhv.name},
      value{nullptr},
      cnt{rhv.cnt}
    {
        if(rhv.name == "int"){
            int* ptr = new int();
            *ptr = *reinterpret_cast<int*>(rhv.value);
            value = reinterpret_cast<void*>(ptr);
            ptr = nullptr;
      }
        else if(rhv.name == "double"){
              double* ptr = new double();
              *ptr = *reinterpret_cast<double*>(rhv.value);
              value = reinterpret_cast<void*>(ptr);
              ptr = nullptr;
        }
        else if(rhv.name == "bool"){
               bool* ptr = new bool();
               *ptr = *reinterpret_cast<bool*>(rhv.value);
               value = reinterpret_cast<void*>(ptr);
               ptr = nullptr;
        }
        else if(rhv.name == "string"){
              string* ptr = new std::string();
              *ptr = *reinterpret_cast<std::string*>(rhv.value);
              value = reinterpret_cast<void*>(ptr);
              ptr = nullptr;
        }
    }

    Object(Object&& rhv)
    : name{rhv.name},
      value{rhv.value},
      cnt{rhv.cnt}
    {
        rhv.value = nullptr; 
        rhv.cnt = 0;
      }

    const Object& operator=(const Object& rhv) {
        if (this != &rhv) {
            clear();
            name = rhv.name;
            cnt = rhv.cnt;
            if (rhv.name == "int") {
                value = new int(*reinterpret_cast<int*>(rhv.value));
            } else if (rhv.name == "double") {
                value = new double(*reinterpret_cast<double*>(rhv.value));
            } else if (rhv.name == "bool") {
                value = new bool(*reinterpret_cast<bool*>(rhv.value));
            }

            } else if (rhv.name == "string") {
                value = new string(*reinterpret_cast<string*>(rhv.value));
            }

            return *this;
        }

    const Object& operator=(Object&& rhv) {
        if (this != &rhv) {
            name = std::move(rhv.name);
            value = rhv.value;
            cnt = rhv.cnt;
            rhv.value = nullptr;
            rhv.cnt = 0;
        }
        return *this;
    }


    
    virtual string __str__() {
        return "Object";
    }

    virtual Object* __add__(Object* rptr) {
     
        throw std::invalid_argument(name + "not have an overloaded add function");
    }
    
    virtual Object* __sub__(Object* rptr) {
     
        throw std::invalid_argument(name + "not have an overloaded sub function");
    }
    
    virtual Object* __mul__(Object* rptr) {
     
        throw std::invalid_argument(name + "not have an overloaded mul function");
    }

    virtual Object* __mod__(Object* rptr) {
     
        throw std::invalid_argument(name + "not have an overloaded mod function");
    }
    
    virtual Object* __div__(Object* rptr) {
     
        throw std::invalid_argument(name + "not have an overloaded div function");
    }

    virtual Object* __add_=__(Object* rptr) {
     
        throw std::invalid_argument(name + "not have an overloaded add function");
    }
    
    virtual Object* __sub_=__(Object* rptr) {
     
        throw std::invalid_argument(name + "not have an overloaded sub function");
    }
    
    virtual Object* __mul_=__(Object* rptr) {
     
        throw std::invalid_argument(name + "not have an overloaded mul function");
    }
    
    virtual Object* __mod_=__(Object* rptr) {
     
        throw std::invalid_argument(name + "not have an overloaded mod function");
    }
    
    virtual Object* __div_=__(Object* rptr) {
     
        throw std::invalid_argument(name + "not have an overloaded div function");
    }




    virtual Object* __call__() {
        throw std::invalid_argument(name + "not have an overloaded call operator");
    }



    virtual Object* __neg__()  {
        throw std::invalid_argument(name + " does not have an overloaded neg function");
    }

    virtual Object* __or__( Object* rptr)  {
        throw std::invalid_argument(name + " does not have an overloaded or function");
    }

    virtual Object* __and__( Object* rptr)  {
        throw std::invalid_argument(name + " does not have an overloaded and operator");
    }

    virtual Object* __denial__()  {
         throw std::invalid_argument(name + " does not have an overloaded denial function");
    }


    virtual Object* __more__( Object* rptr)  {
        throw std::invalid_argument(name + " does not have an overloaded > function");
    }

    virtual Object* __more_equal__( Object* rptr)  {
        throw std::invalid_argument(name + " does not have an overloaded >= function");
    }

    virtual Object* __less__( Object* rptr)  {
        throw std::invalid_argument(name + " does not have an overloaded < function");
    }

    virtual Object* __less_equal__( Object* rptr)  {
        throw std::invalid_argument(name + " does not have an overloaded <= function");
    }

    virtual Object* __equal__( Object* rptr)  {
        throw std::invalid_argument(name + " does not have an overloaded == operator");
    }
    
    virtual Object* __not_equal__( Object* rptr)  {
         throw std::invalid_argument(name + " does not have an overloaded != operator");
     }

    /*virtual Object* __increment__()  {
          throw std::invalid_argument(name + " does not have an overloaded incremen operator");
      }

    virtual Object* __decrement__()  {
          throw std::invalid_argument(name + " does not have an overloaded decrement operator");
      }*/

    virtual Object* __[]__(int index){
        throw std::invalid_argument(":/");
    }

    virtual int __size__(){
        throw std::invalid_argument(" :/");
    }

    virtual Object* __at__(int index){
        throw std::invalid_argument(":/");
    }

    virtual bool __empty__(){
        throw std::invalid_argument(":/");
    }

    virtual void clear_str(){
            throw std::invalid_argument(":/");
     }
  
    
    void clear() {
        if (name == "int") {
            delete reinterpret_cast<int*>(value);
        } else if (name == "double") {
            delete reinterpret_cast<double*>(value);
        } else if (name == "bool") {
            delete reinterpret_cast<bool*>(value);
        }
          else if(name == "string") {
            delete reinterpret_cast<string*>(value);
        }
        value = nullptr;
    }
  //  const Object& operator  
    virtual ~Object() {
        clear();
};
};


/*struct Function : Object {
  
};*/


//CLASSS INTTTTT............................................................................................................
struct Int : Object 
{  
    Int() 
      : Object("int", new int{0}, 0)
    {}

    Int(int v)
        : Object("int", new int{v}, 0) 
    {}

    Int(Object* ptr)
      : Object("int", new int{0}, 0)
    {
        if (ptr->name == "int") {
          *(static_cast<int*>(value)) = *(static_cast<int*>(ptr->value));
        }
        else if(ptr->name == "double") {
          *(static_cast<int*>(value)) = *(static_cast<double*>(ptr->value));
        }
        else if (ptr->name == "bool") {
        *(static_cast<int*>(value)) = *(static_cast<bool*>(ptr->value));
        }
        else if (ptr->name == "string") {
          *(static_cast<int*>(value)) = *(static_cast<char*>(ptr->value));
        }
        else {
          throw std::invalid_argument("Unsupported type for Int conversion:(");
        }
    }

    Object* __add__(Object* rptr) override{
        if(rptr->name == "int" || rptr->name == "bool"){
             return new Int(*static_cast<int*>(value) + *static_cast<int*>(rptr->value));
        }
        else if(rptr->name == "double"){
            return new Double(*reinterpret_cast<int*>(value) + static_cast<int>(*static_cast<double*>(rptr->value)));
        }
        else {
            throw  std::invalid_argument(":(");
        }

    Object* __sub__(Object* rptr) override{
        if(rptr->name == "int" || rptr->name == "bool"){
             return new Int(*static_cast<int*>(value) - *static_cast<int*>(rptr->value));
        }
        else if(rptr->name == "double"){
            return new Double(*reinterpret_cast<int*>(value) - static_cast<int>(*static_cast<double*>(rptr->value)));
        }
        else {
            throw throw std::invalid_argument(":(");
        }
    }
    }

    Object* __mul__(Object* rptr) override{
        if(rptr->name == "int" || rptr->name == "bool"){
             return new Int(*static_cast<int*>(value) * *static_cast<int*>(rptr->value));
        }
        else if(rptr->name == "double"){
            return new Double(*reinterpret_cast<int*>(value) * static_cast<int>(*static_cast<double*>(rptr->value)));
        }
        else {
            throw std::invalid_argument(":(");
        }
    }

    Object* __mul__(Object* rptr) override{
        if(rptr->name == "int"){
             return new Int(*static_cast<int*>(value) % *static_cast<int*>(rptr->value));
        }
        else {
            throw std::invalid_argument(":(");
        }
    }

    Object* __div__(Object* rptr) override{
        if(rptr->name == "int" || rptr->name == "bool"){
                if(*(static_cast<int*>(rptr->value)) != 0 || *(static_cast<int*>(value)) != 0){
                    return new Int(*static_cast<int*>(value) + *static_cast<int*>(rptr->value));
            }
          throw 0;
        }
        else if(rptr->name == "double"){
                if(*(static_cast<double*>(rptr->value)) != 0.0 || *(static_cast<int*>(value)) != 0){
                return new Double(*reinterpret_cast<int*>(value) + static_cast<int>(*static_cast<double*>(rptr->value)));
            }
          throw 0;
        }
            else {
                throw std::invalid_argument(":(");
        }
    }

    Object* __add_=__(Object* rptr) override{
        if(rptr->name == "int" || rptr->name == "bool" || rptr->name = "double"){
            (*static_cast<int*>(value) += *static_cast<int*>(rptr->value));
        }
         else {
            throw std::invalid_argument(":(");
        }
    }

    Object* __sub_=__(Object* rptr) override{
        if(rptr->name == "int" || rptr->name == "bool" || rptr->name = "double"){
            (*static_cast<int*>(value) -= *static_cast<int*>(rptr->value));
        }
         else {
            throw std::invalid_argument(":(");
        }
    }

    Object* __mul_=__(Object* rptr) override{
        if(rptr->name == "int" || rptr->name == "bool" || rptr->name = "double"){
            (*static_cast<int*>(value) *= *static_cast<int*>(rptr->value));
        }
         else {
            throw std::invalid_argument(":(");
        }
    }

    Object* __mod_=__(Object* rptr) override{
        if(rptr->name == "int" || rptr->name == "bool" || rptr->name = "double"){
            (*static_cast<int*>(value) %= *static_cast<int*>(rptr->value));
        }
         else {
            throw std::invalid_argument(":(");
        }
    }

    Object* __div_=__(Object* rptr) override{
        if(rptr->name == "int" || rptr->name == "bool" || rptr->name = "double"){
            (*static_cast<int*>(value) /= *static_cast<int*>(rptr->value));
        }
         else {
            throw std::invalid_argument(":(");
        }
    }

    Object* __neg__(){
        Int* obj = new Int(-*static_cast<int*>(value));
        return obj;
    }


     Object* __or__(Object* other) override {
        if (other->name == "int" || other->name == "bool" || other->name) {
            bool res = false;
            if (other->name == "int") {
                res = (*static_cast<int*>(value) || *static_cast<int*>(other->value));
            } else if (other->name == "bool") { 
                res = (*static_cast<int*>(value) || *static_cast<bool*>(other->value));
            } else if (other->name == "double"){
                 res = (*static_cast<int*>(value) || *static_cast<double*>(other->value));
            }

            Bool* obj = new Bool(res);
            return obj;

        } else {
            throw std::invalid_argument(":(.");       
         }
    }

    Object* __and__(Object* other) override {
        if (other->name == "int" || other->name == "bool" || other->name == "double") {
            bool res = false;
            if (other->name == "int") {
                res = (*static_cast<int*>(value) && *static_cast<int*>(other->value));
            } else if (other->name == "bool") {
                res = (*static_cast<int*>(value) && *static_cast<bool*>(other->value));
            }
              else if(other->name == "double") {
                res = (*static_cast<int*>(value) && *static_cast<double*>(other->value));

            Bool* obj = new Bool(res);
            return obj;

        } else {
            throw std::invalid_argument(":(.");       
         }
    }

    Object* __demial__() override {
          bool res = !*(static_cast<bool*>(value));
          Bool* obj = new Bool;
          *static_cast<bool*>(new_obj->value) = res;
          return obj;
        }   

    Object* __more__(Object* other) override {
        if(other->name == "int" || other->name == "bool" || other->name == "double"){
            Bool* obj = new Bool(*(static_cast<int*>(value)) > *(static_cast<int*>(other->value)));
            return obj;
        } 
            throw std::invalid_argument(":(.");
     }


    Object* __more_equal__(Object* other) override {
        if(other->name == "int" || other->name == "bool" || other->name == "double"){
            Bool* obj = new Bool(*(static_cast<int*>(value)) >= *(static_cast<int*>(other->value)));
            return obj;
        } 
            throw std::invalid_argument(":(.");
     }

    Object* __less__(Object* other) override {
        if(other->name == "int" || other->name == "bool" || other->name == "double"){
            Bool* obj = new Bool(*(static_cast<int*>(value)) < *(static_cast<int*>(other->value)));
            return obj;
        } 
            throw std::invalid_argument(":(.");
     }

    Object* __less_equal__(Object* other) override {
        if(other->name == "int" || other->name == "bool" || other->name == "double"){
            Bool* obj = new Bool(*(static_cast<int*>(value)) <= *(static_cast<int*>(other->value)));
            return obj;
        } 
            throw std::invalid_argument(":(.");
     }

    Object* __equal__(Object* other) override {
        if(other->name == "int" || other->name == "bool" || other->name == "double"){
            Bool* obj = new Bool(*(static_cast<int*>(value)) == *(static_cast<int*>(other->value)));
            return obj;
        } 
            throw std::invalid_argument(":(.");
     }

    Object* __not_equal__(Object* other) override {
        if(other->name == "int" || other->name == "bool" || other->name == "double"){
            Bool* obj = new Bool(*(static_cast<int*>(value)) != *(static_cast<int*>(other->value)));
            return obj;
        } 
            throw std::invalid_argument(":(.");
     }


    string __str__() {
      return "int";
    }

    ~Int(){
        delete (static_cast<bool*>(value));
    }
};

//CLASSSSS DOUBLE.....................................................................
struct Double : Object {
    Double() 
      : Object("double", new double{0.0}, 0)
    {}

    Double(Object* ptr)
      : Object("double", new double{0.0}, 0)
    {
        if (ptr->name == "int") {
          *(static_cast<double*>(value)) = *(static_cast<int*>(ptr->value));
        }
        else if(ptr->name == "double") {
          *(static_cast<double*>(value)) = *(static_cast<double*)ptr->value;
        }
        else if (ptr->name == "bool") {
        *(static_cast<double*>(value)) = *(static_cast<bool*>(ptr->value));
        }
        else if (ptr->name == "string") {
          *(static_cast<double*>(value)) = *(static_cast<char*>(ptr->value));
        }
        else {
          throw std::invalid_argument(":(");
        }
    
    }

    Object* __add__(Object* rptr) override{
        if(rptr->name == "int" || rptr->name == "double"){
             return new Double(*static_cast<double*>(value) + *static_cast<double*>(rptr->value));
        } 
        else {
            throw std::invalid_argument(":(");
        }
    }

    Object* __sub__(Object* rptr) override{
        if(rptr->name == "int" || rptr->name == "double"){
             return new Double(*static_cast<double*>(value) - *static_cast<double*>(rptr->value));
        }
        else {
            throw std::invalid_argument(":(");
        }
    }

    Object* __mul__(Object* rptr) override{
        if(rptr->name == "int" || rptr->name == "double"){
             return new Double(*static_cast<double*>(value) * *static_cast<double*>(rptr->value));
        }
        else {
            throw std::invalid_argument(":(");
        }
    }

    Object* __mod__(Object* rptr) override{
        if(rptr->name == "int" || rptr->name == "double"){
             return new Double(*static_cast<double*>(value) % *static_cast<double*>(rptr->value));
        }
        else {
            throw std::invalid_argument(":(");
        }
    }

    Object* __div__(Object* rptr) override{
        if(rptr->name == "int" || rptr->name == "double"){
                if(*(static_cast<int*>(rptr->value)) != 0 || *(static_cast<double*>(value)) != 0.0){
                    return new Double(*static_cast<double*>(value)) / (*static_cast<double*>(rptr->value));
            }
          throw 0;
        }
            else {
                throw std::invalid_argument(":(");
        }
    }

    Object* __add_=__(Object* rptr) override{
        if(rptr->name == "int" || rptr->name = "double"){
            (*static_cast<double*>(value) += *static_cast<double*>(rptr->value));
        }
         else {
            throw std::invalid_argument(":(");
        }
    }

    Object* __sub_=__(Object* rptr) override{
        if(rptr->name == "int" || rptr->name = "double"){
            (*static_cast<double*>(value) -= *static_cast<double*>(rptr->value));
        }
         else {
            throw std::invalid_argument(":(");
        }
    }

    Object* __mul_=__(Object* rptr) override{
        if(rptr->name == "int" || rptr->name = "double"){
            (*static_cast<double*>(value) *= *static_cast<double*>(rptr->value));
        }
         else {
            throw std::invalid_argument(":(");
        }
    }

    Object* __mod_=__(Object* rptr) override{
        if(rptr->name == "int"  || rptr->name = "double"){
            (*static_cast<double*>(value) %= *static_cast<double*>(rptr->value));
        }
         else {
            throw std::invalid_argument(":(");
        }
    }

    Object* __div_=__(Object* rptr) override{
        if(rptr->name == "int" || rptr->name = "double"){
            (*static_cast<double*>(value) /= *static_cast<double*>(rptr->value));
        }
         else {
            throw std::invalid_argument(":(");
        }
    }

    Object* __neg__(){
        Int* obj = new Double(-*static_cast<double*>(value));
        return obj;
    }


     Object* __or__(Object* other) override {
        if (other->name == "int" || other->name == "bool" || other->name) {
            bool res = false;
            if (other->name == "int") {
                res = (*static_cast<double*>(value) || *static_cast<int*>(other->value));
            } else if (other->name == "bool") { 
                res = (*static_cast<double*>(value) || *static_cast<bool*>(other->value));
            } else if (other->name == "static_cast<int>("){
                 res = (*static_cast<double*>(value) || *static_cast<double*>(other->value));
            }

            Bool* obj = new Bool(res);
            return obj;

        } else {
            throw std::invalid_argument(":(.");       
         }
    }

    Object* __and__(Object* other) override {
        if (other->name == "int" || other->name == "bool" || other->name == "double") {
            bool res = false;
            if (other->name == "int") {
                res = (*static_cast<double*>(value) && *static_cast<int*>(other->value));
            } else if (other->name == "bool") {
                res = (*static_cast<double*>(value) && *static_cast<bool*>(other->value));
            }
              else if(other->name == "double") {
                res = (*static_cast<double*>(value) && *static_cast<double*>(other->value));

            Bool* obj = new Bool(res);
            return obj;

        } else {
            throw std::invalid_argument(":(.");       
         }
      }
    }

    Object* __more__(Object* other) override {
        if(other->name == "int" || other->name == "bool" || other->name == "double"){
            Bool* obj = new Bool(*(static_cast<double*>(value)) > *(static_cast<double*>(other->value)));
            return obj;
        } 
            throw std::invalid_argument(":(.");
     }


    Object* __more_equal__(Object* other) override {
        if(other->name == "int" || other->name == "bool" || other->name == "double"){
            Bool* obj = new Bool(*(static_cast<double*>(value)) >= *(static_cast<double*>(other->value)));
            return obj;
        } 
            throw std::invalid_argument(":(.");
     }

    Object* __less__(Object* other) override {
        if(other->name == "int" || other->name == "bool" || other->name == "double"){
            Bool* obj = new Bool(*(static_cast<double*>(value)) < *(static_cast<double*>(other->value)));
            return obj;
        } 
            throw std::invalid_argument(":(.");
     }

    Object* __less_equal__(Object* other) override {
        if(other->name == "int" || other->name == "bool" || other->name == "double"){
            Bool* obj = new Bool(*(static_cast<double*>(value)) <= *(static_cast<double*>(other->value)));
            return obj;
        } 
            throw std::invalid_argument(":(.");
     }

    Object* __equal__(Object* other) override {
        if(other->name == "int" || other->name == "bool" || other->name == "double"){
            Bool* obj = new Bool(*(static_cast<double*>(value)) == *(static_cast<double*>(other->value)));
            return obj;
        } 
            throw std::invalid_argument(":(.");
     }

    Object* __not_equal__(Object* other) override {
        if(other->name == "int" || other->name == "bool" || other->name == "double"){
            Bool* obj = new Bool(*(static_cast<double*>(value)) != *(static_cast<double*>(other->value)));
            return obj;
        } 
            throw std::invalid_argument(":(.");
     }



    string __str__() {
      return "double";
    }

    ~Double(){
        delete *static_cast
};

//CLASS BOOOLLLLLL.................................................................................................
struct Bool : Object {
    Bool() 
      : Object("bool", new bool{false},0)
    {}

    Bool(bool val) 
     : Object("bool", new bool{val}, 0) 
    {}

    Bool(Object* ptr)
      : Object("bool", new bool{false}, 0)
    {
        if (ptr->name == "int") {
          *(static_cast<bool*>(value)) = *(static_cast<int*>(ptr->value));
        }
        else if(ptr->name == "double") {
          *(static_cast<bool*>(value)) = *(static_cast<double*>(ptr->value));
        }
        else if (ptr->name == "bool") {
            *(static_cast<bool*>(value)) = *(static_cast<bool*>(ptr->value));
        }
        else if (ptr->name == "string") {
          *(static_cast<bool*>(value)) = *(static_cast<char*>(ptr->value));
        }
         else {
          throw std::invalid_argument(":(");
       }
    
     }
}


    Object* __or__(Object* other) override {
        if (other->name == "int" || other->name == "bool" || other->name) {
            bool res = false;
            if (other->name == "int") {
                res = (*static_cast<bool*>(value) || *static_cast<int*>(other->value));
            } else if (other->name == "bool") { 
                res = (*static_cast<bool*>(value) || *static_cast<bool*>(other->value));
            } else if (other->name == "double"){
                 res = (*static_cast<bool*>(value) || *static_cast<double*>(other->value));
            }

            Bool* obj = new Bool(res);
            return obj;

        } else {
            throw std::invalid_argument(":(.");       
         }
    }

    Object* __and__(Object* other) override {
        if (other->name == "int" || other->name == "bool" || other->name == "double") {
            bool res = false;
            if (other->name == "int") {
                res = (*static_cast<bool*>(value) && *static_cast<int*>(other->value));
            } else if (other->name == "bool") {
                res = (*static_cast<bool*>(value) && *static_cast<bool*>(other->value));
            }
              else if(other->name == "double") {
                res = (*static_cast<bool*>(value) && *static_cast<double*>(other->value));

            Bool* obj = new Bool(res);
            return obj;

        } else {
            throw std::invalid_argument(":(.");       
         }
    }

    Object* __demial__() override {
        bool res = !(*static_cast<bool*>(value));
        Bool* obj = new Bool(res);
        return obj;
    }   

    Object* __more__(Object* other) override {
        if(other->name == "int" || other->name == "bool" || other->name == "double"){
            Bool* obj = new Bool(*(static_cast<bool*>(value)) > *(static_cast<bool*>(other->value)));
            return obj;
        } 
            throw std::invalid_argument(":(.");
     }


    Object* __more_equal__(Object* other) override {
        if(other->name == "int" || other->name == "bool" || other->name == "double"){
            Bool* obj = new Bool(*(static_cast<bool*>(value)) >= *(static_cast<bool*>(other->value)));
            return obj;
        } 
            throw std::invalid_argument(":(.");
     }

    Object* __less__(Object* other) override {
        if(other->name == "int" || other->name == "bool" || other->name == "double"){
            Bool* obj = new Bool(*(static_cast<bool*>(value)) < *(static_cast<bool*>(other->value)));
            return obj;
        } 
            throw std::invalid_argument(":(.");
     }

    Object* __less_equal__(Object* other) override {
        if(other->name == "int" || other->name == "bool" || other->name == "double"){
            Bool* obj = new Bool(*(static_cast<bool*>(value)) <= *(static_cast<bool*>(other->value)));
            return obj;
        } 
            throw std::invalid_argument(":(.");
     }

    Object* __equal__(Object* other) override {
        if(other->name == "int" || other->name == "bool" || other->name == "double"){
            Bool* obj = new Bool(*(static_cast<bool*>(value)) == *(static_cast<bool*>(other->value)));
            return obj;
        } 
            throw std::invalid_argument(":(.");
     }

    Object* __not_equal__(Object* other) override {
        if(other->name == "int" || other->name == "bool" || other->name == "double"){
            Bool* obj = new Bool(*(static_cast<bool*>(value)) != *(static_cast<bool*>(other->value)));
            return obj;
        } 
            throw std::invalid_argument(":(.");
     }

    string __str__() {
      return (*(static_cast<bool*>(value))) ? "true" : false;
    }

    ~Bool(){
        delete (static_cast<bool*>(value));
    }
};


//CLASS String......................................................................................................
struct String : Object {
    String() 
      : Object("string", new string, 0)
    {}

    String(Object* ptr)
      : Object("int", new string, 0)
    {
        *(static_cast<string*>(value)) = ptr->__str__();   
    }

    ~String(){
        clear_str();
      }

    Object* __add__(Object* rhv) override {
        if(rhv->name == "string"){
            std::string res = __str__() + rhv->__str__();
            String obj = new std::string(res);
            return obj;
        }
           throw std::invalid_argument(":(.");
        }

    Object* __add_=__(Object* rhv) override{
        if(rhv->name == "string"){
            *(static_cast<std::string*>(value)) += rhv->__str__();
        }  
            throw std::invalid_argument(":(.");
        }

    Object* __more__(Object* rhv) override{
            if(rhv->name == "string"){
                Bool* res = new bool(*(static_cast<std::string*>(value)) > *(static_cast<std::string*>(thv->value)));
                return res;
            }
                 throw std::invalid_argument(":(.");
            }

    Object* __more_equal__(Object* rhv) override{
            if(rhv->name == "string"){
                Bool* res = new bool(*(static_cast<std::string*>(value)) >= *(static_cast<std::string*>(thv->value)));
                return res;
            }
                 throw std::invalid_argument(":(.");
            }    

    Object* __less__(Object* rhv) override {
            if(rhv->name == "string"){
                Bool* res = new bool(*(static_cast<std::string*>(value)) < *(static_cast<std::string*>(thv->value)));
                return res;
            }
                 throw std::invalid_argument(":(.");
            }

    Object* __less_equal__(Object* rhv) override {
            if(rhv->name == "string"){
                Bool* res = new bool(*(static_cast<std::string*>(value)) <= *(static_cast<std::string*>(thv->value)));
                return res;
            }
                 throw std::invalid_argument(":(.");
            }

    Object* __equal__(Object* rhv) override {
            if(rhv->name == "string"){
                Bool* res = new bool(*(static_cast<std::string*>(value)) == *(static_cast<std::string*>(thv->value)));
                return res;
            }
                 throw std::invalid_argument(":(.");
            }

    Object* __not_equal__(Object* rhv) override {
            if(rhv->name == "string"){
                Bool* res = new bool(*(static_cast<std::string*>(value)) != *(static_cast<std::string*>(thv->value)));
                return res;
            }
                 throw std::invalid_argument(":(.");
            }

    Object* __[]__(int index){
            char ind = (static_cast<std::string*>(value))->at(index);
            return ind;
        }


    Object* __at__(int index){
            char ch = (static_cast<std::string*>(value))->at(index);
            std::string new_string(1, ch);
            String* str = new String(new_string);
            return str;
        }



    int __size__() override {
            return (static_cast<std::string*>(value))->size();
        }

    bool  __empty__() override{
            return  *(static_cast<std::string*>(value) == 0;
        }

    void clear_str() override{
        delete (static_cast<std::string*>(value));
     }


       string __str__() {
      return *(static_cast<std::string*>(value));
    }
};

struct Interpreter
{
    std::vector<std::vector<std::string>> parsed_code;
    std::unordered_map<string, Object*> vars;

    std::unordered_set<Object*> objs;

    std::time_t last = std::time();

    Object* eval(std::string) {
    
    }

    // Object* exec(Array) {
    
    // }

    bool validVariableName(string var) {
    
    }

    void garbageColector() {
      for (auto ptr : objs) {
        if (ptr->count <= 0) {
          delete ptr;
          objs.remove(ptr);
        }
      }
    }

    void run() {
      for (auto& line : parsed_code) {
          auto cur = time();
          if (cur - last > 20second) {
            garbageColector();
            last = cur;
          }
 
        if (line.size() >= 3 && line[1] == "=") {
          if (validVariable(line[0])) {
            vars[line[0]] = exec();
          }
        }
      }
    }
};
