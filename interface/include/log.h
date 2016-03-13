#ifndef LOG_H
#define LOG_H

#include <memory>
#include <fstream>
#include <string>
#include "logger.h"

/**
 * @brief A log policy for a logger. Writes log messages to a file.
 */
class file_log_policy
{
       std::unique_ptr< std::ofstream > out_stream;
    public:
        file_log_policy() : out_stream( new std::ofstream ) {}
        void open_ostream(const std::string& name);
        void close_ostream();
        void write(const std::string& msg);
        ~file_log_policy();
};

extern logger<file_log_policy> log_inst;

#ifdef LOGGING_LEVEL_1

#define LOG log_inst.print< severity_type::debug >
#define LOG_ERR log_inst.print< severity_type::error >
#define LOG_WARN log_inst.print< severity_type::warning >

#else

#define LOG(...)
#define LOG_ERR(...)
#define LOG_WARN(...)

#endif

#ifdef LOGGING_LEVEL_2

#define ELOG log_inst.print< severity_type::debug >
#define ELOG_ERR log_inst.print< severity_type::error >
#define ELOG_WARN log_inst.print< severity_type::warning >

#else

#define ELOG(...)
#define ELOG_ERR(...)
#define ELOG_WARN(...)

#endif

#endif // LOG_H

