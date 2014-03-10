#ifndef PRAETORIAN_BASICS_LOGGING_LOGGER
    #define PRAETORIAN_BASICS_LOGGING_LOGGER

    #include <memory>
    #include <string>

    namespace Praetorian {
        namespace Basics {
            namespace Logging {

                class Logger : public std::enable_shared_from_this<Logger> {
                    public: //types
                        typedef std::shared_ptr<Logger> Ptr;


                    public: //methods
                        ~Logger();

                        //Logger::Ptr write(char const * message);
                        //Logger::Ptr writeln(char const * message);

                        Logger::Ptr write(unsigned int message);
                        Logger::Ptr writeln(unsigned int message);

                        virtual Logger::Ptr write(std::string const & message) = 0;
                        Logger::Ptr writeln(std::string const & message);

                        virtual Logger::Ptr writeln() = 0;
                };

            }
        }
    }

#endif
