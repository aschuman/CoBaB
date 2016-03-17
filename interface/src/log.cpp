#include "log.h"

/**
 * @brief Opens a stream with the given name.
 * @param name Name of the logger.
 */
void file_log_policy::open_ostream(const std::string& name)
{
   out_stream->open( name.c_str(), std::ios_base::binary|std::ios_base::out );
   if( !out_stream->is_open() )
   {
        throw(std::runtime_error("LOGGER: Unable to open an output stream"));
   }
}

/**
 * @brief Closes the stream.
 */
void file_log_policy::close_ostream()
{
    if( out_stream )
    {
        out_stream->close();
    }
}

/**
 * @brief Writes the given message to the stream.
 * @param msg The message.
 */
void file_log_policy::write(const std::string& msg)
{
    (*out_stream)<<msg<<std::endl;
}

/**
 * @brief Closes the stream if necessary.
 */
file_log_policy::~file_log_policy()
{
    if( out_stream )
    {
        close_ostream();
    }
}

logger<file_log_policy> log_inst("execution.log");
