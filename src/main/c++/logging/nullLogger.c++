#include "nullLogger.h++"

namespace Praetorian {
    namespace Basics {
        namespace Logging {

            NullLogger::NullLogger()
            {
            }

            NullLogger::~NullLogger() {}

            bool
            NullLogger::isEnabled() const
            {
                return false;
            }


            Logger::Ptr
            NullLogger::write(std::string const & message)
            {
                // do nothing
                return shared_from_this();
            }

            Logger::Ptr
            NullLogger::writeln()
            {
                // do nothing
                return shared_from_this();
            }

        }
    }
}
