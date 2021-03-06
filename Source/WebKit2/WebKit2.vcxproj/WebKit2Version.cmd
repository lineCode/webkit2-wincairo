set WEBKITVERSIONSCRIPT=%PROJECTDIR%..\..\scripts\generate-webkitversion.pl
set WEBKITVERSIONCONFIG=%PROJECTDIR%..\..\mac\Configurations\Version.xcconfig
set WEBKITVERSIONDIR=%CONFIGURATIONBUILDDIR%\include\WebKit2
set WEBKITVERSIONFILE=%WEBKITVERSIONDIR%\WebKitVersion.h
set PATH=%SystemDrive%\cygwin\bin;%PATH%

bash -c 'perl "%WEBKITVERSIONSCRIPT%" --config "%WEBKITVERSIONCONFIG%"  --outputDir "%WEBKITVERSIONDIR%"'
