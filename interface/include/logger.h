#ifndef LOGGER_H
#define LOGGER_H

#include <sstream>
#include <string>
#include <mutex>

/**
 * @brief Denotes the severity of the cause of a log message.
 */
enum severity_type
{
   debug = 1, ///< message does not describe a problem
   error, ///< message describes a problem that could not be handled
   warning ///< message describes a problem that could be handled
};


/**
 * @brief Writes messages with timestamp and severity_type to a stream
 *
 * The Stream is determined by the log_policy.
 */
template< typename log_policy >
class logger
{
    unsigned log_line_number;
    std::string get_time();
    std::string get_logline_header();
    std::stringstream log_stream;
    log_policy* policy;
    std::mutex write_mutex;

    //Core printing functionality
    void print_impl();
    template<typename First, typename...Rest>
    void print_impl(First parm1, Rest...parm);
public:
    logger( const std::string& name );

    template< severity_type severity , typename...Args >
    void print( Args...args );

    ~logger();
};

template< typename log_policy >
/**
 * @brief Constructs a logger. Sends the given name to this loggers log_policy to open the stream.
 * @param name Name of the logger.
 */
logger< log_policy >::logger( const std::string& name )
{
   log_line_number = 0;
   policy = new log_policy;
   if( !policy )
    {
       throw std::runtime_error("LOGGER: Unable to create the logger instance");
    }
    policy->open_ostream( name );
}


template< typename log_policy >
/**
 * @brief Closes the stream. Destructs this logger.
 */
logger< log_policy >::~logger()
{
    if( policy )
    {
       policy->close_ostream();
       delete policy;
    }
}


/**
 * @brief Writes a log message.
 *
 * Method is thread-safe.
 * @param args Mutiple arguments that will be written to the stream.
 */
template< typename log_policy >
    template< severity_type severity , typename...Args >
void logger< log_policy >::print( Args...args )
{
    write_mutex.lock();
    switch( severity )
    {
        case severity_type::debug:
             log_stream<<"<DEBUG> :";
             break;
        case severity_type::warning:
             log_stream<<"<WARNING> :";
             break;
        case severity_type::error:
             log_stream<<"<ERROR> :";
             break;
    };
    print_impl( args... );
    write_mutex.unlock();
}

template< typename log_policy >
void logger< log_policy >::print_impl()
{
    policy->write( get_logline_header() + log_stream.str() );
    log_stream.str("");
}

template< typename log_policy >
    template<typename First, typename...Rest >
void logger< log_policy >::print_impl(First parm1, Rest...parm)
{
    log_stream<<parm1;
    print_impl(parm...);
}

template< typename log_policy >
std::string logger< log_policy >::get_time()
{
    std::string time_str;
    time_t raw_time;
    time( & raw_time );
    time_str = ctime( &raw_time );
    //without the newline character
    return time_str.substr( 0 , time_str.size() - 1 );
}

template< typename log_policy >
std::string logger< log_policy >::get_logline_header()
{
    std::stringstream header;
    header.str("");
    header.fill('0');
    header.width(7);
    header << log_line_number++ <<" < "<<get_time()<<" - ";
    header.fill('0');
    header.width(7);
    header <<clock()<<" > ~ ";
    return header.str();
}

#endif // LOGGER_H

