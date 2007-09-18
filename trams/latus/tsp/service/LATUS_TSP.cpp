// //////////////////////////////////////////////////////////////////////
// Import section
// //////////////////////////////////////////////////////////////////////
// LATUS Common
#include <latus/com/bom/WorldSchedule.hpp>
#include <latus/com/bom/Network.hpp>
#include <latus/com/service/Logger.hpp>
// LATUS TSP
#include <latus/tsp/command/ScheduleParser.hpp>
#include <latus/tsp/command/NetworkGenerator.hpp>
#include <latus/tsp/service/LATUS_TSP.hpp>

namespace LATUS {
  
  namespace TSP {

    // //////////////////////////////////////////////////////////////////////
    LATUS_TSP::LATUS_TSP () {
    }
    
    // //////////////////////////////////////////////////////////////////////
    LATUS_TSP::~LATUS_TSP () {
    }

    // //////////////////////////////////////////////////////////////////////
    void LATUS_TSP::generateInventories () {
      // Retrieve the schedule input filename from the TSP specific
      // service context
      const std::string& lScheduleInputFilename = getScheduleInputFilename ();

      // Parse the schedule input file, and generate the Inventories
      COM::WorldSchedule& lWorldSchedule =
        ScheduleParser::generateInventories (lScheduleInputFilename);

      // Store the WorldSchedule within the TSP specific service context
      setWorldSchedule (lWorldSchedule);

      // DEBUG
      LATUS_LOG_DEBUG ("Generated WorldSchedule:");
      lWorldSchedule.display();

      // From the WorldSchedule (full) BOM, create the Network (full) BOM.
      COM::Network& lNetwork = NetworkGenerator::createNetwork (lWorldSchedule);

      // Store the Network within the TSP specific service context
      setNetwork (lNetwork);

      // DEBUG
      LATUS_LOG_DEBUG ("Generated Network:");
      lNetwork.display();
    }
    
    // //////////////////////////////////////////////////////////////////////
    void LATUS_TSP::getTravelSolutions (const COM::AirportCode_T& iOrigin,
                                        const COM::AirportCode_T& iDestination,
                                        const COM::DateTime_T& iDate,
                                        COM::BucketAvailabilities_T& ioAvl) {
      std::cout << "TSP Service always up!" << std::endl;

      // TODO: Remove the hard coding
      // Hard-code a few availabilities
      ioAvl.push_back (12.1);
      ioAvl.push_back (8.4);
      ioAvl.push_back (5.7);
      ioAvl.push_back (3.3);
    }
    
  }
}
