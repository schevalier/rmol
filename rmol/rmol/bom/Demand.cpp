// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
#include <rmol/bom/Demand.hpp>

namespace RMOL {

  // //////////////////////////////////////////////////////////////////////
  Demand::Demand () :
    _distributionParameters (FldDistributionParameters()), 
    _yieldRange (FldYieldRange()) {
  }

  // //////////////////////////////////////////////////////////////////////
  Demand::Demand (const Demand& iDemand) :
    _distributionParameters (iDemand.getDistributionParameters()),
    _yieldRange (iDemand.getYieldRange()) {
  }

  // //////////////////////////////////////////////////////////////////////
  Demand::Demand (const FldDistributionParameters& iDistributionParameters,
		  const FldYieldRange& iYieldRange) :
    _distributionParameters (iDistributionParameters),
    _yieldRange (iYieldRange) {
  }

  // //////////////////////////////////////////////////////////////////////
  Demand::~Demand() {
  }
  

  // //////////////////////////////////////////////////////////////////////
  double Demand::getUpperYield() const {
    return _yieldRange.getUpperYield();
  }

  // //////////////////////////////////////////////////////////////////////
  double Demand::getAverageYield() const {
    return _yieldRange.getAverageYield();
  }

  // //////////////////////////////////////////////////////////////////////
  double Demand::getLowerYield() {
    return _yieldRange.getLowerYield();
  }

  // //////////////////////////////////////////////////////////////////////
  double Demand::getMean() const {
    return _distributionParameters.getMean();
  }

  // //////////////////////////////////////////////////////////////////////
  double Demand::getStandardDeviation() const {
    return _distributionParameters.getStandardDeviation();
  }

  // //////////////////////////////////////////////////////////////////////
  double Demand::getVariance() const {
    return _distributionParameters.getVariance();
  }

  // //////////////////////////////////////////////////////////////////////
  void Demand::setMean (const double iMean) {
    _distributionParameters.setMean (iMean);
  }

  // /////////////////////////////////////////////////////////////////////
  void Demand::setSD (const double iSD) {
    _distributionParameters.setStandardDeviation (iSD);
  }
}
