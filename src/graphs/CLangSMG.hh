/*
    Created by Viktor Malik on 24.2.2016.
*/

#pragma once

#include <map>
#include <set>
#include <deque>
#include <string>
#include "graphs/CLangStackFrame.hh"
#include "graphs/SMG.hh"
#include "objects/SMGObject.hh"
#include "objects/SMGRegion.hh"

namespace smg {

class CLangSMG : public SMG {
 private:
  std::deque<CLangStackFrame> stack_objects_;
  std::set<SMGObjectPtr> heap_objects_;
  std::map<std::string, SMGRegionPtr> global_objects_;

  bool has_leaks_;
  static bool perform_checks_;

 public:
  static void SetPerformChecks(const bool setting);
  static bool PerformChecks();
  CLangSMG();

  void SetMemoryLeak();
  bool HasMemoryLeaks() const;

  void AddHeapObject(const SMGObjectPtr& object);
  void AddGlobalObject(const SMGRegionPtr& object);
  void AddStackObject(const SMGRegionPtr& object);
  void AddStackFrame(const std::string function_declaration);
  void DropStackFrame();
  void RemoveHeapObject(const SMGRegionPtr& object);

  SMGRegionPtr AddGlobalVariable(const SMGCType& type, const std::string var_name);
  SMGRegionPtr AddLocalVariable(const SMGCType& type, const std::string var_name);
  void free(const int offset, const SMGRegionPtr& region);

  const std::deque<CLangStackFrame>& GetStackFrames() const;
  const std::set<SMGObjectPtr>& GetHeapObjects() const;
  const std::set<SMGObjectPtr> GetGlobalObjects() const;
  const std::map<std::string, SMGRegionPtr>& GetGlobalVariables() const;
  SMGRegionPtr GetObjectForVisibleVariable(const std::string variable_name) const;

  bool HasLocalVariable(const std::string variable_name) const;
  bool IsHeapObject(const SMGObjectPtr& object) const;
  bool IsGlobalObject(const SMGObjectPtr& object) const;
  bool ContainsValue(const SMGValue& value) const;
};

}  // namespace smg


