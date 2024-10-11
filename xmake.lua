set_project("nmsl")
add_rules("mode.debug", "mode.release")
add_requires("spdlog", "glfw", "glad", "glm")
add_requires("imgui docking", {config = {glfw_opengl3 = true}})

set_languages("c++20")

-- uncomment this line for MacOS
if is_os("windows") then
    add_defines("KB_PLATFORM_WINDOWS")
elseif is_os("linux") then
    add_defines("KB_PLATFORM_LINUX")
elseif is_os("macosx") then
    add_defines("KB_PLATFORM_MACOS")
end

function traverse_directory(path)
    add_headerfiles(path .. "/**.h")
    add_includedirs(path)
    for _, dir in ipairs(os.dirs(path .. "/*")) do
        add_headerfiles(dir .. "/**.h")
        add_includedirs(dir)
    end
end

target("KAIBI")

    set_kind("shared")
    add_defines("KB_BUILD_DLL")
    add_files("runtime/**.cpp")
    -- add_headerfiles("kaibi/**.h")
    add_includedirs("runtime/")

    set_pcxxheader("runtime/pch.h")


    add_packages("spdlog", {public = true})
    add_packages("glfw", {public = true})
    add_packages("imgui", {public = true})
    add_packages("glad", {public = true})
    add_packages("glm", {public = true})
    -- set_pcxxheader("kaibi/src/kaibi.h")

target("TESTBED")
    set_kind("binary")
    add_files("testbed/src/**.cpp")
    add_deps("KAIBI")
    traverse_directory("runtime")