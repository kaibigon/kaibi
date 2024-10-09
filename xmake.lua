set_project("nmsl")
add_rules("mode.debug", "mode.release")
add_requires("spdlog")

set_languages("c++20")

add_defines("KB_PLATFORM_WINDOWS")

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
    add_files("kaibi/**.cpp")
    -- add_headerfiles("kaibi/**.h")

    add_packages("spdlog", {public = true})
    -- set_pcxxheader("kaibi/src/kaibi.h")

target("SANDBOX")
    set_kind("binary")
    add_files("sandbox/src/**.cpp")
    add_deps("KAIBI")
    traverse_directory("kaibi/")