set_project("kaibi")
set_version("0.1.0")
set_xmakever("2.8.0")

set_languages("c++20")
set_warnings("all", "error")

add_rules("mode.debug", "mode.release")

target("kaibi")
    set_kind("binary")
    add_files("src/*.cpp")

    if is_plat("windows") then
        add_defines("UNICODE", "_UNICODE", "NOMINMAX", "WIN32_LEAN_AND_MEAN")
        add_ldflags("/SUBSYSTEM:WINDOWS", {force = true})
        add_syslinks(
            "d3d12",
            "dxgi",
            "d3dcompiler",
            "dxguid",
            "user32",
            "gdi32",
            "kernel32",
            "ole32"
        )
    end
