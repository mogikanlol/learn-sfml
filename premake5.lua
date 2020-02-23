workspace "My-Games"
	architecture "x86"
	startproject "Application"

	configurations
	{
		"Debug",
		"Release"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "Application"
	location "Application"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/dependencies/SFML2/include"	}

	libdirs 
	{
		"%{prj.name}/dependencies/SFML2/lib"
	}

	filter "system:windows"
		systemversion "latest"
		
	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

		links
		{
			"sfml-system-d.lib",
			"sfml-graphics-d.lib",
			"sfml-window-d.lib",
			"sfml-audio-d.lib"
		}

		postbuildcommands
		{
			("{COPY} dependencies/SFML2/dll/debug/ ../bin/" .. outputdir .."/Application/"),
			("{COPY} dependencies/arial.ttf ../bin/" .. outputdir .."/Application/")
		}

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

		links
		{
			"sfml-system.lib",
			"sfml-graphics.lib",
			"sfml-window.lib",
			"sfml-audio.lib"
		}

		postbuildcommands
		{
			("{COPY} dependencies/SFML2/dll/release/ ../bin/" .. outputdir .."/Application/"),
			("{COPY} dependencies/arial.ttf ../bin/" .. outputdir .."/Application/")
		}