#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Terra {

	class TERRA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define TA_CORE_TRACE(...)    ::Terra::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TA_CORE_INFO(...)     ::Terra::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TA_CORE_WARN(...)     ::Terra::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TA_CORE_ERROR(...)    ::Terra::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TA_CORE_CRITICAL(...) ::Terra::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define TA_TRACE(...)         ::Terra::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TA_INFO(...)          ::Terra::Log::GetClientLogger()->info(__VA_ARGS__)
#define TA_WARN(...)          ::Terra::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TA_ERROR(...)         ::Terra::Log::GetClientLogger()->error(__VA_ARGS__)
#define TA_CRITICAL(...)      ::Terra::Log::GetClientLogger()->critical(__VA_ARGS__)

