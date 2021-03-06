#pragma once

#include <string>
#include "objects/SMGObject.hh"

namespace smg {

class SMGObjectVisitor;

class SMGRegion : public SMGObject {
 public:
  SMGRegion(const int size, const std::string label);

  std::string ToString() const;
  bool PropertiesEqual(const SMGRegion& other) const;

  std::string GetClassName() const override;
  bool IsAbstract() const override;
  void Accept(SMGObjectVisitor& visitor) const override;
  const SMGObject& Join(const SMGObject& other) const override;
  bool IsMoreGeneral(const SMGObject&) const override;
};

}  // namespace smg
