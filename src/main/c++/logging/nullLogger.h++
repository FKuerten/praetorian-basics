#ifndef PRAETORIAN_BASICS_LOGGING_NULLLOGGER
    #define PRAETORIAN_BASICS_LOGGING_NULLLOGGER

    #include "logger.h++"
    #include <ostream>

    namespace Praetorian {
        namespace Basics {
            namespace Logging {

                class NullLogger : public Logger {
                    public: // types
                        typedef std::shared_ptr<NullLogger> Ptr;

                    private: // data

                    public: // methods
                        NullLogger();
                        ~NullLogger();

                        virtual bool isEnabled() const;

                        virtual Logger::Ptr write(std::string const & message);
                        virtual Logger::Ptr writeln();
                };

            }
        }
    }
#endif

