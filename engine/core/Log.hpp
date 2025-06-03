#pragma once
#include "logMacros.hpp"
#include <memory>
#include <spdlog/spdlog.h>
#include <fmt/compile.h>          // fmt::compile – enables CT-checked strings

namespace core {

class Log {
public:
    static void init();
    static std::shared_ptr<spdlog::logger>& get() { return s_logger; }

    // ── Level helpers ──────────────────────────────────────────────────────────
    template <typename... Args>
    static void info(fmt::format_string<Args...> fmt, Args&&... args)
    { s_logger->info(fmt, std::forward<Args>(args)...); }

    template <typename... Args>
    static void warn(fmt::format_string<Args...> fmt, Args&&... args)
    { s_logger->warn(fmt, std::forward<Args>(args)...); }

    template <typename... Args>
    static void error(fmt::format_string<Args...> fmt, Args&&... args)
    { s_logger->error(fmt, std::forward<Args>(args)...); }

    template <typename... Args>
    static void fatal(fmt::format_string<Args...> fmt, Args&&... args)
    { s_logger->critical(fmt, std::forward<Args>(args)...); }

private:
    static std::shared_ptr<spdlog::logger> s_logger;
};

} // namespace core

