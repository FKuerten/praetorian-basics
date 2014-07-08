#include "streamLogger.h++"

namespace Praetorian {
    namespace Basics {
        namespace Logging {

            StreamLogger::StreamLogger
                (std::ostream & delegate
                )
            : delegate(delegate)
            {
            }

            StreamLogger::~StreamLogger() {}

            bool
            StreamLogger::isEnabled() const
            {
                return true;
            }


            Logger::Ptr
            StreamLogger::write(std::string const & message)
            {
                this->delegate << message;
                return shared_from_this();
            }

            Logger::Ptr
            StreamLogger::writeln()
            {
                this->delegate << std::endl;
                return shared_from_this();
            }

        }
    }
}
