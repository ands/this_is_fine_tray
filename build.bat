@echo off

call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x64

cd /d %~dp0
set CommonCompilerFlags=-nologo -MT -O2 -Oi -fp:fast -Gm- -EHsc -GR- -WX -W2 -wd4201 -wd4100 -wd4189 -wd4505 -wd4127 -wd4324 -FC -Z7 -D_CRT_SECURE_NO_WARNINGS
cl %CommonCompilerFlags% this_is_fine.c /link -incremental:no -opt:ref -SUBSYSTEM:windows -ENTRY:mainCRTStartup
popd

pause