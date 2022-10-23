#pragma once
#include <cstddef>
#include <cstdint>
#include "drivers/infinisim/SpiMaster.h"

namespace Pinetime {
  namespace Drivers {
    namespace Infinisim {
      class Spi {
      public:
        Spi(Pinetime::Drivers::Infinisim::SpiMaster& spiMaster, uint8_t pinCsn);
        Spi(const Spi&) = delete;
        Spi& operator=(const Spi&) = delete;
        Spi(Spi&&) = delete;
        Spi& operator=(Spi&&) = delete;

        bool Init();
        bool Write(const uint8_t* data, size_t size);
        bool Read(uint8_t* cmd, size_t cmdSize, uint8_t* data, size_t dataSize);
        bool WriteCmdAndBuffer(const uint8_t* cmd, size_t cmdSize, const uint8_t* data, size_t dataSize);
        void Sleep();
        void Wakeup();

      private:
        Pinetime::Drivers::Infinisim::SpiMaster& spiMaster;
        uint8_t pinCsn;
      };
    }
  }
}