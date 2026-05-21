{
    files = {
        [[build\.objs\RenderTest\windows\x64\release\src\main.cpp.obj]]
    },
    values = {
        [[C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.41.34120\bin\HostX64\x64\link.exe]],
        {
            "-nologo",
            "-dynamicbase",
            "-nxcompat",
            "-machine:x64",
            "/opt:ref",
            "/opt:icf",
            "d3d12.lib",
            "dxgi.lib",
            "d3dcompiler.lib",
            "dxguid.lib",
            "user32.lib",
            "gdi32.lib",
            "kernel32.lib",
            "ole32.lib",
            "/SUBSYSTEM:WINDOWS"
        }
    }
}