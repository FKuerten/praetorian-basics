#ifndef PRAETORIAN_BASICS_LOGGING_STREAMLOGGER
    #define PRAETORIAN_BASICS_LOGGING_STREAMLOGGER

    #include "logger.h++"
    #include <ostream>

    namespace Praetorian {
        namespace Basics {
            namespace Logging {

                class StreamLogger : public Logger {
                    public: // types
                        typedef std::shared_ptr<StreamLogger> Ptr;

                    private: // data
                        std::ostream & delegate;

                    public: // methods
                        StreamLogger(std::ostream & delegate);
                        ~StreamLogger();

                        virtual Logger::Ptr write(std::string const & message);
                        virtual Logger::Ptr writeln();
                };

            }
        }
    }
#endif

