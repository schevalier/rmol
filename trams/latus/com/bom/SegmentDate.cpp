// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// C
#include <assert.h>
// LATUS COM
#include <latus/com/bom/SegmentDate.hpp>


namespace LATUS {

  namespace COM {

    // //////////////////////////////////////////////////////////////////////
    SegmentDate::SegmentDate (const SegmentDateKey_T& iKey)
      : _key (iKey) {
    }
    
    // //////////////////////////////////////////////////////////////////////
    SegmentDate::~SegmentDate () {
    }

    // //////////////////////////////////////////////////////////////////////
    const std::string SegmentDate::describeKey() const {
      return _key.describe();
    }
    
    // //////////////////////////////////////////////////////////////////////
    void SegmentDate::display() const {

      // Store current formatting flags of std::cout
      std::ios::fmtflags oldFlags = std::cout.flags();

      std::cout << describeKey() << std::endl;

      /*      
      for (SegmentCabinList_T::const_iterator itSegmentCabin =
             _cityPairList.begin();
           itSegmentCabin != _cityPairList.end(); itSegmentCabin++) {
        const SegmentCabin* lSegmentCabin_ptr = itSegmentCabin->second;
        assert (lSegmentCabin_ptr != NULL);

        lSegmentCabin_ptr->display ();
      }
      */
      
      // Reset formatting flags of std::cout
      std::cout.flags (oldFlags);
    }
    
  }
}
