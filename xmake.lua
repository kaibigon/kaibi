set_project("nmsl")
add_rules("mode.debug", "mode.release")
add_requires("spdlog", "glfw")

set_languages("c++20")

-- uncomment this line for MacOS
-- add_defines("KB_PLATFORM_WINDOWS")

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


    add_packages("spdlog", {public = true}, "glfw", {public = true})
    -- set_pcxxheader("kaibi/src/kaibi.h")

target("SANDBOX")
    set_kind("binary")
    add_files("testbed/src/**.cpp")
    add_deps("KAIBI")
    traverse_directory("runtime")