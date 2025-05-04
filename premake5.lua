-- premake5.lua
workspace "LightStream"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "LightStream"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
include "Walnut/WalnutExternal.lua"

include "LightStream"