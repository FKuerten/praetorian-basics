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


                    private:
                        // This should prevent ALL implicit conversions.
                        template <typename T>
                        Logger::Ptr write(T message);
                        template <typename T>
                        Logger::Ptr writeln(T message);

                    public: //methods
                        Logger();
                        ~Logger();

                        virtual bool isEnabled() const = 0;

                        Logger::Ptr write(char const * message);
                        Logger::Ptr writeln(char const * message);

                        Logger::Ptr write(double message);
                        Logger::Ptr writeln(double message);

                        Logger::Ptr write(long double message);
                        Logger::Ptr writeln(long double message);

                        // bools are inherently dangerous
                        Logger::Ptr write(bool message);
                        Logger::Ptr writeln(bool message);

                        Logger::Ptr write(long unsigned int message);
                        Logger::Ptr writeln(long unsigned int message);

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
