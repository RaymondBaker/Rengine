#pragma once
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/async.h>

namespace Ren {
	[[maybe_unused]]
	static void setup_logging() {
		spdlog::init_thread_pool(8192, 1);
        auto stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
        auto rotating_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("Rengine.log", 1024*1024*10, 3);
        std::vector<spdlog::sink_ptr> sinks {stdout_sink, rotating_sink};
        auto logger = std::make_shared<spdlog::async_logger>("loggername", sinks.begin(), sinks.end(), spdlog::thread_pool(), spdlog::async_overflow_policy::block);
        logger->set_pattern("[%H:%M:%S] [%^%l%$] [T: %t] %v");
        logger->set_level(spdlog::level::debug);
        spdlog::register_logger(logger);

        spdlog::set_default_logger(logger);
	}
}
