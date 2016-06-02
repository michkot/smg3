#pragma once

// Basic type hierarchy for SMG implementation
// (c) PP, 2016

#include <string>
#include <map>
#include <vector>
#include <memory>
#include <iostream>

namespace smg {

typedef void* frontend_id;    // unique GCC id (or LLVM representation)

// Type -- reference to type representation (copyable, assignable)
class Type {
private: 
  virtual frontend_id FrontendId() const = 0;

public:
    bool operator==(const Type& rhs) {
      return FrontendId() == rhs.FrontendId();
    }

    virtual size_t SizeOf() const = 0;
    virtual size_t Width() const = 0;
    virtual std::string ToString() const = 0;

    virtual bool IsInteger() const = 0;
    virtual bool IsPointer() const = 0;
    virtual bool IsStruct() const = 0;
    virtual bool IsUnion() const = 0;
    virtual bool IsArray() const = 0;
};


//Následující kod je pseudokod, nebyl sestaven
class LllvmTypeEnvelope : public Type {
private: 
  llvm:Type internType;

private:
  virtual frontend_id FrontendId() const { }

public:
  virtual size_t SizeOf() const { return internType.Sie(); } //etc etc...
  virtual size_t Width() const {}
  virtual std::string ToString() const {}

  virtual bool IsInteger() const {}
  virtual bool IsPointer() const {}
  virtual bool IsStruct() const {}
  virtual bool IsUnion() const {}
  virtual bool IsArray() const {}
}


//část původní implementace

//// type output
//std::ostream &operator << (std::ostream &s, Type t);
//
//// TypeImpl representation (not all members are valid for a type)
//class TypeImpl final {
//  frontend_id fid;      // front-end type representation
//  size_t sz;          // sizeof
//  size_t bsize;       // int width, float width, array dimension
//  Type targetType;    // ptr, array, return type
//
//  struct field_desc {   // for struct/union members, ...
//    size_t offset;    // always zero for union
//    std::string name;   // .name
//    Type type;
//  };
//  std::vector<field_desc> fields; // struct/union fields
//public:
//  enum Kind { UNKNOWN, VOID, INT, REAL, PTR, STRUCT, UNION, ARRAY, FUNCTION, };
//private:
//  Kind kind = UNKNOWN;
//public:
//  // generic wrapper
//  template<typename T1, typename ... T>
//  static Type create(T1 x, T ... args) {
//     if(mapped(x))
//        return m[x].get();
//     // type not registered yet -- create new and register
//     std::unique_ptr<TypeImpl> t{new TypeImpl(x,args...)};
//     m[x] = std::move(t); // TODO use emplace?
//     return m[x].get();
//  }
//
//private: // constructors
//  TypeImpl(frontend_id id, size_t SizeOf, size_t bs): fid(id), sz{SizeOf}, bsize{bs}, kind{INT} {}
//  TypeImpl(frontend_id id, size_t SizeOf, Type t): fid(id), sz{SizeOf}, targetType(t), kind{PTR} {}
//  TypeImpl(frontend_id id, size_t SizeOf): fid(id), sz{SizeOf}, kind{STRUCT} {}
//  TypeImpl(frontend_id id, Type t, size_t n): fid(id), sz{t.SizeOf()*n}, bsize(n), targetType(t), kind{ARRAY} {}
//  TypeImpl() = delete;
//  TypeImpl(const TypeImpl&) = delete;           // not copyable
//  TypeImpl&operator=(const TypeImpl&) = delete; // not assignable
//
//public:
//  size_t      SizeOf() const { return sz; } // sizeof
//  size_t      Width() const { return bsize; } // bitwidth/arraysize
//  frontend_id   id() const { return fid; }
//
//  bool          isInteger() const { return kind==INT; }
//  bool          isPointer() const { return kind==PTR; }
//  bool          isStruct() const { return kind==STRUCT; }
//  bool          isUnion() const { return kind==UNION; }
//  bool          isArray() const { return kind==ARRAY; }
//
//  std::string   ToString() const;
//  void          add_field(size_t o, std::string name, Type t);
//  static Type get(frontend_id id) {
//     if(mapped(id))     return m[id].get();
//     else               return nullptr; // TODO: throw bad_frontend_type_id
//  }
//private:
//  // map registry for all types, updated dynamically
//  // TODO: use singleton?
//  typedef std::map<frontend_id,std::unique_ptr<TypeImpl>> map_t;
//  static map_t m; // owns all types
//  static bool mapped(frontend_id id) { return (m.find(id)!=m.end()); }
//}; // class TypeImpl
//
//// class TypeImpl methods definitions
//inline size_t Type::SizeOf() const { return p->SizeOf(); }
//inline size_t Type::Width() const { return p->Width(); }
//inline frontend_id Type::FrontendId() const { return p->id(); }
//
//inline bool Type::IsInteger() const { return p->isInteger(); }
//inline bool Type::IsPointer() const { return p->isPointer(); }
//inline bool Type::IsStruct() const { return p->isStruct(); }
//inline bool Type::IsUnion() const { return p->isUnion(); }
//inline bool Type::IsArray() const { return p->isArray(); }
//
//inline std::string Type::ToString() const { return p->ToString(); }
//inline void Type::add_field(size_t o, std::string name, Type t) { p->add_field(o,name,t); }

}  // namespace smg
