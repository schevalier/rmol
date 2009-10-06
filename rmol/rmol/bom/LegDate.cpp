// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <cassert>
// STDAIR
#include <stdair/bom/LegDate.hpp>
// RMOL 
#include <rmol/bom/FlightDate.hpp>
#include <rmol/bom/LegDate.hpp>

namespace RMOL {

  // ////////////////////////////////////////////////////////////////////
  LegDate::LegDate (BomStructure_T& ioLegStructure)
    : _legDateStructure (ioLegStructure) {
  }
  
  // ////////////////////////////////////////////////////////////////////
  LegDate::~LegDate () {
  }

  // //////////////////////////////////////////////////////////////////////
  void LegDate::toStream (std::ostream& ioOut) const {
    ioOut << toString() << std::endl;
  }

  // //////////////////////////////////////////////////////////////////////
  void LegDate::fromStream (std::istream& ioIn) {
  }

  // //////////////////////////////////////////////////////////////////////
  std::string LegDate::toString() const {
    std::ostringstream oStr;

    // First, put the key of that level
    oStr << describeShortKey() << std::endl;

    // Then, browse the children
    // [...] (no child for now)
    
    return oStr.str();
  }
    
  // //////////////////////////////////////////////////////////////////////
  const std::string LegDate::describeKey() const {
    return _legDateStructure.describeKey();
  }

  // //////////////////////////////////////////////////////////////////////
  const std::string LegDate::describeShortKey() const {
    return _legDateStructure.describeShortKey();
  }

}

