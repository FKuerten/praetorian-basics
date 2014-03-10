#include "logger.h++"
#include <boost/lexical_cast.hpp>

namespace Praetorian {
    namespace Basics {
        namespace Logging {

            Logger::~Logger()
            {
            }

            /*Logger::Ptr
            Logger::write(char const * message) {
                this->write(std::string(message));
                return shared_from_this();
            }

            Logger::Ptr
            Logger::writeln(char const * message) {
                this->writeln(std::string(message));
                return shared_from_this();
            }*/

            Logger::Ptr
            Logger::write(unsigned int message) {
                this->write(boost::lexical_cast<std::string>(message));
                return shared_from_this();
            }

            Logger::Ptr
            Logger::writeln(unsigned int message) {
                this->writeln(boost::lexical_cast<std::string>(message));
                return shared_from_this();
            }

            Logger::Ptr
            Logger::writeln(std::string const & message) {
                this->write(message);
                this->writeln();
                return shared_from_this();
            }

        }
    }
}
