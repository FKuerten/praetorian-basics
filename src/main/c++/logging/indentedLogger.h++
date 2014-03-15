#ifndef PRAETORIAN_BASICS_LOGGING_INDENTEDLOGGER
    #define PRAETORIAN_BASICS_LOGGING_INDENTEDLOGGER

    #include "logger.h++"

    namespace Praetorian {
        namespace Basics {
            namespace Logging {

                class IndentedLogger : public Logger {
                    public: // types
                        typedef std::shared_ptr<IndentedLogger> Ptr;

                    private: // data
                        Logger::Ptr delegate;
                        std::string indention;
                        bool atStartOfLine;

                    public: // methods
                        IndentedLogger(Logger::Ptr delegate, std::string indention);
                        ~IndentedLogger();

                        virtual bool isEnabled() const;

                        virtual Logger::Ptr write(std::string const & message);
                        virtual Logger::Ptr writeln();
                };

            }
        }
    }
#endif
