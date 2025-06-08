workspace "Terra"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (sloution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Terra/vendor/GLFW/include"

include "Terra/vendor/GLFW"

-- Terra Project LUA

project "Terra"
	location "Terra"
	kind "SharedLib"
	language "C++"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "tapch.h"
	pchsource "Terra/src/tapch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TA_PLATFORM_WINDOWS",
			"TA_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %(cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "TA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TA_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TA_DIST"
		symbols "On"	
	
	filter { "system:windows", "configurations:Release"}
		buildoptions { "/utf-8" }
		buildoptions { "/MT" }

-- Sandbox Project LUA

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Terra/vendor/spdlog/include",
		"Terra/src"
	}

	links
	{
		"Terra"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TA_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "TA_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TA_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TA_DIST"
		symbols "On"	

	filter { "system:windows", "configurations:Release"}
		buildoptions "/utf-8"