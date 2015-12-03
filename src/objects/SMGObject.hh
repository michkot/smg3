#include <string>

typedef int TObjectSize;

class SMGObject
{
private:
   int size;
   std::string label;

public:
   SMGObject(const int, const std::string);
   virtual ~SMGObject() {};

   static const SMGObject & getNullObject();
   std::string getLabel() const;
   TObjectSize getSize() const;

   virtual bool isAbstract() const = 0;
   virtual bool isMoreGeneral(const SMGObject &) const = 0;
   virtual const SMGObject & join(const SMGObject & pOther) const = 0;
};

class SMGNullObject : public SMGObject
{
public:
   SMGNullObject() : SMGObject(0, "NULL") {}

   bool isAbstract() const override {return false;}
   bool isMoreGeneral(const SMGObject &) const override {return false;}
   const SMGObject & join(const SMGObject & pOther) const override {return pOther;}
};