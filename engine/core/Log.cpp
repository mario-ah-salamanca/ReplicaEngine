// ── engine/core/Log.cpp ──────────────────────────────────────────────────────
#include "core/Log.hpp"

#include <filesystem>                                // std::filesystem::create_directories
#include <spdlog/sinks/stdout_color_sinks.h>         // coloured console sink
#include <spdlog/sinks/basic_file_sink.h>            // rolling file sink

namespace core {

std::shared_ptr<spdlog::logger> Log::s_logger;

// -----------------------------------------------------------------------------
void Log::init()
{
    // Ensure the logs directory exists relative to repo root
    std::filesystem::create_directories("../logs");

    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    auto file_sink    = std::make_shared<spdlog::sinks::basic_file_sink_mt>("../logs/boot.log",
                                                                            /*truncate=*/true);

    spdlog::sinks_init_list sink_list{ console_sink, file_sink };
    s_logger = std::make_shared<spdlog::logger>("ENGINE", sink_list);

    // e.g. [12:34:56.789] [info] Message
    s_logger->set_pattern("[%H:%M:%S.%e] [%^%l%$] %v");

#ifdef NDEBUG         // Release build → keep only warnings+
    s_logger->set_level(spdlog::level::warn);
#else                  // Debug build → log everything
    s_logger->set_level(spdlog::level::trace);
#endif

    spdlog::register_logger(s_logger);
}
// -----------------------------------------------------------------------------

} // namespace core

