#include "indentedLogger.h++"

namespace Praetorian {
    namespace Basics {
        namespace Logging {

            IndentedLogger::IndentedLogger
                (Logger::Ptr delegate
                ,std::string indention
                )
            : delegate(delegate)
            , indention(indention)
            , atStartOfLine(true)
            {
            }

            IndentedLogger::~IndentedLogger() {}

            bool
            IndentedLogger::isEnabled() const
            {
                return this->delegate->isEnabled();
            }


            Logger::Ptr
            IndentedLogger::write(std::string const & message)
            {
                if (this->atStartOfLine) {
                    this->delegate->write(this->indention);
                    this->atStartOfLine = false;
                }
                this->delegate->write(message);
                return shared_from_this();
            }

            Logger::Ptr
            IndentedLogger::writeln()
            {
                this->delegate->writeln();
                this->atStartOfLine=true;
                return shared_from_this();
            }

        }
    }
}
