rem Thanks to https://youtu.be/imQpP_ZY83Q

@echo off
tilte Test CmdMenuSel

:menu
cls
echo Test menu
cmdMenuSel F870 "Menu 1" "Menu 2" "Menu 3" "Exit"
if %errorlevel%==1 goto menu1
if %errorlevel%==2 goto menu2
if %errorlevel%==3 goto menu3
if %errorlevel%==4 exit
goto menu

:menu1
cls
echo Menu 1
pause
goto menu

:menu2
cls
echo Menu 2
pause
goto menu

:menu3
cls
echo Menu 3
pause
goto menu